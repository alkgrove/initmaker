/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM TRNG
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

#ifndef _TRNG_H_
#define _TRNG_H_

#include <stdbool.h>

/**
 * @brief trng set INTEN register
 *
 * @param[in] uint8_t mask
 * TRNG_INTENSET_DATARDY  Data Ready Interrupt Enable 
 */
static inline void trng_set_INTEN(uint8_t mask)
{
	TRNG->INTENSET.reg = mask;
}

/**
 * @brief trng get INTEN register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * TRNG_INTENSET_DATARDY  Data Ready Interrupt Enable 
 */
static inline uint8_t trng_get_INTEN(uint8_t mask)
{
    return TRNG->INTENSET.reg & mask;
}

/**
 * @brief trng read INTEN register
 *
 * @param[in] void
 * @return uint8_t
 * TRNG_INTENSET_DATARDY  Data Ready Interrupt Enable 
 */
static inline uint8_t trng_read_INTEN(void)
{
	return TRNG->INTENSET.reg;
}

/**
 * @brief trng write INTEN register
 *
 * @param[in] uint8_t data
 * TRNG_INTENSET_DATARDY  Data Ready Interrupt Enable 
 */
static inline void trng_write_INTEN(uint8_t data)
{
	TRNG->INTENSET.reg = data;
	TRNG->INTENCLR.reg = ~data;
}

/**
 * @brief trng clear INTEN register
 *
 * @param[in] uint8_t mask
 * TRNG_INTENSET_DATARDY  Data Ready Interrupt Enable 
 */
static inline void trng_clear_INTEN(uint8_t mask)
{
	TRNG->INTENCLR.reg = mask;
}

/**
 * @brief trng get INTFLAG register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * TRNG_INTFLAG_DATARDY  Data Ready Interrupt Flag 
 */
static inline uint8_t trng_get_INTFLAG(uint8_t mask)
{
    return TRNG->INTFLAG.reg & mask;
}

/**
 * @brief trng read INTFLAG register
 *
 * @param[in] void
 * @return uint8_t
 * TRNG_INTFLAG_DATARDY  Data Ready Interrupt Flag 
 */
static inline uint8_t trng_read_INTFLAG(void)
{
	return TRNG->INTFLAG.reg;
}

/**
 * @brief trng clear INTFLAG register
 *
 * @param[in] uint8_t mask
 * TRNG_INTFLAG_DATARDY  Data Ready Interrupt Flag 
 */
static inline void trng_clear_INTFLAG(uint8_t mask)
{
	TRNG->INTFLAG.reg = mask;
}

/**
 * @brief trng set CTRLA register
 *
 * @param[in] uint8_t mask
 * TRNG_CTRLA_ENABLE  Enable 
 * TRNG_CTRLA_RUNSTDBY  Run in Standby 
 */
static inline void trng_set_CTRLA(uint8_t mask)
{
	TRNG->CTRLA.reg |= mask;
}

/**
 * @brief trng get CTRLA register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * TRNG_CTRLA_ENABLE  Enable 
 * TRNG_CTRLA_RUNSTDBY  Run in Standby 
 */
static inline uint8_t trng_get_CTRLA(uint8_t mask)
{
    return TRNG->CTRLA.reg & mask;
}

/**
 * @brief trng write CTRLA register
 *
 * @param[in] uint8_t data
 * TRNG_CTRLA_ENABLE  Enable 
 * TRNG_CTRLA_RUNSTDBY  Run in Standby 
 */
static inline void trng_write_CTRLA(uint8_t data)
{
	TRNG->CTRLA.reg = data;
}

/**
 * @brief trng clear CTRLA register
 *
 * @param[in] uint8_t mask
 * TRNG_CTRLA_ENABLE  Enable 
 * TRNG_CTRLA_RUNSTDBY  Run in Standby 
 */
static inline void trng_clear_CTRLA(uint8_t mask)
{
	TRNG->CTRLA.reg &= ~mask;
}

/**
 * @brief trng read CTRLA register
 *
 * @param[in] void
 * @return uint8_t
 * TRNG_CTRLA_ENABLE  Enable 
 * TRNG_CTRLA_RUNSTDBY  Run in Standby 
 */
static inline uint8_t trng_read_CTRLA(void)
{
	return TRNG->CTRLA.reg;
}

/**
 * @brief trng set EVCTRL register
 *
 * @param[in] uint8_t mask
 * TRNG_EVCTRL_DATARDYEO  Data Ready Event Output 
 */
static inline void trng_set_EVCTRL(uint8_t mask)
{
	TRNG->EVCTRL.reg |= mask;
}

/**
 * @brief trng get EVCTRL register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * TRNG_EVCTRL_DATARDYEO  Data Ready Event Output 
 */
static inline uint8_t trng_get_EVCTRL(uint8_t mask)
{
    return TRNG->EVCTRL.reg & mask;
}

/**
 * @brief trng write EVCTRL register
 *
 * @param[in] uint8_t data
 * TRNG_EVCTRL_DATARDYEO  Data Ready Event Output 
 */
static inline void trng_write_EVCTRL(uint8_t data)
{
	TRNG->EVCTRL.reg = data;
}

/**
 * @brief trng clear EVCTRL register
 *
 * @param[in] uint8_t mask
 * TRNG_EVCTRL_DATARDYEO  Data Ready Event Output 
 */
static inline void trng_clear_EVCTRL(uint8_t mask)
{
	TRNG->EVCTRL.reg &= ~mask;
}

/**
 * @brief trng read EVCTRL register
 *
 * @param[in] void
 * @return uint8_t
 * TRNG_EVCTRL_DATARDYEO  Data Ready Event Output 
 */
static inline uint8_t trng_read_EVCTRL(void)
{
	return TRNG->EVCTRL.reg;
}

/**
 * @brief trng get DATA register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * TRNG_DATA_DATA(value)  Output Data 
 */
static inline uint32_t trng_get_DATA(uint32_t mask)
{
    return TRNG->DATA.reg & mask;
}

/**
 * @brief trng read DATA register
 *
 * @param[in] void
 * @return uint32_t
 * TRNG_DATA_DATA(value)  Output Data 
 */
static inline uint32_t trng_read_DATA(void)
{
	return TRNG->DATA.reg;
}

#endif /* _TRNG_H */
