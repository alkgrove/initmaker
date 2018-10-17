/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM EVSYS
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

#ifndef _EVSYS_H_
#define _EVSYS_H_

#include <stdbool.h>

#define EVSYS_CHANNEL0    0
#define EVSYS_CHANNEL1    1
#define EVSYS_CHANNEL2    2
#define EVSYS_CHANNEL3    3
#define EVSYS_CHANNEL4    4
#define EVSYS_CHANNEL5    5
#define EVSYS_CHANNEL6    6
#define EVSYS_CHANNEL7    7
#define EVSYS_CHANNEL8    8
#define EVSYS_CHANNEL9    9
#define EVSYS_CHANNEL10    10
#define EVSYS_CHANNEL11    11
#define EVSYS_CHANNEL12    12
#define EVSYS_CHANNEL13    13
#define EVSYS_CHANNEL14    14
#define EVSYS_CHANNEL15    15
#define EVSYS_CHANNEL16    16
#define EVSYS_CHANNEL17    17
#define EVSYS_CHANNEL18    18
#define EVSYS_CHANNEL19    19
#define EVSYS_CHANNEL20    20
#define EVSYS_CHANNEL21    21
#define EVSYS_CHANNEL22    22
#define EVSYS_CHANNEL23    23
#define EVSYS_CHANNEL24    24
#define EVSYS_CHANNEL25    25
#define EVSYS_CHANNEL26    26
#define EVSYS_CHANNEL27    27
#define EVSYS_CHANNEL28    28
#define EVSYS_CHANNEL29    29
#define EVSYS_CHANNEL30    30
#define EVSYS_CHANNEL31    31

#define EVSYS_USER_CHANNEL_NONE  0
#define EVSYS_USER_CHANNEL0	   1
#define EVSYS_USER_CHANNEL1	   2
#define EVSYS_USER_CHANNEL2	   3
#define EVSYS_USER_CHANNEL3	   4
#define EVSYS_USER_CHANNEL4	   5
#define EVSYS_USER_CHANNEL5	   6
#define EVSYS_USER_CHANNEL6	   7
#define EVSYS_USER_CHANNEL7	   8
#define EVSYS_USER_CHANNEL8	   9
#define EVSYS_USER_CHANNEL9	   10
#define EVSYS_USER_CHANNEL10	   11
#define EVSYS_USER_CHANNEL11	   12
#define EVSYS_USER_CHANNEL12	   13
#define EVSYS_USER_CHANNEL13	   14
#define EVSYS_USER_CHANNEL14	   15
#define EVSYS_USER_CHANNEL15	   16
#define EVSYS_USER_CHANNEL16	   17
#define EVSYS_USER_CHANNEL17	   18
#define EVSYS_USER_CHANNEL18	   19
#define EVSYS_USER_CHANNEL19	   20
#define EVSYS_USER_CHANNEL20	   21
#define EVSYS_USER_CHANNEL21	   22
#define EVSYS_USER_CHANNEL22	   23
#define EVSYS_USER_CHANNEL23	   24
#define EVSYS_USER_CHANNEL24	   25
#define EVSYS_USER_CHANNEL25	   26
#define EVSYS_USER_CHANNEL26	   27
#define EVSYS_USER_CHANNEL27	   28
#define EVSYS_USER_CHANNEL28	   29
#define EVSYS_USER_CHANNEL29	   30
#define EVSYS_USER_CHANNEL30	   31
#define EVSYS_USER_CHANNEL31	   32

/**
 * @brief enable EVSYS USER register
 * It has a companion function evsys_disable_USER(channel)
 * @param[in] user_id uint8_t
 * - EVSYS_ID_USER_RTC_TAMPER
 * - EVSYS_ID_USER_PORT_EV_0
 * - EVSYS_ID_USER_PORT_EV_1
 * - EVSYS_ID_USER_PORT_EV_2
 * - EVSYS_ID_USER_PORT_EV_3
 * - EVSYS_ID_USER_DMAC_CH_0
 * - EVSYS_ID_USER_DMAC_CH_1
 * - EVSYS_ID_USER_DMAC_CH_2
 * - EVSYS_ID_USER_DMAC_CH_3
 * - EVSYS_ID_USER_DMAC_CH_4
 * - EVSYS_ID_USER_DMAC_CH_5
 * - EVSYS_ID_USER_DMAC_CH_6
 * - EVSYS_ID_USER_DMAC_CH_7
 * - EVSYS_ID_USER_TAL_BRK
 * - EVSYS_ID_USER_CM4_TRACE_START
 * - EVSYS_ID_USER_CM4_TRACE_STOP
 * - EVSYS_ID_USER_CM4_TRACE_TRIG
 * - EVSYS_ID_USER_TCC0_EV_0
 * - EVSYS_ID_USER_TCC0_EV_1
 * - EVSYS_ID_USER_TCC0_MC_0
 * - EVSYS_ID_USER_TCC0_MC_1
 * - EVSYS_ID_USER_TCC0_MC_2
 * - EVSYS_ID_USER_TCC0_MC_3
 * - EVSYS_ID_USER_TCC0_MC_4
 * - EVSYS_ID_USER_TCC0_MC_5
 * - EVSYS_ID_USER_TCC1_EV_0
 * - EVSYS_ID_USER_TCC1_EV_1
 * - EVSYS_ID_USER_TCC1_MC_0
 * - EVSYS_ID_USER_TCC1_MC_1
 * - EVSYS_ID_USER_TCC1_MC_2
 * - EVSYS_ID_USER_TCC1_MC_3
 * - EVSYS_ID_USER_TCC2_EV_0
 * - EVSYS_ID_USER_TCC2_EV_1
 * - EVSYS_ID_USER_TCC2_MC_0
 * - EVSYS_ID_USER_TCC2_MC_1
 * - EVSYS_ID_USER_TCC2_MC_2
 * - EVSYS_ID_USER_TCC3_EV_0
 * - EVSYS_ID_USER_TCC3_EV_1
 * - EVSYS_ID_USER_TCC3_MC_0
 * - EVSYS_ID_USER_TCC3_MC_1
 * - EVSYS_ID_USER_TCC4_EV_0
 * - EVSYS_ID_USER_TCC4_EV_1
 * - EVSYS_ID_USER_TCC4_MC_0
 * - EVSYS_ID_USER_TCC4_MC_1
 * - EVSYS_ID_USER_TC0_EVU
 * - EVSYS_ID_USER_TC1_EVU
 * - EVSYS_ID_USER_TC2_EVU
 * - EVSYS_ID_USER_TC3_EVU
 * - EVSYS_ID_USER_TC4_EVU
 * - EVSYS_ID_USER_TC5_EVU
 * - EVSYS_ID_USER_TC6_EVU
 * - EVSYS_ID_USER_TC7_EVU
 * - EVSYS_ID_USER_PDEC_EVU_0
 * - EVSYS_ID_USER_PDEC_EVU_1
 * - EVSYS_ID_USER_PDEC_EVU_2
 * - EVSYS_ID_USER_ADC0_START
 * - EVSYS_ID_USER_ADC0_SYNC
 * - EVSYS_ID_USER_ADC1_START
 * - EVSYS_ID_USER_ADC1_SYNC
 * - EVSYS_ID_USER_AC_SOC_0
 * - EVSYS_ID_USER_AC_SOC_1
 * - EVSYS_ID_USER_DAC_START_0
 * - EVSYS_ID_USER_DAC_START_1
 * - EVSYS_ID_USER_CCL_LUTIN_0
 * - EVSYS_ID_USER_CCL_LUTIN_1
 * - EVSYS_ID_USER_CCL_LUTIN_2
 * - EVSYS_ID_USER_CCL_LUTIN_3
 * @param[in] channel uint8_t 
 * - EVSYS_EVSYS_USER_CHANNEL(value) EVSYS_CHANNEL_n (0..31)
 */
static inline void evsys_enable_USER(uint8_t user_id, uint32_t channel)
{
	EVSYS->USER[user_id].reg = channel + 1;
}
/**
 * @brief disable EVSYS USER channel
 * This is different than other sets in that it isn't a mask
 * rather it offsets the other channels to match numerically
 * It has a companion function evsys_enable_USER(channel)
 * @param[in] user_id uint8_t
 * EVSYS_EVSYS_USER_CHANNEL(value) EVSYS_CHANNEL_n (0..31)
 */
static inline void evsys_disable_USER(uint8_t user_id)
{
	EVSYS->USER[user_id].reg = EVSYS_USER_CHANNEL_NONE;
}

/**
 * @brief evsys write SWEVT register
 *
 * @param[in] data uint32_t 
 * - EVSYS_SWEVT_CHANNEL0 Channel 0 Software Selection
 * - EVSYS_SWEVT_CHANNEL1 Channel 1 Software Selection
 * - EVSYS_SWEVT_CHANNEL2 Channel 2 Software Selection
 * - EVSYS_SWEVT_CHANNEL3 Channel 3 Software Selection
 * - EVSYS_SWEVT_CHANNEL4 Channel 4 Software Selection
 * - EVSYS_SWEVT_CHANNEL5 Channel 5 Software Selection
 * - EVSYS_SWEVT_CHANNEL6 Channel 6 Software Selection
 * - EVSYS_SWEVT_CHANNEL7 Channel 7 Software Selection
 * - EVSYS_SWEVT_CHANNEL8 Channel 8 Software Selection
 * - EVSYS_SWEVT_CHANNEL9 Channel 9 Software Selection
 * - EVSYS_SWEVT_CHANNEL10 Channel 10 Software Selection
 * - EVSYS_SWEVT_CHANNEL11 Channel 11 Software Selection
 * - EVSYS_SWEVT_CHANNEL12 Channel 12 Software Selection
 * - EVSYS_SWEVT_CHANNEL13 Channel 13 Software Selection
 * - EVSYS_SWEVT_CHANNEL14 Channel 14 Software Selection
 * - EVSYS_SWEVT_CHANNEL15 Channel 15 Software Selection
 * - EVSYS_SWEVT_CHANNEL16 Channel 16 Software Selection
 * - EVSYS_SWEVT_CHANNEL17 Channel 17 Software Selection
 * - EVSYS_SWEVT_CHANNEL18 Channel 18 Software Selection
 * - EVSYS_SWEVT_CHANNEL19 Channel 19 Software Selection
 * - EVSYS_SWEVT_CHANNEL20 Channel 20 Software Selection
 * - EVSYS_SWEVT_CHANNEL21 Channel 21 Software Selection
 * - EVSYS_SWEVT_CHANNEL22 Channel 22 Software Selection
 * - EVSYS_SWEVT_CHANNEL23 Channel 23 Software Selection
 * - EVSYS_SWEVT_CHANNEL24 Channel 24 Software Selection
 * - EVSYS_SWEVT_CHANNEL25 Channel 25 Software Selection
 * - EVSYS_SWEVT_CHANNEL26 Channel 26 Software Selection
 * - EVSYS_SWEVT_CHANNEL27 Channel 27 Software Selection
 * - EVSYS_SWEVT_CHANNEL28 Channel 28 Software Selection
 * - EVSYS_SWEVT_CHANNEL29 Channel 29 Software Selection
 * - EVSYS_SWEVT_CHANNEL30 Channel 30 Software Selection
 * - EVSYS_SWEVT_CHANNEL31 Channel 31 Software Selection
 * - EVSYS_SWEVT_CHANNEL(value) Channel x Software Selection
 **/
static inline void evsys_write_SWEVT(uint32_t data)
{
	EVSYS->SWEVT.reg = data;
}

/**
 * @brief evsys set CTRLA register
 *
 * @param[in] mask uint8_t 
 * - EVSYS_CTRLA_SWRST Software Reset
 **/
static inline void evsys_set_CTRLA(uint8_t mask)
{
	EVSYS->CTRLA.reg |= mask;
}

/**
 * @brief evsys get CTRLA register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - EVSYS_CTRLA_SWRST Software Reset
 **/
static inline uint8_t evsys_get_CTRLA(uint8_t mask)
{
    return EVSYS->CTRLA.reg & mask;
}

/**
 * @brief evsys write CTRLA register
 *
 * @param[in] data uint8_t 
 * - EVSYS_CTRLA_SWRST Software Reset
 **/
static inline void evsys_write_CTRLA(uint8_t data)
{
	EVSYS->CTRLA.reg = data;
}

/**
 * @brief evsys clear CTRLA register
 *
 * @param[in] mask uint8_t 
 * - EVSYS_CTRLA_SWRST Software Reset
 **/
static inline void evsys_clear_CTRLA(uint8_t mask)
{
	EVSYS->CTRLA.reg &= ~mask;
}

/**
 * @brief evsys read CTRLA register
 *
 * @return uint8_t
 * - EVSYS_CTRLA_SWRST Software Reset
 **/
static inline uint8_t evsys_read_CTRLA(void)
{
	return EVSYS->CTRLA.reg;
}

/**
 * @brief evsys set PRICTRL register
 *
 * @param[in] mask uint8_t 
 * - EVSYS_PRICTRL_PRI(value) Channel Priority Number
 * - EVSYS_PRICTRL_RREN Round-Robin Scheduling Enable
 **/
static inline void evsys_set_PRICTRL(uint8_t mask)
{
	EVSYS->PRICTRL.reg |= mask;
}

/**
 * @brief evsys get PRICTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - EVSYS_PRICTRL_PRI(value) Channel Priority Number
 * - EVSYS_PRICTRL_RREN Round-Robin Scheduling Enable
 **/
static inline uint8_t evsys_get_PRICTRL(uint8_t mask)
{
    return EVSYS->PRICTRL.reg & mask;
}

/**
 * @brief evsys write PRICTRL register
 *
 * @param[in] data uint8_t 
 * - EVSYS_PRICTRL_PRI(value) Channel Priority Number
 * - EVSYS_PRICTRL_RREN Round-Robin Scheduling Enable
 **/
static inline void evsys_write_PRICTRL(uint8_t data)
{
	EVSYS->PRICTRL.reg = data;
}

/**
 * @brief evsys clear PRICTRL register
 *
 * @param[in] mask uint8_t 
 * - EVSYS_PRICTRL_PRI(value) Channel Priority Number
 * - EVSYS_PRICTRL_RREN Round-Robin Scheduling Enable
 **/
static inline void evsys_clear_PRICTRL(uint8_t mask)
{
	EVSYS->PRICTRL.reg &= ~mask;
}

/**
 * @brief evsys read PRICTRL register
 *
 * @return uint8_t
 * - EVSYS_PRICTRL_PRI(value) Channel Priority Number
 * - EVSYS_PRICTRL_RREN Round-Robin Scheduling Enable
 **/
static inline uint8_t evsys_read_PRICTRL(void)
{
	return EVSYS->PRICTRL.reg;
}

/**
 * @brief evsys set INTPEND register
 *
 * @param[in] mask uint16_t 
 * - EVSYS_INTPEND_ID(value) Channel ID
 * - EVSYS_INTPEND_OVR Channel Overrun
 * - EVSYS_INTPEND_EVD Channel Event Detected
 * - EVSYS_INTPEND_READY Ready
 * - EVSYS_INTPEND_BUSY Busy
 **/
static inline void evsys_set_INTPEND(uint16_t mask)
{
	EVSYS->INTPEND.reg |= mask;
}

/**
 * @brief evsys get INTPEND register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - EVSYS_INTPEND_ID(value) Channel ID
 * - EVSYS_INTPEND_OVR Channel Overrun
 * - EVSYS_INTPEND_EVD Channel Event Detected
 * - EVSYS_INTPEND_READY Ready
 * - EVSYS_INTPEND_BUSY Busy
 **/
static inline uint16_t evsys_get_INTPEND(uint16_t mask)
{
    return EVSYS->INTPEND.reg & mask;
}

/**
 * @brief evsys write INTPEND register
 *
 * @param[in] data uint16_t 
 * - EVSYS_INTPEND_ID(value) Channel ID
 * - EVSYS_INTPEND_OVR Channel Overrun
 * - EVSYS_INTPEND_EVD Channel Event Detected
 * - EVSYS_INTPEND_READY Ready
 * - EVSYS_INTPEND_BUSY Busy
 **/
static inline void evsys_write_INTPEND(uint16_t data)
{
	EVSYS->INTPEND.reg = data;
}

/**
 * @brief evsys clear INTPEND register
 *
 * @param[in] mask uint16_t 
 * - EVSYS_INTPEND_ID(value) Channel ID
 * - EVSYS_INTPEND_OVR Channel Overrun
 * - EVSYS_INTPEND_EVD Channel Event Detected
 * - EVSYS_INTPEND_READY Ready
 * - EVSYS_INTPEND_BUSY Busy
 **/
static inline void evsys_clear_INTPEND(uint16_t mask)
{
	EVSYS->INTPEND.reg &= ~mask;
}

/**
 * @brief evsys read INTPEND register
 *
 * @return uint16_t
 * - EVSYS_INTPEND_ID(value) Channel ID
 * - EVSYS_INTPEND_OVR Channel Overrun
 * - EVSYS_INTPEND_EVD Channel Event Detected
 * - EVSYS_INTPEND_READY Ready
 * - EVSYS_INTPEND_BUSY Busy
 **/
static inline uint16_t evsys_read_INTPEND(void)
{
	return EVSYS->INTPEND.reg;
}

/**
 * @brief evsys set USER register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - EVSYS_USER_CHANNEL(value) Channel Event Selection
 **/
static inline void evsys_set_USER(uint8_t index, uint32_t mask)
{
	EVSYS->USER[index].reg |= mask;
}

/**
 * @brief evsys write USER register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - EVSYS_USER_CHANNEL(value) Channel Event Selection
 **/
static inline void evsys_write_USER(uint8_t index, uint32_t data)
{
	EVSYS->USER[index].reg = data;
}

/**
 * @brief evsys read USER register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - EVSYS_USER_CHANNEL(value) Channel Event Selection
 **/
static inline uint32_t evsys_read_USER(uint8_t index)
{
	return EVSYS->USER[index].reg;
}

/**
 * @brief evsys get INTSTATUS register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EVSYS_INTSTATUS_CHINT0 Channel 0 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT1 Channel 1 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT2 Channel 2 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT3 Channel 3 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT4 Channel 4 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT5 Channel 5 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT6 Channel 6 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT7 Channel 7 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT8 Channel 8 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT9 Channel 9 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT10 Channel 10 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT11 Channel 11 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT(value) Channel x Pending Interrupt
 **/
static inline uint32_t evsys_get_INTSTATUS(uint32_t mask)
{
    return EVSYS->INTSTATUS.reg & mask;
}

/**
 * @brief evsys read INTSTATUS register
 *
 * @return uint32_t
 * - EVSYS_INTSTATUS_CHINT0 Channel 0 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT1 Channel 1 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT2 Channel 2 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT3 Channel 3 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT4 Channel 4 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT5 Channel 5 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT6 Channel 6 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT7 Channel 7 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT8 Channel 8 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT9 Channel 9 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT10 Channel 10 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT11 Channel 11 Pending Interrupt
 * - EVSYS_INTSTATUS_CHINT(value) Channel x Pending Interrupt
 **/
static inline uint32_t evsys_read_INTSTATUS(void)
{
	return EVSYS->INTSTATUS.reg;
}

/**
 * @brief evsys get BUSYCH register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EVSYS_BUSYCH_BUSYCH0 Busy Channel 0
 * - EVSYS_BUSYCH_BUSYCH1 Busy Channel 1
 * - EVSYS_BUSYCH_BUSYCH2 Busy Channel 2
 * - EVSYS_BUSYCH_BUSYCH3 Busy Channel 3
 * - EVSYS_BUSYCH_BUSYCH4 Busy Channel 4
 * - EVSYS_BUSYCH_BUSYCH5 Busy Channel 5
 * - EVSYS_BUSYCH_BUSYCH6 Busy Channel 6
 * - EVSYS_BUSYCH_BUSYCH7 Busy Channel 7
 * - EVSYS_BUSYCH_BUSYCH8 Busy Channel 8
 * - EVSYS_BUSYCH_BUSYCH9 Busy Channel 9
 * - EVSYS_BUSYCH_BUSYCH10 Busy Channel 10
 * - EVSYS_BUSYCH_BUSYCH11 Busy Channel 11
 * - EVSYS_BUSYCH_BUSYCH(value) Busy Channel x
 **/
static inline uint32_t evsys_get_BUSYCH(uint32_t mask)
{
    return EVSYS->BUSYCH.reg & mask;
}

/**
 * @brief evsys read BUSYCH register
 *
 * @return uint32_t
 * - EVSYS_BUSYCH_BUSYCH0 Busy Channel 0
 * - EVSYS_BUSYCH_BUSYCH1 Busy Channel 1
 * - EVSYS_BUSYCH_BUSYCH2 Busy Channel 2
 * - EVSYS_BUSYCH_BUSYCH3 Busy Channel 3
 * - EVSYS_BUSYCH_BUSYCH4 Busy Channel 4
 * - EVSYS_BUSYCH_BUSYCH5 Busy Channel 5
 * - EVSYS_BUSYCH_BUSYCH6 Busy Channel 6
 * - EVSYS_BUSYCH_BUSYCH7 Busy Channel 7
 * - EVSYS_BUSYCH_BUSYCH8 Busy Channel 8
 * - EVSYS_BUSYCH_BUSYCH9 Busy Channel 9
 * - EVSYS_BUSYCH_BUSYCH10 Busy Channel 10
 * - EVSYS_BUSYCH_BUSYCH11 Busy Channel 11
 * - EVSYS_BUSYCH_BUSYCH(value) Busy Channel x
 **/
static inline uint32_t evsys_read_BUSYCH(void)
{
	return EVSYS->BUSYCH.reg;
}

/**
 * @brief evsys get READYUSR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EVSYS_READYUSR_READYUSR0 Ready User for Channel 0
 * - EVSYS_READYUSR_READYUSR1 Ready User for Channel 1
 * - EVSYS_READYUSR_READYUSR2 Ready User for Channel 2
 * - EVSYS_READYUSR_READYUSR3 Ready User for Channel 3
 * - EVSYS_READYUSR_READYUSR4 Ready User for Channel 4
 * - EVSYS_READYUSR_READYUSR5 Ready User for Channel 5
 * - EVSYS_READYUSR_READYUSR6 Ready User for Channel 6
 * - EVSYS_READYUSR_READYUSR7 Ready User for Channel 7
 * - EVSYS_READYUSR_READYUSR8 Ready User for Channel 8
 * - EVSYS_READYUSR_READYUSR9 Ready User for Channel 9
 * - EVSYS_READYUSR_READYUSR10 Ready User for Channel 10
 * - EVSYS_READYUSR_READYUSR11 Ready User for Channel 11
 * - EVSYS_READYUSR_READYUSR(value) Ready User for Channel x
 **/
static inline uint32_t evsys_get_READYUSR(uint32_t mask)
{
    return EVSYS->READYUSR.reg & mask;
}

/**
 * @brief evsys read READYUSR register
 *
 * @return uint32_t
 * - EVSYS_READYUSR_READYUSR0 Ready User for Channel 0
 * - EVSYS_READYUSR_READYUSR1 Ready User for Channel 1
 * - EVSYS_READYUSR_READYUSR2 Ready User for Channel 2
 * - EVSYS_READYUSR_READYUSR3 Ready User for Channel 3
 * - EVSYS_READYUSR_READYUSR4 Ready User for Channel 4
 * - EVSYS_READYUSR_READYUSR5 Ready User for Channel 5
 * - EVSYS_READYUSR_READYUSR6 Ready User for Channel 6
 * - EVSYS_READYUSR_READYUSR7 Ready User for Channel 7
 * - EVSYS_READYUSR_READYUSR8 Ready User for Channel 8
 * - EVSYS_READYUSR_READYUSR9 Ready User for Channel 9
 * - EVSYS_READYUSR_READYUSR10 Ready User for Channel 10
 * - EVSYS_READYUSR_READYUSR11 Ready User for Channel 11
 * - EVSYS_READYUSR_READYUSR(value) Ready User for Channel x
 **/
static inline uint32_t evsys_read_READYUSR(void)
{
	return EVSYS->READYUSR.reg;
}

/**
 * @brief evsys set CHINTEN register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - EVSYS_CHINTENSET_OVR Channel Overrun Interrupt Enable
 * - EVSYS_CHINTENSET_EVD Channel Event Detected Interrupt Enable
 **/
static inline void evsys_set_CHINTEN(uint8_t submodule_index, uint8_t mask)
{
	EVSYS->Channel[submodule_index].CHINTENSET.reg = mask;
}

/**
 * @brief evsys get CHINTEN register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - EVSYS_CHINTENSET_OVR Channel Overrun Interrupt Enable
 * - EVSYS_CHINTENSET_EVD Channel Event Detected Interrupt Enable
 **/
static inline uint8_t evsys_get_CHINTEN(uint8_t submodule_index, uint8_t mask)
{
    return EVSYS->Channel[submodule_index].CHINTENSET.reg & mask;
}

/**
 * @brief evsys read CHINTEN register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint8_t
 * - EVSYS_CHINTENSET_OVR Channel Overrun Interrupt Enable
 * - EVSYS_CHINTENSET_EVD Channel Event Detected Interrupt Enable
 **/
static inline uint8_t evsys_read_CHINTEN(uint8_t submodule_index)
{
	return EVSYS->Channel[submodule_index].CHINTENSET.reg;
}

/**
 * @brief evsys write CHINTEN register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint8_t 
 * - EVSYS_CHINTENSET_OVR Channel Overrun Interrupt Enable
 * - EVSYS_CHINTENSET_EVD Channel Event Detected Interrupt Enable
 **/
static inline void evsys_write_CHINTEN(uint8_t submodule_index, uint8_t data)
{
	EVSYS->Channel[submodule_index].CHINTENSET.reg = data;
	EVSYS->Channel[submodule_index].CHINTENCLR.reg = ~data;
}

/**
 * @brief evsys clear CHINTEN register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - EVSYS_CHINTENSET_OVR Channel Overrun Interrupt Enable
 * - EVSYS_CHINTENSET_EVD Channel Event Detected Interrupt Enable
 **/
static inline void evsys_clear_CHINTEN(uint8_t submodule_index, uint8_t mask)
{
	EVSYS->Channel[submodule_index].CHINTENCLR.reg = mask;
}

/**
 * @brief evsys get CHINTFLAG register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - EVSYS_CHINTFLAG_OVR Channel Overrun
 * - EVSYS_CHINTFLAG_EVD Channel Event Detected
 **/
static inline uint8_t evsys_get_CHINTFLAG(uint8_t submodule_index, uint8_t mask)
{
    return EVSYS->Channel[submodule_index].CHINTFLAG.reg & mask;
}

/**
 * @brief evsys read CHINTFLAG register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint8_t
 * - EVSYS_CHINTFLAG_OVR Channel Overrun
 * - EVSYS_CHINTFLAG_EVD Channel Event Detected
 **/
static inline uint8_t evsys_read_CHINTFLAG(uint8_t submodule_index)
{
	return EVSYS->Channel[submodule_index].CHINTFLAG.reg;
}

/**
 * @brief evsys clear CHINTFLAG register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - EVSYS_CHINTFLAG_OVR Channel Overrun
 * - EVSYS_CHINTFLAG_EVD Channel Event Detected
 **/
static inline void evsys_clear_CHINTFLAG(uint8_t submodule_index, uint8_t mask)
{
	EVSYS->Channel[submodule_index].CHINTFLAG.reg = mask;
}

/**
 * @brief evsys set CHANNEL register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * - EVSYS_CHANNEL_EVGEN(value) Event Generator Selection
 * - EVSYS_CHANNEL_PATH(value) Path Selection
 *  +      EVSYS_CHANNEL_PATH_SYNCHRONOUS Synchronous path
 *  +      EVSYS_CHANNEL_PATH_RESYNCHRONIZED Resynchronized path
 *  +      EVSYS_CHANNEL_PATH_ASYNCHRONOUS Asynchronous path
 * - EVSYS_CHANNEL_EDGSEL(value) Edge Detection Selection
 *  +      EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT No event output when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_RISING_EDGE Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_FALLING_EDGE Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_BOTH_EDGES Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path
 * - EVSYS_CHANNEL_RUNSTDBY Run in standby
 * - EVSYS_CHANNEL_ONDEMAND Generic Clock On Demand
 **/
static inline void evsys_set_CHANNEL(uint8_t submodule_index, uint32_t mask)
{
	EVSYS->Channel[submodule_index].CHANNEL.reg |= mask;
}

/**
 * @brief evsys get CHANNEL register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - EVSYS_CHANNEL_EVGEN(value) Event Generator Selection
 * - EVSYS_CHANNEL_PATH(value) Path Selection
 *  +      EVSYS_CHANNEL_PATH_SYNCHRONOUS Synchronous path
 *  +      EVSYS_CHANNEL_PATH_RESYNCHRONIZED Resynchronized path
 *  +      EVSYS_CHANNEL_PATH_ASYNCHRONOUS Asynchronous path
 * - EVSYS_CHANNEL_EDGSEL(value) Edge Detection Selection
 *  +      EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT No event output when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_RISING_EDGE Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_FALLING_EDGE Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_BOTH_EDGES Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path
 * - EVSYS_CHANNEL_RUNSTDBY Run in standby
 * - EVSYS_CHANNEL_ONDEMAND Generic Clock On Demand
 **/
static inline uint32_t evsys_get_CHANNEL(uint8_t submodule_index, uint32_t mask)
{
    return EVSYS->Channel[submodule_index].CHANNEL.reg & mask;
}

/**
 * @brief evsys write CHANNEL register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint32_t 
 * - EVSYS_CHANNEL_EVGEN(value) Event Generator Selection
 * - EVSYS_CHANNEL_PATH(value) Path Selection
 *  +      EVSYS_CHANNEL_PATH_SYNCHRONOUS Synchronous path
 *  +      EVSYS_CHANNEL_PATH_RESYNCHRONIZED Resynchronized path
 *  +      EVSYS_CHANNEL_PATH_ASYNCHRONOUS Asynchronous path
 * - EVSYS_CHANNEL_EDGSEL(value) Edge Detection Selection
 *  +      EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT No event output when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_RISING_EDGE Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_FALLING_EDGE Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_BOTH_EDGES Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path
 * - EVSYS_CHANNEL_RUNSTDBY Run in standby
 * - EVSYS_CHANNEL_ONDEMAND Generic Clock On Demand
 **/
static inline void evsys_write_CHANNEL(uint8_t submodule_index, uint32_t data)
{
	EVSYS->Channel[submodule_index].CHANNEL.reg = data;
}

/**
 * @brief evsys clear CHANNEL register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * - EVSYS_CHANNEL_EVGEN(value) Event Generator Selection
 * - EVSYS_CHANNEL_PATH(value) Path Selection
 *  +      EVSYS_CHANNEL_PATH_SYNCHRONOUS Synchronous path
 *  +      EVSYS_CHANNEL_PATH_RESYNCHRONIZED Resynchronized path
 *  +      EVSYS_CHANNEL_PATH_ASYNCHRONOUS Asynchronous path
 * - EVSYS_CHANNEL_EDGSEL(value) Edge Detection Selection
 *  +      EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT No event output when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_RISING_EDGE Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_FALLING_EDGE Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_BOTH_EDGES Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path
 * - EVSYS_CHANNEL_RUNSTDBY Run in standby
 * - EVSYS_CHANNEL_ONDEMAND Generic Clock On Demand
 **/
static inline void evsys_clear_CHANNEL(uint8_t submodule_index, uint32_t mask)
{
	EVSYS->Channel[submodule_index].CHANNEL.reg &= ~mask;
}

/**
 * @brief evsys read CHANNEL register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint32_t
 * - EVSYS_CHANNEL_EVGEN(value) Event Generator Selection
 * - EVSYS_CHANNEL_PATH(value) Path Selection
 *  +      EVSYS_CHANNEL_PATH_SYNCHRONOUS Synchronous path
 *  +      EVSYS_CHANNEL_PATH_RESYNCHRONIZED Resynchronized path
 *  +      EVSYS_CHANNEL_PATH_ASYNCHRONOUS Asynchronous path
 * - EVSYS_CHANNEL_EDGSEL(value) Edge Detection Selection
 *  +      EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT No event output when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_RISING_EDGE Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_FALLING_EDGE Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path
 *  +      EVSYS_CHANNEL_EDGSEL_BOTH_EDGES Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path
 * - EVSYS_CHANNEL_RUNSTDBY Run in standby
 * - EVSYS_CHANNEL_ONDEMAND Generic Clock On Demand
 **/
static inline uint32_t evsys_read_CHANNEL(uint8_t submodule_index)
{
	return EVSYS->Channel[submodule_index].CHANNEL.reg;
}

/**
 * @brief evsys get CHSTATUS register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - EVSYS_CHSTATUS_RDYUSR Ready User
 * - EVSYS_CHSTATUS_BUSYCH Busy Channel
 **/
static inline uint8_t evsys_get_CHSTATUS(uint8_t submodule_index, uint8_t mask)
{
    return EVSYS->Channel[submodule_index].CHSTATUS.reg & mask;
}

/**
 * @brief evsys read CHSTATUS register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint8_t
 * - EVSYS_CHSTATUS_RDYUSR Ready User
 * - EVSYS_CHSTATUS_BUSYCH Busy Channel
 **/
static inline uint8_t evsys_read_CHSTATUS(uint8_t submodule_index)
{
	return EVSYS->Channel[submodule_index].CHSTATUS.reg;
}

#endif /* _EVSYS_H */
