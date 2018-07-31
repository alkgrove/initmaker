/*******************************************************************************
 *  diskio.c
 *  C file for disk io for FatFS
 *  
 *  Copyright © Bob Alkire 04/29/2018
 *  ATSAMD51
 * 
 ******************************************************************************/

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "sam.h"
#include "sd.h"
#include "AB1805.h"
#include "rtc.h"
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

static BYTE convertBCD(BYTE bcd)
{
	return ((bcd >> 4)*10) + (bcd & 0xF);
}

DWORD get_fattime(void)
{
	uint32_t time32;
	rtc_time_t time;
	
	rtc_get_time(&time);
	
	time32 = ((convertBCD(time.year)+20) << 25)
			| (convertBCD(time.month) << 21)
			| (convertBCD(time.day) << 16)
			| (convertBCD(time.hour) << 11)
			| (convertBCD(time.minute) << 5)
			| convertBCD(time.second);
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
