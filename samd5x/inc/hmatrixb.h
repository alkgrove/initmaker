/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM HMATRIXB
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

#ifndef _HMATRIXB_H_
#define _HMATRIXB_H_

#include <stdbool.h>

/**
 * @brief hmatrixb set PRAS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 */
static inline void hmatrixb_set_PRAS(uint8_t submodule_index, uint32_t mask)
{
	HMATRIX->Prs[submodule_index].PRAS.reg |= mask;
}

/**
 * @brief hmatrixb get PRAS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t hmatrixb_get_PRAS(uint8_t submodule_index, uint32_t mask)
{
    return HMATRIX->Prs[submodule_index].PRAS.reg & mask;
}

/**
 * @brief hmatrixb write PRAS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t data
 */
static inline void hmatrixb_write_PRAS(uint8_t submodule_index, uint32_t data)
{
	HMATRIX->Prs[submodule_index].PRAS.reg = data;
}

/**
 * @brief hmatrixb clear PRAS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 */
static inline void hmatrixb_clear_PRAS(uint8_t submodule_index, uint32_t mask)
{
	HMATRIX->Prs[submodule_index].PRAS.reg &= ~mask;
}

/**
 * @brief hmatrixb read PRAS register
 *
 * @param[in] uint8_t submodule_index
 * @return uint32_t
 */
static inline uint32_t hmatrixb_read_PRAS(uint8_t submodule_index)
{
	return HMATRIX->Prs[submodule_index].PRAS.reg;
}

/**
 * @brief hmatrixb set PRBS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 */
static inline void hmatrixb_set_PRBS(uint8_t submodule_index, uint32_t mask)
{
	HMATRIX->Prs[submodule_index].PRBS.reg |= mask;
}

/**
 * @brief hmatrixb get PRBS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * @return uint32_t
 */
static inline uint32_t hmatrixb_get_PRBS(uint8_t submodule_index, uint32_t mask)
{
    return HMATRIX->Prs[submodule_index].PRBS.reg & mask;
}

/**
 * @brief hmatrixb write PRBS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t data
 */
static inline void hmatrixb_write_PRBS(uint8_t submodule_index, uint32_t data)
{
	HMATRIX->Prs[submodule_index].PRBS.reg = data;
}

/**
 * @brief hmatrixb clear PRBS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 */
static inline void hmatrixb_clear_PRBS(uint8_t submodule_index, uint32_t mask)
{
	HMATRIX->Prs[submodule_index].PRBS.reg &= ~mask;
}

/**
 * @brief hmatrixb read PRBS register
 *
 * @param[in] uint8_t submodule_index
 * @return uint32_t
 */
static inline uint32_t hmatrixb_read_PRBS(uint8_t submodule_index)
{
	return HMATRIX->Prs[submodule_index].PRBS.reg;
}

#endif /* _HMATRIXB_H */
