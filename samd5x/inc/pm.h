/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM PM
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

#ifndef _PM_H_
#define _PM_H_

#include <stdbool.h>

/**
 * @brief pm set INTEN register
 *
 * @param[in] mask uint8_t 
 * - PM_INTENSET_SLEEPRDY Sleep Mode Entry Ready Enable
 **/
static inline void pm_set_INTEN(uint8_t mask)
{
	PM->INTENSET.reg = mask;
}

/**
 * @brief pm get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PM_INTENSET_SLEEPRDY Sleep Mode Entry Ready Enable
 **/
static inline uint8_t pm_get_INTEN(uint8_t mask)
{
    return PM->INTENSET.reg & mask;
}

/**
 * @brief pm read INTEN register
 *
 * @return uint8_t
 * - PM_INTENSET_SLEEPRDY Sleep Mode Entry Ready Enable
 **/
static inline uint8_t pm_read_INTEN(void)
{
	return PM->INTENSET.reg;
}

/**
 * @brief pm write INTEN register
 *
 * @param[in] data uint8_t 
 * - PM_INTENSET_SLEEPRDY Sleep Mode Entry Ready Enable
 **/
static inline void pm_write_INTEN(uint8_t data)
{
	PM->INTENSET.reg = data;
	PM->INTENCLR.reg = ~data;
}

/**
 * @brief pm clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - PM_INTENSET_SLEEPRDY Sleep Mode Entry Ready Enable
 **/
static inline void pm_clear_INTEN(uint8_t mask)
{
	PM->INTENCLR.reg = mask;
}

/**
 * @brief pm get INTFLAG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PM_INTFLAG_SLEEPRDY Sleep Mode Entry Ready
 **/
static inline uint8_t pm_get_INTFLAG(uint8_t mask)
{
    return PM->INTFLAG.reg & mask;
}

/**
 * @brief pm read INTFLAG register
 *
 * @return uint8_t
 * - PM_INTFLAG_SLEEPRDY Sleep Mode Entry Ready
 **/
static inline uint8_t pm_read_INTFLAG(void)
{
	return PM->INTFLAG.reg;
}

/**
 * @brief pm clear INTFLAG register
 *
 * @param[in] mask uint8_t 
 * - PM_INTFLAG_SLEEPRDY Sleep Mode Entry Ready
 **/
static inline void pm_clear_INTFLAG(uint8_t mask)
{
	PM->INTFLAG.reg = mask;
}

/**
 * @brief pm set CTRLA register
 *
 * @param[in] mask uint8_t 
 * - PM_CTRLA_IORET I/O Retention
 **/
static inline void pm_set_CTRLA(uint8_t mask)
{
	PM->CTRLA.reg |= mask;
}

/**
 * @brief pm get CTRLA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PM_CTRLA_IORET I/O Retention
 **/
static inline uint8_t pm_get_CTRLA(uint8_t mask)
{
    return PM->CTRLA.reg & mask;
}

/**
 * @brief pm write CTRLA register
 *
 * @param[in] data uint8_t 
 * - PM_CTRLA_IORET I/O Retention
 **/
static inline void pm_write_CTRLA(uint8_t data)
{
	PM->CTRLA.reg = data;
}

/**
 * @brief pm clear CTRLA register
 *
 * @param[in] mask uint8_t 
 * - PM_CTRLA_IORET I/O Retention
 **/
static inline void pm_clear_CTRLA(uint8_t mask)
{
	PM->CTRLA.reg &= ~mask;
}

/**
 * @brief pm read CTRLA register
 *
 * @return uint8_t
 * - PM_CTRLA_IORET I/O Retention
 **/
static inline uint8_t pm_read_CTRLA(void)
{
	return PM->CTRLA.reg;
}

/**
 * @brief pm set SLEEPCFG register
 *
 * @param[in] mask uint8_t 
 * - PM_SLEEPCFG_SLEEPMODE(value) Sleep Mode
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE0 CPU clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE1 AHB clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE2 APB clock are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_STANDBY All Clocks are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_HIBERNATE Backup domain is ON as well as some PDRAMs
 *  +      PM_SLEEPCFG_SLEEPMODE_BACKUP Only Backup domain is powered ON
 *  +      PM_SLEEPCFG_SLEEPMODE_OFF All power domains are powered OFF
 **/
static inline void pm_set_SLEEPCFG(uint8_t mask)
{
	PM->SLEEPCFG.reg |= mask;
}

/**
 * @brief pm get SLEEPCFG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PM_SLEEPCFG_SLEEPMODE(value) Sleep Mode
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE0 CPU clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE1 AHB clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE2 APB clock are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_STANDBY All Clocks are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_HIBERNATE Backup domain is ON as well as some PDRAMs
 *  +      PM_SLEEPCFG_SLEEPMODE_BACKUP Only Backup domain is powered ON
 *  +      PM_SLEEPCFG_SLEEPMODE_OFF All power domains are powered OFF
 **/
static inline uint8_t pm_get_SLEEPCFG(uint8_t mask)
{
    return PM->SLEEPCFG.reg & mask;
}

/**
 * @brief pm write SLEEPCFG register
 *
 * @param[in] data uint8_t 
 * - PM_SLEEPCFG_SLEEPMODE(value) Sleep Mode
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE0 CPU clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE1 AHB clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE2 APB clock are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_STANDBY All Clocks are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_HIBERNATE Backup domain is ON as well as some PDRAMs
 *  +      PM_SLEEPCFG_SLEEPMODE_BACKUP Only Backup domain is powered ON
 *  +      PM_SLEEPCFG_SLEEPMODE_OFF All power domains are powered OFF
 **/
static inline void pm_write_SLEEPCFG(uint8_t data)
{
	PM->SLEEPCFG.reg = data;
}

/**
 * @brief pm clear SLEEPCFG register
 *
 * @param[in] mask uint8_t 
 * - PM_SLEEPCFG_SLEEPMODE(value) Sleep Mode
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE0 CPU clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE1 AHB clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE2 APB clock are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_STANDBY All Clocks are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_HIBERNATE Backup domain is ON as well as some PDRAMs
 *  +      PM_SLEEPCFG_SLEEPMODE_BACKUP Only Backup domain is powered ON
 *  +      PM_SLEEPCFG_SLEEPMODE_OFF All power domains are powered OFF
 **/
static inline void pm_clear_SLEEPCFG(uint8_t mask)
{
	PM->SLEEPCFG.reg &= ~mask;
}

/**
 * @brief pm read SLEEPCFG register
 *
 * @return uint8_t
 * - PM_SLEEPCFG_SLEEPMODE(value) Sleep Mode
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE0 CPU clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE1 AHB clock is OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_IDLE2 APB clock are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_STANDBY All Clocks are OFF
 *  +      PM_SLEEPCFG_SLEEPMODE_HIBERNATE Backup domain is ON as well as some PDRAMs
 *  +      PM_SLEEPCFG_SLEEPMODE_BACKUP Only Backup domain is powered ON
 *  +      PM_SLEEPCFG_SLEEPMODE_OFF All power domains are powered OFF
 **/
static inline uint8_t pm_read_SLEEPCFG(void)
{
	return PM->SLEEPCFG.reg;
}

/**
 * @brief pm set STDBYCFG register
 *
 * @param[in] mask uint8_t 
 * - PM_STDBYCFG_RAMCFG(value) Ram Configuration
 *  +      PM_STDBYCFG_RAMCFG_RET All the RAMs are retained
 *  +      PM_STDBYCFG_RAMCFG_PARTIAL Only the first 32K bytes are retained
 *  +      PM_STDBYCFG_RAMCFG_OFF All the RAMs are OFF
 * - PM_STDBYCFG_FASTWKUP(value) Fast Wakeup
 **/
static inline void pm_set_STDBYCFG(uint8_t mask)
{
	PM->STDBYCFG.reg |= mask;
}

/**
 * @brief pm get STDBYCFG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PM_STDBYCFG_RAMCFG(value) Ram Configuration
 *  +      PM_STDBYCFG_RAMCFG_RET All the RAMs are retained
 *  +      PM_STDBYCFG_RAMCFG_PARTIAL Only the first 32K bytes are retained
 *  +      PM_STDBYCFG_RAMCFG_OFF All the RAMs are OFF
 * - PM_STDBYCFG_FASTWKUP(value) Fast Wakeup
 **/
static inline uint8_t pm_get_STDBYCFG(uint8_t mask)
{
    return PM->STDBYCFG.reg & mask;
}

/**
 * @brief pm write STDBYCFG register
 *
 * @param[in] data uint8_t 
 * - PM_STDBYCFG_RAMCFG(value) Ram Configuration
 *  +      PM_STDBYCFG_RAMCFG_RET All the RAMs are retained
 *  +      PM_STDBYCFG_RAMCFG_PARTIAL Only the first 32K bytes are retained
 *  +      PM_STDBYCFG_RAMCFG_OFF All the RAMs are OFF
 * - PM_STDBYCFG_FASTWKUP(value) Fast Wakeup
 **/
static inline void pm_write_STDBYCFG(uint8_t data)
{
	PM->STDBYCFG.reg = data;
}

/**
 * @brief pm clear STDBYCFG register
 *
 * @param[in] mask uint8_t 
 * - PM_STDBYCFG_RAMCFG(value) Ram Configuration
 *  +      PM_STDBYCFG_RAMCFG_RET All the RAMs are retained
 *  +      PM_STDBYCFG_RAMCFG_PARTIAL Only the first 32K bytes are retained
 *  +      PM_STDBYCFG_RAMCFG_OFF All the RAMs are OFF
 * - PM_STDBYCFG_FASTWKUP(value) Fast Wakeup
 **/
static inline void pm_clear_STDBYCFG(uint8_t mask)
{
	PM->STDBYCFG.reg &= ~mask;
}

/**
 * @brief pm read STDBYCFG register
 *
 * @return uint8_t
 * - PM_STDBYCFG_RAMCFG(value) Ram Configuration
 *  +      PM_STDBYCFG_RAMCFG_RET All the RAMs are retained
 *  +      PM_STDBYCFG_RAMCFG_PARTIAL Only the first 32K bytes are retained
 *  +      PM_STDBYCFG_RAMCFG_OFF All the RAMs are OFF
 * - PM_STDBYCFG_FASTWKUP(value) Fast Wakeup
 **/
static inline uint8_t pm_read_STDBYCFG(void)
{
	return PM->STDBYCFG.reg;
}

/**
 * @brief pm set HIBCFG register
 *
 * @param[in] mask uint8_t 
 * - PM_HIBCFG_RAMCFG(value) Ram Configuration
 * - PM_HIBCFG_BRAMCFG(value) Backup Ram Configuration
 **/
static inline void pm_set_HIBCFG(uint8_t mask)
{
	PM->HIBCFG.reg |= mask;
}

/**
 * @brief pm get HIBCFG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PM_HIBCFG_RAMCFG(value) Ram Configuration
 * - PM_HIBCFG_BRAMCFG(value) Backup Ram Configuration
 **/
static inline uint8_t pm_get_HIBCFG(uint8_t mask)
{
    return PM->HIBCFG.reg & mask;
}

/**
 * @brief pm write HIBCFG register
 *
 * @param[in] data uint8_t 
 * - PM_HIBCFG_RAMCFG(value) Ram Configuration
 * - PM_HIBCFG_BRAMCFG(value) Backup Ram Configuration
 **/
static inline void pm_write_HIBCFG(uint8_t data)
{
	PM->HIBCFG.reg = data;
}

/**
 * @brief pm clear HIBCFG register
 *
 * @param[in] mask uint8_t 
 * - PM_HIBCFG_RAMCFG(value) Ram Configuration
 * - PM_HIBCFG_BRAMCFG(value) Backup Ram Configuration
 **/
static inline void pm_clear_HIBCFG(uint8_t mask)
{
	PM->HIBCFG.reg &= ~mask;
}

/**
 * @brief pm read HIBCFG register
 *
 * @return uint8_t
 * - PM_HIBCFG_RAMCFG(value) Ram Configuration
 * - PM_HIBCFG_BRAMCFG(value) Backup Ram Configuration
 **/
static inline uint8_t pm_read_HIBCFG(void)
{
	return PM->HIBCFG.reg;
}

/**
 * @brief pm set BKUPCFG register
 *
 * @param[in] mask uint8_t 
 * - PM_BKUPCFG_BRAMCFG(value) Ram Configuration
 **/
static inline void pm_set_BKUPCFG(uint8_t mask)
{
	PM->BKUPCFG.reg |= mask;
}

/**
 * @brief pm get BKUPCFG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PM_BKUPCFG_BRAMCFG(value) Ram Configuration
 **/
static inline uint8_t pm_get_BKUPCFG(uint8_t mask)
{
    return PM->BKUPCFG.reg & mask;
}

/**
 * @brief pm write BKUPCFG register
 *
 * @param[in] data uint8_t 
 * - PM_BKUPCFG_BRAMCFG(value) Ram Configuration
 **/
static inline void pm_write_BKUPCFG(uint8_t data)
{
	PM->BKUPCFG.reg = data;
}

/**
 * @brief pm clear BKUPCFG register
 *
 * @param[in] mask uint8_t 
 * - PM_BKUPCFG_BRAMCFG(value) Ram Configuration
 **/
static inline void pm_clear_BKUPCFG(uint8_t mask)
{
	PM->BKUPCFG.reg &= ~mask;
}

/**
 * @brief pm read BKUPCFG register
 *
 * @return uint8_t
 * - PM_BKUPCFG_BRAMCFG(value) Ram Configuration
 **/
static inline uint8_t pm_read_BKUPCFG(void)
{
	return PM->BKUPCFG.reg;
}

/**
 * @brief pm set PWSAKDLY register
 *
 * @param[in] mask uint8_t 
 * - PM_PWSAKDLY_DLYVAL(value) Delay Value
 * - PM_PWSAKDLY_IGNACK Ignore Acknowledge
 **/
static inline void pm_set_PWSAKDLY(uint8_t mask)
{
	PM->PWSAKDLY.reg |= mask;
}

/**
 * @brief pm get PWSAKDLY register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PM_PWSAKDLY_DLYVAL(value) Delay Value
 * - PM_PWSAKDLY_IGNACK Ignore Acknowledge
 **/
static inline uint8_t pm_get_PWSAKDLY(uint8_t mask)
{
    return PM->PWSAKDLY.reg & mask;
}

/**
 * @brief pm write PWSAKDLY register
 *
 * @param[in] data uint8_t 
 * - PM_PWSAKDLY_DLYVAL(value) Delay Value
 * - PM_PWSAKDLY_IGNACK Ignore Acknowledge
 **/
static inline void pm_write_PWSAKDLY(uint8_t data)
{
	PM->PWSAKDLY.reg = data;
}

/**
 * @brief pm clear PWSAKDLY register
 *
 * @param[in] mask uint8_t 
 * - PM_PWSAKDLY_DLYVAL(value) Delay Value
 * - PM_PWSAKDLY_IGNACK Ignore Acknowledge
 **/
static inline void pm_clear_PWSAKDLY(uint8_t mask)
{
	PM->PWSAKDLY.reg &= ~mask;
}

/**
 * @brief pm read PWSAKDLY register
 *
 * @return uint8_t
 * - PM_PWSAKDLY_DLYVAL(value) Delay Value
 * - PM_PWSAKDLY_IGNACK Ignore Acknowledge
 **/
static inline uint8_t pm_read_PWSAKDLY(void)
{
	return PM->PWSAKDLY.reg;
}

#endif /* _PM_H */
