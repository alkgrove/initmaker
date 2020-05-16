/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM WDT
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

#ifndef _WDT_H_
#define _WDT_H_

#include <stdbool.h>

/**
 * @brief wdt wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void wdt_wait_for_sync(uint32_t reg)
{
	while (WDT->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief wdt is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool wdt_is_syncing(uint32_t reg)
{
	return WDT->SYNCBUSY.reg & reg;
}

/**
 * @brief wdt set INTEN register
 *
 * @param[in] mask uint8_t 
 * - WDT_INTENSET_EW Early Warning Interrupt Enable
 **/
static inline void wdt_set_INTEN(uint8_t mask)
{
	WDT->INTENSET.reg = mask;
}

/**
 * @brief wdt get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - WDT_INTENSET_EW Early Warning Interrupt Enable
 **/
static inline uint8_t wdt_get_INTEN(uint8_t mask)
{
    return WDT->INTENSET.reg & mask;
}

/**
 * @brief wdt read INTEN register
 *
 * @return uint8_t
 * - WDT_INTENSET_EW Early Warning Interrupt Enable
 **/
static inline uint8_t wdt_read_INTEN(void)
{
	return WDT->INTENSET.reg;
}

/**
 * @brief wdt write INTEN register
 *
 * @param[in] data uint8_t 
 * - WDT_INTENSET_EW Early Warning Interrupt Enable
 **/
static inline void wdt_write_INTEN(uint8_t data)
{
	WDT->INTENSET.reg = data;
	WDT->INTENCLR.reg = ~data;
}

/**
 * @brief wdt clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - WDT_INTENSET_EW Early Warning Interrupt Enable
 **/
static inline void wdt_clear_INTEN(uint8_t mask)
{
	WDT->INTENCLR.reg = mask;
}

/**
 * @brief wdt get INTFLAG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - WDT_INTFLAG_EW Early Warning
 **/
static inline uint8_t wdt_get_INTFLAG(uint8_t mask)
{
    return WDT->INTFLAG.reg & mask;
}

/**
 * @brief wdt read INTFLAG register
 *
 * @return uint8_t
 * - WDT_INTFLAG_EW Early Warning
 **/
static inline uint8_t wdt_read_INTFLAG(void)
{
	return WDT->INTFLAG.reg;
}

/**
 * @brief wdt clear INTFLAG register
 *
 * @param[in] mask uint8_t 
 * - WDT_INTFLAG_EW Early Warning
 **/
static inline void wdt_clear_INTFLAG(uint8_t mask)
{
	WDT->INTFLAG.reg = mask;
}

/**
 * @brief wdt write CLEAR register
 *
 * @param[in] data uint8_t 
 * - WDT_CLEAR_CLEAR(value) Watchdog Clear
 *  +      WDT_CLEAR_CLEAR_KEY Clear Key
 **/
static inline void wdt_write_CLEAR(uint8_t data)
{
	WDT->CLEAR.reg = data;
}

/**
 * @brief wdt set CTRLA register
 *
 * @param[in] mask uint8_t 
 * - WDT_CTRLA_ENABLE Enable
 * - WDT_CTRLA_WEN Watchdog Timer Window Mode Enable
 * - WDT_CTRLA_ALWAYSON Always-On
 **/
static inline void wdt_set_CTRLA(uint8_t mask)
{
	WDT->CTRLA.reg |= mask;
}

/**
 * @brief wdt get CTRLA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - WDT_CTRLA_ENABLE Enable
 * - WDT_CTRLA_WEN Watchdog Timer Window Mode Enable
 * - WDT_CTRLA_ALWAYSON Always-On
 **/
static inline uint8_t wdt_get_CTRLA(uint8_t mask)
{
    return WDT->CTRLA.reg & mask;
}

/**
 * @brief wdt write CTRLA register
 *
 * @param[in] data uint8_t 
 * - WDT_CTRLA_ENABLE Enable
 * - WDT_CTRLA_WEN Watchdog Timer Window Mode Enable
 * - WDT_CTRLA_ALWAYSON Always-On
 **/
static inline void wdt_write_CTRLA(uint8_t data)
{
	WDT->CTRLA.reg = data;
}

/**
 * @brief wdt clear CTRLA register
 *
 * @param[in] mask uint8_t 
 * - WDT_CTRLA_ENABLE Enable
 * - WDT_CTRLA_WEN Watchdog Timer Window Mode Enable
 * - WDT_CTRLA_ALWAYSON Always-On
 **/
static inline void wdt_clear_CTRLA(uint8_t mask)
{
	WDT->CTRLA.reg &= ~mask;
}

/**
 * @brief wdt read CTRLA register
 *
 * @return uint8_t
 * - WDT_CTRLA_ENABLE Enable
 * - WDT_CTRLA_WEN Watchdog Timer Window Mode Enable
 * - WDT_CTRLA_ALWAYSON Always-On
 **/
static inline uint8_t wdt_read_CTRLA(void)
{
	return WDT->CTRLA.reg;
}

/**
 * @brief wdt set CONFIG register
 *
 * @param[in] mask uint8_t 
 * - WDT_CONFIG_PER(value) Time-Out Period
 *  +      WDT_CONFIG_PER_CYC8 8 clock cycles
 *  +      WDT_CONFIG_PER_CYC16 16 clock cycles
 *  +      WDT_CONFIG_PER_CYC32 32 clock cycles
 *  +      WDT_CONFIG_PER_CYC64 64 clock cycles
 *  +      WDT_CONFIG_PER_CYC128 128 clock cycles
 *  +      WDT_CONFIG_PER_CYC256 256 clock cycles
 *  +      WDT_CONFIG_PER_CYC512 512 clock cycles
 *  +      WDT_CONFIG_PER_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_PER_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_PER_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_PER_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_PER_CYC16384 16384 clock cycles
 * - WDT_CONFIG_WINDOW(value) Window Mode Time-Out Period
 *  +      WDT_CONFIG_WINDOW_CYC8 8 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16 16 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC32 32 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC64 64 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC128 128 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC256 256 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC512 512 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16384 16384 clock cycles
 **/
static inline void wdt_set_CONFIG(uint8_t mask)
{
	WDT->CONFIG.reg |= mask;
}

/**
 * @brief wdt get CONFIG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - WDT_CONFIG_PER(value) Time-Out Period
 *  +      WDT_CONFIG_PER_CYC8 8 clock cycles
 *  +      WDT_CONFIG_PER_CYC16 16 clock cycles
 *  +      WDT_CONFIG_PER_CYC32 32 clock cycles
 *  +      WDT_CONFIG_PER_CYC64 64 clock cycles
 *  +      WDT_CONFIG_PER_CYC128 128 clock cycles
 *  +      WDT_CONFIG_PER_CYC256 256 clock cycles
 *  +      WDT_CONFIG_PER_CYC512 512 clock cycles
 *  +      WDT_CONFIG_PER_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_PER_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_PER_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_PER_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_PER_CYC16384 16384 clock cycles
 * - WDT_CONFIG_WINDOW(value) Window Mode Time-Out Period
 *  +      WDT_CONFIG_WINDOW_CYC8 8 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16 16 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC32 32 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC64 64 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC128 128 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC256 256 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC512 512 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16384 16384 clock cycles
 **/
static inline uint8_t wdt_get_CONFIG(uint8_t mask)
{
    return WDT->CONFIG.reg & mask;
}

/**
 * @brief wdt write CONFIG register
 *
 * @param[in] data uint8_t 
 * - WDT_CONFIG_PER(value) Time-Out Period
 *  +      WDT_CONFIG_PER_CYC8 8 clock cycles
 *  +      WDT_CONFIG_PER_CYC16 16 clock cycles
 *  +      WDT_CONFIG_PER_CYC32 32 clock cycles
 *  +      WDT_CONFIG_PER_CYC64 64 clock cycles
 *  +      WDT_CONFIG_PER_CYC128 128 clock cycles
 *  +      WDT_CONFIG_PER_CYC256 256 clock cycles
 *  +      WDT_CONFIG_PER_CYC512 512 clock cycles
 *  +      WDT_CONFIG_PER_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_PER_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_PER_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_PER_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_PER_CYC16384 16384 clock cycles
 * - WDT_CONFIG_WINDOW(value) Window Mode Time-Out Period
 *  +      WDT_CONFIG_WINDOW_CYC8 8 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16 16 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC32 32 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC64 64 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC128 128 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC256 256 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC512 512 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16384 16384 clock cycles
 **/
static inline void wdt_write_CONFIG(uint8_t data)
{
	WDT->CONFIG.reg = data;
}

/**
 * @brief wdt clear CONFIG register
 *
 * @param[in] mask uint8_t 
 * - WDT_CONFIG_PER(value) Time-Out Period
 *  +      WDT_CONFIG_PER_CYC8 8 clock cycles
 *  +      WDT_CONFIG_PER_CYC16 16 clock cycles
 *  +      WDT_CONFIG_PER_CYC32 32 clock cycles
 *  +      WDT_CONFIG_PER_CYC64 64 clock cycles
 *  +      WDT_CONFIG_PER_CYC128 128 clock cycles
 *  +      WDT_CONFIG_PER_CYC256 256 clock cycles
 *  +      WDT_CONFIG_PER_CYC512 512 clock cycles
 *  +      WDT_CONFIG_PER_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_PER_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_PER_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_PER_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_PER_CYC16384 16384 clock cycles
 * - WDT_CONFIG_WINDOW(value) Window Mode Time-Out Period
 *  +      WDT_CONFIG_WINDOW_CYC8 8 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16 16 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC32 32 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC64 64 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC128 128 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC256 256 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC512 512 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16384 16384 clock cycles
 **/
static inline void wdt_clear_CONFIG(uint8_t mask)
{
	WDT->CONFIG.reg &= ~mask;
}

/**
 * @brief wdt read CONFIG register
 *
 * @return uint8_t
 * - WDT_CONFIG_PER(value) Time-Out Period
 *  +      WDT_CONFIG_PER_CYC8 8 clock cycles
 *  +      WDT_CONFIG_PER_CYC16 16 clock cycles
 *  +      WDT_CONFIG_PER_CYC32 32 clock cycles
 *  +      WDT_CONFIG_PER_CYC64 64 clock cycles
 *  +      WDT_CONFIG_PER_CYC128 128 clock cycles
 *  +      WDT_CONFIG_PER_CYC256 256 clock cycles
 *  +      WDT_CONFIG_PER_CYC512 512 clock cycles
 *  +      WDT_CONFIG_PER_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_PER_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_PER_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_PER_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_PER_CYC16384 16384 clock cycles
 * - WDT_CONFIG_WINDOW(value) Window Mode Time-Out Period
 *  +      WDT_CONFIG_WINDOW_CYC8 8 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16 16 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC32 32 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC64 64 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC128 128 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC256 256 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC512 512 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC1024 1024 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC2048 2048 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC4096 4096 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC8192 8192 clock cycles
 *  +      WDT_CONFIG_WINDOW_CYC16384 16384 clock cycles
 **/
static inline uint8_t wdt_read_CONFIG(void)
{
	return WDT->CONFIG.reg;
}

/**
 * @brief wdt set EWCTRL register
 *
 * @param[in] mask uint8_t 
 * - WDT_EWCTRL_EWOFFSET(value) Early Warning Interrupt Time Offset
 *  +      WDT_EWCTRL_EWOFFSET_CYC8 8 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16 16 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC32 32 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC64 64 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC128 128 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC256 256 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC512 512 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC1024 1024 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC2048 2048 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC4096 4096 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC8192 8192 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16384 16384 clock cycles
 **/
static inline void wdt_set_EWCTRL(uint8_t mask)
{
	WDT->EWCTRL.reg |= mask;
}

/**
 * @brief wdt get EWCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - WDT_EWCTRL_EWOFFSET(value) Early Warning Interrupt Time Offset
 *  +      WDT_EWCTRL_EWOFFSET_CYC8 8 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16 16 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC32 32 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC64 64 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC128 128 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC256 256 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC512 512 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC1024 1024 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC2048 2048 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC4096 4096 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC8192 8192 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16384 16384 clock cycles
 **/
static inline uint8_t wdt_get_EWCTRL(uint8_t mask)
{
    return WDT->EWCTRL.reg & mask;
}

/**
 * @brief wdt write EWCTRL register
 *
 * @param[in] data uint8_t 
 * - WDT_EWCTRL_EWOFFSET(value) Early Warning Interrupt Time Offset
 *  +      WDT_EWCTRL_EWOFFSET_CYC8 8 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16 16 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC32 32 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC64 64 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC128 128 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC256 256 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC512 512 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC1024 1024 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC2048 2048 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC4096 4096 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC8192 8192 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16384 16384 clock cycles
 **/
static inline void wdt_write_EWCTRL(uint8_t data)
{
	WDT->EWCTRL.reg = data;
}

/**
 * @brief wdt clear EWCTRL register
 *
 * @param[in] mask uint8_t 
 * - WDT_EWCTRL_EWOFFSET(value) Early Warning Interrupt Time Offset
 *  +      WDT_EWCTRL_EWOFFSET_CYC8 8 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16 16 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC32 32 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC64 64 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC128 128 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC256 256 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC512 512 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC1024 1024 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC2048 2048 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC4096 4096 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC8192 8192 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16384 16384 clock cycles
 **/
static inline void wdt_clear_EWCTRL(uint8_t mask)
{
	WDT->EWCTRL.reg &= ~mask;
}

/**
 * @brief wdt read EWCTRL register
 *
 * @return uint8_t
 * - WDT_EWCTRL_EWOFFSET(value) Early Warning Interrupt Time Offset
 *  +      WDT_EWCTRL_EWOFFSET_CYC8 8 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16 16 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC32 32 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC64 64 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC128 128 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC256 256 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC512 512 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC1024 1024 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC2048 2048 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC4096 4096 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC8192 8192 clock cycles
 *  +      WDT_EWCTRL_EWOFFSET_CYC16384 16384 clock cycles
 **/
static inline uint8_t wdt_read_EWCTRL(void)
{
	return WDT->EWCTRL.reg;
}

/**
 * @brief wdt get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - WDT_SYNCBUSY_ENABLE Enable Synchronization Busy
 * - WDT_SYNCBUSY_WEN Window Enable Synchronization Busy
 * - WDT_SYNCBUSY_ALWAYSON Always-On Synchronization Busy
 * - WDT_SYNCBUSY_CLEAR Clear Synchronization Busy
 **/
static inline uint32_t wdt_get_SYNCBUSY(uint32_t mask)
{
    return WDT->SYNCBUSY.reg & mask;
}

/**
 * @brief wdt read SYNCBUSY register
 *
 * @return uint32_t
 * - WDT_SYNCBUSY_ENABLE Enable Synchronization Busy
 * - WDT_SYNCBUSY_WEN Window Enable Synchronization Busy
 * - WDT_SYNCBUSY_ALWAYSON Always-On Synchronization Busy
 * - WDT_SYNCBUSY_CLEAR Clear Synchronization Busy
 **/
static inline uint32_t wdt_read_SYNCBUSY(void)
{
	return WDT->SYNCBUSY.reg;
}

#endif /* _WDT_H */
