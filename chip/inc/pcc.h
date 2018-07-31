/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM PCC
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

#ifndef _PCC_H_
#define _PCC_H_

#include <stdbool.h>

/**
 * @brief pcc set IMR register
 *
 * @param[in] uint32_t mask
 * PCC_IMR_DRDY  Data Ready Interrupt Mask 
 * PCC_IMR_OVRE  Overrun Error Interrupt Mask 
 */
static inline void pcc_set_IMR(uint32_t mask)
{
	PCC->IER.reg = mask;
}

/**
 * @brief pcc get IMR register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * PCC_IMR_DRDY  Data Ready Interrupt Mask 
 * PCC_IMR_OVRE  Overrun Error Interrupt Mask 
 */
static inline uint32_t pcc_get_IMR(uint32_t mask)
{
    return PCC->IMR.reg & mask;
}

/**
 * @brief pcc read IMR register
 *
 * @param[in] void
 * @return uint32_t
 * PCC_IMR_DRDY  Data Ready Interrupt Mask 
 * PCC_IMR_OVRE  Overrun Error Interrupt Mask 
 */
static inline uint32_t pcc_read_IMR(void)
{
	return PCC->IMR.reg;
}

/**
 * @brief pcc write IMR register
 *
 * @param[in] uint32_t data
 * PCC_IMR_DRDY  Data Ready Interrupt Mask 
 * PCC_IMR_OVRE  Overrun Error Interrupt Mask 
 */
static inline void pcc_write_IMR(uint32_t data)
{
	PCC->IER.reg = data;
	PCC->IDR.reg = ~data;
}

/**
 * @brief pcc clear IMR register
 *
 * @param[in] uint32_t mask
 * PCC_IMR_DRDY  Data Ready Interrupt Mask 
 * PCC_IMR_OVRE  Overrun Error Interrupt Mask 
 */
static inline void pcc_clear_IMR(uint32_t mask)
{
	PCC->IDR.reg = mask;
}

/**
 * @brief pcc set MR register
 *
 * @param[in] uint32_t mask
 * PCC_MR_PCEN  Parallel Capture Enable 
 * PCC_MR_DSIZE(value)  Data size 
 * PCC_MR_SCALE  Scale data 
 * PCC_MR_ALWYS  Always Sampling 
 * PCC_MR_HALFS  Half Sampling 
 * PCC_MR_FRSTS  First sample 
 * PCC_MR_ISIZE(value)  Input Data Size 
 * PCC_MR_CID(value)  Clear If Disabled 
 */
static inline void pcc_set_MR(uint32_t mask)
{
	PCC->MR.reg |= mask;
}

/**
 * @brief pcc get MR register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * PCC_MR_PCEN  Parallel Capture Enable 
 * PCC_MR_DSIZE(value)  Data size 
 * PCC_MR_SCALE  Scale data 
 * PCC_MR_ALWYS  Always Sampling 
 * PCC_MR_HALFS  Half Sampling 
 * PCC_MR_FRSTS  First sample 
 * PCC_MR_ISIZE(value)  Input Data Size 
 * PCC_MR_CID(value)  Clear If Disabled 
 */
static inline uint32_t pcc_get_MR(uint32_t mask)
{
    return PCC->MR.reg & mask;
}

/**
 * @brief pcc write MR register
 *
 * @param[in] uint32_t data
 * PCC_MR_PCEN  Parallel Capture Enable 
 * PCC_MR_DSIZE(value)  Data size 
 * PCC_MR_SCALE  Scale data 
 * PCC_MR_ALWYS  Always Sampling 
 * PCC_MR_HALFS  Half Sampling 
 * PCC_MR_FRSTS  First sample 
 * PCC_MR_ISIZE(value)  Input Data Size 
 * PCC_MR_CID(value)  Clear If Disabled 
 */
static inline void pcc_write_MR(uint32_t data)
{
	PCC->MR.reg = data;
}

/**
 * @brief pcc clear MR register
 *
 * @param[in] uint32_t mask
 * PCC_MR_PCEN  Parallel Capture Enable 
 * PCC_MR_DSIZE(value)  Data size 
 * PCC_MR_SCALE  Scale data 
 * PCC_MR_ALWYS  Always Sampling 
 * PCC_MR_HALFS  Half Sampling 
 * PCC_MR_FRSTS  First sample 
 * PCC_MR_ISIZE(value)  Input Data Size 
 * PCC_MR_CID(value)  Clear If Disabled 
 */
static inline void pcc_clear_MR(uint32_t mask)
{
	PCC->MR.reg &= ~mask;
}

/**
 * @brief pcc read MR register
 *
 * @param[in] void
 * @return uint32_t
 * PCC_MR_PCEN  Parallel Capture Enable 
 * PCC_MR_DSIZE(value)  Data size 
 * PCC_MR_SCALE  Scale data 
 * PCC_MR_ALWYS  Always Sampling 
 * PCC_MR_HALFS  Half Sampling 
 * PCC_MR_FRSTS  First sample 
 * PCC_MR_ISIZE(value)  Input Data Size 
 * PCC_MR_CID(value)  Clear If Disabled 
 */
static inline uint32_t pcc_read_MR(void)
{
	return PCC->MR.reg;
}

/**
 * @brief pcc set WPMR register
 *
 * @param[in] uint32_t mask
 * PCC_WPMR_WPEN  Write Protection Enable 
 * PCC_WPMR_WPKEY(value)  Write Protection Key 
 */
static inline void pcc_set_WPMR(uint32_t mask)
{
	PCC->WPMR.reg |= mask;
}

/**
 * @brief pcc get WPMR register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * PCC_WPMR_WPEN  Write Protection Enable 
 * PCC_WPMR_WPKEY(value)  Write Protection Key 
 */
static inline uint32_t pcc_get_WPMR(uint32_t mask)
{
    return PCC->WPMR.reg & mask;
}

/**
 * @brief pcc write WPMR register
 *
 * @param[in] uint32_t data
 * PCC_WPMR_WPEN  Write Protection Enable 
 * PCC_WPMR_WPKEY(value)  Write Protection Key 
 */
static inline void pcc_write_WPMR(uint32_t data)
{
	PCC->WPMR.reg = data;
}

/**
 * @brief pcc clear WPMR register
 *
 * @param[in] uint32_t mask
 * PCC_WPMR_WPEN  Write Protection Enable 
 * PCC_WPMR_WPKEY(value)  Write Protection Key 
 */
static inline void pcc_clear_WPMR(uint32_t mask)
{
	PCC->WPMR.reg &= ~mask;
}

/**
 * @brief pcc read WPMR register
 *
 * @param[in] void
 * @return uint32_t
 * PCC_WPMR_WPEN  Write Protection Enable 
 * PCC_WPMR_WPKEY(value)  Write Protection Key 
 */
static inline uint32_t pcc_read_WPMR(void)
{
	return PCC->WPMR.reg;
}

/**
 * @brief pcc get ISR register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * PCC_ISR_DRDY  Data Ready Interrupt Status 
 * PCC_ISR_OVRE  Overrun Error Interrupt Status 
 */
static inline uint32_t pcc_get_ISR(uint32_t mask)
{
    return PCC->ISR.reg & mask;
}

/**
 * @brief pcc read ISR register
 *
 * @param[in] void
 * @return uint32_t
 * PCC_ISR_DRDY  Data Ready Interrupt Status 
 * PCC_ISR_OVRE  Overrun Error Interrupt Status 
 */
static inline uint32_t pcc_read_ISR(void)
{
	return PCC->ISR.reg;
}

/**
 * @brief pcc get RHR register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * PCC_RHR_RDATA(value)  Reception Data 
 */
static inline uint32_t pcc_get_RHR(uint32_t mask)
{
    return PCC->RHR.reg & mask;
}

/**
 * @brief pcc read RHR register
 *
 * @param[in] void
 * @return uint32_t
 * PCC_RHR_RDATA(value)  Reception Data 
 */
static inline uint32_t pcc_read_RHR(void)
{
	return PCC->RHR.reg;
}

/**
 * @brief pcc get WPSR register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * PCC_WPSR_WPVS  Write Protection Violation Source 
 * PCC_WPSR_WPVSRC(value)  Write Protection Violation Status 
 */
static inline uint32_t pcc_get_WPSR(uint32_t mask)
{
    return PCC->WPSR.reg & mask;
}

/**
 * @brief pcc read WPSR register
 *
 * @param[in] void
 * @return uint32_t
 * PCC_WPSR_WPVS  Write Protection Violation Source 
 * PCC_WPSR_WPVSRC(value)  Write Protection Violation Status 
 */
static inline uint32_t pcc_read_WPSR(void)
{
	return PCC->WPSR.reg;
}

#endif /* _PCC_H */
