/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM SDHC
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

#ifndef _SDHC_H_
#define _SDHC_H_

#include <stdbool.h>

/**
 * @brief sdhc set SSAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_SSAR_CMD23_ARG2(value) Argument 2
 * - SDHC_SSAR_ADDR(value) SDMA System Address
 **/
static inline void sdhc_set_SSAR(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->SSAR.reg |= mask;
}

/**
 * @brief sdhc get SSAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_SSAR_CMD23_ARG2(value) Argument 2
 * - SDHC_SSAR_ADDR(value) SDMA System Address
 **/
static inline uint32_t sdhc_get_SSAR(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->SSAR.reg & mask);
}

/**
 * @brief sdhc write SSAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint32_t 
 * - SDHC_SSAR_CMD23_ARG2(value) Argument 2
 * - SDHC_SSAR_ADDR(value) SDMA System Address
 **/
static inline void sdhc_write_SSAR(SDHC_t *pSDHC, uint32_t data)
{
	pSDHC->SSAR.reg = data;
}

/**
 * @brief sdhc clear SSAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_SSAR_CMD23_ARG2(value) Argument 2
 * - SDHC_SSAR_ADDR(value) SDMA System Address
 **/
static inline void sdhc_clear_SSAR(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->SSAR.reg &= ~mask;
}

/**
 * @brief sdhc read SSAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_SSAR_CMD23_ARG2(value) Argument 2
 * - SDHC_SSAR_ADDR(value) SDMA System Address
 **/
static inline uint32_t sdhc_read_SSAR(SDHC_t *pSDHC)
{
	return pSDHC->SSAR.reg;
}

/**
 * @brief sdhc set HC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_HC1R_LEDCTRL LED Control
 *  +      SDHC_HC1R_LEDCTRL_OFF LED off
 *  +      SDHC_HC1R_LEDCTRL_ON LED on
 * - SDHC_HC1R_DW Data Width
 *  +      SDHC_HC1R_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_DW_4BIT 4-bit mode
 * - SDHC_HC1R_HSEN High Speed Enable
 *  +      SDHC_HC1R_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_DMASEL_1 Reserved
 *  +      SDHC_HC1R_DMASEL_32BIT 32-bit Address ADMA2 is selected
 * - SDHC_HC1R_CARDDTL Card Detect Test Level
 *  +      SDHC_HC1R_CARDDTL_NO No Card
 *  +      SDHC_HC1R_CARDDTL_YES Card Inserted
 * - SDHC_HC1R_CARDDSEL Card Detect Signal Selection
 *  +      SDHC_HC1R_CARDDSEL_NORMAL SDCD# is selected (for normal use)
 *  +      SDHC_HC1R_CARDDSEL_TEST The Card Select Test Level is selected (for test purpose)
 * - SDHC_HC1R_EMMC_DW Data Width
 *  +      SDHC_HC1R_EMMC_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_EMMC_DW_4BIT 4-bit mode
 * - SDHC_HC1R_EMMC_HSEN High Speed Enable
 *  +      SDHC_HC1R_EMMC_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_EMMC_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_EMMC_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_EMMC_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_EMMC_DMASEL_1 Reserved
 *  +      SDHC_HC1R_EMMC_DMASEL_32BIT 32-bit Address ADMA2 is selected
 **/
static inline void sdhc_set_HC1R(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->HC1R.reg |= mask;
}

/**
 * @brief sdhc get HC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_HC1R_LEDCTRL LED Control
 *  +      SDHC_HC1R_LEDCTRL_OFF LED off
 *  +      SDHC_HC1R_LEDCTRL_ON LED on
 * - SDHC_HC1R_DW Data Width
 *  +      SDHC_HC1R_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_DW_4BIT 4-bit mode
 * - SDHC_HC1R_HSEN High Speed Enable
 *  +      SDHC_HC1R_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_DMASEL_1 Reserved
 *  +      SDHC_HC1R_DMASEL_32BIT 32-bit Address ADMA2 is selected
 * - SDHC_HC1R_CARDDTL Card Detect Test Level
 *  +      SDHC_HC1R_CARDDTL_NO No Card
 *  +      SDHC_HC1R_CARDDTL_YES Card Inserted
 * - SDHC_HC1R_CARDDSEL Card Detect Signal Selection
 *  +      SDHC_HC1R_CARDDSEL_NORMAL SDCD# is selected (for normal use)
 *  +      SDHC_HC1R_CARDDSEL_TEST The Card Select Test Level is selected (for test purpose)
 * - SDHC_HC1R_EMMC_DW Data Width
 *  +      SDHC_HC1R_EMMC_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_EMMC_DW_4BIT 4-bit mode
 * - SDHC_HC1R_EMMC_HSEN High Speed Enable
 *  +      SDHC_HC1R_EMMC_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_EMMC_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_EMMC_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_EMMC_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_EMMC_DMASEL_1 Reserved
 *  +      SDHC_HC1R_EMMC_DMASEL_32BIT 32-bit Address ADMA2 is selected
 **/
static inline uint8_t sdhc_get_HC1R(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->HC1R.reg & mask);
}

/**
 * @brief sdhc write HC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_HC1R_LEDCTRL LED Control
 *  +      SDHC_HC1R_LEDCTRL_OFF LED off
 *  +      SDHC_HC1R_LEDCTRL_ON LED on
 * - SDHC_HC1R_DW Data Width
 *  +      SDHC_HC1R_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_DW_4BIT 4-bit mode
 * - SDHC_HC1R_HSEN High Speed Enable
 *  +      SDHC_HC1R_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_DMASEL_1 Reserved
 *  +      SDHC_HC1R_DMASEL_32BIT 32-bit Address ADMA2 is selected
 * - SDHC_HC1R_CARDDTL Card Detect Test Level
 *  +      SDHC_HC1R_CARDDTL_NO No Card
 *  +      SDHC_HC1R_CARDDTL_YES Card Inserted
 * - SDHC_HC1R_CARDDSEL Card Detect Signal Selection
 *  +      SDHC_HC1R_CARDDSEL_NORMAL SDCD# is selected (for normal use)
 *  +      SDHC_HC1R_CARDDSEL_TEST The Card Select Test Level is selected (for test purpose)
 * - SDHC_HC1R_EMMC_DW Data Width
 *  +      SDHC_HC1R_EMMC_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_EMMC_DW_4BIT 4-bit mode
 * - SDHC_HC1R_EMMC_HSEN High Speed Enable
 *  +      SDHC_HC1R_EMMC_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_EMMC_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_EMMC_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_EMMC_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_EMMC_DMASEL_1 Reserved
 *  +      SDHC_HC1R_EMMC_DMASEL_32BIT 32-bit Address ADMA2 is selected
 **/
static inline void sdhc_write_HC1R(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->HC1R.reg = data;
}

/**
 * @brief sdhc clear HC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_HC1R_LEDCTRL LED Control
 *  +      SDHC_HC1R_LEDCTRL_OFF LED off
 *  +      SDHC_HC1R_LEDCTRL_ON LED on
 * - SDHC_HC1R_DW Data Width
 *  +      SDHC_HC1R_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_DW_4BIT 4-bit mode
 * - SDHC_HC1R_HSEN High Speed Enable
 *  +      SDHC_HC1R_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_DMASEL_1 Reserved
 *  +      SDHC_HC1R_DMASEL_32BIT 32-bit Address ADMA2 is selected
 * - SDHC_HC1R_CARDDTL Card Detect Test Level
 *  +      SDHC_HC1R_CARDDTL_NO No Card
 *  +      SDHC_HC1R_CARDDTL_YES Card Inserted
 * - SDHC_HC1R_CARDDSEL Card Detect Signal Selection
 *  +      SDHC_HC1R_CARDDSEL_NORMAL SDCD# is selected (for normal use)
 *  +      SDHC_HC1R_CARDDSEL_TEST The Card Select Test Level is selected (for test purpose)
 * - SDHC_HC1R_EMMC_DW Data Width
 *  +      SDHC_HC1R_EMMC_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_EMMC_DW_4BIT 4-bit mode
 * - SDHC_HC1R_EMMC_HSEN High Speed Enable
 *  +      SDHC_HC1R_EMMC_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_EMMC_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_EMMC_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_EMMC_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_EMMC_DMASEL_1 Reserved
 *  +      SDHC_HC1R_EMMC_DMASEL_32BIT 32-bit Address ADMA2 is selected
 **/
static inline void sdhc_clear_HC1R(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->HC1R.reg &= ~mask;
}

/**
 * @brief sdhc read HC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_HC1R_LEDCTRL LED Control
 *  +      SDHC_HC1R_LEDCTRL_OFF LED off
 *  +      SDHC_HC1R_LEDCTRL_ON LED on
 * - SDHC_HC1R_DW Data Width
 *  +      SDHC_HC1R_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_DW_4BIT 4-bit mode
 * - SDHC_HC1R_HSEN High Speed Enable
 *  +      SDHC_HC1R_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_DMASEL_1 Reserved
 *  +      SDHC_HC1R_DMASEL_32BIT 32-bit Address ADMA2 is selected
 * - SDHC_HC1R_CARDDTL Card Detect Test Level
 *  +      SDHC_HC1R_CARDDTL_NO No Card
 *  +      SDHC_HC1R_CARDDTL_YES Card Inserted
 * - SDHC_HC1R_CARDDSEL Card Detect Signal Selection
 *  +      SDHC_HC1R_CARDDSEL_NORMAL SDCD# is selected (for normal use)
 *  +      SDHC_HC1R_CARDDSEL_TEST The Card Select Test Level is selected (for test purpose)
 * - SDHC_HC1R_EMMC_DW Data Width
 *  +      SDHC_HC1R_EMMC_DW_1BIT 1-bit mode
 *  +      SDHC_HC1R_EMMC_DW_4BIT 4-bit mode
 * - SDHC_HC1R_EMMC_HSEN High Speed Enable
 *  +      SDHC_HC1R_EMMC_HSEN_NORMAL Normal Speed mode
 *  +      SDHC_HC1R_EMMC_HSEN_HIGH High Speed mode
 * - SDHC_HC1R_EMMC_DMASEL(value) DMA Select
 *  +      SDHC_HC1R_EMMC_DMASEL_SDMA SDMA is selected
 *  +      SDHC_HC1R_EMMC_DMASEL_1 Reserved
 *  +      SDHC_HC1R_EMMC_DMASEL_32BIT 32-bit Address ADMA2 is selected
 **/
static inline uint8_t sdhc_read_HC1R(SDHC_t *pSDHC)
{
	return pSDHC->HC1R.reg;
}

/**
 * @brief sdhc set BGCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_BGCR_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_STPBGR_STOP Stop
 * - SDHC_BGCR_CONTR Continue Request
 *  +      SDHC_BGCR_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_CONTR_RESTART Restart
 * - SDHC_BGCR_RWCTRL Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_DISABLE Disable Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_ENABLE Enable Read Wait Control
 * - SDHC_BGCR_INTBG Interrupt at Block Gap
 *  +      SDHC_BGCR_INTBG_DISABLED Disabled
 *  +      SDHC_BGCR_INTBG_ENABLED Enabled
 * - SDHC_BGCR_EMMC_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_EMMC_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_EMMC_STPBGR_STOP Stop
 * - SDHC_BGCR_EMMC_CONTR Continue Request
 *  +      SDHC_BGCR_EMMC_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_EMMC_CONTR_RESTART Restart
 **/
static inline void sdhc_set_BGCR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->BGCR.reg |= mask;
}

/**
 * @brief sdhc get BGCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_BGCR_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_STPBGR_STOP Stop
 * - SDHC_BGCR_CONTR Continue Request
 *  +      SDHC_BGCR_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_CONTR_RESTART Restart
 * - SDHC_BGCR_RWCTRL Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_DISABLE Disable Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_ENABLE Enable Read Wait Control
 * - SDHC_BGCR_INTBG Interrupt at Block Gap
 *  +      SDHC_BGCR_INTBG_DISABLED Disabled
 *  +      SDHC_BGCR_INTBG_ENABLED Enabled
 * - SDHC_BGCR_EMMC_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_EMMC_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_EMMC_STPBGR_STOP Stop
 * - SDHC_BGCR_EMMC_CONTR Continue Request
 *  +      SDHC_BGCR_EMMC_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_EMMC_CONTR_RESTART Restart
 **/
static inline uint8_t sdhc_get_BGCR(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->BGCR.reg & mask);
}

/**
 * @brief sdhc write BGCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_BGCR_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_STPBGR_STOP Stop
 * - SDHC_BGCR_CONTR Continue Request
 *  +      SDHC_BGCR_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_CONTR_RESTART Restart
 * - SDHC_BGCR_RWCTRL Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_DISABLE Disable Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_ENABLE Enable Read Wait Control
 * - SDHC_BGCR_INTBG Interrupt at Block Gap
 *  +      SDHC_BGCR_INTBG_DISABLED Disabled
 *  +      SDHC_BGCR_INTBG_ENABLED Enabled
 * - SDHC_BGCR_EMMC_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_EMMC_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_EMMC_STPBGR_STOP Stop
 * - SDHC_BGCR_EMMC_CONTR Continue Request
 *  +      SDHC_BGCR_EMMC_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_EMMC_CONTR_RESTART Restart
 **/
static inline void sdhc_write_BGCR(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->BGCR.reg = data;
}

/**
 * @brief sdhc clear BGCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_BGCR_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_STPBGR_STOP Stop
 * - SDHC_BGCR_CONTR Continue Request
 *  +      SDHC_BGCR_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_CONTR_RESTART Restart
 * - SDHC_BGCR_RWCTRL Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_DISABLE Disable Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_ENABLE Enable Read Wait Control
 * - SDHC_BGCR_INTBG Interrupt at Block Gap
 *  +      SDHC_BGCR_INTBG_DISABLED Disabled
 *  +      SDHC_BGCR_INTBG_ENABLED Enabled
 * - SDHC_BGCR_EMMC_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_EMMC_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_EMMC_STPBGR_STOP Stop
 * - SDHC_BGCR_EMMC_CONTR Continue Request
 *  +      SDHC_BGCR_EMMC_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_EMMC_CONTR_RESTART Restart
 **/
static inline void sdhc_clear_BGCR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->BGCR.reg &= ~mask;
}

/**
 * @brief sdhc read BGCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_BGCR_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_STPBGR_STOP Stop
 * - SDHC_BGCR_CONTR Continue Request
 *  +      SDHC_BGCR_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_CONTR_RESTART Restart
 * - SDHC_BGCR_RWCTRL Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_DISABLE Disable Read Wait Control
 *  +      SDHC_BGCR_RWCTRL_ENABLE Enable Read Wait Control
 * - SDHC_BGCR_INTBG Interrupt at Block Gap
 *  +      SDHC_BGCR_INTBG_DISABLED Disabled
 *  +      SDHC_BGCR_INTBG_ENABLED Enabled
 * - SDHC_BGCR_EMMC_STPBGR Stop at Block Gap Request
 *  +      SDHC_BGCR_EMMC_STPBGR_TRANSFER Transfer
 *  +      SDHC_BGCR_EMMC_STPBGR_STOP Stop
 * - SDHC_BGCR_EMMC_CONTR Continue Request
 *  +      SDHC_BGCR_EMMC_CONTR_GO_ON Not affected
 *  +      SDHC_BGCR_EMMC_CONTR_RESTART Restart
 **/
static inline uint8_t sdhc_read_BGCR(SDHC_t *pSDHC)
{
	return pSDHC->BGCR.reg;
}

/**
 * @brief sdhc set NISTR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_NISTR_CMDC Command Complete
 *  +      SDHC_NISTR_CMDC_NO No command complete
 *  +      SDHC_NISTR_CMDC_YES Command complete
 * - SDHC_NISTR_TRFC Transfer Complete
 *  +      SDHC_NISTR_TRFC_NO Not complete
 *  +      SDHC_NISTR_TRFC_YES Command execution is completed
 * - SDHC_NISTR_BLKGE Block Gap Event
 *  +      SDHC_NISTR_BLKGE_NO No Block Gap Event
 *  +      SDHC_NISTR_BLKGE_STOP Transaction stopped at block gap
 * - SDHC_NISTR_DMAINT DMA Interrupt
 *  +      SDHC_NISTR_DMAINT_NO No DMA Interrupt
 *  +      SDHC_NISTR_DMAINT_YES DMA Interrupt is generated
 * - SDHC_NISTR_BWRRDY Buffer Write Ready
 *  +      SDHC_NISTR_BWRRDY_NO Not ready to write buffer
 *  +      SDHC_NISTR_BWRRDY_YES Ready to write buffer
 * - SDHC_NISTR_BRDRDY Buffer Read Ready
 *  +      SDHC_NISTR_BRDRDY_NO Not ready to read buffer
 *  +      SDHC_NISTR_BRDRDY_YES Ready to read buffer
 * - SDHC_NISTR_CINS Card Insertion
 *  +      SDHC_NISTR_CINS_NO Card state stable or Debouncing
 *  +      SDHC_NISTR_CINS_YES Card inserted
 * - SDHC_NISTR_CREM Card Removal
 *  +      SDHC_NISTR_CREM_NO Card state stable or Debouncing
 *  +      SDHC_NISTR_CREM_YES Card Removed
 * - SDHC_NISTR_CINT Card Interrupt
 *  +      SDHC_NISTR_CINT_NO No Card Interrupt
 *  +      SDHC_NISTR_CINT_YES Generate Card Interrupt
 * - SDHC_NISTR_ERRINT Error Interrupt
 *  +      SDHC_NISTR_ERRINT_NO No Error
 *  +      SDHC_NISTR_ERRINT_YES Error
 * - SDHC_NISTR_EMMC_CMDC Command Complete
 *  +      SDHC_NISTR_EMMC_CMDC_NO No command complete
 *  +      SDHC_NISTR_EMMC_CMDC_YES Command complete
 * - SDHC_NISTR_EMMC_TRFC Transfer Complete
 *  +      SDHC_NISTR_EMMC_TRFC_NO Not complete
 *  +      SDHC_NISTR_EMMC_TRFC_YES Command execution is completed
 * - SDHC_NISTR_EMMC_BLKGE Block Gap Event
 *  +      SDHC_NISTR_EMMC_BLKGE_NO No Block Gap Event
 *  +      SDHC_NISTR_EMMC_BLKGE_STOP Transaction stopped at block gap
 * - SDHC_NISTR_EMMC_DMAINT DMA Interrupt
 *  +      SDHC_NISTR_EMMC_DMAINT_NO No DMA Interrupt
 *  +      SDHC_NISTR_EMMC_DMAINT_YES DMA Interrupt is generated
 * - SDHC_NISTR_EMMC_BWRRDY Buffer Write Ready
 *  +      SDHC_NISTR_EMMC_BWRRDY_NO Not ready to write buffer
 *  +      SDHC_NISTR_EMMC_BWRRDY_YES Ready to write buffer
 * - SDHC_NISTR_EMMC_BRDRDY Buffer Read Ready
 *  +      SDHC_NISTR_EMMC_BRDRDY_NO Not ready to read buffer
 *  +      SDHC_NISTR_EMMC_BRDRDY_YES Ready to read buffer
 * - SDHC_NISTR_EMMC_BOOTAR Boot Acknowledge Received
 * - SDHC_NISTR_EMMC_ERRINT Error Interrupt
 *  +      SDHC_NISTR_EMMC_ERRINT_NO No Error
 *  +      SDHC_NISTR_EMMC_ERRINT_YES Error
 **/
static inline void sdhc_set_NISTR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->NISTR.reg |= mask;
}

/**
 * @brief sdhc get NISTR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_NISTR_CMDC Command Complete
 *  +      SDHC_NISTR_CMDC_NO No command complete
 *  +      SDHC_NISTR_CMDC_YES Command complete
 * - SDHC_NISTR_TRFC Transfer Complete
 *  +      SDHC_NISTR_TRFC_NO Not complete
 *  +      SDHC_NISTR_TRFC_YES Command execution is completed
 * - SDHC_NISTR_BLKGE Block Gap Event
 *  +      SDHC_NISTR_BLKGE_NO No Block Gap Event
 *  +      SDHC_NISTR_BLKGE_STOP Transaction stopped at block gap
 * - SDHC_NISTR_DMAINT DMA Interrupt
 *  +      SDHC_NISTR_DMAINT_NO No DMA Interrupt
 *  +      SDHC_NISTR_DMAINT_YES DMA Interrupt is generated
 * - SDHC_NISTR_BWRRDY Buffer Write Ready
 *  +      SDHC_NISTR_BWRRDY_NO Not ready to write buffer
 *  +      SDHC_NISTR_BWRRDY_YES Ready to write buffer
 * - SDHC_NISTR_BRDRDY Buffer Read Ready
 *  +      SDHC_NISTR_BRDRDY_NO Not ready to read buffer
 *  +      SDHC_NISTR_BRDRDY_YES Ready to read buffer
 * - SDHC_NISTR_CINS Card Insertion
 *  +      SDHC_NISTR_CINS_NO Card state stable or Debouncing
 *  +      SDHC_NISTR_CINS_YES Card inserted
 * - SDHC_NISTR_CREM Card Removal
 *  +      SDHC_NISTR_CREM_NO Card state stable or Debouncing
 *  +      SDHC_NISTR_CREM_YES Card Removed
 * - SDHC_NISTR_CINT Card Interrupt
 *  +      SDHC_NISTR_CINT_NO No Card Interrupt
 *  +      SDHC_NISTR_CINT_YES Generate Card Interrupt
 * - SDHC_NISTR_ERRINT Error Interrupt
 *  +      SDHC_NISTR_ERRINT_NO No Error
 *  +      SDHC_NISTR_ERRINT_YES Error
 * - SDHC_NISTR_EMMC_CMDC Command Complete
 *  +      SDHC_NISTR_EMMC_CMDC_NO No command complete
 *  +      SDHC_NISTR_EMMC_CMDC_YES Command complete
 * - SDHC_NISTR_EMMC_TRFC Transfer Complete
 *  +      SDHC_NISTR_EMMC_TRFC_NO Not complete
 *  +      SDHC_NISTR_EMMC_TRFC_YES Command execution is completed
 * - SDHC_NISTR_EMMC_BLKGE Block Gap Event
 *  +      SDHC_NISTR_EMMC_BLKGE_NO No Block Gap Event
 *  +      SDHC_NISTR_EMMC_BLKGE_STOP Transaction stopped at block gap
 * - SDHC_NISTR_EMMC_DMAINT DMA Interrupt
 *  +      SDHC_NISTR_EMMC_DMAINT_NO No DMA Interrupt
 *  +      SDHC_NISTR_EMMC_DMAINT_YES DMA Interrupt is generated
 * - SDHC_NISTR_EMMC_BWRRDY Buffer Write Ready
 *  +      SDHC_NISTR_EMMC_BWRRDY_NO Not ready to write buffer
 *  +      SDHC_NISTR_EMMC_BWRRDY_YES Ready to write buffer
 * - SDHC_NISTR_EMMC_BRDRDY Buffer Read Ready
 *  +      SDHC_NISTR_EMMC_BRDRDY_NO Not ready to read buffer
 *  +      SDHC_NISTR_EMMC_BRDRDY_YES Ready to read buffer
 * - SDHC_NISTR_EMMC_BOOTAR Boot Acknowledge Received
 * - SDHC_NISTR_EMMC_ERRINT Error Interrupt
 *  +      SDHC_NISTR_EMMC_ERRINT_NO No Error
 *  +      SDHC_NISTR_EMMC_ERRINT_YES Error
 **/
static inline uint16_t sdhc_get_NISTR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->NISTR.reg & mask);
}

/**
 * @brief sdhc write NISTR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_NISTR_CMDC Command Complete
 *  +      SDHC_NISTR_CMDC_NO No command complete
 *  +      SDHC_NISTR_CMDC_YES Command complete
 * - SDHC_NISTR_TRFC Transfer Complete
 *  +      SDHC_NISTR_TRFC_NO Not complete
 *  +      SDHC_NISTR_TRFC_YES Command execution is completed
 * - SDHC_NISTR_BLKGE Block Gap Event
 *  +      SDHC_NISTR_BLKGE_NO No Block Gap Event
 *  +      SDHC_NISTR_BLKGE_STOP Transaction stopped at block gap
 * - SDHC_NISTR_DMAINT DMA Interrupt
 *  +      SDHC_NISTR_DMAINT_NO No DMA Interrupt
 *  +      SDHC_NISTR_DMAINT_YES DMA Interrupt is generated
 * - SDHC_NISTR_BWRRDY Buffer Write Ready
 *  +      SDHC_NISTR_BWRRDY_NO Not ready to write buffer
 *  +      SDHC_NISTR_BWRRDY_YES Ready to write buffer
 * - SDHC_NISTR_BRDRDY Buffer Read Ready
 *  +      SDHC_NISTR_BRDRDY_NO Not ready to read buffer
 *  +      SDHC_NISTR_BRDRDY_YES Ready to read buffer
 * - SDHC_NISTR_CINS Card Insertion
 *  +      SDHC_NISTR_CINS_NO Card state stable or Debouncing
 *  +      SDHC_NISTR_CINS_YES Card inserted
 * - SDHC_NISTR_CREM Card Removal
 *  +      SDHC_NISTR_CREM_NO Card state stable or Debouncing
 *  +      SDHC_NISTR_CREM_YES Card Removed
 * - SDHC_NISTR_CINT Card Interrupt
 *  +      SDHC_NISTR_CINT_NO No Card Interrupt
 *  +      SDHC_NISTR_CINT_YES Generate Card Interrupt
 * - SDHC_NISTR_ERRINT Error Interrupt
 *  +      SDHC_NISTR_ERRINT_NO No Error
 *  +      SDHC_NISTR_ERRINT_YES Error
 * - SDHC_NISTR_EMMC_CMDC Command Complete
 *  +      SDHC_NISTR_EMMC_CMDC_NO No command complete
 *  +      SDHC_NISTR_EMMC_CMDC_YES Command complete
 * - SDHC_NISTR_EMMC_TRFC Transfer Complete
 *  +      SDHC_NISTR_EMMC_TRFC_NO Not complete
 *  +      SDHC_NISTR_EMMC_TRFC_YES Command execution is completed
 * - SDHC_NISTR_EMMC_BLKGE Block Gap Event
 *  +      SDHC_NISTR_EMMC_BLKGE_NO No Block Gap Event
 *  +      SDHC_NISTR_EMMC_BLKGE_STOP Transaction stopped at block gap
 * - SDHC_NISTR_EMMC_DMAINT DMA Interrupt
 *  +      SDHC_NISTR_EMMC_DMAINT_NO No DMA Interrupt
 *  +      SDHC_NISTR_EMMC_DMAINT_YES DMA Interrupt is generated
 * - SDHC_NISTR_EMMC_BWRRDY Buffer Write Ready
 *  +      SDHC_NISTR_EMMC_BWRRDY_NO Not ready to write buffer
 *  +      SDHC_NISTR_EMMC_BWRRDY_YES Ready to write buffer
 * - SDHC_NISTR_EMMC_BRDRDY Buffer Read Ready
 *  +      SDHC_NISTR_EMMC_BRDRDY_NO Not ready to read buffer
 *  +      SDHC_NISTR_EMMC_BRDRDY_YES Ready to read buffer
 * - SDHC_NISTR_EMMC_BOOTAR Boot Acknowledge Received
 * - SDHC_NISTR_EMMC_ERRINT Error Interrupt
 *  +      SDHC_NISTR_EMMC_ERRINT_NO No Error
 *  +      SDHC_NISTR_EMMC_ERRINT_YES Error
 **/
static inline void sdhc_write_NISTR(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->NISTR.reg = data;
}

/**
 * @brief sdhc read NISTR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_NISTR_CMDC Command Complete
 *  +      SDHC_NISTR_CMDC_NO No command complete
 *  +      SDHC_NISTR_CMDC_YES Command complete
 * - SDHC_NISTR_TRFC Transfer Complete
 *  +      SDHC_NISTR_TRFC_NO Not complete
 *  +      SDHC_NISTR_TRFC_YES Command execution is completed
 * - SDHC_NISTR_BLKGE Block Gap Event
 *  +      SDHC_NISTR_BLKGE_NO No Block Gap Event
 *  +      SDHC_NISTR_BLKGE_STOP Transaction stopped at block gap
 * - SDHC_NISTR_DMAINT DMA Interrupt
 *  +      SDHC_NISTR_DMAINT_NO No DMA Interrupt
 *  +      SDHC_NISTR_DMAINT_YES DMA Interrupt is generated
 * - SDHC_NISTR_BWRRDY Buffer Write Ready
 *  +      SDHC_NISTR_BWRRDY_NO Not ready to write buffer
 *  +      SDHC_NISTR_BWRRDY_YES Ready to write buffer
 * - SDHC_NISTR_BRDRDY Buffer Read Ready
 *  +      SDHC_NISTR_BRDRDY_NO Not ready to read buffer
 *  +      SDHC_NISTR_BRDRDY_YES Ready to read buffer
 * - SDHC_NISTR_CINS Card Insertion
 *  +      SDHC_NISTR_CINS_NO Card state stable or Debouncing
 *  +      SDHC_NISTR_CINS_YES Card inserted
 * - SDHC_NISTR_CREM Card Removal
 *  +      SDHC_NISTR_CREM_NO Card state stable or Debouncing
 *  +      SDHC_NISTR_CREM_YES Card Removed
 * - SDHC_NISTR_CINT Card Interrupt
 *  +      SDHC_NISTR_CINT_NO No Card Interrupt
 *  +      SDHC_NISTR_CINT_YES Generate Card Interrupt
 * - SDHC_NISTR_ERRINT Error Interrupt
 *  +      SDHC_NISTR_ERRINT_NO No Error
 *  +      SDHC_NISTR_ERRINT_YES Error
 * - SDHC_NISTR_EMMC_CMDC Command Complete
 *  +      SDHC_NISTR_EMMC_CMDC_NO No command complete
 *  +      SDHC_NISTR_EMMC_CMDC_YES Command complete
 * - SDHC_NISTR_EMMC_TRFC Transfer Complete
 *  +      SDHC_NISTR_EMMC_TRFC_NO Not complete
 *  +      SDHC_NISTR_EMMC_TRFC_YES Command execution is completed
 * - SDHC_NISTR_EMMC_BLKGE Block Gap Event
 *  +      SDHC_NISTR_EMMC_BLKGE_NO No Block Gap Event
 *  +      SDHC_NISTR_EMMC_BLKGE_STOP Transaction stopped at block gap
 * - SDHC_NISTR_EMMC_DMAINT DMA Interrupt
 *  +      SDHC_NISTR_EMMC_DMAINT_NO No DMA Interrupt
 *  +      SDHC_NISTR_EMMC_DMAINT_YES DMA Interrupt is generated
 * - SDHC_NISTR_EMMC_BWRRDY Buffer Write Ready
 *  +      SDHC_NISTR_EMMC_BWRRDY_NO Not ready to write buffer
 *  +      SDHC_NISTR_EMMC_BWRRDY_YES Ready to write buffer
 * - SDHC_NISTR_EMMC_BRDRDY Buffer Read Ready
 *  +      SDHC_NISTR_EMMC_BRDRDY_NO Not ready to read buffer
 *  +      SDHC_NISTR_EMMC_BRDRDY_YES Ready to read buffer
 * - SDHC_NISTR_EMMC_BOOTAR Boot Acknowledge Received
 * - SDHC_NISTR_EMMC_ERRINT Error Interrupt
 *  +      SDHC_NISTR_EMMC_ERRINT_NO No Error
 *  +      SDHC_NISTR_EMMC_ERRINT_YES Error
 **/
static inline uint16_t sdhc_read_NISTR(SDHC_t *pSDHC)
{
	return pSDHC->NISTR.reg;
}

/**
 * @brief sdhc set EISTR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_EISTR_CMDTEO Command Timeout Error
 *  +      SDHC_EISTR_CMDTEO_NO No Error
 *  +      SDHC_EISTR_CMDTEO_YES Timeout
 * - SDHC_EISTR_CMDCRC Command CRC Error
 *  +      SDHC_EISTR_CMDCRC_NO No Error
 *  +      SDHC_EISTR_CMDCRC_YES CRC Error Generated
 * - SDHC_EISTR_CMDEND Command End Bit Error
 *  +      SDHC_EISTR_CMDEND_NO No error
 *  +      SDHC_EISTR_CMDEND_YES End Bit Error Generated
 * - SDHC_EISTR_CMDIDX Command Index Error
 *  +      SDHC_EISTR_CMDIDX_NO No Error
 *  +      SDHC_EISTR_CMDIDX_YES Error
 * - SDHC_EISTR_DATTEO Data Timeout Error
 *  +      SDHC_EISTR_DATTEO_NO No Error
 *  +      SDHC_EISTR_DATTEO_YES Timeout
 * - SDHC_EISTR_DATCRC Data CRC Error
 *  +      SDHC_EISTR_DATCRC_NO No Error
 *  +      SDHC_EISTR_DATCRC_YES Error
 * - SDHC_EISTR_DATEND Data End Bit Error
 *  +      SDHC_EISTR_DATEND_NO No Error
 *  +      SDHC_EISTR_DATEND_YES Error
 * - SDHC_EISTR_CURLIM Current Limit Error
 *  +      SDHC_EISTR_CURLIM_NO No Error
 *  +      SDHC_EISTR_CURLIM_YES Power Fail
 * - SDHC_EISTR_ACMD Auto CMD Error
 *  +      SDHC_EISTR_ACMD_NO No Error
 *  +      SDHC_EISTR_ACMD_YES Error
 * - SDHC_EISTR_ADMA ADMA Error
 *  +      SDHC_EISTR_ADMA_NO No Error
 *  +      SDHC_EISTR_ADMA_YES Error
 * - SDHC_EISTR_EMMC_CMDTEO Command Timeout Error
 *  +      SDHC_EISTR_EMMC_CMDTEO_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDTEO_YES Timeout
 * - SDHC_EISTR_EMMC_CMDCRC Command CRC Error
 *  +      SDHC_EISTR_EMMC_CMDCRC_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDCRC_YES CRC Error Generated
 * - SDHC_EISTR_EMMC_CMDEND Command End Bit Error
 *  +      SDHC_EISTR_EMMC_CMDEND_NO No error
 *  +      SDHC_EISTR_EMMC_CMDEND_YES End Bit Error Generated
 * - SDHC_EISTR_EMMC_CMDIDX Command Index Error
 *  +      SDHC_EISTR_EMMC_CMDIDX_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDIDX_YES Error
 * - SDHC_EISTR_EMMC_DATTEO Data Timeout Error
 *  +      SDHC_EISTR_EMMC_DATTEO_NO No Error
 *  +      SDHC_EISTR_EMMC_DATTEO_YES Timeout
 * - SDHC_EISTR_EMMC_DATCRC Data CRC Error
 *  +      SDHC_EISTR_EMMC_DATCRC_NO No Error
 *  +      SDHC_EISTR_EMMC_DATCRC_YES Error
 * - SDHC_EISTR_EMMC_DATEND Data End Bit Error
 *  +      SDHC_EISTR_EMMC_DATEND_NO No Error
 *  +      SDHC_EISTR_EMMC_DATEND_YES Error
 * - SDHC_EISTR_EMMC_CURLIM Current Limit Error
 *  +      SDHC_EISTR_EMMC_CURLIM_NO No Error
 *  +      SDHC_EISTR_EMMC_CURLIM_YES Power Fail
 * - SDHC_EISTR_EMMC_ACMD Auto CMD Error
 *  +      SDHC_EISTR_EMMC_ACMD_NO No Error
 *  +      SDHC_EISTR_EMMC_ACMD_YES Error
 * - SDHC_EISTR_EMMC_ADMA ADMA Error
 *  +      SDHC_EISTR_EMMC_ADMA_NO No Error
 *  +      SDHC_EISTR_EMMC_ADMA_YES Error
 * - SDHC_EISTR_EMMC_BOOTAE Boot Acknowledge Error
 *  +      SDHC_EISTR_EMMC_BOOTAE_0 FIFO contains at least one byte
 *  +      SDHC_EISTR_EMMC_BOOTAE_1 FIFO is empty
 **/
static inline void sdhc_set_EISTR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->EISTR.reg |= mask;
}

/**
 * @brief sdhc get EISTR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_EISTR_CMDTEO Command Timeout Error
 *  +      SDHC_EISTR_CMDTEO_NO No Error
 *  +      SDHC_EISTR_CMDTEO_YES Timeout
 * - SDHC_EISTR_CMDCRC Command CRC Error
 *  +      SDHC_EISTR_CMDCRC_NO No Error
 *  +      SDHC_EISTR_CMDCRC_YES CRC Error Generated
 * - SDHC_EISTR_CMDEND Command End Bit Error
 *  +      SDHC_EISTR_CMDEND_NO No error
 *  +      SDHC_EISTR_CMDEND_YES End Bit Error Generated
 * - SDHC_EISTR_CMDIDX Command Index Error
 *  +      SDHC_EISTR_CMDIDX_NO No Error
 *  +      SDHC_EISTR_CMDIDX_YES Error
 * - SDHC_EISTR_DATTEO Data Timeout Error
 *  +      SDHC_EISTR_DATTEO_NO No Error
 *  +      SDHC_EISTR_DATTEO_YES Timeout
 * - SDHC_EISTR_DATCRC Data CRC Error
 *  +      SDHC_EISTR_DATCRC_NO No Error
 *  +      SDHC_EISTR_DATCRC_YES Error
 * - SDHC_EISTR_DATEND Data End Bit Error
 *  +      SDHC_EISTR_DATEND_NO No Error
 *  +      SDHC_EISTR_DATEND_YES Error
 * - SDHC_EISTR_CURLIM Current Limit Error
 *  +      SDHC_EISTR_CURLIM_NO No Error
 *  +      SDHC_EISTR_CURLIM_YES Power Fail
 * - SDHC_EISTR_ACMD Auto CMD Error
 *  +      SDHC_EISTR_ACMD_NO No Error
 *  +      SDHC_EISTR_ACMD_YES Error
 * - SDHC_EISTR_ADMA ADMA Error
 *  +      SDHC_EISTR_ADMA_NO No Error
 *  +      SDHC_EISTR_ADMA_YES Error
 * - SDHC_EISTR_EMMC_CMDTEO Command Timeout Error
 *  +      SDHC_EISTR_EMMC_CMDTEO_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDTEO_YES Timeout
 * - SDHC_EISTR_EMMC_CMDCRC Command CRC Error
 *  +      SDHC_EISTR_EMMC_CMDCRC_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDCRC_YES CRC Error Generated
 * - SDHC_EISTR_EMMC_CMDEND Command End Bit Error
 *  +      SDHC_EISTR_EMMC_CMDEND_NO No error
 *  +      SDHC_EISTR_EMMC_CMDEND_YES End Bit Error Generated
 * - SDHC_EISTR_EMMC_CMDIDX Command Index Error
 *  +      SDHC_EISTR_EMMC_CMDIDX_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDIDX_YES Error
 * - SDHC_EISTR_EMMC_DATTEO Data Timeout Error
 *  +      SDHC_EISTR_EMMC_DATTEO_NO No Error
 *  +      SDHC_EISTR_EMMC_DATTEO_YES Timeout
 * - SDHC_EISTR_EMMC_DATCRC Data CRC Error
 *  +      SDHC_EISTR_EMMC_DATCRC_NO No Error
 *  +      SDHC_EISTR_EMMC_DATCRC_YES Error
 * - SDHC_EISTR_EMMC_DATEND Data End Bit Error
 *  +      SDHC_EISTR_EMMC_DATEND_NO No Error
 *  +      SDHC_EISTR_EMMC_DATEND_YES Error
 * - SDHC_EISTR_EMMC_CURLIM Current Limit Error
 *  +      SDHC_EISTR_EMMC_CURLIM_NO No Error
 *  +      SDHC_EISTR_EMMC_CURLIM_YES Power Fail
 * - SDHC_EISTR_EMMC_ACMD Auto CMD Error
 *  +      SDHC_EISTR_EMMC_ACMD_NO No Error
 *  +      SDHC_EISTR_EMMC_ACMD_YES Error
 * - SDHC_EISTR_EMMC_ADMA ADMA Error
 *  +      SDHC_EISTR_EMMC_ADMA_NO No Error
 *  +      SDHC_EISTR_EMMC_ADMA_YES Error
 * - SDHC_EISTR_EMMC_BOOTAE Boot Acknowledge Error
 *  +      SDHC_EISTR_EMMC_BOOTAE_0 FIFO contains at least one byte
 *  +      SDHC_EISTR_EMMC_BOOTAE_1 FIFO is empty
 **/
static inline uint16_t sdhc_get_EISTR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->EISTR.reg & mask);
}

/**
 * @brief sdhc write EISTR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_EISTR_CMDTEO Command Timeout Error
 *  +      SDHC_EISTR_CMDTEO_NO No Error
 *  +      SDHC_EISTR_CMDTEO_YES Timeout
 * - SDHC_EISTR_CMDCRC Command CRC Error
 *  +      SDHC_EISTR_CMDCRC_NO No Error
 *  +      SDHC_EISTR_CMDCRC_YES CRC Error Generated
 * - SDHC_EISTR_CMDEND Command End Bit Error
 *  +      SDHC_EISTR_CMDEND_NO No error
 *  +      SDHC_EISTR_CMDEND_YES End Bit Error Generated
 * - SDHC_EISTR_CMDIDX Command Index Error
 *  +      SDHC_EISTR_CMDIDX_NO No Error
 *  +      SDHC_EISTR_CMDIDX_YES Error
 * - SDHC_EISTR_DATTEO Data Timeout Error
 *  +      SDHC_EISTR_DATTEO_NO No Error
 *  +      SDHC_EISTR_DATTEO_YES Timeout
 * - SDHC_EISTR_DATCRC Data CRC Error
 *  +      SDHC_EISTR_DATCRC_NO No Error
 *  +      SDHC_EISTR_DATCRC_YES Error
 * - SDHC_EISTR_DATEND Data End Bit Error
 *  +      SDHC_EISTR_DATEND_NO No Error
 *  +      SDHC_EISTR_DATEND_YES Error
 * - SDHC_EISTR_CURLIM Current Limit Error
 *  +      SDHC_EISTR_CURLIM_NO No Error
 *  +      SDHC_EISTR_CURLIM_YES Power Fail
 * - SDHC_EISTR_ACMD Auto CMD Error
 *  +      SDHC_EISTR_ACMD_NO No Error
 *  +      SDHC_EISTR_ACMD_YES Error
 * - SDHC_EISTR_ADMA ADMA Error
 *  +      SDHC_EISTR_ADMA_NO No Error
 *  +      SDHC_EISTR_ADMA_YES Error
 * - SDHC_EISTR_EMMC_CMDTEO Command Timeout Error
 *  +      SDHC_EISTR_EMMC_CMDTEO_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDTEO_YES Timeout
 * - SDHC_EISTR_EMMC_CMDCRC Command CRC Error
 *  +      SDHC_EISTR_EMMC_CMDCRC_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDCRC_YES CRC Error Generated
 * - SDHC_EISTR_EMMC_CMDEND Command End Bit Error
 *  +      SDHC_EISTR_EMMC_CMDEND_NO No error
 *  +      SDHC_EISTR_EMMC_CMDEND_YES End Bit Error Generated
 * - SDHC_EISTR_EMMC_CMDIDX Command Index Error
 *  +      SDHC_EISTR_EMMC_CMDIDX_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDIDX_YES Error
 * - SDHC_EISTR_EMMC_DATTEO Data Timeout Error
 *  +      SDHC_EISTR_EMMC_DATTEO_NO No Error
 *  +      SDHC_EISTR_EMMC_DATTEO_YES Timeout
 * - SDHC_EISTR_EMMC_DATCRC Data CRC Error
 *  +      SDHC_EISTR_EMMC_DATCRC_NO No Error
 *  +      SDHC_EISTR_EMMC_DATCRC_YES Error
 * - SDHC_EISTR_EMMC_DATEND Data End Bit Error
 *  +      SDHC_EISTR_EMMC_DATEND_NO No Error
 *  +      SDHC_EISTR_EMMC_DATEND_YES Error
 * - SDHC_EISTR_EMMC_CURLIM Current Limit Error
 *  +      SDHC_EISTR_EMMC_CURLIM_NO No Error
 *  +      SDHC_EISTR_EMMC_CURLIM_YES Power Fail
 * - SDHC_EISTR_EMMC_ACMD Auto CMD Error
 *  +      SDHC_EISTR_EMMC_ACMD_NO No Error
 *  +      SDHC_EISTR_EMMC_ACMD_YES Error
 * - SDHC_EISTR_EMMC_ADMA ADMA Error
 *  +      SDHC_EISTR_EMMC_ADMA_NO No Error
 *  +      SDHC_EISTR_EMMC_ADMA_YES Error
 * - SDHC_EISTR_EMMC_BOOTAE Boot Acknowledge Error
 *  +      SDHC_EISTR_EMMC_BOOTAE_0 FIFO contains at least one byte
 *  +      SDHC_EISTR_EMMC_BOOTAE_1 FIFO is empty
 **/
static inline void sdhc_write_EISTR(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->EISTR.reg = data;
}

/**
 * @brief sdhc read EISTR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_EISTR_CMDTEO Command Timeout Error
 *  +      SDHC_EISTR_CMDTEO_NO No Error
 *  +      SDHC_EISTR_CMDTEO_YES Timeout
 * - SDHC_EISTR_CMDCRC Command CRC Error
 *  +      SDHC_EISTR_CMDCRC_NO No Error
 *  +      SDHC_EISTR_CMDCRC_YES CRC Error Generated
 * - SDHC_EISTR_CMDEND Command End Bit Error
 *  +      SDHC_EISTR_CMDEND_NO No error
 *  +      SDHC_EISTR_CMDEND_YES End Bit Error Generated
 * - SDHC_EISTR_CMDIDX Command Index Error
 *  +      SDHC_EISTR_CMDIDX_NO No Error
 *  +      SDHC_EISTR_CMDIDX_YES Error
 * - SDHC_EISTR_DATTEO Data Timeout Error
 *  +      SDHC_EISTR_DATTEO_NO No Error
 *  +      SDHC_EISTR_DATTEO_YES Timeout
 * - SDHC_EISTR_DATCRC Data CRC Error
 *  +      SDHC_EISTR_DATCRC_NO No Error
 *  +      SDHC_EISTR_DATCRC_YES Error
 * - SDHC_EISTR_DATEND Data End Bit Error
 *  +      SDHC_EISTR_DATEND_NO No Error
 *  +      SDHC_EISTR_DATEND_YES Error
 * - SDHC_EISTR_CURLIM Current Limit Error
 *  +      SDHC_EISTR_CURLIM_NO No Error
 *  +      SDHC_EISTR_CURLIM_YES Power Fail
 * - SDHC_EISTR_ACMD Auto CMD Error
 *  +      SDHC_EISTR_ACMD_NO No Error
 *  +      SDHC_EISTR_ACMD_YES Error
 * - SDHC_EISTR_ADMA ADMA Error
 *  +      SDHC_EISTR_ADMA_NO No Error
 *  +      SDHC_EISTR_ADMA_YES Error
 * - SDHC_EISTR_EMMC_CMDTEO Command Timeout Error
 *  +      SDHC_EISTR_EMMC_CMDTEO_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDTEO_YES Timeout
 * - SDHC_EISTR_EMMC_CMDCRC Command CRC Error
 *  +      SDHC_EISTR_EMMC_CMDCRC_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDCRC_YES CRC Error Generated
 * - SDHC_EISTR_EMMC_CMDEND Command End Bit Error
 *  +      SDHC_EISTR_EMMC_CMDEND_NO No error
 *  +      SDHC_EISTR_EMMC_CMDEND_YES End Bit Error Generated
 * - SDHC_EISTR_EMMC_CMDIDX Command Index Error
 *  +      SDHC_EISTR_EMMC_CMDIDX_NO No Error
 *  +      SDHC_EISTR_EMMC_CMDIDX_YES Error
 * - SDHC_EISTR_EMMC_DATTEO Data Timeout Error
 *  +      SDHC_EISTR_EMMC_DATTEO_NO No Error
 *  +      SDHC_EISTR_EMMC_DATTEO_YES Timeout
 * - SDHC_EISTR_EMMC_DATCRC Data CRC Error
 *  +      SDHC_EISTR_EMMC_DATCRC_NO No Error
 *  +      SDHC_EISTR_EMMC_DATCRC_YES Error
 * - SDHC_EISTR_EMMC_DATEND Data End Bit Error
 *  +      SDHC_EISTR_EMMC_DATEND_NO No Error
 *  +      SDHC_EISTR_EMMC_DATEND_YES Error
 * - SDHC_EISTR_EMMC_CURLIM Current Limit Error
 *  +      SDHC_EISTR_EMMC_CURLIM_NO No Error
 *  +      SDHC_EISTR_EMMC_CURLIM_YES Power Fail
 * - SDHC_EISTR_EMMC_ACMD Auto CMD Error
 *  +      SDHC_EISTR_EMMC_ACMD_NO No Error
 *  +      SDHC_EISTR_EMMC_ACMD_YES Error
 * - SDHC_EISTR_EMMC_ADMA ADMA Error
 *  +      SDHC_EISTR_EMMC_ADMA_NO No Error
 *  +      SDHC_EISTR_EMMC_ADMA_YES Error
 * - SDHC_EISTR_EMMC_BOOTAE Boot Acknowledge Error
 *  +      SDHC_EISTR_EMMC_BOOTAE_0 FIFO contains at least one byte
 *  +      SDHC_EISTR_EMMC_BOOTAE_1 FIFO is empty
 **/
static inline uint16_t sdhc_read_EISTR(SDHC_t *pSDHC)
{
	return pSDHC->EISTR.reg;
}

/**
 * @brief sdhc set NISTER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_NISTER_CMDC Command Complete Status Enable
 *  +      SDHC_NISTER_CMDC_MASKED Masked
 *  +      SDHC_NISTER_CMDC_ENABLED Enabled
 * - SDHC_NISTER_TRFC Transfer Complete Status Enable
 *  +      SDHC_NISTER_TRFC_MASKED Masked
 *  +      SDHC_NISTER_TRFC_ENABLED Enabled
 * - SDHC_NISTER_BLKGE Block Gap Event Status Enable
 *  +      SDHC_NISTER_BLKGE_MASKED Masked
 *  +      SDHC_NISTER_BLKGE_ENABLED Enabled
 * - SDHC_NISTER_DMAINT DMA Interrupt Status Enable
 *  +      SDHC_NISTER_DMAINT_MASKED Masked
 *  +      SDHC_NISTER_DMAINT_ENABLED Enabled
 * - SDHC_NISTER_BWRRDY Buffer Write Ready Status Enable
 *  +      SDHC_NISTER_BWRRDY_MASKED Masked
 *  +      SDHC_NISTER_BWRRDY_ENABLED Enabled
 * - SDHC_NISTER_BRDRDY Buffer Read Ready Status Enable
 *  +      SDHC_NISTER_BRDRDY_MASKED Masked
 *  +      SDHC_NISTER_BRDRDY_ENABLED Enabled
 * - SDHC_NISTER_CINS Card Insertion Status Enable
 *  +      SDHC_NISTER_CINS_MASKED Masked
 *  +      SDHC_NISTER_CINS_ENABLED Enabled
 * - SDHC_NISTER_CREM Card Removal Status Enable
 *  +      SDHC_NISTER_CREM_MASKED Masked
 *  +      SDHC_NISTER_CREM_ENABLED Enabled
 * - SDHC_NISTER_CINT Card Interrupt Status Enable
 *  +      SDHC_NISTER_CINT_MASKED Masked
 *  +      SDHC_NISTER_CINT_ENABLED Enabled
 * - SDHC_NISTER_EMMC_CMDC Command Complete Status Enable
 *  +      SDHC_NISTER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISTER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISTER_EMMC_TRFC Transfer Complete Status Enable
 *  +      SDHC_NISTER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISTER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BLKGE Block Gap Event Status Enable
 *  +      SDHC_NISTER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISTER_EMMC_DMAINT DMA Interrupt Status Enable
 *  +      SDHC_NISTER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISTER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BWRRDY Buffer Write Ready Status Enable
 *  +      SDHC_NISTER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BRDRDY Buffer Read Ready Status Enable
 *  +      SDHC_NISTER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BOOTAR Boot Acknowledge Received Status Enable
 **/
static inline void sdhc_set_NISTER(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->NISTER.reg |= mask;
}

/**
 * @brief sdhc get NISTER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_NISTER_CMDC Command Complete Status Enable
 *  +      SDHC_NISTER_CMDC_MASKED Masked
 *  +      SDHC_NISTER_CMDC_ENABLED Enabled
 * - SDHC_NISTER_TRFC Transfer Complete Status Enable
 *  +      SDHC_NISTER_TRFC_MASKED Masked
 *  +      SDHC_NISTER_TRFC_ENABLED Enabled
 * - SDHC_NISTER_BLKGE Block Gap Event Status Enable
 *  +      SDHC_NISTER_BLKGE_MASKED Masked
 *  +      SDHC_NISTER_BLKGE_ENABLED Enabled
 * - SDHC_NISTER_DMAINT DMA Interrupt Status Enable
 *  +      SDHC_NISTER_DMAINT_MASKED Masked
 *  +      SDHC_NISTER_DMAINT_ENABLED Enabled
 * - SDHC_NISTER_BWRRDY Buffer Write Ready Status Enable
 *  +      SDHC_NISTER_BWRRDY_MASKED Masked
 *  +      SDHC_NISTER_BWRRDY_ENABLED Enabled
 * - SDHC_NISTER_BRDRDY Buffer Read Ready Status Enable
 *  +      SDHC_NISTER_BRDRDY_MASKED Masked
 *  +      SDHC_NISTER_BRDRDY_ENABLED Enabled
 * - SDHC_NISTER_CINS Card Insertion Status Enable
 *  +      SDHC_NISTER_CINS_MASKED Masked
 *  +      SDHC_NISTER_CINS_ENABLED Enabled
 * - SDHC_NISTER_CREM Card Removal Status Enable
 *  +      SDHC_NISTER_CREM_MASKED Masked
 *  +      SDHC_NISTER_CREM_ENABLED Enabled
 * - SDHC_NISTER_CINT Card Interrupt Status Enable
 *  +      SDHC_NISTER_CINT_MASKED Masked
 *  +      SDHC_NISTER_CINT_ENABLED Enabled
 * - SDHC_NISTER_EMMC_CMDC Command Complete Status Enable
 *  +      SDHC_NISTER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISTER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISTER_EMMC_TRFC Transfer Complete Status Enable
 *  +      SDHC_NISTER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISTER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BLKGE Block Gap Event Status Enable
 *  +      SDHC_NISTER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISTER_EMMC_DMAINT DMA Interrupt Status Enable
 *  +      SDHC_NISTER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISTER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BWRRDY Buffer Write Ready Status Enable
 *  +      SDHC_NISTER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BRDRDY Buffer Read Ready Status Enable
 *  +      SDHC_NISTER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BOOTAR Boot Acknowledge Received Status Enable
 **/
static inline uint16_t sdhc_get_NISTER(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->NISTER.reg & mask);
}

/**
 * @brief sdhc write NISTER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_NISTER_CMDC Command Complete Status Enable
 *  +      SDHC_NISTER_CMDC_MASKED Masked
 *  +      SDHC_NISTER_CMDC_ENABLED Enabled
 * - SDHC_NISTER_TRFC Transfer Complete Status Enable
 *  +      SDHC_NISTER_TRFC_MASKED Masked
 *  +      SDHC_NISTER_TRFC_ENABLED Enabled
 * - SDHC_NISTER_BLKGE Block Gap Event Status Enable
 *  +      SDHC_NISTER_BLKGE_MASKED Masked
 *  +      SDHC_NISTER_BLKGE_ENABLED Enabled
 * - SDHC_NISTER_DMAINT DMA Interrupt Status Enable
 *  +      SDHC_NISTER_DMAINT_MASKED Masked
 *  +      SDHC_NISTER_DMAINT_ENABLED Enabled
 * - SDHC_NISTER_BWRRDY Buffer Write Ready Status Enable
 *  +      SDHC_NISTER_BWRRDY_MASKED Masked
 *  +      SDHC_NISTER_BWRRDY_ENABLED Enabled
 * - SDHC_NISTER_BRDRDY Buffer Read Ready Status Enable
 *  +      SDHC_NISTER_BRDRDY_MASKED Masked
 *  +      SDHC_NISTER_BRDRDY_ENABLED Enabled
 * - SDHC_NISTER_CINS Card Insertion Status Enable
 *  +      SDHC_NISTER_CINS_MASKED Masked
 *  +      SDHC_NISTER_CINS_ENABLED Enabled
 * - SDHC_NISTER_CREM Card Removal Status Enable
 *  +      SDHC_NISTER_CREM_MASKED Masked
 *  +      SDHC_NISTER_CREM_ENABLED Enabled
 * - SDHC_NISTER_CINT Card Interrupt Status Enable
 *  +      SDHC_NISTER_CINT_MASKED Masked
 *  +      SDHC_NISTER_CINT_ENABLED Enabled
 * - SDHC_NISTER_EMMC_CMDC Command Complete Status Enable
 *  +      SDHC_NISTER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISTER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISTER_EMMC_TRFC Transfer Complete Status Enable
 *  +      SDHC_NISTER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISTER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BLKGE Block Gap Event Status Enable
 *  +      SDHC_NISTER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISTER_EMMC_DMAINT DMA Interrupt Status Enable
 *  +      SDHC_NISTER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISTER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BWRRDY Buffer Write Ready Status Enable
 *  +      SDHC_NISTER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BRDRDY Buffer Read Ready Status Enable
 *  +      SDHC_NISTER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BOOTAR Boot Acknowledge Received Status Enable
 **/
static inline void sdhc_write_NISTER(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->NISTER.reg = data;
}

/**
 * @brief sdhc read NISTER register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_NISTER_CMDC Command Complete Status Enable
 *  +      SDHC_NISTER_CMDC_MASKED Masked
 *  +      SDHC_NISTER_CMDC_ENABLED Enabled
 * - SDHC_NISTER_TRFC Transfer Complete Status Enable
 *  +      SDHC_NISTER_TRFC_MASKED Masked
 *  +      SDHC_NISTER_TRFC_ENABLED Enabled
 * - SDHC_NISTER_BLKGE Block Gap Event Status Enable
 *  +      SDHC_NISTER_BLKGE_MASKED Masked
 *  +      SDHC_NISTER_BLKGE_ENABLED Enabled
 * - SDHC_NISTER_DMAINT DMA Interrupt Status Enable
 *  +      SDHC_NISTER_DMAINT_MASKED Masked
 *  +      SDHC_NISTER_DMAINT_ENABLED Enabled
 * - SDHC_NISTER_BWRRDY Buffer Write Ready Status Enable
 *  +      SDHC_NISTER_BWRRDY_MASKED Masked
 *  +      SDHC_NISTER_BWRRDY_ENABLED Enabled
 * - SDHC_NISTER_BRDRDY Buffer Read Ready Status Enable
 *  +      SDHC_NISTER_BRDRDY_MASKED Masked
 *  +      SDHC_NISTER_BRDRDY_ENABLED Enabled
 * - SDHC_NISTER_CINS Card Insertion Status Enable
 *  +      SDHC_NISTER_CINS_MASKED Masked
 *  +      SDHC_NISTER_CINS_ENABLED Enabled
 * - SDHC_NISTER_CREM Card Removal Status Enable
 *  +      SDHC_NISTER_CREM_MASKED Masked
 *  +      SDHC_NISTER_CREM_ENABLED Enabled
 * - SDHC_NISTER_CINT Card Interrupt Status Enable
 *  +      SDHC_NISTER_CINT_MASKED Masked
 *  +      SDHC_NISTER_CINT_ENABLED Enabled
 * - SDHC_NISTER_EMMC_CMDC Command Complete Status Enable
 *  +      SDHC_NISTER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISTER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISTER_EMMC_TRFC Transfer Complete Status Enable
 *  +      SDHC_NISTER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISTER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BLKGE Block Gap Event Status Enable
 *  +      SDHC_NISTER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISTER_EMMC_DMAINT DMA Interrupt Status Enable
 *  +      SDHC_NISTER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISTER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BWRRDY Buffer Write Ready Status Enable
 *  +      SDHC_NISTER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BRDRDY Buffer Read Ready Status Enable
 *  +      SDHC_NISTER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISTER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISTER_EMMC_BOOTAR Boot Acknowledge Received Status Enable
 **/
static inline uint16_t sdhc_read_NISTER(SDHC_t *pSDHC)
{
	return pSDHC->NISTER.reg;
}

/**
 * @brief sdhc set EISTER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_EISTER_CMDTEO Command Timeout Error Status Enable
 *  +      SDHC_EISTER_CMDTEO_MASKED Masked
 *  +      SDHC_EISTER_CMDTEO_ENABLED Enabled
 * - SDHC_EISTER_CMDCRC Command CRC Error Status Enable
 *  +      SDHC_EISTER_CMDCRC_MASKED Masked
 *  +      SDHC_EISTER_CMDCRC_ENABLED Enabled
 * - SDHC_EISTER_CMDEND Command End Bit Error Status Enable
 *  +      SDHC_EISTER_CMDEND_MASKED Masked
 *  +      SDHC_EISTER_CMDEND_ENABLED Enabled
 * - SDHC_EISTER_CMDIDX Command Index Error Status Enable
 *  +      SDHC_EISTER_CMDIDX_MASKED Masked
 *  +      SDHC_EISTER_CMDIDX_ENABLED Enabled
 * - SDHC_EISTER_DATTEO Data Timeout Error Status Enable
 *  +      SDHC_EISTER_DATTEO_MASKED Masked
 *  +      SDHC_EISTER_DATTEO_ENABLED Enabled
 * - SDHC_EISTER_DATCRC Data CRC Error Status Enable
 *  +      SDHC_EISTER_DATCRC_MASKED Masked
 *  +      SDHC_EISTER_DATCRC_ENABLED Enabled
 * - SDHC_EISTER_DATEND Data End Bit Error Status Enable
 *  +      SDHC_EISTER_DATEND_MASKED Masked
 *  +      SDHC_EISTER_DATEND_ENABLED Enabled
 * - SDHC_EISTER_CURLIM Current Limit Error Status Enable
 *  +      SDHC_EISTER_CURLIM_MASKED Masked
 *  +      SDHC_EISTER_CURLIM_ENABLED Enabled
 * - SDHC_EISTER_ACMD Auto CMD Error Status Enable
 *  +      SDHC_EISTER_ACMD_MASKED Masked
 *  +      SDHC_EISTER_ACMD_ENABLED Enabled
 * - SDHC_EISTER_ADMA ADMA Error Status Enable
 *  +      SDHC_EISTER_ADMA_MASKED Masked
 *  +      SDHC_EISTER_ADMA_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDTEO Command Timeout Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDCRC Command CRC Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDEND Command End Bit Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDIDX Command Index Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATTEO Data Timeout Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATCRC Data CRC Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATEND Data End Bit Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CURLIM Current Limit Error Status Enable
 *  +      SDHC_EISTER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISTER_EMMC_ACMD Auto CMD Error Status Enable
 *  +      SDHC_EISTER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISTER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISTER_EMMC_ADMA ADMA Error Status Enable
 *  +      SDHC_EISTER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISTER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISTER_EMMC_BOOTAE Boot Acknowledge Error Status Enable
 **/
static inline void sdhc_set_EISTER(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->EISTER.reg |= mask;
}

/**
 * @brief sdhc get EISTER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_EISTER_CMDTEO Command Timeout Error Status Enable
 *  +      SDHC_EISTER_CMDTEO_MASKED Masked
 *  +      SDHC_EISTER_CMDTEO_ENABLED Enabled
 * - SDHC_EISTER_CMDCRC Command CRC Error Status Enable
 *  +      SDHC_EISTER_CMDCRC_MASKED Masked
 *  +      SDHC_EISTER_CMDCRC_ENABLED Enabled
 * - SDHC_EISTER_CMDEND Command End Bit Error Status Enable
 *  +      SDHC_EISTER_CMDEND_MASKED Masked
 *  +      SDHC_EISTER_CMDEND_ENABLED Enabled
 * - SDHC_EISTER_CMDIDX Command Index Error Status Enable
 *  +      SDHC_EISTER_CMDIDX_MASKED Masked
 *  +      SDHC_EISTER_CMDIDX_ENABLED Enabled
 * - SDHC_EISTER_DATTEO Data Timeout Error Status Enable
 *  +      SDHC_EISTER_DATTEO_MASKED Masked
 *  +      SDHC_EISTER_DATTEO_ENABLED Enabled
 * - SDHC_EISTER_DATCRC Data CRC Error Status Enable
 *  +      SDHC_EISTER_DATCRC_MASKED Masked
 *  +      SDHC_EISTER_DATCRC_ENABLED Enabled
 * - SDHC_EISTER_DATEND Data End Bit Error Status Enable
 *  +      SDHC_EISTER_DATEND_MASKED Masked
 *  +      SDHC_EISTER_DATEND_ENABLED Enabled
 * - SDHC_EISTER_CURLIM Current Limit Error Status Enable
 *  +      SDHC_EISTER_CURLIM_MASKED Masked
 *  +      SDHC_EISTER_CURLIM_ENABLED Enabled
 * - SDHC_EISTER_ACMD Auto CMD Error Status Enable
 *  +      SDHC_EISTER_ACMD_MASKED Masked
 *  +      SDHC_EISTER_ACMD_ENABLED Enabled
 * - SDHC_EISTER_ADMA ADMA Error Status Enable
 *  +      SDHC_EISTER_ADMA_MASKED Masked
 *  +      SDHC_EISTER_ADMA_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDTEO Command Timeout Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDCRC Command CRC Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDEND Command End Bit Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDIDX Command Index Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATTEO Data Timeout Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATCRC Data CRC Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATEND Data End Bit Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CURLIM Current Limit Error Status Enable
 *  +      SDHC_EISTER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISTER_EMMC_ACMD Auto CMD Error Status Enable
 *  +      SDHC_EISTER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISTER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISTER_EMMC_ADMA ADMA Error Status Enable
 *  +      SDHC_EISTER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISTER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISTER_EMMC_BOOTAE Boot Acknowledge Error Status Enable
 **/
static inline uint16_t sdhc_get_EISTER(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->EISTER.reg & mask);
}

/**
 * @brief sdhc write EISTER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_EISTER_CMDTEO Command Timeout Error Status Enable
 *  +      SDHC_EISTER_CMDTEO_MASKED Masked
 *  +      SDHC_EISTER_CMDTEO_ENABLED Enabled
 * - SDHC_EISTER_CMDCRC Command CRC Error Status Enable
 *  +      SDHC_EISTER_CMDCRC_MASKED Masked
 *  +      SDHC_EISTER_CMDCRC_ENABLED Enabled
 * - SDHC_EISTER_CMDEND Command End Bit Error Status Enable
 *  +      SDHC_EISTER_CMDEND_MASKED Masked
 *  +      SDHC_EISTER_CMDEND_ENABLED Enabled
 * - SDHC_EISTER_CMDIDX Command Index Error Status Enable
 *  +      SDHC_EISTER_CMDIDX_MASKED Masked
 *  +      SDHC_EISTER_CMDIDX_ENABLED Enabled
 * - SDHC_EISTER_DATTEO Data Timeout Error Status Enable
 *  +      SDHC_EISTER_DATTEO_MASKED Masked
 *  +      SDHC_EISTER_DATTEO_ENABLED Enabled
 * - SDHC_EISTER_DATCRC Data CRC Error Status Enable
 *  +      SDHC_EISTER_DATCRC_MASKED Masked
 *  +      SDHC_EISTER_DATCRC_ENABLED Enabled
 * - SDHC_EISTER_DATEND Data End Bit Error Status Enable
 *  +      SDHC_EISTER_DATEND_MASKED Masked
 *  +      SDHC_EISTER_DATEND_ENABLED Enabled
 * - SDHC_EISTER_CURLIM Current Limit Error Status Enable
 *  +      SDHC_EISTER_CURLIM_MASKED Masked
 *  +      SDHC_EISTER_CURLIM_ENABLED Enabled
 * - SDHC_EISTER_ACMD Auto CMD Error Status Enable
 *  +      SDHC_EISTER_ACMD_MASKED Masked
 *  +      SDHC_EISTER_ACMD_ENABLED Enabled
 * - SDHC_EISTER_ADMA ADMA Error Status Enable
 *  +      SDHC_EISTER_ADMA_MASKED Masked
 *  +      SDHC_EISTER_ADMA_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDTEO Command Timeout Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDCRC Command CRC Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDEND Command End Bit Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDIDX Command Index Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATTEO Data Timeout Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATCRC Data CRC Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATEND Data End Bit Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CURLIM Current Limit Error Status Enable
 *  +      SDHC_EISTER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISTER_EMMC_ACMD Auto CMD Error Status Enable
 *  +      SDHC_EISTER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISTER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISTER_EMMC_ADMA ADMA Error Status Enable
 *  +      SDHC_EISTER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISTER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISTER_EMMC_BOOTAE Boot Acknowledge Error Status Enable
 **/
static inline void sdhc_write_EISTER(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->EISTER.reg = data;
}

/**
 * @brief sdhc read EISTER register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_EISTER_CMDTEO Command Timeout Error Status Enable
 *  +      SDHC_EISTER_CMDTEO_MASKED Masked
 *  +      SDHC_EISTER_CMDTEO_ENABLED Enabled
 * - SDHC_EISTER_CMDCRC Command CRC Error Status Enable
 *  +      SDHC_EISTER_CMDCRC_MASKED Masked
 *  +      SDHC_EISTER_CMDCRC_ENABLED Enabled
 * - SDHC_EISTER_CMDEND Command End Bit Error Status Enable
 *  +      SDHC_EISTER_CMDEND_MASKED Masked
 *  +      SDHC_EISTER_CMDEND_ENABLED Enabled
 * - SDHC_EISTER_CMDIDX Command Index Error Status Enable
 *  +      SDHC_EISTER_CMDIDX_MASKED Masked
 *  +      SDHC_EISTER_CMDIDX_ENABLED Enabled
 * - SDHC_EISTER_DATTEO Data Timeout Error Status Enable
 *  +      SDHC_EISTER_DATTEO_MASKED Masked
 *  +      SDHC_EISTER_DATTEO_ENABLED Enabled
 * - SDHC_EISTER_DATCRC Data CRC Error Status Enable
 *  +      SDHC_EISTER_DATCRC_MASKED Masked
 *  +      SDHC_EISTER_DATCRC_ENABLED Enabled
 * - SDHC_EISTER_DATEND Data End Bit Error Status Enable
 *  +      SDHC_EISTER_DATEND_MASKED Masked
 *  +      SDHC_EISTER_DATEND_ENABLED Enabled
 * - SDHC_EISTER_CURLIM Current Limit Error Status Enable
 *  +      SDHC_EISTER_CURLIM_MASKED Masked
 *  +      SDHC_EISTER_CURLIM_ENABLED Enabled
 * - SDHC_EISTER_ACMD Auto CMD Error Status Enable
 *  +      SDHC_EISTER_ACMD_MASKED Masked
 *  +      SDHC_EISTER_ACMD_ENABLED Enabled
 * - SDHC_EISTER_ADMA ADMA Error Status Enable
 *  +      SDHC_EISTER_ADMA_MASKED Masked
 *  +      SDHC_EISTER_ADMA_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDTEO Command Timeout Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDCRC Command CRC Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDEND Command End Bit Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CMDIDX Command Index Error Status Enable
 *  +      SDHC_EISTER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATTEO Data Timeout Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATCRC Data CRC Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISTER_EMMC_DATEND Data End Bit Error Status Enable
 *  +      SDHC_EISTER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISTER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISTER_EMMC_CURLIM Current Limit Error Status Enable
 *  +      SDHC_EISTER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISTER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISTER_EMMC_ACMD Auto CMD Error Status Enable
 *  +      SDHC_EISTER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISTER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISTER_EMMC_ADMA ADMA Error Status Enable
 *  +      SDHC_EISTER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISTER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISTER_EMMC_BOOTAE Boot Acknowledge Error Status Enable
 **/
static inline uint16_t sdhc_read_EISTER(SDHC_t *pSDHC)
{
	return pSDHC->EISTER.reg;
}

/**
 * @brief sdhc set NISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_NISIER_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_CMDC_MASKED Masked
 *  +      SDHC_NISIER_CMDC_ENABLED Enabled
 * - SDHC_NISIER_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_TRFC_MASKED Masked
 *  +      SDHC_NISIER_TRFC_ENABLED Enabled
 * - SDHC_NISIER_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_CINS Card Insertion Signal Enable
 *  +      SDHC_NISIER_CINS_MASKED Masked
 *  +      SDHC_NISIER_CINS_ENABLED Enabled
 * - SDHC_NISIER_CREM Card Removal Signal Enable
 *  +      SDHC_NISIER_CREM_MASKED Masked
 *  +      SDHC_NISIER_CREM_ENABLED Enabled
 * - SDHC_NISIER_CINT Card Interrupt Signal Enable
 *  +      SDHC_NISIER_CINT_MASKED Masked
 *  +      SDHC_NISIER_CINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_EMMC_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BOOTAR Boot Acknowledge Received Signal Enable
 **/
static inline void sdhc_set_NISIER(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->NISIER.reg |= mask;
}

/**
 * @brief sdhc get NISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_NISIER_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_CMDC_MASKED Masked
 *  +      SDHC_NISIER_CMDC_ENABLED Enabled
 * - SDHC_NISIER_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_TRFC_MASKED Masked
 *  +      SDHC_NISIER_TRFC_ENABLED Enabled
 * - SDHC_NISIER_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_CINS Card Insertion Signal Enable
 *  +      SDHC_NISIER_CINS_MASKED Masked
 *  +      SDHC_NISIER_CINS_ENABLED Enabled
 * - SDHC_NISIER_CREM Card Removal Signal Enable
 *  +      SDHC_NISIER_CREM_MASKED Masked
 *  +      SDHC_NISIER_CREM_ENABLED Enabled
 * - SDHC_NISIER_CINT Card Interrupt Signal Enable
 *  +      SDHC_NISIER_CINT_MASKED Masked
 *  +      SDHC_NISIER_CINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_EMMC_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BOOTAR Boot Acknowledge Received Signal Enable
 **/
static inline uint16_t sdhc_get_NISIER(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->NISIER.reg & mask);
}

/**
 * @brief sdhc write NISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_NISIER_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_CMDC_MASKED Masked
 *  +      SDHC_NISIER_CMDC_ENABLED Enabled
 * - SDHC_NISIER_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_TRFC_MASKED Masked
 *  +      SDHC_NISIER_TRFC_ENABLED Enabled
 * - SDHC_NISIER_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_CINS Card Insertion Signal Enable
 *  +      SDHC_NISIER_CINS_MASKED Masked
 *  +      SDHC_NISIER_CINS_ENABLED Enabled
 * - SDHC_NISIER_CREM Card Removal Signal Enable
 *  +      SDHC_NISIER_CREM_MASKED Masked
 *  +      SDHC_NISIER_CREM_ENABLED Enabled
 * - SDHC_NISIER_CINT Card Interrupt Signal Enable
 *  +      SDHC_NISIER_CINT_MASKED Masked
 *  +      SDHC_NISIER_CINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_EMMC_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BOOTAR Boot Acknowledge Received Signal Enable
 **/
static inline void sdhc_write_NISIER(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->NISIER.reg = data;
}

/**
 * @brief sdhc clear NISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_NISIER_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_CMDC_MASKED Masked
 *  +      SDHC_NISIER_CMDC_ENABLED Enabled
 * - SDHC_NISIER_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_TRFC_MASKED Masked
 *  +      SDHC_NISIER_TRFC_ENABLED Enabled
 * - SDHC_NISIER_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_CINS Card Insertion Signal Enable
 *  +      SDHC_NISIER_CINS_MASKED Masked
 *  +      SDHC_NISIER_CINS_ENABLED Enabled
 * - SDHC_NISIER_CREM Card Removal Signal Enable
 *  +      SDHC_NISIER_CREM_MASKED Masked
 *  +      SDHC_NISIER_CREM_ENABLED Enabled
 * - SDHC_NISIER_CINT Card Interrupt Signal Enable
 *  +      SDHC_NISIER_CINT_MASKED Masked
 *  +      SDHC_NISIER_CINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_EMMC_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BOOTAR Boot Acknowledge Received Signal Enable
 **/
static inline void sdhc_clear_NISIER(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->NISIER.reg &= ~mask;
}

/**
 * @brief sdhc read NISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_NISIER_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_CMDC_MASKED Masked
 *  +      SDHC_NISIER_CMDC_ENABLED Enabled
 * - SDHC_NISIER_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_TRFC_MASKED Masked
 *  +      SDHC_NISIER_TRFC_ENABLED Enabled
 * - SDHC_NISIER_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_CINS Card Insertion Signal Enable
 *  +      SDHC_NISIER_CINS_MASKED Masked
 *  +      SDHC_NISIER_CINS_ENABLED Enabled
 * - SDHC_NISIER_CREM Card Removal Signal Enable
 *  +      SDHC_NISIER_CREM_MASKED Masked
 *  +      SDHC_NISIER_CREM_ENABLED Enabled
 * - SDHC_NISIER_CINT Card Interrupt Signal Enable
 *  +      SDHC_NISIER_CINT_MASKED Masked
 *  +      SDHC_NISIER_CINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_CMDC Command Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_CMDC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_CMDC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_TRFC Transfer Complete Signal Enable
 *  +      SDHC_NISIER_EMMC_TRFC_MASKED Masked
 *  +      SDHC_NISIER_EMMC_TRFC_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BLKGE Block Gap Event Signal Enable
 *  +      SDHC_NISIER_EMMC_BLKGE_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BLKGE_ENABLED Enabled
 * - SDHC_NISIER_EMMC_DMAINT DMA Interrupt Signal Enable
 *  +      SDHC_NISIER_EMMC_DMAINT_MASKED Masked
 *  +      SDHC_NISIER_EMMC_DMAINT_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BWRRDY Buffer Write Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BWRRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BWRRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BRDRDY Buffer Read Ready Signal Enable
 *  +      SDHC_NISIER_EMMC_BRDRDY_MASKED Masked
 *  +      SDHC_NISIER_EMMC_BRDRDY_ENABLED Enabled
 * - SDHC_NISIER_EMMC_BOOTAR Boot Acknowledge Received Signal Enable
 **/
static inline uint16_t sdhc_read_NISIER(SDHC_t *pSDHC)
{
	return pSDHC->NISIER.reg;
}

/**
 * @brief sdhc set EISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_EISIER_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_DATEND_MASKED Masked
 *  +      SDHC_EISIER_DATEND_ENABLED Enabled
 * - SDHC_EISIER_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_ACMD_MASKED Masked
 *  +      SDHC_EISIER_ACMD_ENABLED Enabled
 * - SDHC_EISIER_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_ADMA_MASKED Masked
 *  +      SDHC_EISIER_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_BOOTAE Boot Acknowledge Error Signal Enable
 **/
static inline void sdhc_set_EISIER(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->EISIER.reg |= mask;
}

/**
 * @brief sdhc get EISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_EISIER_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_DATEND_MASKED Masked
 *  +      SDHC_EISIER_DATEND_ENABLED Enabled
 * - SDHC_EISIER_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_ACMD_MASKED Masked
 *  +      SDHC_EISIER_ACMD_ENABLED Enabled
 * - SDHC_EISIER_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_ADMA_MASKED Masked
 *  +      SDHC_EISIER_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_BOOTAE Boot Acknowledge Error Signal Enable
 **/
static inline uint16_t sdhc_get_EISIER(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->EISIER.reg & mask);
}

/**
 * @brief sdhc write EISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_EISIER_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_DATEND_MASKED Masked
 *  +      SDHC_EISIER_DATEND_ENABLED Enabled
 * - SDHC_EISIER_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_ACMD_MASKED Masked
 *  +      SDHC_EISIER_ACMD_ENABLED Enabled
 * - SDHC_EISIER_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_ADMA_MASKED Masked
 *  +      SDHC_EISIER_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_BOOTAE Boot Acknowledge Error Signal Enable
 **/
static inline void sdhc_write_EISIER(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->EISIER.reg = data;
}

/**
 * @brief sdhc clear EISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_EISIER_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_DATEND_MASKED Masked
 *  +      SDHC_EISIER_DATEND_ENABLED Enabled
 * - SDHC_EISIER_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_ACMD_MASKED Masked
 *  +      SDHC_EISIER_ACMD_ENABLED Enabled
 * - SDHC_EISIER_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_ADMA_MASKED Masked
 *  +      SDHC_EISIER_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_BOOTAE Boot Acknowledge Error Signal Enable
 **/
static inline void sdhc_clear_EISIER(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->EISIER.reg &= ~mask;
}

/**
 * @brief sdhc read EISIER register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_EISIER_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_DATEND_MASKED Masked
 *  +      SDHC_EISIER_DATEND_ENABLED Enabled
 * - SDHC_EISIER_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_ACMD_MASKED Masked
 *  +      SDHC_EISIER_ACMD_ENABLED Enabled
 * - SDHC_EISIER_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_ADMA_MASKED Masked
 *  +      SDHC_EISIER_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDTEO Command Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDCRC Command CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDEND Command End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CMDIDX Command Index Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CMDIDX_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CMDIDX_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATTEO Data Timeout Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATTEO_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATTEO_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATCRC Data CRC Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATCRC_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATCRC_ENABLED Enabled
 * - SDHC_EISIER_EMMC_DATEND Data End Bit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_DATEND_MASKED Masked
 *  +      SDHC_EISIER_EMMC_DATEND_ENABLED Enabled
 * - SDHC_EISIER_EMMC_CURLIM Current Limit Error Signal Enable
 *  +      SDHC_EISIER_EMMC_CURLIM_MASKED Masked
 *  +      SDHC_EISIER_EMMC_CURLIM_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ACMD Auto CMD Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ACMD_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ACMD_ENABLED Enabled
 * - SDHC_EISIER_EMMC_ADMA ADMA Error Signal Enable
 *  +      SDHC_EISIER_EMMC_ADMA_MASKED Masked
 *  +      SDHC_EISIER_EMMC_ADMA_ENABLED Enabled
 * - SDHC_EISIER_EMMC_BOOTAE Boot Acknowledge Error Signal Enable
 **/
static inline uint16_t sdhc_read_EISIER(SDHC_t *pSDHC)
{
	return pSDHC->EISIER.reg;
}

/**
 * @brief sdhc set HC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_HC2R_UHSMS(value) UHS Mode Select
 *  +      SDHC_HC2R_UHSMS_SDR12 SDR12
 *  +      SDHC_HC2R_UHSMS_SDR25 SDR25
 *  +      SDHC_HC2R_UHSMS_SDR50 SDR50
 *  +      SDHC_HC2R_UHSMS_SDR104 SDR104
 *  +      SDHC_HC2R_UHSMS_DDR50 DDR50
 * - SDHC_HC2R_VS18EN 1.8V Signaling Enable
 *  +      SDHC_HC2R_VS18EN_S33V 3.3V Signaling
 *  +      SDHC_HC2R_VS18EN_S18V 1.8V Signaling
 * - SDHC_HC2R_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_ASINTEN Asynchronous Interrupt Enable
 *  +      SDHC_HC2R_ASINTEN_DISABLED Disabled
 *  +      SDHC_HC2R_ASINTEN_ENABLED Enabled
 * - SDHC_HC2R_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 * - SDHC_HC2R_EMMC_HS200EN(value) HS200 Mode Enable
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR12 SDR12
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR25 SDR25
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR50 SDR50
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR104 SDR104
 *  +      SDHC_HC2R_EMMC_HS200EN_DDR50 DDR50
 * - SDHC_HC2R_EMMC_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_EMMC_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_EMMC_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EMMC_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EMMC_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EMMC_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_EMMC_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_EMMC_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_EMMC_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_EMMC_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_EMMC_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_EMMC_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 **/
static inline void sdhc_set_HC2R(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->HC2R.reg |= mask;
}

/**
 * @brief sdhc get HC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_HC2R_UHSMS(value) UHS Mode Select
 *  +      SDHC_HC2R_UHSMS_SDR12 SDR12
 *  +      SDHC_HC2R_UHSMS_SDR25 SDR25
 *  +      SDHC_HC2R_UHSMS_SDR50 SDR50
 *  +      SDHC_HC2R_UHSMS_SDR104 SDR104
 *  +      SDHC_HC2R_UHSMS_DDR50 DDR50
 * - SDHC_HC2R_VS18EN 1.8V Signaling Enable
 *  +      SDHC_HC2R_VS18EN_S33V 3.3V Signaling
 *  +      SDHC_HC2R_VS18EN_S18V 1.8V Signaling
 * - SDHC_HC2R_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_ASINTEN Asynchronous Interrupt Enable
 *  +      SDHC_HC2R_ASINTEN_DISABLED Disabled
 *  +      SDHC_HC2R_ASINTEN_ENABLED Enabled
 * - SDHC_HC2R_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 * - SDHC_HC2R_EMMC_HS200EN(value) HS200 Mode Enable
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR12 SDR12
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR25 SDR25
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR50 SDR50
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR104 SDR104
 *  +      SDHC_HC2R_EMMC_HS200EN_DDR50 DDR50
 * - SDHC_HC2R_EMMC_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_EMMC_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_EMMC_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EMMC_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EMMC_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EMMC_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_EMMC_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_EMMC_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_EMMC_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_EMMC_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_EMMC_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_EMMC_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 **/
static inline uint16_t sdhc_get_HC2R(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->HC2R.reg & mask);
}

/**
 * @brief sdhc write HC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_HC2R_UHSMS(value) UHS Mode Select
 *  +      SDHC_HC2R_UHSMS_SDR12 SDR12
 *  +      SDHC_HC2R_UHSMS_SDR25 SDR25
 *  +      SDHC_HC2R_UHSMS_SDR50 SDR50
 *  +      SDHC_HC2R_UHSMS_SDR104 SDR104
 *  +      SDHC_HC2R_UHSMS_DDR50 DDR50
 * - SDHC_HC2R_VS18EN 1.8V Signaling Enable
 *  +      SDHC_HC2R_VS18EN_S33V 3.3V Signaling
 *  +      SDHC_HC2R_VS18EN_S18V 1.8V Signaling
 * - SDHC_HC2R_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_ASINTEN Asynchronous Interrupt Enable
 *  +      SDHC_HC2R_ASINTEN_DISABLED Disabled
 *  +      SDHC_HC2R_ASINTEN_ENABLED Enabled
 * - SDHC_HC2R_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 * - SDHC_HC2R_EMMC_HS200EN(value) HS200 Mode Enable
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR12 SDR12
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR25 SDR25
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR50 SDR50
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR104 SDR104
 *  +      SDHC_HC2R_EMMC_HS200EN_DDR50 DDR50
 * - SDHC_HC2R_EMMC_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_EMMC_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_EMMC_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EMMC_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EMMC_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EMMC_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_EMMC_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_EMMC_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_EMMC_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_EMMC_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_EMMC_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_EMMC_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 **/
static inline void sdhc_write_HC2R(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->HC2R.reg = data;
}

/**
 * @brief sdhc clear HC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_HC2R_UHSMS(value) UHS Mode Select
 *  +      SDHC_HC2R_UHSMS_SDR12 SDR12
 *  +      SDHC_HC2R_UHSMS_SDR25 SDR25
 *  +      SDHC_HC2R_UHSMS_SDR50 SDR50
 *  +      SDHC_HC2R_UHSMS_SDR104 SDR104
 *  +      SDHC_HC2R_UHSMS_DDR50 DDR50
 * - SDHC_HC2R_VS18EN 1.8V Signaling Enable
 *  +      SDHC_HC2R_VS18EN_S33V 3.3V Signaling
 *  +      SDHC_HC2R_VS18EN_S18V 1.8V Signaling
 * - SDHC_HC2R_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_ASINTEN Asynchronous Interrupt Enable
 *  +      SDHC_HC2R_ASINTEN_DISABLED Disabled
 *  +      SDHC_HC2R_ASINTEN_ENABLED Enabled
 * - SDHC_HC2R_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 * - SDHC_HC2R_EMMC_HS200EN(value) HS200 Mode Enable
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR12 SDR12
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR25 SDR25
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR50 SDR50
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR104 SDR104
 *  +      SDHC_HC2R_EMMC_HS200EN_DDR50 DDR50
 * - SDHC_HC2R_EMMC_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_EMMC_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_EMMC_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EMMC_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EMMC_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EMMC_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_EMMC_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_EMMC_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_EMMC_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_EMMC_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_EMMC_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_EMMC_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 **/
static inline void sdhc_clear_HC2R(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->HC2R.reg &= ~mask;
}

/**
 * @brief sdhc read HC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_HC2R_UHSMS(value) UHS Mode Select
 *  +      SDHC_HC2R_UHSMS_SDR12 SDR12
 *  +      SDHC_HC2R_UHSMS_SDR25 SDR25
 *  +      SDHC_HC2R_UHSMS_SDR50 SDR50
 *  +      SDHC_HC2R_UHSMS_SDR104 SDR104
 *  +      SDHC_HC2R_UHSMS_DDR50 DDR50
 * - SDHC_HC2R_VS18EN 1.8V Signaling Enable
 *  +      SDHC_HC2R_VS18EN_S33V 3.3V Signaling
 *  +      SDHC_HC2R_VS18EN_S18V 1.8V Signaling
 * - SDHC_HC2R_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_ASINTEN Asynchronous Interrupt Enable
 *  +      SDHC_HC2R_ASINTEN_DISABLED Disabled
 *  +      SDHC_HC2R_ASINTEN_ENABLED Enabled
 * - SDHC_HC2R_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 * - SDHC_HC2R_EMMC_HS200EN(value) HS200 Mode Enable
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR12 SDR12
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR25 SDR25
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR50 SDR50
 *  +      SDHC_HC2R_EMMC_HS200EN_SDR104 SDR104
 *  +      SDHC_HC2R_EMMC_HS200EN_DDR50 DDR50
 * - SDHC_HC2R_EMMC_DRVSEL(value) Driver Strength Select
 *  +      SDHC_HC2R_EMMC_DRVSEL_B Driver Type B is Selected (Default)
 *  +      SDHC_HC2R_EMMC_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_HC2R_EMMC_DRVSEL_D Driver Type D is Selected
 * - SDHC_HC2R_EMMC_EXTUN Execute Tuning
 *  +      SDHC_HC2R_EMMC_EXTUN_NO Not Tuned or Tuning Completed
 *  +      SDHC_HC2R_EMMC_EXTUN_REQUESTED Execute Tuning
 * - SDHC_HC2R_EMMC_SLCKSEL Sampling Clock Select
 *  +      SDHC_HC2R_EMMC_SLCKSEL_FIXED Fixed clock is used to sample data
 *  +      SDHC_HC2R_EMMC_SLCKSEL_TUNED Tuned clock is used to sample data
 * - SDHC_HC2R_EMMC_PVALEN Preset Value Enable
 *  +      SDHC_HC2R_EMMC_PVALEN_HOST SDCLK and Driver Strength are controlled by Host Controller
 *  +      SDHC_HC2R_EMMC_PVALEN_AUTO Automatic Selection by Preset Value is Enabled
 **/
static inline uint16_t sdhc_read_HC2R(SDHC_t *pSDHC)
{
	return pSDHC->HC2R.reg;
}

/**
 * @brief sdhc write FERACES register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_FERACES_ACMD12NE Force Event for Auto CMD12 Not Executed
 *  +      SDHC_FERACES_ACMD12NE_NO No Interrupt
 *  +      SDHC_FERACES_ACMD12NE_YES Interrupt is generated
 * - SDHC_FERACES_ACMDTEO Force Event for Auto CMD Timeout Error
 *  +      SDHC_FERACES_ACMDTEO_NO No Interrupt
 *  +      SDHC_FERACES_ACMDTEO_YES Interrupt is generated
 * - SDHC_FERACES_ACMDCRC Force Event for Auto CMD CRC Error
 *  +      SDHC_FERACES_ACMDCRC_NO No Interrupt
 *  +      SDHC_FERACES_ACMDCRC_YES Interrupt is generated
 * - SDHC_FERACES_ACMDEND Force Event for Auto CMD End Bit Error
 *  +      SDHC_FERACES_ACMDEND_NO No Interrupt
 *  +      SDHC_FERACES_ACMDEND_YES Interrupt is generated
 * - SDHC_FERACES_ACMDIDX Force Event for Auto CMD Index Error
 *  +      SDHC_FERACES_ACMDIDX_NO No Interrupt
 *  +      SDHC_FERACES_ACMDIDX_YES Interrupt is generated
 * - SDHC_FERACES_CMDNI Force Event for Command Not Issued By Auto CMD12 Error
 *  +      SDHC_FERACES_CMDNI_NO No Interrupt
 *  +      SDHC_FERACES_CMDNI_YES Interrupt is generated
 **/
static inline void sdhc_write_FERACES(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->FERACES.reg = data;
}

/**
 * @brief sdhc write FEREIS register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_FEREIS_CMDTEO Force Event for Command Timeout Error
 *  +      SDHC_FEREIS_CMDTEO_NO No Interrupt
 *  +      SDHC_FEREIS_CMDTEO_YES Interrupt is generated
 * - SDHC_FEREIS_CMDCRC Force Event for Command CRC Error
 *  +      SDHC_FEREIS_CMDCRC_NO No Interrupt
 *  +      SDHC_FEREIS_CMDCRC_YES Interrupt is generated
 * - SDHC_FEREIS_CMDEND Force Event for Command End Bit Error
 *  +      SDHC_FEREIS_CMDEND_NO No Interrupt
 *  +      SDHC_FEREIS_CMDEND_YES Interrupt is generated
 * - SDHC_FEREIS_CMDIDX Force Event for Command Index Error
 *  +      SDHC_FEREIS_CMDIDX_NO No Interrupt
 *  +      SDHC_FEREIS_CMDIDX_YES Interrupt is generated
 * - SDHC_FEREIS_DATTEO Force Event for Data Timeout Error
 *  +      SDHC_FEREIS_DATTEO_NO No Interrupt
 *  +      SDHC_FEREIS_DATTEO_YES Interrupt is generated
 * - SDHC_FEREIS_DATCRC Force Event for Data CRC Error
 *  +      SDHC_FEREIS_DATCRC_NO No Interrupt
 *  +      SDHC_FEREIS_DATCRC_YES Interrupt is generated
 * - SDHC_FEREIS_DATEND Force Event for Data End Bit Error
 *  +      SDHC_FEREIS_DATEND_NO No Interrupt
 *  +      SDHC_FEREIS_DATEND_YES Interrupt is generated
 * - SDHC_FEREIS_CURLIM Force Event for Current Limit Error
 *  +      SDHC_FEREIS_CURLIM_NO No Interrupt
 *  +      SDHC_FEREIS_CURLIM_YES Interrupt is generated
 * - SDHC_FEREIS_ACMD Force Event for Auto CMD Error
 *  +      SDHC_FEREIS_ACMD_NO No Interrupt
 *  +      SDHC_FEREIS_ACMD_YES Interrupt is generated
 * - SDHC_FEREIS_ADMA Force Event for ADMA Error
 *  +      SDHC_FEREIS_ADMA_NO No Interrupt
 *  +      SDHC_FEREIS_ADMA_YES Interrupt is generated
 * - SDHC_FEREIS_BOOTAE Force Event for Boot Acknowledge Error
 *  +      SDHC_FEREIS_BOOTAE_NO No Interrupt
 *  +      SDHC_FEREIS_BOOTAE_YES Interrupt is generated
 **/
static inline void sdhc_write_FEREIS(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->FEREIS.reg = data;
}

/**
 * @brief sdhc write MC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_MC2R_SRESP e.MMC Abort Wait IRQ
 * - SDHC_MC2R_ABOOT e.MMC Abort Boot
 **/
static inline void sdhc_write_MC2R(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->MC2R.reg = data;
}

/**
 * @brief sdhc set BSR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_BSR_BLOCKSIZE(value) Transfer Block Size
 * - SDHC_BSR_BOUNDARY(value) SDMA Buffer Boundary
 *  +      SDHC_BSR_BOUNDARY_4K 4k bytes
 *  +      SDHC_BSR_BOUNDARY_8K 8k bytes
 *  +      SDHC_BSR_BOUNDARY_16K 16k bytes
 *  +      SDHC_BSR_BOUNDARY_32K 32k bytes
 *  +      SDHC_BSR_BOUNDARY_64K 64k bytes
 *  +      SDHC_BSR_BOUNDARY_128K 128k bytes
 *  +      SDHC_BSR_BOUNDARY_256K 256k bytes
 *  +      SDHC_BSR_BOUNDARY_512K 512k bytes
 **/
static inline void sdhc_set_BSR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->BSR.reg |= mask;
}

/**
 * @brief sdhc get BSR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_BSR_BLOCKSIZE(value) Transfer Block Size
 * - SDHC_BSR_BOUNDARY(value) SDMA Buffer Boundary
 *  +      SDHC_BSR_BOUNDARY_4K 4k bytes
 *  +      SDHC_BSR_BOUNDARY_8K 8k bytes
 *  +      SDHC_BSR_BOUNDARY_16K 16k bytes
 *  +      SDHC_BSR_BOUNDARY_32K 32k bytes
 *  +      SDHC_BSR_BOUNDARY_64K 64k bytes
 *  +      SDHC_BSR_BOUNDARY_128K 128k bytes
 *  +      SDHC_BSR_BOUNDARY_256K 256k bytes
 *  +      SDHC_BSR_BOUNDARY_512K 512k bytes
 **/
static inline uint16_t sdhc_get_BSR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->BSR.reg & mask);
}

/**
 * @brief sdhc write BSR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_BSR_BLOCKSIZE(value) Transfer Block Size
 * - SDHC_BSR_BOUNDARY(value) SDMA Buffer Boundary
 *  +      SDHC_BSR_BOUNDARY_4K 4k bytes
 *  +      SDHC_BSR_BOUNDARY_8K 8k bytes
 *  +      SDHC_BSR_BOUNDARY_16K 16k bytes
 *  +      SDHC_BSR_BOUNDARY_32K 32k bytes
 *  +      SDHC_BSR_BOUNDARY_64K 64k bytes
 *  +      SDHC_BSR_BOUNDARY_128K 128k bytes
 *  +      SDHC_BSR_BOUNDARY_256K 256k bytes
 *  +      SDHC_BSR_BOUNDARY_512K 512k bytes
 **/
static inline void sdhc_write_BSR(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->BSR.reg = data;
}

/**
 * @brief sdhc clear BSR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_BSR_BLOCKSIZE(value) Transfer Block Size
 * - SDHC_BSR_BOUNDARY(value) SDMA Buffer Boundary
 *  +      SDHC_BSR_BOUNDARY_4K 4k bytes
 *  +      SDHC_BSR_BOUNDARY_8K 8k bytes
 *  +      SDHC_BSR_BOUNDARY_16K 16k bytes
 *  +      SDHC_BSR_BOUNDARY_32K 32k bytes
 *  +      SDHC_BSR_BOUNDARY_64K 64k bytes
 *  +      SDHC_BSR_BOUNDARY_128K 128k bytes
 *  +      SDHC_BSR_BOUNDARY_256K 256k bytes
 *  +      SDHC_BSR_BOUNDARY_512K 512k bytes
 **/
static inline void sdhc_clear_BSR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->BSR.reg &= ~mask;
}

/**
 * @brief sdhc read BSR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_BSR_BLOCKSIZE(value) Transfer Block Size
 * - SDHC_BSR_BOUNDARY(value) SDMA Buffer Boundary
 *  +      SDHC_BSR_BOUNDARY_4K 4k bytes
 *  +      SDHC_BSR_BOUNDARY_8K 8k bytes
 *  +      SDHC_BSR_BOUNDARY_16K 16k bytes
 *  +      SDHC_BSR_BOUNDARY_32K 32k bytes
 *  +      SDHC_BSR_BOUNDARY_64K 64k bytes
 *  +      SDHC_BSR_BOUNDARY_128K 128k bytes
 *  +      SDHC_BSR_BOUNDARY_256K 256k bytes
 *  +      SDHC_BSR_BOUNDARY_512K 512k bytes
 **/
static inline uint16_t sdhc_read_BSR(SDHC_t *pSDHC)
{
	return pSDHC->BSR.reg;
}

/**
 * @brief sdhc write BCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_BCR_BCNT(value) Blocks Count for Current Transfer
 **/
static inline void sdhc_write_BCR(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->BCR.reg = data;
}

/**
 * @brief sdhc read BCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_BCR_BCNT(value) Blocks Count for Current Transfer
 **/
static inline uint16_t sdhc_read_BCR(SDHC_t *pSDHC)
{
	return pSDHC->BCR.reg;
}

/**
 * @brief sdhc set ARG1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_ARG1R_ARG(value) Argument 1
 **/
static inline void sdhc_set_ARG1R(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->ARG1R.reg |= mask;
}

/**
 * @brief sdhc write ARG1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint32_t 
 * - SDHC_ARG1R_ARG(value) Argument 1
 **/
static inline void sdhc_write_ARG1R(SDHC_t *pSDHC, uint32_t data)
{
	pSDHC->ARG1R.reg = data;
}

/**
 * @brief sdhc read ARG1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_ARG1R_ARG(value) Argument 1
 **/
static inline uint32_t sdhc_read_ARG1R(SDHC_t *pSDHC)
{
	return pSDHC->ARG1R.reg;
}

/**
 * @brief sdhc set TMR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_TMR_DMAEN DMA Enable
 *  +      SDHC_TMR_DMAEN_DISABLE No data transfer or Non DMA data transfer
 *  +      SDHC_TMR_DMAEN_ENABLE DMA data transfer
 * - SDHC_TMR_BCEN Block Count Enable
 *  +      SDHC_TMR_BCEN_DISABLE Disable
 *  +      SDHC_TMR_BCEN_ENABLE Enable
 * - SDHC_TMR_ACMDEN(value) Auto Command Enable
 *  +      SDHC_TMR_ACMDEN_DISABLED Auto Command Disabled
 *  +      SDHC_TMR_ACMDEN_CMD12 Auto CMD12 Enable
 *  +      SDHC_TMR_ACMDEN_CMD23 Auto CMD23 Enable
 *  +      SDHC_TMR_ACMDEN_3 Reserved
 * - SDHC_TMR_DTDSEL Data Transfer Direction Selection
 *  +      SDHC_TMR_DTDSEL_WRITE Write (Host to Card)
 *  +      SDHC_TMR_DTDSEL_READ Read (Card to Host)
 * - SDHC_TMR_MSBSEL Multi/Single Block Selection
 *  +      SDHC_TMR_MSBSEL_SINGLE Single Block
 *  +      SDHC_TMR_MSBSEL_MULTIPLE Multiple Block
 **/
static inline void sdhc_set_TMR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->TMR.reg |= mask;
}

/**
 * @brief sdhc get TMR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_TMR_DMAEN DMA Enable
 *  +      SDHC_TMR_DMAEN_DISABLE No data transfer or Non DMA data transfer
 *  +      SDHC_TMR_DMAEN_ENABLE DMA data transfer
 * - SDHC_TMR_BCEN Block Count Enable
 *  +      SDHC_TMR_BCEN_DISABLE Disable
 *  +      SDHC_TMR_BCEN_ENABLE Enable
 * - SDHC_TMR_ACMDEN(value) Auto Command Enable
 *  +      SDHC_TMR_ACMDEN_DISABLED Auto Command Disabled
 *  +      SDHC_TMR_ACMDEN_CMD12 Auto CMD12 Enable
 *  +      SDHC_TMR_ACMDEN_CMD23 Auto CMD23 Enable
 *  +      SDHC_TMR_ACMDEN_3 Reserved
 * - SDHC_TMR_DTDSEL Data Transfer Direction Selection
 *  +      SDHC_TMR_DTDSEL_WRITE Write (Host to Card)
 *  +      SDHC_TMR_DTDSEL_READ Read (Card to Host)
 * - SDHC_TMR_MSBSEL Multi/Single Block Selection
 *  +      SDHC_TMR_MSBSEL_SINGLE Single Block
 *  +      SDHC_TMR_MSBSEL_MULTIPLE Multiple Block
 **/
static inline uint16_t sdhc_get_TMR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->TMR.reg & mask);
}

/**
 * @brief sdhc write TMR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_TMR_DMAEN DMA Enable
 *  +      SDHC_TMR_DMAEN_DISABLE No data transfer or Non DMA data transfer
 *  +      SDHC_TMR_DMAEN_ENABLE DMA data transfer
 * - SDHC_TMR_BCEN Block Count Enable
 *  +      SDHC_TMR_BCEN_DISABLE Disable
 *  +      SDHC_TMR_BCEN_ENABLE Enable
 * - SDHC_TMR_ACMDEN(value) Auto Command Enable
 *  +      SDHC_TMR_ACMDEN_DISABLED Auto Command Disabled
 *  +      SDHC_TMR_ACMDEN_CMD12 Auto CMD12 Enable
 *  +      SDHC_TMR_ACMDEN_CMD23 Auto CMD23 Enable
 *  +      SDHC_TMR_ACMDEN_3 Reserved
 * - SDHC_TMR_DTDSEL Data Transfer Direction Selection
 *  +      SDHC_TMR_DTDSEL_WRITE Write (Host to Card)
 *  +      SDHC_TMR_DTDSEL_READ Read (Card to Host)
 * - SDHC_TMR_MSBSEL Multi/Single Block Selection
 *  +      SDHC_TMR_MSBSEL_SINGLE Single Block
 *  +      SDHC_TMR_MSBSEL_MULTIPLE Multiple Block
 **/
static inline void sdhc_write_TMR(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->TMR.reg = data;
}

/**
 * @brief sdhc clear TMR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_TMR_DMAEN DMA Enable
 *  +      SDHC_TMR_DMAEN_DISABLE No data transfer or Non DMA data transfer
 *  +      SDHC_TMR_DMAEN_ENABLE DMA data transfer
 * - SDHC_TMR_BCEN Block Count Enable
 *  +      SDHC_TMR_BCEN_DISABLE Disable
 *  +      SDHC_TMR_BCEN_ENABLE Enable
 * - SDHC_TMR_ACMDEN(value) Auto Command Enable
 *  +      SDHC_TMR_ACMDEN_DISABLED Auto Command Disabled
 *  +      SDHC_TMR_ACMDEN_CMD12 Auto CMD12 Enable
 *  +      SDHC_TMR_ACMDEN_CMD23 Auto CMD23 Enable
 *  +      SDHC_TMR_ACMDEN_3 Reserved
 * - SDHC_TMR_DTDSEL Data Transfer Direction Selection
 *  +      SDHC_TMR_DTDSEL_WRITE Write (Host to Card)
 *  +      SDHC_TMR_DTDSEL_READ Read (Card to Host)
 * - SDHC_TMR_MSBSEL Multi/Single Block Selection
 *  +      SDHC_TMR_MSBSEL_SINGLE Single Block
 *  +      SDHC_TMR_MSBSEL_MULTIPLE Multiple Block
 **/
static inline void sdhc_clear_TMR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->TMR.reg &= ~mask;
}

/**
 * @brief sdhc read TMR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_TMR_DMAEN DMA Enable
 *  +      SDHC_TMR_DMAEN_DISABLE No data transfer or Non DMA data transfer
 *  +      SDHC_TMR_DMAEN_ENABLE DMA data transfer
 * - SDHC_TMR_BCEN Block Count Enable
 *  +      SDHC_TMR_BCEN_DISABLE Disable
 *  +      SDHC_TMR_BCEN_ENABLE Enable
 * - SDHC_TMR_ACMDEN(value) Auto Command Enable
 *  +      SDHC_TMR_ACMDEN_DISABLED Auto Command Disabled
 *  +      SDHC_TMR_ACMDEN_CMD12 Auto CMD12 Enable
 *  +      SDHC_TMR_ACMDEN_CMD23 Auto CMD23 Enable
 *  +      SDHC_TMR_ACMDEN_3 Reserved
 * - SDHC_TMR_DTDSEL Data Transfer Direction Selection
 *  +      SDHC_TMR_DTDSEL_WRITE Write (Host to Card)
 *  +      SDHC_TMR_DTDSEL_READ Read (Card to Host)
 * - SDHC_TMR_MSBSEL Multi/Single Block Selection
 *  +      SDHC_TMR_MSBSEL_SINGLE Single Block
 *  +      SDHC_TMR_MSBSEL_MULTIPLE Multiple Block
 **/
static inline uint16_t sdhc_read_TMR(SDHC_t *pSDHC)
{
	return pSDHC->TMR.reg;
}

/**
 * @brief sdhc set CR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_CR_RESPTYP(value) Response Type
 *  +      SDHC_CR_RESPTYP_NONE No response
 *  +      SDHC_CR_RESPTYP_136_BIT 136-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT 48-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT_BUSY 48-bit response check busy after response
 * - SDHC_CR_CMDCCEN Command CRC Check Enable
 *  +      SDHC_CR_CMDCCEN_DISABLE Disable
 *  +      SDHC_CR_CMDCCEN_ENABLE Enable
 * - SDHC_CR_CMDICEN Command Index Check Enable
 *  +      SDHC_CR_CMDICEN_DISABLE Disable
 *  +      SDHC_CR_CMDICEN_ENABLE Enable
 * - SDHC_CR_DPSEL Data Present Select
 *  +      SDHC_CR_DPSEL_NO_DATA No Data Present
 *  +      SDHC_CR_DPSEL_DATA Data Present
 * - SDHC_CR_CMDTYP(value) Command Type
 *  +      SDHC_CR_CMDTYP_NORMAL Other commands
 *  +      SDHC_CR_CMDTYP_SUSPEND CMD52 for writing Bus Suspend in CCCR
 *  +      SDHC_CR_CMDTYP_RESUME CMD52 for writing Function Select in CCCR
 *  +      SDHC_CR_CMDTYP_ABORT CMD12, CMD52 for writing I/O Abort in CCCR
 * - SDHC_CR_CMDIDX(value) Command Index
 **/
static inline void sdhc_set_CR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->CR.reg |= mask;
}

/**
 * @brief sdhc get CR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_CR_RESPTYP(value) Response Type
 *  +      SDHC_CR_RESPTYP_NONE No response
 *  +      SDHC_CR_RESPTYP_136_BIT 136-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT 48-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT_BUSY 48-bit response check busy after response
 * - SDHC_CR_CMDCCEN Command CRC Check Enable
 *  +      SDHC_CR_CMDCCEN_DISABLE Disable
 *  +      SDHC_CR_CMDCCEN_ENABLE Enable
 * - SDHC_CR_CMDICEN Command Index Check Enable
 *  +      SDHC_CR_CMDICEN_DISABLE Disable
 *  +      SDHC_CR_CMDICEN_ENABLE Enable
 * - SDHC_CR_DPSEL Data Present Select
 *  +      SDHC_CR_DPSEL_NO_DATA No Data Present
 *  +      SDHC_CR_DPSEL_DATA Data Present
 * - SDHC_CR_CMDTYP(value) Command Type
 *  +      SDHC_CR_CMDTYP_NORMAL Other commands
 *  +      SDHC_CR_CMDTYP_SUSPEND CMD52 for writing Bus Suspend in CCCR
 *  +      SDHC_CR_CMDTYP_RESUME CMD52 for writing Function Select in CCCR
 *  +      SDHC_CR_CMDTYP_ABORT CMD12, CMD52 for writing I/O Abort in CCCR
 * - SDHC_CR_CMDIDX(value) Command Index
 **/
static inline uint16_t sdhc_get_CR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->CR.reg & mask);
}

/**
 * @brief sdhc write CR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_CR_RESPTYP(value) Response Type
 *  +      SDHC_CR_RESPTYP_NONE No response
 *  +      SDHC_CR_RESPTYP_136_BIT 136-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT 48-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT_BUSY 48-bit response check busy after response
 * - SDHC_CR_CMDCCEN Command CRC Check Enable
 *  +      SDHC_CR_CMDCCEN_DISABLE Disable
 *  +      SDHC_CR_CMDCCEN_ENABLE Enable
 * - SDHC_CR_CMDICEN Command Index Check Enable
 *  +      SDHC_CR_CMDICEN_DISABLE Disable
 *  +      SDHC_CR_CMDICEN_ENABLE Enable
 * - SDHC_CR_DPSEL Data Present Select
 *  +      SDHC_CR_DPSEL_NO_DATA No Data Present
 *  +      SDHC_CR_DPSEL_DATA Data Present
 * - SDHC_CR_CMDTYP(value) Command Type
 *  +      SDHC_CR_CMDTYP_NORMAL Other commands
 *  +      SDHC_CR_CMDTYP_SUSPEND CMD52 for writing Bus Suspend in CCCR
 *  +      SDHC_CR_CMDTYP_RESUME CMD52 for writing Function Select in CCCR
 *  +      SDHC_CR_CMDTYP_ABORT CMD12, CMD52 for writing I/O Abort in CCCR
 * - SDHC_CR_CMDIDX(value) Command Index
 **/
static inline void sdhc_write_CR(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->CR.reg = data;
}

/**
 * @brief sdhc clear CR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_CR_RESPTYP(value) Response Type
 *  +      SDHC_CR_RESPTYP_NONE No response
 *  +      SDHC_CR_RESPTYP_136_BIT 136-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT 48-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT_BUSY 48-bit response check busy after response
 * - SDHC_CR_CMDCCEN Command CRC Check Enable
 *  +      SDHC_CR_CMDCCEN_DISABLE Disable
 *  +      SDHC_CR_CMDCCEN_ENABLE Enable
 * - SDHC_CR_CMDICEN Command Index Check Enable
 *  +      SDHC_CR_CMDICEN_DISABLE Disable
 *  +      SDHC_CR_CMDICEN_ENABLE Enable
 * - SDHC_CR_DPSEL Data Present Select
 *  +      SDHC_CR_DPSEL_NO_DATA No Data Present
 *  +      SDHC_CR_DPSEL_DATA Data Present
 * - SDHC_CR_CMDTYP(value) Command Type
 *  +      SDHC_CR_CMDTYP_NORMAL Other commands
 *  +      SDHC_CR_CMDTYP_SUSPEND CMD52 for writing Bus Suspend in CCCR
 *  +      SDHC_CR_CMDTYP_RESUME CMD52 for writing Function Select in CCCR
 *  +      SDHC_CR_CMDTYP_ABORT CMD12, CMD52 for writing I/O Abort in CCCR
 * - SDHC_CR_CMDIDX(value) Command Index
 **/
static inline void sdhc_clear_CR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->CR.reg &= ~mask;
}

/**
 * @brief sdhc read CR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_CR_RESPTYP(value) Response Type
 *  +      SDHC_CR_RESPTYP_NONE No response
 *  +      SDHC_CR_RESPTYP_136_BIT 136-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT 48-bit response
 *  +      SDHC_CR_RESPTYP_48_BIT_BUSY 48-bit response check busy after response
 * - SDHC_CR_CMDCCEN Command CRC Check Enable
 *  +      SDHC_CR_CMDCCEN_DISABLE Disable
 *  +      SDHC_CR_CMDCCEN_ENABLE Enable
 * - SDHC_CR_CMDICEN Command Index Check Enable
 *  +      SDHC_CR_CMDICEN_DISABLE Disable
 *  +      SDHC_CR_CMDICEN_ENABLE Enable
 * - SDHC_CR_DPSEL Data Present Select
 *  +      SDHC_CR_DPSEL_NO_DATA No Data Present
 *  +      SDHC_CR_DPSEL_DATA Data Present
 * - SDHC_CR_CMDTYP(value) Command Type
 *  +      SDHC_CR_CMDTYP_NORMAL Other commands
 *  +      SDHC_CR_CMDTYP_SUSPEND CMD52 for writing Bus Suspend in CCCR
 *  +      SDHC_CR_CMDTYP_RESUME CMD52 for writing Function Select in CCCR
 *  +      SDHC_CR_CMDTYP_ABORT CMD12, CMD52 for writing I/O Abort in CCCR
 * - SDHC_CR_CMDIDX(value) Command Index
 **/
static inline uint16_t sdhc_read_CR(SDHC_t *pSDHC)
{
	return pSDHC->CR.reg;
}

/**
 * @brief sdhc set BDPR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_BDPR_BUFDATA(value) Buffer Data
 **/
static inline void sdhc_set_BDPR(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->BDPR.reg |= mask;
}

/**
 * @brief sdhc get BDPR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_BDPR_BUFDATA(value) Buffer Data
 **/
static inline uint32_t sdhc_get_BDPR(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->BDPR.reg & mask);
}

/**
 * @brief sdhc write BDPR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint32_t 
 * - SDHC_BDPR_BUFDATA(value) Buffer Data
 **/
static inline void sdhc_write_BDPR(SDHC_t *pSDHC, uint32_t data)
{
	pSDHC->BDPR.reg = data;
}

/**
 * @brief sdhc clear BDPR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_BDPR_BUFDATA(value) Buffer Data
 **/
static inline void sdhc_clear_BDPR(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->BDPR.reg &= ~mask;
}

/**
 * @brief sdhc read BDPR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_BDPR_BUFDATA(value) Buffer Data
 **/
static inline uint32_t sdhc_read_BDPR(SDHC_t *pSDHC)
{
	return pSDHC->BDPR.reg;
}

/**
 * @brief sdhc set PCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_PCR_SDBPWR SD Bus Power
 *  +      SDHC_PCR_SDBPWR_OFF Power off
 *  +      SDHC_PCR_SDBPWR_ON Power on
 * - SDHC_PCR_SDBVSEL(value) SD Bus Voltage Select
 *  +      SDHC_PCR_SDBVSEL_1V8 1.8V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V0 3.0V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V3 3.3V (Typ.)
 **/
static inline void sdhc_set_PCR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->PCR.reg |= mask;
}

/**
 * @brief sdhc get PCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_PCR_SDBPWR SD Bus Power
 *  +      SDHC_PCR_SDBPWR_OFF Power off
 *  +      SDHC_PCR_SDBPWR_ON Power on
 * - SDHC_PCR_SDBVSEL(value) SD Bus Voltage Select
 *  +      SDHC_PCR_SDBVSEL_1V8 1.8V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V0 3.0V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V3 3.3V (Typ.)
 **/
static inline uint8_t sdhc_get_PCR(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->PCR.reg & mask);
}

/**
 * @brief sdhc write PCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_PCR_SDBPWR SD Bus Power
 *  +      SDHC_PCR_SDBPWR_OFF Power off
 *  +      SDHC_PCR_SDBPWR_ON Power on
 * - SDHC_PCR_SDBVSEL(value) SD Bus Voltage Select
 *  +      SDHC_PCR_SDBVSEL_1V8 1.8V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V0 3.0V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V3 3.3V (Typ.)
 **/
static inline void sdhc_write_PCR(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->PCR.reg = data;
}

/**
 * @brief sdhc clear PCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_PCR_SDBPWR SD Bus Power
 *  +      SDHC_PCR_SDBPWR_OFF Power off
 *  +      SDHC_PCR_SDBPWR_ON Power on
 * - SDHC_PCR_SDBVSEL(value) SD Bus Voltage Select
 *  +      SDHC_PCR_SDBVSEL_1V8 1.8V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V0 3.0V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V3 3.3V (Typ.)
 **/
static inline void sdhc_clear_PCR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->PCR.reg &= ~mask;
}

/**
 * @brief sdhc read PCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_PCR_SDBPWR SD Bus Power
 *  +      SDHC_PCR_SDBPWR_OFF Power off
 *  +      SDHC_PCR_SDBPWR_ON Power on
 * - SDHC_PCR_SDBVSEL(value) SD Bus Voltage Select
 *  +      SDHC_PCR_SDBVSEL_1V8 1.8V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V0 3.0V (Typ.)
 *  +      SDHC_PCR_SDBVSEL_3V3 3.3V (Typ.)
 **/
static inline uint8_t sdhc_read_PCR(SDHC_t *pSDHC)
{
	return pSDHC->PCR.reg;
}

/**
 * @brief sdhc set WCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_WCR_WKENCINT Wakeup Event Enable on Card Interrupt
 *  +      SDHC_WCR_WKENCINT_DISABLE Disable
 *  +      SDHC_WCR_WKENCINT_ENABLE Enable
 * - SDHC_WCR_WKENCINS Wakeup Event Enable on Card Insertion
 *  +      SDHC_WCR_WKENCINS_DISABLE Disable
 *  +      SDHC_WCR_WKENCINS_ENABLE Enable
 * - SDHC_WCR_WKENCREM Wakeup Event Enable on Card Removal
 *  +      SDHC_WCR_WKENCREM_DISABLE Disable
 *  +      SDHC_WCR_WKENCREM_ENABLE Enable
 **/
static inline void sdhc_set_WCR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->WCR.reg |= mask;
}

/**
 * @brief sdhc get WCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_WCR_WKENCINT Wakeup Event Enable on Card Interrupt
 *  +      SDHC_WCR_WKENCINT_DISABLE Disable
 *  +      SDHC_WCR_WKENCINT_ENABLE Enable
 * - SDHC_WCR_WKENCINS Wakeup Event Enable on Card Insertion
 *  +      SDHC_WCR_WKENCINS_DISABLE Disable
 *  +      SDHC_WCR_WKENCINS_ENABLE Enable
 * - SDHC_WCR_WKENCREM Wakeup Event Enable on Card Removal
 *  +      SDHC_WCR_WKENCREM_DISABLE Disable
 *  +      SDHC_WCR_WKENCREM_ENABLE Enable
 **/
static inline uint8_t sdhc_get_WCR(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->WCR.reg & mask);
}

/**
 * @brief sdhc write WCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_WCR_WKENCINT Wakeup Event Enable on Card Interrupt
 *  +      SDHC_WCR_WKENCINT_DISABLE Disable
 *  +      SDHC_WCR_WKENCINT_ENABLE Enable
 * - SDHC_WCR_WKENCINS Wakeup Event Enable on Card Insertion
 *  +      SDHC_WCR_WKENCINS_DISABLE Disable
 *  +      SDHC_WCR_WKENCINS_ENABLE Enable
 * - SDHC_WCR_WKENCREM Wakeup Event Enable on Card Removal
 *  +      SDHC_WCR_WKENCREM_DISABLE Disable
 *  +      SDHC_WCR_WKENCREM_ENABLE Enable
 **/
static inline void sdhc_write_WCR(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->WCR.reg = data;
}

/**
 * @brief sdhc clear WCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_WCR_WKENCINT Wakeup Event Enable on Card Interrupt
 *  +      SDHC_WCR_WKENCINT_DISABLE Disable
 *  +      SDHC_WCR_WKENCINT_ENABLE Enable
 * - SDHC_WCR_WKENCINS Wakeup Event Enable on Card Insertion
 *  +      SDHC_WCR_WKENCINS_DISABLE Disable
 *  +      SDHC_WCR_WKENCINS_ENABLE Enable
 * - SDHC_WCR_WKENCREM Wakeup Event Enable on Card Removal
 *  +      SDHC_WCR_WKENCREM_DISABLE Disable
 *  +      SDHC_WCR_WKENCREM_ENABLE Enable
 **/
static inline void sdhc_clear_WCR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->WCR.reg &= ~mask;
}

/**
 * @brief sdhc read WCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_WCR_WKENCINT Wakeup Event Enable on Card Interrupt
 *  +      SDHC_WCR_WKENCINT_DISABLE Disable
 *  +      SDHC_WCR_WKENCINT_ENABLE Enable
 * - SDHC_WCR_WKENCINS Wakeup Event Enable on Card Insertion
 *  +      SDHC_WCR_WKENCINS_DISABLE Disable
 *  +      SDHC_WCR_WKENCINS_ENABLE Enable
 * - SDHC_WCR_WKENCREM Wakeup Event Enable on Card Removal
 *  +      SDHC_WCR_WKENCREM_DISABLE Disable
 *  +      SDHC_WCR_WKENCREM_ENABLE Enable
 **/
static inline uint8_t sdhc_read_WCR(SDHC_t *pSDHC)
{
	return pSDHC->WCR.reg;
}

/**
 * @brief sdhc set CCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_CCR_INTCLKEN Internal Clock Enable
 *  +      SDHC_CCR_INTCLKEN_OFF Stop
 *  +      SDHC_CCR_INTCLKEN_ON Oscillate
 * - SDHC_CCR_INTCLKS Internal Clock Stable
 *  +      SDHC_CCR_INTCLKS_NOT_READY Not Ready
 *  +      SDHC_CCR_INTCLKS_READY Ready
 * - SDHC_CCR_SDCLKEN SD Clock Enable
 *  +      SDHC_CCR_SDCLKEN_DISABLE Disable
 *  +      SDHC_CCR_SDCLKEN_ENABLE Enable
 * - SDHC_CCR_CLKGSEL Clock Generator Select
 *  +      SDHC_CCR_CLKGSEL_DIV Divided Clock Mode
 *  +      SDHC_CCR_CLKGSEL_PROG Programmable Clock Mode
 * - SDHC_CCR_USDCLKFSEL(value) Upper Bits of SDCLK Frequency Select
 * - SDHC_CCR_SDCLKFSEL(value) SDCLK Frequency Select
 **/
static inline void sdhc_set_CCR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->CCR.reg |= mask;
}

/**
 * @brief sdhc get CCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_CCR_INTCLKEN Internal Clock Enable
 *  +      SDHC_CCR_INTCLKEN_OFF Stop
 *  +      SDHC_CCR_INTCLKEN_ON Oscillate
 * - SDHC_CCR_INTCLKS Internal Clock Stable
 *  +      SDHC_CCR_INTCLKS_NOT_READY Not Ready
 *  +      SDHC_CCR_INTCLKS_READY Ready
 * - SDHC_CCR_SDCLKEN SD Clock Enable
 *  +      SDHC_CCR_SDCLKEN_DISABLE Disable
 *  +      SDHC_CCR_SDCLKEN_ENABLE Enable
 * - SDHC_CCR_CLKGSEL Clock Generator Select
 *  +      SDHC_CCR_CLKGSEL_DIV Divided Clock Mode
 *  +      SDHC_CCR_CLKGSEL_PROG Programmable Clock Mode
 * - SDHC_CCR_USDCLKFSEL(value) Upper Bits of SDCLK Frequency Select
 * - SDHC_CCR_SDCLKFSEL(value) SDCLK Frequency Select
 **/
static inline uint16_t sdhc_get_CCR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->CCR.reg & mask);
}

/**
 * @brief sdhc write CCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint16_t 
 * - SDHC_CCR_INTCLKEN Internal Clock Enable
 *  +      SDHC_CCR_INTCLKEN_OFF Stop
 *  +      SDHC_CCR_INTCLKEN_ON Oscillate
 * - SDHC_CCR_INTCLKS Internal Clock Stable
 *  +      SDHC_CCR_INTCLKS_NOT_READY Not Ready
 *  +      SDHC_CCR_INTCLKS_READY Ready
 * - SDHC_CCR_SDCLKEN SD Clock Enable
 *  +      SDHC_CCR_SDCLKEN_DISABLE Disable
 *  +      SDHC_CCR_SDCLKEN_ENABLE Enable
 * - SDHC_CCR_CLKGSEL Clock Generator Select
 *  +      SDHC_CCR_CLKGSEL_DIV Divided Clock Mode
 *  +      SDHC_CCR_CLKGSEL_PROG Programmable Clock Mode
 * - SDHC_CCR_USDCLKFSEL(value) Upper Bits of SDCLK Frequency Select
 * - SDHC_CCR_SDCLKFSEL(value) SDCLK Frequency Select
 **/
static inline void sdhc_write_CCR(SDHC_t *pSDHC, uint16_t data)
{
	pSDHC->CCR.reg = data;
}

/**
 * @brief sdhc clear CCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * - SDHC_CCR_INTCLKEN Internal Clock Enable
 *  +      SDHC_CCR_INTCLKEN_OFF Stop
 *  +      SDHC_CCR_INTCLKEN_ON Oscillate
 * - SDHC_CCR_INTCLKS Internal Clock Stable
 *  +      SDHC_CCR_INTCLKS_NOT_READY Not Ready
 *  +      SDHC_CCR_INTCLKS_READY Ready
 * - SDHC_CCR_SDCLKEN SD Clock Enable
 *  +      SDHC_CCR_SDCLKEN_DISABLE Disable
 *  +      SDHC_CCR_SDCLKEN_ENABLE Enable
 * - SDHC_CCR_CLKGSEL Clock Generator Select
 *  +      SDHC_CCR_CLKGSEL_DIV Divided Clock Mode
 *  +      SDHC_CCR_CLKGSEL_PROG Programmable Clock Mode
 * - SDHC_CCR_USDCLKFSEL(value) Upper Bits of SDCLK Frequency Select
 * - SDHC_CCR_SDCLKFSEL(value) SDCLK Frequency Select
 **/
static inline void sdhc_clear_CCR(SDHC_t *pSDHC, uint16_t mask)
{
	pSDHC->CCR.reg &= ~mask;
}

/**
 * @brief sdhc read CCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_CCR_INTCLKEN Internal Clock Enable
 *  +      SDHC_CCR_INTCLKEN_OFF Stop
 *  +      SDHC_CCR_INTCLKEN_ON Oscillate
 * - SDHC_CCR_INTCLKS Internal Clock Stable
 *  +      SDHC_CCR_INTCLKS_NOT_READY Not Ready
 *  +      SDHC_CCR_INTCLKS_READY Ready
 * - SDHC_CCR_SDCLKEN SD Clock Enable
 *  +      SDHC_CCR_SDCLKEN_DISABLE Disable
 *  +      SDHC_CCR_SDCLKEN_ENABLE Enable
 * - SDHC_CCR_CLKGSEL Clock Generator Select
 *  +      SDHC_CCR_CLKGSEL_DIV Divided Clock Mode
 *  +      SDHC_CCR_CLKGSEL_PROG Programmable Clock Mode
 * - SDHC_CCR_USDCLKFSEL(value) Upper Bits of SDCLK Frequency Select
 * - SDHC_CCR_SDCLKFSEL(value) SDCLK Frequency Select
 **/
static inline uint16_t sdhc_read_CCR(SDHC_t *pSDHC)
{
	return pSDHC->CCR.reg;
}

/**
 * @brief sdhc get TCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_TCR_DTCVAL(value) Data Timeout Counter Value
 **/
static inline uint8_t sdhc_get_TCR(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->TCR.reg & mask);
}

/**
 * @brief sdhc write TCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_TCR_DTCVAL(value) Data Timeout Counter Value
 **/
static inline void sdhc_write_TCR(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->TCR.reg = data;
}

/**
 * @brief sdhc read TCR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_TCR_DTCVAL(value) Data Timeout Counter Value
 **/
static inline uint8_t sdhc_read_TCR(SDHC_t *pSDHC)
{
	return pSDHC->TCR.reg;
}

/**
 * @brief sdhc set SRR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_SRR_SWRSTALL Software Reset For All
 *  +      SDHC_SRR_SWRSTALL_WORK Work
 *  +      SDHC_SRR_SWRSTALL_RESET Reset
 * - SDHC_SRR_SWRSTCMD Software Reset For CMD Line
 *  +      SDHC_SRR_SWRSTCMD_WORK Work
 *  +      SDHC_SRR_SWRSTCMD_RESET Reset
 * - SDHC_SRR_SWRSTDAT Software Reset For DAT Line
 *  +      SDHC_SRR_SWRSTDAT_WORK Work
 *  +      SDHC_SRR_SWRSTDAT_RESET Reset
 **/
static inline void sdhc_set_SRR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->SRR.reg |= mask;
}

/**
 * @brief sdhc get SRR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_SRR_SWRSTALL Software Reset For All
 *  +      SDHC_SRR_SWRSTALL_WORK Work
 *  +      SDHC_SRR_SWRSTALL_RESET Reset
 * - SDHC_SRR_SWRSTCMD Software Reset For CMD Line
 *  +      SDHC_SRR_SWRSTCMD_WORK Work
 *  +      SDHC_SRR_SWRSTCMD_RESET Reset
 * - SDHC_SRR_SWRSTDAT Software Reset For DAT Line
 *  +      SDHC_SRR_SWRSTDAT_WORK Work
 *  +      SDHC_SRR_SWRSTDAT_RESET Reset
 **/
static inline uint8_t sdhc_get_SRR(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->SRR.reg & mask);
}

/**
 * @brief sdhc write SRR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_SRR_SWRSTALL Software Reset For All
 *  +      SDHC_SRR_SWRSTALL_WORK Work
 *  +      SDHC_SRR_SWRSTALL_RESET Reset
 * - SDHC_SRR_SWRSTCMD Software Reset For CMD Line
 *  +      SDHC_SRR_SWRSTCMD_WORK Work
 *  +      SDHC_SRR_SWRSTCMD_RESET Reset
 * - SDHC_SRR_SWRSTDAT Software Reset For DAT Line
 *  +      SDHC_SRR_SWRSTDAT_WORK Work
 *  +      SDHC_SRR_SWRSTDAT_RESET Reset
 **/
static inline void sdhc_write_SRR(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->SRR.reg = data;
}

/**
 * @brief sdhc read SRR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_SRR_SWRSTALL Software Reset For All
 *  +      SDHC_SRR_SWRSTALL_WORK Work
 *  +      SDHC_SRR_SWRSTALL_RESET Reset
 * - SDHC_SRR_SWRSTCMD Software Reset For CMD Line
 *  +      SDHC_SRR_SWRSTCMD_WORK Work
 *  +      SDHC_SRR_SWRSTCMD_RESET Reset
 * - SDHC_SRR_SWRSTDAT Software Reset For DAT Line
 *  +      SDHC_SRR_SWRSTDAT_WORK Work
 *  +      SDHC_SRR_SWRSTDAT_RESET Reset
 **/
static inline uint8_t sdhc_read_SRR(SDHC_t *pSDHC)
{
	return pSDHC->SRR.reg;
}

/**
 * @brief sdhc set ASAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - SDHC_ASAR_ADMASA(value) ADMA System Address
 **/
static inline void sdhc_set_ASAR(SDHC_t *pSDHC, uint8_t index, uint32_t mask)
{
	pSDHC->ASAR[index].reg |= mask;
}

/**
 * @brief sdhc get ASAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_ASAR_ADMASA(value) ADMA System Address
 **/
static inline uint32_t sdhc_get_ASAR(SDHC_t *pSDHC, uint8_t index, uint32_t mask)
{
    return (pSDHC->ASAR[index].reg & mask);
}

/**
 * @brief sdhc write ASAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - SDHC_ASAR_ADMASA(value) ADMA System Address
 **/
static inline void sdhc_write_ASAR(SDHC_t *pSDHC, uint8_t index, uint32_t data)
{
	pSDHC->ASAR[index].reg = data;
}

/**
 * @brief sdhc clear ASAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - SDHC_ASAR_ADMASA(value) ADMA System Address
 **/
static inline void sdhc_clear_ASAR(SDHC_t *pSDHC, uint8_t index, uint32_t mask)
{
	pSDHC->ASAR[index].reg &= ~mask;
}

/**
 * @brief sdhc read ASAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - SDHC_ASAR_ADMASA(value) ADMA System Address
 **/
static inline uint32_t sdhc_read_ASAR(SDHC_t *pSDHC, uint8_t index)
{
	return pSDHC->ASAR[index].reg;
}

/**
 * @brief sdhc set PVR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] mask uint16_t 
 * - SDHC_PVR_SDCLKFSEL(value) SDCLK Frequency Select Value for Initialization
 * - SDHC_PVR_CLKGSEL Clock Generator Select Value for Initialization
 *  +      SDHC_PVR_CLKGSEL_DIV Host Controller Ver2.00 Compatible Clock Generator (Divider)
 *  +      SDHC_PVR_CLKGSEL_PROG Programmable Clock Generator
 * - SDHC_PVR_DRVSEL(value) Driver Strength Select Value for Initialization
 *  +      SDHC_PVR_DRVSEL_B Driver Type B is Selected
 *  +      SDHC_PVR_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_PVR_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_PVR_DRVSEL_D Driver Type D is Selected
 **/
static inline void sdhc_set_PVR(SDHC_t *pSDHC, uint8_t index, uint16_t mask)
{
	pSDHC->PVR[index].reg |= mask;
}

/**
 * @brief sdhc get PVR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_PVR_SDCLKFSEL(value) SDCLK Frequency Select Value for Initialization
 * - SDHC_PVR_CLKGSEL Clock Generator Select Value for Initialization
 *  +      SDHC_PVR_CLKGSEL_DIV Host Controller Ver2.00 Compatible Clock Generator (Divider)
 *  +      SDHC_PVR_CLKGSEL_PROG Programmable Clock Generator
 * - SDHC_PVR_DRVSEL(value) Driver Strength Select Value for Initialization
 *  +      SDHC_PVR_DRVSEL_B Driver Type B is Selected
 *  +      SDHC_PVR_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_PVR_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_PVR_DRVSEL_D Driver Type D is Selected
 **/
static inline uint16_t sdhc_get_PVR(SDHC_t *pSDHC, uint8_t index, uint16_t mask)
{
    return (pSDHC->PVR[index].reg & mask);
}

/**
 * @brief sdhc write PVR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] data uint16_t 
 * - SDHC_PVR_SDCLKFSEL(value) SDCLK Frequency Select Value for Initialization
 * - SDHC_PVR_CLKGSEL Clock Generator Select Value for Initialization
 *  +      SDHC_PVR_CLKGSEL_DIV Host Controller Ver2.00 Compatible Clock Generator (Divider)
 *  +      SDHC_PVR_CLKGSEL_PROG Programmable Clock Generator
 * - SDHC_PVR_DRVSEL(value) Driver Strength Select Value for Initialization
 *  +      SDHC_PVR_DRVSEL_B Driver Type B is Selected
 *  +      SDHC_PVR_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_PVR_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_PVR_DRVSEL_D Driver Type D is Selected
 **/
static inline void sdhc_write_PVR(SDHC_t *pSDHC, uint8_t index, uint16_t data)
{
	pSDHC->PVR[index].reg = data;
}

/**
 * @brief sdhc clear PVR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] mask uint16_t 
 * - SDHC_PVR_SDCLKFSEL(value) SDCLK Frequency Select Value for Initialization
 * - SDHC_PVR_CLKGSEL Clock Generator Select Value for Initialization
 *  +      SDHC_PVR_CLKGSEL_DIV Host Controller Ver2.00 Compatible Clock Generator (Divider)
 *  +      SDHC_PVR_CLKGSEL_PROG Programmable Clock Generator
 * - SDHC_PVR_DRVSEL(value) Driver Strength Select Value for Initialization
 *  +      SDHC_PVR_DRVSEL_B Driver Type B is Selected
 *  +      SDHC_PVR_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_PVR_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_PVR_DRVSEL_D Driver Type D is Selected
 **/
static inline void sdhc_clear_PVR(SDHC_t *pSDHC, uint8_t index, uint16_t mask)
{
	pSDHC->PVR[index].reg &= ~mask;
}

/**
 * @brief sdhc read PVR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @return uint16_t
 * - SDHC_PVR_SDCLKFSEL(value) SDCLK Frequency Select Value for Initialization
 * - SDHC_PVR_CLKGSEL Clock Generator Select Value for Initialization
 *  +      SDHC_PVR_CLKGSEL_DIV Host Controller Ver2.00 Compatible Clock Generator (Divider)
 *  +      SDHC_PVR_CLKGSEL_PROG Programmable Clock Generator
 * - SDHC_PVR_DRVSEL(value) Driver Strength Select Value for Initialization
 *  +      SDHC_PVR_DRVSEL_B Driver Type B is Selected
 *  +      SDHC_PVR_DRVSEL_A Driver Type A is Selected
 *  +      SDHC_PVR_DRVSEL_C Driver Type C is Selected
 *  +      SDHC_PVR_DRVSEL_D Driver Type D is Selected
 **/
static inline uint16_t sdhc_read_PVR(SDHC_t *pSDHC, uint8_t index)
{
	return pSDHC->PVR[index].reg;
}

/**
 * @brief sdhc set MC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_MC1R_CMDTYP(value) e.MMC Command Type
 *  +      SDHC_MC1R_CMDTYP_NORMAL Not a MMC specific command
 *  +      SDHC_MC1R_CMDTYP_WAITIRQ Wait IRQ Command
 *  +      SDHC_MC1R_CMDTYP_STREAM Stream Command
 *  +      SDHC_MC1R_CMDTYP_BOOT Boot Command
 * - SDHC_MC1R_DDR e.MMC HSDDR Mode
 * - SDHC_MC1R_OPD e.MMC Open Drain Mode
 * - SDHC_MC1R_BOOTA e.MMC Boot Acknowledge Enable
 * - SDHC_MC1R_RSTN e.MMC Reset Signal
 * - SDHC_MC1R_FCD e.MMC Force Card Detect
 **/
static inline void sdhc_set_MC1R(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->MC1R.reg |= mask;
}

/**
 * @brief sdhc get MC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_MC1R_CMDTYP(value) e.MMC Command Type
 *  +      SDHC_MC1R_CMDTYP_NORMAL Not a MMC specific command
 *  +      SDHC_MC1R_CMDTYP_WAITIRQ Wait IRQ Command
 *  +      SDHC_MC1R_CMDTYP_STREAM Stream Command
 *  +      SDHC_MC1R_CMDTYP_BOOT Boot Command
 * - SDHC_MC1R_DDR e.MMC HSDDR Mode
 * - SDHC_MC1R_OPD e.MMC Open Drain Mode
 * - SDHC_MC1R_BOOTA e.MMC Boot Acknowledge Enable
 * - SDHC_MC1R_RSTN e.MMC Reset Signal
 * - SDHC_MC1R_FCD e.MMC Force Card Detect
 **/
static inline uint8_t sdhc_get_MC1R(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->MC1R.reg & mask);
}

/**
 * @brief sdhc write MC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_MC1R_CMDTYP(value) e.MMC Command Type
 *  +      SDHC_MC1R_CMDTYP_NORMAL Not a MMC specific command
 *  +      SDHC_MC1R_CMDTYP_WAITIRQ Wait IRQ Command
 *  +      SDHC_MC1R_CMDTYP_STREAM Stream Command
 *  +      SDHC_MC1R_CMDTYP_BOOT Boot Command
 * - SDHC_MC1R_DDR e.MMC HSDDR Mode
 * - SDHC_MC1R_OPD e.MMC Open Drain Mode
 * - SDHC_MC1R_BOOTA e.MMC Boot Acknowledge Enable
 * - SDHC_MC1R_RSTN e.MMC Reset Signal
 * - SDHC_MC1R_FCD e.MMC Force Card Detect
 **/
static inline void sdhc_write_MC1R(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->MC1R.reg = data;
}

/**
 * @brief sdhc clear MC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_MC1R_CMDTYP(value) e.MMC Command Type
 *  +      SDHC_MC1R_CMDTYP_NORMAL Not a MMC specific command
 *  +      SDHC_MC1R_CMDTYP_WAITIRQ Wait IRQ Command
 *  +      SDHC_MC1R_CMDTYP_STREAM Stream Command
 *  +      SDHC_MC1R_CMDTYP_BOOT Boot Command
 * - SDHC_MC1R_DDR e.MMC HSDDR Mode
 * - SDHC_MC1R_OPD e.MMC Open Drain Mode
 * - SDHC_MC1R_BOOTA e.MMC Boot Acknowledge Enable
 * - SDHC_MC1R_RSTN e.MMC Reset Signal
 * - SDHC_MC1R_FCD e.MMC Force Card Detect
 **/
static inline void sdhc_clear_MC1R(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->MC1R.reg &= ~mask;
}

/**
 * @brief sdhc read MC1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_MC1R_CMDTYP(value) e.MMC Command Type
 *  +      SDHC_MC1R_CMDTYP_NORMAL Not a MMC specific command
 *  +      SDHC_MC1R_CMDTYP_WAITIRQ Wait IRQ Command
 *  +      SDHC_MC1R_CMDTYP_STREAM Stream Command
 *  +      SDHC_MC1R_CMDTYP_BOOT Boot Command
 * - SDHC_MC1R_DDR e.MMC HSDDR Mode
 * - SDHC_MC1R_OPD e.MMC Open Drain Mode
 * - SDHC_MC1R_BOOTA e.MMC Boot Acknowledge Enable
 * - SDHC_MC1R_RSTN e.MMC Reset Signal
 * - SDHC_MC1R_FCD e.MMC Force Card Detect
 **/
static inline uint8_t sdhc_read_MC1R(SDHC_t *pSDHC)
{
	return pSDHC->MC1R.reg;
}

/**
 * @brief sdhc set ACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_ACR_BMAX(value) AHB Maximum Burst
 *  +      SDHC_ACR_BMAX_INCR16
 *  +      SDHC_ACR_BMAX_INCR8
 *  +      SDHC_ACR_BMAX_INCR4
 *  +      SDHC_ACR_BMAX_SINGLE
 **/
static inline void sdhc_set_ACR(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->ACR.reg |= mask;
}

/**
 * @brief sdhc get ACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_ACR_BMAX(value) AHB Maximum Burst
 *  +      SDHC_ACR_BMAX_INCR16
 *  +      SDHC_ACR_BMAX_INCR8
 *  +      SDHC_ACR_BMAX_INCR4
 *  +      SDHC_ACR_BMAX_SINGLE
 **/
static inline uint32_t sdhc_get_ACR(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->ACR.reg & mask);
}

/**
 * @brief sdhc write ACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint32_t 
 * - SDHC_ACR_BMAX(value) AHB Maximum Burst
 *  +      SDHC_ACR_BMAX_INCR16
 *  +      SDHC_ACR_BMAX_INCR8
 *  +      SDHC_ACR_BMAX_INCR4
 *  +      SDHC_ACR_BMAX_SINGLE
 **/
static inline void sdhc_write_ACR(SDHC_t *pSDHC, uint32_t data)
{
	pSDHC->ACR.reg = data;
}

/**
 * @brief sdhc clear ACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_ACR_BMAX(value) AHB Maximum Burst
 *  +      SDHC_ACR_BMAX_INCR16
 *  +      SDHC_ACR_BMAX_INCR8
 *  +      SDHC_ACR_BMAX_INCR4
 *  +      SDHC_ACR_BMAX_SINGLE
 **/
static inline void sdhc_clear_ACR(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->ACR.reg &= ~mask;
}

/**
 * @brief sdhc read ACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_ACR_BMAX(value) AHB Maximum Burst
 *  +      SDHC_ACR_BMAX_INCR16
 *  +      SDHC_ACR_BMAX_INCR8
 *  +      SDHC_ACR_BMAX_INCR4
 *  +      SDHC_ACR_BMAX_SINGLE
 **/
static inline uint32_t sdhc_read_ACR(SDHC_t *pSDHC)
{
	return pSDHC->ACR.reg;
}

/**
 * @brief sdhc set CC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_CC2R_FSDCLKD Force SDCK Disabled
 *  +      SDHC_CC2R_FSDCLKD_NOEFFECT No effect
 *  +      SDHC_CC2R_FSDCLKD_DISABLE SDCLK can be stopped at any time after DATA transfer.SDCLK enable forcing for 8 SDCLK cycles is disabled
 **/
static inline void sdhc_set_CC2R(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->CC2R.reg |= mask;
}

/**
 * @brief sdhc get CC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_CC2R_FSDCLKD Force SDCK Disabled
 *  +      SDHC_CC2R_FSDCLKD_NOEFFECT No effect
 *  +      SDHC_CC2R_FSDCLKD_DISABLE SDCLK can be stopped at any time after DATA transfer.SDCLK enable forcing for 8 SDCLK cycles is disabled
 **/
static inline uint32_t sdhc_get_CC2R(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->CC2R.reg & mask);
}

/**
 * @brief sdhc write CC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint32_t 
 * - SDHC_CC2R_FSDCLKD Force SDCK Disabled
 *  +      SDHC_CC2R_FSDCLKD_NOEFFECT No effect
 *  +      SDHC_CC2R_FSDCLKD_DISABLE SDCLK can be stopped at any time after DATA transfer.SDCLK enable forcing for 8 SDCLK cycles is disabled
 **/
static inline void sdhc_write_CC2R(SDHC_t *pSDHC, uint32_t data)
{
	pSDHC->CC2R.reg = data;
}

/**
 * @brief sdhc clear CC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_CC2R_FSDCLKD Force SDCK Disabled
 *  +      SDHC_CC2R_FSDCLKD_NOEFFECT No effect
 *  +      SDHC_CC2R_FSDCLKD_DISABLE SDCLK can be stopped at any time after DATA transfer.SDCLK enable forcing for 8 SDCLK cycles is disabled
 **/
static inline void sdhc_clear_CC2R(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->CC2R.reg &= ~mask;
}

/**
 * @brief sdhc read CC2R register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_CC2R_FSDCLKD Force SDCK Disabled
 *  +      SDHC_CC2R_FSDCLKD_NOEFFECT No effect
 *  +      SDHC_CC2R_FSDCLKD_DISABLE SDCLK can be stopped at any time after DATA transfer.SDCLK enable forcing for 8 SDCLK cycles is disabled
 **/
static inline uint32_t sdhc_read_CC2R(SDHC_t *pSDHC)
{
	return pSDHC->CC2R.reg;
}

/**
 * @brief sdhc set CACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_CACR_CAPWREN Capabilities Registers Write Enable (Required to write the correct frequencies in the Capabilities Registers)
 * - SDHC_CACR_KEY(value) Key (0x46)
 **/
static inline void sdhc_set_CACR(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->CACR.reg |= mask;
}

/**
 * @brief sdhc get CACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_CACR_CAPWREN Capabilities Registers Write Enable (Required to write the correct frequencies in the Capabilities Registers)
 * - SDHC_CACR_KEY(value) Key (0x46)
 **/
static inline uint32_t sdhc_get_CACR(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->CACR.reg & mask);
}

/**
 * @brief sdhc write CACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint32_t 
 * - SDHC_CACR_CAPWREN Capabilities Registers Write Enable (Required to write the correct frequencies in the Capabilities Registers)
 * - SDHC_CACR_KEY(value) Key (0x46)
 **/
static inline void sdhc_write_CACR(SDHC_t *pSDHC, uint32_t data)
{
	pSDHC->CACR.reg = data;
}

/**
 * @brief sdhc clear CACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * - SDHC_CACR_CAPWREN Capabilities Registers Write Enable (Required to write the correct frequencies in the Capabilities Registers)
 * - SDHC_CACR_KEY(value) Key (0x46)
 **/
static inline void sdhc_clear_CACR(SDHC_t *pSDHC, uint32_t mask)
{
	pSDHC->CACR.reg &= ~mask;
}

/**
 * @brief sdhc read CACR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_CACR_CAPWREN Capabilities Registers Write Enable (Required to write the correct frequencies in the Capabilities Registers)
 * - SDHC_CACR_KEY(value) Key (0x46)
 **/
static inline uint32_t sdhc_read_CACR(SDHC_t *pSDHC)
{
	return pSDHC->CACR.reg;
}

/**
 * @brief sdhc set DBGR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_DBGR_NIDBG Non-intrusive debug enable
 *  +      SDHC_DBGR_NIDBG_IDBG Debugging is intrusive (reads of BDPR from debugger are considered and increment the internal buffer pointer)
 *  +      SDHC_DBGR_NIDBG_NIDBG Debugging is not intrusive (reads of BDPR from debugger are discarded and do not increment the internal buffer pointer)
 **/
static inline void sdhc_set_DBGR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->DBGR.reg |= mask;
}

/**
 * @brief sdhc get DBGR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_DBGR_NIDBG Non-intrusive debug enable
 *  +      SDHC_DBGR_NIDBG_IDBG Debugging is intrusive (reads of BDPR from debugger are considered and increment the internal buffer pointer)
 *  +      SDHC_DBGR_NIDBG_NIDBG Debugging is not intrusive (reads of BDPR from debugger are discarded and do not increment the internal buffer pointer)
 **/
static inline uint8_t sdhc_get_DBGR(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->DBGR.reg & mask);
}

/**
 * @brief sdhc write DBGR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] data uint8_t 
 * - SDHC_DBGR_NIDBG Non-intrusive debug enable
 *  +      SDHC_DBGR_NIDBG_IDBG Debugging is intrusive (reads of BDPR from debugger are considered and increment the internal buffer pointer)
 *  +      SDHC_DBGR_NIDBG_NIDBG Debugging is not intrusive (reads of BDPR from debugger are discarded and do not increment the internal buffer pointer)
 **/
static inline void sdhc_write_DBGR(SDHC_t *pSDHC, uint8_t data)
{
	pSDHC->DBGR.reg = data;
}

/**
 * @brief sdhc clear DBGR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * - SDHC_DBGR_NIDBG Non-intrusive debug enable
 *  +      SDHC_DBGR_NIDBG_IDBG Debugging is intrusive (reads of BDPR from debugger are considered and increment the internal buffer pointer)
 *  +      SDHC_DBGR_NIDBG_NIDBG Debugging is not intrusive (reads of BDPR from debugger are discarded and do not increment the internal buffer pointer)
 **/
static inline void sdhc_clear_DBGR(SDHC_t *pSDHC, uint8_t mask)
{
	pSDHC->DBGR.reg &= ~mask;
}

/**
 * @brief sdhc read DBGR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_DBGR_NIDBG Non-intrusive debug enable
 *  +      SDHC_DBGR_NIDBG_IDBG Debugging is intrusive (reads of BDPR from debugger are considered and increment the internal buffer pointer)
 *  +      SDHC_DBGR_NIDBG_NIDBG Debugging is not intrusive (reads of BDPR from debugger are discarded and do not increment the internal buffer pointer)
 **/
static inline uint8_t sdhc_read_DBGR(SDHC_t *pSDHC)
{
	return pSDHC->DBGR.reg;
}

/**
 * @brief sdhc get RR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_RR_CMDRESP(value) Command Response
 **/
static inline uint32_t sdhc_get_RR(SDHC_t *pSDHC, uint8_t index, uint32_t mask)
{
    return (pSDHC->RR[index].reg & mask);
}

/**
 * @brief sdhc read RR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - SDHC_RR_CMDRESP(value) Command Response
 **/
static inline uint32_t sdhc_read_RR(SDHC_t *pSDHC, uint8_t index)
{
	return pSDHC->RR[index].reg;
}

/**
 * @brief sdhc get PSR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_PSR_CMDINHC Command Inhibit
 *  +      SDHC_PSR_CMDINHC_CAN Can issue command using only CMD line
 *  +      SDHC_PSR_CMDINHC_CANNOT Cannot issue command
 * - SDHC_PSR_CMDINHD Command Inhibit
 *  +      SDHC_PSR_CMDINHD_CAN Can issue command which uses the DAT line
 *  +      SDHC_PSR_CMDINHD_CANNOT Cannot issue command which uses the DAT line
 * - SDHC_PSR_DLACT DAT Line Active
 *  +      SDHC_PSR_DLACT_INACTIVE DAT Line Inactive
 *  +      SDHC_PSR_DLACT_ACTIVE DAT Line Active
 * - SDHC_PSR_RTREQ Re-Tuning Request
 *  +      SDHC_PSR_RTREQ_OK Fixed or well-tuned sampling clock
 *  +      SDHC_PSR_RTREQ_REQUIRED Sampling clock needs re-tuning
 * - SDHC_PSR_WTACT Write Transfer Active
 *  +      SDHC_PSR_WTACT_NO No valid data
 *  +      SDHC_PSR_WTACT_YES Transferring data
 * - SDHC_PSR_RTACT Read Transfer Active
 *  +      SDHC_PSR_RTACT_NO No valid data
 *  +      SDHC_PSR_RTACT_YES Transferring data
 * - SDHC_PSR_BUFWREN Buffer Write Enable
 *  +      SDHC_PSR_BUFWREN_DISABLE Write disable
 *  +      SDHC_PSR_BUFWREN_ENABLE Write enable
 * - SDHC_PSR_BUFRDEN Buffer Read Enable
 *  +      SDHC_PSR_BUFRDEN_DISABLE Read disable
 *  +      SDHC_PSR_BUFRDEN_ENABLE Read enable
 * - SDHC_PSR_CARDINS Card Inserted
 *  +      SDHC_PSR_CARDINS_NO Reset or Debouncing or No Card
 *  +      SDHC_PSR_CARDINS_YES Card inserted
 * - SDHC_PSR_CARDSS Card State Stable
 *  +      SDHC_PSR_CARDSS_NO Reset or Debouncing
 *  +      SDHC_PSR_CARDSS_YES No Card or Insered
 * - SDHC_PSR_CARDDPL Card Detect Pin Level
 *  +      SDHC_PSR_CARDDPL_NO No card present (SDCD#=1)
 *  +      SDHC_PSR_CARDDPL_YES Card present (SDCD#=0)
 * - SDHC_PSR_WRPPL Write Protect Pin Level
 *  +      SDHC_PSR_WRPPL_PROTECTED Write protected (SDWP#=0)
 *  +      SDHC_PSR_WRPPL_ENABLED Write enabled (SDWP#=1)
 * - SDHC_PSR_DATLL(value) DAT[3:0] Line Level
 * - SDHC_PSR_CMDLL CMD Line Level
 **/
static inline uint32_t sdhc_get_PSR(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->PSR.reg & mask);
}

/**
 * @brief sdhc read PSR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_PSR_CMDINHC Command Inhibit
 *  +      SDHC_PSR_CMDINHC_CAN Can issue command using only CMD line
 *  +      SDHC_PSR_CMDINHC_CANNOT Cannot issue command
 * - SDHC_PSR_CMDINHD Command Inhibit
 *  +      SDHC_PSR_CMDINHD_CAN Can issue command which uses the DAT line
 *  +      SDHC_PSR_CMDINHD_CANNOT Cannot issue command which uses the DAT line
 * - SDHC_PSR_DLACT DAT Line Active
 *  +      SDHC_PSR_DLACT_INACTIVE DAT Line Inactive
 *  +      SDHC_PSR_DLACT_ACTIVE DAT Line Active
 * - SDHC_PSR_RTREQ Re-Tuning Request
 *  +      SDHC_PSR_RTREQ_OK Fixed or well-tuned sampling clock
 *  +      SDHC_PSR_RTREQ_REQUIRED Sampling clock needs re-tuning
 * - SDHC_PSR_WTACT Write Transfer Active
 *  +      SDHC_PSR_WTACT_NO No valid data
 *  +      SDHC_PSR_WTACT_YES Transferring data
 * - SDHC_PSR_RTACT Read Transfer Active
 *  +      SDHC_PSR_RTACT_NO No valid data
 *  +      SDHC_PSR_RTACT_YES Transferring data
 * - SDHC_PSR_BUFWREN Buffer Write Enable
 *  +      SDHC_PSR_BUFWREN_DISABLE Write disable
 *  +      SDHC_PSR_BUFWREN_ENABLE Write enable
 * - SDHC_PSR_BUFRDEN Buffer Read Enable
 *  +      SDHC_PSR_BUFRDEN_DISABLE Read disable
 *  +      SDHC_PSR_BUFRDEN_ENABLE Read enable
 * - SDHC_PSR_CARDINS Card Inserted
 *  +      SDHC_PSR_CARDINS_NO Reset or Debouncing or No Card
 *  +      SDHC_PSR_CARDINS_YES Card inserted
 * - SDHC_PSR_CARDSS Card State Stable
 *  +      SDHC_PSR_CARDSS_NO Reset or Debouncing
 *  +      SDHC_PSR_CARDSS_YES No Card or Insered
 * - SDHC_PSR_CARDDPL Card Detect Pin Level
 *  +      SDHC_PSR_CARDDPL_NO No card present (SDCD#=1)
 *  +      SDHC_PSR_CARDDPL_YES Card present (SDCD#=0)
 * - SDHC_PSR_WRPPL Write Protect Pin Level
 *  +      SDHC_PSR_WRPPL_PROTECTED Write protected (SDWP#=0)
 *  +      SDHC_PSR_WRPPL_ENABLED Write enabled (SDWP#=1)
 * - SDHC_PSR_DATLL(value) DAT[3:0] Line Level
 * - SDHC_PSR_CMDLL CMD Line Level
 **/
static inline uint32_t sdhc_read_PSR(SDHC_t *pSDHC)
{
	return pSDHC->PSR.reg;
}

/**
 * @brief sdhc get ACESR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_ACESR_ACMD12NE Auto CMD12 Not Executed
 *  +      SDHC_ACESR_ACMD12NE_EXEC Executed
 *  +      SDHC_ACESR_ACMD12NE_NOT_EXEC Not executed
 * - SDHC_ACESR_ACMDTEO Auto CMD Timeout Error
 *  +      SDHC_ACESR_ACMDTEO_NO No error
 *  +      SDHC_ACESR_ACMDTEO_YES Timeout
 * - SDHC_ACESR_ACMDCRC Auto CMD CRC Error
 *  +      SDHC_ACESR_ACMDCRC_NO No error
 *  +      SDHC_ACESR_ACMDCRC_YES CRC Error Generated
 * - SDHC_ACESR_ACMDEND Auto CMD End Bit Error
 *  +      SDHC_ACESR_ACMDEND_NO No error
 *  +      SDHC_ACESR_ACMDEND_YES End Bit Error Generated
 * - SDHC_ACESR_ACMDIDX Auto CMD Index Error
 *  +      SDHC_ACESR_ACMDIDX_NO No error
 *  +      SDHC_ACESR_ACMDIDX_YES Error
 * - SDHC_ACESR_CMDNI Command not Issued By Auto CMD12 Error
 *  +      SDHC_ACESR_CMDNI_OK No error
 *  +      SDHC_ACESR_CMDNI_NOT_ISSUED Not Issued
 **/
static inline uint16_t sdhc_get_ACESR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->ACESR.reg & mask);
}

/**
 * @brief sdhc read ACESR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_ACESR_ACMD12NE Auto CMD12 Not Executed
 *  +      SDHC_ACESR_ACMD12NE_EXEC Executed
 *  +      SDHC_ACESR_ACMD12NE_NOT_EXEC Not executed
 * - SDHC_ACESR_ACMDTEO Auto CMD Timeout Error
 *  +      SDHC_ACESR_ACMDTEO_NO No error
 *  +      SDHC_ACESR_ACMDTEO_YES Timeout
 * - SDHC_ACESR_ACMDCRC Auto CMD CRC Error
 *  +      SDHC_ACESR_ACMDCRC_NO No error
 *  +      SDHC_ACESR_ACMDCRC_YES CRC Error Generated
 * - SDHC_ACESR_ACMDEND Auto CMD End Bit Error
 *  +      SDHC_ACESR_ACMDEND_NO No error
 *  +      SDHC_ACESR_ACMDEND_YES End Bit Error Generated
 * - SDHC_ACESR_ACMDIDX Auto CMD Index Error
 *  +      SDHC_ACESR_ACMDIDX_NO No error
 *  +      SDHC_ACESR_ACMDIDX_YES Error
 * - SDHC_ACESR_CMDNI Command not Issued By Auto CMD12 Error
 *  +      SDHC_ACESR_CMDNI_OK No error
 *  +      SDHC_ACESR_CMDNI_NOT_ISSUED Not Issued
 **/
static inline uint16_t sdhc_read_ACESR(SDHC_t *pSDHC)
{
	return pSDHC->ACESR.reg;
}

/**
 * @brief sdhc get CA0R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_CA0R_TEOCLKF(value) Timeout Clock Frequency
 *  +      SDHC_CA0R_TEOCLKF_OTHER Get information via another method
 * - SDHC_CA0R_TEOCLKU Timeout Clock Unit
 *  +      SDHC_CA0R_TEOCLKU_KHZ kHz
 *  +      SDHC_CA0R_TEOCLKU_MHZ MHz
 * - SDHC_CA0R_BASECLKF(value) Base Clock Frequency
 *  +      SDHC_CA0R_BASECLKF_OTHER Get information via another method
 * - SDHC_CA0R_MAXBLKL(value) Max Block Length
 *  +      SDHC_CA0R_MAXBLKL_512 512 bytes
 *  +      SDHC_CA0R_MAXBLKL_1024 1024 bytes
 *  +      SDHC_CA0R_MAXBLKL_2048 2048 bytes
 * - SDHC_CA0R_ED8SUP 8-bit Support for Embedded Device
 *  +      SDHC_CA0R_ED8SUP_NO 8-bit Bus Width not Supported
 *  +      SDHC_CA0R_ED8SUP_YES 8-bit Bus Width Supported
 * - SDHC_CA0R_ADMA2SUP ADMA2 Support
 *  +      SDHC_CA0R_ADMA2SUP_NO ADMA2 not Supported
 *  +      SDHC_CA0R_ADMA2SUP_YES ADMA2 Supported
 * - SDHC_CA0R_HSSUP High Speed Support
 *  +      SDHC_CA0R_HSSUP_NO High Speed not Supported
 *  +      SDHC_CA0R_HSSUP_YES High Speed Supported
 * - SDHC_CA0R_SDMASUP SDMA Support
 *  +      SDHC_CA0R_SDMASUP_NO SDMA not Supported
 *  +      SDHC_CA0R_SDMASUP_YES SDMA Supported
 * - SDHC_CA0R_SRSUP Suspend/Resume Support
 *  +      SDHC_CA0R_SRSUP_NO Suspend/Resume not Supported
 *  +      SDHC_CA0R_SRSUP_YES Suspend/Resume Supported
 * - SDHC_CA0R_V33VSUP Voltage Support 3.3V
 *  +      SDHC_CA0R_V33VSUP_NO 3.3V Not Supported
 *  +      SDHC_CA0R_V33VSUP_YES 3.3V Supported
 * - SDHC_CA0R_V30VSUP Voltage Support 3.0V
 *  +      SDHC_CA0R_V30VSUP_NO 3.0V Not Supported
 *  +      SDHC_CA0R_V30VSUP_YES 3.0V Supported
 * - SDHC_CA0R_V18VSUP Voltage Support 1.8V
 *  +      SDHC_CA0R_V18VSUP_NO 1.8V Not Supported
 *  +      SDHC_CA0R_V18VSUP_YES 1.8V Supported
 * - SDHC_CA0R_SB64SUP 64-Bit System Bus Support
 *  +      SDHC_CA0R_SB64SUP_NO 32-bit Address Descriptors and System Bus
 *  +      SDHC_CA0R_SB64SUP_YES 64-bit Address Descriptors and System Bus
 * - SDHC_CA0R_ASINTSUP Asynchronous Interrupt Support
 *  +      SDHC_CA0R_ASINTSUP_NO Asynchronous Interrupt not Supported
 *  +      SDHC_CA0R_ASINTSUP_YES Asynchronous Interrupt supported
 * - SDHC_CA0R_SLTYPE(value) Slot Type
 *  +      SDHC_CA0R_SLTYPE_REMOVABLE Removable Card Slot
 *  +      SDHC_CA0R_SLTYPE_EMBEDDED Embedded Slot for One Device
 **/
static inline uint32_t sdhc_get_CA0R(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->CA0R.reg & mask);
}

/**
 * @brief sdhc read CA0R register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_CA0R_TEOCLKF(value) Timeout Clock Frequency
 *  +      SDHC_CA0R_TEOCLKF_OTHER Get information via another method
 * - SDHC_CA0R_TEOCLKU Timeout Clock Unit
 *  +      SDHC_CA0R_TEOCLKU_KHZ kHz
 *  +      SDHC_CA0R_TEOCLKU_MHZ MHz
 * - SDHC_CA0R_BASECLKF(value) Base Clock Frequency
 *  +      SDHC_CA0R_BASECLKF_OTHER Get information via another method
 * - SDHC_CA0R_MAXBLKL(value) Max Block Length
 *  +      SDHC_CA0R_MAXBLKL_512 512 bytes
 *  +      SDHC_CA0R_MAXBLKL_1024 1024 bytes
 *  +      SDHC_CA0R_MAXBLKL_2048 2048 bytes
 * - SDHC_CA0R_ED8SUP 8-bit Support for Embedded Device
 *  +      SDHC_CA0R_ED8SUP_NO 8-bit Bus Width not Supported
 *  +      SDHC_CA0R_ED8SUP_YES 8-bit Bus Width Supported
 * - SDHC_CA0R_ADMA2SUP ADMA2 Support
 *  +      SDHC_CA0R_ADMA2SUP_NO ADMA2 not Supported
 *  +      SDHC_CA0R_ADMA2SUP_YES ADMA2 Supported
 * - SDHC_CA0R_HSSUP High Speed Support
 *  +      SDHC_CA0R_HSSUP_NO High Speed not Supported
 *  +      SDHC_CA0R_HSSUP_YES High Speed Supported
 * - SDHC_CA0R_SDMASUP SDMA Support
 *  +      SDHC_CA0R_SDMASUP_NO SDMA not Supported
 *  +      SDHC_CA0R_SDMASUP_YES SDMA Supported
 * - SDHC_CA0R_SRSUP Suspend/Resume Support
 *  +      SDHC_CA0R_SRSUP_NO Suspend/Resume not Supported
 *  +      SDHC_CA0R_SRSUP_YES Suspend/Resume Supported
 * - SDHC_CA0R_V33VSUP Voltage Support 3.3V
 *  +      SDHC_CA0R_V33VSUP_NO 3.3V Not Supported
 *  +      SDHC_CA0R_V33VSUP_YES 3.3V Supported
 * - SDHC_CA0R_V30VSUP Voltage Support 3.0V
 *  +      SDHC_CA0R_V30VSUP_NO 3.0V Not Supported
 *  +      SDHC_CA0R_V30VSUP_YES 3.0V Supported
 * - SDHC_CA0R_V18VSUP Voltage Support 1.8V
 *  +      SDHC_CA0R_V18VSUP_NO 1.8V Not Supported
 *  +      SDHC_CA0R_V18VSUP_YES 1.8V Supported
 * - SDHC_CA0R_SB64SUP 64-Bit System Bus Support
 *  +      SDHC_CA0R_SB64SUP_NO 32-bit Address Descriptors and System Bus
 *  +      SDHC_CA0R_SB64SUP_YES 64-bit Address Descriptors and System Bus
 * - SDHC_CA0R_ASINTSUP Asynchronous Interrupt Support
 *  +      SDHC_CA0R_ASINTSUP_NO Asynchronous Interrupt not Supported
 *  +      SDHC_CA0R_ASINTSUP_YES Asynchronous Interrupt supported
 * - SDHC_CA0R_SLTYPE(value) Slot Type
 *  +      SDHC_CA0R_SLTYPE_REMOVABLE Removable Card Slot
 *  +      SDHC_CA0R_SLTYPE_EMBEDDED Embedded Slot for One Device
 **/
static inline uint32_t sdhc_read_CA0R(SDHC_t *pSDHC)
{
	return pSDHC->CA0R.reg;
}

/**
 * @brief sdhc get CA1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_CA1R_SDR50SUP SDR50 Support
 *  +      SDHC_CA1R_SDR50SUP_NO SDR50 is Not Supported
 *  +      SDHC_CA1R_SDR50SUP_YES SDR50 is Supported
 * - SDHC_CA1R_SDR104SUP SDR104 Support
 *  +      SDHC_CA1R_SDR104SUP_NO SDR104 is Not Supported
 *  +      SDHC_CA1R_SDR104SUP_YES SDR104 is Supported
 * - SDHC_CA1R_DDR50SUP DDR50 Support
 *  +      SDHC_CA1R_DDR50SUP_NO DDR50 is Not Supported
 *  +      SDHC_CA1R_DDR50SUP_YES DDR50 is Supported
 * - SDHC_CA1R_DRVASUP Driver Type A Support
 *  +      SDHC_CA1R_DRVASUP_NO Driver Type A is Not Supported
 *  +      SDHC_CA1R_DRVASUP_YES Driver Type A is Supported
 * - SDHC_CA1R_DRVCSUP Driver Type C Support
 *  +      SDHC_CA1R_DRVCSUP_NO Driver Type C is Not Supported
 *  +      SDHC_CA1R_DRVCSUP_YES Driver Type C is Supported
 * - SDHC_CA1R_DRVDSUP Driver Type D Support
 *  +      SDHC_CA1R_DRVDSUP_NO Driver Type D is Not Supported
 *  +      SDHC_CA1R_DRVDSUP_YES Driver Type D is Supported
 * - SDHC_CA1R_TCNTRT(value) Timer Count for Re-Tuning
 *  +      SDHC_CA1R_TCNTRT_DISABLED Re-Tuning Timer disabled
 *  +      SDHC_CA1R_TCNTRT_1S 1 second
 *  +      SDHC_CA1R_TCNTRT_2S 2 seconds
 *  +      SDHC_CA1R_TCNTRT_4S 4 seconds
 *  +      SDHC_CA1R_TCNTRT_8S 8 seconds
 *  +      SDHC_CA1R_TCNTRT_16S 16 seconds
 *  +      SDHC_CA1R_TCNTRT_32S 32 seconds
 *  +      SDHC_CA1R_TCNTRT_64S 64 seconds
 *  +      SDHC_CA1R_TCNTRT_128S 128 seconds
 *  +      SDHC_CA1R_TCNTRT_256S 256 seconds
 *  +      SDHC_CA1R_TCNTRT_512S 512 seconds
 *  +      SDHC_CA1R_TCNTRT_1024S 1024 seconds
 *  +      SDHC_CA1R_TCNTRT_OTHER Get information from other source
 * - SDHC_CA1R_TSDR50 Use Tuning for SDR50
 *  +      SDHC_CA1R_TSDR50_NO SDR50 does not require tuning
 *  +      SDHC_CA1R_TSDR50_YES SDR50 requires tuning
 * - SDHC_CA1R_CLKMULT(value) Clock Multiplier
 *  +      SDHC_CA1R_CLKMULT_NO Clock Multiplier is Not Supported
 **/
static inline uint32_t sdhc_get_CA1R(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->CA1R.reg & mask);
}

/**
 * @brief sdhc read CA1R register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_CA1R_SDR50SUP SDR50 Support
 *  +      SDHC_CA1R_SDR50SUP_NO SDR50 is Not Supported
 *  +      SDHC_CA1R_SDR50SUP_YES SDR50 is Supported
 * - SDHC_CA1R_SDR104SUP SDR104 Support
 *  +      SDHC_CA1R_SDR104SUP_NO SDR104 is Not Supported
 *  +      SDHC_CA1R_SDR104SUP_YES SDR104 is Supported
 * - SDHC_CA1R_DDR50SUP DDR50 Support
 *  +      SDHC_CA1R_DDR50SUP_NO DDR50 is Not Supported
 *  +      SDHC_CA1R_DDR50SUP_YES DDR50 is Supported
 * - SDHC_CA1R_DRVASUP Driver Type A Support
 *  +      SDHC_CA1R_DRVASUP_NO Driver Type A is Not Supported
 *  +      SDHC_CA1R_DRVASUP_YES Driver Type A is Supported
 * - SDHC_CA1R_DRVCSUP Driver Type C Support
 *  +      SDHC_CA1R_DRVCSUP_NO Driver Type C is Not Supported
 *  +      SDHC_CA1R_DRVCSUP_YES Driver Type C is Supported
 * - SDHC_CA1R_DRVDSUP Driver Type D Support
 *  +      SDHC_CA1R_DRVDSUP_NO Driver Type D is Not Supported
 *  +      SDHC_CA1R_DRVDSUP_YES Driver Type D is Supported
 * - SDHC_CA1R_TCNTRT(value) Timer Count for Re-Tuning
 *  +      SDHC_CA1R_TCNTRT_DISABLED Re-Tuning Timer disabled
 *  +      SDHC_CA1R_TCNTRT_1S 1 second
 *  +      SDHC_CA1R_TCNTRT_2S 2 seconds
 *  +      SDHC_CA1R_TCNTRT_4S 4 seconds
 *  +      SDHC_CA1R_TCNTRT_8S 8 seconds
 *  +      SDHC_CA1R_TCNTRT_16S 16 seconds
 *  +      SDHC_CA1R_TCNTRT_32S 32 seconds
 *  +      SDHC_CA1R_TCNTRT_64S 64 seconds
 *  +      SDHC_CA1R_TCNTRT_128S 128 seconds
 *  +      SDHC_CA1R_TCNTRT_256S 256 seconds
 *  +      SDHC_CA1R_TCNTRT_512S 512 seconds
 *  +      SDHC_CA1R_TCNTRT_1024S 1024 seconds
 *  +      SDHC_CA1R_TCNTRT_OTHER Get information from other source
 * - SDHC_CA1R_TSDR50 Use Tuning for SDR50
 *  +      SDHC_CA1R_TSDR50_NO SDR50 does not require tuning
 *  +      SDHC_CA1R_TSDR50_YES SDR50 requires tuning
 * - SDHC_CA1R_CLKMULT(value) Clock Multiplier
 *  +      SDHC_CA1R_CLKMULT_NO Clock Multiplier is Not Supported
 **/
static inline uint32_t sdhc_read_CA1R(SDHC_t *pSDHC)
{
	return pSDHC->CA1R.reg;
}

/**
 * @brief sdhc get MCCAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - SDHC_MCCAR_MAXCUR33V(value) Maximum Current for 3.3V
 *  +      SDHC_MCCAR_MAXCUR33V_OTHER Get information via another method
 *  +      SDHC_MCCAR_MAXCUR33V_4MA 4mA
 *  +      SDHC_MCCAR_MAXCUR33V_8MA 8mA
 *  +      SDHC_MCCAR_MAXCUR33V_12MA 12mA
 * - SDHC_MCCAR_MAXCUR30V(value) Maximum Current for 3.0V
 *  +      SDHC_MCCAR_MAXCUR30V_OTHER Get information via another method
 *  +      SDHC_MCCAR_MAXCUR30V_4MA 4mA
 *  +      SDHC_MCCAR_MAXCUR30V_8MA 8mA
 *  +      SDHC_MCCAR_MAXCUR30V_12MA 12mA
 * - SDHC_MCCAR_MAXCUR18V(value) Maximum Current for 1.8V
 *  +      SDHC_MCCAR_MAXCUR18V_OTHER Get information via another method
 *  +      SDHC_MCCAR_MAXCUR18V_4MA 4mA
 *  +      SDHC_MCCAR_MAXCUR18V_8MA 8mA
 *  +      SDHC_MCCAR_MAXCUR18V_12MA 12mA
 **/
static inline uint32_t sdhc_get_MCCAR(SDHC_t *pSDHC, uint32_t mask)
{
    return (pSDHC->MCCAR.reg & mask);
}

/**
 * @brief sdhc read MCCAR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint32_t
 * - SDHC_MCCAR_MAXCUR33V(value) Maximum Current for 3.3V
 *  +      SDHC_MCCAR_MAXCUR33V_OTHER Get information via another method
 *  +      SDHC_MCCAR_MAXCUR33V_4MA 4mA
 *  +      SDHC_MCCAR_MAXCUR33V_8MA 8mA
 *  +      SDHC_MCCAR_MAXCUR33V_12MA 12mA
 * - SDHC_MCCAR_MAXCUR30V(value) Maximum Current for 3.0V
 *  +      SDHC_MCCAR_MAXCUR30V_OTHER Get information via another method
 *  +      SDHC_MCCAR_MAXCUR30V_4MA 4mA
 *  +      SDHC_MCCAR_MAXCUR30V_8MA 8mA
 *  +      SDHC_MCCAR_MAXCUR30V_12MA 12mA
 * - SDHC_MCCAR_MAXCUR18V(value) Maximum Current for 1.8V
 *  +      SDHC_MCCAR_MAXCUR18V_OTHER Get information via another method
 *  +      SDHC_MCCAR_MAXCUR18V_4MA 4mA
 *  +      SDHC_MCCAR_MAXCUR18V_8MA 8mA
 *  +      SDHC_MCCAR_MAXCUR18V_12MA 12mA
 **/
static inline uint32_t sdhc_read_MCCAR(SDHC_t *pSDHC)
{
	return pSDHC->MCCAR.reg;
}

/**
 * @brief sdhc get AESR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - SDHC_AESR_ERRST(value) ADMA Error State
 *  +      SDHC_AESR_ERRST_STOP ST_STOP (Stop DMA)
 *  +      SDHC_AESR_ERRST_FDS ST_FDS (Fetch Descriptor)
 *  +      SDHC_AESR_ERRST_2 Reserved
 *  +      SDHC_AESR_ERRST_TFR ST_TFR (Transfer Data)
 * - SDHC_AESR_LMIS ADMA Length Mismatch Error
 *  +      SDHC_AESR_LMIS_NO No Error
 *  +      SDHC_AESR_LMIS_YES Error
 **/
static inline uint8_t sdhc_get_AESR(SDHC_t *pSDHC, uint8_t mask)
{
    return (pSDHC->AESR.reg & mask);
}

/**
 * @brief sdhc read AESR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint8_t
 * - SDHC_AESR_ERRST(value) ADMA Error State
 *  +      SDHC_AESR_ERRST_STOP ST_STOP (Stop DMA)
 *  +      SDHC_AESR_ERRST_FDS ST_FDS (Fetch Descriptor)
 *  +      SDHC_AESR_ERRST_2 Reserved
 *  +      SDHC_AESR_ERRST_TFR ST_TFR (Transfer Data)
 * - SDHC_AESR_LMIS ADMA Length Mismatch Error
 *  +      SDHC_AESR_LMIS_NO No Error
 *  +      SDHC_AESR_LMIS_YES Error
 **/
static inline uint8_t sdhc_read_AESR(SDHC_t *pSDHC)
{
	return pSDHC->AESR.reg;
}

/**
 * @brief sdhc get SISR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_SISR_INTSSL(value) Interrupt Signal for Each Slot
 **/
static inline uint16_t sdhc_get_SISR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->SISR.reg & mask);
}

/**
 * @brief sdhc read SISR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_SISR_INTSSL(value) Interrupt Signal for Each Slot
 **/
static inline uint16_t sdhc_read_SISR(SDHC_t *pSDHC)
{
	return pSDHC->SISR.reg;
}

/**
 * @brief sdhc get HCVR register
 *
 * @param[in] pSDHC SDHC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - SDHC_HCVR_SVER(value) Spec Version
 * - SDHC_HCVR_VVER(value) Vendor Version
 **/
static inline uint16_t sdhc_get_HCVR(SDHC_t *pSDHC, uint16_t mask)
{
    return (pSDHC->HCVR.reg & mask);
}

/**
 * @brief sdhc read HCVR register
 *
 * @param[in] pSDHC SDHC_t *
 * @return uint16_t
 * - SDHC_HCVR_SVER(value) Spec Version
 * - SDHC_HCVR_VVER(value) Vendor Version
 **/
static inline uint16_t sdhc_read_HCVR(SDHC_t *pSDHC)
{
	return pSDHC->HCVR.reg;
}

#endif /* _SDHC_H */
