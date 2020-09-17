/**
 * @file nvm.c
 * @brief driver for erasing and writing to nvm flash
 * @detail prototypes in nvmctrl.h file
 * @copyright Copyright © Alkgrove 2020
 * @author Robert Alkire 
 * @date 01/15/2019 update 3/9/2020
 *
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
#include "sam.h"

void nvm_erase_block(uint32_t *dst)
{
	nvm_wait_ready();
	nvmctrl_write_ADDR((uint32_t) dst);
	nvmctrl_write_CTRLB(NVMCTRL_CTRLB_CMDEX_KEY | NVMCTRL_CTRLB_CMD_EB);
}

bool nvm_is_block_erased(uint32_t *src)
{
    uint32_t *ep = &src[NVMCTRL_BLOCK_SIZE/sizeof(uint32_t)];
    while(src < ep) {
        if (*src != 0xFFFFFFFF) return false;
    }
    return true;
}

int nvm_write_block(uint32_t *dst, uint32_t *src)
{
	/* we want more sanity checks for flash writes here */
	if (!nvm_on_block_boundary(dst)) return FLASH_BAD_BLOCK_ADDRESS;
	nvm_wait_ready();
	for (int pages = 0; pages < (NVMCTRL_BLOCK_SIZE / NVMCTRL_PAGE_SIZE); pages++) {
    	/* writing the block, set manual mode */
    	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_WMODE_MAN);
    	nvm_wait_ready();	
    	/* Clear Page Buffer */
    	nvmctrl_write_CTRLB(NVMCTRL_CTRLB_CMDEX_KEY | NVMCTRL_CTRLB_CMD_PBC);
    	nvm_wait_ready();	
    	/* we must write 32 bit words to 512 byte page buffer */
    	/* adjust PAGE_SIZE (in bytes) to words and copy words to page buffer */
    	/* disable the cache */
    	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_CACHEDIS0);
    	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_CACHEDIS1);
    	
    	for (int i = 0; i < (NVMCTRL_PAGE_SIZE/sizeof(uint32_t)); i++) {
    		*dst++ = *src++;
    	}
    	nvmctrl_clear_CTRLA(NVMCTRL_CTRLA_CACHEDIS0);
    	nvmctrl_clear_CTRLA(NVMCTRL_CTRLA_CACHEDIS1);
	
    	/* then write the page to flash */
    	nvmctrl_write_CTRLB(NVMCTRL_CTRLB_CMDEX_KEY | NVMCTRL_CTRLB_CMD_WP);
	}
	return FLASH_BLOCK_WRITE_OK;
}

int nvm_write_page(uint32_t *dst, uint32_t *src)
{
	/* we want more sanity checks for flash writes here */
	if (!nvm_on_page_boundary(dst)) return FLASH_BAD_PAGE_ADDRESS;
	nvm_wait_ready();
  	/* writing the page, set manual mode */
  	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_WMODE_MAN);
  	nvm_wait_ready();	
  	/* Clear Page Buffer */
  	nvmctrl_write_CTRLB(NVMCTRL_CTRLB_CMDEX_KEY | NVMCTRL_CTRLB_CMD_PBC);
  	nvm_wait_ready();	
  	/* we must write 32 bit words to 512 byte page buffer */
  	/* adjust PAGE_SIZE (in bytes) to words and copy words to page buffer */
  	/* disable the cache */
  	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_CACHEDIS0);
  	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_CACHEDIS1);
  	
  	for (int i = 0; i < (NVMCTRL_PAGE_SIZE/sizeof(uint32_t)); i++) {
  		*dst++ = *src++;
  	}
  	nvmctrl_clear_CTRLA(NVMCTRL_CTRLA_CACHEDIS0);
  	nvmctrl_clear_CTRLA(NVMCTRL_CTRLA_CACHEDIS1);

  	/* then write the page to flash */
  	nvmctrl_write_CTRLB(NVMCTRL_CTRLB_CMDEX_KEY | NVMCTRL_CTRLB_CMD_WP);
    	
	return FLASH_PAGE_WRITE_OK;
}
	
int nvm_write_quadword(uint32_t *dst, uint32_t *src)
{
    if (((uint32_t) dst % 16) != 0) return FLASH_BAD_BLOCK_ADDRESS;
	nvm_wait_ready();
  	/* writing the WQW, set manual mode */
  	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_WMODE_MAN);
  	nvm_wait_ready();	
  	/* Clear page buffer */
  	nvmctrl_write_CTRLB(NVMCTRL_CTRLB_CMDEX_KEY | NVMCTRL_CTRLB_CMD_PBC);
  	nvm_wait_ready();	
  	/* disable the cache - see errata */
  	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_CACHEDIS0);
  	nvmctrl_set_CTRLA(NVMCTRL_CTRLA_CACHEDIS1);
  	/* write to page buffer */
  	*dst++ = *src++;
  	*dst++ = *src++;
  	*dst++ = *src++;
  	*dst++ = *src++;
  	nvmctrl_clear_CTRLA(NVMCTRL_CTRLA_CACHEDIS0);
  	nvmctrl_clear_CTRLA(NVMCTRL_CTRLA_CACHEDIS1);
   	/*  write the page to flash */
  	nvmctrl_write_CTRLB(NVMCTRL_CTRLB_CMDEX_KEY | NVMCTRL_CTRLB_CMD_WQW);
  	
	return FLASH_BLOCK_WRITE_OK;
}

bool nvm_verify_block(uint32_t *dst, uint32_t *src)
{
	for(int i = 0; i < (NVMCTRL_BLOCK_SIZE / sizeof(uint32_t)); i++) {
		if (*dst++ != *src++) return false;
	}
	return true;
}

bool nvm_verify_page(uint32_t *dst, uint32_t *src)
{
	for(int i = 0; i < (NVMCTRL_PAGE_SIZE / sizeof(uint32_t)); i++) {
		if (*dst++ != *src++) return false;
	}
	return true;
}

