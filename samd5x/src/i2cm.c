/*
 * i2cm.c
 * driver for SAMD51 I2C Master
 * 
 * Copyright © Alkgrove 2018
 *
 * @par Redistribution and use in source and binary forms, with or without modification, are permitted 
 * provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions 
 * and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions 
 * and the following disclaimer in the documentation and/or other materials provided with the 
 * distribution. 
 * 3. Neither the name of the copyright holder nor the names of its contributors may be 
 * used to endorse or promote products derived from this software without specific prior written 
 * permission.
 * 
 * @par THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND 
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER 
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF 
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "sam.h"
#include "i2cm.h"

#ifdef FEATURE_RTOS
#include "RTOSconfig.h"
#else
#define I2CM_RTOS_INIT
#define I2CM_RTOS_TAKE
#define I2CM_RTOS_GIVE
#endif


#ifndef I2CM_PORT
#error define name of SERCOM to I2CM_PORT in initmaker config or #define I2CM_PORT SERCOMn
#endif

/* Private Variables for I2CM - do not make global */
volatile uint8_t *txbuf = NULL;
volatile uint8_t *rxbuf = NULL;
volatile uint8_t txlen = 0;
volatile uint8_t rxlen = 0;
volatile uint8_t slaveAddress = 0;
volatile uint8_t status = 0;

const char *i2cm_err_msg[] = {
	"OK",
	"Bus Busy",
	"Bus Fault",
	"Arbitration Lost",
	"No Acknowledge",
	"Bad Message",
	"Timeout"};

const char *i2cm_err_str(int err)
{
	return i2cm_err_msg[err];
}

void i2cmInit(void)
{
    I2CM_RTOS_INIT;
	NVIC_ENABLE_I2CM_PORT_MB();
	NVIC_ENABLE_I2CM_PORT_SB();
	NVIC_ENABLE_I2CM_PORT_ERR();
}
// timeout in ms
#define I2CMTO 500
i2cm_err_t i2cm_transfer( uint8_t address, 
	uint8_t *wrbuf, 
	uint8_t wrlen, 
	uint8_t *rdbuf, 
	uint8_t rdlen)
{
	volatile int32_t timeout = 65535;
	int sdahigh;
	volatile int i;
	int j;
	uint8_t sdapf;
	uint8_t sclpf;
	// If it is not enabled, then enable I2C
	if ((i2cm_read_CTRLA(I2CM_PORT) & SERCOM_I2CM_CTRLA_ENABLE) == 0) {
		i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_ENABLE | SERCOM_I2CM_SYNCBUSY_SWRST);
		i2cm_set_ENABLE(I2CM_PORT);
	}

	// Check if the bus is busy
	while (i2cm_get_BUSSTATE(I2CM_PORT) != I2CM_BUSSTATE_IDLE) {
		if (--timeout <= 0) {
			// switch sda/scl to gpio and force clocks onto scl while
			// watching sda go high, this should clear any slave that
			// is out of sync
			i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_ENABLE);
			i2cm_clear_ENABLE(I2CM_PORT);
			sdapf = port_get_pin_function(I2CM_PORT_SDA);
			sclpf = port_get_pin_function(I2CM_PORT_SCL);
			gpio_set_dir_out(I2CM_PORT_SCL);
			gpio_set_dir_in(I2CM_PORT_SDA);
			sdahigh = 0;
			for (j = 0; j < 100; j++) {
				if (gpio_get_in(I2CM_PORT_SDA)) {
					if (++sdahigh > 8) break;
				} else {
					sdahigh = 0;
				}
				// drive the clock low, then release (open drain)
				gpio_set_wand(I2CM_PORT_SCL, false);
				for (i = 0; i < 300; i++);
				gpio_set_wand(I2CM_PORT_SCL, true);
				for (i = 0; i < 300; i++);
			}
			port_set_pin_function(I2CM_PORT_SDA, sdapf);
			port_set_pin_function(I2CM_PORT_SCL, sclpf);
			i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_ENABLE);
			i2cm_set_ENABLE(I2CM_PORT);

			i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_SYSOP);
			i2cm_write_STATUS(I2CM_PORT, SERCOM_I2CM_STATUS_BUSSTATE(I2CM_BUSSTATE_IDLE));
			if(i2cm_get_BUSSTATE(I2CM_PORT) != I2CM_BUSSTATE_IDLE) return I2CM_BUSFAULT;
		}
	}
	// disable interrupts while setting up message
	i2cm_clear_INTEN(I2CM_PORT, SERCOM_I2CM_INTENCLR_MB
 	             		  | SERCOM_I2CM_INTENCLR_SB
                		  | SERCOM_I2CM_INTENCLR_ERROR);
	slaveAddress = address;
	txbuf = wrbuf;
	rxbuf = rdbuf;
	txlen = wrlen;
	rxlen = rdlen;
	status = 0;
    // enable interrupts
	i2cm_set_INTEN(I2CM_PORT, SERCOM_I2CM_INTENSET_MB
 	             		  | SERCOM_I2CM_INTENSET_SB
                		  | SERCOM_I2CM_INTENSET_ERROR);

	i2cm_set_ACK(I2CM_PORT);
	// start the transfer by writing the target address
	i2cm_write_ADDR(I2CM_PORT, SERCOM_I2CM_ADDR_ADDR(slaveAddress << 1 
		| (((txlen == 0) && (rxlen > 0)) ? I2CM_RD : 0)));
 	return I2CM_OK;
}

i2cm_err_t writeI2C(uint8_t address, uint8_t *wrbuf, uint8_t wrlen)
{
	i2cm_err_t err = I2CM_OK;
	uint32_t count;
	I2CM_RTOS_TAKE
		err = i2cm_transfer(address, wrbuf, wrlen, NULL, 0);
		if (err == I2CM_OK) {
			count = getTimer();
			while((status & I2CM_READY) == 0) {
				if ((getTimer() - count) > (I2CMTO * 1000)) {
					err = I2CM_TIMEOUT;
					break;
				}
			}	
			if (status & I2CM_FAIL) err = I2CM_BUSFAULT;
			if (status & I2CM_NACK) err = I2CM_NO_ACK;
		}
    I2CM_RTOS_GIVE
	return err;
}

i2cm_err_t readI2C( uint8_t address, uint8_t *wrbuf, uint8_t wrlen, uint8_t *rdbuf, uint8_t rdlen)
{
	i2cm_err_t err = I2CM_OK;
	uint32_t count;
	I2CM_RTOS_TAKE
		err = i2cm_transfer(address, wrbuf, wrlen, rdbuf, rdlen);
		if (err == I2CM_OK) {
			count = getTimer();
			while((status & I2CM_READY) == 0) {
				if ((getTimer() - count) > (I2CMTO * 1000)) {
					err = I2CM_TIMEOUT;
					break;
				}
			}	
			if (status & I2CM_FAIL) err = I2CM_BUSFAULT;
			if (status & I2CM_NACK) err = I2CM_NO_ACK;
		}
    I2CM_RTOS_GIVE
	return err;
}

i2cm_err_t probeI2C(uint8_t address)
{
	i2cm_err_t err = I2CM_OK;
	uint32_t count;
	I2CM_RTOS_TAKE
		err = i2cm_transfer(address, NULL, 0, NULL, 0);
		if (err == I2CM_OK) {
			count = getTimer();
			while((status & I2CM_READY) == 0) {
				if ((getTimer() - count) > (I2CMTO * 1000)) {
					err = I2CM_TIMEOUT;
					break;
				}
			}	
			if (status & I2CM_FAIL) err = I2CM_BUSFAULT;
			if (status & I2CM_NACK) err = I2CM_NO_ACK;
		}
    I2CM_RTOS_GIVE
	return err;
}

/* Interrupt Service Routine for I2CM_PORT master on bus */
void I2CM_PORT_MB_Handler(void)
{
	uint16_t status;
	status = i2cm_read_STATUS(I2CM_PORT);
	// bus error check
	if (status & (SERCOM_I2CM_STATUS_ARBLOST | SERCOM_I2CM_STATUS_BUSERR)) {
		status |= I2CM_FAIL;
		status |= I2CM_READY;
		i2cm_clear_INTFLAG(I2CM_PORT, SERCOM_I2CM_INTFLAG_MB);
	// check for NACK from slave
	} else if (status & SERCOM_I2CM_STATUS_RXNACK) {
			status |= I2CM_NACK;
			status |= I2CM_READY;
 			i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_SYSOP);
			i2cm_set_CMD(I2CM_PORT, I2CM_CMD_STOP); // clears MB and issues stop
	// data write check
	} else if (txlen > 0) {
 		i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_SYSOP);
		i2cm_write_DATA(I2CM_PORT,*txbuf++);
		txlen--;
	// data read check
	} else {
		// data read check
 		if (rxlen > 0) {
 			// send ACK to slave while rxlen > 0
 			i2cm_set_ACK(I2CM_PORT);
			// force repeated start by sending address, clears MB int flag
 			i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_SYSOP);
			i2cm_write_ADDR(I2CM_PORT, SERCOM_I2CM_ADDR_ADDR((slaveAddress << 1) | I2CM_RD));
		// data read complete, issue stop
		} else { 
 			i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_SYSOP);
 			i2cm_set_CMD(I2CM_PORT, I2CM_CMD_STOP);
			status |= I2CM_READY;
		}
	}
}
/* Interrupt Service Routine for I2CM_PORT slave on bus */
void I2CM_PORT_SB_Handler(void)
{
   if (rxlen > 0) {
		rxlen--;
       if (rxlen == 0) {
			// send NACK and STOP for final byte
 			i2cm_wait_for_sync(I2CM_PORT, SERCOM_I2CM_SYNCBUSY_SYSOP);
 			i2cm_set_NACK(I2CM_PORT);
 			i2cm_set_CMD(I2CM_PORT, I2CM_CMD_STOP);
			status |= I2CM_READY;
		}
		// read data
		*rxbuf++ = i2cm_read_DATA(I2CM_PORT); // clears SB
	} 
	i2cm_clear_INTFLAG(I2CM_PORT, SERCOM_I2CM_INTFLAG_SB);
}
/* Interrupt Service Routine for I2CM_PORT error */
void I2CM_PORT_ERR_Handler(void)
{
	status |=  I2CM_FAIL;
	status |= I2CM_READY;
	i2cm_clear_INTFLAG(I2CM_PORT, SERCOM_I2CM_INTFLAG_ERROR);
}