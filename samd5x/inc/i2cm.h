/**
 * @file i2cm.h
 *
 * @brief SAM I2CM
 * 
 * @note Copyright © Alkgrove 2018
 * @author Robert Alkire 
 * @date 04/6/2018
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
 
#ifndef __I2CM_H__
#define __I2CM_H__

#define I2CM_BUSY_Pos 0
#define I2CM_BUSY (1 << I2CM_BUSY_Pos)
#define I2CM_FAIL_Pos 1
#define I2CM_FAIL (1 << I2CM_FAIL_Pos)
#define I2CM_NACK_Pos 2
#define I2CM_NACK (1 << I2CM_NACK_Pos)

typedef enum {I2CM_OK = 0, I2CM_BUSBUSY, I2CM_BUSFAULT, I2CM_ARBLOST, I2CM_NO_ACK, I2CM_BAD_MSG, I2CM_TIMEOUT} i2cm_err_t;
	
typedef struct {
	const SERCOM_t *dev;   /**< Pointer to serial port module registers ie SERCOM0 */
	const uint8_t sda; /**< I2C Data Port */
	const uint8_t scl; /**< I2C Clock Port */
	uint8_t *txbuf;  /**< Pointer to allocated transmit buffer */
	uint8_t *rxbuf;  /**< Pointer to allocated receive buffer */
	uint8_t txlen;   /**< Number of bytes to transmit */
	uint8_t rxlen; /**< Number of bytes expected to receive */
	uint8_t address; /**< I2C slave address */
	uint8_t status; /**< Status of transfer: I2CM_BUSY, I2CM_FAIL or I2CM_NACK */
} i2cm_msg_t;

/**
 * @brief blocking write to I2C
 *
 * @param[in] i2cm_msg_t *msg
 * @param[in] uint8_t address 7bit I2C slave address
 * @param[in] uint8_t *wrbuf pointer to write buffer
 * @param[in] uint8_t wrlen length of bytes to write
 * @return i2cm_err_t 
 */
i2cm_err_t writeI2C(volatile i2cm_msg_t *msg, uint8_t address, uint8_t *wrbuf, uint8_t wrlen);

/**
 * @brief blocking read from I2C
 *
 * @param[in] i2cm_msg_t *msg
 * @param[in] uint8_t address 7bit I2C slave address
 * @param[in] uint8_t *wrbuf pointer to write buffer
 * @param[in] uint8_t wrlen number of bytes to write
 * @param[in] uint8_t *rdbuf pointer to read buffer
 * @param[in] uint8_t rdlen number of bytes to read
 * @return i2cm_err_t 
 */
i2cm_err_t readI2C(volatile i2cm_msg_t *msg, uint8_t address, uint8_t *wrbuf, uint8_t wrlen, uint8_t *rdbuf, uint8_t rdlen);

/**
 * @brief query if i2c slave responds at address
 *
 * @param[in] i2cm_msg_t *msg
 * @param[in] uint8_t address 7bit I2C slave address
 * @return bool return I2CM_NO_ACK if no device at address I2CM_OK if found
 */
i2cm_err_t probeI2C(volatile i2cm_msg_t *msg, uint8_t address);

/**
 * @brief non-blocking I2C transfer
 *
 * @param[in] i2cm_msg_t *msg
 * @param[in] uint8_t address 7bit I2C slave address
 * @param[in] uint8_t *wrbuf pointer to write buffer
 * @param[in] uint8_t wrlen number of bytes to write
 * @param[in] uint8_t *rdlen pointer to read buffer, null if write only
 * @param[in] uint8_t rdlen number of bytes to read
 * @return bool i2cm_err_t
 */
i2cm_err_t i2cm_transfer(volatile i2cm_msg_t *msg, uint8_t address, uint8_t *wrbuf, uint8_t wrlen, uint8_t *rdbuf, uint8_t rdlen);

#endif /* __I2CM_H__ */
