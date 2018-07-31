/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM TCC
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

#ifndef _TCC_H_
#define _TCC_H_

#include <stdbool.h>

/**
 * @brief tcc wait for sync
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t reg
 * TCC_SYNCBUSY_SWRST  Swrst Busy 
 * TCC_SYNCBUSY_ENABLE  Enable Busy 
 * TCC_SYNCBUSY_CTRLB  Ctrlb Busy 
 * TCC_SYNCBUSY_STATUS  Status Busy 
 * TCC_SYNCBUSY_COUNT  Count Busy 
 * TCC_SYNCBUSY_PATT  Pattern Busy 
 * TCC_SYNCBUSY_WAVE  Wave Busy 
 * TCC_SYNCBUSY_PER  Period Busy 
 * TCC_SYNCBUSY_CC0  Compare Channel 0 Busy 
 * TCC_SYNCBUSY_CC1  Compare Channel 1 Busy 
 * TCC_SYNCBUSY_CC2  Compare Channel 2 Busy 
 * TCC_SYNCBUSY_CC3  Compare Channel 3 Busy 
 * TCC_SYNCBUSY_CC4  Compare Channel 4 Busy 
 * TCC_SYNCBUSY_CC5  Compare Channel 5 Busy 
 */
static inline void tcc_wait_for_sync(TCC_t *pTCC, uint32_t reg)
{
	while (pTCC->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief tcc is syncing
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t reg
 * TCC_SYNCBUSY_SWRST  Swrst Busy 
 * TCC_SYNCBUSY_ENABLE  Enable Busy 
 * TCC_SYNCBUSY_CTRLB  Ctrlb Busy 
 * TCC_SYNCBUSY_STATUS  Status Busy 
 * TCC_SYNCBUSY_COUNT  Count Busy 
 * TCC_SYNCBUSY_PATT  Pattern Busy 
 * TCC_SYNCBUSY_WAVE  Wave Busy 
 * TCC_SYNCBUSY_PER  Period Busy 
 * TCC_SYNCBUSY_CC0  Compare Channel 0 Busy 
 * TCC_SYNCBUSY_CC1  Compare Channel 1 Busy 
 * TCC_SYNCBUSY_CC2  Compare Channel 2 Busy 
 * TCC_SYNCBUSY_CC3  Compare Channel 3 Busy 
 * TCC_SYNCBUSY_CC4  Compare Channel 4 Busy 
 * TCC_SYNCBUSY_CC5  Compare Channel 5 Busy 
 * @return bool
 */
static inline bool tcc_is_syncing(TCC_t *pTCC, uint32_t reg)
{
	return pTCC->SYNCBUSY.reg & reg;
}

/**
 * @brief tcc set COUNT register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_COUNT_DITH4_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH5_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH6_COUNT(value)  Counter Value 
 * TCC_COUNT_COUNT(value)  Counter Value 
 */
static inline void tcc_set_COUNT(TCC_t *pTCC, uint32_t mask)
{
	pTCC->COUNT.reg |= mask;
}

/**
 * @brief tcc get COUNT register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_COUNT_DITH4_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH5_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH6_COUNT(value)  Counter Value 
 * TCC_COUNT_COUNT(value)  Counter Value 
 */
static inline uint32_t tcc_get_COUNT(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->COUNT.reg & mask;
}

/**
 * @brief tcc write COUNT register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_COUNT_DITH4_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH5_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH6_COUNT(value)  Counter Value 
 * TCC_COUNT_COUNT(value)  Counter Value 
 */
static inline void tcc_write_COUNT(TCC_t *pTCC, uint32_t data)
{
	pTCC->COUNT.reg = data;
}

/**
 * @brief tcc clear COUNT register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_COUNT_DITH4_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH5_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH6_COUNT(value)  Counter Value 
 * TCC_COUNT_COUNT(value)  Counter Value 
 */
static inline void tcc_clear_COUNT(TCC_t *pTCC, uint32_t mask)
{
	pTCC->COUNT.reg &= ~mask;
}

/**
 * @brief tcc read COUNT register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_COUNT_DITH4_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH5_COUNT(value)  Counter Value 
 * TCC_COUNT_DITH6_COUNT(value)  Counter Value 
 * TCC_COUNT_COUNT(value)  Counter Value 
 */
static inline uint32_t tcc_read_COUNT(TCC_t *pTCC)
{
	return pTCC->COUNT.reg;
}

/**
 * @brief tcc set PER register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_PER_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH4_PER(value)  Period Value 
 * TCC_PER_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH5_PER(value)  Period Value 
 * TCC_PER_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH6_PER(value)  Period Value 
 * TCC_PER_PER(value)  Period Value 
 */
static inline void tcc_set_PER(TCC_t *pTCC, uint32_t mask)
{
	pTCC->PER.reg |= mask;
}

/**
 * @brief tcc get PER register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_PER_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH4_PER(value)  Period Value 
 * TCC_PER_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH5_PER(value)  Period Value 
 * TCC_PER_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH6_PER(value)  Period Value 
 * TCC_PER_PER(value)  Period Value 
 */
static inline uint32_t tcc_get_PER(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->PER.reg & mask;
}

/**
 * @brief tcc write PER register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_PER_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH4_PER(value)  Period Value 
 * TCC_PER_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH5_PER(value)  Period Value 
 * TCC_PER_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH6_PER(value)  Period Value 
 * TCC_PER_PER(value)  Period Value 
 */
static inline void tcc_write_PER(TCC_t *pTCC, uint32_t data)
{
	pTCC->PER.reg = data;
}

/**
 * @brief tcc clear PER register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_PER_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH4_PER(value)  Period Value 
 * TCC_PER_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH5_PER(value)  Period Value 
 * TCC_PER_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH6_PER(value)  Period Value 
 * TCC_PER_PER(value)  Period Value 
 */
static inline void tcc_clear_PER(TCC_t *pTCC, uint32_t mask)
{
	pTCC->PER.reg &= ~mask;
}

/**
 * @brief tcc read PER register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_PER_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH4_PER(value)  Period Value 
 * TCC_PER_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH5_PER(value)  Period Value 
 * TCC_PER_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_PER_DITH6_PER(value)  Period Value 
 * TCC_PER_PER(value)  Period Value 
 */
static inline uint32_t tcc_read_PER(TCC_t *pTCC)
{
	return pTCC->PER.reg;
}

/**
 * @brief tcc set CC register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * TCC_CC_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH4_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH5_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH6_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_CC(value)  Channel Compare/Capture Value 
 */
static inline void tcc_set_CC(TCC_t *pTCC, uint8_t index, uint32_t mask)
{
	pTCC->CC[index].reg |= mask;
}

/**
 * @brief tcc get CC register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_CC_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH4_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH5_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH6_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_CC(value)  Channel Compare/Capture Value 
 */
static inline uint32_t tcc_get_CC(TCC_t *pTCC, uint8_t index, uint32_t mask)
{
    return pTCC->CC[index].reg & mask;
}

/**
 * @brief tcc write CC register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @param[in] uint32_t data
 * TCC_CC_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH4_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH5_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH6_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_CC(value)  Channel Compare/Capture Value 
 */
static inline void tcc_write_CC(TCC_t *pTCC, uint8_t index, uint32_t data)
{
	pTCC->CC[index].reg = data;
}

/**
 * @brief tcc clear CC register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * TCC_CC_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH4_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH5_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH6_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_CC(value)  Channel Compare/Capture Value 
 */
static inline void tcc_clear_CC(TCC_t *pTCC, uint8_t index, uint32_t mask)
{
	pTCC->CC[index].reg &= ~mask;
}

/**
 * @brief tcc read CC register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @return uint32_t
 * TCC_CC_DITH4_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH4_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH5_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH5_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_DITH6_DITHER(value)  Dithering Cycle Number 
 * TCC_CC_DITH6_CC(value)  Channel Compare/Capture Value 
 * TCC_CC_CC(value)  Channel Compare/Capture Value 
 */
static inline uint32_t tcc_read_CC(TCC_t *pTCC, uint8_t index)
{
	return pTCC->CC[index].reg;
}

/**
 * @brief tcc set PERBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_PERBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH4_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH5_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH6_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_PERBUF(value)  Period Buffer Value 
 */
static inline void tcc_set_PERBUF(TCC_t *pTCC, uint32_t mask)
{
	pTCC->PERBUF.reg |= mask;
}

/**
 * @brief tcc get PERBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_PERBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH4_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH5_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH6_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_PERBUF(value)  Period Buffer Value 
 */
static inline uint32_t tcc_get_PERBUF(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->PERBUF.reg & mask;
}

/**
 * @brief tcc write PERBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_PERBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH4_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH5_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH6_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_PERBUF(value)  Period Buffer Value 
 */
static inline void tcc_write_PERBUF(TCC_t *pTCC, uint32_t data)
{
	pTCC->PERBUF.reg = data;
}

/**
 * @brief tcc clear PERBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_PERBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH4_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH5_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH6_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_PERBUF(value)  Period Buffer Value 
 */
static inline void tcc_clear_PERBUF(TCC_t *pTCC, uint32_t mask)
{
	pTCC->PERBUF.reg &= ~mask;
}

/**
 * @brief tcc read PERBUF register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_PERBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH4_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH5_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_PERBUF_DITH6_PERBUF(value)  Period Buffer Value 
 * TCC_PERBUF_PERBUF(value)  Period Buffer Value 
 */
static inline uint32_t tcc_read_PERBUF(TCC_t *pTCC)
{
	return pTCC->PERBUF.reg;
}

/**
 * @brief tcc set CCBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * TCC_CCBUF_DITH4_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH6_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_CCBUF(value)  Channel Compare/Capture Buffer Value 
 */
static inline void tcc_set_CCBUF(TCC_t *pTCC, uint8_t index, uint32_t mask)
{
	pTCC->CCBUF[index].reg |= mask;
}

/**
 * @brief tcc get CCBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_CCBUF_DITH4_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH6_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_CCBUF(value)  Channel Compare/Capture Buffer Value 
 */
static inline uint32_t tcc_get_CCBUF(TCC_t *pTCC, uint8_t index, uint32_t mask)
{
    return pTCC->CCBUF[index].reg & mask;
}

/**
 * @brief tcc write CCBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @param[in] uint32_t data
 * TCC_CCBUF_DITH4_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH6_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_CCBUF(value)  Channel Compare/Capture Buffer Value 
 */
static inline void tcc_write_CCBUF(TCC_t *pTCC, uint8_t index, uint32_t data)
{
	pTCC->CCBUF[index].reg = data;
}

/**
 * @brief tcc clear CCBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @param[in] uint32_t mask
 * TCC_CCBUF_DITH4_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH6_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_CCBUF(value)  Channel Compare/Capture Buffer Value 
 */
static inline void tcc_clear_CCBUF(TCC_t *pTCC, uint8_t index, uint32_t mask)
{
	pTCC->CCBUF[index].reg &= ~mask;
}

/**
 * @brief tcc read CCBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t index
 * @return uint32_t
 * TCC_CCBUF_DITH4_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH4_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH5_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_DITH6_DITHERBUF(value)  Dithering Buffer Cycle Number 
 * TCC_CCBUF_DITH6_CCBUF(value)  Channel Compare/Capture Buffer Value 
 * TCC_CCBUF_CCBUF(value)  Channel Compare/Capture Buffer Value 
 */
static inline uint32_t tcc_read_CCBUF(TCC_t *pTCC, uint8_t index)
{
	return pTCC->CCBUF[index].reg;
}

/**
 * @brief tcc set CTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t mask
 * TCC_CTRLBSET_DIR  Counter Direction 
 * TCC_CTRLBSET_LUPD  Lock Update 
 * TCC_CTRLBSET_ONESHOT  One-Shot 
 * TCC_CTRLBSET_IDXCMD(value)  Ramp Index Command 
 *    TCC_CTRLBSET_IDXCMD_DISABLE  Command disabled: Index toggles between cycles A and B 
 *    TCC_CTRLBSET_IDXCMD_SET  Set index: cycle B will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_CLEAR  Clear index: cycle A will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_HOLD  Hold index: the next cycle will be the same as the current cycle 
 * TCC_CTRLBSET_CMD(value)  TCC Command 
 *    TCC_CTRLBSET_CMD_NONE  No action 
 *    TCC_CTRLBSET_CMD_RETRIGGER  Clear start, restart or retrigger 
 *    TCC_CTRLBSET_CMD_STOP  Force stop 
 *    TCC_CTRLBSET_CMD_UPDATE  Force update or double buffered registers 
 *    TCC_CTRLBSET_CMD_READSYNC  Force COUNT read synchronization 
 *    TCC_CTRLBSET_CMD_DMAOS  One-shot DMA trigger 
 */
static inline void tcc_set_CTRLB(TCC_t *pTCC, uint8_t mask)
{
	pTCC->CTRLBSET.reg = mask;
}

/**
 * @brief tcc get CTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t mask
 * @return uint8_t
 * TCC_CTRLBSET_DIR  Counter Direction 
 * TCC_CTRLBSET_LUPD  Lock Update 
 * TCC_CTRLBSET_ONESHOT  One-Shot 
 * TCC_CTRLBSET_IDXCMD(value)  Ramp Index Command 
 *    TCC_CTRLBSET_IDXCMD_DISABLE  Command disabled: Index toggles between cycles A and B 
 *    TCC_CTRLBSET_IDXCMD_SET  Set index: cycle B will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_CLEAR  Clear index: cycle A will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_HOLD  Hold index: the next cycle will be the same as the current cycle 
 * TCC_CTRLBSET_CMD(value)  TCC Command 
 *    TCC_CTRLBSET_CMD_NONE  No action 
 *    TCC_CTRLBSET_CMD_RETRIGGER  Clear start, restart or retrigger 
 *    TCC_CTRLBSET_CMD_STOP  Force stop 
 *    TCC_CTRLBSET_CMD_UPDATE  Force update or double buffered registers 
 *    TCC_CTRLBSET_CMD_READSYNC  Force COUNT read synchronization 
 *    TCC_CTRLBSET_CMD_DMAOS  One-shot DMA trigger 
 */
static inline uint8_t tcc_get_CTRLB(TCC_t *pTCC, uint8_t mask)
{
    return pTCC->CTRLBSET.reg & mask;
}

/**
 * @brief tcc read CTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @return uint8_t
 * TCC_CTRLBSET_DIR  Counter Direction 
 * TCC_CTRLBSET_LUPD  Lock Update 
 * TCC_CTRLBSET_ONESHOT  One-Shot 
 * TCC_CTRLBSET_IDXCMD(value)  Ramp Index Command 
 *    TCC_CTRLBSET_IDXCMD_DISABLE  Command disabled: Index toggles between cycles A and B 
 *    TCC_CTRLBSET_IDXCMD_SET  Set index: cycle B will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_CLEAR  Clear index: cycle A will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_HOLD  Hold index: the next cycle will be the same as the current cycle 
 * TCC_CTRLBSET_CMD(value)  TCC Command 
 *    TCC_CTRLBSET_CMD_NONE  No action 
 *    TCC_CTRLBSET_CMD_RETRIGGER  Clear start, restart or retrigger 
 *    TCC_CTRLBSET_CMD_STOP  Force stop 
 *    TCC_CTRLBSET_CMD_UPDATE  Force update or double buffered registers 
 *    TCC_CTRLBSET_CMD_READSYNC  Force COUNT read synchronization 
 *    TCC_CTRLBSET_CMD_DMAOS  One-shot DMA trigger 
 */
static inline uint8_t tcc_read_CTRLB(TCC_t *pTCC)
{
	return pTCC->CTRLBSET.reg;
}

/**
 * @brief tcc write CTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t data
 * TCC_CTRLBSET_DIR  Counter Direction 
 * TCC_CTRLBSET_LUPD  Lock Update 
 * TCC_CTRLBSET_ONESHOT  One-Shot 
 * TCC_CTRLBSET_IDXCMD(value)  Ramp Index Command 
 *    TCC_CTRLBSET_IDXCMD_DISABLE  Command disabled: Index toggles between cycles A and B 
 *    TCC_CTRLBSET_IDXCMD_SET  Set index: cycle B will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_CLEAR  Clear index: cycle A will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_HOLD  Hold index: the next cycle will be the same as the current cycle 
 * TCC_CTRLBSET_CMD(value)  TCC Command 
 *    TCC_CTRLBSET_CMD_NONE  No action 
 *    TCC_CTRLBSET_CMD_RETRIGGER  Clear start, restart or retrigger 
 *    TCC_CTRLBSET_CMD_STOP  Force stop 
 *    TCC_CTRLBSET_CMD_UPDATE  Force update or double buffered registers 
 *    TCC_CTRLBSET_CMD_READSYNC  Force COUNT read synchronization 
 *    TCC_CTRLBSET_CMD_DMAOS  One-shot DMA trigger 
 */
static inline void tcc_write_CTRLB(TCC_t *pTCC, uint8_t data)
{
	pTCC->CTRLBSET.reg = data;
	pTCC->CTRLBCLR.reg = ~data;
}

/**
 * @brief tcc clear CTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t mask
 * TCC_CTRLBSET_DIR  Counter Direction 
 * TCC_CTRLBSET_LUPD  Lock Update 
 * TCC_CTRLBSET_ONESHOT  One-Shot 
 * TCC_CTRLBSET_IDXCMD(value)  Ramp Index Command 
 *    TCC_CTRLBSET_IDXCMD_DISABLE  Command disabled: Index toggles between cycles A and B 
 *    TCC_CTRLBSET_IDXCMD_SET  Set index: cycle B will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_CLEAR  Clear index: cycle A will be forced in the next cycle 
 *    TCC_CTRLBSET_IDXCMD_HOLD  Hold index: the next cycle will be the same as the current cycle 
 * TCC_CTRLBSET_CMD(value)  TCC Command 
 *    TCC_CTRLBSET_CMD_NONE  No action 
 *    TCC_CTRLBSET_CMD_RETRIGGER  Clear start, restart or retrigger 
 *    TCC_CTRLBSET_CMD_STOP  Force stop 
 *    TCC_CTRLBSET_CMD_UPDATE  Force update or double buffered registers 
 *    TCC_CTRLBSET_CMD_READSYNC  Force COUNT read synchronization 
 *    TCC_CTRLBSET_CMD_DMAOS  One-shot DMA trigger 
 */
static inline void tcc_clear_CTRLB(TCC_t *pTCC, uint8_t mask)
{
	pTCC->CTRLBCLR.reg = mask;
}

/**
 * @brief tcc set INTEN register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_INTENSET_OVF  Overflow Interrupt Enable 
 * TCC_INTENSET_TRG  Retrigger Interrupt Enable 
 * TCC_INTENSET_CNT  Counter Interrupt Enable 
 * TCC_INTENSET_ERR  Error Interrupt Enable 
 * TCC_INTENSET_UFS  Non-Recoverable Update Fault Interrupt Enable 
 * TCC_INTENSET_DFS  Non-Recoverable Debug Fault Interrupt Enable 
 * TCC_INTENSET_FAULTA  Recoverable Fault A Interrupt Enable 
 * TCC_INTENSET_FAULTB  Recoverable Fault B Interrupt Enable 
 * TCC_INTENSET_FAULT0  Non-Recoverable Fault 0 Interrupt Enable 
 * TCC_INTENSET_FAULT1  Non-Recoverable Fault 1 Interrupt Enable 
 * TCC_INTENSET_MC0  Match or Capture Channel 0 Interrupt Enable 
 * TCC_INTENSET_MC1  Match or Capture Channel 1 Interrupt Enable 
 * TCC_INTENSET_MC2  Match or Capture Channel 2 Interrupt Enable 
 * TCC_INTENSET_MC3  Match or Capture Channel 3 Interrupt Enable 
 * TCC_INTENSET_MC4  Match or Capture Channel 4 Interrupt Enable 
 * TCC_INTENSET_MC5  Match or Capture Channel 5 Interrupt Enable 
 * TCC_INTENSET_MC(value)  Match or Capture Channel x Interrupt Enable 
 */
static inline void tcc_set_INTEN(TCC_t *pTCC, uint32_t mask)
{
	pTCC->INTENSET.reg = mask;
}

/**
 * @brief tcc get INTEN register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_INTENSET_OVF  Overflow Interrupt Enable 
 * TCC_INTENSET_TRG  Retrigger Interrupt Enable 
 * TCC_INTENSET_CNT  Counter Interrupt Enable 
 * TCC_INTENSET_ERR  Error Interrupt Enable 
 * TCC_INTENSET_UFS  Non-Recoverable Update Fault Interrupt Enable 
 * TCC_INTENSET_DFS  Non-Recoverable Debug Fault Interrupt Enable 
 * TCC_INTENSET_FAULTA  Recoverable Fault A Interrupt Enable 
 * TCC_INTENSET_FAULTB  Recoverable Fault B Interrupt Enable 
 * TCC_INTENSET_FAULT0  Non-Recoverable Fault 0 Interrupt Enable 
 * TCC_INTENSET_FAULT1  Non-Recoverable Fault 1 Interrupt Enable 
 * TCC_INTENSET_MC0  Match or Capture Channel 0 Interrupt Enable 
 * TCC_INTENSET_MC1  Match or Capture Channel 1 Interrupt Enable 
 * TCC_INTENSET_MC2  Match or Capture Channel 2 Interrupt Enable 
 * TCC_INTENSET_MC3  Match or Capture Channel 3 Interrupt Enable 
 * TCC_INTENSET_MC4  Match or Capture Channel 4 Interrupt Enable 
 * TCC_INTENSET_MC5  Match or Capture Channel 5 Interrupt Enable 
 * TCC_INTENSET_MC(value)  Match or Capture Channel x Interrupt Enable 
 */
static inline uint32_t tcc_get_INTEN(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->INTENSET.reg & mask;
}

/**
 * @brief tcc read INTEN register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_INTENSET_OVF  Overflow Interrupt Enable 
 * TCC_INTENSET_TRG  Retrigger Interrupt Enable 
 * TCC_INTENSET_CNT  Counter Interrupt Enable 
 * TCC_INTENSET_ERR  Error Interrupt Enable 
 * TCC_INTENSET_UFS  Non-Recoverable Update Fault Interrupt Enable 
 * TCC_INTENSET_DFS  Non-Recoverable Debug Fault Interrupt Enable 
 * TCC_INTENSET_FAULTA  Recoverable Fault A Interrupt Enable 
 * TCC_INTENSET_FAULTB  Recoverable Fault B Interrupt Enable 
 * TCC_INTENSET_FAULT0  Non-Recoverable Fault 0 Interrupt Enable 
 * TCC_INTENSET_FAULT1  Non-Recoverable Fault 1 Interrupt Enable 
 * TCC_INTENSET_MC0  Match or Capture Channel 0 Interrupt Enable 
 * TCC_INTENSET_MC1  Match or Capture Channel 1 Interrupt Enable 
 * TCC_INTENSET_MC2  Match or Capture Channel 2 Interrupt Enable 
 * TCC_INTENSET_MC3  Match or Capture Channel 3 Interrupt Enable 
 * TCC_INTENSET_MC4  Match or Capture Channel 4 Interrupt Enable 
 * TCC_INTENSET_MC5  Match or Capture Channel 5 Interrupt Enable 
 * TCC_INTENSET_MC(value)  Match or Capture Channel x Interrupt Enable 
 */
static inline uint32_t tcc_read_INTEN(TCC_t *pTCC)
{
	return pTCC->INTENSET.reg;
}

/**
 * @brief tcc write INTEN register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_INTENSET_OVF  Overflow Interrupt Enable 
 * TCC_INTENSET_TRG  Retrigger Interrupt Enable 
 * TCC_INTENSET_CNT  Counter Interrupt Enable 
 * TCC_INTENSET_ERR  Error Interrupt Enable 
 * TCC_INTENSET_UFS  Non-Recoverable Update Fault Interrupt Enable 
 * TCC_INTENSET_DFS  Non-Recoverable Debug Fault Interrupt Enable 
 * TCC_INTENSET_FAULTA  Recoverable Fault A Interrupt Enable 
 * TCC_INTENSET_FAULTB  Recoverable Fault B Interrupt Enable 
 * TCC_INTENSET_FAULT0  Non-Recoverable Fault 0 Interrupt Enable 
 * TCC_INTENSET_FAULT1  Non-Recoverable Fault 1 Interrupt Enable 
 * TCC_INTENSET_MC0  Match or Capture Channel 0 Interrupt Enable 
 * TCC_INTENSET_MC1  Match or Capture Channel 1 Interrupt Enable 
 * TCC_INTENSET_MC2  Match or Capture Channel 2 Interrupt Enable 
 * TCC_INTENSET_MC3  Match or Capture Channel 3 Interrupt Enable 
 * TCC_INTENSET_MC4  Match or Capture Channel 4 Interrupt Enable 
 * TCC_INTENSET_MC5  Match or Capture Channel 5 Interrupt Enable 
 * TCC_INTENSET_MC(value)  Match or Capture Channel x Interrupt Enable 
 */
static inline void tcc_write_INTEN(TCC_t *pTCC, uint32_t data)
{
	pTCC->INTENSET.reg = data;
	pTCC->INTENCLR.reg = ~data;
}

/**
 * @brief tcc clear INTEN register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_INTENSET_OVF  Overflow Interrupt Enable 
 * TCC_INTENSET_TRG  Retrigger Interrupt Enable 
 * TCC_INTENSET_CNT  Counter Interrupt Enable 
 * TCC_INTENSET_ERR  Error Interrupt Enable 
 * TCC_INTENSET_UFS  Non-Recoverable Update Fault Interrupt Enable 
 * TCC_INTENSET_DFS  Non-Recoverable Debug Fault Interrupt Enable 
 * TCC_INTENSET_FAULTA  Recoverable Fault A Interrupt Enable 
 * TCC_INTENSET_FAULTB  Recoverable Fault B Interrupt Enable 
 * TCC_INTENSET_FAULT0  Non-Recoverable Fault 0 Interrupt Enable 
 * TCC_INTENSET_FAULT1  Non-Recoverable Fault 1 Interrupt Enable 
 * TCC_INTENSET_MC0  Match or Capture Channel 0 Interrupt Enable 
 * TCC_INTENSET_MC1  Match or Capture Channel 1 Interrupt Enable 
 * TCC_INTENSET_MC2  Match or Capture Channel 2 Interrupt Enable 
 * TCC_INTENSET_MC3  Match or Capture Channel 3 Interrupt Enable 
 * TCC_INTENSET_MC4  Match or Capture Channel 4 Interrupt Enable 
 * TCC_INTENSET_MC5  Match or Capture Channel 5 Interrupt Enable 
 * TCC_INTENSET_MC(value)  Match or Capture Channel x Interrupt Enable 
 */
static inline void tcc_clear_INTEN(TCC_t *pTCC, uint32_t mask)
{
	pTCC->INTENCLR.reg = mask;
}

/**
 * @brief tcc get INTFLAG register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_INTFLAG_OVF  Overflow 
 * TCC_INTFLAG_TRG  Retrigger 
 * TCC_INTFLAG_CNT  Counter 
 * TCC_INTFLAG_ERR  Error 
 * TCC_INTFLAG_UFS  Non-Recoverable Update Fault 
 * TCC_INTFLAG_DFS  Non-Recoverable Debug Fault 
 * TCC_INTFLAG_FAULTA  Recoverable Fault A 
 * TCC_INTFLAG_FAULTB  Recoverable Fault B 
 * TCC_INTFLAG_FAULT0  Non-Recoverable Fault 0 
 * TCC_INTFLAG_FAULT1  Non-Recoverable Fault 1 
 * TCC_INTFLAG_MC0  Match or Capture 0 
 * TCC_INTFLAG_MC1  Match or Capture 1 
 * TCC_INTFLAG_MC2  Match or Capture 2 
 * TCC_INTFLAG_MC3  Match or Capture 3 
 * TCC_INTFLAG_MC4  Match or Capture 4 
 * TCC_INTFLAG_MC5  Match or Capture 5 
 * TCC_INTFLAG_MC(value)  Match or Capture x 
 */
static inline uint32_t tcc_get_INTFLAG(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->INTFLAG.reg & mask;
}

/**
 * @brief tcc read INTFLAG register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_INTFLAG_OVF  Overflow 
 * TCC_INTFLAG_TRG  Retrigger 
 * TCC_INTFLAG_CNT  Counter 
 * TCC_INTFLAG_ERR  Error 
 * TCC_INTFLAG_UFS  Non-Recoverable Update Fault 
 * TCC_INTFLAG_DFS  Non-Recoverable Debug Fault 
 * TCC_INTFLAG_FAULTA  Recoverable Fault A 
 * TCC_INTFLAG_FAULTB  Recoverable Fault B 
 * TCC_INTFLAG_FAULT0  Non-Recoverable Fault 0 
 * TCC_INTFLAG_FAULT1  Non-Recoverable Fault 1 
 * TCC_INTFLAG_MC0  Match or Capture 0 
 * TCC_INTFLAG_MC1  Match or Capture 1 
 * TCC_INTFLAG_MC2  Match or Capture 2 
 * TCC_INTFLAG_MC3  Match or Capture 3 
 * TCC_INTFLAG_MC4  Match or Capture 4 
 * TCC_INTFLAG_MC5  Match or Capture 5 
 * TCC_INTFLAG_MC(value)  Match or Capture x 
 */
static inline uint32_t tcc_read_INTFLAG(TCC_t *pTCC)
{
	return pTCC->INTFLAG.reg;
}

/**
 * @brief tcc clear INTFLAG register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_INTFLAG_OVF  Overflow 
 * TCC_INTFLAG_TRG  Retrigger 
 * TCC_INTFLAG_CNT  Counter 
 * TCC_INTFLAG_ERR  Error 
 * TCC_INTFLAG_UFS  Non-Recoverable Update Fault 
 * TCC_INTFLAG_DFS  Non-Recoverable Debug Fault 
 * TCC_INTFLAG_FAULTA  Recoverable Fault A 
 * TCC_INTFLAG_FAULTB  Recoverable Fault B 
 * TCC_INTFLAG_FAULT0  Non-Recoverable Fault 0 
 * TCC_INTFLAG_FAULT1  Non-Recoverable Fault 1 
 * TCC_INTFLAG_MC0  Match or Capture 0 
 * TCC_INTFLAG_MC1  Match or Capture 1 
 * TCC_INTFLAG_MC2  Match or Capture 2 
 * TCC_INTFLAG_MC3  Match or Capture 3 
 * TCC_INTFLAG_MC4  Match or Capture 4 
 * TCC_INTFLAG_MC5  Match or Capture 5 
 * TCC_INTFLAG_MC(value)  Match or Capture x 
 */
static inline void tcc_clear_INTFLAG(TCC_t *pTCC, uint32_t mask)
{
	pTCC->INTFLAG.reg = mask;
}

/**
 * @brief tcc set CTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_CTRLA_SWRST  Software Reset 
 * TCC_CTRLA_ENABLE  Enable 
 * TCC_CTRLA_RESOLUTION(value)  Enhanced Resolution 
 *    TCC_CTRLA_RESOLUTION_NONE  Dithering is disabled 
 *    TCC_CTRLA_RESOLUTION_DITH4  Dithering is done every 16 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH5  Dithering is done every 32 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH6  Dithering is done every 64 PWM frames 
 * TCC_CTRLA_PRESCALER(value)  Prescaler 
 *    TCC_CTRLA_PRESCALER_DIV1  No division 
 *    TCC_CTRLA_PRESCALER_DIV2  Divide by 2 
 *    TCC_CTRLA_PRESCALER_DIV4  Divide by 4 
 *    TCC_CTRLA_PRESCALER_DIV8  Divide by 8 
 *    TCC_CTRLA_PRESCALER_DIV16  Divide by 16 
 *    TCC_CTRLA_PRESCALER_DIV64  Divide by 64 
 *    TCC_CTRLA_PRESCALER_DIV256  Divide by 256 
 *    TCC_CTRLA_PRESCALER_DIV1024  Divide by 1024 
 * TCC_CTRLA_RUNSTDBY  Run in Standby 
 * TCC_CTRLA_PRESCSYNC(value)  Prescaler and Counter Synchronization Selection 
 *    TCC_CTRLA_PRESCSYNC_GCLK  Reload or reset counter on next GCLK 
 *    TCC_CTRLA_PRESCSYNC_PRESC  Reload or reset counter on next prescaler clock 
 *    TCC_CTRLA_PRESCSYNC_RESYNC  Reload or reset counter on next GCLK and reset prescaler counter 
 * TCC_CTRLA_ALOCK  Auto Lock 
 * TCC_CTRLA_MSYNC  Master Synchronization (only for TCC Slave Instance) 
 * TCC_CTRLA_DMAOS  DMA One-shot Trigger Mode 
 * TCC_CTRLA_CPTEN0  Capture Channel 0 Enable 
 * TCC_CTRLA_CPTEN1  Capture Channel 1 Enable 
 * TCC_CTRLA_CPTEN2  Capture Channel 2 Enable 
 * TCC_CTRLA_CPTEN3  Capture Channel 3 Enable 
 * TCC_CTRLA_CPTEN4  Capture Channel 4 Enable 
 * TCC_CTRLA_CPTEN5  Capture Channel 5 Enable 
 * TCC_CTRLA_CPTEN(value)  Capture Channel x Enable 
 */
static inline void tcc_set_CTRLA(TCC_t *pTCC, uint32_t mask)
{
	pTCC->CTRLA.reg |= mask;
}

/**
 * @brief tcc set CTRLA Software Reset register
 * requires tcc_wait_for_sync(TCCn, TCC_SYNCBUSY_SWRST);
 * @param[in] TCC_t *pTCC
 */
static inline void tcc_set_SWRST(TCC_t *pTCC)
{
	pTCC->CTRLA.reg |= TCC_CTRLA_SWRST;
}

/**
 * @brief tcc set CTRLA Enable register
 * requires tcc_wait_for_sync(TCCn, TCC_SYNCBUSY_ENABLE);
 *
 * @param[in] TCC_t *pTCC
 */
static inline void tcc_set_ENABLE(TCC_t *pTCC)
{
	pTCC->CTRLA.reg |= TCC_CTRLA_ENABLE;
}

/**
 * @brief tcc clear CTRLA Enable register
 * requires tcc_wait_for_sync(TCCn, TCC_SYNCBUSY_ENABLE);
 *
 * @param[in] TCC_t *pTCC
 */
static inline void tcc_clear_ENABLE(TCC_t *pTCC)
{
	pTCC->CTRLA.reg &= ~TCC_CTRLA_ENABLE;
}

/**
 * @brief tcc get CTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_CTRLA_SWRST  Software Reset 
 * TCC_CTRLA_ENABLE  Enable 
 * TCC_CTRLA_RESOLUTION(value)  Enhanced Resolution 
 *    TCC_CTRLA_RESOLUTION_NONE  Dithering is disabled 
 *    TCC_CTRLA_RESOLUTION_DITH4  Dithering is done every 16 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH5  Dithering is done every 32 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH6  Dithering is done every 64 PWM frames 
 * TCC_CTRLA_PRESCALER(value)  Prescaler 
 *    TCC_CTRLA_PRESCALER_DIV1  No division 
 *    TCC_CTRLA_PRESCALER_DIV2  Divide by 2 
 *    TCC_CTRLA_PRESCALER_DIV4  Divide by 4 
 *    TCC_CTRLA_PRESCALER_DIV8  Divide by 8 
 *    TCC_CTRLA_PRESCALER_DIV16  Divide by 16 
 *    TCC_CTRLA_PRESCALER_DIV64  Divide by 64 
 *    TCC_CTRLA_PRESCALER_DIV256  Divide by 256 
 *    TCC_CTRLA_PRESCALER_DIV1024  Divide by 1024 
 * TCC_CTRLA_RUNSTDBY  Run in Standby 
 * TCC_CTRLA_PRESCSYNC(value)  Prescaler and Counter Synchronization Selection 
 *    TCC_CTRLA_PRESCSYNC_GCLK  Reload or reset counter on next GCLK 
 *    TCC_CTRLA_PRESCSYNC_PRESC  Reload or reset counter on next prescaler clock 
 *    TCC_CTRLA_PRESCSYNC_RESYNC  Reload or reset counter on next GCLK and reset prescaler counter 
 * TCC_CTRLA_ALOCK  Auto Lock 
 * TCC_CTRLA_MSYNC  Master Synchronization (only for TCC Slave Instance) 
 * TCC_CTRLA_DMAOS  DMA One-shot Trigger Mode 
 * TCC_CTRLA_CPTEN0  Capture Channel 0 Enable 
 * TCC_CTRLA_CPTEN1  Capture Channel 1 Enable 
 * TCC_CTRLA_CPTEN2  Capture Channel 2 Enable 
 * TCC_CTRLA_CPTEN3  Capture Channel 3 Enable 
 * TCC_CTRLA_CPTEN4  Capture Channel 4 Enable 
 * TCC_CTRLA_CPTEN5  Capture Channel 5 Enable 
 * TCC_CTRLA_CPTEN(value)  Capture Channel x Enable 
 */
static inline uint32_t tcc_get_CTRLA(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->CTRLA.reg & mask;
}

/**
 * @brief tcc write CTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_CTRLA_SWRST  Software Reset 
 * TCC_CTRLA_ENABLE  Enable 
 * TCC_CTRLA_RESOLUTION(value)  Enhanced Resolution 
 *    TCC_CTRLA_RESOLUTION_NONE  Dithering is disabled 
 *    TCC_CTRLA_RESOLUTION_DITH4  Dithering is done every 16 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH5  Dithering is done every 32 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH6  Dithering is done every 64 PWM frames 
 * TCC_CTRLA_PRESCALER(value)  Prescaler 
 *    TCC_CTRLA_PRESCALER_DIV1  No division 
 *    TCC_CTRLA_PRESCALER_DIV2  Divide by 2 
 *    TCC_CTRLA_PRESCALER_DIV4  Divide by 4 
 *    TCC_CTRLA_PRESCALER_DIV8  Divide by 8 
 *    TCC_CTRLA_PRESCALER_DIV16  Divide by 16 
 *    TCC_CTRLA_PRESCALER_DIV64  Divide by 64 
 *    TCC_CTRLA_PRESCALER_DIV256  Divide by 256 
 *    TCC_CTRLA_PRESCALER_DIV1024  Divide by 1024 
 * TCC_CTRLA_RUNSTDBY  Run in Standby 
 * TCC_CTRLA_PRESCSYNC(value)  Prescaler and Counter Synchronization Selection 
 *    TCC_CTRLA_PRESCSYNC_GCLK  Reload or reset counter on next GCLK 
 *    TCC_CTRLA_PRESCSYNC_PRESC  Reload or reset counter on next prescaler clock 
 *    TCC_CTRLA_PRESCSYNC_RESYNC  Reload or reset counter on next GCLK and reset prescaler counter 
 * TCC_CTRLA_ALOCK  Auto Lock 
 * TCC_CTRLA_MSYNC  Master Synchronization (only for TCC Slave Instance) 
 * TCC_CTRLA_DMAOS  DMA One-shot Trigger Mode 
 * TCC_CTRLA_CPTEN0  Capture Channel 0 Enable 
 * TCC_CTRLA_CPTEN1  Capture Channel 1 Enable 
 * TCC_CTRLA_CPTEN2  Capture Channel 2 Enable 
 * TCC_CTRLA_CPTEN3  Capture Channel 3 Enable 
 * TCC_CTRLA_CPTEN4  Capture Channel 4 Enable 
 * TCC_CTRLA_CPTEN5  Capture Channel 5 Enable 
 * TCC_CTRLA_CPTEN(value)  Capture Channel x Enable 
 */
static inline void tcc_write_CTRLA(TCC_t *pTCC, uint32_t data)
{
	pTCC->CTRLA.reg = data;
}

/**
 * @brief tcc clear CTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_CTRLA_SWRST  Software Reset 
 * TCC_CTRLA_ENABLE  Enable 
 * TCC_CTRLA_RESOLUTION(value)  Enhanced Resolution 
 *    TCC_CTRLA_RESOLUTION_NONE  Dithering is disabled 
 *    TCC_CTRLA_RESOLUTION_DITH4  Dithering is done every 16 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH5  Dithering is done every 32 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH6  Dithering is done every 64 PWM frames 
 * TCC_CTRLA_PRESCALER(value)  Prescaler 
 *    TCC_CTRLA_PRESCALER_DIV1  No division 
 *    TCC_CTRLA_PRESCALER_DIV2  Divide by 2 
 *    TCC_CTRLA_PRESCALER_DIV4  Divide by 4 
 *    TCC_CTRLA_PRESCALER_DIV8  Divide by 8 
 *    TCC_CTRLA_PRESCALER_DIV16  Divide by 16 
 *    TCC_CTRLA_PRESCALER_DIV64  Divide by 64 
 *    TCC_CTRLA_PRESCALER_DIV256  Divide by 256 
 *    TCC_CTRLA_PRESCALER_DIV1024  Divide by 1024 
 * TCC_CTRLA_RUNSTDBY  Run in Standby 
 * TCC_CTRLA_PRESCSYNC(value)  Prescaler and Counter Synchronization Selection 
 *    TCC_CTRLA_PRESCSYNC_GCLK  Reload or reset counter on next GCLK 
 *    TCC_CTRLA_PRESCSYNC_PRESC  Reload or reset counter on next prescaler clock 
 *    TCC_CTRLA_PRESCSYNC_RESYNC  Reload or reset counter on next GCLK and reset prescaler counter 
 * TCC_CTRLA_ALOCK  Auto Lock 
 * TCC_CTRLA_MSYNC  Master Synchronization (only for TCC Slave Instance) 
 * TCC_CTRLA_DMAOS  DMA One-shot Trigger Mode 
 * TCC_CTRLA_CPTEN0  Capture Channel 0 Enable 
 * TCC_CTRLA_CPTEN1  Capture Channel 1 Enable 
 * TCC_CTRLA_CPTEN2  Capture Channel 2 Enable 
 * TCC_CTRLA_CPTEN3  Capture Channel 3 Enable 
 * TCC_CTRLA_CPTEN4  Capture Channel 4 Enable 
 * TCC_CTRLA_CPTEN5  Capture Channel 5 Enable 
 * TCC_CTRLA_CPTEN(value)  Capture Channel x Enable 
 */
static inline void tcc_clear_CTRLA(TCC_t *pTCC, uint32_t mask)
{
	pTCC->CTRLA.reg &= ~mask;
}

/**
 * @brief tcc read CTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_CTRLA_SWRST  Software Reset 
 * TCC_CTRLA_ENABLE  Enable 
 * TCC_CTRLA_RESOLUTION(value)  Enhanced Resolution 
 *    TCC_CTRLA_RESOLUTION_NONE  Dithering is disabled 
 *    TCC_CTRLA_RESOLUTION_DITH4  Dithering is done every 16 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH5  Dithering is done every 32 PWM frames 
 *    TCC_CTRLA_RESOLUTION_DITH6  Dithering is done every 64 PWM frames 
 * TCC_CTRLA_PRESCALER(value)  Prescaler 
 *    TCC_CTRLA_PRESCALER_DIV1  No division 
 *    TCC_CTRLA_PRESCALER_DIV2  Divide by 2 
 *    TCC_CTRLA_PRESCALER_DIV4  Divide by 4 
 *    TCC_CTRLA_PRESCALER_DIV8  Divide by 8 
 *    TCC_CTRLA_PRESCALER_DIV16  Divide by 16 
 *    TCC_CTRLA_PRESCALER_DIV64  Divide by 64 
 *    TCC_CTRLA_PRESCALER_DIV256  Divide by 256 
 *    TCC_CTRLA_PRESCALER_DIV1024  Divide by 1024 
 * TCC_CTRLA_RUNSTDBY  Run in Standby 
 * TCC_CTRLA_PRESCSYNC(value)  Prescaler and Counter Synchronization Selection 
 *    TCC_CTRLA_PRESCSYNC_GCLK  Reload or reset counter on next GCLK 
 *    TCC_CTRLA_PRESCSYNC_PRESC  Reload or reset counter on next prescaler clock 
 *    TCC_CTRLA_PRESCSYNC_RESYNC  Reload or reset counter on next GCLK and reset prescaler counter 
 * TCC_CTRLA_ALOCK  Auto Lock 
 * TCC_CTRLA_MSYNC  Master Synchronization (only for TCC Slave Instance) 
 * TCC_CTRLA_DMAOS  DMA One-shot Trigger Mode 
 * TCC_CTRLA_CPTEN0  Capture Channel 0 Enable 
 * TCC_CTRLA_CPTEN1  Capture Channel 1 Enable 
 * TCC_CTRLA_CPTEN2  Capture Channel 2 Enable 
 * TCC_CTRLA_CPTEN3  Capture Channel 3 Enable 
 * TCC_CTRLA_CPTEN4  Capture Channel 4 Enable 
 * TCC_CTRLA_CPTEN5  Capture Channel 5 Enable 
 * TCC_CTRLA_CPTEN(value)  Capture Channel x Enable 
 */
static inline uint32_t tcc_read_CTRLA(TCC_t *pTCC)
{
	return pTCC->CTRLA.reg;
}

/**
 * @brief tcc set FCTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_FCTRLA_SRC(value)  Fault A Source 
 *    TCC_FCTRLA_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLA_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLA_KEEP  Fault A Keeper 
 * TCC_FCTRLA_QUAL  Fault A Qualification 
 * TCC_FCTRLA_BLANK(value)  Fault A Blanking Mode 
 *    TCC_FCTRLA_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLA_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLA_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLA_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLA_RESTART  Fault A Restart 
 * TCC_FCTRLA_HALT(value)  Fault A Halt Mode 
 *    TCC_FCTRLA_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLA_HALT_HW  Hardware halt action 
 *    TCC_FCTRLA_HALT_SW  Software halt action 
 *    TCC_FCTRLA_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLA_CHSEL(value)  Fault A Capture Channel 
 *    TCC_FCTRLA_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLA_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLA_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLA_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLA_CAPTURE(value)  Fault A Capture Action 
 *    TCC_FCTRLA_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLA_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLA_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLA_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLA_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLA_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLA_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLA_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLA_BLANKPRESC  Fault A Blanking Prescaler 
 * TCC_FCTRLA_BLANKVAL(value)  Fault A Blanking Time 
 * TCC_FCTRLA_FILTERVAL(value)  Fault A Filter Value 
 */
static inline void tcc_set_FCTRLA(TCC_t *pTCC, uint32_t mask)
{
	pTCC->FCTRLA.reg |= mask;
}

/**
 * @brief tcc get FCTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_FCTRLA_SRC(value)  Fault A Source 
 *    TCC_FCTRLA_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLA_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLA_KEEP  Fault A Keeper 
 * TCC_FCTRLA_QUAL  Fault A Qualification 
 * TCC_FCTRLA_BLANK(value)  Fault A Blanking Mode 
 *    TCC_FCTRLA_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLA_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLA_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLA_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLA_RESTART  Fault A Restart 
 * TCC_FCTRLA_HALT(value)  Fault A Halt Mode 
 *    TCC_FCTRLA_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLA_HALT_HW  Hardware halt action 
 *    TCC_FCTRLA_HALT_SW  Software halt action 
 *    TCC_FCTRLA_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLA_CHSEL(value)  Fault A Capture Channel 
 *    TCC_FCTRLA_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLA_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLA_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLA_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLA_CAPTURE(value)  Fault A Capture Action 
 *    TCC_FCTRLA_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLA_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLA_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLA_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLA_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLA_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLA_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLA_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLA_BLANKPRESC  Fault A Blanking Prescaler 
 * TCC_FCTRLA_BLANKVAL(value)  Fault A Blanking Time 
 * TCC_FCTRLA_FILTERVAL(value)  Fault A Filter Value 
 */
static inline uint32_t tcc_get_FCTRLA(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->FCTRLA.reg & mask;
}

/**
 * @brief tcc write FCTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_FCTRLA_SRC(value)  Fault A Source 
 *    TCC_FCTRLA_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLA_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLA_KEEP  Fault A Keeper 
 * TCC_FCTRLA_QUAL  Fault A Qualification 
 * TCC_FCTRLA_BLANK(value)  Fault A Blanking Mode 
 *    TCC_FCTRLA_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLA_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLA_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLA_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLA_RESTART  Fault A Restart 
 * TCC_FCTRLA_HALT(value)  Fault A Halt Mode 
 *    TCC_FCTRLA_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLA_HALT_HW  Hardware halt action 
 *    TCC_FCTRLA_HALT_SW  Software halt action 
 *    TCC_FCTRLA_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLA_CHSEL(value)  Fault A Capture Channel 
 *    TCC_FCTRLA_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLA_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLA_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLA_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLA_CAPTURE(value)  Fault A Capture Action 
 *    TCC_FCTRLA_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLA_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLA_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLA_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLA_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLA_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLA_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLA_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLA_BLANKPRESC  Fault A Blanking Prescaler 
 * TCC_FCTRLA_BLANKVAL(value)  Fault A Blanking Time 
 * TCC_FCTRLA_FILTERVAL(value)  Fault A Filter Value 
 */
static inline void tcc_write_FCTRLA(TCC_t *pTCC, uint32_t data)
{
	pTCC->FCTRLA.reg = data;
}

/**
 * @brief tcc clear FCTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_FCTRLA_SRC(value)  Fault A Source 
 *    TCC_FCTRLA_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLA_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLA_KEEP  Fault A Keeper 
 * TCC_FCTRLA_QUAL  Fault A Qualification 
 * TCC_FCTRLA_BLANK(value)  Fault A Blanking Mode 
 *    TCC_FCTRLA_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLA_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLA_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLA_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLA_RESTART  Fault A Restart 
 * TCC_FCTRLA_HALT(value)  Fault A Halt Mode 
 *    TCC_FCTRLA_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLA_HALT_HW  Hardware halt action 
 *    TCC_FCTRLA_HALT_SW  Software halt action 
 *    TCC_FCTRLA_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLA_CHSEL(value)  Fault A Capture Channel 
 *    TCC_FCTRLA_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLA_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLA_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLA_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLA_CAPTURE(value)  Fault A Capture Action 
 *    TCC_FCTRLA_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLA_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLA_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLA_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLA_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLA_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLA_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLA_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLA_BLANKPRESC  Fault A Blanking Prescaler 
 * TCC_FCTRLA_BLANKVAL(value)  Fault A Blanking Time 
 * TCC_FCTRLA_FILTERVAL(value)  Fault A Filter Value 
 */
static inline void tcc_clear_FCTRLA(TCC_t *pTCC, uint32_t mask)
{
	pTCC->FCTRLA.reg &= ~mask;
}

/**
 * @brief tcc read FCTRLA register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_FCTRLA_SRC(value)  Fault A Source 
 *    TCC_FCTRLA_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLA_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLA_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLA_KEEP  Fault A Keeper 
 * TCC_FCTRLA_QUAL  Fault A Qualification 
 * TCC_FCTRLA_BLANK(value)  Fault A Blanking Mode 
 *    TCC_FCTRLA_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLA_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLA_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLA_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLA_RESTART  Fault A Restart 
 * TCC_FCTRLA_HALT(value)  Fault A Halt Mode 
 *    TCC_FCTRLA_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLA_HALT_HW  Hardware halt action 
 *    TCC_FCTRLA_HALT_SW  Software halt action 
 *    TCC_FCTRLA_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLA_CHSEL(value)  Fault A Capture Channel 
 *    TCC_FCTRLA_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLA_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLA_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLA_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLA_CAPTURE(value)  Fault A Capture Action 
 *    TCC_FCTRLA_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLA_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLA_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLA_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLA_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLA_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLA_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLA_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLA_BLANKPRESC  Fault A Blanking Prescaler 
 * TCC_FCTRLA_BLANKVAL(value)  Fault A Blanking Time 
 * TCC_FCTRLA_FILTERVAL(value)  Fault A Filter Value 
 */
static inline uint32_t tcc_read_FCTRLA(TCC_t *pTCC)
{
	return pTCC->FCTRLA.reg;
}

/**
 * @brief tcc set FCTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_FCTRLB_SRC(value)  Fault B Source 
 *    TCC_FCTRLB_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLB_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLB_KEEP  Fault B Keeper 
 * TCC_FCTRLB_QUAL  Fault B Qualification 
 * TCC_FCTRLB_BLANK(value)  Fault B Blanking Mode 
 *    TCC_FCTRLB_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLB_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLB_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLB_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLB_RESTART  Fault B Restart 
 * TCC_FCTRLB_HALT(value)  Fault B Halt Mode 
 *    TCC_FCTRLB_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLB_HALT_HW  Hardware halt action 
 *    TCC_FCTRLB_HALT_SW  Software halt action 
 *    TCC_FCTRLB_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLB_CHSEL(value)  Fault B Capture Channel 
 *    TCC_FCTRLB_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLB_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLB_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLB_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLB_CAPTURE(value)  Fault B Capture Action 
 *    TCC_FCTRLB_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLB_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLB_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLB_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLB_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLB_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLB_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLB_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLB_BLANKPRESC  Fault B Blanking Prescaler 
 * TCC_FCTRLB_BLANKVAL(value)  Fault B Blanking Time 
 * TCC_FCTRLB_FILTERVAL(value)  Fault B Filter Value 
 */
static inline void tcc_set_FCTRLB(TCC_t *pTCC, uint32_t mask)
{
	pTCC->FCTRLB.reg |= mask;
}

/**
 * @brief tcc get FCTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_FCTRLB_SRC(value)  Fault B Source 
 *    TCC_FCTRLB_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLB_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLB_KEEP  Fault B Keeper 
 * TCC_FCTRLB_QUAL  Fault B Qualification 
 * TCC_FCTRLB_BLANK(value)  Fault B Blanking Mode 
 *    TCC_FCTRLB_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLB_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLB_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLB_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLB_RESTART  Fault B Restart 
 * TCC_FCTRLB_HALT(value)  Fault B Halt Mode 
 *    TCC_FCTRLB_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLB_HALT_HW  Hardware halt action 
 *    TCC_FCTRLB_HALT_SW  Software halt action 
 *    TCC_FCTRLB_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLB_CHSEL(value)  Fault B Capture Channel 
 *    TCC_FCTRLB_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLB_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLB_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLB_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLB_CAPTURE(value)  Fault B Capture Action 
 *    TCC_FCTRLB_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLB_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLB_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLB_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLB_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLB_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLB_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLB_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLB_BLANKPRESC  Fault B Blanking Prescaler 
 * TCC_FCTRLB_BLANKVAL(value)  Fault B Blanking Time 
 * TCC_FCTRLB_FILTERVAL(value)  Fault B Filter Value 
 */
static inline uint32_t tcc_get_FCTRLB(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->FCTRLB.reg & mask;
}

/**
 * @brief tcc write FCTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_FCTRLB_SRC(value)  Fault B Source 
 *    TCC_FCTRLB_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLB_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLB_KEEP  Fault B Keeper 
 * TCC_FCTRLB_QUAL  Fault B Qualification 
 * TCC_FCTRLB_BLANK(value)  Fault B Blanking Mode 
 *    TCC_FCTRLB_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLB_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLB_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLB_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLB_RESTART  Fault B Restart 
 * TCC_FCTRLB_HALT(value)  Fault B Halt Mode 
 *    TCC_FCTRLB_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLB_HALT_HW  Hardware halt action 
 *    TCC_FCTRLB_HALT_SW  Software halt action 
 *    TCC_FCTRLB_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLB_CHSEL(value)  Fault B Capture Channel 
 *    TCC_FCTRLB_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLB_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLB_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLB_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLB_CAPTURE(value)  Fault B Capture Action 
 *    TCC_FCTRLB_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLB_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLB_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLB_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLB_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLB_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLB_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLB_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLB_BLANKPRESC  Fault B Blanking Prescaler 
 * TCC_FCTRLB_BLANKVAL(value)  Fault B Blanking Time 
 * TCC_FCTRLB_FILTERVAL(value)  Fault B Filter Value 
 */
static inline void tcc_write_FCTRLB(TCC_t *pTCC, uint32_t data)
{
	pTCC->FCTRLB.reg = data;
}

/**
 * @brief tcc clear FCTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_FCTRLB_SRC(value)  Fault B Source 
 *    TCC_FCTRLB_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLB_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLB_KEEP  Fault B Keeper 
 * TCC_FCTRLB_QUAL  Fault B Qualification 
 * TCC_FCTRLB_BLANK(value)  Fault B Blanking Mode 
 *    TCC_FCTRLB_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLB_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLB_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLB_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLB_RESTART  Fault B Restart 
 * TCC_FCTRLB_HALT(value)  Fault B Halt Mode 
 *    TCC_FCTRLB_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLB_HALT_HW  Hardware halt action 
 *    TCC_FCTRLB_HALT_SW  Software halt action 
 *    TCC_FCTRLB_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLB_CHSEL(value)  Fault B Capture Channel 
 *    TCC_FCTRLB_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLB_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLB_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLB_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLB_CAPTURE(value)  Fault B Capture Action 
 *    TCC_FCTRLB_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLB_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLB_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLB_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLB_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLB_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLB_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLB_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLB_BLANKPRESC  Fault B Blanking Prescaler 
 * TCC_FCTRLB_BLANKVAL(value)  Fault B Blanking Time 
 * TCC_FCTRLB_FILTERVAL(value)  Fault B Filter Value 
 */
static inline void tcc_clear_FCTRLB(TCC_t *pTCC, uint32_t mask)
{
	pTCC->FCTRLB.reg &= ~mask;
}

/**
 * @brief tcc read FCTRLB register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_FCTRLB_SRC(value)  Fault B Source 
 *    TCC_FCTRLB_SRC_DISABLE  Fault input disabled 
 *    TCC_FCTRLB_SRC_ENABLE  MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_INVERT  Inverted MCEx (x=0,1) event input 
 *    TCC_FCTRLB_SRC_ALTFAULT  Alternate fault (A or B) state at the end of the previous period 
 * TCC_FCTRLB_KEEP  Fault B Keeper 
 * TCC_FCTRLB_QUAL  Fault B Qualification 
 * TCC_FCTRLB_BLANK(value)  Fault B Blanking Mode 
 *    TCC_FCTRLB_BLANK_START  Blanking applied from start of the ramp 
 *    TCC_FCTRLB_BLANK_RISE  Blanking applied from rising edge of the output waveform 
 *    TCC_FCTRLB_BLANK_FALL  Blanking applied from falling edge of the output waveform 
 *    TCC_FCTRLB_BLANK_BOTH  Blanking applied from each toggle of the output waveform 
 * TCC_FCTRLB_RESTART  Fault B Restart 
 * TCC_FCTRLB_HALT(value)  Fault B Halt Mode 
 *    TCC_FCTRLB_HALT_DISABLE  Halt action disabled 
 *    TCC_FCTRLB_HALT_HW  Hardware halt action 
 *    TCC_FCTRLB_HALT_SW  Software halt action 
 *    TCC_FCTRLB_HALT_NR  Non-recoverable fault 
 * TCC_FCTRLB_CHSEL(value)  Fault B Capture Channel 
 *    TCC_FCTRLB_CHSEL_CC0  Capture value stored in channel 0 
 *    TCC_FCTRLB_CHSEL_CC1  Capture value stored in channel 1 
 *    TCC_FCTRLB_CHSEL_CC2  Capture value stored in channel 2 
 *    TCC_FCTRLB_CHSEL_CC3  Capture value stored in channel 3 
 * TCC_FCTRLB_CAPTURE(value)  Fault B Capture Action 
 *    TCC_FCTRLB_CAPTURE_DISABLE  No capture 
 *    TCC_FCTRLB_CAPTURE_CAPT  Capture on fault 
 *    TCC_FCTRLB_CAPTURE_CAPTMIN  Minimum capture 
 *    TCC_FCTRLB_CAPTURE_CAPTMAX  Maximum capture 
 *    TCC_FCTRLB_CAPTURE_LOCMIN  Minimum local detection 
 *    TCC_FCTRLB_CAPTURE_LOCMAX  Maximum local detection 
 *    TCC_FCTRLB_CAPTURE_DERIV0  Minimum and maximum local detection 
 *    TCC_FCTRLB_CAPTURE_CAPTMARK  Capture with ramp index as MSB value 
 * TCC_FCTRLB_BLANKPRESC  Fault B Blanking Prescaler 
 * TCC_FCTRLB_BLANKVAL(value)  Fault B Blanking Time 
 * TCC_FCTRLB_FILTERVAL(value)  Fault B Filter Value 
 */
static inline uint32_t tcc_read_FCTRLB(TCC_t *pTCC)
{
	return pTCC->FCTRLB.reg;
}

/**
 * @brief tcc set WEXCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_WEXCTRL_OTMX(value)  Output Matrix 
 * TCC_WEXCTRL_DTIEN0  Dead-time Insertion Generator 0 Enable 
 * TCC_WEXCTRL_DTIEN1  Dead-time Insertion Generator 1 Enable 
 * TCC_WEXCTRL_DTIEN2  Dead-time Insertion Generator 2 Enable 
 * TCC_WEXCTRL_DTIEN3  Dead-time Insertion Generator 3 Enable 
 * TCC_WEXCTRL_DTIEN(value)  Dead-time Insertion Generator x Enable 
 * TCC_WEXCTRL_DTLS(value)  Dead-time Low Side Outputs Value 
 * TCC_WEXCTRL_DTHS(value)  Dead-time High Side Outputs Value 
 */
static inline void tcc_set_WEXCTRL(TCC_t *pTCC, uint32_t mask)
{
	pTCC->WEXCTRL.reg |= mask;
}

/**
 * @brief tcc get WEXCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_WEXCTRL_OTMX(value)  Output Matrix 
 * TCC_WEXCTRL_DTIEN0  Dead-time Insertion Generator 0 Enable 
 * TCC_WEXCTRL_DTIEN1  Dead-time Insertion Generator 1 Enable 
 * TCC_WEXCTRL_DTIEN2  Dead-time Insertion Generator 2 Enable 
 * TCC_WEXCTRL_DTIEN3  Dead-time Insertion Generator 3 Enable 
 * TCC_WEXCTRL_DTIEN(value)  Dead-time Insertion Generator x Enable 
 * TCC_WEXCTRL_DTLS(value)  Dead-time Low Side Outputs Value 
 * TCC_WEXCTRL_DTHS(value)  Dead-time High Side Outputs Value 
 */
static inline uint32_t tcc_get_WEXCTRL(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->WEXCTRL.reg & mask;
}

/**
 * @brief tcc write WEXCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_WEXCTRL_OTMX(value)  Output Matrix 
 * TCC_WEXCTRL_DTIEN0  Dead-time Insertion Generator 0 Enable 
 * TCC_WEXCTRL_DTIEN1  Dead-time Insertion Generator 1 Enable 
 * TCC_WEXCTRL_DTIEN2  Dead-time Insertion Generator 2 Enable 
 * TCC_WEXCTRL_DTIEN3  Dead-time Insertion Generator 3 Enable 
 * TCC_WEXCTRL_DTIEN(value)  Dead-time Insertion Generator x Enable 
 * TCC_WEXCTRL_DTLS(value)  Dead-time Low Side Outputs Value 
 * TCC_WEXCTRL_DTHS(value)  Dead-time High Side Outputs Value 
 */
static inline void tcc_write_WEXCTRL(TCC_t *pTCC, uint32_t data)
{
	pTCC->WEXCTRL.reg = data;
}

/**
 * @brief tcc clear WEXCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_WEXCTRL_OTMX(value)  Output Matrix 
 * TCC_WEXCTRL_DTIEN0  Dead-time Insertion Generator 0 Enable 
 * TCC_WEXCTRL_DTIEN1  Dead-time Insertion Generator 1 Enable 
 * TCC_WEXCTRL_DTIEN2  Dead-time Insertion Generator 2 Enable 
 * TCC_WEXCTRL_DTIEN3  Dead-time Insertion Generator 3 Enable 
 * TCC_WEXCTRL_DTIEN(value)  Dead-time Insertion Generator x Enable 
 * TCC_WEXCTRL_DTLS(value)  Dead-time Low Side Outputs Value 
 * TCC_WEXCTRL_DTHS(value)  Dead-time High Side Outputs Value 
 */
static inline void tcc_clear_WEXCTRL(TCC_t *pTCC, uint32_t mask)
{
	pTCC->WEXCTRL.reg &= ~mask;
}

/**
 * @brief tcc read WEXCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_WEXCTRL_OTMX(value)  Output Matrix 
 * TCC_WEXCTRL_DTIEN0  Dead-time Insertion Generator 0 Enable 
 * TCC_WEXCTRL_DTIEN1  Dead-time Insertion Generator 1 Enable 
 * TCC_WEXCTRL_DTIEN2  Dead-time Insertion Generator 2 Enable 
 * TCC_WEXCTRL_DTIEN3  Dead-time Insertion Generator 3 Enable 
 * TCC_WEXCTRL_DTIEN(value)  Dead-time Insertion Generator x Enable 
 * TCC_WEXCTRL_DTLS(value)  Dead-time Low Side Outputs Value 
 * TCC_WEXCTRL_DTHS(value)  Dead-time High Side Outputs Value 
 */
static inline uint32_t tcc_read_WEXCTRL(TCC_t *pTCC)
{
	return pTCC->WEXCTRL.reg;
}

/**
 * @brief tcc set DRVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_DRVCTRL_NRE0  Non-Recoverable State 0 Output Enable 
 * TCC_DRVCTRL_NRE1  Non-Recoverable State 1 Output Enable 
 * TCC_DRVCTRL_NRE2  Non-Recoverable State 2 Output Enable 
 * TCC_DRVCTRL_NRE3  Non-Recoverable State 3 Output Enable 
 * TCC_DRVCTRL_NRE4  Non-Recoverable State 4 Output Enable 
 * TCC_DRVCTRL_NRE5  Non-Recoverable State 5 Output Enable 
 * TCC_DRVCTRL_NRE6  Non-Recoverable State 6 Output Enable 
 * TCC_DRVCTRL_NRE7  Non-Recoverable State 7 Output Enable 
 * TCC_DRVCTRL_NRE(value)  Non-Recoverable State x Output Enable 
 * TCC_DRVCTRL_NRV0  Non-Recoverable State 0 Output Value 
 * TCC_DRVCTRL_NRV1  Non-Recoverable State 1 Output Value 
 * TCC_DRVCTRL_NRV2  Non-Recoverable State 2 Output Value 
 * TCC_DRVCTRL_NRV3  Non-Recoverable State 3 Output Value 
 * TCC_DRVCTRL_NRV4  Non-Recoverable State 4 Output Value 
 * TCC_DRVCTRL_NRV5  Non-Recoverable State 5 Output Value 
 * TCC_DRVCTRL_NRV6  Non-Recoverable State 6 Output Value 
 * TCC_DRVCTRL_NRV7  Non-Recoverable State 7 Output Value 
 * TCC_DRVCTRL_NRV(value)  Non-Recoverable State x Output Value 
 * TCC_DRVCTRL_INVEN0  Output Waveform 0 Inversion 
 * TCC_DRVCTRL_INVEN1  Output Waveform 1 Inversion 
 * TCC_DRVCTRL_INVEN2  Output Waveform 2 Inversion 
 * TCC_DRVCTRL_INVEN3  Output Waveform 3 Inversion 
 * TCC_DRVCTRL_INVEN4  Output Waveform 4 Inversion 
 * TCC_DRVCTRL_INVEN5  Output Waveform 5 Inversion 
 * TCC_DRVCTRL_INVEN6  Output Waveform 6 Inversion 
 * TCC_DRVCTRL_INVEN7  Output Waveform 7 Inversion 
 * TCC_DRVCTRL_INVEN(value)  Output Waveform x Inversion 
 * TCC_DRVCTRL_FILTERVAL0(value)  Non-Recoverable Fault Input 0 Filter Value 
 * TCC_DRVCTRL_FILTERVAL1(value)  Non-Recoverable Fault Input 1 Filter Value 
 */
static inline void tcc_set_DRVCTRL(TCC_t *pTCC, uint32_t mask)
{
	pTCC->DRVCTRL.reg |= mask;
}

/**
 * @brief tcc get DRVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_DRVCTRL_NRE0  Non-Recoverable State 0 Output Enable 
 * TCC_DRVCTRL_NRE1  Non-Recoverable State 1 Output Enable 
 * TCC_DRVCTRL_NRE2  Non-Recoverable State 2 Output Enable 
 * TCC_DRVCTRL_NRE3  Non-Recoverable State 3 Output Enable 
 * TCC_DRVCTRL_NRE4  Non-Recoverable State 4 Output Enable 
 * TCC_DRVCTRL_NRE5  Non-Recoverable State 5 Output Enable 
 * TCC_DRVCTRL_NRE6  Non-Recoverable State 6 Output Enable 
 * TCC_DRVCTRL_NRE7  Non-Recoverable State 7 Output Enable 
 * TCC_DRVCTRL_NRE(value)  Non-Recoverable State x Output Enable 
 * TCC_DRVCTRL_NRV0  Non-Recoverable State 0 Output Value 
 * TCC_DRVCTRL_NRV1  Non-Recoverable State 1 Output Value 
 * TCC_DRVCTRL_NRV2  Non-Recoverable State 2 Output Value 
 * TCC_DRVCTRL_NRV3  Non-Recoverable State 3 Output Value 
 * TCC_DRVCTRL_NRV4  Non-Recoverable State 4 Output Value 
 * TCC_DRVCTRL_NRV5  Non-Recoverable State 5 Output Value 
 * TCC_DRVCTRL_NRV6  Non-Recoverable State 6 Output Value 
 * TCC_DRVCTRL_NRV7  Non-Recoverable State 7 Output Value 
 * TCC_DRVCTRL_NRV(value)  Non-Recoverable State x Output Value 
 * TCC_DRVCTRL_INVEN0  Output Waveform 0 Inversion 
 * TCC_DRVCTRL_INVEN1  Output Waveform 1 Inversion 
 * TCC_DRVCTRL_INVEN2  Output Waveform 2 Inversion 
 * TCC_DRVCTRL_INVEN3  Output Waveform 3 Inversion 
 * TCC_DRVCTRL_INVEN4  Output Waveform 4 Inversion 
 * TCC_DRVCTRL_INVEN5  Output Waveform 5 Inversion 
 * TCC_DRVCTRL_INVEN6  Output Waveform 6 Inversion 
 * TCC_DRVCTRL_INVEN7  Output Waveform 7 Inversion 
 * TCC_DRVCTRL_INVEN(value)  Output Waveform x Inversion 
 * TCC_DRVCTRL_FILTERVAL0(value)  Non-Recoverable Fault Input 0 Filter Value 
 * TCC_DRVCTRL_FILTERVAL1(value)  Non-Recoverable Fault Input 1 Filter Value 
 */
static inline uint32_t tcc_get_DRVCTRL(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->DRVCTRL.reg & mask;
}

/**
 * @brief tcc write DRVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_DRVCTRL_NRE0  Non-Recoverable State 0 Output Enable 
 * TCC_DRVCTRL_NRE1  Non-Recoverable State 1 Output Enable 
 * TCC_DRVCTRL_NRE2  Non-Recoverable State 2 Output Enable 
 * TCC_DRVCTRL_NRE3  Non-Recoverable State 3 Output Enable 
 * TCC_DRVCTRL_NRE4  Non-Recoverable State 4 Output Enable 
 * TCC_DRVCTRL_NRE5  Non-Recoverable State 5 Output Enable 
 * TCC_DRVCTRL_NRE6  Non-Recoverable State 6 Output Enable 
 * TCC_DRVCTRL_NRE7  Non-Recoverable State 7 Output Enable 
 * TCC_DRVCTRL_NRE(value)  Non-Recoverable State x Output Enable 
 * TCC_DRVCTRL_NRV0  Non-Recoverable State 0 Output Value 
 * TCC_DRVCTRL_NRV1  Non-Recoverable State 1 Output Value 
 * TCC_DRVCTRL_NRV2  Non-Recoverable State 2 Output Value 
 * TCC_DRVCTRL_NRV3  Non-Recoverable State 3 Output Value 
 * TCC_DRVCTRL_NRV4  Non-Recoverable State 4 Output Value 
 * TCC_DRVCTRL_NRV5  Non-Recoverable State 5 Output Value 
 * TCC_DRVCTRL_NRV6  Non-Recoverable State 6 Output Value 
 * TCC_DRVCTRL_NRV7  Non-Recoverable State 7 Output Value 
 * TCC_DRVCTRL_NRV(value)  Non-Recoverable State x Output Value 
 * TCC_DRVCTRL_INVEN0  Output Waveform 0 Inversion 
 * TCC_DRVCTRL_INVEN1  Output Waveform 1 Inversion 
 * TCC_DRVCTRL_INVEN2  Output Waveform 2 Inversion 
 * TCC_DRVCTRL_INVEN3  Output Waveform 3 Inversion 
 * TCC_DRVCTRL_INVEN4  Output Waveform 4 Inversion 
 * TCC_DRVCTRL_INVEN5  Output Waveform 5 Inversion 
 * TCC_DRVCTRL_INVEN6  Output Waveform 6 Inversion 
 * TCC_DRVCTRL_INVEN7  Output Waveform 7 Inversion 
 * TCC_DRVCTRL_INVEN(value)  Output Waveform x Inversion 
 * TCC_DRVCTRL_FILTERVAL0(value)  Non-Recoverable Fault Input 0 Filter Value 
 * TCC_DRVCTRL_FILTERVAL1(value)  Non-Recoverable Fault Input 1 Filter Value 
 */
static inline void tcc_write_DRVCTRL(TCC_t *pTCC, uint32_t data)
{
	pTCC->DRVCTRL.reg = data;
}

/**
 * @brief tcc clear DRVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_DRVCTRL_NRE0  Non-Recoverable State 0 Output Enable 
 * TCC_DRVCTRL_NRE1  Non-Recoverable State 1 Output Enable 
 * TCC_DRVCTRL_NRE2  Non-Recoverable State 2 Output Enable 
 * TCC_DRVCTRL_NRE3  Non-Recoverable State 3 Output Enable 
 * TCC_DRVCTRL_NRE4  Non-Recoverable State 4 Output Enable 
 * TCC_DRVCTRL_NRE5  Non-Recoverable State 5 Output Enable 
 * TCC_DRVCTRL_NRE6  Non-Recoverable State 6 Output Enable 
 * TCC_DRVCTRL_NRE7  Non-Recoverable State 7 Output Enable 
 * TCC_DRVCTRL_NRE(value)  Non-Recoverable State x Output Enable 
 * TCC_DRVCTRL_NRV0  Non-Recoverable State 0 Output Value 
 * TCC_DRVCTRL_NRV1  Non-Recoverable State 1 Output Value 
 * TCC_DRVCTRL_NRV2  Non-Recoverable State 2 Output Value 
 * TCC_DRVCTRL_NRV3  Non-Recoverable State 3 Output Value 
 * TCC_DRVCTRL_NRV4  Non-Recoverable State 4 Output Value 
 * TCC_DRVCTRL_NRV5  Non-Recoverable State 5 Output Value 
 * TCC_DRVCTRL_NRV6  Non-Recoverable State 6 Output Value 
 * TCC_DRVCTRL_NRV7  Non-Recoverable State 7 Output Value 
 * TCC_DRVCTRL_NRV(value)  Non-Recoverable State x Output Value 
 * TCC_DRVCTRL_INVEN0  Output Waveform 0 Inversion 
 * TCC_DRVCTRL_INVEN1  Output Waveform 1 Inversion 
 * TCC_DRVCTRL_INVEN2  Output Waveform 2 Inversion 
 * TCC_DRVCTRL_INVEN3  Output Waveform 3 Inversion 
 * TCC_DRVCTRL_INVEN4  Output Waveform 4 Inversion 
 * TCC_DRVCTRL_INVEN5  Output Waveform 5 Inversion 
 * TCC_DRVCTRL_INVEN6  Output Waveform 6 Inversion 
 * TCC_DRVCTRL_INVEN7  Output Waveform 7 Inversion 
 * TCC_DRVCTRL_INVEN(value)  Output Waveform x Inversion 
 * TCC_DRVCTRL_FILTERVAL0(value)  Non-Recoverable Fault Input 0 Filter Value 
 * TCC_DRVCTRL_FILTERVAL1(value)  Non-Recoverable Fault Input 1 Filter Value 
 */
static inline void tcc_clear_DRVCTRL(TCC_t *pTCC, uint32_t mask)
{
	pTCC->DRVCTRL.reg &= ~mask;
}

/**
 * @brief tcc read DRVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_DRVCTRL_NRE0  Non-Recoverable State 0 Output Enable 
 * TCC_DRVCTRL_NRE1  Non-Recoverable State 1 Output Enable 
 * TCC_DRVCTRL_NRE2  Non-Recoverable State 2 Output Enable 
 * TCC_DRVCTRL_NRE3  Non-Recoverable State 3 Output Enable 
 * TCC_DRVCTRL_NRE4  Non-Recoverable State 4 Output Enable 
 * TCC_DRVCTRL_NRE5  Non-Recoverable State 5 Output Enable 
 * TCC_DRVCTRL_NRE6  Non-Recoverable State 6 Output Enable 
 * TCC_DRVCTRL_NRE7  Non-Recoverable State 7 Output Enable 
 * TCC_DRVCTRL_NRE(value)  Non-Recoverable State x Output Enable 
 * TCC_DRVCTRL_NRV0  Non-Recoverable State 0 Output Value 
 * TCC_DRVCTRL_NRV1  Non-Recoverable State 1 Output Value 
 * TCC_DRVCTRL_NRV2  Non-Recoverable State 2 Output Value 
 * TCC_DRVCTRL_NRV3  Non-Recoverable State 3 Output Value 
 * TCC_DRVCTRL_NRV4  Non-Recoverable State 4 Output Value 
 * TCC_DRVCTRL_NRV5  Non-Recoverable State 5 Output Value 
 * TCC_DRVCTRL_NRV6  Non-Recoverable State 6 Output Value 
 * TCC_DRVCTRL_NRV7  Non-Recoverable State 7 Output Value 
 * TCC_DRVCTRL_NRV(value)  Non-Recoverable State x Output Value 
 * TCC_DRVCTRL_INVEN0  Output Waveform 0 Inversion 
 * TCC_DRVCTRL_INVEN1  Output Waveform 1 Inversion 
 * TCC_DRVCTRL_INVEN2  Output Waveform 2 Inversion 
 * TCC_DRVCTRL_INVEN3  Output Waveform 3 Inversion 
 * TCC_DRVCTRL_INVEN4  Output Waveform 4 Inversion 
 * TCC_DRVCTRL_INVEN5  Output Waveform 5 Inversion 
 * TCC_DRVCTRL_INVEN6  Output Waveform 6 Inversion 
 * TCC_DRVCTRL_INVEN7  Output Waveform 7 Inversion 
 * TCC_DRVCTRL_INVEN(value)  Output Waveform x Inversion 
 * TCC_DRVCTRL_FILTERVAL0(value)  Non-Recoverable Fault Input 0 Filter Value 
 * TCC_DRVCTRL_FILTERVAL1(value)  Non-Recoverable Fault Input 1 Filter Value 
 */
static inline uint32_t tcc_read_DRVCTRL(TCC_t *pTCC)
{
	return pTCC->DRVCTRL.reg;
}

/**
 * @brief tcc set DBGCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t mask
 * TCC_DBGCTRL_DBGRUN  Debug Running Mode 
 * TCC_DBGCTRL_FDDBD  Fault Detection on Debug Break Detection 
 */
static inline void tcc_set_DBGCTRL(TCC_t *pTCC, uint8_t mask)
{
	pTCC->DBGCTRL.reg |= mask;
}

/**
 * @brief tcc get DBGCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t mask
 * @return uint8_t
 * TCC_DBGCTRL_DBGRUN  Debug Running Mode 
 * TCC_DBGCTRL_FDDBD  Fault Detection on Debug Break Detection 
 */
static inline uint8_t tcc_get_DBGCTRL(TCC_t *pTCC, uint8_t mask)
{
    return pTCC->DBGCTRL.reg & mask;
}

/**
 * @brief tcc write DBGCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t data
 * TCC_DBGCTRL_DBGRUN  Debug Running Mode 
 * TCC_DBGCTRL_FDDBD  Fault Detection on Debug Break Detection 
 */
static inline void tcc_write_DBGCTRL(TCC_t *pTCC, uint8_t data)
{
	pTCC->DBGCTRL.reg = data;
}

/**
 * @brief tcc clear DBGCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint8_t mask
 * TCC_DBGCTRL_DBGRUN  Debug Running Mode 
 * TCC_DBGCTRL_FDDBD  Fault Detection on Debug Break Detection 
 */
static inline void tcc_clear_DBGCTRL(TCC_t *pTCC, uint8_t mask)
{
	pTCC->DBGCTRL.reg &= ~mask;
}

/**
 * @brief tcc read DBGCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @return uint8_t
 * TCC_DBGCTRL_DBGRUN  Debug Running Mode 
 * TCC_DBGCTRL_FDDBD  Fault Detection on Debug Break Detection 
 */
static inline uint8_t tcc_read_DBGCTRL(TCC_t *pTCC)
{
	return pTCC->DBGCTRL.reg;
}

/**
 * @brief tcc set EVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_EVCTRL_EVACT0(value)  Timer/counter Input Event0 Action 
 *    TCC_EVCTRL_EVACT0_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT0_RETRIGGER  Start, restart or re-trigger counter on event 
 *    TCC_EVCTRL_EVACT0_COUNTEV  Count on event 
 *    TCC_EVCTRL_EVACT0_START  Start counter on event 
 *    TCC_EVCTRL_EVACT0_INC  Increment counter on event 
 *    TCC_EVCTRL_EVACT0_COUNT  Count on active state of asynchronous event 
 *    TCC_EVCTRL_EVACT0_STAMP  Stamp capture 
 *    TCC_EVCTRL_EVACT0_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_EVACT1(value)  Timer/counter Input Event1 Action 
 *    TCC_EVCTRL_EVACT1_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT1_RETRIGGER  Re-trigger counter on event 
 *    TCC_EVCTRL_EVACT1_DIR  Direction control 
 *    TCC_EVCTRL_EVACT1_STOP  Stop counter on event 
 *    TCC_EVCTRL_EVACT1_DEC  Decrement counter on event 
 *    TCC_EVCTRL_EVACT1_PPW  Period capture value in CC0 register, pulse width capture value in CC1 register 
 *    TCC_EVCTRL_EVACT1_PWP  Period capture value in CC1 register, pulse width capture value in CC0 register 
 *    TCC_EVCTRL_EVACT1_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_CNTSEL(value)  Timer/counter Output Event Mode 
 *    TCC_EVCTRL_CNTSEL_START  An interrupt/event is generated when a new counter cycle starts 
 *    TCC_EVCTRL_CNTSEL_END  An interrupt/event is generated when a counter cycle ends 
 *    TCC_EVCTRL_CNTSEL_BETWEEN  An interrupt/event is generated when a counter cycle ends, except for the first and last cycles 
 *    TCC_EVCTRL_CNTSEL_BOUNDARY  An interrupt/event is generated when a new counter cycle starts or a counter cycle ends 
 * TCC_EVCTRL_OVFEO  Overflow/Underflow Output Event Enable 
 * TCC_EVCTRL_TRGEO  Retrigger Output Event Enable 
 * TCC_EVCTRL_CNTEO  Timer/counter Output Event Enable 
 * TCC_EVCTRL_TCINV0  Inverted Event 0 Input Enable 
 * TCC_EVCTRL_TCINV1  Inverted Event 1 Input Enable 
 * TCC_EVCTRL_TCINV(value)  Inverted Event x Input Enable 
 * TCC_EVCTRL_TCEI0  Timer/counter Event 0 Input Enable 
 * TCC_EVCTRL_TCEI1  Timer/counter Event 1 Input Enable 
 * TCC_EVCTRL_TCEI(value)  Timer/counter Event x Input Enable 
 * TCC_EVCTRL_MCEI0  Match or Capture Channel 0 Event Input Enable 
 * TCC_EVCTRL_MCEI1  Match or Capture Channel 1 Event Input Enable 
 * TCC_EVCTRL_MCEI2  Match or Capture Channel 2 Event Input Enable 
 * TCC_EVCTRL_MCEI3  Match or Capture Channel 3 Event Input Enable 
 * TCC_EVCTRL_MCEI4  Match or Capture Channel 4 Event Input Enable 
 * TCC_EVCTRL_MCEI5  Match or Capture Channel 5 Event Input Enable 
 * TCC_EVCTRL_MCEI(value)  Match or Capture Channel x Event Input Enable 
 * TCC_EVCTRL_MCEO0  Match or Capture Channel 0 Event Output Enable 
 * TCC_EVCTRL_MCEO1  Match or Capture Channel 1 Event Output Enable 
 * TCC_EVCTRL_MCEO2  Match or Capture Channel 2 Event Output Enable 
 * TCC_EVCTRL_MCEO3  Match or Capture Channel 3 Event Output Enable 
 * TCC_EVCTRL_MCEO4  Match or Capture Channel 4 Event Output Enable 
 * TCC_EVCTRL_MCEO5  Match or Capture Channel 5 Event Output Enable 
 * TCC_EVCTRL_MCEO(value)  Match or Capture Channel x Event Output Enable 
 */
static inline void tcc_set_EVCTRL(TCC_t *pTCC, uint32_t mask)
{
	pTCC->EVCTRL.reg |= mask;
}

/**
 * @brief tcc get EVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_EVCTRL_EVACT0(value)  Timer/counter Input Event0 Action 
 *    TCC_EVCTRL_EVACT0_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT0_RETRIGGER  Start, restart or re-trigger counter on event 
 *    TCC_EVCTRL_EVACT0_COUNTEV  Count on event 
 *    TCC_EVCTRL_EVACT0_START  Start counter on event 
 *    TCC_EVCTRL_EVACT0_INC  Increment counter on event 
 *    TCC_EVCTRL_EVACT0_COUNT  Count on active state of asynchronous event 
 *    TCC_EVCTRL_EVACT0_STAMP  Stamp capture 
 *    TCC_EVCTRL_EVACT0_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_EVACT1(value)  Timer/counter Input Event1 Action 
 *    TCC_EVCTRL_EVACT1_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT1_RETRIGGER  Re-trigger counter on event 
 *    TCC_EVCTRL_EVACT1_DIR  Direction control 
 *    TCC_EVCTRL_EVACT1_STOP  Stop counter on event 
 *    TCC_EVCTRL_EVACT1_DEC  Decrement counter on event 
 *    TCC_EVCTRL_EVACT1_PPW  Period capture value in CC0 register, pulse width capture value in CC1 register 
 *    TCC_EVCTRL_EVACT1_PWP  Period capture value in CC1 register, pulse width capture value in CC0 register 
 *    TCC_EVCTRL_EVACT1_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_CNTSEL(value)  Timer/counter Output Event Mode 
 *    TCC_EVCTRL_CNTSEL_START  An interrupt/event is generated when a new counter cycle starts 
 *    TCC_EVCTRL_CNTSEL_END  An interrupt/event is generated when a counter cycle ends 
 *    TCC_EVCTRL_CNTSEL_BETWEEN  An interrupt/event is generated when a counter cycle ends, except for the first and last cycles 
 *    TCC_EVCTRL_CNTSEL_BOUNDARY  An interrupt/event is generated when a new counter cycle starts or a counter cycle ends 
 * TCC_EVCTRL_OVFEO  Overflow/Underflow Output Event Enable 
 * TCC_EVCTRL_TRGEO  Retrigger Output Event Enable 
 * TCC_EVCTRL_CNTEO  Timer/counter Output Event Enable 
 * TCC_EVCTRL_TCINV0  Inverted Event 0 Input Enable 
 * TCC_EVCTRL_TCINV1  Inverted Event 1 Input Enable 
 * TCC_EVCTRL_TCINV(value)  Inverted Event x Input Enable 
 * TCC_EVCTRL_TCEI0  Timer/counter Event 0 Input Enable 
 * TCC_EVCTRL_TCEI1  Timer/counter Event 1 Input Enable 
 * TCC_EVCTRL_TCEI(value)  Timer/counter Event x Input Enable 
 * TCC_EVCTRL_MCEI0  Match or Capture Channel 0 Event Input Enable 
 * TCC_EVCTRL_MCEI1  Match or Capture Channel 1 Event Input Enable 
 * TCC_EVCTRL_MCEI2  Match or Capture Channel 2 Event Input Enable 
 * TCC_EVCTRL_MCEI3  Match or Capture Channel 3 Event Input Enable 
 * TCC_EVCTRL_MCEI4  Match or Capture Channel 4 Event Input Enable 
 * TCC_EVCTRL_MCEI5  Match or Capture Channel 5 Event Input Enable 
 * TCC_EVCTRL_MCEI(value)  Match or Capture Channel x Event Input Enable 
 * TCC_EVCTRL_MCEO0  Match or Capture Channel 0 Event Output Enable 
 * TCC_EVCTRL_MCEO1  Match or Capture Channel 1 Event Output Enable 
 * TCC_EVCTRL_MCEO2  Match or Capture Channel 2 Event Output Enable 
 * TCC_EVCTRL_MCEO3  Match or Capture Channel 3 Event Output Enable 
 * TCC_EVCTRL_MCEO4  Match or Capture Channel 4 Event Output Enable 
 * TCC_EVCTRL_MCEO5  Match or Capture Channel 5 Event Output Enable 
 * TCC_EVCTRL_MCEO(value)  Match or Capture Channel x Event Output Enable 
 */
static inline uint32_t tcc_get_EVCTRL(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->EVCTRL.reg & mask;
}

/**
 * @brief tcc write EVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_EVCTRL_EVACT0(value)  Timer/counter Input Event0 Action 
 *    TCC_EVCTRL_EVACT0_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT0_RETRIGGER  Start, restart or re-trigger counter on event 
 *    TCC_EVCTRL_EVACT0_COUNTEV  Count on event 
 *    TCC_EVCTRL_EVACT0_START  Start counter on event 
 *    TCC_EVCTRL_EVACT0_INC  Increment counter on event 
 *    TCC_EVCTRL_EVACT0_COUNT  Count on active state of asynchronous event 
 *    TCC_EVCTRL_EVACT0_STAMP  Stamp capture 
 *    TCC_EVCTRL_EVACT0_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_EVACT1(value)  Timer/counter Input Event1 Action 
 *    TCC_EVCTRL_EVACT1_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT1_RETRIGGER  Re-trigger counter on event 
 *    TCC_EVCTRL_EVACT1_DIR  Direction control 
 *    TCC_EVCTRL_EVACT1_STOP  Stop counter on event 
 *    TCC_EVCTRL_EVACT1_DEC  Decrement counter on event 
 *    TCC_EVCTRL_EVACT1_PPW  Period capture value in CC0 register, pulse width capture value in CC1 register 
 *    TCC_EVCTRL_EVACT1_PWP  Period capture value in CC1 register, pulse width capture value in CC0 register 
 *    TCC_EVCTRL_EVACT1_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_CNTSEL(value)  Timer/counter Output Event Mode 
 *    TCC_EVCTRL_CNTSEL_START  An interrupt/event is generated when a new counter cycle starts 
 *    TCC_EVCTRL_CNTSEL_END  An interrupt/event is generated when a counter cycle ends 
 *    TCC_EVCTRL_CNTSEL_BETWEEN  An interrupt/event is generated when a counter cycle ends, except for the first and last cycles 
 *    TCC_EVCTRL_CNTSEL_BOUNDARY  An interrupt/event is generated when a new counter cycle starts or a counter cycle ends 
 * TCC_EVCTRL_OVFEO  Overflow/Underflow Output Event Enable 
 * TCC_EVCTRL_TRGEO  Retrigger Output Event Enable 
 * TCC_EVCTRL_CNTEO  Timer/counter Output Event Enable 
 * TCC_EVCTRL_TCINV0  Inverted Event 0 Input Enable 
 * TCC_EVCTRL_TCINV1  Inverted Event 1 Input Enable 
 * TCC_EVCTRL_TCINV(value)  Inverted Event x Input Enable 
 * TCC_EVCTRL_TCEI0  Timer/counter Event 0 Input Enable 
 * TCC_EVCTRL_TCEI1  Timer/counter Event 1 Input Enable 
 * TCC_EVCTRL_TCEI(value)  Timer/counter Event x Input Enable 
 * TCC_EVCTRL_MCEI0  Match or Capture Channel 0 Event Input Enable 
 * TCC_EVCTRL_MCEI1  Match or Capture Channel 1 Event Input Enable 
 * TCC_EVCTRL_MCEI2  Match or Capture Channel 2 Event Input Enable 
 * TCC_EVCTRL_MCEI3  Match or Capture Channel 3 Event Input Enable 
 * TCC_EVCTRL_MCEI4  Match or Capture Channel 4 Event Input Enable 
 * TCC_EVCTRL_MCEI5  Match or Capture Channel 5 Event Input Enable 
 * TCC_EVCTRL_MCEI(value)  Match or Capture Channel x Event Input Enable 
 * TCC_EVCTRL_MCEO0  Match or Capture Channel 0 Event Output Enable 
 * TCC_EVCTRL_MCEO1  Match or Capture Channel 1 Event Output Enable 
 * TCC_EVCTRL_MCEO2  Match or Capture Channel 2 Event Output Enable 
 * TCC_EVCTRL_MCEO3  Match or Capture Channel 3 Event Output Enable 
 * TCC_EVCTRL_MCEO4  Match or Capture Channel 4 Event Output Enable 
 * TCC_EVCTRL_MCEO5  Match or Capture Channel 5 Event Output Enable 
 * TCC_EVCTRL_MCEO(value)  Match or Capture Channel x Event Output Enable 
 */
static inline void tcc_write_EVCTRL(TCC_t *pTCC, uint32_t data)
{
	pTCC->EVCTRL.reg = data;
}

/**
 * @brief tcc clear EVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_EVCTRL_EVACT0(value)  Timer/counter Input Event0 Action 
 *    TCC_EVCTRL_EVACT0_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT0_RETRIGGER  Start, restart or re-trigger counter on event 
 *    TCC_EVCTRL_EVACT0_COUNTEV  Count on event 
 *    TCC_EVCTRL_EVACT0_START  Start counter on event 
 *    TCC_EVCTRL_EVACT0_INC  Increment counter on event 
 *    TCC_EVCTRL_EVACT0_COUNT  Count on active state of asynchronous event 
 *    TCC_EVCTRL_EVACT0_STAMP  Stamp capture 
 *    TCC_EVCTRL_EVACT0_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_EVACT1(value)  Timer/counter Input Event1 Action 
 *    TCC_EVCTRL_EVACT1_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT1_RETRIGGER  Re-trigger counter on event 
 *    TCC_EVCTRL_EVACT1_DIR  Direction control 
 *    TCC_EVCTRL_EVACT1_STOP  Stop counter on event 
 *    TCC_EVCTRL_EVACT1_DEC  Decrement counter on event 
 *    TCC_EVCTRL_EVACT1_PPW  Period capture value in CC0 register, pulse width capture value in CC1 register 
 *    TCC_EVCTRL_EVACT1_PWP  Period capture value in CC1 register, pulse width capture value in CC0 register 
 *    TCC_EVCTRL_EVACT1_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_CNTSEL(value)  Timer/counter Output Event Mode 
 *    TCC_EVCTRL_CNTSEL_START  An interrupt/event is generated when a new counter cycle starts 
 *    TCC_EVCTRL_CNTSEL_END  An interrupt/event is generated when a counter cycle ends 
 *    TCC_EVCTRL_CNTSEL_BETWEEN  An interrupt/event is generated when a counter cycle ends, except for the first and last cycles 
 *    TCC_EVCTRL_CNTSEL_BOUNDARY  An interrupt/event is generated when a new counter cycle starts or a counter cycle ends 
 * TCC_EVCTRL_OVFEO  Overflow/Underflow Output Event Enable 
 * TCC_EVCTRL_TRGEO  Retrigger Output Event Enable 
 * TCC_EVCTRL_CNTEO  Timer/counter Output Event Enable 
 * TCC_EVCTRL_TCINV0  Inverted Event 0 Input Enable 
 * TCC_EVCTRL_TCINV1  Inverted Event 1 Input Enable 
 * TCC_EVCTRL_TCINV(value)  Inverted Event x Input Enable 
 * TCC_EVCTRL_TCEI0  Timer/counter Event 0 Input Enable 
 * TCC_EVCTRL_TCEI1  Timer/counter Event 1 Input Enable 
 * TCC_EVCTRL_TCEI(value)  Timer/counter Event x Input Enable 
 * TCC_EVCTRL_MCEI0  Match or Capture Channel 0 Event Input Enable 
 * TCC_EVCTRL_MCEI1  Match or Capture Channel 1 Event Input Enable 
 * TCC_EVCTRL_MCEI2  Match or Capture Channel 2 Event Input Enable 
 * TCC_EVCTRL_MCEI3  Match or Capture Channel 3 Event Input Enable 
 * TCC_EVCTRL_MCEI4  Match or Capture Channel 4 Event Input Enable 
 * TCC_EVCTRL_MCEI5  Match or Capture Channel 5 Event Input Enable 
 * TCC_EVCTRL_MCEI(value)  Match or Capture Channel x Event Input Enable 
 * TCC_EVCTRL_MCEO0  Match or Capture Channel 0 Event Output Enable 
 * TCC_EVCTRL_MCEO1  Match or Capture Channel 1 Event Output Enable 
 * TCC_EVCTRL_MCEO2  Match or Capture Channel 2 Event Output Enable 
 * TCC_EVCTRL_MCEO3  Match or Capture Channel 3 Event Output Enable 
 * TCC_EVCTRL_MCEO4  Match or Capture Channel 4 Event Output Enable 
 * TCC_EVCTRL_MCEO5  Match or Capture Channel 5 Event Output Enable 
 * TCC_EVCTRL_MCEO(value)  Match or Capture Channel x Event Output Enable 
 */
static inline void tcc_clear_EVCTRL(TCC_t *pTCC, uint32_t mask)
{
	pTCC->EVCTRL.reg &= ~mask;
}

/**
 * @brief tcc read EVCTRL register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_EVCTRL_EVACT0(value)  Timer/counter Input Event0 Action 
 *    TCC_EVCTRL_EVACT0_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT0_RETRIGGER  Start, restart or re-trigger counter on event 
 *    TCC_EVCTRL_EVACT0_COUNTEV  Count on event 
 *    TCC_EVCTRL_EVACT0_START  Start counter on event 
 *    TCC_EVCTRL_EVACT0_INC  Increment counter on event 
 *    TCC_EVCTRL_EVACT0_COUNT  Count on active state of asynchronous event 
 *    TCC_EVCTRL_EVACT0_STAMP  Stamp capture 
 *    TCC_EVCTRL_EVACT0_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_EVACT1(value)  Timer/counter Input Event1 Action 
 *    TCC_EVCTRL_EVACT1_OFF  Event action disabled 
 *    TCC_EVCTRL_EVACT1_RETRIGGER  Re-trigger counter on event 
 *    TCC_EVCTRL_EVACT1_DIR  Direction control 
 *    TCC_EVCTRL_EVACT1_STOP  Stop counter on event 
 *    TCC_EVCTRL_EVACT1_DEC  Decrement counter on event 
 *    TCC_EVCTRL_EVACT1_PPW  Period capture value in CC0 register, pulse width capture value in CC1 register 
 *    TCC_EVCTRL_EVACT1_PWP  Period capture value in CC1 register, pulse width capture value in CC0 register 
 *    TCC_EVCTRL_EVACT1_FAULT  Non-recoverable fault 
 * TCC_EVCTRL_CNTSEL(value)  Timer/counter Output Event Mode 
 *    TCC_EVCTRL_CNTSEL_START  An interrupt/event is generated when a new counter cycle starts 
 *    TCC_EVCTRL_CNTSEL_END  An interrupt/event is generated when a counter cycle ends 
 *    TCC_EVCTRL_CNTSEL_BETWEEN  An interrupt/event is generated when a counter cycle ends, except for the first and last cycles 
 *    TCC_EVCTRL_CNTSEL_BOUNDARY  An interrupt/event is generated when a new counter cycle starts or a counter cycle ends 
 * TCC_EVCTRL_OVFEO  Overflow/Underflow Output Event Enable 
 * TCC_EVCTRL_TRGEO  Retrigger Output Event Enable 
 * TCC_EVCTRL_CNTEO  Timer/counter Output Event Enable 
 * TCC_EVCTRL_TCINV0  Inverted Event 0 Input Enable 
 * TCC_EVCTRL_TCINV1  Inverted Event 1 Input Enable 
 * TCC_EVCTRL_TCINV(value)  Inverted Event x Input Enable 
 * TCC_EVCTRL_TCEI0  Timer/counter Event 0 Input Enable 
 * TCC_EVCTRL_TCEI1  Timer/counter Event 1 Input Enable 
 * TCC_EVCTRL_TCEI(value)  Timer/counter Event x Input Enable 
 * TCC_EVCTRL_MCEI0  Match or Capture Channel 0 Event Input Enable 
 * TCC_EVCTRL_MCEI1  Match or Capture Channel 1 Event Input Enable 
 * TCC_EVCTRL_MCEI2  Match or Capture Channel 2 Event Input Enable 
 * TCC_EVCTRL_MCEI3  Match or Capture Channel 3 Event Input Enable 
 * TCC_EVCTRL_MCEI4  Match or Capture Channel 4 Event Input Enable 
 * TCC_EVCTRL_MCEI5  Match or Capture Channel 5 Event Input Enable 
 * TCC_EVCTRL_MCEI(value)  Match or Capture Channel x Event Input Enable 
 * TCC_EVCTRL_MCEO0  Match or Capture Channel 0 Event Output Enable 
 * TCC_EVCTRL_MCEO1  Match or Capture Channel 1 Event Output Enable 
 * TCC_EVCTRL_MCEO2  Match or Capture Channel 2 Event Output Enable 
 * TCC_EVCTRL_MCEO3  Match or Capture Channel 3 Event Output Enable 
 * TCC_EVCTRL_MCEO4  Match or Capture Channel 4 Event Output Enable 
 * TCC_EVCTRL_MCEO5  Match or Capture Channel 5 Event Output Enable 
 * TCC_EVCTRL_MCEO(value)  Match or Capture Channel x Event Output Enable 
 */
static inline uint32_t tcc_read_EVCTRL(TCC_t *pTCC)
{
	return pTCC->EVCTRL.reg;
}

/**
 * @brief tcc set PATT register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint16_t mask
 * TCC_PATT_PGE0  Pattern Generator 0 Output Enable 
 * TCC_PATT_PGE1  Pattern Generator 1 Output Enable 
 * TCC_PATT_PGE2  Pattern Generator 2 Output Enable 
 * TCC_PATT_PGE3  Pattern Generator 3 Output Enable 
 * TCC_PATT_PGE4  Pattern Generator 4 Output Enable 
 * TCC_PATT_PGE5  Pattern Generator 5 Output Enable 
 * TCC_PATT_PGE6  Pattern Generator 6 Output Enable 
 * TCC_PATT_PGE7  Pattern Generator 7 Output Enable 
 * TCC_PATT_PGE(value)  Pattern Generator x Output Enable 
 * TCC_PATT_PGV0  Pattern Generator 0 Output Value 
 * TCC_PATT_PGV1  Pattern Generator 1 Output Value 
 * TCC_PATT_PGV2  Pattern Generator 2 Output Value 
 * TCC_PATT_PGV3  Pattern Generator 3 Output Value 
 * TCC_PATT_PGV4  Pattern Generator 4 Output Value 
 * TCC_PATT_PGV5  Pattern Generator 5 Output Value 
 * TCC_PATT_PGV6  Pattern Generator 6 Output Value 
 * TCC_PATT_PGV7  Pattern Generator 7 Output Value 
 * TCC_PATT_PGV(value)  Pattern Generator x Output Value 
 */
static inline void tcc_set_PATT(TCC_t *pTCC, uint16_t mask)
{
	pTCC->PATT.reg |= mask;
}

/**
 * @brief tcc get PATT register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint16_t mask
 * @return uint16_t
 * TCC_PATT_PGE0  Pattern Generator 0 Output Enable 
 * TCC_PATT_PGE1  Pattern Generator 1 Output Enable 
 * TCC_PATT_PGE2  Pattern Generator 2 Output Enable 
 * TCC_PATT_PGE3  Pattern Generator 3 Output Enable 
 * TCC_PATT_PGE4  Pattern Generator 4 Output Enable 
 * TCC_PATT_PGE5  Pattern Generator 5 Output Enable 
 * TCC_PATT_PGE6  Pattern Generator 6 Output Enable 
 * TCC_PATT_PGE7  Pattern Generator 7 Output Enable 
 * TCC_PATT_PGE(value)  Pattern Generator x Output Enable 
 * TCC_PATT_PGV0  Pattern Generator 0 Output Value 
 * TCC_PATT_PGV1  Pattern Generator 1 Output Value 
 * TCC_PATT_PGV2  Pattern Generator 2 Output Value 
 * TCC_PATT_PGV3  Pattern Generator 3 Output Value 
 * TCC_PATT_PGV4  Pattern Generator 4 Output Value 
 * TCC_PATT_PGV5  Pattern Generator 5 Output Value 
 * TCC_PATT_PGV6  Pattern Generator 6 Output Value 
 * TCC_PATT_PGV7  Pattern Generator 7 Output Value 
 * TCC_PATT_PGV(value)  Pattern Generator x Output Value 
 */
static inline uint16_t tcc_get_PATT(TCC_t *pTCC, uint16_t mask)
{
    return pTCC->PATT.reg & mask;
}

/**
 * @brief tcc write PATT register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint16_t data
 * TCC_PATT_PGE0  Pattern Generator 0 Output Enable 
 * TCC_PATT_PGE1  Pattern Generator 1 Output Enable 
 * TCC_PATT_PGE2  Pattern Generator 2 Output Enable 
 * TCC_PATT_PGE3  Pattern Generator 3 Output Enable 
 * TCC_PATT_PGE4  Pattern Generator 4 Output Enable 
 * TCC_PATT_PGE5  Pattern Generator 5 Output Enable 
 * TCC_PATT_PGE6  Pattern Generator 6 Output Enable 
 * TCC_PATT_PGE7  Pattern Generator 7 Output Enable 
 * TCC_PATT_PGE(value)  Pattern Generator x Output Enable 
 * TCC_PATT_PGV0  Pattern Generator 0 Output Value 
 * TCC_PATT_PGV1  Pattern Generator 1 Output Value 
 * TCC_PATT_PGV2  Pattern Generator 2 Output Value 
 * TCC_PATT_PGV3  Pattern Generator 3 Output Value 
 * TCC_PATT_PGV4  Pattern Generator 4 Output Value 
 * TCC_PATT_PGV5  Pattern Generator 5 Output Value 
 * TCC_PATT_PGV6  Pattern Generator 6 Output Value 
 * TCC_PATT_PGV7  Pattern Generator 7 Output Value 
 * TCC_PATT_PGV(value)  Pattern Generator x Output Value 
 */
static inline void tcc_write_PATT(TCC_t *pTCC, uint16_t data)
{
	pTCC->PATT.reg = data;
}

/**
 * @brief tcc clear PATT register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint16_t mask
 * TCC_PATT_PGE0  Pattern Generator 0 Output Enable 
 * TCC_PATT_PGE1  Pattern Generator 1 Output Enable 
 * TCC_PATT_PGE2  Pattern Generator 2 Output Enable 
 * TCC_PATT_PGE3  Pattern Generator 3 Output Enable 
 * TCC_PATT_PGE4  Pattern Generator 4 Output Enable 
 * TCC_PATT_PGE5  Pattern Generator 5 Output Enable 
 * TCC_PATT_PGE6  Pattern Generator 6 Output Enable 
 * TCC_PATT_PGE7  Pattern Generator 7 Output Enable 
 * TCC_PATT_PGE(value)  Pattern Generator x Output Enable 
 * TCC_PATT_PGV0  Pattern Generator 0 Output Value 
 * TCC_PATT_PGV1  Pattern Generator 1 Output Value 
 * TCC_PATT_PGV2  Pattern Generator 2 Output Value 
 * TCC_PATT_PGV3  Pattern Generator 3 Output Value 
 * TCC_PATT_PGV4  Pattern Generator 4 Output Value 
 * TCC_PATT_PGV5  Pattern Generator 5 Output Value 
 * TCC_PATT_PGV6  Pattern Generator 6 Output Value 
 * TCC_PATT_PGV7  Pattern Generator 7 Output Value 
 * TCC_PATT_PGV(value)  Pattern Generator x Output Value 
 */
static inline void tcc_clear_PATT(TCC_t *pTCC, uint16_t mask)
{
	pTCC->PATT.reg &= ~mask;
}

/**
 * @brief tcc read PATT register
 *
 * @param[in] TCC_t *pTCC
 * @return uint16_t
 * TCC_PATT_PGE0  Pattern Generator 0 Output Enable 
 * TCC_PATT_PGE1  Pattern Generator 1 Output Enable 
 * TCC_PATT_PGE2  Pattern Generator 2 Output Enable 
 * TCC_PATT_PGE3  Pattern Generator 3 Output Enable 
 * TCC_PATT_PGE4  Pattern Generator 4 Output Enable 
 * TCC_PATT_PGE5  Pattern Generator 5 Output Enable 
 * TCC_PATT_PGE6  Pattern Generator 6 Output Enable 
 * TCC_PATT_PGE7  Pattern Generator 7 Output Enable 
 * TCC_PATT_PGE(value)  Pattern Generator x Output Enable 
 * TCC_PATT_PGV0  Pattern Generator 0 Output Value 
 * TCC_PATT_PGV1  Pattern Generator 1 Output Value 
 * TCC_PATT_PGV2  Pattern Generator 2 Output Value 
 * TCC_PATT_PGV3  Pattern Generator 3 Output Value 
 * TCC_PATT_PGV4  Pattern Generator 4 Output Value 
 * TCC_PATT_PGV5  Pattern Generator 5 Output Value 
 * TCC_PATT_PGV6  Pattern Generator 6 Output Value 
 * TCC_PATT_PGV7  Pattern Generator 7 Output Value 
 * TCC_PATT_PGV(value)  Pattern Generator x Output Value 
 */
static inline uint16_t tcc_read_PATT(TCC_t *pTCC)
{
	return pTCC->PATT.reg;
}

/**
 * @brief tcc set WAVE register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_WAVE_WAVEGEN(value)  Waveform Generation 
 *    TCC_WAVE_WAVEGEN_NFRQ  Normal frequency 
 *    TCC_WAVE_WAVEGEN_MFRQ  Match frequency 
 *    TCC_WAVE_WAVEGEN_NPWM  Normal PWM 
 *    TCC_WAVE_WAVEGEN_DSCRITICAL  Dual-slope critical 
 *    TCC_WAVE_WAVEGEN_DSBOTTOM  Dual-slope with interrupt/event condition when COUNT reaches ZERO 
 *    TCC_WAVE_WAVEGEN_DSBOTH  Dual-slope with interrupt/event condition when COUNT reaches ZERO or TOP 
 *    TCC_WAVE_WAVEGEN_DSTOP  Dual-slope with interrupt/event condition when COUNT reaches TOP 
 * TCC_WAVE_RAMP(value)  Ramp Mode 
 *    TCC_WAVE_RAMP_RAMP1  RAMP1 operation 
 *    TCC_WAVE_RAMP_RAMP2A  Alternative RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2  RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2C  Critical RAMP2 operation 
 * TCC_WAVE_CIPEREN  Circular period Enable 
 * TCC_WAVE_CICCEN0  Circular Channel 0 Enable 
 * TCC_WAVE_CICCEN1  Circular Channel 1 Enable 
 * TCC_WAVE_CICCEN2  Circular Channel 2 Enable 
 * TCC_WAVE_CICCEN3  Circular Channel 3 Enable 
 * TCC_WAVE_CICCEN(value)  Circular Channel x Enable 
 * TCC_WAVE_POL0  Channel 0 Polarity 
 * TCC_WAVE_POL1  Channel 1 Polarity 
 * TCC_WAVE_POL2  Channel 2 Polarity 
 * TCC_WAVE_POL3  Channel 3 Polarity 
 * TCC_WAVE_POL4  Channel 4 Polarity 
 * TCC_WAVE_POL5  Channel 5 Polarity 
 * TCC_WAVE_POL(value)  Channel x Polarity 
 * TCC_WAVE_SWAP0  Swap DTI Output Pair 0 
 * TCC_WAVE_SWAP1  Swap DTI Output Pair 1 
 * TCC_WAVE_SWAP2  Swap DTI Output Pair 2 
 * TCC_WAVE_SWAP3  Swap DTI Output Pair 3 
 * TCC_WAVE_SWAP(value)  Swap DTI Output Pair x 
 */
static inline void tcc_set_WAVE(TCC_t *pTCC, uint32_t mask)
{
	pTCC->WAVE.reg |= mask;
}

/**
 * @brief tcc get WAVE register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_WAVE_WAVEGEN(value)  Waveform Generation 
 *    TCC_WAVE_WAVEGEN_NFRQ  Normal frequency 
 *    TCC_WAVE_WAVEGEN_MFRQ  Match frequency 
 *    TCC_WAVE_WAVEGEN_NPWM  Normal PWM 
 *    TCC_WAVE_WAVEGEN_DSCRITICAL  Dual-slope critical 
 *    TCC_WAVE_WAVEGEN_DSBOTTOM  Dual-slope with interrupt/event condition when COUNT reaches ZERO 
 *    TCC_WAVE_WAVEGEN_DSBOTH  Dual-slope with interrupt/event condition when COUNT reaches ZERO or TOP 
 *    TCC_WAVE_WAVEGEN_DSTOP  Dual-slope with interrupt/event condition when COUNT reaches TOP 
 * TCC_WAVE_RAMP(value)  Ramp Mode 
 *    TCC_WAVE_RAMP_RAMP1  RAMP1 operation 
 *    TCC_WAVE_RAMP_RAMP2A  Alternative RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2  RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2C  Critical RAMP2 operation 
 * TCC_WAVE_CIPEREN  Circular period Enable 
 * TCC_WAVE_CICCEN0  Circular Channel 0 Enable 
 * TCC_WAVE_CICCEN1  Circular Channel 1 Enable 
 * TCC_WAVE_CICCEN2  Circular Channel 2 Enable 
 * TCC_WAVE_CICCEN3  Circular Channel 3 Enable 
 * TCC_WAVE_CICCEN(value)  Circular Channel x Enable 
 * TCC_WAVE_POL0  Channel 0 Polarity 
 * TCC_WAVE_POL1  Channel 1 Polarity 
 * TCC_WAVE_POL2  Channel 2 Polarity 
 * TCC_WAVE_POL3  Channel 3 Polarity 
 * TCC_WAVE_POL4  Channel 4 Polarity 
 * TCC_WAVE_POL5  Channel 5 Polarity 
 * TCC_WAVE_POL(value)  Channel x Polarity 
 * TCC_WAVE_SWAP0  Swap DTI Output Pair 0 
 * TCC_WAVE_SWAP1  Swap DTI Output Pair 1 
 * TCC_WAVE_SWAP2  Swap DTI Output Pair 2 
 * TCC_WAVE_SWAP3  Swap DTI Output Pair 3 
 * TCC_WAVE_SWAP(value)  Swap DTI Output Pair x 
 */
static inline uint32_t tcc_get_WAVE(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->WAVE.reg & mask;
}

/**
 * @brief tcc write WAVE register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t data
 * TCC_WAVE_WAVEGEN(value)  Waveform Generation 
 *    TCC_WAVE_WAVEGEN_NFRQ  Normal frequency 
 *    TCC_WAVE_WAVEGEN_MFRQ  Match frequency 
 *    TCC_WAVE_WAVEGEN_NPWM  Normal PWM 
 *    TCC_WAVE_WAVEGEN_DSCRITICAL  Dual-slope critical 
 *    TCC_WAVE_WAVEGEN_DSBOTTOM  Dual-slope with interrupt/event condition when COUNT reaches ZERO 
 *    TCC_WAVE_WAVEGEN_DSBOTH  Dual-slope with interrupt/event condition when COUNT reaches ZERO or TOP 
 *    TCC_WAVE_WAVEGEN_DSTOP  Dual-slope with interrupt/event condition when COUNT reaches TOP 
 * TCC_WAVE_RAMP(value)  Ramp Mode 
 *    TCC_WAVE_RAMP_RAMP1  RAMP1 operation 
 *    TCC_WAVE_RAMP_RAMP2A  Alternative RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2  RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2C  Critical RAMP2 operation 
 * TCC_WAVE_CIPEREN  Circular period Enable 
 * TCC_WAVE_CICCEN0  Circular Channel 0 Enable 
 * TCC_WAVE_CICCEN1  Circular Channel 1 Enable 
 * TCC_WAVE_CICCEN2  Circular Channel 2 Enable 
 * TCC_WAVE_CICCEN3  Circular Channel 3 Enable 
 * TCC_WAVE_CICCEN(value)  Circular Channel x Enable 
 * TCC_WAVE_POL0  Channel 0 Polarity 
 * TCC_WAVE_POL1  Channel 1 Polarity 
 * TCC_WAVE_POL2  Channel 2 Polarity 
 * TCC_WAVE_POL3  Channel 3 Polarity 
 * TCC_WAVE_POL4  Channel 4 Polarity 
 * TCC_WAVE_POL5  Channel 5 Polarity 
 * TCC_WAVE_POL(value)  Channel x Polarity 
 * TCC_WAVE_SWAP0  Swap DTI Output Pair 0 
 * TCC_WAVE_SWAP1  Swap DTI Output Pair 1 
 * TCC_WAVE_SWAP2  Swap DTI Output Pair 2 
 * TCC_WAVE_SWAP3  Swap DTI Output Pair 3 
 * TCC_WAVE_SWAP(value)  Swap DTI Output Pair x 
 */
static inline void tcc_write_WAVE(TCC_t *pTCC, uint32_t data)
{
	pTCC->WAVE.reg = data;
}

/**
 * @brief tcc clear WAVE register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_WAVE_WAVEGEN(value)  Waveform Generation 
 *    TCC_WAVE_WAVEGEN_NFRQ  Normal frequency 
 *    TCC_WAVE_WAVEGEN_MFRQ  Match frequency 
 *    TCC_WAVE_WAVEGEN_NPWM  Normal PWM 
 *    TCC_WAVE_WAVEGEN_DSCRITICAL  Dual-slope critical 
 *    TCC_WAVE_WAVEGEN_DSBOTTOM  Dual-slope with interrupt/event condition when COUNT reaches ZERO 
 *    TCC_WAVE_WAVEGEN_DSBOTH  Dual-slope with interrupt/event condition when COUNT reaches ZERO or TOP 
 *    TCC_WAVE_WAVEGEN_DSTOP  Dual-slope with interrupt/event condition when COUNT reaches TOP 
 * TCC_WAVE_RAMP(value)  Ramp Mode 
 *    TCC_WAVE_RAMP_RAMP1  RAMP1 operation 
 *    TCC_WAVE_RAMP_RAMP2A  Alternative RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2  RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2C  Critical RAMP2 operation 
 * TCC_WAVE_CIPEREN  Circular period Enable 
 * TCC_WAVE_CICCEN0  Circular Channel 0 Enable 
 * TCC_WAVE_CICCEN1  Circular Channel 1 Enable 
 * TCC_WAVE_CICCEN2  Circular Channel 2 Enable 
 * TCC_WAVE_CICCEN3  Circular Channel 3 Enable 
 * TCC_WAVE_CICCEN(value)  Circular Channel x Enable 
 * TCC_WAVE_POL0  Channel 0 Polarity 
 * TCC_WAVE_POL1  Channel 1 Polarity 
 * TCC_WAVE_POL2  Channel 2 Polarity 
 * TCC_WAVE_POL3  Channel 3 Polarity 
 * TCC_WAVE_POL4  Channel 4 Polarity 
 * TCC_WAVE_POL5  Channel 5 Polarity 
 * TCC_WAVE_POL(value)  Channel x Polarity 
 * TCC_WAVE_SWAP0  Swap DTI Output Pair 0 
 * TCC_WAVE_SWAP1  Swap DTI Output Pair 1 
 * TCC_WAVE_SWAP2  Swap DTI Output Pair 2 
 * TCC_WAVE_SWAP3  Swap DTI Output Pair 3 
 * TCC_WAVE_SWAP(value)  Swap DTI Output Pair x 
 */
static inline void tcc_clear_WAVE(TCC_t *pTCC, uint32_t mask)
{
	pTCC->WAVE.reg &= ~mask;
}

/**
 * @brief tcc read WAVE register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_WAVE_WAVEGEN(value)  Waveform Generation 
 *    TCC_WAVE_WAVEGEN_NFRQ  Normal frequency 
 *    TCC_WAVE_WAVEGEN_MFRQ  Match frequency 
 *    TCC_WAVE_WAVEGEN_NPWM  Normal PWM 
 *    TCC_WAVE_WAVEGEN_DSCRITICAL  Dual-slope critical 
 *    TCC_WAVE_WAVEGEN_DSBOTTOM  Dual-slope with interrupt/event condition when COUNT reaches ZERO 
 *    TCC_WAVE_WAVEGEN_DSBOTH  Dual-slope with interrupt/event condition when COUNT reaches ZERO or TOP 
 *    TCC_WAVE_WAVEGEN_DSTOP  Dual-slope with interrupt/event condition when COUNT reaches TOP 
 * TCC_WAVE_RAMP(value)  Ramp Mode 
 *    TCC_WAVE_RAMP_RAMP1  RAMP1 operation 
 *    TCC_WAVE_RAMP_RAMP2A  Alternative RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2  RAMP2 operation 
 *    TCC_WAVE_RAMP_RAMP2C  Critical RAMP2 operation 
 * TCC_WAVE_CIPEREN  Circular period Enable 
 * TCC_WAVE_CICCEN0  Circular Channel 0 Enable 
 * TCC_WAVE_CICCEN1  Circular Channel 1 Enable 
 * TCC_WAVE_CICCEN2  Circular Channel 2 Enable 
 * TCC_WAVE_CICCEN3  Circular Channel 3 Enable 
 * TCC_WAVE_CICCEN(value)  Circular Channel x Enable 
 * TCC_WAVE_POL0  Channel 0 Polarity 
 * TCC_WAVE_POL1  Channel 1 Polarity 
 * TCC_WAVE_POL2  Channel 2 Polarity 
 * TCC_WAVE_POL3  Channel 3 Polarity 
 * TCC_WAVE_POL4  Channel 4 Polarity 
 * TCC_WAVE_POL5  Channel 5 Polarity 
 * TCC_WAVE_POL(value)  Channel x Polarity 
 * TCC_WAVE_SWAP0  Swap DTI Output Pair 0 
 * TCC_WAVE_SWAP1  Swap DTI Output Pair 1 
 * TCC_WAVE_SWAP2  Swap DTI Output Pair 2 
 * TCC_WAVE_SWAP3  Swap DTI Output Pair 3 
 * TCC_WAVE_SWAP(value)  Swap DTI Output Pair x 
 */
static inline uint32_t tcc_read_WAVE(TCC_t *pTCC)
{
	return pTCC->WAVE.reg;
}

/**
 * @brief tcc set PATTBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint16_t mask
 * TCC_PATTBUF_PGEB0  Pattern Generator 0 Output Enable Buffer 
 * TCC_PATTBUF_PGEB1  Pattern Generator 1 Output Enable Buffer 
 * TCC_PATTBUF_PGEB2  Pattern Generator 2 Output Enable Buffer 
 * TCC_PATTBUF_PGEB3  Pattern Generator 3 Output Enable Buffer 
 * TCC_PATTBUF_PGEB4  Pattern Generator 4 Output Enable Buffer 
 * TCC_PATTBUF_PGEB5  Pattern Generator 5 Output Enable Buffer 
 * TCC_PATTBUF_PGEB6  Pattern Generator 6 Output Enable Buffer 
 * TCC_PATTBUF_PGEB7  Pattern Generator 7 Output Enable Buffer 
 * TCC_PATTBUF_PGEB(value)  Pattern Generator x Output Enable Buffer 
 * TCC_PATTBUF_PGVB0  Pattern Generator 0 Output Enable 
 * TCC_PATTBUF_PGVB1  Pattern Generator 1 Output Enable 
 * TCC_PATTBUF_PGVB2  Pattern Generator 2 Output Enable 
 * TCC_PATTBUF_PGVB3  Pattern Generator 3 Output Enable 
 * TCC_PATTBUF_PGVB4  Pattern Generator 4 Output Enable 
 * TCC_PATTBUF_PGVB5  Pattern Generator 5 Output Enable 
 * TCC_PATTBUF_PGVB6  Pattern Generator 6 Output Enable 
 * TCC_PATTBUF_PGVB7  Pattern Generator 7 Output Enable 
 * TCC_PATTBUF_PGVB(value)  Pattern Generator x Output Enable 
 */
static inline void tcc_set_PATTBUF(TCC_t *pTCC, uint16_t mask)
{
	pTCC->PATTBUF.reg |= mask;
}

/**
 * @brief tcc get PATTBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint16_t mask
 * @return uint16_t
 * TCC_PATTBUF_PGEB0  Pattern Generator 0 Output Enable Buffer 
 * TCC_PATTBUF_PGEB1  Pattern Generator 1 Output Enable Buffer 
 * TCC_PATTBUF_PGEB2  Pattern Generator 2 Output Enable Buffer 
 * TCC_PATTBUF_PGEB3  Pattern Generator 3 Output Enable Buffer 
 * TCC_PATTBUF_PGEB4  Pattern Generator 4 Output Enable Buffer 
 * TCC_PATTBUF_PGEB5  Pattern Generator 5 Output Enable Buffer 
 * TCC_PATTBUF_PGEB6  Pattern Generator 6 Output Enable Buffer 
 * TCC_PATTBUF_PGEB7  Pattern Generator 7 Output Enable Buffer 
 * TCC_PATTBUF_PGEB(value)  Pattern Generator x Output Enable Buffer 
 * TCC_PATTBUF_PGVB0  Pattern Generator 0 Output Enable 
 * TCC_PATTBUF_PGVB1  Pattern Generator 1 Output Enable 
 * TCC_PATTBUF_PGVB2  Pattern Generator 2 Output Enable 
 * TCC_PATTBUF_PGVB3  Pattern Generator 3 Output Enable 
 * TCC_PATTBUF_PGVB4  Pattern Generator 4 Output Enable 
 * TCC_PATTBUF_PGVB5  Pattern Generator 5 Output Enable 
 * TCC_PATTBUF_PGVB6  Pattern Generator 6 Output Enable 
 * TCC_PATTBUF_PGVB7  Pattern Generator 7 Output Enable 
 * TCC_PATTBUF_PGVB(value)  Pattern Generator x Output Enable 
 */
static inline uint16_t tcc_get_PATTBUF(TCC_t *pTCC, uint16_t mask)
{
    return pTCC->PATTBUF.reg & mask;
}

/**
 * @brief tcc write PATTBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint16_t data
 * TCC_PATTBUF_PGEB0  Pattern Generator 0 Output Enable Buffer 
 * TCC_PATTBUF_PGEB1  Pattern Generator 1 Output Enable Buffer 
 * TCC_PATTBUF_PGEB2  Pattern Generator 2 Output Enable Buffer 
 * TCC_PATTBUF_PGEB3  Pattern Generator 3 Output Enable Buffer 
 * TCC_PATTBUF_PGEB4  Pattern Generator 4 Output Enable Buffer 
 * TCC_PATTBUF_PGEB5  Pattern Generator 5 Output Enable Buffer 
 * TCC_PATTBUF_PGEB6  Pattern Generator 6 Output Enable Buffer 
 * TCC_PATTBUF_PGEB7  Pattern Generator 7 Output Enable Buffer 
 * TCC_PATTBUF_PGEB(value)  Pattern Generator x Output Enable Buffer 
 * TCC_PATTBUF_PGVB0  Pattern Generator 0 Output Enable 
 * TCC_PATTBUF_PGVB1  Pattern Generator 1 Output Enable 
 * TCC_PATTBUF_PGVB2  Pattern Generator 2 Output Enable 
 * TCC_PATTBUF_PGVB3  Pattern Generator 3 Output Enable 
 * TCC_PATTBUF_PGVB4  Pattern Generator 4 Output Enable 
 * TCC_PATTBUF_PGVB5  Pattern Generator 5 Output Enable 
 * TCC_PATTBUF_PGVB6  Pattern Generator 6 Output Enable 
 * TCC_PATTBUF_PGVB7  Pattern Generator 7 Output Enable 
 * TCC_PATTBUF_PGVB(value)  Pattern Generator x Output Enable 
 */
static inline void tcc_write_PATTBUF(TCC_t *pTCC, uint16_t data)
{
	pTCC->PATTBUF.reg = data;
}

/**
 * @brief tcc clear PATTBUF register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint16_t mask
 * TCC_PATTBUF_PGEB0  Pattern Generator 0 Output Enable Buffer 
 * TCC_PATTBUF_PGEB1  Pattern Generator 1 Output Enable Buffer 
 * TCC_PATTBUF_PGEB2  Pattern Generator 2 Output Enable Buffer 
 * TCC_PATTBUF_PGEB3  Pattern Generator 3 Output Enable Buffer 
 * TCC_PATTBUF_PGEB4  Pattern Generator 4 Output Enable Buffer 
 * TCC_PATTBUF_PGEB5  Pattern Generator 5 Output Enable Buffer 
 * TCC_PATTBUF_PGEB6  Pattern Generator 6 Output Enable Buffer 
 * TCC_PATTBUF_PGEB7  Pattern Generator 7 Output Enable Buffer 
 * TCC_PATTBUF_PGEB(value)  Pattern Generator x Output Enable Buffer 
 * TCC_PATTBUF_PGVB0  Pattern Generator 0 Output Enable 
 * TCC_PATTBUF_PGVB1  Pattern Generator 1 Output Enable 
 * TCC_PATTBUF_PGVB2  Pattern Generator 2 Output Enable 
 * TCC_PATTBUF_PGVB3  Pattern Generator 3 Output Enable 
 * TCC_PATTBUF_PGVB4  Pattern Generator 4 Output Enable 
 * TCC_PATTBUF_PGVB5  Pattern Generator 5 Output Enable 
 * TCC_PATTBUF_PGVB6  Pattern Generator 6 Output Enable 
 * TCC_PATTBUF_PGVB7  Pattern Generator 7 Output Enable 
 * TCC_PATTBUF_PGVB(value)  Pattern Generator x Output Enable 
 */
static inline void tcc_clear_PATTBUF(TCC_t *pTCC, uint16_t mask)
{
	pTCC->PATTBUF.reg &= ~mask;
}

/**
 * @brief tcc read PATTBUF register
 *
 * @param[in] TCC_t *pTCC
 * @return uint16_t
 * TCC_PATTBUF_PGEB0  Pattern Generator 0 Output Enable Buffer 
 * TCC_PATTBUF_PGEB1  Pattern Generator 1 Output Enable Buffer 
 * TCC_PATTBUF_PGEB2  Pattern Generator 2 Output Enable Buffer 
 * TCC_PATTBUF_PGEB3  Pattern Generator 3 Output Enable Buffer 
 * TCC_PATTBUF_PGEB4  Pattern Generator 4 Output Enable Buffer 
 * TCC_PATTBUF_PGEB5  Pattern Generator 5 Output Enable Buffer 
 * TCC_PATTBUF_PGEB6  Pattern Generator 6 Output Enable Buffer 
 * TCC_PATTBUF_PGEB7  Pattern Generator 7 Output Enable Buffer 
 * TCC_PATTBUF_PGEB(value)  Pattern Generator x Output Enable Buffer 
 * TCC_PATTBUF_PGVB0  Pattern Generator 0 Output Enable 
 * TCC_PATTBUF_PGVB1  Pattern Generator 1 Output Enable 
 * TCC_PATTBUF_PGVB2  Pattern Generator 2 Output Enable 
 * TCC_PATTBUF_PGVB3  Pattern Generator 3 Output Enable 
 * TCC_PATTBUF_PGVB4  Pattern Generator 4 Output Enable 
 * TCC_PATTBUF_PGVB5  Pattern Generator 5 Output Enable 
 * TCC_PATTBUF_PGVB6  Pattern Generator 6 Output Enable 
 * TCC_PATTBUF_PGVB7  Pattern Generator 7 Output Enable 
 * TCC_PATTBUF_PGVB(value)  Pattern Generator x Output Enable 
 */
static inline uint16_t tcc_read_PATTBUF(TCC_t *pTCC)
{
	return pTCC->PATTBUF.reg;
}

/**
 * @brief tcc get SYNCBUSY register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_SYNCBUSY_SWRST  Swrst Busy 
 * TCC_SYNCBUSY_ENABLE  Enable Busy 
 * TCC_SYNCBUSY_CTRLB  Ctrlb Busy 
 * TCC_SYNCBUSY_STATUS  Status Busy 
 * TCC_SYNCBUSY_COUNT  Count Busy 
 * TCC_SYNCBUSY_PATT  Pattern Busy 
 * TCC_SYNCBUSY_WAVE  Wave Busy 
 * TCC_SYNCBUSY_PER  Period Busy 
 * TCC_SYNCBUSY_CC0  Compare Channel 0 Busy 
 * TCC_SYNCBUSY_CC1  Compare Channel 1 Busy 
 * TCC_SYNCBUSY_CC2  Compare Channel 2 Busy 
 * TCC_SYNCBUSY_CC3  Compare Channel 3 Busy 
 * TCC_SYNCBUSY_CC4  Compare Channel 4 Busy 
 * TCC_SYNCBUSY_CC5  Compare Channel 5 Busy 
 * TCC_SYNCBUSY_CC(value)  Compare Channel x Busy 
 */
static inline uint32_t tcc_get_SYNCBUSY(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->SYNCBUSY.reg & mask;
}

/**
 * @brief tcc read SYNCBUSY register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_SYNCBUSY_SWRST  Swrst Busy 
 * TCC_SYNCBUSY_ENABLE  Enable Busy 
 * TCC_SYNCBUSY_CTRLB  Ctrlb Busy 
 * TCC_SYNCBUSY_STATUS  Status Busy 
 * TCC_SYNCBUSY_COUNT  Count Busy 
 * TCC_SYNCBUSY_PATT  Pattern Busy 
 * TCC_SYNCBUSY_WAVE  Wave Busy 
 * TCC_SYNCBUSY_PER  Period Busy 
 * TCC_SYNCBUSY_CC0  Compare Channel 0 Busy 
 * TCC_SYNCBUSY_CC1  Compare Channel 1 Busy 
 * TCC_SYNCBUSY_CC2  Compare Channel 2 Busy 
 * TCC_SYNCBUSY_CC3  Compare Channel 3 Busy 
 * TCC_SYNCBUSY_CC4  Compare Channel 4 Busy 
 * TCC_SYNCBUSY_CC5  Compare Channel 5 Busy 
 * TCC_SYNCBUSY_CC(value)  Compare Channel x Busy 
 */
static inline uint32_t tcc_read_SYNCBUSY(TCC_t *pTCC)
{
	return pTCC->SYNCBUSY.reg;
}

/**
 * @brief tcc get STATUS register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * @return uint32_t
 * TCC_STATUS_STOP  Stop 
 * TCC_STATUS_IDX  Ramp 
 * TCC_STATUS_UFS  Non-recoverable Update Fault State 
 * TCC_STATUS_DFS  Non-Recoverable Debug Fault State 
 * TCC_STATUS_SLAVE  Slave 
 * TCC_STATUS_PATTBUFV  Pattern Buffer Valid 
 * TCC_STATUS_PERBUFV  Period Buffer Valid 
 * TCC_STATUS_FAULTAIN  Recoverable Fault A Input 
 * TCC_STATUS_FAULTBIN  Recoverable Fault B Input 
 * TCC_STATUS_FAULT0IN  Non-Recoverable Fault0 Input 
 * TCC_STATUS_FAULT1IN  Non-Recoverable Fault1 Input 
 * TCC_STATUS_FAULTA  Recoverable Fault A State 
 * TCC_STATUS_FAULTB  Recoverable Fault B State 
 * TCC_STATUS_FAULT0  Non-Recoverable Fault 0 State 
 * TCC_STATUS_FAULT1  Non-Recoverable Fault 1 State 
 * TCC_STATUS_CCBUFV0  Compare Channel 0 Buffer Valid 
 * TCC_STATUS_CCBUFV1  Compare Channel 1 Buffer Valid 
 * TCC_STATUS_CCBUFV2  Compare Channel 2 Buffer Valid 
 * TCC_STATUS_CCBUFV3  Compare Channel 3 Buffer Valid 
 * TCC_STATUS_CCBUFV4  Compare Channel 4 Buffer Valid 
 * TCC_STATUS_CCBUFV5  Compare Channel 5 Buffer Valid 
 * TCC_STATUS_CCBUFV(value)  Compare Channel x Buffer Valid 
 * TCC_STATUS_CMP0  Compare Channel 0 Value 
 * TCC_STATUS_CMP1  Compare Channel 1 Value 
 * TCC_STATUS_CMP2  Compare Channel 2 Value 
 * TCC_STATUS_CMP3  Compare Channel 3 Value 
 * TCC_STATUS_CMP4  Compare Channel 4 Value 
 * TCC_STATUS_CMP5  Compare Channel 5 Value 
 * TCC_STATUS_CMP(value)  Compare Channel x Value 
 */
static inline uint32_t tcc_get_STATUS(TCC_t *pTCC, uint32_t mask)
{
    return pTCC->STATUS.reg & mask;
}

/**
 * @brief tcc clear STATUS register
 *
 * @param[in] TCC_t *pTCC
 * @param[in] uint32_t mask
 * TCC_STATUS_STOP  Stop 
 * TCC_STATUS_IDX  Ramp 
 * TCC_STATUS_UFS  Non-recoverable Update Fault State 
 * TCC_STATUS_DFS  Non-Recoverable Debug Fault State 
 * TCC_STATUS_SLAVE  Slave 
 * TCC_STATUS_PATTBUFV  Pattern Buffer Valid 
 * TCC_STATUS_PERBUFV  Period Buffer Valid 
 * TCC_STATUS_FAULTAIN  Recoverable Fault A Input 
 * TCC_STATUS_FAULTBIN  Recoverable Fault B Input 
 * TCC_STATUS_FAULT0IN  Non-Recoverable Fault0 Input 
 * TCC_STATUS_FAULT1IN  Non-Recoverable Fault1 Input 
 * TCC_STATUS_FAULTA  Recoverable Fault A State 
 * TCC_STATUS_FAULTB  Recoverable Fault B State 
 * TCC_STATUS_FAULT0  Non-Recoverable Fault 0 State 
 * TCC_STATUS_FAULT1  Non-Recoverable Fault 1 State 
 * TCC_STATUS_CCBUFV0  Compare Channel 0 Buffer Valid 
 * TCC_STATUS_CCBUFV1  Compare Channel 1 Buffer Valid 
 * TCC_STATUS_CCBUFV2  Compare Channel 2 Buffer Valid 
 * TCC_STATUS_CCBUFV3  Compare Channel 3 Buffer Valid 
 * TCC_STATUS_CCBUFV4  Compare Channel 4 Buffer Valid 
 * TCC_STATUS_CCBUFV5  Compare Channel 5 Buffer Valid 
 * TCC_STATUS_CCBUFV(value)  Compare Channel x Buffer Valid 
 * TCC_STATUS_CMP0  Compare Channel 0 Value 
 * TCC_STATUS_CMP1  Compare Channel 1 Value 
 * TCC_STATUS_CMP2  Compare Channel 2 Value 
 * TCC_STATUS_CMP3  Compare Channel 3 Value 
 * TCC_STATUS_CMP4  Compare Channel 4 Value 
 * TCC_STATUS_CMP5  Compare Channel 5 Value 
 * TCC_STATUS_CMP(value)  Compare Channel x Value 
 */
static inline void tcc_clear_STATUS(TCC_t *pTCC, uint32_t mask)
{
	pTCC->STATUS.reg = mask;
}

/**
 * @brief tcc read STATUS register
 *
 * @param[in] TCC_t *pTCC
 * @return uint32_t
 * TCC_STATUS_STOP  Stop 
 * TCC_STATUS_IDX  Ramp 
 * TCC_STATUS_UFS  Non-recoverable Update Fault State 
 * TCC_STATUS_DFS  Non-Recoverable Debug Fault State 
 * TCC_STATUS_SLAVE  Slave 
 * TCC_STATUS_PATTBUFV  Pattern Buffer Valid 
 * TCC_STATUS_PERBUFV  Period Buffer Valid 
 * TCC_STATUS_FAULTAIN  Recoverable Fault A Input 
 * TCC_STATUS_FAULTBIN  Recoverable Fault B Input 
 * TCC_STATUS_FAULT0IN  Non-Recoverable Fault0 Input 
 * TCC_STATUS_FAULT1IN  Non-Recoverable Fault1 Input 
 * TCC_STATUS_FAULTA  Recoverable Fault A State 
 * TCC_STATUS_FAULTB  Recoverable Fault B State 
 * TCC_STATUS_FAULT0  Non-Recoverable Fault 0 State 
 * TCC_STATUS_FAULT1  Non-Recoverable Fault 1 State 
 * TCC_STATUS_CCBUFV0  Compare Channel 0 Buffer Valid 
 * TCC_STATUS_CCBUFV1  Compare Channel 1 Buffer Valid 
 * TCC_STATUS_CCBUFV2  Compare Channel 2 Buffer Valid 
 * TCC_STATUS_CCBUFV3  Compare Channel 3 Buffer Valid 
 * TCC_STATUS_CCBUFV4  Compare Channel 4 Buffer Valid 
 * TCC_STATUS_CCBUFV5  Compare Channel 5 Buffer Valid 
 * TCC_STATUS_CCBUFV(value)  Compare Channel x Buffer Valid 
 * TCC_STATUS_CMP0  Compare Channel 0 Value 
 * TCC_STATUS_CMP1  Compare Channel 1 Value 
 * TCC_STATUS_CMP2  Compare Channel 2 Value 
 * TCC_STATUS_CMP3  Compare Channel 3 Value 
 * TCC_STATUS_CMP4  Compare Channel 4 Value 
 * TCC_STATUS_CMP5  Compare Channel 5 Value 
 * TCC_STATUS_CMP(value)  Compare Channel x Value 
 */
static inline uint32_t tcc_read_STATUS(TCC_t *pTCC)
{
	return pTCC->STATUS.reg;
}

#endif /* _TCC_H */
