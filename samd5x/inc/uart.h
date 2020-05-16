/**
 * @file usart.h
 * @brief SAM UART
 * 
 * @note Copyright © Alkgrove 2018
 * @author Robert Alkire 
 * @date 03/22/2018
 * @version beta
 *
 * @par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * @par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * @par
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 **/

#ifndef __UART_H__
#define __UART_H__

#ifdef FEATURE_DBG_PORT
#define CONSOLE_PORT DBG_PORT
#else
#define CONSOLE_PORT COM_PORT
#endif

// Define FEATURE_UART_CRLF if using CR/LF (/r/n) for end of line
// otherwise /n line feed only
// #define FEATURE_UART_CRLF
// Define FEATURE_UART_ECHO if incoming characters are echoed
// #define FEATURE_UART_ECHO

#include "sam.h"
#include <stdio.h>
#include "core_cm4.h"

/**
 * @brief UART_putc
 * blocking send of a single character over the UART identified by port
 *
 * @param[in] ch - char 	character to send over serial
 * @param[in] SERCOM_t *dev 	pointer to SERCOM ie SERCOM0, SErCOM1
 */
static inline void UART_putc(int ch, SERCOM_t *dev)
{
	while((usart_read_INTFLAG(dev) & SERCOM_USART_INTFLAG_DRE) == 0); // while TX full
	usart_write_DATA(dev, (uint8_t) ch);
}

/**
 * @brief SWO_putc
 * blocking send of a single character over the UART identified by port
 *
 * @param[in] ch - char 	character to send over serial
 * @param[in] int channel	SWO Channel - must be enabled
 */
/* unfortunately PORT is popular name, so we push away so it plays well with CMSIS */
#pragma push_macro("PORT")
#undef PORT
static inline int SWO_putc(int ch, int channel)
{
  if (((ITM->TCR & ITM_TCR_ITMENA_Msk) != 0UL) &&  /* ITM enabled */
      ((ITM->TER & (1UL  << channel)) != 0UL)) {   /* ITM Port enabled */
		while (ITM->PORT[channel].u32 == 0UL) {
      		__NOP();
    	}
    	ITM->PORT[channel].u8 = (uint8_t) ch;
  }
  return (ch);
}
#pragma pop_macro("PORT")
/**
 * @brief UART_getc
 * blocking receive of a single character over the UART identified by port
 *
 * @param[in] SERCOM_t *dev 	pointer to SERCOM ie SERCOM0, SErCOM1
 */
 
static inline uint32_t UART_getc(SERCOM_t *dev)
{
	while((usart_read_INTFLAG(dev) & SERCOM_USART_INTFLAG_RXC) == 0); // wait for character
	return usart_read_DATA(dev);
}
/**
 * @brief UART_getc_ready
 * returns true if serial has received a character
 *
 * @param[in] SERCOM *dev pointer to sercom data structure
 */
static inline bool UART_getc_ready(SERCOM_t *dev)
{
	return ((usart_read_INTFLAG(dev) & SERCOM_USART_INTFLAG_RXC) != 0);
}

/**
 * @brief getstring(char* str, size_t len) 
 * similar to fgets except no file descriptor, everything comes from console
 *
 * @param[in] char *str pointer to character buffer to receive from
 * @param[in] size_t len length in bytes of the character buffer
 * @return pointer to character buffer
 */
char *getstring(char* str, size_t len);
/**
 * @brief putstring(const char* str);
 * similar to fputs except no file descriptor argument
 *
 * @param[in] char *str pointer to character buffer to send to console
 * @return 1 for success
 */
int putstring(const char* str);


#endif /* __USART_H__ */
