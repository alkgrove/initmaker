/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM RAMECC
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

#ifndef _RAMECC_H_
#define _RAMECC_H_

#include <stdbool.h>

/**
 * @brief ramecc set INTEN register
 *
 * @param[in] mask uint8_t 
 * - RAMECC_INTENSET_SINGLEE Single Bit ECC Error Interrupt Enable Set
 * - RAMECC_INTENSET_DUALE Dual Bit ECC Error Interrupt Enable Set
 **/
static inline void ramecc_set_INTEN(uint8_t mask)
{
	RAMECC->INTENSET.reg = mask;
}

/**
 * @brief ramecc get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RAMECC_INTENSET_SINGLEE Single Bit ECC Error Interrupt Enable Set
 * - RAMECC_INTENSET_DUALE Dual Bit ECC Error Interrupt Enable Set
 **/
static inline uint8_t ramecc_get_INTEN(uint8_t mask)
{
    return RAMECC->INTENSET.reg & mask;
}

/**
 * @brief ramecc read INTEN register
 *
 * @return uint8_t
 * - RAMECC_INTENSET_SINGLEE Single Bit ECC Error Interrupt Enable Set
 * - RAMECC_INTENSET_DUALE Dual Bit ECC Error Interrupt Enable Set
 **/
static inline uint8_t ramecc_read_INTEN(void)
{
	return RAMECC->INTENSET.reg;
}

/**
 * @brief ramecc write INTEN register
 *
 * @param[in] data uint8_t 
 * - RAMECC_INTENSET_SINGLEE Single Bit ECC Error Interrupt Enable Set
 * - RAMECC_INTENSET_DUALE Dual Bit ECC Error Interrupt Enable Set
 **/
static inline void ramecc_write_INTEN(uint8_t data)
{
	RAMECC->INTENSET.reg = data;
	RAMECC->INTENCLR.reg = ~data;
}

/**
 * @brief ramecc clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - RAMECC_INTENSET_SINGLEE Single Bit ECC Error Interrupt Enable Set
 * - RAMECC_INTENSET_DUALE Dual Bit ECC Error Interrupt Enable Set
 **/
static inline void ramecc_clear_INTEN(uint8_t mask)
{
	RAMECC->INTENCLR.reg = mask;
}

/**
 * @brief ramecc get INTFLAG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RAMECC_INTFLAG_SINGLEE Single Bit ECC Error Interrupt
 * - RAMECC_INTFLAG_DUALE Dual Bit ECC Error Interrupt
 **/
static inline uint8_t ramecc_get_INTFLAG(uint8_t mask)
{
    return RAMECC->INTFLAG.reg & mask;
}

/**
 * @brief ramecc read INTFLAG register
 *
 * @return uint8_t
 * - RAMECC_INTFLAG_SINGLEE Single Bit ECC Error Interrupt
 * - RAMECC_INTFLAG_DUALE Dual Bit ECC Error Interrupt
 **/
static inline uint8_t ramecc_read_INTFLAG(void)
{
	return RAMECC->INTFLAG.reg;
}

/**
 * @brief ramecc clear INTFLAG register
 *
 * @param[in] mask uint8_t 
 * - RAMECC_INTFLAG_SINGLEE Single Bit ECC Error Interrupt
 * - RAMECC_INTFLAG_DUALE Dual Bit ECC Error Interrupt
 **/
static inline void ramecc_clear_INTFLAG(uint8_t mask)
{
	RAMECC->INTFLAG.reg = mask;
}

/**
 * @brief ramecc set DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - RAMECC_DBGCTRL_ECCDIS ECC Disable
 * - RAMECC_DBGCTRL_ECCELOG ECC Error Log
 **/
static inline void ramecc_set_DBGCTRL(uint8_t mask)
{
	RAMECC->DBGCTRL.reg |= mask;
}

/**
 * @brief ramecc get DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RAMECC_DBGCTRL_ECCDIS ECC Disable
 * - RAMECC_DBGCTRL_ECCELOG ECC Error Log
 **/
static inline uint8_t ramecc_get_DBGCTRL(uint8_t mask)
{
    return RAMECC->DBGCTRL.reg & mask;
}

/**
 * @brief ramecc write DBGCTRL register
 *
 * @param[in] data uint8_t 
 * - RAMECC_DBGCTRL_ECCDIS ECC Disable
 * - RAMECC_DBGCTRL_ECCELOG ECC Error Log
 **/
static inline void ramecc_write_DBGCTRL(uint8_t data)
{
	RAMECC->DBGCTRL.reg = data;
}

/**
 * @brief ramecc clear DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - RAMECC_DBGCTRL_ECCDIS ECC Disable
 * - RAMECC_DBGCTRL_ECCELOG ECC Error Log
 **/
static inline void ramecc_clear_DBGCTRL(uint8_t mask)
{
	RAMECC->DBGCTRL.reg &= ~mask;
}

/**
 * @brief ramecc read DBGCTRL register
 *
 * @return uint8_t
 * - RAMECC_DBGCTRL_ECCDIS ECC Disable
 * - RAMECC_DBGCTRL_ECCELOG ECC Error Log
 **/
static inline uint8_t ramecc_read_DBGCTRL(void)
{
	return RAMECC->DBGCTRL.reg;
}

/**
 * @brief ramecc get STATUS register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RAMECC_STATUS_ECCDIS ECC Disable
 **/
static inline uint8_t ramecc_get_STATUS(uint8_t mask)
{
    return RAMECC->STATUS.reg & mask;
}

/**
 * @brief ramecc read STATUS register
 *
 * @return uint8_t
 * - RAMECC_STATUS_ECCDIS ECC Disable
 **/
static inline uint8_t ramecc_read_STATUS(void)
{
	return RAMECC->STATUS.reg;
}

/**
 * @brief ramecc get ERRADDR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RAMECC_ERRADDR_ERRADDR(value) Error Address
 **/
static inline uint32_t ramecc_get_ERRADDR(uint32_t mask)
{
    return RAMECC->ERRADDR.reg & mask;
}

/**
 * @brief ramecc read ERRADDR register
 *
 * @return uint32_t
 * - RAMECC_ERRADDR_ERRADDR(value) Error Address
 **/
static inline uint32_t ramecc_read_ERRADDR(void)
{
	return RAMECC->ERRADDR.reg;
}

#endif /* _RAMECC_H */
