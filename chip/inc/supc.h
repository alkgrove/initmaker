/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM SUPC
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

#ifndef _SUPC_H_
#define _SUPC_H_

#include <stdbool.h>

/**
 * @brief supc set INTEN register
 *
 * @param[in] uint32_t mask
 * SUPC_INTENSET_BOD33RDY  BOD33 Ready 
 * SUPC_INTENSET_BOD33DET  BOD33 Detection 
 * SUPC_INTENSET_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_INTENSET_BOD12RDY  BOD12 Ready 
 * SUPC_INTENSET_BOD12DET  BOD12 Detection 
 * SUPC_INTENSET_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_INTENSET_VREGRDY  Voltage Regulator Ready 
 * SUPC_INTENSET_VCORERDY  VDDCORE Ready 
 */
static inline void supc_set_INTEN(uint32_t mask)
{
	SUPC->INTENSET.reg = mask;
}

/**
 * @brief supc get INTEN register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_INTENSET_BOD33RDY  BOD33 Ready 
 * SUPC_INTENSET_BOD33DET  BOD33 Detection 
 * SUPC_INTENSET_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_INTENSET_BOD12RDY  BOD12 Ready 
 * SUPC_INTENSET_BOD12DET  BOD12 Detection 
 * SUPC_INTENSET_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_INTENSET_VREGRDY  Voltage Regulator Ready 
 * SUPC_INTENSET_VCORERDY  VDDCORE Ready 
 */
static inline uint32_t supc_get_INTEN(uint32_t mask)
{
    return SUPC->INTENSET.reg & mask;
}

/**
 * @brief supc read INTEN register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_INTENSET_BOD33RDY  BOD33 Ready 
 * SUPC_INTENSET_BOD33DET  BOD33 Detection 
 * SUPC_INTENSET_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_INTENSET_BOD12RDY  BOD12 Ready 
 * SUPC_INTENSET_BOD12DET  BOD12 Detection 
 * SUPC_INTENSET_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_INTENSET_VREGRDY  Voltage Regulator Ready 
 * SUPC_INTENSET_VCORERDY  VDDCORE Ready 
 */
static inline uint32_t supc_read_INTEN(void)
{
	return SUPC->INTENSET.reg;
}

/**
 * @brief supc write INTEN register
 *
 * @param[in] uint32_t data
 * SUPC_INTENSET_BOD33RDY  BOD33 Ready 
 * SUPC_INTENSET_BOD33DET  BOD33 Detection 
 * SUPC_INTENSET_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_INTENSET_BOD12RDY  BOD12 Ready 
 * SUPC_INTENSET_BOD12DET  BOD12 Detection 
 * SUPC_INTENSET_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_INTENSET_VREGRDY  Voltage Regulator Ready 
 * SUPC_INTENSET_VCORERDY  VDDCORE Ready 
 */
static inline void supc_write_INTEN(uint32_t data)
{
	SUPC->INTENSET.reg = data;
	SUPC->INTENCLR.reg = ~data;
}

/**
 * @brief supc clear INTEN register
 *
 * @param[in] uint32_t mask
 * SUPC_INTENSET_BOD33RDY  BOD33 Ready 
 * SUPC_INTENSET_BOD33DET  BOD33 Detection 
 * SUPC_INTENSET_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_INTENSET_BOD12RDY  BOD12 Ready 
 * SUPC_INTENSET_BOD12DET  BOD12 Detection 
 * SUPC_INTENSET_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_INTENSET_VREGRDY  Voltage Regulator Ready 
 * SUPC_INTENSET_VCORERDY  VDDCORE Ready 
 */
static inline void supc_clear_INTEN(uint32_t mask)
{
	SUPC->INTENCLR.reg = mask;
}

/**
 * @brief supc get INTFLAG register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_INTFLAG_BOD33RDY  BOD33 Ready 
 * SUPC_INTFLAG_BOD33DET  BOD33 Detection 
 * SUPC_INTFLAG_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_INTFLAG_BOD12RDY  BOD12 Ready 
 * SUPC_INTFLAG_BOD12DET  BOD12 Detection 
 * SUPC_INTFLAG_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_INTFLAG_VREGRDY  Voltage Regulator Ready 
 * SUPC_INTFLAG_VCORERDY  VDDCORE Ready 
 */
static inline uint32_t supc_get_INTFLAG(uint32_t mask)
{
    return SUPC->INTFLAG.reg & mask;
}

/**
 * @brief supc read INTFLAG register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_INTFLAG_BOD33RDY  BOD33 Ready 
 * SUPC_INTFLAG_BOD33DET  BOD33 Detection 
 * SUPC_INTFLAG_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_INTFLAG_BOD12RDY  BOD12 Ready 
 * SUPC_INTFLAG_BOD12DET  BOD12 Detection 
 * SUPC_INTFLAG_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_INTFLAG_VREGRDY  Voltage Regulator Ready 
 * SUPC_INTFLAG_VCORERDY  VDDCORE Ready 
 */
static inline uint32_t supc_read_INTFLAG(void)
{
	return SUPC->INTFLAG.reg;
}

/**
 * @brief supc clear INTFLAG register
 *
 * @param[in] uint32_t mask
 * SUPC_INTFLAG_BOD33RDY  BOD33 Ready 
 * SUPC_INTFLAG_BOD33DET  BOD33 Detection 
 * SUPC_INTFLAG_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_INTFLAG_BOD12RDY  BOD12 Ready 
 * SUPC_INTFLAG_BOD12DET  BOD12 Detection 
 * SUPC_INTFLAG_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_INTFLAG_VREGRDY  Voltage Regulator Ready 
 * SUPC_INTFLAG_VCORERDY  VDDCORE Ready 
 */
static inline void supc_clear_INTFLAG(uint32_t mask)
{
	SUPC->INTFLAG.reg = mask;
}

/**
 * @brief supc set BOD33 register
 *
 * @param[in] uint32_t mask
 * SUPC_BOD33_ENABLE  Enable 
 * SUPC_BOD33_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD33_ACTION_NONE  No action 
 *    SUPC_BOD33_ACTION_RESET  The BOD33 generates a reset 
 *    SUPC_BOD33_ACTION_INT  The BOD33 generates an interrupt 
 *    SUPC_BOD33_ACTION_BKUP  The BOD33 puts the device in backup sleep mode 
 * SUPC_BOD33_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD33_RUNSTDBY  Run in Standby mode 
 * SUPC_BOD33_RUNHIB  Run in Hibernate mode 
 * SUPC_BOD33_RUNBKUP  Run in Backup mode 
 * SUPC_BOD33_HYST(value)  Hysteresis value 
 * SUPC_BOD33_PSEL(value)  Prescaler Select 
 *    SUPC_BOD33_PSEL_NODIV  Not divided 
 *    SUPC_BOD33_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD33_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD33_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD33_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD33_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD33_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD33_PSEL_DIV256  Divide clock by 256 
 * SUPC_BOD33_LEVEL(value)  Threshold Level for VDD 
 * SUPC_BOD33_VBATLEVEL(value)  Threshold Level in battery backup sleep mode for VBAT 
 */
static inline void supc_set_BOD33(uint32_t mask)
{
	SUPC->BOD33.reg |= mask;
}

/**
 * @brief supc get BOD33 register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_BOD33_ENABLE  Enable 
 * SUPC_BOD33_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD33_ACTION_NONE  No action 
 *    SUPC_BOD33_ACTION_RESET  The BOD33 generates a reset 
 *    SUPC_BOD33_ACTION_INT  The BOD33 generates an interrupt 
 *    SUPC_BOD33_ACTION_BKUP  The BOD33 puts the device in backup sleep mode 
 * SUPC_BOD33_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD33_RUNSTDBY  Run in Standby mode 
 * SUPC_BOD33_RUNHIB  Run in Hibernate mode 
 * SUPC_BOD33_RUNBKUP  Run in Backup mode 
 * SUPC_BOD33_HYST(value)  Hysteresis value 
 * SUPC_BOD33_PSEL(value)  Prescaler Select 
 *    SUPC_BOD33_PSEL_NODIV  Not divided 
 *    SUPC_BOD33_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD33_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD33_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD33_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD33_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD33_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD33_PSEL_DIV256  Divide clock by 256 
 * SUPC_BOD33_LEVEL(value)  Threshold Level for VDD 
 * SUPC_BOD33_VBATLEVEL(value)  Threshold Level in battery backup sleep mode for VBAT 
 */
static inline uint32_t supc_get_BOD33(uint32_t mask)
{
    return SUPC->BOD33.reg & mask;
}

/**
 * @brief supc write BOD33 register
 *
 * @param[in] uint32_t data
 * SUPC_BOD33_ENABLE  Enable 
 * SUPC_BOD33_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD33_ACTION_NONE  No action 
 *    SUPC_BOD33_ACTION_RESET  The BOD33 generates a reset 
 *    SUPC_BOD33_ACTION_INT  The BOD33 generates an interrupt 
 *    SUPC_BOD33_ACTION_BKUP  The BOD33 puts the device in backup sleep mode 
 * SUPC_BOD33_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD33_RUNSTDBY  Run in Standby mode 
 * SUPC_BOD33_RUNHIB  Run in Hibernate mode 
 * SUPC_BOD33_RUNBKUP  Run in Backup mode 
 * SUPC_BOD33_HYST(value)  Hysteresis value 
 * SUPC_BOD33_PSEL(value)  Prescaler Select 
 *    SUPC_BOD33_PSEL_NODIV  Not divided 
 *    SUPC_BOD33_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD33_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD33_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD33_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD33_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD33_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD33_PSEL_DIV256  Divide clock by 256 
 * SUPC_BOD33_LEVEL(value)  Threshold Level for VDD 
 * SUPC_BOD33_VBATLEVEL(value)  Threshold Level in battery backup sleep mode for VBAT 
 */
static inline void supc_write_BOD33(uint32_t data)
{
	SUPC->BOD33.reg = data;
}

/**
 * @brief supc clear BOD33 register
 *
 * @param[in] uint32_t mask
 * SUPC_BOD33_ENABLE  Enable 
 * SUPC_BOD33_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD33_ACTION_NONE  No action 
 *    SUPC_BOD33_ACTION_RESET  The BOD33 generates a reset 
 *    SUPC_BOD33_ACTION_INT  The BOD33 generates an interrupt 
 *    SUPC_BOD33_ACTION_BKUP  The BOD33 puts the device in backup sleep mode 
 * SUPC_BOD33_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD33_RUNSTDBY  Run in Standby mode 
 * SUPC_BOD33_RUNHIB  Run in Hibernate mode 
 * SUPC_BOD33_RUNBKUP  Run in Backup mode 
 * SUPC_BOD33_HYST(value)  Hysteresis value 
 * SUPC_BOD33_PSEL(value)  Prescaler Select 
 *    SUPC_BOD33_PSEL_NODIV  Not divided 
 *    SUPC_BOD33_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD33_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD33_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD33_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD33_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD33_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD33_PSEL_DIV256  Divide clock by 256 
 * SUPC_BOD33_LEVEL(value)  Threshold Level for VDD 
 * SUPC_BOD33_VBATLEVEL(value)  Threshold Level in battery backup sleep mode for VBAT 
 */
static inline void supc_clear_BOD33(uint32_t mask)
{
	SUPC->BOD33.reg &= ~mask;
}

/**
 * @brief supc read BOD33 register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_BOD33_ENABLE  Enable 
 * SUPC_BOD33_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD33_ACTION_NONE  No action 
 *    SUPC_BOD33_ACTION_RESET  The BOD33 generates a reset 
 *    SUPC_BOD33_ACTION_INT  The BOD33 generates an interrupt 
 *    SUPC_BOD33_ACTION_BKUP  The BOD33 puts the device in backup sleep mode 
 * SUPC_BOD33_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD33_RUNSTDBY  Run in Standby mode 
 * SUPC_BOD33_RUNHIB  Run in Hibernate mode 
 * SUPC_BOD33_RUNBKUP  Run in Backup mode 
 * SUPC_BOD33_HYST(value)  Hysteresis value 
 * SUPC_BOD33_PSEL(value)  Prescaler Select 
 *    SUPC_BOD33_PSEL_NODIV  Not divided 
 *    SUPC_BOD33_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD33_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD33_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD33_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD33_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD33_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD33_PSEL_DIV256  Divide clock by 256 
 * SUPC_BOD33_LEVEL(value)  Threshold Level for VDD 
 * SUPC_BOD33_VBATLEVEL(value)  Threshold Level in battery backup sleep mode for VBAT 
 */
static inline uint32_t supc_read_BOD33(void)
{
	return SUPC->BOD33.reg;
}

/**
 * @brief supc set BOD12 register
 *
 * @param[in] uint32_t mask
 * SUPC_BOD12_ENABLE  Enable 
 * SUPC_BOD12_HYST  Hysteresis Enable 
 * SUPC_BOD12_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD12_ACTION_NONE  No action 
 *    SUPC_BOD12_ACTION_RESET  The BOD12 generates a reset 
 *    SUPC_BOD12_ACTION_INT  The BOD12 generates an interrupt 
 * SUPC_BOD12_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD12_RUNSTDBY  Run during Standby 
 * SUPC_BOD12_ACTCFG  Configuration in Active mode 
 * SUPC_BOD12_PSEL(value)  Prescaler Select 
 *    SUPC_BOD12_PSEL_DIV2  Divide clock by 2 
 *    SUPC_BOD12_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD12_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD12_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD12_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD12_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD12_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD12_PSEL_DIV256  Divide clock by 256 
 *    SUPC_BOD12_PSEL_DIV512  Divide clock by 512 
 *    SUPC_BOD12_PSEL_DIV1024  Divide clock by 1024 
 *    SUPC_BOD12_PSEL_DIV2048  Divide clock by 2048 
 *    SUPC_BOD12_PSEL_DIV4096  Divide clock by 4096 
 *    SUPC_BOD12_PSEL_DIV8192  Divide clock by 8192 
 *    SUPC_BOD12_PSEL_DIV16384  Divide clock by 16384 
 *    SUPC_BOD12_PSEL_DIV32768  Divide clock by 32768 
 *    SUPC_BOD12_PSEL_DIV65536  Divide clock by 65536 
 * SUPC_BOD12_LEVEL(value)  Threshold Level 
 */
static inline void supc_set_BOD12(uint32_t mask)
{
	SUPC->BOD12.reg |= mask;
}

/**
 * @brief supc get BOD12 register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_BOD12_ENABLE  Enable 
 * SUPC_BOD12_HYST  Hysteresis Enable 
 * SUPC_BOD12_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD12_ACTION_NONE  No action 
 *    SUPC_BOD12_ACTION_RESET  The BOD12 generates a reset 
 *    SUPC_BOD12_ACTION_INT  The BOD12 generates an interrupt 
 * SUPC_BOD12_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD12_RUNSTDBY  Run during Standby 
 * SUPC_BOD12_ACTCFG  Configuration in Active mode 
 * SUPC_BOD12_PSEL(value)  Prescaler Select 
 *    SUPC_BOD12_PSEL_DIV2  Divide clock by 2 
 *    SUPC_BOD12_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD12_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD12_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD12_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD12_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD12_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD12_PSEL_DIV256  Divide clock by 256 
 *    SUPC_BOD12_PSEL_DIV512  Divide clock by 512 
 *    SUPC_BOD12_PSEL_DIV1024  Divide clock by 1024 
 *    SUPC_BOD12_PSEL_DIV2048  Divide clock by 2048 
 *    SUPC_BOD12_PSEL_DIV4096  Divide clock by 4096 
 *    SUPC_BOD12_PSEL_DIV8192  Divide clock by 8192 
 *    SUPC_BOD12_PSEL_DIV16384  Divide clock by 16384 
 *    SUPC_BOD12_PSEL_DIV32768  Divide clock by 32768 
 *    SUPC_BOD12_PSEL_DIV65536  Divide clock by 65536 
 * SUPC_BOD12_LEVEL(value)  Threshold Level 
 */
static inline uint32_t supc_get_BOD12(uint32_t mask)
{
    return SUPC->BOD12.reg & mask;
}

/**
 * @brief supc write BOD12 register
 *
 * @param[in] uint32_t data
 * SUPC_BOD12_ENABLE  Enable 
 * SUPC_BOD12_HYST  Hysteresis Enable 
 * SUPC_BOD12_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD12_ACTION_NONE  No action 
 *    SUPC_BOD12_ACTION_RESET  The BOD12 generates a reset 
 *    SUPC_BOD12_ACTION_INT  The BOD12 generates an interrupt 
 * SUPC_BOD12_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD12_RUNSTDBY  Run during Standby 
 * SUPC_BOD12_ACTCFG  Configuration in Active mode 
 * SUPC_BOD12_PSEL(value)  Prescaler Select 
 *    SUPC_BOD12_PSEL_DIV2  Divide clock by 2 
 *    SUPC_BOD12_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD12_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD12_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD12_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD12_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD12_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD12_PSEL_DIV256  Divide clock by 256 
 *    SUPC_BOD12_PSEL_DIV512  Divide clock by 512 
 *    SUPC_BOD12_PSEL_DIV1024  Divide clock by 1024 
 *    SUPC_BOD12_PSEL_DIV2048  Divide clock by 2048 
 *    SUPC_BOD12_PSEL_DIV4096  Divide clock by 4096 
 *    SUPC_BOD12_PSEL_DIV8192  Divide clock by 8192 
 *    SUPC_BOD12_PSEL_DIV16384  Divide clock by 16384 
 *    SUPC_BOD12_PSEL_DIV32768  Divide clock by 32768 
 *    SUPC_BOD12_PSEL_DIV65536  Divide clock by 65536 
 * SUPC_BOD12_LEVEL(value)  Threshold Level 
 */
static inline void supc_write_BOD12(uint32_t data)
{
	SUPC->BOD12.reg = data;
}

/**
 * @brief supc clear BOD12 register
 *
 * @param[in] uint32_t mask
 * SUPC_BOD12_ENABLE  Enable 
 * SUPC_BOD12_HYST  Hysteresis Enable 
 * SUPC_BOD12_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD12_ACTION_NONE  No action 
 *    SUPC_BOD12_ACTION_RESET  The BOD12 generates a reset 
 *    SUPC_BOD12_ACTION_INT  The BOD12 generates an interrupt 
 * SUPC_BOD12_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD12_RUNSTDBY  Run during Standby 
 * SUPC_BOD12_ACTCFG  Configuration in Active mode 
 * SUPC_BOD12_PSEL(value)  Prescaler Select 
 *    SUPC_BOD12_PSEL_DIV2  Divide clock by 2 
 *    SUPC_BOD12_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD12_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD12_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD12_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD12_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD12_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD12_PSEL_DIV256  Divide clock by 256 
 *    SUPC_BOD12_PSEL_DIV512  Divide clock by 512 
 *    SUPC_BOD12_PSEL_DIV1024  Divide clock by 1024 
 *    SUPC_BOD12_PSEL_DIV2048  Divide clock by 2048 
 *    SUPC_BOD12_PSEL_DIV4096  Divide clock by 4096 
 *    SUPC_BOD12_PSEL_DIV8192  Divide clock by 8192 
 *    SUPC_BOD12_PSEL_DIV16384  Divide clock by 16384 
 *    SUPC_BOD12_PSEL_DIV32768  Divide clock by 32768 
 *    SUPC_BOD12_PSEL_DIV65536  Divide clock by 65536 
 * SUPC_BOD12_LEVEL(value)  Threshold Level 
 */
static inline void supc_clear_BOD12(uint32_t mask)
{
	SUPC->BOD12.reg &= ~mask;
}

/**
 * @brief supc read BOD12 register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_BOD12_ENABLE  Enable 
 * SUPC_BOD12_HYST  Hysteresis Enable 
 * SUPC_BOD12_ACTION(value)  Action when Threshold Crossed 
 *    SUPC_BOD12_ACTION_NONE  No action 
 *    SUPC_BOD12_ACTION_RESET  The BOD12 generates a reset 
 *    SUPC_BOD12_ACTION_INT  The BOD12 generates an interrupt 
 * SUPC_BOD12_STDBYCFG  Configuration in Standby mode 
 * SUPC_BOD12_RUNSTDBY  Run during Standby 
 * SUPC_BOD12_ACTCFG  Configuration in Active mode 
 * SUPC_BOD12_PSEL(value)  Prescaler Select 
 *    SUPC_BOD12_PSEL_DIV2  Divide clock by 2 
 *    SUPC_BOD12_PSEL_DIV4  Divide clock by 4 
 *    SUPC_BOD12_PSEL_DIV8  Divide clock by 8 
 *    SUPC_BOD12_PSEL_DIV16  Divide clock by 16 
 *    SUPC_BOD12_PSEL_DIV32  Divide clock by 32 
 *    SUPC_BOD12_PSEL_DIV64  Divide clock by 64 
 *    SUPC_BOD12_PSEL_DIV128  Divide clock by 128 
 *    SUPC_BOD12_PSEL_DIV256  Divide clock by 256 
 *    SUPC_BOD12_PSEL_DIV512  Divide clock by 512 
 *    SUPC_BOD12_PSEL_DIV1024  Divide clock by 1024 
 *    SUPC_BOD12_PSEL_DIV2048  Divide clock by 2048 
 *    SUPC_BOD12_PSEL_DIV4096  Divide clock by 4096 
 *    SUPC_BOD12_PSEL_DIV8192  Divide clock by 8192 
 *    SUPC_BOD12_PSEL_DIV16384  Divide clock by 16384 
 *    SUPC_BOD12_PSEL_DIV32768  Divide clock by 32768 
 *    SUPC_BOD12_PSEL_DIV65536  Divide clock by 65536 
 * SUPC_BOD12_LEVEL(value)  Threshold Level 
 */
static inline uint32_t supc_read_BOD12(void)
{
	return SUPC->BOD12.reg;
}

/**
 * @brief supc set VREG register
 *
 * @param[in] uint32_t mask
 * SUPC_VREG_ENABLE  Enable 
 * SUPC_VREG_SEL  Voltage Regulator Selection 
 *    SUPC_VREG_SEL_LDO  LDO selection 
 *    SUPC_VREG_SEL_BUCK  Buck selection 
 * SUPC_VREG_RUNBKUP  Run in Backup mode 
 * SUPC_VREG_VSEN  Voltage Scaling Enable 
 * SUPC_VREG_VSPER(value)  Voltage Scaling Period 
 */
static inline void supc_set_VREG(uint32_t mask)
{
	SUPC->VREG.reg |= mask;
}

/**
 * @brief supc get VREG register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_VREG_ENABLE  Enable 
 * SUPC_VREG_SEL  Voltage Regulator Selection 
 *    SUPC_VREG_SEL_LDO  LDO selection 
 *    SUPC_VREG_SEL_BUCK  Buck selection 
 * SUPC_VREG_RUNBKUP  Run in Backup mode 
 * SUPC_VREG_VSEN  Voltage Scaling Enable 
 * SUPC_VREG_VSPER(value)  Voltage Scaling Period 
 */
static inline uint32_t supc_get_VREG(uint32_t mask)
{
    return SUPC->VREG.reg & mask;
}

/**
 * @brief supc write VREG register
 *
 * @param[in] uint32_t data
 * SUPC_VREG_ENABLE  Enable 
 * SUPC_VREG_SEL  Voltage Regulator Selection 
 *    SUPC_VREG_SEL_LDO  LDO selection 
 *    SUPC_VREG_SEL_BUCK  Buck selection 
 * SUPC_VREG_RUNBKUP  Run in Backup mode 
 * SUPC_VREG_VSEN  Voltage Scaling Enable 
 * SUPC_VREG_VSPER(value)  Voltage Scaling Period 
 */
static inline void supc_write_VREG(uint32_t data)
{
	SUPC->VREG.reg = data;
}

/**
 * @brief supc clear VREG register
 *
 * @param[in] uint32_t mask
 * SUPC_VREG_ENABLE  Enable 
 * SUPC_VREG_SEL  Voltage Regulator Selection 
 *    SUPC_VREG_SEL_LDO  LDO selection 
 *    SUPC_VREG_SEL_BUCK  Buck selection 
 * SUPC_VREG_RUNBKUP  Run in Backup mode 
 * SUPC_VREG_VSEN  Voltage Scaling Enable 
 * SUPC_VREG_VSPER(value)  Voltage Scaling Period 
 */
static inline void supc_clear_VREG(uint32_t mask)
{
	SUPC->VREG.reg &= ~mask;
}

/**
 * @brief supc read VREG register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_VREG_ENABLE  Enable 
 * SUPC_VREG_SEL  Voltage Regulator Selection 
 *    SUPC_VREG_SEL_LDO  LDO selection 
 *    SUPC_VREG_SEL_BUCK  Buck selection 
 * SUPC_VREG_RUNBKUP  Run in Backup mode 
 * SUPC_VREG_VSEN  Voltage Scaling Enable 
 * SUPC_VREG_VSPER(value)  Voltage Scaling Period 
 */
static inline uint32_t supc_read_VREG(void)
{
	return SUPC->VREG.reg;
}

/**
 * @brief supc set VREF register
 *
 * @param[in] uint32_t mask
 * SUPC_VREF_TSEN  Temperature Sensor Output Enable 
 * SUPC_VREF_VREFOE  Voltage Reference Output Enable 
 * SUPC_VREF_TSSEL  Temperature Sensor Selection 
 * SUPC_VREF_RUNSTDBY  Run during Standby 
 * SUPC_VREF_ONDEMAND  On Demand Contrl 
 * SUPC_VREF_SEL(value)  Voltage Reference Selection 
 *    SUPC_VREF_SEL_1V0  1.0V voltage reference typical value 
 *    SUPC_VREF_SEL_1V1  1.1V voltage reference typical value 
 *    SUPC_VREF_SEL_1V2  1.2V voltage reference typical value 
 *    SUPC_VREF_SEL_1V25  1.25V voltage reference typical value 
 *    SUPC_VREF_SEL_2V0  2.0V voltage reference typical value 
 *    SUPC_VREF_SEL_2V2  2.2V voltage reference typical value 
 *    SUPC_VREF_SEL_2V4  2.4V voltage reference typical value 
 *    SUPC_VREF_SEL_2V5  2.5V voltage reference typical value 
 */
static inline void supc_set_VREF(uint32_t mask)
{
	SUPC->VREF.reg |= mask;
}

/**
 * @brief supc get VREF register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_VREF_TSEN  Temperature Sensor Output Enable 
 * SUPC_VREF_VREFOE  Voltage Reference Output Enable 
 * SUPC_VREF_TSSEL  Temperature Sensor Selection 
 * SUPC_VREF_RUNSTDBY  Run during Standby 
 * SUPC_VREF_ONDEMAND  On Demand Contrl 
 * SUPC_VREF_SEL(value)  Voltage Reference Selection 
 *    SUPC_VREF_SEL_1V0  1.0V voltage reference typical value 
 *    SUPC_VREF_SEL_1V1  1.1V voltage reference typical value 
 *    SUPC_VREF_SEL_1V2  1.2V voltage reference typical value 
 *    SUPC_VREF_SEL_1V25  1.25V voltage reference typical value 
 *    SUPC_VREF_SEL_2V0  2.0V voltage reference typical value 
 *    SUPC_VREF_SEL_2V2  2.2V voltage reference typical value 
 *    SUPC_VREF_SEL_2V4  2.4V voltage reference typical value 
 *    SUPC_VREF_SEL_2V5  2.5V voltage reference typical value 
 */
static inline uint32_t supc_get_VREF(uint32_t mask)
{
    return SUPC->VREF.reg & mask;
}

/**
 * @brief supc write VREF register
 *
 * @param[in] uint32_t data
 * SUPC_VREF_TSEN  Temperature Sensor Output Enable 
 * SUPC_VREF_VREFOE  Voltage Reference Output Enable 
 * SUPC_VREF_TSSEL  Temperature Sensor Selection 
 * SUPC_VREF_RUNSTDBY  Run during Standby 
 * SUPC_VREF_ONDEMAND  On Demand Contrl 
 * SUPC_VREF_SEL(value)  Voltage Reference Selection 
 *    SUPC_VREF_SEL_1V0  1.0V voltage reference typical value 
 *    SUPC_VREF_SEL_1V1  1.1V voltage reference typical value 
 *    SUPC_VREF_SEL_1V2  1.2V voltage reference typical value 
 *    SUPC_VREF_SEL_1V25  1.25V voltage reference typical value 
 *    SUPC_VREF_SEL_2V0  2.0V voltage reference typical value 
 *    SUPC_VREF_SEL_2V2  2.2V voltage reference typical value 
 *    SUPC_VREF_SEL_2V4  2.4V voltage reference typical value 
 *    SUPC_VREF_SEL_2V5  2.5V voltage reference typical value 
 */
static inline void supc_write_VREF(uint32_t data)
{
	SUPC->VREF.reg = data;
}

/**
 * @brief supc clear VREF register
 *
 * @param[in] uint32_t mask
 * SUPC_VREF_TSEN  Temperature Sensor Output Enable 
 * SUPC_VREF_VREFOE  Voltage Reference Output Enable 
 * SUPC_VREF_TSSEL  Temperature Sensor Selection 
 * SUPC_VREF_RUNSTDBY  Run during Standby 
 * SUPC_VREF_ONDEMAND  On Demand Contrl 
 * SUPC_VREF_SEL(value)  Voltage Reference Selection 
 *    SUPC_VREF_SEL_1V0  1.0V voltage reference typical value 
 *    SUPC_VREF_SEL_1V1  1.1V voltage reference typical value 
 *    SUPC_VREF_SEL_1V2  1.2V voltage reference typical value 
 *    SUPC_VREF_SEL_1V25  1.25V voltage reference typical value 
 *    SUPC_VREF_SEL_2V0  2.0V voltage reference typical value 
 *    SUPC_VREF_SEL_2V2  2.2V voltage reference typical value 
 *    SUPC_VREF_SEL_2V4  2.4V voltage reference typical value 
 *    SUPC_VREF_SEL_2V5  2.5V voltage reference typical value 
 */
static inline void supc_clear_VREF(uint32_t mask)
{
	SUPC->VREF.reg &= ~mask;
}

/**
 * @brief supc read VREF register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_VREF_TSEN  Temperature Sensor Output Enable 
 * SUPC_VREF_VREFOE  Voltage Reference Output Enable 
 * SUPC_VREF_TSSEL  Temperature Sensor Selection 
 * SUPC_VREF_RUNSTDBY  Run during Standby 
 * SUPC_VREF_ONDEMAND  On Demand Contrl 
 * SUPC_VREF_SEL(value)  Voltage Reference Selection 
 *    SUPC_VREF_SEL_1V0  1.0V voltage reference typical value 
 *    SUPC_VREF_SEL_1V1  1.1V voltage reference typical value 
 *    SUPC_VREF_SEL_1V2  1.2V voltage reference typical value 
 *    SUPC_VREF_SEL_1V25  1.25V voltage reference typical value 
 *    SUPC_VREF_SEL_2V0  2.0V voltage reference typical value 
 *    SUPC_VREF_SEL_2V2  2.2V voltage reference typical value 
 *    SUPC_VREF_SEL_2V4  2.4V voltage reference typical value 
 *    SUPC_VREF_SEL_2V5  2.5V voltage reference typical value 
 */
static inline uint32_t supc_read_VREF(void)
{
	return SUPC->VREF.reg;
}

/**
 * @brief supc set BBPS register
 *
 * @param[in] uint32_t mask
 * SUPC_BBPS_CONF  Battery Backup Configuration 
 *    SUPC_BBPS_CONF_BOD33  The power switch is handled by the BOD33 
 *    SUPC_BBPS_CONF_FORCED  In Backup Domain, the backup domain is always supplied by battery backup power 
 * SUPC_BBPS_WAKEEN  Wake Enable 
 */
static inline void supc_set_BBPS(uint32_t mask)
{
	SUPC->BBPS.reg |= mask;
}

/**
 * @brief supc get BBPS register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_BBPS_CONF  Battery Backup Configuration 
 *    SUPC_BBPS_CONF_BOD33  The power switch is handled by the BOD33 
 *    SUPC_BBPS_CONF_FORCED  In Backup Domain, the backup domain is always supplied by battery backup power 
 * SUPC_BBPS_WAKEEN  Wake Enable 
 */
static inline uint32_t supc_get_BBPS(uint32_t mask)
{
    return SUPC->BBPS.reg & mask;
}

/**
 * @brief supc write BBPS register
 *
 * @param[in] uint32_t data
 * SUPC_BBPS_CONF  Battery Backup Configuration 
 *    SUPC_BBPS_CONF_BOD33  The power switch is handled by the BOD33 
 *    SUPC_BBPS_CONF_FORCED  In Backup Domain, the backup domain is always supplied by battery backup power 
 * SUPC_BBPS_WAKEEN  Wake Enable 
 */
static inline void supc_write_BBPS(uint32_t data)
{
	SUPC->BBPS.reg = data;
}

/**
 * @brief supc clear BBPS register
 *
 * @param[in] uint32_t mask
 * SUPC_BBPS_CONF  Battery Backup Configuration 
 *    SUPC_BBPS_CONF_BOD33  The power switch is handled by the BOD33 
 *    SUPC_BBPS_CONF_FORCED  In Backup Domain, the backup domain is always supplied by battery backup power 
 * SUPC_BBPS_WAKEEN  Wake Enable 
 */
static inline void supc_clear_BBPS(uint32_t mask)
{
	SUPC->BBPS.reg &= ~mask;
}

/**
 * @brief supc read BBPS register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_BBPS_CONF  Battery Backup Configuration 
 *    SUPC_BBPS_CONF_BOD33  The power switch is handled by the BOD33 
 *    SUPC_BBPS_CONF_FORCED  In Backup Domain, the backup domain is always supplied by battery backup power 
 * SUPC_BBPS_WAKEEN  Wake Enable 
 */
static inline uint32_t supc_read_BBPS(void)
{
	return SUPC->BBPS.reg;
}

/**
 * @brief supc set BKOUT register
 *
 * @param[in] uint32_t mask
 * SUPC_BKOUT_EN(value)  Enable Output 
 * SUPC_BKOUT_CLR(value)  Clear Output 
 * SUPC_BKOUT_SET(value)  Set Output 
 * SUPC_BKOUT_RTCTGL(value)  RTC Toggle Output 
 */
static inline void supc_set_BKOUT(uint32_t mask)
{
	SUPC->BKOUT.reg |= mask;
}

/**
 * @brief supc get BKOUT register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_BKOUT_EN(value)  Enable Output 
 * SUPC_BKOUT_CLR(value)  Clear Output 
 * SUPC_BKOUT_SET(value)  Set Output 
 * SUPC_BKOUT_RTCTGL(value)  RTC Toggle Output 
 */
static inline uint32_t supc_get_BKOUT(uint32_t mask)
{
    return SUPC->BKOUT.reg & mask;
}

/**
 * @brief supc write BKOUT register
 *
 * @param[in] uint32_t data
 * SUPC_BKOUT_EN(value)  Enable Output 
 * SUPC_BKOUT_CLR(value)  Clear Output 
 * SUPC_BKOUT_SET(value)  Set Output 
 * SUPC_BKOUT_RTCTGL(value)  RTC Toggle Output 
 */
static inline void supc_write_BKOUT(uint32_t data)
{
	SUPC->BKOUT.reg = data;
}

/**
 * @brief supc clear BKOUT register
 *
 * @param[in] uint32_t mask
 * SUPC_BKOUT_EN(value)  Enable Output 
 * SUPC_BKOUT_CLR(value)  Clear Output 
 * SUPC_BKOUT_SET(value)  Set Output 
 * SUPC_BKOUT_RTCTGL(value)  RTC Toggle Output 
 */
static inline void supc_clear_BKOUT(uint32_t mask)
{
	SUPC->BKOUT.reg &= ~mask;
}

/**
 * @brief supc read BKOUT register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_BKOUT_EN(value)  Enable Output 
 * SUPC_BKOUT_CLR(value)  Clear Output 
 * SUPC_BKOUT_SET(value)  Set Output 
 * SUPC_BKOUT_RTCTGL(value)  RTC Toggle Output 
 */
static inline uint32_t supc_read_BKOUT(void)
{
	return SUPC->BKOUT.reg;
}

/**
 * @brief supc get STATUS register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_STATUS_BOD33RDY  BOD33 Ready 
 * SUPC_STATUS_BOD33DET  BOD33 Detection 
 * SUPC_STATUS_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_STATUS_BOD12RDY  BOD12 Ready 
 * SUPC_STATUS_BOD12DET  BOD12 Detection 
 * SUPC_STATUS_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_STATUS_VREGRDY  Voltage Regulator Ready 
 * SUPC_STATUS_VCORERDY  VDDCORE Ready 
 */
static inline uint32_t supc_get_STATUS(uint32_t mask)
{
    return SUPC->STATUS.reg & mask;
}

/**
 * @brief supc read STATUS register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_STATUS_BOD33RDY  BOD33 Ready 
 * SUPC_STATUS_BOD33DET  BOD33 Detection 
 * SUPC_STATUS_B33SRDY  BOD33 Synchronization Ready 
 * SUPC_STATUS_BOD12RDY  BOD12 Ready 
 * SUPC_STATUS_BOD12DET  BOD12 Detection 
 * SUPC_STATUS_B12SRDY  BOD12 Synchronization Ready 
 * SUPC_STATUS_VREGRDY  Voltage Regulator Ready 
 * SUPC_STATUS_VCORERDY  VDDCORE Ready 
 */
static inline uint32_t supc_read_STATUS(void)
{
	return SUPC->STATUS.reg;
}

/**
 * @brief supc get BKIN register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * SUPC_BKIN_BKIN(value)  Backup Input Value 
 */
static inline uint32_t supc_get_BKIN(uint32_t mask)
{
    return SUPC->BKIN.reg & mask;
}

/**
 * @brief supc read BKIN register
 *
 * @param[in] void
 * @return uint32_t
 * SUPC_BKIN_BKIN(value)  Backup Input Value 
 */
static inline uint32_t supc_read_BKIN(void)
{
	return SUPC->BKIN.reg;
}

#endif /* _SUPC_H */
