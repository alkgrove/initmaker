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

#define I2CM_READY_Pos 0
#define I2CM_READY (1 << I2CM_READY_Pos)
#define I2CM_FAIL_Pos 1
#define I2CM_FAIL (1 << I2CM_FAIL_Pos)
#define I2CM_NACK_Pos 2
#define I2CM_NACK (1 << I2CM_NACK_Pos)

typedef enum {I2CM_OK = 0, I2CM_BUSBUSY, 
	I2CM_BUSFAULT, I2CM_ARBLOST, I2CM_NO_ACK, I2CM_BAD_MSG, I2CM_TIMEOUT} i2cm_err_t;
/**
 * @brief i2cmInit();
 * must be called before using i2c master
 * sets up FreeRTOS semaphore and enables NVIC interrupts
 */
	
void i2cmInit(void);

/**
 * @brief blocking write to I2C
 *
 * @param[in] uint8_t address 7bit I2C slave address
 * @param[in] uint8_t *wrbuf pointer to write buffer
 * @param[in] uint8_t wrlen length of bytes to write
 * @return i2cm_err_t 
 */
i2cm_err_t writeI2C(uint8_t address, uint8_t *wrbuf, uint8_t wrlen);

/**
 * @brief blocking read from I2C
 *
 * @param[in] uint8_t address 7bit I2C slave address
 * @param[in] uint8_t *wrbuf pointer to write buffer
 * @param[in] uint8_t wrlen number of bytes to write
 * @param[in] uint8_t *rdbuf pointer to read buffer
 * @param[in] uint8_t rdlen number of bytes to read
 * @return i2cm_err_t 
 */
i2cm_err_t readI2C(uint8_t address, uint8_t *wrbuf, uint8_t wrlen, uint8_t *rdbuf, uint8_t rdlen);

/**
 * @brief query if i2c slave responds at address
 *
 * @param[in] uint8_t address 7bit I2C slave address
 * @return bool return I2CM_NO_ACK if no device at address I2CM_OK if found
 */
i2cm_err_t probeI2C(uint8_t address);

/**
 * @brief non-blocking I2C transfer
 *
 * @param[in] uint8_t address 7bit I2C slave address
 * @param[in] uint8_t *wrbuf pointer to write buffer
 * @param[in] uint8_t wrlen number of bytes to write
 * @param[in] uint8_t *rdlen pointer to read buffer, null if write only
 * @param[in] uint8_t rdlen number of bytes to read
 * @return bool i2cm_err_t
 */
i2cm_err_t i2cm_transfer(uint8_t address, uint8_t *wrbuf, uint8_t wrlen, uint8_t *rdbuf, uint8_t rdlen);

const char *i2cm_err_str(int err);
#endif /* __I2CM_H__ */
