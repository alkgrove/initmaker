/*
 * @file usart.h
 * @brief SAM USART
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
 */

#ifndef __USART_H__
#define __USART_H__

#define CONSOLE_PORT 0
#define DEFAULT_FD CONSOLE_PORT

/**
 * @brief UART_putc
 * blocking send of a single character over the UART identified by port
 *
 * @param[in] port - int 	id number of serial communications module 0 - 5 for SERCOM0 to SERCOM5
 * @param[in] ch - char 	character to send over serial
 */
void UART_putc(uint8_t port, char ch);
/**
 * @brief UART_haschar
 *
 * @param[in] port - int 	id number of serial communications module 0 - 5 for SERCOM0 to SERCOM5
 * @return boolean true if receive buffer has character, false if receive buffer empty
 */
bool UART_haschar(uint8_t port);
/**
 * @brief UART_getc
 * blocks for character to be received from UART and returns it
 * @param[in] port - int 	id number of serial communications module 0 - 5 for SERCOM0 to SERCOM5
 * @return uint32_t ch	character read from serial port
 */
uint32_t UART_getc(uint8_t port);
/**
 * @brief UART_gets
 * blocks for a line of characters received from UART and returns with characters written 
 * to null terminated string in buffer. It echos  characters and recognizes back space.
 * it will truncate lines longer than the buffer size
 *
 * @param[in] port - int 	id number of serial communications module 0 - 5 for SERCOM0 to SERCOM5
 * @param[in] buffer - char *	pointer to array of characters to hold line
 * @param[in] len - size_t 	number of bytes in above buffer
 */
void UART_gets(uint8_t port, char *buffer, size_t len);
/**
 * @brief UART_puts
 * blocking send of null terminated c string to UART
 *
 * @param[in] port - int 	id number of serial communications module 0 - 5 for SERCOM0 to SERCOM5
 * @param[in] src - char *	pointer to null terminate c string 
 */
void UART_puts(uint8_t port, const char *src);


#endif /* __USART_H__ */
