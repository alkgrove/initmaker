/**
 * This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version beta
**/
/**
 * \file
 *
 * \brief SAM SERCOM
 *
 * Copyright (C) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 */

#ifndef _SERCOM_H_
#define _SERCOM_H_

#include <stdbool.h>
/* @note General Notes
 * Enable protected means that a register can only be written
 * when the peripheral is disabled
 * Write Synchronization means that while running the register can 
 * be changed after wait for Sync busy to go not busy
 */
 
/*
 * @note USART Baudrate calculation given baudrate ie 115200 and core
 * frequency of SERCOMn port. 
 */
#define USART_BAUDRATE(baud, freq)  (65536 - ((65536 * 16.0f * (baud)) / (freq)))
/**
 * @note baudrate for Standard I2C Master
 * The Trise variable is 215ns typical, freq is the core clock into SERCOM I2C
 * and baud is rate in frequency. No units. 
 * You must calculate I2C_BAUDLOW first and should test if it > 510 which means
 * baudrate is too low for frequency or <= 1 or too high. 
 */
#define I2CM_BAUDLOW(trise,baud,freq) ((((freq) - ((baud) * 10)  \
	   - (INT64_C(trise) * (INT64_C(baud) / 100) * (INT64_C(freq) / 10000) / 1000)) * 10 + 5) / ((baud) * 10))
 /*
  * @note baudrate for high speed I2C Master
  */
#define I2CM_HSBAUDLOW(baud,freq) ((((freq) - ((baud) * 2)) + ((baud) / 2))/(baud))
#define I2CM_BAUD(baudlow) (((baudlow) & 1) ? (((baudlow) / 2) + ((((baudlow) + 1) / 2) << 8)) : ((baudlow) / 2))
 /*
  * @note baudrate for SPI Master
  */

#define SPI_BAUD(baud, freq) (((float) (freq) / (float) (2 * (baud))) - 1)

// Control A Register Mode
#define SERCOM_MODE_USART_EXTCLK 0
#define SERCOM_MODE_USART_INTCLK 1
#define SERCOM_MODE_SPI_SLAVE  2
#define SERCOM_MODE_SPI_MASTER 3
#define SERCOM_MODE_I2C_SLAVE  4
#define SERCOM_MODE_I2C_MASTER 5
// I2CM Status Bus State
#define I2CM_BUSSTATE_UNKNOWN 0
#define I2CM_BUSSTATE_IDLE 	  1
#define I2CM_BUSSTATE_OWNER   2
#define I2CM_BUSSTATE_BUSY    3
// Control B Register CMD & ACK/NACK
#define SERCOM_I2CM_ACK   (0x1UL << SERCOM_I2CM_CTRLB_ACKACT_Pos)
#define SERCOM_I2CM_NACK  (0x0UL << SERCOM_I2CM_CTRLB_ACKACT_Pos)
#define I2CM_CMD_NOP	  (0x00UL << SERCOM_I2CM_CTRLB_CMD_Pos)
#define I2CM_CMD_RS		  (0x01UL << SERCOM_I2CM_CTRLB_CMD_Pos)
#define I2CM_CMD_RDACK	  (0x02UL << SERCOM_I2CM_CTRLB_CMD_Pos)
#define I2CM_CMD_STOP	  (0x03UL << SERCOM_I2CM_CTRLB_CMD_Pos)
// ADDR register
#define I2CM_RD			1
#define I2CM_WR			0

/**
 * @brief spin while I2C Master Sync Bit masked by reg become not busy
 *
 * @param[in] pSERCOM SERCOM_t*
 * @param[in] reg uint32_t
 * - SERCOM_I2CM_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_I2CM_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_I2CM_SYNCBUSY_SYSOP	System Operation Synchronization Busy 
 */
static inline void i2cm_wait_for_sync(SERCOM_t *pSERCOM, uint32_t reg)
{
	while (pSERCOM->I2CM.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief return true if I2C Master Sync Bit masked by reg is busy, false otherwise
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t
 * - SERCOM_I2CM_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_I2CM_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_I2CM_SYNCBUSY_SYSOP	System Operation Synchronization Busy 
 */
static inline bool i2cm_is_syncing(SERCOM_t *pSERCOM, uint32_t reg)
{
	return pSERCOM->I2CM.SYNCBUSY.reg & reg;
}

/**
 * @brief spin while register masked by reg is busy
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t
 * - SERCOM_I2CS_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_I2CS_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_I2CS_SYNCBUSY_LENGTH	Length Synchronization Busy 
 */
static inline void i2cs_wait_for_sync(SERCOM_t *pSERCOM, uint32_t reg)
{
	while (pSERCOM->I2CS.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief return true if I2C Slave Sync Busy is busy, false if not
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t
 * - SERCOM_I2CS_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_I2CS_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_I2CS_SYNCBUSY_LENGTH	Length Synchronization Busy 
 */
static inline bool i2cs_is_syncing(SERCOM_t *pSERCOM, uint32_t reg)
{
	return pSERCOM->I2CS.SYNCBUSY.reg & reg; // do proper boolean
}

/**
 * @brief spin while SPI Sync Busy register masked by reg shows busy
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t
 * - SERCOM_SPI_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_SPI_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_SPI_SYNCBUSY_CTRLB	CTRLB Synchronization Busy 
 * - SERCOM_SPI_SYNCBUSY_LENGTH	LENGTH Synchronization Busy 
 */
static inline void spi_wait_for_sync(SERCOM_t *pSERCOM, uint32_t reg)
{
	while (pSERCOM->SPI.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief return true if SPI Sync Busy is busy, false if not
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t
 * - SERCOM_SPI_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_SPI_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_SPI_SYNCBUSY_CTRLB	CTRLB Synchronization Busy 
 * - SERCOM_SPI_SYNCBUSY_LENGTH	LENGTH Synchronization Busy 
 */
static inline bool spi_is_syncing(SERCOM_t *pSERCOM, uint32_t reg)
{
	return pSERCOM->SPI.SYNCBUSY.reg & reg;
}

/**
 * @brief spins while waiting for sync busy to be not busy
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t
 * - SERCOM_USART_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_CTRLB	CTRLB Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_RXERRCNT	RXERRCNT Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_LENGTH	LENGTH Synchronization Busy 
 */
static inline void usart_wait_for_sync(SERCOM_t *pSERCOM, uint32_t reg)
{
	while (pSERCOM->USART.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief returns USART sync busy masked by reg
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t
 * - SERCOM_USART_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_CTRLB	CTRLB Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_RXERRCNT	RXERRCNT Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_LENGTH	LENGTH Synchronization Busy 
 */
static inline bool usart_is_syncing(SERCOM_t *pSERCOM, uint32_t reg)
{
	return pSERCOM->USART.SYNCBUSY.reg & reg;
}

/**
 * @brief set SPI interrupt enable register 1=enable interrupt, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_SPI_INTENSET_DRE	Data Register Empty Interrupt Enable 
 * - SERCOM_SPI_INTENSET_TXC	Transmit Complete Interrupt Enable 
 * - SERCOM_SPI_INTENSET_RXC	Receive Complete Interrupt Enable 
 * - SERCOM_SPI_INTENSET_SSL	Slave Select Low Interrupt Enable 
 * - SERCOM_SPI_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline void spi_set_INTEN(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->SPI.INTENSET.reg = reg;
}

/**
 * @brief read SPI interrupt enable register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_SPI_INTENSET_DRE	Data Register Empty Interrupt Enable 
 * - SERCOM_SPI_INTENSET_TXC	Transmit Complete Interrupt Enable 
 * - SERCOM_SPI_INTENSET_RXC	Receive Complete Interrupt Enable 
 * - SERCOM_SPI_INTENSET_SSL	Slave Select Low Interrupt Enable 
 * - SERCOM_SPI_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline uint8_t spi_read_INTEN(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.INTENSET.reg;
}

/**
 * @brief read SPI interrupt enable register with mask
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] mask - uint8_t
 * - SERCOM_SPI_INTENSET_DRE	Data Register Empty Interrupt Enable 
 * - SERCOM_SPI_INTENSET_TXC	Transmit Complete Interrupt Enable 
 * - SERCOM_SPI_INTENSET_RXC	Receive Complete Interrupt Enable 
 * - SERCOM_SPI_INTENSET_SSL	Slave Select Low Interrupt Enable 
 * - SERCOM_SPI_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline uint8_t spi_get_INTEN(SERCOM_t *pSERCOM, uint8_t mask)
{
	return pSERCOM->SPI.INTENSET.reg & mask;
}

/**
 * @brief write SPI interrupt enable register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data -  uint8_t
 * - SERCOM_SPI_INTENSET_DRE	Data Register Empty Interrupt Enable 
 * - SERCOM_SPI_INTENSET_TXC	Transmit Complete Interrupt Enable 
 * - SERCOM_SPI_INTENSET_RXC	Receive Complete Interrupt Enable 
 * - SERCOM_SPI_INTENSET_SSL	Slave Select Low Interrupt Enable 
 * - SERCOM_SPI_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline void spi_write_INTEN(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->SPI.INTENSET.reg = data;
	pSERCOM->SPI.INTENCLR.reg = ~data;
}

/**
 * @brief clear SPI interrupt enable register, 1=clears interrupt enable, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_SPI_INTENCLR_DRE	Data Register Empty Interrupt Disable 
 * - SERCOM_SPI_INTENCLR_TXC	Transmit Complete Interrupt Disable 
 * - SERCOM_SPI_INTENCLR_RXC	Receive Complete Interrupt Disable 
 * - SERCOM_SPI_INTENCLR_SSL	Slave Select Low Interrupt Disable 
 * - SERCOM_SPI_INTENCLR_ERROR	Combined Error Interrupt Disable 
 */
static inline void spi_clear_INTEN(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->SPI.INTENCLR.reg = reg;
}

/**
 * @brief read interrupt status flag
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_SPI_INTFLAG_DRE	Data Register Empty Interrupt 
 * - SERCOM_SPI_INTFLAG_TXC	Transmit Complete Interrupt 
 * - SERCOM_SPI_INTFLAG_RXC	Receive Complete Interrupt 
 * - SERCOM_SPI_INTFLAG_SSL	Slave Select Low Interrupt Flag 
 * - SERCOM_SPI_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline uint8_t spi_read_INTFLAG(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.INTFLAG.reg;
}

/**
 * @brief get interrupt status flag with mask
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] mask uint8_t
 * - SERCOM_SPI_INTFLAG_DRE	Data Register Empty Interrupt 
 * - SERCOM_SPI_INTFLAG_TXC	Transmit Complete Interrupt 
 * - SERCOM_SPI_INTFLAG_RXC	Receive Complete Interrupt 
 * - SERCOM_SPI_INTFLAG_SSL	Slave Select Low Interrupt Flag 
 * - SERCOM_SPI_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline uint8_t spi_get_INTFLAG(SERCOM_t *pSERCOM, uint8_t mask)
{
	return pSERCOM->SPI.INTFLAG.reg & mask;
}
/**
 * @brief clear interrupt status flag 1=clears flag, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_SPI_INTFLAG_DRE	Data Register Empty Interrupt 
 * - SERCOM_SPI_INTFLAG_TXC	Transmit Complete Interrupt 
 * - SERCOM_SPI_INTFLAG_RXC	Receive Complete Interrupt 
 * - SERCOM_SPI_INTFLAG_SSL	Slave Select Low Interrupt Flag 
 * - SERCOM_SPI_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline void spi_clear_INTFLAG(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->SPI.INTFLAG.reg = reg;
}

/**
 * @brief wait for sync and set software reset on SPI
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call spi_wait_for_sync(pSERCOM, SERCOM_SPI_SYNCBUSY_SWRST);
 */
static inline void spi_set_SWRST(SERCOM_t *pSERCOM)
{
	pSERCOM->SPI.CTRLA.reg |= SERCOM_SPI_CTRLA_SWRST;
}

/**
 * @brief wait for sync ans set SPI enable
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call spi_wait_for_sync(pSERCOM, SERCOM_SPI_SYNCBUSY_ENABLE);
 */
static inline void spi_set_ENABLE(SERCOM_t *pSERCOM)
{
	pSERCOM->SPI.CTRLA.reg |= SERCOM_SPI_CTRLA_ENABLE;
}

/**
 * @brief wait for sync ans clear SPI enable
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note spi_wait_for_sync(pSERCOM, SERCOM_SPI_SYNCBUSY_ENABLE);
 */
static inline void spi_clear_ENABLE(SERCOM_t *pSERCOM)
{
	pSERCOM->SPI.CTRLA.reg &= ~SERCOM_SPI_CTRLA_ENABLE;
}

/**
 * @brief write SPI Control A
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_SPI_CTRLA_SWRST	Software Reset
 * - SERCOM_SPI_CTRLA_ENABLE	Enable
 * - SERCOM_SPI_CTRLA_MODE(value)	Operating Mode 2=Slave, 3=Master
 * - SERCOM_SPI_CTRLA_RUNSTDBY	Run during Standby 
 * - SERCOM_SPI_CTRLA_IBON	Immediate Buffer Overflow Notification 
 * - SERCOM_SPI_CTRLA_DOPO(n)	Data Out Pinout PADn
 * - SERCOM_SPI_CTRLA_DIPO(n)	Data In Pinout PADn
 * - SERCOM_SPI_CTRLA_FORM(value)	Frame Format
 *  +    0=SPI Frame
 *  +    2=SPI Frame with Address
 * - SERCOM_SPI_CTRLA_CPHA	Clock Phase 
 *  +    0=The data is sampled on a leading SCK edge
 *  +    1=The data is sampled on a trailing SCK edge
 * - SERCOM_SPI_CTRLA_CPOL	Clock Polarity
 *  +    0=The leading edge of a clock cycle is a rising edge
 *  +    1=The leading edge of a clock cycle is a falling edge
 * - SERCOM_SPI_CTRLA_DORD	Data Order 0=MSB first, 1=LSB first
 * @note SWRST and ENABLE must be write synchronized
 * use spi_set_CTRLA_SWRST(), spi_set_CTRLA_ENABLE(), spi_clear_CTRLA_ENABLE()
 */
static inline void spi_write_CTRLA(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->SPI.CTRLA.reg = data;
}

/**
 * @brief read SPI Control A
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_SPI_CTRLA_SWRST	Software Reset 
 * - SERCOM_SPI_CTRLA_ENABLE	Enable 
 * - SERCOM_SPI_CTRLA_MODE(value)	Operating Mode 
 * - SERCOM_SPI_CTRLA_RUNSTDBY	Run during Standby 
 * - SERCOM_SPI_CTRLA_IBON	Immediate Buffer Overflow Notification 
 * - SERCOM_SPI_CTRLA_DOPO(n)	Data Out Pinout PADn
 * - SERCOM_SPI_CTRLA_DIPO(n)	Data In Pinout PADn
 * - SERCOM_SPI_CTRLA_FORM(value)	Frame Format
 *  +    0=SPI Frame
 *  +    2=SPI Frame with Address
 * - SERCOM_SPI_CTRLA_CPHA	Clock Phase 
 *  +    0=The data is sampled on a leading SCK edge
 *  +    1=The data is sampled on a trailing SCK edge
 * - SERCOM_SPI_CTRLA_CPOL	Clock Polarity
 *  +    0=The leading edge of a clock cycle is a rising edge
 *  +    1=The leading edge of a clock cycle is a falling edge
 * - SERCOM_SPI_CTRLA_DORD	Data Order 0=MSB first, 1=LSB first
 */
static inline uint32_t spi_read_CTRLA(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.CTRLA.reg;
}

/**
 * @brief write SPI control B register
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_SPI_CTRLB_CHSIZE(value) Character Size 0=8bit, 1=9bit
 * - SERCOM_SPI_CTRLB_PLOADEN	Data Preload Enable 
 * - SERCOM_SPI_CTRLB_SSDE	Slave Select Low Detect Enable 
 * - SERCOM_SPI_CTRLB_MSSEN	Master Slave Select Enable 
 * - SERCOM_SPI_CTRLB_AMODE	Address Mode
 *  +    0=ADDRMASK is used as a mask to the ADDR register
 *  +    1=The slave responds to the two unique addresses in ADDR and ADDRMASK
 *  +    2=The slave responds to the range of addresses between and including ADDR and ADDRMASK. ADDR is the upper limit
 * - SERCOM_SPI_CTRLB_RXEN	Receiver Enable 
 */
static inline void spi_write_CTRLB(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->SPI.CTRLB.reg = data;
}

/**
 * @brief set SPI control B register with mask
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] mask - uint32_t
 * - SERCOM_SPI_CTRLB_CHSIZE(value) Character Size 0=8bit, 1=9bit
 * - SERCOM_SPI_CTRLB_PLOADEN	Data Preload Enable 
 * - SERCOM_SPI_CTRLB_SSDE	Slave Select Low Detect Enable 
 * - SERCOM_SPI_CTRLB_MSSEN	Master Slave Select Enable 
 * - SERCOM_SPI_CTRLB_AMODE	Address Mode
 *  +    0=ADDRMASK is used as a mask to the ADDR register
 *  +    1=The slave responds to the two unique addresses in ADDR and ADDRMASK
 *  +    2=The slave responds to the range of addresses between and including ADDR and ADDRMASK. ADDR is the upper limit
 * - SERCOM_SPI_CTRLB_RXEN	Receiver Enable 
 */
static inline void spi_set_CTRLB(SERCOM_t *pSERCOM, uint32_t mask)
{
	pSERCOM->SPI.CTRLB.reg |= mask;
}

/**
 * @brief clear SPI control B register with mask
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] mask - uint32_t
 * - SERCOM_SPI_CTRLB_CHSIZE(value) Character Size 0=8bit, 1=9bit
 * - SERCOM_SPI_CTRLB_PLOADEN	Data Preload Enable 
 * - SERCOM_SPI_CTRLB_SSDE	Slave Select Low Detect Enable 
 * - SERCOM_SPI_CTRLB_MSSEN	Master Slave Select Enable 
 * - SERCOM_SPI_CTRLB_AMODE	Address Mode
 *  +    0=ADDRMASK is used as a mask to the ADDR register
 *  +    1=The slave responds to the two unique addresses in ADDR and ADDRMASK
 *  +    2=The slave responds to the range of addresses between and including ADDR and ADDRMASK. ADDR is the upper limit
 * - SERCOM_SPI_CTRLB_RXEN	Receiver Enable 
 */
static inline void spi_clear_CTRLB(SERCOM_t *pSERCOM, uint32_t mask)
{
	pSERCOM->SPI.CTRLB.reg &= ~mask;
}
/**
 * @brief read SPI control B register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_SPI_CTRLB_CHSIZE(value) Character Size 0=8bit, 1=9bit
 * - SERCOM_SPI_CTRLB_PLOADEN	Data Preload Enable 
 * - SERCOM_SPI_CTRLB_SSDE	Slave Select Low Detect Enable 
 * - SERCOM_SPI_CTRLB_MSSEN	Master Slave Select Enable 
 * - SERCOM_SPI_CTRLB_AMODE	Address Mode
 *  +    0=ADDRMASK is used as a mask to the ADDR register
 *  +    1=The slave responds to the two unique addresses in ADDR and ADDRMASK
 *  +    2=The slave responds to the range of addresses between and including ADDR and ADDRMASK. ADDR is the upper limit
 * - SERCOM_SPI_CTRLB_RXEN	Receiver Enable 
 */
 
static inline uint32_t spi_read_CTRLB(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.CTRLB.reg;
}

/**
 * @brief write SPI Control C
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_SPI_CTRLC_ICSPACE(value) 6bit Inter-Character Spacing 
 * - SERCOM_SPI_CTRLC_DATA32B	Data 32 Bit 
 */
static inline void spi_write_CTRLC(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->SPI.CTRLC.reg = data;
}

/**
 * @brief set SPI Control C with mask
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] mask - uint32_t
 * - SERCOM_SPI_CTRLC_ICSPACE(value) 6bit Inter-Character Spacing 
 * - SERCOM_SPI_CTRLC_DATA32B	Data 32 Bit 
 */
static inline void spi_set_CTRLC(SERCOM_t *pSERCOM, uint32_t mask)
{
	pSERCOM->SPI.CTRLC.reg |= mask;
}

/**
 * @brief clear SPI Control C with mask
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] mask - uint32_t
 * - SERCOM_SPI_CTRLC_ICSPACE(value) 6bit Inter-Character Spacing 
 * - SERCOM_SPI_CTRLC_DATA32B	Data 32 Bit 
 */
static inline void spi_clear_CTRLC(SERCOM_t *pSERCOM, uint32_t mask)
{
	pSERCOM->SPI.CTRLC.reg &= ~mask;
}

/**
 * @brief read SPI Control C
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_SPI_CTRLC_ICSPACE(value) 6bit Inter-Character Spacing 
 * - SERCOM_SPI_CTRLC_DATA32B	Data 32 Bit 
 */
static inline uint32_t spi_read_CTRLC(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.CTRLC.reg;
}

/**
 * @brief write SPI Baud rate register
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint8_t
 * - SERCOM_SPI_BAUD_BAUD(value) 
 */
static inline void spi_write_BAUD(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->SPI.BAUD.reg = data;
}

/**
 * @brief read SPI Baud rate register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_SPI_BAUD_BAUD(value) 8 bit 
 */
static inline uint8_t spi_read_BAUD(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.BAUD.reg;
}

/**
 * @brief write SPI length register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint16_t
 * - SERCOM_SPI_LENGTH_LEN(value)	8bit Data Length 
 * - SERCOM_SPI_LENGTH_LENEN	Data Length Enable 
 * @note LENGTH must be write synchronized. 
 * use spi_wait_for_sync(pSERCOM, SERCOM_SPI_SYNCBUSY_LENGTH);
 */
static inline void spi_write_LENGTH(SERCOM_t *pSERCOM, uint16_t data)
{
	pSERCOM->SPI.LENGTH.reg = data;
}

static inline uint16_t spi_read_LENGTH(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.LENGTH.reg;
}

/**
 * @brief write SPI Address
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_SPI_ADDR_ADDR(value)	   8 bit Address Value 
 * - SERCOM_SPI_ADDR_ADDRMASK(value) 8 bit Address Mask 
 * @return
 */
static inline void spi_write_ADDR(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->SPI.ADDR.reg = data;
}

/**
 * @brief read SPI Address and address mask
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_SPI_ADDR_ADDR(value)	   8 bit Address Value 
 * - SERCOM_SPI_ADDR_ADDRMASK(value) 8 bit Address Mask 
 * @return
 */
static inline uint32_t spi_read_ADDR(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.ADDR.reg;
}

/**
 * @brief read SPI Data
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t 32 bit data
 */
static inline uint32_t spi_read_DATA(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.DATA.reg;
}
/**
 * @brief write SPI data
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t 32 bit data
 */
static inline void spi_write_DATA(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->SPI.DATA.reg = data;
}

/**
 * @brief write SPI Debug Control Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint8_t
 * - SERCOM_SPI_DBGCTRL_DBGSTOP	Debug Stop Mode
 */
static inline void spi_write_DBGCTRL(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->SPI.DBGCTRL.reg = data;
}

/**
 * @brief read SPI Debug Control Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * - SERCOM_SPI_DBGCTRL_DBGSTOP	Debug Stop Mode
 */
static inline uint8_t spi_read_DBGCTRL(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.DBGCTRL.reg;
}

/**
 * @brief read USART Sync Busy Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return
 * - SERCOM_USART_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_CTRLB	CTRLB Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_RXERRCNT	RXERRCNT Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_LENGTH	LENGTH Synchronization Busy 
 */
static inline uint32_t spi_read_SYNCBUSY(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.SYNCBUSY.reg;
}

/**
 * @brief clear SPI Status Register with mask
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint16_t
 * - SERCOM_SPI_STATUS_BUFOVF	Buffer Overflow 
 * - SERCOM_SPI_STATUS_LENERR	Transaction Length Error 
 * 
 */
static inline void spi_clear_STATUS(SERCOM_t *pSERCOM, uint16_t reg)
{
	pSERCOM->SPI.STATUS.reg = reg;
}
/**
 * @brief read SPI Status Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint16_t
 * - SERCOM_SPI_STATUS_BUFOVF	Buffer Overflow 
 * - SERCOM_SPI_STATUS_LENERR	Transaction Length Error 
 * 
 */
static inline uint16_t spi_read_STATUS(SERCOM_t *pSERCOM)
{
	return pSERCOM->SPI.STATUS.reg;
}

/**
 * @brief read SPI Status Register with mask
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] mask - uint16_t
 * - SERCOM_SPI_STATUS_BUFOVF	Buffer Overflow 
 * - SERCOM_SPI_STATUS_LENERR	Transaction Length Error 
 * 
 */
static inline uint16_t spi_get_STATUS(SERCOM_t *pSERCOM, uint16_t mask)
{
	return pSERCOM->SPI.STATUS.reg & mask;
}
/**
 * @brief Set I2C Master Interrupt Enable 1=enable, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg -  uint8_t
 * - SERCOM_I2CM_INTENSET_MB	Master On Bus Interrupt Enable 
 * - SERCOM_I2CM_INTENSET_SB	Slave On Bus Interrupt Enable 
 * - SERCOM_I2CM_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline void i2cm_set_INTEN(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->I2CM.INTENSET.reg = reg;
}

/**
 * @brief Read I2C Master Interrupt Enable
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_I2CM_INTENSET_MB	Master On Bus Interrupt Enable 
 * - SERCOM_I2CM_INTENSET_SB	Slave On Bus Interrupt Enable 
 * - SERCOM_I2CM_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline uint8_t i2cm_read_INTEN(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.INTENSET.reg;
}

/**
 * @brief Write I2C Master Interrupt Enable
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint8_t
 * - SERCOM_I2CM_INTENSET_MB	Master On Bus Interrupt Enable 
 * - SERCOM_I2CM_INTENSET_SB	Slave On Bus Interrupt Enable 
 * - SERCOM_I2CM_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline void i2cm_write_INTEN(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->I2CM.INTENSET.reg = data;
	pSERCOM->I2CM.INTENCLR.reg = ~data;
}
/**
 * @brief Clear I2C Master Interrupt Enable bits 1=disable interrupt, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_I2CM_INTENCLR_MB	Master On Bus Interrupt Disable 
 * - SERCOM_I2CM_INTENCLR_SB	Slave On Bus Interrupt Disable 
 * - SERCOM_I2CM_INTENCLR_ERROR	Combined Error Interrupt Disable 
 */
static inline void i2cm_clear_INTEN(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->I2CM.INTENCLR.reg = reg;
}

/**
 * @brief read I2C Master Interrupt Status
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_I2CM_INTFLAG_MB	Master On Bus Interrupt 
 * - SERCOM_I2CM_INTFLAG_SB	Slave On Bus Interrupt 
 * - SERCOM_I2CM_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline uint8_t i2cm_read_INTFLAG(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.INTFLAG.reg;
}

/**
 * @brief clear I2C Master Interrupt flag bit 1=clear, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t reg
 * - SERCOM_I2CM_INTFLAG_MB		Master On Bus Interrupt 
 * - SERCOM_I2CM_INTFLAG_SB		Slave On Bus Interrupt 
 * - SERCOM_I2CM_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline void i2cm_clear_INTFLAG(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->I2CM.INTFLAG.reg = reg;
}

/**
 * @brief set I2C Master bus state to idle synchronized
 * you can only set bus state to idle (1)
 * @param[in] pSERCOM - SERCOM_t*
 * @note needs to be synchronized with 
 * i2cm_wait_for_sync(pSERCOM, SERCOM_I2CM_SYNCBUSY_SYSOP);
 *
 */
static inline void i2cm_force_idle(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CM.STATUS.reg = (pSERCOM->I2CM.STATUS.reg & ~SERCOM_I2CM_STATUS_BUSSTATE_Msk) 
								| SERCOM_I2CM_STATUS_BUSSTATE(I2CM_BUSSTATE_IDLE); // idle state
}

/**
 * @brief return bus state of I2C master
 *  +    0 = I2CM_BUSSTATE_UNKNOWN
 *  +    1 = I2CM_BUSSTATE_IDLE 	 
 *  +    2 = I2CM_BUSSTATE_OWNER  
 *  +    3 = I2CM_BUSSTATE_BUSY   
 *
 * @param[in] pSERCOM - SERCOM_t * pointer to SERCOMn registers
 * @return uint16_t status
 */
static inline uint16_t i2cm_get_BUSSTATE(SERCOM_t *pSERCOM)
{
	return (pSERCOM->I2CM.STATUS.reg & SERCOM_I2CM_STATUS_BUSSTATE_Msk) >> SERCOM_I2CM_STATUS_BUSSTATE_Pos;
}
/**
 * @brief Read I2C Master Status
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint16_t
 * - SERCOM_I2CM_STATUS_BUSERR	Bus Error 
 * - SERCOM_I2CM_STATUS_ARBLOST	Arbitration Lost 
 * - SERCOM_I2CM_STATUS_RXNACK	Received Not Acknowledge 
 * - SERCOM_I2CM_STATUS_BUSSTATE(value)	Bus State 
 * - SERCOM_I2CM_STATUS_LOWTOUT	SCL Low Timeout 
 * - SERCOM_I2CM_STATUS_CLKHOLD	Clock Hold 
 * - SERCOM_I2CM_STATUS_MEXTTOUT	Master SCL Low Extend Timeout 
 * - SERCOM_I2CM_STATUS_SEXTTOUT	Slave SCL Low Extend Timeout 
 * - SERCOM_I2CM_STATUS_LENERR	Length Error 
 */
static inline uint16_t i2cm_read_STATUS(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.STATUS.reg;
}

/**
 * @brief Clear I2C Master Status 1=Clear Status Bit, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint16_t
 * - SERCOM_I2CM_STATUS_BUSERR	Bus Error 
 * - SERCOM_I2CM_STATUS_ARBLOST	Arbitration Lost 
 * - SERCOM_I2CM_STATUS_RXNACK	Received Not Acknowledge 
 * - SERCOM_I2CM_STATUS_BUSSTATE(value)	Bus State 
 * - SERCOM_I2CM_STATUS_LOWTOUT	SCL Low Timeout 
 * - SERCOM_I2CM_STATUS_CLKHOLD	Clock Hold 
 * - SERCOM_I2CM_STATUS_MEXTTOUT	Master SCL Low Extend Timeout 
 * - SERCOM_I2CM_STATUS_SEXTTOUT	Slave SCL Low Extend Timeout 
 * - SERCOM_I2CM_STATUS_LENERR	Length Error 
 * @note call i2cm_wait_for_sync(pSERCOM, SERCOM_I2CM_SYNCBUSY_SYSOP);
 */
static inline void i2cm_write_STATUS(SERCOM_t *pSERCOM, uint16_t data)
{
	pSERCOM->I2CM.STATUS.reg = data;
}

/**
 * @brief Do software reset on I2C Master
 * 
 * @param[in] pSERCOM - SERCOM_t*
 * @note call i2cm_wait_for_sync(pSERCOM, SERCOM_I2CM_SYNCBUSY_SWRST);
 */
static inline void i2cm_set_SWRST(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CM.CTRLA.reg = SERCOM_I2CM_CTRLA_SWRST;
}

/**
 * @brief enable I2C Master
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call i2cm_wait_for_sync(pSERCOM, SERCOM_I2CM_SYNCBUSY_ENABLE);
 */
static inline void i2cm_set_ENABLE(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CM.CTRLA.reg |= SERCOM_I2CM_CTRLA_ENABLE;
}

/**
 * @brief set I2C Master Control B Command with synchronization
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t ACK or NACK
 *  +    SERCOM_I2CM_ACK - set ACK
 *  +    SERCOM_I2CM_NACK - set NACK
 */

/**
 * @brief clear the ACKACT bit in control B register to indicate ACK
 *
 * @param[in] pSERCOM - SERCOM_t*
 */
static inline void i2cm_set_ACK(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CM.CTRLB.reg &= ~SERCOM_I2CM_CTRLB_ACKACT;
}

/**
 * @brief set the ACKACT bit in control B register to indicate NACK
 *
 * @param[in] pSERCOM - SERCOM_t*
 */
static inline void i2cm_set_NACK(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CM.CTRLB.reg |= SERCOM_I2CM_CTRLB_ACKACT;
}

/**
 * @brief set I2C Master Control B Command with synchronization
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint32_t 2 bit command
 *  +    I2CM_CMD_NOP = no operation
 *  +    I2CM_CMD_RS = Execute acknowledge action succeeded by repeated Start
 *  +    I2CM_CMD_RDACK (Read) Execute acknowledge action succeeded by a byte read operation (Write is no operation)
 *  +    I2CM_CMD_STOP Execute acknowledge action succeeded by issuing a stop condition
 * @note call i2cm_wait_for_sync(pSERCOM, SERCOM_I2CM_SYNCBUSY_SYSOP);
 * @note the CMD bits are read as zero and do not need to be masked
 */

static inline void i2cm_set_CMD(SERCOM_t *pSERCOM, uint32_t reg)
{
	pSERCOM->I2CM.CTRLB.reg |= (reg & SERCOM_I2CM_CTRLB_CMD_Msk);
}

/**
 * @brief disable I2C Master by clearing control A enable
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call i2cm_wait_for_sync(pSERCOM, SERCOM_I2CM_SYNCBUSY_ENABLE);
 */
static inline void i2cm_clear_ENABLE(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CM.CTRLA.reg &= ~SERCOM_I2CM_CTRLA_ENABLE;
}

/**
 * @brief write I2C Master Control A
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CM_CTRLA_SWRST	Software Reset 
 * - SERCOM_I2CM_CTRLA_ENABLE	Enable 
 * @note SWRST and ENABLE must be write synchronized
 * use i2cm_set_CTRLA_SWRST(), i2cm_set_CTRLA_ENABLE(), i2cm_clear_CTRLA_ENABLE()
 * if SWRST is used, all other bits are ignored
 * - SERCOM_I2CM_CTRLA_MODE(value) Operating Mode 5 = Master
 * - SERCOM_I2CM_CTRLA_RUNSTDBY	Run in Standby 
 * - SERCOM_I2CM_CTRLA_PINOUT		Pin Usage '0'=2 wire, '1'=4 wire
 * - SERCOM_I2CM_CTRLA_SDAHOLD(value)	SDA Hold Time 
 *  +    0 = Disabled
 *  +    1 = 50-100ns hold time
 *  +    2 = 300-600ns hold time <-
 *  +    3 = 400-800ns hold time
 * - SERCOM_I2CM_CTRLA_MEXTTOEN	Master SCL Low Extend Timeout 
 * - SERCOM_I2CM_CTRLA_SEXTTOEN	Slave SCL Low Extend Timeout 
 * - SERCOM_I2CM_CTRLA_SPEED(value) Transfer Speed 
 *  +    0 = Standard-mode (Sm) up to 100 kHz and Fast-mode (Fm) up to 400 kHz <-
 *  +    1 = Fast-mode Plus (Fm+) up to 1 MHz
 *  +    2 = High-speed mode (Hs-mode) up to 3.4 MHz
 * - SERCOM_I2CM_CTRLA_SCLSM		SCL Clock Stretch Mode 
 * - SERCOM_I2CM_CTRLA_INACTOUT(value) Inactive Time-Out 
 * - SERCOM_I2CM_CTRLA_LOWTOUTEN	SCL Low Timeout Enable 
 */
static inline void i2cm_write_CTRLA(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CM.CTRLA.reg = data;
}

/**
 * @brief read I2C Master Control A
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CM_CTRLA_SWRST	Software Reset
 * - SERCOM_I2CM_CTRLA_ENABLE	Enable 
 * - SERCOM_I2CM_CTRLA_MODE(value) Operating Mode 5 = Master
 * - SERCOM_I2CM_CTRLA_RUNSTDBY	Run in Standby 
 * - SERCOM_I2CM_CTRLA_PINOUT		Pin Usage 
 * - SERCOM_I2CM_CTRLA_SDAHOLD(value)	SDA Hold Time 
 *  +    0 = Disabled
 *  +    1 = 50-100ns hold time
 *  +    2 = 300-600ns hold time
 *  +    3 = 400-800ns hold time
 * - SERCOM_I2CM_CTRLA_MEXTTOEN	Master SCL Low Extend Timeout 
 * - SERCOM_I2CM_CTRLA_SEXTTOEN	Slave SCL Low Extend Timeout 
 * - SERCOM_I2CM_CTRLA_SPEED(value) Transfer Speed 
 *  +    0 = Standard-mode (Sm) up to 100 kHz and Fast-mode (Fm) up to 400 kHz
 *  +    1 = Fast-mode Plus (Fm+) up to 1 MHz
 *  +    2 = High-speed mode (Hs-mode) up to 3.4 MHz
 * - SERCOM_I2CM_CTRLA_SCLSM		SCL Clock Stretch Mode 
 * - SERCOM_I2CM_CTRLA_INACTOUT(value) Inactive Time-Out 
 * - SERCOM_I2CM_CTRLA_LOWTOUTEN	SCL Low Timeout Enable 
 */
static inline uint32_t i2cm_read_CTRLA(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.CTRLA.reg;
}


/**
 * @brief write I2C Master Control B
 * Enabled Protected - only write when disabled
 * @note CTRLB.CMD must be write synchronized
 * use i2cm_wait_for_sync(pSERCOM, I2CM_SYNCBUSY_SYSOP);
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CM_CTRLB_SMEN	Smart Mode Enable 
 * - SERCOM_I2CM_CTRLB_QCEN	Quick Command Enable 
 * - SERCOM_I2CM_CTRLB_CMD(value)	Command 
 *  +    0 = no operation
 *  +    1 = Execute acknowledge action succeeded by repeated Start
 *  +    2 (Write) No operation
 *  +    2 (Read) Execute acknowledge action succeeded by a byte read operation
 *  +    3 Execute acknowledge action succeeded by issuing a stop condition
 * - SERCOM_I2CM_CTRLB_ACKACT	Acknowledge Action 0=send ACK, 1=send NACK
 * @note call i2cm_wait_for_sync(pSERCOM, SERCOM_I2CM_SYNCBUSY_SYSOP);
 */
static inline void i2cm_write_CTRLB(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CM.CTRLB.reg = data;
}

/**
 * @brief read I2C Master Control B
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CM_CTRLB_SMEN	Smart Mode Enable 
 * - SERCOM_I2CM_CTRLB_QCEN	Quick Command Enable 
 * - SERCOM_I2CM_CTRLB_CMD	Command 
 * - SERCOM_I2CM_CTRLB_ACKACT	Acknowledge Action 
 */
static inline uint32_t i2cm_read_CTRLB(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.CTRLB.reg;
}

/**
 * @brief Write I2C Master Control C
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CM_CTRLC_DATA32B	Data 32 Bit 1=32 bit data, 0=8 bit data
 */
static inline void i2cm_write_CTRLC(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CM.CTRLC.reg = data;
}

/**
 * @brief Read I2C Master Control C
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CM_CTRLC_DATA32B	Data 32 Bit 1=32 bit data, 0=8 bit data
 */
static inline uint32_t i2cm_read_CTRLC(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.CTRLC.reg;
}

/**
 * @brief write I2C Master baudrate
 * Enabled Protected - only write when disabled
 * Use I2CM_BAUDLOW to calculate baud and test
 * if between 510 and 1, then use I2CM_BAUD(i2c_baudlow) to 
 * pass to this as data
 * If High Speed I2C (HS) use i2cm_write_HSBAUD instead
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CM_BAUD_BAUD(value)	     Baud Rate Value 
 * - SERCOM_I2CM_BAUD_BAUDLOW(value)   Baud Rate Value Low 
 * - SERCOM_I2CM_BAUD_HSBAUD(value)    High Speed Baud Rate Value 
 * - SERCOM_I2CM_BAUD_HSBAUDLOW(value) High Speed Baud Rate Value Low 
 */
static inline void i2cm_write_BAUD(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CM.BAUD.reg = data;
}

/**
 * @brief write I2C Master high speed baudrate
 * Enabled Protected - only write when disabled
 * Use I2CM_HSBAUDLOW to calculate baud and test
 * if between 510 and 1, then use I2CM_BAUD(i2c_hsbaudlow) to 
 * pass to this as data
 * If standard I2C (HS) use i2cm_write_BAUD instead
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CM_BAUD_BAUD(value)	     Baud Rate Value 
 * - SERCOM_I2CM_BAUD_BAUDLOW(value)   Baud Rate Value Low 
 * - SERCOM_I2CM_BAUD_HSBAUD(value)    High Speed Baud Rate Value 
 * - SERCOM_I2CM_BAUD_HSBAUDLOW(value) High Speed Baud Rate Value Low 
 */
static inline void i2cm_write_HSBAUD(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CM.BAUD.reg = data << 16;
}
/**
 * @brief read I2C Master baudrate
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CM_BAUD_BAUD(value)	     Baud Rate Value 
 * - SERCOM_I2CM_BAUD_BAUDLOW(value)   Baud Rate Value Low 
 * - SERCOM_I2CM_BAUD_HSBAUD(value)    High Speed Baud Rate Value 
 * - SERCOM_I2CM_BAUD_HSBAUDLOW(value) High Speed Baud Rate Value Low 
 */
static inline uint32_t i2cm_read_BAUD(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.BAUD.reg;
}

/**
 * @brief write I2C Master Address
 * Enabled Protected - only write when disabled
 * @note ADDR must be write synchronized. 
 * use i2cm_wait_for_sync(pSERCOM, I2CM_SYNCBUSY_SYSOP);
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CM_ADDR_ADDR(value)	Address Value 
 * - SERCOM_I2CM_ADDR_LENEN	Length Enable 
 * - SERCOM_I2CM_ADDR_HS		High Speed Mode 
 * - SERCOM_I2CM_ADDR_TENBITEN	Ten Bit Addressing Enable 
 * - SERCOM_I2CM_ADDR_LEN(value)	Length 
 */
static inline void i2cm_write_ADDR(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CM.ADDR.reg = data;
}

/**
 * @brief read I2C Master Address
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return
 * - SERCOM_I2CM_ADDR_ADDR	Address Value 
 * - SERCOM_I2CM_ADDR_LENEN	Length Enable 
 * - SERCOM_I2CM_ADDR_HS		High Speed Mode 
 * - SERCOM_I2CM_ADDR_TENBITEN	Ten Bit Addressing Enable 
 * - SERCOM_I2CM_ADDR_LEN		Length 
 */
static inline uint32_t i2cm_read_ADDR(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.ADDR.reg;
}

/**
 * @brief Read I2C Master Data
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t data
 */
static inline uint32_t i2cm_read_DATA(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.DATA.reg;
}

/**
 * @brief Write I2C Master Data
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 */
static inline void i2cm_write_DATA(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CM.DATA.reg = data;
}

/**
 * @brief Write I2C Master Debug Control
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint8_t
 * - SERCOM_I2CM_DBGCTRL_DBGSTOP Debug Mode
 */
static inline void i2cm_write_DBGCTRL(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->I2CM.DBGCTRL.reg = data;
}

/**
 * @brief Read I2C Master Debug Control
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_I2CM_DBGCTRL_DBGSTOP Debug Mode
 */
static inline uint8_t i2cm_read_DBGCTRL(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.DBGCTRL.reg;
}

/**
 * @brief Read I2C Master Sync Busy bit 1=busy, 0=not busy 
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CM_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_I2CM_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_I2CM_SYNCBUSY_SYSOP	System Operation Synchronization Busy 
 */
static inline uint32_t i2cm_read_SYNCBUSY(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CM.SYNCBUSY.reg;
}

/**
 * @brief write baud rate register
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint16_t
 * - SERCOM_USART_BAUD_BAUD(value) baud rate
 */
static inline void usart_write_BAUD(SERCOM_t *pSERCOM, uint16_t data)
{
	pSERCOM->USART.BAUD.reg = data;
}

/**
 * @brief read baud rate register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint16_t
 * - SERCOM_USART_BAUD_BAUD(value) baud rate
 */
static inline uint16_t usart_read_BAUD(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.BAUD.reg;
}

/**
 * @brief set USART Interrupt Enable Register 1=enable interrupt, 0=no change
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_USART_INTENSET_DRE	Data Register Empty Interrupt Enable 
 * - SERCOM_USART_INTENSET_TXC	Transmit Complete Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXC	Receive Complete Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXS	Receive Start Interrupt Enable 
 * - SERCOM_USART_INTENSET_CTSIC	Clear To Send Input Change Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXBRK	Break Received Interrupt Enable 
 * - SERCOM_USART_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline void usart_set_INTEN(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->USART.INTENSET.reg = reg;
}

/**
 * @brief read USART Interrupt Enable Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_USART_INTENSET_DRE	Data Register Empty Interrupt Enable 
 * - SERCOM_USART_INTENSET_TXC	Transmit Complete Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXC	Receive Complete Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXS	Receive Start Interrupt Enable 
 * - SERCOM_USART_INTENSET_CTSIC	Clear To Send Input Change Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXBRK	Break Received Interrupt Enable 
 * - SERCOM_USART_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline uint8_t usart_read_INTEN(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.INTENSET.reg;
}

/**
 * @brief write USART Interrupt Enable Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint8_t
 * - SERCOM_USART_INTENSET_DRE	Data Register Empty Interrupt Enable 
 * - SERCOM_USART_INTENSET_TXC	Transmit Complete Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXC	Receive Complete Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXS	Receive Start Interrupt Enable 
 * - SERCOM_USART_INTENSET_CTSIC	Clear To Send Input Change Interrupt Enable 
 * - SERCOM_USART_INTENSET_RXBRK	Break Received Interrupt Enable 
 * - SERCOM_USART_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline void usart_write_INTEN(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->USART.INTENSET.reg = data;
	pSERCOM->USART.INTENCLR.reg = ~data;
}

/**
 * @brief clear USART Interrupt Enable
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_USART_INTENCLR_DRE	Data Register Empty Interrupt Disable 
 * - SERCOM_USART_INTENCLR_TXC	Transmit Complete Interrupt Disable 
 * - SERCOM_USART_INTENCLR_RXC	Receive Complete Interrupt Disable 
 * - SERCOM_USART_INTENCLR_RXS	Receive Start Interrupt Disable 
 * - SERCOM_USART_INTENCLR_CTSIC	Clear To Send Input Change Interrupt Disable 
 * - SERCOM_USART_INTENCLR_RXBRK	Break Received Interrupt Disable 
 * - SERCOM_USART_INTENCLR_ERROR	Combined Error Interrupt Disable 
 */
static inline void usart_clear_INTEN(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->USART.INTENCLR.reg = reg;
}

/**
 * @brief read USART Interrupt Status Flag
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_USART_INTFLAG_DRE	Data Register Empty Interrupt 
 * - SERCOM_USART_INTFLAG_TXC	Transmit Complete Interrupt 
 * - SERCOM_USART_INTFLAG_RXC	Receive Complete Interrupt 
 * - SERCOM_USART_INTFLAG_RXS	Receive Start Interrupt 
 * - SERCOM_USART_INTFLAG_CTSIC	Clear To Send Input Change Interrupt 
 * - SERCOM_USART_INTFLAG_RXBRK	Break Received Interrupt 
 * - SERCOM_USART_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline uint8_t usart_read_INTFLAG(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.INTFLAG.reg;
}

/**
 * @brief clear USART Interrupt Status Flag
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_USART_INTFLAG_DRE	Data Register Empty Interrupt 
 * - SERCOM_USART_INTFLAG_TXC	Transmit Complete Interrupt 
 * - SERCOM_USART_INTFLAG_RXC	Receive Complete Interrupt 
 * - SERCOM_USART_INTFLAG_RXS	Receive Start Interrupt 
 * - SERCOM_USART_INTFLAG_CTSIC	Clear To Send Input Change Interrupt 
 * - SERCOM_USART_INTFLAG_RXBRK	Break Received Interrupt 
 * - SERCOM_USART_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline void usart_clear_INTFLAG(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->USART.INTFLAG.reg = reg;
}

/**
 * @brief write USART Control A
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_USART_CTRLA_SWRST	 Software Reset 
 * - SERCOM_USART_CTRLA_ENABLE Enable 
 * - SERCOM_USART_CTRLA_MODE(value) Operating Mode 0=USART with external clock, 1=USART with internal clock
 * - SERCOM_USART_CTRLA_RUNSTDBY	Run during Standby 
 * - SERCOM_USART_CTRLA_IBON	Immediate Buffer Overflow Notification 
 * - SERCOM_USART_CTRLA_TXINV	Transmit Data Invert 
 * - SERCOM_USART_CTRLA_RXINV	Receive Data Invert 
 * - SERCOM_USART_CTRLA_SAMPR(value)	Sample 
 *  +    0=16x over-sampling using arithmetic baud rate generation.
 *  +    1=16x over-sampling using fractional baud rate generation.
 *  +    2=8x over-sampling using arithmetic baud rate generation.
 *  +    3=8x over-sampling using fractional baud rate generation.
 *  +    4=3x over-sampling using arithmetic baud rate generation.
 * - SERCOM_USART_CTRLA_TXPO	Transmit Data Pinout 
 *  +    0=TXD is PAD0, XCK is PAD1
 *  +    2=TXD is PAD0, RTS is PAD2, CTS is PAD3
 *  +    3=TXD is PAD0, XCK is PAD1, RTS is PAD2
 * - SERCOM_USART_CTRLA_RXPO	Receive Data Pinout PADn
 * - SERCOM_USART_CTRLA_SAMPA	Sample Adjustment 
 *  +    0= 16X=7-8-9, 8X=3-4-5
 *  +    1= 16X=9-10-11, 8X=4-5-6
 *  +    2= 16X=11-12-13, 8X=5-6-7
 *  +    3= 16X=13-14-15, 8X=6-7-8
 * - SERCOM_USART_CTRLA_FORM	Frame Format 
 *  +    0=USART frame
 *  +    1=USART frame with parity
 *  +    2=LIN Master - Break and sync generation. See LIN Command (CTRLB.LINCMD).
 *  +    4=Auto-baud (LIN Slave) - break detection and auto-baud.
 *  +    5=Auto-baud - break detection and auto-baud with parity
 *  +    7=ISO 7816
 * - SERCOM_USART_CTRLA_CMODE	1=Synchronous, 0=Asynchronous Communication
 * - SERCOM_USART_CTRLA_CPOL	Clock Polarity 
 *  +    0=TXD change/Rising XCK edge RXD Sample/Falling XCK edge
 *  +    1=TXD change/Falling XCK edge RXD Sample/Rising XCK edge
 * - SERCOM_USART_CTRLA_DORD	Data Order 
 *  +    0=MSB is transmitted first.
 *  +    1=LSB is transmitted first.
 * @note SWRST and ENABLE must be write synchronized
 * use spi_set_SWRST(), spi_set_ENABLE(), spi_clear_ENABLE()
 */

static inline void usart_write_CTRLA(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->USART.CTRLA.reg = data;
}

/**
 * @brief read USART Control A
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_USART_CTRLA_SWRST	 Software Reset 
 * - SERCOM_USART_CTRLA_ENABLE Enable 
 * - SERCOM_USART_CTRLA_MODE(value) Operating Mode 0=USART with external clock, 1=USART with internal clock
 * - SERCOM_USART_CTRLA_RUNSTDBY	Run during Standby 
 * - SERCOM_USART_CTRLA_IBON	Immediate Buffer Overflow Notification 
 * - SERCOM_USART_CTRLA_TXINV	Transmit Data Invert 
 * - SERCOM_USART_CTRLA_RXINV	Receive Data Invert 
 * - SERCOM_USART_CTRLA_SAMPR(value)	Sample 
 *  +    0=16x over-sampling using arithmetic baud rate generation.
 *  +    1=16x over-sampling using fractional baud rate generation.
 *  +    2=8x over-sampling using arithmetic baud rate generation.
 *  +    3=8x over-sampling using fractional baud rate generation.
 *  +    4=3x over-sampling using arithmetic baud rate generation.
 * - SERCOM_USART_CTRLA_TXPO	Transmit Data Pinout 
 *  +    0=TXD is PAD0, XCK is PAD1
 *  +    2=TXD is PAD0, RTS is PAD2, CTS is PAD3
 *  +    3=TXD is PAD0, XCK is PAD1, RTS is PAD2
 * - SERCOM_USART_CTRLA_RXPO	Receive Data Pinout PADn
 * - SERCOM_USART_CTRLA_SAMPA	Sample Adjustment 
 *  +    0= 16X=7-8-9, 8X=3-4-5
 *  +    1= 16X=9-10-11, 8X=4-5-6
 *  +    2= 16X=11-12-13, 8X=5-6-7
 *  +    3= 16X=13-14-15, 8X=6-7-8
 * - SERCOM_USART_CTRLA_FORM	Frame Format 
 *  +    0=USART frame
 *  +    1=USART frame with parity
 *  +    2=LIN Master - Break and sync generation. See LIN Command (CTRLB.LINCMD).
 *  +    4=Auto-baud (LIN Slave) - break detection and auto-baud.
 *  +    5=Auto-baud - break detection and auto-baud with parity
 *  +    7=ISO 7816
 * - SERCOM_USART_CTRLA_CMODE	1=Synchronous, 0=Asynchronous Communication
 * - SERCOM_USART_CTRLA_CPOL	Clock Polarity 
 *  +    0=TXD change/Rising XCK edge RXD Sample/Falling XCK edge
 *  +    1=TXD change/Falling XCK edge RXD Sample/Rising XCK edge
 * - SERCOM_USART_CTRLA_DORD	Data Order 
 *  +    0=MSB is transmitted first.
 *  +    1=LSB is transmitted first.
 * @note SWRST and ENABLE must be write synchronized
 * use spi_set_CTRLA_SWRST(), spi_set_CTRLA_ENABLE(), spi_clear_CTRLA_ENABLE()
 */
static inline uint32_t usart_read_CTRLA(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.CTRLA.reg;
}

/**
 * @brief write USART Control B register
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_USART_CTRLB_CHSIZE	Character Size 
 *  +    0=8 bits, 1=9bits, 5=5bits, 6=6bits, 7=7bits
 * - SERCOM_USART_CTRLB_SBMODE	Stop Bit Mode 
 *  +    0=One stop bit
 *  +    1=Two stop bits
 * - SERCOM_USART_CTRLB_COLDEN	Collision Detection Enable 
 * - SERCOM_USART_CTRLB_SFDE		Start of Frame Detection Enable
 *  +    0=Start-of-frame detection disabled.
 *  +    1=Start-of-frame detection enabled. RXC wakes up the device from all sleep modes.
 * - SERCOM_USART_CTRLB_ENC		Encoding Format 1=IrDA encoded
 * - SERCOM_USART_CTRLB_PMODE		Parity Mode 0=Even 1=Odd
 * - SERCOM_USART_CTRLB_TXEN		Transmitter Enable 
 * - SERCOM_USART_CTRLB_RXEN		Receiver Enable 
 * - SERCOM_USART_CTRLB_LINCMD	LIN Command
 *  +    0=Normal USART transmission.
 *  +    1=Break field is transmitted when DATA is written.
 *  +    2=Break, sync and identifier are automatically transmitted when DATA is written with the identifier.
 */
static inline void usart_write_CTRLB(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->USART.CTRLB.reg = data;
}

/**
 * @brief read USART Control B register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_USART_CTRLB_CHSIZE	Character Size 
 *  +    0=8 bits, 1=9bits, 5=5bits, 6=6bits, 7=7bits
 * - SERCOM_USART_CTRLB_SBMODE	Stop Bit Mode 
 *  +    0=One stop bit
 *  +    1=Two stop bits
 * - SERCOM_USART_CTRLB_COLDEN	Collision Detection Enable 
 * - SERCOM_USART_CTRLB_SFDE		Start of Frame Detection Enable
 *  +    0=Start-of-frame detection disabled.
 *  +    1=Start-of-frame detection enabled. RXC wakes up the device from all sleep modes.
 * - SERCOM_USART_CTRLB_ENC		Encoding Format 1=IrDA encoded
 * - SERCOM_USART_CTRLB_PMODE		Parity Mode 0=Even 1=Odd
 * - SERCOM_USART_CTRLB_TXEN		Transmitter Enable 
 * - SERCOM_USART_CTRLB_RXEN		Receiver Enable 
 * - SERCOM_USART_CTRLB_LINCMD	LIN Command
 *  +    0=Normal USART transmission.
 *  +    1=Break field is transmitted when DATA is written.
 *  +    2=Break, sync and identifier are automatically transmitted when DATA is written with the identifier.
 */
static inline uint32_t usart_read_CTRLB(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.CTRLB.reg;
}

/**
 * @brief write USART Control C
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_USART_CTRLC_GTIME	Guard Time 
 * - SERCOM_USART_CTRLC_BRKLEN	LIN Master Break Length
 *  +    0=Break field transmission is 13 bit times
 *  +    1=Break field transmission is 17 bit times
 *  +    2=Break field transmission is 21 bit times
 *  +    3=Break field transmission is 26 bit times
 * - SERCOM_USART_CTRLC_HDRDLY	LIN Master Header Delay 
 *  +    0=Delay between break and sync transmission is 1 bit time.
 *  +  Delay between sync and ID transmission is 1 bit time.
 *  +    1=Delay between break and sync transmission is 4 bit time.
 *  +  Delay between sync and ID transmission is 4 bit time.
 *  +    2=Delay between break and sync transmission is 8 bit time.
 *  +  Delay between sync and ID transmission is 4 bit time.
 *  +    3=Delay between break and sync transmission is 14 bit time.
 *  +  Delay between sync and ID transmission is 4 bit time.
 * - SERCOM_USART_CTRLC_INACK	Inhibit Not Acknowledge 
 * - SERCOM_USART_CTRLC_DSNACK	Disable Successive NACK 
 * - SERCOM_USART_CTRLC_MAXITER	Maximum Iterations 
 * - SERCOM_USART_CTRLC_DATA32B	Data 32 Bit 
 *  +    0=DATA reads (for received data) and writes (for transmit data) according to CTRLB.CHSIZE.
 *  +    1=DATA reads according to CTRLB.CHSIZE.
 *  +  DATA writes using 32-bit Extension.
 *  +    2=DATA reads using 32-bit Extension.
 *  +  DATA writes according to CTRLB.CHSIZE.
 *  +    3=DATA reads and writes using 32-bit Extension.
 */
static inline void usart_write_CTRLC(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->USART.CTRLC.reg = data;
}

/**
 * @brief read USART Control C
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return
 * - SERCOM_USART_CTRLC_GTIME	Guard Time 
 * - SERCOM_USART_CTRLC_BRKLEN	LIN Master Break Length
 *  +    0=Break field transmission is 13 bit times
 *  +    1=Break field transmission is 17 bit times
 *  +    2=Break field transmission is 21 bit times
 *  +    3=Break field transmission is 26 bit times
 * - SERCOM_USART_CTRLC_HDRDLY	LIN Master Header Delay 
 *  +    0=Delay between break and sync transmission is 1 bit time.
 *    Delay between sync and ID transmission is 1 bit time.
 *  +    1=Delay between break and sync transmission is 4 bit time.
 *    Delay between sync and ID transmission is 4 bit time.
 *  +    2=Delay between break and sync transmission is 8 bit time.
 *    Delay between sync and ID transmission is 4 bit time.
 *  +    3=Delay between break and sync transmission is 14 bit time.
 *    Delay between sync and ID transmission is 4 bit time.
 * - SERCOM_USART_CTRLC_INACK	Inhibit Not Acknowledge 
 * - SERCOM_USART_CTRLC_DSNACK	Disable Successive NACK 
 * - SERCOM_USART_CTRLC_MAXITER	Maximum Iterations 
 * - SERCOM_USART_CTRLC_DATA32B	Data 32 Bit 
 *  +    0=DATA reads (for received data) and writes (for transmit data) according to CTRLB.CHSIZE.
 *  +    1=DATA reads according to CTRLB.CHSIZE.
 *    DATA writes using 32-bit Extension.
 *  +    2=DATA reads using 32-bit Extension.
 *    DATA writes according to CTRLB.CHSIZE.
 *  +    3=DATA reads and writes using 32-bit Extension.
 */
static inline uint32_t usart_read_CTRLC(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.CTRLC.reg;
}

/**
 * @brief write USART Receive Pulse Length Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint8_t
 * - SERCOM_USART_RXPL_RXPL 8 bit 
 */
static inline void usart_write_RXPL(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->USART.RXPL.reg = data;
}

/**
 * @brief read USART Receive Pulse Length Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_USART_RXPL_RXPL 8 bit 
 */
static inline uint8_t usart_read_RXPL(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.RXPL.reg;
}

/**
 * @brief
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint16_t
 * - SERCOM_USART_LENGTH_LEN	 	8bit Data Length 
 * - SERCOM_USART_LENGTH_LENEN	Data Length Enable
 *  +    0=Length counter disabled
 *  +    1=Length counter enabled for transmit
 *  +    2=Length counter enabled for receive 
 */
static inline void usart_write_LENGTH(SERCOM_t *pSERCOM, uint16_t data)
{
	pSERCOM->USART.LENGTH.reg = data;
}

/**
 * @brief read USART Length Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint16_t
 * - SERCOM_USART_LENGTH_LEN	Data Length 
 * - SERCOM_USART_LENGTH_LENEN	Data Length Enable
 *  +    0=Length counter disabled
 *  +    1=Length counter enabled for transmit
 *  +    2=Length counter enabled for receive 
 */
static inline uint16_t usart_read_LENGTH(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.LENGTH.reg;
}

/**
 * @brief read USART Data Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t data
 * - SERCOM_USART_DATA_DATA 32 bit data
 */
static inline uint32_t usart_read_DATA(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.DATA.reg;
}

/**
 * @brief write USART Data Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_USART_DATA_DATA 32 bit data
 */
static inline void usart_write_DATA(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->USART.DATA.reg = data;
}

/**
 * @brief write USART Debug Control Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint8_t
 * - SERCOM_USART_DBGCTRL_DBGSTOP
 */
static inline void usart_write_DBGCTRL(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->USART.DBGCTRL.reg = data;
}

/**
 * @brief read USART Debug Control Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return
 * - SERCOM_USART_DBGCTRL_DBGSTOP
 */
static inline uint8_t usart_read_DBGCTRL(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.DBGCTRL.reg;
}

/**
 * @brief read the USART Sync Busy Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_USART_SYNCBUSY_SWRST	Software Reset Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_ENABLE	SERCOM Enable Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_CTRLB	CTRLB Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_RXERRCNT	RXERRCNT Synchronization Busy 
 * - SERCOM_USART_SYNCBUSY_LENGTH	LENGTH Synchronization Busy 
 */
static inline uint32_t usart_read_SYNCBUSY(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.SYNCBUSY.reg;
}

/**
 * @brief initiate software reset by writing to control A
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call usart_wait_for_sync(pSERCOM, SERCOM_USART_SYNCBUSY_SWRST)
  */

static inline void usart_set_SWRST(SERCOM_t *pSERCOM)
{
	pSERCOM->USART.CTRLA.reg = SERCOM_USART_CTRLA_SWRST;
} 

/**
 * @brief Enable USART
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call usart_wait_for_sync(pSERCOM, SERCOM_USART_SYNCBUSY_ENABLE)
 */

static inline void usart_set_ENABLE(SERCOM_t *pSERCOM)
{
	pSERCOM->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;
} 

/**
 * @brief Disable USART
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call usart_wait_for_sync(pSERCOM, SERCOM_USART_SYNCBUSY_ENABLE)
 */

static inline void usart_clear_ENABLE(SERCOM_t *pSERCOM)
{
	pSERCOM->USART.CTRLA.reg &= ~SERCOM_USART_CTRLA_ENABLE;
} 
/**
 * @brief read USART Receive Error Count
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return 8 bit USART Receive Error Count
 */
static inline uint8_t usart_read_RXERRCNT(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.RXERRCNT.reg;
}

/**
 * @brief clear USART Status Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint16_t
 * - SERCOM_USART_STATUS_PERR	Parity Error 
 * - SERCOM_USART_STATUS_FERR	Frame Error 
 * - SERCOM_USART_STATUS_BUFOVF	Buffer Overflow 
 * - SERCOM_USART_STATUS_CTS	Clear To Send 
 * - SERCOM_USART_STATUS_ISF	Inconsistent Sync Field 
 * - SERCOM_USART_STATUS_COLL	Collision Detected 
 * - SERCOM_USART_STATUS_TXE	Transmitter Empty 
 * - SERCOM_USART_STATUS_ITER	Maximum Number of Repetitions Reached 
 */
static inline void usart_clear_STATUS(SERCOM_t *pSERCOM, uint16_t reg)
{
	pSERCOM->USART.STATUS.reg = reg;
}

/**
 * @brief read USART Status Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint16_t
 * - SERCOM_USART_STATUS_PERR	Parity Error 
 * - SERCOM_USART_STATUS_FERR	Frame Error 
 * - SERCOM_USART_STATUS_BUFOVF	Buffer Overflow 
 * - SERCOM_USART_STATUS_CTS	Clear To Send 
 * - SERCOM_USART_STATUS_ISF	Inconsistent Sync Field 
 * - SERCOM_USART_STATUS_COLL	Collision Detected 
 * - SERCOM_USART_STATUS_TXE	Transmitter Empty 
 * - SERCOM_USART_STATUS_ITER	Maximum Number of Repetitions Reached 
 */
static inline uint16_t usart_read_STATUS(SERCOM_t *pSERCOM)
{
	return pSERCOM->USART.STATUS.reg;
}

/**
 * @brief set Interrupt Enable for I2C Slave, 1=sets interrupt enable, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_I2CS_INTENSET_PREC	Stop Received Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_AMATCH	Address Match Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_DRDY	Data Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline void i2cs_set_INTEN(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->I2CS.INTENSET.reg = reg;
}

/**
 * @brief read Interrupt Enable for I2C Slave
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return
 * - SERCOM_I2CS_INTENSET_PREC	Stop Received Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_AMATCH	Address Match Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_DRDY	Data Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline uint8_t i2cs_read_INTEN(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.INTENSET.reg;
}

/**
 * @brief write Interrupt Enable for I2C Slave
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint8_t
 * - SERCOM_I2CS_INTENSET_PREC	Stop Received Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_AMATCH	Address Match Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_DRDY	Data Interrupt Enable 
 * - SERCOM_I2CS_INTENSET_ERROR	Combined Error Interrupt Enable 
 */
static inline void i2cs_write_INTEN(SERCOM_t *pSERCOM, uint8_t data)
{
	pSERCOM->I2CS.INTENSET.reg = data;
	pSERCOM->I2CS.INTENCLR.reg = ~data;
}

/**
 * @brief clear Interrupt Enable for I2C Slave 1=clears interupt enable, 0=do nothing
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_I2CS_INTENCLR_PREC	Stop Received Interrupt Disable 
 * - SERCOM_I2CS_INTENCLR_AMATCH	Address Match Interrupt Disable 
 * - SERCOM_I2CS_INTENCLR_DRDY	Data Interrupt Disable 
 * - SERCOM_I2CS_INTENCLR_ERROR	Combined Error Interrupt Disable 
 */
static inline void i2cs_clear_INTEN(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->I2CS.INTENCLR.reg = reg;
}

/**
 * @brief read interrupt status flag
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint8_t
 * - SERCOM_I2CS_INTFLAG_PREC	    Stop Received Interrupt 
 * - SERCOM_I2CS_INTFLAG_AMATCH	Address Match Interrupt 
 * - SERCOM_I2CS_INTFLAG_DRDY	    Data Interrupt 
 * - SERCOM_I2CS_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline uint8_t i2cs_read_INTFLAG(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.INTFLAG.reg;
}
/**
 * @brief clear interrupt status flag
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] reg - uint8_t
 * - SERCOM_I2CS_INTFLAG_PREC	    Stop Received Interrupt 
 * - SERCOM_I2CS_INTFLAG_AMATCH	Address Match Interrupt 
 * - SERCOM_I2CS_INTFLAG_DRDY	    Data Interrupt 
 * - SERCOM_I2CS_INTFLAG_ERROR	Combined Error Interrupt 
 */
static inline void i2cs_clear_INTFLAG(SERCOM_t *pSERCOM, uint8_t reg)
{
	pSERCOM->I2CS.INTFLAG.reg = reg;
}

/**
 * @brief do software reset on I2C Slave
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call i2cs_wait_for_sync(pSERCOM, SERCOM_I2CS_SYNCBUSY_SWRST);
 */
static inline void i2cs_set_SWRST(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CS.CTRLA.reg = SERCOM_I2CS_CTRLA_SWRST;
}

/**
 * @brief enable I2C Slave
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call i2cs_wait_for_sync(pSERCOM, SERCOM_I2CS_SYNCBUSY_ENABLE);
 * before setting enable
 */
static inline void i2cs_set_ENABLE(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CS.CTRLA.reg |= SERCOM_I2CS_CTRLA_ENABLE;
}

/**
 * @brief Clear I2C Slave Enable 
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @note call i2cm_wait_for_sync(pSERCOM, SERCOM_I2CS_SYNCBUSY_ENABLE);
 */
static inline void i2cs_clear_ENABLE(SERCOM_t *pSERCOM)
{
	pSERCOM->I2CS.CTRLA.reg &= ~SERCOM_I2CS_CTRLA_ENABLE;
}

/**
 * @brief write I2C Slave Control A
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CS_CTRLA_SWRST	Software Reset 
 * - SERCOM_I2CS_CTRLA_ENABLE	Enable 
 * - SERCOM_I2CS_CTRLA_MODE(value) Operating Mode 4=Slave
 * - SERCOM_I2CS_CTRLA_RUNSTDBY	Run during Standby 
 * - SERCOM_I2CS_CTRLA_PINOUT	Pin Usage 
 * - SERCOM_I2CS_CTRLA_SDAHOLD(value) SDA Hold Time 
 *  +    0 = Disabled
 *  +    1 = 50-100ns hold time
 *  +    2 = 300-600ns hold time
 *  +    3 = 400-800ns hold time
 * - SERCOM_I2CS_CTRLA_SEXTTOEN	Slave SCL Low Extend Timeout 
 * - SERCOM_I2CS_CTRLA_SPEED(value) Transfer Speed
 *  +    0 = Standard-mode (Sm) up to 100 kHz and Fast-mode (Fm) up to 400 kHz
 *  +    1 = Fast-mode Plus (Fm+) up to 1 MHz
 *  +    2 = High-speed mode (Hs-mode) up to 3.4 MHz
 * - SERCOM_I2CS_CTRLA_SCLSM	SCL Clock Stretch Mode 
 * - SERCOM_I2CS_CTRLA_LOWTOUTEN	SCL Low Timeout Enable 
 */
static inline void i2cs_write_CTRLA(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CS.CTRLA.reg = data;
}

/**
 * @brief read I2C Slave Control A
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CS_CTRLA_SWRST	Software Reset 
 * - SERCOM_I2CS_CTRLA_ENABLE	Enable 
 * @note SWRST and ENABLE must be write synchronized
 * use i2cs_set_CTRLA_SWRST(), i2cs_set_CTRLA_ENABLE(), i2cs_clear_CTRLA_ENABLE()
 * if SWRST is used, all other bits are ignored
 * - SERCOM_I2CS_CTRLA_MODE(value) Operating Mode 4=Slave
 * - SERCOM_I2CS_CTRLA_RUNSTDBY	Run during Standby 
 * - SERCOM_I2CS_CTRLA_PINOUT	Pin Usage 
 * - SERCOM_I2CS_CTRLA_SDAHOLD(value) SDA Hold Time 
 *  +    0 = Disabled
 *  +    1 = 50-100ns hold time
 *  +    2 = 300-600ns hold time
 *  +    3 = 400-800ns hold time
 * - SERCOM_I2CS_CTRLA_SEXTTOEN	Slave SCL Low Extend Timeout 
 * - SERCOM_I2CS_CTRLA_SPEED(value) Transfer Speed
 *  +    0 = Standard-mode (Sm) up to 100 kHz and Fast-mode (Fm) up to 400 kHz
 *  +    1 = Fast-mode Plus (Fm+) up to 1 MHz
 *  +    2 = High-speed mode (Hs-mode) up to 3.4 MHz
 * - SERCOM_I2CS_CTRLA_SCLSM	SCL Clock Stretch Mode 
 * - SERCOM_I2CS_CTRLA_LOWTOUTEN	SCL Low Timeout Enable 
 */
static inline uint32_t i2cs_read_CTRLA(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.CTRLA.reg;
}

/**
 * @brief write I2C Slave Control B register
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CS_CTRLB_SMEN	Smart Mode Enable 
 * - SERCOM_I2CS_CTRLB_GCMD	PMBus Group Command 
 * - SERCOM_I2CS_CTRLB_AACKEN	Automatic Address Acknowledge 
 * - SERCOM_I2CS_CTRLB_AMODE(value) Address Mode 
 *  +    0 = The slave responds to the address written in ADDR.ADDR masked by the value in ADDR.ADDRMASK.
 *  +    1 =  The slave responds to the two unique addresses in ADDR.ADDR and
ADDR.ADDRMASK.
 *  +    2 = The slave responds to the range of addresses between and including
ADDR.ADDR and ADDR.ADDRMASK. ADDR.ADDR is the upper limit.
 * - SERCOM_I2CS_CTRLB_CMD(value)	Command 
 *  +    0 = No operation
 *  +    2 = Used to complete a transaction in response to a data interrupt (DRDY)
 *      Write - Execute acknowledge action succeeded by waiting for any start (S/Sr)
condition
 *      Read - Wait for any start (S/Sr) condition
 *  +    3 = Used in response to an address interrupt (AMATCH)
 *      Write - Execute acknowledge action succeeded by reception of next byte
 *      Read -  Execute acknowledge action succeeded by slave data interrupt
 *  +    3 = Used in response to a data interrupt (DRDY)
 *     Write - Execute acknowledge action succeeded by reception of next byte
 *     Read - Execute a byte read operation followed by ACK/NACK reception
 * - SERCOM_I2CS_CTRLB_ACKACT	Acknowledge Action 0=Send ACK, 1=Send NACK
 */
static inline void i2cs_write_CTRLB(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CS.CTRLB.reg = data;
}

/**
 * @brief read I2C Slave Control B register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CS_CTRLB_SMEN	Smart Mode Enable 
 * - SERCOM_I2CS_CTRLB_GCMD	PMBus Group Command 
 * - SERCOM_I2CS_CTRLB_AACKEN	Automatic Address Acknowledge 
 * - SERCOM_I2CS_CTRLB_AMODE(value) Address Mode 
 *  +    0 = The slave responds to the address written in ADDR.ADDR masked by the value in ADDR.ADDRMASK.
 *  +    1 =  The slave responds to the two unique addresses in ADDR.ADDR and
ADDR.ADDRMASK.
 *  +    2 = The slave responds to the range of addresses between and including
ADDR.ADDR and ADDR.ADDRMASK. ADDR.ADDR is the upper limit.
 * - SERCOM_I2CS_CTRLB_CMD(value)	Command 
 *  +    0 = No operation
 *  +    2 = Used to complete a transaction in response to a data interrupt (DRDY)
 *      Write - Execute acknowledge action succeeded by waiting for any start (S/Sr)
condition
 *      Read - Wait for any start (S/Sr) condition
 *  +    3 = Used in response to an address interrupt (AMATCH)
 *      Write - Execute acknowledge action succeeded by reception of next byte
 *      Read -  Execute acknowledge action succeeded by slave data interrupt
 *  +    3 = Used in response to a data interrupt (DRDY)
 *     Write - Execute acknowledge action succeeded by reception of next byte
 *     Read - Execute a byte read operation followed by ACK/NACK reception
 * - SERCOM_I2CS_CTRLB_ACKACT	Acknowledge Action 0=Send ACK, 1=Send NACK
 */
static inline uint32_t i2cs_read_CTRLB(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.CTRLB.reg;
}

/**
 * @brief write I2C Slave Control C
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CS_CTRLC_SDASETUP	SDA Setup Time 
 * tsu = (SERCOM_CLK * APBPeriod) * (6 + 16 * SDASETUP)
 * - SERCOM_I2CS_CTRLC_DATA32B	Data 32 Bit 
 */
static inline void i2cs_write_CTRLC(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CS.CTRLC.reg = data;
}

/**
 * @brief read I2C Slave Control C
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CS_CTRLC_SDASETUP	SDA Setup Time 
 * tsu = (SERCOM_CLK * APBPeriod) * (6 + 16 * SDASETUP)
 * - SERCOM_I2CS_CTRLC_DATA32B	Data 32 Bit 0=8 bit, 1=32bit
 */
static inline uint32_t i2cs_read_CTRLC(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.CTRLC.reg;
}

/**
 * @brief write I2C Slave length
 * @note requires write synchronization
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint16_t
 * - SERCOM_I2CS_LENGTH_LEN	Data Length 
 * - SERCOM_I2CS_LENGTH_LENEN	Data Length Enable 
 * @note call i2cs_wait_for_sync(pSERCOM, SERCOM_I2CS_SYNCBUSY_LENGTH);
 * before writing length
 */
static inline void i2cs_write_LENGTH(SERCOM_t *pSERCOM, uint16_t data)
{
	pSERCOM->I2CS.LENGTH.reg = data;
}

/**
 * @brief read I2C Slave Length
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint16_t
 * - SERCOM_I2CS_LENGTH_LEN	8 bit Data Length 
 * - SERCOM_I2CS_LENGTH_LENEN	Data Length Enable 
 */
static inline uint16_t i2cs_read_LENGTH(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.LENGTH.reg;
}

/**
 * @brief write I2C Slave Address
 * Enabled Protected - only write when disabled
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 * - SERCOM_I2CS_ADDR_GENCEN	General Call Address Enable 
 * - SERCOM_I2CS_ADDR_ADDR(value)	Address Value (10bit)
 * - SERCOM_I2CS_ADDR_TENBITEN	Ten Bit Addressing Enable 
 * - SERCOM_I2CS_ADDR_ADDRMASK(value) Address Mask (10bit)
 */
static inline void i2cs_write_ADDR(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CS.ADDR.reg = data;
}

/**
 * @brief read I2C Slave Address
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 * - SERCOM_I2CS_ADDR_GENCEN	General Call Address Enable 
 * - SERCOM_I2CS_ADDR_ADDR(value)	Address Value (10bit)
 * - SERCOM_I2CS_ADDR_TENBITEN	Ten Bit Addressing Enable 
 * - SERCOM_I2CS_ADDR_ADDRMASK(value) Address Mask (10bit)
 */
static inline uint32_t i2cs_read_ADDR(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.ADDR.reg;
}

/**
 * @brief read I2C Slave Data
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 */
static inline uint32_t i2cs_read_DATA(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.DATA.reg;
}

/**
 * @brief write I2C Slave Data
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @param[in] data - uint32_t
 */
static inline void i2cs_write_DATA(SERCOM_t *pSERCOM, uint32_t data)
{
	pSERCOM->I2CS.DATA.reg = data;
}

/**
 * @brief read I2C Slave Sync Busy Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return uint32_t
 */
static inline uint32_t i2cs_read_SYNCBUSY(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.SYNCBUSY.reg;
}

/**
 * @brief read I2C Slave Status Register
 *
 * @param[in] pSERCOM - SERCOM_t*
 * @return
 * - SERCOM_I2CS_STATUS_BUSERR	Bus Error 
 * - SERCOM_I2CS_STATUS_COLL		Transmit Collision 
 * - SERCOM_I2CS_STATUS_RXNACK	Received Not Acknowledge 
 * - SERCOM_I2CS_STATUS_DIR		Read/Write Direction 
 * - SERCOM_I2CS_STATUS_SR		Repeated Start 
 * - SERCOM_I2CS_STATUS_LOWTOUT	SCL Low Timeout 
 * - SERCOM_I2CS_STATUS_CLKHOLD	Clock Hold 
 * - SERCOM_I2CS_STATUS_SEXTTOUT	Slave SCL Low Extend Timeout 
 * - SERCOM_I2CS_STATUS_HS		High Speed 
 * - SERCOM_I2CS_STATUS_LENERR	Transaction Length Error 
 */
static inline uint16_t i2cs_read_STATUS(SERCOM_t *pSERCOM)
{
	return pSERCOM->I2CS.STATUS.reg;
}

#endif /* _SERCOM_H_ */
