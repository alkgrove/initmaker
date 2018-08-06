/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM ICM
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

#ifndef _ICM_H_
#define _ICM_H_

#include <stdbool.h>

/**
 * @brief icmdescriptor set RADDR register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 **/
static inline void icmdescriptor_set_RADDR(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
	pICMdesc->RADDR.reg |= mask;
}

/**
 * @brief icmdescriptor get RADDR register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t icmdescriptor_get_RADDR(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
    return pICMdesc->RADDR.reg & mask;
}

/**
 * @brief icmdescriptor write RADDR register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] data uint32_t 
 **/
static inline void icmdescriptor_write_RADDR(IcmDescriptor_t *pICMdesc, uint32_t data)
{
	pICMdesc->RADDR.reg = data;
}

/**
 * @brief icmdescriptor clear RADDR register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 **/
static inline void icmdescriptor_clear_RADDR(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
	pICMdesc->RADDR.reg &= ~mask;
}

/**
 * @brief icmdescriptor read RADDR register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @return uint32_t
 **/
static inline uint32_t icmdescriptor_read_RADDR(IcmDescriptor_t *pICMdesc)
{
	return pICMdesc->RADDR.reg;
}

/**
 * @brief icmdescriptor set RCFG register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 * - ICM_RCFG_CDWBN Compare Digest Write Back
 *  +      ICM_RCFG_CDWBN_WRBA
 *  +      ICM_RCFG_CDWBN_COMP
 * - ICM_RCFG_WRAP Region Wrap
 *  +      ICM_RCFG_WRAP_NO
 *  +      ICM_RCFG_WRAP_YES
 * - ICM_RCFG_EOM End of Monitoring
 *  +      ICM_RCFG_EOM_NO
 *  +      ICM_RCFG_EOM_YES
 * - ICM_RCFG_RHIEN Region Hash Interrupt Enable
 *  +      ICM_RCFG_RHIEN_EN
 *  +      ICM_RCFG_RHIEN_DIS
 * - ICM_RCFG_DMIEN Region Digest Mismatch Interrupt Enable
 *  +      ICM_RCFG_DMIEN_EN
 *  +      ICM_RCFG_DMIEN_DIS
 * - ICM_RCFG_BEIEN Region Bus Error Interrupt Enable
 *  +      ICM_RCFG_BEIEN_EN
 *  +      ICM_RCFG_BEIEN_DIS
 * - ICM_RCFG_WCIEN Region Wrap Condition Detected Interrupt Enable
 *  +      ICM_RCFG_WCIEN_EN
 *  +      ICM_RCFG_WCIEN_DIS
 * - ICM_RCFG_ECIEN Region End bit Condition detected Interrupt Enable
 *  +      ICM_RCFG_ECIEN_EN
 *  +      ICM_RCFG_ECIEN_DIS
 * - ICM_RCFG_SUIEN Region Status Updated Interrupt Enable
 *  +      ICM_RCFG_SUIEN_EN
 *  +      ICM_RCFG_SUIEN_DIS
 * - ICM_RCFG_PROCDLY SHA Processing Delay
 *  +      ICM_RCFG_PROCDLY_SHORT
 *  +      ICM_RCFG_PROCDLY_LONG
 * - ICM_RCFG_ALGO(value) SHA Algorithm
 * - ICM_RCFG_MRPROT(value) Memory Region AHB Protection
 **/
static inline void icmdescriptor_set_RCFG(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
	pICMdesc->RCFG.reg |= mask;
}

/**
 * @brief icmdescriptor get RCFG register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_RCFG_CDWBN Compare Digest Write Back
 *  +      ICM_RCFG_CDWBN_WRBA
 *  +      ICM_RCFG_CDWBN_COMP
 * - ICM_RCFG_WRAP Region Wrap
 *  +      ICM_RCFG_WRAP_NO
 *  +      ICM_RCFG_WRAP_YES
 * - ICM_RCFG_EOM End of Monitoring
 *  +      ICM_RCFG_EOM_NO
 *  +      ICM_RCFG_EOM_YES
 * - ICM_RCFG_RHIEN Region Hash Interrupt Enable
 *  +      ICM_RCFG_RHIEN_EN
 *  +      ICM_RCFG_RHIEN_DIS
 * - ICM_RCFG_DMIEN Region Digest Mismatch Interrupt Enable
 *  +      ICM_RCFG_DMIEN_EN
 *  +      ICM_RCFG_DMIEN_DIS
 * - ICM_RCFG_BEIEN Region Bus Error Interrupt Enable
 *  +      ICM_RCFG_BEIEN_EN
 *  +      ICM_RCFG_BEIEN_DIS
 * - ICM_RCFG_WCIEN Region Wrap Condition Detected Interrupt Enable
 *  +      ICM_RCFG_WCIEN_EN
 *  +      ICM_RCFG_WCIEN_DIS
 * - ICM_RCFG_ECIEN Region End bit Condition detected Interrupt Enable
 *  +      ICM_RCFG_ECIEN_EN
 *  +      ICM_RCFG_ECIEN_DIS
 * - ICM_RCFG_SUIEN Region Status Updated Interrupt Enable
 *  +      ICM_RCFG_SUIEN_EN
 *  +      ICM_RCFG_SUIEN_DIS
 * - ICM_RCFG_PROCDLY SHA Processing Delay
 *  +      ICM_RCFG_PROCDLY_SHORT
 *  +      ICM_RCFG_PROCDLY_LONG
 * - ICM_RCFG_ALGO(value) SHA Algorithm
 * - ICM_RCFG_MRPROT(value) Memory Region AHB Protection
 **/
static inline uint32_t icmdescriptor_get_RCFG(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
    return pICMdesc->RCFG.reg & mask;
}

/**
 * @brief icmdescriptor write RCFG register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] data uint32_t 
 * - ICM_RCFG_CDWBN Compare Digest Write Back
 *  +      ICM_RCFG_CDWBN_WRBA
 *  +      ICM_RCFG_CDWBN_COMP
 * - ICM_RCFG_WRAP Region Wrap
 *  +      ICM_RCFG_WRAP_NO
 *  +      ICM_RCFG_WRAP_YES
 * - ICM_RCFG_EOM End of Monitoring
 *  +      ICM_RCFG_EOM_NO
 *  +      ICM_RCFG_EOM_YES
 * - ICM_RCFG_RHIEN Region Hash Interrupt Enable
 *  +      ICM_RCFG_RHIEN_EN
 *  +      ICM_RCFG_RHIEN_DIS
 * - ICM_RCFG_DMIEN Region Digest Mismatch Interrupt Enable
 *  +      ICM_RCFG_DMIEN_EN
 *  +      ICM_RCFG_DMIEN_DIS
 * - ICM_RCFG_BEIEN Region Bus Error Interrupt Enable
 *  +      ICM_RCFG_BEIEN_EN
 *  +      ICM_RCFG_BEIEN_DIS
 * - ICM_RCFG_WCIEN Region Wrap Condition Detected Interrupt Enable
 *  +      ICM_RCFG_WCIEN_EN
 *  +      ICM_RCFG_WCIEN_DIS
 * - ICM_RCFG_ECIEN Region End bit Condition detected Interrupt Enable
 *  +      ICM_RCFG_ECIEN_EN
 *  +      ICM_RCFG_ECIEN_DIS
 * - ICM_RCFG_SUIEN Region Status Updated Interrupt Enable
 *  +      ICM_RCFG_SUIEN_EN
 *  +      ICM_RCFG_SUIEN_DIS
 * - ICM_RCFG_PROCDLY SHA Processing Delay
 *  +      ICM_RCFG_PROCDLY_SHORT
 *  +      ICM_RCFG_PROCDLY_LONG
 * - ICM_RCFG_ALGO(value) SHA Algorithm
 * - ICM_RCFG_MRPROT(value) Memory Region AHB Protection
 **/
static inline void icmdescriptor_write_RCFG(IcmDescriptor_t *pICMdesc, uint32_t data)
{
	pICMdesc->RCFG.reg = data;
}

/**
 * @brief icmdescriptor clear RCFG register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 * - ICM_RCFG_CDWBN Compare Digest Write Back
 *  +      ICM_RCFG_CDWBN_WRBA
 *  +      ICM_RCFG_CDWBN_COMP
 * - ICM_RCFG_WRAP Region Wrap
 *  +      ICM_RCFG_WRAP_NO
 *  +      ICM_RCFG_WRAP_YES
 * - ICM_RCFG_EOM End of Monitoring
 *  +      ICM_RCFG_EOM_NO
 *  +      ICM_RCFG_EOM_YES
 * - ICM_RCFG_RHIEN Region Hash Interrupt Enable
 *  +      ICM_RCFG_RHIEN_EN
 *  +      ICM_RCFG_RHIEN_DIS
 * - ICM_RCFG_DMIEN Region Digest Mismatch Interrupt Enable
 *  +      ICM_RCFG_DMIEN_EN
 *  +      ICM_RCFG_DMIEN_DIS
 * - ICM_RCFG_BEIEN Region Bus Error Interrupt Enable
 *  +      ICM_RCFG_BEIEN_EN
 *  +      ICM_RCFG_BEIEN_DIS
 * - ICM_RCFG_WCIEN Region Wrap Condition Detected Interrupt Enable
 *  +      ICM_RCFG_WCIEN_EN
 *  +      ICM_RCFG_WCIEN_DIS
 * - ICM_RCFG_ECIEN Region End bit Condition detected Interrupt Enable
 *  +      ICM_RCFG_ECIEN_EN
 *  +      ICM_RCFG_ECIEN_DIS
 * - ICM_RCFG_SUIEN Region Status Updated Interrupt Enable
 *  +      ICM_RCFG_SUIEN_EN
 *  +      ICM_RCFG_SUIEN_DIS
 * - ICM_RCFG_PROCDLY SHA Processing Delay
 *  +      ICM_RCFG_PROCDLY_SHORT
 *  +      ICM_RCFG_PROCDLY_LONG
 * - ICM_RCFG_ALGO(value) SHA Algorithm
 * - ICM_RCFG_MRPROT(value) Memory Region AHB Protection
 **/
static inline void icmdescriptor_clear_RCFG(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
	pICMdesc->RCFG.reg &= ~mask;
}

/**
 * @brief icmdescriptor read RCFG register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @return uint32_t
 * - ICM_RCFG_CDWBN Compare Digest Write Back
 *  +      ICM_RCFG_CDWBN_WRBA
 *  +      ICM_RCFG_CDWBN_COMP
 * - ICM_RCFG_WRAP Region Wrap
 *  +      ICM_RCFG_WRAP_NO
 *  +      ICM_RCFG_WRAP_YES
 * - ICM_RCFG_EOM End of Monitoring
 *  +      ICM_RCFG_EOM_NO
 *  +      ICM_RCFG_EOM_YES
 * - ICM_RCFG_RHIEN Region Hash Interrupt Enable
 *  +      ICM_RCFG_RHIEN_EN
 *  +      ICM_RCFG_RHIEN_DIS
 * - ICM_RCFG_DMIEN Region Digest Mismatch Interrupt Enable
 *  +      ICM_RCFG_DMIEN_EN
 *  +      ICM_RCFG_DMIEN_DIS
 * - ICM_RCFG_BEIEN Region Bus Error Interrupt Enable
 *  +      ICM_RCFG_BEIEN_EN
 *  +      ICM_RCFG_BEIEN_DIS
 * - ICM_RCFG_WCIEN Region Wrap Condition Detected Interrupt Enable
 *  +      ICM_RCFG_WCIEN_EN
 *  +      ICM_RCFG_WCIEN_DIS
 * - ICM_RCFG_ECIEN Region End bit Condition detected Interrupt Enable
 *  +      ICM_RCFG_ECIEN_EN
 *  +      ICM_RCFG_ECIEN_DIS
 * - ICM_RCFG_SUIEN Region Status Updated Interrupt Enable
 *  +      ICM_RCFG_SUIEN_EN
 *  +      ICM_RCFG_SUIEN_DIS
 * - ICM_RCFG_PROCDLY SHA Processing Delay
 *  +      ICM_RCFG_PROCDLY_SHORT
 *  +      ICM_RCFG_PROCDLY_LONG
 * - ICM_RCFG_ALGO(value) SHA Algorithm
 * - ICM_RCFG_MRPROT(value) Memory Region AHB Protection
 **/
static inline uint32_t icmdescriptor_read_RCFG(IcmDescriptor_t *pICMdesc)
{
	return pICMdesc->RCFG.reg;
}

/**
 * @brief icmdescriptor set RCTRL register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 * - ICM_RCTRL_TRSIZE(value) Transfer Size
 **/
static inline void icmdescriptor_set_RCTRL(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
	pICMdesc->RCTRL.reg |= mask;
}

/**
 * @brief icmdescriptor get RCTRL register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_RCTRL_TRSIZE(value) Transfer Size
 **/
static inline uint32_t icmdescriptor_get_RCTRL(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
    return pICMdesc->RCTRL.reg & mask;
}

/**
 * @brief icmdescriptor write RCTRL register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] data uint32_t 
 * - ICM_RCTRL_TRSIZE(value) Transfer Size
 **/
static inline void icmdescriptor_write_RCTRL(IcmDescriptor_t *pICMdesc, uint32_t data)
{
	pICMdesc->RCTRL.reg = data;
}

/**
 * @brief icmdescriptor clear RCTRL register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 * - ICM_RCTRL_TRSIZE(value) Transfer Size
 **/
static inline void icmdescriptor_clear_RCTRL(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
	pICMdesc->RCTRL.reg &= ~mask;
}

/**
 * @brief icmdescriptor read RCTRL register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @return uint32_t
 * - ICM_RCTRL_TRSIZE(value) Transfer Size
 **/
static inline uint32_t icmdescriptor_read_RCTRL(IcmDescriptor_t *pICMdesc)
{
	return pICMdesc->RCTRL.reg;
}

/**
 * @brief icmdescriptor set RNEXT register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 **/
static inline void icmdescriptor_set_RNEXT(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
	pICMdesc->RNEXT.reg |= mask;
}

/**
 * @brief icmdescriptor get RNEXT register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t icmdescriptor_get_RNEXT(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
    return pICMdesc->RNEXT.reg & mask;
}

/**
 * @brief icmdescriptor write RNEXT register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] data uint32_t 
 **/
static inline void icmdescriptor_write_RNEXT(IcmDescriptor_t *pICMdesc, uint32_t data)
{
	pICMdesc->RNEXT.reg = data;
}

/**
 * @brief icmdescriptor clear RNEXT register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @param[in] mask uint32_t 
 **/
static inline void icmdescriptor_clear_RNEXT(IcmDescriptor_t *pICMdesc, uint32_t mask)
{
	pICMdesc->RNEXT.reg &= ~mask;
}

/**
 * @brief icmdescriptor read RNEXT register
 *
 * @param[in] pICMdesc IcmDescriptor_t *
 * @return uint32_t
 **/
static inline uint32_t icmdescriptor_read_RNEXT(IcmDescriptor_t *pICMdesc)
{
	return pICMdesc->RNEXT.reg;
}

/**
 * @brief icm set IMR register
 *
 * @param[in] mask uint32_t 
 * - ICM_IMR_RHC(value) Region Hash Completed Interrupt Mask
 * - ICM_IMR_RDM(value) Region Digest Mismatch Interrupt Mask
 * - ICM_IMR_RBE(value) Region Bus Error Interrupt Mask
 * - ICM_IMR_RWC(value) Region Wrap Condition Detected Interrupt Mask
 * - ICM_IMR_REC(value) Region End bit Condition Detected Interrupt Mask
 * - ICM_IMR_RSU(value) Region Status Updated Interrupt Mask
 * - ICM_IMR_URAD Undefined Register Access Detection Interrupt Mask
 **/
static inline void icm_set_IMR(uint32_t mask)
{
	ICM->IER.reg = mask;
}

/**
 * @brief icm get IMR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_IMR_RHC(value) Region Hash Completed Interrupt Mask
 * - ICM_IMR_RDM(value) Region Digest Mismatch Interrupt Mask
 * - ICM_IMR_RBE(value) Region Bus Error Interrupt Mask
 * - ICM_IMR_RWC(value) Region Wrap Condition Detected Interrupt Mask
 * - ICM_IMR_REC(value) Region End bit Condition Detected Interrupt Mask
 * - ICM_IMR_RSU(value) Region Status Updated Interrupt Mask
 * - ICM_IMR_URAD Undefined Register Access Detection Interrupt Mask
 **/
static inline uint32_t icm_get_IMR(uint32_t mask)
{
    return ICM->IMR.reg & mask;
}

/**
 * @brief icm read IMR register
 *
 * @return uint32_t
 * - ICM_IMR_RHC(value) Region Hash Completed Interrupt Mask
 * - ICM_IMR_RDM(value) Region Digest Mismatch Interrupt Mask
 * - ICM_IMR_RBE(value) Region Bus Error Interrupt Mask
 * - ICM_IMR_RWC(value) Region Wrap Condition Detected Interrupt Mask
 * - ICM_IMR_REC(value) Region End bit Condition Detected Interrupt Mask
 * - ICM_IMR_RSU(value) Region Status Updated Interrupt Mask
 * - ICM_IMR_URAD Undefined Register Access Detection Interrupt Mask
 **/
static inline uint32_t icm_read_IMR(void)
{
	return ICM->IMR.reg;
}

/**
 * @brief icm write IMR register
 *
 * @param[in] data uint32_t 
 * - ICM_IMR_RHC(value) Region Hash Completed Interrupt Mask
 * - ICM_IMR_RDM(value) Region Digest Mismatch Interrupt Mask
 * - ICM_IMR_RBE(value) Region Bus Error Interrupt Mask
 * - ICM_IMR_RWC(value) Region Wrap Condition Detected Interrupt Mask
 * - ICM_IMR_REC(value) Region End bit Condition Detected Interrupt Mask
 * - ICM_IMR_RSU(value) Region Status Updated Interrupt Mask
 * - ICM_IMR_URAD Undefined Register Access Detection Interrupt Mask
 **/
static inline void icm_write_IMR(uint32_t data)
{
	ICM->IER.reg = data;
	ICM->IDR.reg = ~data;
}

/**
 * @brief icm clear IMR register
 *
 * @param[in] mask uint32_t 
 * - ICM_IMR_RHC(value) Region Hash Completed Interrupt Mask
 * - ICM_IMR_RDM(value) Region Digest Mismatch Interrupt Mask
 * - ICM_IMR_RBE(value) Region Bus Error Interrupt Mask
 * - ICM_IMR_RWC(value) Region Wrap Condition Detected Interrupt Mask
 * - ICM_IMR_REC(value) Region End bit Condition Detected Interrupt Mask
 * - ICM_IMR_RSU(value) Region Status Updated Interrupt Mask
 * - ICM_IMR_URAD Undefined Register Access Detection Interrupt Mask
 **/
static inline void icm_clear_IMR(uint32_t mask)
{
	ICM->IDR.reg = mask;
}

/**
 * @brief icm write CTRL register
 *
 * @param[in] data uint32_t 
 * - ICM_CTRL_ENABLE ICM Enable
 * - ICM_CTRL_DISABLE ICM Disable Register
 * - ICM_CTRL_SWRST Software Reset
 * - ICM_CTRL_REHASH(value) Recompute Internal Hash
 * - ICM_CTRL_RMDIS(value) Region Monitoring Disable
 * - ICM_CTRL_RMEN(value) Region Monitoring Enable
 **/
static inline void icm_write_CTRL(uint32_t data)
{
	ICM->CTRL.reg = data;
}

/**
 * @brief icm write UIHVAL register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 * - ICM_UIHVAL_VAL(value) Initial Hash Value
 **/
static inline void icm_write_UIHVAL(uint8_t index, uint32_t data)
{
	ICM->UIHVAL[index].reg = data;
}

/**
 * @brief icm set CFG register
 *
 * @param[in] mask uint32_t 
 * - ICM_CFG_WBDIS Write Back Disable
 * - ICM_CFG_EOMDIS End of Monitoring Disable
 * - ICM_CFG_SLBDIS Secondary List Branching Disable
 * - ICM_CFG_BBC(value) Bus Burden Control
 * - ICM_CFG_ASCD Automatic Switch To Compare Digest
 * - ICM_CFG_DUALBUFF Dual Input Buffer
 * - ICM_CFG_UIHASH User Initial Hash Value
 * - ICM_CFG_UALGO(value) User SHA Algorithm
 *  +      ICM_CFG_UALGO_SHA1 SHA1 Algorithm
 *  +      ICM_CFG_UALGO_SHA256 SHA256 Algorithm
 *  +      ICM_CFG_UALGO_SHA224 SHA224 Algorithm
 * - ICM_CFG_HAPROT(value) Region Hash Area Protection
 * - ICM_CFG_DAPROT(value) Region Descriptor Area Protection
 **/
static inline void icm_set_CFG(uint32_t mask)
{
	ICM->CFG.reg |= mask;
}

/**
 * @brief icm get CFG register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_CFG_WBDIS Write Back Disable
 * - ICM_CFG_EOMDIS End of Monitoring Disable
 * - ICM_CFG_SLBDIS Secondary List Branching Disable
 * - ICM_CFG_BBC(value) Bus Burden Control
 * - ICM_CFG_ASCD Automatic Switch To Compare Digest
 * - ICM_CFG_DUALBUFF Dual Input Buffer
 * - ICM_CFG_UIHASH User Initial Hash Value
 * - ICM_CFG_UALGO(value) User SHA Algorithm
 *  +      ICM_CFG_UALGO_SHA1 SHA1 Algorithm
 *  +      ICM_CFG_UALGO_SHA256 SHA256 Algorithm
 *  +      ICM_CFG_UALGO_SHA224 SHA224 Algorithm
 * - ICM_CFG_HAPROT(value) Region Hash Area Protection
 * - ICM_CFG_DAPROT(value) Region Descriptor Area Protection
 **/
static inline uint32_t icm_get_CFG(uint32_t mask)
{
    return ICM->CFG.reg & mask;
}

/**
 * @brief icm write CFG register
 *
 * @param[in] data uint32_t 
 * - ICM_CFG_WBDIS Write Back Disable
 * - ICM_CFG_EOMDIS End of Monitoring Disable
 * - ICM_CFG_SLBDIS Secondary List Branching Disable
 * - ICM_CFG_BBC(value) Bus Burden Control
 * - ICM_CFG_ASCD Automatic Switch To Compare Digest
 * - ICM_CFG_DUALBUFF Dual Input Buffer
 * - ICM_CFG_UIHASH User Initial Hash Value
 * - ICM_CFG_UALGO(value) User SHA Algorithm
 *  +      ICM_CFG_UALGO_SHA1 SHA1 Algorithm
 *  +      ICM_CFG_UALGO_SHA256 SHA256 Algorithm
 *  +      ICM_CFG_UALGO_SHA224 SHA224 Algorithm
 * - ICM_CFG_HAPROT(value) Region Hash Area Protection
 * - ICM_CFG_DAPROT(value) Region Descriptor Area Protection
 **/
static inline void icm_write_CFG(uint32_t data)
{
	ICM->CFG.reg = data;
}

/**
 * @brief icm clear CFG register
 *
 * @param[in] mask uint32_t 
 * - ICM_CFG_WBDIS Write Back Disable
 * - ICM_CFG_EOMDIS End of Monitoring Disable
 * - ICM_CFG_SLBDIS Secondary List Branching Disable
 * - ICM_CFG_BBC(value) Bus Burden Control
 * - ICM_CFG_ASCD Automatic Switch To Compare Digest
 * - ICM_CFG_DUALBUFF Dual Input Buffer
 * - ICM_CFG_UIHASH User Initial Hash Value
 * - ICM_CFG_UALGO(value) User SHA Algorithm
 *  +      ICM_CFG_UALGO_SHA1 SHA1 Algorithm
 *  +      ICM_CFG_UALGO_SHA256 SHA256 Algorithm
 *  +      ICM_CFG_UALGO_SHA224 SHA224 Algorithm
 * - ICM_CFG_HAPROT(value) Region Hash Area Protection
 * - ICM_CFG_DAPROT(value) Region Descriptor Area Protection
 **/
static inline void icm_clear_CFG(uint32_t mask)
{
	ICM->CFG.reg &= ~mask;
}

/**
 * @brief icm read CFG register
 *
 * @return uint32_t
 * - ICM_CFG_WBDIS Write Back Disable
 * - ICM_CFG_EOMDIS End of Monitoring Disable
 * - ICM_CFG_SLBDIS Secondary List Branching Disable
 * - ICM_CFG_BBC(value) Bus Burden Control
 * - ICM_CFG_ASCD Automatic Switch To Compare Digest
 * - ICM_CFG_DUALBUFF Dual Input Buffer
 * - ICM_CFG_UIHASH User Initial Hash Value
 * - ICM_CFG_UALGO(value) User SHA Algorithm
 *  +      ICM_CFG_UALGO_SHA1 SHA1 Algorithm
 *  +      ICM_CFG_UALGO_SHA256 SHA256 Algorithm
 *  +      ICM_CFG_UALGO_SHA224 SHA224 Algorithm
 * - ICM_CFG_HAPROT(value) Region Hash Area Protection
 * - ICM_CFG_DAPROT(value) Region Descriptor Area Protection
 **/
static inline uint32_t icm_read_CFG(void)
{
	return ICM->CFG.reg;
}

/**
 * @brief icm set DSCR register
 *
 * @param[in] mask uint32_t 
 * - ICM_DSCR_DASA(value) Descriptor Area Start Address
 **/
static inline void icm_set_DSCR(uint32_t mask)
{
	ICM->DSCR.reg |= mask;
}

/**
 * @brief icm get DSCR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_DSCR_DASA(value) Descriptor Area Start Address
 **/
static inline uint32_t icm_get_DSCR(uint32_t mask)
{
    return ICM->DSCR.reg & mask;
}

/**
 * @brief icm write DSCR register
 *
 * @param[in] data uint32_t 
 * - ICM_DSCR_DASA(value) Descriptor Area Start Address
 **/
static inline void icm_write_DSCR(uint32_t data)
{
	ICM->DSCR.reg = data;
}

/**
 * @brief icm clear DSCR register
 *
 * @param[in] mask uint32_t 
 * - ICM_DSCR_DASA(value) Descriptor Area Start Address
 **/
static inline void icm_clear_DSCR(uint32_t mask)
{
	ICM->DSCR.reg &= ~mask;
}

/**
 * @brief icm read DSCR register
 *
 * @return uint32_t
 * - ICM_DSCR_DASA(value) Descriptor Area Start Address
 **/
static inline uint32_t icm_read_DSCR(void)
{
	return ICM->DSCR.reg;
}

/**
 * @brief icm set HASH register
 *
 * @param[in] mask uint32_t 
 * - ICM_HASH_HASA(value) Hash Area Start Address
 **/
static inline void icm_set_HASH(uint32_t mask)
{
	ICM->HASH.reg |= mask;
}

/**
 * @brief icm get HASH register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_HASH_HASA(value) Hash Area Start Address
 **/
static inline uint32_t icm_get_HASH(uint32_t mask)
{
    return ICM->HASH.reg & mask;
}

/**
 * @brief icm write HASH register
 *
 * @param[in] data uint32_t 
 * - ICM_HASH_HASA(value) Hash Area Start Address
 **/
static inline void icm_write_HASH(uint32_t data)
{
	ICM->HASH.reg = data;
}

/**
 * @brief icm clear HASH register
 *
 * @param[in] mask uint32_t 
 * - ICM_HASH_HASA(value) Hash Area Start Address
 **/
static inline void icm_clear_HASH(uint32_t mask)
{
	ICM->HASH.reg &= ~mask;
}

/**
 * @brief icm read HASH register
 *
 * @return uint32_t
 * - ICM_HASH_HASA(value) Hash Area Start Address
 **/
static inline uint32_t icm_read_HASH(void)
{
	return ICM->HASH.reg;
}

/**
 * @brief icm get SR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_SR_ENABLE ICM Controller Enable Register
 * - ICM_SR_RAWRMDIS(value) RAW Region Monitoring Disabled Status
 * - ICM_SR_RMDIS(value) Region Monitoring Disabled Status
 **/
static inline uint32_t icm_get_SR(uint32_t mask)
{
    return ICM->SR.reg & mask;
}

/**
 * @brief icm read SR register
 *
 * @return uint32_t
 * - ICM_SR_ENABLE ICM Controller Enable Register
 * - ICM_SR_RAWRMDIS(value) RAW Region Monitoring Disabled Status
 * - ICM_SR_RMDIS(value) Region Monitoring Disabled Status
 **/
static inline uint32_t icm_read_SR(void)
{
	return ICM->SR.reg;
}

/**
 * @brief icm get ISR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_ISR_RHC(value) Region Hash Completed
 * - ICM_ISR_RDM(value) Region Digest Mismatch
 * - ICM_ISR_RBE(value) Region Bus Error
 * - ICM_ISR_RWC(value) Region Wrap Condition Detected
 * - ICM_ISR_REC(value) Region End bit Condition Detected
 * - ICM_ISR_RSU(value) Region Status Updated Detected
 * - ICM_ISR_URAD Undefined Register Access Detection Status
 **/
static inline uint32_t icm_get_ISR(uint32_t mask)
{
    return ICM->ISR.reg & mask;
}

/**
 * @brief icm read ISR register
 *
 * @return uint32_t
 * - ICM_ISR_RHC(value) Region Hash Completed
 * - ICM_ISR_RDM(value) Region Digest Mismatch
 * - ICM_ISR_RBE(value) Region Bus Error
 * - ICM_ISR_RWC(value) Region Wrap Condition Detected
 * - ICM_ISR_REC(value) Region End bit Condition Detected
 * - ICM_ISR_RSU(value) Region Status Updated Detected
 * - ICM_ISR_URAD Undefined Register Access Detection Status
 **/
static inline uint32_t icm_read_ISR(void)
{
	return ICM->ISR.reg;
}

/**
 * @brief icm get UASR register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - ICM_UASR_URAT(value) Undefined Register Access Trace
 *  +      ICM_UASR_URAT_UNSPEC_STRUCT_MEMBER Unspecified structure member set to one detected when the descriptor is loaded
 *  +      ICM_UASR_URAT_CFG_MODIFIED CFG modified during active monitoring
 *  +      ICM_UASR_URAT_DSCR_MODIFIED DSCR modified during active monitoring
 *  +      ICM_UASR_URAT_HASH_MODIFIED HASH modified during active monitoring
 *  +      ICM_UASR_URAT_READ_ACCESS Write-only register read access
 **/
static inline uint32_t icm_get_UASR(uint32_t mask)
{
    return ICM->UASR.reg & mask;
}

/**
 * @brief icm read UASR register
 *
 * @return uint32_t
 * - ICM_UASR_URAT(value) Undefined Register Access Trace
 *  +      ICM_UASR_URAT_UNSPEC_STRUCT_MEMBER Unspecified structure member set to one detected when the descriptor is loaded
 *  +      ICM_UASR_URAT_CFG_MODIFIED CFG modified during active monitoring
 *  +      ICM_UASR_URAT_DSCR_MODIFIED DSCR modified during active monitoring
 *  +      ICM_UASR_URAT_HASH_MODIFIED HASH modified during active monitoring
 *  +      ICM_UASR_URAT_READ_ACCESS Write-only register read access
 **/
static inline uint32_t icm_read_UASR(void)
{
	return ICM->UASR.reg;
}

#endif /* _ICM_H */
