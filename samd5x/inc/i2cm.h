/*
 * @file i2cm.h
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
 */
 
#ifndef __I2CM_H__
#define __I2CM_H__

#define I2CM_BUSY_Pos 0
#define I2CM_BUSY (1 << I2CM_BUSY_Pos)
#define I2CM_FAIL_Pos 1
#define I2CM_FAIL (1 << I2CM_FAIL_Pos)
#define I2CM_NACK_Pos 2
#define I2CM_NACK (1 << I2CM_NACK_Pos)

typedef enum {I2CM_OK = 0, I2CM_BUSBUSY, I2CM_BUSFAULT, I2CM_ARBLOST, I2CM_NO_ACK} i2cm_err_t;
	
typedef struct {
	SERCOM_t *dev;
	uint8_t *txbuf;
	uint8_t *rxbuf;
	uint8_t txlen;
	volatile uint8_t rxlen;
	volatile uint8_t address;
	volatile uint8_t status;
} i2cm_msg_t;

/**
 * @brief enable i2c
 * msg->dev must be set before using this
 * @param[in] msg - i2cm_msg_t * pointer to message packet
 * @return I2CM_OK if ok, non-zero if error
 */
 i2cm_err_t i2cm_enable(i2cm_msg_t *msg);
/**
 * @brief setup structure i2cm_msg_t with slave address,
 * pointer to transmit buffer with transmit length in bytes to send
 * pointer to receive buffer and length expected
 * if write only, then leave rxlen to zero and pointer to NULL
 * 
 * @param[in] msg - i2cm_msg_t * pointer to i2cm message structure
 * @return bool false if busy and cant start, true if transfer starts
 */
i2cm_err_t i2cm_transfer(i2cm_msg_t *msg);

/**
 * @brief ISR for master on bus 
 *
 * @param[in] msg - i2cm_msg_t * pointer to I2C Master structure
 */

static inline void i2cm_mb_isr(i2cm_msg_t *msg)
{
	uint16_t status = i2cm_read_STATUS(msg->dev);
	// This doesn't support multimaster
	// Getting an Lost arbitration or Bus error
	// means something is wrong with the I2C bus
	if (status & (SERCOM_I2CM_STATUS_ARBLOST | SERCOM_I2CM_STATUS_BUSERR)) {
		msg->status &= ~I2CM_BUSY;
		msg->status |= I2CM_FAIL;
		i2cm_clear_INTFLAG(msg->dev, SERCOM_I2CM_INTFLAG_MB);
	// Check for a NACK from a slave, this occurs if
	// no slave is present on the bus with the address 
	// Slave is busy with something else and can't respond.
	// Slave gets data or commands that it does not understand.
	// Slave cannot receive more data bytes
	// In any of these cases, mark the NACK and terminate the cycle
	} else if (status & SERCOM_I2CM_STATUS_RXNACK) {
			msg->status |= I2CM_NACK;
			msg->status &= ~I2CM_BUSY;
  			i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
  			i2cm_set_CMD(msg->dev, I2CM_CMD_STOP); // clears MB and issues stop
	} else if (msg->txlen > 0) {
		// we have data to write I2C, clears MB Int Flag
  		i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
		i2cm_write_DATA(msg->dev,*msg->txbuf++);
		msg->txlen--;
	} else { // done with transmit, check if receive follows
  		if (msg->rxlen > 0) {
  			// automatically ack to slave while rxlen > 0
  			i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
  			i2cm_clear_ACKACT(msg->dev);
  			//  force a repeated Start by sending  address, clears MB int flag
  			i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
			i2cm_write_ADDR(msg->dev, SERCOM_I2CM_ADDR_ADDR((msg->address << 1) | I2CM_RD));
		} else { // rxlen == 0, no receive then issue stop, clears MB Int flag
  			i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
  			i2cm_set_CMD(msg->dev, I2CM_CMD_STOP);
			msg->status &= ~I2CM_BUSY;
		}
	}
}

/**
 * @brief ISR for slave on bus 
 *
 * @param[in] msg - i2cm_msg_t * pointer to I2C Master structure
 */

static inline void i2cm_sb_isr(i2cm_msg_t *msg)
{
	
    if (msg->rxlen > 0) {
		msg->rxlen--;
        if (msg->rxlen == 0) {
  			i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
			i2cm_set_ACKACT(msg->dev); // send a NACK for last byte read
 			i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
  			i2cm_set_CMD(msg->dev, I2CM_CMD_STOP);
			msg->status &= ~I2CM_BUSY;
		}
		*msg->rxbuf++ = i2cm_read_DATA(msg->dev); // clears SB
	} 
	i2cm_clear_INTFLAG(msg->dev, SERCOM_I2CM_INTFLAG_SB);
}

/**
 * @brief This is error interrupt for I2C
 *
 * @param[in] msg - i2cm_msg_t * pointer to I2C Master structure
 */
static inline void i2cm_error_isr(i2cm_msg_t *msg)
{
	msg->status |=  I2CM_FAIL;
	msg->status &= ~I2CM_BUSY;
	i2cm_clear_INTFLAG(msg->dev, SERCOM_I2CM_INTFLAG_ERROR);
}

#endif /* __I2CM_H__ */
