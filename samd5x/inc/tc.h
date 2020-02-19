/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM TC
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

#ifndef _TC_H_
#define _TC_H_

#include <stdbool.h>
/**
 * @brief set DBGRUN bit in DBGCTRL register
 * pTC device is running during debug mode
 * @param[in] pTC TC_t * pointer to timer counter module TC0, TC1, TC2, TC3, TC4 or TC5
 */
static inline void tc_set_DBGRUN(TC_t *pTC)
{
	pTC->COUNT8.DBGCTRL.reg |= TC_DBGCTRL_DBGRUN;
}

/*
 * @brief get DBGRUN bit from DBGCTRL register
 *
 * @param[in] pTC TC_t *   pointer to timer counter module TC0, TC1, TC2, TC3, TC4 or TC5
 * @param[in] mask uint8_t
 * @return uint8_t
 */
static inline uint8_t tc_get_DBGRUN(TC_t *pTC)
{
	return (pTC->COUNT8.DBGCTRL.reg & TC_DBGCTRL_DBGRUN);
}

/*
 * @brief clear DBGRUN bit
 * pTC device is halted during debug mode
 * @param[in] pTC TC_t *   pointer to timer counter module TC0, TC1, TC2, TC3, TC4 or TC5
 */
static inline void tc_clear_DBGRUN(TC_t *pTC)
{
	pTC->COUNT8.DBGCTRL.reg &= ~TC_DBGCTRL_DBGRUN;
}
/*
 * @brief clear enable bit in control A
 *  requires tc_wait_for_sync(TCn, TC_SYNCBUSY_SWRST | TC_SYNCBUSY_ENABLE); 
 * @param[in] pTC TC_t *   pointer to timer counter module TC0, TC1, TC2, TC3, TC4 or TC5
 */
static inline void tc_clear_ENABLE(TC_t *pTC)
{
	pTC->COUNT8.CTRLA.reg &= ~TC_CTRLA_ENABLE;
}
/*
 * @brief Set Enable bit in control A register
 * requires tc_wait_for_sync(TCn, TC_SYNCBUSY_SWRST | TC_SYNCBUSY_ENABLE);
 * @param[in] pTC TC_t *   pointer to timer counter module TC0, TC1, TC2, TC3, TC4 or TC5
 */
static inline void tc_set_ENABLE(TC_t *pTC)
{
	pTC->COUNT8.CTRLA.reg |= TC_CTRLA_ENABLE;
}
/*
 * @brief do software reset on timer
 * requires tc_wait_for_sync(TCn, TC_SYNCBUSY_SWRST);
 * @param[in] pTC TC_t *   pointer to timer counter module TC0, TC1, TC2, TC3, TC4 or TC5
 */
static inline void tc_set_SWRST(TC_t *pTC)
{
	pTC->COUNT8.CTRLA.reg |= TC_CTRLA_SWRST;
}

/**
 * @brief tc wait for sync
 *
 * @param[in] pTC TC_t *
 * @param[in] reg uint32_t 
 **/
static inline void tc_wait_for_sync(TC_t *pTC, uint32_t reg)
{
	while (pTC->COUNT8.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief tc is syncing
 *
 * @param[in] pTC TC_t *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool tc_is_syncing(TC_t *pTC, uint32_t reg)
{
	return pTC->COUNT8.SYNCBUSY.reg & reg;
}

/**
 * @brief tccount16 write COUNT register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint16_t 
 * - TC_COUNT32_COUNT_COUNT(value) Counter Value
 **/
static inline void tccount16_write_COUNT(TC_t *pTC, uint16_t data)
{
	pTC->COUNT16.COUNT.reg = data;
}

/**
 * @brief tccount16 read COUNT register
 *
 * @param[in] pTC TC_t *
 * @return uint16_t
 * - TC_COUNT32_COUNT_COUNT(value) Counter Value
 **/
static inline uint16_t tccount16_read_COUNT(TC_t *pTC)
{
	return pTC->COUNT16.COUNT.reg;
}

/**
 * @brief tccount16 write CC register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @param[in] data uint16_t 
 * - TC_COUNT32_CC_CC(value) Counter/Compare Value
 **/
static inline void tccount16_write_CC(TC_t *pTC, uint8_t index, uint16_t data)
{
	pTC->COUNT16.CC[index].reg = data;
}

/**
 * @brief tccount16 read CC register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @return uint16_t
 * - TC_COUNT32_CC_CC(value) Counter/Compare Value
 **/
static inline uint16_t tccount16_read_CC(TC_t *pTC, uint8_t index)
{
	return pTC->COUNT16.CC[index].reg;
}

/**
 * @brief tccount16 write CCBUF register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @param[in] data uint16_t 
 * - TC_COUNT32_CCBUF_CCBUF(value) Counter/Compare Buffer Value
 **/
static inline void tccount16_write_CCBUF(TC_t *pTC, uint8_t index, uint16_t data)
{
	pTC->COUNT16.CCBUF[index].reg = data;
}

/**
 * @brief tccount16 read CCBUF register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @return uint16_t
 * - TC_COUNT32_CCBUF_CCBUF(value) Counter/Compare Buffer Value
 **/
static inline uint16_t tccount16_read_CCBUF(TC_t *pTC, uint8_t index)
{
	return pTC->COUNT16.CCBUF[index].reg;
}

/**
 * @brief tccount32 write COUNT register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint32_t 
 * - TC_COUNT32_COUNT_COUNT(value) Counter Value
 **/
static inline void tccount32_write_COUNT(TC_t *pTC, uint32_t data)
{
	pTC->COUNT32.COUNT.reg = data;
}

/**
 * @brief tccount32 read COUNT register
 *
 * @param[in] pTC TC_t *
 * @return uint32_t
 * - TC_COUNT32_COUNT_COUNT(value) Counter Value
 **/
static inline uint32_t tccount32_read_COUNT(TC_t *pTC)
{
	return pTC->COUNT32.COUNT.reg;
}

/**
 * @brief tccount32 write CC register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - TC_COUNT32_CC_CC(value) Counter/Compare Value
 **/
static inline void tccount32_write_CC(TC_t *pTC, uint8_t index, uint32_t data)
{
	pTC->COUNT32.CC[index].reg = data;
}

/**
 * @brief tccount32 read CC register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - TC_COUNT32_CC_CC(value) Counter/Compare Value
 **/
static inline uint32_t tccount32_read_CC(TC_t *pTC, uint8_t index)
{
	return pTC->COUNT32.CC[index].reg;
}

/**
 * @brief tccount32 write CCBUF register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - TC_COUNT32_CCBUF_CCBUF(value) Counter/Compare Buffer Value
 **/
static inline void tccount32_write_CCBUF(TC_t *pTC, uint8_t index, uint32_t data)
{
	pTC->COUNT32.CCBUF[index].reg = data;
}

/**
 * @brief tccount32 read CCBUF register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - TC_COUNT32_CCBUF_CCBUF(value) Counter/Compare Buffer Value
 **/
static inline uint32_t tccount32_read_CCBUF(TC_t *pTC, uint8_t index)
{
	return pTC->COUNT32.CCBUF[index].reg;
}

/**
 * @brief tc set CTRLB register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_CTRLBSET_DIR Counter Direction
 * - TC_CTRLBSET_LUPD Lock Update
 * - TC_CTRLBSET_ONESHOT One-Shot on Counter
 * - TC_CTRLBSET_CMD(value) Command
 *  +      TC_CTRLBSET_CMD_NONE No action
 *  +      TC_CTRLBSET_CMD_RETRIGGER Force a start, restart or retrigger
 *  +      TC_CTRLBSET_CMD_STOP Force a stop
 *  +      TC_CTRLBSET_CMD_UPDATE Force update of double-buffered register
 *  +      TC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      TC_CTRLBSET_CMD_DMAOS One-shot DMA trigger
 **/
static inline void tc_set_CTRLB(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.CTRLBSET.reg = mask;
}

/**
 * @brief tc get CTRLB register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - TC_CTRLBSET_DIR Counter Direction
 * - TC_CTRLBSET_LUPD Lock Update
 * - TC_CTRLBSET_ONESHOT One-Shot on Counter
 * - TC_CTRLBSET_CMD(value) Command
 *  +      TC_CTRLBSET_CMD_NONE No action
 *  +      TC_CTRLBSET_CMD_RETRIGGER Force a start, restart or retrigger
 *  +      TC_CTRLBSET_CMD_STOP Force a stop
 *  +      TC_CTRLBSET_CMD_UPDATE Force update of double-buffered register
 *  +      TC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      TC_CTRLBSET_CMD_DMAOS One-shot DMA trigger
 **/
static inline uint8_t tc_get_CTRLB(TC_t *pTC, uint8_t mask)
{
    return pTC->COUNT8.CTRLBSET.reg & mask;
}

/**
 * @brief tc read CTRLB register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_CTRLBSET_DIR Counter Direction
 * - TC_CTRLBSET_LUPD Lock Update
 * - TC_CTRLBSET_ONESHOT One-Shot on Counter
 * - TC_CTRLBSET_CMD(value) Command
 *  +      TC_CTRLBSET_CMD_NONE No action
 *  +      TC_CTRLBSET_CMD_RETRIGGER Force a start, restart or retrigger
 *  +      TC_CTRLBSET_CMD_STOP Force a stop
 *  +      TC_CTRLBSET_CMD_UPDATE Force update of double-buffered register
 *  +      TC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      TC_CTRLBSET_CMD_DMAOS One-shot DMA trigger
 **/
static inline uint8_t tc_read_CTRLB(TC_t *pTC)
{
	return pTC->COUNT8.CTRLBSET.reg;
}

/**
 * @brief tc write CTRLB register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint8_t 
 * - TC_CTRLBSET_DIR Counter Direction
 * - TC_CTRLBSET_LUPD Lock Update
 * - TC_CTRLBSET_ONESHOT One-Shot on Counter
 * - TC_CTRLBSET_CMD(value) Command
 *  +      TC_CTRLBSET_CMD_NONE No action
 *  +      TC_CTRLBSET_CMD_RETRIGGER Force a start, restart or retrigger
 *  +      TC_CTRLBSET_CMD_STOP Force a stop
 *  +      TC_CTRLBSET_CMD_UPDATE Force update of double-buffered register
 *  +      TC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      TC_CTRLBSET_CMD_DMAOS One-shot DMA trigger
 **/
static inline void tc_write_CTRLB(TC_t *pTC, uint8_t data)
{
	pTC->COUNT8.CTRLBSET.reg = data;
	pTC->COUNT8.CTRLBCLR.reg = ~data;
}

/**
 * @brief tc clear CTRLB register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_CTRLBSET_DIR Counter Direction
 * - TC_CTRLBSET_LUPD Lock Update
 * - TC_CTRLBSET_ONESHOT One-Shot on Counter
 * - TC_CTRLBSET_CMD(value) Command
 *  +      TC_CTRLBSET_CMD_NONE No action
 *  +      TC_CTRLBSET_CMD_RETRIGGER Force a start, restart or retrigger
 *  +      TC_CTRLBSET_CMD_STOP Force a stop
 *  +      TC_CTRLBSET_CMD_UPDATE Force update of double-buffered register
 *  +      TC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      TC_CTRLBSET_CMD_DMAOS One-shot DMA trigger
 **/
static inline void tc_clear_CTRLB(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.CTRLBCLR.reg = mask;
}

/**
 * @brief tc set INTEN register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_INTENSET_OVF OVF Interrupt Enable
 * - TC_INTENSET_ERR ERR Interrupt Enable
 * - TC_INTENSET_MC0 MC Interrupt Enable 0
 * - TC_INTENSET_MC1 MC Interrupt Enable 1
 * - TC_INTENSET_MC(value) MC Interrupt Enable x
 **/
static inline void tc_set_INTEN(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.INTENSET.reg = mask;
}

/**
 * @brief tc get INTEN register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - TC_INTENSET_OVF OVF Interrupt Enable
 * - TC_INTENSET_ERR ERR Interrupt Enable
 * - TC_INTENSET_MC0 MC Interrupt Enable 0
 * - TC_INTENSET_MC1 MC Interrupt Enable 1
 * - TC_INTENSET_MC(value) MC Interrupt Enable x
 **/
static inline uint8_t tc_get_INTEN(TC_t *pTC, uint8_t mask)
{
    return pTC->COUNT8.INTENSET.reg & mask;
}

/**
 * @brief tc read INTEN register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_INTENSET_OVF OVF Interrupt Enable
 * - TC_INTENSET_ERR ERR Interrupt Enable
 * - TC_INTENSET_MC0 MC Interrupt Enable 0
 * - TC_INTENSET_MC1 MC Interrupt Enable 1
 * - TC_INTENSET_MC(value) MC Interrupt Enable x
 **/
static inline uint8_t tc_read_INTEN(TC_t *pTC)
{
	return pTC->COUNT8.INTENSET.reg;
}

/**
 * @brief tc write INTEN register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint8_t 
 * - TC_INTENSET_OVF OVF Interrupt Enable
 * - TC_INTENSET_ERR ERR Interrupt Enable
 * - TC_INTENSET_MC0 MC Interrupt Enable 0
 * - TC_INTENSET_MC1 MC Interrupt Enable 1
 * - TC_INTENSET_MC(value) MC Interrupt Enable x
 **/
static inline void tc_write_INTEN(TC_t *pTC, uint8_t data)
{
	pTC->COUNT8.INTENSET.reg = data;
	pTC->COUNT8.INTENCLR.reg = ~data;
}

/**
 * @brief tc clear INTEN register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_INTENSET_OVF OVF Interrupt Enable
 * - TC_INTENSET_ERR ERR Interrupt Enable
 * - TC_INTENSET_MC0 MC Interrupt Enable 0
 * - TC_INTENSET_MC1 MC Interrupt Enable 1
 * - TC_INTENSET_MC(value) MC Interrupt Enable x
 **/
static inline void tc_clear_INTEN(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.INTENCLR.reg = mask;
}

/**
 * @brief tc get INTFLAG register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - TC_INTFLAG_OVF OVF Interrupt Flag
 * - TC_INTFLAG_ERR ERR Interrupt Flag
 * - TC_INTFLAG_MC0 MC Interrupt Flag 0
 * - TC_INTFLAG_MC1 MC Interrupt Flag 1
 * - TC_INTFLAG_MC(value) MC Interrupt Flag x
 **/
static inline uint8_t tc_get_INTFLAG(TC_t *pTC, uint8_t mask)
{
    return pTC->COUNT8.INTFLAG.reg & mask;
}

/**
 * @brief tc read INTFLAG register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_INTFLAG_OVF OVF Interrupt Flag
 * - TC_INTFLAG_ERR ERR Interrupt Flag
 * - TC_INTFLAG_MC0 MC Interrupt Flag 0
 * - TC_INTFLAG_MC1 MC Interrupt Flag 1
 * - TC_INTFLAG_MC(value) MC Interrupt Flag x
 **/
static inline uint8_t tc_read_INTFLAG(TC_t *pTC)
{
	return pTC->COUNT8.INTFLAG.reg;
}

/**
 * @brief tc clear INTFLAG register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_INTFLAG_OVF OVF Interrupt Flag
 * - TC_INTFLAG_ERR ERR Interrupt Flag
 * - TC_INTFLAG_MC0 MC Interrupt Flag 0
 * - TC_INTFLAG_MC1 MC Interrupt Flag 1
 * - TC_INTFLAG_MC(value) MC Interrupt Flag x
 **/
static inline void tc_clear_INTFLAG(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.INTFLAG.reg = mask;
}

/**
 * @brief tc set CTRLA register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint32_t 
 * - TC_CTRLA_SWRST Software Reset
 * - TC_CTRLA_ENABLE Enable
 * - TC_CTRLA_MODE(value) Timer Counter Mode
 *  +      TC_CTRLA_MODE_COUNT16 Counter in 16-bit mode
 *  +      TC_CTRLA_MODE_COUNT8 Counter in 8-bit mode
 *  +      TC_CTRLA_MODE_COUNT32 Counter in 32-bit mode
 * - TC_CTRLA_PRESCSYNC(value) Prescaler and Counter Synchronization
 *  +      TC_CTRLA_PRESCSYNC_GCLK Reload or reset the counter on next generic clock
 *  +      TC_CTRLA_PRESCSYNC_PRESC Reload or reset the counter on next prescaler clock
 *  +      TC_CTRLA_PRESCSYNC_RESYNC Reload or reset the counter on next generic clock and reset the prescaler counter
 * - TC_CTRLA_RUNSTDBY Run during Standby
 * - TC_CTRLA_ONDEMAND Clock On Demand
 * - TC_CTRLA_PRESCALER(value) Prescaler
 *  +      TC_CTRLA_PRESCALER_DIV1 Prescaler: GCLK_TC
 *  +      TC_CTRLA_PRESCALER_DIV2 Prescaler: GCLK_TC/2
 *  +      TC_CTRLA_PRESCALER_DIV4 Prescaler: GCLK_TC/4
 *  +      TC_CTRLA_PRESCALER_DIV8 Prescaler: GCLK_TC/8
 *  +      TC_CTRLA_PRESCALER_DIV16 Prescaler: GCLK_TC/16
 *  +      TC_CTRLA_PRESCALER_DIV64 Prescaler: GCLK_TC/64
 *  +      TC_CTRLA_PRESCALER_DIV256 Prescaler: GCLK_TC/256
 *  +      TC_CTRLA_PRESCALER_DIV1024 Prescaler: GCLK_TC/1024
 * - TC_CTRLA_ALOCK Auto Lock
 * - TC_CTRLA_CAPTEN0 Capture Channel 0 Enable
 * - TC_CTRLA_CAPTEN1 Capture Channel 1 Enable
 * - TC_CTRLA_CAPTEN(value) Capture Channel x Enable
 * - TC_CTRLA_COPEN0 Capture On Pin 0 Enable
 * - TC_CTRLA_COPEN1 Capture On Pin 1 Enable
 * - TC_CTRLA_COPEN(value) Capture On Pin x Enable
 * - TC_CTRLA_CAPTMODE0(value) Capture Mode Channel 0
 *  +      TC_CTRLA_CAPTMODE0_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMAX Maximum capture
 * - TC_CTRLA_CAPTMODE1(value) Capture mode Channel 1
 *  +      TC_CTRLA_CAPTMODE1_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMAX Maximum capture
 **/
static inline void tc_set_CTRLA(TC_t *pTC, uint32_t mask)
{
	pTC->COUNT8.CTRLA.reg |= mask;
}

/**
 * @brief tc get CTRLA register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - TC_CTRLA_SWRST Software Reset
 * - TC_CTRLA_ENABLE Enable
 * - TC_CTRLA_MODE(value) Timer Counter Mode
 *  +      TC_CTRLA_MODE_COUNT16 Counter in 16-bit mode
 *  +      TC_CTRLA_MODE_COUNT8 Counter in 8-bit mode
 *  +      TC_CTRLA_MODE_COUNT32 Counter in 32-bit mode
 * - TC_CTRLA_PRESCSYNC(value) Prescaler and Counter Synchronization
 *  +      TC_CTRLA_PRESCSYNC_GCLK Reload or reset the counter on next generic clock
 *  +      TC_CTRLA_PRESCSYNC_PRESC Reload or reset the counter on next prescaler clock
 *  +      TC_CTRLA_PRESCSYNC_RESYNC Reload or reset the counter on next generic clock and reset the prescaler counter
 * - TC_CTRLA_RUNSTDBY Run during Standby
 * - TC_CTRLA_ONDEMAND Clock On Demand
 * - TC_CTRLA_PRESCALER(value) Prescaler
 *  +      TC_CTRLA_PRESCALER_DIV1 Prescaler: GCLK_TC
 *  +      TC_CTRLA_PRESCALER_DIV2 Prescaler: GCLK_TC/2
 *  +      TC_CTRLA_PRESCALER_DIV4 Prescaler: GCLK_TC/4
 *  +      TC_CTRLA_PRESCALER_DIV8 Prescaler: GCLK_TC/8
 *  +      TC_CTRLA_PRESCALER_DIV16 Prescaler: GCLK_TC/16
 *  +      TC_CTRLA_PRESCALER_DIV64 Prescaler: GCLK_TC/64
 *  +      TC_CTRLA_PRESCALER_DIV256 Prescaler: GCLK_TC/256
 *  +      TC_CTRLA_PRESCALER_DIV1024 Prescaler: GCLK_TC/1024
 * - TC_CTRLA_ALOCK Auto Lock
 * - TC_CTRLA_CAPTEN0 Capture Channel 0 Enable
 * - TC_CTRLA_CAPTEN1 Capture Channel 1 Enable
 * - TC_CTRLA_CAPTEN(value) Capture Channel x Enable
 * - TC_CTRLA_COPEN0 Capture On Pin 0 Enable
 * - TC_CTRLA_COPEN1 Capture On Pin 1 Enable
 * - TC_CTRLA_COPEN(value) Capture On Pin x Enable
 * - TC_CTRLA_CAPTMODE0(value) Capture Mode Channel 0
 *  +      TC_CTRLA_CAPTMODE0_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMAX Maximum capture
 * - TC_CTRLA_CAPTMODE1(value) Capture mode Channel 1
 *  +      TC_CTRLA_CAPTMODE1_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMAX Maximum capture
 **/
static inline uint32_t tc_get_CTRLA(TC_t *pTC, uint32_t mask)
{
    return pTC->COUNT8.CTRLA.reg & mask;
}

/**
 * @brief tc write CTRLA register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint32_t 
 * - TC_CTRLA_SWRST Software Reset
 * - TC_CTRLA_ENABLE Enable
 * - TC_CTRLA_MODE(value) Timer Counter Mode
 *  +      TC_CTRLA_MODE_COUNT16 Counter in 16-bit mode
 *  +      TC_CTRLA_MODE_COUNT8 Counter in 8-bit mode
 *  +      TC_CTRLA_MODE_COUNT32 Counter in 32-bit mode
 * - TC_CTRLA_PRESCSYNC(value) Prescaler and Counter Synchronization
 *  +      TC_CTRLA_PRESCSYNC_GCLK Reload or reset the counter on next generic clock
 *  +      TC_CTRLA_PRESCSYNC_PRESC Reload or reset the counter on next prescaler clock
 *  +      TC_CTRLA_PRESCSYNC_RESYNC Reload or reset the counter on next generic clock and reset the prescaler counter
 * - TC_CTRLA_RUNSTDBY Run during Standby
 * - TC_CTRLA_ONDEMAND Clock On Demand
 * - TC_CTRLA_PRESCALER(value) Prescaler
 *  +      TC_CTRLA_PRESCALER_DIV1 Prescaler: GCLK_TC
 *  +      TC_CTRLA_PRESCALER_DIV2 Prescaler: GCLK_TC/2
 *  +      TC_CTRLA_PRESCALER_DIV4 Prescaler: GCLK_TC/4
 *  +      TC_CTRLA_PRESCALER_DIV8 Prescaler: GCLK_TC/8
 *  +      TC_CTRLA_PRESCALER_DIV16 Prescaler: GCLK_TC/16
 *  +      TC_CTRLA_PRESCALER_DIV64 Prescaler: GCLK_TC/64
 *  +      TC_CTRLA_PRESCALER_DIV256 Prescaler: GCLK_TC/256
 *  +      TC_CTRLA_PRESCALER_DIV1024 Prescaler: GCLK_TC/1024
 * - TC_CTRLA_ALOCK Auto Lock
 * - TC_CTRLA_CAPTEN0 Capture Channel 0 Enable
 * - TC_CTRLA_CAPTEN1 Capture Channel 1 Enable
 * - TC_CTRLA_CAPTEN(value) Capture Channel x Enable
 * - TC_CTRLA_COPEN0 Capture On Pin 0 Enable
 * - TC_CTRLA_COPEN1 Capture On Pin 1 Enable
 * - TC_CTRLA_COPEN(value) Capture On Pin x Enable
 * - TC_CTRLA_CAPTMODE0(value) Capture Mode Channel 0
 *  +      TC_CTRLA_CAPTMODE0_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMAX Maximum capture
 * - TC_CTRLA_CAPTMODE1(value) Capture mode Channel 1
 *  +      TC_CTRLA_CAPTMODE1_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMAX Maximum capture
 **/
static inline void tc_write_CTRLA(TC_t *pTC, uint32_t data)
{
	pTC->COUNT8.CTRLA.reg = data;
}

/**
 * @brief tc clear CTRLA register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint32_t 
 * - TC_CTRLA_SWRST Software Reset
 * - TC_CTRLA_ENABLE Enable
 * - TC_CTRLA_MODE(value) Timer Counter Mode
 *  +      TC_CTRLA_MODE_COUNT16 Counter in 16-bit mode
 *  +      TC_CTRLA_MODE_COUNT8 Counter in 8-bit mode
 *  +      TC_CTRLA_MODE_COUNT32 Counter in 32-bit mode
 * - TC_CTRLA_PRESCSYNC(value) Prescaler and Counter Synchronization
 *  +      TC_CTRLA_PRESCSYNC_GCLK Reload or reset the counter on next generic clock
 *  +      TC_CTRLA_PRESCSYNC_PRESC Reload or reset the counter on next prescaler clock
 *  +      TC_CTRLA_PRESCSYNC_RESYNC Reload or reset the counter on next generic clock and reset the prescaler counter
 * - TC_CTRLA_RUNSTDBY Run during Standby
 * - TC_CTRLA_ONDEMAND Clock On Demand
 * - TC_CTRLA_PRESCALER(value) Prescaler
 *  +      TC_CTRLA_PRESCALER_DIV1 Prescaler: GCLK_TC
 *  +      TC_CTRLA_PRESCALER_DIV2 Prescaler: GCLK_TC/2
 *  +      TC_CTRLA_PRESCALER_DIV4 Prescaler: GCLK_TC/4
 *  +      TC_CTRLA_PRESCALER_DIV8 Prescaler: GCLK_TC/8
 *  +      TC_CTRLA_PRESCALER_DIV16 Prescaler: GCLK_TC/16
 *  +      TC_CTRLA_PRESCALER_DIV64 Prescaler: GCLK_TC/64
 *  +      TC_CTRLA_PRESCALER_DIV256 Prescaler: GCLK_TC/256
 *  +      TC_CTRLA_PRESCALER_DIV1024 Prescaler: GCLK_TC/1024
 * - TC_CTRLA_ALOCK Auto Lock
 * - TC_CTRLA_CAPTEN0 Capture Channel 0 Enable
 * - TC_CTRLA_CAPTEN1 Capture Channel 1 Enable
 * - TC_CTRLA_CAPTEN(value) Capture Channel x Enable
 * - TC_CTRLA_COPEN0 Capture On Pin 0 Enable
 * - TC_CTRLA_COPEN1 Capture On Pin 1 Enable
 * - TC_CTRLA_COPEN(value) Capture On Pin x Enable
 * - TC_CTRLA_CAPTMODE0(value) Capture Mode Channel 0
 *  +      TC_CTRLA_CAPTMODE0_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMAX Maximum capture
 * - TC_CTRLA_CAPTMODE1(value) Capture mode Channel 1
 *  +      TC_CTRLA_CAPTMODE1_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMAX Maximum capture
 **/
static inline void tc_clear_CTRLA(TC_t *pTC, uint32_t mask)
{
	pTC->COUNT8.CTRLA.reg &= ~mask;
}

/**
 * @brief tc read CTRLA register
 *
 * @param[in] pTC TC_t *
 * @return uint32_t
 * - TC_CTRLA_SWRST Software Reset
 * - TC_CTRLA_ENABLE Enable
 * - TC_CTRLA_MODE(value) Timer Counter Mode
 *  +      TC_CTRLA_MODE_COUNT16 Counter in 16-bit mode
 *  +      TC_CTRLA_MODE_COUNT8 Counter in 8-bit mode
 *  +      TC_CTRLA_MODE_COUNT32 Counter in 32-bit mode
 * - TC_CTRLA_PRESCSYNC(value) Prescaler and Counter Synchronization
 *  +      TC_CTRLA_PRESCSYNC_GCLK Reload or reset the counter on next generic clock
 *  +      TC_CTRLA_PRESCSYNC_PRESC Reload or reset the counter on next prescaler clock
 *  +      TC_CTRLA_PRESCSYNC_RESYNC Reload or reset the counter on next generic clock and reset the prescaler counter
 * - TC_CTRLA_RUNSTDBY Run during Standby
 * - TC_CTRLA_ONDEMAND Clock On Demand
 * - TC_CTRLA_PRESCALER(value) Prescaler
 *  +      TC_CTRLA_PRESCALER_DIV1 Prescaler: GCLK_TC
 *  +      TC_CTRLA_PRESCALER_DIV2 Prescaler: GCLK_TC/2
 *  +      TC_CTRLA_PRESCALER_DIV4 Prescaler: GCLK_TC/4
 *  +      TC_CTRLA_PRESCALER_DIV8 Prescaler: GCLK_TC/8
 *  +      TC_CTRLA_PRESCALER_DIV16 Prescaler: GCLK_TC/16
 *  +      TC_CTRLA_PRESCALER_DIV64 Prescaler: GCLK_TC/64
 *  +      TC_CTRLA_PRESCALER_DIV256 Prescaler: GCLK_TC/256
 *  +      TC_CTRLA_PRESCALER_DIV1024 Prescaler: GCLK_TC/1024
 * - TC_CTRLA_ALOCK Auto Lock
 * - TC_CTRLA_CAPTEN0 Capture Channel 0 Enable
 * - TC_CTRLA_CAPTEN1 Capture Channel 1 Enable
 * - TC_CTRLA_CAPTEN(value) Capture Channel x Enable
 * - TC_CTRLA_COPEN0 Capture On Pin 0 Enable
 * - TC_CTRLA_COPEN1 Capture On Pin 1 Enable
 * - TC_CTRLA_COPEN(value) Capture On Pin x Enable
 * - TC_CTRLA_CAPTMODE0(value) Capture Mode Channel 0
 *  +      TC_CTRLA_CAPTMODE0_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE0_CAPTMAX Maximum capture
 * - TC_CTRLA_CAPTMODE1(value) Capture mode Channel 1
 *  +      TC_CTRLA_CAPTMODE1_DEFAULT Default capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMIN Minimum capture
 *  +      TC_CTRLA_CAPTMODE1_CAPTMAX Maximum capture
 **/
static inline uint32_t tc_read_CTRLA(TC_t *pTC)
{
	return pTC->COUNT8.CTRLA.reg;
}

/**
 * @brief tc set EVCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint16_t 
 * - TC_EVCTRL_EVACT(value) Event Action
 *  +      TC_EVCTRL_EVACT_OFF Event action disabled
 *  +      TC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger TC on event
 *  +      TC_EVCTRL_EVACT_COUNT Count on event
 *  +      TC_EVCTRL_EVACT_START Start TC on event
 *  +      TC_EVCTRL_EVACT_STAMP Time stamp capture
 *  +      TC_EVCTRL_EVACT_PPW Period catured in CC0, pulse width in CC1
 *  +      TC_EVCTRL_EVACT_PWP Period catured in CC1, pulse width in CC0
 *  +      TC_EVCTRL_EVACT_PW Pulse width capture
 * - TC_EVCTRL_TCINV TC Event Input Polarity
 * - TC_EVCTRL_TCEI TC Event Enable
 * - TC_EVCTRL_OVFEO Event Output Enable
 * - TC_EVCTRL_MCEO0 MC Event Output Enable 0
 * - TC_EVCTRL_MCEO1 MC Event Output Enable 1
 * - TC_EVCTRL_MCEO(value) MC Event Output Enable x
 **/
static inline void tc_set_EVCTRL(TC_t *pTC, uint16_t mask)
{
	pTC->COUNT8.EVCTRL.reg |= mask;
}

/**
 * @brief tc get EVCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - TC_EVCTRL_EVACT(value) Event Action
 *  +      TC_EVCTRL_EVACT_OFF Event action disabled
 *  +      TC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger TC on event
 *  +      TC_EVCTRL_EVACT_COUNT Count on event
 *  +      TC_EVCTRL_EVACT_START Start TC on event
 *  +      TC_EVCTRL_EVACT_STAMP Time stamp capture
 *  +      TC_EVCTRL_EVACT_PPW Period catured in CC0, pulse width in CC1
 *  +      TC_EVCTRL_EVACT_PWP Period catured in CC1, pulse width in CC0
 *  +      TC_EVCTRL_EVACT_PW Pulse width capture
 * - TC_EVCTRL_TCINV TC Event Input Polarity
 * - TC_EVCTRL_TCEI TC Event Enable
 * - TC_EVCTRL_OVFEO Event Output Enable
 * - TC_EVCTRL_MCEO0 MC Event Output Enable 0
 * - TC_EVCTRL_MCEO1 MC Event Output Enable 1
 * - TC_EVCTRL_MCEO(value) MC Event Output Enable x
 **/
static inline uint16_t tc_get_EVCTRL(TC_t *pTC, uint16_t mask)
{
    return pTC->COUNT8.EVCTRL.reg & mask;
}

/**
 * @brief tc write EVCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint16_t 
 * - TC_EVCTRL_EVACT(value) Event Action
 *  +      TC_EVCTRL_EVACT_OFF Event action disabled
 *  +      TC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger TC on event
 *  +      TC_EVCTRL_EVACT_COUNT Count on event
 *  +      TC_EVCTRL_EVACT_START Start TC on event
 *  +      TC_EVCTRL_EVACT_STAMP Time stamp capture
 *  +      TC_EVCTRL_EVACT_PPW Period catured in CC0, pulse width in CC1
 *  +      TC_EVCTRL_EVACT_PWP Period catured in CC1, pulse width in CC0
 *  +      TC_EVCTRL_EVACT_PW Pulse width capture
 * - TC_EVCTRL_TCINV TC Event Input Polarity
 * - TC_EVCTRL_TCEI TC Event Enable
 * - TC_EVCTRL_OVFEO Event Output Enable
 * - TC_EVCTRL_MCEO0 MC Event Output Enable 0
 * - TC_EVCTRL_MCEO1 MC Event Output Enable 1
 * - TC_EVCTRL_MCEO(value) MC Event Output Enable x
 **/
static inline void tc_write_EVCTRL(TC_t *pTC, uint16_t data)
{
	pTC->COUNT8.EVCTRL.reg = data;
}

/**
 * @brief tc clear EVCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint16_t 
 * - TC_EVCTRL_EVACT(value) Event Action
 *  +      TC_EVCTRL_EVACT_OFF Event action disabled
 *  +      TC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger TC on event
 *  +      TC_EVCTRL_EVACT_COUNT Count on event
 *  +      TC_EVCTRL_EVACT_START Start TC on event
 *  +      TC_EVCTRL_EVACT_STAMP Time stamp capture
 *  +      TC_EVCTRL_EVACT_PPW Period catured in CC0, pulse width in CC1
 *  +      TC_EVCTRL_EVACT_PWP Period catured in CC1, pulse width in CC0
 *  +      TC_EVCTRL_EVACT_PW Pulse width capture
 * - TC_EVCTRL_TCINV TC Event Input Polarity
 * - TC_EVCTRL_TCEI TC Event Enable
 * - TC_EVCTRL_OVFEO Event Output Enable
 * - TC_EVCTRL_MCEO0 MC Event Output Enable 0
 * - TC_EVCTRL_MCEO1 MC Event Output Enable 1
 * - TC_EVCTRL_MCEO(value) MC Event Output Enable x
 **/
static inline void tc_clear_EVCTRL(TC_t *pTC, uint16_t mask)
{
	pTC->COUNT8.EVCTRL.reg &= ~mask;
}

/**
 * @brief tc read EVCTRL register
 *
 * @param[in] pTC TC_t *
 * @return uint16_t
 * - TC_EVCTRL_EVACT(value) Event Action
 *  +      TC_EVCTRL_EVACT_OFF Event action disabled
 *  +      TC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger TC on event
 *  +      TC_EVCTRL_EVACT_COUNT Count on event
 *  +      TC_EVCTRL_EVACT_START Start TC on event
 *  +      TC_EVCTRL_EVACT_STAMP Time stamp capture
 *  +      TC_EVCTRL_EVACT_PPW Period catured in CC0, pulse width in CC1
 *  +      TC_EVCTRL_EVACT_PWP Period catured in CC1, pulse width in CC0
 *  +      TC_EVCTRL_EVACT_PW Pulse width capture
 * - TC_EVCTRL_TCINV TC Event Input Polarity
 * - TC_EVCTRL_TCEI TC Event Enable
 * - TC_EVCTRL_OVFEO Event Output Enable
 * - TC_EVCTRL_MCEO0 MC Event Output Enable 0
 * - TC_EVCTRL_MCEO1 MC Event Output Enable 1
 * - TC_EVCTRL_MCEO(value) MC Event Output Enable x
 **/
static inline uint16_t tc_read_EVCTRL(TC_t *pTC)
{
	return pTC->COUNT8.EVCTRL.reg;
}

/**
 * @brief tc set WAVE register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_WAVE_WAVEGEN(value) Waveform Generation Mode
 *  +      TC_WAVE_WAVEGEN_NFRQ Normal frequency
 *  +      TC_WAVE_WAVEGEN_MFRQ Match frequency
 *  +      TC_WAVE_WAVEGEN_NPWM Normal PWM
 *  +      TC_WAVE_WAVEGEN_MPWM Match PWM
 **/
static inline void tc_set_WAVE(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.WAVE.reg |= mask;
}

/**
 * @brief tc get WAVE register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - TC_WAVE_WAVEGEN(value) Waveform Generation Mode
 *  +      TC_WAVE_WAVEGEN_NFRQ Normal frequency
 *  +      TC_WAVE_WAVEGEN_MFRQ Match frequency
 *  +      TC_WAVE_WAVEGEN_NPWM Normal PWM
 *  +      TC_WAVE_WAVEGEN_MPWM Match PWM
 **/
static inline uint8_t tc_get_WAVE(TC_t *pTC, uint8_t mask)
{
    return pTC->COUNT8.WAVE.reg & mask;
}

/**
 * @brief tc write WAVE register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint8_t 
 * - TC_WAVE_WAVEGEN(value) Waveform Generation Mode
 *  +      TC_WAVE_WAVEGEN_NFRQ Normal frequency
 *  +      TC_WAVE_WAVEGEN_MFRQ Match frequency
 *  +      TC_WAVE_WAVEGEN_NPWM Normal PWM
 *  +      TC_WAVE_WAVEGEN_MPWM Match PWM
 **/
static inline void tc_write_WAVE(TC_t *pTC, uint8_t data)
{
	pTC->COUNT8.WAVE.reg = data;
}

/**
 * @brief tc clear WAVE register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_WAVE_WAVEGEN(value) Waveform Generation Mode
 *  +      TC_WAVE_WAVEGEN_NFRQ Normal frequency
 *  +      TC_WAVE_WAVEGEN_MFRQ Match frequency
 *  +      TC_WAVE_WAVEGEN_NPWM Normal PWM
 *  +      TC_WAVE_WAVEGEN_MPWM Match PWM
 **/
static inline void tc_clear_WAVE(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.WAVE.reg &= ~mask;
}

/**
 * @brief tc read WAVE register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_WAVE_WAVEGEN(value) Waveform Generation Mode
 *  +      TC_WAVE_WAVEGEN_NFRQ Normal frequency
 *  +      TC_WAVE_WAVEGEN_MFRQ Match frequency
 *  +      TC_WAVE_WAVEGEN_NPWM Normal PWM
 *  +      TC_WAVE_WAVEGEN_MPWM Match PWM
 **/
static inline uint8_t tc_read_WAVE(TC_t *pTC)
{
	return pTC->COUNT8.WAVE.reg;
}

/**
 * @brief tc set DRVCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_DRVCTRL_INVEN0 Output Waveform Invert Enable 0
 * - TC_DRVCTRL_INVEN1 Output Waveform Invert Enable 1
 * - TC_DRVCTRL_INVEN(value) Output Waveform Invert Enable x
 **/
static inline void tc_set_DRVCTRL(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.DRVCTRL.reg |= mask;
}

/**
 * @brief tc get DRVCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - TC_DRVCTRL_INVEN0 Output Waveform Invert Enable 0
 * - TC_DRVCTRL_INVEN1 Output Waveform Invert Enable 1
 * - TC_DRVCTRL_INVEN(value) Output Waveform Invert Enable x
 **/
static inline uint8_t tc_get_DRVCTRL(TC_t *pTC, uint8_t mask)
{
    return pTC->COUNT8.DRVCTRL.reg & mask;
}

/**
 * @brief tc write DRVCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint8_t 
 * - TC_DRVCTRL_INVEN0 Output Waveform Invert Enable 0
 * - TC_DRVCTRL_INVEN1 Output Waveform Invert Enable 1
 * - TC_DRVCTRL_INVEN(value) Output Waveform Invert Enable x
 **/
static inline void tc_write_DRVCTRL(TC_t *pTC, uint8_t data)
{
	pTC->COUNT8.DRVCTRL.reg = data;
}

/**
 * @brief tc clear DRVCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_DRVCTRL_INVEN0 Output Waveform Invert Enable 0
 * - TC_DRVCTRL_INVEN1 Output Waveform Invert Enable 1
 * - TC_DRVCTRL_INVEN(value) Output Waveform Invert Enable x
 **/
static inline void tc_clear_DRVCTRL(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.DRVCTRL.reg &= ~mask;
}

/**
 * @brief tc read DRVCTRL register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_DRVCTRL_INVEN0 Output Waveform Invert Enable 0
 * - TC_DRVCTRL_INVEN1 Output Waveform Invert Enable 1
 * - TC_DRVCTRL_INVEN(value) Output Waveform Invert Enable x
 **/
static inline uint8_t tc_read_DRVCTRL(TC_t *pTC)
{
	return pTC->COUNT8.DRVCTRL.reg;
}

/**
 * @brief tc set DBGCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void tc_set_DBGCTRL(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.DBGCTRL.reg |= mask;
}

/**
 * @brief tc get DBGCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - TC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline uint8_t tc_get_DBGCTRL(TC_t *pTC, uint8_t mask)
{
    return pTC->COUNT8.DBGCTRL.reg & mask;
}

/**
 * @brief tc write DBGCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint8_t 
 * - TC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void tc_write_DBGCTRL(TC_t *pTC, uint8_t data)
{
	pTC->COUNT8.DBGCTRL.reg = data;
}

/**
 * @brief tc clear DBGCTRL register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void tc_clear_DBGCTRL(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.DBGCTRL.reg &= ~mask;
}

/**
 * @brief tc read DBGCTRL register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline uint8_t tc_read_DBGCTRL(TC_t *pTC)
{
	return pTC->COUNT8.DBGCTRL.reg;
}

/**
 * @brief tccount8 write COUNT register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint8_t 
 * - TC_COUNT32_COUNT_COUNT(value) Counter Value
 **/
static inline void tccount8_write_COUNT(TC_t *pTC, uint8_t data)
{
	pTC->COUNT8.COUNT.reg = data;
}

/**
 * @brief tccount8 read COUNT register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_COUNT32_COUNT_COUNT(value) Counter Value
 **/
static inline uint8_t tccount8_read_COUNT(TC_t *pTC)
{
	return pTC->COUNT8.COUNT.reg;
}

/**
 * @brief tc write PER register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint8_t 
 * - TC_COUNT8_PER_PER(value) Period Value
 **/
static inline void tc_write_PER(TC_t *pTC, uint8_t data)
{
	pTC->COUNT8.PER.reg = data;
}

/**
 * @brief tc read PER register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_COUNT8_PER_PER(value) Period Value
 **/
static inline uint8_t tc_read_PER(TC_t *pTC)
{
	return pTC->COUNT8.PER.reg;
}

/**
 * @brief tccount8 write CC register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @param[in] data uint8_t 
 * - TC_COUNT32_CC_CC(value) Counter/Compare Value
 **/
static inline void tccount8_write_CC(TC_t *pTC, uint8_t index, uint8_t data)
{
	pTC->COUNT8.CC[index].reg = data;
}

/**
 * @brief tccount8 read CC register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @return uint8_t
 * - TC_COUNT32_CC_CC(value) Counter/Compare Value
 **/
static inline uint8_t tccount8_read_CC(TC_t *pTC, uint8_t index)
{
	return pTC->COUNT8.CC[index].reg;
}

/**
 * @brief tc write PERBUF register
 *
 * @param[in] pTC TC_t *
 * @param[in] data uint8_t 
 * - TC_COUNT8_PERBUF_PERBUF(value) Period Buffer Value
 **/
static inline void tc_write_PERBUF(TC_t *pTC, uint8_t data)
{
	pTC->COUNT8.PERBUF.reg = data;
}

/**
 * @brief tc read PERBUF register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_COUNT8_PERBUF_PERBUF(value) Period Buffer Value
 **/
static inline uint8_t tc_read_PERBUF(TC_t *pTC)
{
	return pTC->COUNT8.PERBUF.reg;
}

/**
 * @brief tccount8 write CCBUF register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @param[in] data uint8_t 
 * - TC_COUNT32_CCBUF_CCBUF(value) Counter/Compare Buffer Value
 **/
static inline void tccount8_write_CCBUF(TC_t *pTC, uint8_t index, uint8_t data)
{
	pTC->COUNT8.CCBUF[index].reg = data;
}

/**
 * @brief tccount8 read CCBUF register
 *
 * @param[in] pTC TC_t *
 * @param[in] index uint8_t 
 * @return uint8_t
 * - TC_COUNT32_CCBUF_CCBUF(value) Counter/Compare Buffer Value
 **/
static inline uint8_t tccount8_read_CCBUF(TC_t *pTC, uint8_t index)
{
	return pTC->COUNT8.CCBUF[index].reg;
}

/**
 * @brief tc get SYNCBUSY register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - TC_SYNCBUSY_SWRST swrst
 * - TC_SYNCBUSY_ENABLE enable
 * - TC_SYNCBUSY_CTRLB CTRLB
 * - TC_SYNCBUSY_STATUS STATUS
 * - TC_SYNCBUSY_COUNT Counter
 * - TC_SYNCBUSY_PER Period
 * - TC_SYNCBUSY_CC0 Compare Channel 0
 * - TC_SYNCBUSY_CC1 Compare Channel 1
 * - TC_SYNCBUSY_CC(value) Compare Channel x
 **/
static inline uint32_t tc_get_SYNCBUSY(TC_t *pTC, uint32_t mask)
{
    return pTC->COUNT8.SYNCBUSY.reg & mask;
}

/**
 * @brief tc read SYNCBUSY register
 *
 * @param[in] pTC TC_t *
 * @return uint32_t
 * - TC_SYNCBUSY_SWRST swrst
 * - TC_SYNCBUSY_ENABLE enable
 * - TC_SYNCBUSY_CTRLB CTRLB
 * - TC_SYNCBUSY_STATUS STATUS
 * - TC_SYNCBUSY_COUNT Counter
 * - TC_SYNCBUSY_PER Period
 * - TC_SYNCBUSY_CC0 Compare Channel 0
 * - TC_SYNCBUSY_CC1 Compare Channel 1
 * - TC_SYNCBUSY_CC(value) Compare Channel x
 **/
static inline uint32_t tc_read_SYNCBUSY(TC_t *pTC)
{
	return pTC->COUNT8.SYNCBUSY.reg;
}

/**
 * @brief tc get STATUS register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - TC_STATUS_STOP Stop Status Flag
 * - TC_STATUS_SLAVE Slave Status Flag
 * - TC_STATUS_PERBUFV Synchronization Busy Status
 * - TC_STATUS_CCBUFV0 Compare channel buffer 0 valid
 * - TC_STATUS_CCBUFV1 Compare channel buffer 1 valid
 * - TC_STATUS_CCBUFV(value) Compare channel buffer x valid
 **/
static inline uint8_t tc_get_STATUS(TC_t *pTC, uint8_t mask)
{
    return pTC->COUNT8.STATUS.reg & mask;
}

/**
 * @brief tc clear STATUS register
 *
 * @param[in] pTC TC_t *
 * @param[in] mask uint8_t 
 * - TC_STATUS_STOP Stop Status Flag
 * - TC_STATUS_SLAVE Slave Status Flag
 * - TC_STATUS_PERBUFV Synchronization Busy Status
 * - TC_STATUS_CCBUFV0 Compare channel buffer 0 valid
 * - TC_STATUS_CCBUFV1 Compare channel buffer 1 valid
 * - TC_STATUS_CCBUFV(value) Compare channel buffer x valid
 **/
static inline void tc_clear_STATUS(TC_t *pTC, uint8_t mask)
{
	pTC->COUNT8.STATUS.reg = mask;
}

/**
 * @brief tc read STATUS register
 *
 * @param[in] pTC TC_t *
 * @return uint8_t
 * - TC_STATUS_STOP Stop Status Flag
 * - TC_STATUS_SLAVE Slave Status Flag
 * - TC_STATUS_PERBUFV Synchronization Busy Status
 * - TC_STATUS_CCBUFV0 Compare channel buffer 0 valid
 * - TC_STATUS_CCBUFV1 Compare channel buffer 1 valid
 * - TC_STATUS_CCBUFV(value) Compare channel buffer x valid
 **/
static inline uint8_t tc_read_STATUS(TC_t *pTC)
{
	return pTC->COUNT8.STATUS.reg;
}
/**
 * @brief TIMER_PORT functions
 * @detail
 * The following prototypes are available if:
 * 1) src/tc.c is included in the compiled c files
 * 2) FEATURE_TIME_DELAY and/or FEATURE_TIME_SCHEDULER are globally defined 
 *    These can be defined in the arm-none-eabi-gcc makefile line as -DFEATURE_TIME_DELAY or -DFEATURE_TIME_SCHEDULER
 * 3) Dedicates two timer counters with the follow config definition for initmaker
 *    Any GCLK can be used and sets the rate. Since the routines require synchronization, slow clocks to the iimer
 *    will affect the total delay. Execution time is not factored into the delay so not suited for very precise timing. 
 * 4) if FEATURE_TIME_SCHEDULER is enabled, then call NVIC_ENABLE_TIMER_PORT() in initialization
 *   [TC0]
 *   name=TIMER_PORT
 *   ref_source=gclk1
 *   mode=32
 *   prescaler=1
 *   wavegen=NFRQ
 *   count = 0
 *   ; note that interrupt is used only for FEATURE_TIME_SCHEDULER
 *   interrupt = 1
 *   priority = 7
 */
 
 /*
  * convert ms to timer count for FEATURE_TIME_DELAY and FEATURE_TIME_SCHEDULE
  */
  
#ifdef FEATURE_TIME_DELAY
/**
 * @brief usDelay
 * @detail this was brought over from delay.c. timeDelay can be called directly although macro 
 * is needed to convert microseconds to count
 * @param[in] uint32_t us microseconds of delay 
 */
void usDelay(uint32_t us);
/**
 * @brief msDelay
 * @detail this was brought over from delay.c. timeDelay can be called directly although macro 
 * is needed to convert ms to count
 * @param[in] uint32_t ms milliseconds of delay 
 */
 void msDelay(uint32_t ms);

/**
 * @brief timeDelay(interval) time delay returns after interval count has elapsed
 * @detail uses TC0 with TC1 slaved configured as a 32 bit timer
 * with 1MHz GCLK, interval is in 1usec, maximum interval is 1Hr 10min or 4294967295 us
 * with 10MHz GCLK, interval is in 0.1usec,  maximum interval is 7min 4.9sec or 429496729.6 us
 * with 100MHz GCLK, interval is in 10nsec,  maximum interval is 42.9s or 42949672960 ns
 * 
 * @param[in] uint32_t interval - period in glck ticks for delay
  */
void timeDelay(uint32_t interval);
/**
 * @brief getTimer - return 32 bit timer incremented at gclk tick
 * @detail uses two TCn counters in 32 bit mode. Note must syncrhonize to timer and 
 * if slow gclk will impact execution time. 
 * for example, a simple busy wait dealy
 * uint32_t cnt = get_timer();
 * while(something busy) {
 * 	   if ((get_timer() - cnt) > timeout) return TIMEOUT_ERROR;
 * @return 32 bit count
 */
uint32_t getTimer(void);

#endif  /* FEATURE_TIME_DELAY */
#ifdef FEATURE_TIME_SCHEDULER
/**
 * @brief timeScheduler_t statically allocated node for a scheduled time
 * @detail callback is called when timeout period has elapsed
 * call createTimeSchedule(timeSchedule_t *schedule, void (*callback)(void)) where schedule is the statically allocated
 * memory for timeSchedule node and callback is the function pointer to be called when timer elapses.
 * then call setSchedule(timeSchedule_t *schedule, uint32_t period) to set the period. 
 */
typedef struct timeScheduler_s {
    void (*callback)(uint32_t mask); // callback gets called when timer elapsed
    uint32_t mask;
    uint32_t match;
    uint32_t retrigger;
    bool active;
    struct timeScheduler_s *next; // linked list
} timeScheduler_t;

/**
 * @brief printSchedule - prints the current list of timers - for debug only
 * @detail if DEBUG is active, this routine can be called. It will print the entire linked list of timers
 * It will attempt to decode mask as a four character multichar to provide textual reference to a timer. 
 */
#ifdef DEBUG
void printSchedule(void);
#endif
/**
 * @brief attachTimeSchedule - attaches the timer schedule structure to the scheduler and intiializes the callback function
 * @detail the timeScheduler_t structures are statically allocated for each virtual timer and will call the "callback"
 * function when timer terminates. attachTimeSchedule is called to add the timer to the scheduler and detachTimeSchedule
 * to remove it.
 * @param[in] timeSchedule_t * pointer to static allocated timer schedule structure
 * @param[in] void (*callback)(void) pointer to function to be called when timeout occurs
 * @return timeScheduler_t * pointer to the timer schedule structure
 */
timeScheduler_t *attachTimeSchedule(timeScheduler_t *node, void (*callback)(uint32_t), uint32_t mask);
/**
 * @brief detachTimeSchedule - detaches the timer schedule structure from the scheduler
 * @detail  detachTimeSchedule removes the virtual timer from the scheduler. It can be reused with 
 * a subsequent attachTimeSchedule. The timer interrupt has to travers all of the time schedule structs 
 * which if lengthy can take time. 
 *
 * @param[in] timeSchedule_t * pointer to static allocated virtual timer structure
 * @param[in] void (*callback)(void) pointer to function to be called when timeout occurs
 * @return timeScheduler_t * pointer to the timer schedule structure
 */
timeScheduler_t *detachTimeSchedule(timeScheduler_t *schedule);

/*
 * genericSetTimer - do not call this directly, us setOneShotTime or setRetriggerTime
 */
void genericSetTimer(timeScheduler_t *schedule, uint32_t period, bool retrigger);

/**
 * @brief setOneShotTime set the elapse time and start the timer for one event
 * @param[in] timeSchedule_t * pointer to static allocated virtual timer structure 
 * @param[in] uint32_t period timer elapse time to callback function
 */
static inline void setOneShotTime(timeScheduler_t *schedule, uint32_t period)
{
    genericSetTimer(schedule, period, false);
}
/**
 * @brief setRetriggerTime set the elapse time and start the timer for repeating events
 * @param[in] timeSchedule_t * pointer to static allocated virtual timer structure 
 * @param[in] uint32_t period timer elapse time to callback function
 */
static inline void setRetriggerTime(timeScheduler_t *schedule, uint32_t period)
{
    genericSetTimer(schedule, period, true);
}
/**
 * @brief clearOneShotTime clears elapse time and stop the timer for single events
 * @detail note this is the same as setOneShotTime with interval value of 0. Setting time
 * to zero disables the virtual timer. If the timer was set up with setRettrigerTime, the clearOneShotTime
 * will stop the the timer but retrigger the timer. This is useful for watchdog like timers which expect
 * a clearOneShotTime periodically. 
 * @param[in] timeSchedule_t * pointer to static allocated virtual timer structure 
 */
static inline void clearOneShotTime(timeScheduler_t *schedule)
{
    genericSetTimer(schedule, 0, false);
}
/**
 * @brief clearRetriggerTime clears elapse time and retrigger value and stops the timer for repeating events
 * @detail note this is the same as setRetriggerTime with interval value of 0. Setting time
 * to zero disables the virtual timer
 * @param[in] timeSchedule_t * pointer to static allocated virtual timer structure 
 */
 static inline void clearRetriggerTime(timeScheduler_t *schedule)
{
    genericSetTimer(schedule, 0, true);
}

#endif /* FEATURE_TIME_SCHEDULER */

#endif /* _TC_H */
