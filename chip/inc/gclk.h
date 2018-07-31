/**
 * @note This file is modified from the Atmel ASF4 hri include
 * by Alkgrove 2018
 * @version beta
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
 * @brief wait for gclk to synchronize for GCLK_SYNCBUSY_GENCTRL0 - GCLK_SYNCBUSY_GENCTRL11
 * and GCLK_SYNCBUSY_SWRST
 * @param[in] uint32_t reg 
 * GCLK_SYNCBUSY_SWRST,
 * GCLK_SYNCBUSY_GENCTRL0
 * GCLK_SYNCBUSY_GENCTRL1
 * GCLK_SYNCBUSY_GENCTRL2
 * GCLK_SYNCBUSY_GENCTRL3
 * GCLK_SYNCBUSY_GENCTRL4
 * GCLK_SYNCBUSY_GENCTRL5
 * GCLK_SYNCBUSY_GENCTRL6
 * GCLK_SYNCBUSY_GENCTRL7
 * GCLK_SYNCBUSY_GENCTRL8
 * GCLK_SYNCBUSY_GENCTRL9
 * GCLK_SYNCBUSY_GENCTRL10
 * GCLK_SYNCBUSY_GENCTRL11
 */
static inline void gclk_wait_for_sync(uint32_t reg)
{
	while (GCLK->SYNCBUSY.reg & reg) {
	};
}
/**
 * @brief test if  GCLK_SYNCBUSY_GENCTRL0 - GCLK_SYNCBUSY_GENCTRL11, GCLK_SYNCBUSY_SWRST syncing
 * SYNCBUSY is global to all GCLK Generators with bit for each generator
 * @return uint32_t 0 = done synchronizing
 * GCLK_SYNCBUSY_SWRST
 * GCLK_SYNCBUSY_GENCTRL0
 * GCLK_SYNCBUSY_GENCTRL1
 * GCLK_SYNCBUSY_GENCTRL2
 * GCLK_SYNCBUSY_GENCTRL3
 * GCLK_SYNCBUSY_GENCTRL4
 * GCLK_SYNCBUSY_GENCTRL5
 * GCLK_SYNCBUSY_GENCTRL6
 * GCLK_SYNCBUSY_GENCTRL7
 * GCLK_SYNCBUSY_GENCTRL8
 * GCLK_SYNCBUSY_GENCTRL9
 * GCLK_SYNCBUSY_GENCTRL10
 * GCLK_SYNCBUSY_GENCTRL11
 */

static inline uint32_t gclk_read_SYNCBUSY(void)
{
	return GCLK->SYNCBUSY.reg;
}
/**
 * @brief test if  GCLK_SYNCBUSY_GENCTRL0 - GCLK_SYNCBUSY_GENCTRL11, GCLK_SYNCBUSY_SWRST syncing
 * SYNCBUSY is global to all GCLK Generators with bit for each generator
 * @return uint32_t 0 = done synchronizing
 * GCLK_SYNCBUSY_SWRST
 * GCLK_SYNCBUSY_GENCTRL0
 * GCLK_SYNCBUSY_GENCTRL1
 * GCLK_SYNCBUSY_GENCTRL2
 * GCLK_SYNCBUSY_GENCTRL3
 * GCLK_SYNCBUSY_GENCTRL4
 * GCLK_SYNCBUSY_GENCTRL5
 * GCLK_SYNCBUSY_GENCTRL6
 * GCLK_SYNCBUSY_GENCTRL7
 * GCLK_SYNCBUSY_GENCTRL8
 * GCLK_SYNCBUSY_GENCTRL9
 * GCLK_SYNCBUSY_GENCTRL10
 * GCLK_SYNCBUSY_GENCTRL11
 */

static inline uint32_t gclk_get_SYNCBUSY(uint32_t mask)
{
	return GCLK->SYNCBUSY.reg & mask;
}

/**
 * @brief software reset GCLK controller
 * CTRLA.SWRST must be synchronized before setting
 * CTRLA is global to all GCLK Generators
 */
static inline void gclk_set_SWRST(void)
{
	gclk_wait_for_sync(GCLK_SYNCBUSY_SWRST);
	GCLK->CTRLA.reg = GCLK_CTRLA_SWRST;
}
/**
 * @brief return boolean state of gclk CTRLA SWRST
 * CTRLA is global to all GCLK Generators
 * @return bool false = software reset complete 
 */
static inline bool gclk_read_CTRLA_SWRST(void)
{
	gclk_wait_for_sync(GCLK_SYNCBUSY_SWRST);
	return ((GCLK->CTRLA.reg & GCLK_CTRLA_SWRST) != 0);
}

/**
 * @brief return CTRLA for GCLK
 * GCLK_CTRLA_SWRST	software reset
 * Before reading, CTRLA.SWRST must be synchronized with
 * gclk_wait_for_sync(GCLK_SYNCBUSY_SWRST);
 * CTRLA is global to all GCLK Generators
 * 
 * @return uint8_t
 */
static inline uint8_t gclk_read_CTRLA(void)
{
	return GCLK->CTRLA.reg;
}
/**
 * @brief write configuration to GENCTRL register of GCLK
 * each GCLK generator has its own GENCTRL register 
 * @param[in] uint8_t index 0 - 11 for GCLK0-GCLK11
 * @param[in] uint32_t data bit fields as follows
 * GCLK_GENCTRL_SRC(value)	Source Select
 * GCLK_GENCTRL_GENEN		Generic Clock Generator Enable
 * GCLK_GENCTRL_IDC 		Improve Duty Cycle
 * GCLK_GENCTRL_OOV			Output Off Value
 * GCLK_GENCTRL_OE			Output Enable (1 = GCLK output to external pin
 * GCLK_GENCTRL_DIVSEL		Divide Selection 0 = f/div, 1 = f/2^(div+1)
 * GCLK_GENCTRL_RUNSTDBY	GCLK runs in Standby
 * GCLK_GENCTRL_DIV(value)	Clock division factor (16 bit value for GCLK1, 8 bit for all others)
 * 
 * @note GCLK_GENCTRL_SRC(value) can be replaced with  
 * GCLK_GENCTRL_SRC_XOSC0
 * GCLK_GENCTRL_SRC_XOSC1
 * GCLK_GENCTRL_SRC_GCLKIN
 * GCLK_GENCTRL_SRC_GCLKGEN1
 * GCLK_GENCTRL_SRC_OSCULP32K
 * GCLK_GENCTRL_SRC_XOSC32K
 * GCLK_GENCTRL_SRC_DFLL
 * GCLK_GENCTRL_SRC_DPLL0
 * GCLK_GENCTRL_SRC_DPLL1
 * or use above with GCLK_GENCTRL_SRC(GCLK_GENCTRL_SRC_xxxx_val). Note that the _val 
 * are not bit shifted and GCLK_GENCTRL_SRC(value) does the bit shifting. On the other hand,
 * there is no shifting and it wont matter to the processor.
 */
static inline void gclk_write_GENCTRL(uint8_t index, uint32_t data)
{
	GCLK->GENCTRL[index].reg = data;
}
/**
 * @brief gclk set only the SRC field of GCLK leaving configuration as is
 * each GCLK generator has its own GENCTRL register 
 * @param[in] uint8_t index 0 - 11 for GCLK0-GCLK11
 * @param[in] uint32_t data bit fields as follows
 * GCLK_GENCTRL_SRC(value)	Source Select
 * GCLK_GENCTRL_GENEN		Generic Clock Generator Enable
 * GCLK_GENCTRL_IDC 		Improve Duty Cycle
 * GCLK_GENCTRL_OOV			Output Off Value
 * GCLK_GENCTRL_OE			Output Enable (1 = GCLK output to external pin
 * GCLK_GENCTRL_DIVSEL		Divide Selection 0 = f/div, 1 = f/2^(div+1)
 * GCLK_GENCTRL_RUNSTDBY	GCLK runs in Standby
 * GCLK_GENCTRL_DIV(value)	Clock division factor (16 bit value for GCLK1, 8 bit for all others)
 * 
 * @note GCLK_GENCTRL_SRC(value) can be replaced with  
 * GCLK_GENCTRL_SRC_XOSC0
 * GCLK_GENCTRL_SRC_XOSC1
 * GCLK_GENCTRL_SRC_GCLKIN
 * GCLK_GENCTRL_SRC_GCLKGEN1
 * GCLK_GENCTRL_SRC_OSCULP32K
 * GCLK_GENCTRL_SRC_XOSC32K
 * GCLK_GENCTRL_SRC_DFLL
 * GCLK_GENCTRL_SRC_DPLL0
 * GCLK_GENCTRL_SRC_DPLL1
 * or use above with GCLK_GENCTRL_SRC(GCLK_GENCTRL_SRC_xxxx_val). Note that the _val 
 * are not bit shifted and GCLK_GENCTRL_SRC(value) does the bit shifting. On the other hand,
 * there is no shifting and it wont matter to the processor.
 */
static inline void gclk_set_GENCTRL_SRC(uint8_t index, uint32_t data)
{
	GCLK->GENCTRL[index].reg = (GCLK->GENCTRL[index].reg & ~GCLK_GENCTRL_SRC_Msk) | data;
}
/**
 * @brief get the contents of the GENCTRL register for GCLKn where n is index 0 to 11
 *
 * @param[in] uint8_t index 0-11 for GCLK0 to GCLK11 generator
 * @return uint32_t 32 bit GENCTRL register for GCLKn
 */
static inline uint32_t gclk_read_GENCTRL(uint8_t index)
{
	return GCLK->GENCTRL[index].reg;
}
/**
 * @brief write to peripheral control channel register with data
 *
 * @param[in] uint8_t index 0-47 to select peripheral
 * OSCCTRL_GCLK_ID_DFLL48    Index of Generic Clock for DFLL48 (oscctrl.h) 
 * OSCCTRL_GCLK_ID_FDPLL0    Index of Generic Clock for DPLL0  (oscctrl.h)  
 * OSCCTRL_GCLK_ID_FDPLL1    Index of Generic Clock for DPLL1  (oscctrl.h) 
 * OSCCTRL_GCLK_ID_FDPLL032K  Index of Generic Clock for DPLL0 32K  (oscctrl.h)
 * OSCCTRL_GCLK_ID_FDPLL132K  Index of Generic Clock for DPLL1 32K  (oscctrl.h)
 * SDHC0_GCLK_ID_SLOW    Index of Generic Clock for SHDC0 slow (sdhc0.h)
 * SDHC1_GCLK_ID_SLOW    Index of Generic Clock for SHDC1 slow (sdhc1.h)
 * SERCOM0_GCLK_ID_SLOW  Index of Generic Clock for SERCOM0 slow (sercom0.h)
 * SERCOM1_GCLK_ID_SLOW  Index of Generic Clock for SERCOM1 slow (sercom1.h)
 * SERCOM2_GCLK_ID_SLOW  Index of Generic Clock for SERCOM2 slow (sercom2.h)
 * SERCOM3_GCLK_ID_SLOW  Index of Generic Clock for SERCOM3 slow (sercom3.h)
 * SERCOM4_GCLK_ID_SLOW  Index of Generic Clock for SERCOM4 slow (sercom4.h)
 * SERCOM5_GCLK_ID_SLOW  Index of Generic Clock for SERCOM5 slow (sercom5.h)
 * EIC_GCLK_ID		     Index of Generic Clock for EIC (eic.h)
 * FREQM_GCLK_ID_MSR	 Index of Generic Clock for FREQM measure (freqm.h)
 * FREQM_GCLK_ID_REF	 Index of Generic Clock for FREQM reference (freqm.h)
 * SERCOM0_GCLK_ID_CORE  Index of Generic Clock for SERCOM0 fast (sercom0.h)
 * SERCOM1_GCLK_ID_CORE  Index of Generic Clock for SERCOM1 fast (sercom1.h)
 * TC0_GCLK_ID	         Index of Generic Clock for Timer/Counter TC0 (tc0.h)
 * TC1_GCLK_ID		    Index of Generic Clock for Timer/Counter TC1 (tc1.h)
 * USB_GCLK_ID 	        Index of Generic Clock for USB (usb.h)
 * EVSYS_GCLK_ID_0	    Index of Generic Clock for Event System 0 (evsys.h)
 * EVSYS_GCLK_ID_1	    Index of Generic Clock for Event System 1 (evsys.h)
 * EVSYS_GCLK_ID_2	    Index of Generic Clock for Event System 2 (evsys.h)
 * EVSYS_GCLK_ID_3	    Index of Generic Clock for Event System 3 (evsys.h)
 * EVSYS_GCLK_ID_4	    Index of Generic Clock for Event System 4 (evsys.h)
 * EVSYS_GCLK_ID_5	    Index of Generic Clock for Event System 5 (evsys.h)
 * EVSYS_GCLK_ID_6	    Index of Generic Clock for Event System 6 (evsys.h)
 * EVSYS_GCLK_ID_7	    Index of Generic Clock for Event System 7 (evsys.h)
 * EVSYS_GCLK_ID_8	    Index of Generic Clock for Event System 8 (evsys.h)
 * EVSYS_GCLK_ID_9	    Index of Generic Clock for Event System 9 (evsys.h)
 * EVSYS_GCLK_ID_10     Index of Generic Clock for Event System 10 (evsys.h)
 * EVSYS_GCLK_ID_11     Index of Generic Clock for Event System 11 (evsys.h)
 * SERCOM2_GCLK_ID_CORE Index of Generic Clock for SERCOM2 fast (sercom2.h)
 * SERCOM3_GCLK_ID_CORE Index of Generic Clock for SERCOM3 fast (sercom3.h)
 * TCC0_GCLK_ID	        Index of Generic Clock for TCC0 (tcc0.h)
 * TCC1_GCLK_ID	        Index of Generic Clock for TCC1 (tcc1.h)
 * TC2_GCLK_ID          Index of Generic Clock for Timer/Counter TC2 (tc2.h)
 * TC3_GCLK_ID          Index of Generic Clock for Timer/Counter TC3 (tc3.h)
 * CAN0_GCLK_ID		    Index of Generic Clock for CAN0 (can0.h)
 * CAN1_GCLK_ID	        Index of Generic Clock for CAN1 (can1.h)
 * TCC2_GCLK_ID	        Index of Generic Clock for TCC2 (tcc2.h)
 * TCC3_GCLK_ID	        Index of Generic Clock for TCC3 (tcc3.h)
 * TC4_GCLK_ID          Index of Generic Clock for Timer/Counter TC4 (tc4.h)
 * TC5_GCLK_ID          Index of Generic Clock for Timer/Counter TC5 (tc5.h)
 * PDEC_GCLK_ID		    Index of Generic Clock for Position Decoder PDEC (pdec.h)
 * AC_GCLK_ID		    Index of Generic Clock for Analog Comparator AC (ac.h)
 * CCL_GCLK_ID		    Index of Generic Clock for Configurable Custom Logic CCL (ccl.h)
 * SERCOM4_GCLK_ID_CORE Index of Generic Clock for SERCOM4 fast (sercom4.h)
 * SERCOM5_GCLK_ID_CORE Index of Generic Clock for SERCOM5 fast (sercom5.h)
 * TCC4_GCLK_ID	 	    Index of Generic Clock for Timer/Counter TCC4 (tcc4.h)
 * ADC0_GCLK_ID		    Index of Generic Clock for ADC0 (adc0.h)
 * ADC1_GCLK_ID	        Index of Generic Clock for ADC1 (adc1.h)
 * DAC_GCLK_ID		    Index of Generic Clock for DAC (dac.h)
 * I2S_GCLK_ID_0        Index of Generic Clock for I2S0 (i2s.h)
 * I2S_GCLK_ID_1        Index of Generic Clock for I2S1 (i2s.h)
 * SDHC0_GCLK_ID        Index of Generic Clock for SHDC0 fast (sdhc0.h)
 * SDHC1_GCLK_ID	    Index of Generic Clock for SHDC1 fast (sdhc1.h)
 *
 * @param[in] uint32_t data 
 * GCLK_PCHCTRL_GEN(value) Generic clock generator n
 * GCLK_PCHCTRL_CHEN	Channel Enable
 * GCLK_PCHCTRL_WRTLOCK	Write Lock
 * @note GCLK_PCHCTRL_GEN(value) can be replaced with 
 * GCLK_PCHCTRL_GEN_GCLK0 
 * GCLK_PCHCTRL_GEN_GCLK1 
 * GCLK_PCHCTRL_GEN_GCLK2 
 * GCLK_PCHCTRL_GEN_GCLK3 
 * GCLK_PCHCTRL_GEN_GCLK4 
 * GCLK_PCHCTRL_GEN_GCLK5 
 * GCLK_PCHCTRL_GEN_GCLK6 
 * GCLK_PCHCTRL_GEN_GCLK7 
 * GCLK_PCHCTRL_GEN_GCLK8 
 * GCLK_PCHCTRL_GEN_GCLK9 
 * GCLK_PCHCTRL_GEN_GCLK10
 * GCLK_PCHCTRL_GEN_GCLK11
 *
 */
static inline void gclk_write_PCHCTRL(uint8_t index, uint32_t data)
{
	GCLK->PCHCTRL[index].reg = data;
}
/**
 * @brief get the contents of the PCHCTRL register for GCLKn where n is index 0 to 11
 *
 * @param[in] uint8_t index 0 to 11 for GCLK0 to GCLK11
 * @return uint32_t 32 bit PCHCTRL register contents
 */
static inline uint32_t gclk_read_PCHCTRL(uint8_t index)
{
	return GCLK->PCHCTRL[index].reg;
}

/**
 * @brief get the contents of the PCHCTRL register for GCLKn where n is index 0 to 11
 *
 * @param[in] uint8_t index 0 to 11 for GCLK0 to GCLK11
 * @return uint32_t 32 bit PCHCTRL register contents
 */
static inline uint32_t gclk_get_PCHCTRL(uint8_t index, uint32_t mask)
{
	return GCLK->PCHCTRL[index].reg & mask;
}


#endif /* _GCLK_H_ */
