/*******************************************************************************
 *  diskio.c
 *  C file for disk io for FatFS
 *  This is the SAMD51 MicroSD driver interface to ChaN FatFS
 *  get from here: http://www.elm-chan.org/fsw/ff/00index_e.html
 *  The include file diskio.h is from FatFS
 *  Copyright © Alkgrove 04/29/2018
 *
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
 ******************************************************************************/

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sam.h"
#include "i2cm.h"
#include "sd.h"
#include "AB1805.h"
#include "diskio.h"

sdhc_state_t *sdhc_get_state(void);
//dresult_t disk_ioctl (uint8_t pdrv, uint8_t cmd, void* buff);
DSTATUS disk_status (BYTE pdrv)
{
	(void) pdrv;
	sdhc_state_t *state = sdhc_get_state();
	int stat;
	stat = sdhc_init(state);
	if (stat == SDHC_ERR_CARD_NOT_PRESENT) {
		return STA_NODISK;
	} else if (stat != SDHC_OK) {
		return STA_NOINIT;
	}
	return 0;
}
 
/**
 * @brief Initialize a disk.
 *
 * @param drv Physical drive number (0..).
 *
 * @return 0 or disk status in combination of DSTATUS bits
 *         (STA_NOINIT, STA_PROTECT).
 */
DSTATUS disk_initialize (BYTE pdrv)
{	
	(void) pdrv;
	int stat;
	sdhc_state_t *state = sdhc_get_state();
	stat = sdhc_init(state);
	if (stat == SDHC_ERR_CARD_NOT_PRESENT) {
		return STA_NODISK;
	} else if (stat != SDHC_OK) {
		return STA_NOINIT;
	}
	return 0;
}

DRESULT disk_read (BYTE pdrv, BYTE* buff, DWORD sector, UINT count)
{
	int i;
	(void)pdrv;
	sdhc_state_t *state = sdhc_get_state();
	
	for (i = 0; i < count; i++) {
		if (sdhc_read_block(state, sector + (SD_MMC_BLOCK_SIZE * i), buff + (SD_MMC_BLOCK_SIZE * i)) != SDHC_OK) {
			return RES_ERROR;
		}
	}
	return RES_OK;
}

DRESULT disk_write (BYTE pdrv, const BYTE* buff, DWORD sector, UINT count)
{
	(void)pdrv;
	int i;
	sdhc_state_t *state = sdhc_get_state();
	
	for (i = 0; i < count; i++) {
		if (sdhc_write_block(state, sector + (SD_MMC_BLOCK_SIZE * i), (uint8_t *) buff + (SD_MMC_BLOCK_SIZE * i)) != SDHC_OK) {
			return RES_ERROR;
		}
	}
	return RES_OK;

}

DWORD get_fattime(void)
{
	struct tm time;
	uint32_t time32;
	rtc_get_time(&time);
	// tm_year is years since 1900. fattime year is since 1980
	time32 = ((time.tm_year - 80) << 25)
			| (time.tm_mon << 21)
			| (time.tm_mday << 16)
			| (time.tm_hour << 11)
			| (time.tm_min << 5)
			| (time.tm_sec);
	return time32;
}

DRESULT disk_ioctl (BYTE pdrv, BYTE ctrl, void* buff)
{
	sdhc_state_t *state = sdhc_get_state();
	(void)pdrv;
	switch (ctrl) {
		case GET_BLOCK_SIZE:
			*(uint32_t *) buff = 1; // this means block size is unknown
			return RES_OK;
		break;

		/* Get the number of sectors on the disk */
		case GET_SECTOR_COUNT: 
			*(uint32_t *)buff = state->sectors;
			return RES_OK;
		break;
		/* Get sectors on the disk (WORD) */
		case GET_SECTOR_SIZE:
			*(uint16_t *)buff = SD_MMC_BLOCK_SIZE;
			return RES_OK;
		break;

		/* Make sure that data has been written */
		case CTRL_SYNC:
			if (!state->card_detect || !state->need_init) {
				return RES_NOTRDY;
			}
			return RES_OK;
		break;
		case CTRL_TRIM:
			return RES_OK;
		break;
		default:
			return RES_PARERR;
		break;
	}
}
