/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM DAC
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

#ifndef _DAC_H_
#define _DAC_H_

#include <stdbool.h>

/**
 * @brief dac wait for sync
 *
 * @param[in] uint32_t reg
 */
static inline void dac_wait_for_sync(uint32_t reg)
{
	while (DAC->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief dac is syncing
 *
 * @param[in] uint32_t reg
 * @return bool
 */
static inline bool dac_is_syncing(uint32_t reg)
{
	return DAC->SYNCBUSY.reg & reg;
}

/**
 * @brief dac set INTEN register
 *
 * @param[in] uint8_t mask
 * DAC_INTENSET_UNDERRUN0  Underrun 0 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN1  Underrun 1 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN(value)  Underrun x Interrupt Enable 
 * DAC_INTENSET_EMPTY0  Data Buffer 0 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY1  Data Buffer 1 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY(value)  Data Buffer x Empty Interrupt Enable 
 * DAC_INTENSET_RESRDY0  Result 0 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY1  Result 1 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY(value)  Result x Ready Interrupt Enable 
 * DAC_INTENSET_OVERRUN0  Overrun 0 Interrupt Enable 
 * DAC_INTENSET_OVERRUN1  Overrun 1 Interrupt Enable 
 * DAC_INTENSET_OVERRUN(value)  Overrun x Interrupt Enable 
 */
static inline void dac_set_INTEN(uint8_t mask)
{
	DAC->INTENSET.reg = mask;
}

/**
 * @brief dac get INTEN register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * DAC_INTENSET_UNDERRUN0  Underrun 0 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN1  Underrun 1 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN(value)  Underrun x Interrupt Enable 
 * DAC_INTENSET_EMPTY0  Data Buffer 0 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY1  Data Buffer 1 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY(value)  Data Buffer x Empty Interrupt Enable 
 * DAC_INTENSET_RESRDY0  Result 0 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY1  Result 1 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY(value)  Result x Ready Interrupt Enable 
 * DAC_INTENSET_OVERRUN0  Overrun 0 Interrupt Enable 
 * DAC_INTENSET_OVERRUN1  Overrun 1 Interrupt Enable 
 * DAC_INTENSET_OVERRUN(value)  Overrun x Interrupt Enable 
 */
static inline uint8_t dac_get_INTEN(uint8_t mask)
{
    return DAC->INTENSET.reg & mask;
}

/**
 * @brief dac read INTEN register
 *
 * @param[in] void
 * @return uint8_t
 * DAC_INTENSET_UNDERRUN0  Underrun 0 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN1  Underrun 1 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN(value)  Underrun x Interrupt Enable 
 * DAC_INTENSET_EMPTY0  Data Buffer 0 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY1  Data Buffer 1 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY(value)  Data Buffer x Empty Interrupt Enable 
 * DAC_INTENSET_RESRDY0  Result 0 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY1  Result 1 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY(value)  Result x Ready Interrupt Enable 
 * DAC_INTENSET_OVERRUN0  Overrun 0 Interrupt Enable 
 * DAC_INTENSET_OVERRUN1  Overrun 1 Interrupt Enable 
 * DAC_INTENSET_OVERRUN(value)  Overrun x Interrupt Enable 
 */
static inline uint8_t dac_read_INTEN(void)
{
	return DAC->INTENSET.reg;
}

/**
 * @brief dac write INTEN register
 *
 * @param[in] uint8_t data
 * DAC_INTENSET_UNDERRUN0  Underrun 0 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN1  Underrun 1 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN(value)  Underrun x Interrupt Enable 
 * DAC_INTENSET_EMPTY0  Data Buffer 0 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY1  Data Buffer 1 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY(value)  Data Buffer x Empty Interrupt Enable 
 * DAC_INTENSET_RESRDY0  Result 0 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY1  Result 1 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY(value)  Result x Ready Interrupt Enable 
 * DAC_INTENSET_OVERRUN0  Overrun 0 Interrupt Enable 
 * DAC_INTENSET_OVERRUN1  Overrun 1 Interrupt Enable 
 * DAC_INTENSET_OVERRUN(value)  Overrun x Interrupt Enable 
 */
static inline void dac_write_INTEN(uint8_t data)
{
	DAC->INTENSET.reg = data;
	DAC->INTENCLR.reg = ~data;
}

/**
 * @brief dac clear INTEN register
 *
 * @param[in] uint8_t mask
 * DAC_INTENSET_UNDERRUN0  Underrun 0 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN1  Underrun 1 Interrupt Enable 
 * DAC_INTENSET_UNDERRUN(value)  Underrun x Interrupt Enable 
 * DAC_INTENSET_EMPTY0  Data Buffer 0 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY1  Data Buffer 1 Empty Interrupt Enable 
 * DAC_INTENSET_EMPTY(value)  Data Buffer x Empty Interrupt Enable 
 * DAC_INTENSET_RESRDY0  Result 0 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY1  Result 1 Ready Interrupt Enable 
 * DAC_INTENSET_RESRDY(value)  Result x Ready Interrupt Enable 
 * DAC_INTENSET_OVERRUN0  Overrun 0 Interrupt Enable 
 * DAC_INTENSET_OVERRUN1  Overrun 1 Interrupt Enable 
 * DAC_INTENSET_OVERRUN(value)  Overrun x Interrupt Enable 
 */
static inline void dac_clear_INTEN(uint8_t mask)
{
	DAC->INTENCLR.reg = mask;
}

/**
 * @brief dac get INTFLAG register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * DAC_INTFLAG_UNDERRUN0  Result 0 Underrun 
 * DAC_INTFLAG_UNDERRUN1  Result 1 Underrun 
 * DAC_INTFLAG_UNDERRUN(value)  Result x Underrun 
 * DAC_INTFLAG_EMPTY0  Data Buffer 0 Empty 
 * DAC_INTFLAG_EMPTY1  Data Buffer 1 Empty 
 * DAC_INTFLAG_EMPTY(value)  Data Buffer x Empty 
 * DAC_INTFLAG_RESRDY0  Result 0 Ready 
 * DAC_INTFLAG_RESRDY1  Result 1 Ready 
 * DAC_INTFLAG_RESRDY(value)  Result x Ready 
 * DAC_INTFLAG_OVERRUN0  Result 0 Overrun 
 * DAC_INTFLAG_OVERRUN1  Result 1 Overrun 
 * DAC_INTFLAG_OVERRUN(value)  Result x Overrun 
 */
static inline uint8_t dac_get_INTFLAG(uint8_t mask)
{
    return DAC->INTFLAG.reg & mask;
}

/**
 * @brief dac read INTFLAG register
 *
 * @param[in] void
 * @return uint8_t
 * DAC_INTFLAG_UNDERRUN0  Result 0 Underrun 
 * DAC_INTFLAG_UNDERRUN1  Result 1 Underrun 
 * DAC_INTFLAG_UNDERRUN(value)  Result x Underrun 
 * DAC_INTFLAG_EMPTY0  Data Buffer 0 Empty 
 * DAC_INTFLAG_EMPTY1  Data Buffer 1 Empty 
 * DAC_INTFLAG_EMPTY(value)  Data Buffer x Empty 
 * DAC_INTFLAG_RESRDY0  Result 0 Ready 
 * DAC_INTFLAG_RESRDY1  Result 1 Ready 
 * DAC_INTFLAG_RESRDY(value)  Result x Ready 
 * DAC_INTFLAG_OVERRUN0  Result 0 Overrun 
 * DAC_INTFLAG_OVERRUN1  Result 1 Overrun 
 * DAC_INTFLAG_OVERRUN(value)  Result x Overrun 
 */
static inline uint8_t dac_read_INTFLAG(void)
{
	return DAC->INTFLAG.reg;
}

/**
 * @brief dac clear INTFLAG register
 *
 * @param[in] uint8_t mask
 * DAC_INTFLAG_UNDERRUN0  Result 0 Underrun 
 * DAC_INTFLAG_UNDERRUN1  Result 1 Underrun 
 * DAC_INTFLAG_UNDERRUN(value)  Result x Underrun 
 * DAC_INTFLAG_EMPTY0  Data Buffer 0 Empty 
 * DAC_INTFLAG_EMPTY1  Data Buffer 1 Empty 
 * DAC_INTFLAG_EMPTY(value)  Data Buffer x Empty 
 * DAC_INTFLAG_RESRDY0  Result 0 Ready 
 * DAC_INTFLAG_RESRDY1  Result 1 Ready 
 * DAC_INTFLAG_RESRDY(value)  Result x Ready 
 * DAC_INTFLAG_OVERRUN0  Result 0 Overrun 
 * DAC_INTFLAG_OVERRUN1  Result 1 Overrun 
 * DAC_INTFLAG_OVERRUN(value)  Result x Overrun 
 */
static inline void dac_clear_INTFLAG(uint8_t mask)
{
	DAC->INTFLAG.reg = mask;
}

/**
 * @brief dac write DATA register
 *
 * @param[in] uint8_t index
 * @param[in] uint16_t data
 * DAC_DATA_DATA(value)  DAC0 Data 
 */
static inline void dac_write_DATA(uint8_t index, uint16_t data)
{
	DAC->DATA[index].reg = data;
}

/**
 * @brief dac write DATABUF register
 *
 * @param[in] uint8_t index
 * @param[in] uint16_t data
 * DAC_DATABUF_DATABUF(value)  DAC0 Data Buffer 
 */
static inline void dac_write_DATABUF(uint8_t index, uint16_t data)
{
	DAC->DATABUF[index].reg = data;
}

/**
 * @brief dac set CTRLA register
 *
 * @param[in] uint8_t mask
 * DAC_CTRLA_SWRST  Software Reset 
 * DAC_CTRLA_ENABLE  Enable DAC Controller 
 */
static inline void dac_set_CTRLA(uint8_t mask)
{
	DAC->CTRLA.reg |= mask;
}

/**
 * @brief dac get CTRLA register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * DAC_CTRLA_SWRST  Software Reset 
 * DAC_CTRLA_ENABLE  Enable DAC Controller 
 */
static inline uint8_t dac_get_CTRLA(uint8_t mask)
{
    return DAC->CTRLA.reg & mask;
}

/**
 * @brief dac write CTRLA register
 *
 * @param[in] uint8_t data
 * DAC_CTRLA_SWRST  Software Reset 
 * DAC_CTRLA_ENABLE  Enable DAC Controller 
 */
static inline void dac_write_CTRLA(uint8_t data)
{
	DAC->CTRLA.reg = data;
}

/**
 * @brief dac clear CTRLA register
 *
 * @param[in] uint8_t mask
 * DAC_CTRLA_SWRST  Software Reset 
 * DAC_CTRLA_ENABLE  Enable DAC Controller 
 */
static inline void dac_clear_CTRLA(uint8_t mask)
{
	DAC->CTRLA.reg &= ~mask;
}

/**
 * @brief dac read CTRLA register
 *
 * @param[in] void
 * @return uint8_t
 * DAC_CTRLA_SWRST  Software Reset 
 * DAC_CTRLA_ENABLE  Enable DAC Controller 
 */
static inline uint8_t dac_read_CTRLA(void)
{
	return DAC->CTRLA.reg;
}

/**
 * @brief dac set CTRLB register
 *
 * @param[in] uint8_t mask
 * DAC_CTRLB_DIFF  Differential mode enable 
 * DAC_CTRLB_REFSEL(value)  Reference Selection for DAC0/1 
 *    DAC_CTRLB_REFSEL_VREFPU  External reference unbuffered 
 *    DAC_CTRLB_REFSEL_VDDANA  Analog supply 
 *    DAC_CTRLB_REFSEL_VREFPB  External reference buffered 
 *    DAC_CTRLB_REFSEL_INTREF  Internal bandgap reference 
 */
static inline void dac_set_CTRLB(uint8_t mask)
{
	DAC->CTRLB.reg |= mask;
}

/**
 * @brief dac get CTRLB register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * DAC_CTRLB_DIFF  Differential mode enable 
 * DAC_CTRLB_REFSEL(value)  Reference Selection for DAC0/1 
 *    DAC_CTRLB_REFSEL_VREFPU  External reference unbuffered 
 *    DAC_CTRLB_REFSEL_VDDANA  Analog supply 
 *    DAC_CTRLB_REFSEL_VREFPB  External reference buffered 
 *    DAC_CTRLB_REFSEL_INTREF  Internal bandgap reference 
 */
static inline uint8_t dac_get_CTRLB(uint8_t mask)
{
    return DAC->CTRLB.reg & mask;
}

/**
 * @brief dac write CTRLB register
 *
 * @param[in] uint8_t data
 * DAC_CTRLB_DIFF  Differential mode enable 
 * DAC_CTRLB_REFSEL(value)  Reference Selection for DAC0/1 
 *    DAC_CTRLB_REFSEL_VREFPU  External reference unbuffered 
 *    DAC_CTRLB_REFSEL_VDDANA  Analog supply 
 *    DAC_CTRLB_REFSEL_VREFPB  External reference buffered 
 *    DAC_CTRLB_REFSEL_INTREF  Internal bandgap reference 
 */
static inline void dac_write_CTRLB(uint8_t data)
{
	DAC->CTRLB.reg = data;
}

/**
 * @brief dac clear CTRLB register
 *
 * @param[in] uint8_t mask
 * DAC_CTRLB_DIFF  Differential mode enable 
 * DAC_CTRLB_REFSEL(value)  Reference Selection for DAC0/1 
 *    DAC_CTRLB_REFSEL_VREFPU  External reference unbuffered 
 *    DAC_CTRLB_REFSEL_VDDANA  Analog supply 
 *    DAC_CTRLB_REFSEL_VREFPB  External reference buffered 
 *    DAC_CTRLB_REFSEL_INTREF  Internal bandgap reference 
 */
static inline void dac_clear_CTRLB(uint8_t mask)
{
	DAC->CTRLB.reg &= ~mask;
}

/**
 * @brief dac read CTRLB register
 *
 * @param[in] void
 * @return uint8_t
 * DAC_CTRLB_DIFF  Differential mode enable 
 * DAC_CTRLB_REFSEL(value)  Reference Selection for DAC0/1 
 *    DAC_CTRLB_REFSEL_VREFPU  External reference unbuffered 
 *    DAC_CTRLB_REFSEL_VDDANA  Analog supply 
 *    DAC_CTRLB_REFSEL_VREFPB  External reference buffered 
 *    DAC_CTRLB_REFSEL_INTREF  Internal bandgap reference 
 */
static inline uint8_t dac_read_CTRLB(void)
{
	return DAC->CTRLB.reg;
}

/**
 * @brief dac set EVCTRL register
 *
 * @param[in] uint8_t mask
 * DAC_EVCTRL_STARTEI0  Start Conversion Event Input DAC 0 
 * DAC_EVCTRL_STARTEI1  Start Conversion Event Input DAC 1 
 * DAC_EVCTRL_STARTEI(value)  Start Conversion Event Input DAC x 
 * DAC_EVCTRL_EMPTYEO0  Data Buffer Empty Event Output DAC 0 
 * DAC_EVCTRL_EMPTYEO1  Data Buffer Empty Event Output DAC 1 
 * DAC_EVCTRL_EMPTYEO(value)  Data Buffer Empty Event Output DAC x 
 * DAC_EVCTRL_INVEI0  Enable Invertion of DAC 0 input event 
 * DAC_EVCTRL_INVEI1  Enable Invertion of DAC 1 input event 
 * DAC_EVCTRL_INVEI(value)  Enable Invertion of DAC x input event 
 * DAC_EVCTRL_RESRDYEO0  Result Ready Event Output 0 
 * DAC_EVCTRL_RESRDYEO1  Result Ready Event Output 1 
 * DAC_EVCTRL_RESRDYEO(value)  Result Ready Event Output x 
 */
static inline void dac_set_EVCTRL(uint8_t mask)
{
	DAC->EVCTRL.reg |= mask;
}

/**
 * @brief dac get EVCTRL register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * DAC_EVCTRL_STARTEI0  Start Conversion Event Input DAC 0 
 * DAC_EVCTRL_STARTEI1  Start Conversion Event Input DAC 1 
 * DAC_EVCTRL_STARTEI(value)  Start Conversion Event Input DAC x 
 * DAC_EVCTRL_EMPTYEO0  Data Buffer Empty Event Output DAC 0 
 * DAC_EVCTRL_EMPTYEO1  Data Buffer Empty Event Output DAC 1 
 * DAC_EVCTRL_EMPTYEO(value)  Data Buffer Empty Event Output DAC x 
 * DAC_EVCTRL_INVEI0  Enable Invertion of DAC 0 input event 
 * DAC_EVCTRL_INVEI1  Enable Invertion of DAC 1 input event 
 * DAC_EVCTRL_INVEI(value)  Enable Invertion of DAC x input event 
 * DAC_EVCTRL_RESRDYEO0  Result Ready Event Output 0 
 * DAC_EVCTRL_RESRDYEO1  Result Ready Event Output 1 
 * DAC_EVCTRL_RESRDYEO(value)  Result Ready Event Output x 
 */
static inline uint8_t dac_get_EVCTRL(uint8_t mask)
{
    return DAC->EVCTRL.reg & mask;
}

/**
 * @brief dac write EVCTRL register
 *
 * @param[in] uint8_t data
 * DAC_EVCTRL_STARTEI0  Start Conversion Event Input DAC 0 
 * DAC_EVCTRL_STARTEI1  Start Conversion Event Input DAC 1 
 * DAC_EVCTRL_STARTEI(value)  Start Conversion Event Input DAC x 
 * DAC_EVCTRL_EMPTYEO0  Data Buffer Empty Event Output DAC 0 
 * DAC_EVCTRL_EMPTYEO1  Data Buffer Empty Event Output DAC 1 
 * DAC_EVCTRL_EMPTYEO(value)  Data Buffer Empty Event Output DAC x 
 * DAC_EVCTRL_INVEI0  Enable Invertion of DAC 0 input event 
 * DAC_EVCTRL_INVEI1  Enable Invertion of DAC 1 input event 
 * DAC_EVCTRL_INVEI(value)  Enable Invertion of DAC x input event 
 * DAC_EVCTRL_RESRDYEO0  Result Ready Event Output 0 
 * DAC_EVCTRL_RESRDYEO1  Result Ready Event Output 1 
 * DAC_EVCTRL_RESRDYEO(value)  Result Ready Event Output x 
 */
static inline void dac_write_EVCTRL(uint8_t data)
{
	DAC->EVCTRL.reg = data;
}

/**
 * @brief dac clear EVCTRL register
 *
 * @param[in] uint8_t mask
 * DAC_EVCTRL_STARTEI0  Start Conversion Event Input DAC 0 
 * DAC_EVCTRL_STARTEI1  Start Conversion Event Input DAC 1 
 * DAC_EVCTRL_STARTEI(value)  Start Conversion Event Input DAC x 
 * DAC_EVCTRL_EMPTYEO0  Data Buffer Empty Event Output DAC 0 
 * DAC_EVCTRL_EMPTYEO1  Data Buffer Empty Event Output DAC 1 
 * DAC_EVCTRL_EMPTYEO(value)  Data Buffer Empty Event Output DAC x 
 * DAC_EVCTRL_INVEI0  Enable Invertion of DAC 0 input event 
 * DAC_EVCTRL_INVEI1  Enable Invertion of DAC 1 input event 
 * DAC_EVCTRL_INVEI(value)  Enable Invertion of DAC x input event 
 * DAC_EVCTRL_RESRDYEO0  Result Ready Event Output 0 
 * DAC_EVCTRL_RESRDYEO1  Result Ready Event Output 1 
 * DAC_EVCTRL_RESRDYEO(value)  Result Ready Event Output x 
 */
static inline void dac_clear_EVCTRL(uint8_t mask)
{
	DAC->EVCTRL.reg &= ~mask;
}

/**
 * @brief dac read EVCTRL register
 *
 * @param[in] void
 * @return uint8_t
 * DAC_EVCTRL_STARTEI0  Start Conversion Event Input DAC 0 
 * DAC_EVCTRL_STARTEI1  Start Conversion Event Input DAC 1 
 * DAC_EVCTRL_STARTEI(value)  Start Conversion Event Input DAC x 
 * DAC_EVCTRL_EMPTYEO0  Data Buffer Empty Event Output DAC 0 
 * DAC_EVCTRL_EMPTYEO1  Data Buffer Empty Event Output DAC 1 
 * DAC_EVCTRL_EMPTYEO(value)  Data Buffer Empty Event Output DAC x 
 * DAC_EVCTRL_INVEI0  Enable Invertion of DAC 0 input event 
 * DAC_EVCTRL_INVEI1  Enable Invertion of DAC 1 input event 
 * DAC_EVCTRL_INVEI(value)  Enable Invertion of DAC x input event 
 * DAC_EVCTRL_RESRDYEO0  Result Ready Event Output 0 
 * DAC_EVCTRL_RESRDYEO1  Result Ready Event Output 1 
 * DAC_EVCTRL_RESRDYEO(value)  Result Ready Event Output x 
 */
static inline uint8_t dac_read_EVCTRL(void)
{
	return DAC->EVCTRL.reg;
}

/**
 * @brief dac set DACCTRL register
 *
 * @param[in] uint8_t index
 * @param[in] uint16_t mask
 * DAC_DACCTRL_LEFTADJ  Left Adjusted Data 
 * DAC_DACCTRL_ENABLE  Enable DAC0 
 * DAC_DACCTRL_CCTRL(value)  Current Control 
 *    DAC_DACCTRL_CCTRL_CC100K  GCLK_DAC ≤ 1.2MHz (100kSPS) 
 *    DAC_DACCTRL_CCTRL_CC1M  1.2MHz < GCLK_DAC  ≤ 6MHz (500kSPS) 
 *    DAC_DACCTRL_CCTRL_CC12M  6MHz < GCLK_DAC ≤ 12MHz 
 * DAC_DACCTRL_FEXT  Standalone Filter 
 * DAC_DACCTRL_RUNSTDBY  Run in Standby 
 * DAC_DACCTRL_DITHER  Dithering Mode 
 * DAC_DACCTRL_REFRESH(value)  Refresh period 
 * DAC_DACCTRL_OSR(value)  Sampling Rate 
 */
static inline void dac_set_DACCTRL(uint8_t index, uint16_t mask)
{
	DAC->DACCTRL[index].reg |= mask;
}

/**
 * @brief dac get DACCTRL register
 *
 * @param[in] uint8_t index
 * @param[in] uint16_t mask
 * @return uint16_t
 * DAC_DACCTRL_LEFTADJ  Left Adjusted Data 
 * DAC_DACCTRL_ENABLE  Enable DAC0 
 * DAC_DACCTRL_CCTRL(value)  Current Control 
 *    DAC_DACCTRL_CCTRL_CC100K  GCLK_DAC ≤ 1.2MHz (100kSPS) 
 *    DAC_DACCTRL_CCTRL_CC1M  1.2MHz < GCLK_DAC  ≤ 6MHz (500kSPS) 
 *    DAC_DACCTRL_CCTRL_CC12M  6MHz < GCLK_DAC ≤ 12MHz 
 * DAC_DACCTRL_FEXT  Standalone Filter 
 * DAC_DACCTRL_RUNSTDBY  Run in Standby 
 * DAC_DACCTRL_DITHER  Dithering Mode 
 * DAC_DACCTRL_REFRESH(value)  Refresh period 
 * DAC_DACCTRL_OSR(value)  Sampling Rate 
 */
static inline uint16_t dac_get_DACCTRL(uint8_t index, uint16_t mask)
{
    return DAC->DACCTRL[index].reg & mask;
}

/**
 * @brief dac write DACCTRL register
 *
 * @param[in] uint8_t index
 * @param[in] uint16_t data
 * DAC_DACCTRL_LEFTADJ  Left Adjusted Data 
 * DAC_DACCTRL_ENABLE  Enable DAC0 
 * DAC_DACCTRL_CCTRL(value)  Current Control 
 *    DAC_DACCTRL_CCTRL_CC100K  GCLK_DAC ≤ 1.2MHz (100kSPS) 
 *    DAC_DACCTRL_CCTRL_CC1M  1.2MHz < GCLK_DAC  ≤ 6MHz (500kSPS) 
 *    DAC_DACCTRL_CCTRL_CC12M  6MHz < GCLK_DAC ≤ 12MHz 
 * DAC_DACCTRL_FEXT  Standalone Filter 
 * DAC_DACCTRL_RUNSTDBY  Run in Standby 
 * DAC_DACCTRL_DITHER  Dithering Mode 
 * DAC_DACCTRL_REFRESH(value)  Refresh period 
 * DAC_DACCTRL_OSR(value)  Sampling Rate 
 */
static inline void dac_write_DACCTRL(uint8_t index, uint16_t data)
{
	DAC->DACCTRL[index].reg = data;
}

/**
 * @brief dac clear DACCTRL register
 *
 * @param[in] uint8_t index
 * @param[in] uint16_t mask
 * DAC_DACCTRL_LEFTADJ  Left Adjusted Data 
 * DAC_DACCTRL_ENABLE  Enable DAC0 
 * DAC_DACCTRL_CCTRL(value)  Current Control 
 *    DAC_DACCTRL_CCTRL_CC100K  GCLK_DAC ≤ 1.2MHz (100kSPS) 
 *    DAC_DACCTRL_CCTRL_CC1M  1.2MHz < GCLK_DAC  ≤ 6MHz (500kSPS) 
 *    DAC_DACCTRL_CCTRL_CC12M  6MHz < GCLK_DAC ≤ 12MHz 
 * DAC_DACCTRL_FEXT  Standalone Filter 
 * DAC_DACCTRL_RUNSTDBY  Run in Standby 
 * DAC_DACCTRL_DITHER  Dithering Mode 
 * DAC_DACCTRL_REFRESH(value)  Refresh period 
 * DAC_DACCTRL_OSR(value)  Sampling Rate 
 */
static inline void dac_clear_DACCTRL(uint8_t index, uint16_t mask)
{
	DAC->DACCTRL[index].reg &= ~mask;
}

/**
 * @brief dac read DACCTRL register
 *
 * @param[in] uint8_t index
 * @return uint16_t
 * DAC_DACCTRL_LEFTADJ  Left Adjusted Data 
 * DAC_DACCTRL_ENABLE  Enable DAC0 
 * DAC_DACCTRL_CCTRL(value)  Current Control 
 *    DAC_DACCTRL_CCTRL_CC100K  GCLK_DAC ≤ 1.2MHz (100kSPS) 
 *    DAC_DACCTRL_CCTRL_CC1M  1.2MHz < GCLK_DAC  ≤ 6MHz (500kSPS) 
 *    DAC_DACCTRL_CCTRL_CC12M  6MHz < GCLK_DAC ≤ 12MHz 
 * DAC_DACCTRL_FEXT  Standalone Filter 
 * DAC_DACCTRL_RUNSTDBY  Run in Standby 
 * DAC_DACCTRL_DITHER  Dithering Mode 
 * DAC_DACCTRL_REFRESH(value)  Refresh period 
 * DAC_DACCTRL_OSR(value)  Sampling Rate 
 */
static inline uint16_t dac_read_DACCTRL(uint8_t index)
{
	return DAC->DACCTRL[index].reg;
}

/**
 * @brief dac set DBGCTRL register
 *
 * @param[in] uint8_t mask
 * DAC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline void dac_set_DBGCTRL(uint8_t mask)
{
	DAC->DBGCTRL.reg |= mask;
}

/**
 * @brief dac get DBGCTRL register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * DAC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline uint8_t dac_get_DBGCTRL(uint8_t mask)
{
    return DAC->DBGCTRL.reg & mask;
}

/**
 * @brief dac write DBGCTRL register
 *
 * @param[in] uint8_t data
 * DAC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline void dac_write_DBGCTRL(uint8_t data)
{
	DAC->DBGCTRL.reg = data;
}

/**
 * @brief dac clear DBGCTRL register
 *
 * @param[in] uint8_t mask
 * DAC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline void dac_clear_DBGCTRL(uint8_t mask)
{
	DAC->DBGCTRL.reg &= ~mask;
}

/**
 * @brief dac read DBGCTRL register
 *
 * @param[in] void
 * @return uint8_t
 * DAC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline uint8_t dac_read_DBGCTRL(void)
{
	return DAC->DBGCTRL.reg;
}

/**
 * @brief dac get STATUS register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * DAC_STATUS_READY0  DAC 0 Startup Ready 
 * DAC_STATUS_READY1  DAC 1 Startup Ready 
 * DAC_STATUS_READY(value)  DAC x Startup Ready 
 * DAC_STATUS_EOC0  DAC 0 End of Conversion 
 * DAC_STATUS_EOC1  DAC 1 End of Conversion 
 * DAC_STATUS_EOC(value)  DAC x End of Conversion 
 */
static inline uint8_t dac_get_STATUS(uint8_t mask)
{
    return DAC->STATUS.reg & mask;
}

/**
 * @brief dac read STATUS register
 *
 * @param[in] void
 * @return uint8_t
 * DAC_STATUS_READY0  DAC 0 Startup Ready 
 * DAC_STATUS_READY1  DAC 1 Startup Ready 
 * DAC_STATUS_READY(value)  DAC x Startup Ready 
 * DAC_STATUS_EOC0  DAC 0 End of Conversion 
 * DAC_STATUS_EOC1  DAC 1 End of Conversion 
 * DAC_STATUS_EOC(value)  DAC x End of Conversion 
 */
static inline uint8_t dac_read_STATUS(void)
{
	return DAC->STATUS.reg;
}

/**
 * @brief dac get SYNCBUSY register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * DAC_SYNCBUSY_SWRST  Software Reset 
 * DAC_SYNCBUSY_ENABLE  DAC Enable Status 
 * DAC_SYNCBUSY_DATA0  Data DAC 0 
 * DAC_SYNCBUSY_DATA1  Data DAC 1 
 * DAC_SYNCBUSY_DATA(value)  Data DAC x 
 * DAC_SYNCBUSY_DATABUF0  Data Buffer DAC 0 
 * DAC_SYNCBUSY_DATABUF1  Data Buffer DAC 1 
 * DAC_SYNCBUSY_DATABUF(value)  Data Buffer DAC x 
 */
static inline uint32_t dac_get_SYNCBUSY(uint32_t mask)
{
    return DAC->SYNCBUSY.reg & mask;
}

/**
 * @brief dac read SYNCBUSY register
 *
 * @param[in] void
 * @return uint32_t
 * DAC_SYNCBUSY_SWRST  Software Reset 
 * DAC_SYNCBUSY_ENABLE  DAC Enable Status 
 * DAC_SYNCBUSY_DATA0  Data DAC 0 
 * DAC_SYNCBUSY_DATA1  Data DAC 1 
 * DAC_SYNCBUSY_DATA(value)  Data DAC x 
 * DAC_SYNCBUSY_DATABUF0  Data Buffer DAC 0 
 * DAC_SYNCBUSY_DATABUF1  Data Buffer DAC 1 
 * DAC_SYNCBUSY_DATABUF(value)  Data Buffer DAC x 
 */
static inline uint32_t dac_read_SYNCBUSY(void)
{
	return DAC->SYNCBUSY.reg;
}

/**
 * @brief dac get RESULT register
 *
 * @param[in] uint8_t index
 * @param[in] uint16_t mask
 * @return uint16_t
 * DAC_RESULT_RESULT(value)  Filter Result 
 */
static inline uint16_t dac_get_RESULT(uint8_t index, uint16_t mask)
{
    return DAC->RESULT[index].reg & mask;
}

/**
 * @brief dac read RESULT register
 *
 * @param[in] uint8_t index
 * @return uint16_t
 * DAC_RESULT_RESULT(value)  Filter Result 
 */
static inline uint16_t dac_read_RESULT(uint8_t index)
{
	return DAC->RESULT[index].reg;
}

#endif /* _DAC_H */
