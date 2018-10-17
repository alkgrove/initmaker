/*
 *  @file sd.c
 *  C file for SD card host controller driver
 *  This is a complete rewrite of the SD Card code from ASF4
 *  Copyright © Alkgrove 04/29/2018
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

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "sam.h"
#include "sd_mmc_protocol.h"
#include "sd.h"

#ifndef SDHC0_CORE_FREQ
#define SDHC0_CORE_FREQ 100000000
#endif

#ifndef EIC_SDCD_IRQ
#define	EIC_SDCD_IRQ    EIC6
#endif

static bool sdhc_test_voltage(sdhc_state_t *state, bool F8);
static bool sdhc_test_capacity(sdhc_state_t *state);
static bool sdhc_test_version(sdhc_state_t *state);
static bool sdhc_wait_not_busy(sdhc_state_t *state);
static bool sdhc_test_bus_width(sdhc_state_t *state);
static bool sdhc_test_high_speed(sdhc_state_t *state);
static bool sdhc_init_transfer(sdhc_state_t *state, uint32_t cmd, uint32_t arg, uint16_t block_size);
static bool sdio_test_type(sdhc_state_t *state);

/** SD/MMC transfer rate unit codes (10K) list */
const uint32_t transfer_units[] = {10, 100, 1000, 10000, 0, 0, 0, 0};
/** SD transfer multiplier factor codes (1/10) list */
const uint32_t transfer_multiplier[16] = {0, 10, 12, 13, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 80};

// a small_delay for clocks to happen
// this is lame but this is what they used
void small_delay(void)
{
	volatile int i; 
	for (i = 0; i < 5000; i++) {};
}
 
int sdhc_init(sdhc_state_t *state)
{
	bool F8;
	uint32_t response;
	if (!sdhc_test_card_detect(state)) {
	    return SDHC_ERR_CARD_NOT_PRESENT;
	}
	// set the initial clock slow, single bit and normal speed
	state->type = CARD_TYPE_SD;
	state->version = CARD_VER_UNKNOWN;
	state->rca = 0;
	state->bus_width = 1;
	state->high_speed = false;
	state->clock = SDHC_SLOW_CLOCK;
	sdhc_set_hc(state);
	// send 74 startup clocks (190us)
	small_delay();
	// reset the SD card to idle state CMD0
	F8 = false;
	for(int i = 0; i < 2; i++) { // we do this step twice before failing
		if (!sdhc_send_cmd(SDMMC_MCI_CMD0_GO_IDLE_STATE, 0)) {
			if (i == 1) return SDHC_ERR_BAD_CARD;
		}
		/* Test for SD version 2 */
		if (!sdhc_send_cmd(SD_CMD8_SEND_IF_COND, SD_CMD8_PATTERN | SD_CMD8_HIGH_VOLTAGE)) {
			if (i == 1) return SDHC_ERR_BAD_CARD; // bad card
		} else {
			response = sdhc_read_RR(SDHC0, 0);
			if (response == 0xFFFFFFFF) { // good response but no compliance R7 Value, legacy card
				F8 = false;
				break;
			}
			if ((response & (SD_CMD8_MASK_PATTERN | SD_CMD8_MASK_VOLTAGE)) 
			             == (SD_CMD8_PATTERN | SD_CMD8_HIGH_VOLTAGE)) {
				F8 = true;
				break;
			}
		}
	}
	if (!sdio_test_type(state)) {
		return SDHC_ERR_BAD_CARD;
	}
	if (state->type & CARD_TYPE_SDIO) {
		return SDHC_ERR_SDIO_NOT_SUPPORTED;
	}
  	/* Try to get the SD card's operating condition */
  	if (!sdhc_test_voltage(state, F8)) {
  		state->type = CARD_TYPE_UNKNOWN;
  		return SDHC_ERR_BAD_CARD;
  	}
  	/* SD MEMORY, Put the Card in Identify Mode
  	 * Note: The CID is not used in this stack */
  	if (!sdhc_send_cmd(SDMMC_CMD2_ALL_SEND_CID, 0)) {
  		return SDHC_ERR_BAD_CARD;
  	}
	/* Ask the card to publish a new relative address (RCA).*/
	if (!sdhc_send_cmd(SD_CMD3_SEND_RELATIVE_ADDR, 0)) {
		return SDHC_ERR_BAD_CARD;
	}
	state->rca = (uint16_t) (sdhc_read_RR(SDHC0,0) >> 16);
	/* SD MEMORY, Get the Card-Specific Data */
  	if (!sdhc_test_capacity(state)) {
  		return SDHC_ERR_BAD_CARD;
  	}
	/* Put it into Transfer Mode */
	if (!sdhc_send_cmd(SDMMC_CMD7_SELECT_CARD_CMD, (uint32_t)state->rca << 16)) {
		return SDHC_ERR_BAD_CARD;
	}
	/* SD MEMORY, Read the SCR to get card version */
  	if (!sdhc_test_version(state)) {
  		return SDHC_ERR_BAD_CARD;
  	}
	if (!sdhc_test_bus_width(state)) {
		return SDHC_ERR_BAD_CARD;
	}
	/* update the host controller to the detected changes in bus_width and clock */
	sdhc_set_hc(state);
	/* if it is high speed capable, (well it is) */
	if (sdhc_get_CA0R(SDHC0, SDHC_CA0R_HSSUP)) {
  		if (!sdhc_test_high_speed(state)) {
   			return SDHC_ERR_BAD_CARD;
  		}
	}
	sdhc_set_hc(state); // update host controller
  	if (!sdhc_send_cmd(SDMMC_CMD16_SET_BLOCKLEN, SD_MMC_BLOCK_SIZE)) {
   		return SDHC_ERR_BAD_CARD;
  	}
	state->need_init = false;
	return SDHC_OK;
}

bool sdhc_send_cmd(uint32_t cmd, uint32_t arg)
{
	uint32_t timeout = 0xFFFFFFFF;
	uint32_t command;
	uint32_t eis;
	// we try to send a command when command is inhibited, return false
	if (sdhc_get_PSR(SDHC0, SDHC_PSR_CMDINHC)) {
		return false;
	}
	sdhc_clear_TMR(SDHC0, SDHC_TMR_DMAEN); // clear DMA enable
	sdhc_write_BCR(SDHC0, 0); // block count is zero
	command = SDHC_CR_CMDIDX(cmd) | SDHC_CR_CMDTYP_NORMAL;
	if (cmd & MCI_RESP_PRESENT) {
		if (cmd & MCI_RESP_136) {
			command |= SDHC_CR_RESPTYP_136_BIT;
		} else if (cmd & MCI_RESP_BUSY) {
			command |= SDHC_CR_RESPTYP_48_BIT_BUSY;
		} else {
			command |= SDHC_CR_RESPTYP_48_BIT;
		}
	}
	if (cmd & MCI_CMD_OPENDRAIN) {
		sdhc_set_MC1R(SDHC0, SDHC_MC1R_OPD);
	} else {
		sdhc_clear_MC1R(SDHC0, SDHC_MC1R_OPD);
	}
	sdhc_write_ARG1R(SDHC0, arg); // setup the argument register
	sdhc_write_CR(SDHC0, command); // send command
    eis = (cmd & MCI_RESP_CRC) ?
		 SDHC_EISTR_CMDTEO | SDHC_EISTR_CMDEND | SDHC_EISTR_CMDIDX | SDHC_EISTR_DATTEO 
	   | SDHC_EISTR_DATEND | SDHC_EISTR_ADMA
	   : SDHC_EISTR_CMDTEO | SDHC_EISTR_CMDEND | SDHC_EISTR_CMDIDX | SDHC_EISTR_DATTEO
       | SDHC_EISTR_DATEND | SDHC_EISTR_ADMA | SDHC_EISTR_CMDCRC | SDHC_EISTR_DATCRC;
	do {	
		if (sdhc_get_EISTR(SDHC0, eis)) { // did the command fail?
			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTCMD); // reset command
			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTCMD)) {};
		    sdhc_set_EISTR(SDHC0, SDHC_EISTR_MASK);
			return false;
		}
     } while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_CMDC));
    if (!(command & SDHC_CR_DPSEL_DATA)) { // if data isn't present then set CMD status bit
    	sdhc_set_NISTR(SDHC0, SDHC_NISTR_CMDC);
    }
    if (cmd & MCI_RESP_BUSY) {
    	do {
    		if(--timeout == 0) {
    			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTCMD); // reset command
    			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTCMD)) {};
    			return false;
    		}
 		} while(!sdhc_get_PSR(SDHC0, SDHC_PSR_DATLL(1))); // DAT[0] is busy bit
 	}
 	return true;
}

void sdhc_set_speed(uint32_t fsdhc)
{
	uint32_t div;
	
	if (sdhc_get_CCR(SDHC0, SDHC_CCR_SDCLKEN)) {
		while(sdhc_get_PSR(SDHC0, SDHC_PSR_CMDINHC | SDHC_PSR_CMDINHD)) {}; // wait for command/data to go inactive
		sdhc_clear_CCR(SDHC0, SDHC_CCR_SDCLKEN); // disable the clock
	}
	// since both examples use divided clock rather than programmable - just use divided here
	sdhc_clear_CCR(SDHC0, SDHC_CCR_CLKGSEL); // divided clock
	div = (SDHC0_CORE_FREQ / fsdhc) / 2; // Fsdclk = Fsdhc_core/(2 * div)
	// high speed div must not be 0
	if (sdhc_get_HC1R(SDHC0, SDHC_HC1R_HSEN) && (div == 0)) div = 1;
	// write the 10 bit clock divider
	sdhc_clear_CCR(SDHC0, SDHC_CCR_USDCLKFSEL_Msk | SDHC_CCR_SDCLKFSEL_Msk);
	sdhc_set_CCR(SDHC0, SDHC_CCR_SDCLKFSEL(div) | SDHC_CCR_USDCLKFSEL(div >> 8));
	sdhc_set_CCR(SDHC0, SDHC_CCR_INTCLKEN); // enable internal clock
	while(!sdhc_get_CCR(SDHC0, SDHC_CCR_INTCLKS)) {}; // wait for clock to be stable
	sdhc_set_CCR(SDHC0, SDHC_CCR_SDCLKEN); // enable clock to card
}

/**
 * sdhc_set_hc selects either one or four bit mode, low/high speed and clock
 *
 * bitwidth is SDHC_HC1R_DW_1BIT_Val or SDHC_HC1R_DW_4BIT_Val
 * speed is SDHC_HC1R_HSEN_NORMAL_Val or SDHC_HC1R_HSEN_HIGH_Val 
 */
void sdhc_set_hc(sdhc_state_t *state)
{
	if (state->high_speed) {
		sdhc_set_HC1R(SDHC0, SDHC_HC1R_HSEN);
	} else {
		sdhc_clear_HC1R(SDHC0, SDHC_HC1R_HSEN);
	}
	if (!sdhc_get_HC2R(SDHC0, SDHC_HC2R_PVALEN)) { // PVALEN is probably always low
		sdhc_set_speed(state->clock);
	}
	if (state->bus_width == 4) {
		sdhc_set_HC1R(SDHC0, SDHC_HC1R_DW); // set four bit mode
	} else {
		sdhc_clear_HC1R(SDHC0, SDHC_HC1R_DW); // set one bit mode
	}
}

/**
 * @brief Ask to all cards to send their operations conditions (MCI only).
 * - ACMD41 sends operation condition command.
 * - ACMD41 reads OCR
 *
 * @param state pointer to sdhc
 *
 * @return true if success, otherwise false
 */
static bool sdhc_test_voltage(sdhc_state_t *state, bool F8)
{
	uint32_t arg;
	uint32_t retry = 2100;
	uint32_t response;

	/*
	 * Timeout 1s = 400KHz / ((6+6+6+6)*8) cycles = 2100 retry
	 * 6 = cmd byte size
	 * 6 = response byte size
	 * 6 = cmd byte size
	 * 6 = response byte size
	 */
	retry = 2100;
	do {
		/* CMD55 - Indicate to the card that the next command is an
		 * application specific command rather than a standard command.*/
		if (!sdhc_send_cmd(SDMMC_CMD55_APP_CMD, 0)) {
			return false;
		}

		/* (ACMD41) Sends host OCR register */
		arg = (OCR_VDD_27_28 | OCR_VDD_28_29 | OCR_VDD_29_30 | OCR_VDD_30_31 | OCR_VDD_31_32 | OCR_VDD_32_33);
		if (F8) { // if not legacy card
			arg |= SD_ACMD41_HCS;
		}
		/* Check response */
		if (!sdhc_send_cmd(SD_MCI_ACMD41_SD_SEND_OP_COND, arg)) {
			return false;
		}
		response = sdhc_read_RR(SDHC0,0);
		if (response & OCR_POWER_UP_BUSY) {
			/* Card is ready */
			if ((response & OCR_CCS) != 0) {
				state->type |= CARD_TYPE_HC;
			}
			break;
		}
		if (retry-- == 0) {
			return false;
		}
	} while (1);
	return true;
}

/**
 * \brief CMD9: Addressed card sends its card-specific
 * data (CSD) on the CMD line mci.
 *
 * \return true if success, otherwise false
 */
static bool sdhc_test_capacity(sdhc_state_t *state)
{

	uint32_t transfer_speed;
	int8_t i;
	uint8_t csd[16];
	if (!sdhc_send_cmd(SDMMC_MCI_CMD9_SEND_CSD, (uint32_t)state->rca << 16)) {
		return false;
	}
	for ( i = 0; i < 4; i++) { // this is weird code that should be fixed later
		((uint32_t *)csd)[i] = __builtin_bswap32(sdhc_read_RR(SDHC0,3-i));
	}
	transfer_speed = CSD_TRAN_SPEED(&csd[1]);
	state->clock = transfer_units[transfer_speed & 0x7] * transfer_multiplier[(transfer_speed >> 3) & 0xF] * 1000;
	/*
	 * Card Capacity.
	 * ----------------------------------------------------
	 * For normal SD/MMC card:
	 * sector size is ((device size + 1) * (1 << (device size multiplier + 2)) * (1 << max_read_data_block_length))/512
	 * we can rearrange this like this
	 * sector size is ((device size + 1) * (1 << (device size multiplier +  max_read_data_block_length - 7))
	 * device_size = SD_CSD_1_0_C_SIZE(&csd[1]) 
	 * device_size_multiplier = SD_CSD_1_0_C_SIZE_MULT(&csd[1])
	 * max_read_data_block_length = SD_CSD_1_0_READ_BL_LEN(&csd[1])
	 * Number of sectors is bytes/512
	 * ----------------------------------------------------
	 * For high capacity SD card:
	 * memory capacity = (C_SIZE+1) * 512K byte
	 * So number of sectors is ((C_SIZE+1) * 512 * 1024) / 512
	 * or 1024 * (C_SIZE+1)
	 */
	if (CSD_STRUCTURE_VERSION(&csd[1]) >= SD_CSD_VER_2_0) {
		state->sectors = (SD_CSD_2_0_C_SIZE(&csd[1]) + 1) * 1024;
	} else {
		state->sectors = (SD_CSD_1_0_C_SIZE(&csd[1]) + 1) * (1 << (SD_CSD_1_0_C_SIZE_MULT(&csd[1]) + SD_CSD_1_0_READ_BL_LEN(&csd[1]) - 7));
	}
	return true;
}

/**
 * @brief ACMD51 - Read the SD Configuration Register.
 *
 * @note
 * SD Card Configuration Register (SCR) provides information on the SD Memory
 * Card's special features that were configured into the given card. The size
 * of SCR register is 64 bits.
 *
 *
 * @return true if success, otherwise false
 */
static bool sdhc_test_version(sdhc_state_t *state)
{
	uint8_t scr[SD_SCR_REG_BSIZE];
	uint32_t *p = (uint32_t *) scr;
	int words;
	
	/* CMD55 - Indicate to the card that the next command is an
	 * application specific command rather than a standard command.*/
	if (!sdhc_send_cmd(SDMMC_CMD55_APP_CMD, (uint32_t)state->rca << 16)) {
		return false;
	}
	if (!sdhc_init_transfer(state, SD_ACMD51_SEND_SCR, 0, SD_SCR_REG_BSIZE)) {
		return false;
	}
	do {
  		if (sdhc_get_EISTR(SDHC0, SDHC_EISTR_DATTEO | SDHC_EISTR_DATCRC | SDHC_EISTR_DATEND)) {
  			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset all
  			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
  			state->need_init = true;
  			return false;
  		}
  	} while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_BRDRDY)); // until buffer read ready
  	sdhc_set_NISTR(SDHC0, SDHC_NISTR_BRDRDY); // clear the buffer read ready bit
	for(words = 0; words < (SD_SCR_REG_BSIZE/4); words++) {
		*p++ = sdhc_read_BDPR(SDHC0);
	}

	do {
  		if (sdhc_get_EISTR(SDHC0, (SDHC_EISTR_DATTEO | SDHC_EISTR_DATCRC | SDHC_EISTR_DATEND))) {
  			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset command
  			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
  			state->need_init = true;
  			return false;
  		}
  	} while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_TRFC)); // wait until transfer complete
  	sdhc_set_NISTR(SDHC0, SDHC_NISTR_TRFC);

	/* Get SD Memory Card - Spec. Version */
	switch (SD_SCR_SD_SPEC(scr)) {
		case SD_SCR_SD_SPEC_1_0_01:
			state->version = CARD_VER_SD_1_0;
		break;

		case SD_SCR_SD_SPEC_1_10:
			state->version = CARD_VER_SD_1_10;
		break;

		case SD_SCR_SD_SPEC_2_00:
			if (SD_SCR_SD_SPEC3(scr) == SD_SCR_SD_SPEC_3_00) {
				state->version = CARD_VER_SD_3_0;
			} else {
				state->version = CARD_VER_SD_2_0;
			}
		break;

		default:
			state->version = CARD_VER_SD_1_0;
		break;
	}
	return true;
}

static bool sdhc_init_transfer(sdhc_state_t *state, uint32_t cmd, uint32_t arg, uint16_t block_size)
{
	uint32_t tmr;
	uint32_t command;
	uint32_t timeout = 0xFFFFFFFF;
    uint32_t eis;
    
	if (sdhc_get_PSR(SDHC0, SDHC_PSR_CMDINHC | SDHC_PSR_CMDINHD)) {
		return false;
	}

	if (cmd & MCI_CMD_WRITE) {
		tmr = SDHC_TMR_DTDSEL_WRITE;
	} else {
		tmr = SDHC_TMR_DTDSEL_READ;
	}

	if (cmd & MCI_CMD_SDIO_BYTE) {
		tmr |= SDHC_TMR_MSBSEL_SINGLE;
	} else if (cmd & MCI_CMD_SDIO_BLOCK) {
		tmr |= SDHC_TMR_BCEN | SDHC_TMR_MSBSEL_MULTIPLE;
	} else if (cmd & MCI_CMD_SINGLE_BLOCK) {
		tmr |= SDHC_TMR_MSBSEL_SINGLE;
	} else if (cmd & MCI_CMD_MULTI_BLOCK) {
		tmr |= SDHC_TMR_BCEN | SDHC_TMR_MSBSEL_MULTIPLE;
	} else {
		return false;
	}

	sdhc_write_TMR(SDHC0, tmr);
	sdhc_write_BSR(SDHC0, SDHC_BSR_BLOCKSIZE(block_size) | SDHC_BSR_BOUNDARY_4K);
	sdhc_write_BCR(SDHC0, SDHC_BCR_BCNT(1));
		
	command = SDHC_CR_DPSEL_DATA;
	command |= SDHC_CR_CMDIDX(cmd) | SDHC_CR_CMDTYP_NORMAL;
	if (cmd & MCI_RESP_PRESENT) {
		if (cmd & MCI_RESP_136) {
			command |= SDHC_CR_RESPTYP_136_BIT;
		} else if (cmd & MCI_RESP_BUSY) {
			command |= SDHC_CR_RESPTYP_48_BIT_BUSY;
		} else {
			command |= SDHC_CR_RESPTYP_48_BIT;
		}
	}
	if (cmd & MCI_CMD_OPENDRAIN) {
		sdhc_set_MC1R(SDHC0, SDHC_MC1R_OPD);
	} else {
		sdhc_clear_MC1R(SDHC0, SDHC_MC1R_OPD);
	}
	
	sdhc_write_ARG1R(SDHC0, arg); // setup the argument register
	sdhc_write_CR(SDHC0, command); // send command

    eis = SDHC_EISTR_CMDTEO | SDHC_EISTR_CMDEND | SDHC_EISTR_CMDIDX | SDHC_EISTR_DATTEO 
    	   | SDHC_EISTR_DATEND | SDHC_EISTR_ADMA;
    if ((cmd & MCI_RESP_CRC) == 0) {
    	eis |= (SDHC_EISTR_CMDCRC | SDHC_EISTR_DATCRC);
    }

	do {	
    	if (sdhc_get_EISTR(SDHC0, eis)) { // did the command fail?
    	    sdhc_set_EISTR(SDHC0, SDHC_EISTR_MASK);
  			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTCMD); // reset command
  			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTCMD)) {};
  			return false;
    	}
    } while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_CMDC));
    if (!(command & SDHC_CR_DPSEL_DATA)) { // if data isn't present then set CMD status bit
    	sdhc_set_NISTR(SDHC0, SDHC_NISTR_CMDC);
    }
    if (cmd & MCI_RESP_BUSY) {
    	do {
    		if(--timeout == 0) {
    			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTCMD); // reset command
    			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTCMD)) {};
    			return false;
    		}
 		} while(!sdhc_get_PSR(SDHC0, SDHC_PSR_DATLL(1))); // DAT[0] is busy bit
 	}
 	return true;
}


/**
 *  @brief Start a read block transfer on the line
 *  
 *  dst must be on 4 byte boundary
 */
int sdhc_read_block(sdhc_state_t *state, uint32_t address, uint8_t *dst)
{
	uint32_t arg;
	uint32_t *p = (uint32_t *) dst;
	int words;
	int stat;
 	// card detect should be done differently
	// card detect with interrupt and if removed and reinstalled
	// set need_init, sdhc_init clears need_init
	if (!state->card_detect) {
		return SDHC_ERR_CARD_NOT_PRESENT;
	}
	if (state->need_init) {
		stat = sdhc_init(state);
		if (stat != SDHC_OK) return stat;
	}
	if (!sdhc_wait_not_busy(state)) {
		return SDHC_ERR_BUSY;
	}
	if (state->type & CARD_TYPE_HC) {
		arg = address;
	} else {
		arg = address * SD_MMC_BLOCK_SIZE;
	}
	if (!sdhc_init_transfer(state, SDMMC_CMD17_READ_SINGLE_BLOCK, arg, SD_MMC_BLOCK_SIZE)) {
		return SDHC_ERR_BAD_CARD;
	}
	if (sdhc_read_RR(SDHC0,0) & CARD_STATUS_ERR_RD_WR) {
		return SDHC_ERR_BAD_CARD;
	}

 	do {
  		if (sdhc_get_EISTR(SDHC0, SDHC_EISTR_DATTEO | SDHC_EISTR_DATCRC | SDHC_EISTR_DATEND)) {
  			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset command
  			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
  			state->need_init = true;
  			return SDHC_ERR_BAD_CARD;
  		}
  	} while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_BRDRDY)); // until buffer read ready
  	sdhc_set_NISTR(SDHC0, SDHC_NISTR_BRDRDY); // clear the buffer read ready bit
	for(words = 0; words < (SD_MMC_BLOCK_SIZE/4); words++) {
		*p++ = sdhc_read_BDPR(SDHC0);
	}
	do {
  		if (sdhc_get_EISTR(SDHC0, (SDHC_EISTR_DATTEO | SDHC_EISTR_DATCRC | SDHC_EISTR_DATEND))) {
  			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset command
  			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
  			state->need_init = true;
  			return SDHC_ERR_BAD_CARD;
  		}
  	} while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_TRFC)); // wait until transfer complete
  	sdhc_set_NISTR(SDHC0, SDHC_NISTR_TRFC);
	return SDHC_OK;
}
/**
 *  @brief Start a write blocks transfer on the line
 *  Note: The driver will use the DMA available to speed up the transfer. (there is no evidence of that)
 *  src must be on 4 byte boundary
 */

int sdhc_write_block(sdhc_state_t *state, uint32_t address, uint8_t *src)
{
	uint32_t arg;
	int words;
	uint32_t *p = (uint32_t *) src;
	int stat;
	
	if (!state->card_detect) {
		return SDHC_ERR_CARD_NOT_PRESENT;
	}
	if (state->need_init) {
		stat = sdhc_init(state);
		if (stat != SDHC_OK) return stat;
	}
	if (!sdhc_wait_not_busy(state)) {
		return SDHC_ERR_BUSY;
	}
	/*
	 * SDSC Card (CCS=0) uses byte unit address,
	 * SDHC and SDXC Cards (CCS=1) use block unit address (512 Bytes unit).
	 */
	if (state->type & CARD_TYPE_HC) {
		arg = address;
	} else {
		arg = (address * SD_MMC_BLOCK_SIZE);
	}

	if (!sdhc_init_transfer(state, SDMMC_CMD24_WRITE_BLOCK, arg, SD_MMC_BLOCK_SIZE)) {
		return SDHC_ERR_BAD_CARD;
	}
	if (sdhc_read_RR(SDHC0,0) & CARD_STATUS_ERR_RD_WR) {
		return SDHC_ERR_BAD_CARD;
	}

	do {
		if (sdhc_get_EISTR(SDHC0, (SDHC_EISTR_DATTEO | SDHC_EISTR_DATCRC | SDHC_EISTR_DATEND))) {
			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset command
    		while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
    		state->need_init = true;
			return SDHC_ERR_BAD_CARD;
		}
	} while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_BWRRDY));
	sdhc_set_NISTR(SDHC0, SDHC_NISTR_BWRRDY);
    /* Write data */
    for(words = 0; words < (SD_MMC_BLOCK_SIZE / 4); words++) {
    	sdhc_write_BDPR(SDHC0, *p++);
    }
    /* Wait end of transfer */
    do {
  		if (sdhc_get_EISTR(SDHC0, (SDHC_EISTR_DATTEO | SDHC_EISTR_DATCRC | SDHC_EISTR_DATEND))) {
  			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset command
      		while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
      		state->need_init = true;
  			return SDHC_ERR_BAD_CARD;
  		}
    } while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_TRFC)); // wait until transfer complete
    sdhc_set_NISTR(SDHC0, SDHC_NISTR_TRFC);
	return SDHC_OK;
}

/**
 * @brief test card detect
 * @return true if card detected, false if no card present
 **/
bool sdhc_test_card_detect(sdhc_state_t *state)
{
	state->card_detect = !eic_get_PINSTATE(EIC_SDCD_IRQ);
	if (!state->card_detect) {
		state->need_init = true; // this should be done in interrupt routine
	}
	return state->card_detect;
}

/**
 * @brief CMD13 - Addressed card sends its status register.
 * This function waits the clear of the busy flag
 *
 * @return true if success, otherwise false
 */
static bool sdhc_wait_not_busy(sdhc_state_t *state)
{
	uint32_t timeout;

	/* Wait for data ready status.
	 * Nec timing: 0 to unlimited
	 * However a timeout is used.
	 * 200 000 * 8 cycles
	 */
	timeout = 200000;
	do {
		if (!sdhc_send_cmd(SDMMC_MCI_CMD13_SEND_STATUS, (uint32_t) state->rca << 16)) {
			return false;
		}
		/* Check busy flag */
		if (sdhc_read_RR(SDHC0,0) & CARD_STATUS_READY_FOR_DATA) {
			break;
		}
		if (timeout-- == 0) {
			return false;
		}
	} while (1);

	return true;
}

/**
 * @brief Try to get the SDIO card's operating condition
 * - CMD5 to read OCR NF field
 * - CMD5 to wait OCR power up busy
 * - CMD5 to read OCR MP field
 *   sd_mmc_card->type is updated
 *
 * @return true if success, otherwise false
 */
static bool sdio_test_type(sdhc_state_t *state)
{
	uint32_t response;
	uint32_t cmd5_retry = 5000;

	/* CMD5 - SDIO send operation condition (OCR) command. */
	if (!sdhc_send_cmd(SDIO_CMD5_SEND_OP_COND, 0)) {
		return true; /* No error but card type not updated */
	}
	response = sdhc_read_RR(SDHC0,0);
	if ((response & OCR_SDIO_NF) == 0) {
		return true; /* No error but card type not updated */
	}

	/*
	 * Wait card ready
	 * Timeout 1s = 400KHz / ((6+4)*8) cylces = 5000 retry
	 * 6 = cmd byte size
	 * 4(SPI) 6(MCI) = response byte size
	 */
	while (1) {
		/* CMD5 - SDIO send operation condition (OCR) command.*/
		if (!sdhc_send_cmd(SDIO_CMD5_SEND_OP_COND, response & (OCR_VDD_27_28 | OCR_VDD_28_29 
								| OCR_VDD_29_30 | OCR_VDD_30_31 | OCR_VDD_31_32 | OCR_VDD_32_33))) {
			return false;
		}
		response = sdhc_read_RR(SDHC0,0);
		if ((response & OCR_POWER_UP_BUSY) == OCR_POWER_UP_BUSY) {
			break;
		}
		if (cmd5_retry-- == 0) {
			return false;
		}
	}
	/* Update card type at the end of busy */
	if ((response & OCR_SDIO_MP) > 0) {
		state->type = CARD_TYPE_SD_COMBO;
	} else {
		state->type = CARD_TYPE_SDIO;
	}
	return true;
}


static bool sdhc_test_high_speed(sdhc_state_t *state)
{
	uint8_t switch_status[SD_SW_STATUS_BSIZE] = {0};
	uint32_t *p = (uint32_t *)switch_status;
	int words;
	if ((state->type & CARD_TYPE_SD) && (state->version > CARD_VER_SD_1_0)) {
		if (!sdhc_init_transfer(state, SD_CMD6_SWITCH_FUNC, 
		                         SD_CMD6_MODE_SWITCH 
    	                       | SD_CMD6_GRP6_NO_INFLUENCE 
    	                       | SD_CMD6_GRP5_NO_INFLUENCE
    	                       | SD_CMD6_GRP4_NO_INFLUENCE
    	                       | SD_CMD6_GRP3_NO_INFLUENCE
    	                       | SD_CMD6_GRP2_DEFAULT
    	                       | SD_CMD6_GRP1_HIGH_SPEED,
    	                       SD_SW_STATUS_BSIZE)) {

			return false;
		}
    	do {
      		if (sdhc_get_EISTR(SDHC0, SDHC_EISTR_DATTEO | SDHC_EISTR_DATCRC | SDHC_EISTR_DATEND)) {
      			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset command
      			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
      			state->need_init = true;
      			return false;
      		}
      	} while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_BRDRDY)); // until buffer read ready
      	sdhc_set_NISTR(SDHC0, SDHC_NISTR_BRDRDY); // clear the buffer read ready bit
    	for(words = 0; words < (SD_SW_STATUS_BSIZE/4); words++) {
    		*p++ = sdhc_read_BDPR(SDHC0);
    	}
    	do {
    		if (sdhc_get_EISTR(SDHC0, (SDHC_EISTR_DATTEO | SDHC_EISTR_DATCRC | SDHC_EISTR_DATEND))) {
    			sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset command
    			while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
      			state->need_init = true;
    			return false;
    		}
    	} while (!sdhc_get_NISTR(SDHC0, SDHC_NISTR_TRFC)); // wait until transfer complete
    	sdhc_set_NISTR(SDHC0, SDHC_NISTR_TRFC);

		if (sdhc_read_RR(SDHC0, 0) & CARD_STATUS_SWITCH_ERROR) {
			return false;
		}
    	if (SD_SW_STATUS_FUN_GRP1_RC(switch_status) == SD_SW_STATUS_FUN_GRP_RC_ERROR) {
    		/* No supported, it is not a protocol error */
    		return true;
    	}
    	if (SD_SW_STATUS_FUN_GRP1_BUSY(switch_status)) {
    		return false;
    	}
    	/* CMD6 function switching period is within 8 clocks
    	 * after the end bit of status data.*/
    	small_delay();
 	}
	state->high_speed = true;
	state->clock *= 2; // turbo clock
	return true;
}

static bool sdhc_test_bus_width(sdhc_state_t *state)
{
	/**
	 * A SD memory card always supports bus 4bit
	 * A SD COMBO card always supports bus 4bit
	 * A SDIO Full-Speed alone always supports 4bit
	 * A SDIO Low-Speed alone can supports 4bit (Optional)
	 */
#ifdef USE_SDIO
	uint8_t value;
	if (state->type & CARD_TYPE_SDIO) {

        /* Check 4bit support in 4BLS of "Card Capability" register */
        if (!sdio_send_cmd52(SDIO_CMD52_READ_FLAG, SDIO_CIA, SDIO_CCCR_CAP, 0, &value)) {
        	return false;
        }
    
		if ((value & SDIO_CAP_4BLS) != SDIO_CAP_4BLS) {
			/* Not supported, it is not a protocol error */
			return true;
		}
		/* HS mode possible, then enable */
		value = SDIO_BUSWIDTH_4B;
		if (!sdio_send_cmd52(SDIO_CMD52_WRITE_FLAG, SDIO_CIA, SDIO_CCCR_BUS_CTRL, 1, &value)) {
			return false;
		}
	} 
#endif
	if (state->type & CARD_TYPE_SD) {
	/* CMD55 - Indicate to the card that the next command is an
	 * application specific command rather than a standard command.*/
		if (!sdhc_send_cmd(SDMMC_CMD55_APP_CMD, (uint32_t)state->rca << 16)) {
			return false;
		}
    	if (!sdhc_send_cmd(SD_ACMD6_SET_BUS_WIDTH, SD_ACMD6_4B)) {
    		return false;
    	}
    }
	state->bus_width = 4;
	return true;
}

#ifdef DEBUG
void sdhc_print_cardstate(sdhc_state_t *state)
{
	char *card;
	char *version;
	if ((state->type & (CARD_TYPE_SD | CARD_TYPE_SDIO)) == (CARD_TYPE_SD | CARD_TYPE_SDIO)) {
		card = "SD/SDIO";
	} else if (state->type & CARD_TYPE_SD) {
		card = "SD";
	} else if (state->type & CARD_TYPE_SDIO) {
		card = "SDIO";
	} else if (state->type & CARD_TYPE_MMC) {
		card = "MMC";
	} else if (state->type & CARD_TYPE_HC) {
		card = "SDHC";
	} else {
		card = "Unknown";
	}
	if (state->version == CARD_VER_SD_1_0) {
		version = "1.0";
	} else if (state->version == SD_SCR_SD_SPEC_1_10) {
		version = "1.1";
	} else if (state->version == SD_SCR_SD_SPEC_2_00) {
		version = "2.0";
	} else if (state->version == CARD_VER_SD_3_0) {
		version = "3.0";
	} else {
		version = "Unknown";
	}
	
	printf("Sectors %u (%uMB)\n", (unsigned int) state->sectors, (unsigned int) (state->sectors/1000000) * 512);
	printf("Clock %u Hz\n", (unsigned int) state->clock);
	printf("RCA 0x%04X\n", (unsigned int) state->rca);
	printf("Type %s\n", card);
	printf("SD Version %s\n", version);
	printf("Bus width %d bits\n", (int) state->bus_width);
	printf("%s Speed\n", state->high_speed ? "High" : "Normal");
	printf("Card %s\n", state->card_detect ? "Installed" : "Not Installed");
	printf("%s\n", state->need_init ? "Needs initialization" : "Initialized");
}

void sdhc_print_status(sdhc_state_t *state, char *str) 
{
	uint32_t response;
	if (sdhc_send_cmd(SDMMC_MCI_CMD13_SEND_STATUS, (uint32_t) state->rca << 16)) {
		response = sdhc_read_RR(SDHC0,0);
		printf("%s status\n", str);
		if (response & CARD_STATUS_APP_CMD) printf("  APP CMD Enabled\n");
		if (response & CARD_STATUS_SWITCH_ERROR) printf("  Switch Error\n");
		if (response & CARD_STATUS_READY_FOR_DATA) printf("  Ready For Data\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_IDLE) printf("  Idle State\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_READY) printf("  Ready State\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_IDENT) printf("  Ident State\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_STBY) printf("  Standby State\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_TRAN) printf("  Transfer State\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_DATA) printf("  Data State\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_RCV) printf("  Receive State\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_PRG) printf("  Prg State\n");
		if ((response & CARD_STATUS_STATE) == CARD_STATUS_STATE_DIS) printf("  Dis State\n");
		if (response & CARD_STATUS_ERASE_RESET) printf("  Erase Reset Enabled\n");
		if (response & CARD_STATUS_WP_ERASE_SKIP) printf("  WP Erase Skip\n");
		if (response & CARD_STATUS_ECC_DISABLED) printf("  ECC disabled\n");
		if (response & CARD_STATUS_CIDCSD_OVERWRITE) printf("  CSD Overwrite Error\n");
		if (response & CARD_STATUS_ERROR) printf("  General Unknown Error\n");
		if (response & CARD_STATUS_CC_ERROR) printf("  Card Controller Error\n");
		if (response & CARD_STATUS_CARD_ECC_FAILED) printf("  Card ECC Failed\n");
		if (response & CARD_STATUS_ILLEGAL_COMMAND) printf("  Illegal Command\n");
		if (response & CARD_STATUS_COM_CRC_ERROR) printf("  CRC Failed\n");
		if (response & CARD_STATUS_UNLOCK_FAILED) printf("  Bad Password\n");
		if (response & CARD_STATUS_CARD_IS_LOCKED) printf("  Locked Card\n");
		if (response & CARD_STATUS_WP_VIOLATION) printf("  Attempt to write in WP space\n");
		if (response & CARD_STATUS_ERASE_PARAM) printf("  Bad Blocks to Erase\n");
		if (response & CARD_STATUS_ERASE_SEQ_ERROR) printf("  Erase out of sequence\n");
		if (response & CARD_STATUS_BLOCK_LEN_ERROR) printf("  Block Length Error\n");
		if (response & CARD_STATUS_ADDRESS_MISALIGN) printf("  Misaligned Address\n");
		if (response & CARD_STATUS_ADDR_OUT_OF_RANGE) printf("  Address out of range\n");
		printf("End Status %s\n", str);
	}
}
#endif