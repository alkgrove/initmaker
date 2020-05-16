/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file ac.h
 *
 * \brief SAM AC
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

#ifndef _AC_H_
#define _AC_H_

#include <stdbool.h>

/**
 * @brief ac wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void ac_wait_for_sync(uint32_t reg)
{
	while (AC->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief ac is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool ac_is_syncing(uint32_t reg)
{
	return AC->SYNCBUSY.reg & reg;
}

/**
 * @brief ac set INTEN register
 *
 * @param[in] mask uint8_t 
 * - AC_INTENSET_COMP0 Comparator 0 Interrupt Enable
 * - AC_INTENSET_COMP1 Comparator 1 Interrupt Enable
 * - AC_INTENSET_COMP(value) Comparator x Interrupt Enable
 * - AC_INTENSET_WIN0 Window 0 Interrupt Enable
 * - AC_INTENSET_WIN(value) Window x Interrupt Enable
 **/
static inline void ac_set_INTEN(uint8_t mask)
{
	AC->INTENSET.reg = mask;
}

/**
 * @brief ac get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AC_INTENSET_COMP0 Comparator 0 Interrupt Enable
 * - AC_INTENSET_COMP1 Comparator 1 Interrupt Enable
 * - AC_INTENSET_COMP(value) Comparator x Interrupt Enable
 * - AC_INTENSET_WIN0 Window 0 Interrupt Enable
 * - AC_INTENSET_WIN(value) Window x Interrupt Enable
 **/
static inline uint8_t ac_get_INTEN(uint8_t mask)
{
    return AC->INTENSET.reg & mask;
}

/**
 * @brief ac read INTEN register
 *
 * @return uint8_t
 * - AC_INTENSET_COMP0 Comparator 0 Interrupt Enable
 * - AC_INTENSET_COMP1 Comparator 1 Interrupt Enable
 * - AC_INTENSET_COMP(value) Comparator x Interrupt Enable
 * - AC_INTENSET_WIN0 Window 0 Interrupt Enable
 * - AC_INTENSET_WIN(value) Window x Interrupt Enable
 **/
static inline uint8_t ac_read_INTEN(void)
{
	return AC->INTENSET.reg;
}

/**
 * @brief ac write INTEN register
 *
 * @param[in] data uint8_t 
 * - AC_INTENSET_COMP0 Comparator 0 Interrupt Enable
 * - AC_INTENSET_COMP1 Comparator 1 Interrupt Enable
 * - AC_INTENSET_COMP(value) Comparator x Interrupt Enable
 * - AC_INTENSET_WIN0 Window 0 Interrupt Enable
 * - AC_INTENSET_WIN(value) Window x Interrupt Enable
 **/
static inline void ac_write_INTEN(uint8_t data)
{
	AC->INTENSET.reg = data;
	AC->INTENCLR.reg = ~data;
}

/**
 * @brief ac clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - AC_INTENSET_COMP0 Comparator 0 Interrupt Enable
 * - AC_INTENSET_COMP1 Comparator 1 Interrupt Enable
 * - AC_INTENSET_COMP(value) Comparator x Interrupt Enable
 * - AC_INTENSET_WIN0 Window 0 Interrupt Enable
 * - AC_INTENSET_WIN(value) Window x Interrupt Enable
 **/
static inline void ac_clear_INTEN(uint8_t mask)
{
	AC->INTENCLR.reg = mask;
}

/**
 * @brief ac get INTFLAG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AC_INTFLAG_COMP0 Comparator 0
 * - AC_INTFLAG_COMP1 Comparator 1
 * - AC_INTFLAG_COMP(value) Comparator x
 * - AC_INTFLAG_WIN0 Window 0
 * - AC_INTFLAG_WIN(value) Window x
 **/
static inline uint8_t ac_get_INTFLAG(uint8_t mask)
{
    return AC->INTFLAG.reg & mask;
}

/**
 * @brief ac read INTFLAG register
 *
 * @return uint8_t
 * - AC_INTFLAG_COMP0 Comparator 0
 * - AC_INTFLAG_COMP1 Comparator 1
 * - AC_INTFLAG_COMP(value) Comparator x
 * - AC_INTFLAG_WIN0 Window 0
 * - AC_INTFLAG_WIN(value) Window x
 **/
static inline uint8_t ac_read_INTFLAG(void)
{
	return AC->INTFLAG.reg;
}

/**
 * @brief ac clear INTFLAG register
 *
 * @param[in] mask uint8_t 
 * - AC_INTFLAG_COMP0 Comparator 0
 * - AC_INTFLAG_COMP1 Comparator 1
 * - AC_INTFLAG_COMP(value) Comparator x
 * - AC_INTFLAG_WIN0 Window 0
 * - AC_INTFLAG_WIN(value) Window x
 **/
static inline void ac_clear_INTFLAG(uint8_t mask)
{
	AC->INTFLAG.reg = mask;
}

/**
 * @brief ac write CTRLB register
 *
 * @param[in] data uint8_t 
 * - AC_CTRLB_START0 Comparator 0 Start Comparison
 * - AC_CTRLB_START1 Comparator 1 Start Comparison
 * - AC_CTRLB_START(value) Comparator x Start Comparison
 **/
static inline void ac_write_CTRLB(uint8_t data)
{
	AC->CTRLB.reg = data;
}

/**
 * @brief ac set CTRLA register
 *
 * @param[in] mask uint8_t 
 * - AC_CTRLA_SWRST Software Reset
 * - AC_CTRLA_ENABLE Enable
 **/
static inline void ac_set_CTRLA(uint8_t mask)
{
	AC->CTRLA.reg |= mask;
}

/**
 * @brief ac get CTRLA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AC_CTRLA_SWRST Software Reset
 * - AC_CTRLA_ENABLE Enable
 **/
static inline uint8_t ac_get_CTRLA(uint8_t mask)
{
    return AC->CTRLA.reg & mask;
}

/**
 * @brief ac write CTRLA register
 *
 * @param[in] data uint8_t 
 * - AC_CTRLA_SWRST Software Reset
 * - AC_CTRLA_ENABLE Enable
 **/
static inline void ac_write_CTRLA(uint8_t data)
{
	AC->CTRLA.reg = data;
}

/**
 * @brief ac clear CTRLA register
 *
 * @param[in] mask uint8_t 
 * - AC_CTRLA_SWRST Software Reset
 * - AC_CTRLA_ENABLE Enable
 **/
static inline void ac_clear_CTRLA(uint8_t mask)
{
	AC->CTRLA.reg &= ~mask;
}

/**
 * @brief ac read CTRLA register
 *
 * @return uint8_t
 * - AC_CTRLA_SWRST Software Reset
 * - AC_CTRLA_ENABLE Enable
 **/
static inline uint8_t ac_read_CTRLA(void)
{
	return AC->CTRLA.reg;
}

/**
 * @brief ac set EVCTRL register
 *
 * @param[in] mask uint16_t 
 * - AC_EVCTRL_COMPEO0 Comparator 0 Event Output Enable
 * - AC_EVCTRL_COMPEO1 Comparator 1 Event Output Enable
 * - AC_EVCTRL_COMPEO(value) Comparator x Event Output Enable
 * - AC_EVCTRL_WINEO0 Window 0 Event Output Enable
 * - AC_EVCTRL_WINEO(value) Window x Event Output Enable
 * - AC_EVCTRL_COMPEI0 Comparator 0 Event Input Enable
 * - AC_EVCTRL_COMPEI1 Comparator 1 Event Input Enable
 * - AC_EVCTRL_COMPEI(value) Comparator x Event Input Enable
 * - AC_EVCTRL_INVEI0 Comparator 0 Input Event Invert Enable
 * - AC_EVCTRL_INVEI1 Comparator 1 Input Event Invert Enable
 * - AC_EVCTRL_INVEI(value) Comparator x Input Event Invert Enable
 **/
static inline void ac_set_EVCTRL(uint16_t mask)
{
	AC->EVCTRL.reg |= mask;
}

/**
 * @brief ac get EVCTRL register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - AC_EVCTRL_COMPEO0 Comparator 0 Event Output Enable
 * - AC_EVCTRL_COMPEO1 Comparator 1 Event Output Enable
 * - AC_EVCTRL_COMPEO(value) Comparator x Event Output Enable
 * - AC_EVCTRL_WINEO0 Window 0 Event Output Enable
 * - AC_EVCTRL_WINEO(value) Window x Event Output Enable
 * - AC_EVCTRL_COMPEI0 Comparator 0 Event Input Enable
 * - AC_EVCTRL_COMPEI1 Comparator 1 Event Input Enable
 * - AC_EVCTRL_COMPEI(value) Comparator x Event Input Enable
 * - AC_EVCTRL_INVEI0 Comparator 0 Input Event Invert Enable
 * - AC_EVCTRL_INVEI1 Comparator 1 Input Event Invert Enable
 * - AC_EVCTRL_INVEI(value) Comparator x Input Event Invert Enable
 **/
static inline uint16_t ac_get_EVCTRL(uint16_t mask)
{
    return AC->EVCTRL.reg & mask;
}

/**
 * @brief ac write EVCTRL register
 *
 * @param[in] data uint16_t 
 * - AC_EVCTRL_COMPEO0 Comparator 0 Event Output Enable
 * - AC_EVCTRL_COMPEO1 Comparator 1 Event Output Enable
 * - AC_EVCTRL_COMPEO(value) Comparator x Event Output Enable
 * - AC_EVCTRL_WINEO0 Window 0 Event Output Enable
 * - AC_EVCTRL_WINEO(value) Window x Event Output Enable
 * - AC_EVCTRL_COMPEI0 Comparator 0 Event Input Enable
 * - AC_EVCTRL_COMPEI1 Comparator 1 Event Input Enable
 * - AC_EVCTRL_COMPEI(value) Comparator x Event Input Enable
 * - AC_EVCTRL_INVEI0 Comparator 0 Input Event Invert Enable
 * - AC_EVCTRL_INVEI1 Comparator 1 Input Event Invert Enable
 * - AC_EVCTRL_INVEI(value) Comparator x Input Event Invert Enable
 **/
static inline void ac_write_EVCTRL(uint16_t data)
{
	AC->EVCTRL.reg = data;
}

/**
 * @brief ac clear EVCTRL register
 *
 * @param[in] mask uint16_t 
 * - AC_EVCTRL_COMPEO0 Comparator 0 Event Output Enable
 * - AC_EVCTRL_COMPEO1 Comparator 1 Event Output Enable
 * - AC_EVCTRL_COMPEO(value) Comparator x Event Output Enable
 * - AC_EVCTRL_WINEO0 Window 0 Event Output Enable
 * - AC_EVCTRL_WINEO(value) Window x Event Output Enable
 * - AC_EVCTRL_COMPEI0 Comparator 0 Event Input Enable
 * - AC_EVCTRL_COMPEI1 Comparator 1 Event Input Enable
 * - AC_EVCTRL_COMPEI(value) Comparator x Event Input Enable
 * - AC_EVCTRL_INVEI0 Comparator 0 Input Event Invert Enable
 * - AC_EVCTRL_INVEI1 Comparator 1 Input Event Invert Enable
 * - AC_EVCTRL_INVEI(value) Comparator x Input Event Invert Enable
 **/
static inline void ac_clear_EVCTRL(uint16_t mask)
{
	AC->EVCTRL.reg &= ~mask;
}

/**
 * @brief ac read EVCTRL register
 *
 * @return uint16_t
 * - AC_EVCTRL_COMPEO0 Comparator 0 Event Output Enable
 * - AC_EVCTRL_COMPEO1 Comparator 1 Event Output Enable
 * - AC_EVCTRL_COMPEO(value) Comparator x Event Output Enable
 * - AC_EVCTRL_WINEO0 Window 0 Event Output Enable
 * - AC_EVCTRL_WINEO(value) Window x Event Output Enable
 * - AC_EVCTRL_COMPEI0 Comparator 0 Event Input Enable
 * - AC_EVCTRL_COMPEI1 Comparator 1 Event Input Enable
 * - AC_EVCTRL_COMPEI(value) Comparator x Event Input Enable
 * - AC_EVCTRL_INVEI0 Comparator 0 Input Event Invert Enable
 * - AC_EVCTRL_INVEI1 Comparator 1 Input Event Invert Enable
 * - AC_EVCTRL_INVEI(value) Comparator x Input Event Invert Enable
 **/
static inline uint16_t ac_read_EVCTRL(void)
{
	return AC->EVCTRL.reg;
}

/**
 * @brief ac set DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - AC_DBGCTRL_DBGRUN Debug Run
 **/
static inline void ac_set_DBGCTRL(uint8_t mask)
{
	AC->DBGCTRL.reg |= mask;
}

/**
 * @brief ac get DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AC_DBGCTRL_DBGRUN Debug Run
 **/
static inline uint8_t ac_get_DBGCTRL(uint8_t mask)
{
    return AC->DBGCTRL.reg & mask;
}

/**
 * @brief ac write DBGCTRL register
 *
 * @param[in] data uint8_t 
 * - AC_DBGCTRL_DBGRUN Debug Run
 **/
static inline void ac_write_DBGCTRL(uint8_t data)
{
	AC->DBGCTRL.reg = data;
}

/**
 * @brief ac clear DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - AC_DBGCTRL_DBGRUN Debug Run
 **/
static inline void ac_clear_DBGCTRL(uint8_t mask)
{
	AC->DBGCTRL.reg &= ~mask;
}

/**
 * @brief ac read DBGCTRL register
 *
 * @return uint8_t
 * - AC_DBGCTRL_DBGRUN Debug Run
 **/
static inline uint8_t ac_read_DBGCTRL(void)
{
	return AC->DBGCTRL.reg;
}

/**
 * @brief ac set WINCTRL register
 *
 * @param[in] mask uint8_t 
 * - AC_WINCTRL_WEN0 Window 0 Mode Enable
 * - AC_WINCTRL_WINTSEL0(value) Window 0 Interrupt Selection
 *  +      AC_WINCTRL_WINTSEL0_ABOVE Interrupt on signal above window
 *  +      AC_WINCTRL_WINTSEL0_INSIDE Interrupt on signal inside window
 *  +      AC_WINCTRL_WINTSEL0_BELOW Interrupt on signal below window
 *  +      AC_WINCTRL_WINTSEL0_OUTSIDE Interrupt on signal outside window
 **/
static inline void ac_set_WINCTRL(uint8_t mask)
{
	AC->WINCTRL.reg |= mask;
}

/**
 * @brief ac get WINCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AC_WINCTRL_WEN0 Window 0 Mode Enable
 * - AC_WINCTRL_WINTSEL0(value) Window 0 Interrupt Selection
 *  +      AC_WINCTRL_WINTSEL0_ABOVE Interrupt on signal above window
 *  +      AC_WINCTRL_WINTSEL0_INSIDE Interrupt on signal inside window
 *  +      AC_WINCTRL_WINTSEL0_BELOW Interrupt on signal below window
 *  +      AC_WINCTRL_WINTSEL0_OUTSIDE Interrupt on signal outside window
 **/
static inline uint8_t ac_get_WINCTRL(uint8_t mask)
{
    return AC->WINCTRL.reg & mask;
}

/**
 * @brief ac write WINCTRL register
 *
 * @param[in] data uint8_t 
 * - AC_WINCTRL_WEN0 Window 0 Mode Enable
 * - AC_WINCTRL_WINTSEL0(value) Window 0 Interrupt Selection
 *  +      AC_WINCTRL_WINTSEL0_ABOVE Interrupt on signal above window
 *  +      AC_WINCTRL_WINTSEL0_INSIDE Interrupt on signal inside window
 *  +      AC_WINCTRL_WINTSEL0_BELOW Interrupt on signal below window
 *  +      AC_WINCTRL_WINTSEL0_OUTSIDE Interrupt on signal outside window
 **/
static inline void ac_write_WINCTRL(uint8_t data)
{
	AC->WINCTRL.reg = data;
}

/**
 * @brief ac clear WINCTRL register
 *
 * @param[in] mask uint8_t 
 * - AC_WINCTRL_WEN0 Window 0 Mode Enable
 * - AC_WINCTRL_WINTSEL0(value) Window 0 Interrupt Selection
 *  +      AC_WINCTRL_WINTSEL0_ABOVE Interrupt on signal above window
 *  +      AC_WINCTRL_WINTSEL0_INSIDE Interrupt on signal inside window
 *  +      AC_WINCTRL_WINTSEL0_BELOW Interrupt on signal below window
 *  +      AC_WINCTRL_WINTSEL0_OUTSIDE Interrupt on signal outside window
 **/
static inline void ac_clear_WINCTRL(uint8_t mask)
{
	AC->WINCTRL.reg &= ~mask;
}

/**
 * @brief ac read WINCTRL register
 *
 * @return uint8_t
 * - AC_WINCTRL_WEN0 Window 0 Mode Enable
 * - AC_WINCTRL_WINTSEL0(value) Window 0 Interrupt Selection
 *  +      AC_WINCTRL_WINTSEL0_ABOVE Interrupt on signal above window
 *  +      AC_WINCTRL_WINTSEL0_INSIDE Interrupt on signal inside window
 *  +      AC_WINCTRL_WINTSEL0_BELOW Interrupt on signal below window
 *  +      AC_WINCTRL_WINTSEL0_OUTSIDE Interrupt on signal outside window
 **/
static inline uint8_t ac_read_WINCTRL(void)
{
	return AC->WINCTRL.reg;
}

/**
 * @brief ac set SCALER register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint8_t 
 * - AC_SCALER_VALUE(value) Scaler Value
 **/
static inline void ac_set_SCALER(uint8_t index, uint8_t mask)
{
	AC->SCALER[index].reg |= mask;
}

/**
 * @brief ac get SCALER register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AC_SCALER_VALUE(value) Scaler Value
 **/
static inline uint8_t ac_get_SCALER(uint8_t index, uint8_t mask)
{
    return AC->SCALER[index].reg & mask;
}

/**
 * @brief ac write SCALER register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint8_t 
 * - AC_SCALER_VALUE(value) Scaler Value
 **/
static inline void ac_write_SCALER(uint8_t index, uint8_t data)
{
	AC->SCALER[index].reg = data;
}

/**
 * @brief ac clear SCALER register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint8_t 
 * - AC_SCALER_VALUE(value) Scaler Value
 **/
static inline void ac_clear_SCALER(uint8_t index, uint8_t mask)
{
	AC->SCALER[index].reg &= ~mask;
}

/**
 * @brief ac read SCALER register
 *
 * @param[in] index uint8_t 
 * @return uint8_t
 * - AC_SCALER_VALUE(value) Scaler Value
 **/
static inline uint8_t ac_read_SCALER(uint8_t index)
{
	return AC->SCALER[index].reg;
}

/**
 * @brief ac set COMPCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - AC_COMPCTRL_ENABLE Enable
 * - AC_COMPCTRL_SINGLE Single-Shot Mode
 * - AC_COMPCTRL_INTSEL(value) Interrupt Selection
 *  +      AC_COMPCTRL_INTSEL_TOGGLE Interrupt on comparator output toggle
 *  +      AC_COMPCTRL_INTSEL_RISING Interrupt on comparator output rising
 *  +      AC_COMPCTRL_INTSEL_FALLING Interrupt on comparator output falling
 *  +      AC_COMPCTRL_INTSEL_EOC Interrupt on end of comparison (single-shot mode only)
 * - AC_COMPCTRL_RUNSTDBY Run in Standby
 * - AC_COMPCTRL_MUXNEG(value) Negative Input Mux Selection
 *  +      AC_COMPCTRL_MUXNEG_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXNEG_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXNEG_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXNEG_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXNEG_GND Ground
 *  +      AC_COMPCTRL_MUXNEG_VSCALE VDD scaler
 *  +      AC_COMPCTRL_MUXNEG_BANDGAP Internal bandgap voltage
 *  +      AC_COMPCTRL_MUXNEG_DAC DAC output
 * - AC_COMPCTRL_MUXPOS(value) Positive Input Mux Selection
 *  +      AC_COMPCTRL_MUXPOS_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXPOS_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXPOS_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXPOS_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXPOS_VSCALE VDD Scaler
 * - AC_COMPCTRL_SWAP Swap Inputs and Invert
 * - AC_COMPCTRL_SPEED(value) Speed Selection
 *  +      AC_COMPCTRL_SPEED_HIGH High speed
 * - AC_COMPCTRL_HYSTEN Hysteresis Enable
 * - AC_COMPCTRL_HYST(value) Hysteresis Level
 *  +      AC_COMPCTRL_HYST_HYST50 50mV
 *  +      AC_COMPCTRL_HYST_HYST100 100mV
 *  +      AC_COMPCTRL_HYST_HYST150 150mV
 * - AC_COMPCTRL_FLEN(value) Filter Length
 *  +      AC_COMPCTRL_FLEN_OFF No filtering
 *  +      AC_COMPCTRL_FLEN_MAJ3 3-bit majority function (2 of 3)
 *  +      AC_COMPCTRL_FLEN_MAJ5 5-bit majority function (3 of 5)
 * - AC_COMPCTRL_OUT(value) Output
 *  +      AC_COMPCTRL_OUT_OFF The output of COMPn is not routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_ASYNC The asynchronous output of COMPn is routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_SYNC The synchronous output (including filtering) of COMPn is routed to the COMPn I/O port
 **/
static inline void ac_set_COMPCTRL(uint8_t index, uint32_t mask)
{
	AC->COMPCTRL[index].reg |= mask;
}

/**
 * @brief ac get COMPCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - AC_COMPCTRL_ENABLE Enable
 * - AC_COMPCTRL_SINGLE Single-Shot Mode
 * - AC_COMPCTRL_INTSEL(value) Interrupt Selection
 *  +      AC_COMPCTRL_INTSEL_TOGGLE Interrupt on comparator output toggle
 *  +      AC_COMPCTRL_INTSEL_RISING Interrupt on comparator output rising
 *  +      AC_COMPCTRL_INTSEL_FALLING Interrupt on comparator output falling
 *  +      AC_COMPCTRL_INTSEL_EOC Interrupt on end of comparison (single-shot mode only)
 * - AC_COMPCTRL_RUNSTDBY Run in Standby
 * - AC_COMPCTRL_MUXNEG(value) Negative Input Mux Selection
 *  +      AC_COMPCTRL_MUXNEG_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXNEG_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXNEG_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXNEG_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXNEG_GND Ground
 *  +      AC_COMPCTRL_MUXNEG_VSCALE VDD scaler
 *  +      AC_COMPCTRL_MUXNEG_BANDGAP Internal bandgap voltage
 *  +      AC_COMPCTRL_MUXNEG_DAC DAC output
 * - AC_COMPCTRL_MUXPOS(value) Positive Input Mux Selection
 *  +      AC_COMPCTRL_MUXPOS_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXPOS_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXPOS_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXPOS_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXPOS_VSCALE VDD Scaler
 * - AC_COMPCTRL_SWAP Swap Inputs and Invert
 * - AC_COMPCTRL_SPEED(value) Speed Selection
 *  +      AC_COMPCTRL_SPEED_HIGH High speed
 * - AC_COMPCTRL_HYSTEN Hysteresis Enable
 * - AC_COMPCTRL_HYST(value) Hysteresis Level
 *  +      AC_COMPCTRL_HYST_HYST50 50mV
 *  +      AC_COMPCTRL_HYST_HYST100 100mV
 *  +      AC_COMPCTRL_HYST_HYST150 150mV
 * - AC_COMPCTRL_FLEN(value) Filter Length
 *  +      AC_COMPCTRL_FLEN_OFF No filtering
 *  +      AC_COMPCTRL_FLEN_MAJ3 3-bit majority function (2 of 3)
 *  +      AC_COMPCTRL_FLEN_MAJ5 5-bit majority function (3 of 5)
 * - AC_COMPCTRL_OUT(value) Output
 *  +      AC_COMPCTRL_OUT_OFF The output of COMPn is not routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_ASYNC The asynchronous output of COMPn is routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_SYNC The synchronous output (including filtering) of COMPn is routed to the COMPn I/O port
 **/
static inline uint32_t ac_get_COMPCTRL(uint8_t index, uint32_t mask)
{
    return AC->COMPCTRL[index].reg & mask;
}

/**
 * @brief ac write COMPCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - AC_COMPCTRL_ENABLE Enable
 * - AC_COMPCTRL_SINGLE Single-Shot Mode
 * - AC_COMPCTRL_INTSEL(value) Interrupt Selection
 *  +      AC_COMPCTRL_INTSEL_TOGGLE Interrupt on comparator output toggle
 *  +      AC_COMPCTRL_INTSEL_RISING Interrupt on comparator output rising
 *  +      AC_COMPCTRL_INTSEL_FALLING Interrupt on comparator output falling
 *  +      AC_COMPCTRL_INTSEL_EOC Interrupt on end of comparison (single-shot mode only)
 * - AC_COMPCTRL_RUNSTDBY Run in Standby
 * - AC_COMPCTRL_MUXNEG(value) Negative Input Mux Selection
 *  +      AC_COMPCTRL_MUXNEG_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXNEG_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXNEG_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXNEG_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXNEG_GND Ground
 *  +      AC_COMPCTRL_MUXNEG_VSCALE VDD scaler
 *  +      AC_COMPCTRL_MUXNEG_BANDGAP Internal bandgap voltage
 *  +      AC_COMPCTRL_MUXNEG_DAC DAC output
 * - AC_COMPCTRL_MUXPOS(value) Positive Input Mux Selection
 *  +      AC_COMPCTRL_MUXPOS_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXPOS_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXPOS_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXPOS_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXPOS_VSCALE VDD Scaler
 * - AC_COMPCTRL_SWAP Swap Inputs and Invert
 * - AC_COMPCTRL_SPEED(value) Speed Selection
 *  +      AC_COMPCTRL_SPEED_HIGH High speed
 * - AC_COMPCTRL_HYSTEN Hysteresis Enable
 * - AC_COMPCTRL_HYST(value) Hysteresis Level
 *  +      AC_COMPCTRL_HYST_HYST50 50mV
 *  +      AC_COMPCTRL_HYST_HYST100 100mV
 *  +      AC_COMPCTRL_HYST_HYST150 150mV
 * - AC_COMPCTRL_FLEN(value) Filter Length
 *  +      AC_COMPCTRL_FLEN_OFF No filtering
 *  +      AC_COMPCTRL_FLEN_MAJ3 3-bit majority function (2 of 3)
 *  +      AC_COMPCTRL_FLEN_MAJ5 5-bit majority function (3 of 5)
 * - AC_COMPCTRL_OUT(value) Output
 *  +      AC_COMPCTRL_OUT_OFF The output of COMPn is not routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_ASYNC The asynchronous output of COMPn is routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_SYNC The synchronous output (including filtering) of COMPn is routed to the COMPn I/O port
 **/
static inline void ac_write_COMPCTRL(uint8_t index, uint32_t data)
{
	AC->COMPCTRL[index].reg = data;
}

/**
 * @brief ac clear COMPCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - AC_COMPCTRL_ENABLE Enable
 * - AC_COMPCTRL_SINGLE Single-Shot Mode
 * - AC_COMPCTRL_INTSEL(value) Interrupt Selection
 *  +      AC_COMPCTRL_INTSEL_TOGGLE Interrupt on comparator output toggle
 *  +      AC_COMPCTRL_INTSEL_RISING Interrupt on comparator output rising
 *  +      AC_COMPCTRL_INTSEL_FALLING Interrupt on comparator output falling
 *  +      AC_COMPCTRL_INTSEL_EOC Interrupt on end of comparison (single-shot mode only)
 * - AC_COMPCTRL_RUNSTDBY Run in Standby
 * - AC_COMPCTRL_MUXNEG(value) Negative Input Mux Selection
 *  +      AC_COMPCTRL_MUXNEG_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXNEG_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXNEG_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXNEG_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXNEG_GND Ground
 *  +      AC_COMPCTRL_MUXNEG_VSCALE VDD scaler
 *  +      AC_COMPCTRL_MUXNEG_BANDGAP Internal bandgap voltage
 *  +      AC_COMPCTRL_MUXNEG_DAC DAC output
 * - AC_COMPCTRL_MUXPOS(value) Positive Input Mux Selection
 *  +      AC_COMPCTRL_MUXPOS_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXPOS_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXPOS_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXPOS_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXPOS_VSCALE VDD Scaler
 * - AC_COMPCTRL_SWAP Swap Inputs and Invert
 * - AC_COMPCTRL_SPEED(value) Speed Selection
 *  +      AC_COMPCTRL_SPEED_HIGH High speed
 * - AC_COMPCTRL_HYSTEN Hysteresis Enable
 * - AC_COMPCTRL_HYST(value) Hysteresis Level
 *  +      AC_COMPCTRL_HYST_HYST50 50mV
 *  +      AC_COMPCTRL_HYST_HYST100 100mV
 *  +      AC_COMPCTRL_HYST_HYST150 150mV
 * - AC_COMPCTRL_FLEN(value) Filter Length
 *  +      AC_COMPCTRL_FLEN_OFF No filtering
 *  +      AC_COMPCTRL_FLEN_MAJ3 3-bit majority function (2 of 3)
 *  +      AC_COMPCTRL_FLEN_MAJ5 5-bit majority function (3 of 5)
 * - AC_COMPCTRL_OUT(value) Output
 *  +      AC_COMPCTRL_OUT_OFF The output of COMPn is not routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_ASYNC The asynchronous output of COMPn is routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_SYNC The synchronous output (including filtering) of COMPn is routed to the COMPn I/O port
 **/
static inline void ac_clear_COMPCTRL(uint8_t index, uint32_t mask)
{
	AC->COMPCTRL[index].reg &= ~mask;
}

/**
 * @brief ac read COMPCTRL register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - AC_COMPCTRL_ENABLE Enable
 * - AC_COMPCTRL_SINGLE Single-Shot Mode
 * - AC_COMPCTRL_INTSEL(value) Interrupt Selection
 *  +      AC_COMPCTRL_INTSEL_TOGGLE Interrupt on comparator output toggle
 *  +      AC_COMPCTRL_INTSEL_RISING Interrupt on comparator output rising
 *  +      AC_COMPCTRL_INTSEL_FALLING Interrupt on comparator output falling
 *  +      AC_COMPCTRL_INTSEL_EOC Interrupt on end of comparison (single-shot mode only)
 * - AC_COMPCTRL_RUNSTDBY Run in Standby
 * - AC_COMPCTRL_MUXNEG(value) Negative Input Mux Selection
 *  +      AC_COMPCTRL_MUXNEG_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXNEG_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXNEG_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXNEG_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXNEG_GND Ground
 *  +      AC_COMPCTRL_MUXNEG_VSCALE VDD scaler
 *  +      AC_COMPCTRL_MUXNEG_BANDGAP Internal bandgap voltage
 *  +      AC_COMPCTRL_MUXNEG_DAC DAC output
 * - AC_COMPCTRL_MUXPOS(value) Positive Input Mux Selection
 *  +      AC_COMPCTRL_MUXPOS_PIN0 I/O pin 0
 *  +      AC_COMPCTRL_MUXPOS_PIN1 I/O pin 1
 *  +      AC_COMPCTRL_MUXPOS_PIN2 I/O pin 2
 *  +      AC_COMPCTRL_MUXPOS_PIN3 I/O pin 3
 *  +      AC_COMPCTRL_MUXPOS_VSCALE VDD Scaler
 * - AC_COMPCTRL_SWAP Swap Inputs and Invert
 * - AC_COMPCTRL_SPEED(value) Speed Selection
 *  +      AC_COMPCTRL_SPEED_HIGH High speed
 * - AC_COMPCTRL_HYSTEN Hysteresis Enable
 * - AC_COMPCTRL_HYST(value) Hysteresis Level
 *  +      AC_COMPCTRL_HYST_HYST50 50mV
 *  +      AC_COMPCTRL_HYST_HYST100 100mV
 *  +      AC_COMPCTRL_HYST_HYST150 150mV
 * - AC_COMPCTRL_FLEN(value) Filter Length
 *  +      AC_COMPCTRL_FLEN_OFF No filtering
 *  +      AC_COMPCTRL_FLEN_MAJ3 3-bit majority function (2 of 3)
 *  +      AC_COMPCTRL_FLEN_MAJ5 5-bit majority function (3 of 5)
 * - AC_COMPCTRL_OUT(value) Output
 *  +      AC_COMPCTRL_OUT_OFF The output of COMPn is not routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_ASYNC The asynchronous output of COMPn is routed to the COMPn I/O port
 *  +      AC_COMPCTRL_OUT_SYNC The synchronous output (including filtering) of COMPn is routed to the COMPn I/O port
 **/
static inline uint32_t ac_read_COMPCTRL(uint8_t index)
{
	return AC->COMPCTRL[index].reg;
}

/**
 * @brief ac set CALIB register
 *
 * @param[in] mask uint16_t 
 * - AC_CALIB_BIAS0(value) COMP0/1 Bias Scaling
 **/
static inline void ac_set_CALIB(uint16_t mask)
{
	AC->CALIB.reg |= mask;
}

/**
 * @brief ac get CALIB register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - AC_CALIB_BIAS0(value) COMP0/1 Bias Scaling
 **/
static inline uint16_t ac_get_CALIB(uint16_t mask)
{
    return AC->CALIB.reg & mask;
}

/**
 * @brief ac write CALIB register
 *
 * @param[in] data uint16_t 
 * - AC_CALIB_BIAS0(value) COMP0/1 Bias Scaling
 **/
static inline void ac_write_CALIB(uint16_t data)
{
	AC->CALIB.reg = data;
}

/**
 * @brief ac clear CALIB register
 *
 * @param[in] mask uint16_t 
 * - AC_CALIB_BIAS0(value) COMP0/1 Bias Scaling
 **/
static inline void ac_clear_CALIB(uint16_t mask)
{
	AC->CALIB.reg &= ~mask;
}

/**
 * @brief ac read CALIB register
 *
 * @return uint16_t
 * - AC_CALIB_BIAS0(value) COMP0/1 Bias Scaling
 **/
static inline uint16_t ac_read_CALIB(void)
{
	return AC->CALIB.reg;
}

/**
 * @brief ac get STATUSA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AC_STATUSA_STATE0 Comparator 0 Current State
 * - AC_STATUSA_STATE1 Comparator 1 Current State
 * - AC_STATUSA_STATE(value) Comparator x Current State
 * - AC_STATUSA_WSTATE0(value) Window 0 Current State
 *  +      AC_STATUSA_WSTATE0_ABOVE Signal is above window
 *  +      AC_STATUSA_WSTATE0_INSIDE Signal is inside window
 *  +      AC_STATUSA_WSTATE0_BELOW Signal is below window
 **/
static inline uint8_t ac_get_STATUSA(uint8_t mask)
{
    return AC->STATUSA.reg & mask;
}

/**
 * @brief ac read STATUSA register
 *
 * @return uint8_t
 * - AC_STATUSA_STATE0 Comparator 0 Current State
 * - AC_STATUSA_STATE1 Comparator 1 Current State
 * - AC_STATUSA_STATE(value) Comparator x Current State
 * - AC_STATUSA_WSTATE0(value) Window 0 Current State
 *  +      AC_STATUSA_WSTATE0_ABOVE Signal is above window
 *  +      AC_STATUSA_WSTATE0_INSIDE Signal is inside window
 *  +      AC_STATUSA_WSTATE0_BELOW Signal is below window
 **/
static inline uint8_t ac_read_STATUSA(void)
{
	return AC->STATUSA.reg;
}

/**
 * @brief ac get STATUSB register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AC_STATUSB_READY0 Comparator 0 Ready
 * - AC_STATUSB_READY1 Comparator 1 Ready
 * - AC_STATUSB_READY(value) Comparator x Ready
 **/
static inline uint8_t ac_get_STATUSB(uint8_t mask)
{
    return AC->STATUSB.reg & mask;
}

/**
 * @brief ac read STATUSB register
 *
 * @return uint8_t
 * - AC_STATUSB_READY0 Comparator 0 Ready
 * - AC_STATUSB_READY1 Comparator 1 Ready
 * - AC_STATUSB_READY(value) Comparator x Ready
 **/
static inline uint8_t ac_read_STATUSB(void)
{
	return AC->STATUSB.reg;
}

/**
 * @brief ac get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - AC_SYNCBUSY_SWRST Software Reset Synchronization Busy
 * - AC_SYNCBUSY_ENABLE Enable Synchronization Busy
 * - AC_SYNCBUSY_WINCTRL WINCTRL Synchronization Busy
 * - AC_SYNCBUSY_COMPCTRL0 COMPCTRL 0 Synchronization Busy
 * - AC_SYNCBUSY_COMPCTRL1 COMPCTRL 1 Synchronization Busy
 * - AC_SYNCBUSY_COMPCTRL(value) COMPCTRL x Synchronization Busy
 **/
static inline uint32_t ac_get_SYNCBUSY(uint32_t mask)
{
    return AC->SYNCBUSY.reg & mask;
}

/**
 * @brief ac read SYNCBUSY register
 *
 * @return uint32_t
 * - AC_SYNCBUSY_SWRST Software Reset Synchronization Busy
 * - AC_SYNCBUSY_ENABLE Enable Synchronization Busy
 * - AC_SYNCBUSY_WINCTRL WINCTRL Synchronization Busy
 * - AC_SYNCBUSY_COMPCTRL0 COMPCTRL 0 Synchronization Busy
 * - AC_SYNCBUSY_COMPCTRL1 COMPCTRL 1 Synchronization Busy
 * - AC_SYNCBUSY_COMPCTRL(value) COMPCTRL x Synchronization Busy
 **/
static inline uint32_t ac_read_SYNCBUSY(void)
{
	return AC->SYNCBUSY.reg;
}

#endif /* _AC_H */
