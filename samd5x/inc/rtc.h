/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM RTC
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

#ifndef _RTC_H_
#define _RTC_H_

#include <stdbool.h>

/**
 * @brief rtcmode0 wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void rtcmode0_wait_for_sync(uint32_t reg)
{
	while (RTC->MODE0.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief rtcmode0 is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool rtcmode0_is_syncing(uint32_t reg)
{
	return RTC->MODE0.SYNCBUSY.reg & reg;
}

/**
 * @brief rtcmode1 wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void rtcmode1_wait_for_sync(uint32_t reg)
{
	while (RTC->MODE1.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief rtcmode1 is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool rtcmode1_is_syncing(uint32_t reg)
{
	return RTC->MODE1.SYNCBUSY.reg & reg;
}

/**
 * @brief rtcmode2 wait for sync
 *
 * @param[in] reg uint32_t 
 **/
static inline void rtcmode2_wait_for_sync(uint32_t reg)
{
	while (RTC->MODE2.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief rtcmode2 is syncing
 *
 * @param[in] reg uint32_t 
 * @return bool
 **/
static inline bool rtcmode2_is_syncing(uint32_t reg)
{
	return RTC->MODE2.SYNCBUSY.reg & reg;
}

/**
 * @brief rtcalarm set ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline void rtcalarm_set_ALARM(uint8_t submodule_index, uint32_t mask)
{
	((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].ALARM.reg |= mask;
}

/**
 * @brief rtcalarm get ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline uint32_t rtcalarm_get_ALARM(uint8_t submodule_index, uint32_t mask)
{
    return ((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].ALARM.reg & mask;
}

/**
 * @brief rtcalarm write ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline void rtcalarm_write_ALARM(uint8_t submodule_index, uint32_t data)
{
	((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].ALARM.reg = data;
}

/**
 * @brief rtcalarm clear ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline void rtcalarm_clear_ALARM(uint8_t submodule_index, uint32_t mask)
{
	((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].ALARM.reg &= ~mask;
}

/**
 * @brief rtcalarm read ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint32_t
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline uint32_t rtcalarm_read_ALARM(uint8_t submodule_index)
{
	return ((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].ALARM.reg;
}

/**
 * @brief rtcalarm set MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline void rtcalarm_set_MASK(uint8_t submodule_index, uint8_t mask)
{
	((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].MASK.reg |= mask;
}

/**
 * @brief rtcalarm get MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline uint8_t rtcalarm_get_MASK(uint8_t submodule_index, uint8_t mask)
{
    return ((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].MASK.reg & mask;
}

/**
 * @brief rtcalarm write MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint8_t 
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline void rtcalarm_write_MASK(uint8_t submodule_index, uint8_t data)
{
	((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].MASK.reg = data;
}

/**
 * @brief rtcalarm clear MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline void rtcalarm_clear_MASK(uint8_t submodule_index, uint8_t mask)
{
	((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].MASK.reg &= ~mask;
}

/**
 * @brief rtcalarm read MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint8_t
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline uint8_t rtcalarm_read_MASK(uint8_t submodule_index)
{
	return ((RTCMODE2_t *)RTC)->Mode2Alarm[submodule_index].MASK.reg;
}

/**
 * @brief rtcmode2 set ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline void rtcmode2_set_ALARM(uint8_t submodule_index, uint32_t mask)
{
	RTC->MODE2.Mode2Alarm[submodule_index].ALARM.reg |= mask;
}

/**
 * @brief rtcmode2 get ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline uint32_t rtcmode2_get_ALARM(uint8_t submodule_index, uint32_t mask)
{
    return RTC->MODE2.Mode2Alarm[submodule_index].ALARM.reg & mask;
}

/**
 * @brief rtcmode2 write ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline void rtcmode2_write_ALARM(uint8_t submodule_index, uint32_t data)
{
	RTC->MODE2.Mode2Alarm[submodule_index].ALARM.reg = data;
}

/**
 * @brief rtcmode2 clear ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline void rtcmode2_clear_ALARM(uint8_t submodule_index, uint32_t mask)
{
	RTC->MODE2.Mode2Alarm[submodule_index].ALARM.reg &= ~mask;
}

/**
 * @brief rtcmode2 read ALARM register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint32_t
 * - RTC_MODE2_ALARM_SECOND(value) Second
 * - RTC_MODE2_ALARM_MINUTE(value) Minute
 * - RTC_MODE2_ALARM_HOUR(value) Hour
 *  +      RTC_MODE2_ALARM_HOUR_AM Morning hour
 *  +      RTC_MODE2_ALARM_HOUR_PM Afternoon hour
 * - RTC_MODE2_ALARM_DAY(value) Day
 * - RTC_MODE2_ALARM_MONTH(value) Month
 * - RTC_MODE2_ALARM_YEAR(value) Year
 **/
static inline uint32_t rtcmode2_read_ALARM(uint8_t submodule_index)
{
	return RTC->MODE2.Mode2Alarm[submodule_index].ALARM.reg;
}

/**
 * @brief rtcmode2 set MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline void rtcmode2_set_MASK(uint8_t submodule_index, uint8_t mask)
{
	RTC->MODE2.Mode2Alarm[submodule_index].MASK.reg |= mask;
}

/**
 * @brief rtcmode2 get MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline uint8_t rtcmode2_get_MASK(uint8_t submodule_index, uint8_t mask)
{
    return RTC->MODE2.Mode2Alarm[submodule_index].MASK.reg & mask;
}

/**
 * @brief rtcmode2 write MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] data uint8_t 
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline void rtcmode2_write_MASK(uint8_t submodule_index, uint8_t data)
{
	RTC->MODE2.Mode2Alarm[submodule_index].MASK.reg = data;
}

/**
 * @brief rtcmode2 clear MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @param[in] mask uint8_t 
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline void rtcmode2_clear_MASK(uint8_t submodule_index, uint8_t mask)
{
	RTC->MODE2.Mode2Alarm[submodule_index].MASK.reg &= ~mask;
}

/**
 * @brief rtcmode2 read MASK register
 *
 * @param[in] submodule_index uint8_t 
 * @return uint8_t
 * - RTC_MODE2_MASK_SEL(value) Alarm Mask Selection
 *  +      RTC_MODE2_MASK_SEL_OFF Alarm Disabled
 *  +      RTC_MODE2_MASK_SEL_SS Match seconds only
 *  +      RTC_MODE2_MASK_SEL_MMSS Match seconds and minutes only
 *  +      RTC_MODE2_MASK_SEL_HHMMSS Match seconds, minutes, and hours only
 *  +      RTC_MODE2_MASK_SEL_DDHHMMSS Match seconds, minutes, hours, and days only
 *  +      RTC_MODE2_MASK_SEL_MMDDHHMMSS Match seconds, minutes, hours, days, and months only
 *  +      RTC_MODE2_MASK_SEL_YYMMDDHHMMSS Match seconds, minutes, hours, days, months, and years
 **/
static inline uint8_t rtcmode2_read_MASK(uint8_t submodule_index)
{
	return RTC->MODE2.Mode2Alarm[submodule_index].MASK.reg;
}

/**
 * @brief rtcmode2 set INTEN register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode2_set_INTEN(uint16_t mask)
{
	RTC->MODE2.INTENSET.reg = mask;
}

/**
 * @brief rtcmode2 get INTEN register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline uint16_t rtcmode2_get_INTEN(uint16_t mask)
{
    return RTC->MODE2.INTENSET.reg & mask;
}

/**
 * @brief rtcmode2 read INTEN register
 *
 * @return uint16_t
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline uint16_t rtcmode2_read_INTEN(void)
{
	return RTC->MODE2.INTENSET.reg;
}

/**
 * @brief rtcmode2 write INTEN register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode2_write_INTEN(uint16_t data)
{
	RTC->MODE2.INTENSET.reg = data;
	RTC->MODE2.INTENCLR.reg = ~data;
}

/**
 * @brief rtcmode2 clear INTEN register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode2_clear_INTEN(uint16_t mask)
{
	RTC->MODE2.INTENCLR.reg = mask;
}

/**
 * @brief rtcmode2 get INTFLAG register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline uint16_t rtcmode2_get_INTFLAG(uint16_t mask)
{
    return RTC->MODE2.INTFLAG.reg & mask;
}

/**
 * @brief rtcmode2 read INTFLAG register
 *
 * @return uint16_t
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline uint16_t rtcmode2_read_INTFLAG(void)
{
	return RTC->MODE2.INTFLAG.reg;
}

/**
 * @brief rtcmode2 clear INTFLAG register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline void rtcmode2_clear_INTFLAG(uint16_t mask)
{
	RTC->MODE2.INTFLAG.reg = mask;
}

/**
 * @brief rtcmode2 set CTRLA register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode2_set_CTRLA(uint16_t mask)
{
	RTC->MODE2.CTRLA.reg |= mask;
}

/**
 * @brief rtcmode2 get CTRLA register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline uint16_t rtcmode2_get_CTRLA(uint16_t mask)
{
    return RTC->MODE2.CTRLA.reg & mask;
}

/**
 * @brief rtcmode2 write CTRLA register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode2_write_CTRLA(uint16_t data)
{
	RTC->MODE2.CTRLA.reg = data;
}

/**
 * @brief rtcmode2 clear CTRLA register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode2_clear_CTRLA(uint16_t mask)
{
	RTC->MODE2.CTRLA.reg &= ~mask;
}

/**
 * @brief rtcmode2 read CTRLA register
 *
 * @return uint16_t
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline uint16_t rtcmode2_read_CTRLA(void)
{
	return RTC->MODE2.CTRLA.reg;
}

/**
 * @brief rtcmode2 set CTRLB register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode2_set_CTRLB(uint16_t mask)
{
	RTC->MODE2.CTRLB.reg |= mask;
}

/**
 * @brief rtcmode2 get CTRLB register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline uint16_t rtcmode2_get_CTRLB(uint16_t mask)
{
    return RTC->MODE2.CTRLB.reg & mask;
}

/**
 * @brief rtcmode2 write CTRLB register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode2_write_CTRLB(uint16_t data)
{
	RTC->MODE2.CTRLB.reg = data;
}

/**
 * @brief rtcmode2 clear CTRLB register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode2_clear_CTRLB(uint16_t mask)
{
	RTC->MODE2.CTRLB.reg &= ~mask;
}

/**
 * @brief rtcmode2 read CTRLB register
 *
 * @return uint16_t
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline uint16_t rtcmode2_read_CTRLB(void)
{
	return RTC->MODE2.CTRLB.reg;
}

/**
 * @brief rtcmode2 set EVCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode2_set_EVCTRL(uint32_t mask)
{
	RTC->MODE2.EVCTRL.reg |= mask;
}

/**
 * @brief rtcmode2 get EVCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline uint32_t rtcmode2_get_EVCTRL(uint32_t mask)
{
    return RTC->MODE2.EVCTRL.reg & mask;
}

/**
 * @brief rtcmode2 write EVCTRL register
 *
 * @param[in] data uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode2_write_EVCTRL(uint32_t data)
{
	RTC->MODE2.EVCTRL.reg = data;
}

/**
 * @brief rtcmode2 clear EVCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode2_clear_EVCTRL(uint32_t mask)
{
	RTC->MODE2.EVCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode2 read EVCTRL register
 *
 * @return uint32_t
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline uint32_t rtcmode2_read_EVCTRL(void)
{
	return RTC->MODE2.EVCTRL.reg;
}

/**
 * @brief rtcmode2 set DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode2_set_DBGCTRL(uint8_t mask)
{
	RTC->MODE2.DBGCTRL.reg |= mask;
}

/**
 * @brief rtcmode2 get DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline uint8_t rtcmode2_get_DBGCTRL(uint8_t mask)
{
    return RTC->MODE2.DBGCTRL.reg & mask;
}

/**
 * @brief rtcmode2 write DBGCTRL register
 *
 * @param[in] data uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode2_write_DBGCTRL(uint8_t data)
{
	RTC->MODE2.DBGCTRL.reg = data;
}

/**
 * @brief rtcmode2 clear DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode2_clear_DBGCTRL(uint8_t mask)
{
	RTC->MODE2.DBGCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode2 read DBGCTRL register
 *
 * @return uint8_t
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline uint8_t rtcmode2_read_DBGCTRL(void)
{
	return RTC->MODE2.DBGCTRL.reg;
}

/**
 * @brief rtcmode2 set FREQCORR register
 *
 * @param[in] mask uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode2_set_FREQCORR(uint8_t mask)
{
	RTC->MODE2.FREQCORR.reg |= mask;
}

/**
 * @brief rtcmode2 get FREQCORR register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline uint8_t rtcmode2_get_FREQCORR(uint8_t mask)
{
    return RTC->MODE2.FREQCORR.reg & mask;
}

/**
 * @brief rtcmode2 write FREQCORR register
 *
 * @param[in] data uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode2_write_FREQCORR(uint8_t data)
{
	RTC->MODE2.FREQCORR.reg = data;
}

/**
 * @brief rtcmode2 clear FREQCORR register
 *
 * @param[in] mask uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode2_clear_FREQCORR(uint8_t mask)
{
	RTC->MODE2.FREQCORR.reg &= ~mask;
}

/**
 * @brief rtcmode2 read FREQCORR register
 *
 * @return uint8_t
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline uint8_t rtcmode2_read_FREQCORR(void)
{
	return RTC->MODE2.FREQCORR.reg;
}

/**
 * @brief rtcmode2 set CLOCK register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE2_CLOCK_SECOND(value) Second
 * - RTC_MODE2_CLOCK_MINUTE(value) Minute
 * - RTC_MODE2_CLOCK_HOUR(value) Hour
 *  +      RTC_MODE2_CLOCK_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_CLOCK_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_CLOCK_DAY(value) Day
 * - RTC_MODE2_CLOCK_MONTH(value) Month
 * - RTC_MODE2_CLOCK_YEAR(value) Year
 **/
static inline void rtcmode2_set_CLOCK(uint32_t mask)
{
	RTC->MODE2.CLOCK.reg |= mask;
}

/**
 * @brief rtcmode2 get CLOCK register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_CLOCK_SECOND(value) Second
 * - RTC_MODE2_CLOCK_MINUTE(value) Minute
 * - RTC_MODE2_CLOCK_HOUR(value) Hour
 *  +      RTC_MODE2_CLOCK_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_CLOCK_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_CLOCK_DAY(value) Day
 * - RTC_MODE2_CLOCK_MONTH(value) Month
 * - RTC_MODE2_CLOCK_YEAR(value) Year
 **/
static inline uint32_t rtcmode2_get_CLOCK(uint32_t mask)
{
    return RTC->MODE2.CLOCK.reg & mask;
}

/**
 * @brief rtcmode2 write CLOCK register
 *
 * @param[in] data uint32_t 
 * - RTC_MODE2_CLOCK_SECOND(value) Second
 * - RTC_MODE2_CLOCK_MINUTE(value) Minute
 * - RTC_MODE2_CLOCK_HOUR(value) Hour
 *  +      RTC_MODE2_CLOCK_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_CLOCK_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_CLOCK_DAY(value) Day
 * - RTC_MODE2_CLOCK_MONTH(value) Month
 * - RTC_MODE2_CLOCK_YEAR(value) Year
 **/
static inline void rtcmode2_write_CLOCK(uint32_t data)
{
	RTC->MODE2.CLOCK.reg = data;
}

/**
 * @brief rtcmode2 clear CLOCK register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE2_CLOCK_SECOND(value) Second
 * - RTC_MODE2_CLOCK_MINUTE(value) Minute
 * - RTC_MODE2_CLOCK_HOUR(value) Hour
 *  +      RTC_MODE2_CLOCK_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_CLOCK_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_CLOCK_DAY(value) Day
 * - RTC_MODE2_CLOCK_MONTH(value) Month
 * - RTC_MODE2_CLOCK_YEAR(value) Year
 **/
static inline void rtcmode2_clear_CLOCK(uint32_t mask)
{
	RTC->MODE2.CLOCK.reg &= ~mask;
}

/**
 * @brief rtcmode2 read CLOCK register
 *
 * @return uint32_t
 * - RTC_MODE2_CLOCK_SECOND(value) Second
 * - RTC_MODE2_CLOCK_MINUTE(value) Minute
 * - RTC_MODE2_CLOCK_HOUR(value) Hour
 *  +      RTC_MODE2_CLOCK_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_CLOCK_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_CLOCK_DAY(value) Day
 * - RTC_MODE2_CLOCK_MONTH(value) Month
 * - RTC_MODE2_CLOCK_YEAR(value) Year
 **/
static inline uint32_t rtcmode2_read_CLOCK(void)
{
	return RTC->MODE2.CLOCK.reg;
}

/**
 * @brief rtcmode2 set GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode2_set_GP(uint8_t index, uint32_t mask)
{
	RTC->MODE2.GP[index].reg |= mask;
}

/**
 * @brief rtcmode2 get GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_GP_GP(value) General Purpose
 **/
static inline uint32_t rtcmode2_get_GP(uint8_t index, uint32_t mask)
{
    return RTC->MODE2.GP[index].reg & mask;
}

/**
 * @brief rtcmode2 write GP register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode2_write_GP(uint8_t index, uint32_t data)
{
	RTC->MODE2.GP[index].reg = data;
}

/**
 * @brief rtcmode2 clear GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode2_clear_GP(uint8_t index, uint32_t mask)
{
	RTC->MODE2.GP[index].reg &= ~mask;
}

/**
 * @brief rtcmode2 read GP register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - RTC_GP_GP(value) General Purpose
 **/
static inline uint32_t rtcmode2_read_GP(uint8_t index)
{
	return RTC->MODE2.GP[index].reg;
}

/**
 * @brief rtcmode2 set TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode2_set_TAMPCTRL(uint32_t mask)
{
	RTC->MODE2.TAMPCTRL.reg |= mask;
}

/**
 * @brief rtcmode2 get TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline uint32_t rtcmode2_get_TAMPCTRL(uint32_t mask)
{
    return RTC->MODE2.TAMPCTRL.reg & mask;
}

/**
 * @brief rtcmode2 write TAMPCTRL register
 *
 * @param[in] data uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode2_write_TAMPCTRL(uint32_t data)
{
	RTC->MODE2.TAMPCTRL.reg = data;
}

/**
 * @brief rtcmode2 clear TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode2_clear_TAMPCTRL(uint32_t mask)
{
	RTC->MODE2.TAMPCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode2 read TAMPCTRL register
 *
 * @return uint32_t
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline uint32_t rtcmode2_read_TAMPCTRL(void)
{
	return RTC->MODE2.TAMPCTRL.reg;
}

/**
 * @brief rtcmode2 set TAMPID register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode2_set_TAMPID(uint32_t mask)
{
	RTC->MODE2.TAMPID.reg |= mask;
}

/**
 * @brief rtcmode2 get TAMPID register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline uint32_t rtcmode2_get_TAMPID(uint32_t mask)
{
    return RTC->MODE2.TAMPID.reg & mask;
}

/**
 * @brief rtcmode2 write TAMPID register
 *
 * @param[in] data uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode2_write_TAMPID(uint32_t data)
{
	RTC->MODE2.TAMPID.reg = data;
}

/**
 * @brief rtcmode2 clear TAMPID register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode2_clear_TAMPID(uint32_t mask)
{
	RTC->MODE2.TAMPID.reg &= ~mask;
}

/**
 * @brief rtcmode2 read TAMPID register
 *
 * @return uint32_t
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline uint32_t rtcmode2_read_TAMPID(void)
{
	return RTC->MODE2.TAMPID.reg;
}

/**
 * @brief rtcmode2 set BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode2_set_BKUP(uint8_t index, uint32_t mask)
{
	RTC->MODE2.BKUP[index].reg |= mask;
}

/**
 * @brief rtcmode2 get BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline uint32_t rtcmode2_get_BKUP(uint8_t index, uint32_t mask)
{
    return RTC->MODE2.BKUP[index].reg & mask;
}

/**
 * @brief rtcmode2 write BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode2_write_BKUP(uint8_t index, uint32_t data)
{
	RTC->MODE2.BKUP[index].reg = data;
}

/**
 * @brief rtcmode2 clear BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode2_clear_BKUP(uint8_t index, uint32_t mask)
{
	RTC->MODE2.BKUP[index].reg &= ~mask;
}

/**
 * @brief rtcmode2 read BKUP register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline uint32_t rtcmode2_read_BKUP(uint8_t index)
{
	return RTC->MODE2.BKUP[index].reg;
}

/**
 * @brief rtcmode2 get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * -
 **/
static inline uint32_t rtcmode2_get_SYNCBUSY(uint32_t mask)
{
    return RTC->MODE2.SYNCBUSY.reg & mask;
}

/**
 * @brief rtcmode2 read SYNCBUSY register
 *
 * @return uint32_t
 * -
 **/
static inline uint32_t rtcmode2_read_SYNCBUSY(void)
{
	return RTC->MODE2.SYNCBUSY.reg;
}

/**
 * @brief rtcmode2 get TIMESTAMP register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_TIMESTAMP_SECOND(value) Second Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MINUTE(value) Minute Timestamp Value
 * - RTC_MODE2_TIMESTAMP_HOUR(value) Hour Timestamp Value
 *  +      RTC_MODE2_TIMESTAMP_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_TIMESTAMP_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_TIMESTAMP_DAY(value) Day Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MONTH(value) Month Timestamp Value
 * - RTC_MODE2_TIMESTAMP_YEAR(value) Year Timestamp Value
 **/
static inline uint32_t rtcmode2_get_TIMESTAMP(uint32_t mask)
{
    return RTC->MODE2.TIMESTAMP.reg & mask;
}

/**
 * @brief rtcmode2 read TIMESTAMP register
 *
 * @return uint32_t
 * - RTC_MODE2_TIMESTAMP_SECOND(value) Second Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MINUTE(value) Minute Timestamp Value
 * - RTC_MODE2_TIMESTAMP_HOUR(value) Hour Timestamp Value
 *  +      RTC_MODE2_TIMESTAMP_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_TIMESTAMP_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_TIMESTAMP_DAY(value) Day Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MONTH(value) Month Timestamp Value
 * - RTC_MODE2_TIMESTAMP_YEAR(value) Year Timestamp Value
 **/
static inline uint32_t rtcmode2_read_TIMESTAMP(void)
{
	return RTC->MODE2.TIMESTAMP.reg;
}

/**
 * @brief rtcmode0 set INTEN register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode0_set_INTEN(uint16_t mask)
{
	RTC->MODE0.INTENSET.reg = mask;
}

/**
 * @brief rtcmode0 get INTEN register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline uint16_t rtcmode0_get_INTEN(uint16_t mask)
{
    return RTC->MODE0.INTENSET.reg & mask;
}

/**
 * @brief rtcmode0 read INTEN register
 *
 * @return uint16_t
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline uint16_t rtcmode0_read_INTEN(void)
{
	return RTC->MODE0.INTENSET.reg;
}

/**
 * @brief rtcmode0 write INTEN register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode0_write_INTEN(uint16_t data)
{
	RTC->MODE0.INTENSET.reg = data;
	RTC->MODE0.INTENCLR.reg = ~data;
}

/**
 * @brief rtcmode0 clear INTEN register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode0_clear_INTEN(uint16_t mask)
{
	RTC->MODE0.INTENCLR.reg = mask;
}

/**
 * @brief rtcmode0 get INTFLAG register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline uint16_t rtcmode0_get_INTFLAG(uint16_t mask)
{
    return RTC->MODE0.INTFLAG.reg & mask;
}

/**
 * @brief rtcmode0 read INTFLAG register
 *
 * @return uint16_t
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline uint16_t rtcmode0_read_INTFLAG(void)
{
	return RTC->MODE0.INTFLAG.reg;
}

/**
 * @brief rtcmode0 clear INTFLAG register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline void rtcmode0_clear_INTFLAG(uint16_t mask)
{
	RTC->MODE0.INTFLAG.reg = mask;
}

/**
 * @brief rtcmode0 set CTRLA register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode0_set_CTRLA(uint16_t mask)
{
	RTC->MODE0.CTRLA.reg |= mask;
}

/**
 * @brief rtcmode0 get CTRLA register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline uint16_t rtcmode0_get_CTRLA(uint16_t mask)
{
    return RTC->MODE0.CTRLA.reg & mask;
}

/**
 * @brief rtcmode0 write CTRLA register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode0_write_CTRLA(uint16_t data)
{
	RTC->MODE0.CTRLA.reg = data;
}

/**
 * @brief rtcmode0 clear CTRLA register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode0_clear_CTRLA(uint16_t mask)
{
	RTC->MODE0.CTRLA.reg &= ~mask;
}

/**
 * @brief rtcmode0 read CTRLA register
 *
 * @return uint16_t
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline uint16_t rtcmode0_read_CTRLA(void)
{
	return RTC->MODE0.CTRLA.reg;
}

/**
 * @brief rtcmode0 set CTRLB register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode0_set_CTRLB(uint16_t mask)
{
	RTC->MODE0.CTRLB.reg |= mask;
}

/**
 * @brief rtcmode0 get CTRLB register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline uint16_t rtcmode0_get_CTRLB(uint16_t mask)
{
    return RTC->MODE0.CTRLB.reg & mask;
}

/**
 * @brief rtcmode0 write CTRLB register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode0_write_CTRLB(uint16_t data)
{
	RTC->MODE0.CTRLB.reg = data;
}

/**
 * @brief rtcmode0 clear CTRLB register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode0_clear_CTRLB(uint16_t mask)
{
	RTC->MODE0.CTRLB.reg &= ~mask;
}

/**
 * @brief rtcmode0 read CTRLB register
 *
 * @return uint16_t
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline uint16_t rtcmode0_read_CTRLB(void)
{
	return RTC->MODE0.CTRLB.reg;
}

/**
 * @brief rtcmode0 set EVCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode0_set_EVCTRL(uint32_t mask)
{
	RTC->MODE0.EVCTRL.reg |= mask;
}

/**
 * @brief rtcmode0 get EVCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline uint32_t rtcmode0_get_EVCTRL(uint32_t mask)
{
    return RTC->MODE0.EVCTRL.reg & mask;
}

/**
 * @brief rtcmode0 write EVCTRL register
 *
 * @param[in] data uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode0_write_EVCTRL(uint32_t data)
{
	RTC->MODE0.EVCTRL.reg = data;
}

/**
 * @brief rtcmode0 clear EVCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode0_clear_EVCTRL(uint32_t mask)
{
	RTC->MODE0.EVCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode0 read EVCTRL register
 *
 * @return uint32_t
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline uint32_t rtcmode0_read_EVCTRL(void)
{
	return RTC->MODE0.EVCTRL.reg;
}

/**
 * @brief rtcmode0 set DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode0_set_DBGCTRL(uint8_t mask)
{
	RTC->MODE0.DBGCTRL.reg |= mask;
}

/**
 * @brief rtcmode0 get DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline uint8_t rtcmode0_get_DBGCTRL(uint8_t mask)
{
    return RTC->MODE0.DBGCTRL.reg & mask;
}

/**
 * @brief rtcmode0 write DBGCTRL register
 *
 * @param[in] data uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode0_write_DBGCTRL(uint8_t data)
{
	RTC->MODE0.DBGCTRL.reg = data;
}

/**
 * @brief rtcmode0 clear DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode0_clear_DBGCTRL(uint8_t mask)
{
	RTC->MODE0.DBGCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode0 read DBGCTRL register
 *
 * @return uint8_t
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline uint8_t rtcmode0_read_DBGCTRL(void)
{
	return RTC->MODE0.DBGCTRL.reg;
}

/**
 * @brief rtcmode0 set FREQCORR register
 *
 * @param[in] mask uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode0_set_FREQCORR(uint8_t mask)
{
	RTC->MODE0.FREQCORR.reg |= mask;
}

/**
 * @brief rtcmode0 get FREQCORR register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline uint8_t rtcmode0_get_FREQCORR(uint8_t mask)
{
    return RTC->MODE0.FREQCORR.reg & mask;
}

/**
 * @brief rtcmode0 write FREQCORR register
 *
 * @param[in] data uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode0_write_FREQCORR(uint8_t data)
{
	RTC->MODE0.FREQCORR.reg = data;
}

/**
 * @brief rtcmode0 clear FREQCORR register
 *
 * @param[in] mask uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode0_clear_FREQCORR(uint8_t mask)
{
	RTC->MODE0.FREQCORR.reg &= ~mask;
}

/**
 * @brief rtcmode0 read FREQCORR register
 *
 * @return uint8_t
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline uint8_t rtcmode0_read_FREQCORR(void)
{
	return RTC->MODE0.FREQCORR.reg;
}

/**
 * @brief rtcmode0 set COUNT register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline void rtcmode0_set_COUNT(uint32_t mask)
{
	RTC->MODE0.COUNT.reg |= mask;
}

/**
 * @brief rtcmode0 get COUNT register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline uint32_t rtcmode0_get_COUNT(uint32_t mask)
{
    return RTC->MODE0.COUNT.reg & mask;
}

/**
 * @brief rtcmode0 write COUNT register
 *
 * @param[in] data uint32_t 
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline void rtcmode0_write_COUNT(uint32_t data)
{
	RTC->MODE0.COUNT.reg = data;
}

/**
 * @brief rtcmode0 clear COUNT register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline void rtcmode0_clear_COUNT(uint32_t mask)
{
	RTC->MODE0.COUNT.reg &= ~mask;
}

/**
 * @brief rtcmode0 read COUNT register
 *
 * @return uint32_t
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline uint32_t rtcmode0_read_COUNT(void)
{
	return RTC->MODE0.COUNT.reg;
}

/**
 * @brief rtcmode0 set COMP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline void rtcmode0_set_COMP(uint8_t index, uint32_t mask)
{
	RTC->MODE0.COMP[index].reg |= mask;
}

/**
 * @brief rtcmode0 get COMP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline uint32_t rtcmode0_get_COMP(uint8_t index, uint32_t mask)
{
    return RTC->MODE0.COMP[index].reg & mask;
}

/**
 * @brief rtcmode0 write COMP register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline void rtcmode0_write_COMP(uint8_t index, uint32_t data)
{
	RTC->MODE0.COMP[index].reg = data;
}

/**
 * @brief rtcmode0 clear COMP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline void rtcmode0_clear_COMP(uint8_t index, uint32_t mask)
{
	RTC->MODE0.COMP[index].reg &= ~mask;
}

/**
 * @brief rtcmode0 read COMP register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline uint32_t rtcmode0_read_COMP(uint8_t index)
{
	return RTC->MODE0.COMP[index].reg;
}

/**
 * @brief rtcmode0 set GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode0_set_GP(uint8_t index, uint32_t mask)
{
	RTC->MODE0.GP[index].reg |= mask;
}

/**
 * @brief rtcmode0 get GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_GP_GP(value) General Purpose
 **/
static inline uint32_t rtcmode0_get_GP(uint8_t index, uint32_t mask)
{
    return RTC->MODE0.GP[index].reg & mask;
}

/**
 * @brief rtcmode0 write GP register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode0_write_GP(uint8_t index, uint32_t data)
{
	RTC->MODE0.GP[index].reg = data;
}

/**
 * @brief rtcmode0 clear GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode0_clear_GP(uint8_t index, uint32_t mask)
{
	RTC->MODE0.GP[index].reg &= ~mask;
}

/**
 * @brief rtcmode0 read GP register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - RTC_GP_GP(value) General Purpose
 **/
static inline uint32_t rtcmode0_read_GP(uint8_t index)
{
	return RTC->MODE0.GP[index].reg;
}

/**
 * @brief rtcmode0 set TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode0_set_TAMPCTRL(uint32_t mask)
{
	RTC->MODE0.TAMPCTRL.reg |= mask;
}

/**
 * @brief rtcmode0 get TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline uint32_t rtcmode0_get_TAMPCTRL(uint32_t mask)
{
    return RTC->MODE0.TAMPCTRL.reg & mask;
}

/**
 * @brief rtcmode0 write TAMPCTRL register
 *
 * @param[in] data uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode0_write_TAMPCTRL(uint32_t data)
{
	RTC->MODE0.TAMPCTRL.reg = data;
}

/**
 * @brief rtcmode0 clear TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode0_clear_TAMPCTRL(uint32_t mask)
{
	RTC->MODE0.TAMPCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode0 read TAMPCTRL register
 *
 * @return uint32_t
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline uint32_t rtcmode0_read_TAMPCTRL(void)
{
	return RTC->MODE0.TAMPCTRL.reg;
}

/**
 * @brief rtcmode0 set TAMPID register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode0_set_TAMPID(uint32_t mask)
{
	RTC->MODE0.TAMPID.reg |= mask;
}

/**
 * @brief rtcmode0 get TAMPID register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline uint32_t rtcmode0_get_TAMPID(uint32_t mask)
{
    return RTC->MODE0.TAMPID.reg & mask;
}

/**
 * @brief rtcmode0 write TAMPID register
 *
 * @param[in] data uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode0_write_TAMPID(uint32_t data)
{
	RTC->MODE0.TAMPID.reg = data;
}

/**
 * @brief rtcmode0 clear TAMPID register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode0_clear_TAMPID(uint32_t mask)
{
	RTC->MODE0.TAMPID.reg &= ~mask;
}

/**
 * @brief rtcmode0 read TAMPID register
 *
 * @return uint32_t
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline uint32_t rtcmode0_read_TAMPID(void)
{
	return RTC->MODE0.TAMPID.reg;
}

/**
 * @brief rtcmode0 set BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode0_set_BKUP(uint8_t index, uint32_t mask)
{
	RTC->MODE0.BKUP[index].reg |= mask;
}

/**
 * @brief rtcmode0 get BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline uint32_t rtcmode0_get_BKUP(uint8_t index, uint32_t mask)
{
    return RTC->MODE0.BKUP[index].reg & mask;
}

/**
 * @brief rtcmode0 write BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode0_write_BKUP(uint8_t index, uint32_t data)
{
	RTC->MODE0.BKUP[index].reg = data;
}

/**
 * @brief rtcmode0 clear BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode0_clear_BKUP(uint8_t index, uint32_t mask)
{
	RTC->MODE0.BKUP[index].reg &= ~mask;
}

/**
 * @brief rtcmode0 read BKUP register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline uint32_t rtcmode0_read_BKUP(uint8_t index)
{
	return RTC->MODE0.BKUP[index].reg;
}

/**
 * @brief rtcmode0 get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * -
 **/
static inline uint32_t rtcmode0_get_SYNCBUSY(uint32_t mask)
{
    return RTC->MODE0.SYNCBUSY.reg & mask;
}

/**
 * @brief rtcmode0 read SYNCBUSY register
 *
 * @return uint32_t
 * -
 **/
static inline uint32_t rtcmode0_read_SYNCBUSY(void)
{
	return RTC->MODE0.SYNCBUSY.reg;
}

/**
 * @brief rtcmode0 get TIMESTAMP register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_TIMESTAMP_SECOND(value) Second Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MINUTE(value) Minute Timestamp Value
 * - RTC_MODE2_TIMESTAMP_HOUR(value) Hour Timestamp Value
 *  +      RTC_MODE2_TIMESTAMP_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_TIMESTAMP_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_TIMESTAMP_DAY(value) Day Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MONTH(value) Month Timestamp Value
 * - RTC_MODE2_TIMESTAMP_YEAR(value) Year Timestamp Value
 **/
static inline uint32_t rtcmode0_get_TIMESTAMP(uint32_t mask)
{
    return RTC->MODE0.TIMESTAMP.reg & mask;
}

/**
 * @brief rtcmode0 read TIMESTAMP register
 *
 * @return uint32_t
 * - RTC_MODE2_TIMESTAMP_SECOND(value) Second Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MINUTE(value) Minute Timestamp Value
 * - RTC_MODE2_TIMESTAMP_HOUR(value) Hour Timestamp Value
 *  +      RTC_MODE2_TIMESTAMP_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_TIMESTAMP_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_TIMESTAMP_DAY(value) Day Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MONTH(value) Month Timestamp Value
 * - RTC_MODE2_TIMESTAMP_YEAR(value) Year Timestamp Value
 **/
static inline uint32_t rtcmode0_read_TIMESTAMP(void)
{
	return RTC->MODE0.TIMESTAMP.reg;
}

/**
 * @brief rtcmode1 set INTEN register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode1_set_INTEN(uint16_t mask)
{
	RTC->MODE1.INTENSET.reg = mask;
}

/**
 * @brief rtcmode1 get INTEN register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline uint16_t rtcmode1_get_INTEN(uint16_t mask)
{
    return RTC->MODE1.INTENSET.reg & mask;
}

/**
 * @brief rtcmode1 read INTEN register
 *
 * @return uint16_t
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline uint16_t rtcmode1_read_INTEN(void)
{
	return RTC->MODE1.INTENSET.reg;
}

/**
 * @brief rtcmode1 write INTEN register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode1_write_INTEN(uint16_t data)
{
	RTC->MODE1.INTENSET.reg = data;
	RTC->MODE1.INTENCLR.reg = ~data;
}

/**
 * @brief rtcmode1 clear INTEN register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTENSET_PER0 Periodic Interval 0 Enable
 * - RTC_MODE2_INTENSET_PER1 Periodic Interval 1 Enable
 * - RTC_MODE2_INTENSET_PER2 Periodic Interval 2 Enable
 * - RTC_MODE2_INTENSET_PER3 Periodic Interval 3 Enable
 * - RTC_MODE2_INTENSET_PER4 Periodic Interval 4 Enable
 * - RTC_MODE2_INTENSET_PER5 Periodic Interval 5 Enable
 * - RTC_MODE2_INTENSET_PER6 Periodic Interval 6 Enable
 * - RTC_MODE2_INTENSET_PER7 Periodic Interval 7 Enable
 * - RTC_MODE2_INTENSET_PER(value) Periodic Interval x Enable
 * - RTC_MODE2_INTENSET_ALARM0 Alarm 0 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM1 Alarm 1 Interrupt Enable
 * - RTC_MODE2_INTENSET_ALARM(value) Alarm x Interrupt Enable
 * - RTC_MODE2_INTENSET_TAMPER Tamper Enable
 * - RTC_MODE2_INTENSET_OVF Overflow Interrupt Enable
 **/
static inline void rtcmode1_clear_INTEN(uint16_t mask)
{
	RTC->MODE1.INTENCLR.reg = mask;
}

/**
 * @brief rtcmode1 get INTFLAG register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline uint16_t rtcmode1_get_INTFLAG(uint16_t mask)
{
    return RTC->MODE1.INTFLAG.reg & mask;
}

/**
 * @brief rtcmode1 read INTFLAG register
 *
 * @return uint16_t
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline uint16_t rtcmode1_read_INTFLAG(void)
{
	return RTC->MODE1.INTFLAG.reg;
}

/**
 * @brief rtcmode1 clear INTFLAG register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_INTFLAG_PER0 Periodic Interval 0
 * - RTC_MODE2_INTFLAG_PER1 Periodic Interval 1
 * - RTC_MODE2_INTFLAG_PER2 Periodic Interval 2
 * - RTC_MODE2_INTFLAG_PER3 Periodic Interval 3
 * - RTC_MODE2_INTFLAG_PER4 Periodic Interval 4
 * - RTC_MODE2_INTFLAG_PER5 Periodic Interval 5
 * - RTC_MODE2_INTFLAG_PER6 Periodic Interval 6
 * - RTC_MODE2_INTFLAG_PER7 Periodic Interval 7
 * - RTC_MODE2_INTFLAG_PER(value) Periodic Interval x
 * - RTC_MODE2_INTFLAG_ALARM0 Alarm 0
 * - RTC_MODE2_INTFLAG_ALARM1 Alarm 1
 * - RTC_MODE2_INTFLAG_ALARM(value) Alarm x
 * - RTC_MODE2_INTFLAG_TAMPER Tamper
 * - RTC_MODE2_INTFLAG_OVF Overflow
 **/
static inline void rtcmode1_clear_INTFLAG(uint16_t mask)
{
	RTC->MODE1.INTFLAG.reg = mask;
}

/**
 * @brief rtcmode1 set CTRLA register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode1_set_CTRLA(uint16_t mask)
{
	RTC->MODE1.CTRLA.reg |= mask;
}

/**
 * @brief rtcmode1 get CTRLA register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline uint16_t rtcmode1_get_CTRLA(uint16_t mask)
{
    return RTC->MODE1.CTRLA.reg & mask;
}

/**
 * @brief rtcmode1 write CTRLA register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode1_write_CTRLA(uint16_t data)
{
	RTC->MODE1.CTRLA.reg = data;
}

/**
 * @brief rtcmode1 clear CTRLA register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline void rtcmode1_clear_CTRLA(uint16_t mask)
{
	RTC->MODE1.CTRLA.reg &= ~mask;
}

/**
 * @brief rtcmode1 read CTRLA register
 *
 * @return uint16_t
 * - RTC_MODE2_CTRLA_SWRST Software Reset
 * - RTC_MODE2_CTRLA_ENABLE Enable
 * - RTC_MODE2_CTRLA_MODE(value) Operating Mode
 *  +      RTC_MODE2_CTRLA_MODE_COUNT32 Mode 0: 32-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_COUNT16 Mode 1: 16-bit Counter
 *  +      RTC_MODE2_CTRLA_MODE_CLOCK Mode 2: Clock/Calendar
 * - RTC_MODE2_CTRLA_CLKREP Clock Representation
 * - RTC_MODE2_CTRLA_MATCHCLR Clear on Match
 * - RTC_MODE2_CTRLA_PRESCALER(value) Prescaler
 *  +      RTC_MODE2_CTRLA_PRESCALER_OFF CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1 CLK_RTC_CNT = GCLK_RTC/1
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV2 CLK_RTC_CNT = GCLK_RTC/2
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV4 CLK_RTC_CNT = GCLK_RTC/4
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV8 CLK_RTC_CNT = GCLK_RTC/8
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV16 CLK_RTC_CNT = GCLK_RTC/16
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV32 CLK_RTC_CNT = GCLK_RTC/32
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV64 CLK_RTC_CNT = GCLK_RTC/64
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV128 CLK_RTC_CNT = GCLK_RTC/128
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV256 CLK_RTC_CNT = GCLK_RTC/256
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV512 CLK_RTC_CNT = GCLK_RTC/512
 *  +      RTC_MODE2_CTRLA_PRESCALER_DIV1024 CLK_RTC_CNT = GCLK_RTC/1024
 * - RTC_MODE2_CTRLA_BKTRST BKUP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_GPTRST GP Registers Reset On Tamper Enable
 * - RTC_MODE2_CTRLA_CLOCKSYNC Clock Read Synchronization Enable
 **/
static inline uint16_t rtcmode1_read_CTRLA(void)
{
	return RTC->MODE1.CTRLA.reg;
}

/**
 * @brief rtcmode1 set CTRLB register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode1_set_CTRLB(uint16_t mask)
{
	RTC->MODE1.CTRLB.reg |= mask;
}

/**
 * @brief rtcmode1 get CTRLB register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline uint16_t rtcmode1_get_CTRLB(uint16_t mask)
{
    return RTC->MODE1.CTRLB.reg & mask;
}

/**
 * @brief rtcmode1 write CTRLB register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode1_write_CTRLB(uint16_t data)
{
	RTC->MODE1.CTRLB.reg = data;
}

/**
 * @brief rtcmode1 clear CTRLB register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline void rtcmode1_clear_CTRLB(uint16_t mask)
{
	RTC->MODE1.CTRLB.reg &= ~mask;
}

/**
 * @brief rtcmode1 read CTRLB register
 *
 * @return uint16_t
 * - RTC_MODE2_CTRLB_GP0EN General Purpose 0 Enable
 * - RTC_MODE2_CTRLB_GP2EN General Purpose 2 Enable
 * - RTC_MODE2_CTRLB_DEBMAJ Debouncer Majority Enable
 * - RTC_MODE2_CTRLB_DEBASYNC Debouncer Asynchronous Enable
 * - RTC_MODE2_CTRLB_RTCOUT RTC Output Enable
 * - RTC_MODE2_CTRLB_DMAEN DMA Enable
 * - RTC_MODE2_CTRLB_DEBF(value) Debounce Freqnuency
 *  +      RTC_MODE2_CTRLB_DEBF_DIV2 CLK_RTC_DEB = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_DEBF_DIV4 CLK_RTC_DEB = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_DEBF_DIV8 CLK_RTC_DEB = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_DEBF_DIV16 CLK_RTC_DEB = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_DEBF_DIV32 CLK_RTC_DEB = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_DEBF_DIV64 CLK_RTC_DEB = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_DEBF_DIV128 CLK_RTC_DEB = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_DEBF_DIV256 CLK_RTC_DEB = CLK_RTC/256
 * - RTC_MODE2_CTRLB_ACTF(value) Active Layer Freqnuency
 *  +      RTC_MODE2_CTRLB_ACTF_DIV2 CLK_RTC_OUT = CLK_RTC/2
 *  +      RTC_MODE2_CTRLB_ACTF_DIV4 CLK_RTC_OUT = CLK_RTC/4
 *  +      RTC_MODE2_CTRLB_ACTF_DIV8 CLK_RTC_OUT = CLK_RTC/8
 *  +      RTC_MODE2_CTRLB_ACTF_DIV16 CLK_RTC_OUT = CLK_RTC/16
 *  +      RTC_MODE2_CTRLB_ACTF_DIV32 CLK_RTC_OUT = CLK_RTC/32
 *  +      RTC_MODE2_CTRLB_ACTF_DIV64 CLK_RTC_OUT = CLK_RTC/64
 *  +      RTC_MODE2_CTRLB_ACTF_DIV128 CLK_RTC_OUT = CLK_RTC/128
 *  +      RTC_MODE2_CTRLB_ACTF_DIV256 CLK_RTC_OUT = CLK_RTC/256
 **/
static inline uint16_t rtcmode1_read_CTRLB(void)
{
	return RTC->MODE1.CTRLB.reg;
}

/**
 * @brief rtcmode1 set EVCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode1_set_EVCTRL(uint32_t mask)
{
	RTC->MODE1.EVCTRL.reg |= mask;
}

/**
 * @brief rtcmode1 get EVCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline uint32_t rtcmode1_get_EVCTRL(uint32_t mask)
{
    return RTC->MODE1.EVCTRL.reg & mask;
}

/**
 * @brief rtcmode1 write EVCTRL register
 *
 * @param[in] data uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode1_write_EVCTRL(uint32_t data)
{
	RTC->MODE1.EVCTRL.reg = data;
}

/**
 * @brief rtcmode1 clear EVCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline void rtcmode1_clear_EVCTRL(uint32_t mask)
{
	RTC->MODE1.EVCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode1 read EVCTRL register
 *
 * @return uint32_t
 * - RTC_MODE2_EVCTRL_PEREO0 Periodic Interval 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO1 Periodic Interval 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO2 Periodic Interval 2 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO3 Periodic Interval 3 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO4 Periodic Interval 4 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO5 Periodic Interval 5 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO6 Periodic Interval 6 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO7 Periodic Interval 7 Event Output Enable
 * - RTC_MODE2_EVCTRL_PEREO(value) Periodic Interval x Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO0 Alarm 0 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO1 Alarm 1 Event Output Enable
 * - RTC_MODE2_EVCTRL_ALARMEO(value) Alarm x Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEREO Tamper Event Output Enable
 * - RTC_MODE2_EVCTRL_OVFEO Overflow Event Output Enable
 * - RTC_MODE2_EVCTRL_TAMPEVEI Tamper Event Input Enable
 **/
static inline uint32_t rtcmode1_read_EVCTRL(void)
{
	return RTC->MODE1.EVCTRL.reg;
}

/**
 * @brief rtcmode1 set DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode1_set_DBGCTRL(uint8_t mask)
{
	RTC->MODE1.DBGCTRL.reg |= mask;
}

/**
 * @brief rtcmode1 get DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline uint8_t rtcmode1_get_DBGCTRL(uint8_t mask)
{
    return RTC->MODE1.DBGCTRL.reg & mask;
}

/**
 * @brief rtcmode1 write DBGCTRL register
 *
 * @param[in] data uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode1_write_DBGCTRL(uint8_t data)
{
	RTC->MODE1.DBGCTRL.reg = data;
}

/**
 * @brief rtcmode1 clear DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline void rtcmode1_clear_DBGCTRL(uint8_t mask)
{
	RTC->MODE1.DBGCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode1 read DBGCTRL register
 *
 * @return uint8_t
 * - RTC_DBGCTRL_DBGRUN Run During Debug
 **/
static inline uint8_t rtcmode1_read_DBGCTRL(void)
{
	return RTC->MODE1.DBGCTRL.reg;
}

/**
 * @brief rtcmode1 set FREQCORR register
 *
 * @param[in] mask uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode1_set_FREQCORR(uint8_t mask)
{
	RTC->MODE1.FREQCORR.reg |= mask;
}

/**
 * @brief rtcmode1 get FREQCORR register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline uint8_t rtcmode1_get_FREQCORR(uint8_t mask)
{
    return RTC->MODE1.FREQCORR.reg & mask;
}

/**
 * @brief rtcmode1 write FREQCORR register
 *
 * @param[in] data uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode1_write_FREQCORR(uint8_t data)
{
	RTC->MODE1.FREQCORR.reg = data;
}

/**
 * @brief rtcmode1 clear FREQCORR register
 *
 * @param[in] mask uint8_t 
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline void rtcmode1_clear_FREQCORR(uint8_t mask)
{
	RTC->MODE1.FREQCORR.reg &= ~mask;
}

/**
 * @brief rtcmode1 read FREQCORR register
 *
 * @return uint8_t
 * - RTC_FREQCORR_VALUE(value) Correction Value
 * - RTC_FREQCORR_SIGN Correction Sign
 **/
static inline uint8_t rtcmode1_read_FREQCORR(void)
{
	return RTC->MODE1.FREQCORR.reg;
}

/**
 * @brief rtcmode1 set COUNT register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline void rtcmode1_set_COUNT(uint16_t mask)
{
	RTC->MODE1.COUNT.reg |= mask;
}

/**
 * @brief rtcmode1 get COUNT register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline uint16_t rtcmode1_get_COUNT(uint16_t mask)
{
    return RTC->MODE1.COUNT.reg & mask;
}

/**
 * @brief rtcmode1 write COUNT register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline void rtcmode1_write_COUNT(uint16_t data)
{
	RTC->MODE1.COUNT.reg = data;
}

/**
 * @brief rtcmode1 clear COUNT register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline void rtcmode1_clear_COUNT(uint16_t mask)
{
	RTC->MODE1.COUNT.reg &= ~mask;
}

/**
 * @brief rtcmode1 read COUNT register
 *
 * @return uint16_t
 * - RTC_MODE1_COUNT_COUNT(value) Counter Value
 **/
static inline uint16_t rtcmode1_read_COUNT(void)
{
	return RTC->MODE1.COUNT.reg;
}

/**
 * @brief rtcmode1 set PER register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE1_PER_PER(value) Counter Period
 **/
static inline void rtcmode1_set_PER(uint16_t mask)
{
	RTC->MODE1.PER.reg |= mask;
}

/**
 * @brief rtcmode1 get PER register
 *
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE1_PER_PER(value) Counter Period
 **/
static inline uint16_t rtcmode1_get_PER(uint16_t mask)
{
    return RTC->MODE1.PER.reg & mask;
}

/**
 * @brief rtcmode1 write PER register
 *
 * @param[in] data uint16_t 
 * - RTC_MODE1_PER_PER(value) Counter Period
 **/
static inline void rtcmode1_write_PER(uint16_t data)
{
	RTC->MODE1.PER.reg = data;
}

/**
 * @brief rtcmode1 clear PER register
 *
 * @param[in] mask uint16_t 
 * - RTC_MODE1_PER_PER(value) Counter Period
 **/
static inline void rtcmode1_clear_PER(uint16_t mask)
{
	RTC->MODE1.PER.reg &= ~mask;
}

/**
 * @brief rtcmode1 read PER register
 *
 * @return uint16_t
 * - RTC_MODE1_PER_PER(value) Counter Period
 **/
static inline uint16_t rtcmode1_read_PER(void)
{
	return RTC->MODE1.PER.reg;
}

/**
 * @brief rtcmode1 set COMP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint16_t 
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline void rtcmode1_set_COMP(uint8_t index, uint16_t mask)
{
	RTC->MODE1.COMP[index].reg |= mask;
}

/**
 * @brief rtcmode1 get COMP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint16_t 
 * @return uint16_t
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline uint16_t rtcmode1_get_COMP(uint8_t index, uint16_t mask)
{
    return RTC->MODE1.COMP[index].reg & mask;
}

/**
 * @brief rtcmode1 write COMP register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint16_t 
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline void rtcmode1_write_COMP(uint8_t index, uint16_t data)
{
	RTC->MODE1.COMP[index].reg = data;
}

/**
 * @brief rtcmode1 clear COMP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint16_t 
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline void rtcmode1_clear_COMP(uint8_t index, uint16_t mask)
{
	RTC->MODE1.COMP[index].reg &= ~mask;
}

/**
 * @brief rtcmode1 read COMP register
 *
 * @param[in] index uint8_t 
 * @return uint16_t
 * - RTC_MODE1_COMP_COMP(value) Compare Value
 **/
static inline uint16_t rtcmode1_read_COMP(uint8_t index)
{
	return RTC->MODE1.COMP[index].reg;
}

/**
 * @brief rtcmode1 set GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode1_set_GP(uint8_t index, uint32_t mask)
{
	RTC->MODE1.GP[index].reg |= mask;
}

/**
 * @brief rtcmode1 get GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_GP_GP(value) General Purpose
 **/
static inline uint32_t rtcmode1_get_GP(uint8_t index, uint32_t mask)
{
    return RTC->MODE1.GP[index].reg & mask;
}

/**
 * @brief rtcmode1 write GP register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode1_write_GP(uint8_t index, uint32_t data)
{
	RTC->MODE1.GP[index].reg = data;
}

/**
 * @brief rtcmode1 clear GP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_GP_GP(value) General Purpose
 **/
static inline void rtcmode1_clear_GP(uint8_t index, uint32_t mask)
{
	RTC->MODE1.GP[index].reg &= ~mask;
}

/**
 * @brief rtcmode1 read GP register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - RTC_GP_GP(value) General Purpose
 **/
static inline uint32_t rtcmode1_read_GP(uint8_t index)
{
	return RTC->MODE1.GP[index].reg;
}

/**
 * @brief rtcmode1 set TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode1_set_TAMPCTRL(uint32_t mask)
{
	RTC->MODE1.TAMPCTRL.reg |= mask;
}

/**
 * @brief rtcmode1 get TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline uint32_t rtcmode1_get_TAMPCTRL(uint32_t mask)
{
    return RTC->MODE1.TAMPCTRL.reg & mask;
}

/**
 * @brief rtcmode1 write TAMPCTRL register
 *
 * @param[in] data uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode1_write_TAMPCTRL(uint32_t data)
{
	RTC->MODE1.TAMPCTRL.reg = data;
}

/**
 * @brief rtcmode1 clear TAMPCTRL register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline void rtcmode1_clear_TAMPCTRL(uint32_t mask)
{
	RTC->MODE1.TAMPCTRL.reg &= ~mask;
}

/**
 * @brief rtcmode1 read TAMPCTRL register
 *
 * @return uint32_t
 * - RTC_TAMPCTRL_IN0ACT(value) Tamper Input 0 Action
 *  +      RTC_TAMPCTRL_IN0ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN0ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN0ACT_ACTL Compare IN0 to OUT
 * - RTC_TAMPCTRL_IN1ACT(value) Tamper Input 1 Action
 *  +      RTC_TAMPCTRL_IN1ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN1ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN1ACT_ACTL Compare IN1 to OUT
 * - RTC_TAMPCTRL_IN2ACT(value) Tamper Input 2 Action
 *  +      RTC_TAMPCTRL_IN2ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN2ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN2ACT_ACTL Compare IN2 to OUT
 * - RTC_TAMPCTRL_IN3ACT(value) Tamper Input 3 Action
 *  +      RTC_TAMPCTRL_IN3ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN3ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN3ACT_ACTL Compare IN3 to OUT
 * - RTC_TAMPCTRL_IN4ACT(value) Tamper Input 4 Action
 *  +      RTC_TAMPCTRL_IN4ACT_OFF Off (Disabled)
 *  +      RTC_TAMPCTRL_IN4ACT_WAKE Wake without timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_CAPTURE Capture timestamp
 *  +      RTC_TAMPCTRL_IN4ACT_ACTL Compare IN4 to OUT
 * - RTC_TAMPCTRL_TAMLVL0 Tamper Level Select 0
 * - RTC_TAMPCTRL_TAMLVL1 Tamper Level Select 1
 * - RTC_TAMPCTRL_TAMLVL2 Tamper Level Select 2
 * - RTC_TAMPCTRL_TAMLVL3 Tamper Level Select 3
 * - RTC_TAMPCTRL_TAMLVL4 Tamper Level Select 4
 * - RTC_TAMPCTRL_TAMLVL(value) Tamper Level Select x
 * - RTC_TAMPCTRL_DEBNC0 Debouncer Enable 0
 * - RTC_TAMPCTRL_DEBNC1 Debouncer Enable 1
 * - RTC_TAMPCTRL_DEBNC2 Debouncer Enable 2
 * - RTC_TAMPCTRL_DEBNC3 Debouncer Enable 3
 * - RTC_TAMPCTRL_DEBNC4 Debouncer Enable 4
 * - RTC_TAMPCTRL_DEBNC(value) Debouncer Enable x
 **/
static inline uint32_t rtcmode1_read_TAMPCTRL(void)
{
	return RTC->MODE1.TAMPCTRL.reg;
}

/**
 * @brief rtcmode1 set TAMPID register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode1_set_TAMPID(uint32_t mask)
{
	RTC->MODE1.TAMPID.reg |= mask;
}

/**
 * @brief rtcmode1 get TAMPID register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline uint32_t rtcmode1_get_TAMPID(uint32_t mask)
{
    return RTC->MODE1.TAMPID.reg & mask;
}

/**
 * @brief rtcmode1 write TAMPID register
 *
 * @param[in] data uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode1_write_TAMPID(uint32_t data)
{
	RTC->MODE1.TAMPID.reg = data;
}

/**
 * @brief rtcmode1 clear TAMPID register
 *
 * @param[in] mask uint32_t 
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline void rtcmode1_clear_TAMPID(uint32_t mask)
{
	RTC->MODE1.TAMPID.reg &= ~mask;
}

/**
 * @brief rtcmode1 read TAMPID register
 *
 * @return uint32_t
 * - RTC_TAMPID_TAMPID0 Tamper Input 0 Detected
 * - RTC_TAMPID_TAMPID1 Tamper Input 1 Detected
 * - RTC_TAMPID_TAMPID2 Tamper Input 2 Detected
 * - RTC_TAMPID_TAMPID3 Tamper Input 3 Detected
 * - RTC_TAMPID_TAMPID4 Tamper Input 4 Detected
 * - RTC_TAMPID_TAMPID(value) Tamper Input x Detected
 * - RTC_TAMPID_TAMPEVT Tamper Event Detected
 **/
static inline uint32_t rtcmode1_read_TAMPID(void)
{
	return RTC->MODE1.TAMPID.reg;
}

/**
 * @brief rtcmode1 set BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode1_set_BKUP(uint8_t index, uint32_t mask)
{
	RTC->MODE1.BKUP[index].reg |= mask;
}

/**
 * @brief rtcmode1 get BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline uint32_t rtcmode1_get_BKUP(uint8_t index, uint32_t mask)
{
    return RTC->MODE1.BKUP[index].reg & mask;
}

/**
 * @brief rtcmode1 write BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode1_write_BKUP(uint8_t index, uint32_t data)
{
	RTC->MODE1.BKUP[index].reg = data;
}

/**
 * @brief rtcmode1 clear BKUP register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline void rtcmode1_clear_BKUP(uint8_t index, uint32_t mask)
{
	RTC->MODE1.BKUP[index].reg &= ~mask;
}

/**
 * @brief rtcmode1 read BKUP register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 * - RTC_BKUP_BKUP(value) Backup
 **/
static inline uint32_t rtcmode1_read_BKUP(uint8_t index)
{
	return RTC->MODE1.BKUP[index].reg;
}

/**
 * @brief rtcmode1 get SYNCBUSY register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * -
 **/
static inline uint32_t rtcmode1_get_SYNCBUSY(uint32_t mask)
{
    return RTC->MODE1.SYNCBUSY.reg & mask;
}

/**
 * @brief rtcmode1 read SYNCBUSY register
 *
 * @return uint32_t
 * -
 **/
static inline uint32_t rtcmode1_read_SYNCBUSY(void)
{
	return RTC->MODE1.SYNCBUSY.reg;
}

/**
 * @brief rtcmode1 get TIMESTAMP register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - RTC_MODE2_TIMESTAMP_SECOND(value) Second Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MINUTE(value) Minute Timestamp Value
 * - RTC_MODE2_TIMESTAMP_HOUR(value) Hour Timestamp Value
 *  +      RTC_MODE2_TIMESTAMP_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_TIMESTAMP_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_TIMESTAMP_DAY(value) Day Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MONTH(value) Month Timestamp Value
 * - RTC_MODE2_TIMESTAMP_YEAR(value) Year Timestamp Value
 **/
static inline uint32_t rtcmode1_get_TIMESTAMP(uint32_t mask)
{
    return RTC->MODE1.TIMESTAMP.reg & mask;
}

/**
 * @brief rtcmode1 read TIMESTAMP register
 *
 * @return uint32_t
 * - RTC_MODE2_TIMESTAMP_SECOND(value) Second Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MINUTE(value) Minute Timestamp Value
 * - RTC_MODE2_TIMESTAMP_HOUR(value) Hour Timestamp Value
 *  +      RTC_MODE2_TIMESTAMP_HOUR_AM AM when CLKREP in 12-hour
 *  +      RTC_MODE2_TIMESTAMP_HOUR_PM PM when CLKREP in 12-hour
 * - RTC_MODE2_TIMESTAMP_DAY(value) Day Timestamp Value
 * - RTC_MODE2_TIMESTAMP_MONTH(value) Month Timestamp Value
 * - RTC_MODE2_TIMESTAMP_YEAR(value) Year Timestamp Value
 **/
static inline uint32_t rtcmode1_read_TIMESTAMP(void)
{
	return RTC->MODE1.TIMESTAMP.reg;
}

#endif /* _RTC_H */
