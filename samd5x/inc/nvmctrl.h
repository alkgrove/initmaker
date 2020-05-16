/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM NVMCTRL
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

#ifndef _NVMCTRL_H_
#define _NVMCTRL_H_

#include <stdbool.h>
#include <stdint.h>
#define FLASH_BLOCK_WRITE_OK 0
#define FLASH_PAGE_WRITE_OK 0
#define FLASH_BAD_BLOCK_ADDRESS -1
#define FLASH_BAD_PAGE_ADDRESS -1

#ifdef FEATURE_BANK_SWITCH
#define RECORDBLOCK_ADDR ((FLASH_ADDR + (FLASH_SIZE/2)) - NVMCTRL_BLOCK_SIZE)
#else
#define RECORDBLOCK_ADDR ((FLASH_ADDR + FLASH_SIZE) - NVMCTRL_BLOCK_SIZE)
#endif
#define RECORD_SIZE 64

/**
 * @brief nvmctrl set INTEN register
 *
 * @param[in] mask uint16_t 
 * - NVMCTRL_INTENSET_DONE Command Done Interrupt Enable
 * - NVMCTRL_INTENSET_ADDRE Address Error Interrupt Enable
 * - NVMCTRL_INTENSET_PROGE Programming Error Interrupt Enable
 * - NVMCTRL_INTENSET_LOCKE Lock Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCSE ECC Single Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCDE ECC Dual Error Interrupt Enable
 * - NVMCTRL_INTENSET_NVME NVM Error Interrupt Enable
 * - NVMCTRL_INTENSET_SUSP Suspended Write Or Erase  Interrupt Enable
 * - NVMCTRL_INTENSET_SEESFULL Active SEES Full Interrupt Enable
 * - NVMCTRL_INTENSET_SEESOVF Active SEES Overflow Interrupt Enable
 * - NVMCTRL_INTENSET_SEEWRC SEE Write Completed Interrupt Enable
 **/
static inline void nvmctrl_set_INTEN(uint16_t mask)
{
	NVMCTRL->INTENSET.reg = mask;
}

/**
 * @brief nvmctrl get INTEN register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - NVMCTRL_INTENSET_DONE Command Done Interrupt Enable
 * - NVMCTRL_INTENSET_ADDRE Address Error Interrupt Enable
 * - NVMCTRL_INTENSET_PROGE Programming Error Interrupt Enable
 * - NVMCTRL_INTENSET_LOCKE Lock Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCSE ECC Single Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCDE ECC Dual Error Interrupt Enable
 * - NVMCTRL_INTENSET_NVME NVM Error Interrupt Enable
 * - NVMCTRL_INTENSET_SUSP Suspended Write Or Erase  Interrupt Enable
 * - NVMCTRL_INTENSET_SEESFULL Active SEES Full Interrupt Enable
 * - NVMCTRL_INTENSET_SEESOVF Active SEES Overflow Interrupt Enable
 * - NVMCTRL_INTENSET_SEEWRC SEE Write Completed Interrupt Enable
 **/
static inline uint16_t nvmctrl_get_INTEN(uint16_t mask)
{
    return NVMCTRL->INTENSET.reg & mask;
}

/**
 * @brief nvmctrl read INTEN register
 *
 * @return uint16_t
 * - NVMCTRL_INTENSET_DONE Command Done Interrupt Enable
 * - NVMCTRL_INTENSET_ADDRE Address Error Interrupt Enable
 * - NVMCTRL_INTENSET_PROGE Programming Error Interrupt Enable
 * - NVMCTRL_INTENSET_LOCKE Lock Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCSE ECC Single Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCDE ECC Dual Error Interrupt Enable
 * - NVMCTRL_INTENSET_NVME NVM Error Interrupt Enable
 * - NVMCTRL_INTENSET_SUSP Suspended Write Or Erase  Interrupt Enable
 * - NVMCTRL_INTENSET_SEESFULL Active SEES Full Interrupt Enable
 * - NVMCTRL_INTENSET_SEESOVF Active SEES Overflow Interrupt Enable
 * - NVMCTRL_INTENSET_SEEWRC SEE Write Completed Interrupt Enable
 **/
static inline uint16_t nvmctrl_read_INTEN(void)
{
	return NVMCTRL->INTENSET.reg;
}

/**
 * @brief nvmctrl write INTEN register
 *
 * @param[in] data uint16_t 
 * - NVMCTRL_INTENSET_DONE Command Done Interrupt Enable
 * - NVMCTRL_INTENSET_ADDRE Address Error Interrupt Enable
 * - NVMCTRL_INTENSET_PROGE Programming Error Interrupt Enable
 * - NVMCTRL_INTENSET_LOCKE Lock Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCSE ECC Single Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCDE ECC Dual Error Interrupt Enable
 * - NVMCTRL_INTENSET_NVME NVM Error Interrupt Enable
 * - NVMCTRL_INTENSET_SUSP Suspended Write Or Erase  Interrupt Enable
 * - NVMCTRL_INTENSET_SEESFULL Active SEES Full Interrupt Enable
 * - NVMCTRL_INTENSET_SEESOVF Active SEES Overflow Interrupt Enable
 * - NVMCTRL_INTENSET_SEEWRC SEE Write Completed Interrupt Enable
 **/
static inline void nvmctrl_write_INTEN(uint16_t data)
{
	NVMCTRL->INTENSET.reg = data;
	NVMCTRL->INTENCLR.reg = ~data;
}

/**
 * @brief nvmctrl clear INTEN register
 *
 * @param[in] mask uint16_t 
 * - NVMCTRL_INTENSET_DONE Command Done Interrupt Enable
 * - NVMCTRL_INTENSET_ADDRE Address Error Interrupt Enable
 * - NVMCTRL_INTENSET_PROGE Programming Error Interrupt Enable
 * - NVMCTRL_INTENSET_LOCKE Lock Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCSE ECC Single Error Interrupt Enable
 * - NVMCTRL_INTENSET_ECCDE ECC Dual Error Interrupt Enable
 * - NVMCTRL_INTENSET_NVME NVM Error Interrupt Enable
 * - NVMCTRL_INTENSET_SUSP Suspended Write Or Erase  Interrupt Enable
 * - NVMCTRL_INTENSET_SEESFULL Active SEES Full Interrupt Enable
 * - NVMCTRL_INTENSET_SEESOVF Active SEES Overflow Interrupt Enable
 * - NVMCTRL_INTENSET_SEEWRC SEE Write Completed Interrupt Enable
 **/
static inline void nvmctrl_clear_INTEN(uint16_t mask)
{
	NVMCTRL->INTENCLR.reg = mask;
}

/**
 * @brief nvmctrl get INTFLAG register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - NVMCTRL_INTFLAG_DONE Command Done
 * - NVMCTRL_INTFLAG_ADDRE Address Error
 * - NVMCTRL_INTFLAG_PROGE Programming Error
 * - NVMCTRL_INTFLAG_LOCKE Lock Error
 * - NVMCTRL_INTFLAG_ECCSE ECC Single Error
 * - NVMCTRL_INTFLAG_ECCDE ECC Dual Error
 * - NVMCTRL_INTFLAG_NVME NVM Error
 * - NVMCTRL_INTFLAG_SUSP Suspended Write Or Erase Operation
 * - NVMCTRL_INTFLAG_SEESFULL Active SEES Full
 * - NVMCTRL_INTFLAG_SEESOVF Active SEES Overflow
 * - NVMCTRL_INTFLAG_SEEWRC SEE Write Completed
 **/
static inline uint16_t nvmctrl_get_INTFLAG(uint16_t mask)
{
    return NVMCTRL->INTFLAG.reg & mask;
}

/**
 * @brief nvmctrl read INTFLAG register
 *
 * @return uint16_t
 * - NVMCTRL_INTFLAG_DONE Command Done
 * - NVMCTRL_INTFLAG_ADDRE Address Error
 * - NVMCTRL_INTFLAG_PROGE Programming Error
 * - NVMCTRL_INTFLAG_LOCKE Lock Error
 * - NVMCTRL_INTFLAG_ECCSE ECC Single Error
 * - NVMCTRL_INTFLAG_ECCDE ECC Dual Error
 * - NVMCTRL_INTFLAG_NVME NVM Error
 * - NVMCTRL_INTFLAG_SUSP Suspended Write Or Erase Operation
 * - NVMCTRL_INTFLAG_SEESFULL Active SEES Full
 * - NVMCTRL_INTFLAG_SEESOVF Active SEES Overflow
 * - NVMCTRL_INTFLAG_SEEWRC SEE Write Completed
 **/
static inline uint16_t nvmctrl_read_INTFLAG(void)
{
	return NVMCTRL->INTFLAG.reg;
}

/**
 * @brief nvmctrl clear INTFLAG register
 *
 * @param[in] mask uint16_t 
 * - NVMCTRL_INTFLAG_DONE Command Done
 * - NVMCTRL_INTFLAG_ADDRE Address Error
 * - NVMCTRL_INTFLAG_PROGE Programming Error
 * - NVMCTRL_INTFLAG_LOCKE Lock Error
 * - NVMCTRL_INTFLAG_ECCSE ECC Single Error
 * - NVMCTRL_INTFLAG_ECCDE ECC Dual Error
 * - NVMCTRL_INTFLAG_NVME NVM Error
 * - NVMCTRL_INTFLAG_SUSP Suspended Write Or Erase Operation
 * - NVMCTRL_INTFLAG_SEESFULL Active SEES Full
 * - NVMCTRL_INTFLAG_SEESOVF Active SEES Overflow
 * - NVMCTRL_INTFLAG_SEEWRC SEE Write Completed
 **/
static inline void nvmctrl_clear_INTFLAG(uint16_t mask)
{
	NVMCTRL->INTFLAG.reg = mask;
}

/**
 * @brief nvmctrl write CTRLB register
 *
 * @param[in] data uint16_t 
 * - NVMCTRL_CTRLB_CMD(value) Command
 *  +      NVMCTRL_CTRLB_CMD_EP Erase Page - Only supported in the USER and AUX pages.
 *  +      NVMCTRL_CTRLB_CMD_EB Erase Block - Erases the block addressed by the ADDR register, not supported in the user page
 *  +      NVMCTRL_CTRLB_CMD_WP Write Page - Writes the contents of the page buffer to the page addressed by the ADDR register, not supported in the user page
 *  +      NVMCTRL_CTRLB_CMD_WQW Write Quad Word - Writes a 128-bit word at the location addressed by the ADDR register.
 *  +      NVMCTRL_CTRLB_CMD_SWRST Software Reset - Power-Cycle the NVM memory and replay the device automatic calibration procedure and resets the module configuration registers
 *  +      NVMCTRL_CTRLB_CMD_LR Lock Region - Locks the region containing the address location in the ADDR register.
 *  +      NVMCTRL_CTRLB_CMD_UR Unlock Region - Unlocks the region containing the address location in the ADDR register.
 *  +      NVMCTRL_CTRLB_CMD_SPRM Sets the power reduction mode.
 *  +      NVMCTRL_CTRLB_CMD_CPRM Clears the power reduction mode.
 *  +      NVMCTRL_CTRLB_CMD_PBC Page Buffer Clear - Clears the page buffer.
 *  +      NVMCTRL_CTRLB_CMD_SSB Set Security Bit
 *  +      NVMCTRL_CTRLB_CMD_BKSWRST Bank swap and system reset, if SMEE is used also reallocate SMEE data into the opposite BANK
 *  +      NVMCTRL_CTRLB_CMD_CELCK Chip Erase Lock - DSU.CE command is not available
 *  +      NVMCTRL_CTRLB_CMD_CEULCK Chip Erase Unlock - DSU.CE command is available
 *  +      NVMCTRL_CTRLB_CMD_SBPDIS Sets STATUS.BPDIS, Boot loader protection is discarded until CBPDIS is issued or next start-up sequence
 *  +      NVMCTRL_CTRLB_CMD_CBPDIS Clears STATUS.BPDIS, Boot loader protection is not discarded
 *  +      NVMCTRL_CTRLB_CMD_ASEES0 Activate SmartEEPROM Sector 0, deactivate Sector 1
 *  +      NVMCTRL_CTRLB_CMD_ASEES1 Activate SmartEEPROM Sector 1, deactivate Sector 0
 *  +      NVMCTRL_CTRLB_CMD_SEERALOC Starts SmartEEPROM sector reallocation algorithm
 *  +      NVMCTRL_CTRLB_CMD_SEEFLUSH Flush SMEE data when in buffered mode
 *  +      NVMCTRL_CTRLB_CMD_LSEE Lock access to SmartEEPROM data from any mean
 *  +      NVMCTRL_CTRLB_CMD_USEE Unlock access to SmartEEPROM data
 *  +      NVMCTRL_CTRLB_CMD_LSEER Lock access to the SmartEEPROM Register Address Space (above 64KB)
 *  +      NVMCTRL_CTRLB_CMD_USEER Unlock access to the SmartEEPROM Register Address Space (above 64KB)
 * - NVMCTRL_CTRLB_CMDEX(value) Command Execution
 *  +      NVMCTRL_CTRLB_CMDEX_KEY Execution Key
 **/
static inline void nvmctrl_write_CTRLB(uint16_t data)
{
	NVMCTRL->CTRLB.reg = data;
}

/**
 * @brief nvmctrl set CTRLA register
 *
 * @param[in] mask uint16_t 
 * - NVMCTRL_CTRLA_AUTOWS Auto Wait State Enable
 * - NVMCTRL_CTRLA_SUSPEN Suspend Enable
 * - NVMCTRL_CTRLA_WMODE(value) Write Mode
 *  +      NVMCTRL_CTRLA_WMODE_MAN Manual Write
 *  +      NVMCTRL_CTRLA_WMODE_ADW Automatic Double Word Write
 *  +      NVMCTRL_CTRLA_WMODE_AQW Automatic Quad Word
 *  +      NVMCTRL_CTRLA_WMODE_AP Automatic Page Write
 * - NVMCTRL_CTRLA_PRM(value) Power Reduction Mode during Sleep
 *  +      NVMCTRL_CTRLA_PRM_SEMIAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 *  +      NVMCTRL_CTRLA_PRM_FULLAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode when system is not in standby mode.
 *  +      NVMCTRL_CTRLA_PRM_MANUAL NVM block does not enter low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 * - NVMCTRL_CTRLA_RWS(value) NVM Read Wait States
 * - NVMCTRL_CTRLA_AHBNS0 Force AHB0 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_AHBNS1 Force AHB1 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_CACHEDIS0 AHB0 Cache Disable
 * - NVMCTRL_CTRLA_CACHEDIS1 AHB1 Cache Disable
 **/
static inline void nvmctrl_set_CTRLA(uint16_t mask)
{
	NVMCTRL->CTRLA.reg |= mask;
}

/**
 * @brief nvmctrl get CTRLA register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - NVMCTRL_CTRLA_AUTOWS Auto Wait State Enable
 * - NVMCTRL_CTRLA_SUSPEN Suspend Enable
 * - NVMCTRL_CTRLA_WMODE(value) Write Mode
 *  +      NVMCTRL_CTRLA_WMODE_MAN Manual Write
 *  +      NVMCTRL_CTRLA_WMODE_ADW Automatic Double Word Write
 *  +      NVMCTRL_CTRLA_WMODE_AQW Automatic Quad Word
 *  +      NVMCTRL_CTRLA_WMODE_AP Automatic Page Write
 * - NVMCTRL_CTRLA_PRM(value) Power Reduction Mode during Sleep
 *  +      NVMCTRL_CTRLA_PRM_SEMIAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 *  +      NVMCTRL_CTRLA_PRM_FULLAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode when system is not in standby mode.
 *  +      NVMCTRL_CTRLA_PRM_MANUAL NVM block does not enter low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 * - NVMCTRL_CTRLA_RWS(value) NVM Read Wait States
 * - NVMCTRL_CTRLA_AHBNS0 Force AHB0 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_AHBNS1 Force AHB1 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_CACHEDIS0 AHB0 Cache Disable
 * - NVMCTRL_CTRLA_CACHEDIS1 AHB1 Cache Disable
 **/
static inline uint16_t nvmctrl_get_CTRLA(uint16_t mask)
{
    return NVMCTRL->CTRLA.reg & mask;
}

/**
 * @brief nvmctrl write CTRLA register
 *
 * @param[in] data uint16_t 
 * - NVMCTRL_CTRLA_AUTOWS Auto Wait State Enable
 * - NVMCTRL_CTRLA_SUSPEN Suspend Enable
 * - NVMCTRL_CTRLA_WMODE(value) Write Mode
 *  +      NVMCTRL_CTRLA_WMODE_MAN Manual Write
 *  +      NVMCTRL_CTRLA_WMODE_ADW Automatic Double Word Write
 *  +      NVMCTRL_CTRLA_WMODE_AQW Automatic Quad Word
 *  +      NVMCTRL_CTRLA_WMODE_AP Automatic Page Write
 * - NVMCTRL_CTRLA_PRM(value) Power Reduction Mode during Sleep
 *  +      NVMCTRL_CTRLA_PRM_SEMIAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 *  +      NVMCTRL_CTRLA_PRM_FULLAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode when system is not in standby mode.
 *  +      NVMCTRL_CTRLA_PRM_MANUAL NVM block does not enter low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 * - NVMCTRL_CTRLA_RWS(value) NVM Read Wait States
 * - NVMCTRL_CTRLA_AHBNS0 Force AHB0 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_AHBNS1 Force AHB1 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_CACHEDIS0 AHB0 Cache Disable
 * - NVMCTRL_CTRLA_CACHEDIS1 AHB1 Cache Disable
 **/
static inline void nvmctrl_write_CTRLA(uint16_t data)
{
	NVMCTRL->CTRLA.reg = data;
}

/**
 * @brief nvmctrl clear CTRLA register
 *
 * @param[in] mask uint16_t 
 * - NVMCTRL_CTRLA_AUTOWS Auto Wait State Enable
 * - NVMCTRL_CTRLA_SUSPEN Suspend Enable
 * - NVMCTRL_CTRLA_WMODE(value) Write Mode
 *  +      NVMCTRL_CTRLA_WMODE_MAN Manual Write
 *  +      NVMCTRL_CTRLA_WMODE_ADW Automatic Double Word Write
 *  +      NVMCTRL_CTRLA_WMODE_AQW Automatic Quad Word
 *  +      NVMCTRL_CTRLA_WMODE_AP Automatic Page Write
 * - NVMCTRL_CTRLA_PRM(value) Power Reduction Mode during Sleep
 *  +      NVMCTRL_CTRLA_PRM_SEMIAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 *  +      NVMCTRL_CTRLA_PRM_FULLAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode when system is not in standby mode.
 *  +      NVMCTRL_CTRLA_PRM_MANUAL NVM block does not enter low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 * - NVMCTRL_CTRLA_RWS(value) NVM Read Wait States
 * - NVMCTRL_CTRLA_AHBNS0 Force AHB0 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_AHBNS1 Force AHB1 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_CACHEDIS0 AHB0 Cache Disable
 * - NVMCTRL_CTRLA_CACHEDIS1 AHB1 Cache Disable
 **/
static inline void nvmctrl_clear_CTRLA(uint16_t mask)
{
	NVMCTRL->CTRLA.reg &= ~mask;
}

/**
 * @brief nvmctrl read CTRLA register
 *
 * @return uint16_t
 * - NVMCTRL_CTRLA_AUTOWS Auto Wait State Enable
 * - NVMCTRL_CTRLA_SUSPEN Suspend Enable
 * - NVMCTRL_CTRLA_WMODE(value) Write Mode
 *  +      NVMCTRL_CTRLA_WMODE_MAN Manual Write
 *  +      NVMCTRL_CTRLA_WMODE_ADW Automatic Double Word Write
 *  +      NVMCTRL_CTRLA_WMODE_AQW Automatic Quad Word
 *  +      NVMCTRL_CTRLA_WMODE_AP Automatic Page Write
 * - NVMCTRL_CTRLA_PRM(value) Power Reduction Mode during Sleep
 *  +      NVMCTRL_CTRLA_PRM_SEMIAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 *  +      NVMCTRL_CTRLA_PRM_FULLAUTO NVM block enters low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode when system is not in standby mode.
 *  +      NVMCTRL_CTRLA_PRM_MANUAL NVM block does not enter low-power mode when entering standby mode. NVM block enters low-power mode when SPRM command is issued. NVM block exits low-power mode upon first access.
 * - NVMCTRL_CTRLA_RWS(value) NVM Read Wait States
 * - NVMCTRL_CTRLA_AHBNS0 Force AHB0 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_AHBNS1 Force AHB1 access to NONSEQ, burst transfers are continuously rearbitrated
 * - NVMCTRL_CTRLA_CACHEDIS0 AHB0 Cache Disable
 * - NVMCTRL_CTRLA_CACHEDIS1 AHB1 Cache Disable
 **/
static inline uint16_t nvmctrl_read_CTRLA(void)
{
	return NVMCTRL->CTRLA.reg;
}

/**
 * @brief nvmctrl write ADDR register
 *
 * @param[in] data uint32_t 
 * - NVMCTRL_ADDR_ADDR(value) NVM Address
 **/
static inline void nvmctrl_write_ADDR(uint32_t data)
{
	NVMCTRL->ADDR.reg = data;
}

/**
 * @brief nvmctrl read ADDR register
 *
 * @return uint32_t
 * - NVMCTRL_ADDR_ADDR(value) NVM Address
 **/
static inline uint32_t nvmctrl_read_ADDR(void)
{
	return NVMCTRL->ADDR.reg;
}

/**
 * @brief nvmctrl set DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - NVMCTRL_DBGCTRL_ECCDIS Debugger ECC Read Disable
 * - NVMCTRL_DBGCTRL_ECCELOG Debugger ECC Error Tracking Mode
 **/
static inline void nvmctrl_set_DBGCTRL(uint8_t mask)
{
	NVMCTRL->DBGCTRL.reg |= mask;
}

/**
 * @brief nvmctrl get DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - NVMCTRL_DBGCTRL_ECCDIS Debugger ECC Read Disable
 * - NVMCTRL_DBGCTRL_ECCELOG Debugger ECC Error Tracking Mode
 **/
static inline uint8_t nvmctrl_get_DBGCTRL(uint8_t mask)
{
    return NVMCTRL->DBGCTRL.reg & mask;
}

/**
 * @brief nvmctrl write DBGCTRL register
 *
 * @param[in] data uint8_t 
 * - NVMCTRL_DBGCTRL_ECCDIS Debugger ECC Read Disable
 * - NVMCTRL_DBGCTRL_ECCELOG Debugger ECC Error Tracking Mode
 **/
static inline void nvmctrl_write_DBGCTRL(uint8_t data)
{
	NVMCTRL->DBGCTRL.reg = data;
}

/**
 * @brief nvmctrl clear DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - NVMCTRL_DBGCTRL_ECCDIS Debugger ECC Read Disable
 * - NVMCTRL_DBGCTRL_ECCELOG Debugger ECC Error Tracking Mode
 **/
static inline void nvmctrl_clear_DBGCTRL(uint8_t mask)
{
	NVMCTRL->DBGCTRL.reg &= ~mask;
}

/**
 * @brief nvmctrl read DBGCTRL register
 *
 * @return uint8_t
 * - NVMCTRL_DBGCTRL_ECCDIS Debugger ECC Read Disable
 * - NVMCTRL_DBGCTRL_ECCELOG Debugger ECC Error Tracking Mode
 **/
static inline uint8_t nvmctrl_read_DBGCTRL(void)
{
	return NVMCTRL->DBGCTRL.reg;
}

/**
 * @brief nvmctrl set SEECFG register
 *
 * @param[in] mask uint8_t 
 * - NVMCTRL_SEECFG_WMODE Write Mode
 *  +      NVMCTRL_SEECFG_WMODE_UNBUFFERED A NVM write command is issued after each write in the pagebuffer
 *  +      NVMCTRL_SEECFG_WMODE_BUFFERED A NVM write command is issued when a write to a new page is requested
 * - NVMCTRL_SEECFG_APRDIS Automatic Page Reallocation Disable
 **/
static inline void nvmctrl_set_SEECFG(uint8_t mask)
{
	NVMCTRL->SEECFG.reg |= mask;
}

/**
 * @brief nvmctrl get SEECFG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - NVMCTRL_SEECFG_WMODE Write Mode
 *  +      NVMCTRL_SEECFG_WMODE_UNBUFFERED A NVM write command is issued after each write in the pagebuffer
 *  +      NVMCTRL_SEECFG_WMODE_BUFFERED A NVM write command is issued when a write to a new page is requested
 * - NVMCTRL_SEECFG_APRDIS Automatic Page Reallocation Disable
 **/
static inline uint8_t nvmctrl_get_SEECFG(uint8_t mask)
{
    return NVMCTRL->SEECFG.reg & mask;
}

/**
 * @brief nvmctrl write SEECFG register
 *
 * @param[in] data uint8_t 
 * - NVMCTRL_SEECFG_WMODE Write Mode
 *  +      NVMCTRL_SEECFG_WMODE_UNBUFFERED A NVM write command is issued after each write in the pagebuffer
 *  +      NVMCTRL_SEECFG_WMODE_BUFFERED A NVM write command is issued when a write to a new page is requested
 * - NVMCTRL_SEECFG_APRDIS Automatic Page Reallocation Disable
 **/
static inline void nvmctrl_write_SEECFG(uint8_t data)
{
	NVMCTRL->SEECFG.reg = data;
}

/**
 * @brief nvmctrl clear SEECFG register
 *
 * @param[in] mask uint8_t 
 * - NVMCTRL_SEECFG_WMODE Write Mode
 *  +      NVMCTRL_SEECFG_WMODE_UNBUFFERED A NVM write command is issued after each write in the pagebuffer
 *  +      NVMCTRL_SEECFG_WMODE_BUFFERED A NVM write command is issued when a write to a new page is requested
 * - NVMCTRL_SEECFG_APRDIS Automatic Page Reallocation Disable
 **/
static inline void nvmctrl_clear_SEECFG(uint8_t mask)
{
	NVMCTRL->SEECFG.reg &= ~mask;
}

/**
 * @brief nvmctrl read SEECFG register
 *
 * @return uint8_t
 * - NVMCTRL_SEECFG_WMODE Write Mode
 *  +      NVMCTRL_SEECFG_WMODE_UNBUFFERED A NVM write command is issued after each write in the pagebuffer
 *  +      NVMCTRL_SEECFG_WMODE_BUFFERED A NVM write command is issued when a write to a new page is requested
 * - NVMCTRL_SEECFG_APRDIS Automatic Page Reallocation Disable
 **/
static inline uint8_t nvmctrl_read_SEECFG(void)
{
	return NVMCTRL->SEECFG.reg;
}

/**
 * @brief nvmctrl get PARAM register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - NVMCTRL_PARAM_NVMP(value) NVM Pages
 * - NVMCTRL_PARAM_PSZ(value) Page Size
 *  +      NVMCTRL_PARAM_PSZ_8 8 bytes
 *  +      NVMCTRL_PARAM_PSZ_16 16 bytes
 *  +      NVMCTRL_PARAM_PSZ_32 32 bytes
 *  +      NVMCTRL_PARAM_PSZ_64 64 bytes
 *  +      NVMCTRL_PARAM_PSZ_128 128 bytes
 *  +      NVMCTRL_PARAM_PSZ_256 256 bytes
 *  +      NVMCTRL_PARAM_PSZ_512 512 bytes
 *  +      NVMCTRL_PARAM_PSZ_1024 1024 bytes
 * - NVMCTRL_PARAM_SEE SmartEEPROM Supported
 **/
static inline uint32_t nvmctrl_get_PARAM(uint32_t mask)
{
    return NVMCTRL->PARAM.reg & mask;
}

/**
 * @brief nvmctrl read PARAM register
 *
 * @return uint32_t
 * - NVMCTRL_PARAM_NVMP(value) NVM Pages
 * - NVMCTRL_PARAM_PSZ(value) Page Size
 *  +      NVMCTRL_PARAM_PSZ_8 8 bytes
 *  +      NVMCTRL_PARAM_PSZ_16 16 bytes
 *  +      NVMCTRL_PARAM_PSZ_32 32 bytes
 *  +      NVMCTRL_PARAM_PSZ_64 64 bytes
 *  +      NVMCTRL_PARAM_PSZ_128 128 bytes
 *  +      NVMCTRL_PARAM_PSZ_256 256 bytes
 *  +      NVMCTRL_PARAM_PSZ_512 512 bytes
 *  +      NVMCTRL_PARAM_PSZ_1024 1024 bytes
 * - NVMCTRL_PARAM_SEE SmartEEPROM Supported
 **/
static inline uint32_t nvmctrl_read_PARAM(void)
{
	return NVMCTRL->PARAM.reg;
}

/**
 * @brief nvmctrl get STATUS register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - NVMCTRL_STATUS_READY Ready to accept a command
 * - NVMCTRL_STATUS_PRM Power Reduction Mode
 * - NVMCTRL_STATUS_LOAD NVM Page Buffer Active Loading
 * - NVMCTRL_STATUS_SUSP NVM Write Or Erase Operation Is Suspended
 * - NVMCTRL_STATUS_AFIRST BANKA First
 * - NVMCTRL_STATUS_BPDIS Boot Loader Protection Disable
 * - NVMCTRL_STATUS_BOOTPROT(value) Boot Loader Protection Size
 **/
static inline uint16_t nvmctrl_get_STATUS(uint16_t mask)
{
    return NVMCTRL->STATUS.reg & mask;
}

/**
 * @brief nvmctrl read STATUS register
 *
 * @return uint16_t
 * - NVMCTRL_STATUS_READY Ready to accept a command
 * - NVMCTRL_STATUS_PRM Power Reduction Mode
 * - NVMCTRL_STATUS_LOAD NVM Page Buffer Active Loading
 * - NVMCTRL_STATUS_SUSP NVM Write Or Erase Operation Is Suspended
 * - NVMCTRL_STATUS_AFIRST BANKA First
 * - NVMCTRL_STATUS_BPDIS Boot Loader Protection Disable
 * - NVMCTRL_STATUS_BOOTPROT(value) Boot Loader Protection Size
 **/
static inline uint16_t nvmctrl_read_STATUS(void)
{
	return NVMCTRL->STATUS.reg;
}

/**
 * @brief nvmctrl get RUNLOCK register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - NVMCTRL_RUNLOCK_RUNLOCK(value) Region Un-Lock Bits
 **/
static inline uint32_t nvmctrl_get_RUNLOCK(uint32_t mask)
{
    return NVMCTRL->RUNLOCK.reg & mask;
}

/**
 * @brief nvmctrl read RUNLOCK register
 *
 * @return uint32_t
 * - NVMCTRL_RUNLOCK_RUNLOCK(value) Region Un-Lock Bits
 **/
static inline uint32_t nvmctrl_read_RUNLOCK(void)
{
	return NVMCTRL->RUNLOCK.reg;
}

/**
 * @brief nvmctrl read PBLDATA register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - NVMCTRL_PBLDATA_DATA(value) Page Buffer Data
 **/
static inline uint32_t nvmctrl_read_PBLDATA(uint8_t index)
{
	return NVMCTRL->PBLDATA[index].reg;
}

/**
 * @brief nvmctrl get ECCERR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - NVMCTRL_ECCERR_ADDR(value) Error Address
 * - NVMCTRL_ECCERR_TYPEL(value) Low Double-Word Error Type
 *  +      NVMCTRL_ECCERR_TYPEL_NONE No Error Detected Since Last Read
 *  +      NVMCTRL_ECCERR_TYPEL_SINGLE At Least One Single Error Detected Since last Read
 *  +      NVMCTRL_ECCERR_TYPEL_DUAL At Least One Dual Error Detected Since Last Read
 * - NVMCTRL_ECCERR_TYPEH(value) High Double-Word Error Type
 *  +      NVMCTRL_ECCERR_TYPEH_NONE No Error Detected Since Last Read
 *  +      NVMCTRL_ECCERR_TYPEH_SINGLE At Least One Single Error Detected Since last Read
 *  +      NVMCTRL_ECCERR_TYPEH_DUAL At Least One Dual Error Detected Since Last Read
 **/
static inline uint32_t nvmctrl_get_ECCERR(uint32_t mask)
{
    return NVMCTRL->ECCERR.reg & mask;
}

/**
 * @brief nvmctrl read ECCERR register
 *
 * @return uint32_t
 * - NVMCTRL_ECCERR_ADDR(value) Error Address
 * - NVMCTRL_ECCERR_TYPEL(value) Low Double-Word Error Type
 *  +      NVMCTRL_ECCERR_TYPEL_NONE No Error Detected Since Last Read
 *  +      NVMCTRL_ECCERR_TYPEL_SINGLE At Least One Single Error Detected Since last Read
 *  +      NVMCTRL_ECCERR_TYPEL_DUAL At Least One Dual Error Detected Since Last Read
 * - NVMCTRL_ECCERR_TYPEH(value) High Double-Word Error Type
 *  +      NVMCTRL_ECCERR_TYPEH_NONE No Error Detected Since Last Read
 *  +      NVMCTRL_ECCERR_TYPEH_SINGLE At Least One Single Error Detected Since last Read
 *  +      NVMCTRL_ECCERR_TYPEH_DUAL At Least One Dual Error Detected Since Last Read
 **/
static inline uint32_t nvmctrl_read_ECCERR(void)
{
	return NVMCTRL->ECCERR.reg;
}

/**
 * @brief nvmctrl get SEESTAT register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - NVMCTRL_SEESTAT_ASEES Active SmartEEPROM Sector
 * - NVMCTRL_SEESTAT_LOAD Page Buffer Loaded
 * - NVMCTRL_SEESTAT_BUSY Busy
 * - NVMCTRL_SEESTAT_LOCK SmartEEPROM Write Access Is Locked
 * - NVMCTRL_SEESTAT_RLOCK SmartEEPROM Write Access To Register Address Space Is Locked
 * - NVMCTRL_SEESTAT_SBLK(value) Blocks Number In a Sector
 * - NVMCTRL_SEESTAT_PSZ(value) SmartEEPROM Page Size
 **/
static inline uint32_t nvmctrl_get_SEESTAT(uint32_t mask)
{
    return NVMCTRL->SEESTAT.reg & mask;
}

/**
 * @brief nvmctrl read SEESTAT register
 *
 * @return uint32_t
 * - NVMCTRL_SEESTAT_ASEES Active SmartEEPROM Sector
 * - NVMCTRL_SEESTAT_LOAD Page Buffer Loaded
 * - NVMCTRL_SEESTAT_BUSY Busy
 * - NVMCTRL_SEESTAT_LOCK SmartEEPROM Write Access Is Locked
 * - NVMCTRL_SEESTAT_RLOCK SmartEEPROM Write Access To Register Address Space Is Locked
 * - NVMCTRL_SEESTAT_SBLK(value) Blocks Number In a Sector
 * - NVMCTRL_SEESTAT_PSZ(value) SmartEEPROM Page Size
 **/
static inline uint32_t nvmctrl_read_SEESTAT(void)
{
	return NVMCTRL->SEESTAT.reg;
}
/**
 * @brief nvmctrl wait for ready
 *
 **/
static inline void nvm_wait_ready(void)
{
	while(nvmctrl_get_STATUS(NVMCTRL_STATUS_READY) == 0);
}


/**
 * @brief write quadword
 * @detail write four 32 bit words to flash. Must add source nvm.c to use
 * dst must be aligned on 16 byte boundary
 * @param[in] uint32_t *dst pointer to main flash aligned to 16 bytes
 * @param[in] uint32_t *src pointer to four 32 bit words to write
 * @return int error FLASH_BLOCK_WRITE_OK or FLASH_BAD_BLOCK_ADDRESS
 */
 int nvm_write_quadword(uint32_t *dst, uint32_t *src);

/**
 * @brief write_block
 * @detail must insure erased before using. Must add source nvm.c to use
 * src must be 32 bit aligned buffer that is NVMCTRL_BLOCK_SIZE big 
 * dst must be aligned on NVMCTRL_BLOCK_SIZE boundary
 * @param[in] uint32_t *dst pointer to main flash aligned to NVMCTRL_BLOCK_SIZE
 * @param[in] uint32_t *src pointer to source buffer 32bit aligned 
 * @return int error FLASH_BLOCK_WRITE_OK or FLASH_BAD_BLOCK_ADDRESS
 */
int nvm_write_block(uint32_t *dst, uint32_t *src);

/**
 * @brief nvm_verify_block
 * @detail compare main flash pointed to by dst to sram buffer pointed to by src
 * @param[in] uint32_t *src
 * @param[in] uint32_t *dst
 * @return bool true if match false if not same
 */
bool nvm_verify_block(uint32_t *src, uint32_t *dst);

/**
 * @brief nvm_is_block_erased
 * @detail scan block to see if it is already erased
 * @param[in] uint32_t *src pointer to block to test, must be aligned to 8192 byte boundary
 * @return bool true if erased false if dirty
 */
bool nvm_is_block_erased(uint32_t *src);

/**
 * @brief nvm_erase_block
 * @detail erase 8192 byte block of memory pointed to by dst.
 * This must be done to the same dst prior to calling nvm_write_block or nvm_write_quadword
 * @param[in] uint32_t *dst must be aligned to 8192 byte boundary
 */
void nvm_erase_block(uint32_t *dst);

/*
 * @brief nvm_write_page
 * @detail must insure erased before using. Must add source nvm.c to use
 * src mustbe 32 bit aligned buffer that is NVMCTRL_PAGE_SIZE big
 * dst must be aligned on NVMCTRL_PAGE_SIZE boundary
 * @param[in] uint32_t *dst pointer to main flash aligned to NVMCTRL_BLOCK_SIZE
 * @param[in] uint32_t *src pointer to source buffer 32bit aligned 
 * @return int error FLASH_BLOCK_WRITE_OK or FLASH_BAD_BLOCK_ADDRESS
 */
 int nvm_write_page(uint32_t *dst, uint32_t *src);

 /*
  * @brief nvm_on_block_boundary(uint32_t *src)
  * @param[in] uint32_t *src pointer to memory
  * @return bool returns true if on block boundary false otherwise
  */
static inline bool nvm_on_block_boundary(uint32_t *src)
{
    return (((uint32_t)src & (NVMCTRL_BLOCK_SIZE - 1)) == 0);
}

/*
  * @brief nvm_on_page_boundary(uint32_t *src)
  * @param[in] uint32_t *src pointer to memory
  * @return bool returns true if on page boundary false otherwise
  */
static inline bool nvm_on_page_boundary(uint32_t *src)
{
    return (((uint32_t)src & (NVMCTRL_PAGE_SIZE - 1)) == 0);
}
/*
 * @brief getRecord()
 * @return uint8_t * return pointer to the most current record
 */
uint8_t *getRecord(void);
/*
  * @brief writeRecord
  * @detail write's a record to the next available slot, erases the block if no more slots available
  * @param[in] uint32_t *src pointer to memory to write
  */
void writeRecord(uint8_t *src);


#endif /* _NVMCTRL_H */
