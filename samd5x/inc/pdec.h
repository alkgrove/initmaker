/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM PDEC
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

#ifndef _PDEC_H_
#define _PDEC_H_

#include <stdbool.h>

/**
 * @brief pdec wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void pdec_wait_for_sync(uint32_t reg)
{
	while (PDEC->SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief pdec is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool pdec_is_syncing(uint32_t reg)
{
	return PDEC->SYNCBUSY.reg & reg;
}

/**
 * @brief pdec set CTRLB register
 *
 * @param[in] mask uint8_t 
 * - PDEC_CTRLBSET_LUPD Lock Update
 * - PDEC_CTRLBSET_CMD(value) Command
 *  +      PDEC_CTRLBSET_CMD_NONE No action
 *  +      PDEC_CTRLBSET_CMD_RETRIGGER Force a counter restart or retrigger
 *  +      PDEC_CTRLBSET_CMD_UPDATE Force update of double buffered registers
 *  +      PDEC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      PDEC_CTRLBSET_CMD_START Start QDEC/HALL
 *  +      PDEC_CTRLBSET_CMD_STOP Stop QDEC/HALL
 **/
static inline void pdec_set_CTRLB(uint8_t mask)
{
	PDEC->CTRLBSET.reg = mask;
}

/**
 * @brief pdec get CTRLB register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PDEC_CTRLBSET_LUPD Lock Update
 * - PDEC_CTRLBSET_CMD(value) Command
 *  +      PDEC_CTRLBSET_CMD_NONE No action
 *  +      PDEC_CTRLBSET_CMD_RETRIGGER Force a counter restart or retrigger
 *  +      PDEC_CTRLBSET_CMD_UPDATE Force update of double buffered registers
 *  +      PDEC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      PDEC_CTRLBSET_CMD_START Start QDEC/HALL
 *  +      PDEC_CTRLBSET_CMD_STOP Stop QDEC/HALL
 **/
static inline uint8_t pdec_get_CTRLB(uint8_t mask)
{
    return PDEC->CTRLBSET.reg & mask;
}

/**
 * @brief pdec read CTRLB register
 *
 * @return uint8_t
 * - PDEC_CTRLBSET_LUPD Lock Update
 * - PDEC_CTRLBSET_CMD(value) Command
 *  +      PDEC_CTRLBSET_CMD_NONE No action
 *  +      PDEC_CTRLBSET_CMD_RETRIGGER Force a counter restart or retrigger
 *  +      PDEC_CTRLBSET_CMD_UPDATE Force update of double buffered registers
 *  +      PDEC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      PDEC_CTRLBSET_CMD_START Start QDEC/HALL
 *  +      PDEC_CTRLBSET_CMD_STOP Stop QDEC/HALL
 **/
static inline uint8_t pdec_read_CTRLB(void)
{
	return PDEC->CTRLBSET.reg;
}

/**
 * @brief pdec write CTRLB register
 *
 * @param[in] data uint8_t 
 * - PDEC_CTRLBSET_LUPD Lock Update
 * - PDEC_CTRLBSET_CMD(value) Command
 *  +      PDEC_CTRLBSET_CMD_NONE No action
 *  +      PDEC_CTRLBSET_CMD_RETRIGGER Force a counter restart or retrigger
 *  +      PDEC_CTRLBSET_CMD_UPDATE Force update of double buffered registers
 *  +      PDEC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      PDEC_CTRLBSET_CMD_START Start QDEC/HALL
 *  +      PDEC_CTRLBSET_CMD_STOP Stop QDEC/HALL
 **/
static inline void pdec_write_CTRLB(uint8_t data)
{
	PDEC->CTRLBSET.reg = data;
	PDEC->CTRLBCLR.reg = ~data;
}

/**
 * @brief pdec clear CTRLB register
 *
 * @param[in] mask uint8_t 
 * - PDEC_CTRLBSET_LUPD Lock Update
 * - PDEC_CTRLBSET_CMD(value) Command
 *  +      PDEC_CTRLBSET_CMD_NONE No action
 *  +      PDEC_CTRLBSET_CMD_RETRIGGER Force a counter restart or retrigger
 *  +      PDEC_CTRLBSET_CMD_UPDATE Force update of double buffered registers
 *  +      PDEC_CTRLBSET_CMD_READSYNC Force a read synchronization of COUNT
 *  +      PDEC_CTRLBSET_CMD_START Start QDEC/HALL
 *  +      PDEC_CTRLBSET_CMD_STOP Stop QDEC/HALL
 **/
static inline void pdec_clear_CTRLB(uint8_t mask)
{
	PDEC->CTRLBCLR.reg = mask;
}

/**
 * @brief pdec set INTEN register
 *
 * @param[in] mask uint8_t 
 * - PDEC_INTENSET_OVF Overflow/Underflow Interrupt Enable
 * - PDEC_INTENSET_ERR Error Interrupt Enable
 * - PDEC_INTENSET_DIR Direction Interrupt Enable
 * - PDEC_INTENSET_VLC Velocity Interrupt Enable
 * - PDEC_INTENSET_MC0 Channel 0 Compare Match Enable
 * - PDEC_INTENSET_MC1 Channel 1 Compare Match Enable
 * - PDEC_INTENSET_MC(value) Channel x Compare Match Enable
 **/
static inline void pdec_set_INTEN(uint8_t mask)
{
	PDEC->INTENSET.reg = mask;
}

/**
 * @brief pdec get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PDEC_INTENSET_OVF Overflow/Underflow Interrupt Enable
 * - PDEC_INTENSET_ERR Error Interrupt Enable
 * - PDEC_INTENSET_DIR Direction Interrupt Enable
 * - PDEC_INTENSET_VLC Velocity Interrupt Enable
 * - PDEC_INTENSET_MC0 Channel 0 Compare Match Enable
 * - PDEC_INTENSET_MC1 Channel 1 Compare Match Enable
 * - PDEC_INTENSET_MC(value) Channel x Compare Match Enable
 **/
static inline uint8_t pdec_get_INTEN(uint8_t mask)
{
    return PDEC->INTENSET.reg & mask;
}

/**
 * @brief pdec read INTEN register
 *
 * @return uint8_t
 * - PDEC_INTENSET_OVF Overflow/Underflow Interrupt Enable
 * - PDEC_INTENSET_ERR Error Interrupt Enable
 * - PDEC_INTENSET_DIR Direction Interrupt Enable
 * - PDEC_INTENSET_VLC Velocity Interrupt Enable
 * - PDEC_INTENSET_MC0 Channel 0 Compare Match Enable
 * - PDEC_INTENSET_MC1 Channel 1 Compare Match Enable
 * - PDEC_INTENSET_MC(value) Channel x Compare Match Enable
 **/
static inline uint8_t pdec_read_INTEN(void)
{
	return PDEC->INTENSET.reg;
}

/**
 * @brief pdec write INTEN register
 *
 * @param[in] data uint8_t 
 * - PDEC_INTENSET_OVF Overflow/Underflow Interrupt Enable
 * - PDEC_INTENSET_ERR Error Interrupt Enable
 * - PDEC_INTENSET_DIR Direction Interrupt Enable
 * - PDEC_INTENSET_VLC Velocity Interrupt Enable
 * - PDEC_INTENSET_MC0 Channel 0 Compare Match Enable
 * - PDEC_INTENSET_MC1 Channel 1 Compare Match Enable
 * - PDEC_INTENSET_MC(value) Channel x Compare Match Enable
 **/
static inline void pdec_write_INTEN(uint8_t data)
{
	PDEC->INTENSET.reg = data;
	PDEC->INTENCLR.reg = ~data;
}

/**
 * @brief pdec clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - PDEC_INTENSET_OVF Overflow/Underflow Interrupt Enable
 * - PDEC_INTENSET_ERR Error Interrupt Enable
 * - PDEC_INTENSET_DIR Direction Interrupt Enable
 * - PDEC_INTENSET_VLC Velocity Interrupt Enable
 * - PDEC_INTENSET_MC0 Channel 0 Compare Match Enable
 * - PDEC_INTENSET_MC1 Channel 1 Compare Match Enable
 * - PDEC_INTENSET_MC(value) Channel x Compare Match Enable
 **/
static inline void pdec_clear_INTEN(uint8_t mask)
{
	PDEC->INTENCLR.reg = mask;
}

/**
 * @brief pdec get INTFLAG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PDEC_INTFLAG_OVF Overflow/Underflow
 * - PDEC_INTFLAG_ERR Error
 * - PDEC_INTFLAG_DIR Direction Change
 * - PDEC_INTFLAG_VLC Velocity
 * - PDEC_INTFLAG_MC0 Channel 0 Compare Match
 * - PDEC_INTFLAG_MC1 Channel 1 Compare Match
 * - PDEC_INTFLAG_MC(value) Channel x Compare Match
 **/
static inline uint8_t pdec_get_INTFLAG(uint8_t mask)
{
    return PDEC->INTFLAG.reg & mask;
}

/**
 * @brief pdec read INTFLAG register
 *
 * @return uint8_t
 * - PDEC_INTFLAG_OVF Overflow/Underflow
 * - PDEC_INTFLAG_ERR Error
 * - PDEC_INTFLAG_DIR Direction Change
 * - PDEC_INTFLAG_VLC Velocity
 * - PDEC_INTFLAG_MC0 Channel 0 Compare Match
 * - PDEC_INTFLAG_MC1 Channel 1 Compare Match
 * - PDEC_INTFLAG_MC(value) Channel x Compare Match
 **/
static inline uint8_t pdec_read_INTFLAG(void)
{
	return PDEC->INTFLAG.reg;
}

/**
 * @brief pdec clear INTFLAG register
 *
 * @param[in] mask uint8_t 
 * - PDEC_INTFLAG_OVF Overflow/Underflow
 * - PDEC_INTFLAG_ERR Error
 * - PDEC_INTFLAG_DIR Direction Change
 * - PDEC_INTFLAG_VLC Velocity
 * - PDEC_INTFLAG_MC0 Channel 0 Compare Match
 * - PDEC_INTFLAG_MC1 Channel 1 Compare Match
 * - PDEC_INTFLAG_MC(value) Channel x Compare Match
 **/
static inline void pdec_clear_INTFLAG(uint8_t mask)
{
	PDEC->INTFLAG.reg = mask;
}

/**
 * @brief pdec set CTRLA register
 *
 * @param[in] mask uint32_t 
 * - PDEC_CTRLA_SWRST Software Reset
 * - PDEC_CTRLA_ENABLE Enable
 * - PDEC_CTRLA_MODE(value) Operation Mode
 *  +      PDEC_CTRLA_MODE_QDEC QDEC operating mode
 *  +      PDEC_CTRLA_MODE_HALL HALL operating mode
 *  +      PDEC_CTRLA_MODE_COUNTER COUNTER operating mode
 * - PDEC_CTRLA_RUNSTDBY Run in Standby
 * - PDEC_CTRLA_CONF(value) PDEC Configuration
 *  +      PDEC_CTRLA_CONF_X4 Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X4S Secure Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X2 Decoder direction
 *  +      PDEC_CTRLA_CONF_X2S Secure decoder direction
 *  +      PDEC_CTRLA_CONF_AUTOC Auto correction mode
 * - PDEC_CTRLA_ALOCK Auto Lock
 * - PDEC_CTRLA_SWAP PDEC Phase A and B Swap
 * - PDEC_CTRLA_PEREN Period Enable
 * - PDEC_CTRLA_PINEN0 PDEC Input From Pin 0 Enable
 * - PDEC_CTRLA_PINEN1 PDEC Input From Pin 1 Enable
 * - PDEC_CTRLA_PINEN2 PDEC Input From Pin 2 Enable
 * - PDEC_CTRLA_PINEN(value) PDEC Input From Pin x Enable
 * - PDEC_CTRLA_PINVEN0 IO Pin 0 Invert Enable
 * - PDEC_CTRLA_PINVEN1 IO Pin 1 Invert Enable
 * - PDEC_CTRLA_PINVEN2 IO Pin 2 Invert Enable
 * - PDEC_CTRLA_PINVEN(value) IO Pin x Invert Enable
 * - PDEC_CTRLA_ANGULAR(value) Angular Counter Length
 * - PDEC_CTRLA_MAXCMP(value) Maximum Consecutive Missing Pulses
 **/
static inline void pdec_set_CTRLA(uint32_t mask)
{
	PDEC->CTRLA.reg |= mask;
}

/**
 * @brief pdec get CTRLA register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PDEC_CTRLA_SWRST Software Reset
 * - PDEC_CTRLA_ENABLE Enable
 * - PDEC_CTRLA_MODE(value) Operation Mode
 *  +      PDEC_CTRLA_MODE_QDEC QDEC operating mode
 *  +      PDEC_CTRLA_MODE_HALL HALL operating mode
 *  +      PDEC_CTRLA_MODE_COUNTER COUNTER operating mode
 * - PDEC_CTRLA_RUNSTDBY Run in Standby
 * - PDEC_CTRLA_CONF(value) PDEC Configuration
 *  +      PDEC_CTRLA_CONF_X4 Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X4S Secure Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X2 Decoder direction
 *  +      PDEC_CTRLA_CONF_X2S Secure decoder direction
 *  +      PDEC_CTRLA_CONF_AUTOC Auto correction mode
 * - PDEC_CTRLA_ALOCK Auto Lock
 * - PDEC_CTRLA_SWAP PDEC Phase A and B Swap
 * - PDEC_CTRLA_PEREN Period Enable
 * - PDEC_CTRLA_PINEN0 PDEC Input From Pin 0 Enable
 * - PDEC_CTRLA_PINEN1 PDEC Input From Pin 1 Enable
 * - PDEC_CTRLA_PINEN2 PDEC Input From Pin 2 Enable
 * - PDEC_CTRLA_PINEN(value) PDEC Input From Pin x Enable
 * - PDEC_CTRLA_PINVEN0 IO Pin 0 Invert Enable
 * - PDEC_CTRLA_PINVEN1 IO Pin 1 Invert Enable
 * - PDEC_CTRLA_PINVEN2 IO Pin 2 Invert Enable
 * - PDEC_CTRLA_PINVEN(value) IO Pin x Invert Enable
 * - PDEC_CTRLA_ANGULAR(value) Angular Counter Length
 * - PDEC_CTRLA_MAXCMP(value) Maximum Consecutive Missing Pulses
 **/
static inline uint32_t pdec_get_CTRLA(uint32_t mask)
{
    return PDEC->CTRLA.reg & mask;
}

/**
 * @brief pdec write CTRLA register
 *
 * @param[in] data uint32_t 
 * - PDEC_CTRLA_SWRST Software Reset
 * - PDEC_CTRLA_ENABLE Enable
 * - PDEC_CTRLA_MODE(value) Operation Mode
 *  +      PDEC_CTRLA_MODE_QDEC QDEC operating mode
 *  +      PDEC_CTRLA_MODE_HALL HALL operating mode
 *  +      PDEC_CTRLA_MODE_COUNTER COUNTER operating mode
 * - PDEC_CTRLA_RUNSTDBY Run in Standby
 * - PDEC_CTRLA_CONF(value) PDEC Configuration
 *  +      PDEC_CTRLA_CONF_X4 Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X4S Secure Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X2 Decoder direction
 *  +      PDEC_CTRLA_CONF_X2S Secure decoder direction
 *  +      PDEC_CTRLA_CONF_AUTOC Auto correction mode
 * - PDEC_CTRLA_ALOCK Auto Lock
 * - PDEC_CTRLA_SWAP PDEC Phase A and B Swap
 * - PDEC_CTRLA_PEREN Period Enable
 * - PDEC_CTRLA_PINEN0 PDEC Input From Pin 0 Enable
 * - PDEC_CTRLA_PINEN1 PDEC Input From Pin 1 Enable
 * - PDEC_CTRLA_PINEN2 PDEC Input From Pin 2 Enable
 * - PDEC_CTRLA_PINEN(value) PDEC Input From Pin x Enable
 * - PDEC_CTRLA_PINVEN0 IO Pin 0 Invert Enable
 * - PDEC_CTRLA_PINVEN1 IO Pin 1 Invert Enable
 * - PDEC_CTRLA_PINVEN2 IO Pin 2 Invert Enable
 * - PDEC_CTRLA_PINVEN(value) IO Pin x Invert Enable
 * - PDEC_CTRLA_ANGULAR(value) Angular Counter Length
 * - PDEC_CTRLA_MAXCMP(value) Maximum Consecutive Missing Pulses
 **/
static inline void pdec_write_CTRLA(uint32_t data)
{
	PDEC->CTRLA.reg = data;
}

/**
 * @brief pdec clear CTRLA register
 *
 * @param[in] mask uint32_t 
 * - PDEC_CTRLA_SWRST Software Reset
 * - PDEC_CTRLA_ENABLE Enable
 * - PDEC_CTRLA_MODE(value) Operation Mode
 *  +      PDEC_CTRLA_MODE_QDEC QDEC operating mode
 *  +      PDEC_CTRLA_MODE_HALL HALL operating mode
 *  +      PDEC_CTRLA_MODE_COUNTER COUNTER operating mode
 * - PDEC_CTRLA_RUNSTDBY Run in Standby
 * - PDEC_CTRLA_CONF(value) PDEC Configuration
 *  +      PDEC_CTRLA_CONF_X4 Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X4S Secure Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X2 Decoder direction
 *  +      PDEC_CTRLA_CONF_X2S Secure decoder direction
 *  +      PDEC_CTRLA_CONF_AUTOC Auto correction mode
 * - PDEC_CTRLA_ALOCK Auto Lock
 * - PDEC_CTRLA_SWAP PDEC Phase A and B Swap
 * - PDEC_CTRLA_PEREN Period Enable
 * - PDEC_CTRLA_PINEN0 PDEC Input From Pin 0 Enable
 * - PDEC_CTRLA_PINEN1 PDEC Input From Pin 1 Enable
 * - PDEC_CTRLA_PINEN2 PDEC Input From Pin 2 Enable
 * - PDEC_CTRLA_PINEN(value) PDEC Input From Pin x Enable
 * - PDEC_CTRLA_PINVEN0 IO Pin 0 Invert Enable
 * - PDEC_CTRLA_PINVEN1 IO Pin 1 Invert Enable
 * - PDEC_CTRLA_PINVEN2 IO Pin 2 Invert Enable
 * - PDEC_CTRLA_PINVEN(value) IO Pin x Invert Enable
 * - PDEC_CTRLA_ANGULAR(value) Angular Counter Length
 * - PDEC_CTRLA_MAXCMP(value) Maximum Consecutive Missing Pulses
 **/
static inline void pdec_clear_CTRLA(uint32_t mask)
{
	PDEC->CTRLA.reg &= ~mask;
}

/**
 * @brief pdec read CTRLA register
 *
 * @return uint32_t
 * - PDEC_CTRLA_SWRST Software Reset
 * - PDEC_CTRLA_ENABLE Enable
 * - PDEC_CTRLA_MODE(value) Operation Mode
 *  +      PDEC_CTRLA_MODE_QDEC QDEC operating mode
 *  +      PDEC_CTRLA_MODE_HALL HALL operating mode
 *  +      PDEC_CTRLA_MODE_COUNTER COUNTER operating mode
 * - PDEC_CTRLA_RUNSTDBY Run in Standby
 * - PDEC_CTRLA_CONF(value) PDEC Configuration
 *  +      PDEC_CTRLA_CONF_X4 Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X4S Secure Quadrature decoder direction
 *  +      PDEC_CTRLA_CONF_X2 Decoder direction
 *  +      PDEC_CTRLA_CONF_X2S Secure decoder direction
 *  +      PDEC_CTRLA_CONF_AUTOC Auto correction mode
 * - PDEC_CTRLA_ALOCK Auto Lock
 * - PDEC_CTRLA_SWAP PDEC Phase A and B Swap
 * - PDEC_CTRLA_PEREN Period Enable
 * - PDEC_CTRLA_PINEN0 PDEC Input From Pin 0 Enable
 * - PDEC_CTRLA_PINEN1 PDEC Input From Pin 1 Enable
 * - PDEC_CTRLA_PINEN2 PDEC Input From Pin 2 Enable
 * - PDEC_CTRLA_PINEN(value) PDEC Input From Pin x Enable
 * - PDEC_CTRLA_PINVEN0 IO Pin 0 Invert Enable
 * - PDEC_CTRLA_PINVEN1 IO Pin 1 Invert Enable
 * - PDEC_CTRLA_PINVEN2 IO Pin 2 Invert Enable
 * - PDEC_CTRLA_PINVEN(value) IO Pin x Invert Enable
 * - PDEC_CTRLA_ANGULAR(value) Angular Counter Length
 * - PDEC_CTRLA_MAXCMP(value) Maximum Consecutive Missing Pulses
 **/
static inline uint32_t pdec_read_CTRLA(void)
{
	return PDEC->CTRLA.reg;
}

/**
 * @brief pdec set EVCTRL register
 *
 * @param[in] mask uint16_t 
 * - PDEC_EVCTRL_EVACT(value) Event Action
 *  +      PDEC_EVCTRL_EVACT_OFF Event action disabled
 *  +      PDEC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger on event
 *  +      PDEC_EVCTRL_EVACT_COUNT Count on event
 * - PDEC_EVCTRL_EVINV(value) Inverted Event Input Enable
 * - PDEC_EVCTRL_EVEI(value) Event Input Enable
 * - PDEC_EVCTRL_OVFEO Overflow/Underflow Output Event Enable
 * - PDEC_EVCTRL_ERREO Error  Output Event Enable
 * - PDEC_EVCTRL_DIREO Direction Output Event Enable
 * - PDEC_EVCTRL_VLCEO Velocity Output Event Enable
 * - PDEC_EVCTRL_MCEO0 Match Channel 0 Event Output Enable
 * - PDEC_EVCTRL_MCEO1 Match Channel 1 Event Output Enable
 * - PDEC_EVCTRL_MCEO(value) Match Channel x Event Output Enable
 **/
static inline void pdec_set_EVCTRL(uint16_t mask)
{
	PDEC->EVCTRL.reg |= mask;
}

/**
 * @brief pdec get EVCTRL register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - PDEC_EVCTRL_EVACT(value) Event Action
 *  +      PDEC_EVCTRL_EVACT_OFF Event action disabled
 *  +      PDEC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger on event
 *  +      PDEC_EVCTRL_EVACT_COUNT Count on event
 * - PDEC_EVCTRL_EVINV(value) Inverted Event Input Enable
 * - PDEC_EVCTRL_EVEI(value) Event Input Enable
 * - PDEC_EVCTRL_OVFEO Overflow/Underflow Output Event Enable
 * - PDEC_EVCTRL_ERREO Error  Output Event Enable
 * - PDEC_EVCTRL_DIREO Direction Output Event Enable
 * - PDEC_EVCTRL_VLCEO Velocity Output Event Enable
 * - PDEC_EVCTRL_MCEO0 Match Channel 0 Event Output Enable
 * - PDEC_EVCTRL_MCEO1 Match Channel 1 Event Output Enable
 * - PDEC_EVCTRL_MCEO(value) Match Channel x Event Output Enable
 **/
static inline uint16_t pdec_get_EVCTRL(uint16_t mask)
{
    return PDEC->EVCTRL.reg & mask;
}

/**
 * @brief pdec write EVCTRL register
 *
 * @param[in] data uint16_t 
 * - PDEC_EVCTRL_EVACT(value) Event Action
 *  +      PDEC_EVCTRL_EVACT_OFF Event action disabled
 *  +      PDEC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger on event
 *  +      PDEC_EVCTRL_EVACT_COUNT Count on event
 * - PDEC_EVCTRL_EVINV(value) Inverted Event Input Enable
 * - PDEC_EVCTRL_EVEI(value) Event Input Enable
 * - PDEC_EVCTRL_OVFEO Overflow/Underflow Output Event Enable
 * - PDEC_EVCTRL_ERREO Error  Output Event Enable
 * - PDEC_EVCTRL_DIREO Direction Output Event Enable
 * - PDEC_EVCTRL_VLCEO Velocity Output Event Enable
 * - PDEC_EVCTRL_MCEO0 Match Channel 0 Event Output Enable
 * - PDEC_EVCTRL_MCEO1 Match Channel 1 Event Output Enable
 * - PDEC_EVCTRL_MCEO(value) Match Channel x Event Output Enable
 **/
static inline void pdec_write_EVCTRL(uint16_t data)
{
	PDEC->EVCTRL.reg = data;
}

/**
 * @brief pdec clear EVCTRL register
 *
 * @param[in] mask uint16_t 
 * - PDEC_EVCTRL_EVACT(value) Event Action
 *  +      PDEC_EVCTRL_EVACT_OFF Event action disabled
 *  +      PDEC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger on event
 *  +      PDEC_EVCTRL_EVACT_COUNT Count on event
 * - PDEC_EVCTRL_EVINV(value) Inverted Event Input Enable
 * - PDEC_EVCTRL_EVEI(value) Event Input Enable
 * - PDEC_EVCTRL_OVFEO Overflow/Underflow Output Event Enable
 * - PDEC_EVCTRL_ERREO Error  Output Event Enable
 * - PDEC_EVCTRL_DIREO Direction Output Event Enable
 * - PDEC_EVCTRL_VLCEO Velocity Output Event Enable
 * - PDEC_EVCTRL_MCEO0 Match Channel 0 Event Output Enable
 * - PDEC_EVCTRL_MCEO1 Match Channel 1 Event Output Enable
 * - PDEC_EVCTRL_MCEO(value) Match Channel x Event Output Enable
 **/
static inline void pdec_clear_EVCTRL(uint16_t mask)
{
	PDEC->EVCTRL.reg &= ~mask;
}

/**
 * @brief pdec read EVCTRL register
 *
 * @return uint16_t
 * - PDEC_EVCTRL_EVACT(value) Event Action
 *  +      PDEC_EVCTRL_EVACT_OFF Event action disabled
 *  +      PDEC_EVCTRL_EVACT_RETRIGGER Start, restart or retrigger on event
 *  +      PDEC_EVCTRL_EVACT_COUNT Count on event
 * - PDEC_EVCTRL_EVINV(value) Inverted Event Input Enable
 * - PDEC_EVCTRL_EVEI(value) Event Input Enable
 * - PDEC_EVCTRL_OVFEO Overflow/Underflow Output Event Enable
 * - PDEC_EVCTRL_ERREO Error  Output Event Enable
 * - PDEC_EVCTRL_DIREO Direction Output Event Enable
 * - PDEC_EVCTRL_VLCEO Velocity Output Event Enable
 * - PDEC_EVCTRL_MCEO0 Match Channel 0 Event Output Enable
 * - PDEC_EVCTRL_MCEO1 Match Channel 1 Event Output Enable
 * - PDEC_EVCTRL_MCEO(value) Match Channel x Event Output Enable
 **/
static inline uint16_t pdec_read_EVCTRL(void)
{
	return PDEC->EVCTRL.reg;
}

/**
 * @brief pdec set DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - PDEC_DBGCTRL_DBGRUN Debug Run Mode
 **/
static inline void pdec_set_DBGCTRL(uint8_t mask)
{
	PDEC->DBGCTRL.reg |= mask;
}

/**
 * @brief pdec get DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PDEC_DBGCTRL_DBGRUN Debug Run Mode
 **/
static inline uint8_t pdec_get_DBGCTRL(uint8_t mask)
{
    return PDEC->DBGCTRL.reg & mask;
}

/**
 * @brief pdec write DBGCTRL register
 *
 * @param[in] data uint8_t 
 * - PDEC_DBGCTRL_DBGRUN Debug Run Mode
 **/
static inline void pdec_write_DBGCTRL(uint8_t data)
{
	PDEC->DBGCTRL.reg = data;
}

/**
 * @brief pdec clear DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - PDEC_DBGCTRL_DBGRUN Debug Run Mode
 **/
static inline void pdec_clear_DBGCTRL(uint8_t mask)
{
	PDEC->DBGCTRL.reg &= ~mask;
}

/**
 * @brief pdec read DBGCTRL register
 *
 * @return uint8_t
 * - PDEC_DBGCTRL_DBGRUN Debug Run Mode
 **/
static inline uint8_t pdec_read_DBGCTRL(void)
{
	return PDEC->DBGCTRL.reg;
}

/**
 * @brief pdec set PRESC register
 *
 * @param[in] mask uint8_t 
 * - PDEC_PRESC_PRESC(value) Prescaler Value
 *  +      PDEC_PRESC_PRESC_DIV1 No division
 *  +      PDEC_PRESC_PRESC_DIV2 Divide by 2
 *  +      PDEC_PRESC_PRESC_DIV4 Divide by 4
 *  +      PDEC_PRESC_PRESC_DIV8 Divide by 8
 *  +      PDEC_PRESC_PRESC_DIV16 Divide by 16
 *  +      PDEC_PRESC_PRESC_DIV32 Divide by 32
 *  +      PDEC_PRESC_PRESC_DIV64 Divide by 64
 *  +      PDEC_PRESC_PRESC_DIV128 Divide by 128
 *  +      PDEC_PRESC_PRESC_DIV256 Divide by 256
 *  +      PDEC_PRESC_PRESC_DIV512 Divide by 512
 *  +      PDEC_PRESC_PRESC_DIV1024 Divide by 1024
 **/
static inline void pdec_set_PRESC(uint8_t mask)
{
	PDEC->PRESC.reg |= mask;
}

/**
 * @brief pdec get PRESC register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PDEC_PRESC_PRESC(value) Prescaler Value
 *  +      PDEC_PRESC_PRESC_DIV1 No division
 *  +      PDEC_PRESC_PRESC_DIV2 Divide by 2
 *  +      PDEC_PRESC_PRESC_DIV4 Divide by 4
 *  +      PDEC_PRESC_PRESC_DIV8 Divide by 8
 *  +      PDEC_PRESC_PRESC_DIV16 Divide by 16
 *  +      PDEC_PRESC_PRESC_DIV32 Divide by 32
 *  +      PDEC_PRESC_PRESC_DIV64 Divide by 64
 *  +      PDEC_PRESC_PRESC_DIV128 Divide by 128
 *  +      PDEC_PRESC_PRESC_DIV256 Divide by 256
 *  +      PDEC_PRESC_PRESC_DIV512 Divide by 512
 *  +      PDEC_PRESC_PRESC_DIV1024 Divide by 1024
 **/
static inline uint8_t pdec_get_PRESC(uint8_t mask)
{
    return PDEC->PRESC.reg & mask;
}

/**
 * @brief pdec write PRESC register
 *
 * @param[in] data uint8_t 
 * - PDEC_PRESC_PRESC(value) Prescaler Value
 *  +      PDEC_PRESC_PRESC_DIV1 No division
 *  +      PDEC_PRESC_PRESC_DIV2 Divide by 2
 *  +      PDEC_PRESC_PRESC_DIV4 Divide by 4
 *  +      PDEC_PRESC_PRESC_DIV8 Divide by 8
 *  +      PDEC_PRESC_PRESC_DIV16 Divide by 16
 *  +      PDEC_PRESC_PRESC_DIV32 Divide by 32
 *  +      PDEC_PRESC_PRESC_DIV64 Divide by 64
 *  +      PDEC_PRESC_PRESC_DIV128 Divide by 128
 *  +      PDEC_PRESC_PRESC_DIV256 Divide by 256
 *  +      PDEC_PRESC_PRESC_DIV512 Divide by 512
 *  +      PDEC_PRESC_PRESC_DIV1024 Divide by 1024
 **/
static inline void pdec_write_PRESC(uint8_t data)
{
	PDEC->PRESC.reg = data;
}

/**
 * @brief pdec clear PRESC register
 *
 * @param[in] mask uint8_t 
 * - PDEC_PRESC_PRESC(value) Prescaler Value
 *  +      PDEC_PRESC_PRESC_DIV1 No division
 *  +      PDEC_PRESC_PRESC_DIV2 Divide by 2
 *  +      PDEC_PRESC_PRESC_DIV4 Divide by 4
 *  +      PDEC_PRESC_PRESC_DIV8 Divide by 8
 *  +      PDEC_PRESC_PRESC_DIV16 Divide by 16
 *  +      PDEC_PRESC_PRESC_DIV32 Divide by 32
 *  +      PDEC_PRESC_PRESC_DIV64 Divide by 64
 *  +      PDEC_PRESC_PRESC_DIV128 Divide by 128
 *  +      PDEC_PRESC_PRESC_DIV256 Divide by 256
 *  +      PDEC_PRESC_PRESC_DIV512 Divide by 512
 *  +      PDEC_PRESC_PRESC_DIV1024 Divide by 1024
 **/
static inline void pdec_clear_PRESC(uint8_t mask)
{
	PDEC->PRESC.reg &= ~mask;
}

/**
 * @brief pdec read PRESC register
 *
 * @return uint8_t
 * - PDEC_PRESC_PRESC(value) Prescaler Value
 *  +      PDEC_PRESC_PRESC_DIV1 No division
 *  +      PDEC_PRESC_PRESC_DIV2 Divide by 2
 *  +      PDEC_PRESC_PRESC_DIV4 Divide by 4
 *  +      PDEC_PRESC_PRESC_DIV8 Divide by 8
 *  +      PDEC_PRESC_PRESC_DIV16 Divide by 16
 *  +      PDEC_PRESC_PRESC_DIV32 Divide by 32
 *  +      PDEC_PRESC_PRESC_DIV64 Divide by 64
 *  +      PDEC_PRESC_PRESC_DIV128 Divide by 128
 *  +      PDEC_PRESC_PRESC_DIV256 Divide by 256
 *  +      PDEC_PRESC_PRESC_DIV512 Divide by 512
 *  +      PDEC_PRESC_PRESC_DIV1024 Divide by 1024
 **/
static inline uint8_t pdec_read_PRESC(void)
{
	return PDEC->PRESC.reg;
}

/**
 * @brief pdec set FILTER register
 *
 * @param[in] mask uint8_t 
 * - PDEC_FILTER_FILTER(value) Filter Value
 **/
static inline void pdec_set_FILTER(uint8_t mask)
{
	PDEC->FILTER.reg |= mask;
}

/**
 * @brief pdec get FILTER register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PDEC_FILTER_FILTER(value) Filter Value
 **/
static inline uint8_t pdec_get_FILTER(uint8_t mask)
{
    return PDEC->FILTER.reg & mask;
}

/**
 * @brief pdec write FILTER register
 *
 * @param[in] data uint8_t 
 * - PDEC_FILTER_FILTER(value) Filter Value
 **/
static inline void pdec_write_FILTER(uint8_t data)
{
	PDEC->FILTER.reg = data;
}

/**
 * @brief pdec clear FILTER register
 *
 * @param[in] mask uint8_t 
 * - PDEC_FILTER_FILTER(value) Filter Value
 **/
static inline void pdec_clear_FILTER(uint8_t mask)
{
	PDEC->FILTER.reg &= ~mask;
}

/**
 * @brief pdec read FILTER register
 *
 * @return uint8_t
 * - PDEC_FILTER_FILTER(value) Filter Value
 **/
static inline uint8_t pdec_read_FILTER(void)
{
	return PDEC->FILTER.reg;
}

/**
 * @brief pdec set PRESCBUF register
 *
 * @param[in] mask uint8_t 
 * - PDEC_PRESCBUF_PRESCBUF(value) Prescaler Buffer Value
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1 No division
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV2 Divide by 2
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV4 Divide by 4
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV8 Divide by 8
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV16 Divide by 16
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV32 Divide by 32
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV64 Divide by 64
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV128 Divide by 128
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV256 Divide by 256
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV512 Divide by 512
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1024 Divide by 1024
 **/
static inline void pdec_set_PRESCBUF(uint8_t mask)
{
	PDEC->PRESCBUF.reg |= mask;
}

/**
 * @brief pdec get PRESCBUF register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PDEC_PRESCBUF_PRESCBUF(value) Prescaler Buffer Value
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1 No division
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV2 Divide by 2
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV4 Divide by 4
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV8 Divide by 8
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV16 Divide by 16
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV32 Divide by 32
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV64 Divide by 64
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV128 Divide by 128
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV256 Divide by 256
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV512 Divide by 512
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1024 Divide by 1024
 **/
static inline uint8_t pdec_get_PRESCBUF(uint8_t mask)
{
    return PDEC->PRESCBUF.reg & mask;
}

/**
 * @brief pdec write PRESCBUF register
 *
 * @param[in] data uint8_t 
 * - PDEC_PRESCBUF_PRESCBUF(value) Prescaler Buffer Value
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1 No division
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV2 Divide by 2
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV4 Divide by 4
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV8 Divide by 8
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV16 Divide by 16
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV32 Divide by 32
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV64 Divide by 64
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV128 Divide by 128
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV256 Divide by 256
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV512 Divide by 512
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1024 Divide by 1024
 **/
static inline void pdec_write_PRESCBUF(uint8_t data)
{
	PDEC->PRESCBUF.reg = data;
}

/**
 * @brief pdec clear PRESCBUF register
 *
 * @param[in] mask uint8_t 
 * - PDEC_PRESCBUF_PRESCBUF(value) Prescaler Buffer Value
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1 No division
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV2 Divide by 2
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV4 Divide by 4
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV8 Divide by 8
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV16 Divide by 16
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV32 Divide by 32
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV64 Divide by 64
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV128 Divide by 128
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV256 Divide by 256
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV512 Divide by 512
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1024 Divide by 1024
 **/
static inline void pdec_clear_PRESCBUF(uint8_t mask)
{
	PDEC->PRESCBUF.reg &= ~mask;
}

/**
 * @brief pdec read PRESCBUF register
 *
 * @return uint8_t
 * - PDEC_PRESCBUF_PRESCBUF(value) Prescaler Buffer Value
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1 No division
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV2 Divide by 2
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV4 Divide by 4
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV8 Divide by 8
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV16 Divide by 16
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV32 Divide by 32
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV64 Divide by 64
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV128 Divide by 128
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV256 Divide by 256
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV512 Divide by 512
 *  +      PDEC_PRESCBUF_PRESCBUF_DIV1024 Divide by 1024
 **/
static inline uint8_t pdec_read_PRESCBUF(void)
{
	return PDEC->PRESCBUF.reg;
}

/**
 * @brief pdec set FILTERBUF register
 *
 * @param[in] mask uint8_t 
 * - PDEC_FILTERBUF_FILTERBUF(value) Filter Buffer Value
 **/
static inline void pdec_set_FILTERBUF(uint8_t mask)
{
	PDEC->FILTERBUF.reg |= mask;
}

/**
 * @brief pdec get FILTERBUF register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - PDEC_FILTERBUF_FILTERBUF(value) Filter Buffer Value
 **/
static inline uint8_t pdec_get_FILTERBUF(uint8_t mask)
{
    return PDEC->FILTERBUF.reg & mask;
}

/**
 * @brief pdec write FILTERBUF register
 *
 * @param[in] data uint8_t 
 * - PDEC_FILTERBUF_FILTERBUF(value) Filter Buffer Value
 **/
static inline void pdec_write_FILTERBUF(uint8_t data)
{
	PDEC->FILTERBUF.reg = data;
}

/**
 * @brief pdec clear FILTERBUF register
 *
 * @param[in] mask uint8_t 
 * - PDEC_FILTERBUF_FILTERBUF(value) Filter Buffer Value
 **/
static inline void pdec_clear_FILTERBUF(uint8_t mask)
{
	PDEC->FILTERBUF.reg &= ~mask;
}

/**
 * @brief pdec read FILTERBUF register
 *
 * @return uint8_t
 * - PDEC_FILTERBUF_FILTERBUF(value) Filter Buffer Value
 **/
static inline uint8_t pdec_read_FILTERBUF(void)
{
	return PDEC->FILTERBUF.reg;
}

/**
 * @brief pdec set COUNT register
 *
 * @param[in] mask uint32_t 
 * - PDEC_COUNT_COUNT(value) Counter Value
 **/
static inline void pdec_set_COUNT(uint32_t mask)
{
	PDEC->COUNT.reg |= mask;
}

/**
 * @brief pdec get COUNT register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PDEC_COUNT_COUNT(value) Counter Value
 **/
static inline uint32_t pdec_get_COUNT(uint32_t mask)
{
    return PDEC->COUNT.reg & mask;
}

/**
 * @brief pdec write COUNT register
 *
 * @param[in] data uint32_t 
 * - PDEC_COUNT_COUNT(value) Counter Value
 **/
static inline void pdec_write_COUNT(uint32_t data)
{
	PDEC->COUNT.reg = data;
}

/**
 * @brief pdec clear COUNT register
 *
 * @param[in] mask uint32_t 
 * - PDEC_COUNT_COUNT(value) Counter Value
 **/
static inline void pdec_clear_COUNT(uint32_t mask)
{
	PDEC->COUNT.reg &= ~mask;
}

/**
 * @brief pdec read COUNT register
 *
 * @return uint32_t
 * - PDEC_COUNT_COUNT(value) Counter Value
 **/
static inline uint32_t pdec_read_COUNT(void)
{
	return PDEC->COUNT.reg;
}

/**
 * @brief pdec set CC register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - PDEC_CC_CC(value) Channel Compare Value
 **/
static inline void pdec_set_CC(uint8_t index, uint32_t mask)
{
	PDEC->CC[index].reg |= mask;
}

/**
 * @brief pdec get CC register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PDEC_CC_CC(value) Channel Compare Value
 **/
static inline uint32_t pdec_get_CC(uint8_t index, uint32_t mask)
{
    return PDEC->CC[index].reg & mask;
}

/**
 * @brief pdec write CC register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - PDEC_CC_CC(value) Channel Compare Value
 **/
static inline void pdec_write_CC(uint8_t index, uint32_t data)
{
	PDEC->CC[index].reg = data;
}

/**
 * @brief pdec clear CC register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - PDEC_CC_CC(value) Channel Compare Value
 **/
static inline void pdec_clear_CC(uint8_t index, uint32_t mask)
{
	PDEC->CC[index].reg &= ~mask;
}

/**
 * @brief pdec read CC register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - PDEC_CC_CC(value) Channel Compare Value
 **/
static inline uint32_t pdec_read_CC(uint8_t index)
{
	return PDEC->CC[index].reg;
}

/**
 * @brief pdec set CCBUF register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - PDEC_CCBUF_CCBUF(value) Channel Compare Buffer Value
 **/
static inline void pdec_set_CCBUF(uint8_t index, uint32_t mask)
{
	PDEC->CCBUF[index].reg |= mask;
}

/**
 * @brief pdec get CCBUF register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PDEC_CCBUF_CCBUF(value) Channel Compare Buffer Value
 **/
static inline uint32_t pdec_get_CCBUF(uint8_t index, uint32_t mask)
{
    return PDEC->CCBUF[index].reg & mask;
}

/**
 * @brief pdec write CCBUF register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - PDEC_CCBUF_CCBUF(value) Channel Compare Buffer Value
 **/
static inline void pdec_write_CCBUF(uint8_t index, uint32_t data)
{
	PDEC->CCBUF[index].reg = data;
}

/**
 * @brief pdec clear CCBUF register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - PDEC_CCBUF_CCBUF(value) Channel Compare Buffer Value
 **/
static inline void pdec_clear_CCBUF(uint8_t index, uint32_t mask)
{
	PDEC->CCBUF[index].reg &= ~mask;
}

/**
 * @brief pdec read CCBUF register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - PDEC_CCBUF_CCBUF(value) Channel Compare Buffer Value
 **/
static inline uint32_t pdec_read_CCBUF(uint8_t index)
{
	return PDEC->CCBUF[index].reg;
}

/**
 * @brief pdec get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - PDEC_SYNCBUSY_SWRST Software Reset Synchronization Busy
 * - PDEC_SYNCBUSY_ENABLE Enable Synchronization Busy
 * - PDEC_SYNCBUSY_CTRLB Control B Synchronization Busy
 * - PDEC_SYNCBUSY_STATUS Status Synchronization Busy
 * - PDEC_SYNCBUSY_PRESC Prescaler Synchronization Busy
 * - PDEC_SYNCBUSY_FILTER Filter Synchronization Busy
 * - PDEC_SYNCBUSY_COUNT Count Synchronization Busy
 * - PDEC_SYNCBUSY_CC0 Compare Channel 0 Synchronization Busy
 * - PDEC_SYNCBUSY_CC1 Compare Channel 1 Synchronization Busy
 * - PDEC_SYNCBUSY_CC(value) Compare Channel x Synchronization Busy
 **/
static inline uint32_t pdec_get_SYNCBUSY(uint32_t mask)
{
    return PDEC->SYNCBUSY.reg & mask;
}

/**
 * @brief pdec read SYNCBUSY register
 *
 * @return uint32_t
 * - PDEC_SYNCBUSY_SWRST Software Reset Synchronization Busy
 * - PDEC_SYNCBUSY_ENABLE Enable Synchronization Busy
 * - PDEC_SYNCBUSY_CTRLB Control B Synchronization Busy
 * - PDEC_SYNCBUSY_STATUS Status Synchronization Busy
 * - PDEC_SYNCBUSY_PRESC Prescaler Synchronization Busy
 * - PDEC_SYNCBUSY_FILTER Filter Synchronization Busy
 * - PDEC_SYNCBUSY_COUNT Count Synchronization Busy
 * - PDEC_SYNCBUSY_CC0 Compare Channel 0 Synchronization Busy
 * - PDEC_SYNCBUSY_CC1 Compare Channel 1 Synchronization Busy
 * - PDEC_SYNCBUSY_CC(value) Compare Channel x Synchronization Busy
 **/
static inline uint32_t pdec_read_SYNCBUSY(void)
{
	return PDEC->SYNCBUSY.reg;
}

/**
 * @brief pdec get STATUS register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - PDEC_STATUS_QERR Quadrature Error Flag
 * - PDEC_STATUS_IDXERR Index Error Flag
 * - PDEC_STATUS_MPERR Missing Pulse Error flag
 * - PDEC_STATUS_WINERR Window Error Flag
 * - PDEC_STATUS_HERR Hall Error Flag
 * - PDEC_STATUS_STOP Stop
 * - PDEC_STATUS_DIR Direction Status Flag
 * - PDEC_STATUS_PRESCBUFV Prescaler Buffer Valid
 * - PDEC_STATUS_FILTERBUFV Filter Buffer Valid
 * - PDEC_STATUS_CCBUFV0 Compare Channel 0 Buffer Valid
 * - PDEC_STATUS_CCBUFV1 Compare Channel 1 Buffer Valid
 * - PDEC_STATUS_CCBUFV(value) Compare Channel x Buffer Valid
 **/
static inline uint16_t pdec_get_STATUS(uint16_t mask)
{
    return PDEC->STATUS.reg & mask;
}

/**
 * @brief pdec clear STATUS register
 *
 * @param[in] mask uint16_t 
 * - PDEC_STATUS_QERR Quadrature Error Flag
 * - PDEC_STATUS_IDXERR Index Error Flag
 * - PDEC_STATUS_MPERR Missing Pulse Error flag
 * - PDEC_STATUS_WINERR Window Error Flag
 * - PDEC_STATUS_HERR Hall Error Flag
 * - PDEC_STATUS_STOP Stop
 * - PDEC_STATUS_DIR Direction Status Flag
 * - PDEC_STATUS_PRESCBUFV Prescaler Buffer Valid
 * - PDEC_STATUS_FILTERBUFV Filter Buffer Valid
 * - PDEC_STATUS_CCBUFV0 Compare Channel 0 Buffer Valid
 * - PDEC_STATUS_CCBUFV1 Compare Channel 1 Buffer Valid
 * - PDEC_STATUS_CCBUFV(value) Compare Channel x Buffer Valid
 **/
static inline void pdec_clear_STATUS(uint16_t mask)
{
	PDEC->STATUS.reg = mask;
}

/**
 * @brief pdec read STATUS register
 *
 * @return uint16_t
 * - PDEC_STATUS_QERR Quadrature Error Flag
 * - PDEC_STATUS_IDXERR Index Error Flag
 * - PDEC_STATUS_MPERR Missing Pulse Error flag
 * - PDEC_STATUS_WINERR Window Error Flag
 * - PDEC_STATUS_HERR Hall Error Flag
 * - PDEC_STATUS_STOP Stop
 * - PDEC_STATUS_DIR Direction Status Flag
 * - PDEC_STATUS_PRESCBUFV Prescaler Buffer Valid
 * - PDEC_STATUS_FILTERBUFV Filter Buffer Valid
 * - PDEC_STATUS_CCBUFV0 Compare Channel 0 Buffer Valid
 * - PDEC_STATUS_CCBUFV1 Compare Channel 1 Buffer Valid
 * - PDEC_STATUS_CCBUFV(value) Compare Channel x Buffer Valid
 **/
static inline uint16_t pdec_read_STATUS(void)
{
	return PDEC->STATUS.reg;
}

#endif /* _PDEC_H */
