/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM I2S
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

#ifndef _I2S_H_
#define _I2S_H_

#include <stdbool.h>

/**
 * @brief i2s wait for sync
 *
 * @param[in] uint16_t reg
 */
static inline void i2s_wait_for_sync(uint16_t reg)
{
	while (I2S->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief i2s is syncing
 *
 * @param[in] uint16_t reg
 * @return bool
 */
static inline bool i2s_is_syncing(uint16_t reg)
{
	return I2S->SYNCBUSY.reg & reg;
}

/**
 * @brief i2s set INTEN register
 *
 * @param[in] uint16_t mask
 * I2S_INTENSET_RXRDY0  Receive Ready 0 Interrupt Enable 
 * I2S_INTENSET_RXRDY1  Receive Ready 1 Interrupt Enable 
 * I2S_INTENSET_RXRDY(value)  Receive Ready x Interrupt Enable 
 * I2S_INTENSET_RXOR0  Receive Overrun 0 Interrupt Enable 
 * I2S_INTENSET_RXOR1  Receive Overrun 1 Interrupt Enable 
 * I2S_INTENSET_RXOR(value)  Receive Overrun x Interrupt Enable 
 * I2S_INTENSET_TXRDY0  Transmit Ready 0 Interrupt Enable 
 * I2S_INTENSET_TXRDY1  Transmit Ready 1 Interrupt Enable 
 * I2S_INTENSET_TXRDY(value)  Transmit Ready x Interrupt Enable 
 * I2S_INTENSET_TXUR0  Transmit Underrun 0 Interrupt Enable 
 * I2S_INTENSET_TXUR1  Transmit Underrun 1 Interrupt Enable 
 * I2S_INTENSET_TXUR(value)  Transmit Underrun x Interrupt Enable 
 */
static inline void i2s_set_INTEN(uint16_t mask)
{
	I2S->INTENSET.reg = mask;
}

/**
 * @brief i2s get INTEN register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * I2S_INTENSET_RXRDY0  Receive Ready 0 Interrupt Enable 
 * I2S_INTENSET_RXRDY1  Receive Ready 1 Interrupt Enable 
 * I2S_INTENSET_RXRDY(value)  Receive Ready x Interrupt Enable 
 * I2S_INTENSET_RXOR0  Receive Overrun 0 Interrupt Enable 
 * I2S_INTENSET_RXOR1  Receive Overrun 1 Interrupt Enable 
 * I2S_INTENSET_RXOR(value)  Receive Overrun x Interrupt Enable 
 * I2S_INTENSET_TXRDY0  Transmit Ready 0 Interrupt Enable 
 * I2S_INTENSET_TXRDY1  Transmit Ready 1 Interrupt Enable 
 * I2S_INTENSET_TXRDY(value)  Transmit Ready x Interrupt Enable 
 * I2S_INTENSET_TXUR0  Transmit Underrun 0 Interrupt Enable 
 * I2S_INTENSET_TXUR1  Transmit Underrun 1 Interrupt Enable 
 * I2S_INTENSET_TXUR(value)  Transmit Underrun x Interrupt Enable 
 */
static inline uint16_t i2s_get_INTEN(uint16_t mask)
{
    return I2S->INTENSET.reg & mask;
}

/**
 * @brief i2s read INTEN register
 *
 * @param[in] void
 * @return uint16_t
 * I2S_INTENSET_RXRDY0  Receive Ready 0 Interrupt Enable 
 * I2S_INTENSET_RXRDY1  Receive Ready 1 Interrupt Enable 
 * I2S_INTENSET_RXRDY(value)  Receive Ready x Interrupt Enable 
 * I2S_INTENSET_RXOR0  Receive Overrun 0 Interrupt Enable 
 * I2S_INTENSET_RXOR1  Receive Overrun 1 Interrupt Enable 
 * I2S_INTENSET_RXOR(value)  Receive Overrun x Interrupt Enable 
 * I2S_INTENSET_TXRDY0  Transmit Ready 0 Interrupt Enable 
 * I2S_INTENSET_TXRDY1  Transmit Ready 1 Interrupt Enable 
 * I2S_INTENSET_TXRDY(value)  Transmit Ready x Interrupt Enable 
 * I2S_INTENSET_TXUR0  Transmit Underrun 0 Interrupt Enable 
 * I2S_INTENSET_TXUR1  Transmit Underrun 1 Interrupt Enable 
 * I2S_INTENSET_TXUR(value)  Transmit Underrun x Interrupt Enable 
 */
static inline uint16_t i2s_read_INTEN(void)
{
	return I2S->INTENSET.reg;
}

/**
 * @brief i2s write INTEN register
 *
 * @param[in] uint16_t data
 * I2S_INTENSET_RXRDY0  Receive Ready 0 Interrupt Enable 
 * I2S_INTENSET_RXRDY1  Receive Ready 1 Interrupt Enable 
 * I2S_INTENSET_RXRDY(value)  Receive Ready x Interrupt Enable 
 * I2S_INTENSET_RXOR0  Receive Overrun 0 Interrupt Enable 
 * I2S_INTENSET_RXOR1  Receive Overrun 1 Interrupt Enable 
 * I2S_INTENSET_RXOR(value)  Receive Overrun x Interrupt Enable 
 * I2S_INTENSET_TXRDY0  Transmit Ready 0 Interrupt Enable 
 * I2S_INTENSET_TXRDY1  Transmit Ready 1 Interrupt Enable 
 * I2S_INTENSET_TXRDY(value)  Transmit Ready x Interrupt Enable 
 * I2S_INTENSET_TXUR0  Transmit Underrun 0 Interrupt Enable 
 * I2S_INTENSET_TXUR1  Transmit Underrun 1 Interrupt Enable 
 * I2S_INTENSET_TXUR(value)  Transmit Underrun x Interrupt Enable 
 */
static inline void i2s_write_INTEN(uint16_t data)
{
	I2S->INTENSET.reg = data;
	I2S->INTENCLR.reg = ~data;
}

/**
 * @brief i2s clear INTEN register
 *
 * @param[in] uint16_t mask
 * I2S_INTENSET_RXRDY0  Receive Ready 0 Interrupt Enable 
 * I2S_INTENSET_RXRDY1  Receive Ready 1 Interrupt Enable 
 * I2S_INTENSET_RXRDY(value)  Receive Ready x Interrupt Enable 
 * I2S_INTENSET_RXOR0  Receive Overrun 0 Interrupt Enable 
 * I2S_INTENSET_RXOR1  Receive Overrun 1 Interrupt Enable 
 * I2S_INTENSET_RXOR(value)  Receive Overrun x Interrupt Enable 
 * I2S_INTENSET_TXRDY0  Transmit Ready 0 Interrupt Enable 
 * I2S_INTENSET_TXRDY1  Transmit Ready 1 Interrupt Enable 
 * I2S_INTENSET_TXRDY(value)  Transmit Ready x Interrupt Enable 
 * I2S_INTENSET_TXUR0  Transmit Underrun 0 Interrupt Enable 
 * I2S_INTENSET_TXUR1  Transmit Underrun 1 Interrupt Enable 
 * I2S_INTENSET_TXUR(value)  Transmit Underrun x Interrupt Enable 
 */
static inline void i2s_clear_INTEN(uint16_t mask)
{
	I2S->INTENCLR.reg = mask;
}

/**
 * @brief i2s get INTFLAG register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * I2S_INTFLAG_RXRDY0  Receive Ready 0 
 * I2S_INTFLAG_RXRDY1  Receive Ready 1 
 * I2S_INTFLAG_RXRDY(value)  Receive Ready x 
 * I2S_INTFLAG_RXOR0  Receive Overrun 0 
 * I2S_INTFLAG_RXOR1  Receive Overrun 1 
 * I2S_INTFLAG_RXOR(value)  Receive Overrun x 
 * I2S_INTFLAG_TXRDY0  Transmit Ready 0 
 * I2S_INTFLAG_TXRDY1  Transmit Ready 1 
 * I2S_INTFLAG_TXRDY(value)  Transmit Ready x 
 * I2S_INTFLAG_TXUR0  Transmit Underrun 0 
 * I2S_INTFLAG_TXUR1  Transmit Underrun 1 
 * I2S_INTFLAG_TXUR(value)  Transmit Underrun x 
 */
static inline uint16_t i2s_get_INTFLAG(uint16_t mask)
{
    return I2S->INTFLAG.reg & mask;
}

/**
 * @brief i2s read INTFLAG register
 *
 * @param[in] void
 * @return uint16_t
 * I2S_INTFLAG_RXRDY0  Receive Ready 0 
 * I2S_INTFLAG_RXRDY1  Receive Ready 1 
 * I2S_INTFLAG_RXRDY(value)  Receive Ready x 
 * I2S_INTFLAG_RXOR0  Receive Overrun 0 
 * I2S_INTFLAG_RXOR1  Receive Overrun 1 
 * I2S_INTFLAG_RXOR(value)  Receive Overrun x 
 * I2S_INTFLAG_TXRDY0  Transmit Ready 0 
 * I2S_INTFLAG_TXRDY1  Transmit Ready 1 
 * I2S_INTFLAG_TXRDY(value)  Transmit Ready x 
 * I2S_INTFLAG_TXUR0  Transmit Underrun 0 
 * I2S_INTFLAG_TXUR1  Transmit Underrun 1 
 * I2S_INTFLAG_TXUR(value)  Transmit Underrun x 
 */
static inline uint16_t i2s_read_INTFLAG(void)
{
	return I2S->INTFLAG.reg;
}

/**
 * @brief i2s clear INTFLAG register
 *
 * @param[in] uint16_t mask
 * I2S_INTFLAG_RXRDY0  Receive Ready 0 
 * I2S_INTFLAG_RXRDY1  Receive Ready 1 
 * I2S_INTFLAG_RXRDY(value)  Receive Ready x 
 * I2S_INTFLAG_RXOR0  Receive Overrun 0 
 * I2S_INTFLAG_RXOR1  Receive Overrun 1 
 * I2S_INTFLAG_RXOR(value)  Receive Overrun x 
 * I2S_INTFLAG_TXRDY0  Transmit Ready 0 
 * I2S_INTFLAG_TXRDY1  Transmit Ready 1 
 * I2S_INTFLAG_TXRDY(value)  Transmit Ready x 
 * I2S_INTFLAG_TXUR0  Transmit Underrun 0 
 * I2S_INTFLAG_TXUR1  Transmit Underrun 1 
 * I2S_INTFLAG_TXUR(value)  Transmit Underrun x 
 */
static inline void i2s_clear_INTFLAG(uint16_t mask)
{
	I2S->INTFLAG.reg = mask;
}

/**
 * @brief i2s write TXDATA register
 *
 * @param[in] uint32_t data
 * I2S_TXDATA_DATA(value)  Sample Data 
 */
static inline void i2s_write_TXDATA(uint32_t data)
{
	I2S->TXDATA.reg = data;
}

/**
 * @brief i2s set CTRLA register
 *
 * @param[in] uint8_t mask
 * I2S_CTRLA_SWRST  Software Reset 
 * I2S_CTRLA_ENABLE  Enable 
 * I2S_CTRLA_CKEN0  Clock Unit 0 Enable 
 * I2S_CTRLA_CKEN1  Clock Unit 1 Enable 
 * I2S_CTRLA_CKEN(value)  Clock Unit x Enable 
 * I2S_CTRLA_TXEN  Tx Serializer Enable 
 * I2S_CTRLA_RXEN  Rx Serializer Enable 
 */
static inline void i2s_set_CTRLA(uint8_t mask)
{
	I2S->CTRLA.reg |= mask;
}

/**
 * @brief i2s get CTRLA register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * I2S_CTRLA_SWRST  Software Reset 
 * I2S_CTRLA_ENABLE  Enable 
 * I2S_CTRLA_CKEN0  Clock Unit 0 Enable 
 * I2S_CTRLA_CKEN1  Clock Unit 1 Enable 
 * I2S_CTRLA_CKEN(value)  Clock Unit x Enable 
 * I2S_CTRLA_TXEN  Tx Serializer Enable 
 * I2S_CTRLA_RXEN  Rx Serializer Enable 
 */
static inline uint8_t i2s_get_CTRLA(uint8_t mask)
{
    return I2S->CTRLA.reg & mask;
}

/**
 * @brief i2s write CTRLA register
 *
 * @param[in] uint8_t data
 * I2S_CTRLA_SWRST  Software Reset 
 * I2S_CTRLA_ENABLE  Enable 
 * I2S_CTRLA_CKEN0  Clock Unit 0 Enable 
 * I2S_CTRLA_CKEN1  Clock Unit 1 Enable 
 * I2S_CTRLA_CKEN(value)  Clock Unit x Enable 
 * I2S_CTRLA_TXEN  Tx Serializer Enable 
 * I2S_CTRLA_RXEN  Rx Serializer Enable 
 */
static inline void i2s_write_CTRLA(uint8_t data)
{
	I2S->CTRLA.reg = data;
}

/**
 * @brief i2s clear CTRLA register
 *
 * @param[in] uint8_t mask
 * I2S_CTRLA_SWRST  Software Reset 
 * I2S_CTRLA_ENABLE  Enable 
 * I2S_CTRLA_CKEN0  Clock Unit 0 Enable 
 * I2S_CTRLA_CKEN1  Clock Unit 1 Enable 
 * I2S_CTRLA_CKEN(value)  Clock Unit x Enable 
 * I2S_CTRLA_TXEN  Tx Serializer Enable 
 * I2S_CTRLA_RXEN  Rx Serializer Enable 
 */
static inline void i2s_clear_CTRLA(uint8_t mask)
{
	I2S->CTRLA.reg &= ~mask;
}

/**
 * @brief i2s read CTRLA register
 *
 * @param[in] void
 * @return uint8_t
 * I2S_CTRLA_SWRST  Software Reset 
 * I2S_CTRLA_ENABLE  Enable 
 * I2S_CTRLA_CKEN0  Clock Unit 0 Enable 
 * I2S_CTRLA_CKEN1  Clock Unit 1 Enable 
 * I2S_CTRLA_CKEN(value)  Clock Unit x Enable 
 * I2S_CTRLA_TXEN  Tx Serializer Enable 
 * I2S_CTRLA_RXEN  Rx Serializer Enable 
 */
static inline uint8_t i2s_read_CTRLA(void)
{
	return I2S->CTRLA.reg;
}

/**
 * @brief i2s set CLKCTRL register
 *
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * I2S_CLKCTRL_SLOTSIZE(value)  Slot Size 
 *    I2S_CLKCTRL_SLOTSIZE_8  8-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_16  16-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_24  24-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_32  32-bit Slot for Clock Unit n 
 * I2S_CLKCTRL_NBSLOTS(value)  Number of Slots in Frame 
 * I2S_CLKCTRL_FSWIDTH(value)  Frame Sync Width 
 *    I2S_CLKCTRL_FSWIDTH_SLOT  Frame Sync Pulse is 1 Slot wide (default for I2S protocol) 
 *    I2S_CLKCTRL_FSWIDTH_HALF  Frame Sync Pulse is half a Frame wide 
 *    I2S_CLKCTRL_FSWIDTH_BIT  Frame Sync Pulse is 1 Bit wide 
 *    I2S_CLKCTRL_FSWIDTH_BURST  Clock Unit n operates in Burst mode, with a 1-bit wide Frame Sync pulse per Data sample, only when Data transfer is requested 
 * I2S_CLKCTRL_BITDELAY  Data Delay from Frame Sync 
 *    I2S_CLKCTRL_BITDELAY_LJ  Left Justified (0 Bit Delay) 
 *    I2S_CLKCTRL_BITDELAY_I2S  I2S (1 Bit Delay) 
 * I2S_CLKCTRL_FSSEL  Frame Sync Select 
 *    I2S_CLKCTRL_FSSEL_SCKDIV  Divided Serial Clock n is used as Frame Sync n source 
 *    I2S_CLKCTRL_FSSEL_FSPIN  FSn input pin is used as Frame Sync n source 
 * I2S_CLKCTRL_FSINV  Frame Sync Invert 
 * I2S_CLKCTRL_FSOUTINV  Frame Sync Output Invert 
 * I2S_CLKCTRL_SCKSEL  Serial Clock Select 
 *    I2S_CLKCTRL_SCKSEL_MCKDIV  Divided Master Clock n is used as Serial Clock n source 
 *    I2S_CLKCTRL_SCKSEL_SCKPIN  SCKn input pin is used as Serial Clock n source 
 * I2S_CLKCTRL_SCKOUTINV  Serial Clock Output Invert 
 * I2S_CLKCTRL_MCKSEL  Master Clock Select 
 *    I2S_CLKCTRL_MCKSEL_GCLK  GCLK_I2S_n is used as Master Clock n source 
 *    I2S_CLKCTRL_MCKSEL_MCKPIN  MCKn input pin is used as Master Clock n source 
 * I2S_CLKCTRL_MCKEN  Master Clock Enable 
 * I2S_CLKCTRL_MCKOUTINV  Master Clock Output Invert 
 * I2S_CLKCTRL_MCKDIV(value)  Master Clock Division Factor 
 * I2S_CLKCTRL_MCKOUTDIV(value)  Master Clock Output Division Factor 
 */
static inline void i2s_set_CLKCTRL(uint8_t index, uint32_t mask)
{
	I2S->CLKCTRL[index].reg |= mask;
}

/**
 * @brief i2s get CLKCTRL register
 *
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * @return uint32_t
 * I2S_CLKCTRL_SLOTSIZE(value)  Slot Size 
 *    I2S_CLKCTRL_SLOTSIZE_8  8-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_16  16-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_24  24-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_32  32-bit Slot for Clock Unit n 
 * I2S_CLKCTRL_NBSLOTS(value)  Number of Slots in Frame 
 * I2S_CLKCTRL_FSWIDTH(value)  Frame Sync Width 
 *    I2S_CLKCTRL_FSWIDTH_SLOT  Frame Sync Pulse is 1 Slot wide (default for I2S protocol) 
 *    I2S_CLKCTRL_FSWIDTH_HALF  Frame Sync Pulse is half a Frame wide 
 *    I2S_CLKCTRL_FSWIDTH_BIT  Frame Sync Pulse is 1 Bit wide 
 *    I2S_CLKCTRL_FSWIDTH_BURST  Clock Unit n operates in Burst mode, with a 1-bit wide Frame Sync pulse per Data sample, only when Data transfer is requested 
 * I2S_CLKCTRL_BITDELAY  Data Delay from Frame Sync 
 *    I2S_CLKCTRL_BITDELAY_LJ  Left Justified (0 Bit Delay) 
 *    I2S_CLKCTRL_BITDELAY_I2S  I2S (1 Bit Delay) 
 * I2S_CLKCTRL_FSSEL  Frame Sync Select 
 *    I2S_CLKCTRL_FSSEL_SCKDIV  Divided Serial Clock n is used as Frame Sync n source 
 *    I2S_CLKCTRL_FSSEL_FSPIN  FSn input pin is used as Frame Sync n source 
 * I2S_CLKCTRL_FSINV  Frame Sync Invert 
 * I2S_CLKCTRL_FSOUTINV  Frame Sync Output Invert 
 * I2S_CLKCTRL_SCKSEL  Serial Clock Select 
 *    I2S_CLKCTRL_SCKSEL_MCKDIV  Divided Master Clock n is used as Serial Clock n source 
 *    I2S_CLKCTRL_SCKSEL_SCKPIN  SCKn input pin is used as Serial Clock n source 
 * I2S_CLKCTRL_SCKOUTINV  Serial Clock Output Invert 
 * I2S_CLKCTRL_MCKSEL  Master Clock Select 
 *    I2S_CLKCTRL_MCKSEL_GCLK  GCLK_I2S_n is used as Master Clock n source 
 *    I2S_CLKCTRL_MCKSEL_MCKPIN  MCKn input pin is used as Master Clock n source 
 * I2S_CLKCTRL_MCKEN  Master Clock Enable 
 * I2S_CLKCTRL_MCKOUTINV  Master Clock Output Invert 
 * I2S_CLKCTRL_MCKDIV(value)  Master Clock Division Factor 
 * I2S_CLKCTRL_MCKOUTDIV(value)  Master Clock Output Division Factor 
 */
static inline uint32_t i2s_get_CLKCTRL(uint8_t index, uint32_t mask)
{
    return I2S->CLKCTRL[index].reg & mask;
}

/**
 * @brief i2s write CLKCTRL register
 *
 * @param[in] uint8_t index
 * @param[in] uint32_t data
 * I2S_CLKCTRL_SLOTSIZE(value)  Slot Size 
 *    I2S_CLKCTRL_SLOTSIZE_8  8-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_16  16-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_24  24-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_32  32-bit Slot for Clock Unit n 
 * I2S_CLKCTRL_NBSLOTS(value)  Number of Slots in Frame 
 * I2S_CLKCTRL_FSWIDTH(value)  Frame Sync Width 
 *    I2S_CLKCTRL_FSWIDTH_SLOT  Frame Sync Pulse is 1 Slot wide (default for I2S protocol) 
 *    I2S_CLKCTRL_FSWIDTH_HALF  Frame Sync Pulse is half a Frame wide 
 *    I2S_CLKCTRL_FSWIDTH_BIT  Frame Sync Pulse is 1 Bit wide 
 *    I2S_CLKCTRL_FSWIDTH_BURST  Clock Unit n operates in Burst mode, with a 1-bit wide Frame Sync pulse per Data sample, only when Data transfer is requested 
 * I2S_CLKCTRL_BITDELAY  Data Delay from Frame Sync 
 *    I2S_CLKCTRL_BITDELAY_LJ  Left Justified (0 Bit Delay) 
 *    I2S_CLKCTRL_BITDELAY_I2S  I2S (1 Bit Delay) 
 * I2S_CLKCTRL_FSSEL  Frame Sync Select 
 *    I2S_CLKCTRL_FSSEL_SCKDIV  Divided Serial Clock n is used as Frame Sync n source 
 *    I2S_CLKCTRL_FSSEL_FSPIN  FSn input pin is used as Frame Sync n source 
 * I2S_CLKCTRL_FSINV  Frame Sync Invert 
 * I2S_CLKCTRL_FSOUTINV  Frame Sync Output Invert 
 * I2S_CLKCTRL_SCKSEL  Serial Clock Select 
 *    I2S_CLKCTRL_SCKSEL_MCKDIV  Divided Master Clock n is used as Serial Clock n source 
 *    I2S_CLKCTRL_SCKSEL_SCKPIN  SCKn input pin is used as Serial Clock n source 
 * I2S_CLKCTRL_SCKOUTINV  Serial Clock Output Invert 
 * I2S_CLKCTRL_MCKSEL  Master Clock Select 
 *    I2S_CLKCTRL_MCKSEL_GCLK  GCLK_I2S_n is used as Master Clock n source 
 *    I2S_CLKCTRL_MCKSEL_MCKPIN  MCKn input pin is used as Master Clock n source 
 * I2S_CLKCTRL_MCKEN  Master Clock Enable 
 * I2S_CLKCTRL_MCKOUTINV  Master Clock Output Invert 
 * I2S_CLKCTRL_MCKDIV(value)  Master Clock Division Factor 
 * I2S_CLKCTRL_MCKOUTDIV(value)  Master Clock Output Division Factor 
 */
static inline void i2s_write_CLKCTRL(uint8_t index, uint32_t data)
{
	I2S->CLKCTRL[index].reg = data;
}

/**
 * @brief i2s clear CLKCTRL register
 *
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * I2S_CLKCTRL_SLOTSIZE(value)  Slot Size 
 *    I2S_CLKCTRL_SLOTSIZE_8  8-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_16  16-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_24  24-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_32  32-bit Slot for Clock Unit n 
 * I2S_CLKCTRL_NBSLOTS(value)  Number of Slots in Frame 
 * I2S_CLKCTRL_FSWIDTH(value)  Frame Sync Width 
 *    I2S_CLKCTRL_FSWIDTH_SLOT  Frame Sync Pulse is 1 Slot wide (default for I2S protocol) 
 *    I2S_CLKCTRL_FSWIDTH_HALF  Frame Sync Pulse is half a Frame wide 
 *    I2S_CLKCTRL_FSWIDTH_BIT  Frame Sync Pulse is 1 Bit wide 
 *    I2S_CLKCTRL_FSWIDTH_BURST  Clock Unit n operates in Burst mode, with a 1-bit wide Frame Sync pulse per Data sample, only when Data transfer is requested 
 * I2S_CLKCTRL_BITDELAY  Data Delay from Frame Sync 
 *    I2S_CLKCTRL_BITDELAY_LJ  Left Justified (0 Bit Delay) 
 *    I2S_CLKCTRL_BITDELAY_I2S  I2S (1 Bit Delay) 
 * I2S_CLKCTRL_FSSEL  Frame Sync Select 
 *    I2S_CLKCTRL_FSSEL_SCKDIV  Divided Serial Clock n is used as Frame Sync n source 
 *    I2S_CLKCTRL_FSSEL_FSPIN  FSn input pin is used as Frame Sync n source 
 * I2S_CLKCTRL_FSINV  Frame Sync Invert 
 * I2S_CLKCTRL_FSOUTINV  Frame Sync Output Invert 
 * I2S_CLKCTRL_SCKSEL  Serial Clock Select 
 *    I2S_CLKCTRL_SCKSEL_MCKDIV  Divided Master Clock n is used as Serial Clock n source 
 *    I2S_CLKCTRL_SCKSEL_SCKPIN  SCKn input pin is used as Serial Clock n source 
 * I2S_CLKCTRL_SCKOUTINV  Serial Clock Output Invert 
 * I2S_CLKCTRL_MCKSEL  Master Clock Select 
 *    I2S_CLKCTRL_MCKSEL_GCLK  GCLK_I2S_n is used as Master Clock n source 
 *    I2S_CLKCTRL_MCKSEL_MCKPIN  MCKn input pin is used as Master Clock n source 
 * I2S_CLKCTRL_MCKEN  Master Clock Enable 
 * I2S_CLKCTRL_MCKOUTINV  Master Clock Output Invert 
 * I2S_CLKCTRL_MCKDIV(value)  Master Clock Division Factor 
 * I2S_CLKCTRL_MCKOUTDIV(value)  Master Clock Output Division Factor 
 */
static inline void i2s_clear_CLKCTRL(uint8_t index, uint32_t mask)
{
	I2S->CLKCTRL[index].reg &= ~mask;
}

/**
 * @brief i2s read CLKCTRL register
 *
 * @param[in] uint8_t index
 * @return uint32_t
 * I2S_CLKCTRL_SLOTSIZE(value)  Slot Size 
 *    I2S_CLKCTRL_SLOTSIZE_8  8-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_16  16-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_24  24-bit Slot for Clock Unit n 
 *    I2S_CLKCTRL_SLOTSIZE_32  32-bit Slot for Clock Unit n 
 * I2S_CLKCTRL_NBSLOTS(value)  Number of Slots in Frame 
 * I2S_CLKCTRL_FSWIDTH(value)  Frame Sync Width 
 *    I2S_CLKCTRL_FSWIDTH_SLOT  Frame Sync Pulse is 1 Slot wide (default for I2S protocol) 
 *    I2S_CLKCTRL_FSWIDTH_HALF  Frame Sync Pulse is half a Frame wide 
 *    I2S_CLKCTRL_FSWIDTH_BIT  Frame Sync Pulse is 1 Bit wide 
 *    I2S_CLKCTRL_FSWIDTH_BURST  Clock Unit n operates in Burst mode, with a 1-bit wide Frame Sync pulse per Data sample, only when Data transfer is requested 
 * I2S_CLKCTRL_BITDELAY  Data Delay from Frame Sync 
 *    I2S_CLKCTRL_BITDELAY_LJ  Left Justified (0 Bit Delay) 
 *    I2S_CLKCTRL_BITDELAY_I2S  I2S (1 Bit Delay) 
 * I2S_CLKCTRL_FSSEL  Frame Sync Select 
 *    I2S_CLKCTRL_FSSEL_SCKDIV  Divided Serial Clock n is used as Frame Sync n source 
 *    I2S_CLKCTRL_FSSEL_FSPIN  FSn input pin is used as Frame Sync n source 
 * I2S_CLKCTRL_FSINV  Frame Sync Invert 
 * I2S_CLKCTRL_FSOUTINV  Frame Sync Output Invert 
 * I2S_CLKCTRL_SCKSEL  Serial Clock Select 
 *    I2S_CLKCTRL_SCKSEL_MCKDIV  Divided Master Clock n is used as Serial Clock n source 
 *    I2S_CLKCTRL_SCKSEL_SCKPIN  SCKn input pin is used as Serial Clock n source 
 * I2S_CLKCTRL_SCKOUTINV  Serial Clock Output Invert 
 * I2S_CLKCTRL_MCKSEL  Master Clock Select 
 *    I2S_CLKCTRL_MCKSEL_GCLK  GCLK_I2S_n is used as Master Clock n source 
 *    I2S_CLKCTRL_MCKSEL_MCKPIN  MCKn input pin is used as Master Clock n source 
 * I2S_CLKCTRL_MCKEN  Master Clock Enable 
 * I2S_CLKCTRL_MCKOUTINV  Master Clock Output Invert 
 * I2S_CLKCTRL_MCKDIV(value)  Master Clock Division Factor 
 * I2S_CLKCTRL_MCKOUTDIV(value)  Master Clock Output Division Factor 
 */
static inline uint32_t i2s_read_CLKCTRL(uint8_t index)
{
	return I2S->CLKCTRL[index].reg;
}

/**
 * @brief i2s set TXCTRL register
 *
 * @param[in] uint32_t mask
 * I2S_TXCTRL_TXDEFAULT(value)  Line Default Line when Slot Disabled 
 *    I2S_TXCTRL_TXDEFAULT_ZERO  Output Default Value is 0 
 *    I2S_TXCTRL_TXDEFAULT_ONE  Output Default Value is 1 
 *    I2S_TXCTRL_TXDEFAULT_HIZ  Output Default Value is high impedance 
 * I2S_TXCTRL_TXSAME  Transmit Data when Underrun 
 *    I2S_TXCTRL_TXSAME_ZERO  Zero data transmitted in case of underrun 
 *    I2S_TXCTRL_TXSAME_SAME  Last data transmitted in case of underrun 
 * I2S_TXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_TXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_TXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_TXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_TXCTRL_DATASIZE_32  32 bits 
 *    I2S_TXCTRL_DATASIZE_24  24 bits 
 *    I2S_TXCTRL_DATASIZE_20  20 bits 
 *    I2S_TXCTRL_DATASIZE_18  18 bits 
 *    I2S_TXCTRL_DATASIZE_16  16 bits 
 *    I2S_TXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_TXCTRL_DATASIZE_8  8 bits 
 *    I2S_TXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_TXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_TXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_TXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_TXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_TXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_TXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_TXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_TXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_TXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_TXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_TXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_TXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_TXCTRL_MONO  Mono Mode 
 *    I2S_TXCTRL_MONO_STEREO  Normal mode 
 *    I2S_TXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_TXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_TXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_TXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 */
static inline void i2s_set_TXCTRL(uint32_t mask)
{
	I2S->TXCTRL.reg |= mask;
}

/**
 * @brief i2s get TXCTRL register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * I2S_TXCTRL_TXDEFAULT(value)  Line Default Line when Slot Disabled 
 *    I2S_TXCTRL_TXDEFAULT_ZERO  Output Default Value is 0 
 *    I2S_TXCTRL_TXDEFAULT_ONE  Output Default Value is 1 
 *    I2S_TXCTRL_TXDEFAULT_HIZ  Output Default Value is high impedance 
 * I2S_TXCTRL_TXSAME  Transmit Data when Underrun 
 *    I2S_TXCTRL_TXSAME_ZERO  Zero data transmitted in case of underrun 
 *    I2S_TXCTRL_TXSAME_SAME  Last data transmitted in case of underrun 
 * I2S_TXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_TXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_TXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_TXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_TXCTRL_DATASIZE_32  32 bits 
 *    I2S_TXCTRL_DATASIZE_24  24 bits 
 *    I2S_TXCTRL_DATASIZE_20  20 bits 
 *    I2S_TXCTRL_DATASIZE_18  18 bits 
 *    I2S_TXCTRL_DATASIZE_16  16 bits 
 *    I2S_TXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_TXCTRL_DATASIZE_8  8 bits 
 *    I2S_TXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_TXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_TXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_TXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_TXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_TXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_TXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_TXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_TXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_TXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_TXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_TXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_TXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_TXCTRL_MONO  Mono Mode 
 *    I2S_TXCTRL_MONO_STEREO  Normal mode 
 *    I2S_TXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_TXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_TXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_TXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 */
static inline uint32_t i2s_get_TXCTRL(uint32_t mask)
{
    return I2S->TXCTRL.reg & mask;
}

/**
 * @brief i2s write TXCTRL register
 *
 * @param[in] uint32_t data
 * I2S_TXCTRL_TXDEFAULT(value)  Line Default Line when Slot Disabled 
 *    I2S_TXCTRL_TXDEFAULT_ZERO  Output Default Value is 0 
 *    I2S_TXCTRL_TXDEFAULT_ONE  Output Default Value is 1 
 *    I2S_TXCTRL_TXDEFAULT_HIZ  Output Default Value is high impedance 
 * I2S_TXCTRL_TXSAME  Transmit Data when Underrun 
 *    I2S_TXCTRL_TXSAME_ZERO  Zero data transmitted in case of underrun 
 *    I2S_TXCTRL_TXSAME_SAME  Last data transmitted in case of underrun 
 * I2S_TXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_TXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_TXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_TXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_TXCTRL_DATASIZE_32  32 bits 
 *    I2S_TXCTRL_DATASIZE_24  24 bits 
 *    I2S_TXCTRL_DATASIZE_20  20 bits 
 *    I2S_TXCTRL_DATASIZE_18  18 bits 
 *    I2S_TXCTRL_DATASIZE_16  16 bits 
 *    I2S_TXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_TXCTRL_DATASIZE_8  8 bits 
 *    I2S_TXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_TXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_TXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_TXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_TXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_TXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_TXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_TXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_TXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_TXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_TXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_TXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_TXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_TXCTRL_MONO  Mono Mode 
 *    I2S_TXCTRL_MONO_STEREO  Normal mode 
 *    I2S_TXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_TXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_TXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_TXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 */
static inline void i2s_write_TXCTRL(uint32_t data)
{
	I2S->TXCTRL.reg = data;
}

/**
 * @brief i2s clear TXCTRL register
 *
 * @param[in] uint32_t mask
 * I2S_TXCTRL_TXDEFAULT(value)  Line Default Line when Slot Disabled 
 *    I2S_TXCTRL_TXDEFAULT_ZERO  Output Default Value is 0 
 *    I2S_TXCTRL_TXDEFAULT_ONE  Output Default Value is 1 
 *    I2S_TXCTRL_TXDEFAULT_HIZ  Output Default Value is high impedance 
 * I2S_TXCTRL_TXSAME  Transmit Data when Underrun 
 *    I2S_TXCTRL_TXSAME_ZERO  Zero data transmitted in case of underrun 
 *    I2S_TXCTRL_TXSAME_SAME  Last data transmitted in case of underrun 
 * I2S_TXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_TXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_TXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_TXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_TXCTRL_DATASIZE_32  32 bits 
 *    I2S_TXCTRL_DATASIZE_24  24 bits 
 *    I2S_TXCTRL_DATASIZE_20  20 bits 
 *    I2S_TXCTRL_DATASIZE_18  18 bits 
 *    I2S_TXCTRL_DATASIZE_16  16 bits 
 *    I2S_TXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_TXCTRL_DATASIZE_8  8 bits 
 *    I2S_TXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_TXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_TXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_TXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_TXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_TXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_TXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_TXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_TXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_TXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_TXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_TXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_TXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_TXCTRL_MONO  Mono Mode 
 *    I2S_TXCTRL_MONO_STEREO  Normal mode 
 *    I2S_TXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_TXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_TXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_TXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 */
static inline void i2s_clear_TXCTRL(uint32_t mask)
{
	I2S->TXCTRL.reg &= ~mask;
}

/**
 * @brief i2s read TXCTRL register
 *
 * @param[in] void
 * @return uint32_t
 * I2S_TXCTRL_TXDEFAULT(value)  Line Default Line when Slot Disabled 
 *    I2S_TXCTRL_TXDEFAULT_ZERO  Output Default Value is 0 
 *    I2S_TXCTRL_TXDEFAULT_ONE  Output Default Value is 1 
 *    I2S_TXCTRL_TXDEFAULT_HIZ  Output Default Value is high impedance 
 * I2S_TXCTRL_TXSAME  Transmit Data when Underrun 
 *    I2S_TXCTRL_TXSAME_ZERO  Zero data transmitted in case of underrun 
 *    I2S_TXCTRL_TXSAME_SAME  Last data transmitted in case of underrun 
 * I2S_TXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_TXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_TXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_TXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_TXCTRL_DATASIZE_32  32 bits 
 *    I2S_TXCTRL_DATASIZE_24  24 bits 
 *    I2S_TXCTRL_DATASIZE_20  20 bits 
 *    I2S_TXCTRL_DATASIZE_18  18 bits 
 *    I2S_TXCTRL_DATASIZE_16  16 bits 
 *    I2S_TXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_TXCTRL_DATASIZE_8  8 bits 
 *    I2S_TXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_TXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_TXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_TXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_TXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_TXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_TXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_TXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_TXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_TXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_TXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_TXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_TXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_TXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_TXCTRL_MONO  Mono Mode 
 *    I2S_TXCTRL_MONO_STEREO  Normal mode 
 *    I2S_TXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_TXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_TXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_TXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 */
static inline uint32_t i2s_read_TXCTRL(void)
{
	return I2S->TXCTRL.reg;
}

/**
 * @brief i2s set RXCTRL register
 *
 * @param[in] uint32_t mask
 * I2S_RXCTRL_SERMODE(value)  Serializer Mode 
 *    I2S_RXCTRL_SERMODE_RX  Receive 
 *    I2S_RXCTRL_SERMODE_PDM2  Receive one PDM data on each serial clock edge 
 * I2S_RXCTRL_CLKSEL  Clock Unit Selection 
 *    I2S_RXCTRL_CLKSEL_CLK0  Use Clock Unit 0 
 *    I2S_RXCTRL_CLKSEL_CLK1  Use Clock Unit 1 
 * I2S_RXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_RXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_RXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_RXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_RXCTRL_DATASIZE_32  32 bits 
 *    I2S_RXCTRL_DATASIZE_24  24 bits 
 *    I2S_RXCTRL_DATASIZE_20  20 bits 
 *    I2S_RXCTRL_DATASIZE_18  18 bits 
 *    I2S_RXCTRL_DATASIZE_16  16 bits 
 *    I2S_RXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_RXCTRL_DATASIZE_8  8 bits 
 *    I2S_RXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_RXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_RXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_RXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_RXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_RXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_RXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_RXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_RXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_RXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_RXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_RXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_RXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_RXCTRL_MONO  Mono Mode 
 *    I2S_RXCTRL_MONO_STEREO  Normal mode 
 *    I2S_RXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_RXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_RXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_RXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 * I2S_RXCTRL_RXLOOP  Loop-back Test Mode 
 */
static inline void i2s_set_RXCTRL(uint32_t mask)
{
	I2S->RXCTRL.reg |= mask;
}

/**
 * @brief i2s get RXCTRL register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * I2S_RXCTRL_SERMODE(value)  Serializer Mode 
 *    I2S_RXCTRL_SERMODE_RX  Receive 
 *    I2S_RXCTRL_SERMODE_PDM2  Receive one PDM data on each serial clock edge 
 * I2S_RXCTRL_CLKSEL  Clock Unit Selection 
 *    I2S_RXCTRL_CLKSEL_CLK0  Use Clock Unit 0 
 *    I2S_RXCTRL_CLKSEL_CLK1  Use Clock Unit 1 
 * I2S_RXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_RXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_RXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_RXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_RXCTRL_DATASIZE_32  32 bits 
 *    I2S_RXCTRL_DATASIZE_24  24 bits 
 *    I2S_RXCTRL_DATASIZE_20  20 bits 
 *    I2S_RXCTRL_DATASIZE_18  18 bits 
 *    I2S_RXCTRL_DATASIZE_16  16 bits 
 *    I2S_RXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_RXCTRL_DATASIZE_8  8 bits 
 *    I2S_RXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_RXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_RXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_RXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_RXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_RXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_RXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_RXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_RXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_RXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_RXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_RXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_RXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_RXCTRL_MONO  Mono Mode 
 *    I2S_RXCTRL_MONO_STEREO  Normal mode 
 *    I2S_RXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_RXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_RXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_RXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 * I2S_RXCTRL_RXLOOP  Loop-back Test Mode 
 */
static inline uint32_t i2s_get_RXCTRL(uint32_t mask)
{
    return I2S->RXCTRL.reg & mask;
}

/**
 * @brief i2s write RXCTRL register
 *
 * @param[in] uint32_t data
 * I2S_RXCTRL_SERMODE(value)  Serializer Mode 
 *    I2S_RXCTRL_SERMODE_RX  Receive 
 *    I2S_RXCTRL_SERMODE_PDM2  Receive one PDM data on each serial clock edge 
 * I2S_RXCTRL_CLKSEL  Clock Unit Selection 
 *    I2S_RXCTRL_CLKSEL_CLK0  Use Clock Unit 0 
 *    I2S_RXCTRL_CLKSEL_CLK1  Use Clock Unit 1 
 * I2S_RXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_RXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_RXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_RXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_RXCTRL_DATASIZE_32  32 bits 
 *    I2S_RXCTRL_DATASIZE_24  24 bits 
 *    I2S_RXCTRL_DATASIZE_20  20 bits 
 *    I2S_RXCTRL_DATASIZE_18  18 bits 
 *    I2S_RXCTRL_DATASIZE_16  16 bits 
 *    I2S_RXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_RXCTRL_DATASIZE_8  8 bits 
 *    I2S_RXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_RXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_RXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_RXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_RXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_RXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_RXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_RXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_RXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_RXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_RXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_RXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_RXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_RXCTRL_MONO  Mono Mode 
 *    I2S_RXCTRL_MONO_STEREO  Normal mode 
 *    I2S_RXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_RXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_RXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_RXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 * I2S_RXCTRL_RXLOOP  Loop-back Test Mode 
 */
static inline void i2s_write_RXCTRL(uint32_t data)
{
	I2S->RXCTRL.reg = data;
}

/**
 * @brief i2s clear RXCTRL register
 *
 * @param[in] uint32_t mask
 * I2S_RXCTRL_SERMODE(value)  Serializer Mode 
 *    I2S_RXCTRL_SERMODE_RX  Receive 
 *    I2S_RXCTRL_SERMODE_PDM2  Receive one PDM data on each serial clock edge 
 * I2S_RXCTRL_CLKSEL  Clock Unit Selection 
 *    I2S_RXCTRL_CLKSEL_CLK0  Use Clock Unit 0 
 *    I2S_RXCTRL_CLKSEL_CLK1  Use Clock Unit 1 
 * I2S_RXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_RXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_RXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_RXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_RXCTRL_DATASIZE_32  32 bits 
 *    I2S_RXCTRL_DATASIZE_24  24 bits 
 *    I2S_RXCTRL_DATASIZE_20  20 bits 
 *    I2S_RXCTRL_DATASIZE_18  18 bits 
 *    I2S_RXCTRL_DATASIZE_16  16 bits 
 *    I2S_RXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_RXCTRL_DATASIZE_8  8 bits 
 *    I2S_RXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_RXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_RXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_RXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_RXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_RXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_RXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_RXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_RXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_RXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_RXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_RXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_RXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_RXCTRL_MONO  Mono Mode 
 *    I2S_RXCTRL_MONO_STEREO  Normal mode 
 *    I2S_RXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_RXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_RXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_RXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 * I2S_RXCTRL_RXLOOP  Loop-back Test Mode 
 */
static inline void i2s_clear_RXCTRL(uint32_t mask)
{
	I2S->RXCTRL.reg &= ~mask;
}

/**
 * @brief i2s read RXCTRL register
 *
 * @param[in] void
 * @return uint32_t
 * I2S_RXCTRL_SERMODE(value)  Serializer Mode 
 *    I2S_RXCTRL_SERMODE_RX  Receive 
 *    I2S_RXCTRL_SERMODE_PDM2  Receive one PDM data on each serial clock edge 
 * I2S_RXCTRL_CLKSEL  Clock Unit Selection 
 *    I2S_RXCTRL_CLKSEL_CLK0  Use Clock Unit 0 
 *    I2S_RXCTRL_CLKSEL_CLK1  Use Clock Unit 1 
 * I2S_RXCTRL_SLOTADJ  Data Slot Formatting Adjust 
 *    I2S_RXCTRL_SLOTADJ_RIGHT  Data is right adjusted in slot 
 *    I2S_RXCTRL_SLOTADJ_LEFT  Data is left adjusted in slot 
 * I2S_RXCTRL_DATASIZE(value)  Data Word Size 
 *    I2S_RXCTRL_DATASIZE_32  32 bits 
 *    I2S_RXCTRL_DATASIZE_24  24 bits 
 *    I2S_RXCTRL_DATASIZE_20  20 bits 
 *    I2S_RXCTRL_DATASIZE_18  18 bits 
 *    I2S_RXCTRL_DATASIZE_16  16 bits 
 *    I2S_RXCTRL_DATASIZE_16C  16 bits compact stereo 
 *    I2S_RXCTRL_DATASIZE_8  8 bits 
 *    I2S_RXCTRL_DATASIZE_8C  8 bits compact stereo 
 * I2S_RXCTRL_WORDADJ  Data Word Formatting Adjust 
 *    I2S_RXCTRL_WORDADJ_RIGHT  Data is right adjusted in word 
 *    I2S_RXCTRL_WORDADJ_LEFT  Data is left adjusted in word 
 * I2S_RXCTRL_EXTEND(value)  Data Formatting Bit Extension 
 *    I2S_RXCTRL_EXTEND_ZERO  Extend with zeroes 
 *    I2S_RXCTRL_EXTEND_ONE  Extend with ones 
 *    I2S_RXCTRL_EXTEND_MSBIT  Extend with Most Significant Bit 
 *    I2S_RXCTRL_EXTEND_LSBIT  Extend with Least Significant Bit 
 * I2S_RXCTRL_BITREV  Data Formatting Bit Reverse 
 *    I2S_RXCTRL_BITREV_MSBIT  Transfer Data Most Significant Bit first (default for I2S protocol) 
 *    I2S_RXCTRL_BITREV_LSBIT  Transfer Data Least Significant Bit first 
 * I2S_RXCTRL_SLOTDIS0  Slot 0 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS1  Slot 1 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS2  Slot 2 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS3  Slot 3 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS4  Slot 4 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS5  Slot 5 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS6  Slot 6 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS7  Slot 7 Disabled for this Serializer 
 * I2S_RXCTRL_SLOTDIS(value)  Slot x Disabled for this Serializer 
 * I2S_RXCTRL_MONO  Mono Mode 
 *    I2S_RXCTRL_MONO_STEREO  Normal mode 
 *    I2S_RXCTRL_MONO_MONO  Left channel data is duplicated to right channel 
 * I2S_RXCTRL_DMA  Single or Multiple DMA Channels 
 *    I2S_RXCTRL_DMA_SINGLE  Single DMA channel 
 *    I2S_RXCTRL_DMA_MULTIPLE  One DMA channel per data channel 
 * I2S_RXCTRL_RXLOOP  Loop-back Test Mode 
 */
static inline uint32_t i2s_read_RXCTRL(void)
{
	return I2S->RXCTRL.reg;
}

/**
 * @brief i2s get SYNCBUSY register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * I2S_SYNCBUSY_SWRST  Software Reset Synchronization Status 
 * I2S_SYNCBUSY_ENABLE  Enable Synchronization Status 
 * I2S_SYNCBUSY_CKEN0  Clock Unit 0 Enable Synchronization Status 
 * I2S_SYNCBUSY_CKEN1  Clock Unit 1 Enable Synchronization Status 
 * I2S_SYNCBUSY_CKEN(value)  Clock Unit x Enable Synchronization Status 
 * I2S_SYNCBUSY_TXEN  Tx Serializer Enable Synchronization Status 
 * I2S_SYNCBUSY_RXEN  Rx Serializer Enable Synchronization Status 
 * I2S_SYNCBUSY_TXDATA  Tx Data Synchronization Status 
 * I2S_SYNCBUSY_RXDATA  Rx Data Synchronization Status 
 */
static inline uint16_t i2s_get_SYNCBUSY(uint16_t mask)
{
    return I2S->SYNCBUSY.reg & mask;
}

/**
 * @brief i2s read SYNCBUSY register
 *
 * @param[in] void
 * @return uint16_t
 * I2S_SYNCBUSY_SWRST  Software Reset Synchronization Status 
 * I2S_SYNCBUSY_ENABLE  Enable Synchronization Status 
 * I2S_SYNCBUSY_CKEN0  Clock Unit 0 Enable Synchronization Status 
 * I2S_SYNCBUSY_CKEN1  Clock Unit 1 Enable Synchronization Status 
 * I2S_SYNCBUSY_CKEN(value)  Clock Unit x Enable Synchronization Status 
 * I2S_SYNCBUSY_TXEN  Tx Serializer Enable Synchronization Status 
 * I2S_SYNCBUSY_RXEN  Rx Serializer Enable Synchronization Status 
 * I2S_SYNCBUSY_TXDATA  Tx Data Synchronization Status 
 * I2S_SYNCBUSY_RXDATA  Rx Data Synchronization Status 
 */
static inline uint16_t i2s_read_SYNCBUSY(void)
{
	return I2S->SYNCBUSY.reg;
}

/**
 * @brief i2s get RXDATA register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * I2S_RXDATA_DATA(value)  Sample Data 
 */
static inline uint32_t i2s_get_RXDATA(uint32_t mask)
{
    return I2S->RXDATA.reg & mask;
}

/**
 * @brief i2s read RXDATA register
 *
 * @param[in] void
 * @return uint32_t
 * I2S_RXDATA_DATA(value)  Sample Data 
 */
static inline uint32_t i2s_read_RXDATA(void)
{
	return I2S->RXDATA.reg;
}

#endif /* _I2S_H */
