/**
 * @file spim.h
 * @brief SAM SPI Master
 * 
 * @note Copyright © Alkgrove 2018
 * @author Robert Alkire 
 * @date 04/18/2018
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

 
#ifndef __SPIM_H__
#define __SPIM_H__

typedef enum {SPIM_OK = 0, SPIM_ERROR} spi_err_t;
	
typedef struct {
	SERCOM_t *dev; /**< Pointer to serial port module registers ie SERCOM0 */
	uint8_t cs; /**< PINPORT of chip select pin */
	uint8_t *txbuf; /**< Pointer to allocated transmit buffer */
	uint8_t *rxbuf; /**< Pointer to allocated receive buffer */
	uint8_t len; /**< Number of bytes to send and receive */
} spim_msg_t;

/**
 * @brief SPI master transfer
 * write only then rxbuf = NULL
 * write and read buffers same length
 * @param[in] msg - spim_msg_t *
 * @return 0 ok, 1 not so ok
 */
spi_err_t spim_transfer(spim_msg_t *msg);


#endif /* __SPIM_H__ */
