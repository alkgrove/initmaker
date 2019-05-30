/*
 *  @file qspi_flash.h
 *  QSPI Flash Memory Driver
 *  Copyright © Alkgrove 10/14/2018
 *  ATSAMD51
 * @par Redistribution and use in source and binary forms, with or without modification, are permitted 
 * provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions 
 * and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions 
 * and the following disclaimer in the documentation and/or other materials provided with the 
 * distribution. 
 * 3. Neither the name of the copyright holder nor the names of its contributors may be 
 * used to endorse or promote products derived from this software without specific prior written 
 * permission.
 * 
 * @par THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND 
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER 
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF 
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */



#ifndef __QSPI_FLASH_H__
#define __QSPI_FLASH_H__

#define W25Q128JV
#ifdef W25Q128JV
#define PAGE_SIZE 256
#define SECTOR_ERASE_SIZE (PAGE_SIZE * 16)
#define BLOCK_ERASE_SIZE (PAGE_SIZE * 128)
#define LARGEBLOCK_ERASE_SIZE (PAGE_SIZE * 256)
#define CHIP_SIZE (PAGE_SIZE * 65536)
#endif

/* Quad Flash Commands */
#define CMD_WRITE_ENABLE 0x06
#define CMD_VOLATILE_SR_WRITE_ENABLE 0x50
#define CMD_WRITE_DISABLE 0x04
#define CMD_MANUF_ID 0x90
#define CMD_JEDEC_ID 0x9F
#define CMD_UNIQUE_ID 0x4B
#define CMD_READ_DATA 0x03
#define CMD_FAST_READ 0x0B
#define CMD_FAST_READ_QUADIO 0xEB
#define CMD_PAGE_PROGRAM 0x02
#define CMD_SECTOR_ERASE 0x20
#define CMD_BLOCK_ERASE32 0x52
#define CMD_BLOCK_ERASE64 0xD8
#define CMD1_CHIP_ERASE 0xC7
#define CMD2_CHIP_ERASE 0x60
#define CMD_READ_STATUS1 0x05
#define CMD_READ_STATUS2 0x35
#define CMD_READ_STATUS3 0x15
#define CMD_WRITE_STATUS1 0x01
#define CMD_WRITE_STATUS2 0x31
#define CMD_WRITE_STATUS3 0x11
#define CMD_FAST_READ_QUADOUT 0x6B
#define CMD_ENTER_QPI 0x38
#define CMD_ENABLE_RESET 0x66
#define CMD_RESET 0x99

#define CMD_SET_READ_PARAMETERS 0xC0
#define CMD_EXIT_QPI 0xFF


/* Status 1 */
#define STAT1_BUSY (1 << 0)
#define STAT1_WEL (1 << 1)
#define STAT1_BP0 (1 << 2)
#define STAT1_BP1 (1 << 3)
#define STAT1_BP2 (1 << 4)
#define STAT1_TB (1 << 5)
#define STAT1_SEC (1 << 6)
#define STAT1_SRP (1 << 7)

/* Status 2 */
#define STAT2_SRL (1 << 0)
#define STAT2_QE (1 << 1)
#define STAT2_LB1 (1 << 3)
#define STAT2_LB2 (1 << 4)
#define STAT2_LB3 (1 << 5)
#define STAT2_CMP (1 << 6)
#define STAT2_SUS (1 << 7)

/* Status 3 */
#define STAT3_WPS (1 << 2)
#define STAT3_DRV0 (1 << 5)
#define STAT3_DRV1 (1 << 6)
#define STAT3_HOLD (1 << 7)

/* QPI Read Parameters Control */

#define READ_PARAM_CLK2 (0 << 4)
#define READ_PARAM_CLK4 (1 << 4)
#define READ_PARAM_CLK6 (2 << 4)
#define READ_PARAM_CLK8 (3 << 4)
#define READ_PARAM_WRAP8 (0)
#define READ_PARAM_WRAP16 (1)
#define READ_PARAM_WRAP32 (2)
#define READ_PARAM_WRAP64 (3)

/**
 * @brief initialize qspi flash
 * This enables quad mode if it isn't already enabled
 */
void qspi_flash_init_device(void);

/**
 * @brief return when flash not busy
 *
 */
 void qspi_wait_flash_ready(void);
 

/**
 * @brief send command to flash
 *
 * @param[in] uint8_t cmd
 */
void qspi_flash_command(uint8_t cmd);

/**
 * @brief send sector command to flash
 *
 * @param[in] uint8_t cmd
 * @param[in] uint32_t adr
 */
void qspi_flash_sector_command(uint8_t cmd, uint32_t adr);

/**
 * @brief write command to flash
 *
 * @param[in] uint8_t cmd
 * @param[in] uint8_t* data
 * @param[in] uint32_t len
 */
void qspi_flash_write_command(uint8_t cmd, uint8_t* data, uint32_t len);

/**
 * @brief read command data from flash
 *
 * @param[in] uint8_t cmd
 * @param[in] uint8_t* response
 * @param[in] uint32_t len
 */
void qspi_flash_read_command(uint8_t cmd, uint8_t* response, uint32_t len);

/**
 * @brief read command in QPI mode
 *
 * @param[in] uint8_t cmd
 * @param[in] uint8_t* response
 * @param[in] uint32_t len
 */
void qpi_flash_read_command(uint8_t cmd, uint8_t* response, uint32_t len);

/**
 * @brief write command in QPI mode
 *
 * @param[in] uint8_t cmd
 * @param[in] uint8_t* data
 * @param[in] uint32_t len
 */
void qpi_flash_write_command(uint8_t cmd, uint8_t* data, uint32_t len);

/**
 * @brief write data to flash
 *
 * @param[in] uint32_t adr
 * @param[in] uint8_t* data
 * @param[in] uint32_t len
 */
void qspi_flash_write_data(uint32_t adr, uint8_t* data, uint32_t len);

/**
 * @brief read data from flash
 *
 * @param[in] uint32_t adr
 * @param[in] uint8_t* data
 * @param[in] uint32_t len
 */
void qspi_flash_read_data(uint32_t adr, uint8_t* data, uint32_t len);


/**
 * @brief send command to flash using QPI mode
 *
 * @param[in] uint8_t cmd
 **/
void qpi_flash_command(uint8_t cmd);

/**
 * @brief send command and address to flash using QPI mode
 *
 * @param[in] uint8_t cmd
 * @param[in] uint32_t adr
 **/
void qpi_flash_sector_command(uint8_t cmd, uint32_t adr);

/**
 * @brief write data in QPI mode
 *
 * @param[in] uint32_t adr
 * @param[in] uint8_t* data
 * @param[in] uint32_t len
 */
void qpi_flash_write_data(uint32_t adr, uint8_t* data, uint32_t len);

/**
 * @brief read data in QPI mode
 *
 * @param[in] uint32_t adr
 * @param[in] uint8_t* data
 * @param[in] uint32_t len
 */
void qpi_flash_read_data(uint32_t adr, uint8_t* data, uint32_t len);

/**
 * @brief wait for flash not busy in QPI mode
 **/
void qpi_wait_flash_ready(void);

/**
 * @brief enter QPI mode and set read parameters
 * based on QSPI clock
 **/
void enter_qpi_mode(void);

/**
 * @brief exit QPI mode and go back to QSPI mode
 **/
void exit_qpi_mode(void);


#endif // __QSPI_FLASH_H__