/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM QSPI
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _QSPI_H_
#define _QSPI_H_

#include <stdbool.h>
/*
 * @note QSPI Baudrate calculation given baudrate ie 115200 and core
 * frequency of SERCOMn port. 
 */
#define QSPI_BAUD(baudrate, freq)  (((freq)/(baudrate))-1)

/**
 * @brief qspi set INTEN register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INTENSET_RXC Receive Data Register Full Interrupt Enable
 * - QSPI_INTENSET_DRE Transmit Data Register Empty Interrupt Enable
 * - QSPI_INTENSET_TXC Transmission Complete Interrupt Enable
 * - QSPI_INTENSET_ERROR Overrun Error Interrupt Enable
 * - QSPI_INTENSET_CSRISE Chip Select Rise Interrupt Enable
 * - QSPI_INTENSET_INSTREND Instruction End Interrupt Enable
 **/
static inline void qspi_set_INTEN(uint32_t mask)
{
	QSPI->INTENSET.reg = mask;
}

/**
 * @brief qspi get INTEN register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_INTENSET_RXC Receive Data Register Full Interrupt Enable
 * - QSPI_INTENSET_DRE Transmit Data Register Empty Interrupt Enable
 * - QSPI_INTENSET_TXC Transmission Complete Interrupt Enable
 * - QSPI_INTENSET_ERROR Overrun Error Interrupt Enable
 * - QSPI_INTENSET_CSRISE Chip Select Rise Interrupt Enable
 * - QSPI_INTENSET_INSTREND Instruction End Interrupt Enable
 **/
static inline uint32_t qspi_get_INTEN(uint32_t mask)
{
    return QSPI->INTENSET.reg & mask;
}

/**
 * @brief qspi read INTEN register
 *
 * @return uint32_t
 * - QSPI_INTENSET_RXC Receive Data Register Full Interrupt Enable
 * - QSPI_INTENSET_DRE Transmit Data Register Empty Interrupt Enable
 * - QSPI_INTENSET_TXC Transmission Complete Interrupt Enable
 * - QSPI_INTENSET_ERROR Overrun Error Interrupt Enable
 * - QSPI_INTENSET_CSRISE Chip Select Rise Interrupt Enable
 * - QSPI_INTENSET_INSTREND Instruction End Interrupt Enable
 **/
static inline uint32_t qspi_read_INTEN(void)
{
	return QSPI->INTENSET.reg;
}

/**
 * @brief qspi write INTEN register
 *
 * @param[in] data uint32_t 
 * - QSPI_INTENSET_RXC Receive Data Register Full Interrupt Enable
 * - QSPI_INTENSET_DRE Transmit Data Register Empty Interrupt Enable
 * - QSPI_INTENSET_TXC Transmission Complete Interrupt Enable
 * - QSPI_INTENSET_ERROR Overrun Error Interrupt Enable
 * - QSPI_INTENSET_CSRISE Chip Select Rise Interrupt Enable
 * - QSPI_INTENSET_INSTREND Instruction End Interrupt Enable
 **/
static inline void qspi_write_INTEN(uint32_t data)
{
	QSPI->INTENSET.reg = data;
	QSPI->INTENCLR.reg = ~data;
}

/**
 * @brief qspi clear INTEN register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INTENSET_RXC Receive Data Register Full Interrupt Enable
 * - QSPI_INTENSET_DRE Transmit Data Register Empty Interrupt Enable
 * - QSPI_INTENSET_TXC Transmission Complete Interrupt Enable
 * - QSPI_INTENSET_ERROR Overrun Error Interrupt Enable
 * - QSPI_INTENSET_CSRISE Chip Select Rise Interrupt Enable
 * - QSPI_INTENSET_INSTREND Instruction End Interrupt Enable
 **/
static inline void qspi_clear_INTEN(uint32_t mask)
{
	QSPI->INTENCLR.reg = mask;
}

/**
 * @brief qspi get INTFLAG register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_INTFLAG_RXC Receive Data Register Full
 * - QSPI_INTFLAG_DRE Transmit Data Register Empty
 * - QSPI_INTFLAG_TXC Transmission Complete
 * - QSPI_INTFLAG_ERROR Overrun Error
 * - QSPI_INTFLAG_CSRISE Chip Select Rise
 * - QSPI_INTFLAG_INSTREND Instruction End
 **/
static inline uint32_t qspi_get_INTFLAG(uint32_t mask)
{
    return QSPI->INTFLAG.reg & mask;
}

/**
 * @brief qspi read INTFLAG register
 *
 * @return uint32_t
 * - QSPI_INTFLAG_RXC Receive Data Register Full
 * - QSPI_INTFLAG_DRE Transmit Data Register Empty
 * - QSPI_INTFLAG_TXC Transmission Complete
 * - QSPI_INTFLAG_ERROR Overrun Error
 * - QSPI_INTFLAG_CSRISE Chip Select Rise
 * - QSPI_INTFLAG_INSTREND Instruction End
 **/
static inline uint32_t qspi_read_INTFLAG(void)
{
	return QSPI->INTFLAG.reg;
}

/**
 * @brief qspi clear INTFLAG register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INTFLAG_RXC Receive Data Register Full
 * - QSPI_INTFLAG_DRE Transmit Data Register Empty
 * - QSPI_INTFLAG_TXC Transmission Complete
 * - QSPI_INTFLAG_ERROR Overrun Error
 * - QSPI_INTFLAG_CSRISE Chip Select Rise
 * - QSPI_INTFLAG_INSTREND Instruction End
 **/
static inline void qspi_clear_INTFLAG(uint32_t mask)
{
	QSPI->INTFLAG.reg = mask;
}

/**
 * @brief qspi write TXDATA register
 *
 * @param[in] data uint32_t 
 * - QSPI_TXDATA_DATA(value) Transmit Data
 **/
static inline void qspi_write_TXDATA(uint32_t data)
{
	QSPI->TXDATA.reg = data;
}

/**
 * @brief qspi write SCRAMBKEY register
 *
 * @param[in] data uint32_t 
 * - QSPI_SCRAMBKEY_KEY(value) Scrambling User Key
 **/
static inline void qspi_write_SCRAMBKEY(uint32_t data)
{
	QSPI->SCRAMBKEY.reg = data;
}

/**
 * @brief qspi set CTRLA register
 *
 * @param[in] mask uint32_t 
 * - QSPI_CTRLA_SWRST Software Reset
 * - QSPI_CTRLA_ENABLE Enable
 * - QSPI_CTRLA_LASTXFER Last Transfer
 **/
static inline void qspi_set_CTRLA(uint32_t mask)
{
	QSPI->CTRLA.reg |= mask;
}

/**
 * @brief qspi get CTRLA register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_CTRLA_SWRST Software Reset
 * - QSPI_CTRLA_ENABLE Enable
 * - QSPI_CTRLA_LASTXFER Last Transfer
 **/
static inline uint32_t qspi_get_CTRLA(uint32_t mask)
{
    return QSPI->CTRLA.reg & mask;
}

/**
 * @brief qspi write CTRLA register
 *
 * @param[in] data uint32_t 
 * - QSPI_CTRLA_SWRST Software Reset
 * - QSPI_CTRLA_ENABLE Enable
 * - QSPI_CTRLA_LASTXFER Last Transfer
 **/
static inline void qspi_write_CTRLA(uint32_t data)
{
	QSPI->CTRLA.reg = data;
}

/**
 * @brief qspi clear CTRLA register
 *
 * @param[in] mask uint32_t 
 * - QSPI_CTRLA_SWRST Software Reset
 * - QSPI_CTRLA_ENABLE Enable
 * - QSPI_CTRLA_LASTXFER Last Transfer
 **/
static inline void qspi_clear_CTRLA(uint32_t mask)
{
	QSPI->CTRLA.reg &= ~mask;
}

/**
 * @brief qspi read CTRLA register
 *
 * @return uint32_t
 * - QSPI_CTRLA_SWRST Software Reset
 * - QSPI_CTRLA_ENABLE Enable
 * - QSPI_CTRLA_LASTXFER Last Transfer
 **/
static inline uint32_t qspi_read_CTRLA(void)
{
	return QSPI->CTRLA.reg;
}

/**
 * @brief qspi set CTRLB register
 *
 * @param[in] mask uint32_t 
 * - QSPI_CTRLB_MODE Serial Memory Mode
 *  +      QSPI_CTRLB_MODE_SPI SPI operating mode
 *  +      QSPI_CTRLB_MODE_MEMORY Serial Memory operating mode
 * - QSPI_CTRLB_LOOPEN Local Loopback Enable
 * - QSPI_CTRLB_WDRBT Wait Data Read Before Transfer
 * - QSPI_CTRLB_SMEMREG Serial Memory reg
 * - QSPI_CTRLB_CSMODE(value) Chip Select Mode
 *  +      QSPI_CTRLB_CSMODE_NORELOAD The chip select is deasserted if TD has not been reloaded before the end of the current transfer.
 *  +      QSPI_CTRLB_CSMODE_LASTXFER The chip select is deasserted when the bit LASTXFER is written at 1 and the character written in TD has been transferred.
 *  +      QSPI_CTRLB_CSMODE_SYSTEMATICALLY The chip select is deasserted systematically after each transfer.
 * - QSPI_CTRLB_DATALEN(value) Data Length
 *  +      QSPI_CTRLB_DATALEN_8BITS 8-bits transfer
 *  +      QSPI_CTRLB_DATALEN_9BITS 9 bits transfer
 *  +      QSPI_CTRLB_DATALEN_10BITS 10-bits transfer
 *  +      QSPI_CTRLB_DATALEN_11BITS 11-bits transfer
 *  +      QSPI_CTRLB_DATALEN_12BITS 12-bits transfer
 *  +      QSPI_CTRLB_DATALEN_13BITS 13-bits transfer
 *  +      QSPI_CTRLB_DATALEN_14BITS 14-bits transfer
 *  +      QSPI_CTRLB_DATALEN_15BITS 15-bits transfer
 *  +      QSPI_CTRLB_DATALEN_16BITS 16-bits transfer
 * - QSPI_CTRLB_DLYBCT(value) Delay Between Consecutive Transfers
 * - QSPI_CTRLB_DLYCS(value) Minimum Inactive CS Delay
 **/
static inline void qspi_set_CTRLB(uint32_t mask)
{
	QSPI->CTRLB.reg |= mask;
}

/**
 * @brief qspi get CTRLB register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_CTRLB_MODE Serial Memory Mode
 *  +      QSPI_CTRLB_MODE_SPI SPI operating mode
 *  +      QSPI_CTRLB_MODE_MEMORY Serial Memory operating mode
 * - QSPI_CTRLB_LOOPEN Local Loopback Enable
 * - QSPI_CTRLB_WDRBT Wait Data Read Before Transfer
 * - QSPI_CTRLB_SMEMREG Serial Memory reg
 * - QSPI_CTRLB_CSMODE(value) Chip Select Mode
 *  +      QSPI_CTRLB_CSMODE_NORELOAD The chip select is deasserted if TD has not been reloaded before the end of the current transfer.
 *  +      QSPI_CTRLB_CSMODE_LASTXFER The chip select is deasserted when the bit LASTXFER is written at 1 and the character written in TD has been transferred.
 *  +      QSPI_CTRLB_CSMODE_SYSTEMATICALLY The chip select is deasserted systematically after each transfer.
 * - QSPI_CTRLB_DATALEN(value) Data Length
 *  +      QSPI_CTRLB_DATALEN_8BITS 8-bits transfer
 *  +      QSPI_CTRLB_DATALEN_9BITS 9 bits transfer
 *  +      QSPI_CTRLB_DATALEN_10BITS 10-bits transfer
 *  +      QSPI_CTRLB_DATALEN_11BITS 11-bits transfer
 *  +      QSPI_CTRLB_DATALEN_12BITS 12-bits transfer
 *  +      QSPI_CTRLB_DATALEN_13BITS 13-bits transfer
 *  +      QSPI_CTRLB_DATALEN_14BITS 14-bits transfer
 *  +      QSPI_CTRLB_DATALEN_15BITS 15-bits transfer
 *  +      QSPI_CTRLB_DATALEN_16BITS 16-bits transfer
 * - QSPI_CTRLB_DLYBCT(value) Delay Between Consecutive Transfers
 * - QSPI_CTRLB_DLYCS(value) Minimum Inactive CS Delay
 **/
static inline uint32_t qspi_get_CTRLB(uint32_t mask)
{
    return QSPI->CTRLB.reg & mask;
}

/**
 * @brief qspi write CTRLB register
 *
 * @param[in] data uint32_t 
 * - QSPI_CTRLB_MODE Serial Memory Mode
 *  +      QSPI_CTRLB_MODE_SPI SPI operating mode
 *  +      QSPI_CTRLB_MODE_MEMORY Serial Memory operating mode
 * - QSPI_CTRLB_LOOPEN Local Loopback Enable
 * - QSPI_CTRLB_WDRBT Wait Data Read Before Transfer
 * - QSPI_CTRLB_SMEMREG Serial Memory reg
 * - QSPI_CTRLB_CSMODE(value) Chip Select Mode
 *  +      QSPI_CTRLB_CSMODE_NORELOAD The chip select is deasserted if TD has not been reloaded before the end of the current transfer.
 *  +      QSPI_CTRLB_CSMODE_LASTXFER The chip select is deasserted when the bit LASTXFER is written at 1 and the character written in TD has been transferred.
 *  +      QSPI_CTRLB_CSMODE_SYSTEMATICALLY The chip select is deasserted systematically after each transfer.
 * - QSPI_CTRLB_DATALEN(value) Data Length
 *  +      QSPI_CTRLB_DATALEN_8BITS 8-bits transfer
 *  +      QSPI_CTRLB_DATALEN_9BITS 9 bits transfer
 *  +      QSPI_CTRLB_DATALEN_10BITS 10-bits transfer
 *  +      QSPI_CTRLB_DATALEN_11BITS 11-bits transfer
 *  +      QSPI_CTRLB_DATALEN_12BITS 12-bits transfer
 *  +      QSPI_CTRLB_DATALEN_13BITS 13-bits transfer
 *  +      QSPI_CTRLB_DATALEN_14BITS 14-bits transfer
 *  +      QSPI_CTRLB_DATALEN_15BITS 15-bits transfer
 *  +      QSPI_CTRLB_DATALEN_16BITS 16-bits transfer
 * - QSPI_CTRLB_DLYBCT(value) Delay Between Consecutive Transfers
 * - QSPI_CTRLB_DLYCS(value) Minimum Inactive CS Delay
 **/
static inline void qspi_write_CTRLB(uint32_t data)
{
	QSPI->CTRLB.reg = data;
}

/**
 * @brief qspi clear CTRLB register
 *
 * @param[in] mask uint32_t 
 * - QSPI_CTRLB_MODE Serial Memory Mode
 *  +      QSPI_CTRLB_MODE_SPI SPI operating mode
 *  +      QSPI_CTRLB_MODE_MEMORY Serial Memory operating mode
 * - QSPI_CTRLB_LOOPEN Local Loopback Enable
 * - QSPI_CTRLB_WDRBT Wait Data Read Before Transfer
 * - QSPI_CTRLB_SMEMREG Serial Memory reg
 * - QSPI_CTRLB_CSMODE(value) Chip Select Mode
 *  +      QSPI_CTRLB_CSMODE_NORELOAD The chip select is deasserted if TD has not been reloaded before the end of the current transfer.
 *  +      QSPI_CTRLB_CSMODE_LASTXFER The chip select is deasserted when the bit LASTXFER is written at 1 and the character written in TD has been transferred.
 *  +      QSPI_CTRLB_CSMODE_SYSTEMATICALLY The chip select is deasserted systematically after each transfer.
 * - QSPI_CTRLB_DATALEN(value) Data Length
 *  +      QSPI_CTRLB_DATALEN_8BITS 8-bits transfer
 *  +      QSPI_CTRLB_DATALEN_9BITS 9 bits transfer
 *  +      QSPI_CTRLB_DATALEN_10BITS 10-bits transfer
 *  +      QSPI_CTRLB_DATALEN_11BITS 11-bits transfer
 *  +      QSPI_CTRLB_DATALEN_12BITS 12-bits transfer
 *  +      QSPI_CTRLB_DATALEN_13BITS 13-bits transfer
 *  +      QSPI_CTRLB_DATALEN_14BITS 14-bits transfer
 *  +      QSPI_CTRLB_DATALEN_15BITS 15-bits transfer
 *  +      QSPI_CTRLB_DATALEN_16BITS 16-bits transfer
 * - QSPI_CTRLB_DLYBCT(value) Delay Between Consecutive Transfers
 * - QSPI_CTRLB_DLYCS(value) Minimum Inactive CS Delay
 **/
static inline void qspi_clear_CTRLB(uint32_t mask)
{
	QSPI->CTRLB.reg &= ~mask;
}

/**
 * @brief qspi read CTRLB register
 *
 * @return uint32_t
 * - QSPI_CTRLB_MODE Serial Memory Mode
 *  +      QSPI_CTRLB_MODE_SPI SPI operating mode
 *  +      QSPI_CTRLB_MODE_MEMORY Serial Memory operating mode
 * - QSPI_CTRLB_LOOPEN Local Loopback Enable
 * - QSPI_CTRLB_WDRBT Wait Data Read Before Transfer
 * - QSPI_CTRLB_SMEMREG Serial Memory reg
 * - QSPI_CTRLB_CSMODE(value) Chip Select Mode
 *  +      QSPI_CTRLB_CSMODE_NORELOAD The chip select is deasserted if TD has not been reloaded before the end of the current transfer.
 *  +      QSPI_CTRLB_CSMODE_LASTXFER The chip select is deasserted when the bit LASTXFER is written at 1 and the character written in TD has been transferred.
 *  +      QSPI_CTRLB_CSMODE_SYSTEMATICALLY The chip select is deasserted systematically after each transfer.
 * - QSPI_CTRLB_DATALEN(value) Data Length
 *  +      QSPI_CTRLB_DATALEN_8BITS 8-bits transfer
 *  +      QSPI_CTRLB_DATALEN_9BITS 9 bits transfer
 *  +      QSPI_CTRLB_DATALEN_10BITS 10-bits transfer
 *  +      QSPI_CTRLB_DATALEN_11BITS 11-bits transfer
 *  +      QSPI_CTRLB_DATALEN_12BITS 12-bits transfer
 *  +      QSPI_CTRLB_DATALEN_13BITS 13-bits transfer
 *  +      QSPI_CTRLB_DATALEN_14BITS 14-bits transfer
 *  +      QSPI_CTRLB_DATALEN_15BITS 15-bits transfer
 *  +      QSPI_CTRLB_DATALEN_16BITS 16-bits transfer
 * - QSPI_CTRLB_DLYBCT(value) Delay Between Consecutive Transfers
 * - QSPI_CTRLB_DLYCS(value) Minimum Inactive CS Delay
 **/
static inline uint32_t qspi_read_CTRLB(void)
{
	return QSPI->CTRLB.reg;
}

/**
 * @brief qspi set BAUD register
 *
 * @param[in] mask uint32_t 
 * - QSPI_BAUD_CPOL Clock Polarity
 * - QSPI_BAUD_CPHA Clock Phase
 * - QSPI_BAUD_BAUD(value) Serial Clock Baud Rate
 * - QSPI_BAUD_DLYBS(value) Delay Before SCK
 **/
static inline void qspi_set_BAUD(uint32_t mask)
{
	QSPI->BAUD.reg |= mask;
}

/**
 * @brief qspi get BAUD register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_BAUD_CPOL Clock Polarity
 * - QSPI_BAUD_CPHA Clock Phase
 * - QSPI_BAUD_BAUD(value) Serial Clock Baud Rate
 * - QSPI_BAUD_DLYBS(value) Delay Before SCK
 **/
static inline uint32_t qspi_get_BAUD(uint32_t mask)
{
    return QSPI->BAUD.reg & mask;
}

/**
 * @brief qspi write BAUD register
 *
 * @param[in] data uint32_t 
 * - QSPI_BAUD_CPOL Clock Polarity
 * - QSPI_BAUD_CPHA Clock Phase
 * - QSPI_BAUD_BAUD(value) Serial Clock Baud Rate
 * - QSPI_BAUD_DLYBS(value) Delay Before SCK
 **/
static inline void qspi_write_BAUD(uint32_t data)
{
	QSPI->BAUD.reg = data;
}

/**
 * @brief qspi clear BAUD register
 *
 * @param[in] mask uint32_t 
 * - QSPI_BAUD_CPOL Clock Polarity
 * - QSPI_BAUD_CPHA Clock Phase
 * - QSPI_BAUD_BAUD(value) Serial Clock Baud Rate
 * - QSPI_BAUD_DLYBS(value) Delay Before SCK
 **/
static inline void qspi_clear_BAUD(uint32_t mask)
{
	QSPI->BAUD.reg &= ~mask;
}

/**
 * @brief qspi read BAUD register
 *
 * @return uint32_t
 * - QSPI_BAUD_CPOL Clock Polarity
 * - QSPI_BAUD_CPHA Clock Phase
 * - QSPI_BAUD_BAUD(value) Serial Clock Baud Rate
 * - QSPI_BAUD_DLYBS(value) Delay Before SCK
 **/
static inline uint32_t qspi_read_BAUD(void)
{
	return QSPI->BAUD.reg;
}

/**
 * @brief qspi set INSTRADDR register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INSTRADDR_ADDR(value) Instruction Address
 **/
static inline void qspi_set_INSTRADDR(uint32_t mask)
{
	QSPI->INSTRADDR.reg |= mask;
}

/**
 * @brief qspi get INSTRADDR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_INSTRADDR_ADDR(value) Instruction Address
 **/
static inline uint32_t qspi_get_INSTRADDR(uint32_t mask)
{
    return QSPI->INSTRADDR.reg & mask;
}

/**
 * @brief qspi write INSTRADDR register
 *
 * @param[in] data uint32_t 
 * - QSPI_INSTRADDR_ADDR(value) Instruction Address
 **/
static inline void qspi_write_INSTRADDR(uint32_t data)
{
	QSPI->INSTRADDR.reg = data;
}

/**
 * @brief qspi clear INSTRADDR register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INSTRADDR_ADDR(value) Instruction Address
 **/
static inline void qspi_clear_INSTRADDR(uint32_t mask)
{
	QSPI->INSTRADDR.reg &= ~mask;
}

/**
 * @brief qspi read INSTRADDR register
 *
 * @return uint32_t
 * - QSPI_INSTRADDR_ADDR(value) Instruction Address
 **/
static inline uint32_t qspi_read_INSTRADDR(void)
{
	return QSPI->INSTRADDR.reg;
}

/**
 * @brief qspi set INSTRCTRL register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INSTRCTRL_INSTR(value) Instruction Code
 * - QSPI_INSTRCTRL_OPTCODE(value) Option Code
 **/
static inline void qspi_set_INSTRCTRL(uint32_t mask)
{
	QSPI->INSTRCTRL.reg |= mask;
}

/**
 * @brief qspi get INSTRCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_INSTRCTRL_INSTR(value) Instruction Code
 * - QSPI_INSTRCTRL_OPTCODE(value) Option Code
 **/
static inline uint32_t qspi_get_INSTRCTRL(uint32_t mask)
{
    return QSPI->INSTRCTRL.reg & mask;
}

/**
 * @brief qspi write INSTRCTRL register
 *
 * @param[in] data uint32_t 
 * - QSPI_INSTRCTRL_INSTR(value) Instruction Code
 * - QSPI_INSTRCTRL_OPTCODE(value) Option Code
 **/
static inline void qspi_write_INSTRCTRL(uint32_t data)
{
	QSPI->INSTRCTRL.reg = data;
}

/**
 * @brief qspi clear INSTRCTRL register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INSTRCTRL_INSTR(value) Instruction Code
 * - QSPI_INSTRCTRL_OPTCODE(value) Option Code
 **/
static inline void qspi_clear_INSTRCTRL(uint32_t mask)
{
	QSPI->INSTRCTRL.reg &= ~mask;
}

/**
 * @brief qspi read INSTRCTRL register
 *
 * @return uint32_t
 * - QSPI_INSTRCTRL_INSTR(value) Instruction Code
 * - QSPI_INSTRCTRL_OPTCODE(value) Option Code
 **/
static inline uint32_t qspi_read_INSTRCTRL(void)
{
	return QSPI->INSTRCTRL.reg;
}

/**
 * @brief qspi set INSTRFRAME register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INSTRFRAME_WIDTH(value) Instruction Code, Address, Option Code and Data Width
 *  +      QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Single-bit SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_IO Instruction: Single-bit SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_IO Instruction: Single-bit SPI / Address-Option: Quad SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_CMD Instruction: Dual SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_CMD Instruction: Quad SPI / Address-Option: Quad SPI / Data: Quad SPI
 * - QSPI_INSTRFRAME_INSTREN Instruction Enable
 * - QSPI_INSTRFRAME_ADDREN Address Enable
 * - QSPI_INSTRFRAME_OPTCODEEN Option Enable
 * - QSPI_INSTRFRAME_DATAEN Data Enable
 * - QSPI_INSTRFRAME_OPTCODELEN(value) Option Code Length
 *  +      QSPI_INSTRFRAME_OPTCODELEN_1BIT 1-bit length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_2BITS 2-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_4BITS 4-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_8BITS 8-bits length option code
 * - QSPI_INSTRFRAME_ADDRLEN Address Length
 *  +      QSPI_INSTRFRAME_ADDRLEN_24BITS 24-bits address length
 *  +      QSPI_INSTRFRAME_ADDRLEN_32BITS 32-bits address length
 * - QSPI_INSTRFRAME_TFRTYPE(value) Data Transfer Type
 *  +      QSPI_INSTRFRAME_TFRTYPE_READ Read transfer from the serial memory.Scrambling is not performed.Read at random location (fetch) in the serial flash memory is not possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_READMEMORY Read data transfer from the serial memory.If enabled, scrambling is performed.Read at random location (fetch) in the serial flash memory is possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITE Write transfer into the serial memory.Scrambling is not performed.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITEMEMORY Write data transfer into the serial memory.If enabled, scrambling is performed.
 * - QSPI_INSTRFRAME_CRMODE Continuous Read Mode
 * - QSPI_INSTRFRAME_DDREN Double Data Rate Enable
 * - QSPI_INSTRFRAME_DUMMYLEN(value) Dummy Cycles Length
 **/
static inline void qspi_set_INSTRFRAME(uint32_t mask)
{
	QSPI->INSTRFRAME.reg |= mask;
}

/**
 * @brief qspi get INSTRFRAME register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_INSTRFRAME_WIDTH(value) Instruction Code, Address, Option Code and Data Width
 *  +      QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Single-bit SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_IO Instruction: Single-bit SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_IO Instruction: Single-bit SPI / Address-Option: Quad SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_CMD Instruction: Dual SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_CMD Instruction: Quad SPI / Address-Option: Quad SPI / Data: Quad SPI
 * - QSPI_INSTRFRAME_INSTREN Instruction Enable
 * - QSPI_INSTRFRAME_ADDREN Address Enable
 * - QSPI_INSTRFRAME_OPTCODEEN Option Enable
 * - QSPI_INSTRFRAME_DATAEN Data Enable
 * - QSPI_INSTRFRAME_OPTCODELEN(value) Option Code Length
 *  +      QSPI_INSTRFRAME_OPTCODELEN_1BIT 1-bit length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_2BITS 2-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_4BITS 4-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_8BITS 8-bits length option code
 * - QSPI_INSTRFRAME_ADDRLEN Address Length
 *  +      QSPI_INSTRFRAME_ADDRLEN_24BITS 24-bits address length
 *  +      QSPI_INSTRFRAME_ADDRLEN_32BITS 32-bits address length
 * - QSPI_INSTRFRAME_TFRTYPE(value) Data Transfer Type
 *  +      QSPI_INSTRFRAME_TFRTYPE_READ Read transfer from the serial memory.Scrambling is not performed.Read at random location (fetch) in the serial flash memory is not possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_READMEMORY Read data transfer from the serial memory.If enabled, scrambling is performed.Read at random location (fetch) in the serial flash memory is possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITE Write transfer into the serial memory.Scrambling is not performed.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITEMEMORY Write data transfer into the serial memory.If enabled, scrambling is performed.
 * - QSPI_INSTRFRAME_CRMODE Continuous Read Mode
 * - QSPI_INSTRFRAME_DDREN Double Data Rate Enable
 * - QSPI_INSTRFRAME_DUMMYLEN(value) Dummy Cycles Length
 **/
static inline uint32_t qspi_get_INSTRFRAME(uint32_t mask)
{
    return QSPI->INSTRFRAME.reg & mask;
}

/**
 * @brief qspi write INSTRFRAME register
 *
 * @param[in] data uint32_t 
 * - QSPI_INSTRFRAME_WIDTH(value) Instruction Code, Address, Option Code and Data Width
 *  +      QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Single-bit SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_IO Instruction: Single-bit SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_IO Instruction: Single-bit SPI / Address-Option: Quad SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_CMD Instruction: Dual SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_CMD Instruction: Quad SPI / Address-Option: Quad SPI / Data: Quad SPI
 * - QSPI_INSTRFRAME_INSTREN Instruction Enable
 * - QSPI_INSTRFRAME_ADDREN Address Enable
 * - QSPI_INSTRFRAME_OPTCODEEN Option Enable
 * - QSPI_INSTRFRAME_DATAEN Data Enable
 * - QSPI_INSTRFRAME_OPTCODELEN(value) Option Code Length
 *  +      QSPI_INSTRFRAME_OPTCODELEN_1BIT 1-bit length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_2BITS 2-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_4BITS 4-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_8BITS 8-bits length option code
 * - QSPI_INSTRFRAME_ADDRLEN Address Length
 *  +      QSPI_INSTRFRAME_ADDRLEN_24BITS 24-bits address length
 *  +      QSPI_INSTRFRAME_ADDRLEN_32BITS 32-bits address length
 * - QSPI_INSTRFRAME_TFRTYPE(value) Data Transfer Type
 *  +      QSPI_INSTRFRAME_TFRTYPE_READ Read transfer from the serial memory.Scrambling is not performed.Read at random location (fetch) in the serial flash memory is not possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_READMEMORY Read data transfer from the serial memory.If enabled, scrambling is performed.Read at random location (fetch) in the serial flash memory is possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITE Write transfer into the serial memory.Scrambling is not performed.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITEMEMORY Write data transfer into the serial memory.If enabled, scrambling is performed.
 * - QSPI_INSTRFRAME_CRMODE Continuous Read Mode
 * - QSPI_INSTRFRAME_DDREN Double Data Rate Enable
 * - QSPI_INSTRFRAME_DUMMYLEN(value) Dummy Cycles Length
 **/
static inline void qspi_write_INSTRFRAME(uint32_t data)
{
	QSPI->INSTRFRAME.reg = data;
}

/**
 * @brief qspi clear INSTRFRAME register
 *
 * @param[in] mask uint32_t 
 * - QSPI_INSTRFRAME_WIDTH(value) Instruction Code, Address, Option Code and Data Width
 *  +      QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Single-bit SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_IO Instruction: Single-bit SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_IO Instruction: Single-bit SPI / Address-Option: Quad SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_CMD Instruction: Dual SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_CMD Instruction: Quad SPI / Address-Option: Quad SPI / Data: Quad SPI
 * - QSPI_INSTRFRAME_INSTREN Instruction Enable
 * - QSPI_INSTRFRAME_ADDREN Address Enable
 * - QSPI_INSTRFRAME_OPTCODEEN Option Enable
 * - QSPI_INSTRFRAME_DATAEN Data Enable
 * - QSPI_INSTRFRAME_OPTCODELEN(value) Option Code Length
 *  +      QSPI_INSTRFRAME_OPTCODELEN_1BIT 1-bit length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_2BITS 2-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_4BITS 4-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_8BITS 8-bits length option code
 * - QSPI_INSTRFRAME_ADDRLEN Address Length
 *  +      QSPI_INSTRFRAME_ADDRLEN_24BITS 24-bits address length
 *  +      QSPI_INSTRFRAME_ADDRLEN_32BITS 32-bits address length
 * - QSPI_INSTRFRAME_TFRTYPE(value) Data Transfer Type
 *  +      QSPI_INSTRFRAME_TFRTYPE_READ Read transfer from the serial memory.Scrambling is not performed.Read at random location (fetch) in the serial flash memory is not possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_READMEMORY Read data transfer from the serial memory.If enabled, scrambling is performed.Read at random location (fetch) in the serial flash memory is possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITE Write transfer into the serial memory.Scrambling is not performed.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITEMEMORY Write data transfer into the serial memory.If enabled, scrambling is performed.
 * - QSPI_INSTRFRAME_CRMODE Continuous Read Mode
 * - QSPI_INSTRFRAME_DDREN Double Data Rate Enable
 * - QSPI_INSTRFRAME_DUMMYLEN(value) Dummy Cycles Length
 **/
static inline void qspi_clear_INSTRFRAME(uint32_t mask)
{
	QSPI->INSTRFRAME.reg &= ~mask;
}

/**
 * @brief qspi read INSTRFRAME register
 *
 * @return uint32_t
 * - QSPI_INSTRFRAME_WIDTH(value) Instruction Code, Address, Option Code and Data Width
 *  +      QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Single-bit SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_OUTPUT Instruction: Single-bit SPI / Address-Option: Single-bit SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_IO Instruction: Single-bit SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_IO Instruction: Single-bit SPI / Address-Option: Quad SPI / Data: Quad SPI
 *  +      QSPI_INSTRFRAME_WIDTH_DUAL_CMD Instruction: Dual SPI / Address-Option: Dual SPI / Data: Dual SPI
 *  +      QSPI_INSTRFRAME_WIDTH_QUAD_CMD Instruction: Quad SPI / Address-Option: Quad SPI / Data: Quad SPI
 * - QSPI_INSTRFRAME_INSTREN Instruction Enable
 * - QSPI_INSTRFRAME_ADDREN Address Enable
 * - QSPI_INSTRFRAME_OPTCODEEN Option Enable
 * - QSPI_INSTRFRAME_DATAEN Data Enable
 * - QSPI_INSTRFRAME_OPTCODELEN(value) Option Code Length
 *  +      QSPI_INSTRFRAME_OPTCODELEN_1BIT 1-bit length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_2BITS 2-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_4BITS 4-bits length option code
 *  +      QSPI_INSTRFRAME_OPTCODELEN_8BITS 8-bits length option code
 * - QSPI_INSTRFRAME_ADDRLEN Address Length
 *  +      QSPI_INSTRFRAME_ADDRLEN_24BITS 24-bits address length
 *  +      QSPI_INSTRFRAME_ADDRLEN_32BITS 32-bits address length
 * - QSPI_INSTRFRAME_TFRTYPE(value) Data Transfer Type
 *  +      QSPI_INSTRFRAME_TFRTYPE_READ Read transfer from the serial memory.Scrambling is not performed.Read at random location (fetch) in the serial flash memory is not possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_READMEMORY Read data transfer from the serial memory.If enabled, scrambling is performed.Read at random location (fetch) in the serial flash memory is possible.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITE Write transfer into the serial memory.Scrambling is not performed.
 *  +      QSPI_INSTRFRAME_TFRTYPE_WRITEMEMORY Write data transfer into the serial memory.If enabled, scrambling is performed.
 * - QSPI_INSTRFRAME_CRMODE Continuous Read Mode
 * - QSPI_INSTRFRAME_DDREN Double Data Rate Enable
 * - QSPI_INSTRFRAME_DUMMYLEN(value) Dummy Cycles Length
 **/
static inline uint32_t qspi_read_INSTRFRAME(void)
{
	return QSPI->INSTRFRAME.reg;
}

/**
 * @brief qspi set SCRAMBCTRL register
 *
 * @param[in] mask uint32_t 
 * - QSPI_SCRAMBCTRL_ENABLE Scrambling/Unscrambling Enable
 * - QSPI_SCRAMBCTRL_RANDOMDIS Scrambling/Unscrambling Random Value Disable
 **/
static inline void qspi_set_SCRAMBCTRL(uint32_t mask)
{
	QSPI->SCRAMBCTRL.reg |= mask;
}

/**
 * @brief qspi get SCRAMBCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_SCRAMBCTRL_ENABLE Scrambling/Unscrambling Enable
 * - QSPI_SCRAMBCTRL_RANDOMDIS Scrambling/Unscrambling Random Value Disable
 **/
static inline uint32_t qspi_get_SCRAMBCTRL(uint32_t mask)
{
    return QSPI->SCRAMBCTRL.reg & mask;
}

/**
 * @brief qspi write SCRAMBCTRL register
 *
 * @param[in] data uint32_t 
 * - QSPI_SCRAMBCTRL_ENABLE Scrambling/Unscrambling Enable
 * - QSPI_SCRAMBCTRL_RANDOMDIS Scrambling/Unscrambling Random Value Disable
 **/
static inline void qspi_write_SCRAMBCTRL(uint32_t data)
{
	QSPI->SCRAMBCTRL.reg = data;
}

/**
 * @brief qspi clear SCRAMBCTRL register
 *
 * @param[in] mask uint32_t 
 * - QSPI_SCRAMBCTRL_ENABLE Scrambling/Unscrambling Enable
 * - QSPI_SCRAMBCTRL_RANDOMDIS Scrambling/Unscrambling Random Value Disable
 **/
static inline void qspi_clear_SCRAMBCTRL(uint32_t mask)
{
	QSPI->SCRAMBCTRL.reg &= ~mask;
}

/**
 * @brief qspi read SCRAMBCTRL register
 *
 * @return uint32_t
 * - QSPI_SCRAMBCTRL_ENABLE Scrambling/Unscrambling Enable
 * - QSPI_SCRAMBCTRL_RANDOMDIS Scrambling/Unscrambling Random Value Disable
 **/
static inline uint32_t qspi_read_SCRAMBCTRL(void)
{
	return QSPI->SCRAMBCTRL.reg;
}

/**
 * @brief qspi get RXDATA register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_RXDATA_DATA(value) Receive Data
 **/
static inline uint32_t qspi_get_RXDATA(uint32_t mask)
{
    return QSPI->RXDATA.reg & mask;
}

/**
 * @brief qspi read RXDATA register
 *
 * @return uint32_t
 * - QSPI_RXDATA_DATA(value) Receive Data
 **/
static inline uint32_t qspi_read_RXDATA(void)
{
	return QSPI->RXDATA.reg;
}

/**
 * @brief qspi get STATUS register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - QSPI_STATUS_ENABLE Enable
 * - QSPI_STATUS_CSSTATUS Chip Select
 **/
static inline uint32_t qspi_get_STATUS(uint32_t mask)
{
    return QSPI->STATUS.reg & mask;
}

/**
 * @brief qspi read STATUS register
 *
 * @return uint32_t
 * - QSPI_STATUS_ENABLE Enable
 * - QSPI_STATUS_CSSTATUS Chip Select
 **/
static inline uint32_t qspi_read_STATUS(void)
{
	return QSPI->STATUS.reg;
}

#endif /* _QSPI_H */
