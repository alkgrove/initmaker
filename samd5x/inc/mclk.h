/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM MCLK
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

#ifndef _MCLK_H_
#define _MCLK_H_

#include <stdbool.h>

/**
 * @brief mclk set INTEN register
 *
 * @param[in] mask uint8_t 
 * - MCLK_INTENSET_CKRDY Clock Ready Interrupt Enable
 **/
static inline void mclk_set_INTEN(uint8_t mask)
{
	MCLK->INTENSET.reg = mask;
}

/**
 * @brief mclk get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - MCLK_INTENSET_CKRDY Clock Ready Interrupt Enable
 **/
static inline uint8_t mclk_get_INTEN(uint8_t mask)
{
    return MCLK->INTENSET.reg & mask;
}

/**
 * @brief mclk read INTEN register
 *
 * @return uint8_t
 * - MCLK_INTENSET_CKRDY Clock Ready Interrupt Enable
 **/
static inline uint8_t mclk_read_INTEN(void)
{
	return MCLK->INTENSET.reg;
}

/**
 * @brief mclk write INTEN register
 *
 * @param[in] data uint8_t 
 * - MCLK_INTENSET_CKRDY Clock Ready Interrupt Enable
 **/
static inline void mclk_write_INTEN(uint8_t data)
{
	MCLK->INTENSET.reg = data;
	MCLK->INTENCLR.reg = ~data;
}

/**
 * @brief mclk clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - MCLK_INTENSET_CKRDY Clock Ready Interrupt Enable
 **/
static inline void mclk_clear_INTEN(uint8_t mask)
{
	MCLK->INTENCLR.reg = mask;
}

/**
 * @brief mclk get INTFLAG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - MCLK_INTFLAG_CKRDY Clock Ready
 **/
static inline uint8_t mclk_get_INTFLAG(uint8_t mask)
{
    return MCLK->INTFLAG.reg & mask;
}

/**
 * @brief mclk read INTFLAG register
 *
 * @return uint8_t
 * - MCLK_INTFLAG_CKRDY Clock Ready
 **/
static inline uint8_t mclk_read_INTFLAG(void)
{
	return MCLK->INTFLAG.reg;
}

/**
 * @brief mclk clear INTFLAG register
 *
 * @param[in] mask uint8_t 
 * - MCLK_INTFLAG_CKRDY Clock Ready
 **/
static inline void mclk_clear_INTFLAG(uint8_t mask)
{
	MCLK->INTFLAG.reg = mask;
}

/**
 * @brief mclk set CPUDIV register
 *
 * @param[in] mask uint8_t 
 * - MCLK_CPUDIV_DIV(value) Low-Power Clock Division Factor
 *  +      MCLK_CPUDIV_DIV_DIV1 Divide by 1
 *  +      MCLK_CPUDIV_DIV_DIV2 Divide by 2
 *  +      MCLK_CPUDIV_DIV_DIV4 Divide by 4
 *  +      MCLK_CPUDIV_DIV_DIV8 Divide by 8
 *  +      MCLK_CPUDIV_DIV_DIV16 Divide by 16
 *  +      MCLK_CPUDIV_DIV_DIV32 Divide by 32
 *  +      MCLK_CPUDIV_DIV_DIV64 Divide by 64
 *  +      MCLK_CPUDIV_DIV_DIV128 Divide by 128
 **/
static inline void mclk_set_CPUDIV(uint8_t mask)
{
	MCLK->CPUDIV.reg |= mask;
}

/**
 * @brief mclk get CPUDIV register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - MCLK_CPUDIV_DIV(value) Low-Power Clock Division Factor
 *  +      MCLK_CPUDIV_DIV_DIV1 Divide by 1
 *  +      MCLK_CPUDIV_DIV_DIV2 Divide by 2
 *  +      MCLK_CPUDIV_DIV_DIV4 Divide by 4
 *  +      MCLK_CPUDIV_DIV_DIV8 Divide by 8
 *  +      MCLK_CPUDIV_DIV_DIV16 Divide by 16
 *  +      MCLK_CPUDIV_DIV_DIV32 Divide by 32
 *  +      MCLK_CPUDIV_DIV_DIV64 Divide by 64
 *  +      MCLK_CPUDIV_DIV_DIV128 Divide by 128
 **/
static inline uint8_t mclk_get_CPUDIV(uint8_t mask)
{
    return MCLK->CPUDIV.reg & mask;
}

/**
 * @brief mclk write CPUDIV register
 *
 * @param[in] data uint8_t 
 * - MCLK_CPUDIV_DIV(value) Low-Power Clock Division Factor
 *  +      MCLK_CPUDIV_DIV_DIV1 Divide by 1
 *  +      MCLK_CPUDIV_DIV_DIV2 Divide by 2
 *  +      MCLK_CPUDIV_DIV_DIV4 Divide by 4
 *  +      MCLK_CPUDIV_DIV_DIV8 Divide by 8
 *  +      MCLK_CPUDIV_DIV_DIV16 Divide by 16
 *  +      MCLK_CPUDIV_DIV_DIV32 Divide by 32
 *  +      MCLK_CPUDIV_DIV_DIV64 Divide by 64
 *  +      MCLK_CPUDIV_DIV_DIV128 Divide by 128
 **/
static inline void mclk_write_CPUDIV(uint8_t data)
{
	MCLK->CPUDIV.reg = data;
}

/**
 * @brief mclk clear CPUDIV register
 *
 * @param[in] mask uint8_t 
 * - MCLK_CPUDIV_DIV(value) Low-Power Clock Division Factor
 *  +      MCLK_CPUDIV_DIV_DIV1 Divide by 1
 *  +      MCLK_CPUDIV_DIV_DIV2 Divide by 2
 *  +      MCLK_CPUDIV_DIV_DIV4 Divide by 4
 *  +      MCLK_CPUDIV_DIV_DIV8 Divide by 8
 *  +      MCLK_CPUDIV_DIV_DIV16 Divide by 16
 *  +      MCLK_CPUDIV_DIV_DIV32 Divide by 32
 *  +      MCLK_CPUDIV_DIV_DIV64 Divide by 64
 *  +      MCLK_CPUDIV_DIV_DIV128 Divide by 128
 **/
static inline void mclk_clear_CPUDIV(uint8_t mask)
{
	MCLK->CPUDIV.reg &= ~mask;
}

/**
 * @brief mclk read CPUDIV register
 *
 * @return uint8_t
 * - MCLK_CPUDIV_DIV(value) Low-Power Clock Division Factor
 *  +      MCLK_CPUDIV_DIV_DIV1 Divide by 1
 *  +      MCLK_CPUDIV_DIV_DIV2 Divide by 2
 *  +      MCLK_CPUDIV_DIV_DIV4 Divide by 4
 *  +      MCLK_CPUDIV_DIV_DIV8 Divide by 8
 *  +      MCLK_CPUDIV_DIV_DIV16 Divide by 16
 *  +      MCLK_CPUDIV_DIV_DIV32 Divide by 32
 *  +      MCLK_CPUDIV_DIV_DIV64 Divide by 64
 *  +      MCLK_CPUDIV_DIV_DIV128 Divide by 128
 **/
static inline uint8_t mclk_read_CPUDIV(void)
{
	return MCLK->CPUDIV.reg;
}

/**
 * @brief mclk set AHBMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_AHBMASK_HPB0 HPB0 AHB Clock Mask
 * - MCLK_AHBMASK_HPB1 HPB1 AHB Clock Mask
 * - MCLK_AHBMASK_HPB2 HPB2 AHB Clock Mask
 * - MCLK_AHBMASK_HPB3 HPB3 AHB Clock Mask
 * - MCLK_AHBMASK_DSU DSU AHB Clock Mask
 * - MCLK_AHBMASK_HMATRIX HMATRIX AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL NVMCTRL AHB Clock Mask
 * - MCLK_AHBMASK_HSRAM HSRAM AHB Clock Mask
 * - MCLK_AHBMASK_CMCC CMCC AHB Clock Mask
 * - MCLK_AHBMASK_DMAC DMAC AHB Clock Mask
 * - MCLK_AHBMASK_USB USB AHB Clock Mask
 * - MCLK_AHBMASK_BKUPRAM BKUPRAM AHB Clock Mask
 * - MCLK_AHBMASK_PAC PAC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI QSPI AHB Clock Mask
 * - MCLK_AHBMASK_SDHC0 SDHC0 AHB Clock Mask
 * - MCLK_AHBMASK_SDHC1 SDHC1 AHB Clock Mask
 * - MCLK_AHBMASK_ICM ICM AHB Clock Mask
 * - MCLK_AHBMASK_PUKCC PUKCC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI_2X QSPI_2X AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_SMEEPROM NVMCTRL_SMEEPROM AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_CACHE NVMCTRL_CACHE AHB Clock Mask
 **/
static inline void mclk_set_AHBMASK(uint32_t mask)
{
	MCLK->AHBMASK.reg |= mask;
}

/**
 * @brief mclk get AHBMASK register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - MCLK_AHBMASK_HPB0 HPB0 AHB Clock Mask
 * - MCLK_AHBMASK_HPB1 HPB1 AHB Clock Mask
 * - MCLK_AHBMASK_HPB2 HPB2 AHB Clock Mask
 * - MCLK_AHBMASK_HPB3 HPB3 AHB Clock Mask
 * - MCLK_AHBMASK_DSU DSU AHB Clock Mask
 * - MCLK_AHBMASK_HMATRIX HMATRIX AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL NVMCTRL AHB Clock Mask
 * - MCLK_AHBMASK_HSRAM HSRAM AHB Clock Mask
 * - MCLK_AHBMASK_CMCC CMCC AHB Clock Mask
 * - MCLK_AHBMASK_DMAC DMAC AHB Clock Mask
 * - MCLK_AHBMASK_USB USB AHB Clock Mask
 * - MCLK_AHBMASK_BKUPRAM BKUPRAM AHB Clock Mask
 * - MCLK_AHBMASK_PAC PAC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI QSPI AHB Clock Mask
 * - MCLK_AHBMASK_SDHC0 SDHC0 AHB Clock Mask
 * - MCLK_AHBMASK_SDHC1 SDHC1 AHB Clock Mask
 * - MCLK_AHBMASK_ICM ICM AHB Clock Mask
 * - MCLK_AHBMASK_PUKCC PUKCC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI_2X QSPI_2X AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_SMEEPROM NVMCTRL_SMEEPROM AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_CACHE NVMCTRL_CACHE AHB Clock Mask
 **/
static inline uint32_t mclk_get_AHBMASK(uint32_t mask)
{
    return MCLK->AHBMASK.reg & mask;
}

/**
 * @brief mclk write AHBMASK register
 *
 * @param[in] data uint32_t 
 * - MCLK_AHBMASK_HPB0 HPB0 AHB Clock Mask
 * - MCLK_AHBMASK_HPB1 HPB1 AHB Clock Mask
 * - MCLK_AHBMASK_HPB2 HPB2 AHB Clock Mask
 * - MCLK_AHBMASK_HPB3 HPB3 AHB Clock Mask
 * - MCLK_AHBMASK_DSU DSU AHB Clock Mask
 * - MCLK_AHBMASK_HMATRIX HMATRIX AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL NVMCTRL AHB Clock Mask
 * - MCLK_AHBMASK_HSRAM HSRAM AHB Clock Mask
 * - MCLK_AHBMASK_CMCC CMCC AHB Clock Mask
 * - MCLK_AHBMASK_DMAC DMAC AHB Clock Mask
 * - MCLK_AHBMASK_USB USB AHB Clock Mask
 * - MCLK_AHBMASK_BKUPRAM BKUPRAM AHB Clock Mask
 * - MCLK_AHBMASK_PAC PAC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI QSPI AHB Clock Mask
 * - MCLK_AHBMASK_SDHC0 SDHC0 AHB Clock Mask
 * - MCLK_AHBMASK_SDHC1 SDHC1 AHB Clock Mask
 * - MCLK_AHBMASK_ICM ICM AHB Clock Mask
 * - MCLK_AHBMASK_PUKCC PUKCC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI_2X QSPI_2X AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_SMEEPROM NVMCTRL_SMEEPROM AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_CACHE NVMCTRL_CACHE AHB Clock Mask
 **/
static inline void mclk_write_AHBMASK(uint32_t data)
{
	MCLK->AHBMASK.reg = data;
}

/**
 * @brief mclk clear AHBMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_AHBMASK_HPB0 HPB0 AHB Clock Mask
 * - MCLK_AHBMASK_HPB1 HPB1 AHB Clock Mask
 * - MCLK_AHBMASK_HPB2 HPB2 AHB Clock Mask
 * - MCLK_AHBMASK_HPB3 HPB3 AHB Clock Mask
 * - MCLK_AHBMASK_DSU DSU AHB Clock Mask
 * - MCLK_AHBMASK_HMATRIX HMATRIX AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL NVMCTRL AHB Clock Mask
 * - MCLK_AHBMASK_HSRAM HSRAM AHB Clock Mask
 * - MCLK_AHBMASK_CMCC CMCC AHB Clock Mask
 * - MCLK_AHBMASK_DMAC DMAC AHB Clock Mask
 * - MCLK_AHBMASK_USB USB AHB Clock Mask
 * - MCLK_AHBMASK_BKUPRAM BKUPRAM AHB Clock Mask
 * - MCLK_AHBMASK_PAC PAC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI QSPI AHB Clock Mask
 * - MCLK_AHBMASK_SDHC0 SDHC0 AHB Clock Mask
 * - MCLK_AHBMASK_SDHC1 SDHC1 AHB Clock Mask
 * - MCLK_AHBMASK_ICM ICM AHB Clock Mask
 * - MCLK_AHBMASK_PUKCC PUKCC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI_2X QSPI_2X AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_SMEEPROM NVMCTRL_SMEEPROM AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_CACHE NVMCTRL_CACHE AHB Clock Mask
 **/
static inline void mclk_clear_AHBMASK(uint32_t mask)
{
	MCLK->AHBMASK.reg &= ~mask;
}

/**
 * @brief mclk read AHBMASK register
 *
 * @return uint32_t
 * - MCLK_AHBMASK_HPB0 HPB0 AHB Clock Mask
 * - MCLK_AHBMASK_HPB1 HPB1 AHB Clock Mask
 * - MCLK_AHBMASK_HPB2 HPB2 AHB Clock Mask
 * - MCLK_AHBMASK_HPB3 HPB3 AHB Clock Mask
 * - MCLK_AHBMASK_DSU DSU AHB Clock Mask
 * - MCLK_AHBMASK_HMATRIX HMATRIX AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL NVMCTRL AHB Clock Mask
 * - MCLK_AHBMASK_HSRAM HSRAM AHB Clock Mask
 * - MCLK_AHBMASK_CMCC CMCC AHB Clock Mask
 * - MCLK_AHBMASK_DMAC DMAC AHB Clock Mask
 * - MCLK_AHBMASK_USB USB AHB Clock Mask
 * - MCLK_AHBMASK_BKUPRAM BKUPRAM AHB Clock Mask
 * - MCLK_AHBMASK_PAC PAC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI QSPI AHB Clock Mask
 * - MCLK_AHBMASK_SDHC0 SDHC0 AHB Clock Mask
 * - MCLK_AHBMASK_SDHC1 SDHC1 AHB Clock Mask
 * - MCLK_AHBMASK_ICM ICM AHB Clock Mask
 * - MCLK_AHBMASK_PUKCC PUKCC AHB Clock Mask
 * - MCLK_AHBMASK_QSPI_2X QSPI_2X AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_SMEEPROM NVMCTRL_SMEEPROM AHB Clock Mask
 * - MCLK_AHBMASK_NVMCTRL_CACHE NVMCTRL_CACHE AHB Clock Mask
 **/
static inline uint32_t mclk_read_AHBMASK(void)
{
	return MCLK->AHBMASK.reg;
}

/**
 * @brief mclk set APBAMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_APBAMASK_PAC PAC APB Clock Enable
 * - MCLK_APBAMASK_PM PM APB Clock Enable
 * - MCLK_APBAMASK_MCLK MCLK APB Clock Enable
 * - MCLK_APBAMASK_RSTC RSTC APB Clock Enable
 * - MCLK_APBAMASK_OSCCTRL OSCCTRL APB Clock Enable
 * - MCLK_APBAMASK_OSC32KCTRL OSC32KCTRL APB Clock Enable
 * - MCLK_APBAMASK_SUPC SUPC APB Clock Enable
 * - MCLK_APBAMASK_GCLK GCLK APB Clock Enable
 * - MCLK_APBAMASK_WDT WDT APB Clock Enable
 * - MCLK_APBAMASK_RTC RTC APB Clock Enable
 * - MCLK_APBAMASK_EIC EIC APB Clock Enable
 * - MCLK_APBAMASK_FREQM FREQM APB Clock Enable
 * - MCLK_APBAMASK_SERCOM0 SERCOM0 APB Clock Enable
 * - MCLK_APBAMASK_SERCOM1 SERCOM1 APB Clock Enable
 * - MCLK_APBAMASK_TC0 TC0 APB Clock Enable
 * - MCLK_APBAMASK_TC1 TC1 APB Clock Enable
 **/
static inline void mclk_set_APBAMASK(uint32_t mask)
{
	MCLK->APBAMASK.reg |= mask;
}

/**
 * @brief mclk get APBAMASK register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - MCLK_APBAMASK_PAC PAC APB Clock Enable
 * - MCLK_APBAMASK_PM PM APB Clock Enable
 * - MCLK_APBAMASK_MCLK MCLK APB Clock Enable
 * - MCLK_APBAMASK_RSTC RSTC APB Clock Enable
 * - MCLK_APBAMASK_OSCCTRL OSCCTRL APB Clock Enable
 * - MCLK_APBAMASK_OSC32KCTRL OSC32KCTRL APB Clock Enable
 * - MCLK_APBAMASK_SUPC SUPC APB Clock Enable
 * - MCLK_APBAMASK_GCLK GCLK APB Clock Enable
 * - MCLK_APBAMASK_WDT WDT APB Clock Enable
 * - MCLK_APBAMASK_RTC RTC APB Clock Enable
 * - MCLK_APBAMASK_EIC EIC APB Clock Enable
 * - MCLK_APBAMASK_FREQM FREQM APB Clock Enable
 * - MCLK_APBAMASK_SERCOM0 SERCOM0 APB Clock Enable
 * - MCLK_APBAMASK_SERCOM1 SERCOM1 APB Clock Enable
 * - MCLK_APBAMASK_TC0 TC0 APB Clock Enable
 * - MCLK_APBAMASK_TC1 TC1 APB Clock Enable
 **/
static inline uint32_t mclk_get_APBAMASK(uint32_t mask)
{
    return MCLK->APBAMASK.reg & mask;
}

/**
 * @brief mclk write APBAMASK register
 *
 * @param[in] data uint32_t 
 * - MCLK_APBAMASK_PAC PAC APB Clock Enable
 * - MCLK_APBAMASK_PM PM APB Clock Enable
 * - MCLK_APBAMASK_MCLK MCLK APB Clock Enable
 * - MCLK_APBAMASK_RSTC RSTC APB Clock Enable
 * - MCLK_APBAMASK_OSCCTRL OSCCTRL APB Clock Enable
 * - MCLK_APBAMASK_OSC32KCTRL OSC32KCTRL APB Clock Enable
 * - MCLK_APBAMASK_SUPC SUPC APB Clock Enable
 * - MCLK_APBAMASK_GCLK GCLK APB Clock Enable
 * - MCLK_APBAMASK_WDT WDT APB Clock Enable
 * - MCLK_APBAMASK_RTC RTC APB Clock Enable
 * - MCLK_APBAMASK_EIC EIC APB Clock Enable
 * - MCLK_APBAMASK_FREQM FREQM APB Clock Enable
 * - MCLK_APBAMASK_SERCOM0 SERCOM0 APB Clock Enable
 * - MCLK_APBAMASK_SERCOM1 SERCOM1 APB Clock Enable
 * - MCLK_APBAMASK_TC0 TC0 APB Clock Enable
 * - MCLK_APBAMASK_TC1 TC1 APB Clock Enable
 **/
static inline void mclk_write_APBAMASK(uint32_t data)
{
	MCLK->APBAMASK.reg = data;
}

/**
 * @brief mclk clear APBAMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_APBAMASK_PAC PAC APB Clock Enable
 * - MCLK_APBAMASK_PM PM APB Clock Enable
 * - MCLK_APBAMASK_MCLK MCLK APB Clock Enable
 * - MCLK_APBAMASK_RSTC RSTC APB Clock Enable
 * - MCLK_APBAMASK_OSCCTRL OSCCTRL APB Clock Enable
 * - MCLK_APBAMASK_OSC32KCTRL OSC32KCTRL APB Clock Enable
 * - MCLK_APBAMASK_SUPC SUPC APB Clock Enable
 * - MCLK_APBAMASK_GCLK GCLK APB Clock Enable
 * - MCLK_APBAMASK_WDT WDT APB Clock Enable
 * - MCLK_APBAMASK_RTC RTC APB Clock Enable
 * - MCLK_APBAMASK_EIC EIC APB Clock Enable
 * - MCLK_APBAMASK_FREQM FREQM APB Clock Enable
 * - MCLK_APBAMASK_SERCOM0 SERCOM0 APB Clock Enable
 * - MCLK_APBAMASK_SERCOM1 SERCOM1 APB Clock Enable
 * - MCLK_APBAMASK_TC0 TC0 APB Clock Enable
 * - MCLK_APBAMASK_TC1 TC1 APB Clock Enable
 **/
static inline void mclk_clear_APBAMASK(uint32_t mask)
{
	MCLK->APBAMASK.reg &= ~mask;
}

/**
 * @brief mclk read APBAMASK register
 *
 * @return uint32_t
 * - MCLK_APBAMASK_PAC PAC APB Clock Enable
 * - MCLK_APBAMASK_PM PM APB Clock Enable
 * - MCLK_APBAMASK_MCLK MCLK APB Clock Enable
 * - MCLK_APBAMASK_RSTC RSTC APB Clock Enable
 * - MCLK_APBAMASK_OSCCTRL OSCCTRL APB Clock Enable
 * - MCLK_APBAMASK_OSC32KCTRL OSC32KCTRL APB Clock Enable
 * - MCLK_APBAMASK_SUPC SUPC APB Clock Enable
 * - MCLK_APBAMASK_GCLK GCLK APB Clock Enable
 * - MCLK_APBAMASK_WDT WDT APB Clock Enable
 * - MCLK_APBAMASK_RTC RTC APB Clock Enable
 * - MCLK_APBAMASK_EIC EIC APB Clock Enable
 * - MCLK_APBAMASK_FREQM FREQM APB Clock Enable
 * - MCLK_APBAMASK_SERCOM0 SERCOM0 APB Clock Enable
 * - MCLK_APBAMASK_SERCOM1 SERCOM1 APB Clock Enable
 * - MCLK_APBAMASK_TC0 TC0 APB Clock Enable
 * - MCLK_APBAMASK_TC1 TC1 APB Clock Enable
 **/
static inline uint32_t mclk_read_APBAMASK(void)
{
	return MCLK->APBAMASK.reg;
}

/**
 * @brief mclk set APBBMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_APBBMASK_USB USB APB Clock Enable
 * - MCLK_APBBMASK_DSU DSU APB Clock Enable
 * - MCLK_APBBMASK_NVMCTRL NVMCTRL APB Clock Enable
 * - MCLK_APBBMASK_PORT PORT APB Clock Enable
 * - MCLK_APBBMASK_HMATRIX HMATRIX APB Clock Enable
 * - MCLK_APBBMASK_EVSYS EVSYS APB Clock Enable
 * - MCLK_APBBMASK_SERCOM2 SERCOM2 APB Clock Enable
 * - MCLK_APBBMASK_SERCOM3 SERCOM3 APB Clock Enable
 * - MCLK_APBBMASK_TCC0 TCC0 APB Clock Enable
 * - MCLK_APBBMASK_TCC1 TCC1 APB Clock Enable
 * - MCLK_APBBMASK_TC2 TC2 APB Clock Enable
 * - MCLK_APBBMASK_TC3 TC3 APB Clock Enable
 * - MCLK_APBBMASK_TAL TAL APB Clock Enable
 * - MCLK_APBBMASK_RAMECC RAMECC APB Clock Enable
 **/
static inline void mclk_set_APBBMASK(uint32_t mask)
{
	MCLK->APBBMASK.reg |= mask;
}

/**
 * @brief mclk get APBBMASK register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - MCLK_APBBMASK_USB USB APB Clock Enable
 * - MCLK_APBBMASK_DSU DSU APB Clock Enable
 * - MCLK_APBBMASK_NVMCTRL NVMCTRL APB Clock Enable
 * - MCLK_APBBMASK_PORT PORT APB Clock Enable
 * - MCLK_APBBMASK_HMATRIX HMATRIX APB Clock Enable
 * - MCLK_APBBMASK_EVSYS EVSYS APB Clock Enable
 * - MCLK_APBBMASK_SERCOM2 SERCOM2 APB Clock Enable
 * - MCLK_APBBMASK_SERCOM3 SERCOM3 APB Clock Enable
 * - MCLK_APBBMASK_TCC0 TCC0 APB Clock Enable
 * - MCLK_APBBMASK_TCC1 TCC1 APB Clock Enable
 * - MCLK_APBBMASK_TC2 TC2 APB Clock Enable
 * - MCLK_APBBMASK_TC3 TC3 APB Clock Enable
 * - MCLK_APBBMASK_TAL TAL APB Clock Enable
 * - MCLK_APBBMASK_RAMECC RAMECC APB Clock Enable
 **/
static inline uint32_t mclk_get_APBBMASK(uint32_t mask)
{
    return MCLK->APBBMASK.reg & mask;
}

/**
 * @brief mclk write APBBMASK register
 *
 * @param[in] data uint32_t 
 * - MCLK_APBBMASK_USB USB APB Clock Enable
 * - MCLK_APBBMASK_DSU DSU APB Clock Enable
 * - MCLK_APBBMASK_NVMCTRL NVMCTRL APB Clock Enable
 * - MCLK_APBBMASK_PORT PORT APB Clock Enable
 * - MCLK_APBBMASK_HMATRIX HMATRIX APB Clock Enable
 * - MCLK_APBBMASK_EVSYS EVSYS APB Clock Enable
 * - MCLK_APBBMASK_SERCOM2 SERCOM2 APB Clock Enable
 * - MCLK_APBBMASK_SERCOM3 SERCOM3 APB Clock Enable
 * - MCLK_APBBMASK_TCC0 TCC0 APB Clock Enable
 * - MCLK_APBBMASK_TCC1 TCC1 APB Clock Enable
 * - MCLK_APBBMASK_TC2 TC2 APB Clock Enable
 * - MCLK_APBBMASK_TC3 TC3 APB Clock Enable
 * - MCLK_APBBMASK_TAL TAL APB Clock Enable
 * - MCLK_APBBMASK_RAMECC RAMECC APB Clock Enable
 **/
static inline void mclk_write_APBBMASK(uint32_t data)
{
	MCLK->APBBMASK.reg = data;
}

/**
 * @brief mclk clear APBBMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_APBBMASK_USB USB APB Clock Enable
 * - MCLK_APBBMASK_DSU DSU APB Clock Enable
 * - MCLK_APBBMASK_NVMCTRL NVMCTRL APB Clock Enable
 * - MCLK_APBBMASK_PORT PORT APB Clock Enable
 * - MCLK_APBBMASK_HMATRIX HMATRIX APB Clock Enable
 * - MCLK_APBBMASK_EVSYS EVSYS APB Clock Enable
 * - MCLK_APBBMASK_SERCOM2 SERCOM2 APB Clock Enable
 * - MCLK_APBBMASK_SERCOM3 SERCOM3 APB Clock Enable
 * - MCLK_APBBMASK_TCC0 TCC0 APB Clock Enable
 * - MCLK_APBBMASK_TCC1 TCC1 APB Clock Enable
 * - MCLK_APBBMASK_TC2 TC2 APB Clock Enable
 * - MCLK_APBBMASK_TC3 TC3 APB Clock Enable
 * - MCLK_APBBMASK_TAL TAL APB Clock Enable
 * - MCLK_APBBMASK_RAMECC RAMECC APB Clock Enable
 **/
static inline void mclk_clear_APBBMASK(uint32_t mask)
{
	MCLK->APBBMASK.reg &= ~mask;
}

/**
 * @brief mclk read APBBMASK register
 *
 * @return uint32_t
 * - MCLK_APBBMASK_USB USB APB Clock Enable
 * - MCLK_APBBMASK_DSU DSU APB Clock Enable
 * - MCLK_APBBMASK_NVMCTRL NVMCTRL APB Clock Enable
 * - MCLK_APBBMASK_PORT PORT APB Clock Enable
 * - MCLK_APBBMASK_HMATRIX HMATRIX APB Clock Enable
 * - MCLK_APBBMASK_EVSYS EVSYS APB Clock Enable
 * - MCLK_APBBMASK_SERCOM2 SERCOM2 APB Clock Enable
 * - MCLK_APBBMASK_SERCOM3 SERCOM3 APB Clock Enable
 * - MCLK_APBBMASK_TCC0 TCC0 APB Clock Enable
 * - MCLK_APBBMASK_TCC1 TCC1 APB Clock Enable
 * - MCLK_APBBMASK_TC2 TC2 APB Clock Enable
 * - MCLK_APBBMASK_TC3 TC3 APB Clock Enable
 * - MCLK_APBBMASK_TAL TAL APB Clock Enable
 * - MCLK_APBBMASK_RAMECC RAMECC APB Clock Enable
 **/
static inline uint32_t mclk_read_APBBMASK(void)
{
	return MCLK->APBBMASK.reg;
}

/**
 * @brief mclk set APBCMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_APBCMASK_TCC2 TCC2 APB Clock Enable
 * - MCLK_APBCMASK_TCC3 TCC3 APB Clock Enable
 * - MCLK_APBCMASK_TC4 TC4 APB Clock Enable
 * - MCLK_APBCMASK_TC5 TC5 APB Clock Enable
 * - MCLK_APBCMASK_PDEC PDEC APB Clock Enable
 * - MCLK_APBCMASK_AC AC APB Clock Enable
 * - MCLK_APBCMASK_AES AES APB Clock Enable
 * - MCLK_APBCMASK_TRNG TRNG APB Clock Enable
 * - MCLK_APBCMASK_ICM ICM APB Clock Enable
 * - MCLK_APBCMASK_QSPI QSPI APB Clock Enable
 * - MCLK_APBCMASK_CCL CCL APB Clock Enable
 **/
static inline void mclk_set_APBCMASK(uint32_t mask)
{
	MCLK->APBCMASK.reg |= mask;
}

/**
 * @brief mclk get APBCMASK register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - MCLK_APBCMASK_TCC2 TCC2 APB Clock Enable
 * - MCLK_APBCMASK_TCC3 TCC3 APB Clock Enable
 * - MCLK_APBCMASK_TC4 TC4 APB Clock Enable
 * - MCLK_APBCMASK_TC5 TC5 APB Clock Enable
 * - MCLK_APBCMASK_PDEC PDEC APB Clock Enable
 * - MCLK_APBCMASK_AC AC APB Clock Enable
 * - MCLK_APBCMASK_AES AES APB Clock Enable
 * - MCLK_APBCMASK_TRNG TRNG APB Clock Enable
 * - MCLK_APBCMASK_ICM ICM APB Clock Enable
 * - MCLK_APBCMASK_QSPI QSPI APB Clock Enable
 * - MCLK_APBCMASK_CCL CCL APB Clock Enable
 **/
static inline uint32_t mclk_get_APBCMASK(uint32_t mask)
{
    return MCLK->APBCMASK.reg & mask;
}

/**
 * @brief mclk write APBCMASK register
 *
 * @param[in] data uint32_t 
 * - MCLK_APBCMASK_TCC2 TCC2 APB Clock Enable
 * - MCLK_APBCMASK_TCC3 TCC3 APB Clock Enable
 * - MCLK_APBCMASK_TC4 TC4 APB Clock Enable
 * - MCLK_APBCMASK_TC5 TC5 APB Clock Enable
 * - MCLK_APBCMASK_PDEC PDEC APB Clock Enable
 * - MCLK_APBCMASK_AC AC APB Clock Enable
 * - MCLK_APBCMASK_AES AES APB Clock Enable
 * - MCLK_APBCMASK_TRNG TRNG APB Clock Enable
 * - MCLK_APBCMASK_ICM ICM APB Clock Enable
 * - MCLK_APBCMASK_QSPI QSPI APB Clock Enable
 * - MCLK_APBCMASK_CCL CCL APB Clock Enable
 **/
static inline void mclk_write_APBCMASK(uint32_t data)
{
	MCLK->APBCMASK.reg = data;
}

/**
 * @brief mclk clear APBCMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_APBCMASK_TCC2 TCC2 APB Clock Enable
 * - MCLK_APBCMASK_TCC3 TCC3 APB Clock Enable
 * - MCLK_APBCMASK_TC4 TC4 APB Clock Enable
 * - MCLK_APBCMASK_TC5 TC5 APB Clock Enable
 * - MCLK_APBCMASK_PDEC PDEC APB Clock Enable
 * - MCLK_APBCMASK_AC AC APB Clock Enable
 * - MCLK_APBCMASK_AES AES APB Clock Enable
 * - MCLK_APBCMASK_TRNG TRNG APB Clock Enable
 * - MCLK_APBCMASK_ICM ICM APB Clock Enable
 * - MCLK_APBCMASK_QSPI QSPI APB Clock Enable
 * - MCLK_APBCMASK_CCL CCL APB Clock Enable
 **/
static inline void mclk_clear_APBCMASK(uint32_t mask)
{
	MCLK->APBCMASK.reg &= ~mask;
}

/**
 * @brief mclk read APBCMASK register
 *
 * @return uint32_t
 * - MCLK_APBCMASK_TCC2 TCC2 APB Clock Enable
 * - MCLK_APBCMASK_TCC3 TCC3 APB Clock Enable
 * - MCLK_APBCMASK_TC4 TC4 APB Clock Enable
 * - MCLK_APBCMASK_TC5 TC5 APB Clock Enable
 * - MCLK_APBCMASK_PDEC PDEC APB Clock Enable
 * - MCLK_APBCMASK_AC AC APB Clock Enable
 * - MCLK_APBCMASK_AES AES APB Clock Enable
 * - MCLK_APBCMASK_TRNG TRNG APB Clock Enable
 * - MCLK_APBCMASK_ICM ICM APB Clock Enable
 * - MCLK_APBCMASK_QSPI QSPI APB Clock Enable
 * - MCLK_APBCMASK_CCL CCL APB Clock Enable
 **/
static inline uint32_t mclk_read_APBCMASK(void)
{
	return MCLK->APBCMASK.reg;
}

/**
 * @brief mclk set APBDMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_APBDMASK_SERCOM4 SERCOM4 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM5 SERCOM5 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM6 SERCOM6 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM7 SERCOM7 APB Clock Enable
 * - MCLK_APBDMASK_TCC4 TCC4 APB Clock Enable
 * - MCLK_APBDMASK_TC6 TC6 APB Clock Enable
 * - MCLK_APBDMASK_TC7 TC7 APB Clock Enable
 * - MCLK_APBDMASK_ADC0 ADC0 APB Clock Enable
 * - MCLK_APBDMASK_ADC1 ADC1 APB Clock Enable
 * - MCLK_APBDMASK_DAC DAC APB Clock Enable
 * - MCLK_APBDMASK_I2S I2S APB Clock Enable
 * - MCLK_APBDMASK_PCC PCC APB Clock Enable
 **/
static inline void mclk_set_APBDMASK(uint32_t mask)
{
	MCLK->APBDMASK.reg |= mask;
}

/**
 * @brief mclk get APBDMASK register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - MCLK_APBDMASK_SERCOM4 SERCOM4 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM5 SERCOM5 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM6 SERCOM6 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM7 SERCOM7 APB Clock Enable
 * - MCLK_APBDMASK_TCC4 TCC4 APB Clock Enable
 * - MCLK_APBDMASK_TC6 TC6 APB Clock Enable
 * - MCLK_APBDMASK_TC7 TC7 APB Clock Enable
 * - MCLK_APBDMASK_ADC0 ADC0 APB Clock Enable
 * - MCLK_APBDMASK_ADC1 ADC1 APB Clock Enable
 * - MCLK_APBDMASK_DAC DAC APB Clock Enable
 * - MCLK_APBDMASK_I2S I2S APB Clock Enable
 * - MCLK_APBDMASK_PCC PCC APB Clock Enable
 **/
static inline uint32_t mclk_get_APBDMASK(uint32_t mask)
{
    return MCLK->APBDMASK.reg & mask;
}

/**
 * @brief mclk write APBDMASK register
 *
 * @param[in] data uint32_t 
 * - MCLK_APBDMASK_SERCOM4 SERCOM4 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM5 SERCOM5 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM6 SERCOM6 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM7 SERCOM7 APB Clock Enable
 * - MCLK_APBDMASK_TCC4 TCC4 APB Clock Enable
 * - MCLK_APBDMASK_TC6 TC6 APB Clock Enable
 * - MCLK_APBDMASK_TC7 TC7 APB Clock Enable
 * - MCLK_APBDMASK_ADC0 ADC0 APB Clock Enable
 * - MCLK_APBDMASK_ADC1 ADC1 APB Clock Enable
 * - MCLK_APBDMASK_DAC DAC APB Clock Enable
 * - MCLK_APBDMASK_I2S I2S APB Clock Enable
 * - MCLK_APBDMASK_PCC PCC APB Clock Enable
 **/
static inline void mclk_write_APBDMASK(uint32_t data)
{
	MCLK->APBDMASK.reg = data;
}

/**
 * @brief mclk clear APBDMASK register
 *
 * @param[in] mask uint32_t 
 * - MCLK_APBDMASK_SERCOM4 SERCOM4 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM5 SERCOM5 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM6 SERCOM6 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM7 SERCOM7 APB Clock Enable
 * - MCLK_APBDMASK_TCC4 TCC4 APB Clock Enable
 * - MCLK_APBDMASK_TC6 TC6 APB Clock Enable
 * - MCLK_APBDMASK_TC7 TC7 APB Clock Enable
 * - MCLK_APBDMASK_ADC0 ADC0 APB Clock Enable
 * - MCLK_APBDMASK_ADC1 ADC1 APB Clock Enable
 * - MCLK_APBDMASK_DAC DAC APB Clock Enable
 * - MCLK_APBDMASK_I2S I2S APB Clock Enable
 * - MCLK_APBDMASK_PCC PCC APB Clock Enable
 **/
static inline void mclk_clear_APBDMASK(uint32_t mask)
{
	MCLK->APBDMASK.reg &= ~mask;
}

/**
 * @brief mclk read APBDMASK register
 *
 * @return uint32_t
 * - MCLK_APBDMASK_SERCOM4 SERCOM4 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM5 SERCOM5 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM6 SERCOM6 APB Clock Enable
 * - MCLK_APBDMASK_SERCOM7 SERCOM7 APB Clock Enable
 * - MCLK_APBDMASK_TCC4 TCC4 APB Clock Enable
 * - MCLK_APBDMASK_TC6 TC6 APB Clock Enable
 * - MCLK_APBDMASK_TC7 TC7 APB Clock Enable
 * - MCLK_APBDMASK_ADC0 ADC0 APB Clock Enable
 * - MCLK_APBDMASK_ADC1 ADC1 APB Clock Enable
 * - MCLK_APBDMASK_DAC DAC APB Clock Enable
 * - MCLK_APBDMASK_I2S I2S APB Clock Enable
 * - MCLK_APBDMASK_PCC PCC APB Clock Enable
 **/
static inline uint32_t mclk_read_APBDMASK(void)
{
	return MCLK->APBDMASK.reg;
}

/**
 * @brief mclk get HSDIV register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - MCLK_HSDIV_DIV(value) CPU Clock Division Factor
 *  +      MCLK_HSDIV_DIV_DIV1 Divide by 1
 **/
static inline uint8_t mclk_get_HSDIV(uint8_t mask)
{
    return MCLK->HSDIV.reg & mask;
}

/**
 * @brief mclk read HSDIV register
 *
 * @return uint8_t
 * - MCLK_HSDIV_DIV(value) CPU Clock Division Factor
 *  +      MCLK_HSDIV_DIV_DIV1 Divide by 1
 **/
static inline uint8_t mclk_read_HSDIV(void)
{
	return MCLK->HSDIV.reg;
}

#endif /* _MCLK_H */
