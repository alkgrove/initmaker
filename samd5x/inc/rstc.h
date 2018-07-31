/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM RSTC
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

#ifndef _RSTC_H_
#define _RSTC_H_

#include <stdbool.h>

/**
 * @brief rstc get RCAUSE register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * RSTC_RCAUSE_POR  Power On Reset 
 * RSTC_RCAUSE_BODCORE  Brown Out CORE Detector Reset 
 * RSTC_RCAUSE_BODVDD  Brown Out VDD Detector Reset 
 * RSTC_RCAUSE_NVM  NVM Reset 
 * RSTC_RCAUSE_EXT  External Reset 
 * RSTC_RCAUSE_WDT  Watchdog Reset 
 * RSTC_RCAUSE_SYST  System Reset Request 
 * RSTC_RCAUSE_BACKUP  Backup Reset 
 */
static inline uint8_t rstc_get_RCAUSE(uint8_t mask)
{
    return RSTC->RCAUSE.reg & mask;
}

/**
 * @brief rstc read RCAUSE register
 *
 * @param[in] void
 * @return uint8_t
 * RSTC_RCAUSE_POR  Power On Reset 
 * RSTC_RCAUSE_BODCORE  Brown Out CORE Detector Reset 
 * RSTC_RCAUSE_BODVDD  Brown Out VDD Detector Reset 
 * RSTC_RCAUSE_NVM  NVM Reset 
 * RSTC_RCAUSE_EXT  External Reset 
 * RSTC_RCAUSE_WDT  Watchdog Reset 
 * RSTC_RCAUSE_SYST  System Reset Request 
 * RSTC_RCAUSE_BACKUP  Backup Reset 
 */
static inline uint8_t rstc_read_RCAUSE(void)
{
	return RSTC->RCAUSE.reg;
}

/**
 * @brief rstc get BKUPEXIT register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * RSTC_BKUPEXIT_RTC  Real Timer Counter Interrupt 
 * RSTC_BKUPEXIT_BBPS  Battery Backup Power Switch 
 * RSTC_BKUPEXIT_HIB  Hibernate 
 */
static inline uint8_t rstc_get_BKUPEXIT(uint8_t mask)
{
    return RSTC->BKUPEXIT.reg & mask;
}

/**
 * @brief rstc read BKUPEXIT register
 *
 * @param[in] void
 * @return uint8_t
 * RSTC_BKUPEXIT_RTC  Real Timer Counter Interrupt 
 * RSTC_BKUPEXIT_BBPS  Battery Backup Power Switch 
 * RSTC_BKUPEXIT_HIB  Hibernate 
 */
static inline uint8_t rstc_read_BKUPEXIT(void)
{
	return RSTC->BKUPEXIT.reg;
}

#endif /* _RSTC_H */
