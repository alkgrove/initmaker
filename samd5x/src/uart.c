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

#ifdef FEATURE_DBG_PORT
#ifndef DBG_PORT
#error define name of SERCOM to DBG_PORT in initmaker config or #define DBG_PORT SERCOMn
#endif
#else
#ifndef COM_PORT
#error define name of SERCOM to COM_PORT in initmaker config or #define COM_PORT SERCOMn
#endif
#endif
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
		putchar(*str++);
	}
#ifdef EOL_IS_CRLF
	putchar('\r');
#endif
	putchar('\n');
	return 1;
}

/*
 * similar to fputs except without the file descriptor
 */

int putstring(const char* str)
{
	while(*str != '\0') {
		putchar(*str++);
	}
	return 1;
}
/*
 * Wrapper for getchar
 * requires to be linked with the option -Wl,wrap=getchar
 */
 
int __wrap_getchar(void)
{
	return UART_getc(CONSOLE_PORT);
}

/*
 * similar to fgets except no file descriptor
 * note because of potential buffer overflow, gets is not implemented
 * always null terminates the string, EOL is linefeed
 */

char *getstring(char* str, size_t len) 
{
	int ch = 0;
	int i = 0;
	len--;
	while((i < len) && (ch != '\n')) {
		ch = getchar();
		if (ch < 0) return NULL;
#ifdef UART_ECHO
		putchar(ch);
#endif
		if (ch == '\r') {
			ch = '\n';
		}
		if ((ch == '\b') || (ch == 0x7F)) {
			if (i > 0) i--;
		} else {
		    str[i++] = ch;
		}
	}
	str[i] = '\0';
	return str;
}
