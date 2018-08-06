/*
 * @file sd.h
 * @brief SD Card Driver for SAMD51
 * 
 * @note Copyright © Alkgrove 2018
 * @author Robert Alkire 
 * @date 05/15/18
 *
 * @par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * @par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * @par
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __SD_H__
#define __SD_H__

/** @name Card State */
/** @{ */
typedef struct {
	uint32_t sectors;  /**< Capacity in bytes */
	uint32_t clock;      /**< Accepted Cloc Rate in Hz */
	uint16_t rca; 			 /**< Relative Card Address */
	uint8_t type;			 /**< Type of Card */
	uint8_t version;		 /**< Version of Card */
	uint8_t bus_width;		 /**< Acceptable Bus Width (1 or 4) */
	bool high_speed;		 /**< Turbo mode */
	bool card_detect;		 /**< Card Detect True if card installed */
	bool need_init;			 /**< Card installed but not initialized if true */
} sdhc_state_t;
/** @} */

/** @name Card Types */
/** @{ */
#define CARD_TYPE_UNKNOWN (0)   /**< Unknown type card */
#define CARD_TYPE_SD (1 << 0)   /**< SD card */
#define CARD_TYPE_MMC (1 << 1)  /**< MMC card */
#define CARD_TYPE_SDIO (1 << 2) /**< SDIO card */
#define CARD_TYPE_HC (1 << 3)   /**< High capacity card */
/** SD combo card (io + memory) */
#define CARD_TYPE_SD_COMBO (CARD_TYPE_SD | CARD_TYPE_SDIO)
/** @} */

/** @name Card Versions */
/** @{ */
#define CARD_VER_UNKNOWN (0)    /**< Unknown card version */
#define CARD_VER_SD_1_0 (0x10)  /**< SD version 1.0 and 1.01 */
#define CARD_VER_SD_1_10 (0x1A) /**< SD version 1.10 */
#define CARD_VER_SD_2_0 (0X20)  /**< SD version 2.00 */
#define CARD_VER_SD_3_0 (0X30)  /**< SD version 3.0X */
#define CARD_VER_MMC_1_2 (0x12) /**< MMC version 1.2 */
#define CARD_VER_MMC_1_4 (0x14) /**< MMC version 1.4 */
#define CARD_VER_MMC_2_2 (0x22) /**< MMC version 2.2 */
#define CARD_VER_MMC_3 (0x30)   /**< MMC version 3 */
#define CARD_VER_MMC_4 (0x40)   /**< MMC version 4 */
/** @} */

/** @name Flags used to define MCI parser for SD/MMC command */
/** @{ */
#define MCI_RESP_PRESENT (1ul << 8) /**< Have response */
#define MCI_RESP_136 (1ul << 11) /**< 136 bit response */
#define MCI_RESP_CRC (1ul << 12) /**< Expect valid crc */
#define MCI_RESP_BUSY (1ul << 13) /**< Card may send busy */
#define MCI_CMD_OPENDRAIN (1ul << 14) /**< Open drain for a braodcast command */
#define MCI_CMD_WRITE (1ul << 15) /**< To signal a data write operation */
#define MCI_CMD_SDIO_BYTE (1ul << 16) /**< To signal a SDIO tranfer in multi byte mode */
#define MCI_CMD_SDIO_BLOCK (1ul << 17) /**< To signal a SDIO tranfer in block mode */
#define MCI_CMD_STREAM (1ul << 18) /**< To signal a data transfer in stream mode */
#define MCI_CMD_SINGLE_BLOCK (1ul << 19) /**< To signal a data transfer in single block mode */
#define MCI_CMD_MULTI_BLOCK (1ul << 20) /**< To signal a data transfer in multi block mode */
/** @} */

/** This SD stack uses the maximum block size authorized (512 bytes) */
#define SD_MMC_BLOCK_SIZE 512
#define SDHC_SLOW_CLOCK 400000

/** @name Error Codes */
/** @{ */
#define SDHC_OK 0
#define SDHC_ERR_CARD_NOT_PRESENT 1
#define SDHC_ERR_BAD_CARD 2
#define SDHC_ERR_SDIO_NOT_SUPPORTED 3
#define SDHC_ERR_BUSY 4

/** @} */

/**
 * @brief
 *
 * @param[in] state - sdhc_state_t *
 * @return return error code
 */
int sdhc_init(sdhc_state_t *state);

/**
 * @brief
 *
 * @param[in] cmd - uint32_t 
 * @param[in] arg - uint32_t 
 * @return true if success, false if failed 
 */
bool sdhc_send_cmd(uint32_t cmd, uint32_t arg);

/**
 * @brief
 *
 * @param[in] fsdhc - uint32_t 
 */
void sdhc_set_speed(uint32_t fsdhc);

/**
 * @brief
 *
 * @param[in] state - sdhc_state_t *
 */
void sdhc_set_hc(sdhc_state_t *state);

/**
 * @brief sdhc_read_blocks
 * read 512 byte blocks for block_count blocks from SD/MMC card with address
 * to filebuffer pointed to by dst
 * @param[in] state - sdhc_state_t *
 * @param[in] address - uint32_t 
 * @param[in] dst - uint8_t *
 * @return true if success, false if failed 
 */
int sdhc_read_block(sdhc_state_t *state, uint32_t address, uint8_t *dst);

/**
 * @brief sdhc_write_blocks 
 * writes a 512 byte block file buffer pointed to by src to SD/MMC card with address
 * for block_count blocks
 * @param[in] state - sdhc_state_t *
 * @param[in] address - uint32_t  disc byte (or sector) address
 * @param[in] src - uint8_t * pointer to memory to write
 * @return true if success, false if failed 
 */
int sdhc_write_block(sdhc_state_t *state, uint32_t address, uint8_t *src);

#ifdef DEBUG
void sdhc_print_status(sdhc_state_t *state, char *str);
void sdhc_print_cardstate(sdhc_state_t *state);
#endif
/**
 * @brief
 *
 * @param[in] state - sdhc_state_t *
 * @return true if success, false if failed 
 */
bool sdhc_test_card_detect(sdhc_state_t *state);


#endif /* __SD_H__ */
