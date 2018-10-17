/**
 * @note This file is modified from the Atmel ASF4 hri include
 * by Alkgrove 2018
 * @version beta
**/
/**
 * @file gpio.h
 *
 * @brief GPIO (PORT)
 *
 * Copyright (C) 2014 Atmel Corporation. All rights reserved.
 *
 * @asf_license_start
 *
 * @page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @asf_license_stop
 */
 
 /*
  * @note GPIO drivers are pin oriented and as such set up as bits.
  * As such, it has more sets and gets of bits
  */
#ifndef __GPIO_H__
#define __GPIO_H__

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Macros for the pin and port group, lower 5
 * bits are pin number in the group, higher 3
 * bits are the port group A, B etc
 */
#define GPIO_PIN(n) (((n)&0x1Fu) << 0)
#define GPIO_PORT(n) ((n) >> 5)
#define GPIO(port, pin) ((((port)&0x7u) << 5) + ((pin)&0x1Fu))

// pin function
#define GPIO_PIN_FUNCTION_OFF 0xff 	/**< \brief PORT Function Off (GPIO Mode) */
#define GPIO_PIN_FUNCTION_A 0		/**< \brief PORT Function A (EIC) */
#define GPIO_PIN_FUNCTION_B 1		/**< \brief PORT Function B (Analog) */
#define GPIO_PIN_FUNCTION_C 2		/**< \brief PORT Function C (SERCOM) */
#define GPIO_PIN_FUNCTION_D 3		/**< \brief PORT Function D (SERCOM) */
#define GPIO_PIN_FUNCTION_E 4		/**< \brief PORT Function E (TC) */
#define GPIO_PIN_FUNCTION_F 5		/**< \brief PORT Function F (TCC) */
#define GPIO_PIN_FUNCTION_G 6		/**< \brief PORT Function G (TCC, PDEC) */
#define GPIO_PIN_FUNCTION_H 7		/**< \brief PORT Function H (QSPI, CAN, USB, CM4) */
#define GPIO_PIN_FUNCTION_I 8		/**< \brief PORT Function I (SDHC, CAN) */
#define GPIO_PIN_FUNCTION_J 9		/**< \brief PORT Function J (I2S) */
#define GPIO_PIN_FUNCTION_K 10		/**< \brief PORT Function K (PCC) */
#define GPIO_PIN_FUNCTION_L 11		/**< \brief PORT Function L (GMAC) */
#define GPIO_PIN_FUNCTION_M 12		/**< \brief PORT Function M (GCLK, AC) */
#define GPIO_PIN_FUNCTION_N 13		/**< \brief PORT Function N (CCL) */

#define PORT_EVCTRL_PID_Pos        0            /**< \brief (PORT_EVCTRL) PORT Event Pin Identifier 0 */
#define PORT_EVCTRL_PID_Msk        (_U_(0x1F) << PORT_EVCTRL_PID_Pos)
#define PORT_EVCTRL_PID(value)     (PORT_EVCTRL_PID_Msk & ((value) << PORT_EVCTRL_PID_Pos))
#define PORT_EVCTRL_EVACT_Pos      5            /**< \brief (PORT_EVCTRL) PORT Event Action 0 */
#define PORT_EVCTRL_EVACT_Msk      (_U_(0x3) << PORT_EVCTRL_EVACT_Pos)
#define PORT_EVCTRL_EVACT(value)   (PORT_EVCTRL_EVACT0_Msk & ((value) << PORT_EVCTRL_EVACT0_Pos))
#define   PORT_EVCTRL_EVACT_OUT_Val      _U_(0x0)   /**< \brief (PORT_EVCTRL) Event output to pin */
#define   PORT_EVCTRL_EVACT_SET_Val      _U_(0x1)   /**< \brief (PORT_EVCTRL) Set output register of pin on event */
#define   PORT_EVCTRL_EVACT_CLR_Val      _U_(0x2)   /**< \brief (PORT_EVCTRL) Clear output register of pin on event */
#define   PORT_EVCTRL_EVACT_TGL_Val      _U_(0x3)   /**< \brief (PORT_EVCTRL) Toggle output register of pin on event */
#define PORT_EVCTRL_EVACT_OUT      (PORT_EVCTRL_EVACT_OUT_Val    << PORT_EVCTRL_EVACT_Pos)
#define PORT_EVCTRL_EVACT_SET      (PORT_EVCTRL_EVACT_SET_Val    << PORT_EVCTRL_EVACT_Pos)
#define PORT_EVCTRL_EVACT_CLR      (PORT_EVCTRL_EVACT_CLR_Val    << PORT_EVCTRL_EVACT_Pos)
#define PORT_EVCTRL_EVACT_TGL      (PORT_EVCTRL_EVACT_TGL_Val    << PORT_EVCTRL_EVACT_Pos)
#define PORT_EVCTRL_PORTEI_Pos     7            /**< \brief (PORT_EVCTRL) PORT Event Input Enable */
#define PORT_EVCTRL_PORTEI         (_U_(0x1) << PORT_EVCTRL_PORTEI0_Pos)
#define PORT_EVCTRL_Msk            _U_(0xFF)
#define PORT_EVCTRL0_Pos 			0
#define PORT_EVCTRL1_Pos 			8
#define PORT_EVCTRL2_Pos 			16
#define PORT_EVCTRL3_Pos 			24

/**
 * @brief PORT pull mode settings
 */
typedef enum { GPIO_PULL_OFF = 0, GPIO_PULL_UP, GPIO_PULL_DOWN } gpio_pull_t;
/**
 * @brief drive strength settings 
 */
typedef enum {NORMAL_DRIVE = 0, HIGH_DRIVE} gpio_drive_t;
/**
 * @brief PORT direction settins
 */
typedef enum { GPIO_DIRECTION_OFF = 0, GPIO_DIRECTION_IN, GPIO_DIRECTION_OUT } gpio_direction_t;

/**
 * @brief PORT group abstraction
 */
typedef enum { PORTA = 0, PORTB, PORTC, PORTD, PORTE } portgroup_t;

/**
 * @brief Set pin direction as an output for port/pin
 * it sets output drive to normal and pin function to GPIO
 * call gpio_set_high_drive() to change drive and port_set_pin_function() to change function
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 *
 */
static inline void gpio_set_dir_out(const uint8_t portpin) 
{
	uint32_t config = PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_WRPMUX;
	if (GPIO_PIN(portpin) < 16) {
		config |= 1U << GPIO_PIN(portpin);
	} else {
		config |= PORT_WRCONFIG_HWSEL | 1U << (GPIO_PIN(portpin) - 16);
	}
  	PORT->Group[GPIO_PORT(portpin)].DIRSET.reg = 1U << GPIO_PIN(portpin); // set as output pin
	PORT->Group[GPIO_PORT(portpin)].WRCONFIG.reg = config; // update config
}
 
/**
 * @brief Set pin direction as an input on port/pin
 * it sets pin function to GPIO and no pullup or pulldown
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 */
static inline void gpio_set_dir_in(const uint8_t portpin)
{
	uint32_t config = PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_INEN | PORT_WRCONFIG_WRPMUX; // note PORT_WRCONFIG_WRPMUX may not be necessary here
	if (GPIO_PIN(portpin) < 16) {
		config |= 1U << GPIO_PIN(portpin);
	} else {
		config |= PORT_WRCONFIG_HWSEL | 1U << (GPIO_PIN(portpin) - 16);
	}
  	PORT->Group[GPIO_PORT(portpin)].DIRCLR.reg = 1U << GPIO_PIN(portpin); // set as input pin
	PORT->Group[GPIO_PORT(portpin)].WRCONFIG.reg = config; // update config
}

/**
 * @brief Set pin direction as an off on port/pin
 * GPIO for this port/pin is turned off and is hi-z
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 */
static inline void gpio_set_dir_off(const uint8_t portpin)
{
	uint32_t config = PORT_WRCONFIG_WRPINCFG;
	if (GPIO_PIN(portpin) < 16) {
		config |= 1U << GPIO_PIN(portpin);
	} else {
		config |= PORT_WRCONFIG_HWSEL | 1U << (GPIO_PIN(portpin) - 16);
	}
  	PORT->Group[GPIO_PORT(portpin)].DIRCLR.reg = 1U << GPIO_PIN(portpin); // set as input with inen disabled
	PORT->Group[GPIO_PORT(portpin)].WRCONFIG.reg = config; // update config
}

/**
 * @brief Get pin direction on PORTA, PORTB
 *
 * @param[in] portindex - portgroup_t  Ports are grouped into groups of maximum 32 pins,
 *                      PORTA = group 0, PORTB = group 1, etc
 * @return uint32_t direction '1' is output, '0' is input
 */

static inline uint32_t gpio_read_DIR(const portgroup_t portindex) 
{
	return PORT->Group[portindex].DIR.reg;
}

/**
 * @brief set port pin high drive
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 */
static inline void gpio_set_high_drive(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].PINCFG[GPIO_PIN(portpin)].reg |= PORT_PINCFG_DRVSTR;
}

/**
 * @brief set port pin to normal drive
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 */
static inline void gpio_set_normal_drive(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].PINCFG[GPIO_PIN(portpin)].reg &= ~PORT_PINCFG_DRVSTR;
}

/**
 * @brief set port pin to Pull up, down or off
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @param[in] pull - gpio_pull_t  GPIO_PULL_OFF, GPIO_PULL_UP, GPIO_PULL_DOWN
 */
static inline void gpio_set_pull(const uint8_t portpin, const gpio_pull_t pull)
{
	if (pull == GPIO_PULL_UP) {
		PORT->Group[GPIO_PORT(portpin)].PINCFG[GPIO_PIN(portpin)].reg |= PORT_PINCFG_PULLEN;
  		PORT->Group[GPIO_PORT(portpin)].OUTSET.reg = 1U << GPIO_PIN(portpin);
  	} else if (pull == GPIO_PULL_DOWN) {
		PORT->Group[GPIO_PORT(portpin)].PINCFG[GPIO_PIN(portpin)].reg |= PORT_PINCFG_PULLEN;
   		PORT->Group[GPIO_PORT(portpin)].OUTCLR.reg = 1U << GPIO_PIN(portpin);
  	} else {
		PORT->Group[GPIO_PORT(portpin)].PINCFG[GPIO_PIN(portpin)].reg &= ~PORT_PINCFG_PULLEN;
	}  	
}
/**
 * @brief Set pin function on port/pin
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @param[in] pinfunction - uint8_t  GPIO_PIN_FUNCTION_OFF, GPIO_PIN_FUNCTION_A to GPIO_PIN_FUNCTION_N
 * @note also can be from includes/pio defines ie MUX_PA04D_SERCOM0_PAD0
 */

static inline void port_set_pin_function(const uint8_t portpin, const uint8_t pinfunction)
{
	uint32_t config = (pinfunction == GPIO_PIN_FUNCTION_OFF) ? 
	                                    PORT_WRCONFIG_WRPINCFG 
                                        : (PORT_WRCONFIG_WRPINCFG
                                    	| PORT_WRCONFIG_WRPMUX 
                                    	| PORT_WRCONFIG_PMUXEN 
                                    	| PORT_WRCONFIG_PMUX(pinfunction));
	if (GPIO_PIN(portpin) < 16) {
		config |= 1U << GPIO_PIN(portpin);
	} else {
		config |= PORT_WRCONFIG_HWSEL | 1U << (GPIO_PIN(portpin) - 16);
	}
	PORT->Group[GPIO_PORT(portpin)].WRCONFIG.reg = config; // update config
}

//    uint8_t data;
//	if (function == GPIO_PIN_FUNCTION_OFF) {
//	    PORT->Group[GPIO_PORT(portpin)].PINCFG[GPIO_PIN(portpin)].reg &= ~PORT_PINCFG_PMUXEN;
//	} else {
//	    PORT->Group[GPIO_PORT(portpin)].PINCFG[GPIO_PIN(portpin)].reg |= PORT_PINCFG_PMUXEN;
//
//		data = PORT->Group[GPIO_PORT(portpin)].PMUX[GPIO_PIN(portpin)>>1].reg;
//
//		if (GPIO_PIN(portpin) & 1) {
			/* Odd numbered pin */
//		    data = (data & ~PORT_PMUX_PMUXO_Msk) | PORT_PMUX_PMUXO(pinfunction);
//		} else {
			/*  Even numbered pin */
//		    data = (data & ~PORT_PMUX_PMUXE_Msk) | PORT_PMUX_PMUXE(pinfunction);
//		}
//		PORT->Group[GPIO_PORT(portpin)].PMUX[GPIO_PIN(portpin)>>1].reg = data;
//	}

/**
 * @brief Set output gpio pin to state on port/pin
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @param[in] state - bool  true = high, false = low
 */

static inline void gpio_set_out(const uint8_t portpin, bool state) 
{
	if(state) {
		PORT->Group[GPIO_PORT(portpin)].OUTSET.reg = 1U << GPIO_PIN(portpin);
	} else {
		PORT->Group[GPIO_PORT(portpin)].OUTCLR.reg = 1U << GPIO_PIN(portpin);
	}
}

/**
 * @brief Set output gpio pin high on portgroup PORTA, PORTB
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 *
 */

static inline void gpio_set_out_high(const uint8_t portpin) 
{
	PORT->Group[GPIO_PORT(portpin)].OUTSET.reg = 1U << GPIO_PIN(portpin);
}

/**
 * @brief Set output gpio pin low on portpin
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 *
 */

static inline void gpio_set_out_low(const uint8_t portpin) 
{
	PORT->Group[GPIO_PORT(portpin)].OUTCLR.reg = 1U << GPIO_PIN(portpin);
}

/**
 * @brief Toggle output gpio pins port/pin
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 */

static inline void gpio_toggle_out(const uint8_t portpin) 
{
	PORT->Group[GPIO_PORT(portpin)].OUTTGL.reg = 1U << GPIO_PIN(portpin);
}

/**
 * @brief set output gpio group on portgroup PORTA, PORTB masked by mask to state
 *
 * @param[in] portindex - portgroup_t  Ports are grouped into groups of maximum 32 pins,
 *                      PORTA = group 0, PORTB = group 1, etc
 * @param[in] mask - uint32_t   for each bit in mask, '1' changes bits to corresponding bit in state; '0' doesn't change bit
 * @param[in] state - uint32_t  if mask bit is set, then set pin to corresponding state bit
 *
 */
 static inline void gpio_write_group_state(const portgroup_t portindex, const uint32_t mask, const uint32_t state) 
{
	PORT->Group[portindex].OUTSET.reg = mask & state;
	PORT->Group[portindex].OUTCLR.reg = mask & ~state;
}

/**
 * @brief get gpio pin input on port/pin
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @return bool true if pin was high false if pin was low
 */

static inline bool gpio_get_in(const uint8_t portpin) 
{
	return ((PORT->Group[GPIO_PORT(portpin)].IN.reg & (1U << GPIO_PIN(portpin))) != 0);
}

/**
 * @brief get gpio pin output state on port/pin
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @return bool true if pin was high false if pin was low
 */

static inline bool gpio_get_out(const uint8_t portpin) 
{
	return ((PORT->Group[GPIO_PORT(portpin)].OUT.reg & (1U << GPIO_PIN(portpin))) != 0);
}

/**
 * @brief Set level as a 'wired and' bus (hi-z with pullup) on port/pin
 * This uses direction bits to emulate hi-z connections with a pullup. The restriction is that
 * the voltage cannot exceed VDDIO and uses the internal pullups. 
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @param[in] state - bool  true = hi-z pulled up; false = driven low
 */
static inline void gpio_set_wand(const uint8_t portpin, const bool state)
{
	if (state) {
	  	PORT->Group[GPIO_PORT(portpin)].DIRCLR.reg = 1U << GPIO_PIN(portpin); // input
  		PORT->Group[GPIO_PORT(portpin)].OUTSET.reg = 1U << GPIO_PIN(portpin); // enable pullup
  	} else {
	  	PORT->Group[GPIO_PORT(portpin)].DIRSET.reg = 1U << GPIO_PIN(portpin); // output
  		PORT->Group[GPIO_PORT(portpin)].OUTCLR.reg = 1U << GPIO_PIN(portpin); // drive low
	}  	
}

/**
 * @brief Set level as a 'wired or' bus (hi-z with pulldown) on port/pin
 * This uses direction bits to emulate hi-z connections with a pulldown. The restriction is that
 * the voltage cannot exceed VDDIO and uses the internal pulldowns. 
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @param[in] state - bool  true = driven high; false = hi-z pulled low
 */
static inline void gpio_set_wor(const uint8_t portpin, const bool state)
{
	if (state) {
	  	PORT->Group[GPIO_PORT(portpin)].DIRSET.reg = 1U << GPIO_PIN(portpin); // output
  		PORT->Group[GPIO_PORT(portpin)].OUTSET.reg = 1U << GPIO_PIN(portpin); // drive high
  	} else {
	  	PORT->Group[GPIO_PORT(portpin)].DIRCLR.reg = 1U << GPIO_PIN(portpin); // input
  		PORT->Group[GPIO_PORT(portpin)].OUTCLR.reg = 1U << GPIO_PIN(portpin); // enable pulldown
	}  	
}
 
/**
 * @brief get gpio pin input on portgroup PORTA, PORTB as group
 *
 * @param[in] portindex - portgroup_t  Ports are grouped into groups of maximum 32 pins,
 *                      PORTA = group 0, PORTB = group 1, etc
 * @return uint32_t 32 bits from input register
 */

static inline uint32_t gpio_read_IN(const portgroup_t portindex) 
{
	return PORT->Group[portindex].IN.reg;
}

/**
 * @brief get gpio pin output on portgroup PORTA, PORTB as group
 *
 * @param[in] portindex - portgroup_t  Ports are grouped into groups of maximum 32 pins,
 *                      PORTA = group 0, PORTB = group 1, etc
 * @return uint32_t 32 bits from output register
 */

static inline uint32_t gpio_read_OUT(const portgroup_t portindex) 
{
	return PORT->Group[portindex].OUT.reg;
}

/**
 * @brief get gpio pincfg on portgroup PORTA, PORTB for pin index
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @return 32 bits from pincfg register
 */

static inline uint32_t gpio_get_pincfg(const uint8_t portpin) 
{
	return PORT->Group[GPIO_PORT(portpin)].PINCFG[GPIO_PIN(portpin)].reg;
}

/**
 * @brief get gpio function on port/pin
 *
 * @param[in] portpin - uint8_t  Pin number is bits 0..4 and Port is bits 5..7
 * @return uint8_t pmux register for port/pin
 */

static inline uint8_t port_get_pin_function(const uint8_t portpin) 
{
	uint8_t val;
	val = PORT->Group[GPIO_PORT(portpin)].PMUX[GPIO_PIN(portpin) >> 1].reg;
	if (GPIO_PIN(portpin) & 1) { 
		return (val & PORT_PMUX_PMUXO_Msk) >> PORT_PMUX_PMUXO_Pos;
	} else {
		return (val & PORT_PMUX_PMUXE_Msk) >> PORT_PMUX_PMUXE_Pos;
	}	

}
/**
 * @brief gpio set EVCTRL register
 *
 * @param[in] portpin - uint8_t 
 * @param[in] mask - uint32_t 
 * - PORT_EVCTRL_PID0(value) (PORT_EVCTRL) PORT Event Pin Identifier 0 
 * - PORT_EVCTRL_EVACT0(value) (PORT_EVCTRL) PORT Event Action 0 
 *  +   PORT_EVCTRL_EVACT0_OUT (PORT_EVCTRL) Event output to pin 
 *  +   PORT_EVCTRL_EVACT0_SET (PORT_EVCTRL) Set output register of pin on event 
 *  +   PORT_EVCTRL_EVACT0_CLR (PORT_EVCTRL) Clear output register of pin on event 
 *  +   PORT_EVCTRL_EVACT0_TGL (PORT_EVCTRL) Toggle output register of pin on event 
 * - PORT_EVCTRL_PORTEI0 (PORT_EVCTRL) PORT Event Input Enable 0 
 * - PORT_EVCTRL_PID1(value) (PORT_EVCTRL) PORT Event Pin Identifier 1 
 * - PORT_EVCTRL_EVACT1(value) (PORT_EVCTRL) PORT Event Action 1 
 * - PORT_EVCTRL_PORTEI1 (PORT_EVCTRL) PORT Event Input Enable 1 
 * - PORT_EVCTRL_PID2(value) (PORT_EVCTRL) PORT Event Pin Identifier 2 
 * - PORT_EVCTRL_EVACT2(value) (PORT_EVCTRL) PORT Event Action 2 
 * - PORT_EVCTRL_PORTEI2 (PORT_EVCTRL) PORT Event Input Enable 2 
 * - PORT_EVCTRL_PID3(value) (PORT_EVCTRL) PORT Event Pin Identifier 3 
 * - PORT_EVCTRL_EVACT3(value) (PORT_EVCTRL) PORT Event Action 3 
 * - PORT_EVCTRL_PORTEI3 (PORT_EVCTRL) PORT Event Input Enable 3 
 */
static inline void gpio_set_EVCTRL(const uint8_t portpin, uint32_t mask)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg |= mask;
}

/**
 * @brief gpio get EVCTRL register
 *
 * @param[in] portpin - uint8_t 
 * @param[in] mask - uint32_t 
 * @return uint32_t
 * - PORT_EVCTRL_PID0(value) (PORT_EVCTRL) PORT Event Pin Identifier 0 
 * - PORT_EVCTRL_EVACT0(value) (PORT_EVCTRL) PORT Event Action 0 
 *  +   PORT_EVCTRL_EVACT0_OUT (PORT_EVCTRL) Event output to pin 
 *  +   PORT_EVCTRL_EVACT0_SET (PORT_EVCTRL) Set output register of pin on event 
 *  +   PORT_EVCTRL_EVACT0_CLR (PORT_EVCTRL) Clear output register of pin on event 
 *  +   PORT_EVCTRL_EVACT0_TGL (PORT_EVCTRL) Toggle output register of pin on event 
 * - PORT_EVCTRL_PORTEI0 (PORT_EVCTRL) PORT Event Input Enable 0 
 * - PORT_EVCTRL_PID1(value) (PORT_EVCTRL) PORT Event Pin Identifier 1 
 * - PORT_EVCTRL_EVACT1(value) (PORT_EVCTRL) PORT Event Action 1 
 * - PORT_EVCTRL_PORTEI1 (PORT_EVCTRL) PORT Event Input Enable 1 
 * - PORT_EVCTRL_PID2(value) (PORT_EVCTRL) PORT Event Pin Identifier 2 
 * - PORT_EVCTRL_EVACT2(value) (PORT_EVCTRL) PORT Event Action 2 
 * - PORT_EVCTRL_PORTEI2 (PORT_EVCTRL) PORT Event Input Enable 2 
 * - PORT_EVCTRL_PID3(value) (PORT_EVCTRL) PORT Event Pin Identifier 3 
 * - PORT_EVCTRL_EVACT3(value) (PORT_EVCTRL) PORT Event Action 3 
 * - PORT_EVCTRL_PORTEI3 (PORT_EVCTRL) PORT Event Input Enable 3 
 */
static inline uint32_t gpio_get_EVCTRL(const uint8_t portpin, uint32_t mask)
{
    return PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg & mask;
}

/**
 * @brief gpio write EVCTRL register
 *
 * @param[in] portpin - uint8_t 
 * @param[in] data - uint32_t 
 * - PORT_EVCTRL_PID0(value) (PORT_EVCTRL) PORT Event Pin Identifier 0 
 * - PORT_EVCTRL_EVACT0(value) (PORT_EVCTRL) PORT Event Action 0 
 *  +   PORT_EVCTRL_EVACT0_OUT (PORT_EVCTRL) Event output to pin 
 *  +   PORT_EVCTRL_EVACT0_SET (PORT_EVCTRL) Set output register of pin on event 
 *  +   PORT_EVCTRL_EVACT0_CLR (PORT_EVCTRL) Clear output register of pin on event 
 *  +   PORT_EVCTRL_EVACT0_TGL (PORT_EVCTRL) Toggle output register of pin on event 
 * - PORT_EVCTRL_PORTEI0 (PORT_EVCTRL) PORT Event Input Enable 0 
 * - PORT_EVCTRL_PID1(value) (PORT_EVCTRL) PORT Event Pin Identifier 1 
 * - PORT_EVCTRL_EVACT1(value) (PORT_EVCTRL) PORT Event Action 1 
 * - PORT_EVCTRL_PORTEI1 (PORT_EVCTRL) PORT Event Input Enable 1 
 * - PORT_EVCTRL_PID2(value) (PORT_EVCTRL) PORT Event Pin Identifier 2 
 * - PORT_EVCTRL_EVACT2(value) (PORT_EVCTRL) PORT Event Action 2 
 * - PORT_EVCTRL_PORTEI2 (PORT_EVCTRL) PORT Event Input Enable 2 
 * - PORT_EVCTRL_PID3(value) (PORT_EVCTRL) PORT Event Pin Identifier 3 
 * - PORT_EVCTRL_EVACT3(value) (PORT_EVCTRL) PORT Event Action 3 
 * - PORT_EVCTRL_PORTEI3 (PORT_EVCTRL) PORT Event Input Enable 3 
 */
static inline void gpio_write_EVCTRL(const uint8_t portpin, uint32_t data)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg = data;
}

/**
 * @brief gpio disable EVCTRL channel 0 register
 *
 * @param[in] portpin - uint8_t 
 */
static inline void gpio_disable_EVCTRL0(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg &= ~PORT_EVCTRL_PORTEI0;
}

/**
 * @brief gpio disable EVCTRL channel 1 register
 *
 * @param[in] portpin - uint8_t 
 */
static inline void gpio_disable_EVCTRL1(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg &= ~PORT_EVCTRL_PORTEI1;
}
/**
 * @brief gpio disable EVCTRL channel 2 register
 *
 * @param[in] portpin - uint8_t 
 */
static inline void gpio_disable_EVCTRL2(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg &= ~PORT_EVCTRL_PORTEI2;
}

/**
 * @brief gpio disable EVCTRL channel 3 register
 *
 * @param[in] portpin - uint8_t 
 */
static inline void gpio_disable_EVCTRL3(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg &= ~PORT_EVCTRL_PORTEI3;
}

/**
 * @brief gpio enable EVCTRL channel 0 register
 *
 * @param[in] portpin - uint8_t 
 */
static inline void gpio_enable_EVCTRL0(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg |= PORT_EVCTRL_PORTEI0;
}
/**
 * @brief gpio enable EVCTRL channel 0 register
 *
 * @param[in] portpin - uint8_t 
 */
static inline void gpio_enable_EVCTRL1(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg |= PORT_EVCTRL_PORTEI1;
}
/**
 * @brief gpio enable EVCTRL channel 2 register
 *
 * @param[in] portpin - uint8_t 
 */
static inline void gpio_enable_EVCTRL2(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg |= PORT_EVCTRL_PORTEI2;
}
/**
 * @brief gpio enable EVCTRL channel 3 register
 *
 * @param[in] portpin - uint8_t 
 */
static inline void gpio_enable_EVCTRL3(const uint8_t portpin)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg |= PORT_EVCTRL_PORTEI3;
}
/**
 * @brief gpio set EVCTRL channel 0 register
 *
 * @param[in] portpin - uint8_t 
 * @param[in] data - uint32_t 
 * - PORT_EVCTRL_EVACT_OUT
 * - PORT_EVCTRL_EVACT_SET
 * - PORT_EVCTRL_EVACT_CLR
 * - PORT_EVCTRL_EVACT_TGL
 * - PORT_EVCTRL_PORTEI 
 */
static inline void gpio_set_EVCTRL0(const uint8_t portpin, uint32_t data)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg = 
		(PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg & ~(PORT_EVCTRL_Msk << PORT_EVCTRL0_Pos))
		| ((PORT_EVCTRL_PID(GPIO_PIN(portpin)) | data) << PORT_EVCTRL0_Pos);
}

/**
 * @brief gpio set EVCTRL channel 1 register
 *
 * @param[in] portpin - uint8_t 
 * @param[in] data - uint32_t 
 * - PORT_EVCTRL_EVACT_OUT
 * - PORT_EVCTRL_EVACT_SET
 * - PORT_EVCTRL_EVACT_CLR
 * - PORT_EVCTRL_EVACT_TGL
 * - PORT_EVCTRL_PORTEI 
 */
static inline void gpio_set_EVCTRL1(const uint8_t portpin, uint32_t data)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg = 
		(PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg & ~(PORT_EVCTRL_Msk << PORT_EVCTRL1_Pos))
		| ((PORT_EVCTRL_PID(GPIO_PIN(portpin)) | data) << PORT_EVCTRL1_Pos);
}
/**
 * @brief gpio set EVCTRL channel 2 register
 *
 * @param[in] portpin - uint8_t 
 * @param[in] data - uint32_t 
 * - PORT_EVCTRL_EVACT_OUT
 * - PORT_EVCTRL_EVACT_SET
 * - PORT_EVCTRL_EVACT_CLR
 * - PORT_EVCTRL_EVACT_TGL
 * - PORT_EVCTRL_PORTEI 
 */
static inline void gpio_set_EVCTRL2(const uint8_t portpin, uint32_t data)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg = 
		(PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg & ~(PORT_EVCTRL_Msk << PORT_EVCTRL2_Pos))
		| ((PORT_EVCTRL_PID(GPIO_PIN(portpin)) | data) << PORT_EVCTRL2_Pos);
}
/**
 * @brief gpio set EVCTRL channel 3 register
 *
 * @param[in] portpin - uint8_t 
 * @param[in] data - uint32_t 
 * - PORT_EVCTRL_EVACT_OUT
 * - PORT_EVCTRL_EVACT_SET
 * - PORT_EVCTRL_EVACT_CLR
 * - PORT_EVCTRL_EVACT_TGL
 * - PORT_EVCTRL_PORTEI 
 */
static inline void gpio_set_EVCTRL3(const uint8_t portpin, uint32_t data)
{
	PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg = 
		(PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg & ~(PORT_EVCTRL_Msk << PORT_EVCTRL3_Pos))
		| ((PORT_EVCTRL_PID(GPIO_PIN(portpin)) | data) << PORT_EVCTRL3_Pos);
}

/**
 * @brief gpio read EVCTRL register
 *
 * @param[in] portpin - uint8_t 
 * @return uint32_t
 * - PORT_EVCTRL_PID0(value) (PORT_EVCTRL) PORT Event Pin Identifier 0 
 * - PORT_EVCTRL_EVACT0(value) (PORT_EVCTRL) PORT Event Action 0 
 *  +   PORT_EVCTRL_EVACT0_OUT (PORT_EVCTRL) Event output to pin 
 *  +   PORT_EVCTRL_EVACT0_SET (PORT_EVCTRL) Set output register of pin on event 
 *  +   PORT_EVCTRL_EVACT0_CLR (PORT_EVCTRL) Clear output register of pin on event 
 *  +   PORT_EVCTRL_EVACT0_TGL (PORT_EVCTRL) Toggle output register of pin on event 
 * - PORT_EVCTRL_PORTEI0 (PORT_EVCTRL) PORT Event Input Enable 0 
 * - PORT_EVCTRL_PID1(value) (PORT_EVCTRL) PORT Event Pin Identifier 1 
 * - PORT_EVCTRL_EVACT1(value) (PORT_EVCTRL) PORT Event Action 1 
 * - PORT_EVCTRL_PORTEI1 (PORT_EVCTRL) PORT Event Input Enable 1 
 * - PORT_EVCTRL_PID2(value) (PORT_EVCTRL) PORT Event Pin Identifier 2 
 * - PORT_EVCTRL_EVACT2(value) (PORT_EVCTRL) PORT Event Action 2 
 * - PORT_EVCTRL_PORTEI2 (PORT_EVCTRL) PORT Event Input Enable 2 
 * - PORT_EVCTRL_PID3(value) (PORT_EVCTRL) PORT Event Pin Identifier 3 
 * - PORT_EVCTRL_EVACT3(value) (PORT_EVCTRL) PORT Event Action 3 
 * - PORT_EVCTRL_PORTEI3 (PORT_EVCTRL) PORT Event Input Enable 3 
 */
static inline uint32_t gpio_read_EVCTRL(const uint8_t portpin)
{
	return PORT->Group[GPIO_PORT(portpin)].EVCTRL.reg;
}
#endif
