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

// Define UART_WINDOWS if using CR/LF (/r/n) for end of line
#define UART_WINDOWS
// Define UART_ECHO if incoming characters are echoed
#define UART_ECHO

#include "sam.h"
#include <stdio.h>
#include "core_cm4.h"

extern const FILE __COM[];
// Replacements for stdin, stdout and stderr. 
// This is to avoid RAM bloat from reent. 
extern FILE *serout;
extern FILE *serin;
extern FILE *sererr;

#define COM0 ((FILE * const)&__COM[0])
#define COM1 ((FILE * const)&__COM[1])
#define COM2 ((FILE * const)&__COM[2])
#define COM3 ((FILE * const)&__COM[3])
#define COM4 ((FILE * const)&__COM[4])
#define COM5 ((FILE * const)&__COM[5])
#define COM6 ((FILE * const)&__COM[6])
#define COM7 ((FILE * const)&__COM[7])
#define SWO0 ((FILE * const)&__COM[8])
#define SWO1 ((FILE * const)&__COM[9])
#define SWO2 ((FILE * const)&__COM[10])
#define SWO3 ((FILE * const)&__COM[11])
#define SWO4 ((FILE * const)&__COM[12])
#define SWO5 ((FILE * const)&__COM[13])
#define SWO6 ((FILE * const)&__COM[14])
#define SWO7 ((FILE * const)&__COM[15])


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
 * @brief getc_ready
 * returns true if serial has received a character
 *
 * @param[in] FILE *fp 	FILE Pointer to get device
 */
 
static inline bool getc_ready(FILE *fp)
{
	return (usart_read_INTFLAG(fp->dev) & SERCOM_USART_INTFLAG_RXC) != 0;
}


#endif /* __USART_H__ */
