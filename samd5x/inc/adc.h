/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM ADC
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

#ifndef _ADC_H_
#define _ADC_H_

#include <stdbool.h>

/**
 * @brief adc wait for sync
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t reg
 */
static inline void adc_wait_for_sync(ADC_t *pADC, uint32_t reg)
{
	while (pADC->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief adc is syncing
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t reg
 * @return bool
 */
static inline bool adc_is_syncing(ADC_t *pADC, uint32_t reg)
{
	return pADC->SYNCBUSY.reg & reg;
}

/**
 * @brief adc set INTEN register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_INTENSET_RESRDY  Result Ready Interrupt Enable 
 * ADC_INTENSET_OVERRUN  Overrun Interrupt Enable 
 * ADC_INTENSET_WINMON  Window Monitor Interrupt Enable 
 */
static inline void adc_set_INTEN(ADC_t *pADC, uint8_t mask)
{
	pADC->INTENSET.reg = mask;
}

/**
 * @brief adc get INTEN register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_INTENSET_RESRDY  Result Ready Interrupt Enable 
 * ADC_INTENSET_OVERRUN  Overrun Interrupt Enable 
 * ADC_INTENSET_WINMON  Window Monitor Interrupt Enable 
 */
static inline uint8_t adc_get_INTEN(ADC_t *pADC, uint8_t mask)
{
    return pADC->INTENSET.reg & mask;
}

/**
 * @brief adc read INTEN register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_INTENSET_RESRDY  Result Ready Interrupt Enable 
 * ADC_INTENSET_OVERRUN  Overrun Interrupt Enable 
 * ADC_INTENSET_WINMON  Window Monitor Interrupt Enable 
 */
static inline uint8_t adc_read_INTEN(ADC_t *pADC)
{
	return pADC->INTENSET.reg;
}

/**
 * @brief adc write INTEN register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t data
 * ADC_INTENSET_RESRDY  Result Ready Interrupt Enable 
 * ADC_INTENSET_OVERRUN  Overrun Interrupt Enable 
 * ADC_INTENSET_WINMON  Window Monitor Interrupt Enable 
 */
static inline void adc_write_INTEN(ADC_t *pADC, uint8_t data)
{
	pADC->INTENSET.reg = data;
	pADC->INTENCLR.reg = ~data;
}

/**
 * @brief adc clear INTEN register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_INTENSET_RESRDY  Result Ready Interrupt Enable 
 * ADC_INTENSET_OVERRUN  Overrun Interrupt Enable 
 * ADC_INTENSET_WINMON  Window Monitor Interrupt Enable 
 */
static inline void adc_clear_INTEN(ADC_t *pADC, uint8_t mask)
{
	pADC->INTENCLR.reg = mask;
}

/**
 * @brief adc get INTFLAG register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_INTFLAG_RESRDY  Result Ready Interrupt Flag 
 * ADC_INTFLAG_OVERRUN  Overrun Interrupt Flag 
 * ADC_INTFLAG_WINMON  Window Monitor Interrupt Flag 
 */
static inline uint8_t adc_get_INTFLAG(ADC_t *pADC, uint8_t mask)
{
    return pADC->INTFLAG.reg & mask;
}

/**
 * @brief adc read INTFLAG register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_INTFLAG_RESRDY  Result Ready Interrupt Flag 
 * ADC_INTFLAG_OVERRUN  Overrun Interrupt Flag 
 * ADC_INTFLAG_WINMON  Window Monitor Interrupt Flag 
 */
static inline uint8_t adc_read_INTFLAG(ADC_t *pADC)
{
	return pADC->INTFLAG.reg;
}

/**
 * @brief adc clear INTFLAG register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_INTFLAG_RESRDY  Result Ready Interrupt Flag 
 * ADC_INTFLAG_OVERRUN  Overrun Interrupt Flag 
 * ADC_INTFLAG_WINMON  Window Monitor Interrupt Flag 
 */
static inline void adc_clear_INTFLAG(ADC_t *pADC, uint8_t mask)
{
	pADC->INTFLAG.reg = mask;
}

/**
 * @brief adc write DSEQDATA register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t data
 * ADC_DSEQDATA_DATA(value)  DMA Sequential Data 
 */
static inline void adc_write_DSEQDATA(ADC_t *pADC, uint32_t data)
{
	pADC->DSEQDATA.reg = data;
}

/**
 * @brief adc set CTRLA register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_CTRLA_SWRST  Software Reset 
 * ADC_CTRLA_ENABLE  Enable 
 * ADC_CTRLA_DUALSEL(value)  Dual Mode Trigger Selection 
 *    ADC_CTRLA_DUALSEL_BOTH  Start event or software trigger will start a conversion on both ADCs 
 *    ADC_CTRLA_DUALSEL_INTERLEAVE  START event or software trigger will alternatingly start a conversion on ADC0 and ADC1 
 * ADC_CTRLA_SLAVEEN  Slave Enable 
 * ADC_CTRLA_RUNSTDBY  Run in Standby 
 * ADC_CTRLA_ONDEMAND  On Demand Control 
 * ADC_CTRLA_PRESCALER(value)  Prescaler Configuration 
 *    ADC_CTRLA_PRESCALER_DIV2  Peripheral clock divided by 2 
 *    ADC_CTRLA_PRESCALER_DIV4  Peripheral clock divided by 4 
 *    ADC_CTRLA_PRESCALER_DIV8  Peripheral clock divided by 8 
 *    ADC_CTRLA_PRESCALER_DIV16  Peripheral clock divided by 16 
 *    ADC_CTRLA_PRESCALER_DIV32  Peripheral clock divided by 32 
 *    ADC_CTRLA_PRESCALER_DIV64  Peripheral clock divided by 64 
 *    ADC_CTRLA_PRESCALER_DIV128  Peripheral clock divided by 128 
 *    ADC_CTRLA_PRESCALER_DIV256  Peripheral clock divided by 256 
 * ADC_CTRLA_R2R  Rail to Rail Operation Enable 
 */
static inline void adc_set_CTRLA(ADC_t *pADC, uint16_t mask)
{
	pADC->CTRLA.reg |= mask;
}

/**
 * @brief adc get CTRLA register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_CTRLA_SWRST  Software Reset 
 * ADC_CTRLA_ENABLE  Enable 
 * ADC_CTRLA_DUALSEL(value)  Dual Mode Trigger Selection 
 *    ADC_CTRLA_DUALSEL_BOTH  Start event or software trigger will start a conversion on both ADCs 
 *    ADC_CTRLA_DUALSEL_INTERLEAVE  START event or software trigger will alternatingly start a conversion on ADC0 and ADC1 
 * ADC_CTRLA_SLAVEEN  Slave Enable 
 * ADC_CTRLA_RUNSTDBY  Run in Standby 
 * ADC_CTRLA_ONDEMAND  On Demand Control 
 * ADC_CTRLA_PRESCALER(value)  Prescaler Configuration 
 *    ADC_CTRLA_PRESCALER_DIV2  Peripheral clock divided by 2 
 *    ADC_CTRLA_PRESCALER_DIV4  Peripheral clock divided by 4 
 *    ADC_CTRLA_PRESCALER_DIV8  Peripheral clock divided by 8 
 *    ADC_CTRLA_PRESCALER_DIV16  Peripheral clock divided by 16 
 *    ADC_CTRLA_PRESCALER_DIV32  Peripheral clock divided by 32 
 *    ADC_CTRLA_PRESCALER_DIV64  Peripheral clock divided by 64 
 *    ADC_CTRLA_PRESCALER_DIV128  Peripheral clock divided by 128 
 *    ADC_CTRLA_PRESCALER_DIV256  Peripheral clock divided by 256 
 * ADC_CTRLA_R2R  Rail to Rail Operation Enable 
 */
static inline uint16_t adc_get_CTRLA(ADC_t *pADC, uint16_t mask)
{
    return pADC->CTRLA.reg & mask;
}

/**
 * @brief adc write CTRLA register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t data
 * ADC_CTRLA_SWRST  Software Reset 
 * ADC_CTRLA_ENABLE  Enable 
 * ADC_CTRLA_DUALSEL(value)  Dual Mode Trigger Selection 
 *    ADC_CTRLA_DUALSEL_BOTH  Start event or software trigger will start a conversion on both ADCs 
 *    ADC_CTRLA_DUALSEL_INTERLEAVE  START event or software trigger will alternatingly start a conversion on ADC0 and ADC1 
 * ADC_CTRLA_SLAVEEN  Slave Enable 
 * ADC_CTRLA_RUNSTDBY  Run in Standby 
 * ADC_CTRLA_ONDEMAND  On Demand Control 
 * ADC_CTRLA_PRESCALER(value)  Prescaler Configuration 
 *    ADC_CTRLA_PRESCALER_DIV2  Peripheral clock divided by 2 
 *    ADC_CTRLA_PRESCALER_DIV4  Peripheral clock divided by 4 
 *    ADC_CTRLA_PRESCALER_DIV8  Peripheral clock divided by 8 
 *    ADC_CTRLA_PRESCALER_DIV16  Peripheral clock divided by 16 
 *    ADC_CTRLA_PRESCALER_DIV32  Peripheral clock divided by 32 
 *    ADC_CTRLA_PRESCALER_DIV64  Peripheral clock divided by 64 
 *    ADC_CTRLA_PRESCALER_DIV128  Peripheral clock divided by 128 
 *    ADC_CTRLA_PRESCALER_DIV256  Peripheral clock divided by 256 
 * ADC_CTRLA_R2R  Rail to Rail Operation Enable 
 */
static inline void adc_write_CTRLA(ADC_t *pADC, uint16_t data)
{
	pADC->CTRLA.reg = data;
}

/**
 * @brief adc clear CTRLA register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_CTRLA_SWRST  Software Reset 
 * ADC_CTRLA_ENABLE  Enable 
 * ADC_CTRLA_DUALSEL(value)  Dual Mode Trigger Selection 
 *    ADC_CTRLA_DUALSEL_BOTH  Start event or software trigger will start a conversion on both ADCs 
 *    ADC_CTRLA_DUALSEL_INTERLEAVE  START event or software trigger will alternatingly start a conversion on ADC0 and ADC1 
 * ADC_CTRLA_SLAVEEN  Slave Enable 
 * ADC_CTRLA_RUNSTDBY  Run in Standby 
 * ADC_CTRLA_ONDEMAND  On Demand Control 
 * ADC_CTRLA_PRESCALER(value)  Prescaler Configuration 
 *    ADC_CTRLA_PRESCALER_DIV2  Peripheral clock divided by 2 
 *    ADC_CTRLA_PRESCALER_DIV4  Peripheral clock divided by 4 
 *    ADC_CTRLA_PRESCALER_DIV8  Peripheral clock divided by 8 
 *    ADC_CTRLA_PRESCALER_DIV16  Peripheral clock divided by 16 
 *    ADC_CTRLA_PRESCALER_DIV32  Peripheral clock divided by 32 
 *    ADC_CTRLA_PRESCALER_DIV64  Peripheral clock divided by 64 
 *    ADC_CTRLA_PRESCALER_DIV128  Peripheral clock divided by 128 
 *    ADC_CTRLA_PRESCALER_DIV256  Peripheral clock divided by 256 
 * ADC_CTRLA_R2R  Rail to Rail Operation Enable 
 */
static inline void adc_clear_CTRLA(ADC_t *pADC, uint16_t mask)
{
	pADC->CTRLA.reg &= ~mask;
}

/**
 * @brief adc read CTRLA register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_CTRLA_SWRST  Software Reset 
 * ADC_CTRLA_ENABLE  Enable 
 * ADC_CTRLA_DUALSEL(value)  Dual Mode Trigger Selection 
 *    ADC_CTRLA_DUALSEL_BOTH  Start event or software trigger will start a conversion on both ADCs 
 *    ADC_CTRLA_DUALSEL_INTERLEAVE  START event or software trigger will alternatingly start a conversion on ADC0 and ADC1 
 * ADC_CTRLA_SLAVEEN  Slave Enable 
 * ADC_CTRLA_RUNSTDBY  Run in Standby 
 * ADC_CTRLA_ONDEMAND  On Demand Control 
 * ADC_CTRLA_PRESCALER(value)  Prescaler Configuration 
 *    ADC_CTRLA_PRESCALER_DIV2  Peripheral clock divided by 2 
 *    ADC_CTRLA_PRESCALER_DIV4  Peripheral clock divided by 4 
 *    ADC_CTRLA_PRESCALER_DIV8  Peripheral clock divided by 8 
 *    ADC_CTRLA_PRESCALER_DIV16  Peripheral clock divided by 16 
 *    ADC_CTRLA_PRESCALER_DIV32  Peripheral clock divided by 32 
 *    ADC_CTRLA_PRESCALER_DIV64  Peripheral clock divided by 64 
 *    ADC_CTRLA_PRESCALER_DIV128  Peripheral clock divided by 128 
 *    ADC_CTRLA_PRESCALER_DIV256  Peripheral clock divided by 256 
 * ADC_CTRLA_R2R  Rail to Rail Operation Enable 
 */
static inline uint16_t adc_read_CTRLA(ADC_t *pADC)
{
	return pADC->CTRLA.reg;
}

/**
 * @brief adc set EVCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_EVCTRL_FLUSHEI  Flush Event Input Enable 
 * ADC_EVCTRL_STARTEI  Start Conversion Event Input Enable 
 * ADC_EVCTRL_FLUSHINV  Flush Event Invert Enable 
 * ADC_EVCTRL_STARTINV  Start Conversion Event Invert Enable 
 * ADC_EVCTRL_RESRDYEO  Result Ready Event Out 
 * ADC_EVCTRL_WINMONEO  Window Monitor Event Out 
 */
static inline void adc_set_EVCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->EVCTRL.reg |= mask;
}

/**
 * @brief adc get EVCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_EVCTRL_FLUSHEI  Flush Event Input Enable 
 * ADC_EVCTRL_STARTEI  Start Conversion Event Input Enable 
 * ADC_EVCTRL_FLUSHINV  Flush Event Invert Enable 
 * ADC_EVCTRL_STARTINV  Start Conversion Event Invert Enable 
 * ADC_EVCTRL_RESRDYEO  Result Ready Event Out 
 * ADC_EVCTRL_WINMONEO  Window Monitor Event Out 
 */
static inline uint8_t adc_get_EVCTRL(ADC_t *pADC, uint8_t mask)
{
    return pADC->EVCTRL.reg & mask;
}

/**
 * @brief adc write EVCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t data
 * ADC_EVCTRL_FLUSHEI  Flush Event Input Enable 
 * ADC_EVCTRL_STARTEI  Start Conversion Event Input Enable 
 * ADC_EVCTRL_FLUSHINV  Flush Event Invert Enable 
 * ADC_EVCTRL_STARTINV  Start Conversion Event Invert Enable 
 * ADC_EVCTRL_RESRDYEO  Result Ready Event Out 
 * ADC_EVCTRL_WINMONEO  Window Monitor Event Out 
 */
static inline void adc_write_EVCTRL(ADC_t *pADC, uint8_t data)
{
	pADC->EVCTRL.reg = data;
}

/**
 * @brief adc clear EVCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_EVCTRL_FLUSHEI  Flush Event Input Enable 
 * ADC_EVCTRL_STARTEI  Start Conversion Event Input Enable 
 * ADC_EVCTRL_FLUSHINV  Flush Event Invert Enable 
 * ADC_EVCTRL_STARTINV  Start Conversion Event Invert Enable 
 * ADC_EVCTRL_RESRDYEO  Result Ready Event Out 
 * ADC_EVCTRL_WINMONEO  Window Monitor Event Out 
 */
static inline void adc_clear_EVCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->EVCTRL.reg &= ~mask;
}

/**
 * @brief adc read EVCTRL register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_EVCTRL_FLUSHEI  Flush Event Input Enable 
 * ADC_EVCTRL_STARTEI  Start Conversion Event Input Enable 
 * ADC_EVCTRL_FLUSHINV  Flush Event Invert Enable 
 * ADC_EVCTRL_STARTINV  Start Conversion Event Invert Enable 
 * ADC_EVCTRL_RESRDYEO  Result Ready Event Out 
 * ADC_EVCTRL_WINMONEO  Window Monitor Event Out 
 */
static inline uint8_t adc_read_EVCTRL(ADC_t *pADC)
{
	return pADC->EVCTRL.reg;
}

/**
 * @brief adc set DBGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline void adc_set_DBGCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->DBGCTRL.reg |= mask;
}

/**
 * @brief adc get DBGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline uint8_t adc_get_DBGCTRL(ADC_t *pADC, uint8_t mask)
{
    return pADC->DBGCTRL.reg & mask;
}

/**
 * @brief adc write DBGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t data
 * ADC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline void adc_write_DBGCTRL(ADC_t *pADC, uint8_t data)
{
	pADC->DBGCTRL.reg = data;
}

/**
 * @brief adc clear DBGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline void adc_clear_DBGCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->DBGCTRL.reg &= ~mask;
}

/**
 * @brief adc read DBGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_DBGCTRL_DBGRUN  Debug Run 
 */
static inline uint8_t adc_read_DBGCTRL(ADC_t *pADC)
{
	return pADC->DBGCTRL.reg;
}

/**
 * @brief adc set INPUTCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_INPUTCTRL_MUXPOS(value)  Positive Mux Input Selection 
 *    ADC_INPUTCTRL_MUXPOS_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN8  ADC AIN8 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN9  ADC AIN9 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN10  ADC AIN10 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN11  ADC AIN11 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN12  ADC AIN12 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN13  ADC AIN13 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN14  ADC AIN14 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN15  ADC AIN15 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN16  ADC AIN16 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN17  ADC AIN17 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN18  ADC AIN18 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN19  ADC AIN19 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN20  ADC AIN20 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN21  ADC AIN21 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN22  ADC AIN22 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN23  ADC AIN23 Pin 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC  1/4 Scaled Core Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDVBAT  1/4 Scaled VBAT Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDIOVCC  1/4 Scaled I/O Supply 
 *    ADC_INPUTCTRL_MUXPOS_BANDGAP  Bandgap Voltage 
 *    ADC_INPUTCTRL_MUXPOS_PTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_CTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_DAC  DAC Output 
 *    ADC_INPUTCTRL_MUXPOS_PTC  PTC output (only on ADC0) 
 * ADC_INPUTCTRL_DIFFMODE  Differential Mode 
 * ADC_INPUTCTRL_MUXNEG(value)  Negative Mux Input Selection 
 *    ADC_INPUTCTRL_MUXNEG_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXNEG_GND  Internal Ground 
 * ADC_INPUTCTRL_DSEQSTOP  Stop DMA Sequencing 
 */
static inline void adc_set_INPUTCTRL(ADC_t *pADC, uint16_t mask)
{
	pADC->INPUTCTRL.reg |= mask;
}

/**
 * @brief adc get INPUTCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_INPUTCTRL_MUXPOS(value)  Positive Mux Input Selection 
 *    ADC_INPUTCTRL_MUXPOS_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN8  ADC AIN8 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN9  ADC AIN9 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN10  ADC AIN10 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN11  ADC AIN11 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN12  ADC AIN12 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN13  ADC AIN13 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN14  ADC AIN14 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN15  ADC AIN15 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN16  ADC AIN16 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN17  ADC AIN17 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN18  ADC AIN18 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN19  ADC AIN19 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN20  ADC AIN20 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN21  ADC AIN21 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN22  ADC AIN22 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN23  ADC AIN23 Pin 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC  1/4 Scaled Core Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDVBAT  1/4 Scaled VBAT Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDIOVCC  1/4 Scaled I/O Supply 
 *    ADC_INPUTCTRL_MUXPOS_BANDGAP  Bandgap Voltage 
 *    ADC_INPUTCTRL_MUXPOS_PTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_CTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_DAC  DAC Output 
 *    ADC_INPUTCTRL_MUXPOS_PTC  PTC output (only on ADC0) 
 * ADC_INPUTCTRL_DIFFMODE  Differential Mode 
 * ADC_INPUTCTRL_MUXNEG(value)  Negative Mux Input Selection 
 *    ADC_INPUTCTRL_MUXNEG_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXNEG_GND  Internal Ground 
 * ADC_INPUTCTRL_DSEQSTOP  Stop DMA Sequencing 
 */
static inline uint16_t adc_get_INPUTCTRL(ADC_t *pADC, uint16_t mask)
{
    return pADC->INPUTCTRL.reg & mask;
}

/**
 * @brief adc write INPUTCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t data
 * ADC_INPUTCTRL_MUXPOS(value)  Positive Mux Input Selection 
 *    ADC_INPUTCTRL_MUXPOS_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN8  ADC AIN8 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN9  ADC AIN9 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN10  ADC AIN10 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN11  ADC AIN11 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN12  ADC AIN12 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN13  ADC AIN13 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN14  ADC AIN14 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN15  ADC AIN15 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN16  ADC AIN16 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN17  ADC AIN17 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN18  ADC AIN18 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN19  ADC AIN19 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN20  ADC AIN20 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN21  ADC AIN21 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN22  ADC AIN22 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN23  ADC AIN23 Pin 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC  1/4 Scaled Core Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDVBAT  1/4 Scaled VBAT Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDIOVCC  1/4 Scaled I/O Supply 
 *    ADC_INPUTCTRL_MUXPOS_BANDGAP  Bandgap Voltage 
 *    ADC_INPUTCTRL_MUXPOS_PTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_CTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_DAC  DAC Output 
 *    ADC_INPUTCTRL_MUXPOS_PTC  PTC output (only on ADC0) 
 * ADC_INPUTCTRL_DIFFMODE  Differential Mode 
 * ADC_INPUTCTRL_MUXNEG(value)  Negative Mux Input Selection 
 *    ADC_INPUTCTRL_MUXNEG_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXNEG_GND  Internal Ground 
 * ADC_INPUTCTRL_DSEQSTOP  Stop DMA Sequencing 
 */
static inline void adc_write_INPUTCTRL(ADC_t *pADC, uint16_t data)
{
	pADC->INPUTCTRL.reg = data;
}

/**
 * @brief adc clear INPUTCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_INPUTCTRL_MUXPOS(value)  Positive Mux Input Selection 
 *    ADC_INPUTCTRL_MUXPOS_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN8  ADC AIN8 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN9  ADC AIN9 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN10  ADC AIN10 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN11  ADC AIN11 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN12  ADC AIN12 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN13  ADC AIN13 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN14  ADC AIN14 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN15  ADC AIN15 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN16  ADC AIN16 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN17  ADC AIN17 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN18  ADC AIN18 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN19  ADC AIN19 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN20  ADC AIN20 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN21  ADC AIN21 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN22  ADC AIN22 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN23  ADC AIN23 Pin 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC  1/4 Scaled Core Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDVBAT  1/4 Scaled VBAT Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDIOVCC  1/4 Scaled I/O Supply 
 *    ADC_INPUTCTRL_MUXPOS_BANDGAP  Bandgap Voltage 
 *    ADC_INPUTCTRL_MUXPOS_PTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_CTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_DAC  DAC Output 
 *    ADC_INPUTCTRL_MUXPOS_PTC  PTC output (only on ADC0) 
 * ADC_INPUTCTRL_DIFFMODE  Differential Mode 
 * ADC_INPUTCTRL_MUXNEG(value)  Negative Mux Input Selection 
 *    ADC_INPUTCTRL_MUXNEG_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXNEG_GND  Internal Ground 
 * ADC_INPUTCTRL_DSEQSTOP  Stop DMA Sequencing 
 */
static inline void adc_clear_INPUTCTRL(ADC_t *pADC, uint16_t mask)
{
	pADC->INPUTCTRL.reg &= ~mask;
}

/**
 * @brief adc read INPUTCTRL register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_INPUTCTRL_MUXPOS(value)  Positive Mux Input Selection 
 *    ADC_INPUTCTRL_MUXPOS_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN8  ADC AIN8 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN9  ADC AIN9 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN10  ADC AIN10 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN11  ADC AIN11 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN12  ADC AIN12 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN13  ADC AIN13 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN14  ADC AIN14 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN15  ADC AIN15 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN16  ADC AIN16 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN17  ADC AIN17 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN18  ADC AIN18 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN19  ADC AIN19 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN20  ADC AIN20 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN21  ADC AIN21 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN22  ADC AIN22 Pin 
 *    ADC_INPUTCTRL_MUXPOS_AIN23  ADC AIN23 Pin 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC  1/4 Scaled Core Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDVBAT  1/4 Scaled VBAT Supply 
 *    ADC_INPUTCTRL_MUXPOS_SCALEDIOVCC  1/4 Scaled I/O Supply 
 *    ADC_INPUTCTRL_MUXPOS_BANDGAP  Bandgap Voltage 
 *    ADC_INPUTCTRL_MUXPOS_PTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_CTAT  Temperature Sensor 
 *    ADC_INPUTCTRL_MUXPOS_DAC  DAC Output 
 *    ADC_INPUTCTRL_MUXPOS_PTC  PTC output (only on ADC0) 
 * ADC_INPUTCTRL_DIFFMODE  Differential Mode 
 * ADC_INPUTCTRL_MUXNEG(value)  Negative Mux Input Selection 
 *    ADC_INPUTCTRL_MUXNEG_AIN0  ADC AIN0 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN1  ADC AIN1 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN2  ADC AIN2 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN3  ADC AIN3 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN4  ADC AIN4 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN5  ADC AIN5 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN6  ADC AIN6 Pin 
 *    ADC_INPUTCTRL_MUXNEG_AIN7  ADC AIN7 Pin 
 *    ADC_INPUTCTRL_MUXNEG_GND  Internal Ground 
 * ADC_INPUTCTRL_DSEQSTOP  Stop DMA Sequencing 
 */
static inline uint16_t adc_read_INPUTCTRL(ADC_t *pADC)
{
	return pADC->INPUTCTRL.reg;
}

/**
 * @brief adc set CTRLB register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_CTRLB_LEFTADJ  Left-Adjusted Result 
 * ADC_CTRLB_FREERUN  Free Running Mode 
 * ADC_CTRLB_CORREN  Digital Correction Logic Enable 
 * ADC_CTRLB_RESSEL(value)  Conversion Result Resolution 
 *    ADC_CTRLB_RESSEL_12BIT  12-bit result 
 *    ADC_CTRLB_RESSEL_16BIT  For averaging mode output 
 *    ADC_CTRLB_RESSEL_10BIT  10-bit result 
 *    ADC_CTRLB_RESSEL_8BIT  8-bit result 
 * ADC_CTRLB_WINMODE(value)  Window Monitor Mode 
 *    ADC_CTRLB_WINMODE_DISABLE  No window mode (default) 
 *    ADC_CTRLB_WINMODE_MODE1  RESULT > WINLT 
 *    ADC_CTRLB_WINMODE_MODE2  RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE3  WINLT < RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE4  !(WINLT < RESULT < WINUT) 
 * ADC_CTRLB_WINSS  Window Single Sample 
 */
static inline void adc_set_CTRLB(ADC_t *pADC, uint16_t mask)
{
	pADC->CTRLB.reg |= mask;
}

/**
 * @brief adc get CTRLB register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_CTRLB_LEFTADJ  Left-Adjusted Result 
 * ADC_CTRLB_FREERUN  Free Running Mode 
 * ADC_CTRLB_CORREN  Digital Correction Logic Enable 
 * ADC_CTRLB_RESSEL(value)  Conversion Result Resolution 
 *    ADC_CTRLB_RESSEL_12BIT  12-bit result 
 *    ADC_CTRLB_RESSEL_16BIT  For averaging mode output 
 *    ADC_CTRLB_RESSEL_10BIT  10-bit result 
 *    ADC_CTRLB_RESSEL_8BIT  8-bit result 
 * ADC_CTRLB_WINMODE(value)  Window Monitor Mode 
 *    ADC_CTRLB_WINMODE_DISABLE  No window mode (default) 
 *    ADC_CTRLB_WINMODE_MODE1  RESULT > WINLT 
 *    ADC_CTRLB_WINMODE_MODE2  RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE3  WINLT < RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE4  !(WINLT < RESULT < WINUT) 
 * ADC_CTRLB_WINSS  Window Single Sample 
 */
static inline uint16_t adc_get_CTRLB(ADC_t *pADC, uint16_t mask)
{
    return pADC->CTRLB.reg & mask;
}

/**
 * @brief adc write CTRLB register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t data
 * ADC_CTRLB_LEFTADJ  Left-Adjusted Result 
 * ADC_CTRLB_FREERUN  Free Running Mode 
 * ADC_CTRLB_CORREN  Digital Correction Logic Enable 
 * ADC_CTRLB_RESSEL(value)  Conversion Result Resolution 
 *    ADC_CTRLB_RESSEL_12BIT  12-bit result 
 *    ADC_CTRLB_RESSEL_16BIT  For averaging mode output 
 *    ADC_CTRLB_RESSEL_10BIT  10-bit result 
 *    ADC_CTRLB_RESSEL_8BIT  8-bit result 
 * ADC_CTRLB_WINMODE(value)  Window Monitor Mode 
 *    ADC_CTRLB_WINMODE_DISABLE  No window mode (default) 
 *    ADC_CTRLB_WINMODE_MODE1  RESULT > WINLT 
 *    ADC_CTRLB_WINMODE_MODE2  RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE3  WINLT < RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE4  !(WINLT < RESULT < WINUT) 
 * ADC_CTRLB_WINSS  Window Single Sample 
 */
static inline void adc_write_CTRLB(ADC_t *pADC, uint16_t data)
{
	pADC->CTRLB.reg = data;
}

/**
 * @brief adc clear CTRLB register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_CTRLB_LEFTADJ  Left-Adjusted Result 
 * ADC_CTRLB_FREERUN  Free Running Mode 
 * ADC_CTRLB_CORREN  Digital Correction Logic Enable 
 * ADC_CTRLB_RESSEL(value)  Conversion Result Resolution 
 *    ADC_CTRLB_RESSEL_12BIT  12-bit result 
 *    ADC_CTRLB_RESSEL_16BIT  For averaging mode output 
 *    ADC_CTRLB_RESSEL_10BIT  10-bit result 
 *    ADC_CTRLB_RESSEL_8BIT  8-bit result 
 * ADC_CTRLB_WINMODE(value)  Window Monitor Mode 
 *    ADC_CTRLB_WINMODE_DISABLE  No window mode (default) 
 *    ADC_CTRLB_WINMODE_MODE1  RESULT > WINLT 
 *    ADC_CTRLB_WINMODE_MODE2  RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE3  WINLT < RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE4  !(WINLT < RESULT < WINUT) 
 * ADC_CTRLB_WINSS  Window Single Sample 
 */
static inline void adc_clear_CTRLB(ADC_t *pADC, uint16_t mask)
{
	pADC->CTRLB.reg &= ~mask;
}

/**
 * @brief adc read CTRLB register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_CTRLB_LEFTADJ  Left-Adjusted Result 
 * ADC_CTRLB_FREERUN  Free Running Mode 
 * ADC_CTRLB_CORREN  Digital Correction Logic Enable 
 * ADC_CTRLB_RESSEL(value)  Conversion Result Resolution 
 *    ADC_CTRLB_RESSEL_12BIT  12-bit result 
 *    ADC_CTRLB_RESSEL_16BIT  For averaging mode output 
 *    ADC_CTRLB_RESSEL_10BIT  10-bit result 
 *    ADC_CTRLB_RESSEL_8BIT  8-bit result 
 * ADC_CTRLB_WINMODE(value)  Window Monitor Mode 
 *    ADC_CTRLB_WINMODE_DISABLE  No window mode (default) 
 *    ADC_CTRLB_WINMODE_MODE1  RESULT > WINLT 
 *    ADC_CTRLB_WINMODE_MODE2  RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE3  WINLT < RESULT < WINUT 
 *    ADC_CTRLB_WINMODE_MODE4  !(WINLT < RESULT < WINUT) 
 * ADC_CTRLB_WINSS  Window Single Sample 
 */
static inline uint16_t adc_read_CTRLB(ADC_t *pADC)
{
	return pADC->CTRLB.reg;
}

/**
 * @brief adc set REFCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_REFCTRL_REFSEL(value)  Reference Selection 
 *    ADC_REFCTRL_REFSEL_INTREF  Internal Bandgap Reference 
 *    ADC_REFCTRL_REFSEL_INTVCC0  1/2 VDDANA 
 *    ADC_REFCTRL_REFSEL_INTVCC1  VDDANA 
 *    ADC_REFCTRL_REFSEL_AREFA  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFB  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFC  External Reference (only on ADC1) 
 * ADC_REFCTRL_REFCOMP  Reference Buffer Offset Compensation Enable 
 */
static inline void adc_set_REFCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->REFCTRL.reg |= mask;
}

/**
 * @brief adc get REFCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_REFCTRL_REFSEL(value)  Reference Selection 
 *    ADC_REFCTRL_REFSEL_INTREF  Internal Bandgap Reference 
 *    ADC_REFCTRL_REFSEL_INTVCC0  1/2 VDDANA 
 *    ADC_REFCTRL_REFSEL_INTVCC1  VDDANA 
 *    ADC_REFCTRL_REFSEL_AREFA  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFB  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFC  External Reference (only on ADC1) 
 * ADC_REFCTRL_REFCOMP  Reference Buffer Offset Compensation Enable 
 */
static inline uint8_t adc_get_REFCTRL(ADC_t *pADC, uint8_t mask)
{
    return pADC->REFCTRL.reg & mask;
}

/**
 * @brief adc write REFCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t data
 * ADC_REFCTRL_REFSEL(value)  Reference Selection 
 *    ADC_REFCTRL_REFSEL_INTREF  Internal Bandgap Reference 
 *    ADC_REFCTRL_REFSEL_INTVCC0  1/2 VDDANA 
 *    ADC_REFCTRL_REFSEL_INTVCC1  VDDANA 
 *    ADC_REFCTRL_REFSEL_AREFA  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFB  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFC  External Reference (only on ADC1) 
 * ADC_REFCTRL_REFCOMP  Reference Buffer Offset Compensation Enable 
 */
static inline void adc_write_REFCTRL(ADC_t *pADC, uint8_t data)
{
	pADC->REFCTRL.reg = data;
}

/**
 * @brief adc clear REFCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_REFCTRL_REFSEL(value)  Reference Selection 
 *    ADC_REFCTRL_REFSEL_INTREF  Internal Bandgap Reference 
 *    ADC_REFCTRL_REFSEL_INTVCC0  1/2 VDDANA 
 *    ADC_REFCTRL_REFSEL_INTVCC1  VDDANA 
 *    ADC_REFCTRL_REFSEL_AREFA  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFB  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFC  External Reference (only on ADC1) 
 * ADC_REFCTRL_REFCOMP  Reference Buffer Offset Compensation Enable 
 */
static inline void adc_clear_REFCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->REFCTRL.reg &= ~mask;
}

/**
 * @brief adc read REFCTRL register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_REFCTRL_REFSEL(value)  Reference Selection 
 *    ADC_REFCTRL_REFSEL_INTREF  Internal Bandgap Reference 
 *    ADC_REFCTRL_REFSEL_INTVCC0  1/2 VDDANA 
 *    ADC_REFCTRL_REFSEL_INTVCC1  VDDANA 
 *    ADC_REFCTRL_REFSEL_AREFA  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFB  External Reference 
 *    ADC_REFCTRL_REFSEL_AREFC  External Reference (only on ADC1) 
 * ADC_REFCTRL_REFCOMP  Reference Buffer Offset Compensation Enable 
 */
static inline uint8_t adc_read_REFCTRL(ADC_t *pADC)
{
	return pADC->REFCTRL.reg;
}

/**
 * @brief adc set AVGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_AVGCTRL_SAMPLENUM(value)  Number of Samples to be Collected 
 *    ADC_AVGCTRL_SAMPLENUM_1  1 sample 
 *    ADC_AVGCTRL_SAMPLENUM_2  2 samples 
 *    ADC_AVGCTRL_SAMPLENUM_4  4 samples 
 *    ADC_AVGCTRL_SAMPLENUM_8  8 samples 
 *    ADC_AVGCTRL_SAMPLENUM_16  16 samples 
 *    ADC_AVGCTRL_SAMPLENUM_32  32 samples 
 *    ADC_AVGCTRL_SAMPLENUM_64  64 samples 
 *    ADC_AVGCTRL_SAMPLENUM_128  128 samples 
 *    ADC_AVGCTRL_SAMPLENUM_256  256 samples 
 *    ADC_AVGCTRL_SAMPLENUM_512  512 samples 
 *    ADC_AVGCTRL_SAMPLENUM_1024  1024 samples 
 * ADC_AVGCTRL_ADJRES(value)  Adjusting Result / Division Coefficient 
 */
static inline void adc_set_AVGCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->AVGCTRL.reg |= mask;
}

/**
 * @brief adc get AVGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_AVGCTRL_SAMPLENUM(value)  Number of Samples to be Collected 
 *    ADC_AVGCTRL_SAMPLENUM_1  1 sample 
 *    ADC_AVGCTRL_SAMPLENUM_2  2 samples 
 *    ADC_AVGCTRL_SAMPLENUM_4  4 samples 
 *    ADC_AVGCTRL_SAMPLENUM_8  8 samples 
 *    ADC_AVGCTRL_SAMPLENUM_16  16 samples 
 *    ADC_AVGCTRL_SAMPLENUM_32  32 samples 
 *    ADC_AVGCTRL_SAMPLENUM_64  64 samples 
 *    ADC_AVGCTRL_SAMPLENUM_128  128 samples 
 *    ADC_AVGCTRL_SAMPLENUM_256  256 samples 
 *    ADC_AVGCTRL_SAMPLENUM_512  512 samples 
 *    ADC_AVGCTRL_SAMPLENUM_1024  1024 samples 
 * ADC_AVGCTRL_ADJRES(value)  Adjusting Result / Division Coefficient 
 */
static inline uint8_t adc_get_AVGCTRL(ADC_t *pADC, uint8_t mask)
{
    return pADC->AVGCTRL.reg & mask;
}

/**
 * @brief adc write AVGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t data
 * ADC_AVGCTRL_SAMPLENUM(value)  Number of Samples to be Collected 
 *    ADC_AVGCTRL_SAMPLENUM_1  1 sample 
 *    ADC_AVGCTRL_SAMPLENUM_2  2 samples 
 *    ADC_AVGCTRL_SAMPLENUM_4  4 samples 
 *    ADC_AVGCTRL_SAMPLENUM_8  8 samples 
 *    ADC_AVGCTRL_SAMPLENUM_16  16 samples 
 *    ADC_AVGCTRL_SAMPLENUM_32  32 samples 
 *    ADC_AVGCTRL_SAMPLENUM_64  64 samples 
 *    ADC_AVGCTRL_SAMPLENUM_128  128 samples 
 *    ADC_AVGCTRL_SAMPLENUM_256  256 samples 
 *    ADC_AVGCTRL_SAMPLENUM_512  512 samples 
 *    ADC_AVGCTRL_SAMPLENUM_1024  1024 samples 
 * ADC_AVGCTRL_ADJRES(value)  Adjusting Result / Division Coefficient 
 */
static inline void adc_write_AVGCTRL(ADC_t *pADC, uint8_t data)
{
	pADC->AVGCTRL.reg = data;
}

/**
 * @brief adc clear AVGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_AVGCTRL_SAMPLENUM(value)  Number of Samples to be Collected 
 *    ADC_AVGCTRL_SAMPLENUM_1  1 sample 
 *    ADC_AVGCTRL_SAMPLENUM_2  2 samples 
 *    ADC_AVGCTRL_SAMPLENUM_4  4 samples 
 *    ADC_AVGCTRL_SAMPLENUM_8  8 samples 
 *    ADC_AVGCTRL_SAMPLENUM_16  16 samples 
 *    ADC_AVGCTRL_SAMPLENUM_32  32 samples 
 *    ADC_AVGCTRL_SAMPLENUM_64  64 samples 
 *    ADC_AVGCTRL_SAMPLENUM_128  128 samples 
 *    ADC_AVGCTRL_SAMPLENUM_256  256 samples 
 *    ADC_AVGCTRL_SAMPLENUM_512  512 samples 
 *    ADC_AVGCTRL_SAMPLENUM_1024  1024 samples 
 * ADC_AVGCTRL_ADJRES(value)  Adjusting Result / Division Coefficient 
 */
static inline void adc_clear_AVGCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->AVGCTRL.reg &= ~mask;
}

/**
 * @brief adc read AVGCTRL register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_AVGCTRL_SAMPLENUM(value)  Number of Samples to be Collected 
 *    ADC_AVGCTRL_SAMPLENUM_1  1 sample 
 *    ADC_AVGCTRL_SAMPLENUM_2  2 samples 
 *    ADC_AVGCTRL_SAMPLENUM_4  4 samples 
 *    ADC_AVGCTRL_SAMPLENUM_8  8 samples 
 *    ADC_AVGCTRL_SAMPLENUM_16  16 samples 
 *    ADC_AVGCTRL_SAMPLENUM_32  32 samples 
 *    ADC_AVGCTRL_SAMPLENUM_64  64 samples 
 *    ADC_AVGCTRL_SAMPLENUM_128  128 samples 
 *    ADC_AVGCTRL_SAMPLENUM_256  256 samples 
 *    ADC_AVGCTRL_SAMPLENUM_512  512 samples 
 *    ADC_AVGCTRL_SAMPLENUM_1024  1024 samples 
 * ADC_AVGCTRL_ADJRES(value)  Adjusting Result / Division Coefficient 
 */
static inline uint8_t adc_read_AVGCTRL(ADC_t *pADC)
{
	return pADC->AVGCTRL.reg;
}

/**
 * @brief adc set SAMPCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_SAMPCTRL_SAMPLEN(value)  Sampling Time Length 
 * ADC_SAMPCTRL_OFFCOMP  Comparator Offset Compensation Enable 
 */
static inline void adc_set_SAMPCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->SAMPCTRL.reg |= mask;
}

/**
 * @brief adc get SAMPCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_SAMPCTRL_SAMPLEN(value)  Sampling Time Length 
 * ADC_SAMPCTRL_OFFCOMP  Comparator Offset Compensation Enable 
 */
static inline uint8_t adc_get_SAMPCTRL(ADC_t *pADC, uint8_t mask)
{
    return pADC->SAMPCTRL.reg & mask;
}

/**
 * @brief adc write SAMPCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t data
 * ADC_SAMPCTRL_SAMPLEN(value)  Sampling Time Length 
 * ADC_SAMPCTRL_OFFCOMP  Comparator Offset Compensation Enable 
 */
static inline void adc_write_SAMPCTRL(ADC_t *pADC, uint8_t data)
{
	pADC->SAMPCTRL.reg = data;
}

/**
 * @brief adc clear SAMPCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_SAMPCTRL_SAMPLEN(value)  Sampling Time Length 
 * ADC_SAMPCTRL_OFFCOMP  Comparator Offset Compensation Enable 
 */
static inline void adc_clear_SAMPCTRL(ADC_t *pADC, uint8_t mask)
{
	pADC->SAMPCTRL.reg &= ~mask;
}

/**
 * @brief adc read SAMPCTRL register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_SAMPCTRL_SAMPLEN(value)  Sampling Time Length 
 * ADC_SAMPCTRL_OFFCOMP  Comparator Offset Compensation Enable 
 */
static inline uint8_t adc_read_SAMPCTRL(ADC_t *pADC)
{
	return pADC->SAMPCTRL.reg;
}

/**
 * @brief adc set WINLT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_WINLT_WINLT(value)  Window Lower Threshold 
 */
static inline void adc_set_WINLT(ADC_t *pADC, uint16_t mask)
{
	pADC->WINLT.reg |= mask;
}

/**
 * @brief adc get WINLT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_WINLT_WINLT(value)  Window Lower Threshold 
 */
static inline uint16_t adc_get_WINLT(ADC_t *pADC, uint16_t mask)
{
    return pADC->WINLT.reg & mask;
}

/**
 * @brief adc write WINLT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t data
 * ADC_WINLT_WINLT(value)  Window Lower Threshold 
 */
static inline void adc_write_WINLT(ADC_t *pADC, uint16_t data)
{
	pADC->WINLT.reg = data;
}

/**
 * @brief adc clear WINLT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_WINLT_WINLT(value)  Window Lower Threshold 
 */
static inline void adc_clear_WINLT(ADC_t *pADC, uint16_t mask)
{
	pADC->WINLT.reg &= ~mask;
}

/**
 * @brief adc read WINLT register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_WINLT_WINLT(value)  Window Lower Threshold 
 */
static inline uint16_t adc_read_WINLT(ADC_t *pADC)
{
	return pADC->WINLT.reg;
}

/**
 * @brief adc set WINUT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_WINUT_WINUT(value)  Window Upper Threshold 
 */
static inline void adc_set_WINUT(ADC_t *pADC, uint16_t mask)
{
	pADC->WINUT.reg |= mask;
}

/**
 * @brief adc get WINUT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_WINUT_WINUT(value)  Window Upper Threshold 
 */
static inline uint16_t adc_get_WINUT(ADC_t *pADC, uint16_t mask)
{
    return pADC->WINUT.reg & mask;
}

/**
 * @brief adc write WINUT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t data
 * ADC_WINUT_WINUT(value)  Window Upper Threshold 
 */
static inline void adc_write_WINUT(ADC_t *pADC, uint16_t data)
{
	pADC->WINUT.reg = data;
}

/**
 * @brief adc clear WINUT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_WINUT_WINUT(value)  Window Upper Threshold 
 */
static inline void adc_clear_WINUT(ADC_t *pADC, uint16_t mask)
{
	pADC->WINUT.reg &= ~mask;
}

/**
 * @brief adc read WINUT register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_WINUT_WINUT(value)  Window Upper Threshold 
 */
static inline uint16_t adc_read_WINUT(ADC_t *pADC)
{
	return pADC->WINUT.reg;
}

/**
 * @brief adc set GAINCORR register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_GAINCORR_GAINCORR(value)  Gain Correction Value 
 */
static inline void adc_set_GAINCORR(ADC_t *pADC, uint16_t mask)
{
	pADC->GAINCORR.reg |= mask;
}

/**
 * @brief adc get GAINCORR register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_GAINCORR_GAINCORR(value)  Gain Correction Value 
 */
static inline uint16_t adc_get_GAINCORR(ADC_t *pADC, uint16_t mask)
{
    return pADC->GAINCORR.reg & mask;
}

/**
 * @brief adc write GAINCORR register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t data
 * ADC_GAINCORR_GAINCORR(value)  Gain Correction Value 
 */
static inline void adc_write_GAINCORR(ADC_t *pADC, uint16_t data)
{
	pADC->GAINCORR.reg = data;
}

/**
 * @brief adc clear GAINCORR register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_GAINCORR_GAINCORR(value)  Gain Correction Value 
 */
static inline void adc_clear_GAINCORR(ADC_t *pADC, uint16_t mask)
{
	pADC->GAINCORR.reg &= ~mask;
}

/**
 * @brief adc read GAINCORR register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_GAINCORR_GAINCORR(value)  Gain Correction Value 
 */
static inline uint16_t adc_read_GAINCORR(ADC_t *pADC)
{
	return pADC->GAINCORR.reg;
}

/**
 * @brief adc set OFFSETCORR register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_OFFSETCORR_OFFSETCORR(value)  Offset Correction Value 
 */
static inline void adc_set_OFFSETCORR(ADC_t *pADC, uint16_t mask)
{
	pADC->OFFSETCORR.reg |= mask;
}

/**
 * @brief adc get OFFSETCORR register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_OFFSETCORR_OFFSETCORR(value)  Offset Correction Value 
 */
static inline uint16_t adc_get_OFFSETCORR(ADC_t *pADC, uint16_t mask)
{
    return pADC->OFFSETCORR.reg & mask;
}

/**
 * @brief adc write OFFSETCORR register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t data
 * ADC_OFFSETCORR_OFFSETCORR(value)  Offset Correction Value 
 */
static inline void adc_write_OFFSETCORR(ADC_t *pADC, uint16_t data)
{
	pADC->OFFSETCORR.reg = data;
}

/**
 * @brief adc clear OFFSETCORR register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_OFFSETCORR_OFFSETCORR(value)  Offset Correction Value 
 */
static inline void adc_clear_OFFSETCORR(ADC_t *pADC, uint16_t mask)
{
	pADC->OFFSETCORR.reg &= ~mask;
}

/**
 * @brief adc read OFFSETCORR register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_OFFSETCORR_OFFSETCORR(value)  Offset Correction Value 
 */
static inline uint16_t adc_read_OFFSETCORR(ADC_t *pADC)
{
	return pADC->OFFSETCORR.reg;
}

/**
 * @brief adc set SWTRIG register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_SWTRIG_FLUSH  ADC Conversion Flush 
 * ADC_SWTRIG_START  Start ADC Conversion 
 */
static inline void adc_set_SWTRIG(ADC_t *pADC, uint8_t mask)
{
	pADC->SWTRIG.reg |= mask;
}

/**
 * @brief adc get SWTRIG register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_SWTRIG_FLUSH  ADC Conversion Flush 
 * ADC_SWTRIG_START  Start ADC Conversion 
 */
static inline uint8_t adc_get_SWTRIG(ADC_t *pADC, uint8_t mask)
{
    return pADC->SWTRIG.reg & mask;
}

/**
 * @brief adc write SWTRIG register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t data
 * ADC_SWTRIG_FLUSH  ADC Conversion Flush 
 * ADC_SWTRIG_START  Start ADC Conversion 
 */
static inline void adc_write_SWTRIG(ADC_t *pADC, uint8_t data)
{
	pADC->SWTRIG.reg = data;
}

/**
 * @brief adc clear SWTRIG register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * ADC_SWTRIG_FLUSH  ADC Conversion Flush 
 * ADC_SWTRIG_START  Start ADC Conversion 
 */
static inline void adc_clear_SWTRIG(ADC_t *pADC, uint8_t mask)
{
	pADC->SWTRIG.reg &= ~mask;
}

/**
 * @brief adc read SWTRIG register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_SWTRIG_FLUSH  ADC Conversion Flush 
 * ADC_SWTRIG_START  Start ADC Conversion 
 */
static inline uint8_t adc_read_SWTRIG(ADC_t *pADC)
{
	return pADC->SWTRIG.reg;
}

/**
 * @brief adc set DSEQCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t mask
 * ADC_DSEQCTRL_INPUTCTRL  Input Control 
 * ADC_DSEQCTRL_CTRLB  Control B 
 * ADC_DSEQCTRL_REFCTRL  Reference Control 
 * ADC_DSEQCTRL_AVGCTRL  Average Control 
 * ADC_DSEQCTRL_SAMPCTRL  Sampling Time Control 
 * ADC_DSEQCTRL_WINLT  Window Monitor Lower Threshold 
 * ADC_DSEQCTRL_WINUT  Window Monitor Upper Threshold 
 * ADC_DSEQCTRL_GAINCORR  Gain Correction 
 * ADC_DSEQCTRL_OFFSETCORR  Offset Correction 
 * ADC_DSEQCTRL_AUTOSTART  ADC Auto-Start Conversion 
 */
static inline void adc_set_DSEQCTRL(ADC_t *pADC, uint32_t mask)
{
	pADC->DSEQCTRL.reg |= mask;
}

/**
 * @brief adc get DSEQCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t mask
 * @return uint32_t
 * ADC_DSEQCTRL_INPUTCTRL  Input Control 
 * ADC_DSEQCTRL_CTRLB  Control B 
 * ADC_DSEQCTRL_REFCTRL  Reference Control 
 * ADC_DSEQCTRL_AVGCTRL  Average Control 
 * ADC_DSEQCTRL_SAMPCTRL  Sampling Time Control 
 * ADC_DSEQCTRL_WINLT  Window Monitor Lower Threshold 
 * ADC_DSEQCTRL_WINUT  Window Monitor Upper Threshold 
 * ADC_DSEQCTRL_GAINCORR  Gain Correction 
 * ADC_DSEQCTRL_OFFSETCORR  Offset Correction 
 * ADC_DSEQCTRL_AUTOSTART  ADC Auto-Start Conversion 
 */
static inline uint32_t adc_get_DSEQCTRL(ADC_t *pADC, uint32_t mask)
{
    return pADC->DSEQCTRL.reg & mask;
}

/**
 * @brief adc write DSEQCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t data
 * ADC_DSEQCTRL_INPUTCTRL  Input Control 
 * ADC_DSEQCTRL_CTRLB  Control B 
 * ADC_DSEQCTRL_REFCTRL  Reference Control 
 * ADC_DSEQCTRL_AVGCTRL  Average Control 
 * ADC_DSEQCTRL_SAMPCTRL  Sampling Time Control 
 * ADC_DSEQCTRL_WINLT  Window Monitor Lower Threshold 
 * ADC_DSEQCTRL_WINUT  Window Monitor Upper Threshold 
 * ADC_DSEQCTRL_GAINCORR  Gain Correction 
 * ADC_DSEQCTRL_OFFSETCORR  Offset Correction 
 * ADC_DSEQCTRL_AUTOSTART  ADC Auto-Start Conversion 
 */
static inline void adc_write_DSEQCTRL(ADC_t *pADC, uint32_t data)
{
	pADC->DSEQCTRL.reg = data;
}

/**
 * @brief adc clear DSEQCTRL register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t mask
 * ADC_DSEQCTRL_INPUTCTRL  Input Control 
 * ADC_DSEQCTRL_CTRLB  Control B 
 * ADC_DSEQCTRL_REFCTRL  Reference Control 
 * ADC_DSEQCTRL_AVGCTRL  Average Control 
 * ADC_DSEQCTRL_SAMPCTRL  Sampling Time Control 
 * ADC_DSEQCTRL_WINLT  Window Monitor Lower Threshold 
 * ADC_DSEQCTRL_WINUT  Window Monitor Upper Threshold 
 * ADC_DSEQCTRL_GAINCORR  Gain Correction 
 * ADC_DSEQCTRL_OFFSETCORR  Offset Correction 
 * ADC_DSEQCTRL_AUTOSTART  ADC Auto-Start Conversion 
 */
static inline void adc_clear_DSEQCTRL(ADC_t *pADC, uint32_t mask)
{
	pADC->DSEQCTRL.reg &= ~mask;
}

/**
 * @brief adc read DSEQCTRL register
 *
 * @param[in] ADC_t *pADC
 * @return uint32_t
 * ADC_DSEQCTRL_INPUTCTRL  Input Control 
 * ADC_DSEQCTRL_CTRLB  Control B 
 * ADC_DSEQCTRL_REFCTRL  Reference Control 
 * ADC_DSEQCTRL_AVGCTRL  Average Control 
 * ADC_DSEQCTRL_SAMPCTRL  Sampling Time Control 
 * ADC_DSEQCTRL_WINLT  Window Monitor Lower Threshold 
 * ADC_DSEQCTRL_WINUT  Window Monitor Upper Threshold 
 * ADC_DSEQCTRL_GAINCORR  Gain Correction 
 * ADC_DSEQCTRL_OFFSETCORR  Offset Correction 
 * ADC_DSEQCTRL_AUTOSTART  ADC Auto-Start Conversion 
 */
static inline uint32_t adc_read_DSEQCTRL(ADC_t *pADC)
{
	return pADC->DSEQCTRL.reg;
}

/**
 * @brief adc set CALIB register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_CALIB_BIASCOMP(value)  Bias Comparator Scaling 
 * ADC_CALIB_BIASR2R(value)  Bias R2R Ampli scaling 
 * ADC_CALIB_BIASREFBUF(value)  Bias  Reference Buffer Scaling 
 */
static inline void adc_set_CALIB(ADC_t *pADC, uint16_t mask)
{
	pADC->CALIB.reg |= mask;
}

/**
 * @brief adc get CALIB register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_CALIB_BIASCOMP(value)  Bias Comparator Scaling 
 * ADC_CALIB_BIASR2R(value)  Bias R2R Ampli scaling 
 * ADC_CALIB_BIASREFBUF(value)  Bias  Reference Buffer Scaling 
 */
static inline uint16_t adc_get_CALIB(ADC_t *pADC, uint16_t mask)
{
    return pADC->CALIB.reg & mask;
}

/**
 * @brief adc write CALIB register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t data
 * ADC_CALIB_BIASCOMP(value)  Bias Comparator Scaling 
 * ADC_CALIB_BIASR2R(value)  Bias R2R Ampli scaling 
 * ADC_CALIB_BIASREFBUF(value)  Bias  Reference Buffer Scaling 
 */
static inline void adc_write_CALIB(ADC_t *pADC, uint16_t data)
{
	pADC->CALIB.reg = data;
}

/**
 * @brief adc clear CALIB register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * ADC_CALIB_BIASCOMP(value)  Bias Comparator Scaling 
 * ADC_CALIB_BIASR2R(value)  Bias R2R Ampli scaling 
 * ADC_CALIB_BIASREFBUF(value)  Bias  Reference Buffer Scaling 
 */
static inline void adc_clear_CALIB(ADC_t *pADC, uint16_t mask)
{
	pADC->CALIB.reg &= ~mask;
}

/**
 * @brief adc read CALIB register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_CALIB_BIASCOMP(value)  Bias Comparator Scaling 
 * ADC_CALIB_BIASR2R(value)  Bias R2R Ampli scaling 
 * ADC_CALIB_BIASREFBUF(value)  Bias  Reference Buffer Scaling 
 */
static inline uint16_t adc_read_CALIB(ADC_t *pADC)
{
	return pADC->CALIB.reg;
}

/**
 * @brief adc get STATUS register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint8_t mask
 * @return uint8_t
 * ADC_STATUS_ADCBUSY  ADC Busy Status 
 * ADC_STATUS_WCC(value)  Window Comparator Counter 
 */
static inline uint8_t adc_get_STATUS(ADC_t *pADC, uint8_t mask)
{
    return pADC->STATUS.reg & mask;
}

/**
 * @brief adc read STATUS register
 *
 * @param[in] ADC_t *pADC
 * @return uint8_t
 * ADC_STATUS_ADCBUSY  ADC Busy Status 
 * ADC_STATUS_WCC(value)  Window Comparator Counter 
 */
static inline uint8_t adc_read_STATUS(ADC_t *pADC)
{
	return pADC->STATUS.reg;
}

/**
 * @brief adc get SYNCBUSY register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t mask
 * @return uint32_t
 * ADC_SYNCBUSY_SWRST  SWRST Synchronization Busy 
 * ADC_SYNCBUSY_ENABLE  ENABLE Synchronization Busy 
 * ADC_SYNCBUSY_INPUTCTRL  Input Control Synchronization Busy 
 * ADC_SYNCBUSY_CTRLB  Control B Synchronization Busy 
 * ADC_SYNCBUSY_REFCTRL  Reference Control Synchronization Busy 
 * ADC_SYNCBUSY_AVGCTRL  Average Control Synchronization Busy 
 * ADC_SYNCBUSY_SAMPCTRL  Sampling Time Control Synchronization Busy 
 * ADC_SYNCBUSY_WINLT  Window Monitor Lower Threshold Synchronization Busy 
 * ADC_SYNCBUSY_WINUT  Window Monitor Upper Threshold Synchronization Busy 
 * ADC_SYNCBUSY_GAINCORR  Gain Correction Synchronization Busy 
 * ADC_SYNCBUSY_OFFSETCORR  Offset Correction Synchronization Busy 
 * ADC_SYNCBUSY_SWTRIG  Software Trigger Synchronization Busy 
 */
static inline uint32_t adc_get_SYNCBUSY(ADC_t *pADC, uint32_t mask)
{
    return pADC->SYNCBUSY.reg & mask;
}

/**
 * @brief adc read SYNCBUSY register
 *
 * @param[in] ADC_t *pADC
 * @return uint32_t
 * ADC_SYNCBUSY_SWRST  SWRST Synchronization Busy 
 * ADC_SYNCBUSY_ENABLE  ENABLE Synchronization Busy 
 * ADC_SYNCBUSY_INPUTCTRL  Input Control Synchronization Busy 
 * ADC_SYNCBUSY_CTRLB  Control B Synchronization Busy 
 * ADC_SYNCBUSY_REFCTRL  Reference Control Synchronization Busy 
 * ADC_SYNCBUSY_AVGCTRL  Average Control Synchronization Busy 
 * ADC_SYNCBUSY_SAMPCTRL  Sampling Time Control Synchronization Busy 
 * ADC_SYNCBUSY_WINLT  Window Monitor Lower Threshold Synchronization Busy 
 * ADC_SYNCBUSY_WINUT  Window Monitor Upper Threshold Synchronization Busy 
 * ADC_SYNCBUSY_GAINCORR  Gain Correction Synchronization Busy 
 * ADC_SYNCBUSY_OFFSETCORR  Offset Correction Synchronization Busy 
 * ADC_SYNCBUSY_SWTRIG  Software Trigger Synchronization Busy 
 */
static inline uint32_t adc_read_SYNCBUSY(ADC_t *pADC)
{
	return pADC->SYNCBUSY.reg;
}

/**
 * @brief adc get DSEQSTAT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint32_t mask
 * @return uint32_t
 * ADC_DSEQSTAT_INPUTCTRL  Input Control 
 * ADC_DSEQSTAT_CTRLB  Control B 
 * ADC_DSEQSTAT_REFCTRL  Reference Control 
 * ADC_DSEQSTAT_AVGCTRL  Average Control 
 * ADC_DSEQSTAT_SAMPCTRL  Sampling Time Control 
 * ADC_DSEQSTAT_WINLT  Window Monitor Lower Threshold 
 * ADC_DSEQSTAT_WINUT  Window Monitor Upper Threshold 
 * ADC_DSEQSTAT_GAINCORR  Gain Correction 
 * ADC_DSEQSTAT_OFFSETCORR  Offset Correction 
 * ADC_DSEQSTAT_BUSY  DMA Sequencing Busy 
 */
static inline uint32_t adc_get_DSEQSTAT(ADC_t *pADC, uint32_t mask)
{
    return pADC->DSEQSTAT.reg & mask;
}

/**
 * @brief adc read DSEQSTAT register
 *
 * @param[in] ADC_t *pADC
 * @return uint32_t
 * ADC_DSEQSTAT_INPUTCTRL  Input Control 
 * ADC_DSEQSTAT_CTRLB  Control B 
 * ADC_DSEQSTAT_REFCTRL  Reference Control 
 * ADC_DSEQSTAT_AVGCTRL  Average Control 
 * ADC_DSEQSTAT_SAMPCTRL  Sampling Time Control 
 * ADC_DSEQSTAT_WINLT  Window Monitor Lower Threshold 
 * ADC_DSEQSTAT_WINUT  Window Monitor Upper Threshold 
 * ADC_DSEQSTAT_GAINCORR  Gain Correction 
 * ADC_DSEQSTAT_OFFSETCORR  Offset Correction 
 * ADC_DSEQSTAT_BUSY  DMA Sequencing Busy 
 */
static inline uint32_t adc_read_DSEQSTAT(ADC_t *pADC)
{
	return pADC->DSEQSTAT.reg;
}

/**
 * @brief adc get RESULT register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_RESULT_RESULT(value)  Result Conversion Value 
 */
static inline uint16_t adc_get_RESULT(ADC_t *pADC, uint16_t mask)
{
    return pADC->RESULT.reg & mask;
}

/**
 * @brief adc read RESULT register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_RESULT_RESULT(value)  Result Conversion Value 
 */
static inline uint16_t adc_read_RESULT(ADC_t *pADC)
{
	return pADC->RESULT.reg;
}

/**
 * @brief adc get RESS register
 *
 * @param[in] ADC_t *pADC
 * @param[in] uint16_t mask
 * @return uint16_t
 * ADC_RESS_RESS(value)  Last ADC conversion result 
 */
static inline uint16_t adc_get_RESS(ADC_t *pADC, uint16_t mask)
{
    return pADC->RESS.reg & mask;
}

/**
 * @brief adc read RESS register
 *
 * @param[in] ADC_t *pADC
 * @return uint16_t
 * ADC_RESS_RESS(value)  Last ADC conversion result 
 */
static inline uint16_t adc_read_RESS(ADC_t *pADC)
{
	return pADC->RESS.reg;
}

#endif /* _ADC_H */
