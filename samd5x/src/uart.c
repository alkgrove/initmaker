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

FILE *serout = ((FILE * const)&__COM[0]);
FILE *serin = ((FILE * const)&__COM[0]);
FILE *sererr = ((FILE * const)&__COM[0]);
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
	return __wrap_putc(c, serout);
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
	return __wrap_fputs(str, serout);
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
 * Wrapper for polling fgets (linux and cygwin single threaded)
 * requires to be linked with the option -Wl,wrap=fgets
 * note because of potential buffer overflow, gets is not implemented
 * always null terminates the string, EOL is linefeed
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
		__wrap_putc(ch, serout);
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

/**
 * The following defines the gets function for FreeRTOS as a non-polling 
 * block on semaphore routine.
 * It is only for the console and should be used by only one task.
 * it must be initialized with initTaskConsoleGet()
 * it will wait for a semaphore to be given indicating end of line
 * and copy the string to a string buffer up to length or EOL which ever is smallest string.
 * the interrupt for CONSOLE_PORT must be enabled for RXC and priority set
 *
 **/
#ifdef USE_FREERTOS

static consoleInput_t consoleInput;

void SERCOM0_2_Handler(void) /* ISR for SERCOM0_UART_RXC priority 7  */
{
	char ch; 
	BaseType_t higherPriorityTaskWoken = pdFALSE;
	usart_clear_INTFLAG(CONSOLE_PORT, SERCOM_USART_INTFLAG_RXC);
	ch = (char) usart_read_DATA(CONSOLE_PORT);
	if (consoleInput.index < CONSOLE_INPUTBUFFER_SIZE-1) {
#ifdef UART_ECHO
		UART_putc(ch, CONSOLE_PORT);
#endif
		if ((ch == '\r') || (ch == '\n')) {
			ch = '\0';
		}
		if ((ch == '\b') || (ch == 0x7F)) {
			if (consoleInput.index > 0) consoleInput.index--;
		} else {
		    consoleInput.buffer[consoleInput.index++] = ch;
		}
	} else {
		ch = '\0';
		consoleInput.buffer[CONSOLE_INPUTBUFFER_SIZE-1] = '\0';
	}
	if (ch == '\0') {
 		usart_clear_INTEN(CONSOLE_PORT, SERCOM_USART_INTENCLR_RXC);
		xSemaphoreGiveFromISR(consoleInput.handle, &higherPriorityTaskWoken);
	}
	portYIELD_FROM_ISR(higherPriorityTaskWoken);	
}

void initTaskConsoleGet(void)
{
	consoleInput.index = 0;
	consoleInput.buffer[0] = '\0';
	consoleInput.handle = xSemaphoreCreateBinaryStatic(&consoleInput.semaphoreBuffer);
 	configASSERT( consoleInput.handle );
 	/* Start listening for a line to be sent */
 	usart_clear_INTFLAG(CONSOLE_PORT, SERCOM_USART_INTFLAG_RXC);
 	usart_set_INTEN(CONSOLE_PORT, SERCOM_USART_INTENSET_RXC);
 	/* semaphore comes up taken, so it will wait until it is given by eol from isr */
}
	

char *taskConsoleGets(char* str, size_t len, TickType_t timeToWait) 
{
	if (xSemaphoreTake(consoleInput.handle, timeToWait) == pdTRUE) {
		memcpy(str, consoleInput.buffer, MIN(len, consoleInput.index));
		consoleInput.index = 0;
		consoleInput.buffer[0] = '\0';
 		usart_set_INTEN(CONSOLE_PORT, SERCOM_USART_INTENSET_RXC);
		return str;
	} else {
		return NULL;
	}
}
#endif