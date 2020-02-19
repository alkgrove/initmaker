/*
 *  @file qspi_flash.c
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

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sam.h"
#include "qspi_flash.h"

void qspi_flash_command(uint8_t cmd)
{
	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(cmd));

	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_READ
		                | QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI
                        | QSPI_INSTRFRAME_ADDRLEN_24BITS
                        | QSPI_INSTRFRAME_INSTREN);
    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);

}

void qspi_flash_sector_command(uint8_t cmd, uint32_t adr)
{
	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(cmd));
	qspi_write_INSTRADDR(adr);
	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_WRITE
		                | QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI
                        | QSPI_INSTRFRAME_ADDRLEN_24BITS
                        | QSPI_INSTRFRAME_ADDREN
                        | QSPI_INSTRFRAME_INSTREN);
    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
}

void qspi_flash_write_command(uint8_t cmd, uint8_t* data, uint32_t len) 
{
	/* disable cache and invalidate */
	cmcc_write_CTRL(0);
	while(cmcc_get_SR(CMCC_SR_CSTS)) {};
	cmcc_write_MAINT0(CMCC_MAINT0_INVALL);

	
	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(cmd));
	qspi_write_INSTRFRAME((data == NULL) 
	                    ? (QSPI_INSTRFRAME_TFRTYPE_WRITE
      	                    | QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI
                            | QSPI_INSTRFRAME_ADDRLEN_24BITS
                            | QSPI_INSTRFRAME_INSTREN) 
                        : (QSPI_INSTRFRAME_TFRTYPE_WRITE
      	                    | QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI
                            | QSPI_INSTRFRAME_ADDRLEN_24BITS
                            | QSPI_INSTRFRAME_DATAEN
                            | QSPI_INSTRFRAME_INSTREN));   
    qspi_read_INSTRFRAME(); /* dummy read */
    if (data != NULL) {
   	 	memcpy((uint8_t *) QSPI_AHB, data, len);
    }
    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
    /* start CACHE */
    cmcc_write_CTRL(CMCC_CTRL_CEN);
}

void qspi_flash_read_command(uint8_t cmd, uint8_t* response, uint32_t len)
{
	/* disable cache and invalidate */
	cmcc_write_CTRL(0);
	while(cmcc_get_SR(CMCC_SR_CSTS)) {};
	cmcc_write_MAINT0(CMCC_MAINT0_INVALL);

	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(cmd));
	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_READ
		                | QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI
                        | QSPI_INSTRFRAME_DATAEN
                        | QSPI_INSTRFRAME_INSTREN);
    qspi_read_INSTRFRAME(); /* dummy read */
    memcpy(response, (uint8_t *) QSPI_AHB, len);

    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
    /* start CACHE */
    cmcc_write_CTRL(CMCC_CTRL_CEN);
}

void qpi_flash_command(uint8_t cmd)
{
	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(cmd));

	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_READ
		                | QSPI_INSTRFRAME_WIDTH_QUAD_CMD
                        | QSPI_INSTRFRAME_INSTREN);
    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);

}

void qpi_flash_read_command(uint8_t cmd, uint8_t* response, uint32_t len)
{
	/* disable cache and invalidate */
	cmcc_write_CTRL(0);
	while(cmcc_get_SR(CMCC_SR_CSTS)) {};
	cmcc_write_MAINT0(CMCC_MAINT0_INVALL);

	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(cmd));
	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_READ
		                | QSPI_INSTRFRAME_WIDTH_QUAD_CMD
                        | QSPI_INSTRFRAME_DATAEN
                        | QSPI_INSTRFRAME_INSTREN);
    qspi_read_INSTRFRAME(); /* dummy read */
    memcpy(response, (uint8_t *) QSPI_AHB, len);

    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
    /* start CACHE */
    cmcc_write_CTRL(CMCC_CTRL_CEN);
}

void qpi_flash_write_command(uint8_t cmd, uint8_t* data, uint32_t len)
{
	/* disable cache and invalidate */
	cmcc_write_CTRL(0);
	while(cmcc_get_SR(CMCC_SR_CSTS)) {};
	cmcc_write_MAINT0(CMCC_MAINT0_INVALL);

	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(cmd));
	qspi_write_INSTRFRAME((data == NULL)
	                    ? (QSPI_INSTRFRAME_TFRTYPE_WRITE
      	                    | QSPI_INSTRFRAME_WIDTH_QUAD_CMD
                            | QSPI_INSTRFRAME_INSTREN)
                        : (QSPI_INSTRFRAME_TFRTYPE_WRITE
      	                    | QSPI_INSTRFRAME_WIDTH_QUAD_CMD
                            | QSPI_INSTRFRAME_DATAEN
                            | QSPI_INSTRFRAME_INSTREN));
    qspi_read_INSTRFRAME(); /* dummy read */
    if (data != NULL) {
   	 	memcpy((uint8_t *) QSPI_AHB, data, len);
    }
    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
    /* start CACHE */
    cmcc_write_CTRL(CMCC_CTRL_CEN);
}

void qspi_flash_write_data(uint32_t adr, uint8_t* data, uint32_t len)
{
	/* disable cache and invalidate */
	cmcc_write_CTRL(0);
	while(cmcc_get_SR(CMCC_SR_CSTS)) {};
	cmcc_write_MAINT0(CMCC_MAINT0_INVALL);

	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(CMD_PAGE_PROGRAM));
	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_WRITEMEMORY
	                    | QSPI_INSTRFRAME_WIDTH_SINGLE_BIT_SPI
	                    | QSPI_INSTRFRAME_ADDRLEN_24BITS
	                    | QSPI_INSTRFRAME_INSTREN
	                    | QSPI_INSTRFRAME_ADDREN
	                    | QSPI_INSTRFRAME_DATAEN);

    memcpy(((uint8_t *) QSPI_AHB) + adr, data, len);

    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
    /* start CACHE */
    cmcc_write_CTRL(CMCC_CTRL_CEN);
}

void qspi_flash_read_data(uint32_t adr, uint8_t* data, uint32_t len)
{
	/* disable cache and invalidate */
	cmcc_write_CTRL(0);
	while(cmcc_get_SR(CMCC_SR_CSTS)) {};
	cmcc_write_MAINT0(CMCC_MAINT0_INVALL);

	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(CMD_FAST_READ_QUADOUT));
	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_READMEMORY
	                    | QSPI_INSTRFRAME_WIDTH_QUAD_OUTPUT
	                    | QSPI_INSTRFRAME_ADDRLEN_24BITS
	                    | QSPI_INSTRFRAME_INSTREN
	                    | QSPI_INSTRFRAME_ADDREN
	                    | QSPI_INSTRFRAME_DATAEN
	                    | QSPI_INSTRFRAME_DUMMYLEN(8));

   	memcpy(data, ((uint8_t *) QSPI_AHB) + adr, len);

    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
    /* start CACHE */
    cmcc_write_CTRL(CMCC_CTRL_CEN);
}

void qpi_flash_sector_command(uint8_t cmd, uint32_t adr)
{
	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(cmd));
	qspi_write_INSTRADDR(adr);
	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_WRITE
		                | QSPI_INSTRFRAME_WIDTH_QUAD_CMD
                        | QSPI_INSTRFRAME_ADDRLEN_24BITS
                        | QSPI_INSTRFRAME_ADDREN
                        | QSPI_INSTRFRAME_INSTREN);
    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
}

void qpi_flash_write_data(uint32_t adr, uint8_t* data, uint32_t len)
{
	/* disable cache and invalidate */
	cmcc_write_CTRL(0);
	while(cmcc_get_SR(CMCC_SR_CSTS)) {};
	cmcc_write_MAINT0(CMCC_MAINT0_INVALL);

	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(CMD_PAGE_PROGRAM));
	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_WRITEMEMORY
	                    | QSPI_INSTRFRAME_WIDTH_QUAD_CMD
	                    | QSPI_INSTRFRAME_ADDRLEN_24BITS
	                    | QSPI_INSTRFRAME_INSTREN
	                    | QSPI_INSTRFRAME_ADDREN
	                    | QSPI_INSTRFRAME_DATAEN);

    memcpy(((uint8_t *) QSPI_AHB) + adr, data, len);

    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
    /* start CACHE */
    cmcc_write_CTRL(CMCC_CTRL_CEN);
}

void enter_qpi_mode(void)
{
	uint8_t param = READ_PARAM_DUMMY_CLOCKS;
	qspi_flash_command(CMD_ENTER_QPI);
	qpi_flash_write_command(CMD_SET_READ_PARAMETERS, &param, 1);
}

void exit_qpi_mode(void)
{
	qpi_flash_write_command(CMD_EXIT_QPI, NULL, 0);
}

void qpi_flash_read_data(uint32_t adr, uint8_t* data, uint32_t len)
{
	/* disable cache and invalidate */
	cmcc_write_CTRL(0);
	while(cmcc_get_SR(CMCC_SR_CSTS)) {};
	cmcc_write_MAINT0(CMCC_MAINT0_INVALL);

	qspi_write_INSTRCTRL(QSPI_INSTRCTRL_INSTR(CMD_FAST_READ_QUADIO));
	qspi_write_INSTRFRAME(QSPI_INSTRFRAME_TFRTYPE_READMEMORY
	                    | QSPI_INSTRFRAME_WIDTH_QUAD_CMD
	                    | QSPI_INSTRFRAME_ADDRLEN_24BITS
	                    | QSPI_INSTRFRAME_INSTREN
	                    | QSPI_INSTRFRAME_ADDREN
	                    | QSPI_INSTRFRAME_DATAEN
	                    | QSPI_INSTRFRAME_DUMMYLEN(QPI_DUMMY_CLOCK_LEN));

   	memcpy(data, ((uint8_t *) QSPI_AHB) + adr, len);

    qspi_set_CTRLA(QSPI_CTRLA_ENABLE | QSPI_CTRLA_LASTXFER);
    while (qspi_get_INTFLAG(QSPI_INTFLAG_INSTREND) == 0);
    qspi_clear_INTFLAG(QSPI_INTFLAG_INSTREND);
    /* start CACHE */
    cmcc_write_CTRL(CMCC_CTRL_CEN);
}

void qspi_wait_flash_ready(void)
{
    uint8_t status;
	do {
    	qspi_flash_read_command(CMD_READ_STATUS1, &status, 1);
    } while ((status & STAT1_BUSY) != 0);
}

void qpi_wait_flash_ready(void)
{
    uint8_t status;
	do {
    	qpi_flash_read_command(CMD_READ_STATUS1, &status, 1);
    } while ((status & STAT1_BUSY) != 0);
}

void qspi_flash_init_device(void) {

    uint8_t status;
    uint8_t quadenabled[] = {0, STAT2_QE};
    // wait for not busy
	qspi_wait_flash_ready();
    // issue reset
	qspi_flash_command(CMD_ENABLE_RESET);
	qspi_flash_command(CMD_RESET);
	usDelay(30);
	// check if Quad SPI enabled, and enable it if it isn't
    qspi_flash_read_command(CMD_READ_STATUS2, &status, 1);

    if ((status & STAT2_QE) == 0) { // if flash isn't quad enabled, enable it now
    	// QE can be written one time programmable memory if OTP is defined
    	// Do not program SRL, LB1-LP3 as one these are always OTP
#ifdef OTP
#warning This permamently writes status
        qspi_flash_command(CMD_WRITE_ENABLE);
        qspi_flash_write_command(CMD_WRITE_STATUS1, quadenabled, 2);
		qspi_wait_flash_ready();
#else
        qspi_flash_command(CMD_VOLATILE_SR_WRITE_ENABLE);
        qspi_flash_write_command(CMD_WRITE_STATUS1, quadenabled, 2);
#endif
    }
}