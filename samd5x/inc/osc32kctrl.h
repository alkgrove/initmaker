/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM OSC32KCTRL
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

#ifndef _OSC32KCTRL_H_
#define _OSC32KCTRL_H_

#include <stdbool.h>

/**
 * @brief osc32kctrl set INTEN register
 *
 * @param[in] mask uint32_t 
 * - OSC32KCTRL_INTENSET_XOSC32KRDY XOSC32K Ready Interrupt Enable
 * - OSC32KCTRL_INTENSET_XOSC32KFAIL XOSC32K Clock Failure Detector Interrupt Enable
 **/
static inline void osc32kctrl_set_INTEN(uint32_t mask)
{
	OSC32KCTRL->INTENSET.reg = mask;
}

/**
 * @brief osc32kctrl get INTEN register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSC32KCTRL_INTENSET_XOSC32KRDY XOSC32K Ready Interrupt Enable
 * - OSC32KCTRL_INTENSET_XOSC32KFAIL XOSC32K Clock Failure Detector Interrupt Enable
 **/
static inline uint32_t osc32kctrl_get_INTEN(uint32_t mask)
{
    return OSC32KCTRL->INTENSET.reg & mask;
}

/**
 * @brief osc32kctrl read INTEN register
 *
 * @return uint32_t
 * - OSC32KCTRL_INTENSET_XOSC32KRDY XOSC32K Ready Interrupt Enable
 * - OSC32KCTRL_INTENSET_XOSC32KFAIL XOSC32K Clock Failure Detector Interrupt Enable
 **/
static inline uint32_t osc32kctrl_read_INTEN(void)
{
	return OSC32KCTRL->INTENSET.reg;
}

/**
 * @brief osc32kctrl write INTEN register
 *
 * @param[in] data uint32_t 
 * - OSC32KCTRL_INTENSET_XOSC32KRDY XOSC32K Ready Interrupt Enable
 * - OSC32KCTRL_INTENSET_XOSC32KFAIL XOSC32K Clock Failure Detector Interrupt Enable
 **/
static inline void osc32kctrl_write_INTEN(uint32_t data)
{
	OSC32KCTRL->INTENSET.reg = data;
	OSC32KCTRL->INTENCLR.reg = ~data;
}

/**
 * @brief osc32kctrl clear INTEN register
 *
 * @param[in] mask uint32_t 
 * - OSC32KCTRL_INTENSET_XOSC32KRDY XOSC32K Ready Interrupt Enable
 * - OSC32KCTRL_INTENSET_XOSC32KFAIL XOSC32K Clock Failure Detector Interrupt Enable
 **/
static inline void osc32kctrl_clear_INTEN(uint32_t mask)
{
	OSC32KCTRL->INTENCLR.reg = mask;
}

/**
 * @brief osc32kctrl get INTFLAG register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSC32KCTRL_INTFLAG_XOSC32KRDY XOSC32K Ready
 * - OSC32KCTRL_INTFLAG_XOSC32KFAIL XOSC32K Clock Failure Detector
 **/
static inline uint32_t osc32kctrl_get_INTFLAG(uint32_t mask)
{
    return OSC32KCTRL->INTFLAG.reg & mask;
}

/**
 * @brief osc32kctrl read INTFLAG register
 *
 * @return uint32_t
 * - OSC32KCTRL_INTFLAG_XOSC32KRDY XOSC32K Ready
 * - OSC32KCTRL_INTFLAG_XOSC32KFAIL XOSC32K Clock Failure Detector
 **/
static inline uint32_t osc32kctrl_read_INTFLAG(void)
{
	return OSC32KCTRL->INTFLAG.reg;
}

/**
 * @brief osc32kctrl clear INTFLAG register
 *
 * @param[in] mask uint32_t 
 * - OSC32KCTRL_INTFLAG_XOSC32KRDY XOSC32K Ready
 * - OSC32KCTRL_INTFLAG_XOSC32KFAIL XOSC32K Clock Failure Detector
 **/
static inline void osc32kctrl_clear_INTFLAG(uint32_t mask)
{
	OSC32KCTRL->INTFLAG.reg = mask;
}

/**
 * @brief osc32kctrl set RTCCTRL register
 *
 * @param[in] mask uint8_t 
 * - OSC32KCTRL_RTCCTRL_RTCSEL(value) RTC Clock Selection
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K 1.024kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K 32.768kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K 1.024kHz from 32.768kHz internal oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K 32.768kHz from 32.768kHz external crystal oscillator
 **/
static inline void osc32kctrl_set_RTCCTRL(uint8_t mask)
{
	OSC32KCTRL->RTCCTRL.reg |= mask;
}

/**
 * @brief osc32kctrl get RTCCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - OSC32KCTRL_RTCCTRL_RTCSEL(value) RTC Clock Selection
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K 1.024kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K 32.768kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K 1.024kHz from 32.768kHz internal oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K 32.768kHz from 32.768kHz external crystal oscillator
 **/
static inline uint8_t osc32kctrl_get_RTCCTRL(uint8_t mask)
{
    return OSC32KCTRL->RTCCTRL.reg & mask;
}

/**
 * @brief osc32kctrl write RTCCTRL register
 *
 * @param[in] data uint8_t 
 * - OSC32KCTRL_RTCCTRL_RTCSEL(value) RTC Clock Selection
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K 1.024kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K 32.768kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K 1.024kHz from 32.768kHz internal oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K 32.768kHz from 32.768kHz external crystal oscillator
 **/
static inline void osc32kctrl_write_RTCCTRL(uint8_t data)
{
	OSC32KCTRL->RTCCTRL.reg = data;
}

/**
 * @brief osc32kctrl clear RTCCTRL register
 *
 * @param[in] mask uint8_t 
 * - OSC32KCTRL_RTCCTRL_RTCSEL(value) RTC Clock Selection
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K 1.024kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K 32.768kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K 1.024kHz from 32.768kHz internal oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K 32.768kHz from 32.768kHz external crystal oscillator
 **/
static inline void osc32kctrl_clear_RTCCTRL(uint8_t mask)
{
	OSC32KCTRL->RTCCTRL.reg &= ~mask;
}

/**
 * @brief osc32kctrl read RTCCTRL register
 *
 * @return uint8_t
 * - OSC32KCTRL_RTCCTRL_RTCSEL(value) RTC Clock Selection
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K 1.024kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K 32.768kHz from 32kHz internal ULP oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K 1.024kHz from 32.768kHz internal oscillator
 *  +      OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K 32.768kHz from 32.768kHz external crystal oscillator
 **/
static inline uint8_t osc32kctrl_read_RTCCTRL(void)
{
	return OSC32KCTRL->RTCCTRL.reg;
}

/**
 * @brief osc32kctrl set XOSC32K register
 *
 * @param[in] mask uint16_t 
 * - OSC32KCTRL_XOSC32K_ENABLE Oscillator Enable
 * - OSC32KCTRL_XOSC32K_XTALEN Crystal Oscillator Enable
 * - OSC32KCTRL_XOSC32K_EN32K 32kHz Output Enable
 * - OSC32KCTRL_XOSC32K_EN1K 1kHz Output Enable
 * - OSC32KCTRL_XOSC32K_RUNSTDBY Run in Standby
 * - OSC32KCTRL_XOSC32K_ONDEMAND On Demand Control
 * - OSC32KCTRL_XOSC32K_STARTUP(value) Oscillator Start-Up Time
 * - OSC32KCTRL_XOSC32K_WRTLOCK Write Lock
 * - OSC32KCTRL_XOSC32K_CGM(value) Control Gain Mode
 *  +      OSC32KCTRL_XOSC32K_CGM_XT Standard mode
 *  +      OSC32KCTRL_XOSC32K_CGM_HS High Speed mode
 **/
static inline void osc32kctrl_set_XOSC32K(uint16_t mask)
{
	OSC32KCTRL->XOSC32K.reg |= mask;
}

/**
 * @brief osc32kctrl get XOSC32K register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - OSC32KCTRL_XOSC32K_ENABLE Oscillator Enable
 * - OSC32KCTRL_XOSC32K_XTALEN Crystal Oscillator Enable
 * - OSC32KCTRL_XOSC32K_EN32K 32kHz Output Enable
 * - OSC32KCTRL_XOSC32K_EN1K 1kHz Output Enable
 * - OSC32KCTRL_XOSC32K_RUNSTDBY Run in Standby
 * - OSC32KCTRL_XOSC32K_ONDEMAND On Demand Control
 * - OSC32KCTRL_XOSC32K_STARTUP(value) Oscillator Start-Up Time
 * - OSC32KCTRL_XOSC32K_WRTLOCK Write Lock
 * - OSC32KCTRL_XOSC32K_CGM(value) Control Gain Mode
 *  +      OSC32KCTRL_XOSC32K_CGM_XT Standard mode
 *  +      OSC32KCTRL_XOSC32K_CGM_HS High Speed mode
 **/
static inline uint16_t osc32kctrl_get_XOSC32K(uint16_t mask)
{
    return OSC32KCTRL->XOSC32K.reg & mask;
}

/**
 * @brief osc32kctrl write XOSC32K register
 *
 * @param[in] data uint16_t 
 * - OSC32KCTRL_XOSC32K_ENABLE Oscillator Enable
 * - OSC32KCTRL_XOSC32K_XTALEN Crystal Oscillator Enable
 * - OSC32KCTRL_XOSC32K_EN32K 32kHz Output Enable
 * - OSC32KCTRL_XOSC32K_EN1K 1kHz Output Enable
 * - OSC32KCTRL_XOSC32K_RUNSTDBY Run in Standby
 * - OSC32KCTRL_XOSC32K_ONDEMAND On Demand Control
 * - OSC32KCTRL_XOSC32K_STARTUP(value) Oscillator Start-Up Time
 * - OSC32KCTRL_XOSC32K_WRTLOCK Write Lock
 * - OSC32KCTRL_XOSC32K_CGM(value) Control Gain Mode
 *  +      OSC32KCTRL_XOSC32K_CGM_XT Standard mode
 *  +      OSC32KCTRL_XOSC32K_CGM_HS High Speed mode
 **/
static inline void osc32kctrl_write_XOSC32K(uint16_t data)
{
	OSC32KCTRL->XOSC32K.reg = data;
}

/**
 * @brief osc32kctrl clear XOSC32K register
 *
 * @param[in] mask uint16_t 
 * - OSC32KCTRL_XOSC32K_ENABLE Oscillator Enable
 * - OSC32KCTRL_XOSC32K_XTALEN Crystal Oscillator Enable
 * - OSC32KCTRL_XOSC32K_EN32K 32kHz Output Enable
 * - OSC32KCTRL_XOSC32K_EN1K 1kHz Output Enable
 * - OSC32KCTRL_XOSC32K_RUNSTDBY Run in Standby
 * - OSC32KCTRL_XOSC32K_ONDEMAND On Demand Control
 * - OSC32KCTRL_XOSC32K_STARTUP(value) Oscillator Start-Up Time
 * - OSC32KCTRL_XOSC32K_WRTLOCK Write Lock
 * - OSC32KCTRL_XOSC32K_CGM(value) Control Gain Mode
 *  +      OSC32KCTRL_XOSC32K_CGM_XT Standard mode
 *  +      OSC32KCTRL_XOSC32K_CGM_HS High Speed mode
 **/
static inline void osc32kctrl_clear_XOSC32K(uint16_t mask)
{
	OSC32KCTRL->XOSC32K.reg &= ~mask;
}

/**
 * @brief osc32kctrl read XOSC32K register
 *
 * @return uint16_t
 * - OSC32KCTRL_XOSC32K_ENABLE Oscillator Enable
 * - OSC32KCTRL_XOSC32K_XTALEN Crystal Oscillator Enable
 * - OSC32KCTRL_XOSC32K_EN32K 32kHz Output Enable
 * - OSC32KCTRL_XOSC32K_EN1K 1kHz Output Enable
 * - OSC32KCTRL_XOSC32K_RUNSTDBY Run in Standby
 * - OSC32KCTRL_XOSC32K_ONDEMAND On Demand Control
 * - OSC32KCTRL_XOSC32K_STARTUP(value) Oscillator Start-Up Time
 * - OSC32KCTRL_XOSC32K_WRTLOCK Write Lock
 * - OSC32KCTRL_XOSC32K_CGM(value) Control Gain Mode
 *  +      OSC32KCTRL_XOSC32K_CGM_XT Standard mode
 *  +      OSC32KCTRL_XOSC32K_CGM_HS High Speed mode
 **/
static inline uint16_t osc32kctrl_read_XOSC32K(void)
{
	return OSC32KCTRL->XOSC32K.reg;
}

/**
 * @brief osc32kctrl set CFDCTRL register
 *
 * @param[in] mask uint8_t 
 * - OSC32KCTRL_CFDCTRL_CFDEN Clock Failure Detector Enable
 * - OSC32KCTRL_CFDCTRL_SWBACK Clock Switch Back
 * - OSC32KCTRL_CFDCTRL_CFDPRESC Clock Failure Detector Prescaler
 **/
static inline void osc32kctrl_set_CFDCTRL(uint8_t mask)
{
	OSC32KCTRL->CFDCTRL.reg |= mask;
}

/**
 * @brief osc32kctrl get CFDCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - OSC32KCTRL_CFDCTRL_CFDEN Clock Failure Detector Enable
 * - OSC32KCTRL_CFDCTRL_SWBACK Clock Switch Back
 * - OSC32KCTRL_CFDCTRL_CFDPRESC Clock Failure Detector Prescaler
 **/
static inline uint8_t osc32kctrl_get_CFDCTRL(uint8_t mask)
{
    return OSC32KCTRL->CFDCTRL.reg & mask;
}

/**
 * @brief osc32kctrl write CFDCTRL register
 *
 * @param[in] data uint8_t 
 * - OSC32KCTRL_CFDCTRL_CFDEN Clock Failure Detector Enable
 * - OSC32KCTRL_CFDCTRL_SWBACK Clock Switch Back
 * - OSC32KCTRL_CFDCTRL_CFDPRESC Clock Failure Detector Prescaler
 **/
static inline void osc32kctrl_write_CFDCTRL(uint8_t data)
{
	OSC32KCTRL->CFDCTRL.reg = data;
}

/**
 * @brief osc32kctrl clear CFDCTRL register
 *
 * @param[in] mask uint8_t 
 * - OSC32KCTRL_CFDCTRL_CFDEN Clock Failure Detector Enable
 * - OSC32KCTRL_CFDCTRL_SWBACK Clock Switch Back
 * - OSC32KCTRL_CFDCTRL_CFDPRESC Clock Failure Detector Prescaler
 **/
static inline void osc32kctrl_clear_CFDCTRL(uint8_t mask)
{
	OSC32KCTRL->CFDCTRL.reg &= ~mask;
}

/**
 * @brief osc32kctrl read CFDCTRL register
 *
 * @return uint8_t
 * - OSC32KCTRL_CFDCTRL_CFDEN Clock Failure Detector Enable
 * - OSC32KCTRL_CFDCTRL_SWBACK Clock Switch Back
 * - OSC32KCTRL_CFDCTRL_CFDPRESC Clock Failure Detector Prescaler
 **/
static inline uint8_t osc32kctrl_read_CFDCTRL(void)
{
	return OSC32KCTRL->CFDCTRL.reg;
}

/**
 * @brief osc32kctrl set EVCTRL register
 *
 * @param[in] mask uint8_t 
 * - OSC32KCTRL_EVCTRL_CFDEO Clock Failure Detector Event Output Enable
 **/
static inline void osc32kctrl_set_EVCTRL(uint8_t mask)
{
	OSC32KCTRL->EVCTRL.reg |= mask;
}

/**
 * @brief osc32kctrl get EVCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - OSC32KCTRL_EVCTRL_CFDEO Clock Failure Detector Event Output Enable
 **/
static inline uint8_t osc32kctrl_get_EVCTRL(uint8_t mask)
{
    return OSC32KCTRL->EVCTRL.reg & mask;
}

/**
 * @brief osc32kctrl write EVCTRL register
 *
 * @param[in] data uint8_t 
 * - OSC32KCTRL_EVCTRL_CFDEO Clock Failure Detector Event Output Enable
 **/
static inline void osc32kctrl_write_EVCTRL(uint8_t data)
{
	OSC32KCTRL->EVCTRL.reg = data;
}

/**
 * @brief osc32kctrl clear EVCTRL register
 *
 * @param[in] mask uint8_t 
 * - OSC32KCTRL_EVCTRL_CFDEO Clock Failure Detector Event Output Enable
 **/
static inline void osc32kctrl_clear_EVCTRL(uint8_t mask)
{
	OSC32KCTRL->EVCTRL.reg &= ~mask;
}

/**
 * @brief osc32kctrl read EVCTRL register
 *
 * @return uint8_t
 * - OSC32KCTRL_EVCTRL_CFDEO Clock Failure Detector Event Output Enable
 **/
static inline uint8_t osc32kctrl_read_EVCTRL(void)
{
	return OSC32KCTRL->EVCTRL.reg;
}

/**
 * @brief osc32kctrl set OSCULP32K register
 *
 * @param[in] mask uint32_t 
 * - OSC32KCTRL_OSCULP32K_EN32K Enable Out 32k
 * - OSC32KCTRL_OSCULP32K_EN1K Enable Out 1k
 * - OSC32KCTRL_OSCULP32K_CALIB(value) Oscillator Calibration
 * - OSC32KCTRL_OSCULP32K_WRTLOCK Write Lock
 **/
static inline void osc32kctrl_set_OSCULP32K(uint32_t mask)
{
	OSC32KCTRL->OSCULP32K.reg |= mask;
}

/**
 * @brief osc32kctrl get OSCULP32K register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSC32KCTRL_OSCULP32K_EN32K Enable Out 32k
 * - OSC32KCTRL_OSCULP32K_EN1K Enable Out 1k
 * - OSC32KCTRL_OSCULP32K_CALIB(value) Oscillator Calibration
 * - OSC32KCTRL_OSCULP32K_WRTLOCK Write Lock
 **/
static inline uint32_t osc32kctrl_get_OSCULP32K(uint32_t mask)
{
    return OSC32KCTRL->OSCULP32K.reg & mask;
}

/**
 * @brief osc32kctrl write OSCULP32K register
 *
 * @param[in] data uint32_t 
 * - OSC32KCTRL_OSCULP32K_EN32K Enable Out 32k
 * - OSC32KCTRL_OSCULP32K_EN1K Enable Out 1k
 * - OSC32KCTRL_OSCULP32K_CALIB(value) Oscillator Calibration
 * - OSC32KCTRL_OSCULP32K_WRTLOCK Write Lock
 **/
static inline void osc32kctrl_write_OSCULP32K(uint32_t data)
{
	OSC32KCTRL->OSCULP32K.reg = data;
}

/**
 * @brief osc32kctrl clear OSCULP32K register
 *
 * @param[in] mask uint32_t 
 * - OSC32KCTRL_OSCULP32K_EN32K Enable Out 32k
 * - OSC32KCTRL_OSCULP32K_EN1K Enable Out 1k
 * - OSC32KCTRL_OSCULP32K_CALIB(value) Oscillator Calibration
 * - OSC32KCTRL_OSCULP32K_WRTLOCK Write Lock
 **/
static inline void osc32kctrl_clear_OSCULP32K(uint32_t mask)
{
	OSC32KCTRL->OSCULP32K.reg &= ~mask;
}

/**
 * @brief osc32kctrl read OSCULP32K register
 *
 * @return uint32_t
 * - OSC32KCTRL_OSCULP32K_EN32K Enable Out 32k
 * - OSC32KCTRL_OSCULP32K_EN1K Enable Out 1k
 * - OSC32KCTRL_OSCULP32K_CALIB(value) Oscillator Calibration
 * - OSC32KCTRL_OSCULP32K_WRTLOCK Write Lock
 **/
static inline uint32_t osc32kctrl_read_OSCULP32K(void)
{
	return OSC32KCTRL->OSCULP32K.reg;
}

/**
 * @brief osc32kctrl get STATUS register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSC32KCTRL_STATUS_XOSC32KRDY XOSC32K Ready
 * - OSC32KCTRL_STATUS_XOSC32KFAIL XOSC32K Clock Failure Detector
 * - OSC32KCTRL_STATUS_XOSC32KSW XOSC32K Clock switch
 **/
static inline uint32_t osc32kctrl_get_STATUS(uint32_t mask)
{
    return OSC32KCTRL->STATUS.reg & mask;
}

/**
 * @brief osc32kctrl read STATUS register
 *
 * @return uint32_t
 * - OSC32KCTRL_STATUS_XOSC32KRDY XOSC32K Ready
 * - OSC32KCTRL_STATUS_XOSC32KFAIL XOSC32K Clock Failure Detector
 * - OSC32KCTRL_STATUS_XOSC32KSW XOSC32K Clock switch
 **/
static inline uint32_t osc32kctrl_read_STATUS(void)
{
	return OSC32KCTRL->STATUS.reg;
}

#endif /* _OSC32KCTRL_H */
