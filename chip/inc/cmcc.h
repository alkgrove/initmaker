/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM CMCC
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

#ifndef _CMCC_H_
#define _CMCC_H_

#include <stdbool.h>

/**
 * @brief cmcc write CTRL register
 *
 * @param[in] uint32_t data
 * CMCC_CTRL_CEN  Cache Controller Enable 
 */
static inline void cmcc_write_CTRL(uint32_t data)
{
	CMCC->CTRL.reg = data;
}

/**
 * @brief cmcc write MAINT0 register
 *
 * @param[in] uint32_t data
 * CMCC_MAINT0_INVALL  Cache Controller invalidate All 
 */
static inline void cmcc_write_MAINT0(uint32_t data)
{
	CMCC->MAINT0.reg = data;
}

/**
 * @brief cmcc write MAINT1 register
 *
 * @param[in] uint32_t data
 * CMCC_MAINT1_INDEX(value)  Invalidate Index 
 * CMCC_MAINT1_WAY(value)  Invalidate Way 
 *    CMCC_MAINT1_WAY_WAY0  Way 0 is selection for index invalidation 
 *    CMCC_MAINT1_WAY_WAY1  Way 1 is selection for index invalidation 
 *    CMCC_MAINT1_WAY_WAY2  Way 2 is selection for index invalidation 
 *    CMCC_MAINT1_WAY_WAY3  Way 3 is selection for index invalidation 
 */
static inline void cmcc_write_MAINT1(uint32_t data)
{
	CMCC->MAINT1.reg = data;
}

/**
 * @brief cmcc write MCTRL register
 *
 * @param[in] uint32_t data
 * CMCC_MCTRL_SWRST  Cache Controller Software Reset 
 */
static inline void cmcc_write_MCTRL(uint32_t data)
{
	CMCC->MCTRL.reg = data;
}

/**
 * @brief cmcc set CFG register
 *
 * @param[in] uint32_t mask
 * CMCC_CFG_ICDIS  Instruction Cache Disable 
 * CMCC_CFG_DCDIS  Data Cache Disable 
 * CMCC_CFG_CSIZESW(value)  Cache size configured by software 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_1KB  the Cache Size is configured to 1KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_2KB  the Cache Size is configured to 2KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_4KB  the Cache Size is configured to 4KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_8KB  the Cache Size is configured to 8KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_16KB  the Cache Size is configured to 16KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_32KB  the Cache Size is configured to 32KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_64KB  the Cache Size is configured to 64KB 
 */
static inline void cmcc_set_CFG(uint32_t mask)
{
	CMCC->CFG.reg |= mask;
}

/**
 * @brief cmcc get CFG register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * CMCC_CFG_ICDIS  Instruction Cache Disable 
 * CMCC_CFG_DCDIS  Data Cache Disable 
 * CMCC_CFG_CSIZESW(value)  Cache size configured by software 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_1KB  the Cache Size is configured to 1KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_2KB  the Cache Size is configured to 2KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_4KB  the Cache Size is configured to 4KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_8KB  the Cache Size is configured to 8KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_16KB  the Cache Size is configured to 16KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_32KB  the Cache Size is configured to 32KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_64KB  the Cache Size is configured to 64KB 
 */
static inline uint32_t cmcc_get_CFG(uint32_t mask)
{
    return CMCC->CFG.reg & mask;
}

/**
 * @brief cmcc write CFG register
 *
 * @param[in] uint32_t data
 * CMCC_CFG_ICDIS  Instruction Cache Disable 
 * CMCC_CFG_DCDIS  Data Cache Disable 
 * CMCC_CFG_CSIZESW(value)  Cache size configured by software 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_1KB  the Cache Size is configured to 1KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_2KB  the Cache Size is configured to 2KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_4KB  the Cache Size is configured to 4KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_8KB  the Cache Size is configured to 8KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_16KB  the Cache Size is configured to 16KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_32KB  the Cache Size is configured to 32KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_64KB  the Cache Size is configured to 64KB 
 */
static inline void cmcc_write_CFG(uint32_t data)
{
	CMCC->CFG.reg = data;
}

/**
 * @brief cmcc clear CFG register
 *
 * @param[in] uint32_t mask
 * CMCC_CFG_ICDIS  Instruction Cache Disable 
 * CMCC_CFG_DCDIS  Data Cache Disable 
 * CMCC_CFG_CSIZESW(value)  Cache size configured by software 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_1KB  the Cache Size is configured to 1KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_2KB  the Cache Size is configured to 2KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_4KB  the Cache Size is configured to 4KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_8KB  the Cache Size is configured to 8KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_16KB  the Cache Size is configured to 16KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_32KB  the Cache Size is configured to 32KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_64KB  the Cache Size is configured to 64KB 
 */
static inline void cmcc_clear_CFG(uint32_t mask)
{
	CMCC->CFG.reg &= ~mask;
}

/**
 * @brief cmcc read CFG register
 *
 * @param[in] void
 * @return uint32_t
 * CMCC_CFG_ICDIS  Instruction Cache Disable 
 * CMCC_CFG_DCDIS  Data Cache Disable 
 * CMCC_CFG_CSIZESW(value)  Cache size configured by software 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_1KB  the Cache Size is configured to 1KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_2KB  the Cache Size is configured to 2KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_4KB  the Cache Size is configured to 4KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_8KB  the Cache Size is configured to 8KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_16KB  the Cache Size is configured to 16KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_32KB  the Cache Size is configured to 32KB 
 *    CMCC_CFG_CSIZESW_CONF_CSIZE_64KB  the Cache Size is configured to 64KB 
 */
static inline uint32_t cmcc_read_CFG(void)
{
	return CMCC->CFG.reg;
}

/**
 * @brief cmcc set LCKWAY register
 *
 * @param[in] uint32_t mask
 * CMCC_LCKWAY_LCKWAY(value)  Lockdown way Register 
 */
static inline void cmcc_set_LCKWAY(uint32_t mask)
{
	CMCC->LCKWAY.reg |= mask;
}

/**
 * @brief cmcc get LCKWAY register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * CMCC_LCKWAY_LCKWAY(value)  Lockdown way Register 
 */
static inline uint32_t cmcc_get_LCKWAY(uint32_t mask)
{
    return CMCC->LCKWAY.reg & mask;
}

/**
 * @brief cmcc write LCKWAY register
 *
 * @param[in] uint32_t data
 * CMCC_LCKWAY_LCKWAY(value)  Lockdown way Register 
 */
static inline void cmcc_write_LCKWAY(uint32_t data)
{
	CMCC->LCKWAY.reg = data;
}

/**
 * @brief cmcc clear LCKWAY register
 *
 * @param[in] uint32_t mask
 * CMCC_LCKWAY_LCKWAY(value)  Lockdown way Register 
 */
static inline void cmcc_clear_LCKWAY(uint32_t mask)
{
	CMCC->LCKWAY.reg &= ~mask;
}

/**
 * @brief cmcc read LCKWAY register
 *
 * @param[in] void
 * @return uint32_t
 * CMCC_LCKWAY_LCKWAY(value)  Lockdown way Register 
 */
static inline uint32_t cmcc_read_LCKWAY(void)
{
	return CMCC->LCKWAY.reg;
}

/**
 * @brief cmcc set MCFG register
 *
 * @param[in] uint32_t mask
 * CMCC_MCFG_MODE(value)  Cache Controller Monitor Counter Mode 
 *    CMCC_MCFG_MODE_CYCLE_COUNT  cycle counter 
 *    CMCC_MCFG_MODE_IHIT_COUNT  instruction hit counter 
 *    CMCC_MCFG_MODE_DHIT_COUNT  data hit counter 
 */
static inline void cmcc_set_MCFG(uint32_t mask)
{
	CMCC->MCFG.reg |= mask;
}

/**
 * @brief cmcc get MCFG register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * CMCC_MCFG_MODE(value)  Cache Controller Monitor Counter Mode 
 *    CMCC_MCFG_MODE_CYCLE_COUNT  cycle counter 
 *    CMCC_MCFG_MODE_IHIT_COUNT  instruction hit counter 
 *    CMCC_MCFG_MODE_DHIT_COUNT  data hit counter 
 */
static inline uint32_t cmcc_get_MCFG(uint32_t mask)
{
    return CMCC->MCFG.reg & mask;
}

/**
 * @brief cmcc write MCFG register
 *
 * @param[in] uint32_t data
 * CMCC_MCFG_MODE(value)  Cache Controller Monitor Counter Mode 
 *    CMCC_MCFG_MODE_CYCLE_COUNT  cycle counter 
 *    CMCC_MCFG_MODE_IHIT_COUNT  instruction hit counter 
 *    CMCC_MCFG_MODE_DHIT_COUNT  data hit counter 
 */
static inline void cmcc_write_MCFG(uint32_t data)
{
	CMCC->MCFG.reg = data;
}

/**
 * @brief cmcc clear MCFG register
 *
 * @param[in] uint32_t mask
 * CMCC_MCFG_MODE(value)  Cache Controller Monitor Counter Mode 
 *    CMCC_MCFG_MODE_CYCLE_COUNT  cycle counter 
 *    CMCC_MCFG_MODE_IHIT_COUNT  instruction hit counter 
 *    CMCC_MCFG_MODE_DHIT_COUNT  data hit counter 
 */
static inline void cmcc_clear_MCFG(uint32_t mask)
{
	CMCC->MCFG.reg &= ~mask;
}

/**
 * @brief cmcc read MCFG register
 *
 * @param[in] void
 * @return uint32_t
 * CMCC_MCFG_MODE(value)  Cache Controller Monitor Counter Mode 
 *    CMCC_MCFG_MODE_CYCLE_COUNT  cycle counter 
 *    CMCC_MCFG_MODE_IHIT_COUNT  instruction hit counter 
 *    CMCC_MCFG_MODE_DHIT_COUNT  data hit counter 
 */
static inline uint32_t cmcc_read_MCFG(void)
{
	return CMCC->MCFG.reg;
}

/**
 * @brief cmcc set MEN register
 *
 * @param[in] uint32_t mask
 * CMCC_MEN_MENABLE  Cache Controller Monitor Enable 
 */
static inline void cmcc_set_MEN(uint32_t mask)
{
	CMCC->MEN.reg |= mask;
}

/**
 * @brief cmcc get MEN register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * CMCC_MEN_MENABLE  Cache Controller Monitor Enable 
 */
static inline uint32_t cmcc_get_MEN(uint32_t mask)
{
    return CMCC->MEN.reg & mask;
}

/**
 * @brief cmcc write MEN register
 *
 * @param[in] uint32_t data
 * CMCC_MEN_MENABLE  Cache Controller Monitor Enable 
 */
static inline void cmcc_write_MEN(uint32_t data)
{
	CMCC->MEN.reg = data;
}

/**
 * @brief cmcc clear MEN register
 *
 * @param[in] uint32_t mask
 * CMCC_MEN_MENABLE  Cache Controller Monitor Enable 
 */
static inline void cmcc_clear_MEN(uint32_t mask)
{
	CMCC->MEN.reg &= ~mask;
}

/**
 * @brief cmcc read MEN register
 *
 * @param[in] void
 * @return uint32_t
 * CMCC_MEN_MENABLE  Cache Controller Monitor Enable 
 */
static inline uint32_t cmcc_read_MEN(void)
{
	return CMCC->MEN.reg;
}

/**
 * @brief cmcc get TYPE register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * CMCC_TYPE_GCLK  dynamic Clock Gating supported 
 * CMCC_TYPE_RRP  Round Robin Policy supported 
 * CMCC_TYPE_WAYNUM(value)  Number of Way 
 *    CMCC_TYPE_WAYNUM_DMAPPED  Direct Mapped Cache 
 *    CMCC_TYPE_WAYNUM_ARCH2WAY  2-WAY set associative 
 *    CMCC_TYPE_WAYNUM_ARCH4WAY  4-WAY set associative 
 * CMCC_TYPE_LCKDOWN  Lock Down supported 
 * CMCC_TYPE_CSIZE(value)  Cache Size 
 *    CMCC_TYPE_CSIZE_CSIZE_1KB  Cache Size is 1 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_2KB  Cache Size is 2 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_4KB  Cache Size is 4 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_8KB  Cache Size is 8 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_16KB  Cache Size is 16 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_32KB  Cache Size is 32 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_64KB  Cache Size is 64 KB 
 * CMCC_TYPE_CLSIZE(value)  Cache Line Size 
 *    CMCC_TYPE_CLSIZE_CLSIZE_4B  Cache Line Size is 4 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_8B  Cache Line Size is 8 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_16B  Cache Line Size is 16 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_32B  Cache Line Size is 32 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_64B  Cache Line Size is 64 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_128B  Cache Line Size is 128 bytes 
 */
static inline uint32_t cmcc_get_TYPE(uint32_t mask)
{
    return CMCC->TYPE.reg & mask;
}

/**
 * @brief cmcc read TYPE register
 *
 * @param[in] void
 * @return uint32_t
 * CMCC_TYPE_GCLK  dynamic Clock Gating supported 
 * CMCC_TYPE_RRP  Round Robin Policy supported 
 * CMCC_TYPE_WAYNUM(value)  Number of Way 
 *    CMCC_TYPE_WAYNUM_DMAPPED  Direct Mapped Cache 
 *    CMCC_TYPE_WAYNUM_ARCH2WAY  2-WAY set associative 
 *    CMCC_TYPE_WAYNUM_ARCH4WAY  4-WAY set associative 
 * CMCC_TYPE_LCKDOWN  Lock Down supported 
 * CMCC_TYPE_CSIZE(value)  Cache Size 
 *    CMCC_TYPE_CSIZE_CSIZE_1KB  Cache Size is 1 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_2KB  Cache Size is 2 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_4KB  Cache Size is 4 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_8KB  Cache Size is 8 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_16KB  Cache Size is 16 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_32KB  Cache Size is 32 KB 
 *    CMCC_TYPE_CSIZE_CSIZE_64KB  Cache Size is 64 KB 
 * CMCC_TYPE_CLSIZE(value)  Cache Line Size 
 *    CMCC_TYPE_CLSIZE_CLSIZE_4B  Cache Line Size is 4 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_8B  Cache Line Size is 8 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_16B  Cache Line Size is 16 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_32B  Cache Line Size is 32 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_64B  Cache Line Size is 64 bytes 
 *    CMCC_TYPE_CLSIZE_CLSIZE_128B  Cache Line Size is 128 bytes 
 */
static inline uint32_t cmcc_read_TYPE(void)
{
	return CMCC->TYPE.reg;
}

/**
 * @brief cmcc get SR register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * CMCC_SR_CSTS  Cache Controller Status 
 */
static inline uint32_t cmcc_get_SR(uint32_t mask)
{
    return CMCC->SR.reg & mask;
}

/**
 * @brief cmcc read SR register
 *
 * @param[in] void
 * @return uint32_t
 * CMCC_SR_CSTS  Cache Controller Status 
 */
static inline uint32_t cmcc_read_SR(void)
{
	return CMCC->SR.reg;
}

/**
 * @brief cmcc get MSR register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * CMCC_MSR_EVENT_CNT(value)  Monitor Event Counter 
 */
static inline uint32_t cmcc_get_MSR(uint32_t mask)
{
    return CMCC->MSR.reg & mask;
}

/**
 * @brief cmcc read MSR register
 *
 * @param[in] void
 * @return uint32_t
 * CMCC_MSR_EVENT_CNT(value)  Monitor Event Counter 
 */
static inline uint32_t cmcc_read_MSR(void)
{
	return CMCC->MSR.reg;
}

#endif /* _CMCC_H */
