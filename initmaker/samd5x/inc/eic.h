/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM EIC
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

#ifndef _EIC_H_
#define _EIC_H_

#include <stdbool.h>
#define EIC_CONFIG_FILTEN		0x8
#define EIC_CONFIG_SENSE_Msk	0x7
#define EIC_CONFIG_SENSE(value) ((value) & 0x7)
#define EIC_CONFIG_SENSE_NONE   0x0
#define EIC_CONFIG_SENSE_RISE	0x1
#define EIC_CONFIG_SENSE_FALL	0x2
#define EIC_CONFIG_SENSE_BOTH	0x3
#define EIC_CONFIG_SENSE_HIGH	0x4
#define EIC_CONFIG_SENSE_LOW 	0x5

#define EIC0_Pos	0	/* EIC/EXTINT[0] */
#define EIC0	(1 << EIC0_Pos)	/* EIC/EXTINT[0] */
#define EIC1_Pos	1	/* EIC/EXTINT[1] */
#define EIC1	(1 << EIC1_Pos)	/* EIC/EXTINT[1] */
#define EIC2_Pos	2	/* EIC/EXTINT[2] */
#define EIC2	(1 << EIC2_Pos)	/* EIC/EXTINT[2] */
#define EIC3_Pos	3	/* EIC/EXTINT[3] */
#define EIC3	(1 << EIC3_Pos)	/* EIC/EXTINT[3] */
#define EIC4_Pos	4	/* EIC/EXTINT[4] */
#define EIC4	(1 << EIC4_Pos)	/* EIC/EXTINT[4] */
#define EIC5_Pos	5	/* EIC/EXTINT[5] */
#define EIC5	(1 << EIC5_Pos)	/* EIC/EXTINT[5] */
#define EIC6_Pos	6	/* EIC/EXTINT[6] */
#define EIC6	(1 << EIC6_Pos)	/* EIC/EXTINT[6] */
#define EIC7_Pos	7	/* EIC/EXTINT[7] */
#define EIC7	(1 << EIC7_Pos)	/* EIC/EXTINT[7] */
#define EIC8_Pos	8	/* EIC/EXTINT[8] */
#define EIC8	(1 << EIC8_Pos)	/* EIC/EXTINT[8] */
#define EIC9_Pos	9	/* EIC/EXTINT[9] */
#define EIC9	(1 << EIC9_Pos)	/* EIC/EXTINT[9] */
#define EIC10_Pos	10	/* EIC/EXTINT[10] */
#define EIC10	(1 << EIC10_Pos)	/* EIC/EXTINT[10] */
#define EIC11_Pos	11	/* EIC/EXTINT[11] */
#define EIC11	(1 << EIC11_Pos)	/* EIC/EXTINT[11] */
#define EIC12_Pos	12	/* EIC/EXTINT[12] */
#define EIC12	(1 << EIC12_Pos)	/* EIC/EXTINT[12] */
#define EIC13_Pos	13	/* EIC/EXTINT[13] */
#define EIC13	(1 << EIC13_Pos)	/* EIC/EXTINT[13] */
#define EIC14_Pos	14	/* EIC/EXTINT[14] */
#define EIC14	(1 << EIC14_Pos)	/* EIC/EXTINT[14] */
#define EIC15_Pos	15	/* EIC/EXTINT[15] */
#define EIC15	(1 << EIC15_Pos)	/* EIC/EXTINT[15] */

/**
 * @brief do software reset on EIC module
 * Requires synchronization after setting
 * eic_wait_for_sync(EIC_SYNCBUSY_SWRST);
 */
static inline void eic_set_SWRST(void)
{
	EIC->CTRLA.reg |= EIC_CTRLA_SWRST;
}

/**
 * @brief get state of software reset
 * @return bool true if software reset, false if not
 * eic_wait_for_sync(EIC_SYNCBUSY_SWRST);
 */
static inline bool eic_get_SWRST(void)
{
	return (bool) (EIC->CTRLA.reg & EIC_CTRLA_SWRST) >> EIC_CTRLA_SWRST_Pos;
}

/**
 * @brief set ENABLE bit enabling the EIC module
 * this must be synchronized with
 * eic_wait_for_sync(EIC_SYNCBUSY_ENABLE);
 */
static inline void eic_set_ENABLE(void)
{
	EIC->CTRLA.reg |= EIC_CTRLA_ENABLE;
}

/**
 * @brief clear ENABLE bit
 * requires synchronization with
 * eic_wait_for_sync(EIC_SYNCBUSY_ENABLE);
 */
static inline void eic_clear_ENABLE(void)
{
	EIC->CTRLA.reg &= ~EIC_CTRLA_ENABLE;
}

/**
 * @brief get clock select 
 *
 * @return bool true=32KHz clock, false=GCLK
 */
static inline bool eic_get_CKSEL(void)
{
	return (bool) ((EIC->CTRLA.reg & EIC_CTRLA_CKSEL) >> EIC_CTRLA_CKSEL_Pos);
}

/**
 * @brief eic wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void eic_wait_for_sync(uint32_t reg)
{
	while (EIC->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief eic is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool eic_is_syncing(uint32_t reg)
{
	return EIC->SYNCBUSY.reg & reg;
}

/**
 * @brief eic set INTEN register
 *
 * @param[in] mask uint32_t 
 * - EIC_INTENSET_EXTINT(value) External Interrupt Enable
 *
 * Example:
 * @code
 *     eic_set_INTEN(EIC2 | EIC4);
 * @endcode
 **/
static inline void eic_set_INTEN(uint32_t mask)
{
	EIC->INTENSET.reg = mask;
}

/**
 * @brief eic get INTEN register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EIC_INTENSET_EXTINT(value) External Interrupt Enable
 **/
static inline uint32_t eic_get_INTEN(uint32_t mask)
{
    return EIC->INTENSET.reg & mask;
}

/**
 * @brief eic read INTEN register
 *
 * @return uint32_t
 * - EIC_INTENSET_EXTINT(value) External Interrupt Enable
 **/
static inline uint32_t eic_read_INTEN(void)
{
	return EIC->INTENSET.reg;
}

/**
 * @brief eic write INTEN register
 *
 * @param[in] data uint32_t 
 * - EIC_INTENSET_EXTINT(value) External Interrupt Enable
 **/
static inline void eic_write_INTEN(uint32_t data)
{
	EIC->INTENSET.reg = data;
	EIC->INTENCLR.reg = ~data;
}

/**
 * @brief eic clear INTEN register
 *
 * @param[in] mask uint32_t 
 * - EIC_INTENSET_EXTINT(value) External Interrupt Enable
 **/
static inline void eic_clear_INTEN(uint32_t mask)
{
	EIC->INTENCLR.reg = mask;
}

/**
 * @brief eic get NMIFLAG register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - EIC_NMIFLAG_NMI Non-Maskable Interrupt
 **/
static inline uint16_t eic_get_NMIFLAG(uint16_t mask)
{
    return EIC->NMIFLAG.reg & mask;
}

/**
 * @brief eic read NMIFLAG register
 *
 * @return uint16_t
 * - EIC_NMIFLAG_NMI Non-Maskable Interrupt
 **/
static inline uint16_t eic_read_NMIFLAG(void)
{
	return EIC->NMIFLAG.reg;
}

/**
 * @brief eic clear NMIFLAG register
 *
 * @param[in] mask uint16_t 
 * - EIC_NMIFLAG_NMI Non-Maskable Interrupt
 **/
static inline void eic_clear_NMIFLAG(uint16_t mask)
{
	EIC->NMIFLAG.reg = mask;
}

/**
 * @brief eic get INTFLAG register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EIC_INTFLAG_EXTINT(value) External Interrupt
 **/
static inline uint32_t eic_get_INTFLAG(uint32_t mask)
{
    return EIC->INTFLAG.reg & mask;
}

/**
 * @brief eic read INTFLAG register
 *
 * @return uint32_t
 * - EIC_INTFLAG_EXTINT(value) External Interrupt
 **/
static inline uint32_t eic_read_INTFLAG(void)
{
	return EIC->INTFLAG.reg;
}

/**
 * @brief eic clear INTFLAG register
 *
 * @param[in] mask uint32_t 
 * - EIC_INTFLAG_EXTINT(value) External Interrupt
 *
 * Example:
 * @code
 *     eic_clear_INTFLAG(EIC2 | EIC4);
 * @endcode
 **/
static inline void eic_clear_INTFLAG(uint32_t mask)
{
	EIC->INTFLAG.reg = mask;
}

/**
 * @brief eic set CTRLA register
 *
 * @param[in] mask uint8_t 
 * - EIC_CTRLA_SWRST Software Reset
 * - EIC_CTRLA_ENABLE Enable
 * - EIC_CTRLA_CKSEL Clock Selection
 **/
static inline void eic_set_CTRLA(uint8_t mask)
{
	EIC->CTRLA.reg |= mask;
}

/**
 * @brief eic get CTRLA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - EIC_CTRLA_SWRST Software Reset
 * - EIC_CTRLA_ENABLE Enable
 * - EIC_CTRLA_CKSEL Clock Selection
 **/
static inline uint8_t eic_get_CTRLA(uint8_t mask)
{
    return EIC->CTRLA.reg & mask;
}

/**
 * @brief eic write CTRLA register
 *
 * @param[in] data uint8_t 
 * - EIC_CTRLA_SWRST Software Reset
 * - EIC_CTRLA_ENABLE Enable
 * - EIC_CTRLA_CKSEL Clock Selection
 **/
static inline void eic_write_CTRLA(uint8_t data)
{
	EIC->CTRLA.reg = data;
}

/**
 * @brief eic clear CTRLA register
 *
 * @param[in] mask uint8_t 
 * - EIC_CTRLA_SWRST Software Reset
 * - EIC_CTRLA_ENABLE Enable
 * - EIC_CTRLA_CKSEL Clock Selection
 **/
static inline void eic_clear_CTRLA(uint8_t mask)
{
	EIC->CTRLA.reg &= ~mask;
}

/**
 * @brief eic read CTRLA register
 *
 * @return uint8_t
 * - EIC_CTRLA_SWRST Software Reset
 * - EIC_CTRLA_ENABLE Enable
 * - EIC_CTRLA_CKSEL Clock Selection
 **/
static inline uint8_t eic_read_CTRLA(void)
{
	return EIC->CTRLA.reg;
}

/**
 * @brief eic set NMICTRL register
 *
 * @param[in] mask uint8_t 
 * - EIC_NMICTRL_NMISENSE(value) Non-Maskable Interrupt Sense Configuration
 *  +      EIC_NMICTRL_NMISENSE_NONE No detection
 *  +      EIC_NMICTRL_NMISENSE_RISE Rising-edge detection
 *  +      EIC_NMICTRL_NMISENSE_FALL Falling-edge detection
 *  +      EIC_NMICTRL_NMISENSE_BOTH Both-edges detection
 *  +      EIC_NMICTRL_NMISENSE_HIGH High-level detection
 *  +      EIC_NMICTRL_NMISENSE_LOW Low-level detection
 * - EIC_NMICTRL_NMIFILTEN Non-Maskable Interrupt Filter Enable
 * - EIC_NMICTRL_NMIASYNCH Asynchronous Edge Detection Mode
 **/
static inline void eic_set_NMICTRL(uint8_t mask)
{
	EIC->NMICTRL.reg |= mask;
}

/**
 * @brief eic get NMICTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - EIC_NMICTRL_NMISENSE(value) Non-Maskable Interrupt Sense Configuration
 *  +      EIC_NMICTRL_NMISENSE_NONE No detection
 *  +      EIC_NMICTRL_NMISENSE_RISE Rising-edge detection
 *  +      EIC_NMICTRL_NMISENSE_FALL Falling-edge detection
 *  +      EIC_NMICTRL_NMISENSE_BOTH Both-edges detection
 *  +      EIC_NMICTRL_NMISENSE_HIGH High-level detection
 *  +      EIC_NMICTRL_NMISENSE_LOW Low-level detection
 * - EIC_NMICTRL_NMIFILTEN Non-Maskable Interrupt Filter Enable
 * - EIC_NMICTRL_NMIASYNCH Asynchronous Edge Detection Mode
 **/
static inline uint8_t eic_get_NMICTRL(uint8_t mask)
{
    return EIC->NMICTRL.reg & mask;
}

/**
 * @brief eic write NMICTRL register
 *
 * @param[in] data uint8_t 
 * - EIC_NMICTRL_NMISENSE(value) Non-Maskable Interrupt Sense Configuration
 *  +      EIC_NMICTRL_NMISENSE_NONE No detection
 *  +      EIC_NMICTRL_NMISENSE_RISE Rising-edge detection
 *  +      EIC_NMICTRL_NMISENSE_FALL Falling-edge detection
 *  +      EIC_NMICTRL_NMISENSE_BOTH Both-edges detection
 *  +      EIC_NMICTRL_NMISENSE_HIGH High-level detection
 *  +      EIC_NMICTRL_NMISENSE_LOW Low-level detection
 * - EIC_NMICTRL_NMIFILTEN Non-Maskable Interrupt Filter Enable
 * - EIC_NMICTRL_NMIASYNCH Asynchronous Edge Detection Mode
 **/
static inline void eic_write_NMICTRL(uint8_t data)
{
	EIC->NMICTRL.reg = data;
}

/**
 * @brief eic clear NMICTRL register
 *
 * @param[in] mask uint8_t 
 * - EIC_NMICTRL_NMISENSE(value) Non-Maskable Interrupt Sense Configuration
 *  +      EIC_NMICTRL_NMISENSE_NONE No detection
 *  +      EIC_NMICTRL_NMISENSE_RISE Rising-edge detection
 *  +      EIC_NMICTRL_NMISENSE_FALL Falling-edge detection
 *  +      EIC_NMICTRL_NMISENSE_BOTH Both-edges detection
 *  +      EIC_NMICTRL_NMISENSE_HIGH High-level detection
 *  +      EIC_NMICTRL_NMISENSE_LOW Low-level detection
 * - EIC_NMICTRL_NMIFILTEN Non-Maskable Interrupt Filter Enable
 * - EIC_NMICTRL_NMIASYNCH Asynchronous Edge Detection Mode
 **/
static inline void eic_clear_NMICTRL(uint8_t mask)
{
	EIC->NMICTRL.reg &= ~mask;
}

/**
 * @brief eic read NMICTRL register
 *
 * @return uint8_t
 * - EIC_NMICTRL_NMISENSE(value) Non-Maskable Interrupt Sense Configuration
 *  +      EIC_NMICTRL_NMISENSE_NONE No detection
 *  +      EIC_NMICTRL_NMISENSE_RISE Rising-edge detection
 *  +      EIC_NMICTRL_NMISENSE_FALL Falling-edge detection
 *  +      EIC_NMICTRL_NMISENSE_BOTH Both-edges detection
 *  +      EIC_NMICTRL_NMISENSE_HIGH High-level detection
 *  +      EIC_NMICTRL_NMISENSE_LOW Low-level detection
 * - EIC_NMICTRL_NMIFILTEN Non-Maskable Interrupt Filter Enable
 * - EIC_NMICTRL_NMIASYNCH Asynchronous Edge Detection Mode
 **/
static inline uint8_t eic_read_NMICTRL(void)
{
	return EIC->NMICTRL.reg;
}

/**
 * @brief eic set EVCTRL register
 *
 * @param[in] mask uint32_t 
 * - EIC_EVCTRL_EXTINTEO(value) External Interrupt Event Output Enable
 **/
static inline void eic_set_EVCTRL(uint32_t mask)
{
	EIC->EVCTRL.reg |= mask;
}

/**
 * @brief eic get EVCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EIC_EVCTRL_EXTINTEO(value) External Interrupt Event Output Enable
 **/
static inline uint32_t eic_get_EVCTRL(uint32_t mask)
{
    return EIC->EVCTRL.reg & mask;
}

/**
 * @brief eic write EVCTRL register
 *
 * @param[in] data uint32_t 
 * - EIC_EVCTRL_EXTINTEO(value) External Interrupt Event Output Enable
 **/
static inline void eic_write_EVCTRL(uint32_t data)
{
	EIC->EVCTRL.reg = data;
}

/**
 * @brief eic clear EVCTRL register
 *
 * @param[in] mask uint32_t 
 * - EIC_EVCTRL_EXTINTEO(value) External Interrupt Event Output Enable
 **/
static inline void eic_clear_EVCTRL(uint32_t mask)
{
	EIC->EVCTRL.reg &= ~mask;
}

/**
 * @brief eic read EVCTRL register
 *
 * @return uint32_t
 * - EIC_EVCTRL_EXTINTEO(value) External Interrupt Event Output Enable
 **/
static inline uint32_t eic_read_EVCTRL(void)
{
	return EIC->EVCTRL.reg;
}

/**
 * @brief eic set ASYNCH register
 *
 * @param[in] mask uint32_t 
 * - EIC_ASYNCH_ASYNCH(value) Asynchronous Edge Detection Mode
 **/
static inline void eic_set_ASYNCH(uint32_t mask)
{
	EIC->ASYNCH.reg |= mask;
}

/**
 * @brief eic get ASYNCH register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EIC_ASYNCH_ASYNCH(value) Asynchronous Edge Detection Mode
 **/
static inline uint32_t eic_get_ASYNCH(uint32_t mask)
{
    return EIC->ASYNCH.reg & mask;
}

/**
 * @brief eic write ASYNCH register
 *
 * @param[in] data uint32_t 
 * - EIC_ASYNCH_ASYNCH(value) Asynchronous Edge Detection Mode
 **/
static inline void eic_write_ASYNCH(uint32_t data)
{
	EIC->ASYNCH.reg = data;
}

/**
 * @brief eic clear ASYNCH register
 *
 * @param[in] mask uint32_t 
 * - EIC_ASYNCH_ASYNCH(value) Asynchronous Edge Detection Mode
 **/
static inline void eic_clear_ASYNCH(uint32_t mask)
{
	EIC->ASYNCH.reg &= ~mask;
}

/**
 * @brief eic read ASYNCH register
 *
 * @return uint32_t
 * - EIC_ASYNCH_ASYNCH(value) Asynchronous Edge Detection Mode
 **/
static inline uint32_t eic_read_ASYNCH(void)
{
	return EIC->ASYNCH.reg;
}

/**
 * @brief set an individual config entry indexed by EICn
 * Enable Protected
 * @param[in] eicn uint8_t 
 * @param[in] mask config for EICn
 * - EIC_CONFIG_FILTEN 		Filter Enable
 * - EIC_CONFIG_SENSE(value)
 *  +      EIC_CONFIG_SENSE_NONE   No detection      
 *  +      EIC_CONFIG_SENSE_RISE   Rising edge detection 
 *  +      EIC_CONFIG_SENSE_FALL   Falling edge detection
 *  +      EIC_CONFIG_SENSE_BOTH   Both edges detection
 *  +      EIC_CONFIG_SENSE_HIGH   High level detection
 *  +      EIC_CONFIG_SENSE_LOW    Low level detection
 */
static inline void eic_set_CONFIG(uint8_t eicn, uint8_t mask)
{
	uint32_t tmp;
	uint8_t index = eicn >> 3;
	uint8_t pos = (eicn & 7) << 2;
	tmp = EIC->CONFIG[index].reg & ~((uint32_t) (0x0000000F << pos));
	EIC->CONFIG[index].reg = tmp | ((mask & 0x0F) << pos);
}

/**
 * @brief get an individual config entry indexed by EICn
 *
 * @param[in] eicn uint8_t 
 * @param[in] mask uint32_t 
 * - EIC_CONFIG_SENSE(value) Input Sense Configuration
 *  +      EIC_CONFIG_SENSE_NONE No detection
 *  +      EIC_CONFIG_SENSE_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE_HIGH High level detection
 *  +      EIC_CONFIG_SENSE_LOW Low level detection
 * - EIC_CONFIG_FILTEN 		Filter Enable
 */
static inline uint8_t eic_get_CONFIG(uint8_t eicn, uint8_t mask)
{
	uint8_t index = eicn >> 3;
	uint8_t pos = (eicn & 7) << 2;
	return (uint8_t) ((EIC->CONFIG[index].reg >> pos) & mask);
}



/**
 * @brief eic write CONFIG register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - EIC_CONFIG_SENSE0(value) Input Sense Configuration 0
 *  +      EIC_CONFIG_SENSE0_NONE No detection
 *  +      EIC_CONFIG_SENSE0_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE0_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE0_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE0_HIGH High level detection
 *  +      EIC_CONFIG_SENSE0_LOW Low level detection
 * - EIC_CONFIG_FILTEN0 Filter Enable 0
 * - EIC_CONFIG_SENSE1(value) Input Sense Configuration 1
 *  +      EIC_CONFIG_SENSE1_NONE No detection
 *  +      EIC_CONFIG_SENSE1_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE1_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE1_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE1_HIGH High level detection
 *  +      EIC_CONFIG_SENSE1_LOW Low level detection
 * - EIC_CONFIG_FILTEN1 Filter Enable 1
 * - EIC_CONFIG_SENSE2(value) Input Sense Configuration 2
 *  +      EIC_CONFIG_SENSE2_NONE No detection
 *  +      EIC_CONFIG_SENSE2_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE2_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE2_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE2_HIGH High level detection
 *  +      EIC_CONFIG_SENSE2_LOW Low level detection
 * - EIC_CONFIG_FILTEN2 Filter Enable 2
 * - EIC_CONFIG_SENSE3(value) Input Sense Configuration 3
 *  +      EIC_CONFIG_SENSE3_NONE No detection
 *  +      EIC_CONFIG_SENSE3_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE3_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE3_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE3_HIGH High level detection
 *  +      EIC_CONFIG_SENSE3_LOW Low level detection
 * - EIC_CONFIG_FILTEN3 Filter Enable 3
 * - EIC_CONFIG_SENSE4(value) Input Sense Configuration 4
 *  +      EIC_CONFIG_SENSE4_NONE No detection
 *  +      EIC_CONFIG_SENSE4_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE4_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE4_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE4_HIGH High level detection
 *  +      EIC_CONFIG_SENSE4_LOW Low level detection
 * - EIC_CONFIG_FILTEN4 Filter Enable 4
 * - EIC_CONFIG_SENSE5(value) Input Sense Configuration 5
 *  +      EIC_CONFIG_SENSE5_NONE No detection
 *  +      EIC_CONFIG_SENSE5_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE5_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE5_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE5_HIGH High level detection
 *  +      EIC_CONFIG_SENSE5_LOW Low level detection
 * - EIC_CONFIG_FILTEN5 Filter Enable 5
 * - EIC_CONFIG_SENSE6(value) Input Sense Configuration 6
 *  +      EIC_CONFIG_SENSE6_NONE No detection
 *  +      EIC_CONFIG_SENSE6_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE6_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE6_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE6_HIGH High level detection
 *  +      EIC_CONFIG_SENSE6_LOW Low level detection
 * - EIC_CONFIG_FILTEN6 Filter Enable 6
 * - EIC_CONFIG_SENSE7(value) Input Sense Configuration 7
 *  +      EIC_CONFIG_SENSE7_NONE No detection
 *  +      EIC_CONFIG_SENSE7_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE7_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE7_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE7_HIGH High level detection
 *  +      EIC_CONFIG_SENSE7_LOW Low level detection
 * - EIC_CONFIG_FILTEN7 Filter Enable 7
 **/
static inline void eic_write_CONFIG(uint8_t index, uint32_t data)
{
	EIC->CONFIG[index].reg = data;
}

/**
 * @brief eic clear CONFIG register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - EIC_CONFIG_SENSE0(value) Input Sense Configuration 0
 *  +      EIC_CONFIG_SENSE0_NONE No detection
 *  +      EIC_CONFIG_SENSE0_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE0_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE0_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE0_HIGH High level detection
 *  +      EIC_CONFIG_SENSE0_LOW Low level detection
 * - EIC_CONFIG_FILTEN0 Filter Enable 0
 * - EIC_CONFIG_SENSE1(value) Input Sense Configuration 1
 *  +      EIC_CONFIG_SENSE1_NONE No detection
 *  +      EIC_CONFIG_SENSE1_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE1_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE1_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE1_HIGH High level detection
 *  +      EIC_CONFIG_SENSE1_LOW Low level detection
 * - EIC_CONFIG_FILTEN1 Filter Enable 1
 * - EIC_CONFIG_SENSE2(value) Input Sense Configuration 2
 *  +      EIC_CONFIG_SENSE2_NONE No detection
 *  +      EIC_CONFIG_SENSE2_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE2_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE2_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE2_HIGH High level detection
 *  +      EIC_CONFIG_SENSE2_LOW Low level detection
 * - EIC_CONFIG_FILTEN2 Filter Enable 2
 * - EIC_CONFIG_SENSE3(value) Input Sense Configuration 3
 *  +      EIC_CONFIG_SENSE3_NONE No detection
 *  +      EIC_CONFIG_SENSE3_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE3_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE3_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE3_HIGH High level detection
 *  +      EIC_CONFIG_SENSE3_LOW Low level detection
 * - EIC_CONFIG_FILTEN3 Filter Enable 3
 * - EIC_CONFIG_SENSE4(value) Input Sense Configuration 4
 *  +      EIC_CONFIG_SENSE4_NONE No detection
 *  +      EIC_CONFIG_SENSE4_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE4_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE4_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE4_HIGH High level detection
 *  +      EIC_CONFIG_SENSE4_LOW Low level detection
 * - EIC_CONFIG_FILTEN4 Filter Enable 4
 * - EIC_CONFIG_SENSE5(value) Input Sense Configuration 5
 *  +      EIC_CONFIG_SENSE5_NONE No detection
 *  +      EIC_CONFIG_SENSE5_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE5_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE5_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE5_HIGH High level detection
 *  +      EIC_CONFIG_SENSE5_LOW Low level detection
 * - EIC_CONFIG_FILTEN5 Filter Enable 5
 * - EIC_CONFIG_SENSE6(value) Input Sense Configuration 6
 *  +      EIC_CONFIG_SENSE6_NONE No detection
 *  +      EIC_CONFIG_SENSE6_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE6_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE6_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE6_HIGH High level detection
 *  +      EIC_CONFIG_SENSE6_LOW Low level detection
 * - EIC_CONFIG_FILTEN6 Filter Enable 6
 * - EIC_CONFIG_SENSE7(value) Input Sense Configuration 7
 *  +      EIC_CONFIG_SENSE7_NONE No detection
 *  +      EIC_CONFIG_SENSE7_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE7_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE7_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE7_HIGH High level detection
 *  +      EIC_CONFIG_SENSE7_LOW Low level detection
 * - EIC_CONFIG_FILTEN7 Filter Enable 7
 **/
static inline void eic_clear_CONFIG(uint8_t index, uint32_t mask)
{
	EIC->CONFIG[index].reg &= ~mask;
}

/**
 * @brief eic read CONFIG register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - EIC_CONFIG_SENSE0(value) Input Sense Configuration 0
 *  +      EIC_CONFIG_SENSE0_NONE No detection
 *  +      EIC_CONFIG_SENSE0_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE0_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE0_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE0_HIGH High level detection
 *  +      EIC_CONFIG_SENSE0_LOW Low level detection
 * - EIC_CONFIG_FILTEN0 Filter Enable 0
 * - EIC_CONFIG_SENSE1(value) Input Sense Configuration 1
 *  +      EIC_CONFIG_SENSE1_NONE No detection
 *  +      EIC_CONFIG_SENSE1_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE1_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE1_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE1_HIGH High level detection
 *  +      EIC_CONFIG_SENSE1_LOW Low level detection
 * - EIC_CONFIG_FILTEN1 Filter Enable 1
 * - EIC_CONFIG_SENSE2(value) Input Sense Configuration 2
 *  +      EIC_CONFIG_SENSE2_NONE No detection
 *  +      EIC_CONFIG_SENSE2_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE2_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE2_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE2_HIGH High level detection
 *  +      EIC_CONFIG_SENSE2_LOW Low level detection
 * - EIC_CONFIG_FILTEN2 Filter Enable 2
 * - EIC_CONFIG_SENSE3(value) Input Sense Configuration 3
 *  +      EIC_CONFIG_SENSE3_NONE No detection
 *  +      EIC_CONFIG_SENSE3_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE3_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE3_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE3_HIGH High level detection
 *  +      EIC_CONFIG_SENSE3_LOW Low level detection
 * - EIC_CONFIG_FILTEN3 Filter Enable 3
 * - EIC_CONFIG_SENSE4(value) Input Sense Configuration 4
 *  +      EIC_CONFIG_SENSE4_NONE No detection
 *  +      EIC_CONFIG_SENSE4_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE4_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE4_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE4_HIGH High level detection
 *  +      EIC_CONFIG_SENSE4_LOW Low level detection
 * - EIC_CONFIG_FILTEN4 Filter Enable 4
 * - EIC_CONFIG_SENSE5(value) Input Sense Configuration 5
 *  +      EIC_CONFIG_SENSE5_NONE No detection
 *  +      EIC_CONFIG_SENSE5_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE5_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE5_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE5_HIGH High level detection
 *  +      EIC_CONFIG_SENSE5_LOW Low level detection
 * - EIC_CONFIG_FILTEN5 Filter Enable 5
 * - EIC_CONFIG_SENSE6(value) Input Sense Configuration 6
 *  +      EIC_CONFIG_SENSE6_NONE No detection
 *  +      EIC_CONFIG_SENSE6_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE6_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE6_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE6_HIGH High level detection
 *  +      EIC_CONFIG_SENSE6_LOW Low level detection
 * - EIC_CONFIG_FILTEN6 Filter Enable 6
 * - EIC_CONFIG_SENSE7(value) Input Sense Configuration 7
 *  +      EIC_CONFIG_SENSE7_NONE No detection
 *  +      EIC_CONFIG_SENSE7_RISE Rising edge detection
 *  +      EIC_CONFIG_SENSE7_FALL Falling edge detection
 *  +      EIC_CONFIG_SENSE7_BOTH Both edges detection
 *  +      EIC_CONFIG_SENSE7_HIGH High level detection
 *  +      EIC_CONFIG_SENSE7_LOW Low level detection
 * - EIC_CONFIG_FILTEN7 Filter Enable 7
 **/
static inline uint32_t eic_read_CONFIG(uint8_t index)
{
	return EIC->CONFIG[index].reg;
}

/**
 * @brief eic set DEBOUNCEN register
 *
 * @param[in] mask uint32_t 
 * - EIC_DEBOUNCEN_DEBOUNCEN(value) Debouncer Enable
 **/
static inline void eic_set_DEBOUNCEN(uint32_t mask)
{
	EIC->DEBOUNCEN.reg |= mask;
}

/**
 * @brief eic get DEBOUNCEN register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EIC_DEBOUNCEN_DEBOUNCEN(value) Debouncer Enable
 **/
static inline uint32_t eic_get_DEBOUNCEN(uint32_t mask)
{
    return EIC->DEBOUNCEN.reg & mask;
}

/**
 * @brief eic write DEBOUNCEN register
 *
 * @param[in] data uint32_t 
 * - EIC_DEBOUNCEN_DEBOUNCEN(value) Debouncer Enable
 **/
static inline void eic_write_DEBOUNCEN(uint32_t data)
{
	EIC->DEBOUNCEN.reg = data;
}

/**
 * @brief eic clear DEBOUNCEN register
 *
 * @param[in] mask uint32_t 
 * - EIC_DEBOUNCEN_DEBOUNCEN(value) Debouncer Enable
 **/
static inline void eic_clear_DEBOUNCEN(uint32_t mask)
{
	EIC->DEBOUNCEN.reg &= ~mask;
}

/**
 * @brief eic read DEBOUNCEN register
 *
 * @return uint32_t
 * - EIC_DEBOUNCEN_DEBOUNCEN(value) Debouncer Enable
 **/
static inline uint32_t eic_read_DEBOUNCEN(void)
{
	return EIC->DEBOUNCEN.reg;
}

/**
 * @brief eic set DPRESCALER register
 *
 * @param[in] mask uint32_t 
 * - EIC_DPRESCALER_PRESCALER0(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES0 Debouncer number of states
 * - EIC_DPRESCALER_PRESCALER1(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES1 Debouncer number of states
 * - EIC_DPRESCALER_TICKON Pin Sampler frequency selection
 **/
static inline void eic_set_DPRESCALER(uint32_t mask)
{
	EIC->DPRESCALER.reg |= mask;
}

/**
 * @brief eic get DPRESCALER register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EIC_DPRESCALER_PRESCALER0(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES0 Debouncer number of states
 * - EIC_DPRESCALER_PRESCALER1(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES1 Debouncer number of states
 * - EIC_DPRESCALER_TICKON Pin Sampler frequency selection
 **/
static inline uint32_t eic_get_DPRESCALER(uint32_t mask)
{
    return EIC->DPRESCALER.reg & mask;
}

/**
 * @brief eic write DPRESCALER register
 *
 * @param[in] data uint32_t 
 * - EIC_DPRESCALER_PRESCALER0(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES0 Debouncer number of states
 * - EIC_DPRESCALER_PRESCALER1(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES1 Debouncer number of states
 * - EIC_DPRESCALER_TICKON Pin Sampler frequency selection
 **/
static inline void eic_write_DPRESCALER(uint32_t data)
{
	EIC->DPRESCALER.reg = data;
}

/**
 * @brief eic clear DPRESCALER register
 *
 * @param[in] mask uint32_t 
 * - EIC_DPRESCALER_PRESCALER0(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES0 Debouncer number of states
 * - EIC_DPRESCALER_PRESCALER1(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES1 Debouncer number of states
 * - EIC_DPRESCALER_TICKON Pin Sampler frequency selection
 **/
static inline void eic_clear_DPRESCALER(uint32_t mask)
{
	EIC->DPRESCALER.reg &= ~mask;
}

/**
 * @brief eic read DPRESCALER register
 *
 * @return uint32_t
 * - EIC_DPRESCALER_PRESCALER0(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES0 Debouncer number of states
 * - EIC_DPRESCALER_PRESCALER1(value) Debouncer Prescaler
 * - EIC_DPRESCALER_STATES1 Debouncer number of states
 * - EIC_DPRESCALER_TICKON Pin Sampler frequency selection
 **/
static inline uint32_t eic_read_DPRESCALER(void)
{
	return EIC->DPRESCALER.reg;
}

/**
 * @brief eic get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EIC_SYNCBUSY_SWRST Software Reset Synchronization Busy Status
 * - EIC_SYNCBUSY_ENABLE Enable Synchronization Busy Status
 **/
static inline uint32_t eic_get_SYNCBUSY(uint32_t mask)
{
    return EIC->SYNCBUSY.reg & mask;
}

/**
 * @brief eic read SYNCBUSY register
 *
 * @return uint32_t
 * - EIC_SYNCBUSY_SWRST Software Reset Synchronization Busy Status
 * - EIC_SYNCBUSY_ENABLE Enable Synchronization Busy Status
 **/
static inline uint32_t eic_read_SYNCBUSY(void)
{
	return EIC->SYNCBUSY.reg;
}

/**
 * @brief eic get PINSTATE register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EIC_PINSTATE_PINSTATE(value) Pin State
 **/
static inline uint32_t eic_get_PINSTATE(uint32_t mask)
{
    return EIC->PINSTATE.reg & mask;
}

/**
 * @brief eic read PINSTATE register
 *
 * @return uint32_t
 * - EIC_PINSTATE_PINSTATE(value) Pin State
 **/
static inline uint32_t eic_read_PINSTATE(void)
{
	return EIC->PINSTATE.reg;
}

#endif /* _EIC_H */
