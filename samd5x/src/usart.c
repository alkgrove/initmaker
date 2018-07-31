/*
 * usart.c
 * basic blocking USART driver for SAMD51
 * 
 * Copyright © Alkgrove 2018
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
 */

#include <stdbool.h>
#include <stdint.h>
#include "sam.h"

static SERCOM_t *USART_PORTS[] = SERCOM_INSTS;
// blocking put character
void UART_putc(uint8_t port, char ch)
{
	SERCOM_t *io = USART_PORTS[port];
	while((usart_read_INTFLAG(io) & SERCOM_USART_INTFLAG_DRE) == 0); // while TX full
	usart_write_DATA(io, ch);
}
// return true if receive buffer in UART has a character to read
bool UART_haschar(uint8_t port)
{
	SERCOM_t *io = USART_PORTS[port];
	return (usart_read_INTFLAG(io) & SERCOM_USART_INTFLAG_RXC) != 0;
}
// blocking get character from UART
uint32_t UART_getc(uint8_t port)
{
	SERCOM_t *io = USART_PORTS[port];
	while((usart_read_INTFLAG(io) & SERCOM_USART_INTFLAG_RXC) == 0); // wait for character
	return usart_read_DATA(io);
}

// blocking get string from UART
// handles carraige return and backspace
// local echo of characters
void UART_gets(uint8_t port, char *buffer, size_t len)
{
	int ch;
	int i = 0;

	while(i < len) {
		ch = UART_getc(port);
		if (ch >= 0) {
			UART_putc(port, ch);
			if (ch == '\r') {
			    UART_putc(port, '\n');
			    break;
			}
            if (i > 0 && ch == '\b') {
				i--;
				UART_putc(port, '\b');
				UART_putc(port, ' ');
				UART_putc(port, '\b');				
			} else {
				buffer[i++] = ch;
			}
		}
	}
	buffer[i] = '\0';
}
// blocking put string to UART
void UART_puts(uint8_t port, const char *src)
{
    while(*src != '\0') {
        UART_putc(port, *src++);
    }
}

