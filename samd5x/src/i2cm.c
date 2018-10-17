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
#include "delay.h"

#define I2CMTO 500000
i2cm_err_t i2cm_transfer(volatile i2cm_msg_t *msg, uint8_t address, 
	uint8_t *wrbuf, uint8_t wrlen, 
	uint8_t *rdbuf, uint8_t rdlen)
{
	SERCOM_t *dev = (SERCOM_t *) msg->dev;
	volatile int32_t timeout = 65535;
	int sdahigh;
	volatile int i;
	int j;
	uint8_t sdapf;
	uint8_t sclpf;
	// If it is not enabled, then enable I2C
	if ((i2cm_read_CTRLA(dev) & SERCOM_I2CM_CTRLA_ENABLE) == 0) {
		i2cm_wait_for_sync(dev, SERCOM_I2CM_SYNCBUSY_ENABLE | SERCOM_I2CM_SYNCBUSY_SWRST);
		i2cm_set_ENABLE(dev);
	}
	// Check if the bus is busy
	while (i2cm_get_BUSSTATE(dev) != I2CM_BUSSTATE_IDLE) {
		if (--timeout <= 0) {
			// switch sda/scl to gpio and force clocks onto scl while
			// watching sda go high, this should clear any slave that
			// is out of sync
			i2cm_wait_for_sync(dev, SERCOM_I2CM_SYNCBUSY_ENABLE);
			i2cm_clear_ENABLE(dev);
			sdapf = port_get_pin_function(msg->sda);
			sclpf = port_get_pin_function(msg->scl);
			gpio_set_dir_out(msg->scl);
			gpio_set_dir_in(msg->sda);
			sdahigh = 0;
			for (j = 0; j < 100; j++) {
				if (gpio_get_in(msg->sda)) {
					if (++sdahigh > 8) break;
				} else {
					sdahigh = 0;
				}
				// drive the clock low, then release (open drain)
				gpio_set_wand(msg->scl, false);
				for (i = 0; i < 300; i++);
				gpio_set_wand(msg->scl, true);
				for (i = 0; i < 300; i++);
			}
			port_set_pin_function(msg->sda, sdapf);
			port_set_pin_function(msg->scl, sclpf);
			i2cm_wait_for_sync(dev, SERCOM_I2CM_SYNCBUSY_ENABLE);
			i2cm_set_ENABLE(dev);

			i2cm_wait_for_sync(dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
			i2cm_write_STATUS(dev, SERCOM_I2CM_STATUS_BUSSTATE(I2CM_BUSSTATE_IDLE));
			if(i2cm_get_BUSSTATE(dev) != I2CM_BUSSTATE_IDLE) return I2CM_BUSFAULT;
		}
	}
	// disable interrupts while setting up message
	i2cm_clear_INTEN(dev, SERCOM_I2CM_INTENCLR_MB
 	             		  | SERCOM_I2CM_INTENCLR_SB
                		  | SERCOM_I2CM_INTENCLR_ERROR);
	msg->address = address;
	msg->txbuf = wrbuf;
	msg->rxbuf = rdbuf;
	msg->txlen = wrlen;
	msg->rxlen = rdlen;
	msg->status = I2CM_BUSY;
    // enable interrupts
	i2cm_set_INTEN(dev, SERCOM_I2CM_INTENSET_MB
 	             		  | SERCOM_I2CM_INTENSET_SB
                		  | SERCOM_I2CM_INTENSET_ERROR);

	i2cm_set_ACK(dev);
	// start the transfer by writing the target address
	i2cm_write_ADDR(dev, SERCOM_I2CM_ADDR_ADDR(msg->address << 1 
		| (((msg->txlen == 0) && (msg->rxlen > 0)) ? I2CM_RD : 0)));
 	return I2CM_OK;
}

i2cm_err_t writeI2C(volatile i2cm_msg_t *msg, uint8_t address, uint8_t *wrbuf, uint8_t wrlen)
{
	i2cm_err_t stat;
	uint32_t count;
	stat = i2cm_transfer(msg, address, wrbuf, wrlen, NULL, 0);
	if(stat != I2CM_OK) return stat;
	count = get_timer();
	while(msg->status & I2CM_BUSY) {
		if ((get_timer() - count) > I2CMTO) return I2CM_TIMEOUT;
	}
	if (msg->status & I2CM_FAIL) return I2CM_BUSFAULT;
	if (msg->status & I2CM_NACK) return I2CM_NO_ACK;
	return I2CM_OK;
}

i2cm_err_t readI2C(volatile i2cm_msg_t *msg, uint8_t address, uint8_t *wrbuf, uint8_t wrlen, uint8_t *rdbuf, uint8_t rdlen)
{
	i2cm_err_t stat;
	uint32_t count;
	stat = i2cm_transfer(msg, address, wrbuf, wrlen, rdbuf, rdlen);
	if(stat != I2CM_OK) return stat;
	count = get_timer();
	while(msg->status & I2CM_BUSY) {
		if ((get_timer() - count) > I2CMTO) return I2CM_TIMEOUT;
	}
	if (msg->status & I2CM_FAIL) return I2CM_BUSFAULT;
	if (msg->status & I2CM_NACK) return I2CM_NO_ACK;
	return I2CM_OK;
}

i2cm_err_t probeI2C(volatile i2cm_msg_t *msg, uint8_t address)
{
	i2cm_err_t stat;
	uint32_t count;
	stat = i2cm_transfer(msg, address, NULL, 0, NULL, 0);
	if(stat != I2CM_OK) return stat;
	count = get_timer();
	while(msg->status & I2CM_BUSY) {
		if ((get_timer() - count) > I2CMTO) return I2CM_TIMEOUT;
	}
	if (msg->status & I2CM_NACK) return I2CM_NO_ACK;
	return I2CM_OK;
}

