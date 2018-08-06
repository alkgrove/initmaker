/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM PAC
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

#ifndef _PAC_H_
#define _PAC_H_

#include <stdbool.h>

/**
 * @brief pac set INTEN register
 *
 * @param[in] mask uint8_t 
 * - PAC_INTENSET_ERR Peripheral access error interrupt enable
 **/
static inline void pac_set_INTEN(uint8_t mask)
{
	PAC->INTENSET.reg = mask;
}

/**
 * @brief pac get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PAC_INTENSET_ERR Peripheral access error interrupt enable
 **/
static inline uint8_t pac_get_INTEN(uint8_t mask)
{
    return PAC->INTENSET.reg & mask;
}

/**
 * @brief pac read INTEN register
 *
 * @return uint8_t
 * - PAC_INTENSET_ERR Peripheral access error interrupt enable
 **/
static inline uint8_t pac_read_INTEN(void)
{
	return PAC->INTENSET.reg;
}

/**
 * @brief pac write INTEN register
 *
 * @param[in] data uint8_t 
 * - PAC_INTENSET_ERR Peripheral access error interrupt enable
 **/
static inline void pac_write_INTEN(uint8_t data)
{
	PAC->INTENSET.reg = data;
	PAC->INTENCLR.reg = ~data;
}

/**
 * @brief pac clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - PAC_INTENSET_ERR Peripheral access error interrupt enable
 **/
static inline void pac_clear_INTEN(uint8_t mask)
{
	PAC->INTENCLR.reg = mask;
}

/**
 * @brief pac get INTFLAGAHB register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_INTFLAGAHB_FLASH FLASH
 * - PAC_INTFLAGAHB_FLASH_ALT FLASH_ALT
 * - PAC_INTFLAGAHB_SEEPROM SEEPROM
 * - PAC_INTFLAGAHB_RAMCM4S RAMCM4S
 * - PAC_INTFLAGAHB_RAMPPPDSU RAMPPPDSU
 * - PAC_INTFLAGAHB_RAMDMAWR RAMDMAWR
 * - PAC_INTFLAGAHB_RAMDMACICM RAMDMACICM
 * - PAC_INTFLAGAHB_HPB0 HPB0
 * - PAC_INTFLAGAHB_HPB1 HPB1
 * - PAC_INTFLAGAHB_HPB2 HPB2
 * - PAC_INTFLAGAHB_HPB3 HPB3
 * - PAC_INTFLAGAHB_PUKCC PUKCC
 * - PAC_INTFLAGAHB_SDHC0 SDHC0
 * - PAC_INTFLAGAHB_SDHC1 SDHC1
 * - PAC_INTFLAGAHB_QSPI QSPI
 * - PAC_INTFLAGAHB_BKUPRAM BKUPRAM
 **/
static inline uint32_t pac_get_INTFLAGAHB(uint32_t mask)
{
    return PAC->INTFLAGAHB.reg & mask;
}

/**
 * @brief pac read INTFLAGAHB register
 *
 * @return uint32_t
 * - PAC_INTFLAGAHB_FLASH FLASH
 * - PAC_INTFLAGAHB_FLASH_ALT FLASH_ALT
 * - PAC_INTFLAGAHB_SEEPROM SEEPROM
 * - PAC_INTFLAGAHB_RAMCM4S RAMCM4S
 * - PAC_INTFLAGAHB_RAMPPPDSU RAMPPPDSU
 * - PAC_INTFLAGAHB_RAMDMAWR RAMDMAWR
 * - PAC_INTFLAGAHB_RAMDMACICM RAMDMACICM
 * - PAC_INTFLAGAHB_HPB0 HPB0
 * - PAC_INTFLAGAHB_HPB1 HPB1
 * - PAC_INTFLAGAHB_HPB2 HPB2
 * - PAC_INTFLAGAHB_HPB3 HPB3
 * - PAC_INTFLAGAHB_PUKCC PUKCC
 * - PAC_INTFLAGAHB_SDHC0 SDHC0
 * - PAC_INTFLAGAHB_SDHC1 SDHC1
 * - PAC_INTFLAGAHB_QSPI QSPI
 * - PAC_INTFLAGAHB_BKUPRAM BKUPRAM
 **/
static inline uint32_t pac_read_INTFLAGAHB(void)
{
	return PAC->INTFLAGAHB.reg;
}

/**
 * @brief pac clear INTFLAGAHB register
 *
 * @param[in] mask uint32_t 
 * - PAC_INTFLAGAHB_FLASH FLASH
 * - PAC_INTFLAGAHB_FLASH_ALT FLASH_ALT
 * - PAC_INTFLAGAHB_SEEPROM SEEPROM
 * - PAC_INTFLAGAHB_RAMCM4S RAMCM4S
 * - PAC_INTFLAGAHB_RAMPPPDSU RAMPPPDSU
 * - PAC_INTFLAGAHB_RAMDMAWR RAMDMAWR
 * - PAC_INTFLAGAHB_RAMDMACICM RAMDMACICM
 * - PAC_INTFLAGAHB_HPB0 HPB0
 * - PAC_INTFLAGAHB_HPB1 HPB1
 * - PAC_INTFLAGAHB_HPB2 HPB2
 * - PAC_INTFLAGAHB_HPB3 HPB3
 * - PAC_INTFLAGAHB_PUKCC PUKCC
 * - PAC_INTFLAGAHB_SDHC0 SDHC0
 * - PAC_INTFLAGAHB_SDHC1 SDHC1
 * - PAC_INTFLAGAHB_QSPI QSPI
 * - PAC_INTFLAGAHB_BKUPRAM BKUPRAM
 **/
static inline void pac_clear_INTFLAGAHB(uint32_t mask)
{
	PAC->INTFLAGAHB.reg = mask;
}

/**
 * @brief pac get INTFLAGA register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_INTFLAGA_PAC PAC
 * - PAC_INTFLAGA_PM PM
 * - PAC_INTFLAGA_MCLK MCLK
 * - PAC_INTFLAGA_RSTC RSTC
 * - PAC_INTFLAGA_OSCCTRL OSCCTRL
 * - PAC_INTFLAGA_OSC32KCTRL OSC32KCTRL
 * - PAC_INTFLAGA_SUPC SUPC
 * - PAC_INTFLAGA_GCLK GCLK
 * - PAC_INTFLAGA_WDT WDT
 * - PAC_INTFLAGA_RTC RTC
 * - PAC_INTFLAGA_EIC EIC
 * - PAC_INTFLAGA_FREQM FREQM
 * - PAC_INTFLAGA_SERCOM0 SERCOM0
 * - PAC_INTFLAGA_SERCOM1 SERCOM1
 * - PAC_INTFLAGA_TC0 TC0
 * - PAC_INTFLAGA_TC1 TC1
 **/
static inline uint32_t pac_get_INTFLAGA(uint32_t mask)
{
    return PAC->INTFLAGA.reg & mask;
}

/**
 * @brief pac read INTFLAGA register
 *
 * @return uint32_t
 * - PAC_INTFLAGA_PAC PAC
 * - PAC_INTFLAGA_PM PM
 * - PAC_INTFLAGA_MCLK MCLK
 * - PAC_INTFLAGA_RSTC RSTC
 * - PAC_INTFLAGA_OSCCTRL OSCCTRL
 * - PAC_INTFLAGA_OSC32KCTRL OSC32KCTRL
 * - PAC_INTFLAGA_SUPC SUPC
 * - PAC_INTFLAGA_GCLK GCLK
 * - PAC_INTFLAGA_WDT WDT
 * - PAC_INTFLAGA_RTC RTC
 * - PAC_INTFLAGA_EIC EIC
 * - PAC_INTFLAGA_FREQM FREQM
 * - PAC_INTFLAGA_SERCOM0 SERCOM0
 * - PAC_INTFLAGA_SERCOM1 SERCOM1
 * - PAC_INTFLAGA_TC0 TC0
 * - PAC_INTFLAGA_TC1 TC1
 **/
static inline uint32_t pac_read_INTFLAGA(void)
{
	return PAC->INTFLAGA.reg;
}

/**
 * @brief pac clear INTFLAGA register
 *
 * @param[in] mask uint32_t 
 * - PAC_INTFLAGA_PAC PAC
 * - PAC_INTFLAGA_PM PM
 * - PAC_INTFLAGA_MCLK MCLK
 * - PAC_INTFLAGA_RSTC RSTC
 * - PAC_INTFLAGA_OSCCTRL OSCCTRL
 * - PAC_INTFLAGA_OSC32KCTRL OSC32KCTRL
 * - PAC_INTFLAGA_SUPC SUPC
 * - PAC_INTFLAGA_GCLK GCLK
 * - PAC_INTFLAGA_WDT WDT
 * - PAC_INTFLAGA_RTC RTC
 * - PAC_INTFLAGA_EIC EIC
 * - PAC_INTFLAGA_FREQM FREQM
 * - PAC_INTFLAGA_SERCOM0 SERCOM0
 * - PAC_INTFLAGA_SERCOM1 SERCOM1
 * - PAC_INTFLAGA_TC0 TC0
 * - PAC_INTFLAGA_TC1 TC1
 **/
static inline void pac_clear_INTFLAGA(uint32_t mask)
{
	PAC->INTFLAGA.reg = mask;
}

/**
 * @brief pac get INTFLAGB register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_INTFLAGB_USB USB
 * - PAC_INTFLAGB_DSU DSU
 * - PAC_INTFLAGB_NVMCTRL NVMCTRL
 * - PAC_INTFLAGB_CMCC CMCC
 * - PAC_INTFLAGB_PORT PORT
 * - PAC_INTFLAGB_DMAC DMAC
 * - PAC_INTFLAGB_HMATRIX HMATRIX
 * - PAC_INTFLAGB_EVSYS EVSYS
 * - PAC_INTFLAGB_SERCOM2 SERCOM2
 * - PAC_INTFLAGB_SERCOM3 SERCOM3
 * - PAC_INTFLAGB_TCC0 TCC0
 * - PAC_INTFLAGB_TCC1 TCC1
 * - PAC_INTFLAGB_TC2 TC2
 * - PAC_INTFLAGB_TC3 TC3
 * - PAC_INTFLAGB_TAL TAL
 * - PAC_INTFLAGB_RAMECC RAMECC
 **/
static inline uint32_t pac_get_INTFLAGB(uint32_t mask)
{
    return PAC->INTFLAGB.reg & mask;
}

/**
 * @brief pac read INTFLAGB register
 *
 * @return uint32_t
 * - PAC_INTFLAGB_USB USB
 * - PAC_INTFLAGB_DSU DSU
 * - PAC_INTFLAGB_NVMCTRL NVMCTRL
 * - PAC_INTFLAGB_CMCC CMCC
 * - PAC_INTFLAGB_PORT PORT
 * - PAC_INTFLAGB_DMAC DMAC
 * - PAC_INTFLAGB_HMATRIX HMATRIX
 * - PAC_INTFLAGB_EVSYS EVSYS
 * - PAC_INTFLAGB_SERCOM2 SERCOM2
 * - PAC_INTFLAGB_SERCOM3 SERCOM3
 * - PAC_INTFLAGB_TCC0 TCC0
 * - PAC_INTFLAGB_TCC1 TCC1
 * - PAC_INTFLAGB_TC2 TC2
 * - PAC_INTFLAGB_TC3 TC3
 * - PAC_INTFLAGB_TAL TAL
 * - PAC_INTFLAGB_RAMECC RAMECC
 **/
static inline uint32_t pac_read_INTFLAGB(void)
{
	return PAC->INTFLAGB.reg;
}

/**
 * @brief pac clear INTFLAGB register
 *
 * @param[in] mask uint32_t 
 * - PAC_INTFLAGB_USB USB
 * - PAC_INTFLAGB_DSU DSU
 * - PAC_INTFLAGB_NVMCTRL NVMCTRL
 * - PAC_INTFLAGB_CMCC CMCC
 * - PAC_INTFLAGB_PORT PORT
 * - PAC_INTFLAGB_DMAC DMAC
 * - PAC_INTFLAGB_HMATRIX HMATRIX
 * - PAC_INTFLAGB_EVSYS EVSYS
 * - PAC_INTFLAGB_SERCOM2 SERCOM2
 * - PAC_INTFLAGB_SERCOM3 SERCOM3
 * - PAC_INTFLAGB_TCC0 TCC0
 * - PAC_INTFLAGB_TCC1 TCC1
 * - PAC_INTFLAGB_TC2 TC2
 * - PAC_INTFLAGB_TC3 TC3
 * - PAC_INTFLAGB_TAL TAL
 * - PAC_INTFLAGB_RAMECC RAMECC
 **/
static inline void pac_clear_INTFLAGB(uint32_t mask)
{
	PAC->INTFLAGB.reg = mask;
}

/**
 * @brief pac get INTFLAGC register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_INTFLAGC_TCC2 TCC2
 * - PAC_INTFLAGC_TCC3 TCC3
 * - PAC_INTFLAGC_TC4 TC4
 * - PAC_INTFLAGC_TC5 TC5
 * - PAC_INTFLAGC_PDEC PDEC
 * - PAC_INTFLAGC_AC AC
 * - PAC_INTFLAGC_AES AES
 * - PAC_INTFLAGC_TRNG TRNG
 * - PAC_INTFLAGC_ICM ICM
 * - PAC_INTFLAGC_PUKCC PUKCC
 * - PAC_INTFLAGC_QSPI QSPI
 * - PAC_INTFLAGC_CCL CCL
 **/
static inline uint32_t pac_get_INTFLAGC(uint32_t mask)
{
    return PAC->INTFLAGC.reg & mask;
}

/**
 * @brief pac read INTFLAGC register
 *
 * @return uint32_t
 * - PAC_INTFLAGC_TCC2 TCC2
 * - PAC_INTFLAGC_TCC3 TCC3
 * - PAC_INTFLAGC_TC4 TC4
 * - PAC_INTFLAGC_TC5 TC5
 * - PAC_INTFLAGC_PDEC PDEC
 * - PAC_INTFLAGC_AC AC
 * - PAC_INTFLAGC_AES AES
 * - PAC_INTFLAGC_TRNG TRNG
 * - PAC_INTFLAGC_ICM ICM
 * - PAC_INTFLAGC_PUKCC PUKCC
 * - PAC_INTFLAGC_QSPI QSPI
 * - PAC_INTFLAGC_CCL CCL
 **/
static inline uint32_t pac_read_INTFLAGC(void)
{
	return PAC->INTFLAGC.reg;
}

/**
 * @brief pac clear INTFLAGC register
 *
 * @param[in] mask uint32_t 
 * - PAC_INTFLAGC_TCC2 TCC2
 * - PAC_INTFLAGC_TCC3 TCC3
 * - PAC_INTFLAGC_TC4 TC4
 * - PAC_INTFLAGC_TC5 TC5
 * - PAC_INTFLAGC_PDEC PDEC
 * - PAC_INTFLAGC_AC AC
 * - PAC_INTFLAGC_AES AES
 * - PAC_INTFLAGC_TRNG TRNG
 * - PAC_INTFLAGC_ICM ICM
 * - PAC_INTFLAGC_PUKCC PUKCC
 * - PAC_INTFLAGC_QSPI QSPI
 * - PAC_INTFLAGC_CCL CCL
 **/
static inline void pac_clear_INTFLAGC(uint32_t mask)
{
	PAC->INTFLAGC.reg = mask;
}

/**
 * @brief pac get INTFLAGD register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_INTFLAGD_SERCOM4 SERCOM4
 * - PAC_INTFLAGD_SERCOM5 SERCOM5
 * - PAC_INTFLAGD_SERCOM6 SERCOM6
 * - PAC_INTFLAGD_SERCOM7 SERCOM7
 * - PAC_INTFLAGD_TCC4 TCC4
 * - PAC_INTFLAGD_TC6 TC6
 * - PAC_INTFLAGD_TC7 TC7
 * - PAC_INTFLAGD_ADC0 ADC0
 * - PAC_INTFLAGD_ADC1 ADC1
 * - PAC_INTFLAGD_DAC DAC
 * - PAC_INTFLAGD_I2S I2S
 * - PAC_INTFLAGD_PCC PCC
 **/
static inline uint32_t pac_get_INTFLAGD(uint32_t mask)
{
    return PAC->INTFLAGD.reg & mask;
}

/**
 * @brief pac read INTFLAGD register
 *
 * @return uint32_t
 * - PAC_INTFLAGD_SERCOM4 SERCOM4
 * - PAC_INTFLAGD_SERCOM5 SERCOM5
 * - PAC_INTFLAGD_SERCOM6 SERCOM6
 * - PAC_INTFLAGD_SERCOM7 SERCOM7
 * - PAC_INTFLAGD_TCC4 TCC4
 * - PAC_INTFLAGD_TC6 TC6
 * - PAC_INTFLAGD_TC7 TC7
 * - PAC_INTFLAGD_ADC0 ADC0
 * - PAC_INTFLAGD_ADC1 ADC1
 * - PAC_INTFLAGD_DAC DAC
 * - PAC_INTFLAGD_I2S I2S
 * - PAC_INTFLAGD_PCC PCC
 **/
static inline uint32_t pac_read_INTFLAGD(void)
{
	return PAC->INTFLAGD.reg;
}

/**
 * @brief pac clear INTFLAGD register
 *
 * @param[in] mask uint32_t 
 * - PAC_INTFLAGD_SERCOM4 SERCOM4
 * - PAC_INTFLAGD_SERCOM5 SERCOM5
 * - PAC_INTFLAGD_SERCOM6 SERCOM6
 * - PAC_INTFLAGD_SERCOM7 SERCOM7
 * - PAC_INTFLAGD_TCC4 TCC4
 * - PAC_INTFLAGD_TC6 TC6
 * - PAC_INTFLAGD_TC7 TC7
 * - PAC_INTFLAGD_ADC0 ADC0
 * - PAC_INTFLAGD_ADC1 ADC1
 * - PAC_INTFLAGD_DAC DAC
 * - PAC_INTFLAGD_I2S I2S
 * - PAC_INTFLAGD_PCC PCC
 **/
static inline void pac_clear_INTFLAGD(uint32_t mask)
{
	PAC->INTFLAGD.reg = mask;
}

/**
 * @brief pac set WRCTRL register
 *
 * @param[in] mask uint32_t 
 * - PAC_WRCTRL_PERID(value) Peripheral identifier
 * - PAC_WRCTRL_KEY(value) Peripheral access control key
 *  +      PAC_WRCTRL_KEY_OFF No action
 *  +      PAC_WRCTRL_KEY_CLR Clear protection
 *  +      PAC_WRCTRL_KEY_SET Set protection
 *  +      PAC_WRCTRL_KEY_SETLCK Set and lock protection
 **/
static inline void pac_set_WRCTRL(uint32_t mask)
{
	PAC->WRCTRL.reg |= mask;
}

/**
 * @brief pac get WRCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_WRCTRL_PERID(value) Peripheral identifier
 * - PAC_WRCTRL_KEY(value) Peripheral access control key
 *  +      PAC_WRCTRL_KEY_OFF No action
 *  +      PAC_WRCTRL_KEY_CLR Clear protection
 *  +      PAC_WRCTRL_KEY_SET Set protection
 *  +      PAC_WRCTRL_KEY_SETLCK Set and lock protection
 **/
static inline uint32_t pac_get_WRCTRL(uint32_t mask)
{
    return PAC->WRCTRL.reg & mask;
}

/**
 * @brief pac write WRCTRL register
 *
 * @param[in] data uint32_t 
 * - PAC_WRCTRL_PERID(value) Peripheral identifier
 * - PAC_WRCTRL_KEY(value) Peripheral access control key
 *  +      PAC_WRCTRL_KEY_OFF No action
 *  +      PAC_WRCTRL_KEY_CLR Clear protection
 *  +      PAC_WRCTRL_KEY_SET Set protection
 *  +      PAC_WRCTRL_KEY_SETLCK Set and lock protection
 **/
static inline void pac_write_WRCTRL(uint32_t data)
{
	PAC->WRCTRL.reg = data;
}

/**
 * @brief pac clear WRCTRL register
 *
 * @param[in] mask uint32_t 
 * - PAC_WRCTRL_PERID(value) Peripheral identifier
 * - PAC_WRCTRL_KEY(value) Peripheral access control key
 *  +      PAC_WRCTRL_KEY_OFF No action
 *  +      PAC_WRCTRL_KEY_CLR Clear protection
 *  +      PAC_WRCTRL_KEY_SET Set protection
 *  +      PAC_WRCTRL_KEY_SETLCK Set and lock protection
 **/
static inline void pac_clear_WRCTRL(uint32_t mask)
{
	PAC->WRCTRL.reg &= ~mask;
}

/**
 * @brief pac read WRCTRL register
 *
 * @return uint32_t
 * - PAC_WRCTRL_PERID(value) Peripheral identifier
 * - PAC_WRCTRL_KEY(value) Peripheral access control key
 *  +      PAC_WRCTRL_KEY_OFF No action
 *  +      PAC_WRCTRL_KEY_CLR Clear protection
 *  +      PAC_WRCTRL_KEY_SET Set protection
 *  +      PAC_WRCTRL_KEY_SETLCK Set and lock protection
 **/
static inline uint32_t pac_read_WRCTRL(void)
{
	return PAC->WRCTRL.reg;
}

/**
 * @brief pac set EVCTRL register
 *
 * @param[in] mask uint8_t 
 * - PAC_EVCTRL_ERREO Peripheral acess error event output
 **/
static inline void pac_set_EVCTRL(uint8_t mask)
{
	PAC->EVCTRL.reg |= mask;
}

/**
 * @brief pac get EVCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PAC_EVCTRL_ERREO Peripheral acess error event output
 **/
static inline uint8_t pac_get_EVCTRL(uint8_t mask)
{
    return PAC->EVCTRL.reg & mask;
}

/**
 * @brief pac write EVCTRL register
 *
 * @param[in] data uint8_t 
 * - PAC_EVCTRL_ERREO Peripheral acess error event output
 **/
static inline void pac_write_EVCTRL(uint8_t data)
{
	PAC->EVCTRL.reg = data;
}

/**
 * @brief pac clear EVCTRL register
 *
 * @param[in] mask uint8_t 
 * - PAC_EVCTRL_ERREO Peripheral acess error event output
 **/
static inline void pac_clear_EVCTRL(uint8_t mask)
{
	PAC->EVCTRL.reg &= ~mask;
}

/**
 * @brief pac read EVCTRL register
 *
 * @return uint8_t
 * - PAC_EVCTRL_ERREO Peripheral acess error event output
 **/
static inline uint8_t pac_read_EVCTRL(void)
{
	return PAC->EVCTRL.reg;
}

/**
 * @brief pac get STATUSA register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_STATUSA_PAC PAC APB Protect Enable
 * - PAC_STATUSA_PM PM APB Protect Enable
 * - PAC_STATUSA_MCLK MCLK APB Protect Enable
 * - PAC_STATUSA_RSTC RSTC APB Protect Enable
 * - PAC_STATUSA_OSCCTRL OSCCTRL APB Protect Enable
 * - PAC_STATUSA_OSC32KCTRL OSC32KCTRL APB Protect Enable
 * - PAC_STATUSA_SUPC SUPC APB Protect Enable
 * - PAC_STATUSA_GCLK GCLK APB Protect Enable
 * - PAC_STATUSA_WDT WDT APB Protect Enable
 * - PAC_STATUSA_RTC RTC APB Protect Enable
 * - PAC_STATUSA_EIC EIC APB Protect Enable
 * - PAC_STATUSA_FREQM FREQM APB Protect Enable
 * - PAC_STATUSA_SERCOM0 SERCOM0 APB Protect Enable
 * - PAC_STATUSA_SERCOM1 SERCOM1 APB Protect Enable
 * - PAC_STATUSA_TC0 TC0 APB Protect Enable
 * - PAC_STATUSA_TC1 TC1 APB Protect Enable
 **/
static inline uint32_t pac_get_STATUSA(uint32_t mask)
{
    return PAC->STATUSA.reg & mask;
}

/**
 * @brief pac read STATUSA register
 *
 * @return uint32_t
 * - PAC_STATUSA_PAC PAC APB Protect Enable
 * - PAC_STATUSA_PM PM APB Protect Enable
 * - PAC_STATUSA_MCLK MCLK APB Protect Enable
 * - PAC_STATUSA_RSTC RSTC APB Protect Enable
 * - PAC_STATUSA_OSCCTRL OSCCTRL APB Protect Enable
 * - PAC_STATUSA_OSC32KCTRL OSC32KCTRL APB Protect Enable
 * - PAC_STATUSA_SUPC SUPC APB Protect Enable
 * - PAC_STATUSA_GCLK GCLK APB Protect Enable
 * - PAC_STATUSA_WDT WDT APB Protect Enable
 * - PAC_STATUSA_RTC RTC APB Protect Enable
 * - PAC_STATUSA_EIC EIC APB Protect Enable
 * - PAC_STATUSA_FREQM FREQM APB Protect Enable
 * - PAC_STATUSA_SERCOM0 SERCOM0 APB Protect Enable
 * - PAC_STATUSA_SERCOM1 SERCOM1 APB Protect Enable
 * - PAC_STATUSA_TC0 TC0 APB Protect Enable
 * - PAC_STATUSA_TC1 TC1 APB Protect Enable
 **/
static inline uint32_t pac_read_STATUSA(void)
{
	return PAC->STATUSA.reg;
}

/**
 * @brief pac get STATUSB register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_STATUSB_USB USB APB Protect Enable
 * - PAC_STATUSB_DSU DSU APB Protect Enable
 * - PAC_STATUSB_NVMCTRL NVMCTRL APB Protect Enable
 * - PAC_STATUSB_CMCC CMCC APB Protect Enable
 * - PAC_STATUSB_PORT PORT APB Protect Enable
 * - PAC_STATUSB_DMAC DMAC APB Protect Enable
 * - PAC_STATUSB_HMATRIX HMATRIX APB Protect Enable
 * - PAC_STATUSB_EVSYS EVSYS APB Protect Enable
 * - PAC_STATUSB_SERCOM2 SERCOM2 APB Protect Enable
 * - PAC_STATUSB_SERCOM3 SERCOM3 APB Protect Enable
 * - PAC_STATUSB_TCC0 TCC0 APB Protect Enable
 * - PAC_STATUSB_TCC1 TCC1 APB Protect Enable
 * - PAC_STATUSB_TC2 TC2 APB Protect Enable
 * - PAC_STATUSB_TC3 TC3 APB Protect Enable
 * - PAC_STATUSB_TAL TAL APB Protect Enable
 * - PAC_STATUSB_RAMECC RAMECC APB Protect Enable
 **/
static inline uint32_t pac_get_STATUSB(uint32_t mask)
{
    return PAC->STATUSB.reg & mask;
}

/**
 * @brief pac read STATUSB register
 *
 * @return uint32_t
 * - PAC_STATUSB_USB USB APB Protect Enable
 * - PAC_STATUSB_DSU DSU APB Protect Enable
 * - PAC_STATUSB_NVMCTRL NVMCTRL APB Protect Enable
 * - PAC_STATUSB_CMCC CMCC APB Protect Enable
 * - PAC_STATUSB_PORT PORT APB Protect Enable
 * - PAC_STATUSB_DMAC DMAC APB Protect Enable
 * - PAC_STATUSB_HMATRIX HMATRIX APB Protect Enable
 * - PAC_STATUSB_EVSYS EVSYS APB Protect Enable
 * - PAC_STATUSB_SERCOM2 SERCOM2 APB Protect Enable
 * - PAC_STATUSB_SERCOM3 SERCOM3 APB Protect Enable
 * - PAC_STATUSB_TCC0 TCC0 APB Protect Enable
 * - PAC_STATUSB_TCC1 TCC1 APB Protect Enable
 * - PAC_STATUSB_TC2 TC2 APB Protect Enable
 * - PAC_STATUSB_TC3 TC3 APB Protect Enable
 * - PAC_STATUSB_TAL TAL APB Protect Enable
 * - PAC_STATUSB_RAMECC RAMECC APB Protect Enable
 **/
static inline uint32_t pac_read_STATUSB(void)
{
	return PAC->STATUSB.reg;
}

/**
 * @brief pac get STATUSC register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_STATUSC_TCC2 TCC2 APB Protect Enable
 * - PAC_STATUSC_TCC3 TCC3 APB Protect Enable
 * - PAC_STATUSC_TC4 TC4 APB Protect Enable
 * - PAC_STATUSC_TC5 TC5 APB Protect Enable
 * - PAC_STATUSC_PDEC PDEC APB Protect Enable
 * - PAC_STATUSC_AC AC APB Protect Enable
 * - PAC_STATUSC_AES AES APB Protect Enable
 * - PAC_STATUSC_TRNG TRNG APB Protect Enable
 * - PAC_STATUSC_ICM ICM APB Protect Enable
 * - PAC_STATUSC_PUKCC PUKCC APB Protect Enable
 * - PAC_STATUSC_QSPI QSPI APB Protect Enable
 * - PAC_STATUSC_CCL CCL APB Protect Enable
 **/
static inline uint32_t pac_get_STATUSC(uint32_t mask)
{
    return PAC->STATUSC.reg & mask;
}

/**
 * @brief pac read STATUSC register
 *
 * @return uint32_t
 * - PAC_STATUSC_TCC2 TCC2 APB Protect Enable
 * - PAC_STATUSC_TCC3 TCC3 APB Protect Enable
 * - PAC_STATUSC_TC4 TC4 APB Protect Enable
 * - PAC_STATUSC_TC5 TC5 APB Protect Enable
 * - PAC_STATUSC_PDEC PDEC APB Protect Enable
 * - PAC_STATUSC_AC AC APB Protect Enable
 * - PAC_STATUSC_AES AES APB Protect Enable
 * - PAC_STATUSC_TRNG TRNG APB Protect Enable
 * - PAC_STATUSC_ICM ICM APB Protect Enable
 * - PAC_STATUSC_PUKCC PUKCC APB Protect Enable
 * - PAC_STATUSC_QSPI QSPI APB Protect Enable
 * - PAC_STATUSC_CCL CCL APB Protect Enable
 **/
static inline uint32_t pac_read_STATUSC(void)
{
	return PAC->STATUSC.reg;
}

/**
 * @brief pac get STATUSD register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PAC_STATUSD_SERCOM4 SERCOM4 APB Protect Enable
 * - PAC_STATUSD_SERCOM5 SERCOM5 APB Protect Enable
 * - PAC_STATUSD_SERCOM6 SERCOM6 APB Protect Enable
 * - PAC_STATUSD_SERCOM7 SERCOM7 APB Protect Enable
 * - PAC_STATUSD_TCC4 TCC4 APB Protect Enable
 * - PAC_STATUSD_TC6 TC6 APB Protect Enable
 * - PAC_STATUSD_TC7 TC7 APB Protect Enable
 * - PAC_STATUSD_ADC0 ADC0 APB Protect Enable
 * - PAC_STATUSD_ADC1 ADC1 APB Protect Enable
 * - PAC_STATUSD_DAC DAC APB Protect Enable
 * - PAC_STATUSD_I2S I2S APB Protect Enable
 * - PAC_STATUSD_PCC PCC APB Protect Enable
 **/
static inline uint32_t pac_get_STATUSD(uint32_t mask)
{
    return PAC->STATUSD.reg & mask;
}

/**
 * @brief pac read STATUSD register
 *
 * @return uint32_t
 * - PAC_STATUSD_SERCOM4 SERCOM4 APB Protect Enable
 * - PAC_STATUSD_SERCOM5 SERCOM5 APB Protect Enable
 * - PAC_STATUSD_SERCOM6 SERCOM6 APB Protect Enable
 * - PAC_STATUSD_SERCOM7 SERCOM7 APB Protect Enable
 * - PAC_STATUSD_TCC4 TCC4 APB Protect Enable
 * - PAC_STATUSD_TC6 TC6 APB Protect Enable
 * - PAC_STATUSD_TC7 TC7 APB Protect Enable
 * - PAC_STATUSD_ADC0 ADC0 APB Protect Enable
 * - PAC_STATUSD_ADC1 ADC1 APB Protect Enable
 * - PAC_STATUSD_DAC DAC APB Protect Enable
 * - PAC_STATUSD_I2S I2S APB Protect Enable
 * - PAC_STATUSD_PCC PCC APB Protect Enable
 **/
static inline uint32_t pac_read_STATUSD(void)
{
	return PAC->STATUSD.reg;
}

#endif /* _PAC_H */
