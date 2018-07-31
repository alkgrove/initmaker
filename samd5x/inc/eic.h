/**
 * @note This file is modified from the Atmel ASF4 hri include
 * by Alkgrove 2018
 * @version beta
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
 * @brief spin until sync busy bit is cleared
 *
 * @param[in] uint32_t
 * EIC_SYNCBUSY_SWRST	Software Reset Synchronization Busy Status 
 * EIC_SYNCBUSY_ENABLE	Enable Synchronization Busy Status 
 */
static inline void eic_wait_for_sync(uint32_t reg)
{
	while (EIC->SYNCBUSY.reg & reg) {};
}

/**
 * @brief get Sync Busy register masked
 *
 * @param[in] uint32_t
 * EIC_SYNCBUSY_SWRST	Software Reset Synchronization Busy Status 
 * EIC_SYNCBUSY_ENABLE	Enable Synchronization Busy Status 
 */
static inline bool eic_is_syncing(uint32_t reg)
{
	return EIC->SYNCBUSY.reg & reg;
}

/**
 * @brief set Interrupt Enable '1'=enable interrupt, '0'= do nothing
 *
 * @param[in] uint32_t mask
 * EIC_INTENSET_EXTINT(EICn)
 */
static inline void eic_set_INTEN(uint32_t mask)
{
	EIC->INTENSET.reg = mask;
}

/**
 * @brief get Interrupt Enable masked
 *
 * @param[in] uint32_t mask
 * EIC_INTENSET_EXTINT(EICn)
 */
static inline uint32_t eic_get_INTEN(uint32_t mask)
{
	return EIC->INTENSET.reg & mask;
}
/**
 * @brief read EIC Interrupt Enable Register
 *
 * @return uint32_t 16 bit 
 * EIC_INTENSET_EXTINT(EICn) 
 */
static inline uint32_t eic_read_INTEN(void)
{
	return EIC->INTENSET.reg;
}

/**
 * @brief write EIC Interrupt Enable Register
 *
 * @param[in] uint32_t 16 bit '1'=enable interrupt, '0'=disable interrupt
 * EIC_INTENSET_EXTINT(EICn) 
 */
static inline void eic_write_INTEN(uint32_t data)
{
	EIC->INTENSET.reg = data;
	EIC->INTENCLR.reg = ~data;
}

/**
 * @brief write EIC Interrupt Enable Register
 *
 * @param[in] uint32_t 16 bit '1'=disable interrupt, '0'=do nothing
 * EIC_INTENCLR_EXTINT(EICn) 
 */
static inline void eic_clear_INTEN(uint32_t mask)
{
	EIC->INTENCLR.reg = mask;
}

/**
 * @brief read NMI Interrupt flag 
 *
 * @return bool true if set; false if cleared
 * EIC_NMIFLAG_NMI
 */
static inline bool eic_get_NMIFLAG(void)
{
	return (bool) (EIC->NMIFLAG.reg & EIC_NMIFLAG_NMI) >> EIC_NMIFLAG_NMI_Pos;
}

/**
 * @brief clear NMI Interrupt flag 
 *
 */
static inline void eic_clear_NMIFLAG(void)
{
	EIC->NMIFLAG.reg = EIC_NMIFLAG_NMI;
}

/**
 * @brief read NMI Interrupt flag 
 *
 * @return uint16_t
 * EIC_NMIFLAG_NMI
 */
static inline uint16_t eic_read_NMIFLAG(void)
{
	return EIC->NMIFLAG.reg;
}

static inline uint32_t eic_read_INTFLAG(void)
{
	return EIC->INTFLAG.reg;
}
/**
 * @brief reset the interrupt flag
 *
 * @param[in] uint32_t mask
 */
static inline void eic_clear_INTFLAG(uint32_t mask)
{
	EIC->INTFLAG.reg = mask;
}

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
 * @brief set control A register bits with mask
 *
 * @param[in] uint8_t mask
 * EIC_CTRLA_SWRST	Software Reset 
 * EIC_CTRLA_ENABLE	Enable 
 * EIC_CTRLA_CKSEL	Clock Selection 0 = GCLK, 1 = ULP 32K clock
 * @param[in]
 * @return
 */
static inline void eic_set_CTRLA(uint8_t mask)
{
	EIC->CTRLA.reg |= mask;
}

/**
 * @brief get control A register masked
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 */
static inline uint8_t eic_get_CTRLA(uint8_t mask)
{
	return (EIC->CTRLA.reg & mask);
}

/**
 * @brief write CTRLA 
 * @note ENABLE and SWRST require write synchronization
 * if SWRST is set, all other bits are ignored
 * @param[in] uint8_t data
 */
static inline void eic_write_CTRLA(uint8_t data)
{
	EIC->CTRLA.reg = data;
}

/**
 * @brief read CTRLA 
 * @return uint8_t data
 */
static inline uint8_t eic_read_CTRLA(void)
{
	return EIC->CTRLA.reg;
}

/**
 * @brief write NMI control register
 *
 * @param[in] uint8_t data
 * EIC_NMICTRL_NMISENSE		Non-Maskable Interrupt Sense Configuration 
 *   EIC_NMICTRL_NMISENSE_NONE    No detection       
 *   EIC_NMICTRL_NMISENSE_RISE    Rising-edge detection 
 *   EIC_NMICTRL_NMISENSE_FALL    Falling-edge detection
 *   EIC_NMICTRL_NMISENSE_BOTH    Both-edges detection
 *   EIC_NMICTRL_NMISENSE_HIGH    High-level detection
 *   EIC_NMICTRL_NMISENSE_LOW     Low-level detection
 * EIC_NMICTRL_NMIFILTEN	Non-Maskable Interrupt Filter Enable 
 * EIC_NMICTRL_NMIASYNCH	Asynchronous Edge Detection Mode (1=async, 0=sync)
 */
static inline void eic_write_NMICTRL(uint8_t data)
{
	EIC->NMICTRL.reg = data;
}

/**
 * @brief read NMI control register
 *
 * @return uint8_t data
 * EIC_NMICTRL_NMISENSE		Non-Maskable Interrupt Sense Configuration 
 *   EIC_NMICTRL_NMISENSE_NONE    No detection       
 *   EIC_NMICTRL_NMISENSE_RISE    Rising-edge detection 
 *   EIC_NMICTRL_NMISENSE_FALL    Falling-edge detection
 *   EIC_NMICTRL_NMISENSE_BOTH    Both-edges detection
 *   EIC_NMICTRL_NMISENSE_HIGH    High-level detection
 *   EIC_NMICTRL_NMISENSE_LOW     Low-level detection
 * EIC_NMICTRL_NMIFILTEN	Non-Maskable Interrupt Filter Enable 
 * EIC_NMICTRL_NMIASYNCH	Asynchronous Edge Detection Mode (1=async, 0=sync)
 */
static inline uint8_t eic_read_NMICTRL(void)
{
	return EIC->NMICTRL.reg;
}

/**
 * @brief set event control register with mask
 * Enable protected
 * @param[in] uint32_t mask
 * EIC_EVCTRL_EXTINTEO(EICn)  External Interrupt Event Output Enable
 */
static inline void eic_set_EVCTRL(uint32_t mask)
{
	EIC->EVCTRL.reg |= mask;
}

/**
 * @brief write event control register
 * Enable protected
 * @param[in] uint32_t mask
 * EIC_EVCTRL_EXTINTEO(EICn)  External Interrupt Event Output Enable
 */
static inline void eic_write_EVCTRL(uint32_t data)
{
	EIC->EVCTRL.reg = data;
}

/**
 * @brief clear event control register with mask
 * Enable protected
 * @param[in] uint32_t mask
 * EIC_EVCTRL_EXTINTEO(EICn)  External Interrupt Event Output Enable
 */
static inline void eic_clear_EVCTRL(uint32_t mask)
{
	EIC->EVCTRL.reg &= ~mask;
}

/**
 * @brief read event control register
 *
 * @return uint32_t 
 * EIC_EVCTRL_EXTINTEO(EICn)  External Interrupt Event Output Enable
 */
static inline uint32_t eic_read_EVCTRL(void)
{
	return EIC->EVCTRL.reg;
}

/**
 * @brief write async/sync control register
 * Enable Protected
 * @param[in] uint32_t data
 * EIC_ASYNCH_ASYNCH(EICn) Asynchronous Edge Detection Mode
 * '1' is edge detection is asynchronously operated.
 * '0' is edge detection is synchronously operated.
 */
static inline void eic_write_ASYNCH(uint32_t data)
{
	EIC->ASYNCH.reg = data;
}

/**
 * @brief read async/sync control register
 *
 * @return uint32_t
 * EIC_ASYNCH_ASYNCH(EICn) Asynchronous Edge Detection Mode
 * '1' is edge detection is asynchronously operated.
 * '0' is edge detection is synchronously operated.
 */
static inline uint32_t eic_read_ASYNCH(void)
{
	return EIC->ASYNCH.reg;
}

/**
 * @brief set an individual config entry indexed by EICn
 * Enable Protected
 * @param[in] uint8_t index (EICn)
 * @param[in] config for EICn
 * EIC_CONFIG_FILTEN 		Filter Enable
 * EIC_CONFIG_SENSE(value)
 *  EIC_CONFIG_SENSE_NONE   No detection      
 *  EIC_CONFIG_SENSE_RISE   Rising edge detection 
 *  EIC_CONFIG_SENSE_FALL   Falling edge detection
 *  EIC_CONFIG_SENSE_BOTH   Both edges detection
 *  EIC_CONFIG_SENSE_HIGH   High level detection
 *  EIC_CONFIG_SENSE_LOW    Low level detection
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
 * @param[in] uint8_t index (EICn)
 * @param[in] uint8_t mask
 * EIC_CONFIG_SENSE_Msk
 * EIC_CONFIG_FILTEN 		Filter Enable
 */
static inline uint8_t eic_get_CONFIG(uint8_t eicn, uint8_t mask)
{
	uint8_t index = eicn >> 3;
	uint8_t pos = (eicn & 7) << 2;
	return (uint8_t) ((EIC->CONFIG[index].reg >> pos) & mask);
}

/**
 * @brief write config register indexed
 * Enable Protected
 * @param[in] uint8_t index for Config0 and Config1
 * @param[in] uint32_t data
 * EIC_CONFIG_SENSE0	Input Sense Configuration 0 
 * EIC_CONFIG_FILTEN0	Filter Enable 0 
 * EIC_CONFIG_SENSE1	Input Sense Configuration 1 
 * EIC_CONFIG_FILTEN1	Filter Enable 1 
 * EIC_CONFIG_SENSE2	Input Sense Configuration 2 
 * EIC_CONFIG_FILTEN2	Filter Enable 2 
 * EIC_CONFIG_SENSE3	Input Sense Configuration 3 
 * EIC_CONFIG_FILTEN3	Filter Enable 3 
 * EIC_CONFIG_SENSE4	Input Sense Configuration 4 
 * EIC_CONFIG_FILTEN4	Filter Enable 4 
 * EIC_CONFIG_SENSE5	Input Sense Configuration 5 
 * EIC_CONFIG_FILTEN5	Filter Enable 5 
 * EIC_CONFIG_SENSE6	Input Sense Configuration 6 
 * EIC_CONFIG_FILTEN6	Filter Enable 6 
 * EIC_CONFIG_SENSE7	Input Sense Configuration 7 
 * EIC_CONFIG_FILTEN7	Filter Enable 7 
 * Sense Configuration for SENSEn is
 *  EIC_CONFIG_SENSEn_NONE   No detection      
 *  EIC_CONFIG_SENSEn_RISE   Rising edge detection 
 *  EIC_CONFIG_SENSEn_FALL   Falling edge detection
 *  EIC_CONFIG_SENSEn_BOTH   Both edges detection
 *  EIC_CONFIG_SENSEn_HIGH   High level detection
 *  EIC_CONFIG_SENSEn_LOW    Low level detection
 */
static inline void eic_write_CONFIG(uint8_t index, uint32_t data)
{
	EIC->CONFIG[index].reg = data;
}

/**
 * @brief read config register indexed
 * Enable Protected
 * @param[in] uint8_t index for Config0 and Config1
 * @param[in] uint32_t data
 * EIC_CONFIG_SENSE0	Input Sense Configuration 0 
 * EIC_CONFIG_FILTEN0	Filter Enable 0 
 * EIC_CONFIG_SENSE1	Input Sense Configuration 1 
 * EIC_CONFIG_FILTEN1	Filter Enable 1 
 * EIC_CONFIG_SENSE2	Input Sense Configuration 2 
 * EIC_CONFIG_FILTEN2	Filter Enable 2 
 * EIC_CONFIG_SENSE3	Input Sense Configuration 3 
 * EIC_CONFIG_FILTEN3	Filter Enable 3 
 * EIC_CONFIG_SENSE4	Input Sense Configuration 4 
 * EIC_CONFIG_FILTEN4	Filter Enable 4 
 * EIC_CONFIG_SENSE5	Input Sense Configuration 5 
 * EIC_CONFIG_FILTEN5	Filter Enable 5 
 * EIC_CONFIG_SENSE6	Input Sense Configuration 6 
 * EIC_CONFIG_FILTEN6	Filter Enable 6 
 * EIC_CONFIG_SENSE7	Input Sense Configuration 7 
 * EIC_CONFIG_FILTEN7	Filter Enable 7 
 * Sense Configuration for SENSEn is
 *  EIC_CONFIG_SENSEn_NONE   No detection      
 *  EIC_CONFIG_SENSEn_RISE   Rising edge detection 
 *  EIC_CONFIG_SENSEn_FALL   Falling edge detection
 *  EIC_CONFIG_SENSEn_BOTH   Both edges detection
 *  EIC_CONFIG_SENSEn_HIGH   High level detection
 *  EIC_CONFIG_SENSEn_LOW    Low level detection
 */
 
static inline uint32_t eic_read_CONFIG(uint8_t index)
{
	return EIC->CONFIG[index].reg;
}

/**
 * @brief set Debounce Enable
 * Enable Protected
 * @param[in] uint32_t mask (1 << EICn) '1'=enables debounce, '0'=do nothing
 */
static inline void eic_set_DEBOUNCEN(uint32_t mask)
{
	EIC->DEBOUNCEN.reg |= mask;
}

/**
 * @brief write Debounce Enable Register
 *
 * @param[in] uint32_t
 * EIC_DEBOUNCEN_DEBOUNCEN(EICn) Debouncer Enable
 */
static inline void eic_write_DEBOUNCEN(uint32_t data)
{
	EIC->DEBOUNCEN.reg = data;
}
/**
 * @brief clear Debounce Enable Register bits
 *
 * @param[in] uint32_t mask (1 << EICn) '1'=disable debounce, '0'=do nothing
 * @param[in]
 * @return
 */
static inline void eic_clear_DEBOUNCEN(uint32_t mask)
{
	EIC->DEBOUNCEN.reg &= ~mask;
}

/**
 * @brief clear Control A Register bits
 *
 * @param[in] uint8_t mask
 * EIC_CTRLA_SWRST	Software Reset 
 * EIC_CTRLA_ENABLE	Enable 
 * EIC_CTRLA_CKSEL	Clock Selection 
 * @return
 */
static inline void eic_clear_CTRLA(uint32_t mask)
{
	EIC->CTRLA.reg &= ~mask;
}

/**
 * @brief read Debounce Enable Register
 *
 * @return uint32_t
 * EIC_DEBOUNCEN_DEBOUNCEN(EICn) Debouncer Enable
 */
static inline uint32_t eic_read_DEBOUNCEN(void)
{
	return EIC->DEBOUNCEN.reg;
}

/**
 * @brief write Debounce Prescaler Register
 * Enable Protected
 * @param[in] uint32_t data
 * EIC_DPRESCALER_PRESCALER0(value)	Debouncer Prescaler for EIC0-EIC7
 * EIC_DPRESCALER_STATES0		Debouncer number of states '1'=7 samples,'0'=3 samples
 * EIC_DPRESCALER_PRESCALER1(value)	Debouncer Prescaler for EIC8-EIC15
 * EIC_DPRESCALER_STATES1		Debouncer number of states '1'=7 samples,'0'=3 samples
 * EIC_DPRESCALER_TICKON		Pin Sampler frequency selection '1'=low freq, '0'=GCLK
 * Prescaler
 * 0x0 = clock/2
 * 0x1 = clock/4
 * 0x2 = clock/8
 * 0x3 = clock/16
 * 0x4 = clock/32
 * 0x5 = clock/64
 * 0x6 = clock/128
 * 0x7 = clock/256
 */
static inline void eic_write_DPRESCALER(uint32_t data)
{
	EIC->DPRESCALER.reg = data;
}

/**
 * @brief read Debounce Prescaler Register
 *
 * @return uint32_t data
 * EIC_DPRESCALER_PRESCALER0(value)	Debouncer Prescaler for EIC0-EIC7
 * EIC_DPRESCALER_STATES0		Debouncer number of states '1'=7 samples,'0'=3 samples
 * EIC_DPRESCALER_PRESCALER1(value)	Debouncer Prescaler for EIC8-EIC15
 * EIC_DPRESCALER_STATES1		Debouncer number of states '1'=7 samples,'0'=3 samples
 * EIC_DPRESCALER_TICKON		Pin Sampler frequency selection '1'=low freq, '0'=GCLK
 * Prescaler
 * 0x0 = clock/2
 * 0x1 = clock/4
 * 0x2 = clock/8
 * 0x3 = clock/16
 * 0x4 = clock/32
 * 0x5 = clock/64
 * 0x6 = clock/128
 * 0x7 = clock/256
 */
static inline uint32_t eic_read_DPRESCALER(void)
{
	return EIC->DPRESCALER.reg;
}

/**
 * @brief read Sync Busy Register
 *
 * @return uint32_t
 * EIC_SYNCBUSY_SWRST	Software Reset Synchronization Busy Status 
 * EIC_SYNCBUSY_ENABLE	Enable Synchronization Busy Status 
 */
static inline uint32_t eic_read_SYNCBUSY(void)
{
	return EIC->SYNCBUSY.reg;
}

/**
 * @brief get Pinstate Register masked
 *
 * @return uint32_t (1 << EICn)
 */

static inline uint32_t eic_get_PINSTATE(uint32_t mask)
{
	return EIC->PINSTATE.reg & mask;
}
/**
 * @brief read Pinstate Register 
 *
 * @return uint32_t (1 << EICn)
 */
static inline uint32_t eic_read_PINSTATE(void)
{
	return EIC->PINSTATE.reg;
}

#endif /* _EIC_H_ */
