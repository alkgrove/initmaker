/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM USB
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

#ifndef _USB_H_
#define _USB_H_

#include <stdbool.h>

/**
 * @brief usbdevice wait for sync
 *
 * @param[in] uint8_t reg
 */
static inline void usbdevice_wait_for_sync(uint8_t reg)
{
	while (USB->DEVICE.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief usbdevice is syncing
 *
 * @param[in] uint8_t reg
 * @return bool
 */
static inline bool usbdevice_is_syncing(uint8_t reg)
{
	return USB->DEVICE.SYNCBUSY.reg & reg;
}

/**
 * @brief usbhost wait for sync
 *
 * @param[in] uint8_t reg
 */
static inline void usbhost_wait_for_sync(uint8_t reg)
{
	while (USB->HOST.SYNCBUSY.reg & reg) {
	};
}

/**
 * @brief usbhost is syncing
 *
 * @param[in] uint8_t reg
 * @return bool
 */
static inline bool usbhost_is_syncing(uint8_t reg)
{
	return USB->HOST.SYNCBUSY.reg & reg;
}

/**
 * @brief usbpipe set PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbpipe_set_PSTATUS(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PSTATUSSET.reg = mask;
}

/**
 * @brief usbpipe get PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline uint8_t usbpipe_get_PSTATUS(uint8_t submodule_index, uint8_t mask)
{
    return ((USBHOST_t *)USB)->HostPipe[submodule_index].PSTATUS.reg & mask;
}

/**
 * @brief usbpipe read PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline uint8_t usbpipe_read_PSTATUS(uint8_t submodule_index)
{
	return ((USBHOST_t *)USB)->HostPipe[submodule_index].PSTATUS.reg;
}

/**
 * @brief usbpipe write PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbpipe_write_PSTATUS(uint8_t submodule_index, uint8_t data)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PSTATUSSET.reg = data;
	((USBHOST_t *)USB)->HostPipe[submodule_index].PSTATUSCLR.reg = ~data;
}

/**
 * @brief usbpipe clear PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbpipe_clear_PSTATUS(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PSTATUSCLR.reg = mask;
}

/**
 * @brief usbpipe set PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline void usbpipe_set_PINTEN(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PINTENSET.reg = mask;
}

/**
 * @brief usbpipe get PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline uint8_t usbpipe_get_PINTEN(uint8_t submodule_index, uint8_t mask)
{
    return ((USBHOST_t *)USB)->HostPipe[submodule_index].PINTENSET.reg & mask;
}

/**
 * @brief usbpipe read PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline uint8_t usbpipe_read_PINTEN(uint8_t submodule_index)
{
	return ((USBHOST_t *)USB)->HostPipe[submodule_index].PINTENSET.reg;
}

/**
 * @brief usbpipe write PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline void usbpipe_write_PINTEN(uint8_t submodule_index, uint8_t data)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PINTENSET.reg = data;
	((USBHOST_t *)USB)->HostPipe[submodule_index].PINTENCLR.reg = ~data;
}

/**
 * @brief usbpipe clear PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline void usbpipe_clear_PINTEN(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PINTENCLR.reg = mask;
}

/**
 * @brief usbpipe get PINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_PINTFLAG_TRCPT0  Transfer Complete 0 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT1  Transfer Complete 1 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT(value)  Transfer Complete x Interrupt Flag 
 * USB_HOST_PINTFLAG_TRFAIL  Error Flow Interrupt Flag 
 * USB_HOST_PINTFLAG_PERR  Pipe Error Interrupt Flag 
 * USB_HOST_PINTFLAG_TXSTP  Transmit  Setup Interrupt Flag 
 * USB_HOST_PINTFLAG_STALL  Stall Interrupt Flag 
 */
static inline uint8_t usbpipe_get_PINTFLAG(uint8_t submodule_index, uint8_t mask)
{
    return ((USBHOST_t *)USB)->HostPipe[submodule_index].PINTFLAG.reg & mask;
}

/**
 * @brief usbpipe read PINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_PINTFLAG_TRCPT0  Transfer Complete 0 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT1  Transfer Complete 1 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT(value)  Transfer Complete x Interrupt Flag 
 * USB_HOST_PINTFLAG_TRFAIL  Error Flow Interrupt Flag 
 * USB_HOST_PINTFLAG_PERR  Pipe Error Interrupt Flag 
 * USB_HOST_PINTFLAG_TXSTP  Transmit  Setup Interrupt Flag 
 * USB_HOST_PINTFLAG_STALL  Stall Interrupt Flag 
 */
static inline uint8_t usbpipe_read_PINTFLAG(uint8_t submodule_index)
{
	return ((USBHOST_t *)USB)->HostPipe[submodule_index].PINTFLAG.reg;
}

/**
 * @brief usbpipe clear PINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PINTFLAG_TRCPT0  Transfer Complete 0 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT1  Transfer Complete 1 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT(value)  Transfer Complete x Interrupt Flag 
 * USB_HOST_PINTFLAG_TRFAIL  Error Flow Interrupt Flag 
 * USB_HOST_PINTFLAG_PERR  Pipe Error Interrupt Flag 
 * USB_HOST_PINTFLAG_TXSTP  Transmit  Setup Interrupt Flag 
 * USB_HOST_PINTFLAG_STALL  Stall Interrupt Flag 
 */
static inline void usbpipe_clear_PINTFLAG(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PINTFLAG.reg = mask;
}

/**
 * @brief usbpipe set PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline void usbpipe_set_PCFG(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PCFG.reg |= mask;
}

/**
 * @brief usbpipe get PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline uint8_t usbpipe_get_PCFG(uint8_t submodule_index, uint8_t mask)
{
    return ((USBHOST_t *)USB)->HostPipe[submodule_index].PCFG.reg & mask;
}

/**
 * @brief usbpipe write PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline void usbpipe_write_PCFG(uint8_t submodule_index, uint8_t data)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PCFG.reg = data;
}

/**
 * @brief usbpipe clear PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline void usbpipe_clear_PCFG(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].PCFG.reg &= ~mask;
}

/**
 * @brief usbpipe read PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline uint8_t usbpipe_read_PCFG(uint8_t submodule_index)
{
	return ((USBHOST_t *)USB)->HostPipe[submodule_index].PCFG.reg;
}

/**
 * @brief usbpipe set BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline void usbpipe_set_BINTERVAL(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].BINTERVAL.reg |= mask;
}

/**
 * @brief usbpipe get BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline uint8_t usbpipe_get_BINTERVAL(uint8_t submodule_index, uint8_t mask)
{
    return ((USBHOST_t *)USB)->HostPipe[submodule_index].BINTERVAL.reg & mask;
}

/**
 * @brief usbpipe write BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline void usbpipe_write_BINTERVAL(uint8_t submodule_index, uint8_t data)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].BINTERVAL.reg = data;
}

/**
 * @brief usbpipe clear BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline void usbpipe_clear_BINTERVAL(uint8_t submodule_index, uint8_t mask)
{
	((USBHOST_t *)USB)->HostPipe[submodule_index].BINTERVAL.reg &= ~mask;
}

/**
 * @brief usbpipe read BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline uint8_t usbpipe_read_BINTERVAL(uint8_t submodule_index)
{
	return ((USBHOST_t *)USB)->HostPipe[submodule_index].BINTERVAL.reg;
}

/**
 * @brief usbhost set PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbhost_set_PSTATUS(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].PSTATUSSET.reg = mask;
}

/**
 * @brief usbhost get PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline uint8_t usbhost_get_PSTATUS(uint8_t submodule_index, uint8_t mask)
{
    return USB->HOST.HostPipe[submodule_index].PSTATUS.reg & mask;
}

/**
 * @brief usbhost read PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline uint8_t usbhost_read_PSTATUS(uint8_t submodule_index)
{
	return USB->HOST.HostPipe[submodule_index].PSTATUS.reg;
}

/**
 * @brief usbhost write PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbhost_write_PSTATUS(uint8_t submodule_index, uint8_t data)
{
	USB->HOST.HostPipe[submodule_index].PSTATUSSET.reg = data;
	USB->HOST.HostPipe[submodule_index].PSTATUSCLR.reg = ~data;
}

/**
 * @brief usbhost clear PSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PSTATUS_DTGL  Data Toggle 
 * USB_HOST_PSTATUS_CURBK  Current Bank 
 * USB_HOST_PSTATUS_PFREEZE  Pipe Freeze 
 * USB_HOST_PSTATUS_BK0RDY  Bank 0 ready 
 * USB_HOST_PSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbhost_clear_PSTATUS(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].PSTATUSCLR.reg = mask;
}

/**
 * @brief usbhost set PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline void usbhost_set_PINTEN(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].PINTENSET.reg = mask;
}

/**
 * @brief usbhost get PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline uint8_t usbhost_get_PINTEN(uint8_t submodule_index, uint8_t mask)
{
    return USB->HOST.HostPipe[submodule_index].PINTENSET.reg & mask;
}

/**
 * @brief usbhost read PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline uint8_t usbhost_read_PINTEN(uint8_t submodule_index)
{
	return USB->HOST.HostPipe[submodule_index].PINTENSET.reg;
}

/**
 * @brief usbhost write PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline void usbhost_write_PINTEN(uint8_t submodule_index, uint8_t data)
{
	USB->HOST.HostPipe[submodule_index].PINTENSET.reg = data;
	USB->HOST.HostPipe[submodule_index].PINTENCLR.reg = ~data;
}

/**
 * @brief usbhost clear PINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_HOST_PINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_HOST_PINTENSET_TRFAIL  Error Flow Interrupt Enable 
 * USB_HOST_PINTENSET_PERR  Pipe Error Interrupt Enable 
 * USB_HOST_PINTENSET_TXSTP  Transmit  Setup Interrupt Enable 
 * USB_HOST_PINTENSET_STALL  Stall Interrupt Enable 
 */
static inline void usbhost_clear_PINTEN(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].PINTENCLR.reg = mask;
}

/**
 * @brief usbhost get PINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_PINTFLAG_TRCPT0  Transfer Complete 0 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT1  Transfer Complete 1 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT(value)  Transfer Complete x Interrupt Flag 
 * USB_HOST_PINTFLAG_TRFAIL  Error Flow Interrupt Flag 
 * USB_HOST_PINTFLAG_PERR  Pipe Error Interrupt Flag 
 * USB_HOST_PINTFLAG_TXSTP  Transmit  Setup Interrupt Flag 
 * USB_HOST_PINTFLAG_STALL  Stall Interrupt Flag 
 */
static inline uint8_t usbhost_get_PINTFLAG(uint8_t submodule_index, uint8_t mask)
{
    return USB->HOST.HostPipe[submodule_index].PINTFLAG.reg & mask;
}

/**
 * @brief usbhost read PINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_PINTFLAG_TRCPT0  Transfer Complete 0 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT1  Transfer Complete 1 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT(value)  Transfer Complete x Interrupt Flag 
 * USB_HOST_PINTFLAG_TRFAIL  Error Flow Interrupt Flag 
 * USB_HOST_PINTFLAG_PERR  Pipe Error Interrupt Flag 
 * USB_HOST_PINTFLAG_TXSTP  Transmit  Setup Interrupt Flag 
 * USB_HOST_PINTFLAG_STALL  Stall Interrupt Flag 
 */
static inline uint8_t usbhost_read_PINTFLAG(uint8_t submodule_index)
{
	return USB->HOST.HostPipe[submodule_index].PINTFLAG.reg;
}

/**
 * @brief usbhost clear PINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PINTFLAG_TRCPT0  Transfer Complete 0 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT1  Transfer Complete 1 Interrupt Flag 
 * USB_HOST_PINTFLAG_TRCPT(value)  Transfer Complete x Interrupt Flag 
 * USB_HOST_PINTFLAG_TRFAIL  Error Flow Interrupt Flag 
 * USB_HOST_PINTFLAG_PERR  Pipe Error Interrupt Flag 
 * USB_HOST_PINTFLAG_TXSTP  Transmit  Setup Interrupt Flag 
 * USB_HOST_PINTFLAG_STALL  Stall Interrupt Flag 
 */
static inline void usbhost_clear_PINTFLAG(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].PINTFLAG.reg = mask;
}

/**
 * @brief usbhost set PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline void usbhost_set_PCFG(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].PCFG.reg |= mask;
}

/**
 * @brief usbhost get PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline uint8_t usbhost_get_PCFG(uint8_t submodule_index, uint8_t mask)
{
    return USB->HOST.HostPipe[submodule_index].PCFG.reg & mask;
}

/**
 * @brief usbhost write PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline void usbhost_write_PCFG(uint8_t submodule_index, uint8_t data)
{
	USB->HOST.HostPipe[submodule_index].PCFG.reg = data;
}

/**
 * @brief usbhost clear PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline void usbhost_clear_PCFG(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].PCFG.reg &= ~mask;
}

/**
 * @brief usbhost read PCFG register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_PCFG_PTOKEN(value)  Pipe Token 
 * USB_HOST_PCFG_BK  Pipe Bank 
 * USB_HOST_PCFG_PTYPE(value)  Pipe Type 
 */
static inline uint8_t usbhost_read_PCFG(uint8_t submodule_index)
{
	return USB->HOST.HostPipe[submodule_index].PCFG.reg;
}

/**
 * @brief usbhost set BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline void usbhost_set_BINTERVAL(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].BINTERVAL.reg |= mask;
}

/**
 * @brief usbhost get BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline uint8_t usbhost_get_BINTERVAL(uint8_t submodule_index, uint8_t mask)
{
    return USB->HOST.HostPipe[submodule_index].BINTERVAL.reg & mask;
}

/**
 * @brief usbhost write BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline void usbhost_write_BINTERVAL(uint8_t submodule_index, uint8_t data)
{
	USB->HOST.HostPipe[submodule_index].BINTERVAL.reg = data;
}

/**
 * @brief usbhost clear BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline void usbhost_clear_BINTERVAL(uint8_t submodule_index, uint8_t mask)
{
	USB->HOST.HostPipe[submodule_index].BINTERVAL.reg &= ~mask;
}

/**
 * @brief usbhost read BINTERVAL register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_HOST_BINTERVAL_BITINTERVAL(value)  Bit Interval 
 */
static inline uint8_t usbhost_read_BINTERVAL(uint8_t submodule_index)
{
	return USB->HOST.HostPipe[submodule_index].BINTERVAL.reg;
}

/**
 * @brief usbhost set INTEN register
 *
 * @param[in] uint16_t mask
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline void usbhost_set_INTEN(uint16_t mask)
{
	USB->HOST.INTENSET.reg = mask;
}

/**
 * @brief usbhost get INTEN register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline uint16_t usbhost_get_INTEN(uint16_t mask)
{
    return USB->HOST.INTENSET.reg & mask;
}

/**
 * @brief usbhost read INTEN register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline uint16_t usbhost_read_INTEN(void)
{
	return USB->HOST.INTENSET.reg;
}

/**
 * @brief usbhost write INTEN register
 *
 * @param[in] uint16_t data
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline void usbhost_write_INTEN(uint16_t data)
{
	USB->HOST.INTENSET.reg = data;
	USB->HOST.INTENCLR.reg = ~data;
}

/**
 * @brief usbhost clear INTEN register
 *
 * @param[in] uint16_t mask
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline void usbhost_clear_INTEN(uint16_t mask)
{
	USB->HOST.INTENCLR.reg = mask;
}

/**
 * @brief usbhost get INTFLAG register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_INTFLAG_HSOF  Host Start Of Frame 
 * USB_HOST_INTFLAG_RST  Bus Reset 
 * USB_HOST_INTFLAG_WAKEUP  Wake Up 
 * USB_HOST_INTFLAG_DNRSM  Downstream 
 * USB_HOST_INTFLAG_UPRSM  Upstream Resume from the Device 
 * USB_HOST_INTFLAG_RAMACER  Ram Access 
 * USB_HOST_INTFLAG_DCONN  Device Connection 
 * USB_HOST_INTFLAG_DDISC  Device Disconnection 
 */
static inline uint16_t usbhost_get_INTFLAG(uint16_t mask)
{
    return USB->HOST.INTFLAG.reg & mask;
}

/**
 * @brief usbhost read INTFLAG register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_INTFLAG_HSOF  Host Start Of Frame 
 * USB_HOST_INTFLAG_RST  Bus Reset 
 * USB_HOST_INTFLAG_WAKEUP  Wake Up 
 * USB_HOST_INTFLAG_DNRSM  Downstream 
 * USB_HOST_INTFLAG_UPRSM  Upstream Resume from the Device 
 * USB_HOST_INTFLAG_RAMACER  Ram Access 
 * USB_HOST_INTFLAG_DCONN  Device Connection 
 * USB_HOST_INTFLAG_DDISC  Device Disconnection 
 */
static inline uint16_t usbhost_read_INTFLAG(void)
{
	return USB->HOST.INTFLAG.reg;
}

/**
 * @brief usbhost clear INTFLAG register
 *
 * @param[in] uint16_t mask
 * USB_HOST_INTFLAG_HSOF  Host Start Of Frame 
 * USB_HOST_INTFLAG_RST  Bus Reset 
 * USB_HOST_INTFLAG_WAKEUP  Wake Up 
 * USB_HOST_INTFLAG_DNRSM  Downstream 
 * USB_HOST_INTFLAG_UPRSM  Upstream Resume from the Device 
 * USB_HOST_INTFLAG_RAMACER  Ram Access 
 * USB_HOST_INTFLAG_DCONN  Device Connection 
 * USB_HOST_INTFLAG_DDISC  Device Disconnection 
 */
static inline void usbhost_clear_INTFLAG(uint16_t mask)
{
	USB->HOST.INTFLAG.reg = mask;
}

/**
 * @brief usbhost set CTRLA register
 *
 * @param[in] uint8_t mask
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline void usbhost_set_CTRLA(uint8_t mask)
{
	USB->HOST.CTRLA.reg |= mask;
}

/**
 * @brief usbhost get CTRLA register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline uint8_t usbhost_get_CTRLA(uint8_t mask)
{
    return USB->HOST.CTRLA.reg & mask;
}

/**
 * @brief usbhost write CTRLA register
 *
 * @param[in] uint8_t data
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline void usbhost_write_CTRLA(uint8_t data)
{
	USB->HOST.CTRLA.reg = data;
}

/**
 * @brief usbhost clear CTRLA register
 *
 * @param[in] uint8_t mask
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline void usbhost_clear_CTRLA(uint8_t mask)
{
	USB->HOST.CTRLA.reg &= ~mask;
}

/**
 * @brief usbhost read CTRLA register
 *
 * @param[in] void
 * @return uint8_t
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline uint8_t usbhost_read_CTRLA(void)
{
	return USB->HOST.CTRLA.reg;
}

/**
 * @brief usbhost set QOSCTRL register
 *
 * @param[in] uint8_t mask
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline void usbhost_set_QOSCTRL(uint8_t mask)
{
	USB->HOST.QOSCTRL.reg |= mask;
}

/**
 * @brief usbhost get QOSCTRL register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline uint8_t usbhost_get_QOSCTRL(uint8_t mask)
{
    return USB->HOST.QOSCTRL.reg & mask;
}

/**
 * @brief usbhost write QOSCTRL register
 *
 * @param[in] uint8_t data
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline void usbhost_write_QOSCTRL(uint8_t data)
{
	USB->HOST.QOSCTRL.reg = data;
}

/**
 * @brief usbhost clear QOSCTRL register
 *
 * @param[in] uint8_t mask
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline void usbhost_clear_QOSCTRL(uint8_t mask)
{
	USB->HOST.QOSCTRL.reg &= ~mask;
}

/**
 * @brief usbhost read QOSCTRL register
 *
 * @param[in] void
 * @return uint8_t
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline uint8_t usbhost_read_QOSCTRL(void)
{
	return USB->HOST.QOSCTRL.reg;
}

/**
 * @brief usbhost set CTRLB register
 *
 * @param[in] uint16_t mask
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline void usbhost_set_CTRLB(uint16_t mask)
{
	USB->HOST.CTRLB.reg |= mask;
}

/**
 * @brief usbhost get CTRLB register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline uint16_t usbhost_get_CTRLB(uint16_t mask)
{
    return USB->HOST.CTRLB.reg & mask;
}

/**
 * @brief usbhost write CTRLB register
 *
 * @param[in] uint16_t data
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline void usbhost_write_CTRLB(uint16_t data)
{
	USB->HOST.CTRLB.reg = data;
}

/**
 * @brief usbhost clear CTRLB register
 *
 * @param[in] uint16_t mask
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline void usbhost_clear_CTRLB(uint16_t mask)
{
	USB->HOST.CTRLB.reg &= ~mask;
}

/**
 * @brief usbhost read CTRLB register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline uint16_t usbhost_read_CTRLB(void)
{
	return USB->HOST.CTRLB.reg;
}

/**
 * @brief usbhost set HSOFC register
 *
 * @param[in] uint8_t mask
 * USB_HOST_HSOFC_FLENC(value)  Frame Length Control 
 * USB_HOST_HSOFC_FLENCE  Frame Length Control Enable 
 */
static inline void usbhost_set_HSOFC(uint8_t mask)
{
	USB->HOST.HSOFC.reg |= mask;
}

/**
 * @brief usbhost get HSOFC register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_HSOFC_FLENC(value)  Frame Length Control 
 * USB_HOST_HSOFC_FLENCE  Frame Length Control Enable 
 */
static inline uint8_t usbhost_get_HSOFC(uint8_t mask)
{
    return USB->HOST.HSOFC.reg & mask;
}

/**
 * @brief usbhost write HSOFC register
 *
 * @param[in] uint8_t data
 * USB_HOST_HSOFC_FLENC(value)  Frame Length Control 
 * USB_HOST_HSOFC_FLENCE  Frame Length Control Enable 
 */
static inline void usbhost_write_HSOFC(uint8_t data)
{
	USB->HOST.HSOFC.reg = data;
}

/**
 * @brief usbhost clear HSOFC register
 *
 * @param[in] uint8_t mask
 * USB_HOST_HSOFC_FLENC(value)  Frame Length Control 
 * USB_HOST_HSOFC_FLENCE  Frame Length Control Enable 
 */
static inline void usbhost_clear_HSOFC(uint8_t mask)
{
	USB->HOST.HSOFC.reg &= ~mask;
}

/**
 * @brief usbhost read HSOFC register
 *
 * @param[in] void
 * @return uint8_t
 * USB_HOST_HSOFC_FLENC(value)  Frame Length Control 
 * USB_HOST_HSOFC_FLENCE  Frame Length Control Enable 
 */
static inline uint8_t usbhost_read_HSOFC(void)
{
	return USB->HOST.HSOFC.reg;
}

/**
 * @brief usbhost set FNUM register
 *
 * @param[in] uint16_t mask
 * USB_HOST_FNUM_MFNUM(value)  Micro Frame Number 
 * USB_HOST_FNUM_FNUM(value)  Frame Number 
 */
static inline void usbhost_set_FNUM(uint16_t mask)
{
	USB->HOST.FNUM.reg |= mask;
}

/**
 * @brief usbhost get FNUM register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_FNUM_MFNUM(value)  Micro Frame Number 
 * USB_HOST_FNUM_FNUM(value)  Frame Number 
 */
static inline uint16_t usbhost_get_FNUM(uint16_t mask)
{
    return USB->HOST.FNUM.reg & mask;
}

/**
 * @brief usbhost write FNUM register
 *
 * @param[in] uint16_t data
 * USB_HOST_FNUM_MFNUM(value)  Micro Frame Number 
 * USB_HOST_FNUM_FNUM(value)  Frame Number 
 */
static inline void usbhost_write_FNUM(uint16_t data)
{
	USB->HOST.FNUM.reg = data;
}

/**
 * @brief usbhost clear FNUM register
 *
 * @param[in] uint16_t mask
 * USB_HOST_FNUM_MFNUM(value)  Micro Frame Number 
 * USB_HOST_FNUM_FNUM(value)  Frame Number 
 */
static inline void usbhost_clear_FNUM(uint16_t mask)
{
	USB->HOST.FNUM.reg &= ~mask;
}

/**
 * @brief usbhost read FNUM register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_FNUM_MFNUM(value)  Micro Frame Number 
 * USB_HOST_FNUM_FNUM(value)  Frame Number 
 */
static inline uint16_t usbhost_read_FNUM(void)
{
	return USB->HOST.FNUM.reg;
}

/**
 * @brief usbhost set DESCADD register
 *
 * @param[in] uint32_t mask
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline void usbhost_set_DESCADD(uint32_t mask)
{
	USB->HOST.DESCADD.reg |= mask;
}

/**
 * @brief usbhost get DESCADD register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline uint32_t usbhost_get_DESCADD(uint32_t mask)
{
    return USB->HOST.DESCADD.reg & mask;
}

/**
 * @brief usbhost write DESCADD register
 *
 * @param[in] uint32_t data
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline void usbhost_write_DESCADD(uint32_t data)
{
	USB->HOST.DESCADD.reg = data;
}

/**
 * @brief usbhost clear DESCADD register
 *
 * @param[in] uint32_t mask
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline void usbhost_clear_DESCADD(uint32_t mask)
{
	USB->HOST.DESCADD.reg &= ~mask;
}

/**
 * @brief usbhost read DESCADD register
 *
 * @param[in] void
 * @return uint32_t
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline uint32_t usbhost_read_DESCADD(void)
{
	return USB->HOST.DESCADD.reg;
}

/**
 * @brief usbhost set PADCAL register
 *
 * @param[in] uint16_t mask
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline void usbhost_set_PADCAL(uint16_t mask)
{
	USB->HOST.PADCAL.reg |= mask;
}

/**
 * @brief usbhost get PADCAL register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline uint16_t usbhost_get_PADCAL(uint16_t mask)
{
    return USB->HOST.PADCAL.reg & mask;
}

/**
 * @brief usbhost write PADCAL register
 *
 * @param[in] uint16_t data
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline void usbhost_write_PADCAL(uint16_t data)
{
	USB->HOST.PADCAL.reg = data;
}

/**
 * @brief usbhost clear PADCAL register
 *
 * @param[in] uint16_t mask
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline void usbhost_clear_PADCAL(uint16_t mask)
{
	USB->HOST.PADCAL.reg &= ~mask;
}

/**
 * @brief usbhost read PADCAL register
 *
 * @param[in] void
 * @return uint16_t
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline uint16_t usbhost_read_PADCAL(void)
{
	return USB->HOST.PADCAL.reg;
}

/**
 * @brief usbhost get SYNCBUSY register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_SYNCBUSY_SWRST  Software Reset Synchronization Busy 
 * USB_SYNCBUSY_ENABLE  Enable Synchronization Busy 
 */
static inline uint8_t usbhost_get_SYNCBUSY(uint8_t mask)
{
    return USB->HOST.SYNCBUSY.reg & mask;
}

/**
 * @brief usbhost read SYNCBUSY register
 *
 * @param[in] void
 * @return uint8_t
 * USB_SYNCBUSY_SWRST  Software Reset Synchronization Busy 
 * USB_SYNCBUSY_ENABLE  Enable Synchronization Busy 
 */
static inline uint8_t usbhost_read_SYNCBUSY(void)
{
	return USB->HOST.SYNCBUSY.reg;
}

/**
 * @brief usbhost get FSMSTATUS register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_FSMSTATUS_FSMSTATE(value)  Fine State Machine Status 
 *    USB_FSMSTATUS_FSMSTATE_OFF  OFF. It corresponds to the powered-off, disconnected, and disabled state 
 *    USB_FSMSTATUS_FSMSTATE_ON  ON. It corresponds to the Idle and Active states 
 *    USB_FSMSTATUS_FSMSTATE_SUSPEND  SUSPEND 
 *    USB_FSMSTATUS_FSMSTATE_SLEEP  SLEEP 
 *    USB_FSMSTATUS_FSMSTATE_DNRESUME  DNRESUME. Down Stream Resume. 
 *    USB_FSMSTATUS_FSMSTATE_UPRESUME  UPRESUME. Up Stream Resume. 
 *    USB_FSMSTATUS_FSMSTATE_RESET  RESET. USB lines Reset. 
 */
static inline uint8_t usbhost_get_FSMSTATUS(uint8_t mask)
{
    return USB->HOST.FSMSTATUS.reg & mask;
}

/**
 * @brief usbhost read FSMSTATUS register
 *
 * @param[in] void
 * @return uint8_t
 * USB_FSMSTATUS_FSMSTATE(value)  Fine State Machine Status 
 *    USB_FSMSTATUS_FSMSTATE_OFF  OFF. It corresponds to the powered-off, disconnected, and disabled state 
 *    USB_FSMSTATUS_FSMSTATE_ON  ON. It corresponds to the Idle and Active states 
 *    USB_FSMSTATUS_FSMSTATE_SUSPEND  SUSPEND 
 *    USB_FSMSTATUS_FSMSTATE_SLEEP  SLEEP 
 *    USB_FSMSTATUS_FSMSTATE_DNRESUME  DNRESUME. Down Stream Resume. 
 *    USB_FSMSTATUS_FSMSTATE_UPRESUME  UPRESUME. Up Stream Resume. 
 *    USB_FSMSTATUS_FSMSTATE_RESET  RESET. USB lines Reset. 
 */
static inline uint8_t usbhost_read_FSMSTATUS(void)
{
	return USB->HOST.FSMSTATUS.reg;
}

/**
 * @brief usbhost get FLENHIGH register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_FLENHIGH_FLENHIGH(value)  Frame Length 
 */
static inline uint8_t usbhost_get_FLENHIGH(uint8_t mask)
{
    return USB->HOST.FLENHIGH.reg & mask;
}

/**
 * @brief usbhost read FLENHIGH register
 *
 * @param[in] void
 * @return uint8_t
 * USB_HOST_FLENHIGH_FLENHIGH(value)  Frame Length 
 */
static inline uint8_t usbhost_read_FLENHIGH(void)
{
	return USB->HOST.FLENHIGH.reg;
}

/**
 * @brief usbhost get PINTSMRY register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_PINTSMRY_EPINT0  Pipe 0 Interrupt 
 * USB_HOST_PINTSMRY_EPINT1  Pipe 1 Interrupt 
 * USB_HOST_PINTSMRY_EPINT2  Pipe 2 Interrupt 
 * USB_HOST_PINTSMRY_EPINT3  Pipe 3 Interrupt 
 * USB_HOST_PINTSMRY_EPINT4  Pipe 4 Interrupt 
 * USB_HOST_PINTSMRY_EPINT5  Pipe 5 Interrupt 
 * USB_HOST_PINTSMRY_EPINT6  Pipe 6 Interrupt 
 * USB_HOST_PINTSMRY_EPINT7  Pipe 7 Interrupt 
 * USB_HOST_PINTSMRY_EPINT(value)  Pipe x Interrupt 
 */
static inline uint16_t usbhost_get_PINTSMRY(uint16_t mask)
{
    return USB->HOST.PINTSMRY.reg & mask;
}

/**
 * @brief usbhost read PINTSMRY register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_PINTSMRY_EPINT0  Pipe 0 Interrupt 
 * USB_HOST_PINTSMRY_EPINT1  Pipe 1 Interrupt 
 * USB_HOST_PINTSMRY_EPINT2  Pipe 2 Interrupt 
 * USB_HOST_PINTSMRY_EPINT3  Pipe 3 Interrupt 
 * USB_HOST_PINTSMRY_EPINT4  Pipe 4 Interrupt 
 * USB_HOST_PINTSMRY_EPINT5  Pipe 5 Interrupt 
 * USB_HOST_PINTSMRY_EPINT6  Pipe 6 Interrupt 
 * USB_HOST_PINTSMRY_EPINT7  Pipe 7 Interrupt 
 * USB_HOST_PINTSMRY_EPINT(value)  Pipe x Interrupt 
 */
static inline uint16_t usbhost_read_PINTSMRY(void)
{
	return USB->HOST.PINTSMRY.reg;
}

/**
 * @brief usbhost get STATUS register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_STATUS_SPEED(value)  Speed Status 
 * USB_HOST_STATUS_LINESTATE(value)  USB Line State Status 
 */
static inline uint8_t usbhost_get_STATUS(uint8_t mask)
{
    return USB->HOST.STATUS.reg & mask;
}

/**
 * @brief usbhost clear STATUS register
 *
 * @param[in] uint8_t mask
 * USB_HOST_STATUS_SPEED(value)  Speed Status 
 * USB_HOST_STATUS_LINESTATE(value)  USB Line State Status 
 */
static inline void usbhost_clear_STATUS(uint8_t mask)
{
	USB->HOST.STATUS.reg = mask;
}

/**
 * @brief usbhost read STATUS register
 *
 * @param[in] void
 * @return uint8_t
 * USB_HOST_STATUS_SPEED(value)  Speed Status 
 * USB_HOST_STATUS_LINESTATE(value)  USB Line State Status 
 */
static inline uint8_t usbhost_read_STATUS(void)
{
	return USB->HOST.STATUS.reg;
}

/**
 * @brief usbdevicedescbank set ADDR register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint32_t mask
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbdevicedescbank_set_ADDR(UsbDeviceDescBank_t *pUSBdevdesc, uint32_t mask)
{
	pUSBdevdesc->ADDR.reg |= mask;
}

/**
 * @brief usbdevicedescbank get ADDR register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline uint32_t usbdevicedescbank_get_ADDR(UsbDeviceDescBank_t *pUSBdevdesc, uint32_t mask)
{
    return pUSBdevdesc->ADDR.reg & mask;
}

/**
 * @brief usbdevicedescbank write ADDR register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint32_t data
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbdevicedescbank_write_ADDR(UsbDeviceDescBank_t *pUSBdevdesc, uint32_t data)
{
	pUSBdevdesc->ADDR.reg = data;
}

/**
 * @brief usbdevicedescbank clear ADDR register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint32_t mask
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbdevicedescbank_clear_ADDR(UsbDeviceDescBank_t *pUSBdevdesc, uint32_t mask)
{
	pUSBdevdesc->ADDR.reg &= ~mask;
}

/**
 * @brief usbdevicedescbank read ADDR register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @return uint32_t
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline uint32_t usbdevicedescbank_read_ADDR(UsbDeviceDescBank_t *pUSBdevdesc)
{
	return pUSBdevdesc->ADDR.reg;
}

/**
 * @brief usbdevicedescbank set PCKSIZE register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint32_t mask
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbdevicedescbank_set_PCKSIZE(UsbDeviceDescBank_t *pUSBdevdesc, uint32_t mask)
{
	pUSBdevdesc->PCKSIZE.reg |= mask;
}

/**
 * @brief usbdevicedescbank get PCKSIZE register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline uint32_t usbdevicedescbank_get_PCKSIZE(UsbDeviceDescBank_t *pUSBdevdesc, uint32_t mask)
{
    return pUSBdevdesc->PCKSIZE.reg & mask;
}

/**
 * @brief usbdevicedescbank write PCKSIZE register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint32_t data
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbdevicedescbank_write_PCKSIZE(UsbDeviceDescBank_t *pUSBdevdesc, uint32_t data)
{
	pUSBdevdesc->PCKSIZE.reg = data;
}

/**
 * @brief usbdevicedescbank clear PCKSIZE register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint32_t mask
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbdevicedescbank_clear_PCKSIZE(UsbDeviceDescBank_t *pUSBdevdesc, uint32_t mask)
{
	pUSBdevdesc->PCKSIZE.reg &= ~mask;
}

/**
 * @brief usbdevicedescbank read PCKSIZE register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @return uint32_t
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline uint32_t usbdevicedescbank_read_PCKSIZE(UsbDeviceDescBank_t *pUSBdevdesc)
{
	return pUSBdevdesc->PCKSIZE.reg;
}

/**
 * @brief usbdevicedescbank set EXTREG register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint16_t mask
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbdevicedescbank_set_EXTREG(UsbDeviceDescBank_t *pUSBdevdesc, uint16_t mask)
{
	pUSBdevdesc->EXTREG.reg |= mask;
}

/**
 * @brief usbdevicedescbank get EXTREG register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline uint16_t usbdevicedescbank_get_EXTREG(UsbDeviceDescBank_t *pUSBdevdesc, uint16_t mask)
{
    return pUSBdevdesc->EXTREG.reg & mask;
}

/**
 * @brief usbdevicedescbank write EXTREG register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint16_t data
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbdevicedescbank_write_EXTREG(UsbDeviceDescBank_t *pUSBdevdesc, uint16_t data)
{
	pUSBdevdesc->EXTREG.reg = data;
}

/**
 * @brief usbdevicedescbank clear EXTREG register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @param[in] uint16_t mask
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbdevicedescbank_clear_EXTREG(UsbDeviceDescBank_t *pUSBdevdesc, uint16_t mask)
{
	pUSBdevdesc->EXTREG.reg &= ~mask;
}

/**
 * @brief usbdevicedescbank read EXTREG register
 *
 * @param[in] UsbDeviceDescBank_t *pUSBdevdesc
 * @return uint16_t
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline uint16_t usbdevicedescbank_read_EXTREG(UsbDeviceDescBank_t *pUSBdevdesc)
{
	return pUSBdevdesc->EXTREG.reg;
}

/**
 * @brief usbdevicedescriptor set ADDR register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbdevicedescriptor_set_ADDR(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint32_t mask)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].ADDR.reg |= mask;
}

/**
 * @brief usbdevicedescriptor get ADDR register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline uint32_t usbdevicedescriptor_get_ADDR(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint32_t mask)
{
    return pUSBdevdesc->DeviceDescBank[submodule_index].ADDR.reg & mask;
}

/**
 * @brief usbdevicedescriptor write ADDR register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t data
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbdevicedescriptor_write_ADDR(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint32_t data)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].ADDR.reg = data;
}

/**
 * @brief usbdevicedescriptor clear ADDR register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbdevicedescriptor_clear_ADDR(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint32_t mask)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].ADDR.reg &= ~mask;
}

/**
 * @brief usbdevicedescriptor read ADDR register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @return uint32_t
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline uint32_t usbdevicedescriptor_read_ADDR(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index)
{
	return pUSBdevdesc->DeviceDescBank[submodule_index].ADDR.reg;
}

/**
 * @brief usbdevicedescriptor set PCKSIZE register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbdevicedescriptor_set_PCKSIZE(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint32_t mask)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].PCKSIZE.reg |= mask;
}

/**
 * @brief usbdevicedescriptor get PCKSIZE register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline uint32_t usbdevicedescriptor_get_PCKSIZE(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint32_t mask)
{
    return pUSBdevdesc->DeviceDescBank[submodule_index].PCKSIZE.reg & mask;
}

/**
 * @brief usbdevicedescriptor write PCKSIZE register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t data
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbdevicedescriptor_write_PCKSIZE(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint32_t data)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].PCKSIZE.reg = data;
}

/**
 * @brief usbdevicedescriptor clear PCKSIZE register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbdevicedescriptor_clear_PCKSIZE(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint32_t mask)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].PCKSIZE.reg &= ~mask;
}

/**
 * @brief usbdevicedescriptor read PCKSIZE register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @return uint32_t
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline uint32_t usbdevicedescriptor_read_PCKSIZE(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index)
{
	return pUSBdevdesc->DeviceDescBank[submodule_index].PCKSIZE.reg;
}

/**
 * @brief usbdevicedescriptor set EXTREG register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint16_t mask
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbdevicedescriptor_set_EXTREG(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint16_t mask)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].EXTREG.reg |= mask;
}

/**
 * @brief usbdevicedescriptor get EXTREG register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline uint16_t usbdevicedescriptor_get_EXTREG(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint16_t mask)
{
    return pUSBdevdesc->DeviceDescBank[submodule_index].EXTREG.reg & mask;
}

/**
 * @brief usbdevicedescriptor write EXTREG register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint16_t data
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbdevicedescriptor_write_EXTREG(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint16_t data)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].EXTREG.reg = data;
}

/**
 * @brief usbdevicedescriptor clear EXTREG register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint16_t mask
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbdevicedescriptor_clear_EXTREG(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index, uint16_t mask)
{
	pUSBdevdesc->DeviceDescBank[submodule_index].EXTREG.reg &= ~mask;
}

/**
 * @brief usbdevicedescriptor read EXTREG register
 *
 * @param[in] UsbDeviceDescriptor_t *pUSBdevdesc
 * @param[in] uint8_t submodule_index
 * @return uint16_t
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline uint16_t usbdevicedescriptor_read_EXTREG(UsbDeviceDescriptor_t *pUSBdevdesc, uint8_t submodule_index)
{
	return pUSBdevdesc->DeviceDescBank[submodule_index].EXTREG.reg;
}

/**
 * @brief usbdevice set INTEN register
 *
 * @param[in] uint16_t mask
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline void usbdevice_set_INTEN(uint16_t mask)
{
	USB->DEVICE.INTENSET.reg = mask;
}

/**
 * @brief usbdevice get INTEN register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline uint16_t usbdevice_get_INTEN(uint16_t mask)
{
    return USB->DEVICE.INTENSET.reg & mask;
}

/**
 * @brief usbdevice read INTEN register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline uint16_t usbdevice_read_INTEN(void)
{
	return USB->DEVICE.INTENSET.reg;
}

/**
 * @brief usbdevice write INTEN register
 *
 * @param[in] uint16_t data
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline void usbdevice_write_INTEN(uint16_t data)
{
	USB->DEVICE.INTENSET.reg = data;
	USB->DEVICE.INTENCLR.reg = ~data;
}

/**
 * @brief usbdevice clear INTEN register
 *
 * @param[in] uint16_t mask
 * USB_HOST_INTENSET_HSOF  Host Start Of Frame Interrupt Enable 
 * USB_HOST_INTENSET_RST  Bus Reset Interrupt Enable 
 * USB_HOST_INTENSET_WAKEUP  Wake Up Interrupt Enable 
 * USB_HOST_INTENSET_DNRSM  DownStream to the Device Interrupt Enable 
 * USB_HOST_INTENSET_UPRSM  Upstream Resume fromthe device Interrupt Enable 
 * USB_HOST_INTENSET_RAMACER  Ram Access Interrupt Enable 
 * USB_HOST_INTENSET_DCONN  Link Power Management Interrupt Enable 
 * USB_HOST_INTENSET_DDISC  Device Disconnection Interrupt Enable 
 */
static inline void usbdevice_clear_INTEN(uint16_t mask)
{
	USB->DEVICE.INTENCLR.reg = mask;
}

/**
 * @brief usbdevice get INTFLAG register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_INTFLAG_HSOF  Host Start Of Frame 
 * USB_HOST_INTFLAG_RST  Bus Reset 
 * USB_HOST_INTFLAG_WAKEUP  Wake Up 
 * USB_HOST_INTFLAG_DNRSM  Downstream 
 * USB_HOST_INTFLAG_UPRSM  Upstream Resume from the Device 
 * USB_HOST_INTFLAG_RAMACER  Ram Access 
 * USB_HOST_INTFLAG_DCONN  Device Connection 
 * USB_HOST_INTFLAG_DDISC  Device Disconnection 
 */
static inline uint16_t usbdevice_get_INTFLAG(uint16_t mask)
{
    return USB->DEVICE.INTFLAG.reg & mask;
}

/**
 * @brief usbdevice read INTFLAG register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_INTFLAG_HSOF  Host Start Of Frame 
 * USB_HOST_INTFLAG_RST  Bus Reset 
 * USB_HOST_INTFLAG_WAKEUP  Wake Up 
 * USB_HOST_INTFLAG_DNRSM  Downstream 
 * USB_HOST_INTFLAG_UPRSM  Upstream Resume from the Device 
 * USB_HOST_INTFLAG_RAMACER  Ram Access 
 * USB_HOST_INTFLAG_DCONN  Device Connection 
 * USB_HOST_INTFLAG_DDISC  Device Disconnection 
 */
static inline uint16_t usbdevice_read_INTFLAG(void)
{
	return USB->DEVICE.INTFLAG.reg;
}

/**
 * @brief usbdevice clear INTFLAG register
 *
 * @param[in] uint16_t mask
 * USB_HOST_INTFLAG_HSOF  Host Start Of Frame 
 * USB_HOST_INTFLAG_RST  Bus Reset 
 * USB_HOST_INTFLAG_WAKEUP  Wake Up 
 * USB_HOST_INTFLAG_DNRSM  Downstream 
 * USB_HOST_INTFLAG_UPRSM  Upstream Resume from the Device 
 * USB_HOST_INTFLAG_RAMACER  Ram Access 
 * USB_HOST_INTFLAG_DCONN  Device Connection 
 * USB_HOST_INTFLAG_DDISC  Device Disconnection 
 */
static inline void usbdevice_clear_INTFLAG(uint16_t mask)
{
	USB->DEVICE.INTFLAG.reg = mask;
}

/**
 * @brief usbdevice set CTRLA register
 *
 * @param[in] uint8_t mask
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline void usbdevice_set_CTRLA(uint8_t mask)
{
	USB->DEVICE.CTRLA.reg |= mask;
}

/**
 * @brief usbdevice get CTRLA register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline uint8_t usbdevice_get_CTRLA(uint8_t mask)
{
    return USB->DEVICE.CTRLA.reg & mask;
}

/**
 * @brief usbdevice write CTRLA register
 *
 * @param[in] uint8_t data
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline void usbdevice_write_CTRLA(uint8_t data)
{
	USB->DEVICE.CTRLA.reg = data;
}

/**
 * @brief usbdevice clear CTRLA register
 *
 * @param[in] uint8_t mask
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline void usbdevice_clear_CTRLA(uint8_t mask)
{
	USB->DEVICE.CTRLA.reg &= ~mask;
}

/**
 * @brief usbdevice read CTRLA register
 *
 * @param[in] void
 * @return uint8_t
 * USB_CTRLA_SWRST  Software Reset 
 * USB_CTRLA_ENABLE  Enable 
 * USB_CTRLA_RUNSTDBY  Run in Standby Mode 
 * USB_CTRLA_MODE  Operating Mode 
 *    USB_CTRLA_MODE_DEVICE  Device Mode 
 *    USB_CTRLA_MODE_HOST  Host Mode 
 */
static inline uint8_t usbdevice_read_CTRLA(void)
{
	return USB->DEVICE.CTRLA.reg;
}

/**
 * @brief usbdevice set QOSCTRL register
 *
 * @param[in] uint8_t mask
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline void usbdevice_set_QOSCTRL(uint8_t mask)
{
	USB->DEVICE.QOSCTRL.reg |= mask;
}

/**
 * @brief usbdevice get QOSCTRL register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline uint8_t usbdevice_get_QOSCTRL(uint8_t mask)
{
    return USB->DEVICE.QOSCTRL.reg & mask;
}

/**
 * @brief usbdevice write QOSCTRL register
 *
 * @param[in] uint8_t data
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline void usbdevice_write_QOSCTRL(uint8_t data)
{
	USB->DEVICE.QOSCTRL.reg = data;
}

/**
 * @brief usbdevice clear QOSCTRL register
 *
 * @param[in] uint8_t mask
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline void usbdevice_clear_QOSCTRL(uint8_t mask)
{
	USB->DEVICE.QOSCTRL.reg &= ~mask;
}

/**
 * @brief usbdevice read QOSCTRL register
 *
 * @param[in] void
 * @return uint8_t
 * USB_QOSCTRL_CQOS(value)  Configuration Quality of Service 
 * USB_QOSCTRL_DQOS(value)  Data Quality of Service 
 */
static inline uint8_t usbdevice_read_QOSCTRL(void)
{
	return USB->DEVICE.QOSCTRL.reg;
}

/**
 * @brief usbdevice set CTRLB register
 *
 * @param[in] uint16_t mask
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline void usbdevice_set_CTRLB(uint16_t mask)
{
	USB->DEVICE.CTRLB.reg |= mask;
}

/**
 * @brief usbdevice get CTRLB register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline uint16_t usbdevice_get_CTRLB(uint16_t mask)
{
    return USB->DEVICE.CTRLB.reg & mask;
}

/**
 * @brief usbdevice write CTRLB register
 *
 * @param[in] uint16_t data
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline void usbdevice_write_CTRLB(uint16_t data)
{
	USB->DEVICE.CTRLB.reg = data;
}

/**
 * @brief usbdevice clear CTRLB register
 *
 * @param[in] uint16_t mask
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline void usbdevice_clear_CTRLB(uint16_t mask)
{
	USB->DEVICE.CTRLB.reg &= ~mask;
}

/**
 * @brief usbdevice read CTRLB register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_CTRLB_RESUME  Send USB Resume 
 * USB_HOST_CTRLB_SPDCONF(value)  Speed Configuration for Host 
 *    USB_HOST_CTRLB_SPDCONF_NORMAL  Normal mode: the host starts in full-speed mode and performs a high-speed reset to switch to the high speed mode if the downstream peripheral is high-speed capable. 
 *    USB_HOST_CTRLB_SPDCONF_FS  Full-speed: the host remains in full-speed mode whatever is the peripheral speed capability. Relevant in UTMI mode only. 
 * USB_HOST_CTRLB_AUTORESUME  Auto Resume Enable 
 * USB_HOST_CTRLB_TSTJ  Test mode J 
 * USB_HOST_CTRLB_TSTK  Test mode K 
 * USB_HOST_CTRLB_SOFE  Start of Frame Generation Enable 
 * USB_HOST_CTRLB_BUSRESET  Send USB Reset 
 * USB_HOST_CTRLB_VBUSOK  VBUS is OK 
 * USB_HOST_CTRLB_L1RESUME  Send L1 Resume 
 */
static inline uint16_t usbdevice_read_CTRLB(void)
{
	return USB->DEVICE.CTRLB.reg;
}

/**
 * @brief usbdevice set DADD register
 *
 * @param[in] uint8_t mask
 * USB_DEVICE_DADD_DADD(value)  Device Address 
 * USB_DEVICE_DADD_ADDEN  Device Address Enable 
 */
static inline void usbdevice_set_DADD(uint8_t mask)
{
	USB->DEVICE.DADD.reg |= mask;
}

/**
 * @brief usbdevice get DADD register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_DADD_DADD(value)  Device Address 
 * USB_DEVICE_DADD_ADDEN  Device Address Enable 
 */
static inline uint8_t usbdevice_get_DADD(uint8_t mask)
{
    return USB->DEVICE.DADD.reg & mask;
}

/**
 * @brief usbdevice write DADD register
 *
 * @param[in] uint8_t data
 * USB_DEVICE_DADD_DADD(value)  Device Address 
 * USB_DEVICE_DADD_ADDEN  Device Address Enable 
 */
static inline void usbdevice_write_DADD(uint8_t data)
{
	USB->DEVICE.DADD.reg = data;
}

/**
 * @brief usbdevice clear DADD register
 *
 * @param[in] uint8_t mask
 * USB_DEVICE_DADD_DADD(value)  Device Address 
 * USB_DEVICE_DADD_ADDEN  Device Address Enable 
 */
static inline void usbdevice_clear_DADD(uint8_t mask)
{
	USB->DEVICE.DADD.reg &= ~mask;
}

/**
 * @brief usbdevice read DADD register
 *
 * @param[in] void
 * @return uint8_t
 * USB_DEVICE_DADD_DADD(value)  Device Address 
 * USB_DEVICE_DADD_ADDEN  Device Address Enable 
 */
static inline uint8_t usbdevice_read_DADD(void)
{
	return USB->DEVICE.DADD.reg;
}

/**
 * @brief usbdevice set DESCADD register
 *
 * @param[in] uint32_t mask
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline void usbdevice_set_DESCADD(uint32_t mask)
{
	USB->DEVICE.DESCADD.reg |= mask;
}

/**
 * @brief usbdevice get DESCADD register
 *
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline uint32_t usbdevice_get_DESCADD(uint32_t mask)
{
    return USB->DEVICE.DESCADD.reg & mask;
}

/**
 * @brief usbdevice write DESCADD register
 *
 * @param[in] uint32_t data
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline void usbdevice_write_DESCADD(uint32_t data)
{
	USB->DEVICE.DESCADD.reg = data;
}

/**
 * @brief usbdevice clear DESCADD register
 *
 * @param[in] uint32_t mask
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline void usbdevice_clear_DESCADD(uint32_t mask)
{
	USB->DEVICE.DESCADD.reg &= ~mask;
}

/**
 * @brief usbdevice read DESCADD register
 *
 * @param[in] void
 * @return uint32_t
 * USB_DESCADD_DESCADD(value)  Descriptor Address Value 
 */
static inline uint32_t usbdevice_read_DESCADD(void)
{
	return USB->DEVICE.DESCADD.reg;
}

/**
 * @brief usbdevice set PADCAL register
 *
 * @param[in] uint16_t mask
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline void usbdevice_set_PADCAL(uint16_t mask)
{
	USB->DEVICE.PADCAL.reg |= mask;
}

/**
 * @brief usbdevice get PADCAL register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline uint16_t usbdevice_get_PADCAL(uint16_t mask)
{
    return USB->DEVICE.PADCAL.reg & mask;
}

/**
 * @brief usbdevice write PADCAL register
 *
 * @param[in] uint16_t data
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline void usbdevice_write_PADCAL(uint16_t data)
{
	USB->DEVICE.PADCAL.reg = data;
}

/**
 * @brief usbdevice clear PADCAL register
 *
 * @param[in] uint16_t mask
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline void usbdevice_clear_PADCAL(uint16_t mask)
{
	USB->DEVICE.PADCAL.reg &= ~mask;
}

/**
 * @brief usbdevice read PADCAL register
 *
 * @param[in] void
 * @return uint16_t
 * USB_PADCAL_TRANSP(value)  USB Pad Transp calibration 
 * USB_PADCAL_TRANSN(value)  USB Pad Transn calibration 
 * USB_PADCAL_TRIM(value)  USB Pad Trim calibration 
 */
static inline uint16_t usbdevice_read_PADCAL(void)
{
	return USB->DEVICE.PADCAL.reg;
}

/**
 * @brief usbdevice get SYNCBUSY register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_SYNCBUSY_SWRST  Software Reset Synchronization Busy 
 * USB_SYNCBUSY_ENABLE  Enable Synchronization Busy 
 */
static inline uint8_t usbdevice_get_SYNCBUSY(uint8_t mask)
{
    return USB->DEVICE.SYNCBUSY.reg & mask;
}

/**
 * @brief usbdevice read SYNCBUSY register
 *
 * @param[in] void
 * @return uint8_t
 * USB_SYNCBUSY_SWRST  Software Reset Synchronization Busy 
 * USB_SYNCBUSY_ENABLE  Enable Synchronization Busy 
 */
static inline uint8_t usbdevice_read_SYNCBUSY(void)
{
	return USB->DEVICE.SYNCBUSY.reg;
}

/**
 * @brief usbdevice get STATUS register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_HOST_STATUS_SPEED(value)  Speed Status 
 * USB_HOST_STATUS_LINESTATE(value)  USB Line State Status 
 */
static inline uint8_t usbdevice_get_STATUS(uint8_t mask)
{
    return USB->DEVICE.STATUS.reg & mask;
}

/**
 * @brief usbdevice read STATUS register
 *
 * @param[in] void
 * @return uint8_t
 * USB_HOST_STATUS_SPEED(value)  Speed Status 
 * USB_HOST_STATUS_LINESTATE(value)  USB Line State Status 
 */
static inline uint8_t usbdevice_read_STATUS(void)
{
	return USB->DEVICE.STATUS.reg;
}

/**
 * @brief usbdevice get FSMSTATUS register
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_FSMSTATUS_FSMSTATE(value)  Fine State Machine Status 
 *    USB_FSMSTATUS_FSMSTATE_OFF  OFF. It corresponds to the powered-off, disconnected, and disabled state 
 *    USB_FSMSTATUS_FSMSTATE_ON  ON. It corresponds to the Idle and Active states 
 *    USB_FSMSTATUS_FSMSTATE_SUSPEND  SUSPEND 
 *    USB_FSMSTATUS_FSMSTATE_SLEEP  SLEEP 
 *    USB_FSMSTATUS_FSMSTATE_DNRESUME  DNRESUME. Down Stream Resume. 
 *    USB_FSMSTATUS_FSMSTATE_UPRESUME  UPRESUME. Up Stream Resume. 
 *    USB_FSMSTATUS_FSMSTATE_RESET  RESET. USB lines Reset. 
 */
static inline uint8_t usbdevice_get_FSMSTATUS(uint8_t mask)
{
    return USB->DEVICE.FSMSTATUS.reg & mask;
}

/**
 * @brief usbdevice read FSMSTATUS register
 *
 * @param[in] void
 * @return uint8_t
 * USB_FSMSTATUS_FSMSTATE(value)  Fine State Machine Status 
 *    USB_FSMSTATUS_FSMSTATE_OFF  OFF. It corresponds to the powered-off, disconnected, and disabled state 
 *    USB_FSMSTATUS_FSMSTATE_ON  ON. It corresponds to the Idle and Active states 
 *    USB_FSMSTATUS_FSMSTATE_SUSPEND  SUSPEND 
 *    USB_FSMSTATUS_FSMSTATE_SLEEP  SLEEP 
 *    USB_FSMSTATUS_FSMSTATE_DNRESUME  DNRESUME. Down Stream Resume. 
 *    USB_FSMSTATUS_FSMSTATE_UPRESUME  UPRESUME. Up Stream Resume. 
 *    USB_FSMSTATUS_FSMSTATE_RESET  RESET. USB lines Reset. 
 */
static inline uint8_t usbdevice_read_FSMSTATUS(void)
{
	return USB->DEVICE.FSMSTATUS.reg;
}

/**
 * @brief usbdevice get FNUM register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_FNUM_MFNUM(value)  Micro Frame Number 
 * USB_HOST_FNUM_FNUM(value)  Frame Number 
 */
static inline uint16_t usbdevice_get_FNUM(uint16_t mask)
{
    return USB->DEVICE.FNUM.reg & mask;
}

/**
 * @brief usbdevice read FNUM register
 *
 * @param[in] void
 * @return uint16_t
 * USB_HOST_FNUM_MFNUM(value)  Micro Frame Number 
 * USB_HOST_FNUM_FNUM(value)  Frame Number 
 */
static inline uint16_t usbdevice_read_FNUM(void)
{
	return USB->DEVICE.FNUM.reg;
}

/**
 * @brief usbdevice get EPINTSMRY register
 *
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_DEVICE_EPINTSMRY_EPINT0  End Point 0 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT1  End Point 1 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT2  End Point 2 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT3  End Point 3 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT4  End Point 4 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT5  End Point 5 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT6  End Point 6 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT7  End Point 7 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT(value)  End Point x Interrupt 
 */
static inline uint16_t usbdevice_get_EPINTSMRY(uint16_t mask)
{
    return USB->DEVICE.EPINTSMRY.reg & mask;
}

/**
 * @brief usbdevice read EPINTSMRY register
 *
 * @param[in] void
 * @return uint16_t
 * USB_DEVICE_EPINTSMRY_EPINT0  End Point 0 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT1  End Point 1 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT2  End Point 2 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT3  End Point 3 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT4  End Point 4 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT5  End Point 5 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT6  End Point 6 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT7  End Point 7 Interrupt 
 * USB_DEVICE_EPINTSMRY_EPINT(value)  End Point x Interrupt 
 */
static inline uint16_t usbdevice_read_EPINTSMRY(void)
{
	return USB->DEVICE.EPINTSMRY.reg;
}

/**
 * @brief usbendpoint set EPSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbendpoint_set_EPSTATUS(uint8_t submodule_index, uint8_t mask)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = mask;
}

/**
 * @brief usbendpoint get EPSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline uint8_t usbendpoint_get_EPSTATUS(uint8_t submodule_index, uint8_t mask)
{
    return ((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPSTATUS.reg & mask;
}

/**
 * @brief usbendpoint read EPSTATUS register
 *
 * @param[in] uint8_t           submodule_index
 * @return uint8_t
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline uint8_t usbendpoint_read_EPSTATUS(uint8_t           submodule_index)
{
	return ((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPSTATUS.reg;
}

/**
 * @brief usbendpoint write EPSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbendpoint_write_EPSTATUS(uint8_t submodule_index, uint8_t data)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = data;
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = ~data;
}

/**
 * @brief usbendpoint clear EPSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbendpoint_clear_EPSTATUS(uint8_t submodule_index, uint8_t mask)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = mask;
}

/**
 * @brief usbendpoint set EPINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline void usbendpoint_set_EPINTEN(uint8_t submodule_index, uint8_t mask)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTENSET.reg = mask;
}

/**
 * @brief usbendpoint get EPINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline uint8_t usbendpoint_get_EPINTEN(uint8_t submodule_index, uint8_t mask)
{
    return ((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTENSET.reg & mask;
}

/**
 * @brief usbendpoint read EPINTEN register
 *
 * @param[in] uint8_t           submodule_index
 * @return uint8_t
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline uint8_t usbendpoint_read_EPINTEN(uint8_t           submodule_index)
{
	return ((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTENSET.reg;
}

/**
 * @brief usbendpoint write EPINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline void usbendpoint_write_EPINTEN(uint8_t submodule_index, uint8_t data)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTENSET.reg = data;
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = ~data;
}

/**
 * @brief usbendpoint clear EPINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline void usbendpoint_clear_EPINTEN(uint8_t submodule_index, uint8_t mask)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = mask;
}

/**
 * @brief usbendpoint get EPINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_EPINTFLAG_TRCPT0  Transfer Complete 0 
 * USB_DEVICE_EPINTFLAG_TRCPT1  Transfer Complete 1 
 * USB_DEVICE_EPINTFLAG_TRCPT(value)  Transfer Complete x 
 * USB_DEVICE_EPINTFLAG_TRFAIL0  Error Flow 0 
 * USB_DEVICE_EPINTFLAG_TRFAIL1  Error Flow 1 
 * USB_DEVICE_EPINTFLAG_TRFAIL(value)  Error Flow x 
 * USB_DEVICE_EPINTFLAG_RXSTP  Received Setup 
 * USB_DEVICE_EPINTFLAG_STALL0  Stall 0 In/out 
 * USB_DEVICE_EPINTFLAG_STALL1  Stall 1 In/out 
 * USB_DEVICE_EPINTFLAG_STALL(value)  Stall x In/out 
 */
static inline uint8_t usbendpoint_get_EPINTFLAG(uint8_t submodule_index, uint8_t mask)
{
    return ((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & mask;
}

/**
 * @brief usbendpoint read EPINTFLAG register
 *
 * @param[in] uint8_t           submodule_index
 * @return uint8_t
 * USB_DEVICE_EPINTFLAG_TRCPT0  Transfer Complete 0 
 * USB_DEVICE_EPINTFLAG_TRCPT1  Transfer Complete 1 
 * USB_DEVICE_EPINTFLAG_TRCPT(value)  Transfer Complete x 
 * USB_DEVICE_EPINTFLAG_TRFAIL0  Error Flow 0 
 * USB_DEVICE_EPINTFLAG_TRFAIL1  Error Flow 1 
 * USB_DEVICE_EPINTFLAG_TRFAIL(value)  Error Flow x 
 * USB_DEVICE_EPINTFLAG_RXSTP  Received Setup 
 * USB_DEVICE_EPINTFLAG_STALL0  Stall 0 In/out 
 * USB_DEVICE_EPINTFLAG_STALL1  Stall 1 In/out 
 * USB_DEVICE_EPINTFLAG_STALL(value)  Stall x In/out 
 */
static inline uint8_t usbendpoint_read_EPINTFLAG(uint8_t           submodule_index)
{
	return ((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTFLAG.reg;
}

/**
 * @brief usbendpoint clear EPINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPINTFLAG_TRCPT0  Transfer Complete 0 
 * USB_DEVICE_EPINTFLAG_TRCPT1  Transfer Complete 1 
 * USB_DEVICE_EPINTFLAG_TRCPT(value)  Transfer Complete x 
 * USB_DEVICE_EPINTFLAG_TRFAIL0  Error Flow 0 
 * USB_DEVICE_EPINTFLAG_TRFAIL1  Error Flow 1 
 * USB_DEVICE_EPINTFLAG_TRFAIL(value)  Error Flow x 
 * USB_DEVICE_EPINTFLAG_RXSTP  Received Setup 
 * USB_DEVICE_EPINTFLAG_STALL0  Stall 0 In/out 
 * USB_DEVICE_EPINTFLAG_STALL1  Stall 1 In/out 
 * USB_DEVICE_EPINTFLAG_STALL(value)  Stall x In/out 
 */
static inline void usbendpoint_clear_EPINTFLAG(uint8_t submodule_index, uint8_t mask)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = mask;
}

/**
 * @brief usbendpoint set EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline void usbendpoint_set_EPCFG(uint8_t submodule_index, uint8_t mask)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPCFG.reg |= mask;
}

/**
 * @brief usbendpoint get EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline uint8_t usbendpoint_get_EPCFG(uint8_t submodule_index, uint8_t mask)
{
    return ((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPCFG.reg & mask;
}

/**
 * @brief usbendpoint write EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline void usbendpoint_write_EPCFG(uint8_t submodule_index, uint8_t data)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPCFG.reg = data;
}

/**
 * @brief usbendpoint clear EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline void usbendpoint_clear_EPCFG(uint8_t submodule_index, uint8_t mask)
{
	((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPCFG.reg &= ~mask;
}

/**
 * @brief usbendpoint read EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline uint8_t usbendpoint_read_EPCFG(uint8_t submodule_index)
{
	return ((USBDEVICE_t *)USB)->DeviceEndpoint[submodule_index].EPCFG.reg;
}

/**
 * @brief usbdevice set EPSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbdevice_set_EPSTATUS(uint8_t submodule_index, uint8_t mask)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = mask;
}

/**
 * @brief usbdevice get EPSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline uint8_t usbdevice_get_EPSTATUS(uint8_t submodule_index, uint8_t mask)
{
    return USB->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg & mask;
}

/**
 * @brief usbdevice read EPSTATUS register
 *
 * @param[in] uint8_t           submodule_index
 * @return uint8_t
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline uint8_t usbdevice_read_EPSTATUS(uint8_t           submodule_index)
{
	return USB->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg;
}

/**
 * @brief usbdevice write EPSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbdevice_write_EPSTATUS(uint8_t submodule_index, uint8_t data)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = data;
	USB->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = ~data;
}

/**
 * @brief usbdevice clear EPSTATUS register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPSTATUS_DTGLOUT  Data Toggle Out 
 * USB_DEVICE_EPSTATUS_DTGLIN  Data Toggle In 
 * USB_DEVICE_EPSTATUS_CURBK  Current Bank 
 * USB_DEVICE_EPSTATUS_STALLRQ0  Stall 0 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ1  Stall 1 Request 
 * USB_DEVICE_EPSTATUS_STALLRQ(value)  Stall x Request 
 * USB_DEVICE_EPSTATUS_BK0RDY  Bank 0 ready 
 * USB_DEVICE_EPSTATUS_BK1RDY  Bank 1 ready 
 */
static inline void usbdevice_clear_EPSTATUS(uint8_t submodule_index, uint8_t mask)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = mask;
}

/**
 * @brief usbdevice set EPINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline void usbdevice_set_EPINTEN(uint8_t submodule_index, uint8_t mask)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = mask;
}

/**
 * @brief usbdevice get EPINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline uint8_t usbdevice_get_EPINTEN(uint8_t submodule_index, uint8_t mask)
{
    return USB->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg & mask;
}

/**
 * @brief usbdevice read EPINTEN register
 *
 * @param[in] uint8_t           submodule_index
 * @return uint8_t
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline uint8_t usbdevice_read_EPINTEN(uint8_t           submodule_index)
{
	return USB->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg;
}

/**
 * @brief usbdevice write EPINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline void usbdevice_write_EPINTEN(uint8_t submodule_index, uint8_t data)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = data;
	USB->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = ~data;
}

/**
 * @brief usbdevice clear EPINTEN register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPINTENSET_TRCPT0  Transfer Complete 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT1  Transfer Complete 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRCPT(value)  Transfer Complete x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL0  Error Flow 0 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL1  Error Flow 1 Interrupt Enable 
 * USB_DEVICE_EPINTENSET_TRFAIL(value)  Error Flow x Interrupt Enable 
 * USB_DEVICE_EPINTENSET_RXSTP  Received Setup Interrupt Enable 
 * USB_DEVICE_EPINTENSET_STALL0  Stall 0 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL1  Stall 1 In/out Interrupt enable 
 * USB_DEVICE_EPINTENSET_STALL(value)  Stall x In/out Interrupt enable 
 */
static inline void usbdevice_clear_EPINTEN(uint8_t submodule_index, uint8_t mask)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = mask;
}

/**
 * @brief usbdevice get EPINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_EPINTFLAG_TRCPT0  Transfer Complete 0 
 * USB_DEVICE_EPINTFLAG_TRCPT1  Transfer Complete 1 
 * USB_DEVICE_EPINTFLAG_TRCPT(value)  Transfer Complete x 
 * USB_DEVICE_EPINTFLAG_TRFAIL0  Error Flow 0 
 * USB_DEVICE_EPINTFLAG_TRFAIL1  Error Flow 1 
 * USB_DEVICE_EPINTFLAG_TRFAIL(value)  Error Flow x 
 * USB_DEVICE_EPINTFLAG_RXSTP  Received Setup 
 * USB_DEVICE_EPINTFLAG_STALL0  Stall 0 In/out 
 * USB_DEVICE_EPINTFLAG_STALL1  Stall 1 In/out 
 * USB_DEVICE_EPINTFLAG_STALL(value)  Stall x In/out 
 */
static inline uint8_t usbdevice_get_EPINTFLAG(uint8_t submodule_index, uint8_t mask)
{
    return USB->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & mask;
}

/**
 * @brief usbdevice read EPINTFLAG register
 *
 * @param[in] uint8_t           submodule_index
 * @return uint8_t
 * USB_DEVICE_EPINTFLAG_TRCPT0  Transfer Complete 0 
 * USB_DEVICE_EPINTFLAG_TRCPT1  Transfer Complete 1 
 * USB_DEVICE_EPINTFLAG_TRCPT(value)  Transfer Complete x 
 * USB_DEVICE_EPINTFLAG_TRFAIL0  Error Flow 0 
 * USB_DEVICE_EPINTFLAG_TRFAIL1  Error Flow 1 
 * USB_DEVICE_EPINTFLAG_TRFAIL(value)  Error Flow x 
 * USB_DEVICE_EPINTFLAG_RXSTP  Received Setup 
 * USB_DEVICE_EPINTFLAG_STALL0  Stall 0 In/out 
 * USB_DEVICE_EPINTFLAG_STALL1  Stall 1 In/out 
 * USB_DEVICE_EPINTFLAG_STALL(value)  Stall x In/out 
 */
static inline uint8_t usbdevice_read_EPINTFLAG(uint8_t           submodule_index)
{
	return USB->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg;
}

/**
 * @brief usbdevice clear EPINTFLAG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPINTFLAG_TRCPT0  Transfer Complete 0 
 * USB_DEVICE_EPINTFLAG_TRCPT1  Transfer Complete 1 
 * USB_DEVICE_EPINTFLAG_TRCPT(value)  Transfer Complete x 
 * USB_DEVICE_EPINTFLAG_TRFAIL0  Error Flow 0 
 * USB_DEVICE_EPINTFLAG_TRFAIL1  Error Flow 1 
 * USB_DEVICE_EPINTFLAG_TRFAIL(value)  Error Flow x 
 * USB_DEVICE_EPINTFLAG_RXSTP  Received Setup 
 * USB_DEVICE_EPINTFLAG_STALL0  Stall 0 In/out 
 * USB_DEVICE_EPINTFLAG_STALL1  Stall 1 In/out 
 * USB_DEVICE_EPINTFLAG_STALL(value)  Stall x In/out 
 */
static inline void usbdevice_clear_EPINTFLAG(uint8_t submodule_index, uint8_t mask)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = mask;
}

/**
 * @brief usbdevice set EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline void usbdevice_set_EPCFG(uint8_t submodule_index, uint8_t mask)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg |= mask;
}

/**
 * @brief usbdevice get EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * @return uint8_t
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline uint8_t usbdevice_get_EPCFG(uint8_t submodule_index, uint8_t mask)
{
    return USB->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg & mask;
}

/**
 * @brief usbdevice write EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t data
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline void usbdevice_write_EPCFG(uint8_t submodule_index, uint8_t data)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg = data;
}

/**
 * @brief usbdevice clear EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @param[in] uint8_t mask
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline void usbdevice_clear_EPCFG(uint8_t submodule_index, uint8_t mask)
{
	USB->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg &= ~mask;
}

/**
 * @brief usbdevice read EPCFG register
 *
 * @param[in] uint8_t submodule_index
 * @return uint8_t
 * USB_DEVICE_EPCFG_EPTYPE0(value)  End Point Type0 
 * USB_DEVICE_EPCFG_EPTYPE1(value)  End Point Type1 
 * USB_DEVICE_EPCFG_NYETDIS  NYET Token Disable 
 */
static inline uint8_t usbdevice_read_EPCFG(uint8_t submodule_index)
{
	return USB->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
}

/**
 * @brief usbhostdescbank set ADDR register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint32_t mask
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbhostdescbank_set_ADDR(UsbHostDescBank_t *pUSBhostdesc, uint32_t mask)
{
	pUSBhostdesc->ADDR.reg |= mask;
}

/**
 * @brief usbhostdescbank get ADDR register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline uint32_t usbhostdescbank_get_ADDR(UsbHostDescBank_t *pUSBhostdesc, uint32_t mask)
{
    return pUSBhostdesc->ADDR.reg & mask;
}

/**
 * @brief usbhostdescbank write ADDR register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint32_t data
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbhostdescbank_write_ADDR(UsbHostDescBank_t *pUSBhostdesc, uint32_t data)
{
	pUSBhostdesc->ADDR.reg = data;
}

/**
 * @brief usbhostdescbank clear ADDR register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint32_t mask
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbhostdescbank_clear_ADDR(UsbHostDescBank_t *pUSBhostdesc, uint32_t mask)
{
	pUSBhostdesc->ADDR.reg &= ~mask;
}

/**
 * @brief usbhostdescbank read ADDR register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @return uint32_t
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline uint32_t usbhostdescbank_read_ADDR(UsbHostDescBank_t *pUSBhostdesc)
{
	return pUSBhostdesc->ADDR.reg;
}

/**
 * @brief usbhostdescbank set PCKSIZE register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint32_t mask
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbhostdescbank_set_PCKSIZE(UsbHostDescBank_t *pUSBhostdesc, uint32_t mask)
{
	pUSBhostdesc->PCKSIZE.reg |= mask;
}

/**
 * @brief usbhostdescbank get PCKSIZE register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline uint32_t usbhostdescbank_get_PCKSIZE(UsbHostDescBank_t *pUSBhostdesc, uint32_t mask)
{
    return pUSBhostdesc->PCKSIZE.reg & mask;
}

/**
 * @brief usbhostdescbank write PCKSIZE register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint32_t data
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbhostdescbank_write_PCKSIZE(UsbHostDescBank_t *pUSBhostdesc, uint32_t data)
{
	pUSBhostdesc->PCKSIZE.reg = data;
}

/**
 * @brief usbhostdescbank clear PCKSIZE register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint32_t mask
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbhostdescbank_clear_PCKSIZE(UsbHostDescBank_t *pUSBhostdesc, uint32_t mask)
{
	pUSBhostdesc->PCKSIZE.reg &= ~mask;
}

/**
 * @brief usbhostdescbank read PCKSIZE register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @return uint32_t
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline uint32_t usbhostdescbank_read_PCKSIZE(UsbHostDescBank_t *pUSBhostdesc)
{
	return pUSBhostdesc->PCKSIZE.reg;
}

/**
 * @brief usbhostdescbank set EXTREG register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint16_t mask
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbhostdescbank_set_EXTREG(UsbHostDescBank_t *pUSBhostdesc, uint16_t mask)
{
	pUSBhostdesc->EXTREG.reg |= mask;
}

/**
 * @brief usbhostdescbank get EXTREG register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline uint16_t usbhostdescbank_get_EXTREG(UsbHostDescBank_t *pUSBhostdesc, uint16_t mask)
{
    return pUSBhostdesc->EXTREG.reg & mask;
}

/**
 * @brief usbhostdescbank write EXTREG register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint16_t data
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbhostdescbank_write_EXTREG(UsbHostDescBank_t *pUSBhostdesc, uint16_t data)
{
	pUSBhostdesc->EXTREG.reg = data;
}

/**
 * @brief usbhostdescbank clear EXTREG register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @param[in] uint16_t mask
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbhostdescbank_clear_EXTREG(UsbHostDescBank_t *pUSBhostdesc, uint16_t mask)
{
	pUSBhostdesc->EXTREG.reg &= ~mask;
}

/**
 * @brief usbhostdescbank read EXTREG register
 *
 * @param[in] UsbHostDescBank_t *pUSBhostdesc
 * @return uint16_t
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline uint16_t usbhostdescbank_read_EXTREG(UsbHostDescBank_t *pUSBhostdesc)
{
	return pUSBhostdesc->EXTREG.reg;
}

/**
 * @brief usbhostdescriptor set ADDR register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbhostdescriptor_set_ADDR(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint32_t mask)
{
	pUSBhostdesc->HostDescBank[submodule_index].ADDR.reg |= mask;
}

/**
 * @brief usbhostdescriptor get ADDR register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline uint32_t usbhostdescriptor_get_ADDR(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint32_t mask)
{
    return pUSBhostdesc->HostDescBank[submodule_index].ADDR.reg & mask;
}

/**
 * @brief usbhostdescriptor write ADDR register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t data
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbhostdescriptor_write_ADDR(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint32_t data)
{
	pUSBhostdesc->HostDescBank[submodule_index].ADDR.reg = data;
}

/**
 * @brief usbhostdescriptor clear ADDR register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline void usbhostdescriptor_clear_ADDR(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint32_t mask)
{
	pUSBhostdesc->HostDescBank[submodule_index].ADDR.reg &= ~mask;
}

/**
 * @brief usbhostdescriptor read ADDR register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t           submodule_index
 * @return uint32_t
 * USB_HOST_ADDR_ADDR(value)  Adress of data buffer 
 */
static inline uint32_t usbhostdescriptor_read_ADDR(UsbHostDescriptor_t *pUSBhostdesc, uint8_t           submodule_index)
{
	return pUSBhostdesc->HostDescBank[submodule_index].ADDR.reg;
}

/**
 * @brief usbhostdescriptor set PCKSIZE register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbhostdescriptor_set_PCKSIZE(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint32_t mask)
{
	pUSBhostdesc->HostDescBank[submodule_index].PCKSIZE.reg |= mask;
}

/**
 * @brief usbhostdescriptor get PCKSIZE register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * @return uint32_t
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline uint32_t usbhostdescriptor_get_PCKSIZE(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint32_t mask)
{
    return pUSBhostdesc->HostDescBank[submodule_index].PCKSIZE.reg & mask;
}

/**
 * @brief usbhostdescriptor write PCKSIZE register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t data
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbhostdescriptor_write_PCKSIZE(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint32_t data)
{
	pUSBhostdesc->HostDescBank[submodule_index].PCKSIZE.reg = data;
}

/**
 * @brief usbhostdescriptor clear PCKSIZE register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint32_t mask
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline void usbhostdescriptor_clear_PCKSIZE(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint32_t mask)
{
	pUSBhostdesc->HostDescBank[submodule_index].PCKSIZE.reg &= ~mask;
}

/**
 * @brief usbhostdescriptor read PCKSIZE register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @return uint32_t
 * USB_HOST_PCKSIZE_BYTE_COUNT(value)  Byte Count 
 * USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(value)  Multi Packet In or Out size 
 * USB_HOST_PCKSIZE_SIZE(value)  Pipe size 
 * USB_HOST_PCKSIZE_AUTO_ZLP  Automatic Zero Length Packet 
 */
static inline uint32_t usbhostdescriptor_read_PCKSIZE(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index)
{
	return pUSBhostdesc->HostDescBank[submodule_index].PCKSIZE.reg;
}

/**
 * @brief usbhostdescriptor set EXTREG register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint16_t mask
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbhostdescriptor_set_EXTREG(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint16_t mask)
{
	pUSBhostdesc->HostDescBank[submodule_index].EXTREG.reg |= mask;
}

/**
 * @brief usbhostdescriptor get EXTREG register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint16_t mask
 * @return uint16_t
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline uint16_t usbhostdescriptor_get_EXTREG(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint16_t mask)
{
    return pUSBhostdesc->HostDescBank[submodule_index].EXTREG.reg & mask;
}

/**
 * @brief usbhostdescriptor write EXTREG register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint16_t data
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbhostdescriptor_write_EXTREG(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint16_t data)
{
	pUSBhostdesc->HostDescBank[submodule_index].EXTREG.reg = data;
}

/**
 * @brief usbhostdescriptor clear EXTREG register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @param[in] uint16_t mask
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline void usbhostdescriptor_clear_EXTREG(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index, uint16_t mask)
{
	pUSBhostdesc->HostDescBank[submodule_index].EXTREG.reg &= ~mask;
}

/**
 * @brief usbhostdescriptor read EXTREG register
 *
 * @param[in] UsbHostDescriptor_t *pUSBhostdesc
 * @param[in] uint8_t submodule_index
 * @return uint16_t
 * USB_HOST_EXTREG_SUBPID(value)  SUBPID field send with extended token 
 * USB_HOST_EXTREG_VARIABLE(value)  Variable field send with extended token 
 */
static inline uint16_t usbhostdescriptor_read_EXTREG(UsbHostDescriptor_t *pUSBhostdesc, uint8_t submodule_index)
{
	return pUSBhostdesc->HostDescBank[submodule_index].EXTREG.reg;
}

#endif /* _USB_H */
