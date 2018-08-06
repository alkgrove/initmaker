/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM OSCCTRL
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

#ifndef _OSCCTRL_H_
#define _OSCCTRL_H_

#include <stdbool.h>

/* from Table 28-7 in datasheet
 * used in OSCCTRL_XOSCCTRL_IPTAT, OSCCTRL_XOSCCTRL_IMULT and OSCCTRL_XOSCCTRL_CFDPRESC
 */
#define XOSC_IMULT(f) (f>=32000000 ? 7 : (f>=24000000 ? 6 : (f>=16000000 ? 5 : 4)))
#define XOSC_IPTAT(f) 3
#define XOSC_CFDPRESC(f) (f>=32000000 ? 0 : (f>=24000000 ? 1 : (f>=16000000 ? 2 : 3)))
/*
 * Index for DPLLxxxx 
 */
#define DPLL0	0 
#define DPLL1	1

/**
 * @brief oscctrl set DPLLCTRLA register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - OSCCTRL_DPLLCTRLA_ENABLE DPLL Enable
 * - OSCCTRL_DPLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DPLLCTRLA_ONDEMAND On Demand Control
 **/
static inline void oscctrl_set_DPLLCTRLA(uint8_t submodule_index, uint8_t mask)
{
	OSCCTRL->Dpll[submodule_index].DPLLCTRLA.reg |= mask;
}

/**
 * @brief oscctrl get DPLLCTRLA register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - OSCCTRL_DPLLCTRLA_ENABLE DPLL Enable
 * - OSCCTRL_DPLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DPLLCTRLA_ONDEMAND On Demand Control
 **/
static inline uint8_t oscctrl_get_DPLLCTRLA(uint8_t submodule_index, uint8_t mask)
{
    return OSCCTRL->Dpll[submodule_index].DPLLCTRLA.reg & mask;
}

/**
 * @brief oscctrl write DPLLCTRLA register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint8_t 
 * - OSCCTRL_DPLLCTRLA_ENABLE DPLL Enable
 * - OSCCTRL_DPLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DPLLCTRLA_ONDEMAND On Demand Control
 **/
static inline void oscctrl_write_DPLLCTRLA(uint8_t submodule_index, uint8_t data)
{
	OSCCTRL->Dpll[submodule_index].DPLLCTRLA.reg = data;
}

/**
 * @brief oscctrl clear DPLLCTRLA register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - OSCCTRL_DPLLCTRLA_ENABLE DPLL Enable
 * - OSCCTRL_DPLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DPLLCTRLA_ONDEMAND On Demand Control
 **/
static inline void oscctrl_clear_DPLLCTRLA(uint8_t submodule_index, uint8_t mask)
{
	OSCCTRL->Dpll[submodule_index].DPLLCTRLA.reg &= ~mask;
}

/**
 * @brief oscctrl read DPLLCTRLA register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint8_t
 * - OSCCTRL_DPLLCTRLA_ENABLE DPLL Enable
 * - OSCCTRL_DPLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DPLLCTRLA_ONDEMAND On Demand Control
 **/
static inline uint8_t oscctrl_read_DPLLCTRLA(uint8_t submodule_index)
{
	return OSCCTRL->Dpll[submodule_index].DPLLCTRLA.reg;
}

/**
 * @brief oscctrl write DPLLRATIO register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint32_t 
 * - OSCCTRL_DPLLRATIO_LDR(value) Loop Divider Ratio
 * - OSCCTRL_DPLLRATIO_LDRFRAC(value) Loop Divider Ratio Fractional Part
 **/
static inline void oscctrl_write_DPLLRATIO(uint8_t submodule_index, uint32_t data)
{
	OSCCTRL->Dpll[submodule_index].DPLLRATIO.reg = data;
}

/**
 * @brief oscctrl read DPLLRATIO register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint32_t
 * - OSCCTRL_DPLLRATIO_LDR(value) Loop Divider Ratio
 * - OSCCTRL_DPLLRATIO_LDRFRAC(value) Loop Divider Ratio Fractional Part
 **/
static inline uint32_t oscctrl_read_DPLLRATIO(uint8_t submodule_index)
{
	return OSCCTRL->Dpll[submodule_index].DPLLRATIO.reg;
}

/**
 * @brief oscctrl set DPLLCTRLB register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * - OSCCTRL_DPLLCTRLB_FILTER(value) Proportional Integral Filter Selection
 * - OSCCTRL_DPLLCTRLB_WUF Wake Up Fast
 * - OSCCTRL_DPLLCTRLB_REFCLK(value) Reference Clock Selection
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_GCLK Dedicated GCLK clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC32 XOSC32K clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC0 XOSC0 clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC1 XOSC1 clock reference
 * - OSCCTRL_DPLLCTRLB_LTIME(value) Lock Time
 *  +      OSCCTRL_DPLLCTRLB_LTIME_DEFAULT No time-out. Automatic lock
 *  +      OSCCTRL_DPLLCTRLB_LTIME_800US Time-out if no lock within 800us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_900US Time-out if no lock within 900us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1MS Time-out if no lock within 1ms
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1P1MS Time-out if no lock within 1.1ms
 * - OSCCTRL_DPLLCTRLB_LBYPASS Lock Bypass
 * - OSCCTRL_DPLLCTRLB_DCOFILTER(value) Sigma-Delta DCO Filter Selection
 * - OSCCTRL_DPLLCTRLB_DCOEN DCO Filter Enable
 * - OSCCTRL_DPLLCTRLB_DIV(value) Clock Divider
 **/
static inline void oscctrl_set_DPLLCTRLB(uint8_t submodule_index, uint32_t mask)
{
	OSCCTRL->Dpll[submodule_index].DPLLCTRLB.reg |= mask;
}

/**
 * @brief oscctrl get DPLLCTRLB register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSCCTRL_DPLLCTRLB_FILTER(value) Proportional Integral Filter Selection
 * - OSCCTRL_DPLLCTRLB_WUF Wake Up Fast
 * - OSCCTRL_DPLLCTRLB_REFCLK(value) Reference Clock Selection
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_GCLK Dedicated GCLK clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC32 XOSC32K clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC0 XOSC0 clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC1 XOSC1 clock reference
 * - OSCCTRL_DPLLCTRLB_LTIME(value) Lock Time
 *  +      OSCCTRL_DPLLCTRLB_LTIME_DEFAULT No time-out. Automatic lock
 *  +      OSCCTRL_DPLLCTRLB_LTIME_800US Time-out if no lock within 800us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_900US Time-out if no lock within 900us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1MS Time-out if no lock within 1ms
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1P1MS Time-out if no lock within 1.1ms
 * - OSCCTRL_DPLLCTRLB_LBYPASS Lock Bypass
 * - OSCCTRL_DPLLCTRLB_DCOFILTER(value) Sigma-Delta DCO Filter Selection
 * - OSCCTRL_DPLLCTRLB_DCOEN DCO Filter Enable
 * - OSCCTRL_DPLLCTRLB_DIV(value) Clock Divider
 **/
static inline uint32_t oscctrl_get_DPLLCTRLB(uint8_t submodule_index, uint32_t mask)
{
    return OSCCTRL->Dpll[submodule_index].DPLLCTRLB.reg & mask;
}

/**
 * @brief oscctrl write DPLLCTRLB register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint32_t 
 * - OSCCTRL_DPLLCTRLB_FILTER(value) Proportional Integral Filter Selection
 * - OSCCTRL_DPLLCTRLB_WUF Wake Up Fast
 * - OSCCTRL_DPLLCTRLB_REFCLK(value) Reference Clock Selection
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_GCLK Dedicated GCLK clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC32 XOSC32K clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC0 XOSC0 clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC1 XOSC1 clock reference
 * - OSCCTRL_DPLLCTRLB_LTIME(value) Lock Time
 *  +      OSCCTRL_DPLLCTRLB_LTIME_DEFAULT No time-out. Automatic lock
 *  +      OSCCTRL_DPLLCTRLB_LTIME_800US Time-out if no lock within 800us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_900US Time-out if no lock within 900us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1MS Time-out if no lock within 1ms
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1P1MS Time-out if no lock within 1.1ms
 * - OSCCTRL_DPLLCTRLB_LBYPASS Lock Bypass
 * - OSCCTRL_DPLLCTRLB_DCOFILTER(value) Sigma-Delta DCO Filter Selection
 * - OSCCTRL_DPLLCTRLB_DCOEN DCO Filter Enable
 * - OSCCTRL_DPLLCTRLB_DIV(value) Clock Divider
 **/
static inline void oscctrl_write_DPLLCTRLB(uint8_t submodule_index, uint32_t data)
{
	OSCCTRL->Dpll[submodule_index].DPLLCTRLB.reg = data;
}

/**
 * @brief oscctrl clear DPLLCTRLB register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * - OSCCTRL_DPLLCTRLB_FILTER(value) Proportional Integral Filter Selection
 * - OSCCTRL_DPLLCTRLB_WUF Wake Up Fast
 * - OSCCTRL_DPLLCTRLB_REFCLK(value) Reference Clock Selection
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_GCLK Dedicated GCLK clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC32 XOSC32K clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC0 XOSC0 clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC1 XOSC1 clock reference
 * - OSCCTRL_DPLLCTRLB_LTIME(value) Lock Time
 *  +      OSCCTRL_DPLLCTRLB_LTIME_DEFAULT No time-out. Automatic lock
 *  +      OSCCTRL_DPLLCTRLB_LTIME_800US Time-out if no lock within 800us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_900US Time-out if no lock within 900us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1MS Time-out if no lock within 1ms
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1P1MS Time-out if no lock within 1.1ms
 * - OSCCTRL_DPLLCTRLB_LBYPASS Lock Bypass
 * - OSCCTRL_DPLLCTRLB_DCOFILTER(value) Sigma-Delta DCO Filter Selection
 * - OSCCTRL_DPLLCTRLB_DCOEN DCO Filter Enable
 * - OSCCTRL_DPLLCTRLB_DIV(value) Clock Divider
 **/
static inline void oscctrl_clear_DPLLCTRLB(uint8_t submodule_index, uint32_t mask)
{
	OSCCTRL->Dpll[submodule_index].DPLLCTRLB.reg &= ~mask;
}

/**
 * @brief oscctrl read DPLLCTRLB register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint32_t
 * - OSCCTRL_DPLLCTRLB_FILTER(value) Proportional Integral Filter Selection
 * - OSCCTRL_DPLLCTRLB_WUF Wake Up Fast
 * - OSCCTRL_DPLLCTRLB_REFCLK(value) Reference Clock Selection
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_GCLK Dedicated GCLK clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC32 XOSC32K clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC0 XOSC0 clock reference
 *  +      OSCCTRL_DPLLCTRLB_REFCLK_XOSC1 XOSC1 clock reference
 * - OSCCTRL_DPLLCTRLB_LTIME(value) Lock Time
 *  +      OSCCTRL_DPLLCTRLB_LTIME_DEFAULT No time-out. Automatic lock
 *  +      OSCCTRL_DPLLCTRLB_LTIME_800US Time-out if no lock within 800us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_900US Time-out if no lock within 900us
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1MS Time-out if no lock within 1ms
 *  +      OSCCTRL_DPLLCTRLB_LTIME_1P1MS Time-out if no lock within 1.1ms
 * - OSCCTRL_DPLLCTRLB_LBYPASS Lock Bypass
 * - OSCCTRL_DPLLCTRLB_DCOFILTER(value) Sigma-Delta DCO Filter Selection
 * - OSCCTRL_DPLLCTRLB_DCOEN DCO Filter Enable
 * - OSCCTRL_DPLLCTRLB_DIV(value) Clock Divider
 **/
static inline uint32_t oscctrl_read_DPLLCTRLB(uint8_t submodule_index)
{
	return OSCCTRL->Dpll[submodule_index].DPLLCTRLB.reg;
}
/**
 * @brief oscctrl get DPLLSYNCBUSY register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSCCTRL_DPLLSYNCBUSY_ENABLE DPLL Enable Synchronization Status
 * - OSCCTRL_DPLLSYNCBUSY_DPLLRATIO DPLL Loop Divider Ratio Synchronization Status
 **/
static inline uint32_t oscctrl_get_DPLLSYNCBUSY(uint8_t submodule_index, uint32_t mask)
{
    return OSCCTRL->Dpll[submodule_index].DPLLSYNCBUSY.reg & mask;
}

/**
 * @brief oscctrl read DPLLSYNCBUSY register
 *
 * @param[in] submodule_index uint8_t           
 * @return uint32_t
 * - OSCCTRL_DPLLSYNCBUSY_ENABLE DPLL Enable Synchronization Status
 * - OSCCTRL_DPLLSYNCBUSY_DPLLRATIO DPLL Loop Divider Ratio Synchronization Status
 **/
static inline uint32_t oscctrl_read_DPLLSYNCBUSY(uint8_t           submodule_index)
{
	return OSCCTRL->Dpll[submodule_index].DPLLSYNCBUSY.reg;
}

/**
 * @brief oscctrl get DPLLSTATUS register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSCCTRL_DPLLSTATUS_LOCK DPLL Lock Status
 * - OSCCTRL_DPLLSTATUS_CLKRDY DPLL Clock Ready
 **/
static inline uint32_t oscctrl_get_DPLLSTATUS(uint8_t submodule_index, uint32_t mask)
{
    return OSCCTRL->Dpll[submodule_index].DPLLSTATUS.reg & mask;
}

/**
 * @brief oscctrl read DPLLSTATUS register
 *
 * @param[in] submodule_index uint8_t           
 * @return uint32_t
 * - OSCCTRL_DPLLSTATUS_LOCK DPLL Lock Status
 * - OSCCTRL_DPLLSTATUS_CLKRDY DPLL Clock Ready
 **/
static inline uint32_t oscctrl_read_DPLLSTATUS(uint8_t           submodule_index)
{
	return OSCCTRL->Dpll[submodule_index].DPLLSTATUS.reg;
}

/**
 * @brief oscctrl set INTEN register
 *
 * @param[in] mask uint32_t 
 * - OSCCTRL_INTENSET_XOSCRDY0 XOSC 0 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY1 XOSC 1 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY(value) XOSC x Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL0 XOSC 0 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL1 XOSC 1 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL(value) XOSC x Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRDY DFLL Ready Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLOOB DFLL Out Of Bounds Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKF DFLL Lock Fine Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKC DFLL Lock Coarse Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRCS DFLL Reference Clock Stopped Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKR DPLL0 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKF DPLL0 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LTO DPLL0 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKR DPLL1 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKF DPLL1 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LTO DPLL1 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete Interrupt Enable
 **/
static inline void oscctrl_set_INTEN(uint32_t mask)
{
	OSCCTRL->INTENSET.reg = mask;
}

/**
 * @brief oscctrl get INTEN register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSCCTRL_INTENSET_XOSCRDY0 XOSC 0 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY1 XOSC 1 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY(value) XOSC x Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL0 XOSC 0 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL1 XOSC 1 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL(value) XOSC x Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRDY DFLL Ready Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLOOB DFLL Out Of Bounds Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKF DFLL Lock Fine Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKC DFLL Lock Coarse Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRCS DFLL Reference Clock Stopped Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKR DPLL0 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKF DPLL0 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LTO DPLL0 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKR DPLL1 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKF DPLL1 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LTO DPLL1 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete Interrupt Enable
 **/
static inline uint32_t oscctrl_get_INTEN(uint32_t mask)
{
    return OSCCTRL->INTENSET.reg & mask;
}

/**
 * @brief oscctrl read INTEN register
 *
 * @return uint32_t
 * - OSCCTRL_INTENSET_XOSCRDY0 XOSC 0 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY1 XOSC 1 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY(value) XOSC x Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL0 XOSC 0 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL1 XOSC 1 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL(value) XOSC x Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRDY DFLL Ready Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLOOB DFLL Out Of Bounds Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKF DFLL Lock Fine Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKC DFLL Lock Coarse Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRCS DFLL Reference Clock Stopped Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKR DPLL0 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKF DPLL0 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LTO DPLL0 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKR DPLL1 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKF DPLL1 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LTO DPLL1 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete Interrupt Enable
 **/
static inline uint32_t oscctrl_read_INTEN(void)
{
	return OSCCTRL->INTENSET.reg;
}

/**
 * @brief oscctrl write INTEN register
 *
 * @param[in] data uint32_t 
 * - OSCCTRL_INTENSET_XOSCRDY0 XOSC 0 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY1 XOSC 1 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY(value) XOSC x Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL0 XOSC 0 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL1 XOSC 1 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL(value) XOSC x Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRDY DFLL Ready Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLOOB DFLL Out Of Bounds Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKF DFLL Lock Fine Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKC DFLL Lock Coarse Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRCS DFLL Reference Clock Stopped Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKR DPLL0 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKF DPLL0 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LTO DPLL0 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKR DPLL1 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKF DPLL1 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LTO DPLL1 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete Interrupt Enable
 **/
static inline void oscctrl_write_INTEN(uint32_t data)
{
	OSCCTRL->INTENSET.reg = data;
	OSCCTRL->INTENCLR.reg = ~data;
}

/**
 * @brief oscctrl clear INTEN register
 *
 * @param[in] mask uint32_t 
 * - OSCCTRL_INTENSET_XOSCRDY0 XOSC 0 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY1 XOSC 1 Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCRDY(value) XOSC x Ready Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL0 XOSC 0 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL1 XOSC 1 Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_XOSCFAIL(value) XOSC x Clock Failure Detector Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRDY DFLL Ready Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLOOB DFLL Out Of Bounds Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKF DFLL Lock Fine Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLLCKC DFLL Lock Coarse Interrupt Enable
 * - OSCCTRL_INTENSET_DFLLRCS DFLL Reference Clock Stopped Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKR DPLL0 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LCKF DPLL0 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LTO DPLL0 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKR DPLL1 Lock Rise Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LCKF DPLL1 Lock Fall Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LTO DPLL1 Lock Timeout Interrupt Enable
 * - OSCCTRL_INTENSET_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete Interrupt Enable
 **/
static inline void oscctrl_clear_INTEN(uint32_t mask)
{
	OSCCTRL->INTENCLR.reg = mask;
}

/**
 * @brief oscctrl get INTFLAG register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSCCTRL_INTFLAG_XOSCRDY0 XOSC 0 Ready
 * - OSCCTRL_INTFLAG_XOSCRDY1 XOSC 1 Ready
 * - OSCCTRL_INTFLAG_XOSCRDY(value) XOSC x Ready
 * - OSCCTRL_INTFLAG_XOSCFAIL0 XOSC 0 Clock Failure Detector
 * - OSCCTRL_INTFLAG_XOSCFAIL1 XOSC 1 Clock Failure Detector
 * - OSCCTRL_INTFLAG_XOSCFAIL(value) XOSC x Clock Failure Detector
 * - OSCCTRL_INTFLAG_DFLLRDY DFLL Ready
 * - OSCCTRL_INTFLAG_DFLLOOB DFLL Out Of Bounds
 * - OSCCTRL_INTFLAG_DFLLLCKF DFLL Lock Fine
 * - OSCCTRL_INTFLAG_DFLLLCKC DFLL Lock Coarse
 * - OSCCTRL_INTFLAG_DFLLRCS DFLL Reference Clock Stopped
 * - OSCCTRL_INTFLAG_DPLL0LCKR DPLL0 Lock Rise
 * - OSCCTRL_INTFLAG_DPLL0LCKF DPLL0 Lock Fall
 * - OSCCTRL_INTFLAG_DPLL0LTO DPLL0 Lock Timeout
 * - OSCCTRL_INTFLAG_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete
 * - OSCCTRL_INTFLAG_DPLL1LCKR DPLL1 Lock Rise
 * - OSCCTRL_INTFLAG_DPLL1LCKF DPLL1 Lock Fall
 * - OSCCTRL_INTFLAG_DPLL1LTO DPLL1 Lock Timeout
 * - OSCCTRL_INTFLAG_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete
 **/
static inline uint32_t oscctrl_get_INTFLAG(uint32_t mask)
{
    return OSCCTRL->INTFLAG.reg & mask;
}

/**
 * @brief oscctrl read INTFLAG register
 *
 * @return uint32_t
 * - OSCCTRL_INTFLAG_XOSCRDY0 XOSC 0 Ready
 * - OSCCTRL_INTFLAG_XOSCRDY1 XOSC 1 Ready
 * - OSCCTRL_INTFLAG_XOSCRDY(value) XOSC x Ready
 * - OSCCTRL_INTFLAG_XOSCFAIL0 XOSC 0 Clock Failure Detector
 * - OSCCTRL_INTFLAG_XOSCFAIL1 XOSC 1 Clock Failure Detector
 * - OSCCTRL_INTFLAG_XOSCFAIL(value) XOSC x Clock Failure Detector
 * - OSCCTRL_INTFLAG_DFLLRDY DFLL Ready
 * - OSCCTRL_INTFLAG_DFLLOOB DFLL Out Of Bounds
 * - OSCCTRL_INTFLAG_DFLLLCKF DFLL Lock Fine
 * - OSCCTRL_INTFLAG_DFLLLCKC DFLL Lock Coarse
 * - OSCCTRL_INTFLAG_DFLLRCS DFLL Reference Clock Stopped
 * - OSCCTRL_INTFLAG_DPLL0LCKR DPLL0 Lock Rise
 * - OSCCTRL_INTFLAG_DPLL0LCKF DPLL0 Lock Fall
 * - OSCCTRL_INTFLAG_DPLL0LTO DPLL0 Lock Timeout
 * - OSCCTRL_INTFLAG_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete
 * - OSCCTRL_INTFLAG_DPLL1LCKR DPLL1 Lock Rise
 * - OSCCTRL_INTFLAG_DPLL1LCKF DPLL1 Lock Fall
 * - OSCCTRL_INTFLAG_DPLL1LTO DPLL1 Lock Timeout
 * - OSCCTRL_INTFLAG_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete
 **/
static inline uint32_t oscctrl_read_INTFLAG(void)
{
	return OSCCTRL->INTFLAG.reg;
}

/**
 * @brief oscctrl clear INTFLAG register
 *
 * @param[in] mask uint32_t 
 * - OSCCTRL_INTFLAG_XOSCRDY0 XOSC 0 Ready
 * - OSCCTRL_INTFLAG_XOSCRDY1 XOSC 1 Ready
 * - OSCCTRL_INTFLAG_XOSCRDY(value) XOSC x Ready
 * - OSCCTRL_INTFLAG_XOSCFAIL0 XOSC 0 Clock Failure Detector
 * - OSCCTRL_INTFLAG_XOSCFAIL1 XOSC 1 Clock Failure Detector
 * - OSCCTRL_INTFLAG_XOSCFAIL(value) XOSC x Clock Failure Detector
 * - OSCCTRL_INTFLAG_DFLLRDY DFLL Ready
 * - OSCCTRL_INTFLAG_DFLLOOB DFLL Out Of Bounds
 * - OSCCTRL_INTFLAG_DFLLLCKF DFLL Lock Fine
 * - OSCCTRL_INTFLAG_DFLLLCKC DFLL Lock Coarse
 * - OSCCTRL_INTFLAG_DFLLRCS DFLL Reference Clock Stopped
 * - OSCCTRL_INTFLAG_DPLL0LCKR DPLL0 Lock Rise
 * - OSCCTRL_INTFLAG_DPLL0LCKF DPLL0 Lock Fall
 * - OSCCTRL_INTFLAG_DPLL0LTO DPLL0 Lock Timeout
 * - OSCCTRL_INTFLAG_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete
 * - OSCCTRL_INTFLAG_DPLL1LCKR DPLL1 Lock Rise
 * - OSCCTRL_INTFLAG_DPLL1LCKF DPLL1 Lock Fall
 * - OSCCTRL_INTFLAG_DPLL1LTO DPLL1 Lock Timeout
 * - OSCCTRL_INTFLAG_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete
 **/
static inline void oscctrl_clear_INTFLAG(uint32_t mask)
{
	OSCCTRL->INTFLAG.reg = mask;
}

/**
 * @brief oscctrl set EVCTRL register
 *
 * @param[in] mask uint8_t 
 * - OSCCTRL_EVCTRL_CFDEO0 Clock 0 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO1 Clock 1 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO(value) Clock x Failure Detector Event Output Enable
 **/
static inline void oscctrl_set_EVCTRL(uint8_t mask)
{
	OSCCTRL->EVCTRL.reg |= mask;
}

/**
 * @brief oscctrl get EVCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - OSCCTRL_EVCTRL_CFDEO0 Clock 0 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO1 Clock 1 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO(value) Clock x Failure Detector Event Output Enable
 **/
static inline uint8_t oscctrl_get_EVCTRL(uint8_t mask)
{
    return OSCCTRL->EVCTRL.reg & mask;
}

/**
 * @brief oscctrl write EVCTRL register
 *
 * @param[in] data uint8_t 
 * - OSCCTRL_EVCTRL_CFDEO0 Clock 0 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO1 Clock 1 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO(value) Clock x Failure Detector Event Output Enable
 **/
static inline void oscctrl_write_EVCTRL(uint8_t data)
{
	OSCCTRL->EVCTRL.reg = data;
}

/**
 * @brief oscctrl clear EVCTRL register
 *
 * @param[in] mask uint8_t 
 * - OSCCTRL_EVCTRL_CFDEO0 Clock 0 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO1 Clock 1 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO(value) Clock x Failure Detector Event Output Enable
 **/
static inline void oscctrl_clear_EVCTRL(uint8_t mask)
{
	OSCCTRL->EVCTRL.reg &= ~mask;
}

/**
 * @brief oscctrl read EVCTRL register
 *
 * @return uint8_t
 * - OSCCTRL_EVCTRL_CFDEO0 Clock 0 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO1 Clock 1 Failure Detector Event Output Enable
 * - OSCCTRL_EVCTRL_CFDEO(value) Clock x Failure Detector Event Output Enable
 **/
static inline uint8_t oscctrl_read_EVCTRL(void)
{
	return OSCCTRL->EVCTRL.reg;
}

/**
 * @brief oscctrl set XOSCCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - OSCCTRL_XOSCCTRL_ENABLE Oscillator Enable
 * - OSCCTRL_XOSCCTRL_XTALEN Crystal Oscillator Enable
 * - OSCCTRL_XOSCCTRL_RUNSTDBY Run in Standby
 * - OSCCTRL_XOSCCTRL_ONDEMAND On Demand Control
 * - OSCCTRL_XOSCCTRL_LOWBUFGAIN Low Buffer Gain Enable
 * - OSCCTRL_XOSCCTRL_IPTAT(value) Oscillator Current Reference
 * - OSCCTRL_XOSCCTRL_IMULT(value) Oscillator Current Multiplier
 * - OSCCTRL_XOSCCTRL_ENALC Automatic Loop Control Enable
 * - OSCCTRL_XOSCCTRL_CFDEN Clock Failure Detector Enable
 * - OSCCTRL_XOSCCTRL_SWBEN Xosc Clock Switch Enable
 * - OSCCTRL_XOSCCTRL_STARTUP(value) Start-Up Time
 * - OSCCTRL_XOSCCTRL_CFDPRESC(value) Clock Failure Detector Prescaler
 **/
static inline void oscctrl_set_XOSCCTRL(uint8_t index, uint32_t mask)
{
	OSCCTRL->XOSCCTRL[index].reg |= mask;
}

/**
 * @brief oscctrl get XOSCCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSCCTRL_XOSCCTRL_ENABLE Oscillator Enable
 * - OSCCTRL_XOSCCTRL_XTALEN Crystal Oscillator Enable
 * - OSCCTRL_XOSCCTRL_RUNSTDBY Run in Standby
 * - OSCCTRL_XOSCCTRL_ONDEMAND On Demand Control
 * - OSCCTRL_XOSCCTRL_LOWBUFGAIN Low Buffer Gain Enable
 * - OSCCTRL_XOSCCTRL_IPTAT(value) Oscillator Current Reference
 * - OSCCTRL_XOSCCTRL_IMULT(value) Oscillator Current Multiplier
 * - OSCCTRL_XOSCCTRL_ENALC Automatic Loop Control Enable
 * - OSCCTRL_XOSCCTRL_CFDEN Clock Failure Detector Enable
 * - OSCCTRL_XOSCCTRL_SWBEN Xosc Clock Switch Enable
 * - OSCCTRL_XOSCCTRL_STARTUP(value) Start-Up Time
 * - OSCCTRL_XOSCCTRL_CFDPRESC(value) Clock Failure Detector Prescaler
 **/
static inline uint32_t oscctrl_get_XOSCCTRL(uint8_t index, uint32_t mask)
{
    return OSCCTRL->XOSCCTRL[index].reg & mask;
}

/**
 * @brief oscctrl write XOSCCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - OSCCTRL_XOSCCTRL_ENABLE Oscillator Enable
 * - OSCCTRL_XOSCCTRL_XTALEN Crystal Oscillator Enable
 * - OSCCTRL_XOSCCTRL_RUNSTDBY Run in Standby
 * - OSCCTRL_XOSCCTRL_ONDEMAND On Demand Control
 * - OSCCTRL_XOSCCTRL_LOWBUFGAIN Low Buffer Gain Enable
 * - OSCCTRL_XOSCCTRL_IPTAT(value) Oscillator Current Reference
 * - OSCCTRL_XOSCCTRL_IMULT(value) Oscillator Current Multiplier
 * - OSCCTRL_XOSCCTRL_ENALC Automatic Loop Control Enable
 * - OSCCTRL_XOSCCTRL_CFDEN Clock Failure Detector Enable
 * - OSCCTRL_XOSCCTRL_SWBEN Xosc Clock Switch Enable
 * - OSCCTRL_XOSCCTRL_STARTUP(value) Start-Up Time
 * - OSCCTRL_XOSCCTRL_CFDPRESC(value) Clock Failure Detector Prescaler
 **/
static inline void oscctrl_write_XOSCCTRL(uint8_t index, uint32_t data)
{
	OSCCTRL->XOSCCTRL[index].reg = data;
}

/**
 * @brief oscctrl clear XOSCCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - OSCCTRL_XOSCCTRL_ENABLE Oscillator Enable
 * - OSCCTRL_XOSCCTRL_XTALEN Crystal Oscillator Enable
 * - OSCCTRL_XOSCCTRL_RUNSTDBY Run in Standby
 * - OSCCTRL_XOSCCTRL_ONDEMAND On Demand Control
 * - OSCCTRL_XOSCCTRL_LOWBUFGAIN Low Buffer Gain Enable
 * - OSCCTRL_XOSCCTRL_IPTAT(value) Oscillator Current Reference
 * - OSCCTRL_XOSCCTRL_IMULT(value) Oscillator Current Multiplier
 * - OSCCTRL_XOSCCTRL_ENALC Automatic Loop Control Enable
 * - OSCCTRL_XOSCCTRL_CFDEN Clock Failure Detector Enable
 * - OSCCTRL_XOSCCTRL_SWBEN Xosc Clock Switch Enable
 * - OSCCTRL_XOSCCTRL_STARTUP(value) Start-Up Time
 * - OSCCTRL_XOSCCTRL_CFDPRESC(value) Clock Failure Detector Prescaler
 **/
static inline void oscctrl_clear_XOSCCTRL(uint8_t index, uint32_t mask)
{
	OSCCTRL->XOSCCTRL[index].reg &= ~mask;
}

/**
 * @brief oscctrl read XOSCCTRL register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - OSCCTRL_XOSCCTRL_ENABLE Oscillator Enable
 * - OSCCTRL_XOSCCTRL_XTALEN Crystal Oscillator Enable
 * - OSCCTRL_XOSCCTRL_RUNSTDBY Run in Standby
 * - OSCCTRL_XOSCCTRL_ONDEMAND On Demand Control
 * - OSCCTRL_XOSCCTRL_LOWBUFGAIN Low Buffer Gain Enable
 * - OSCCTRL_XOSCCTRL_IPTAT(value) Oscillator Current Reference
 * - OSCCTRL_XOSCCTRL_IMULT(value) Oscillator Current Multiplier
 * - OSCCTRL_XOSCCTRL_ENALC Automatic Loop Control Enable
 * - OSCCTRL_XOSCCTRL_CFDEN Clock Failure Detector Enable
 * - OSCCTRL_XOSCCTRL_SWBEN Xosc Clock Switch Enable
 * - OSCCTRL_XOSCCTRL_STARTUP(value) Start-Up Time
 * - OSCCTRL_XOSCCTRL_CFDPRESC(value) Clock Failure Detector Prescaler
 **/
static inline uint32_t oscctrl_read_XOSCCTRL(uint8_t index)
{
	return OSCCTRL->XOSCCTRL[index].reg;
}

/**
 * @brief oscctrl set DFLLCTRLA register
 *
 * @param[in] mask uint8_t 
 * - OSCCTRL_DFLLCTRLA_ENABLE DFLL Enable
 * - OSCCTRL_DFLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DFLLCTRLA_ONDEMAND On Demand Control
 **/
static inline void oscctrl_set_DFLLCTRLA(uint8_t mask)
{
	OSCCTRL->DFLLCTRLA.reg |= mask;
}

/**
 * @brief oscctrl get DFLLCTRLA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - OSCCTRL_DFLLCTRLA_ENABLE DFLL Enable
 * - OSCCTRL_DFLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DFLLCTRLA_ONDEMAND On Demand Control
 **/
static inline uint8_t oscctrl_get_DFLLCTRLA(uint8_t mask)
{
    return OSCCTRL->DFLLCTRLA.reg & mask;
}

/**
 * @brief oscctrl write DFLLCTRLA register
 *
 * @param[in] data uint8_t 
 * - OSCCTRL_DFLLCTRLA_ENABLE DFLL Enable
 * - OSCCTRL_DFLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DFLLCTRLA_ONDEMAND On Demand Control
 **/
static inline void oscctrl_write_DFLLCTRLA(uint8_t data)
{
	OSCCTRL->DFLLCTRLA.reg = data;
}

/**
 * @brief oscctrl clear DFLLCTRLA register
 *
 * @param[in] mask uint8_t 
 * - OSCCTRL_DFLLCTRLA_ENABLE DFLL Enable
 * - OSCCTRL_DFLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DFLLCTRLA_ONDEMAND On Demand Control
 **/
static inline void oscctrl_clear_DFLLCTRLA(uint8_t mask)
{
	OSCCTRL->DFLLCTRLA.reg &= ~mask;
}

/**
 * @brief oscctrl read DFLLCTRLA register
 *
 * @return uint8_t
 * - OSCCTRL_DFLLCTRLA_ENABLE DFLL Enable
 * - OSCCTRL_DFLLCTRLA_RUNSTDBY Run in Standby
 * - OSCCTRL_DFLLCTRLA_ONDEMAND On Demand Control
 **/
static inline uint8_t oscctrl_read_DFLLCTRLA(void)
{
	return OSCCTRL->DFLLCTRLA.reg;
}

/**
 * @brief oscctrl set DFLLCTRLB register
 *
 * @param[in] mask uint8_t 
 * - OSCCTRL_DFLLCTRLB_MODE Operating Mode Selection
 * - OSCCTRL_DFLLCTRLB_STABLE Stable DFLL Frequency
 * - OSCCTRL_DFLLCTRLB_LLAW Lose Lock After Wake
 * - OSCCTRL_DFLLCTRLB_USBCRM USB Clock Recovery Mode
 * - OSCCTRL_DFLLCTRLB_CCDIS Chill Cycle Disable
 * - OSCCTRL_DFLLCTRLB_QLDIS Quick Lock Disable
 * - OSCCTRL_DFLLCTRLB_BPLCKC Bypass Coarse Lock
 * - OSCCTRL_DFLLCTRLB_WAITLOCK Wait Lock
 **/
static inline void oscctrl_set_DFLLCTRLB(uint8_t mask)
{
	OSCCTRL->DFLLCTRLB.reg |= mask;
}

/**
 * @brief oscctrl get DFLLCTRLB register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - OSCCTRL_DFLLCTRLB_MODE Operating Mode Selection
 * - OSCCTRL_DFLLCTRLB_STABLE Stable DFLL Frequency
 * - OSCCTRL_DFLLCTRLB_LLAW Lose Lock After Wake
 * - OSCCTRL_DFLLCTRLB_USBCRM USB Clock Recovery Mode
 * - OSCCTRL_DFLLCTRLB_CCDIS Chill Cycle Disable
 * - OSCCTRL_DFLLCTRLB_QLDIS Quick Lock Disable
 * - OSCCTRL_DFLLCTRLB_BPLCKC Bypass Coarse Lock
 * - OSCCTRL_DFLLCTRLB_WAITLOCK Wait Lock
 **/
static inline uint8_t oscctrl_get_DFLLCTRLB(uint8_t mask)
{
    return OSCCTRL->DFLLCTRLB.reg & mask;
}

/**
 * @brief oscctrl write DFLLCTRLB register
 *
 * @param[in] data uint8_t 
 * - OSCCTRL_DFLLCTRLB_MODE Operating Mode Selection
 * - OSCCTRL_DFLLCTRLB_STABLE Stable DFLL Frequency
 * - OSCCTRL_DFLLCTRLB_LLAW Lose Lock After Wake
 * - OSCCTRL_DFLLCTRLB_USBCRM USB Clock Recovery Mode
 * - OSCCTRL_DFLLCTRLB_CCDIS Chill Cycle Disable
 * - OSCCTRL_DFLLCTRLB_QLDIS Quick Lock Disable
 * - OSCCTRL_DFLLCTRLB_BPLCKC Bypass Coarse Lock
 * - OSCCTRL_DFLLCTRLB_WAITLOCK Wait Lock
 **/
static inline void oscctrl_write_DFLLCTRLB(uint8_t data)
{
	OSCCTRL->DFLLCTRLB.reg = data;
}

/**
 * @brief oscctrl clear DFLLCTRLB register
 *
 * @param[in] mask uint8_t 
 * - OSCCTRL_DFLLCTRLB_MODE Operating Mode Selection
 * - OSCCTRL_DFLLCTRLB_STABLE Stable DFLL Frequency
 * - OSCCTRL_DFLLCTRLB_LLAW Lose Lock After Wake
 * - OSCCTRL_DFLLCTRLB_USBCRM USB Clock Recovery Mode
 * - OSCCTRL_DFLLCTRLB_CCDIS Chill Cycle Disable
 * - OSCCTRL_DFLLCTRLB_QLDIS Quick Lock Disable
 * - OSCCTRL_DFLLCTRLB_BPLCKC Bypass Coarse Lock
 * - OSCCTRL_DFLLCTRLB_WAITLOCK Wait Lock
 **/
static inline void oscctrl_clear_DFLLCTRLB(uint8_t mask)
{
	OSCCTRL->DFLLCTRLB.reg &= ~mask;
}

/**
 * @brief oscctrl read DFLLCTRLB register
 *
 * @return uint8_t
 * - OSCCTRL_DFLLCTRLB_MODE Operating Mode Selection
 * - OSCCTRL_DFLLCTRLB_STABLE Stable DFLL Frequency
 * - OSCCTRL_DFLLCTRLB_LLAW Lose Lock After Wake
 * - OSCCTRL_DFLLCTRLB_USBCRM USB Clock Recovery Mode
 * - OSCCTRL_DFLLCTRLB_CCDIS Chill Cycle Disable
 * - OSCCTRL_DFLLCTRLB_QLDIS Quick Lock Disable
 * - OSCCTRL_DFLLCTRLB_BPLCKC Bypass Coarse Lock
 * - OSCCTRL_DFLLCTRLB_WAITLOCK Wait Lock
 **/
static inline uint8_t oscctrl_read_DFLLCTRLB(void)
{
	return OSCCTRL->DFLLCTRLB.reg;
}

/**
 * @brief oscctrl write DFLLVAL register
 *
 * @param[in] data uint32_t 
 * - OSCCTRL_DFLLVAL_FINE(value) Fine Value
 * - OSCCTRL_DFLLVAL_COARSE(value) Coarse Value
 * - OSCCTRL_DFLLVAL_DIFF(value) Multiplication Ratio Difference
 **/
static inline void oscctrl_write_DFLLVAL(uint32_t data)
{
	OSCCTRL->DFLLVAL.reg = data;
}

/**
 * @brief oscctrl clear DFLLVAL register
 *
 * @param[in] mask uint32_t 
 * - OSCCTRL_DFLLVAL_FINE(value) Fine Value
 * - OSCCTRL_DFLLVAL_COARSE(value) Coarse Value
 * - OSCCTRL_DFLLVAL_DIFF(value) Multiplication Ratio Difference
 **/
static inline void oscctrl_clear_DFLLVAL(uint32_t mask)
{
	OSCCTRL->DFLLVAL.reg &= ~mask;
}

/**
 * @brief oscctrl read DFLLVAL register
 *
 * @return uint32_t
 * - OSCCTRL_DFLLVAL_FINE(value) Fine Value
 * - OSCCTRL_DFLLVAL_COARSE(value) Coarse Value
 * - OSCCTRL_DFLLVAL_DIFF(value) Multiplication Ratio Difference
 **/
static inline uint32_t oscctrl_read_DFLLVAL(void)
{
	return OSCCTRL->DFLLVAL.reg;
}

/**
 * @brief oscctrl write DFLLMUL register
 *
 * @param[in] data uint32_t 
 * - OSCCTRL_DFLLMUL_MUL(value) DFLL Multiply Factor
 * - OSCCTRL_DFLLMUL_FSTEP(value) Fine Maximum Step
 * - OSCCTRL_DFLLMUL_CSTEP(value) Coarse Maximum Step
 **/
static inline void oscctrl_write_DFLLMUL(uint32_t data)
{
	OSCCTRL->DFLLMUL.reg = data;
}

/**
 * @brief oscctrl read DFLLMUL register
 *
 * @return uint32_t
 * - OSCCTRL_DFLLMUL_MUL(value) DFLL Multiply Factor
 * - OSCCTRL_DFLLMUL_FSTEP(value) Fine Maximum Step
 * - OSCCTRL_DFLLMUL_CSTEP(value) Coarse Maximum Step
 **/
static inline uint32_t oscctrl_read_DFLLMUL(void)
{
	return OSCCTRL->DFLLMUL.reg;
}

/**
 * @brief oscctrl set DFLLSYNC register
 *
 * @param[in] mask uint8_t 
 * - OSCCTRL_DFLLSYNC_ENABLE ENABLE Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLCTRLB DFLLCTRLB Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLVAL DFLLVAL Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLMUL DFLLMUL Synchronization Busy
 **/
static inline void oscctrl_set_DFLLSYNC(uint8_t mask)
{
	OSCCTRL->DFLLSYNC.reg |= mask;
}

/**
 * @brief oscctrl get DFLLSYNC register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - OSCCTRL_DFLLSYNC_ENABLE ENABLE Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLCTRLB DFLLCTRLB Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLVAL DFLLVAL Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLMUL DFLLMUL Synchronization Busy
 **/
static inline uint8_t oscctrl_get_DFLLSYNC(uint8_t mask)
{
    return OSCCTRL->DFLLSYNC.reg & mask;
}

/**
 * @brief oscctrl write DFLLSYNC register
 *
 * @param[in] data uint8_t 
 * - OSCCTRL_DFLLSYNC_ENABLE ENABLE Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLCTRLB DFLLCTRLB Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLVAL DFLLVAL Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLMUL DFLLMUL Synchronization Busy
 **/
static inline void oscctrl_write_DFLLSYNC(uint8_t data)
{
	OSCCTRL->DFLLSYNC.reg = data;
}

/**
 * @brief oscctrl read DFLLSYNC register
 *
 * @return uint8_t
 * - OSCCTRL_DFLLSYNC_ENABLE ENABLE Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLCTRLB DFLLCTRLB Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLVAL DFLLVAL Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLMUL DFLLMUL Synchronization Busy
 **/
static inline uint8_t oscctrl_read_DFLLSYNC(void)
{
	return OSCCTRL->DFLLSYNC.reg;
}

/**
 * @brief oscctrl get STATUS register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - OSCCTRL_STATUS_XOSCRDY0 XOSC 0 Ready
 * - OSCCTRL_STATUS_XOSCRDY1 XOSC 1 Ready
 * - OSCCTRL_STATUS_XOSCRDY(value) XOSC x Ready
 * - OSCCTRL_STATUS_XOSCFAIL0 XOSC 0 Clock Failure Detector
 * - OSCCTRL_STATUS_XOSCFAIL1 XOSC 1 Clock Failure Detector
 * - OSCCTRL_STATUS_XOSCFAIL(value) XOSC x Clock Failure Detector
 * - OSCCTRL_STATUS_XOSCCKSW0 XOSC 0 Clock Switch
 * - OSCCTRL_STATUS_XOSCCKSW1 XOSC 1 Clock Switch
 * - OSCCTRL_STATUS_XOSCCKSW(value) XOSC x Clock Switch
 * - OSCCTRL_STATUS_DFLLRDY DFLL Ready
 * - OSCCTRL_STATUS_DFLLOOB DFLL Out Of Bounds
 * - OSCCTRL_STATUS_DFLLLCKF DFLL Lock Fine
 * - OSCCTRL_STATUS_DFLLLCKC DFLL Lock Coarse
 * - OSCCTRL_STATUS_DFLLRCS DFLL Reference Clock Stopped
 * - OSCCTRL_STATUS_DPLL0LCKR DPLL0 Lock Rise
 * - OSCCTRL_STATUS_DPLL0LCKF DPLL0 Lock Fall
 * - OSCCTRL_STATUS_DPLL0TO DPLL0 Timeout
 * - OSCCTRL_STATUS_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete
 * - OSCCTRL_STATUS_DPLL1LCKR DPLL1 Lock Rise
 * - OSCCTRL_STATUS_DPLL1LCKF DPLL1 Lock Fall
 * - OSCCTRL_STATUS_DPLL1TO DPLL1 Timeout
 * - OSCCTRL_STATUS_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete
 **/
static inline uint32_t oscctrl_get_STATUS(uint32_t mask)
{
    return OSCCTRL->STATUS.reg & mask;
}

/**
 * @brief oscctrl read STATUS register
 *
 * @return uint32_t
 * - OSCCTRL_STATUS_XOSCRDY0 XOSC 0 Ready
 * - OSCCTRL_STATUS_XOSCRDY1 XOSC 1 Ready
 * - OSCCTRL_STATUS_XOSCRDY(value) XOSC x Ready
 * - OSCCTRL_STATUS_XOSCFAIL0 XOSC 0 Clock Failure Detector
 * - OSCCTRL_STATUS_XOSCFAIL1 XOSC 1 Clock Failure Detector
 * - OSCCTRL_STATUS_XOSCFAIL(value) XOSC x Clock Failure Detector
 * - OSCCTRL_STATUS_XOSCCKSW0 XOSC 0 Clock Switch
 * - OSCCTRL_STATUS_XOSCCKSW1 XOSC 1 Clock Switch
 * - OSCCTRL_STATUS_XOSCCKSW(value) XOSC x Clock Switch
 * - OSCCTRL_STATUS_DFLLRDY DFLL Ready
 * - OSCCTRL_STATUS_DFLLOOB DFLL Out Of Bounds
 * - OSCCTRL_STATUS_DFLLLCKF DFLL Lock Fine
 * - OSCCTRL_STATUS_DFLLLCKC DFLL Lock Coarse
 * - OSCCTRL_STATUS_DFLLRCS DFLL Reference Clock Stopped
 * - OSCCTRL_STATUS_DPLL0LCKR DPLL0 Lock Rise
 * - OSCCTRL_STATUS_DPLL0LCKF DPLL0 Lock Fall
 * - OSCCTRL_STATUS_DPLL0TO DPLL0 Timeout
 * - OSCCTRL_STATUS_DPLL0LDRTO DPLL0 Loop Divider Ratio Update Complete
 * - OSCCTRL_STATUS_DPLL1LCKR DPLL1 Lock Rise
 * - OSCCTRL_STATUS_DPLL1LCKF DPLL1 Lock Fall
 * - OSCCTRL_STATUS_DPLL1TO DPLL1 Timeout
 * - OSCCTRL_STATUS_DPLL1LDRTO DPLL1 Loop Divider Ratio Update Complete
 **/
static inline uint32_t oscctrl_read_STATUS(void)
{
	return OSCCTRL->STATUS.reg;
}

/**
 * @brief set DFLL Control A Enable bit
 * @note dfll_wait_for_sync(OSCCTRL_DFLLSYNC_ENABLE); 
 * dfll_set_ENABLE();
 */
static inline void dfll_set_ENABLE(void)
{
	OSCCTRL->DFLLCTRLA.reg |= OSCCTRL_DFLLCTRLA_ENABLE;
}

/**
 * @brief clear DFLL Control A Enable bit
 * @note dfll_wait_for_sync(OSCCTRL_DFLLSYNC_ENABLE); 
 * dfll_clear_ENABLE();
 */
static inline void dfll_clear_ENABLE(void)
{
	OSCCTRL->DFLLCTRLA.reg &= ~OSCCTRL_DFLLCTRLA_ENABLE;
}
/**
 * @brief wait for DFLL sync busy to be not busy
 * @param[in] reg
 * - OSCCTRL_DFLLSYNC_ENABLE	Enable Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLCTRLB DFLLCTRLB Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLVAL DFLLVAL Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLMUL DFLLMUL Synchronization Busy
 * 
 */
static inline void dfll_wait_for_sync(uint8_t reg)
{
	while (oscctrl_read_DFLLSYNC() & reg) {};
}

/**
 * @brief wait for DFLL sync busy to be not busy
 * @param[in] reg uint8_t
 * - OSCCTRL_DFLLSYNC_ENABLE	Enable Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLCTRLB DFLLCTRLB Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLVAL DFLLVAL Synchronization Busy
 * - OSCCTRL_DFLLSYNC_DFLLMUL DFLLMUL Synchronization Busy
 * @return true if busy
 */
static inline bool dfll_is_syncing(uint8_t reg)
{
	return (oscctrl_read_DFLLSYNC() & reg) != 0;
}

/**
 * @brief spin while DPLL0 or DPLL1 sync is busy 
 *
 * @param[in] index DPLL0 or DPLL1
 * @param[in] reg uint32_t
 * - OSCCTRL_DPLLSYNCBUSY_ENABLE	    DPLL Enable Synchronization Status 
 * - OSCCTRL_DPLLSYNCBUSY_DPLLRATIO	DPLL Loop Divider Ratio Synchronization Status 
 */
static inline void dpll_wait_for_sync(uint8_t index, uint32_t reg)
{
	while(OSCCTRL->Dpll[index].DPLLSYNCBUSY.reg & reg) {};
}

/**
 * @brief set DPLL0 or DPLL1 control A register enable bit
 * param[in] index DPLL0 or DPLL1
 * @note  dpll_wait_for_sync(OSCCTRL_DPLLSYNC_ENABLE);
 * dpll_set_ENABLE(DPLL0);
 */
static inline void dpll_set_ENABLE(uint8_t index)
{
	OSCCTRL->Dpll[index].DPLLCTRLA.reg |= OSCCTRL_DPLLCTRLA_ENABLE;
}

/**
 * @brief clear DPLL0 or DPLL1 control A register enable bit
 * param[in] index DPLL0 or DPLL1
 * @note  dpll_wait_for_sync(OSCCTRL_DPLLSYNC_ENABLE);
 * dpll_clear_ENABLE(DPLL0);
 */
static inline void dpll_clear_ENABLE(uint8_t index)
{
	OSCCTRL->Dpll[index].DPLLCTRLA.reg &= ~OSCCTRL_DPLLCTRLA_ENABLE;
}

/**
 * @brief return DPLL0 or DPLL1 sync busy register masked by reg
 *
 * @param[in] index DPLL0 or DPLL1
 * @param[in] reg uint32_t
 * - OSCCTRL_DPLLSYNCBUSY_ENABLE	    DPLL Enable Synchronization Status 
 * - OSCCTRL_DPLLSYNCBUSY_DPLLRATIO	DPLL Loop Divider Ratio Synchronization Status 
 * return bool
 */
static inline bool dpll_is_syncing(uint8_t index, uint32_t reg)
{
	return (OSCCTRL->Dpll[index].DPLLSYNCBUSY.reg & reg) != 0;
}

#endif /* _OSCCTRL_H */
