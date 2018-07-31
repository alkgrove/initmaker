/**
 * @note This file is modified from the Atmel ASF4 hri include
 * by Alkgrove 2018
 * @version beta
**/
/**
 * \file
 *
 * \brief SAM DMAC
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

#ifndef _DMAC_H_
#define _DMAC_H_

#include <stdbool.h>

#define MAX_BTCNT 65535

#ifndef DMAC_BASE_COUNT
#define DMAC_BASE_COUNT DMAC_CH_NUM
#endif

#define CHANNEL0	0
#define CHANNEL1	1
#define CHANNEL2	2
#define CHANNEL3	3
#define CHANNEL4	4
#define CHANNEL5	5
#define CHANNEL6	6
#define CHANNEL7	7
#define CHANNEL8	8
#define CHANNEL9	9
#define CHANNEL10	10
#define CHANNEL11	11
#define CHANNEL12	12
#define CHANNEL13	13
#define CHANNEL14	14
#define CHANNEL15	15
#define CHANNEL16	16
#define CHANNEL17	17
#define CHANNEL18	18
#define CHANNEL19	19
#define CHANNEL20	20
#define CHANNEL21	21
#define CHANNEL22	22
#define CHANNEL23	23
#define CHANNEL24	24
#define CHANNEL25	25
#define CHANNEL26	26
#define CHANNEL27	27
#define CHANNEL28	28
#define CHANNEL29	29
#define CHANNEL30	30
#define CHANNEL31	31

/**
 * @brief Trigger Source
 *
 */
#define DMAC_DISABLE_TRIGGER		0x00
#define DMAC_SOFTWARE_TRIGGER   	0x00
#define DMAC_RTC_TIMESTAMP_TRIGGER  0x01
#define DMAC_DSU_DCC0_TRIGGER	    0x02
#define DMAC_DSU_DCC1_TRIGGER	    0x03
#define DMAC_SERCOM0_RX_TRIGGER	    0x04
#define DMAC_SERCOM0_TX_TRIGGER	    0x05
#define DMAC_SERCOM1_RX_TRIGGER	    0x06
#define DMAC_SERCOM1_TX_TRIGGER	    0x07
#define DMAC_SERCOM2_RX_TRIGGER	    0x08
#define DMAC_SERCOM2_TX_TRIGGER	    0x09
#define DMAC_SERCOM3_RX_TRIGGER	    0x0A
#define DMAC_SERCOM3_TX_TRIGGER	    0x0B
#define DMAC_SERCOM4_RX_TRIGGER	    0x0C
#define DMAC_SERCOM4_TX_TRIGGER	    0x0D
#define DMAC_SERCOM5_RX_TRIGGER	    0x0E
#define DMAC_SERCOM5_TX_TRIGGER	    0x0F
#define DMAC_SERCOM6_RX_TRIGGER	    0x10
#define DMAC_SERCOM6_TX_TRIGGER	    0x11
#define DMAC_SERCOM7_RX_TRIGGER	    0x12
#define DMAC_SERCOM7_TX_TRIGGER	    0x13
#define DMAC_CAN0_DEBUG_TRIGGER	    0x14
#define DMAC_CAN1_DEBUG_TRIGGER	    0x15
#define DMAC_TCC0_OVF_TRIGGER  	    0x16
#define DMAC_TCC0_MC0_TRIGGER	0x17
#define DMAC_TCC0_MC1_TRIGGER	0x18
#define DMAC_TCC0_MC2_TRIGGER	0x19
#define DMAC_TCC0_MC3_TRIGGER	0x1A
#define DMAC_TCC0_MC4_TRIGGER	0x1B
#define DMAC_TCC0_MC5_TRIGGER	0x1C
#define DMAC_TCC1_OVF_TRIGGER		0x1D
#define DMAC_TCC1_MC0_TRIGGER	0x1E
#define DMAC_TCC1_MC1_TRIGGER	0x1F
#define DMAC_TCC1_MC2_TRIGGER	0x20
#define DMAC_TCC1_MC3_TRIGGER	0x21
#define DMAC_TCC2_OVF_TRIGGER		0x22
#define DMAC_TCC2_MC0_TRIGGER	0x23
#define DMAC_TCC2_MC1_TRIGGER	0x24
#define DMAC_TCC2_MC2_TRIGGER	0x25
#define DMAC_TCC3_OVF_TRIGGER		0x26
#define DMAC_TCC3_MC0_TRIGGER	0x27
#define DMAC_TCC3_MC1_TRIGGER	0x28
#define DMAC_TCC4_OVF_TRIGGER		0x29
#define DMAC_TCC4_MC0_TRIGGER	0x2A
#define DMAC_TCC4_MC1_TRIGGER	0x2B
#define DMAC_TC0_OVF_TRIGGER			0x2C
#define DMAC_TC0_MC0_TRIGGER	0x2D
#define DMAC_TC0_MC1_TRIGGER	0x2E
#define DMAC_TC1_OVF_TRIGGER			0x2F
#define DMAC_TC1_MC0_TRIGGER	0x30
#define DMAC_TC1_MC1_TRIGGER	0x31
#define DMAC_TC2_OVF_TRIGGER			0x32
#define DMAC_TC2_MC0_TRIGGER	0x33
#define DMAC_TC2_MC1_TRIGGER	0x34
#define DMAC_TC3_OVF_TRIGGER			0x35
#define DMAC_TC3_MC0_TRIGGER	0x36
#define DMAC_TC3_MC1_TRIGGER	0x37
#define DMAC_TC4_OVF_TRIGGER			0x38
#define DMAC_TC4_MC0_TRIGGER	0x39
#define DMAC_TC4_MC1_TRIGGER	0x3A
#define DMAC_TC5_OVF_TRIGGER			0x3B
#define DMAC_TC5_MC0_TRIGGER	0x3C
#define DMAC_TC5_MC1_TRIGGER	0x3D
#define DMAC_TC6_OVF_TRIGGER			0x3E
#define DMAC_TC6_MC0_TRIGGER	0x3F
#define DMAC_TC6_MC1_TRIGGER	0x40
#define DMAC_TC7_OVF_TRIGGER			0x41
#define DMAC_TC7_MC0_TRIGGER	0x42
#define DMAC_TC7_MC1_TRIGGER	0x43
#define DMAC_ADC0_RESRDY_TRIGGER	    0x44
#define DMAC_ADC0_SEQ_TRIGGER	    0x45
#define DMAC_ADC1_RESRDY_TRIGGER	    0x46
#define DMAC_ADC1_SEQ_TRIGGER	    0x47
#define DMAC_DAC_EMPTY0_TRIGGER	    0x48
#define DMAC_DAC_EMPTY1_TRIGGER	    0x49
#define DMAC_DAC_RESRDY0_TRIGGER	    0x4A
#define DMAC_DAC_RESRDY1_TRIGGER	    0x4B
#define DMAC_I2S_RX0_TRIGGER		0x4C
#define DMAC_I2S_RX1_TRIGGER		0x4D
#define DMAC_I2S_TX0_TRIGGER		0x4E
#define DMAC_I2S_TX1_TRIGGER		0x4F
#define DMAC_PCC_RX_TRIGGER		    0x50
#define DMAC_AES_WR_TRIGGER		    0x51
#define DMAC_AES_RD_TRIGGER	        0x52
#define DMAC_QSPI_RX_TRIGGER	    0x53
#define DMAC_QSPI_TX_TRIGGER	    0x54

/**
 * @brief return pointer to base descriptor array
 * @param[in] uint8_t index to base descriptor arra
 * @return DmacDescriptor *
 */
DmacDescriptor *get_base_DMA_descriptor(uint8_t channel);
/**
 * @brief return pointer to write back descriptor array
 * @param[in] uint8_t index to base descriptor arra
 *
 * @return DmacDescriptor *
 */
DmacDescriptor *get_base_DMA_writeback_descriptor(uint8_t channel);

/**
 * @brief a debug print of descriptor
 * @param[in] DmacDescriptor * pointer to Descriptor
 * @param[in] DmacDescriptor * ep pointer to last descriptor in link list or null
 *
 */
#ifdef DEBUG
void print_descriptor(DmacDescriptor *p, DmacDescriptor *ep);
#endif
/**
 * @brief set DMA Software Reset
 * DMA Enable and CRC Enable must be disabled before setting the software reset
 */
static inline void dmac_set_SWRST(void)
{
	DMAC->CTRL.reg |= DMAC_CTRL_SWRST;
}
/**
 * @brief get software reset bit from CTROL register
 *
 * @return bool true if software reset in progress, false if not
 */
static inline bool dmac_get_SWRST(void)
{
	return (bool) ((DMAC->CTRL.reg & DMAC_CTRL_SWRST) >> DMAC_CTRL_SWRST_Pos);
}
/**
 * @brief set DMA Enable bit
 *
 */
static inline void dmac_set_DMAENABLE(void)
{
	DMAC->CTRL.reg |= DMAC_CTRL_DMAENABLE;
}

/**
 * @brief get DMA Enable bit
 *
 * @return bool true if set, false if clear
 */
static inline bool dmac_get_DMAENABLE(void)
{
	return (bool) (DMAC->CTRL.reg & DMAC_CTRL_DMAENABLE) >> DMAC_CTRL_DMAENABLE_Pos;
}

/**
 * @brief clear DMA Enable bit
 * This must be done prior to SWRST
 *
 */
static inline void dmac_clear_DMAENABLE(void)
{
	DMAC->CTRL.reg &= ~DMAC_CTRL_DMAENABLE;
}

/**
 * @brief write Control registers 
 *
 * @param[in] uint16_t data 
 * DMAC_CTRL_SWRST	Software Reset 
 * DMAC_CTRL_DMAENABLE	DMA Enable 
 * DMAC_CTRL_LVLEN0	Priority Level 0 Enable 
 * DMAC_CTRL_LVLEN1	Priority Level 1 Enable 
 * DMAC_CTRL_LVLEN2	Priority Level 2 Enable 
 * DMAC_CTRL_LVLEN3	Priority Level 3 Enable 
 * DMAC_CTRL_LVLEN(value) Priority Level x Enable 
 */
static inline void dmac_write_CTRL(uint16_t data)
{
	DMAC->CTRL.reg = data;
}

/**
 * @brief read Control registers 
 *
 * @return uint16_t 
 * DMAC_CTRL_SWRST	Software Reset 
 * DMAC_CTRL_DMAENABLE	DMA Enable 
 * DMAC_CTRL_LVLEN0	Priority Level 0 Enable 
 * DMAC_CTRL_LVLEN1	Priority Level 1 Enable 
 * DMAC_CTRL_LVLEN2	Priority Level 2 Enable 
 * DMAC_CTRL_LVLEN3	Priority Level 3 Enable 
 * DMAC_CTRL_LVLEN(value) Priority Level x Enable 
 */
static inline uint16_t dmac_read_CTRL(void)
{
	return DMAC->CTRL.reg;
}

/**
 * @brief set CRC Control
 *
 * @param[in] uint16_t mask
 * DMAC_CRCCTRL_CRCBEATSIZE(value) CRC Beat Size 
 * DMAC_CRCCTRL_CRCBEATSIZE_BYTE 
 * DMAC_CRCCTRL_CRCBEATSIZE_HWORD
 * DMAC_CRCCTRL_CRCBEATSIZE_WORD
 * DMAC_CRCCTRL_CRCPOLY(value)	CRC Polynomial Type 
 * DMAC_CRCCTRL_CRCPOLY_CRC16 
 * DMAC_CRCCTRL_CRCPOLY_CRC32 
 * DMAC_CRCCTRL_CRCSRC(value)	CRC Input Source 
 * DMAC_CRCCTRL_CRCSRC_DISABLE
 * DMAC_CRCCTRL_CRCSRC_IO     
 * DMAC_CRCCTRL_CRCMODE		    CRC Operating Mode 
 * DMAC_CRCCTRL_CRCMODE_DEFAULT
 * DMAC_CRCCTRL_CRCMODE_CRCMON 
 * DMAC_CRCCTRL_CRCMODE_CRCGEN  
 */
static inline void dmac_set_CRCCTRL(uint16_t mask)
{
	DMAC->CRCCTRL.reg |= mask;
}

/**
 * @brief set CRC Control
 *
 * @param[in] uint16_t mask
 * DMAC_CRCCTRL_CRCBEATSIZE(value) CRC Beat Size 
 * DMAC_CRCCTRL_CRCBEATSIZE_BYTE 
 * DMAC_CRCCTRL_CRCBEATSIZE_HWORD
 * DMAC_CRCCTRL_CRCBEATSIZE_WORD
 * DMAC_CRCCTRL_CRCPOLY(value)	CRC Polynomial Type 
 * DMAC_CRCCTRL_CRCPOLY_CRC16 
 * DMAC_CRCCTRL_CRCPOLY_CRC32 
 * DMAC_CRCCTRL_CRCSRC(value)	CRC Input Source 
 * DMAC_CRCCTRL_CRCSRC_DISABLE
 * DMAC_CRCCTRL_CRCSRC_IO     
 * DMAC_CRCCTRL_CRCMODE		CRC Operating Mode 
 * DMAC_CRCCTRL_CRCMODE_DEFAULT
 * DMAC_CRCCTRL_CRCMODE_CRCMON 
 * DMAC_CRCCTRL_CRCMODE_CRCGEN  
 */
static inline void dmac_write_CRCCTRL(uint16_t data)
{
	DMAC->CRCCTRL.reg = data;
}
/**
 * @brief clear CRC control register with mask
 *
 * @param[in] uint16_t mask
 * DMAC_CRCCTRL_CRCBEATSIZE(value) CRC Beat Size 
 * DMAC_CRCCTRL_CRCBEATSIZE_BYTE 
 * DMAC_CRCCTRL_CRCBEATSIZE_HWORD
 * DMAC_CRCCTRL_CRCBEATSIZE_WORD
 * DMAC_CRCCTRL_CRCPOLY(value)	CRC Polynomial Type 
 * DMAC_CRCCTRL_CRCPOLY_CRC16 
 * DMAC_CRCCTRL_CRCPOLY_CRC32 
 * DMAC_CRCCTRL_CRCSRC(value)	CRC Input Source 
 * DMAC_CRCCTRL_CRCSRC_DISABLE
 * DMAC_CRCCTRL_CRCSRC_IO     
 * DMAC_CRCCTRL_CRCMODE		CRC Operating Mode 
 * DMAC_CRCCTRL_CRCMODE_DEFAULT
 * DMAC_CRCCTRL_CRCMODE_CRCMON 
 * DMAC_CRCCTRL_CRCMODE_CRCGEN 
 */
static inline void dmac_clear_CRCCTRL(uint16_t mask)
{
	DMAC->CRCCTRL.reg &= ~mask;
}

/**
 * @brief read CRC control register
 *
 * @param[in] uint16_t mask
 * DMAC_CRCCTRL_CRCBEATSIZE(value) CRC Beat Size 
 * DMAC_CRCCTRL_CRCBEATSIZE_BYTE 
 * DMAC_CRCCTRL_CRCBEATSIZE_HWORD
 * DMAC_CRCCTRL_CRCBEATSIZE_WORD
 * DMAC_CRCCTRL_CRCPOLY(value)	CRC Polynomial Type 
 * DMAC_CRCCTRL_CRCPOLY_CRC16 
 * DMAC_CRCCTRL_CRCPOLY_CRC32 
 * DMAC_CRCCTRL_CRCSRC(value)	CRC Input Source 
 * DMAC_CRCCTRL_CRCSRC_DISABLE
 * DMAC_CRCCTRL_CRCSRC_IO     
 * DMAC_CRCCTRL_CRCMODE		CRC Operating Mode 
 * DMAC_CRCCTRL_CRCMODE_DEFAULT
 * DMAC_CRCCTRL_CRCMODE_CRCMON 
 * DMAC_CRCCTRL_CRCMODE_CRCGEN 
 */
static inline uint16_t dmac_read_CRCCTRL(void)
{
	return DMAC->CRCCTRL.reg;
}

/**
 * @brief write CRC Data 
 *
 * @param[in] uint32_t CRC data (16/32 bit)
 */
static inline void dmac_write_CRCDATAIN(uint32_t data)
{
	DMAC->CRCDATAIN.reg = data;
}

/**
 * @brief read CRC Data input
 *
 * @return uint32_t CRC data (16/32 bit)
 */
static inline uint32_t dmac_read_CRCDATAIN(void)
{
	return DMAC->CRCDATAIN.reg;
}

/**
 * @brief write checksum register
 *
 * @param[in] uint32_t data checksum
 * this can only be written when CRC is disabled
 */
static inline void dmac_write_CRCCHKSUM(uint32_t data)
{
	DMAC->CRCCHKSUM.reg = data;
}

/**
 * @brief read the 16 bit or 32bit checksum
 * 
 * @return uint32_t checksum (16 bit upper bits are zero)
 */
static inline uint32_t dmac_read_CRCCHKSUM(void)
{
	return DMAC->CRCCHKSUM.reg;
}
/**
 * @brief set DBG control Debug Run bit
 *
 */
static inline void dmac_set_DBGRUN(void)
{
	DMAC->DBGCTRL.reg |= DMAC_DBGCTRL_DBGRUN;
}

/**
 * @brief clear DBG control Debug Run bit
 *
 */
static inline void dmac_clear_DBGRUN(void)
{
	DMAC->DBGCTRL.reg &= ~DMAC_DBGCTRL_DBGRUN;
}

/**
 * @brief write debug control register
 *
 * @return uint8_t
 * DMAC_DBGCTRL_DBGRUN
 */
static inline void dmac_write_DBGCTRL(uint8_t data)
{
	DMAC->DBGCTRL.reg = data;
}

/**
 * @brief read debug control 
 *
 * @return uint8_t
 * DMAC_DBGCTRL_DBGRUN
 */
static inline uint8_t dmac_read_DBGCTRL(void)
{
	return DMAC->DBGCTRL.reg;
}

/**
 * @brief set software trigger, initiating a DMA cycle
 *
 * @param[in] uint32_t mask 1 = trigger, 0 = do nothing
 * DMAC_SWTRIGCTRL_SWTRIG0	Channel 0 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG1	Channel 1 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG2	Channel 2 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG3	Channel 3 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG4	Channel 4 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG5	Channel 5 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG6	Channel 6 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG7	Channel 7 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG8	Channel 8 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG9	Channel 9 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG10	Channel 10 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG11	Channel 11 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG12	Channel 12 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG13	Channel 13 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG14	Channel 14 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG15	Channel 15 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG16	Channel 16 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG17	Channel 17 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG18	Channel 18 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG19	Channel 19 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG20	Channel 20 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG21	Channel 21 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG22	Channel 22 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG23	Channel 23 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG24	Channel 24 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG25	Channel 25 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG26	Channel 26 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG27	Channel 27 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG28	Channel 28 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG29	Channel 29 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG30	Channel 30 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG31	Channel 31 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG(value) Channel value Software Trigger 
 */
static inline void dmac_set_SWTRIGCTRL(uint32_t mask)
{
	DMAC->SWTRIGCTRL.reg |= mask;
}

/**
 * @brief get software trigger control register
 *
 * @param[in] uint32_t mask 
 * @return uint32_t software trigger control register masked by mask
 * DMAC_SWTRIGCTRL_SWTRIG0	Channel 0 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG1	Channel 1 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG2	Channel 2 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG3	Channel 3 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG4	Channel 4 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG5	Channel 5 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG6	Channel 6 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG7	Channel 7 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG8	Channel 8 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG9	Channel 9 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG10	Channel 10 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG11	Channel 11 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG12	Channel 12 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG13	Channel 13 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG14	Channel 14 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG15	Channel 15 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG16	Channel 16 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG17	Channel 17 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG18	Channel 18 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG19	Channel 19 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG20	Channel 20 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG21	Channel 21 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG22	Channel 22 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG23	Channel 23 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG24	Channel 24 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG25	Channel 25 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG26	Channel 26 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG27	Channel 27 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG28	Channel 28 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG29	Channel 29 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG30	Channel 30 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG31	Channel 31 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG(value) Channel value Software Trigger 
 */
static inline uint32_t dmac_get_SWTRIGCTRL(uint32_t mask)
{
	return (DMAC->SWTRIGCTRL.reg & mask);
}
/**
 * @brief write software trigger control register
 *
 * @param[in] uint32_t data
 * DMAC_SWTRIGCTRL_SWTRIG0	Channel 0 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG1	Channel 1 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG2	Channel 2 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG3	Channel 3 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG4	Channel 4 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG5	Channel 5 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG6	Channel 6 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG7	Channel 7 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG8	Channel 8 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG9	Channel 9 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG10	Channel 10 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG11	Channel 11 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG12	Channel 12 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG13	Channel 13 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG14	Channel 14 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG15	Channel 15 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG16	Channel 16 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG17	Channel 17 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG18	Channel 18 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG19	Channel 19 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG20	Channel 20 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG21	Channel 21 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG22	Channel 22 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG23	Channel 23 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG24	Channel 24 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG25	Channel 25 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG26	Channel 26 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG27	Channel 27 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG28	Channel 28 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG29	Channel 29 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG30	Channel 30 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG31	Channel 31 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG(value) Channel value Software Trigger 
 */
static inline void dmac_write_SWTRIGCTRL(uint32_t data)
{
	DMAC->SWTRIGCTRL.reg = data;
}

/**
 * @brief clear software trigger control
 *
 * @param[in] uint32_t mask 1 = clears software trigger, 0 does nothing
 * DMAC_SWTRIGCTRL_SWTRIG0	Channel 0 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG1	Channel 1 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG2	Channel 2 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG3	Channel 3 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG4	Channel 4 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG5	Channel 5 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG6	Channel 6 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG7	Channel 7 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG8	Channel 8 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG9	Channel 9 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG10	Channel 10 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG11	Channel 11 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG12	Channel 12 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG13	Channel 13 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG14	Channel 14 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG15	Channel 15 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG16	Channel 16 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG17	Channel 17 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG18	Channel 18 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG19	Channel 19 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG20	Channel 20 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG21	Channel 21 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG22	Channel 22 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG23	Channel 23 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG24	Channel 24 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG25	Channel 25 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG26	Channel 26 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG27	Channel 27 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG28	Channel 28 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG29	Channel 29 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG30	Channel 30 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG31	Channel 31 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG(value) Channel value Software Trigger 
 */
static inline void dmac_clear_SWTRIGCTRL(uint32_t mask)
{
	DMAC->SWTRIGCTRL.reg &= ~mask;
}

/**
 * @brief read software trigger control register
 *
 * @return uint32_t software trigger state
 * DMAC_SWTRIGCTRL_SWTRIG0	Channel 0 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG1	Channel 1 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG2	Channel 2 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG3	Channel 3 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG4	Channel 4 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG5	Channel 5 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG6	Channel 6 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG7	Channel 7 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG8	Channel 8 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG9	Channel 9 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG10	Channel 10 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG11	Channel 11 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG12	Channel 12 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG13	Channel 13 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG14	Channel 14 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG15	Channel 15 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG16	Channel 16 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG17	Channel 17 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG18	Channel 18 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG19	Channel 19 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG20	Channel 20 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG21	Channel 21 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG22	Channel 22 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG23	Channel 23 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG24	Channel 24 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG25	Channel 25 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG26	Channel 26 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG27	Channel 27 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG28	Channel 28 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG29	Channel 29 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG30	Channel 30 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG31	Channel 31 Software Trigger 
 * DMAC_SWTRIGCTRL_SWTRIG(value) Channel value Software Trigger 
 */
static inline uint32_t dmac_read_SWTRIGCTRL(void)
{
	return DMAC->SWTRIGCTRL.reg;
}

/**
 * @brief set Priority Control with mask
 *
 * @param[in] uint32_t mask
 * DMAC_PRICTRL0_LVLPRI0(value)	Level 0 Channel Priority Number 
 * DMAC_PRICTRL0_QOS0		Level 0 Quality of Service 
 * DMAC_PRICTRL0_QOS0_REGULAR  
 * DMAC_PRICTRL0_QOS0_SHORTAGE 
 * DMAC_PRICTRL0_QOS0_SENSITIVE
 * DMAC_PRICTRL0_QOS0_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN0	Level 0 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI1(value)	Level 1 Channel Priority Number 
 * DMAC_PRICTRL0_QOS1		Level 1 Quality of Service 
 * DMAC_PRICTRL0_QOS1_REGULAR  
 * DMAC_PRICTRL0_QOS1_SHORTAGE 
 * DMAC_PRICTRL0_QOS1_SENSITIVE
 * DMAC_PRICTRL0_QOS1_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN1	Level 1 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI2(value)	Level 2 Channel Priority Number 
 * DMAC_PRICTRL0_QOS2		Level 2 Quality of Service 
 * DMAC_PRICTRL0_QOS2_REGULAR  
 * DMAC_PRICTRL0_QOS2_SHORTAGE 
 * DMAC_PRICTRL0_QOS2_SENSITIVE
 * DMAC_PRICTRL0_QOS2_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN2	Level 2 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI3(value)	Level 3 Channel Priority Number 
 * DMAC_PRICTRL0_QOS3		Level 3 Quality of Service 
 * DMAC_PRICTRL0_QOS3_REGULAR  
 * DMAC_PRICTRL0_QOS3_SHORTAGE 
 * DMAC_PRICTRL0_QOS3_SENSITIVE
 * DMAC_PRICTRL0_QOS3_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN3	Level 3 Round-Robin Scheduling Enable 
 * @return uint32_t
 */
static inline void dmac_set_PRICTRL0(uint32_t mask)
{
	DMAC->PRICTRL0.reg |= mask;
}

/**
 * @brief get Priority Control with mask
 *
 * @param[in] uint32_t mask
 * DMAC_PRICTRL0_LVLPRI0(value)	Level 0 Channel Priority Number 
 * DMAC_PRICTRL0_QOS0		Level 0 Quality of Service 
 * DMAC_PRICTRL0_QOS0_REGULAR  
 * DMAC_PRICTRL0_QOS0_SHORTAGE 
 * DMAC_PRICTRL0_QOS0_SENSITIVE
 * DMAC_PRICTRL0_QOS0_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN0	Level 0 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI1(value)	Level 1 Channel Priority Number 
 * DMAC_PRICTRL0_QOS1		Level 1 Quality of Service 
 * DMAC_PRICTRL0_QOS1_REGULAR  
 * DMAC_PRICTRL0_QOS1_SHORTAGE 
 * DMAC_PRICTRL0_QOS1_SENSITIVE
 * DMAC_PRICTRL0_QOS1_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN1	Level 1 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI2(value)	Level 2 Channel Priority Number 
 * DMAC_PRICTRL0_QOS2		Level 2 Quality of Service 
 * DMAC_PRICTRL0_QOS2_REGULAR  
 * DMAC_PRICTRL0_QOS2_SHORTAGE 
 * DMAC_PRICTRL0_QOS2_SENSITIVE
 * DMAC_PRICTRL0_QOS2_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN2	Level 2 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI3(value)	Level 3 Channel Priority Number 
 * DMAC_PRICTRL0_QOS3		Level 3 Quality of Service 
 * DMAC_PRICTRL0_QOS3_REGULAR  
 * DMAC_PRICTRL0_QOS3_SHORTAGE 
 * DMAC_PRICTRL0_QOS3_SENSITIVE
 * DMAC_PRICTRL0_QOS3_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN3	Level 3 Round-Robin Scheduling Enable 
 * @return uint32_t
 */
static inline uint32_t dmac_get_PRICTRL0(uint32_t mask)
{
	return (DMAC->PRICTRL0.reg & mask);
}
/**
 * @brief write Priority Control
 *
 * @param[in] uint32_t mask
 * DMAC_PRICTRL0_LVLPRI0(value)	Level 0 Channel Priority Number 
 * DMAC_PRICTRL0_QOS0		Level 0 Quality of Service 
 * DMAC_PRICTRL0_QOS0_REGULAR  
 * DMAC_PRICTRL0_QOS0_SHORTAGE 
 * DMAC_PRICTRL0_QOS0_SENSITIVE
 * DMAC_PRICTRL0_QOS0_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN0	Level 0 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI1(value)	Level 1 Channel Priority Number 
 * DMAC_PRICTRL0_QOS1		Level 1 Quality of Service 
 * DMAC_PRICTRL0_QOS1_REGULAR  
 * DMAC_PRICTRL0_QOS1_SHORTAGE 
 * DMAC_PRICTRL0_QOS1_SENSITIVE
 * DMAC_PRICTRL0_QOS1_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN1	Level 1 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI2(value)	Level 2 Channel Priority Number 
 * DMAC_PRICTRL0_QOS2		Level 2 Quality of Service 
 * DMAC_PRICTRL0_QOS2_REGULAR  
 * DMAC_PRICTRL0_QOS2_SHORTAGE 
 * DMAC_PRICTRL0_QOS2_SENSITIVE
 * DMAC_PRICTRL0_QOS2_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN2	Level 2 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI3(value)	Level 3 Channel Priority Number 
 * DMAC_PRICTRL0_QOS3		Level 3 Quality of Service 
 * DMAC_PRICTRL0_QOS3_REGULAR  
 * DMAC_PRICTRL0_QOS3_SHORTAGE 
 * DMAC_PRICTRL0_QOS3_SENSITIVE
 * DMAC_PRICTRL0_QOS3_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN3	Level 3 Round-Robin Scheduling Enable 
 * @return uint32_t
 */
static inline void dmac_write_PRICTRL0(uint32_t data)
{
	DMAC->PRICTRL0.reg = data;
}

/**
 * @brief read Priority Control 
 *
 * @param[in] uint32_t mask
 * DMAC_PRICTRL0_LVLPRI0(value)	Level 0 Channel Priority Number 
 * DMAC_PRICTRL0_QOS0		Level 0 Quality of Service 
 * DMAC_PRICTRL0_QOS0_REGULAR  
 * DMAC_PRICTRL0_QOS0_SHORTAGE 
 * DMAC_PRICTRL0_QOS0_SENSITIVE
 * DMAC_PRICTRL0_QOS0_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN0	Level 0 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI1(value)	Level 1 Channel Priority Number 
 * DMAC_PRICTRL0_QOS1		Level 1 Quality of Service 
 * DMAC_PRICTRL0_QOS1_REGULAR  
 * DMAC_PRICTRL0_QOS1_SHORTAGE 
 * DMAC_PRICTRL0_QOS1_SENSITIVE
 * DMAC_PRICTRL0_QOS1_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN1	Level 1 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI2(value)	Level 2 Channel Priority Number 
 * DMAC_PRICTRL0_QOS2		Level 2 Quality of Service 
 * DMAC_PRICTRL0_QOS2_REGULAR  
 * DMAC_PRICTRL0_QOS2_SHORTAGE 
 * DMAC_PRICTRL0_QOS2_SENSITIVE
 * DMAC_PRICTRL0_QOS2_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN2	Level 2 Round-Robin Scheduling Enable 
 * DMAC_PRICTRL0_LVLPRI3(value)	Level 3 Channel Priority Number 
 * DMAC_PRICTRL0_QOS3		Level 3 Quality of Service 
 * DMAC_PRICTRL0_QOS3_REGULAR  
 * DMAC_PRICTRL0_QOS3_SHORTAGE 
 * DMAC_PRICTRL0_QOS3_SENSITIVE
 * DMAC_PRICTRL0_QOS3_CRITICAL 
 * DMAC_PRICTRL0_RRLVLEN3	Level 3 Round-Robin Scheduling Enable 
 * @return uint32_t
 */

static inline uint32_t dmac_read_PRICTRL0(void)
{
	return DMAC->PRICTRL0.reg;
}

/**
 * @brief get Interrupt Pending register with mask
 *
 * @param[in] uint16_t mask
 * @return uint16_t masked interrupt pending register
 */
static inline uint16_t dmac_get_INTPEND(uint16_t mask)
{
	uint16_t tmp;
	tmp = DMAC->INTPEND.reg;
	tmp &= mask;
	return tmp;
}

/**
 * @brief write interrupt pending register
 *
 * @param[in] uint16_t data 
 */
static inline void dmac_write_INTPEND(uint16_t data)
{
	DMAC->INTPEND.reg = data;
}

/**
 * @brief clear interrupt pending register with mask
 *
 * @param[in] uint16_t mask 1 = clear register, 0 = do nothing 
 */
static inline void dmac_clear_INTPEND(uint16_t mask)
{
	DMAC->INTPEND.reg &= ~mask;
}

/**
 * @brief read interrupt pending register
 *
 * @return uint16_t interrupt pending register
 */
static inline uint16_t dmac_read_INTPEND(void)
{
	return DMAC->INTPEND.reg;
}

/**
 * @brief write base address for the channel descripters
 * must be aligned to 16 bytes
 * @param[in] uint32_t data base address for channel descriptors
 */
static inline void dmac_write_BASEADDR(uint32_t data)
{
	DMAC->BASEADDR.reg = data;
}

/**
 * @brief read the base address for the channel descripters
 * must be aligned to 16 bytes
 * @return uint32_t data base address for channel descriptors
 */
static inline uint32_t dmac_read_BASEADDR(void)
{
	return DMAC->BASEADDR.reg;
}

/**
 * @brief write write-back base address register
 * writeback buffer must be 16 byte aligned
 *
 * @param[in] uint32_t write back base address
 */
static inline void dmac_write_WRBADDR(uint32_t data)
{
	DMAC->WRBADDR.reg = data;
}

/**
 * @brief read write-back base address register
 * writeback buffer must be 16 byte aligned
 *
 * @return uint32_t write back base address
 */
static inline uint32_t dmac_read_WRBADDR(void)
{
	return DMAC->WRBADDR.reg;
}

/**
 * @brief get interrupt pending status for all channels
 * This is read only register
 * @return uint32_t
 * DMAC_INTSTATUS_CHINT0	Channel 0 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT1	Channel 1 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT2	Channel 2 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT3	Channel 3 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT4	Channel 4 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT5	Channel 5 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT6	Channel 6 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT7	Channel 7 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT8	Channel 8 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT9	Channel 9 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT10	Channel 10 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT11	Channel 11 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT12	Channel 12 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT13	Channel 13 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT14	Channel 14 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT15	Channel 15 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT16	Channel 16 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT17	Channel 17 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT18	Channel 18 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT19	Channel 19 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT20	Channel 20 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT21	Channel 21 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT22	Channel 22 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT23	Channel 23 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT24	Channel 24 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT25	Channel 25 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT26	Channel 26 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT27	Channel 27 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT28	Channel 28 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT29	Channel 29 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT30	Channel 30 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT31	Channel 31 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT(value)	Channel x Pending Interrupt 
 */
static inline uint32_t dmac_get_INTSTATUS(uint32_t mask)
{
	return (DMAC->INTSTATUS.reg & mask);
}
/**
 * @brief get interrupt pending status for all channels
 * This is read only register
 * @return uint32_t
 * DMAC_INTSTATUS_CHINT0	Channel 0 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT1	Channel 1 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT2	Channel 2 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT3	Channel 3 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT4	Channel 4 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT5	Channel 5 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT6	Channel 6 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT7	Channel 7 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT8	Channel 8 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT9	Channel 9 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT10	Channel 10 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT11	Channel 11 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT12	Channel 12 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT13	Channel 13 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT14	Channel 14 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT15	Channel 15 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT16	Channel 16 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT17	Channel 17 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT18	Channel 18 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT19	Channel 19 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT20	Channel 20 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT21	Channel 21 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT22	Channel 22 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT23	Channel 23 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT24	Channel 24 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT25	Channel 25 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT26	Channel 26 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT27	Channel 27 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT28	Channel 28 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT29	Channel 29 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT30	Channel 30 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT31	Channel 31 Pending Interrupt 
 * DMAC_INTSTATUS_CHINT(value)	Channel x Pending Interrupt 
 */
static inline uint32_t dmac_read_INTSTATUS(void)
{
	return DMAC->INTSTATUS.reg;
}

/**
 * @brief ready channel busy
 * read only register set when DMA transfer starts, cleared when it ends
 * @return uint32_t
 * DMAC_BUSYCH_BUSYCH0	Busy Channel 0 
 * DMAC_BUSYCH_BUSYCH1	Busy Channel 1 
 * DMAC_BUSYCH_BUSYCH2	Busy Channel 2 
 * DMAC_BUSYCH_BUSYCH3	Busy Channel 3 
 * DMAC_BUSYCH_BUSYCH4	Busy Channel 4 
 * DMAC_BUSYCH_BUSYCH5	Busy Channel 5 
 * DMAC_BUSYCH_BUSYCH6	Busy Channel 6 
 * DMAC_BUSYCH_BUSYCH7	Busy Channel 7 
 * DMAC_BUSYCH_BUSYCH8	Busy Channel 8 
 * DMAC_BUSYCH_BUSYCH9	Busy Channel 9 
 * DMAC_BUSYCH_BUSYCH10	Busy Channel 10 
 * DMAC_BUSYCH_BUSYCH11	Busy Channel 11 
 * DMAC_BUSYCH_BUSYCH12	Busy Channel 12 
 * DMAC_BUSYCH_BUSYCH13	Busy Channel 13 
 * DMAC_BUSYCH_BUSYCH14	Busy Channel 14 
 * DMAC_BUSYCH_BUSYCH15	Busy Channel 15 
 * DMAC_BUSYCH_BUSYCH16	Busy Channel 16 
 * DMAC_BUSYCH_BUSYCH17	Busy Channel 17 
 * DMAC_BUSYCH_BUSYCH18	Busy Channel 18 
 * DMAC_BUSYCH_BUSYCH19	Busy Channel 19 
 * DMAC_BUSYCH_BUSYCH20	Busy Channel 20 
 * DMAC_BUSYCH_BUSYCH21	Busy Channel 21 
 * DMAC_BUSYCH_BUSYCH22	Busy Channel 22 
 * DMAC_BUSYCH_BUSYCH23	Busy Channel 23 
 * DMAC_BUSYCH_BUSYCH24	Busy Channel 24 
 * DMAC_BUSYCH_BUSYCH25	Busy Channel 25 
 * DMAC_BUSYCH_BUSYCH26	Busy Channel 26 
 * DMAC_BUSYCH_BUSYCH27	Busy Channel 27 
 * DMAC_BUSYCH_BUSYCH28	Busy Channel 28 
 * DMAC_BUSYCH_BUSYCH29	Busy Channel 29 
 * DMAC_BUSYCH_BUSYCH30	Busy Channel 30 
 * DMAC_BUSYCH_BUSYCH31	Busy Channel 31 
 * DMAC_BUSYCH_BUSYCH(value) Busy Channel x 
 */
static inline uint32_t dmac_get_BUSYCH(uint32_t mask)
{
	return (DMAC->BUSYCH.reg & mask);
}
/**
 * @brief ready channel busy
 * read only register set when DMA transfer starts, cleared when it ends
 * @return uint32_t
 * DMAC_BUSYCH_BUSYCH0	Busy Channel 0 
 * DMAC_BUSYCH_BUSYCH1	Busy Channel 1 
 * DMAC_BUSYCH_BUSYCH2	Busy Channel 2 
 * DMAC_BUSYCH_BUSYCH3	Busy Channel 3 
 * DMAC_BUSYCH_BUSYCH4	Busy Channel 4 
 * DMAC_BUSYCH_BUSYCH5	Busy Channel 5 
 * DMAC_BUSYCH_BUSYCH6	Busy Channel 6 
 * DMAC_BUSYCH_BUSYCH7	Busy Channel 7 
 * DMAC_BUSYCH_BUSYCH8	Busy Channel 8 
 * DMAC_BUSYCH_BUSYCH9	Busy Channel 9 
 * DMAC_BUSYCH_BUSYCH10	Busy Channel 10 
 * DMAC_BUSYCH_BUSYCH11	Busy Channel 11 
 * DMAC_BUSYCH_BUSYCH12	Busy Channel 12 
 * DMAC_BUSYCH_BUSYCH13	Busy Channel 13 
 * DMAC_BUSYCH_BUSYCH14	Busy Channel 14 
 * DMAC_BUSYCH_BUSYCH15	Busy Channel 15 
 * DMAC_BUSYCH_BUSYCH16	Busy Channel 16 
 * DMAC_BUSYCH_BUSYCH17	Busy Channel 17 
 * DMAC_BUSYCH_BUSYCH18	Busy Channel 18 
 * DMAC_BUSYCH_BUSYCH19	Busy Channel 19 
 * DMAC_BUSYCH_BUSYCH20	Busy Channel 20 
 * DMAC_BUSYCH_BUSYCH21	Busy Channel 21 
 * DMAC_BUSYCH_BUSYCH22	Busy Channel 22 
 * DMAC_BUSYCH_BUSYCH23	Busy Channel 23 
 * DMAC_BUSYCH_BUSYCH24	Busy Channel 24 
 * DMAC_BUSYCH_BUSYCH25	Busy Channel 25 
 * DMAC_BUSYCH_BUSYCH26	Busy Channel 26 
 * DMAC_BUSYCH_BUSYCH27	Busy Channel 27 
 * DMAC_BUSYCH_BUSYCH28	Busy Channel 28 
 * DMAC_BUSYCH_BUSYCH29	Busy Channel 29 
 * DMAC_BUSYCH_BUSYCH30	Busy Channel 30 
 * DMAC_BUSYCH_BUSYCH31	Busy Channel 31 
 * DMAC_BUSYCH_BUSYCH(value) Busy Channel x 
 */
static inline uint32_t dmac_read_BUSYCH(void)
{
	return DMAC->BUSYCH.reg;
}

/**
 * @brief get pending channel with mask
 * read only bit is set when channel is pending DMA transfer
 * @param[in] uint32_t mask
 * @return uint32_t
 * DMAC_PENDCH_PENDCH0	Pending Channel 0 
 * DMAC_PENDCH_PENDCH1	Pending Channel 1 
 * DMAC_PENDCH_PENDCH2	Pending Channel 2 
 * DMAC_PENDCH_PENDCH3	Pending Channel 3 
 * DMAC_PENDCH_PENDCH4	Pending Channel 4 
 * DMAC_PENDCH_PENDCH5	Pending Channel 5 
 * DMAC_PENDCH_PENDCH6	Pending Channel 6 
 * DMAC_PENDCH_PENDCH7	Pending Channel 7 
 * DMAC_PENDCH_PENDCH8	Pending Channel 8 
 * DMAC_PENDCH_PENDCH9	Pending Channel 9 
 * DMAC_PENDCH_PENDCH10	Pending Channel 10 
 * DMAC_PENDCH_PENDCH11	Pending Channel 11 
 * DMAC_PENDCH_PENDCH12	Pending Channel 12 
 * DMAC_PENDCH_PENDCH13	Pending Channel 13 
 * DMAC_PENDCH_PENDCH14	Pending Channel 14 
 * DMAC_PENDCH_PENDCH15	Pending Channel 15 
 * DMAC_PENDCH_PENDCH16	Pending Channel 16 
 * DMAC_PENDCH_PENDCH17	Pending Channel 17 
 * DMAC_PENDCH_PENDCH18	Pending Channel 18 
 * DMAC_PENDCH_PENDCH19	Pending Channel 19 
 * DMAC_PENDCH_PENDCH20	Pending Channel 20 
 * DMAC_PENDCH_PENDCH21	Pending Channel 21 
 * DMAC_PENDCH_PENDCH22	Pending Channel 22 
 * DMAC_PENDCH_PENDCH23	Pending Channel 23 
 * DMAC_PENDCH_PENDCH24	Pending Channel 24 
 * DMAC_PENDCH_PENDCH25	Pending Channel 25 
 * DMAC_PENDCH_PENDCH26	Pending Channel 26 
 * DMAC_PENDCH_PENDCH27	Pending Channel 27 
 * DMAC_PENDCH_PENDCH28	Pending Channel 28 
 * DMAC_PENDCH_PENDCH29	Pending Channel 29 
 * DMAC_PENDCH_PENDCH30	Pending Channel 30 
 * DMAC_PENDCH_PENDCH31	Pending Channel 31 
 * DMAC_PENDCH_PENDCH(value)	Pending Channel x 
 */
static inline uint32_t dmac_get_PENDCH(uint32_t mask)
{
	return (DMAC->PENDCH.reg & mask);
}
/**
 * @brief read pending channel
 * read only bit is set when channel is pending DMA transfer
 * @return uint32_t
 * DMAC_PENDCH_PENDCH0	Pending Channel 0 
 * DMAC_PENDCH_PENDCH1	Pending Channel 1 
 * DMAC_PENDCH_PENDCH2	Pending Channel 2 
 * DMAC_PENDCH_PENDCH3	Pending Channel 3 
 * DMAC_PENDCH_PENDCH4	Pending Channel 4 
 * DMAC_PENDCH_PENDCH5	Pending Channel 5 
 * DMAC_PENDCH_PENDCH6	Pending Channel 6 
 * DMAC_PENDCH_PENDCH7	Pending Channel 7 
 * DMAC_PENDCH_PENDCH8	Pending Channel 8 
 * DMAC_PENDCH_PENDCH9	Pending Channel 9 
 * DMAC_PENDCH_PENDCH10	Pending Channel 10 
 * DMAC_PENDCH_PENDCH11	Pending Channel 11 
 * DMAC_PENDCH_PENDCH12	Pending Channel 12 
 * DMAC_PENDCH_PENDCH13	Pending Channel 13 
 * DMAC_PENDCH_PENDCH14	Pending Channel 14 
 * DMAC_PENDCH_PENDCH15	Pending Channel 15 
 * DMAC_PENDCH_PENDCH16	Pending Channel 16 
 * DMAC_PENDCH_PENDCH17	Pending Channel 17 
 * DMAC_PENDCH_PENDCH18	Pending Channel 18 
 * DMAC_PENDCH_PENDCH19	Pending Channel 19 
 * DMAC_PENDCH_PENDCH20	Pending Channel 20 
 * DMAC_PENDCH_PENDCH21	Pending Channel 21 
 * DMAC_PENDCH_PENDCH22	Pending Channel 22 
 * DMAC_PENDCH_PENDCH23	Pending Channel 23 
 * DMAC_PENDCH_PENDCH24	Pending Channel 24 
 * DMAC_PENDCH_PENDCH25	Pending Channel 25 
 * DMAC_PENDCH_PENDCH26	Pending Channel 26 
 * DMAC_PENDCH_PENDCH27	Pending Channel 27 
 * DMAC_PENDCH_PENDCH28	Pending Channel 28 
 * DMAC_PENDCH_PENDCH29	Pending Channel 29 
 * DMAC_PENDCH_PENDCH30	Pending Channel 30 
 * DMAC_PENDCH_PENDCH31	Pending Channel 31 
 * DMAC_PENDCH_PENDCH(value)	Pending Channel x 
 */
static inline uint32_t dmac_read_PENDCH(void)
{
	return DMAC->PENDCH.reg;
}

/**
 * @brief read active register with mask
 *
 * @return uint32_t
 * DMAC_ACTIVE_LVLEX0	Level 0 Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX1	Level 1 Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX2	Level 2 Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX3	Level 3 Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX(value)	Level x Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX_Msk
 * DMAC_ACTIVE_ID(value)	Active Channel ID 
 * DMAC_ACTIVE_ID_Msk
 * DMAC_ACTIVE_ABUSY	Active Channel Busy 
 * DMAC_ACTIVE_BTCNT(value)	Active Channel Block Transfer Count 
 * DMAC_ACTIVE_BTCNT_Msk
 * read only
 */
static inline uint32_t dmac_get_ACTIVE(uint32_t mask)
{
	return (DMAC->ACTIVE.reg & mask);
}
/**
 * @brief read active register
 *
 * @return uint32_t
 * DMAC_ACTIVE_LVLEX0	Level 0 Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX1	Level 1 Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX2	Level 2 Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX3	Level 3 Channel Trigger Request Executing 
 * DMAC_ACTIVE_LVLEX(value)	Level x Channel Trigger Request Executing 
 * DMAC_ACTIVE_ID(value)	Active Channel ID 
 * DMAC_ACTIVE_ABUSY	Active Channel Busy 
 * DMAC_ACTIVE_BTCNT(value)	Active Channel Block Transfer Count 
 * read only
 */
static inline uint32_t dmac_read_ACTIVE(void)
{
	return DMAC->ACTIVE.reg;
}

/**
 * @brief get the CRC Status Register with mask
 *
 * @param[in] uint8_t mask
 * @return uint8_t
 * DMAC_CRCSTATUS_CRCBUSY	CRC Module Busy 
 * DMAC_CRCSTATUS_CRCZERO	CRC Zero 
 * DMAC_CRCSTATUS_CRCERR	CRC Error 
 */
static inline uint8_t dmac_get_CRCSTATUS(uint8_t mask)
{
	uint8_t tmp;
	tmp = DMAC->CRCSTATUS.reg;
	tmp &= mask;
	return tmp;
}

/**
 * @brief read the CRC Status Register
 *
 * @return uint8_t
 * DMAC_CRCSTATUS_CRCBUSY	CRC Module Busy 
 * DMAC_CRCSTATUS_CRCZERO	CRC Zero 
 * DMAC_CRCSTATUS_CRCERR	CRC Error 
 */
static inline uint8_t dmac_read_CRCSTATUS(void)
{
	return DMAC->CRCSTATUS.reg;
}

/**
 * @brief write destination address to descriptor with data
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @param[in] uint32_t data
 */
static inline void dmacdescriptor_write_DSTADDR(DmacDescriptor *pDMADESC, uint32_t data)
{
	pDMADESC->DSTADDR.reg = data;
}

/**
 * @brief read destination address to descriptor with data from channel index
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @return uint32_t destination address
 */
static inline uint32_t dmacdescriptor_read_DSTADDR(DmacDescriptor *pDMADESC)
{
	return pDMADESC->DSTADDR.reg;
}

/**
 * @brief set block transfer control register with mask
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @param[in] uint16_t mask
 * DMAC_BTCTRL_VALID	Descriptor Valid 
 * DMAC_BTCTRL_EVOSEL_Msk	Block Event Output Selection mask
 * DMAC_BTCTRL_BLOCKACT_Msk	Block Action mask
 * DMAC_BTCTRL_BEATSIZE_Msk	Beat Size mask
 * DMAC_BTCTRL_SRCINC	Source Address Increment Enable 
 * DMAC_BTCTRL_DSTINC	Destination Address Increment Enable 
 * DMAC_BTCTRL_STEPSEL	Step Selection 
 * DMAC_BTCTRL_STEPSIZE_Msk	 Address Increment Step Size mask
 * @return masked block transfer control
 */
static inline void dmacdescriptor_set_BTCTRL(DmacDescriptor *pDMADESC, uint16_t mask)
{
	pDMADESC->BTCTRL.reg |= mask;
}
/**
 * @brief get block transfer control register with mask
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @param[in] uint16_t mask
 * DMAC_BTCTRL_VALID	Descriptor Valid 
 * DMAC_BTCTRL_EVOSEL_Msk	Block Event Output Selection mask
 * DMAC_BTCTRL_BLOCKACT_Msk	Block Action mask
 * DMAC_BTCTRL_BEATSIZE_Msk	Beat Size mask
 * DMAC_BTCTRL_SRCINC	Source Address Increment Enable 
 * DMAC_BTCTRL_DSTINC	Destination Address Increment Enable 
 * DMAC_BTCTRL_STEPSEL	Step Selection 
 * DMAC_BTCTRL_STEPSIZE_Msk	 Address Increment Step Size mask
 * @return masked block transfer control
 */
static inline uint16_t dmacdescriptor_get_BTCTRL(DmacDescriptor *pDMADESC, uint16_t mask)
{
	return (pDMADESC->BTCTRL.reg & mask);
}

/**
 * @brief write to DMA Descriptor in SRAM BTCTRL register
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @param[in] uint16_t data
 * DMAC_BTCTRL_VALID	Descriptor Valid 
 * DMAC_BTCTRL_EVOSEL	Block Event Output Selection 
 *  DMAC_BTCTRL_EVOSEL_DISABLE
 *  DMAC_BTCTRL_EVOSEL_BLOCK  
 *  DMAC_BTCTRL_EVOSEL_BURST  
 * DMAC_BTCTRL_BLOCKACT	Block Action
 *   DMAC_BTCTRL_BLOCKACT_NOACT  
 *   DMAC_BTCTRL_BLOCKACT_INT    
 *   DMAC_BTCTRL_BLOCKACT_SUSPEND
 *   DMAC_BTCTRL_BLOCKACT_BOTH   
 * DMAC_BTCTRL_BEATSIZE	Beat Size 
 *  DMAC_BTCTRL_BEATSIZE_BYTE 
 *  DMAC_BTCTRL_BEATSIZE_HWORD
 *  DMAC_BTCTRL_BEATSIZE_WORD 
 * DMAC_BTCTRL_SRCINC	Source Address Increment Enable 
 * DMAC_BTCTRL_DSTINC	Destination Address Increment Enable 
 * DMAC_BTCTRL_STEPSEL	Step Selection 
 *  DMAC_BTCTRL_STEPSEL_DST
 *  DMAC_BTCTRL_STEPSEL_SRC
 * DMAC_BTCTRL_STEPSIZE	Address Increment Step Size 
 *  DMAC_BTCTRL_STEPSIZE_X1  
 *  DMAC_BTCTRL_STEPSIZE_X2  
 *  DMAC_BTCTRL_STEPSIZE_X4  
 *  DMAC_BTCTRL_STEPSIZE_X8  
 *  DMAC_BTCTRL_STEPSIZE_X16 
 *  DMAC_BTCTRL_STEPSIZE_X32 
 *  DMAC_BTCTRL_STEPSIZE_X64 
 *  DMAC_BTCTRL_STEPSIZE_X128
 */
static inline void dmacdescriptor_write_BTCTRL(DmacDescriptor *pDMADESC, uint16_t data)
{
	pDMADESC->BTCTRL.reg = data;
}
/**
 * @brief clear bits in block transfer control register at channel index
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @param[in] uint16_t mask
 * DMAC_BTCTRL_VALID	Descriptor Valid 
 * DMAC_BTCTRL_EVOSEL_Msk	Block Event Output Selection mask
 * DMAC_BTCTRL_BLOCKACT_Msk	Block Action mask
 * DMAC_BTCTRL_BEATSIZE_Msk	Beat Size mask
 * DMAC_BTCTRL_SRCINC	Source Address Increment Enable 
 * DMAC_BTCTRL_DSTINC	Destination Address Increment Enable 
 * DMAC_BTCTRL_STEPSEL	Step Selection 
 * DMAC_BTCTRL_STEPSIZE_Msk	 Address Increment Step Size mask
 */
static inline void dmacdescriptor_clear_BTCTRL(DmacDescriptor *pDMADESC, uint16_t mask)
{
	pDMADESC->BTCTRL.reg &= ~mask;
}

/**
 * @brief read block transfer control register
 *
 * @param[in] uint8_t channel index into DMA channel descriptor
 * @return channel block transfer control register 
 * DMAC_BTCTRL_VALID	Descriptor Valid 
 * DMAC_BTCTRL_EVOSEL	Block Event Output Selection 
 *  DMAC_BTCTRL_EVOSEL_DISABLE
 *  DMAC_BTCTRL_EVOSEL_BLOCK  
 *  DMAC_BTCTRL_EVOSEL_BURST  
 * DMAC_BTCTRL_BLOCKACT	Block Action
 *   DMAC_BTCTRL_BLOCKACT_NOACT  
 *   DMAC_BTCTRL_BLOCKACT_INT    
 *   DMAC_BTCTRL_BLOCKACT_SUSPEND
 *   DMAC_BTCTRL_BLOCKACT_BOTH   
 * DMAC_BTCTRL_BEATSIZE	Beat Size 
 *  DMAC_BTCTRL_BEATSIZE_BYTE 
 *  DMAC_BTCTRL_BEATSIZE_HWORD
 *  DMAC_BTCTRL_BEATSIZE_WORD 
 * DMAC_BTCTRL_SRCINC	Source Address Increment Enable 
 * DMAC_BTCTRL_DSTINC	Destination Address Increment Enable 
 * DMAC_BTCTRL_STEPSEL	Step Selection 
 *  DMAC_BTCTRL_STEPSEL_DST
 *  DMAC_BTCTRL_STEPSEL_SRC
 * DMAC_BTCTRL_STEPSIZE	Address Increment Step Size 
 *  DMAC_BTCTRL_STEPSIZE_X1  
 *  DMAC_BTCTRL_STEPSIZE_X2  
 *  DMAC_BTCTRL_STEPSIZE_X4  
 *  DMAC_BTCTRL_STEPSIZE_X8  
 *  DMAC_BTCTRL_STEPSIZE_X16 
 *  DMAC_BTCTRL_STEPSIZE_X32 
 *  DMAC_BTCTRL_STEPSIZE_X64 
 *  DMAC_BTCTRL_STEPSIZE_X128
 */
static inline uint16_t dmacdescriptor_read_BTCTRL(DmacDescriptor *pDMADESC)
{
	return pDMADESC->BTCTRL.reg;
}

/**
 * @brief block transfer length
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @param[in] uint16 data length of block
 */
static inline void dmacdescriptor_write_BTCNT(DmacDescriptor *pDMADESC, uint16_t data)
{
	pDMADESC->BTCNT.reg = data;
}

/**
 * @brief read block transfer length
 *
 * @param[in] channel of descriptor
 * @return uint16  length of block
 */
static inline uint16_t dmacdescriptor_read_BTCNT(DmacDescriptor *pDMADESC)
{
	return pDMADESC->BTCNT.reg;
}

/**
 * @brief write source address to descriptor
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @param[in] uint32_t data source address to write to descriptor
 */
static inline void dmacdescriptor_write_SRCADDR(DmacDescriptor *pDMADESC, uint32_t data)
{
	pDMADESC->SRCADDR.reg = data;
}

/**
 * @brief read source address from descriptor
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @return uint32_t data source address
 */
static inline uint32_t dmacdescriptor_read_SRCADDR(DmacDescriptor *pDMADESC)
{
	return pDMADESC->SRCADDR.reg;
}

/**
 * @brief write descriptor address
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @param[in] uint32_t data
 */
static inline void dmacdescriptor_write_DESCADDR(DmacDescriptor *pDMADESC, uint32_t data)
{
	pDMADESC->DESCADDR.reg = data;
}

/**
 * @brief read descriptor address
 *
 * @param[in] DmacDescriptor *pDMADESC pointer to descriptor
 * @return uint32_t data descriptor address pointer
 */
static inline uint32_t dmacdescriptor_read_DESCADDR(DmacDescriptor *pDMADESC)
{
	return pDMADESC->DESCADDR.reg;
}

/**
 * @brief enable interrupts for dma channel by mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t mask 1 enable interrupts, 0 do nothing
 * DMAC_CHINTENSET_TERR	Channel Transfer Error Interrupt Enable 
 * DMAC_CHINTENSET_TCMPL	Channel Transfer Complete Interrupt Enable 
 * DMAC_CHINTENSET_SUSP	Channel Suspend Interrupt Enable 
 */
static inline void dmac_set_CHINTEN(uint8_t index, uint8_t mask)
{
	DMAC->Channel[index].CHINTENSET.reg = mask;
}
/**
 * @brief get enable interrupts for dma channel by mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t mask 1 enable interrupts, 0 do nothing
 * @return uint8_t 
 * DMAC_CHINTENSET_TERR	Channel Transfer Error Interrupt Enable 
 * DMAC_CHINTENSET_TCMPL	Channel Transfer Complete Interrupt Enable 
 * DMAC_CHINTENSET_SUSP	Channel Suspend Interrupt Enable 
 */
static inline uint8_t dmac_get_CHINTEN(uint8_t index, uint8_t mask)
{
	return (DMAC->Channel[index].CHINTENSET.reg & mask);
}

/**
 * @brief read interrupt enable register
 *
 * @param[in] uint8_t channel index
 * @return uint8_t enabled channel interrupt register
 * DMAC_CHINTENSET_TERR	Channel Transfer Error Interrupt Enable 
 * DMAC_CHINTENSET_TCMPL	Channel Transfer Complete Interrupt Enable 
 * DMAC_CHINTENSET_SUSP	Channel Suspend Interrupt Enable 
 */
static inline uint8_t dmac_read_CHINTEN(uint8_t index)
{
	return DMAC->Channel[index].CHINTENSET.reg;
}
/**
 * @brief write to set and clear interrupt enable
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t data interrupt bits to set and clear interrupts
 * DMAC_CHINTENSET_TERR	Channel Transfer Error Interrupt Enable 
 * DMAC_CHINTENSET_TCMPL	Channel Transfer Complete Interrupt Enable 
 * DMAC_CHINTENSET_SUSP	Channel Suspend Interrupt Enable 
 */
static inline void dmac_write_CHINTEN(uint8_t index, uint8_t data)
{
	DMAC->Channel[index].CHINTENSET.reg = data;
	DMAC->Channel[index].CHINTENCLR.reg = ~data;
}
/**
 * @brief disable interrupts for dma channel by mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t mask 1 disable interrupts, 0 do nothing
 * DMAC_CHINTENCLR_TERR	Channel Transfer Error Interrupt Enable 
 * DMAC_CHINTENCLR_TCMPL	Channel Transfer Complete Interrupt Enable 
 * DMAC_CHINTENCLR_SUSP	Channel Suspend Interrupt Enable 
 */
static inline void dmac_clear_CHINTEN(uint8_t index, uint8_t mask)
{
	DMAC->Channel[index].CHINTENCLR.reg = mask;
}

/**
 * @brief clear channel interrupt flag
 *
 * @param[in] uint8_t channel index
 * @return uint8_t interrupt flag mask to clear
 * DMAC_CHINTFLAG_TERR	Channel Transfer Error 
 * DMAC_CHINTFLAG_TCMPL	Channel Transfer Complete 
 * DMAC_CHINTFLAG_SUSP	Channel Suspend 
 */
static inline uint8_t dmac_get_CHINTFLAG(uint8_t index, uint8_t mask)
{
	return DMAC->Channel[index].CHINTFLAG.reg & mask;
}

/**
 * @brief read channel interrupt flag
 *
 * @param[in] uint8_t channel index
 * @return uint8_t interrupt flags for channel
 * DMAC_CHINTFLAG_TERR	Channel Transfer Error 
 * DMAC_CHINTFLAG_TCMPL	Channel Transfer Complete 
 * DMAC_CHINTFLAG_SUSP	Channel Suspend 
 */
static inline uint8_t dmac_read_CHINTFLAG(uint8_t index)
{
	return DMAC->Channel[index].CHINTFLAG.reg;
}
/**
 * @brief clear channel interrupt flag
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t interrupt flag mask to clear
 * DMAC_CHINTFLAG_TERR	Channel Transfer Error 
 * DMAC_CHINTFLAG_TCMPL	Channel Transfer Complete 
 * DMAC_CHINTFLAG_SUSP	Channel Suspend 
 */
static inline void dmac_clear_CHINTFLAG(uint8_t index, uint8_t mask)
{
	DMAC->Channel[index].CHINTFLAG.reg = mask;
}

/**
 * @brief set channel control A with mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint32_t mask
 * DMAC_CHCTRLA_SWRST	Channel Software Reset 
 * DMAC_CHCTRLA_ENABLE	Channel Enable 
 * DMAC_CHCTRLA_RUNSTDBY	Channel Run in Standby 
 * DMAC_CHCTRLA_TRIGSRC(value)	Trigger Source 
 * DMAC_CHCTRLA_TRIGACT(value)	Trigger Action 
 * DMAC_CHCTRLA_TRIGACT_BLOCK
 * DMAC_CHCTRLA_TRIGACT_BURST
 * DMAC_CHCTRLA_TRIGACT_TRANSACTION
 * DMAC_CHCTRLA_BURSTLEN(value)	Burst Length
 * DMAC_CHCTRLA_BURSTLEN_SINGLE
 * DMAC_CHCTRLA_BURSTLEN_2BEAT 
 * DMAC_CHCTRLA_BURSTLEN_3BEAT 
 * DMAC_CHCTRLA_BURSTLEN_4BEAT 
 * DMAC_CHCTRLA_BURSTLEN_5BEAT 
 * DMAC_CHCTRLA_BURSTLEN_6BEAT 
 * DMAC_CHCTRLA_BURSTLEN_7BEAT 
 * DMAC_CHCTRLA_BURSTLEN_8BEAT 
 * DMAC_CHCTRLA_BURSTLEN_9BEAT 
 * DMAC_CHCTRLA_BURSTLEN_10BEAT
 * DMAC_CHCTRLA_BURSTLEN_11BEAT
 * DMAC_CHCTRLA_BURSTLEN_12BEAT
 * DMAC_CHCTRLA_BURSTLEN_13BEAT
 * DMAC_CHCTRLA_BURSTLEN_14BEAT
 * DMAC_CHCTRLA_BURSTLEN_15BEAT
 * DMAC_CHCTRLA_BURSTLEN_16BEAT
 * DMAC_CHCTRLA_THRESHOLD(value) FIFO Threshold 
 * DMAC_CHCTRLA_THRESHOLD_1BEAT 
 * DMAC_CHCTRLA_THRESHOLD_2BEATS
 * DMAC_CHCTRLA_THRESHOLD_4BEATS
 * DMAC_CHCTRLA_THRESHOLD_8BEATS 
 */
static inline void dmac_set_CHCTRLA(uint8_t index, uint32_t mask)
{
	DMAC->Channel[index].CHCTRLA.reg |= mask;
}
/**
 * @brief clear channel control A with mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint32_t mask
 * DMAC_CHCTRLA_SWRST	Channel Software Reset 
 * DMAC_CHCTRLA_ENABLE	Channel Enable 
 * DMAC_CHCTRLA_RUNSTDBY	Channel Run in Standby 
 * DMAC_CHCTRLA_TRIGSRC(value)	Trigger Source 
 * DMAC_CHCTRLA_TRIGACT(value)	Trigger Action 
 * DMAC_CHCTRLA_TRIGACT_BLOCK
 * DMAC_CHCTRLA_TRIGACT_BURST
 * DMAC_CHCTRLA_TRIGACT_TRANSACTION
 * DMAC_CHCTRLA_BURSTLEN(value)	Burst Length
 * DMAC_CHCTRLA_BURSTLEN_SINGLE
 * DMAC_CHCTRLA_BURSTLEN_2BEAT 
 * DMAC_CHCTRLA_BURSTLEN_3BEAT 
 * DMAC_CHCTRLA_BURSTLEN_4BEAT 
 * DMAC_CHCTRLA_BURSTLEN_5BEAT 
 * DMAC_CHCTRLA_BURSTLEN_6BEAT 
 * DMAC_CHCTRLA_BURSTLEN_7BEAT 
 * DMAC_CHCTRLA_BURSTLEN_8BEAT 
 * DMAC_CHCTRLA_BURSTLEN_9BEAT 
 * DMAC_CHCTRLA_BURSTLEN_10BEAT
 * DMAC_CHCTRLA_BURSTLEN_11BEAT
 * DMAC_CHCTRLA_BURSTLEN_12BEAT
 * DMAC_CHCTRLA_BURSTLEN_13BEAT
 * DMAC_CHCTRLA_BURSTLEN_14BEAT
 * DMAC_CHCTRLA_BURSTLEN_15BEAT
 * DMAC_CHCTRLA_BURSTLEN_16BEAT
 * DMAC_CHCTRLA_THRESHOLD(value) FIFO Threshold 
 * DMAC_CHCTRLA_THRESHOLD_1BEAT 
 * DMAC_CHCTRLA_THRESHOLD_2BEATS
 * DMAC_CHCTRLA_THRESHOLD_4BEATS
 * DMAC_CHCTRLA_THRESHOLD_8BEATS 
 */
static inline void dmac_clear_CHCTRLA(uint8_t index, uint32_t mask)
{
	DMAC->Channel[index].CHCTRLA.reg &= ~mask;
}
/**
 * @brief get channel control A with mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint32_t mask
 * DMAC_CHCTRLA_SWRST	Channel Software Reset 
 * DMAC_CHCTRLA_ENABLE	Channel Enable 
 * DMAC_CHCTRLA_RUNSTDBY	Channel Run in Standby 
 * DMAC_CHCTRLA_TRIGSRC(value)	Trigger Source 
 * DMAC_CHCTRLA_TRIGACT(value)	Trigger Action 
 * DMAC_CHCTRLA_TRIGACT_BLOCK
 * DMAC_CHCTRLA_TRIGACT_BURST
 * DMAC_CHCTRLA_TRIGACT_TRANSACTION
 * DMAC_CHCTRLA_BURSTLEN(value)	Burst Length
 * DMAC_CHCTRLA_BURSTLEN_SINGLE
 * DMAC_CHCTRLA_BURSTLEN_2BEAT 
 * DMAC_CHCTRLA_BURSTLEN_3BEAT 
 * DMAC_CHCTRLA_BURSTLEN_4BEAT 
 * DMAC_CHCTRLA_BURSTLEN_5BEAT 
 * DMAC_CHCTRLA_BURSTLEN_6BEAT 
 * DMAC_CHCTRLA_BURSTLEN_7BEAT 
 * DMAC_CHCTRLA_BURSTLEN_8BEAT 
 * DMAC_CHCTRLA_BURSTLEN_9BEAT 
 * DMAC_CHCTRLA_BURSTLEN_10BEAT
 * DMAC_CHCTRLA_BURSTLEN_11BEAT
 * DMAC_CHCTRLA_BURSTLEN_12BEAT
 * DMAC_CHCTRLA_BURSTLEN_13BEAT
 * DMAC_CHCTRLA_BURSTLEN_14BEAT
 * DMAC_CHCTRLA_BURSTLEN_15BEAT
 * DMAC_CHCTRLA_BURSTLEN_16BEAT
 * DMAC_CHCTRLA_THRESHOLD(value) FIFO Threshold 
 * DMAC_CHCTRLA_THRESHOLD_1BEAT 
 * DMAC_CHCTRLA_THRESHOLD_2BEATS
 * DMAC_CHCTRLA_THRESHOLD_4BEATS
 * DMAC_CHCTRLA_THRESHOLD_8BEATS 
 * @return uint32_T channel control register
 */
static inline uint32_t dmac_get_CHCTRLA(uint8_t index, uint32_t mask)
{
	return (DMAC->Channel[index].CHCTRLA.reg & mask);
}

/**
 * @brief write channel control A 
 *
 * @param[in] uint8_t channel index
 * @param[in] uint32_t mask
 * DMAC_CHCTRLA_SWRST	Channel Software Reset 
 * DMAC_CHCTRLA_ENABLE	Channel Enable 
 * DMAC_CHCTRLA_RUNSTDBY	Channel Run in Standby 
 * DMAC_CHCTRLA_TRIGSRC(value)	Trigger Source 
 * DMAC_CHCTRLA_TRIGACT(value)	Trigger Action 
 * DMAC_CHCTRLA_TRIGACT_BLOCK
 * DMAC_CHCTRLA_TRIGACT_BURST
 * DMAC_CHCTRLA_TRIGACT_TRANSACTION
 * DMAC_CHCTRLA_BURSTLEN(value)	Burst Length
 * DMAC_CHCTRLA_BURSTLEN_SINGLE
 * DMAC_CHCTRLA_BURSTLEN_2BEAT 
 * DMAC_CHCTRLA_BURSTLEN_3BEAT 
 * DMAC_CHCTRLA_BURSTLEN_4BEAT 
 * DMAC_CHCTRLA_BURSTLEN_5BEAT 
 * DMAC_CHCTRLA_BURSTLEN_6BEAT 
 * DMAC_CHCTRLA_BURSTLEN_7BEAT 
 * DMAC_CHCTRLA_BURSTLEN_8BEAT 
 * DMAC_CHCTRLA_BURSTLEN_9BEAT 
 * DMAC_CHCTRLA_BURSTLEN_10BEAT
 * DMAC_CHCTRLA_BURSTLEN_11BEAT
 * DMAC_CHCTRLA_BURSTLEN_12BEAT
 * DMAC_CHCTRLA_BURSTLEN_13BEAT
 * DMAC_CHCTRLA_BURSTLEN_14BEAT
 * DMAC_CHCTRLA_BURSTLEN_15BEAT
 * DMAC_CHCTRLA_BURSTLEN_16BEAT
 * DMAC_CHCTRLA_THRESHOLD(value) FIFO Threshold 
 * DMAC_CHCTRLA_THRESHOLD_1BEAT 
 * DMAC_CHCTRLA_THRESHOLD_2BEATS
 * DMAC_CHCTRLA_THRESHOLD_4BEATS
 * DMAC_CHCTRLA_THRESHOLD_8BEATS 
 */
static inline void dmac_write_CHCTRLA(uint8_t index, uint32_t data)
{
	DMAC->Channel[index].CHCTRLA.reg = data;
}

/**
 * @brief read channel control A index by channel number
 *
 * @param[in] uint8_t channel index
 * @param[in] uint32_t data
 */
static inline uint32_t dmac_read_CHCTRLA(uint8_t index)
{
	return DMAC->Channel[index].CHCTRLA.reg;
}

/**
 * @brief write channel control B
 *
 * @param[in] uint8_t index channel 
 * @param[in] uint8_t data
 * DMAC_CHCTRLB_CMD_NOACT  
 * DMAC_CHCTRLB_CMD_SUSPEND
 * DMAC_CHCTRLB_CMD_RESUME 
 */
static inline void dmac_write_CHCTRLB(uint8_t index, uint8_t data)
{
	DMAC->Channel[index].CHCTRLB.reg = data;
}

/**
 * @brief read channel control B
 *
 * @param[in] uint8_t index channel 
 * @return uint8_t
 * DMAC_CHCTRLB_CMD_NOACT  
 * DMAC_CHCTRLB_CMD_SUSPEND
 * DMAC_CHCTRLB_CMD_RESUME 
 */
static inline uint8_t dmac_read_CHCTRLB(uint8_t index)
{
	return DMAC->Channel[index].CHCTRLB.reg;
}

/**
 * @brief write channel priority level
 *
 * @param[in] uint8_t channel number
 * @param[in] uint8_t channel priority level
 * DMAC_CHPRILVL_PRILVL(value) 
 * DMAC_CHPRILVL_PRILVL_LVL0    Channel Priority Level 0 (Lowest Level) 
 * DMAC_CHPRILVL_PRILVL_LVL1    Channel Priority Level 1             
 * DMAC_CHPRILVL_PRILVL_LVL2    Channel Priority Level 2             
 * DMAC_CHPRILVL_PRILVL_LVL3    Channel Priority Level 3             
 * DMAC_CHPRILVL_PRILVL_LVL4    Channel Priority Level 4             
 * DMAC_CHPRILVL_PRILVL_LVL5    Channel Priority Level 5             
 * DMAC_CHPRILVL_PRILVL_LVL6    Channel Priority Level 6             
 * DMAC_CHPRILVL_PRILVL_LVL7    Channel Priority Level 7 (Highest Level)
 */
static inline void dmac_write_CHPRILVL(uint8_t index, uint8_t data)
{
	DMAC->Channel[index].CHPRILVL.reg = data;
}

/**
 * @brief read channel priority level
 *
 * @param[in] uint8_t channel number
 * @return uint8_t read channel priority level
 * DMAC_CHPRILVL_PRILVL(value) 
 * DMAC_CHPRILVL_PRILVL_LVL0    Channel Priority Level 0 (Lowest Level) 
 * DMAC_CHPRILVL_PRILVL_LVL1    Channel Priority Level 1             
 * DMAC_CHPRILVL_PRILVL_LVL2    Channel Priority Level 2             
 * DMAC_CHPRILVL_PRILVL_LVL3    Channel Priority Level 3             
 * DMAC_CHPRILVL_PRILVL_LVL4    Channel Priority Level 4             
 * DMAC_CHPRILVL_PRILVL_LVL5    Channel Priority Level 5             
 * DMAC_CHPRILVL_PRILVL_LVL6    Channel Priority Level 6             
 * DMAC_CHPRILVL_PRILVL_LVL7    Channel Priority Level 7 (Highest Level)
 */
static inline uint8_t dmac_read_CHPRILVL(uint8_t index)
{
	return DMAC->Channel[index].CHPRILVL.reg;
}

/**
 * @brief Set channel event control register with mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t mask
 * DMAC_CHEVCTRL_EVACT		Channel Event Input Action 
 *  DMAC_CHEVCTRL_EVACT_NOACT  
 *  DMAC_CHEVCTRL_EVACT_TRIG   
 *  DMAC_CHEVCTRL_EVACT_CTRIG  
 *  DMAC_CHEVCTRL_EVACT_CBLOCK 
 *  DMAC_CHEVCTRL_EVACT_SUSPEND
 *  DMAC_CHEVCTRL_EVACT_RESUME 
 *  DMAC_CHEVCTRL_EVACT_SSKIP  
 *  DMAC_CHEVCTRL_EVACT_INCPRI 
 * DMAC_CHEVCTRL_EVOMODE	Channel Event Output Mode 
 *  DMAC_CHEVCTRL_EVOMODE_DEFAULT
 *  DMAC_CHEVCTRL_EVOMODE_TRIGACT
 * DMAC_CHEVCTRL_EVIE		Channel Event Input Enable 
 * DMAC_CHEVCTRL_EVOE		Channel Event Output Enable 
 */
static inline void dmac_set_CHEVCTRL(uint8_t index, uint8_t mask)
{
	DMAC->Channel[index].CHEVCTRL.reg |= mask;
}

/**
 * @brief get channel event control register with mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t mask
 * @return channel event control register masked
 * DMAC_CHEVCTRL_EVACT		Channel Event Input Action 
 *  DMAC_CHEVCTRL_EVACT_NOACT  
 *  DMAC_CHEVCTRL_EVACT_TRIG   
 *  DMAC_CHEVCTRL_EVACT_CTRIG  
 *  DMAC_CHEVCTRL_EVACT_CBLOCK 
 *  DMAC_CHEVCTRL_EVACT_SUSPEND
 *  DMAC_CHEVCTRL_EVACT_RESUME 
 *  DMAC_CHEVCTRL_EVACT_SSKIP  
 *  DMAC_CHEVCTRL_EVACT_INCPRI 
 * DMAC_CHEVCTRL_EVOMODE	Channel Event Output Mode 
 *  DMAC_CHEVCTRL_EVOMODE_DEFAULT
 *  DMAC_CHEVCTRL_EVOMODE_TRIGACT
 * DMAC_CHEVCTRL_EVIE		Channel Event Input Enable 
 * DMAC_CHEVCTRL_EVOE		Channel Event Output Enable 
 */
static inline uint8_t dmac_get_CHEVCTRL(uint8_t index, uint8_t mask)
{
	return (DMAC->Channel[index].CHEVCTRL.reg & mask);
}

/**
 * @brief write channel event control register with mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t data
 * DMAC_CHEVCTRL_EVACT		Channel Event Input Action 
 *  DMAC_CHEVCTRL_EVACT_NOACT  
 *  DMAC_CHEVCTRL_EVACT_TRIG   
 *  DMAC_CHEVCTRL_EVACT_CTRIG  
 *  DMAC_CHEVCTRL_EVACT_CBLOCK 
 *  DMAC_CHEVCTRL_EVACT_SUSPEND
 *  DMAC_CHEVCTRL_EVACT_RESUME 
 *  DMAC_CHEVCTRL_EVACT_SSKIP  
 *  DMAC_CHEVCTRL_EVACT_INCPRI 
 * DMAC_CHEVCTRL_EVOMODE	Channel Event Output Mode 
 *  DMAC_CHEVCTRL_EVOMODE_DEFAULT
 *  DMAC_CHEVCTRL_EVOMODE_TRIGACT
 * DMAC_CHEVCTRL_EVIE		Channel Event Input Enable 
 * DMAC_CHEVCTRL_EVOE		Channel Event Output Enable 
 */
static inline void dmac_write_CHEVCTRL(uint8_t index, uint8_t data)
{
	DMAC->Channel[index].CHEVCTRL.reg = data;
}
/**
 * @brief clear channel event control register with mask
 *
 * @param[in] uint8_t channel index
 * @param[in] uint8_t data
 * DMAC_CHEVCTRL_EVACT		Channel Event Input Action 
 *  DMAC_CHEVCTRL_EVACT_NOACT  
 *  DMAC_CHEVCTRL_EVACT_TRIG   
 *  DMAC_CHEVCTRL_EVACT_CTRIG  
 *  DMAC_CHEVCTRL_EVACT_CBLOCK 
 *  DMAC_CHEVCTRL_EVACT_SUSPEND
 *  DMAC_CHEVCTRL_EVACT_RESUME 
 *  DMAC_CHEVCTRL_EVACT_SSKIP  
 *  DMAC_CHEVCTRL_EVACT_INCPRI 
 * DMAC_CHEVCTRL_EVOMODE	Channel Event Output Mode 
 *  DMAC_CHEVCTRL_EVOMODE_DEFAULT
 *  DMAC_CHEVCTRL_EVOMODE_TRIGACT
 * DMAC_CHEVCTRL_EVIE		Channel Event Input Enable 
 * DMAC_CHEVCTRL_EVOE		Channel Event Output Enable 
 */
static inline void dmac_clear_CHEVCTRL(uint8_t index, uint8_t mask)
{
	DMAC->Channel[index].CHEVCTRL.reg &= ~mask;
}

/**
 * @brief read channel event control register with mask
 *
 * @param[in] uint8_t channel index
 * @return uint8_t 
 * DMAC_CHEVCTRL_EVACT		Channel Event Input Action 
 *  DMAC_CHEVCTRL_EVACT_NOACT  
 *  DMAC_CHEVCTRL_EVACT_TRIG   
 *  DMAC_CHEVCTRL_EVACT_CTRIG  
 *  DMAC_CHEVCTRL_EVACT_CBLOCK 
 *  DMAC_CHEVCTRL_EVACT_SUSPEND
 *  DMAC_CHEVCTRL_EVACT_RESUME 
 *  DMAC_CHEVCTRL_EVACT_SSKIP  
 *  DMAC_CHEVCTRL_EVACT_INCPRI 
 * DMAC_CHEVCTRL_EVOMODE	Channel Event Output Mode 
 *  DMAC_CHEVCTRL_EVOMODE_DEFAULT
 *  DMAC_CHEVCTRL_EVOMODE_TRIGACT
 * DMAC_CHEVCTRL_EVIE		Channel Event Input Enable 
 * DMAC_CHEVCTRL_EVOE		Channel Event Output Enable 
 */
static inline uint8_t dmac_read_CHEVCTRL(uint8_t index)
{
	return DMAC->Channel[index].CHEVCTRL.reg;
}

/**
 * @brief get channel status
 *
 * @param[in] uint8_t index channel 
 * @param[in] uint8_t mask
 * @return channel status
 * DMAC_CHSTATUS_PEND	Channel Pending 
 * DMAC_CHSTATUS_BUSY	Channel Busy 
 * DMAC_CHSTATUS_FERR	Channel Fetch Error 
 * DMAC_CHSTATUS_CRCERR	Channel CRC Error 
 */
static inline uint8_t dmac_get_CHSTATUS(uint8_t index, uint8_t mask)
{
	uint8_t tmp;
	tmp = DMAC->Channel[index].CHSTATUS.reg;
	tmp &= mask;
	return tmp;
}
/**
 * @brief clear channel status bit '1' = clear '0' = do nothing
 * only CRCERR can be cleared
 *
 * @param[in] uint8_t index channel
 * @param[in] uint8_t mask
 * DMAC_CHSTATUS_PEND	Channel Pending 
 * DMAC_CHSTATUS_BUSY	Channel Busy 
 * DMAC_CHSTATUS_FERR	Channel Fetch Error 
 * DMAC_CHSTATUS_CRCERR	Channel CRC Error 
 */
static inline void dmac_clear_CHSTATUS(uint8_t index, uint8_t mask)
{
	DMAC->Channel[index].CHSTATUS.reg = mask;
}
/**
 * @brief read channel status
 *
 * @param[in] uint8_t index channel
 * @return uint8_t
 * DMAC_CHSTATUS_PEND	Channel Pending 
 * DMAC_CHSTATUS_BUSY	Channel Busy 
 * DMAC_CHSTATUS_FERR	Channel Fetch Error 
 * DMAC_CHSTATUS_CRCERR	Channel CRC Error 
 */
static inline uint8_t dmac_read_CHSTATUS(uint8_t index)
{
	return DMAC->Channel[index].CHSTATUS.reg;
}

#endif /* _DMAC_H_ */
