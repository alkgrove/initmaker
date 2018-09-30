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
#include "uart.h"
#include "sam.h"

const FILE __COM[] = {
	{.type=SERIAL_COM, .dev=SERCOM0},
    {.type=SERIAL_COM, .dev=SERCOM1},
    {.type=SERIAL_COM, .dev=SERCOM2},
    {.type=SERIAL_COM, .dev=SERCOM3},
    {.type=SERIAL_COM, .dev=SERCOM4},
    {.type=SERIAL_COM, .dev=SERCOM5},
    {0},
    {0},
    {.type=SWO_COM, .io=0},
    {.type=SWO_COM, .io=1},
    {.type=SWO_COM, .io=2},
    {.type=SWO_COM, .io=3},
    {.type=SWO_COM, .io=4},
    {.type=SWO_COM, .io=5},
    {.type=SWO_COM, .io=6},
    {.type=SWO_COM, .io=7}
};


/*
 * Wrapper for putc
 * requires to be linked with the option -Wl,wrap=putc
 */

int __wrap_putc(int c, FILE *fp)
{
	if (fp == NULL) return EOF;
	if (fp->type == SERIAL_COM) {
		UART_putc(c, fp->dev);
	} else if (fp->type == SWO_COM) {
		SWO_putc(c, fp->io);
	}
	return c;
}

/*
 * Wrapper for putc
 * requires to be linked with the option -Wl,wrap=putc
 */

int __wrap_putchar(int c)
{
	return __wrap_putc(c, stdout);
}
/*
 * Wrapper for fputs
 * requires to be linked with the option -Wl,wrap=fputs
 */

int __wrap_fputs (const char* str, FILE *fp) 
{
	while(*str != '\0') {
		__wrap_putc(*str++, fp);
	}
#ifdef UART_WINDOWS
	__wrap_putc('\r', fp);
#endif
	__wrap_putc('\n', fp);
	return 1;
}

/*
 * Wrapper for puts
 * requires to be linked with the option -Wl,wrap=puts
 */

int __wrap_puts(const char* str) 
{
	return __wrap_fputs(str, stdout);
}
/*
 * Wrapper for getc
 * requires to be linked with the option -Wl,wrap=getc
 */
 
int __wrap_getc(FILE *fp)
{
	if ((fp != NULL) && (fp->type == SERIAL_COM)) {
		return UART_getc(fp->dev);
	} 
	return EOF;
}

/*
 * Wrapper for fgets
 * requires to be linked with the option -Wl,wrap=fgets
 * note because of potential buffer overflow, gets is not implemented
 */
 
 
/* linux and cygwin fgets 
 * reading stdin from a terminal puts the EOL character as linefeed even if return is hit
 * when reading a windows text file, it puts CRLF at the end of the line.
 * if the buffer overflows at length - 1, it returns without a EOL character but 
 * always null terminates the string. 
 * Also using either ctrl-j or ctrl-m, both terminate the line and puts LF as EOL
 * since fgets in this context is only used for serial IO, an EOL will be LF
 */


char *__wrap_fgets(char* str, size_t len, FILE *fp) 
{
	int ch = 0;
	int i = 0;
	len--;
	while((i < len) && (ch != '\n')) {
		ch = __wrap_getc(fp);
		if (ch < 0) return NULL;
#ifdef UART_ECHO
		__wrap_putc(ch, fp);
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

