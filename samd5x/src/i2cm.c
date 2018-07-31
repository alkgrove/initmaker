/*
 * i2cm.c
 * driver for SAMD51 I2C Master
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

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include "sam.h"


i2cm_err_t i2cm_enable(i2cm_msg_t *msg)
{
	int32_t timeout = 65535;
	i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_ENABLE | SERCOM_I2CM_SYNCBUSY_SWRST);
	i2cm_set_ENABLE(msg->dev);

	while (i2cm_get_BUSSTATE(msg->dev) != I2CM_BUSSTATE_IDLE) {
		if (--timeout <= 0) {
			i2cm_wait_for_sync(msg->dev, SERCOM_I2CM_SYNCBUSY_SYSOP);
			i2cm_write_STATUS(msg->dev, SERCOM_I2CM_STATUS_BUSSTATE(I2CM_BUSSTATE_IDLE));
			if(i2cm_get_BUSSTATE(msg->dev) != I2CM_BUSSTATE_IDLE) return I2CM_BUSFAULT;
		}
	}
	i2cm_set_INTEN(msg->dev, SERCOM_I2CM_INTENSET_MB
 	             		  | SERCOM_I2CM_INTENSET_SB
                		  | SERCOM_I2CM_INTENSET_ERROR);
    return I2CM_OK;
}

i2cm_err_t i2cm_transfer(i2cm_msg_t *msg)
{
	uint32_t timeout = 100000;
	while(i2cm_get_BUSSTATE(msg->dev) != I2CM_BUSSTATE_IDLE) {
		if (--timeout == 0) return I2CM_BUSBUSY;
	}

	i2cm_clear_ACKACT(msg->dev);

	// start the transfer by writing the target address
	i2cm_write_ADDR(msg->dev, SERCOM_I2CM_ADDR_ADDR(msg->address << 1 
		| (((msg->txlen == 0) && (msg->rxlen > 0)) ? I2CM_RD : 0)));

 	return I2CM_OK;
}







