/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM CCL
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

#ifndef _CCL_H_
#define _CCL_H_

#include <stdbool.h>

/**
 * @brief ccl set CTRL register
 *
 * @param[in] mask uint8_t 
 * - CCL_CTRL_SWRST Software Reset
 * - CCL_CTRL_ENABLE Enable
 * - CCL_CTRL_RUNSTDBY Run in Standby
 **/
static inline void ccl_set_CTRL(uint8_t mask)
{
	CCL->CTRL.reg |= mask;
}

/**
 * @brief ccl get CTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - CCL_CTRL_SWRST Software Reset
 * - CCL_CTRL_ENABLE Enable
 * - CCL_CTRL_RUNSTDBY Run in Standby
 **/
static inline uint8_t ccl_get_CTRL(uint8_t mask)
{
    return CCL->CTRL.reg & mask;
}

/**
 * @brief ccl write CTRL register
 *
 * @param[in] data uint8_t 
 * - CCL_CTRL_SWRST Software Reset
 * - CCL_CTRL_ENABLE Enable
 * - CCL_CTRL_RUNSTDBY Run in Standby
 **/
static inline void ccl_write_CTRL(uint8_t data)
{
	CCL->CTRL.reg = data;
}

/**
 * @brief ccl clear CTRL register
 *
 * @param[in] mask uint8_t 
 * - CCL_CTRL_SWRST Software Reset
 * - CCL_CTRL_ENABLE Enable
 * - CCL_CTRL_RUNSTDBY Run in Standby
 **/
static inline void ccl_clear_CTRL(uint8_t mask)
{
	CCL->CTRL.reg &= ~mask;
}

/**
 * @brief ccl read CTRL register
 *
 * @return uint8_t
 * - CCL_CTRL_SWRST Software Reset
 * - CCL_CTRL_ENABLE Enable
 * - CCL_CTRL_RUNSTDBY Run in Standby
 **/
static inline uint8_t ccl_read_CTRL(void)
{
	return CCL->CTRL.reg;
}

/**
 * @brief ccl set SEQCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint8_t 
 * - CCL_SEQCTRL_SEQSEL(value) Sequential Selection
 *  +      CCL_SEQCTRL_SEQSEL_DISABLE Sequential logic is disabled
 *  +      CCL_SEQCTRL_SEQSEL_DFF D flip flop
 *  +      CCL_SEQCTRL_SEQSEL_JK JK flip flop
 *  +      CCL_SEQCTRL_SEQSEL_LATCH D latch
 *  +      CCL_SEQCTRL_SEQSEL_RS RS latch
 **/
static inline void ccl_set_SEQCTRL(uint8_t index, uint8_t mask)
{
	CCL->SEQCTRL[index].reg |= mask;
}

/**
 * @brief ccl get SEQCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - CCL_SEQCTRL_SEQSEL(value) Sequential Selection
 *  +      CCL_SEQCTRL_SEQSEL_DISABLE Sequential logic is disabled
 *  +      CCL_SEQCTRL_SEQSEL_DFF D flip flop
 *  +      CCL_SEQCTRL_SEQSEL_JK JK flip flop
 *  +      CCL_SEQCTRL_SEQSEL_LATCH D latch
 *  +      CCL_SEQCTRL_SEQSEL_RS RS latch
 **/
static inline uint8_t ccl_get_SEQCTRL(uint8_t index, uint8_t mask)
{
    return CCL->SEQCTRL[index].reg & mask;
}

/**
 * @brief ccl write SEQCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint8_t 
 * - CCL_SEQCTRL_SEQSEL(value) Sequential Selection
 *  +      CCL_SEQCTRL_SEQSEL_DISABLE Sequential logic is disabled
 *  +      CCL_SEQCTRL_SEQSEL_DFF D flip flop
 *  +      CCL_SEQCTRL_SEQSEL_JK JK flip flop
 *  +      CCL_SEQCTRL_SEQSEL_LATCH D latch
 *  +      CCL_SEQCTRL_SEQSEL_RS RS latch
 **/
static inline void ccl_write_SEQCTRL(uint8_t index, uint8_t data)
{
	CCL->SEQCTRL[index].reg = data;
}

/**
 * @brief ccl clear SEQCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint8_t 
 * - CCL_SEQCTRL_SEQSEL(value) Sequential Selection
 *  +      CCL_SEQCTRL_SEQSEL_DISABLE Sequential logic is disabled
 *  +      CCL_SEQCTRL_SEQSEL_DFF D flip flop
 *  +      CCL_SEQCTRL_SEQSEL_JK JK flip flop
 *  +      CCL_SEQCTRL_SEQSEL_LATCH D latch
 *  +      CCL_SEQCTRL_SEQSEL_RS RS latch
 **/
static inline void ccl_clear_SEQCTRL(uint8_t index, uint8_t mask)
{
	CCL->SEQCTRL[index].reg &= ~mask;
}

/**
 * @brief ccl read SEQCTRL register
 *
 * @param[in] index uint8_t 
 * @return uint8_t
 * - CCL_SEQCTRL_SEQSEL(value) Sequential Selection
 *  +      CCL_SEQCTRL_SEQSEL_DISABLE Sequential logic is disabled
 *  +      CCL_SEQCTRL_SEQSEL_DFF D flip flop
 *  +      CCL_SEQCTRL_SEQSEL_JK JK flip flop
 *  +      CCL_SEQCTRL_SEQSEL_LATCH D latch
 *  +      CCL_SEQCTRL_SEQSEL_RS RS latch
 **/
static inline uint8_t ccl_read_SEQCTRL(uint8_t index)
{
	return CCL->SEQCTRL[index].reg;
}

/**
 * @brief ccl set LUTCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - CCL_LUTCTRL_ENABLE LUT Enable
 * - CCL_LUTCTRL_FILTSEL(value) Filter Selection
 *  +      CCL_LUTCTRL_FILTSEL_DISABLE Filter disabled
 *  +      CCL_LUTCTRL_FILTSEL_SYNCH Synchronizer enabled
 *  +      CCL_LUTCTRL_FILTSEL_FILTER Filter enabled
 * - CCL_LUTCTRL_EDGESEL Edge Selection
 * - CCL_LUTCTRL_INSEL0(value) Input Selection 0
 *  +      CCL_LUTCTRL_INSEL0_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL0_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL0_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL0_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL0_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL0_AC AC input source
 *  +      CCL_LUTCTRL_INSEL0_TC TC input source
 *  +      CCL_LUTCTRL_INSEL0_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL0_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL0_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL1(value) Input Selection 1
 *  +      CCL_LUTCTRL_INSEL1_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL1_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL1_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL1_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL1_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL1_AC AC input source
 *  +      CCL_LUTCTRL_INSEL1_TC TC input source
 *  +      CCL_LUTCTRL_INSEL1_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL1_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL1_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL2(value) Input Selection 2
 *  +      CCL_LUTCTRL_INSEL2_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL2_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL2_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL2_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL2_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL2_AC AC input source
 *  +      CCL_LUTCTRL_INSEL2_TC TC input source
 *  +      CCL_LUTCTRL_INSEL2_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL2_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL2_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INVEI Inverted Event Input Enable
 * - CCL_LUTCTRL_LUTEI LUT Event Input Enable
 * - CCL_LUTCTRL_LUTEO LUT Event Output Enable
 * - CCL_LUTCTRL_TRUTH(value) Truth Value
 **/
static inline void ccl_set_LUTCTRL(uint8_t index, uint32_t mask)
{
	CCL->LUTCTRL[index].reg |= mask;
}

/**
 * @brief ccl get LUTCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - CCL_LUTCTRL_ENABLE LUT Enable
 * - CCL_LUTCTRL_FILTSEL(value) Filter Selection
 *  +      CCL_LUTCTRL_FILTSEL_DISABLE Filter disabled
 *  +      CCL_LUTCTRL_FILTSEL_SYNCH Synchronizer enabled
 *  +      CCL_LUTCTRL_FILTSEL_FILTER Filter enabled
 * - CCL_LUTCTRL_EDGESEL Edge Selection
 * - CCL_LUTCTRL_INSEL0(value) Input Selection 0
 *  +      CCL_LUTCTRL_INSEL0_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL0_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL0_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL0_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL0_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL0_AC AC input source
 *  +      CCL_LUTCTRL_INSEL0_TC TC input source
 *  +      CCL_LUTCTRL_INSEL0_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL0_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL0_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL1(value) Input Selection 1
 *  +      CCL_LUTCTRL_INSEL1_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL1_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL1_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL1_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL1_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL1_AC AC input source
 *  +      CCL_LUTCTRL_INSEL1_TC TC input source
 *  +      CCL_LUTCTRL_INSEL1_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL1_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL1_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL2(value) Input Selection 2
 *  +      CCL_LUTCTRL_INSEL2_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL2_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL2_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL2_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL2_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL2_AC AC input source
 *  +      CCL_LUTCTRL_INSEL2_TC TC input source
 *  +      CCL_LUTCTRL_INSEL2_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL2_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL2_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INVEI Inverted Event Input Enable
 * - CCL_LUTCTRL_LUTEI LUT Event Input Enable
 * - CCL_LUTCTRL_LUTEO LUT Event Output Enable
 * - CCL_LUTCTRL_TRUTH(value) Truth Value
 **/
static inline uint32_t ccl_get_LUTCTRL(uint8_t index, uint32_t mask)
{
    return CCL->LUTCTRL[index].reg & mask;
}

/**
 * @brief ccl write LUTCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - CCL_LUTCTRL_ENABLE LUT Enable
 * - CCL_LUTCTRL_FILTSEL(value) Filter Selection
 *  +      CCL_LUTCTRL_FILTSEL_DISABLE Filter disabled
 *  +      CCL_LUTCTRL_FILTSEL_SYNCH Synchronizer enabled
 *  +      CCL_LUTCTRL_FILTSEL_FILTER Filter enabled
 * - CCL_LUTCTRL_EDGESEL Edge Selection
 * - CCL_LUTCTRL_INSEL0(value) Input Selection 0
 *  +      CCL_LUTCTRL_INSEL0_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL0_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL0_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL0_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL0_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL0_AC AC input source
 *  +      CCL_LUTCTRL_INSEL0_TC TC input source
 *  +      CCL_LUTCTRL_INSEL0_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL0_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL0_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL1(value) Input Selection 1
 *  +      CCL_LUTCTRL_INSEL1_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL1_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL1_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL1_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL1_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL1_AC AC input source
 *  +      CCL_LUTCTRL_INSEL1_TC TC input source
 *  +      CCL_LUTCTRL_INSEL1_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL1_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL1_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL2(value) Input Selection 2
 *  +      CCL_LUTCTRL_INSEL2_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL2_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL2_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL2_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL2_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL2_AC AC input source
 *  +      CCL_LUTCTRL_INSEL2_TC TC input source
 *  +      CCL_LUTCTRL_INSEL2_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL2_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL2_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INVEI Inverted Event Input Enable
 * - CCL_LUTCTRL_LUTEI LUT Event Input Enable
 * - CCL_LUTCTRL_LUTEO LUT Event Output Enable
 * - CCL_LUTCTRL_TRUTH(value) Truth Value
 **/
static inline void ccl_write_LUTCTRL(uint8_t index, uint32_t data)
{
	CCL->LUTCTRL[index].reg = data;
}

/**
 * @brief ccl clear LUTCTRL register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - CCL_LUTCTRL_ENABLE LUT Enable
 * - CCL_LUTCTRL_FILTSEL(value) Filter Selection
 *  +      CCL_LUTCTRL_FILTSEL_DISABLE Filter disabled
 *  +      CCL_LUTCTRL_FILTSEL_SYNCH Synchronizer enabled
 *  +      CCL_LUTCTRL_FILTSEL_FILTER Filter enabled
 * - CCL_LUTCTRL_EDGESEL Edge Selection
 * - CCL_LUTCTRL_INSEL0(value) Input Selection 0
 *  +      CCL_LUTCTRL_INSEL0_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL0_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL0_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL0_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL0_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL0_AC AC input source
 *  +      CCL_LUTCTRL_INSEL0_TC TC input source
 *  +      CCL_LUTCTRL_INSEL0_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL0_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL0_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL1(value) Input Selection 1
 *  +      CCL_LUTCTRL_INSEL1_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL1_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL1_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL1_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL1_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL1_AC AC input source
 *  +      CCL_LUTCTRL_INSEL1_TC TC input source
 *  +      CCL_LUTCTRL_INSEL1_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL1_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL1_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL2(value) Input Selection 2
 *  +      CCL_LUTCTRL_INSEL2_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL2_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL2_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL2_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL2_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL2_AC AC input source
 *  +      CCL_LUTCTRL_INSEL2_TC TC input source
 *  +      CCL_LUTCTRL_INSEL2_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL2_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL2_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INVEI Inverted Event Input Enable
 * - CCL_LUTCTRL_LUTEI LUT Event Input Enable
 * - CCL_LUTCTRL_LUTEO LUT Event Output Enable
 * - CCL_LUTCTRL_TRUTH(value) Truth Value
 **/
static inline void ccl_clear_LUTCTRL(uint8_t index, uint32_t mask)
{
	CCL->LUTCTRL[index].reg &= ~mask;
}

/**
 * @brief ccl read LUTCTRL register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - CCL_LUTCTRL_ENABLE LUT Enable
 * - CCL_LUTCTRL_FILTSEL(value) Filter Selection
 *  +      CCL_LUTCTRL_FILTSEL_DISABLE Filter disabled
 *  +      CCL_LUTCTRL_FILTSEL_SYNCH Synchronizer enabled
 *  +      CCL_LUTCTRL_FILTSEL_FILTER Filter enabled
 * - CCL_LUTCTRL_EDGESEL Edge Selection
 * - CCL_LUTCTRL_INSEL0(value) Input Selection 0
 *  +      CCL_LUTCTRL_INSEL0_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL0_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL0_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL0_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL0_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL0_AC AC input source
 *  +      CCL_LUTCTRL_INSEL0_TC TC input source
 *  +      CCL_LUTCTRL_INSEL0_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL0_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL0_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL1(value) Input Selection 1
 *  +      CCL_LUTCTRL_INSEL1_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL1_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL1_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL1_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL1_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL1_AC AC input source
 *  +      CCL_LUTCTRL_INSEL1_TC TC input source
 *  +      CCL_LUTCTRL_INSEL1_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL1_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL1_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INSEL2(value) Input Selection 2
 *  +      CCL_LUTCTRL_INSEL2_MASK Masked input
 *  +      CCL_LUTCTRL_INSEL2_FEEDBACK Feedback input source
 *  +      CCL_LUTCTRL_INSEL2_LINK Linked LUT input source
 *  +      CCL_LUTCTRL_INSEL2_EVENT Event input source
 *  +      CCL_LUTCTRL_INSEL2_IO I/O pin input source
 *  +      CCL_LUTCTRL_INSEL2_AC AC input source
 *  +      CCL_LUTCTRL_INSEL2_TC TC input source
 *  +      CCL_LUTCTRL_INSEL2_ALTTC Alternate TC input source
 *  +      CCL_LUTCTRL_INSEL2_TCC TCC input source
 *  +      CCL_LUTCTRL_INSEL2_SERCOM SERCOM input source
 * - CCL_LUTCTRL_INVEI Inverted Event Input Enable
 * - CCL_LUTCTRL_LUTEI LUT Event Input Enable
 * - CCL_LUTCTRL_LUTEO LUT Event Output Enable
 * - CCL_LUTCTRL_TRUTH(value) Truth Value
 **/
static inline uint32_t ccl_read_LUTCTRL(uint8_t index)
{
	return CCL->LUTCTRL[index].reg;
}

#endif /* _CCL_H */
