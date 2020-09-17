/*
 * uart.c
 * basic blocking UART driver for SAMD51
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
#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "sam.h"

/*
 * Wrapper for putchar
 * requires to be linked with the option -Wl,wrap=putchar
 */

int __wrap_putchar(int c) 
{
	UART_putc(c, CONSOLE_PORT);
	return 1;
}
/*
 * Wrapper for puts
 * requires to be linked with the option -Wl,wrap=puts
 */

int __wrap_puts(const char* str)
{
	while(*str != '\0') {
	    UART_putc(*str++, CONSOLE_PORT);
	}
#ifdef FEATURE_UART_CRLF
	UART_putc('\r', CONSOLE_PORT);
#endif
	UART_putc('\n', CONSOLE_PORT);
	return 1;
}
/*
 * it is for situations that do not require CRLF or LF appended
 */
int puts_nonl(const char* str)
{
	while(*str != '\0') {
	    UART_putc(*str++, CONSOLE_PORT);
	}
	return 1;
}

/*
 * Wrapper for getchar
 * requires to be linked with the option -Wl,wrap=getchar
 */
 
int __wrap_getchar(void)
{
    int ch;
    ch = UART_getc(CONSOLE_PORT);
#ifdef FEATURE_UART_ECHO
	UART_putc(ch, CONSOLE_PORT);
#endif
	return ch;
}


/* 
 * getns
 * similar to gets but requires a length of array for dst
 * this behaves more like fgets but to console and no FILE *
 */
 
char *getns(char *dst, size_t len)
{
	int ch = 0;
	size_t i = 0;
	
	while(true) {
        ch = UART_getc(CONSOLE_PORT);
        if ((ch == '\n') || (ch == '\r')) break;
#ifdef FEATURE_UART_ECHO
	    UART_putc(ch, CONSOLE_PORT);
#endif
		if (ch < 0) return NULL;
		if ((ch == '\b') || (ch == 0x7F)) {
            if (i > 0) {
                i--;
#ifdef FEATURE_UART_ECHO
                UART_putc('\b', CONSOLE_PORT);
	            UART_putc(' ', CONSOLE_PORT);
	            UART_putc('\b', CONSOLE_PORT);
#endif
            }
		} else {
		    if (i >= len) {
#ifdef FEATURE_UART_ECHO
#ifdef FEATURE_UART_OVERFLOW_BELL
	            UART_putc('\a', CONSOLE_PORT);
#endif
#endif
                break;
		    }
		    dst[i++] = ch;
		}
	}
#ifdef FEATURE_UART_ECHO
#ifdef FEATURE_UART_CRLF
	UART_putc('\r', CONSOLE_PORT);
#endif
	UART_putc('\n', CONSOLE_PORT);
#endif
	dst[i] = '\0';
	return dst;
}
