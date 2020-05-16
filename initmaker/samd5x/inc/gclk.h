/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM GCLK
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

#ifndef _GCLK_H_
#define _GCLK_H_

#include <stdbool.h>

#define	GCLK0 	0	/**< /brief GCLK index for GCLK0 **/
#define GCLK1	1	/**< /brief GCLK index for GCLK1 **/
#define GCLK2	2	/**< /brief GCLK index for GCLK2 **/
#define GCLK3	3	/**< /brief GCLK index for GCLK3 **/
#define GCLK4	4	/**< /brief GCLK index for GCLK4 **/
#define GCLK5	5	/**< /brief GCLK index for GCLK5 **/
#define GCLK6	6	/**< /brief GCLK index for GCLK6 **/
#define GCLK7	7	/**< /brief GCLK index for GCLK7 **/
#define GCLK8	8	/**< /brief GCLK index for GCLK8 **/
#define GCLK9	9	/**< /brief GCLK index for GCLK9 **/
#define GCLK10	10	/**< /brief GCLK index for GCLK10 **/
#define GCLK11	11	/**< /brief GCLK index for GCLK11 **/

/**
 * @brief gclk wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void gclk_wait_for_sync(uint32_t reg)
{
	while (GCLK->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief gclk is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool gclk_is_syncing(uint32_t reg)
{
	return GCLK->SYNCBUSY.reg & reg;
}

/**
 * @brief software reset GCLK controller
 * CTRLA is global to all GCLK Generators
 * CTRLA.SWRST must be synchronized before setting
 * @note gclk_wait_for_sync(GCLK_SYNCBUSY_SWRST); gclk_set_SWRST();
 */
static inline void gclk_set_SWRST(void)
{
	GCLK->CTRLA.reg = GCLK_CTRLA_SWRST;
}
/**
 * @brief return boolean state of gclk CTRLA SWRST
 * CTRLA is global to all GCLK Generators
 * CTRLA.SWRST must be synchronized before 
 * @note gclk_wait_for_sync(GCLK_SYNCBUSY_SWRST); gclk_get_SWRST();
 * @return false = software reset complete 
 */
static inline bool gclk_get_SWRST(void)
{
	return ((GCLK->CTRLA.reg & GCLK_CTRLA_SWRST) != 0);
}

/**
 * @brief gclk read CTRLA register
 *
 * @return uint8_t
 * - GCLK_CTRLA_SWRST Software Reset
 **/
static inline uint8_t gclk_read_CTRLA(void)
{
	return GCLK->CTRLA.reg;
}

/**
 * @brief gclk set GENCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - GCLK_GENCTRL_SRC(value) Source Select
 *  +      GCLK_GENCTRL_SRC_XOSC0 XOSC0 oscillator output
 *  +      GCLK_GENCTRL_SRC_XOSC1 XOSC1 oscillator output
 *  +      GCLK_GENCTRL_SRC_GCLKIN Generator input pad
 *  +      GCLK_GENCTRL_SRC_GCLKGEN1 Generic clock generator 1 output
 *  +      GCLK_GENCTRL_SRC_OSCULP32K OSCULP32K oscillator output
 *  +      GCLK_GENCTRL_SRC_XOSC32K XOSC32K oscillator output
 *  +      GCLK_GENCTRL_SRC_DFLL DFLL output
 *  +      GCLK_GENCTRL_SRC_DPLL0 DPLL0 output
 *  +      GCLK_GENCTRL_SRC_DPLL1 DPLL1 output
 * - GCLK_GENCTRL_GENEN Generic Clock Generator Enable
 * - GCLK_GENCTRL_IDC Improve Duty Cycle
 * - GCLK_GENCTRL_OOV Output Off Value
 * - GCLK_GENCTRL_OE Output Enable
 * - GCLK_GENCTRL_DIVSEL Divide Selection
 * - GCLK_GENCTRL_RUNSTDBY Run in Standby
 * - GCLK_GENCTRL_DIV(value) Division Factor
 **/
static inline void gclk_set_GENCTRL(uint8_t index, uint32_t mask)
{
	GCLK->GENCTRL[index].reg |= mask;
}

/**
 * @brief gclk set only the SRC field of GCLK leaving configuration as is
 * each GCLK generator has its own GENCTRL register 
 * @param[in] index - int8_t  0 - 11 for GCLK0-GCLK11
 * @param[in] src - uint32_t  Source For GCLK
 * - GCLK_GENCTRL_SRC(value)	Source Select
 *  +  GCLK_GENCTRL_SRC_XOSC0
 *  +  GCLK_GENCTRL_SRC_XOSC1
 *  +  GCLK_GENCTRL_SRC_GCLKIN
 *  +  GCLK_GENCTRL_SRC_GCLKGEN1
 *  +  GCLK_GENCTRL_SRC_OSCULP32K
 *  +  GCLK_GENCTRL_SRC_XOSC32K
 *  +  GCLK_GENCTRL_SRC_DFLL
 *  +  GCLK_GENCTRL_SRC_DPLL0
 *  +  GCLK_GENCTRL_SRC_DPLL1
 * 
 */
static inline void gclk_set_GENCTRL_SRC(uint8_t index, uint32_t src)
{
	GCLK->GENCTRL[index].reg = (GCLK->GENCTRL[index].reg & ~GCLK_GENCTRL_SRC_Msk) | src;
}

/**
 * @brief gclk get GENCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - GCLK_GENCTRL_SRC(value) Source Select
 *  +      GCLK_GENCTRL_SRC_XOSC0 XOSC0 oscillator output
 *  +      GCLK_GENCTRL_SRC_XOSC1 XOSC1 oscillator output
 *  +      GCLK_GENCTRL_SRC_GCLKIN Generator input pad
 *  +      GCLK_GENCTRL_SRC_GCLKGEN1 Generic clock generator 1 output
 *  +      GCLK_GENCTRL_SRC_OSCULP32K OSCULP32K oscillator output
 *  +      GCLK_GENCTRL_SRC_XOSC32K XOSC32K oscillator output
 *  +      GCLK_GENCTRL_SRC_DFLL DFLL output
 *  +      GCLK_GENCTRL_SRC_DPLL0 DPLL0 output
 *  +      GCLK_GENCTRL_SRC_DPLL1 DPLL1 output
 * - GCLK_GENCTRL_GENEN Generic Clock Generator Enable
 * - GCLK_GENCTRL_IDC Improve Duty Cycle
 * - GCLK_GENCTRL_OOV Output Off Value
 * - GCLK_GENCTRL_OE Output Enable
 * - GCLK_GENCTRL_DIVSEL Divide Selection
 * - GCLK_GENCTRL_RUNSTDBY Run in Standby
 * - GCLK_GENCTRL_DIV(value) Division Factor
 **/
static inline uint32_t gclk_get_GENCTRL(uint8_t index, uint32_t mask)
{
    return GCLK->GENCTRL[index].reg & mask;
}

/**
 * @brief get the contents of the PCHCTRL register for GCLKn where n is index 0 to 11
 *
 * @param[in] index 0 to 11 for GCLK0 to GCLK11
 * @param[in] mask - uint32_t
 * - GCLK_PCHCTRL_GEN(value) Generic Clock Generator
 *  +      GCLK_PCHCTRL_GEN_GCLK0 Generic clock generator 0
 *  +      GCLK_PCHCTRL_GEN_GCLK1 Generic clock generator 1
 *  +      GCLK_PCHCTRL_GEN_GCLK2 Generic clock generator 2
 *  +      GCLK_PCHCTRL_GEN_GCLK3 Generic clock generator 3
 *  +      GCLK_PCHCTRL_GEN_GCLK4 Generic clock generator 4
 *  +      GCLK_PCHCTRL_GEN_GCLK5 Generic clock generator 5
 *  +      GCLK_PCHCTRL_GEN_GCLK6 Generic clock generator 6
 *  +      GCLK_PCHCTRL_GEN_GCLK7 Generic clock generator 7
 *  +      GCLK_PCHCTRL_GEN_GCLK8 Generic clock generator 8
 *  +      GCLK_PCHCTRL_GEN_GCLK9 Generic clock generator 9
 *  +      GCLK_PCHCTRL_GEN_GCLK10 Generic clock generator 10
 *  +      GCLK_PCHCTRL_GEN_GCLK11 Generic clock generator 11
 * - GCLK_PCHCTRL_CHEN Channel Enable
 * - GCLK_PCHCTRL_WRTLOCK Write Lock
 * @return uint32_t 32 bit PCHCTRL register contents
 */
static inline uint32_t gclk_get_PCHCTRL(uint8_t index, uint32_t mask)
{
	return GCLK->PCHCTRL[index].reg & mask;
}
/**
 * @brief gclk write GENCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - GCLK_GENCTRL_SRC(value) Source Select
 *  +      GCLK_GENCTRL_SRC_XOSC0 XOSC0 oscillator output
 *  +      GCLK_GENCTRL_SRC_XOSC1 XOSC1 oscillator output
 *  +      GCLK_GENCTRL_SRC_GCLKIN Generator input pad
 *  +      GCLK_GENCTRL_SRC_GCLKGEN1 Generic clock generator 1 output
 *  +      GCLK_GENCTRL_SRC_OSCULP32K OSCULP32K oscillator output
 *  +      GCLK_GENCTRL_SRC_XOSC32K XOSC32K oscillator output
 *  +      GCLK_GENCTRL_SRC_DFLL DFLL output
 *  +      GCLK_GENCTRL_SRC_DPLL0 DPLL0 output
 *  +      GCLK_GENCTRL_SRC_DPLL1 DPLL1 output
 * - GCLK_GENCTRL_GENEN Generic Clock Generator Enable
 * - GCLK_GENCTRL_IDC Improve Duty Cycle
 * - GCLK_GENCTRL_OOV Output Off Value
 * - GCLK_GENCTRL_OE Output Enable
 * - GCLK_GENCTRL_DIVSEL Divide Selection
 * - GCLK_GENCTRL_RUNSTDBY Run in Standby
 * - GCLK_GENCTRL_DIV(value) Division Factor
 **/
static inline void gclk_write_GENCTRL(uint8_t index, uint32_t data)
{
	GCLK->GENCTRL[index].reg = data;
}

/**
 * @brief gclk read GENCTRL register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - GCLK_GENCTRL_SRC(value) Source Select
 *  +      GCLK_GENCTRL_SRC_XOSC0 XOSC0 oscillator output
 *  +      GCLK_GENCTRL_SRC_XOSC1 XOSC1 oscillator output
 *  +      GCLK_GENCTRL_SRC_GCLKIN Generator input pad
 *  +      GCLK_GENCTRL_SRC_GCLKGEN1 Generic clock generator 1 output
 *  +      GCLK_GENCTRL_SRC_OSCULP32K OSCULP32K oscillator output
 *  +      GCLK_GENCTRL_SRC_XOSC32K XOSC32K oscillator output
 *  +      GCLK_GENCTRL_SRC_DFLL DFLL output
 *  +      GCLK_GENCTRL_SRC_DPLL0 DPLL0 output
 *  +      GCLK_GENCTRL_SRC_DPLL1 DPLL1 output
 * - GCLK_GENCTRL_GENEN Generic Clock Generator Enable
 * - GCLK_GENCTRL_IDC Improve Duty Cycle
 * - GCLK_GENCTRL_OOV Output Off Value
 * - GCLK_GENCTRL_OE Output Enable
 * - GCLK_GENCTRL_DIVSEL Divide Selection
 * - GCLK_GENCTRL_RUNSTDBY Run in Standby
 * - GCLK_GENCTRL_DIV(value) Division Factor
 **/
static inline uint32_t gclk_read_GENCTRL(uint8_t index)
{
	return GCLK->GENCTRL[index].reg;
}

/**
 * @brief gclk write PCHCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - GCLK_PCHCTRL_GEN(value) Generic Clock Generator
 *  +      GCLK_PCHCTRL_GEN_GCLK0 Generic clock generator 0
 *  +      GCLK_PCHCTRL_GEN_GCLK1 Generic clock generator 1
 *  +      GCLK_PCHCTRL_GEN_GCLK2 Generic clock generator 2
 *  +      GCLK_PCHCTRL_GEN_GCLK3 Generic clock generator 3
 *  +      GCLK_PCHCTRL_GEN_GCLK4 Generic clock generator 4
 *  +      GCLK_PCHCTRL_GEN_GCLK5 Generic clock generator 5
 *  +      GCLK_PCHCTRL_GEN_GCLK6 Generic clock generator 6
 *  +      GCLK_PCHCTRL_GEN_GCLK7 Generic clock generator 7
 *  +      GCLK_PCHCTRL_GEN_GCLK8 Generic clock generator 8
 *  +      GCLK_PCHCTRL_GEN_GCLK9 Generic clock generator 9
 *  +      GCLK_PCHCTRL_GEN_GCLK10 Generic clock generator 10
 *  +      GCLK_PCHCTRL_GEN_GCLK11 Generic clock generator 11
 * - GCLK_PCHCTRL_CHEN Channel Enable
 * - GCLK_PCHCTRL_WRTLOCK Write Lock
 **/
static inline void gclk_write_PCHCTRL(uint8_t index, uint32_t data)
{
	GCLK->PCHCTRL[index].reg = data;
}

/**
 * @brief gclk read PCHCTRL register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - GCLK_PCHCTRL_GEN(value) Generic Clock Generator
 *  +      GCLK_PCHCTRL_GEN_GCLK0 Generic clock generator 0
 *  +      GCLK_PCHCTRL_GEN_GCLK1 Generic clock generator 1
 *  +      GCLK_PCHCTRL_GEN_GCLK2 Generic clock generator 2
 *  +      GCLK_PCHCTRL_GEN_GCLK3 Generic clock generator 3
 *  +      GCLK_PCHCTRL_GEN_GCLK4 Generic clock generator 4
 *  +      GCLK_PCHCTRL_GEN_GCLK5 Generic clock generator 5
 *  +      GCLK_PCHCTRL_GEN_GCLK6 Generic clock generator 6
 *  +      GCLK_PCHCTRL_GEN_GCLK7 Generic clock generator 7
 *  +      GCLK_PCHCTRL_GEN_GCLK8 Generic clock generator 8
 *  +      GCLK_PCHCTRL_GEN_GCLK9 Generic clock generator 9
 *  +      GCLK_PCHCTRL_GEN_GCLK10 Generic clock generator 10
 *  +      GCLK_PCHCTRL_GEN_GCLK11 Generic clock generator 11
 * - GCLK_PCHCTRL_CHEN Channel Enable
 * - GCLK_PCHCTRL_WRTLOCK Write Lock
 **/
static inline uint32_t gclk_read_PCHCTRL(uint8_t index)
{
	return GCLK->PCHCTRL[index].reg;
}

/**
 * @brief gclk get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - GCLK_SYNCBUSY_SWRST Software Reset Synchroniation Busy bit
 * - GCLK_SYNCBUSY_GENCTRL0 Generic Clock Generator Control 0 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL1 Generic Clock Generator Control 1 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL2 Generic Clock Generator Control 2 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL3 Generic Clock Generator Control 3 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL4 Generic Clock Generator Control 4 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL5 Generic Clock Generator Control 5 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL6 Generic Clock Generator Control 6 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL7 Generic Clock Generator Control 7 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL8 Generic Clock Generator Control 8 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL9 Generic Clock Generator Control 9 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL10 Generic Clock Generator Control 10 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL11 Generic Clock Generator Control 11 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL(value) Generic Clock Generator Control x Synchronization Busy bits
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK0 Generic clock generator 0
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK1 Generic clock generator 1
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK2 Generic clock generator 2
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK3 Generic clock generator 3
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK4 Generic clock generator 4
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK5 Generic clock generator 5
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK6 Generic clock generator 6
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK7 Generic clock generator 7
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK8 Generic clock generator 8
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK9 Generic clock generator 9
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK10 Generic clock generator 10
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK11 Generic clock generator 11
 **/
static inline uint32_t gclk_get_SYNCBUSY(uint32_t mask)
{
    return GCLK->SYNCBUSY.reg & mask;
}

/**
 * @brief gclk read SYNCBUSY register
 *
 * @return uint32_t
 * - GCLK_SYNCBUSY_SWRST Software Reset Synchroniation Busy bit
 * - GCLK_SYNCBUSY_GENCTRL0 Generic Clock Generator Control 0 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL1 Generic Clock Generator Control 1 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL2 Generic Clock Generator Control 2 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL3 Generic Clock Generator Control 3 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL4 Generic Clock Generator Control 4 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL5 Generic Clock Generator Control 5 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL6 Generic Clock Generator Control 6 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL7 Generic Clock Generator Control 7 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL8 Generic Clock Generator Control 8 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL9 Generic Clock Generator Control 9 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL10 Generic Clock Generator Control 10 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL11 Generic Clock Generator Control 11 Synchronization Busy bits
 * - GCLK_SYNCBUSY_GENCTRL(value) Generic Clock Generator Control x Synchronization Busy bits
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK0 Generic clock generator 0
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK1 Generic clock generator 1
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK2 Generic clock generator 2
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK3 Generic clock generator 3
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK4 Generic clock generator 4
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK5 Generic clock generator 5
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK6 Generic clock generator 6
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK7 Generic clock generator 7
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK8 Generic clock generator 8
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK9 Generic clock generator 9
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK10 Generic clock generator 10
 *  +      GCLK_SYNCBUSY_GENCTRL_GCLK11 Generic clock generator 11
 **/
static inline uint32_t gclk_read_SYNCBUSY(void)
{
	return GCLK->SYNCBUSY.reg;
}

#endif /* _GCLK_H */
