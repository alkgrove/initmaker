/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM DSU
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _DSU_H_
#define _DSU_H_

#include <stdbool.h>

/**
 * @brief dsu get STATUSB register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - DSU_STATUSB_PROT Protected
 * - DSU_STATUSB_DBGPRES Debugger Present
 * - DSU_STATUSB_DCCD0 Debug Communication Channel 0 Dirty
 * - DSU_STATUSB_DCCD1 Debug Communication Channel 1 Dirty
 * - DSU_STATUSB_DCCD(value) Debug Communication Channel x Dirty
 * - DSU_STATUSB_HPE Hot-Plugging Enable
 * - DSU_STATUSB_CELCK Chip Erase Locked
 * - DSU_STATUSB_TDCCD0 Test Debug Communication Channel 0 Dirty
 * - DSU_STATUSB_TDCCD1 Test Debug Communication Channel 1 Dirty
 * - DSU_STATUSB_TDCCD(value) Test Debug Communication Channel x Dirty
 **/
static inline uint8_t dsu_get_STATUSB(uint8_t mask)
{
    return DSU->STATUSB.reg & mask;
}

/**
 * @brief dsu read STATUSB register
 *
 * @return uint8_t
 * - DSU_STATUSB_PROT Protected
 * - DSU_STATUSB_DBGPRES Debugger Present
 * - DSU_STATUSB_DCCD0 Debug Communication Channel 0 Dirty
 * - DSU_STATUSB_DCCD1 Debug Communication Channel 1 Dirty
 * - DSU_STATUSB_DCCD(value) Debug Communication Channel x Dirty
 * - DSU_STATUSB_HPE Hot-Plugging Enable
 * - DSU_STATUSB_CELCK Chip Erase Locked
 * - DSU_STATUSB_TDCCD0 Test Debug Communication Channel 0 Dirty
 * - DSU_STATUSB_TDCCD1 Test Debug Communication Channel 1 Dirty
 * - DSU_STATUSB_TDCCD(value) Test Debug Communication Channel x Dirty
 **/
static inline uint8_t dsu_read_STATUSB(void)
{
	return DSU->STATUSB.reg;
}

/**
 * @brief dsu get DID register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_DID_DEVSEL(value) Device Select
 * - DSU_DID_REVISION(value) Revision Number
 * - DSU_DID_DIE(value) Die Number
 * - DSU_DID_SERIES(value) Series
 *  +      DSU_DID_SERIES_0 Cortex-M0+ processor, basic feature set
 *  +      DSU_DID_SERIES_1 Cortex-M0+ processor, USB
 * - DSU_DID_FAMILY(value) Family
 *  +      DSU_DID_FAMILY_0 General purpose microcontroller
 *  +      DSU_DID_FAMILY_1 PicoPower
 * - DSU_DID_PROCESSOR(value) Processor
 *  +      DSU_DID_PROCESSOR_CM0P Cortex-M0+
 *  +      DSU_DID_PROCESSOR_CM23 Cortex-M23
 *  +      DSU_DID_PROCESSOR_CM3 Cortex-M3
 *  +      DSU_DID_PROCESSOR_CM4 Cortex-M4
 *  +      DSU_DID_PROCESSOR_CM4F Cortex-M4 with FPU
 *  +      DSU_DID_PROCESSOR_CM33 Cortex-M33
 **/
static inline uint32_t dsu_get_DID(uint32_t mask)
{
    return DSU->DID.reg & mask;
}

/**
 * @brief dsu read DID register
 *
 * @return uint32_t
 * - DSU_DID_DEVSEL(value) Device Select
 * - DSU_DID_REVISION(value) Revision Number
 * - DSU_DID_DIE(value) Die Number
 * - DSU_DID_SERIES(value) Series
 *  +      DSU_DID_SERIES_0 Cortex-M0+ processor, basic feature set
 *  +      DSU_DID_SERIES_1 Cortex-M0+ processor, USB
 * - DSU_DID_FAMILY(value) Family
 *  +      DSU_DID_FAMILY_0 General purpose microcontroller
 *  +      DSU_DID_FAMILY_1 PicoPower
 * - DSU_DID_PROCESSOR(value) Processor
 *  +      DSU_DID_PROCESSOR_CM0P Cortex-M0+
 *  +      DSU_DID_PROCESSOR_CM23 Cortex-M23
 *  +      DSU_DID_PROCESSOR_CM3 Cortex-M3
 *  +      DSU_DID_PROCESSOR_CM4 Cortex-M4
 *  +      DSU_DID_PROCESSOR_CM4F Cortex-M4 with FPU
 *  +      DSU_DID_PROCESSOR_CM33 Cortex-M33
 **/
static inline uint32_t dsu_read_DID(void)
{
	return DSU->DID.reg;
}

/**
 * @brief dsu get MBDFAIL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBDFAIL_DATA(value) Error Data Read
 **/
static inline uint32_t dsu_get_MBDFAIL(uint32_t mask)
{
    return DSU->MBDFAIL.reg & mask;
}

/**
 * @brief dsu read MBDFAIL register
 *
 * @return uint32_t
 * - DSU_MBDFAIL_DATA(value) Error Data Read
 **/
static inline uint32_t dsu_read_MBDFAIL(void)
{
	return DSU->MBDFAIL.reg;
}

/**
 * @brief dsu get MBDEXP register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBDEXP_DATA(value) Expected Data
 **/
static inline uint32_t dsu_get_MBDEXP(uint32_t mask)
{
    return DSU->MBDEXP.reg & mask;
}

/**
 * @brief dsu read MBDEXP register
 *
 * @return uint32_t
 * - DSU_MBDEXP_DATA(value) Expected Data
 **/
static inline uint32_t dsu_read_MBDEXP(void)
{
	return DSU->MBDEXP.reg;
}

/**
 * @brief dsu get MBAFAIL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBAFAIL_ADDR(value) Error Address
 **/
static inline uint32_t dsu_get_MBAFAIL(uint32_t mask)
{
    return DSU->MBAFAIL.reg & mask;
}

/**
 * @brief dsu read MBAFAIL register
 *
 * @return uint32_t
 * - DSU_MBAFAIL_ADDR(value) Error Address
 **/
static inline uint32_t dsu_read_MBAFAIL(void)
{
	return DSU->MBAFAIL.reg;
}

/**
 * @brief dsu get MBCONTEXT register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBCONTEXT_SUBSTEP(value) Algorithm Sub-step
 *  +      DSU_MBCONTEXT_SUBSTEP_R0_1
 *  +      DSU_MBCONTEXT_SUBSTEP_R1_1
 *  +      DSU_MBCONTEXT_SUBSTEP_R0_2
 *  +      DSU_MBCONTEXT_SUBSTEP_R1_2
 *  +      DSU_MBCONTEXT_SUBSTEP_R0_3
 *  +      DSU_MBCONTEXT_SUBSTEP_R1_3
 * - DSU_MBCONTEXT_STEP(value) Algorithm Step
 *  +      DSU_MBCONTEXT_STEP_DOWN_R0W1
 *  +      DSU_MBCONTEXT_STEP_UP_R1W0R0W1
 *  +      DSU_MBCONTEXT_STEP_UP_R1W0
 *  +      DSU_MBCONTEXT_STEP_UP_R0W1R1W0
 *  +      DSU_MBCONTEXT_STEP_UP_R0
 *  +      DSU_MBCONTEXT_STEP_UP_R0R0W0R0W1
 *  +      DSU_MBCONTEXT_STEP_UP_R1R1W1R1W0
 *  +      DSU_MBCONTEXT_STEP_DOWN_R0R0W0R0W1
 *  +      DSU_MBCONTEXT_STEP_DOWN_R1R1W1R1W0
 *  +      DSU_MBCONTEXT_STEP_UP_R0R0
 *  +      DSU_MBCONTEXT_STEP_DOWN_R1W0R0W1
 *  +      DSU_MBCONTEXT_STEP_DOWN_R1R1
 * - DSU_MBCONTEXT_PORT DPRAM Port Index
 **/
static inline uint32_t dsu_get_MBCONTEXT(uint32_t mask)
{
    return DSU->MBCONTEXT.reg & mask;
}

/**
 * @brief dsu read MBCONTEXT register
 *
 * @return uint32_t
 * - DSU_MBCONTEXT_SUBSTEP(value) Algorithm Sub-step
 *  +      DSU_MBCONTEXT_SUBSTEP_R0_1
 *  +      DSU_MBCONTEXT_SUBSTEP_R1_1
 *  +      DSU_MBCONTEXT_SUBSTEP_R0_2
 *  +      DSU_MBCONTEXT_SUBSTEP_R1_2
 *  +      DSU_MBCONTEXT_SUBSTEP_R0_3
 *  +      DSU_MBCONTEXT_SUBSTEP_R1_3
 * - DSU_MBCONTEXT_STEP(value) Algorithm Step
 *  +      DSU_MBCONTEXT_STEP_DOWN_R0W1
 *  +      DSU_MBCONTEXT_STEP_UP_R1W0R0W1
 *  +      DSU_MBCONTEXT_STEP_UP_R1W0
 *  +      DSU_MBCONTEXT_STEP_UP_R0W1R1W0
 *  +      DSU_MBCONTEXT_STEP_UP_R0
 *  +      DSU_MBCONTEXT_STEP_UP_R0R0W0R0W1
 *  +      DSU_MBCONTEXT_STEP_UP_R1R1W1R1W0
 *  +      DSU_MBCONTEXT_STEP_DOWN_R0R0W0R0W1
 *  +      DSU_MBCONTEXT_STEP_DOWN_R1R1W1R1W0
 *  +      DSU_MBCONTEXT_STEP_UP_R0R0
 *  +      DSU_MBCONTEXT_STEP_DOWN_R1W0R0W1
 *  +      DSU_MBCONTEXT_STEP_DOWN_R1R1
 * - DSU_MBCONTEXT_PORT DPRAM Port Index
 **/
static inline uint32_t dsu_read_MBCONTEXT(void)
{
	return DSU->MBCONTEXT.reg;
}

/**
 * @brief dsu get MBBUSY0 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBBUSY0_BUSY0 Memory 0 BIST Busy
 * - DSU_MBBUSY0_BUSY1 Memory 1 BIST Busy
 * - DSU_MBBUSY0_BUSY2 Memory 2 BIST Busy
 * - DSU_MBBUSY0_BUSY3 Memory 3 BIST Busy
 * - DSU_MBBUSY0_BUSY4 Memory 4 BIST Busy
 * - DSU_MBBUSY0_BUSY5 Memory 5 BIST Busy
 * - DSU_MBBUSY0_BUSY6 Memory 6 BIST Busy
 * - DSU_MBBUSY0_BUSY7 Memory 7 BIST Busy
 * - DSU_MBBUSY0_BUSY8 Memory 8 BIST Busy
 * - DSU_MBBUSY0_BUSY9 Memory 9 BIST Busy
 * - DSU_MBBUSY0_BUSY10 Memory 10 BIST Busy
 * - DSU_MBBUSY0_BUSY11 Memory 11 BIST Busy
 * - DSU_MBBUSY0_BUSY12 Memory 12 BIST Busy
 * - DSU_MBBUSY0_BUSY13 Memory 13 BIST Busy
 * - DSU_MBBUSY0_BUSY14 Memory 14 BIST Busy
 * - DSU_MBBUSY0_BUSY15 Memory 15 BIST Busy
 * - DSU_MBBUSY0_BUSY16 Memory 16 BIST Busy
 * - DSU_MBBUSY0_BUSY17 Memory 17 BIST Busy
 * - DSU_MBBUSY0_BUSY18 Memory 18 BIST Busy
 * - DSU_MBBUSY0_BUSY19 Memory 19 BIST Busy
 * - DSU_MBBUSY0_BUSY20 Memory 20 BIST Busy
 * - DSU_MBBUSY0_BUSY21 Memory 21 BIST Busy
 * - DSU_MBBUSY0_BUSY22 Memory 22 BIST Busy
 * - DSU_MBBUSY0_BUSY23 Memory 23 BIST Busy
 * - DSU_MBBUSY0_BUSY24 Memory 24 BIST Busy
 * - DSU_MBBUSY0_BUSY25 Memory 25 BIST Busy
 * - DSU_MBBUSY0_BUSY26 Memory 26 BIST Busy
 * - DSU_MBBUSY0_BUSY27 Memory 27 BIST Busy
 * - DSU_MBBUSY0_BUSY28 Memory 28 BIST Busy
 * - DSU_MBBUSY0_BUSY(value) Memory x BIST Busy
 **/
static inline uint32_t dsu_get_MBBUSY0(uint32_t mask)
{
    return DSU->MBBUSY0.reg & mask;
}

/**
 * @brief dsu read MBBUSY0 register
 *
 * @return uint32_t
 * - DSU_MBBUSY0_BUSY0 Memory 0 BIST Busy
 * - DSU_MBBUSY0_BUSY1 Memory 1 BIST Busy
 * - DSU_MBBUSY0_BUSY2 Memory 2 BIST Busy
 * - DSU_MBBUSY0_BUSY3 Memory 3 BIST Busy
 * - DSU_MBBUSY0_BUSY4 Memory 4 BIST Busy
 * - DSU_MBBUSY0_BUSY5 Memory 5 BIST Busy
 * - DSU_MBBUSY0_BUSY6 Memory 6 BIST Busy
 * - DSU_MBBUSY0_BUSY7 Memory 7 BIST Busy
 * - DSU_MBBUSY0_BUSY8 Memory 8 BIST Busy
 * - DSU_MBBUSY0_BUSY9 Memory 9 BIST Busy
 * - DSU_MBBUSY0_BUSY10 Memory 10 BIST Busy
 * - DSU_MBBUSY0_BUSY11 Memory 11 BIST Busy
 * - DSU_MBBUSY0_BUSY12 Memory 12 BIST Busy
 * - DSU_MBBUSY0_BUSY13 Memory 13 BIST Busy
 * - DSU_MBBUSY0_BUSY14 Memory 14 BIST Busy
 * - DSU_MBBUSY0_BUSY15 Memory 15 BIST Busy
 * - DSU_MBBUSY0_BUSY16 Memory 16 BIST Busy
 * - DSU_MBBUSY0_BUSY17 Memory 17 BIST Busy
 * - DSU_MBBUSY0_BUSY18 Memory 18 BIST Busy
 * - DSU_MBBUSY0_BUSY19 Memory 19 BIST Busy
 * - DSU_MBBUSY0_BUSY20 Memory 20 BIST Busy
 * - DSU_MBBUSY0_BUSY21 Memory 21 BIST Busy
 * - DSU_MBBUSY0_BUSY22 Memory 22 BIST Busy
 * - DSU_MBBUSY0_BUSY23 Memory 23 BIST Busy
 * - DSU_MBBUSY0_BUSY24 Memory 24 BIST Busy
 * - DSU_MBBUSY0_BUSY25 Memory 25 BIST Busy
 * - DSU_MBBUSY0_BUSY26 Memory 26 BIST Busy
 * - DSU_MBBUSY0_BUSY27 Memory 27 BIST Busy
 * - DSU_MBBUSY0_BUSY28 Memory 28 BIST Busy
 * - DSU_MBBUSY0_BUSY(value) Memory x BIST Busy
 **/
static inline uint32_t dsu_read_MBBUSY0(void)
{
	return DSU->MBBUSY0.reg;
}

/**
 * @brief dsu get ENTRY0 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_ENTRY0_EPRES Entry Present
 * - DSU_ENTRY0_FMT Format
 * - DSU_ENTRY0_ADDOFF(value) Address Offset
 **/
static inline uint32_t dsu_get_ENTRY0(uint32_t mask)
{
    return DSU->ENTRY0.reg & mask;
}

/**
 * @brief dsu read ENTRY0 register
 *
 * @return uint32_t
 * - DSU_ENTRY0_EPRES Entry Present
 * - DSU_ENTRY0_FMT Format
 * - DSU_ENTRY0_ADDOFF(value) Address Offset
 **/
static inline uint32_t dsu_read_ENTRY0(void)
{
	return DSU->ENTRY0.reg;
}

/**
 * @brief dsu get ENTRY1 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t dsu_get_ENTRY1(uint32_t mask)
{
    return DSU->ENTRY1.reg & mask;
}

/**
 * @brief dsu read ENTRY1 register
 *
 * @return uint32_t
 **/
static inline uint32_t dsu_read_ENTRY1(void)
{
	return DSU->ENTRY1.reg;
}

/**
 * @brief dsu get END register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_END_END(value) End Marker
 **/
static inline uint32_t dsu_get_END(uint32_t mask)
{
    return DSU->END.reg & mask;
}

/**
 * @brief dsu read END register
 *
 * @return uint32_t
 * - DSU_END_END(value) End Marker
 **/
static inline uint32_t dsu_read_END(void)
{
	return DSU->END.reg;
}

/**
 * @brief dsu get MEMTYPE register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MEMTYPE_SMEMP System Memory Present
 **/
static inline uint32_t dsu_get_MEMTYPE(uint32_t mask)
{
    return DSU->MEMTYPE.reg & mask;
}

/**
 * @brief dsu read MEMTYPE register
 *
 * @return uint32_t
 * - DSU_MEMTYPE_SMEMP System Memory Present
 **/
static inline uint32_t dsu_read_MEMTYPE(void)
{
	return DSU->MEMTYPE.reg;
}

/**
 * @brief dsu get PID4 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_PID4_JEPCC(value) JEP-106 Continuation Code
 * - DSU_PID4_FKBC(value) 4KB count
 **/
static inline uint32_t dsu_get_PID4(uint32_t mask)
{
    return DSU->PID4.reg & mask;
}

/**
 * @brief dsu read PID4 register
 *
 * @return uint32_t
 * - DSU_PID4_JEPCC(value) JEP-106 Continuation Code
 * - DSU_PID4_FKBC(value) 4KB count
 **/
static inline uint32_t dsu_read_PID4(void)
{
	return DSU->PID4.reg;
}

/**
 * @brief dsu get PID5 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t dsu_get_PID5(uint32_t mask)
{
    return DSU->PID5.reg & mask;
}

/**
 * @brief dsu read PID5 register
 *
 * @return uint32_t
 **/
static inline uint32_t dsu_read_PID5(void)
{
	return DSU->PID5.reg;
}

/**
 * @brief dsu get PID6 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t dsu_get_PID6(uint32_t mask)
{
    return DSU->PID6.reg & mask;
}

/**
 * @brief dsu read PID6 register
 *
 * @return uint32_t
 **/
static inline uint32_t dsu_read_PID6(void)
{
	return DSU->PID6.reg;
}

/**
 * @brief dsu get PID7 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t dsu_get_PID7(uint32_t mask)
{
    return DSU->PID7.reg & mask;
}

/**
 * @brief dsu read PID7 register
 *
 * @return uint32_t
 **/
static inline uint32_t dsu_read_PID7(void)
{
	return DSU->PID7.reg;
}

/**
 * @brief dsu get PID0 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_PID0_PARTNBL(value) Part Number Low
 **/
static inline uint32_t dsu_get_PID0(uint32_t mask)
{
    return DSU->PID0.reg & mask;
}

/**
 * @brief dsu read PID0 register
 *
 * @return uint32_t
 * - DSU_PID0_PARTNBL(value) Part Number Low
 **/
static inline uint32_t dsu_read_PID0(void)
{
	return DSU->PID0.reg;
}

/**
 * @brief dsu get PID1 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_PID1_PARTNBH(value) Part Number High
 * - DSU_PID1_JEPIDCL(value) Low part of the JEP-106 Identity Code
 **/
static inline uint32_t dsu_get_PID1(uint32_t mask)
{
    return DSU->PID1.reg & mask;
}

/**
 * @brief dsu read PID1 register
 *
 * @return uint32_t
 * - DSU_PID1_PARTNBH(value) Part Number High
 * - DSU_PID1_JEPIDCL(value) Low part of the JEP-106 Identity Code
 **/
static inline uint32_t dsu_read_PID1(void)
{
	return DSU->PID1.reg;
}

/**
 * @brief dsu get PID2 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_PID2_JEPIDCH(value) JEP-106 Identity Code High
 * - DSU_PID2_JEPU JEP-106 Identity Code is used
 * - DSU_PID2_REVISION(value) Revision Number
 **/
static inline uint32_t dsu_get_PID2(uint32_t mask)
{
    return DSU->PID2.reg & mask;
}

/**
 * @brief dsu read PID2 register
 *
 * @return uint32_t
 * - DSU_PID2_JEPIDCH(value) JEP-106 Identity Code High
 * - DSU_PID2_JEPU JEP-106 Identity Code is used
 * - DSU_PID2_REVISION(value) Revision Number
 **/
static inline uint32_t dsu_read_PID2(void)
{
	return DSU->PID2.reg;
}

/**
 * @brief dsu get PID3 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_PID3_CUSMOD(value) ARM CUSMOD
 * - DSU_PID3_REVAND(value) Revision Number
 **/
static inline uint32_t dsu_get_PID3(uint32_t mask)
{
    return DSU->PID3.reg & mask;
}

/**
 * @brief dsu read PID3 register
 *
 * @return uint32_t
 * - DSU_PID3_CUSMOD(value) ARM CUSMOD
 * - DSU_PID3_REVAND(value) Revision Number
 **/
static inline uint32_t dsu_read_PID3(void)
{
	return DSU->PID3.reg;
}

/**
 * @brief dsu get CID0 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_CID0_PREAMBLEB0(value) Preamble Byte 0
 **/
static inline uint32_t dsu_get_CID0(uint32_t mask)
{
    return DSU->CID0.reg & mask;
}

/**
 * @brief dsu read CID0 register
 *
 * @return uint32_t
 * - DSU_CID0_PREAMBLEB0(value) Preamble Byte 0
 **/
static inline uint32_t dsu_read_CID0(void)
{
	return DSU->CID0.reg;
}

/**
 * @brief dsu get CID1 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_CID1_PREAMBLE(value) Preamble
 * - DSU_CID1_CCLASS(value) Component Class
 **/
static inline uint32_t dsu_get_CID1(uint32_t mask)
{
    return DSU->CID1.reg & mask;
}

/**
 * @brief dsu read CID1 register
 *
 * @return uint32_t
 * - DSU_CID1_PREAMBLE(value) Preamble
 * - DSU_CID1_CCLASS(value) Component Class
 **/
static inline uint32_t dsu_read_CID1(void)
{
	return DSU->CID1.reg;
}

/**
 * @brief dsu get CID2 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_CID2_PREAMBLEB2(value) Preamble Byte 2
 **/
static inline uint32_t dsu_get_CID2(uint32_t mask)
{
    return DSU->CID2.reg & mask;
}

/**
 * @brief dsu read CID2 register
 *
 * @return uint32_t
 * - DSU_CID2_PREAMBLEB2(value) Preamble Byte 2
 **/
static inline uint32_t dsu_read_CID2(void)
{
	return DSU->CID2.reg;
}

/**
 * @brief dsu get CID3 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_CID3_PREAMBLEB3(value) Preamble Byte 3
 **/
static inline uint32_t dsu_get_CID3(uint32_t mask)
{
    return DSU->CID3.reg & mask;
}

/**
 * @brief dsu read CID3 register
 *
 * @return uint32_t
 * - DSU_CID3_PREAMBLEB3(value) Preamble Byte 3
 **/
static inline uint32_t dsu_read_CID3(void)
{
	return DSU->CID3.reg;
}

/**
 * @brief dsu set ADDR register
 *
 * @param[in] mask uint32_t 
 * - DSU_ADDR_AMOD(value) Access Mode
 * - DSU_ADDR_ADDR(value) Address
 **/
static inline void dsu_set_ADDR(uint32_t mask)
{
	DSU->ADDR.reg |= mask;
}

/**
 * @brief dsu get ADDR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_ADDR_AMOD(value) Access Mode
 * - DSU_ADDR_ADDR(value) Address
 **/
static inline uint32_t dsu_get_ADDR(uint32_t mask)
{
    return DSU->ADDR.reg & mask;
}

/**
 * @brief dsu write ADDR register
 *
 * @param[in] data uint32_t 
 * - DSU_ADDR_AMOD(value) Access Mode
 * - DSU_ADDR_ADDR(value) Address
 **/
static inline void dsu_write_ADDR(uint32_t data)
{
	DSU->ADDR.reg = data;
}

/**
 * @brief dsu clear ADDR register
 *
 * @param[in] mask uint32_t 
 * - DSU_ADDR_AMOD(value) Access Mode
 * - DSU_ADDR_ADDR(value) Address
 **/
static inline void dsu_clear_ADDR(uint32_t mask)
{
	DSU->ADDR.reg &= ~mask;
}

/**
 * @brief dsu read ADDR register
 *
 * @return uint32_t
 * - DSU_ADDR_AMOD(value) Access Mode
 * - DSU_ADDR_ADDR(value) Address
 **/
static inline uint32_t dsu_read_ADDR(void)
{
	return DSU->ADDR.reg;
}

/**
 * @brief dsu set LENGTH register
 *
 * @param[in] mask uint32_t 
 * - DSU_LENGTH_LENGTH(value) Length
 **/
static inline void dsu_set_LENGTH(uint32_t mask)
{
	DSU->LENGTH.reg |= mask;
}

/**
 * @brief dsu get LENGTH register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_LENGTH_LENGTH(value) Length
 **/
static inline uint32_t dsu_get_LENGTH(uint32_t mask)
{
    return DSU->LENGTH.reg & mask;
}

/**
 * @brief dsu write LENGTH register
 *
 * @param[in] data uint32_t 
 * - DSU_LENGTH_LENGTH(value) Length
 **/
static inline void dsu_write_LENGTH(uint32_t data)
{
	DSU->LENGTH.reg = data;
}

/**
 * @brief dsu clear LENGTH register
 *
 * @param[in] mask uint32_t 
 * - DSU_LENGTH_LENGTH(value) Length
 **/
static inline void dsu_clear_LENGTH(uint32_t mask)
{
	DSU->LENGTH.reg &= ~mask;
}

/**
 * @brief dsu read LENGTH register
 *
 * @return uint32_t
 * - DSU_LENGTH_LENGTH(value) Length
 **/
static inline uint32_t dsu_read_LENGTH(void)
{
	return DSU->LENGTH.reg;
}

/**
 * @brief dsu set DATA register
 *
 * @param[in] mask uint32_t 
 * - DSU_DATA_DATA(value) Data
 **/
static inline void dsu_set_DATA(uint32_t mask)
{
	DSU->DATA.reg |= mask;
}

/**
 * @brief dsu get DATA register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_DATA_DATA(value) Data
 **/
static inline uint32_t dsu_get_DATA(uint32_t mask)
{
    return DSU->DATA.reg & mask;
}

/**
 * @brief dsu write DATA register
 *
 * @param[in] data uint32_t 
 * - DSU_DATA_DATA(value) Data
 **/
static inline void dsu_write_DATA(uint32_t data)
{
	DSU->DATA.reg = data;
}

/**
 * @brief dsu clear DATA register
 *
 * @param[in] mask uint32_t 
 * - DSU_DATA_DATA(value) Data
 **/
static inline void dsu_clear_DATA(uint32_t mask)
{
	DSU->DATA.reg &= ~mask;
}

/**
 * @brief dsu read DATA register
 *
 * @return uint32_t
 * - DSU_DATA_DATA(value) Data
 **/
static inline uint32_t dsu_read_DATA(void)
{
	return DSU->DATA.reg;
}

/**
 * @brief dsu set DCC register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - DSU_DCC_DATA(value) Data
 **/
static inline void dsu_set_DCC(uint8_t index, uint32_t mask)
{
	DSU->DCC[index].reg |= mask;
}

/**
 * @brief dsu get DCC register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_DCC_DATA(value) Data
 **/
static inline uint32_t dsu_get_DCC(uint8_t index, uint32_t mask)
{
    return DSU->DCC[index].reg & mask;
}

/**
 * @brief dsu write DCC register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - DSU_DCC_DATA(value) Data
 **/
static inline void dsu_write_DCC(uint8_t index, uint32_t data)
{
	DSU->DCC[index].reg = data;
}

/**
 * @brief dsu clear DCC register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - DSU_DCC_DATA(value) Data
 **/
static inline void dsu_clear_DCC(uint8_t index, uint32_t mask)
{
	DSU->DCC[index].reg &= ~mask;
}

/**
 * @brief dsu read DCC register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - DSU_DCC_DATA(value) Data
 **/
static inline uint32_t dsu_read_DCC(uint8_t index)
{
	return DSU->DCC[index].reg;
}

/**
 * @brief dsu set CFG register
 *
 * @param[in] mask uint32_t 
 * - DSU_CFG_LQOS(value) Latency Quality Of Service
 * - DSU_CFG_DCCDMALEVEL(value) DMA Trigger Level
 *  +      DSU_CFG_DCCDMALEVEL_EMPTY Trigger rises when DCC is empty
 *  +      DSU_CFG_DCCDMALEVEL_FULL Trigger rises when DCC is full
 * - DSU_CFG_ETBRAMEN Trace Control
 **/
static inline void dsu_set_CFG(uint32_t mask)
{
	DSU->CFG.reg |= mask;
}

/**
 * @brief dsu get CFG register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_CFG_LQOS(value) Latency Quality Of Service
 * - DSU_CFG_DCCDMALEVEL(value) DMA Trigger Level
 *  +      DSU_CFG_DCCDMALEVEL_EMPTY Trigger rises when DCC is empty
 *  +      DSU_CFG_DCCDMALEVEL_FULL Trigger rises when DCC is full
 * - DSU_CFG_ETBRAMEN Trace Control
 **/
static inline uint32_t dsu_get_CFG(uint32_t mask)
{
    return DSU->CFG.reg & mask;
}

/**
 * @brief dsu write CFG register
 *
 * @param[in] data uint32_t 
 * - DSU_CFG_LQOS(value) Latency Quality Of Service
 * - DSU_CFG_DCCDMALEVEL(value) DMA Trigger Level
 *  +      DSU_CFG_DCCDMALEVEL_EMPTY Trigger rises when DCC is empty
 *  +      DSU_CFG_DCCDMALEVEL_FULL Trigger rises when DCC is full
 * - DSU_CFG_ETBRAMEN Trace Control
 **/
static inline void dsu_write_CFG(uint32_t data)
{
	DSU->CFG.reg = data;
}

/**
 * @brief dsu clear CFG register
 *
 * @param[in] mask uint32_t 
 * - DSU_CFG_LQOS(value) Latency Quality Of Service
 * - DSU_CFG_DCCDMALEVEL(value) DMA Trigger Level
 *  +      DSU_CFG_DCCDMALEVEL_EMPTY Trigger rises when DCC is empty
 *  +      DSU_CFG_DCCDMALEVEL_FULL Trigger rises when DCC is full
 * - DSU_CFG_ETBRAMEN Trace Control
 **/
static inline void dsu_clear_CFG(uint32_t mask)
{
	DSU->CFG.reg &= ~mask;
}

/**
 * @brief dsu read CFG register
 *
 * @return uint32_t
 * - DSU_CFG_LQOS(value) Latency Quality Of Service
 * - DSU_CFG_DCCDMALEVEL(value) DMA Trigger Level
 *  +      DSU_CFG_DCCDMALEVEL_EMPTY Trigger rises when DCC is empty
 *  +      DSU_CFG_DCCDMALEVEL_FULL Trigger rises when DCC is full
 * - DSU_CFG_ETBRAMEN Trace Control
 **/
static inline uint32_t dsu_read_CFG(void)
{
	return DSU->CFG.reg;
}

/**
 * @brief dsu set MBCTRL register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBCTRL_SWRST MBIST Software Reset
 * - DSU_MBCTRL_ENABLE MBIST Enable
 **/
static inline void dsu_set_MBCTRL(uint32_t mask)
{
	DSU->MBCTRL.reg |= mask;
}

/**
 * @brief dsu get MBCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBCTRL_SWRST MBIST Software Reset
 * - DSU_MBCTRL_ENABLE MBIST Enable
 **/
static inline uint32_t dsu_get_MBCTRL(uint32_t mask)
{
    return DSU->MBCTRL.reg & mask;
}

/**
 * @brief dsu write MBCTRL register
 *
 * @param[in] data uint32_t 
 * - DSU_MBCTRL_SWRST MBIST Software Reset
 * - DSU_MBCTRL_ENABLE MBIST Enable
 **/
static inline void dsu_write_MBCTRL(uint32_t data)
{
	DSU->MBCTRL.reg = data;
}

/**
 * @brief dsu clear MBCTRL register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBCTRL_SWRST MBIST Software Reset
 * - DSU_MBCTRL_ENABLE MBIST Enable
 **/
static inline void dsu_clear_MBCTRL(uint32_t mask)
{
	DSU->MBCTRL.reg &= ~mask;
}

/**
 * @brief dsu read MBCTRL register
 *
 * @return uint32_t
 * - DSU_MBCTRL_SWRST MBIST Software Reset
 * - DSU_MBCTRL_ENABLE MBIST Enable
 **/
static inline uint32_t dsu_read_MBCTRL(void)
{
	return DSU->MBCTRL.reg;
}

/**
 * @brief dsu set MBCONFIG register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBCONFIG_ALGO(value) MBIST Algorithm
 *  +      DSU_MBCONFIG_ALGO_MEMCLEAR Memory Clear (1n)
 *  +      DSU_MBCONFIG_ALGO_VERIFY Memory Verify (1n)
 *  +      DSU_MBCONFIG_ALGO_CLEARVER Memory Clear and Verify (2n)
 *  +      DSU_MBCONFIG_ALGO_ADDR_DEC Address Decoder (2n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_LR March LR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SR March SR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SS March SS (22n)
 *  +      DSU_MBCONFIG_ALGO_CRC_UP CRC increasing address (1n)
 *  +      DSU_MBCONFIG_ALGO_CRC_DOWN CRC decreasing address (1n)
 * - DSU_MBCONFIG_DEFRDMARGIN Force Default Read Margin
 * - DSU_MBCONFIG_DBG Enable Debug Mode
 **/
static inline void dsu_set_MBCONFIG(uint32_t mask)
{
	DSU->MBCONFIG.reg |= mask;
}

/**
 * @brief dsu get MBCONFIG register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBCONFIG_ALGO(value) MBIST Algorithm
 *  +      DSU_MBCONFIG_ALGO_MEMCLEAR Memory Clear (1n)
 *  +      DSU_MBCONFIG_ALGO_VERIFY Memory Verify (1n)
 *  +      DSU_MBCONFIG_ALGO_CLEARVER Memory Clear and Verify (2n)
 *  +      DSU_MBCONFIG_ALGO_ADDR_DEC Address Decoder (2n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_LR March LR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SR March SR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SS March SS (22n)
 *  +      DSU_MBCONFIG_ALGO_CRC_UP CRC increasing address (1n)
 *  +      DSU_MBCONFIG_ALGO_CRC_DOWN CRC decreasing address (1n)
 * - DSU_MBCONFIG_DEFRDMARGIN Force Default Read Margin
 * - DSU_MBCONFIG_DBG Enable Debug Mode
 **/
static inline uint32_t dsu_get_MBCONFIG(uint32_t mask)
{
    return DSU->MBCONFIG.reg & mask;
}

/**
 * @brief dsu write MBCONFIG register
 *
 * @param[in] data uint32_t 
 * - DSU_MBCONFIG_ALGO(value) MBIST Algorithm
 *  +      DSU_MBCONFIG_ALGO_MEMCLEAR Memory Clear (1n)
 *  +      DSU_MBCONFIG_ALGO_VERIFY Memory Verify (1n)
 *  +      DSU_MBCONFIG_ALGO_CLEARVER Memory Clear and Verify (2n)
 *  +      DSU_MBCONFIG_ALGO_ADDR_DEC Address Decoder (2n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_LR March LR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SR March SR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SS March SS (22n)
 *  +      DSU_MBCONFIG_ALGO_CRC_UP CRC increasing address (1n)
 *  +      DSU_MBCONFIG_ALGO_CRC_DOWN CRC decreasing address (1n)
 * - DSU_MBCONFIG_DEFRDMARGIN Force Default Read Margin
 * - DSU_MBCONFIG_DBG Enable Debug Mode
 **/
static inline void dsu_write_MBCONFIG(uint32_t data)
{
	DSU->MBCONFIG.reg = data;
}

/**
 * @brief dsu clear MBCONFIG register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBCONFIG_ALGO(value) MBIST Algorithm
 *  +      DSU_MBCONFIG_ALGO_MEMCLEAR Memory Clear (1n)
 *  +      DSU_MBCONFIG_ALGO_VERIFY Memory Verify (1n)
 *  +      DSU_MBCONFIG_ALGO_CLEARVER Memory Clear and Verify (2n)
 *  +      DSU_MBCONFIG_ALGO_ADDR_DEC Address Decoder (2n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_LR March LR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SR March SR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SS March SS (22n)
 *  +      DSU_MBCONFIG_ALGO_CRC_UP CRC increasing address (1n)
 *  +      DSU_MBCONFIG_ALGO_CRC_DOWN CRC decreasing address (1n)
 * - DSU_MBCONFIG_DEFRDMARGIN Force Default Read Margin
 * - DSU_MBCONFIG_DBG Enable Debug Mode
 **/
static inline void dsu_clear_MBCONFIG(uint32_t mask)
{
	DSU->MBCONFIG.reg &= ~mask;
}

/**
 * @brief dsu read MBCONFIG register
 *
 * @return uint32_t
 * - DSU_MBCONFIG_ALGO(value) MBIST Algorithm
 *  +      DSU_MBCONFIG_ALGO_MEMCLEAR Memory Clear (1n)
 *  +      DSU_MBCONFIG_ALGO_VERIFY Memory Verify (1n)
 *  +      DSU_MBCONFIG_ALGO_CLEARVER Memory Clear and Verify (2n)
 *  +      DSU_MBCONFIG_ALGO_ADDR_DEC Address Decoder (2n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_LR March LR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SR March SR (14n)
 *  +      DSU_MBCONFIG_ALGO_MARCH_SS March SS (22n)
 *  +      DSU_MBCONFIG_ALGO_CRC_UP CRC increasing address (1n)
 *  +      DSU_MBCONFIG_ALGO_CRC_DOWN CRC decreasing address (1n)
 * - DSU_MBCONFIG_DEFRDMARGIN Force Default Read Margin
 * - DSU_MBCONFIG_DBG Enable Debug Mode
 **/
static inline uint32_t dsu_read_MBCONFIG(void)
{
	return DSU->MBCONFIG.reg;
}

/**
 * @brief dsu set MBWORD register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBWORD_DATA(value) MBIST Background Word
 **/
static inline void dsu_set_MBWORD(uint32_t mask)
{
	DSU->MBWORD.reg |= mask;
}

/**
 * @brief dsu get MBWORD register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBWORD_DATA(value) MBIST Background Word
 **/
static inline uint32_t dsu_get_MBWORD(uint32_t mask)
{
    return DSU->MBWORD.reg & mask;
}

/**
 * @brief dsu write MBWORD register
 *
 * @param[in] data uint32_t 
 * - DSU_MBWORD_DATA(value) MBIST Background Word
 **/
static inline void dsu_write_MBWORD(uint32_t data)
{
	DSU->MBWORD.reg = data;
}

/**
 * @brief dsu clear MBWORD register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBWORD_DATA(value) MBIST Background Word
 **/
static inline void dsu_clear_MBWORD(uint32_t mask)
{
	DSU->MBWORD.reg &= ~mask;
}

/**
 * @brief dsu read MBWORD register
 *
 * @return uint32_t
 * - DSU_MBWORD_DATA(value) MBIST Background Word
 **/
static inline uint32_t dsu_read_MBWORD(void)
{
	return DSU->MBWORD.reg;
}

/**
 * @brief dsu set MBGSTAT register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBGSTAT_ALLDONE MBIST Completed
 * - DSU_MBGSTAT_FAILED MBIST Failed
 * - DSU_MBGSTAT_ERRINFO MBIST Error Info Present
 * - DSU_MBGSTAT_CONFIGURED MBIST Configuration Sent
 **/
static inline void dsu_set_MBGSTAT(uint32_t mask)
{
	DSU->MBGSTAT.reg |= mask;
}

/**
 * @brief dsu get MBGSTAT register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBGSTAT_ALLDONE MBIST Completed
 * - DSU_MBGSTAT_FAILED MBIST Failed
 * - DSU_MBGSTAT_ERRINFO MBIST Error Info Present
 * - DSU_MBGSTAT_CONFIGURED MBIST Configuration Sent
 **/
static inline uint32_t dsu_get_MBGSTAT(uint32_t mask)
{
    return DSU->MBGSTAT.reg & mask;
}

/**
 * @brief dsu write MBGSTAT register
 *
 * @param[in] data uint32_t 
 * - DSU_MBGSTAT_ALLDONE MBIST Completed
 * - DSU_MBGSTAT_FAILED MBIST Failed
 * - DSU_MBGSTAT_ERRINFO MBIST Error Info Present
 * - DSU_MBGSTAT_CONFIGURED MBIST Configuration Sent
 **/
static inline void dsu_write_MBGSTAT(uint32_t data)
{
	DSU->MBGSTAT.reg = data;
}

/**
 * @brief dsu clear MBGSTAT register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBGSTAT_ALLDONE MBIST Completed
 * - DSU_MBGSTAT_FAILED MBIST Failed
 * - DSU_MBGSTAT_ERRINFO MBIST Error Info Present
 * - DSU_MBGSTAT_CONFIGURED MBIST Configuration Sent
 **/
static inline void dsu_clear_MBGSTAT(uint32_t mask)
{
	DSU->MBGSTAT.reg &= ~mask;
}

/**
 * @brief dsu read MBGSTAT register
 *
 * @return uint32_t
 * - DSU_MBGSTAT_ALLDONE MBIST Completed
 * - DSU_MBGSTAT_FAILED MBIST Failed
 * - DSU_MBGSTAT_ERRINFO MBIST Error Info Present
 * - DSU_MBGSTAT_CONFIGURED MBIST Configuration Sent
 **/
static inline uint32_t dsu_read_MBGSTAT(void)
{
	return DSU->MBGSTAT.reg;
}

/**
 * @brief dsu set MBENABLE0 register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBENABLE0_ENABLE0 Memory 0 MBIST Enable
 * - DSU_MBENABLE0_ENABLE1 Memory 1 MBIST Enable
 * - DSU_MBENABLE0_ENABLE2 Memory 2 MBIST Enable
 * - DSU_MBENABLE0_ENABLE3 Memory 3 MBIST Enable
 * - DSU_MBENABLE0_ENABLE4 Memory 4 MBIST Enable
 * - DSU_MBENABLE0_ENABLE5 Memory 5 MBIST Enable
 * - DSU_MBENABLE0_ENABLE6 Memory 6 MBIST Enable
 * - DSU_MBENABLE0_ENABLE7 Memory 7 MBIST Enable
 * - DSU_MBENABLE0_ENABLE8 Memory 8 MBIST Enable
 * - DSU_MBENABLE0_ENABLE9 Memory 9 MBIST Enable
 * - DSU_MBENABLE0_ENABLE10 Memory 10 MBIST Enable
 * - DSU_MBENABLE0_ENABLE11 Memory 11 MBIST Enable
 * - DSU_MBENABLE0_ENABLE12 Memory 12 MBIST Enable
 * - DSU_MBENABLE0_ENABLE13 Memory 13 MBIST Enable
 * - DSU_MBENABLE0_ENABLE14 Memory 14 MBIST Enable
 * - DSU_MBENABLE0_ENABLE15 Memory 15 MBIST Enable
 * - DSU_MBENABLE0_ENABLE16 Memory 16 MBIST Enable
 * - DSU_MBENABLE0_ENABLE17 Memory 17 MBIST Enable
 * - DSU_MBENABLE0_ENABLE18 Memory 18 MBIST Enable
 * - DSU_MBENABLE0_ENABLE19 Memory 19 MBIST Enable
 * - DSU_MBENABLE0_ENABLE20 Memory 20 MBIST Enable
 * - DSU_MBENABLE0_ENABLE21 Memory 21 MBIST Enable
 * - DSU_MBENABLE0_ENABLE22 Memory 22 MBIST Enable
 * - DSU_MBENABLE0_ENABLE23 Memory 23 MBIST Enable
 * - DSU_MBENABLE0_ENABLE24 Memory 24 MBIST Enable
 * - DSU_MBENABLE0_ENABLE25 Memory 25 MBIST Enable
 * - DSU_MBENABLE0_ENABLE26 Memory 26 MBIST Enable
 * - DSU_MBENABLE0_ENABLE27 Memory 27 MBIST Enable
 * - DSU_MBENABLE0_ENABLE28 Memory 28 MBIST Enable
 * - DSU_MBENABLE0_ENABLE(value) Memory x MBIST Enable
 **/
static inline void dsu_set_MBENABLE0(uint32_t mask)
{
	DSU->MBENABLE0.reg |= mask;
}

/**
 * @brief dsu get MBENABLE0 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBENABLE0_ENABLE0 Memory 0 MBIST Enable
 * - DSU_MBENABLE0_ENABLE1 Memory 1 MBIST Enable
 * - DSU_MBENABLE0_ENABLE2 Memory 2 MBIST Enable
 * - DSU_MBENABLE0_ENABLE3 Memory 3 MBIST Enable
 * - DSU_MBENABLE0_ENABLE4 Memory 4 MBIST Enable
 * - DSU_MBENABLE0_ENABLE5 Memory 5 MBIST Enable
 * - DSU_MBENABLE0_ENABLE6 Memory 6 MBIST Enable
 * - DSU_MBENABLE0_ENABLE7 Memory 7 MBIST Enable
 * - DSU_MBENABLE0_ENABLE8 Memory 8 MBIST Enable
 * - DSU_MBENABLE0_ENABLE9 Memory 9 MBIST Enable
 * - DSU_MBENABLE0_ENABLE10 Memory 10 MBIST Enable
 * - DSU_MBENABLE0_ENABLE11 Memory 11 MBIST Enable
 * - DSU_MBENABLE0_ENABLE12 Memory 12 MBIST Enable
 * - DSU_MBENABLE0_ENABLE13 Memory 13 MBIST Enable
 * - DSU_MBENABLE0_ENABLE14 Memory 14 MBIST Enable
 * - DSU_MBENABLE0_ENABLE15 Memory 15 MBIST Enable
 * - DSU_MBENABLE0_ENABLE16 Memory 16 MBIST Enable
 * - DSU_MBENABLE0_ENABLE17 Memory 17 MBIST Enable
 * - DSU_MBENABLE0_ENABLE18 Memory 18 MBIST Enable
 * - DSU_MBENABLE0_ENABLE19 Memory 19 MBIST Enable
 * - DSU_MBENABLE0_ENABLE20 Memory 20 MBIST Enable
 * - DSU_MBENABLE0_ENABLE21 Memory 21 MBIST Enable
 * - DSU_MBENABLE0_ENABLE22 Memory 22 MBIST Enable
 * - DSU_MBENABLE0_ENABLE23 Memory 23 MBIST Enable
 * - DSU_MBENABLE0_ENABLE24 Memory 24 MBIST Enable
 * - DSU_MBENABLE0_ENABLE25 Memory 25 MBIST Enable
 * - DSU_MBENABLE0_ENABLE26 Memory 26 MBIST Enable
 * - DSU_MBENABLE0_ENABLE27 Memory 27 MBIST Enable
 * - DSU_MBENABLE0_ENABLE28 Memory 28 MBIST Enable
 * - DSU_MBENABLE0_ENABLE(value) Memory x MBIST Enable
 **/
static inline uint32_t dsu_get_MBENABLE0(uint32_t mask)
{
    return DSU->MBENABLE0.reg & mask;
}

/**
 * @brief dsu write MBENABLE0 register
 *
 * @param[in] data uint32_t 
 * - DSU_MBENABLE0_ENABLE0 Memory 0 MBIST Enable
 * - DSU_MBENABLE0_ENABLE1 Memory 1 MBIST Enable
 * - DSU_MBENABLE0_ENABLE2 Memory 2 MBIST Enable
 * - DSU_MBENABLE0_ENABLE3 Memory 3 MBIST Enable
 * - DSU_MBENABLE0_ENABLE4 Memory 4 MBIST Enable
 * - DSU_MBENABLE0_ENABLE5 Memory 5 MBIST Enable
 * - DSU_MBENABLE0_ENABLE6 Memory 6 MBIST Enable
 * - DSU_MBENABLE0_ENABLE7 Memory 7 MBIST Enable
 * - DSU_MBENABLE0_ENABLE8 Memory 8 MBIST Enable
 * - DSU_MBENABLE0_ENABLE9 Memory 9 MBIST Enable
 * - DSU_MBENABLE0_ENABLE10 Memory 10 MBIST Enable
 * - DSU_MBENABLE0_ENABLE11 Memory 11 MBIST Enable
 * - DSU_MBENABLE0_ENABLE12 Memory 12 MBIST Enable
 * - DSU_MBENABLE0_ENABLE13 Memory 13 MBIST Enable
 * - DSU_MBENABLE0_ENABLE14 Memory 14 MBIST Enable
 * - DSU_MBENABLE0_ENABLE15 Memory 15 MBIST Enable
 * - DSU_MBENABLE0_ENABLE16 Memory 16 MBIST Enable
 * - DSU_MBENABLE0_ENABLE17 Memory 17 MBIST Enable
 * - DSU_MBENABLE0_ENABLE18 Memory 18 MBIST Enable
 * - DSU_MBENABLE0_ENABLE19 Memory 19 MBIST Enable
 * - DSU_MBENABLE0_ENABLE20 Memory 20 MBIST Enable
 * - DSU_MBENABLE0_ENABLE21 Memory 21 MBIST Enable
 * - DSU_MBENABLE0_ENABLE22 Memory 22 MBIST Enable
 * - DSU_MBENABLE0_ENABLE23 Memory 23 MBIST Enable
 * - DSU_MBENABLE0_ENABLE24 Memory 24 MBIST Enable
 * - DSU_MBENABLE0_ENABLE25 Memory 25 MBIST Enable
 * - DSU_MBENABLE0_ENABLE26 Memory 26 MBIST Enable
 * - DSU_MBENABLE0_ENABLE27 Memory 27 MBIST Enable
 * - DSU_MBENABLE0_ENABLE28 Memory 28 MBIST Enable
 * - DSU_MBENABLE0_ENABLE(value) Memory x MBIST Enable
 **/
static inline void dsu_write_MBENABLE0(uint32_t data)
{
	DSU->MBENABLE0.reg = data;
}

/**
 * @brief dsu clear MBENABLE0 register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBENABLE0_ENABLE0 Memory 0 MBIST Enable
 * - DSU_MBENABLE0_ENABLE1 Memory 1 MBIST Enable
 * - DSU_MBENABLE0_ENABLE2 Memory 2 MBIST Enable
 * - DSU_MBENABLE0_ENABLE3 Memory 3 MBIST Enable
 * - DSU_MBENABLE0_ENABLE4 Memory 4 MBIST Enable
 * - DSU_MBENABLE0_ENABLE5 Memory 5 MBIST Enable
 * - DSU_MBENABLE0_ENABLE6 Memory 6 MBIST Enable
 * - DSU_MBENABLE0_ENABLE7 Memory 7 MBIST Enable
 * - DSU_MBENABLE0_ENABLE8 Memory 8 MBIST Enable
 * - DSU_MBENABLE0_ENABLE9 Memory 9 MBIST Enable
 * - DSU_MBENABLE0_ENABLE10 Memory 10 MBIST Enable
 * - DSU_MBENABLE0_ENABLE11 Memory 11 MBIST Enable
 * - DSU_MBENABLE0_ENABLE12 Memory 12 MBIST Enable
 * - DSU_MBENABLE0_ENABLE13 Memory 13 MBIST Enable
 * - DSU_MBENABLE0_ENABLE14 Memory 14 MBIST Enable
 * - DSU_MBENABLE0_ENABLE15 Memory 15 MBIST Enable
 * - DSU_MBENABLE0_ENABLE16 Memory 16 MBIST Enable
 * - DSU_MBENABLE0_ENABLE17 Memory 17 MBIST Enable
 * - DSU_MBENABLE0_ENABLE18 Memory 18 MBIST Enable
 * - DSU_MBENABLE0_ENABLE19 Memory 19 MBIST Enable
 * - DSU_MBENABLE0_ENABLE20 Memory 20 MBIST Enable
 * - DSU_MBENABLE0_ENABLE21 Memory 21 MBIST Enable
 * - DSU_MBENABLE0_ENABLE22 Memory 22 MBIST Enable
 * - DSU_MBENABLE0_ENABLE23 Memory 23 MBIST Enable
 * - DSU_MBENABLE0_ENABLE24 Memory 24 MBIST Enable
 * - DSU_MBENABLE0_ENABLE25 Memory 25 MBIST Enable
 * - DSU_MBENABLE0_ENABLE26 Memory 26 MBIST Enable
 * - DSU_MBENABLE0_ENABLE27 Memory 27 MBIST Enable
 * - DSU_MBENABLE0_ENABLE28 Memory 28 MBIST Enable
 * - DSU_MBENABLE0_ENABLE(value) Memory x MBIST Enable
 **/
static inline void dsu_clear_MBENABLE0(uint32_t mask)
{
	DSU->MBENABLE0.reg &= ~mask;
}

/**
 * @brief dsu read MBENABLE0 register
 *
 * @return uint32_t
 * - DSU_MBENABLE0_ENABLE0 Memory 0 MBIST Enable
 * - DSU_MBENABLE0_ENABLE1 Memory 1 MBIST Enable
 * - DSU_MBENABLE0_ENABLE2 Memory 2 MBIST Enable
 * - DSU_MBENABLE0_ENABLE3 Memory 3 MBIST Enable
 * - DSU_MBENABLE0_ENABLE4 Memory 4 MBIST Enable
 * - DSU_MBENABLE0_ENABLE5 Memory 5 MBIST Enable
 * - DSU_MBENABLE0_ENABLE6 Memory 6 MBIST Enable
 * - DSU_MBENABLE0_ENABLE7 Memory 7 MBIST Enable
 * - DSU_MBENABLE0_ENABLE8 Memory 8 MBIST Enable
 * - DSU_MBENABLE0_ENABLE9 Memory 9 MBIST Enable
 * - DSU_MBENABLE0_ENABLE10 Memory 10 MBIST Enable
 * - DSU_MBENABLE0_ENABLE11 Memory 11 MBIST Enable
 * - DSU_MBENABLE0_ENABLE12 Memory 12 MBIST Enable
 * - DSU_MBENABLE0_ENABLE13 Memory 13 MBIST Enable
 * - DSU_MBENABLE0_ENABLE14 Memory 14 MBIST Enable
 * - DSU_MBENABLE0_ENABLE15 Memory 15 MBIST Enable
 * - DSU_MBENABLE0_ENABLE16 Memory 16 MBIST Enable
 * - DSU_MBENABLE0_ENABLE17 Memory 17 MBIST Enable
 * - DSU_MBENABLE0_ENABLE18 Memory 18 MBIST Enable
 * - DSU_MBENABLE0_ENABLE19 Memory 19 MBIST Enable
 * - DSU_MBENABLE0_ENABLE20 Memory 20 MBIST Enable
 * - DSU_MBENABLE0_ENABLE21 Memory 21 MBIST Enable
 * - DSU_MBENABLE0_ENABLE22 Memory 22 MBIST Enable
 * - DSU_MBENABLE0_ENABLE23 Memory 23 MBIST Enable
 * - DSU_MBENABLE0_ENABLE24 Memory 24 MBIST Enable
 * - DSU_MBENABLE0_ENABLE25 Memory 25 MBIST Enable
 * - DSU_MBENABLE0_ENABLE26 Memory 26 MBIST Enable
 * - DSU_MBENABLE0_ENABLE27 Memory 27 MBIST Enable
 * - DSU_MBENABLE0_ENABLE28 Memory 28 MBIST Enable
 * - DSU_MBENABLE0_ENABLE(value) Memory x MBIST Enable
 **/
static inline uint32_t dsu_read_MBENABLE0(void)
{
	return DSU->MBENABLE0.reg;
}

/**
 * @brief dsu set DCFG register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - DSU_DCFG_DCFG(value) Device Configuration
 **/
static inline void dsu_set_DCFG(uint8_t index, uint32_t mask)
{
	DSU->DCFG[index].reg |= mask;
}

/**
 * @brief dsu get DCFG register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_DCFG_DCFG(value) Device Configuration
 **/
static inline uint32_t dsu_get_DCFG(uint8_t index, uint32_t mask)
{
    return DSU->DCFG[index].reg & mask;
}

/**
 * @brief dsu write DCFG register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - DSU_DCFG_DCFG(value) Device Configuration
 **/
static inline void dsu_write_DCFG(uint8_t index, uint32_t data)
{
	DSU->DCFG[index].reg = data;
}

/**
 * @brief dsu clear DCFG register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - DSU_DCFG_DCFG(value) Device Configuration
 **/
static inline void dsu_clear_DCFG(uint8_t index, uint32_t mask)
{
	DSU->DCFG[index].reg &= ~mask;
}

/**
 * @brief dsu read DCFG register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - DSU_DCFG_DCFG(value) Device Configuration
 **/
static inline uint32_t dsu_read_DCFG(uint8_t index)
{
	return DSU->DCFG[index].reg;
}

/**
 * @brief dsu get STATUSA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - DSU_STATUSA_DONE Done
 * - DSU_STATUSA_CRSTEXT CPU Reset Phase Extension
 * - DSU_STATUSA_BERR Bus Error
 * - DSU_STATUSA_FAIL Failure
 * - DSU_STATUSA_PERR Protection Error
 **/
static inline uint8_t dsu_get_STATUSA(uint8_t mask)
{
    return DSU->STATUSA.reg & mask;
}

/**
 * @brief dsu clear STATUSA register
 *
 * @param[in] mask uint8_t 
 * - DSU_STATUSA_DONE Done
 * - DSU_STATUSA_CRSTEXT CPU Reset Phase Extension
 * - DSU_STATUSA_BERR Bus Error
 * - DSU_STATUSA_FAIL Failure
 * - DSU_STATUSA_PERR Protection Error
 **/
static inline void dsu_clear_STATUSA(uint8_t mask)
{
	DSU->STATUSA.reg = mask;
}

/**
 * @brief dsu read STATUSA register
 *
 * @return uint8_t
 * - DSU_STATUSA_DONE Done
 * - DSU_STATUSA_CRSTEXT CPU Reset Phase Extension
 * - DSU_STATUSA_BERR Bus Error
 * - DSU_STATUSA_FAIL Failure
 * - DSU_STATUSA_PERR Protection Error
 **/
static inline uint8_t dsu_read_STATUSA(void)
{
	return DSU->STATUSA.reg;
}

/**
 * @brief dsu get MBSTATUS0 register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - DSU_MBSTATUS0_STATUS0 Memory 0 MBIST Status
 * - DSU_MBSTATUS0_STATUS1 Memory 1 MBIST Status
 * - DSU_MBSTATUS0_STATUS2 Memory 2 MBIST Status
 * - DSU_MBSTATUS0_STATUS3 Memory 3 MBIST Status
 * - DSU_MBSTATUS0_STATUS4 Memory 4 MBIST Status
 * - DSU_MBSTATUS0_STATUS5 Memory 5 MBIST Status
 * - DSU_MBSTATUS0_STATUS6 Memory 6 MBIST Status
 * - DSU_MBSTATUS0_STATUS7 Memory 7 MBIST Status
 * - DSU_MBSTATUS0_STATUS8 Memory 8 MBIST Status
 * - DSU_MBSTATUS0_STATUS9 Memory 9 MBIST Status
 * - DSU_MBSTATUS0_STATUS10 Memory 10 MBIST Status
 * - DSU_MBSTATUS0_STATUS11 Memory 11 MBIST Status
 * - DSU_MBSTATUS0_STATUS12 Memory 12 MBIST Status
 * - DSU_MBSTATUS0_STATUS13 Memory 13 MBIST Status
 * - DSU_MBSTATUS0_STATUS14 Memory 14 MBIST Status
 * - DSU_MBSTATUS0_STATUS15 Memory 15 MBIST Status
 * - DSU_MBSTATUS0_STATUS16 Memory 16 MBIST Status
 * - DSU_MBSTATUS0_STATUS17 Memory 17 MBIST Status
 * - DSU_MBSTATUS0_STATUS18 Memory 18 MBIST Status
 * - DSU_MBSTATUS0_STATUS19 Memory 19 MBIST Status
 * - DSU_MBSTATUS0_STATUS20 Memory 20 MBIST Status
 * - DSU_MBSTATUS0_STATUS21 Memory 21 MBIST Status
 * - DSU_MBSTATUS0_STATUS22 Memory 22 MBIST Status
 * - DSU_MBSTATUS0_STATUS23 Memory 23 MBIST Status
 * - DSU_MBSTATUS0_STATUS24 Memory 24 MBIST Status
 * - DSU_MBSTATUS0_STATUS25 Memory 25 MBIST Status
 * - DSU_MBSTATUS0_STATUS26 Memory 26 MBIST Status
 * - DSU_MBSTATUS0_STATUS27 Memory 27 MBIST Status
 * - DSU_MBSTATUS0_STATUS28 Memory 28 MBIST Status
 * - DSU_MBSTATUS0_STATUS(value) Memory x MBIST Status
 **/
static inline uint32_t dsu_get_MBSTATUS0(uint32_t mask)
{
    return DSU->MBSTATUS0.reg & mask;
}

/**
 * @brief dsu clear MBSTATUS0 register
 *
 * @param[in] mask uint32_t 
 * - DSU_MBSTATUS0_STATUS0 Memory 0 MBIST Status
 * - DSU_MBSTATUS0_STATUS1 Memory 1 MBIST Status
 * - DSU_MBSTATUS0_STATUS2 Memory 2 MBIST Status
 * - DSU_MBSTATUS0_STATUS3 Memory 3 MBIST Status
 * - DSU_MBSTATUS0_STATUS4 Memory 4 MBIST Status
 * - DSU_MBSTATUS0_STATUS5 Memory 5 MBIST Status
 * - DSU_MBSTATUS0_STATUS6 Memory 6 MBIST Status
 * - DSU_MBSTATUS0_STATUS7 Memory 7 MBIST Status
 * - DSU_MBSTATUS0_STATUS8 Memory 8 MBIST Status
 * - DSU_MBSTATUS0_STATUS9 Memory 9 MBIST Status
 * - DSU_MBSTATUS0_STATUS10 Memory 10 MBIST Status
 * - DSU_MBSTATUS0_STATUS11 Memory 11 MBIST Status
 * - DSU_MBSTATUS0_STATUS12 Memory 12 MBIST Status
 * - DSU_MBSTATUS0_STATUS13 Memory 13 MBIST Status
 * - DSU_MBSTATUS0_STATUS14 Memory 14 MBIST Status
 * - DSU_MBSTATUS0_STATUS15 Memory 15 MBIST Status
 * - DSU_MBSTATUS0_STATUS16 Memory 16 MBIST Status
 * - DSU_MBSTATUS0_STATUS17 Memory 17 MBIST Status
 * - DSU_MBSTATUS0_STATUS18 Memory 18 MBIST Status
 * - DSU_MBSTATUS0_STATUS19 Memory 19 MBIST Status
 * - DSU_MBSTATUS0_STATUS20 Memory 20 MBIST Status
 * - DSU_MBSTATUS0_STATUS21 Memory 21 MBIST Status
 * - DSU_MBSTATUS0_STATUS22 Memory 22 MBIST Status
 * - DSU_MBSTATUS0_STATUS23 Memory 23 MBIST Status
 * - DSU_MBSTATUS0_STATUS24 Memory 24 MBIST Status
 * - DSU_MBSTATUS0_STATUS25 Memory 25 MBIST Status
 * - DSU_MBSTATUS0_STATUS26 Memory 26 MBIST Status
 * - DSU_MBSTATUS0_STATUS27 Memory 27 MBIST Status
 * - DSU_MBSTATUS0_STATUS28 Memory 28 MBIST Status
 * - DSU_MBSTATUS0_STATUS(value) Memory x MBIST Status
 **/
static inline void dsu_clear_MBSTATUS0(uint32_t mask)
{
	DSU->MBSTATUS0.reg = mask;
}

/**
 * @brief dsu read MBSTATUS0 register
 *
 * @return uint32_t
 * - DSU_MBSTATUS0_STATUS0 Memory 0 MBIST Status
 * - DSU_MBSTATUS0_STATUS1 Memory 1 MBIST Status
 * - DSU_MBSTATUS0_STATUS2 Memory 2 MBIST Status
 * - DSU_MBSTATUS0_STATUS3 Memory 3 MBIST Status
 * - DSU_MBSTATUS0_STATUS4 Memory 4 MBIST Status
 * - DSU_MBSTATUS0_STATUS5 Memory 5 MBIST Status
 * - DSU_MBSTATUS0_STATUS6 Memory 6 MBIST Status
 * - DSU_MBSTATUS0_STATUS7 Memory 7 MBIST Status
 * - DSU_MBSTATUS0_STATUS8 Memory 8 MBIST Status
 * - DSU_MBSTATUS0_STATUS9 Memory 9 MBIST Status
 * - DSU_MBSTATUS0_STATUS10 Memory 10 MBIST Status
 * - DSU_MBSTATUS0_STATUS11 Memory 11 MBIST Status
 * - DSU_MBSTATUS0_STATUS12 Memory 12 MBIST Status
 * - DSU_MBSTATUS0_STATUS13 Memory 13 MBIST Status
 * - DSU_MBSTATUS0_STATUS14 Memory 14 MBIST Status
 * - DSU_MBSTATUS0_STATUS15 Memory 15 MBIST Status
 * - DSU_MBSTATUS0_STATUS16 Memory 16 MBIST Status
 * - DSU_MBSTATUS0_STATUS17 Memory 17 MBIST Status
 * - DSU_MBSTATUS0_STATUS18 Memory 18 MBIST Status
 * - DSU_MBSTATUS0_STATUS19 Memory 19 MBIST Status
 * - DSU_MBSTATUS0_STATUS20 Memory 20 MBIST Status
 * - DSU_MBSTATUS0_STATUS21 Memory 21 MBIST Status
 * - DSU_MBSTATUS0_STATUS22 Memory 22 MBIST Status
 * - DSU_MBSTATUS0_STATUS23 Memory 23 MBIST Status
 * - DSU_MBSTATUS0_STATUS24 Memory 24 MBIST Status
 * - DSU_MBSTATUS0_STATUS25 Memory 25 MBIST Status
 * - DSU_MBSTATUS0_STATUS26 Memory 26 MBIST Status
 * - DSU_MBSTATUS0_STATUS27 Memory 27 MBIST Status
 * - DSU_MBSTATUS0_STATUS28 Memory 28 MBIST Status
 * - DSU_MBSTATUS0_STATUS(value) Memory x MBIST Status
 **/
static inline uint32_t dsu_read_MBSTATUS0(void)
{
	return DSU->MBSTATUS0.reg;
}

/**
 * @brief dsu write CTRL register
 *
 * @param[in] data uint8_t 
 * - DSU_CTRL_SWRST Software Reset
 * - DSU_CTRL_CRC 32-bit Cyclic Redundancy Code
 * - DSU_CTRL_MBIST Memory built-in self-test
 * - DSU_CTRL_CE Chip-Erase
 * - DSU_CTRL_ARR Auxiliary Row Read
 * - DSU_CTRL_SMSA Start Memory Stream Access
 **/
static inline void dsu_write_CTRL(uint8_t data)
{
	DSU->CTRL.reg = data;
}

#endif /* _DSU_H */
