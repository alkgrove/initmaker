/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM FREQM
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

#ifndef _FREQM_H_
#define _FREQM_H_

#include <stdbool.h>

/**
 * @brief freqm wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void freqm_wait_for_sync(uint32_t reg)
{
	while (FREQM->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief freqm is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool freqm_is_syncing(uint32_t reg)
{
	return FREQM->SYNCBUSY.reg & reg;
}

/**
 * @brief freqm set INTEN register
 *
 * @param[in] mask uint8_t 
 * - FREQM_INTENSET_DONE Measurement Done Interrupt Enable
 **/
static inline void freqm_set_INTEN(uint8_t mask)
{
	FREQM->INTENSET.reg = mask;
}

/**
 * @brief freqm get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - FREQM_INTENSET_DONE Measurement Done Interrupt Enable
 **/
static inline uint8_t freqm_get_INTEN(uint8_t mask)
{
    return FREQM->INTENSET.reg & mask;
}

/**
 * @brief freqm read INTEN register
 *
 * @return uint8_t
 * - FREQM_INTENSET_DONE Measurement Done Interrupt Enable
 **/
static inline uint8_t freqm_read_INTEN(void)
{
	return FREQM->INTENSET.reg;
}

/**
 * @brief freqm write INTEN register
 *
 * @param[in] data uint8_t 
 * - FREQM_INTENSET_DONE Measurement Done Interrupt Enable
 **/
static inline void freqm_write_INTEN(uint8_t data)
{
	FREQM->INTENSET.reg = data;
	FREQM->INTENCLR.reg = ~data;
}

/**
 * @brief freqm clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - FREQM_INTENSET_DONE Measurement Done Interrupt Enable
 **/
static inline void freqm_clear_INTEN(uint8_t mask)
{
	FREQM->INTENCLR.reg = mask;
}

/**
 * @brief freqm get INTFLAG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - FREQM_INTFLAG_DONE Measurement Done
 **/
static inline uint8_t freqm_get_INTFLAG(uint8_t mask)
{
    return FREQM->INTFLAG.reg & mask;
}

/**
 * @brief freqm read INTFLAG register
 *
 * @return uint8_t
 * - FREQM_INTFLAG_DONE Measurement Done
 **/
static inline uint8_t freqm_read_INTFLAG(void)
{
	return FREQM->INTFLAG.reg;
}

/**
 * @brief freqm clear INTFLAG register
 *
 * @param[in] mask uint8_t 
 * - FREQM_INTFLAG_DONE Measurement Done
 **/
static inline void freqm_clear_INTFLAG(uint8_t mask)
{
	FREQM->INTFLAG.reg = mask;
}

/**
 * @brief freqm write CTRLB register
 *
 * @param[in] data uint8_t 
 * - FREQM_CTRLB_START Start Measurement
 **/
static inline void freqm_write_CTRLB(uint8_t data)
{
	FREQM->CTRLB.reg = data;
}

/**
 * @brief freqm set CTRLA register
 *
 * @param[in] mask uint8_t 
 * - FREQM_CTRLA_SWRST Software Reset
 * - FREQM_CTRLA_ENABLE Enable
 **/
static inline void freqm_set_CTRLA(uint8_t mask)
{
	FREQM->CTRLA.reg |= mask;
}

/**
 * @brief freqm get CTRLA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - FREQM_CTRLA_SWRST Software Reset
 * - FREQM_CTRLA_ENABLE Enable
 **/
static inline uint8_t freqm_get_CTRLA(uint8_t mask)
{
    return FREQM->CTRLA.reg & mask;
}

/**
 * @brief freqm write CTRLA register
 *
 * @param[in] data uint8_t 
 * - FREQM_CTRLA_SWRST Software Reset
 * - FREQM_CTRLA_ENABLE Enable
 **/
static inline void freqm_write_CTRLA(uint8_t data)
{
	FREQM->CTRLA.reg = data;
}

/**
 * @brief freqm clear CTRLA register
 *
 * @param[in] mask uint8_t 
 * - FREQM_CTRLA_SWRST Software Reset
 * - FREQM_CTRLA_ENABLE Enable
 **/
static inline void freqm_clear_CTRLA(uint8_t mask)
{
	FREQM->CTRLA.reg &= ~mask;
}

/**
 * @brief freqm read CTRLA register
 *
 * @return uint8_t
 * - FREQM_CTRLA_SWRST Software Reset
 * - FREQM_CTRLA_ENABLE Enable
 **/
static inline uint8_t freqm_read_CTRLA(void)
{
	return FREQM->CTRLA.reg;
}

/**
 * @brief freqm set CFGA register
 *
 * @param[in] mask uint16_t 
 * - FREQM_CFGA_REFNUM(value) Number of Reference Clock Cycles
 **/
static inline void freqm_set_CFGA(uint16_t mask)
{
	FREQM->CFGA.reg |= mask;
}

/**
 * @brief freqm get CFGA register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - FREQM_CFGA_REFNUM(value) Number of Reference Clock Cycles
 **/
static inline uint16_t freqm_get_CFGA(uint16_t mask)
{
    return FREQM->CFGA.reg & mask;
}

/**
 * @brief freqm write CFGA register
 *
 * @param[in] data uint16_t 
 * - FREQM_CFGA_REFNUM(value) Number of Reference Clock Cycles
 **/
static inline void freqm_write_CFGA(uint16_t data)
{
	FREQM->CFGA.reg = data;
}

/**
 * @brief freqm clear CFGA register
 *
 * @param[in] mask uint16_t 
 * - FREQM_CFGA_REFNUM(value) Number of Reference Clock Cycles
 **/
static inline void freqm_clear_CFGA(uint16_t mask)
{
	FREQM->CFGA.reg &= ~mask;
}

/**
 * @brief freqm read CFGA register
 *
 * @return uint16_t
 * - FREQM_CFGA_REFNUM(value) Number of Reference Clock Cycles
 **/
static inline uint16_t freqm_read_CFGA(void)
{
	return FREQM->CFGA.reg;
}

/**
 * @brief freqm get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - FREQM_SYNCBUSY_SWRST Software Reset
 * - FREQM_SYNCBUSY_ENABLE Enable
 **/
static inline uint32_t freqm_get_SYNCBUSY(uint32_t mask)
{
    return FREQM->SYNCBUSY.reg & mask;
}

/**
 * @brief freqm read SYNCBUSY register
 *
 * @return uint32_t
 * - FREQM_SYNCBUSY_SWRST Software Reset
 * - FREQM_SYNCBUSY_ENABLE Enable
 **/
static inline uint32_t freqm_read_SYNCBUSY(void)
{
	return FREQM->SYNCBUSY.reg;
}

/**
 * @brief freqm get VALUE register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - FREQM_VALUE_VALUE(value) Measurement Value
 **/
static inline uint32_t freqm_get_VALUE(uint32_t mask)
{
    return FREQM->VALUE.reg & mask;
}

/**
 * @brief freqm read VALUE register
 *
 * @return uint32_t
 * - FREQM_VALUE_VALUE(value) Measurement Value
 **/
static inline uint32_t freqm_read_VALUE(void)
{
	return FREQM->VALUE.reg;
}

/**
 * @brief freqm get STATUS register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - FREQM_STATUS_BUSY FREQM Status
 * - FREQM_STATUS_OVF Sticky Count Value Overflow
 **/
static inline uint8_t freqm_get_STATUS(uint8_t mask)
{
    return FREQM->STATUS.reg & mask;
}

/**
 * @brief freqm clear STATUS register
 *
 * @param[in] mask uint8_t 
 * - FREQM_STATUS_BUSY FREQM Status
 * - FREQM_STATUS_OVF Sticky Count Value Overflow
 **/
static inline void freqm_clear_STATUS(uint8_t mask)
{
	FREQM->STATUS.reg = mask;
}

/**
 * @brief freqm read STATUS register
 *
 * @return uint8_t
 * - FREQM_STATUS_BUSY FREQM Status
 * - FREQM_STATUS_OVF Sticky Count Value Overflow
 **/
static inline uint8_t freqm_read_STATUS(void)
{
	return FREQM->STATUS.reg;
}

#endif /* _FREQM_H */
