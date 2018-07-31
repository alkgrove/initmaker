/**
 * @note This file is modified from the Atmel ASF4 hri include
 * by Alkgrove 2018
 * @version beta
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
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * SDHC_SSAR_CMD23_ARG2(value)  Argument 2 
 * SDHC_SSAR_ADDR(value)  SDMA System Address 
 */
static inline void sdhc_set_SSAR(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->SSAR.reg |= mask;
}

/**
 * @brief sdhc get SSAR register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 * SDHC_SSAR_CMD23_ARG2(value)  Argument 2 
 * SDHC_SSAR_ADDR(value)  SDMA System Address 
 */
static inline uint32_t sdhc_get_SSAR(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->SSAR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t data
 */
static inline void sdhc_write_SSAR(SDHC_t *SDHC, uint32_t data)
{
	SDHC->SSAR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_clear_SSAR(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->SSAR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 */
static inline uint32_t sdhc_read_SSAR(SDHC_t *SDHC)
{
	return SDHC->SSAR.reg;
}

/*
 * @brief set host control 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * SDHC_HC1R_LEDCTRL	LED Control 
 * SDHC_HC1R_DW	Data Width 
 *  SDHC_HC1R_DW_1BIT
 *  SDHC_HC1R_DW_4BIT
 * SDHC_HC1R_HSEN	    High Speed Enable 
 *  SDHC_HC1R_HSEN_NORMAL 
 *  SDHC_HC1R_HSEN_HIGH   
 * SDHC_HC1R_DMASEL	    DMA Select 
 *  SDHC_HC1R_DMASEL_SDMA 
 *  SDHC_HC1R_DMASEL_1    
 *  SDHC_HC1R_DMASEL_32BIT
 * SDHC_HC1R_CARDDTL	Card Detect Test Level 
 * SDHC_HC1R_CARDDSEL	Card Detect Signal Selection 
 * EMMC Mode only
 * SDHC_HC1R_EMMC_DW	Data Width 
 * SDHC_HC1R_EMMC_HSEN	High Speed Enable 
 * SDHC_HC1R_EMMC_DMASEL	DMA Select 

 
 */
static inline void sdhc_set_HC1R(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->HC1R.reg |= mask;
}

/*
 * @brief get host control 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 * SDHC_HC1R_LEDCTRL	LED Control 
 * SDHC_HC1R_DW	Data Width 
 *  SDHC_HC1R_DW_1BIT
 *  SDHC_HC1R_DW_4BIT
 * SDHC_HC1R_HSEN	    High Speed Enable 
 *  SDHC_HC1R_HSEN_NORMAL 
 *  SDHC_HC1R_HSEN_HIGH   
 * SDHC_HC1R_DMASEL	    DMA Select 
 *  SDHC_HC1R_DMASEL_SDMA 
 *  SDHC_HC1R_DMASEL_1    
 *  SDHC_HC1R_DMASEL_32BIT
 * SDHC_HC1R_CARDDTL	Card Detect Test Level 
 * SDHC_HC1R_CARDDSEL	Card Detect Signal Selection 
 * EMMC Mode only
 * SDHC_HC1R_EMMC_DW	Data Width 
 * SDHC_HC1R_EMMC_HSEN	High Speed Enable 
 * SDHC_HC1R_EMMC_DMASEL	DMA Select 
 */
static inline uint8_t sdhc_get_HC1R(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->HC1R.reg & mask);
}

/*
 * @brief write host control 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data
 * SDHC_HC1R_LEDCTRL	LED Control 
 * SDHC_HC1R_DW	Data Width 
 *  SDHC_HC1R_DW_1BIT
 *  SDHC_HC1R_DW_4BIT
 * SDHC_HC1R_HSEN	    High Speed Enable 
 *  SDHC_HC1R_HSEN_NORMAL 
 *  SDHC_HC1R_HSEN_HIGH   
 * SDHC_HC1R_DMASEL	    DMA Select 
 *  SDHC_HC1R_DMASEL_SDMA 
 *  SDHC_HC1R_DMASEL_1    
 *  SDHC_HC1R_DMASEL_32BIT
 * SDHC_HC1R_CARDDTL	Card Detect Test Level 
 * SDHC_HC1R_CARDDSEL	Card Detect Signal Selection 
 * EMMC Mode only
 * SDHC_HC1R_EMMC_DW	Data Width 
 * SDHC_HC1R_EMMC_HSEN	High Speed Enable 
 * SDHC_HC1R_EMMC_DMASEL	DMA Select 
 */
static inline void sdhc_write_HC1R(SDHC_t *SDHC, uint8_t data)
{
	SDHC->HC1R.reg = data;
}

/*
 * @brief clear host control 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * SDHC_HC1R_LEDCTRL	LED Control 
 * SDHC_HC1R_DW	Data Width 
 *  SDHC_HC1R_DW_1BIT
 *  SDHC_HC1R_DW_4BIT
 * SDHC_HC1R_HSEN	    High Speed Enable 
 *  SDHC_HC1R_HSEN_NORMAL 
 *  SDHC_HC1R_HSEN_HIGH   
 * SDHC_HC1R_DMASEL	    DMA Select 
 *  SDHC_HC1R_DMASEL_SDMA 
 *  SDHC_HC1R_DMASEL_1    
 *  SDHC_HC1R_DMASEL_32BIT
 * SDHC_HC1R_CARDDTL	Card Detect Test Level 
 * SDHC_HC1R_CARDDSEL	Card Detect Signal Selection 
 * EMMC Mode only
 * SDHC_HC1R_EMMC_DW	Data Width 
 * SDHC_HC1R_EMMC_HSEN	High Speed Enable 
 * SDHC_HC1R_EMMC_DMASEL	DMA Select 
 */
static inline void sdhc_clear_HC1R(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->HC1R.reg &= ~mask;
}

/*
 * @brief read host control 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t
 * SDHC_HC1R_LEDCTRL	LED Control 
 * SDHC_HC1R_DW	Data Width 
 *  SDHC_HC1R_DW_1BIT
 *  SDHC_HC1R_DW_4BIT
 * SDHC_HC1R_HSEN	    High Speed Enable 
 *  SDHC_HC1R_HSEN_NORMAL 
 *  SDHC_HC1R_HSEN_HIGH   
 * SDHC_HC1R_DMASEL	    DMA Select 
 *  SDHC_HC1R_DMASEL_SDMA 
 *  SDHC_HC1R_DMASEL_1    
 *  SDHC_HC1R_DMASEL_32BIT
 * SDHC_HC1R_CARDDTL	Card Detect Test Level 
 * SDHC_HC1R_CARDDSEL	Card Detect Signal Selection 
 * EMMC Mode only
 * SDHC_HC1R_EMMC_DW	Data Width 
 * SDHC_HC1R_EMMC_HSEN	High Speed Enable 
 * SDHC_HC1R_EMMC_DMASEL	DMA Select 
 */
static inline uint8_t sdhc_read_HC1R(SDHC_t *SDHC)
{
	return SDHC->HC1R.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_set_BGCR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->BGCR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 */
static inline uint8_t sdhc_get_BGCR(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->BGCR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data
 */
static inline void sdhc_write_BGCR(SDHC_t *SDHC, uint8_t data)
{
	SDHC->BGCR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_clear_BGCR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->BGCR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t
 */
static inline uint8_t sdhc_read_BGCR(SDHC_t *SDHC)
{
	return SDHC->BGCR.reg;
}

/*
 * @brief set normal interrupt status register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_NISTR_CMDC	Command Complete 
 * SDHC_NISTR_TRFC	Transfer Complete 
 * SDHC_NISTR_BLKGE	Block Gap Event 
 * SDHC_NISTR_DMAINT	DMA Interrupt 
 * SDHC_NISTR_BWRRDY	Buffer Write Ready 
 * SDHC_NISTR_BRDRDY	Buffer Read Ready 
 * SDHC_NISTR_CINS	Card Insertion 
 * SDHC_NISTR_CREM	Card Removal 
 * SDHC_NISTR_CINT	Card Interrupt 
 * SDHC_NISTR_ERRINT	Error Interrupt 
 */
static inline void sdhc_set_NISTR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->NISTR.reg |= mask;
}

/*
 * @brief get normal interupt status register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 * SDHC_NISTR_CMDC	Command Complete 
 * SDHC_NISTR_TRFC	Transfer Complete 
 * SDHC_NISTR_BLKGE	Block Gap Event 
 * SDHC_NISTR_DMAINT	DMA Interrupt 
 * SDHC_NISTR_BWRRDY	Buffer Write Ready 
 * SDHC_NISTR_BRDRDY	Buffer Read Ready 
 * SDHC_NISTR_CINS	Card Insertion 
 * SDHC_NISTR_CREM	Card Removal 
 * SDHC_NISTR_CINT	Card Interrupt 
 * SDHC_NISTR_ERRINT	Error Interrupt 
 */
static inline uint16_t sdhc_get_NISTR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->NISTR.reg & mask);
}

/*
 * @brief write normal interrupt status register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 * SDHC_NISTR_CMDC	Command Complete 
 * SDHC_NISTR_TRFC	Transfer Complete 
 * SDHC_NISTR_BLKGE	Block Gap Event 
 * SDHC_NISTR_DMAINT	DMA Interrupt 
 * SDHC_NISTR_BWRRDY	Buffer Write Ready 
 * SDHC_NISTR_BRDRDY	Buffer Read Ready 
 * SDHC_NISTR_CINS	Card Insertion 
 * SDHC_NISTR_CREM	Card Removal 
 * SDHC_NISTR_CINT	Card Interrupt 
 * SDHC_NISTR_ERRINT	Error Interrupt 
 */
static inline void sdhc_write_NISTR(SDHC_t *SDHC, uint16_t data)
{
	SDHC->NISTR.reg = data;
}


/*
 * @brief read normal interrupt status register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 * SDHC_NISTR_CMDC	Command Complete 
 * SDHC_NISTR_TRFC	Transfer Complete 
 * SDHC_NISTR_BLKGE	Block Gap Event 
 * SDHC_NISTR_DMAINT	DMA Interrupt 
 * SDHC_NISTR_BWRRDY	Buffer Write Ready 
 * SDHC_NISTR_BRDRDY	Buffer Read Ready 
 * SDHC_NISTR_CINS	Card Insertion 
 * SDHC_NISTR_CREM	Card Removal 
 * SDHC_NISTR_CINT	Card Interrupt 
 * SDHC_NISTR_ERRINT	Error Interrupt 
 */
static inline uint16_t sdhc_read_NISTR(SDHC_t *SDHC)
{
	return SDHC->NISTR.reg;
}

/*
 * @brief set error interrupt status register masked
 * setting a bit clears the register
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_EISTR_CMDTEO	Command Timeout Error 
 * SDHC_EISTR_CMDCRC	Command CRC Error 
 * SDHC_EISTR_CMDEND	Command End Bit Error 
 * SDHC_EISTR_CMDIDX	Command Index Error 
 * SDHC_EISTR_DATTEO	Data Timeout Error 
 * SDHC_EISTR_DATCRC	Data CRC Error 
 * SDHC_EISTR_DATEND	Data End Bit Error 
 * SDHC_EISTR_CURLIM	Current Limit Error 
 * SDHC_EISTR_ACMD	Auto CMD Error 
 * SDHC_EISTR_ADMA	ADMA Error 
 */
static inline void sdhc_set_EISTR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->EISTR.reg |= mask;
}

/*
 * @brief get error interrupt status register masked
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 * SDHC_EISTR_CMDTEO	Command Timeout Error 
 * SDHC_EISTR_CMDCRC	Command CRC Error 
 * SDHC_EISTR_CMDEND	Command End Bit Error 
 * SDHC_EISTR_CMDIDX	Command Index Error 
 * SDHC_EISTR_DATTEO	Data Timeout Error 
 * SDHC_EISTR_DATCRC	Data CRC Error 
 * SDHC_EISTR_DATEND	Data End Bit Error 
 * SDHC_EISTR_CURLIM	Current Limit Error 
 * SDHC_EISTR_ACMD	Auto CMD Error 
 * SDHC_EISTR_ADMA	ADMA Error 
 */
static inline uint16_t sdhc_get_EISTR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->EISTR.reg & mask);
}

/*
 * @brief write error status register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 * SDHC_EISTR_CMDTEO	Command Timeout Error 
 * SDHC_EISTR_CMDCRC	Command CRC Error 
 * SDHC_EISTR_CMDEND	Command End Bit Error 
 * SDHC_EISTR_CMDIDX	Command Index Error 
 * SDHC_EISTR_DATTEO	Data Timeout Error 
 * SDHC_EISTR_DATCRC	Data CRC Error 
 * SDHC_EISTR_DATEND	Data End Bit Error 
 * SDHC_EISTR_CURLIM	Current Limit Error 
 * SDHC_EISTR_ACMD	Auto CMD Error 
 * SDHC_EISTR_ADMA	ADMA Error 
 */
static inline void sdhc_write_EISTR(SDHC_t *SDHC, uint16_t data)
{
	SDHC->EISTR.reg = data;
}


/*
 * @brief read error interrupt status register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 * SDHC_EISTR_CMDTEO	Command Timeout Error 
 * SDHC_EISTR_CMDCRC	Command CRC Error 
 * SDHC_EISTR_CMDEND	Command End Bit Error 
 * SDHC_EISTR_CMDIDX	Command Index Error 
 * SDHC_EISTR_DATTEO	Data Timeout Error 
 * SDHC_EISTR_DATCRC	Data CRC Error 
 * SDHC_EISTR_DATEND	Data End Bit Error 
 * SDHC_EISTR_CURLIM	Current Limit Error 
 * SDHC_EISTR_ACMD	Auto CMD Error 
 * SDHC_EISTR_ADMA	ADMA Error 
 */
static inline uint16_t sdhc_read_EISTR(SDHC_t *SDHC)
{
	return SDHC->EISTR.reg;
}

/*
 * @brief set Normal Interrupt Status Register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_NISTER_CMDC	Command Complete Status Enable 
 * SDHC_NISTER_TRFC	Transfer Complete Status Enable 
 * SDHC_NISTER_BLKGE	Block Gap Event Status Enable 
 * SDHC_NISTER_DMAINT	DMA Interrupt Status Enable 
 * SDHC_NISTER_BWRRDY	Buffer Write Ready Status Enable 
 * SDHC_NISTER_BRDRDY	Buffer Read Ready Status Enable 
 * SDHC_NISTER_CINS	Card Insertion Status Enable 
 * SDHC_NISTER_CREM	Card Removal Status Enable 
 * SDHC_NISTER_CINT	Card Interrupt Status Enable 
 */
static inline void sdhc_set_NISTER(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->NISTER.reg |= mask;
}

/*
 * @brief get Normal Interrupt Status Register with mask
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 * SDHC_NISTER_CMDC	Command Complete Status Enable 
 * SDHC_NISTER_TRFC	Transfer Complete Status Enable 
 * SDHC_NISTER_BLKGE	Block Gap Event Status Enable 
 * SDHC_NISTER_DMAINT	DMA Interrupt Status Enable 
 * SDHC_NISTER_BWRRDY	Buffer Write Ready Status Enable 
 * SDHC_NISTER_BRDRDY	Buffer Read Ready Status Enable 
 * SDHC_NISTER_CINS	Card Insertion Status Enable 
 * SDHC_NISTER_CREM	Card Removal Status Enable 
 * SDHC_NISTER_CINT	Card Interrupt Status Enable 
 */
static inline uint16_t sdhc_get_NISTER(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->NISTER.reg & mask);
}

/*
 * @brief write Normal Interrupt Status Register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 * SDHC_NISTER_CMDC	Command Complete Status Enable 
 * SDHC_NISTER_TRFC	Transfer Complete Status Enable 
 * SDHC_NISTER_BLKGE	Block Gap Event Status Enable 
 * SDHC_NISTER_DMAINT	DMA Interrupt Status Enable 
 * SDHC_NISTER_BWRRDY	Buffer Write Ready Status Enable 
 * SDHC_NISTER_BRDRDY	Buffer Read Ready Status Enable 
 * SDHC_NISTER_CINS	Card Insertion Status Enable 
 * SDHC_NISTER_CREM	Card Removal Status Enable 
 * SDHC_NISTER_CINT	Card Interrupt Status Enable 
 */
static inline void sdhc_write_NISTER(SDHC_t *SDHC, uint16_t data)
{
	SDHC->NISTER.reg = data;
}

/*
 * @brief read normal interrupt status register eMMC
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 * SDHC_NISTER_CMDC	Command Complete Status Enable 
 * SDHC_NISTER_TRFC	Transfer Complete Status Enable 
 * SDHC_NISTER_BLKGE	Block Gap Event Status Enable 
 * SDHC_NISTER_DMAINT	DMA Interrupt Status Enable 
 * SDHC_NISTER_BWRRDY	Buffer Write Ready Status Enable 
 * SDHC_NISTER_BRDRDY	Buffer Read Ready Status Enable 
 * SDHC_NISTER_CINS	Card Insertion Status Enable 
 * SDHC_NISTER_CREM	Card Removal Status Enable 
 * SDHC_NISTER_CINT	Card Interrupt Status Enable 
 */
static inline uint16_t sdhc_read_NISTER(SDHC_t *SDHC)
{
	return SDHC->NISTER.reg;
}

/*
 * @brief set Error Interrupt Status Register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_EISIER_CMDTEO	Command Timeout Error Signal Enable 
 * SDHC_EISIER_CMDCRC	Command CRC Error Signal Enable 
 * SDHC_EISIER_CMDEND	Command End Bit Error Signal Enable 
 * SDHC_EISIER_CMDIDX	Command Index Error Signal Enable 
 * SDHC_EISIER_DATTEO	Data Timeout Error Signal Enable 
 * SDHC_EISIER_DATCRC	Data CRC Error Signal Enable 
 * SDHC_EISIER_DATEND	Data End Bit Error Signal Enable 
 * SDHC_EISIER_CURLIM	Current Limit Error Signal Enable 
 * SDHC_EISIER_ACMD	Auto CMD Error Signal Enable 
 * SDHC_EISIER_ADMA	ADMA Error Signal Enable 
 */
static inline void sdhc_set_EISTER(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->EISTER.reg |= mask;
}

/*
 * @brief get Error Interrupt register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 * SDHC_EISIER_CMDTEO	Command Timeout Error Signal Enable 
 * SDHC_EISIER_CMDCRC	Command CRC Error Signal Enable 
 * SDHC_EISIER_CMDEND	Command End Bit Error Signal Enable 
 * SDHC_EISIER_CMDIDX	Command Index Error Signal Enable 
 * SDHC_EISIER_DATTEO	Data Timeout Error Signal Enable 
 * SDHC_EISIER_DATCRC	Data CRC Error Signal Enable 
 * SDHC_EISIER_DATEND	Data End Bit Error Signal Enable 
 * SDHC_EISIER_CURLIM	Current Limit Error Signal Enable 
 * SDHC_EISIER_ACMD	Auto CMD Error Signal Enable 
 * SDHC_EISIER_ADMA	ADMA Error Signal Enable 
 */
static inline uint16_t sdhc_get_EISTER(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->EISTER.reg & mask);
}

/*
 * @brief write error interrupt status register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 * SDHC_EISIER_CMDTEO	Command Timeout Error Signal Enable 
 * SDHC_EISIER_CMDCRC	Command CRC Error Signal Enable 
 * SDHC_EISIER_CMDEND	Command End Bit Error Signal Enable 
 * SDHC_EISIER_CMDIDX	Command Index Error Signal Enable 
 * SDHC_EISIER_DATTEO	Data Timeout Error Signal Enable 
 * SDHC_EISIER_DATCRC	Data CRC Error Signal Enable 
 * SDHC_EISIER_DATEND	Data End Bit Error Signal Enable 
 * SDHC_EISIER_CURLIM	Current Limit Error Signal Enable 
 * SDHC_EISIER_ACMD	Auto CMD Error Signal Enable 
 * SDHC_EISIER_ADMA	ADMA Error Signal Enable 
 */
static inline void sdhc_write_EISTER(SDHC_t *SDHC, uint16_t data)
{
	SDHC->EISTER.reg = data;
}


/*
 * @brief read Error Interrupt Status Register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 * SDHC_EISIER_CMDTEO	Command Timeout Error Signal Enable 
 * SDHC_EISIER_CMDCRC	Command CRC Error Signal Enable 
 * SDHC_EISIER_CMDEND	Command End Bit Error Signal Enable 
 * SDHC_EISIER_CMDIDX	Command Index Error Signal Enable 
 * SDHC_EISIER_DATTEO	Data Timeout Error Signal Enable 
 * SDHC_EISIER_DATCRC	Data CRC Error Signal Enable 
 * SDHC_EISIER_DATEND	Data End Bit Error Signal Enable 
 * SDHC_EISIER_CURLIM	Current Limit Error Signal Enable 
 * SDHC_EISIER_ACMD	Auto CMD Error Signal Enable 
 * SDHC_EISIER_ADMA	ADMA Error Signal Enable 
 */
static inline uint16_t sdhc_read_EISTER(SDHC_t *SDHC)
{
	return SDHC->EISTER.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 */
static inline void sdhc_set_NISIER(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->NISIER.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 */
static inline uint16_t sdhc_get_NISIER(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->NISIER.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 */
static inline void sdhc_write_NISIER(SDHC_t *SDHC, uint16_t data)
{
	SDHC->NISIER.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 */
static inline void sdhc_clear_NISIER(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->NISIER.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 */
static inline uint16_t sdhc_read_NISIER(SDHC_t *SDHC)
{
	return SDHC->NISIER.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 */
static inline void sdhc_set_EISIER(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->EISIER.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 */
static inline uint16_t sdhc_get_EISIER(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->EISIER.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 */
static inline void sdhc_write_EISIER(SDHC_t *SDHC, uint16_t data)
{
	SDHC->EISIER.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 */
static inline void sdhc_clear_EISIER(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->EISIER.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 */
static inline uint16_t sdhc_read_EISIER(SDHC_t *SDHC)
{
	return SDHC->EISIER.reg;
}

/*
 * @brief set host control 2 register masked
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_HC2R_UHSMS	UHS Mode Select
 *  SDHC_HC2R_UHSMS_SDR12 
 *  SDHC_HC2R_UHSMS_SDR25 
 *  SDHC_HC2R_UHSMS_SDR50 
 *  SDHC_HC2R_UHSMS_SDR104
 *  SDHC_HC2R_UHSMS_DDR50 
 * SDHC_HC2R_VS18EN	1.8V Signaling Enable
 *  SDHC_HC2R_VS18EN_S33V
 *  SDHC_HC2R_VS18EN_S18V 
 * SDHC_HC2R_DRVSEL	Driver Strength Select
 *  SDHC_HC2R_DRVSEL_B
 *  SDHC_HC2R_DRVSEL_A
 *  SDHC_HC2R_DRVSEL_C
 *  SDHC_HC2R_DRVSEL_D 
 * SDHC_HC2R_EXTUN	Execute Tuning 
 * SDHC_HC2R_SLCKSEL	Sampling Clock Select 
 *  SDHC_HC2R_SLCKSEL_FIXED
 *  SDHC_HC2R_SLCKSEL_TUNED
 * SDHC_HC2R_ASINTEN	Asynchronous Interrupt Enable 
 * SDHC_HC2R_PVALEN	Preset Value Enable 
 *  SDHC_HC2R_PVALEN_HOST
 *  SDHC_HC2R_PVALEN_AUTO
 */
static inline void sdhc_set_HC2R(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->HC2R.reg |= mask;
}

/*
 * @brief get host control 2 register masked
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 * SDHC_HC2R_UHSMS	UHS Mode Select
 *  SDHC_HC2R_UHSMS_SDR12 
 *  SDHC_HC2R_UHSMS_SDR25 
 *  SDHC_HC2R_UHSMS_SDR50 
 *  SDHC_HC2R_UHSMS_SDR104
 *  SDHC_HC2R_UHSMS_DDR50 
 * SDHC_HC2R_VS18EN	1.8V Signaling Enable
 *  SDHC_HC2R_VS18EN_S33V
 *  SDHC_HC2R_VS18EN_S18V 
 * SDHC_HC2R_DRVSEL	Driver Strength Select
 *  SDHC_HC2R_DRVSEL_B
 *  SDHC_HC2R_DRVSEL_A
 *  SDHC_HC2R_DRVSEL_C
 *  SDHC_HC2R_DRVSEL_D 
 * SDHC_HC2R_EXTUN	Execute Tuning 
 * SDHC_HC2R_SLCKSEL	Sampling Clock Select 
 *  SDHC_HC2R_SLCKSEL_FIXED
 *  SDHC_HC2R_SLCKSEL_TUNED
 * SDHC_HC2R_ASINTEN	Asynchronous Interrupt Enable 
 * SDHC_HC2R_PVALEN	Preset Value Enable 
 *  SDHC_HC2R_PVALEN_HOST
 *  SDHC_HC2R_PVALEN_AUTO
 */
static inline uint16_t sdhc_get_HC2R(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->HC2R.reg & mask);
}

/*
 * @brief write host control 2 register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 * SDHC_HC2R_UHSMS	UHS Mode Select
 *  SDHC_HC2R_UHSMS_SDR12 
 *  SDHC_HC2R_UHSMS_SDR25 
 *  SDHC_HC2R_UHSMS_SDR50 
 *  SDHC_HC2R_UHSMS_SDR104
 *  SDHC_HC2R_UHSMS_DDR50 
 * SDHC_HC2R_VS18EN	1.8V Signaling Enable
 *  SDHC_HC2R_VS18EN_S33V
 *  SDHC_HC2R_VS18EN_S18V 
 * SDHC_HC2R_DRVSEL	Driver Strength Select
 *  SDHC_HC2R_DRVSEL_B
 *  SDHC_HC2R_DRVSEL_A
 *  SDHC_HC2R_DRVSEL_C
 *  SDHC_HC2R_DRVSEL_D 
 * SDHC_HC2R_EXTUN	Execute Tuning 
 * SDHC_HC2R_SLCKSEL	Sampling Clock Select 
 *  SDHC_HC2R_SLCKSEL_FIXED
 *  SDHC_HC2R_SLCKSEL_TUNED
 * SDHC_HC2R_ASINTEN	Asynchronous Interrupt Enable 
 * SDHC_HC2R_PVALEN	Preset Value Enable 
 *  SDHC_HC2R_PVALEN_HOST
 *  SDHC_HC2R_PVALEN_AUTO
 */
static inline void sdhc_write_HC2R(SDHC_t *SDHC, uint16_t data)
{
	SDHC->HC2R.reg = data;
}

/*
 * @brief clear host control 2 register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_HC2R_UHSMS	UHS Mode Select
 *  SDHC_HC2R_UHSMS_SDR12 
 *  SDHC_HC2R_UHSMS_SDR25 
 *  SDHC_HC2R_UHSMS_SDR50 
 *  SDHC_HC2R_UHSMS_SDR104
 *  SDHC_HC2R_UHSMS_DDR50 
 * SDHC_HC2R_VS18EN	1.8V Signaling Enable
 *  SDHC_HC2R_VS18EN_S33V
 *  SDHC_HC2R_VS18EN_S18V 
 * SDHC_HC2R_DRVSEL	Driver Strength Select
 *  SDHC_HC2R_DRVSEL_B
 *  SDHC_HC2R_DRVSEL_A
 *  SDHC_HC2R_DRVSEL_C
 *  SDHC_HC2R_DRVSEL_D 
 * SDHC_HC2R_EXTUN	Execute Tuning 
 * SDHC_HC2R_SLCKSEL	Sampling Clock Select 
 *  SDHC_HC2R_SLCKSEL_FIXED
 *  SDHC_HC2R_SLCKSEL_TUNED
 * SDHC_HC2R_ASINTEN	Asynchronous Interrupt Enable 
 * SDHC_HC2R_PVALEN	Preset Value Enable 
 *  SDHC_HC2R_PVALEN_HOST
 *  SDHC_HC2R_PVALEN_AUTO
 */
static inline void sdhc_clear_HC2R(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->HC2R.reg &= ~mask;
}

/*
 * @brief read host control 2 register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 * SDHC_HC2R_UHSMS	UHS Mode Select
 *  SDHC_HC2R_UHSMS_SDR12 
 *  SDHC_HC2R_UHSMS_SDR25 
 *  SDHC_HC2R_UHSMS_SDR50 
 *  SDHC_HC2R_UHSMS_SDR104
 *  SDHC_HC2R_UHSMS_DDR50 
 * SDHC_HC2R_VS18EN	1.8V Signaling Enable
 *  SDHC_HC2R_VS18EN_S33V
 *  SDHC_HC2R_VS18EN_S18V 
 * SDHC_HC2R_DRVSEL	Driver Strength Select
 *  SDHC_HC2R_DRVSEL_B
 *  SDHC_HC2R_DRVSEL_A
 *  SDHC_HC2R_DRVSEL_C
 *  SDHC_HC2R_DRVSEL_D 
 * SDHC_HC2R_EXTUN	Execute Tuning 
 * SDHC_HC2R_SLCKSEL	Sampling Clock Select 
 *  SDHC_HC2R_SLCKSEL_FIXED
 *  SDHC_HC2R_SLCKSEL_TUNED
 * SDHC_HC2R_ASINTEN	Asynchronous Interrupt Enable 
 * SDHC_HC2R_PVALEN	Preset Value Enable 
 *  SDHC_HC2R_PVALEN_HOST
 *  SDHC_HC2R_PVALEN_AUTO
 */
static inline uint16_t sdhc_read_HC2R(SDHC_t *SDHC)
{
	return SDHC->HC2R.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 */
static inline void sdhc_write_FERACES(SDHC_t *SDHC, uint16_t data)
{
	SDHC->FERACES.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 */
static inline void sdhc_write_FEREIS(SDHC_t *SDHC, uint16_t data)
{
	SDHC->FEREIS.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data
 */
static inline void sdhc_write_MC2R(SDHC_t *SDHC, uint8_t data)
{
	SDHC->MC2R.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 */
static inline void sdhc_set_BSR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->BSR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 */
static inline uint16_t sdhc_get_BSR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->BSR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 */
static inline void sdhc_write_BSR(SDHC_t *SDHC, uint16_t data)
{
	SDHC->BSR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 */
static inline void sdhc_clear_BSR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->BSR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 */
static inline uint16_t sdhc_read_BSR(SDHC_t *SDHC)
{
	return SDHC->BSR.reg;
}

/*
 * @brief write block count register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t block count
 */
static inline void sdhc_write_BCR(SDHC_t *SDHC, uint16_t data)
{
	SDHC->BCR.reg = data;
}

/*
 * @brief read block count register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 */
static inline uint16_t sdhc_read_BCR(SDHC_t *SDHC)
{
	return SDHC->BCR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_set_ARG1R(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->ARG1R.reg |= mask;
}


/*
 * @brief write argument 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t data
 */
static inline void sdhc_write_ARG1R(SDHC_t *SDHC, uint32_t data)
{
	SDHC->ARG1R.reg = data;
}


/*
 * @brief read argument 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 */
static inline uint32_t sdhc_read_ARG1R(SDHC_t *SDHC)
{
	return SDHC->ARG1R.reg;
}

/*
 * @brief set transfer mode register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_TMR_DMAEN	DMA Enable 
 * SDHC_TMR_BCEN	Block Count Enable 
 * SDHC_TMR_ACMDEN	Auto Command Enable 
 *  SDHC_TMR_ACMDEN_DISABLED
 *  SDHC_TMR_ACMDEN_CMD12   
 *  SDHC_TMR_ACMDEN_CMD23   
 *  SDHC_TMR_ACMDEN_3       
 * SDHC_TMR_DTDSEL	Data Transfer Direction Selection 
 * SDHC_TMR_MSBSEL	Multi/Single Block Selection 
 *  SDHC_TMR_MSBSEL_SINGLE  
 *  SDHC_TMR_MSBSEL_MULTIPLE
 */
static inline void sdhc_set_TMR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->TMR.reg |= mask;
}

/*
 * @brief get transfer mode register masked
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 * SDHC_TMR_DMAEN	DMA Enable 
 * SDHC_TMR_BCEN	Block Count Enable 
 * SDHC_TMR_ACMDEN	Auto Command Enable 
 *  SDHC_TMR_ACMDEN_DISABLED
 *  SDHC_TMR_ACMDEN_CMD12   
 *  SDHC_TMR_ACMDEN_CMD23   
 *  SDHC_TMR_ACMDEN_3       
 * SDHC_TMR_DTDSEL	Data Transfer Direction Selection 
 * SDHC_TMR_MSBSEL	Multi/Single Block Selection 
 *  SDHC_TMR_MSBSEL_SINGLE  
 *  SDHC_TMR_MSBSEL_MULTIPLE
 */
static inline uint16_t sdhc_get_TMR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->TMR.reg & mask);
}

/*
 * @brief write transfer mode register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 * SDHC_TMR_DMAEN	DMA Enable 
 * SDHC_TMR_BCEN	Block Count Enable 
 * SDHC_TMR_ACMDEN	Auto Command Enable 
 *  SDHC_TMR_ACMDEN_DISABLED
 *  SDHC_TMR_ACMDEN_CMD12   
 *  SDHC_TMR_ACMDEN_CMD23   
 *  SDHC_TMR_ACMDEN_3       
 * SDHC_TMR_DTDSEL	Data Transfer Direction Selection 
 * SDHC_TMR_MSBSEL	Multi/Single Block Selection 
 *  SDHC_TMR_MSBSEL_SINGLE  
 *  SDHC_TMR_MSBSEL_MULTIPLE
 */
static inline void sdhc_write_TMR(SDHC_t *SDHC, uint16_t data)
{
	SDHC->TMR.reg = data;
}

/*
 * @brief clear transfer mode register with mask
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_TMR_DMAEN	DMA Enable 
 * SDHC_TMR_BCEN	Block Count Enable 
 * SDHC_TMR_ACMDEN	Auto Command Enable 
 *  SDHC_TMR_ACMDEN_DISABLED
 *  SDHC_TMR_ACMDEN_CMD12   
 *  SDHC_TMR_ACMDEN_CMD23   
 *  SDHC_TMR_ACMDEN_3       
 * SDHC_TMR_DTDSEL	Data Transfer Direction Selection 
 * SDHC_TMR_MSBSEL	Multi/Single Block Selection 
 *  SDHC_TMR_MSBSEL_SINGLE  
 *  SDHC_TMR_MSBSEL_MULTIPLE
 */
static inline void sdhc_clear_TMR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->TMR.reg &= ~mask;
}

/*
 * @brief read transfer mode register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 * SDHC_TMR_DMAEN	DMA Enable 
 * SDHC_TMR_BCEN	Block Count Enable 
 * SDHC_TMR_ACMDEN	Auto Command Enable 
 *  SDHC_TMR_ACMDEN_DISABLED
 *  SDHC_TMR_ACMDEN_CMD12   
 *  SDHC_TMR_ACMDEN_CMD23   
 *  SDHC_TMR_ACMDEN_3       
 * SDHC_TMR_DTDSEL	Data Transfer Direction Selection 
 * SDHC_TMR_MSBSEL	Multi/Single Block Selection 
 *  SDHC_TMR_MSBSEL_SINGLE  
 *  SDHC_TMR_MSBSEL_MULTIPLE
 */
static inline uint16_t sdhc_read_TMR(SDHC_t *SDHC)
{
	return SDHC->TMR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 */
static inline void sdhc_set_CR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->CR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 */
static inline uint16_t sdhc_get_CR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->CR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 */
static inline void sdhc_write_CR(SDHC_t *SDHC, uint16_t data)
{
	SDHC->CR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 */
static inline void sdhc_clear_CR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->CR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 */
static inline uint16_t sdhc_read_CR(SDHC_t *SDHC)
{
	return SDHC->CR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_set_BDPR(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->BDPR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t sdhc_get_BDPR(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->BDPR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t data
 */
static inline void sdhc_write_BDPR(SDHC_t *SDHC, uint32_t data)
{
	SDHC->BDPR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_clear_BDPR(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->BDPR.reg &= ~mask;
}

/*
 * @brief read buffer data port register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 */
static inline uint32_t sdhc_read_BDPR(SDHC_t *SDHC)
{
	return SDHC->BDPR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_set_PCR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->PCR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 */
static inline uint8_t sdhc_get_PCR(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->PCR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data
 * SDHC_PCR_SDBPWR	SD Bus Power 
 * SDHC_PCR_SDBVSEL	SD Bus Voltage Select 
 *  SDHC_PCR_SDBVSEL_1V8
 *  SDHC_PCR_SDBVSEL_3V0
 *  SDHC_PCR_SDBVSEL_3V3
 */
static inline void sdhc_write_PCR(SDHC_t *SDHC, uint8_t data)
{
	SDHC->PCR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_clear_PCR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->PCR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t
 */
static inline uint8_t sdhc_read_PCR(SDHC_t *SDHC)
{
	return SDHC->PCR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_set_WCR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->WCR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 */
static inline uint8_t sdhc_get_WCR(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->WCR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data
 */
static inline void sdhc_write_WCR(SDHC_t *SDHC, uint8_t data)
{
	SDHC->WCR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_clear_WCR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->WCR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t
 */
static inline uint8_t sdhc_read_WCR(SDHC_t *SDHC)
{
	return SDHC->WCR.reg;
}

/*
 * @brief set clock control register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_CCR_INTCLKEN	Internal Clock Enable 
 * SDHC_CCR_INTCLKS	Internal Clock Stable 
 * SDHC_CCR_SDCLKEN	SD Clock Enable 
 * SDHC_CCR_CLKGSEL	Clock Generator Select 
 * SDHC_CCR_USDCLKFSEL(value)	Upper Bits of SDCLK Frequency Select 
 * SDHC_CCR_SDCLKFSEL(value)	SDCLK Frequency Select 
 */
static inline void sdhc_set_CCR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->CCR.reg |= mask;
}

/*
 * @brief get clock control register with mask
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 * SDHC_CCR_INTCLKEN	Internal Clock Enable 
 * SDHC_CCR_INTCLKS	Internal Clock Stable 
 * SDHC_CCR_SDCLKEN	SD Clock Enable 
 * SDHC_CCR_CLKGSEL	Clock Generator Select 
 * SDHC_CCR_USDCLKFSEL(value)	Upper Bits of SDCLK Frequency Select 
 * SDHC_CCR_SDCLKFSEL(value)	SDCLK Frequency Select 
 */
static inline uint16_t sdhc_get_CCR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->CCR.reg & mask);
}

/*
 * @brief write clock control register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t data
 * SDHC_CCR_INTCLKEN	Internal Clock Enable 
 * SDHC_CCR_INTCLKS	Internal Clock Stable 
 * SDHC_CCR_SDCLKEN	SD Clock Enable 
 * SDHC_CCR_CLKGSEL	Clock Generator Select 
 * SDHC_CCR_USDCLKFSEL(value)	Upper Bits of SDCLK Frequency Select 
 * SDHC_CCR_SDCLKFSEL(value)	SDCLK Frequency Select 
 */
static inline void sdhc_write_CCR(SDHC_t *SDHC, uint16_t data)
{
	SDHC->CCR.reg = data;
}

/*
 * @brief  clear clock control register with mask
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * SDHC_CCR_INTCLKEN	Internal Clock Enable 
 * SDHC_CCR_INTCLKS	Internal Clock Stable 
 * SDHC_CCR_SDCLKEN	SD Clock Enable 
 * SDHC_CCR_CLKGSEL	Clock Generator Select 
 * SDHC_CCR_USDCLKFSEL(value)	Upper Bits of SDCLK Frequency Select 
 * SDHC_CCR_SDCLKFSEL(value)	SDCLK Frequency Select 
 */
static inline void sdhc_clear_CCR(SDHC_t *SDHC, uint16_t mask)
{
	SDHC->CCR.reg &= ~mask;
}

/*
 * @brief read clock control register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 * SDHC_CCR_INTCLKEN	Internal Clock Enable 
 * SDHC_CCR_INTCLKS	Internal Clock Stable 
 * SDHC_CCR_SDCLKEN	SD Clock Enable 
 * SDHC_CCR_CLKGSEL	Clock Generator Select 
 * SDHC_CCR_USDCLKFSEL(value)	Upper Bits of SDCLK Frequency Select 
 * SDHC_CCR_SDCLKFSEL(value)	SDCLK Frequency Select 
 */
static inline uint16_t sdhc_read_CCR(SDHC_t *SDHC)
{
	return SDHC->CCR.reg;
}


/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 */
static inline uint8_t sdhc_get_TCR(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->TCR.reg & mask);
}

/*
 * @brief write timeout control register
 * 14 is max value for data 2^(13 + value)/fcore
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data SDHC_TCR_DTCVAL(data) Data Timeout Counter Value
 
 */
static inline void sdhc_write_TCR(SDHC_t *SDHC, uint8_t data)
{
	SDHC->TCR.reg = data;
}


/*
 * @brief read timeout control register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t SDHC_TCR_DTCVAL
 */
static inline uint8_t sdhc_read_TCR(SDHC_t *SDHC)
{
	return SDHC->TCR.reg;
}

/*
 * @brief do software reset
 * when read bits go to zero when reset complete
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * SDHC_SRR_SWRSTALL	Software Reset For All 
 * SDHC_SRR_SWRSTCMD	Software Reset For CMD Line 
 * SDHC_SRR_SWRSTDAT	Software Reset For DAT Line 
 */
static inline void sdhc_set_SRR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->SRR.reg |= mask;
}

/*
 * @brief read software reset masked
 * bits go to zero when reset complete
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 * SDHC_SRR_SWRSTALL	Software Reset For All 
 * SDHC_SRR_SWRSTCMD	Software Reset For CMD Line 
 * SDHC_SRR_SWRSTDAT	Software Reset For DAT Line 
 */
static inline uint8_t sdhc_get_SRR(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->SRR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data
 * SDHC_SRR_SWRSTALL	Software Reset For All 
 * SDHC_SRR_SWRSTCMD	Software Reset For CMD Line 
 * SDHC_SRR_SWRSTDAT	Software Reset For DAT Line 
 */
static inline void sdhc_write_SRR(SDHC_t *SDHC, uint8_t data)
{
	SDHC->SRR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t
 * SDHC_SRR_SWRSTALL	Software Reset For All 
 * SDHC_SRR_SWRSTCMD	Software Reset For CMD Line 
 * SDHC_SRR_SWRSTDAT	Software Reset For DAT Line 
 */
static inline uint8_t sdhc_read_SRR(SDHC_t *SDHC)
{
	return SDHC->SRR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 */
static inline void sdhc_set_ASAR(SDHC_t *SDHC, uint8_t index, uint32_t mask)
{
	SDHC->ASAR[index].reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t sdhc_get_ASAR(SDHC_t *SDHC, uint8_t index, uint32_t mask)
{
	return (SDHC->ASAR[index].reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint32_t data
 */
static inline void sdhc_write_ASAR(SDHC_t *SDHC, uint8_t index, uint32_t data)
{
	SDHC->ASAR[index].reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 */
static inline void sdhc_clear_ASAR(SDHC_t *SDHC, uint8_t index, uint32_t mask)
{
	SDHC->ASAR[index].reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @return uint32_t
 */
static inline uint32_t sdhc_read_ASAR(SDHC_t *SDHC, uint8_t index)
{
	return SDHC->ASAR[index].reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint16_t mask
 */
static inline void sdhc_set_PVR(SDHC_t *SDHC, uint8_t index, uint16_t mask)
{
	SDHC->PVR[index].reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint16_t mask
 * @return uint16_t
 */
static inline uint16_t sdhc_get_PVR(SDHC_t *SDHC, uint8_t index, uint16_t mask)
{
	return (SDHC->PVR[index].reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint16_t data
 */
static inline void sdhc_write_PVR(SDHC_t *SDHC, uint8_t index, uint16_t data)
{
	SDHC->PVR[index].reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint16_t mask
 */
static inline void sdhc_clear_PVR(SDHC_t *SDHC, uint8_t index, uint16_t mask)
{
	SDHC->PVR[index].reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @return uint16_t
 */
static inline uint16_t sdhc_read_PVR(SDHC_t *SDHC, uint8_t index)
{
	return SDHC->PVR[index].reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_set_MC1R(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->MC1R.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 */
static inline uint8_t sdhc_get_MC1R(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->MC1R.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data
 */
static inline void sdhc_write_MC1R(SDHC_t *SDHC, uint8_t data)
{
	SDHC->MC1R.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_clear_MC1R(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->MC1R.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t
 */
static inline uint8_t sdhc_read_MC1R(SDHC_t *SDHC)
{
	return SDHC->MC1R.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_set_ACR(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->ACR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t sdhc_get_ACR(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->ACR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t data
 */
static inline void sdhc_write_ACR(SDHC_t *SDHC, uint32_t data)
{
	SDHC->ACR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_clear_ACR(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->ACR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 */
static inline uint32_t sdhc_read_ACR(SDHC_t *SDHC)
{
	return SDHC->ACR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_set_CC2R(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->CC2R.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t sdhc_get_CC2R(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->CC2R.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t data
 */
static inline void sdhc_write_CC2R(SDHC_t *SDHC, uint32_t data)
{
	SDHC->CC2R.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_clear_CC2R(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->CC2R.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 */
static inline uint32_t sdhc_read_CC2R(SDHC_t *SDHC)
{
	return SDHC->CC2R.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_set_CACR(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->CACR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t sdhc_get_CACR(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->CACR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t data
 */
static inline void sdhc_write_CACR(SDHC_t *SDHC, uint32_t data)
{
	SDHC->CACR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 */
static inline void sdhc_clear_CACR(SDHC_t *SDHC, uint32_t mask)
{
	SDHC->CACR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 */
static inline uint32_t sdhc_read_CACR(SDHC_t *SDHC)
{
	return SDHC->CACR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_set_DBGR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->DBGR.reg |= mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 */
static inline uint8_t sdhc_get_DBGR(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->DBGR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t data
 */
static inline void sdhc_write_DBGR(SDHC_t *SDHC, uint8_t data)
{
	SDHC->DBGR.reg = data;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 */
static inline void sdhc_clear_DBGR(SDHC_t *SDHC, uint8_t mask)
{
	SDHC->DBGR.reg &= ~mask;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t
 */
static inline uint8_t sdhc_read_DBGR(SDHC_t *SDHC)
{
	return SDHC->DBGR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t sdhc_get_RR(SDHC_t *SDHC, uint8_t index, uint32_t mask)
{
	return (SDHC->RR[index].reg & mask);
}

/*
 * @brief read response register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t index
 * @return uint32_t
 */
static inline uint32_t sdhc_read_RR(SDHC_t *SDHC, uint8_t index)
{
	return SDHC->RR[index].reg;
}

/*
 * @brief get present state register
 * read only register
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 * SDHC_PSR_CMDINHC	Command Inhibit (CMD) 
 * SDHC_PSR_CMDINHD	Command Inhibit (DAT) 
 * SDHC_PSR_DLACT	DAT Line Active 
 * SDHC_PSR_RTREQ	Re-Tuning Request 
 * SDHC_PSR_WTACT	Write Transfer Active 
 * SDHC_PSR_RTACT	Read Transfer Active 
 * SDHC_PSR_BUFWREN	Buffer Write Enable 
 * SDHC_PSR_BUFRDEN	Buffer Read Enable 
 * SDHC_PSR_CARDINS	Card Inserted 
 * SDHC_PSR_CARDSS	Card State Stable 
 * SDHC_PSR_CARDDPL	Card Detect Pin Level 
 * SDHC_PSR_WRPPL	Write Protect Pin Level 
 * SDHC_PSR_DATLL	DAT[3:0] Line Level 
 * SDHC_PSR_CMDLL	CMD Line Level 
 */
static inline uint32_t sdhc_get_PSR(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->PSR.reg & mask);
}

/*
 * @brief read present state register
 * read only
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 * SDHC_PSR_CMDINHC	Command Inhibit (CMD) 
 * SDHC_PSR_CMDINHD	Command Inhibit (DAT) 
 * SDHC_PSR_DLACT	DAT Line Active 
 * SDHC_PSR_RTREQ	Re-Tuning Request 
 * SDHC_PSR_WTACT	Write Transfer Active 
 * SDHC_PSR_RTACT	Read Transfer Active 
 * SDHC_PSR_BUFWREN	Buffer Write Enable 
 * SDHC_PSR_BUFRDEN	Buffer Read Enable 
 * SDHC_PSR_CARDINS	Card Inserted 
 * SDHC_PSR_CARDSS	Card State Stable 
 * SDHC_PSR_CARDDPL	Card Detect Pin Level 
 * SDHC_PSR_WRPPL	Write Protect Pin Level 
 * SDHC_PSR_DATLL	DAT[3:0] Line Level 
 * SDHC_PSR_CMDLL	CMD Line Level 
 */
static inline uint32_t sdhc_read_PSR(SDHC_t *SDHC)
{
	return SDHC->PSR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 */
static inline uint16_t sdhc_get_ACESR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->ACESR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 */
static inline uint16_t sdhc_read_ACESR(SDHC_t *SDHC)
{
	return SDHC->ACESR.reg;
}

/*
 * @brief get capability register 0 with mask
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 * SDHC_CA0R_TEOCLKF	Timeout Clock Frequency 
 * SDHC_CA0R_TEOCLKU	Timeout Clock Unit 
 * SDHC_CA0R_BASECLKF	Base Clock Frequency 
 * SDHC_CA0R_MAXBLKL	Max Block Length 
 *  SDHC_CA0R_MAXBLKL_512 
 *  SDHC_CA0R_MAXBLKL_1024
 *  SDHC_CA0R_MAXBLKL_2048
 * SDHC_CA0R_ED8SUP	8-bit Support for Embedded Device 
 * SDHC_CA0R_ADMA2SUP	ADMA2 Support 
 * SDHC_CA0R_HSSUP	High Speed Support 
 * SDHC_CA0R_SDMASUP	SDMA Support 
 * SDHC_CA0R_SRSUP	Suspend/Resume Support 
 * SDHC_CA0R_V33VSUP	Voltage Support 3.3V 
 * SDHC_CA0R_V30VSUP	Voltage Support 3.0V 
 * SDHC_CA0R_V18VSUP	Voltage Support 1.8V 
 * SDHC_CA0R_SB64SUP	64-Bit System Bus Support 
 * SDHC_CA0R_ASINTSUP	Asynchronous Interrupt Support 
 * SDHC_CA0R_SLTYPE	Slot Type 
 */
static inline uint32_t sdhc_get_CA0R(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->CA0R.reg & mask);
}

/*
 * @brief read capability register 0
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 * SDHC_CA0R_TEOCLKF	Timeout Clock Frequency 
 * SDHC_CA0R_TEOCLKU	Timeout Clock Unit 
 * SDHC_CA0R_BASECLKF	Base Clock Frequency 
 * SDHC_CA0R_MAXBLKL	Max Block Length 
 *  SDHC_CA0R_MAXBLKL_512 
 *  SDHC_CA0R_MAXBLKL_1024
 *  SDHC_CA0R_MAXBLKL_2048
 * SDHC_CA0R_ED8SUP	8-bit Support for Embedded Device 
 * SDHC_CA0R_ADMA2SUP	ADMA2 Support 
 * SDHC_CA0R_HSSUP	High Speed Support 
 * SDHC_CA0R_SDMASUP	SDMA Support 
 * SDHC_CA0R_SRSUP	Suspend/Resume Support 
 * SDHC_CA0R_V33VSUP	Voltage Support 3.3V 
 * SDHC_CA0R_V30VSUP	Voltage Support 3.0V 
 * SDHC_CA0R_V18VSUP	Voltage Support 1.8V 
 * SDHC_CA0R_SB64SUP	64-Bit System Bus Support 
 * SDHC_CA0R_ASINTSUP	Asynchronous Interrupt Support 
 * SDHC_CA0R_SLTYPE	Slot Type 
 */
static inline uint32_t sdhc_read_CA0R(SDHC_t *SDHC)
{
	return SDHC->CA0R.reg;
}

/*
 * @brief get capabilities 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 * SDHC_CA1R_SDR50SUP	SDR50 Support 
 * SDHC_CA1R_SDR104SUP	SDR104 Support 
 * SDHC_CA1R_DDR50SUP	DDR50 Support 
 * SDHC_CA1R_DRVASUP	Driver Type A Support 
 * SDHC_CA1R_DRVCSUP	Driver Type C Support 
 * SDHC_CA1R_DRVDSUP	Driver Type D Support 
 * SDHC_CA1R_TCNTRT	Timer Count for Re-Tuning
 *  SDHC_CA1R_TCNTRT_1S   
 *  SDHC_CA1R_TCNTRT_2S   
 *  SDHC_CA1R_TCNTRT_4S   
 *  SDHC_CA1R_TCNTRT_8S   
 *  SDHC_CA1R_TCNTRT_16S  
 *  SDHC_CA1R_TCNTRT_32S  
 *  SDHC_CA1R_TCNTRT_64S  
 *  SDHC_CA1R_TCNTRT_128S 
 *  SDHC_CA1R_TCNTRT_256S 
 *  SDHC_CA1R_TCNTRT_512S 
 *  SDHC_CA1R_TCNTRT_1024S
 *  SDHC_CA1R_TCNTRT_OTHER
 * SDHC_CA1R_TSDR50	Use Tuning for SDR50 
 * SDHC_CA1R_CLKMULT	Clock Multiplier 
 */
static inline uint32_t sdhc_get_CA1R(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->CA1R.reg & mask);
}

/*
 * @brief read capabilities 1 register
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 * SDHC_CA1R_SDR50SUP	SDR50 Support 
 * SDHC_CA1R_SDR104SUP	SDR104 Support 
 * SDHC_CA1R_DDR50SUP	DDR50 Support 
 * SDHC_CA1R_DRVASUP	Driver Type A Support 
 * SDHC_CA1R_DRVCSUP	Driver Type C Support 
 * SDHC_CA1R_DRVDSUP	Driver Type D Support 
 * SDHC_CA1R_TCNTRT	Timer Count for Re-Tuning
 *  SDHC_CA1R_TCNTRT_1S   
 *  SDHC_CA1R_TCNTRT_2S   
 *  SDHC_CA1R_TCNTRT_4S   
 *  SDHC_CA1R_TCNTRT_8S   
 *  SDHC_CA1R_TCNTRT_16S  
 *  SDHC_CA1R_TCNTRT_32S  
 *  SDHC_CA1R_TCNTRT_64S  
 *  SDHC_CA1R_TCNTRT_128S 
 *  SDHC_CA1R_TCNTRT_256S 
 *  SDHC_CA1R_TCNTRT_512S 
 *  SDHC_CA1R_TCNTRT_1024S
 *  SDHC_CA1R_TCNTRT_OTHER
 * SDHC_CA1R_TSDR50	Use Tuning for SDR50 
 * SDHC_CA1R_CLKMULT	Clock Multiplier 
 */
static inline uint32_t sdhc_read_CA1R(SDHC_t *SDHC)
{
	return SDHC->CA1R.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t sdhc_get_MCCAR(SDHC_t *SDHC, uint32_t mask)
{
	return (SDHC->MCCAR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint32_t
 */
static inline uint32_t sdhc_read_MCCAR(SDHC_t *SDHC)
{
	return SDHC->MCCAR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint8_t mask
 * @return uint8_t
 */
static inline uint8_t sdhc_get_AESR(SDHC_t *SDHC, uint8_t mask)
{
	return (SDHC->AESR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint8_t
 */
static inline uint8_t sdhc_read_AESR(SDHC_t *SDHC)
{
	return SDHC->AESR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 */
static inline uint16_t sdhc_get_SISR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->SISR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 */
static inline uint16_t sdhc_read_SISR(SDHC_t *SDHC)
{
	return SDHC->SISR.reg;
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @param[in] uint16_t mask
 * @return uint16_t
 */
static inline uint16_t sdhc_get_HCVR(SDHC_t *SDHC, uint16_t mask)
{
	return (SDHC->HCVR.reg & mask);
}

/*
 * @brief
 *
 * @param[in] SDHC_t *SDHC
 * @return uint16_t
 */
static inline uint16_t sdhc_read_HCVR(SDHC_t *SDHC)
{
	return SDHC->HCVR.reg;
}

#endif /* _SDHC_H_ */
