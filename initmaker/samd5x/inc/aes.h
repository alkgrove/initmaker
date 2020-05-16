/**
 * @note This file is modified from the Atmel ASF4 hri includes
 * by Alkgrove 2018
 * @version alpha
**/
/**
 * \file
 *
 * \brief SAM AES
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 */

#ifndef _AES_H_
#define _AES_H_

#include <stdbool.h>

/**
 * @brief aes set INTEN register
 *
 * @param[in] mask uint8_t 
 * - AES_INTENSET_ENCCMP Encryption Complete Interrupt Enable
 * - AES_INTENSET_GFMCMP GF Multiplication Complete Interrupt Enable
 **/
static inline void aes_set_INTEN(uint8_t mask)
{
	AES->INTENSET.reg = mask;
}

/**
 * @brief aes get INTEN register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AES_INTENSET_ENCCMP Encryption Complete Interrupt Enable
 * - AES_INTENSET_GFMCMP GF Multiplication Complete Interrupt Enable
 **/
static inline uint8_t aes_get_INTEN(uint8_t mask)
{
    return AES->INTENSET.reg & mask;
}

/**
 * @brief aes read INTEN register
 *
 * @return uint8_t
 * - AES_INTENSET_ENCCMP Encryption Complete Interrupt Enable
 * - AES_INTENSET_GFMCMP GF Multiplication Complete Interrupt Enable
 **/
static inline uint8_t aes_read_INTEN(void)
{
	return AES->INTENSET.reg;
}

/**
 * @brief aes write INTEN register
 *
 * @param[in] data uint8_t 
 * - AES_INTENSET_ENCCMP Encryption Complete Interrupt Enable
 * - AES_INTENSET_GFMCMP GF Multiplication Complete Interrupt Enable
 **/
static inline void aes_write_INTEN(uint8_t data)
{
	AES->INTENSET.reg = data;
	AES->INTENCLR.reg = ~data;
}

/**
 * @brief aes clear INTEN register
 *
 * @param[in] mask uint8_t 
 * - AES_INTENSET_ENCCMP Encryption Complete Interrupt Enable
 * - AES_INTENSET_GFMCMP GF Multiplication Complete Interrupt Enable
 **/
static inline void aes_clear_INTEN(uint8_t mask)
{
	AES->INTENCLR.reg = mask;
}

/**
 * @brief aes get INTFLAG register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AES_INTFLAG_ENCCMP Encryption Complete
 * - AES_INTFLAG_GFMCMP GF Multiplication Complete
 **/
static inline uint8_t aes_get_INTFLAG(uint8_t mask)
{
    return AES->INTFLAG.reg & mask;
}

/**
 * @brief aes read INTFLAG register
 *
 * @return uint8_t
 * - AES_INTFLAG_ENCCMP Encryption Complete
 * - AES_INTFLAG_GFMCMP GF Multiplication Complete
 **/
static inline uint8_t aes_read_INTFLAG(void)
{
	return AES->INTFLAG.reg;
}

/**
 * @brief aes clear INTFLAG register
 *
 * @param[in] mask uint8_t 
 * - AES_INTFLAG_ENCCMP Encryption Complete
 * - AES_INTFLAG_GFMCMP GF Multiplication Complete
 **/
static inline void aes_clear_INTFLAG(uint8_t mask)
{
	AES->INTFLAG.reg = mask;
}

/**
 * @brief aes write KEYWORD register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 **/
static inline void aes_write_KEYWORD(uint8_t index, uint32_t data)
{
	AES->KEYWORD[index].reg = data;
}

/**
 * @brief aes write INTVECTV register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 **/
static inline void aes_write_INTVECTV(uint8_t index, uint32_t data)
{
	AES->INTVECTV[index].reg = data;
}

/**
 * @brief aes set CTRLA register
 *
 * @param[in] mask uint32_t 
 * - AES_CTRLA_SWRST Software Reset
 * - AES_CTRLA_ENABLE Enable
 * - AES_CTRLA_AESMODE(value) AES Modes of operation
 *  +      AES_CTRLA_AESMODE_ECB Electronic code book mode
 *  +      AES_CTRLA_AESMODE_CBC Cipher block chaining mode
 *  +      AES_CTRLA_AESMODE_OFB Output feedback mode
 *  +      AES_CTRLA_AESMODE_CFB Cipher feedback mode
 *  +      AES_CTRLA_AESMODE_COUNTER Counter mode
 *  +      AES_CTRLA_AESMODE_CCM CCM mode
 *  +      AES_CTRLA_AESMODE_GCM Galois counter mode
 * - AES_CTRLA_CFBS(value) Cipher Feedback Block Size
 *  +      AES_CTRLA_CFBS_128BIT 128-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_64BIT 64-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_32BIT 32-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_16BIT 16-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_8BIT 8-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 * - AES_CTRLA_KEYSIZE(value) Encryption Key Size
 *  +      AES_CTRLA_KEYSIZE_128BIT 128-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_192BIT 192-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_256BIT 256-bit Key for Encryption / Decryption
 * - AES_CTRLA_CIPHER Cipher Mode
 *  +      AES_CTRLA_CIPHER_DEC Decryption
 *  +      AES_CTRLA_CIPHER_ENC Encryption
 * - AES_CTRLA_STARTMODE Start Mode Select
 *  +      AES_CTRLA_STARTMODE_MANUAL Start Encryption / Decryption in Manual mode
 *  +      AES_CTRLA_STARTMODE_AUTO Start Encryption / Decryption in Auto mode
 * - AES_CTRLA_LOD Last Output Data Mode
 *  +      AES_CTRLA_LOD_NONE No effect
 *  +      AES_CTRLA_LOD_LAST Start encryption in Last Output Data mode
 * - AES_CTRLA_KEYGEN Last Key Generation
 *  +      AES_CTRLA_KEYGEN_NONE No effect
 *  +      AES_CTRLA_KEYGEN_LAST Start Computation of the last NK words of the expanded key
 * - AES_CTRLA_XORKEY XOR Key Operation
 *  +      AES_CTRLA_XORKEY_NONE No effect
 *  +      AES_CTRLA_XORKEY_XOR The user keyword gets XORed with the previous keyword register content.
 * - AES_CTRLA_CTYPE(value) Counter Measure Type
 **/
static inline void aes_set_CTRLA(uint32_t mask)
{
	AES->CTRLA.reg |= mask;
}

/**
 * @brief aes get CTRLA register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 * - AES_CTRLA_SWRST Software Reset
 * - AES_CTRLA_ENABLE Enable
 * - AES_CTRLA_AESMODE(value) AES Modes of operation
 *  +      AES_CTRLA_AESMODE_ECB Electronic code book mode
 *  +      AES_CTRLA_AESMODE_CBC Cipher block chaining mode
 *  +      AES_CTRLA_AESMODE_OFB Output feedback mode
 *  +      AES_CTRLA_AESMODE_CFB Cipher feedback mode
 *  +      AES_CTRLA_AESMODE_COUNTER Counter mode
 *  +      AES_CTRLA_AESMODE_CCM CCM mode
 *  +      AES_CTRLA_AESMODE_GCM Galois counter mode
 * - AES_CTRLA_CFBS(value) Cipher Feedback Block Size
 *  +      AES_CTRLA_CFBS_128BIT 128-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_64BIT 64-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_32BIT 32-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_16BIT 16-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_8BIT 8-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 * - AES_CTRLA_KEYSIZE(value) Encryption Key Size
 *  +      AES_CTRLA_KEYSIZE_128BIT 128-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_192BIT 192-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_256BIT 256-bit Key for Encryption / Decryption
 * - AES_CTRLA_CIPHER Cipher Mode
 *  +      AES_CTRLA_CIPHER_DEC Decryption
 *  +      AES_CTRLA_CIPHER_ENC Encryption
 * - AES_CTRLA_STARTMODE Start Mode Select
 *  +      AES_CTRLA_STARTMODE_MANUAL Start Encryption / Decryption in Manual mode
 *  +      AES_CTRLA_STARTMODE_AUTO Start Encryption / Decryption in Auto mode
 * - AES_CTRLA_LOD Last Output Data Mode
 *  +      AES_CTRLA_LOD_NONE No effect
 *  +      AES_CTRLA_LOD_LAST Start encryption in Last Output Data mode
 * - AES_CTRLA_KEYGEN Last Key Generation
 *  +      AES_CTRLA_KEYGEN_NONE No effect
 *  +      AES_CTRLA_KEYGEN_LAST Start Computation of the last NK words of the expanded key
 * - AES_CTRLA_XORKEY XOR Key Operation
 *  +      AES_CTRLA_XORKEY_NONE No effect
 *  +      AES_CTRLA_XORKEY_XOR The user keyword gets XORed with the previous keyword register content.
 * - AES_CTRLA_CTYPE(value) Counter Measure Type
 **/
static inline uint32_t aes_get_CTRLA(uint32_t mask)
{
    return AES->CTRLA.reg & mask;
}

/**
 * @brief aes write CTRLA register
 *
 * @param[in] data uint32_t 
 * - AES_CTRLA_SWRST Software Reset
 * - AES_CTRLA_ENABLE Enable
 * - AES_CTRLA_AESMODE(value) AES Modes of operation
 *  +      AES_CTRLA_AESMODE_ECB Electronic code book mode
 *  +      AES_CTRLA_AESMODE_CBC Cipher block chaining mode
 *  +      AES_CTRLA_AESMODE_OFB Output feedback mode
 *  +      AES_CTRLA_AESMODE_CFB Cipher feedback mode
 *  +      AES_CTRLA_AESMODE_COUNTER Counter mode
 *  +      AES_CTRLA_AESMODE_CCM CCM mode
 *  +      AES_CTRLA_AESMODE_GCM Galois counter mode
 * - AES_CTRLA_CFBS(value) Cipher Feedback Block Size
 *  +      AES_CTRLA_CFBS_128BIT 128-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_64BIT 64-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_32BIT 32-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_16BIT 16-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_8BIT 8-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 * - AES_CTRLA_KEYSIZE(value) Encryption Key Size
 *  +      AES_CTRLA_KEYSIZE_128BIT 128-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_192BIT 192-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_256BIT 256-bit Key for Encryption / Decryption
 * - AES_CTRLA_CIPHER Cipher Mode
 *  +      AES_CTRLA_CIPHER_DEC Decryption
 *  +      AES_CTRLA_CIPHER_ENC Encryption
 * - AES_CTRLA_STARTMODE Start Mode Select
 *  +      AES_CTRLA_STARTMODE_MANUAL Start Encryption / Decryption in Manual mode
 *  +      AES_CTRLA_STARTMODE_AUTO Start Encryption / Decryption in Auto mode
 * - AES_CTRLA_LOD Last Output Data Mode
 *  +      AES_CTRLA_LOD_NONE No effect
 *  +      AES_CTRLA_LOD_LAST Start encryption in Last Output Data mode
 * - AES_CTRLA_KEYGEN Last Key Generation
 *  +      AES_CTRLA_KEYGEN_NONE No effect
 *  +      AES_CTRLA_KEYGEN_LAST Start Computation of the last NK words of the expanded key
 * - AES_CTRLA_XORKEY XOR Key Operation
 *  +      AES_CTRLA_XORKEY_NONE No effect
 *  +      AES_CTRLA_XORKEY_XOR The user keyword gets XORed with the previous keyword register content.
 * - AES_CTRLA_CTYPE(value) Counter Measure Type
 **/
static inline void aes_write_CTRLA(uint32_t data)
{
	AES->CTRLA.reg = data;
}

/**
 * @brief aes clear CTRLA register
 *
 * @param[in] mask uint32_t 
 * - AES_CTRLA_SWRST Software Reset
 * - AES_CTRLA_ENABLE Enable
 * - AES_CTRLA_AESMODE(value) AES Modes of operation
 *  +      AES_CTRLA_AESMODE_ECB Electronic code book mode
 *  +      AES_CTRLA_AESMODE_CBC Cipher block chaining mode
 *  +      AES_CTRLA_AESMODE_OFB Output feedback mode
 *  +      AES_CTRLA_AESMODE_CFB Cipher feedback mode
 *  +      AES_CTRLA_AESMODE_COUNTER Counter mode
 *  +      AES_CTRLA_AESMODE_CCM CCM mode
 *  +      AES_CTRLA_AESMODE_GCM Galois counter mode
 * - AES_CTRLA_CFBS(value) Cipher Feedback Block Size
 *  +      AES_CTRLA_CFBS_128BIT 128-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_64BIT 64-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_32BIT 32-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_16BIT 16-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_8BIT 8-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 * - AES_CTRLA_KEYSIZE(value) Encryption Key Size
 *  +      AES_CTRLA_KEYSIZE_128BIT 128-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_192BIT 192-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_256BIT 256-bit Key for Encryption / Decryption
 * - AES_CTRLA_CIPHER Cipher Mode
 *  +      AES_CTRLA_CIPHER_DEC Decryption
 *  +      AES_CTRLA_CIPHER_ENC Encryption
 * - AES_CTRLA_STARTMODE Start Mode Select
 *  +      AES_CTRLA_STARTMODE_MANUAL Start Encryption / Decryption in Manual mode
 *  +      AES_CTRLA_STARTMODE_AUTO Start Encryption / Decryption in Auto mode
 * - AES_CTRLA_LOD Last Output Data Mode
 *  +      AES_CTRLA_LOD_NONE No effect
 *  +      AES_CTRLA_LOD_LAST Start encryption in Last Output Data mode
 * - AES_CTRLA_KEYGEN Last Key Generation
 *  +      AES_CTRLA_KEYGEN_NONE No effect
 *  +      AES_CTRLA_KEYGEN_LAST Start Computation of the last NK words of the expanded key
 * - AES_CTRLA_XORKEY XOR Key Operation
 *  +      AES_CTRLA_XORKEY_NONE No effect
 *  +      AES_CTRLA_XORKEY_XOR The user keyword gets XORed with the previous keyword register content.
 * - AES_CTRLA_CTYPE(value) Counter Measure Type
 **/
static inline void aes_clear_CTRLA(uint32_t mask)
{
	AES->CTRLA.reg &= ~mask;
}

/**
 * @brief aes read CTRLA register
 *
 * @return uint32_t
 * - AES_CTRLA_SWRST Software Reset
 * - AES_CTRLA_ENABLE Enable
 * - AES_CTRLA_AESMODE(value) AES Modes of operation
 *  +      AES_CTRLA_AESMODE_ECB Electronic code book mode
 *  +      AES_CTRLA_AESMODE_CBC Cipher block chaining mode
 *  +      AES_CTRLA_AESMODE_OFB Output feedback mode
 *  +      AES_CTRLA_AESMODE_CFB Cipher feedback mode
 *  +      AES_CTRLA_AESMODE_COUNTER Counter mode
 *  +      AES_CTRLA_AESMODE_CCM CCM mode
 *  +      AES_CTRLA_AESMODE_GCM Galois counter mode
 * - AES_CTRLA_CFBS(value) Cipher Feedback Block Size
 *  +      AES_CTRLA_CFBS_128BIT 128-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_64BIT 64-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_32BIT 32-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_16BIT 16-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 *  +      AES_CTRLA_CFBS_8BIT 8-bit Input data block for Encryption/Decryption in Cipher Feedback mode
 * - AES_CTRLA_KEYSIZE(value) Encryption Key Size
 *  +      AES_CTRLA_KEYSIZE_128BIT 128-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_192BIT 192-bit Key for Encryption / Decryption
 *  +      AES_CTRLA_KEYSIZE_256BIT 256-bit Key for Encryption / Decryption
 * - AES_CTRLA_CIPHER Cipher Mode
 *  +      AES_CTRLA_CIPHER_DEC Decryption
 *  +      AES_CTRLA_CIPHER_ENC Encryption
 * - AES_CTRLA_STARTMODE Start Mode Select
 *  +      AES_CTRLA_STARTMODE_MANUAL Start Encryption / Decryption in Manual mode
 *  +      AES_CTRLA_STARTMODE_AUTO Start Encryption / Decryption in Auto mode
 * - AES_CTRLA_LOD Last Output Data Mode
 *  +      AES_CTRLA_LOD_NONE No effect
 *  +      AES_CTRLA_LOD_LAST Start encryption in Last Output Data mode
 * - AES_CTRLA_KEYGEN Last Key Generation
 *  +      AES_CTRLA_KEYGEN_NONE No effect
 *  +      AES_CTRLA_KEYGEN_LAST Start Computation of the last NK words of the expanded key
 * - AES_CTRLA_XORKEY XOR Key Operation
 *  +      AES_CTRLA_XORKEY_NONE No effect
 *  +      AES_CTRLA_XORKEY_XOR The user keyword gets XORed with the previous keyword register content.
 * - AES_CTRLA_CTYPE(value) Counter Measure Type
 **/
static inline uint32_t aes_read_CTRLA(void)
{
	return AES->CTRLA.reg;
}

/**
 * @brief aes set CTRLB register
 *
 * @param[in] mask uint8_t 
 * - AES_CTRLB_START Start Encryption/Decryption
 * - AES_CTRLB_NEWMSG New message
 * - AES_CTRLB_EOM End of message
 * - AES_CTRLB_GFMUL GF Multiplication
 **/
static inline void aes_set_CTRLB(uint8_t mask)
{
	AES->CTRLB.reg |= mask;
}

/**
 * @brief aes get CTRLB register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AES_CTRLB_START Start Encryption/Decryption
 * - AES_CTRLB_NEWMSG New message
 * - AES_CTRLB_EOM End of message
 * - AES_CTRLB_GFMUL GF Multiplication
 **/
static inline uint8_t aes_get_CTRLB(uint8_t mask)
{
    return AES->CTRLB.reg & mask;
}

/**
 * @brief aes write CTRLB register
 *
 * @param[in] data uint8_t 
 * - AES_CTRLB_START Start Encryption/Decryption
 * - AES_CTRLB_NEWMSG New message
 * - AES_CTRLB_EOM End of message
 * - AES_CTRLB_GFMUL GF Multiplication
 **/
static inline void aes_write_CTRLB(uint8_t data)
{
	AES->CTRLB.reg = data;
}

/**
 * @brief aes clear CTRLB register
 *
 * @param[in] mask uint8_t 
 * - AES_CTRLB_START Start Encryption/Decryption
 * - AES_CTRLB_NEWMSG New message
 * - AES_CTRLB_EOM End of message
 * - AES_CTRLB_GFMUL GF Multiplication
 **/
static inline void aes_clear_CTRLB(uint8_t mask)
{
	AES->CTRLB.reg &= ~mask;
}

/**
 * @brief aes read CTRLB register
 *
 * @return uint8_t
 * - AES_CTRLB_START Start Encryption/Decryption
 * - AES_CTRLB_NEWMSG New message
 * - AES_CTRLB_EOM End of message
 * - AES_CTRLB_GFMUL GF Multiplication
 **/
static inline uint8_t aes_read_CTRLB(void)
{
	return AES->CTRLB.reg;
}

/**
 * @brief aes write DATABUFPTR register
 *
 * @param[in] data uint8_t 
 * - AES_DATABUFPTR_INDATAPTR(value) Input Data Pointer
 **/
static inline void aes_write_DATABUFPTR(uint8_t data)
{
	AES->DATABUFPTR.reg = data;
}

/**
 * @brief aes read DATABUFPTR register
 *
 * @return uint8_t
 * - AES_DATABUFPTR_INDATAPTR(value) Input Data Pointer
 **/
static inline uint8_t aes_read_DATABUFPTR(void)
{
	return AES->DATABUFPTR.reg;
}

/**
 * @brief aes set DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - AES_DBGCTRL_DBGRUN Debug Run
 **/
static inline void aes_set_DBGCTRL(uint8_t mask)
{
	AES->DBGCTRL.reg |= mask;
}

/**
 * @brief aes get DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * @return uint8_t
 * - AES_DBGCTRL_DBGRUN Debug Run
 **/
static inline uint8_t aes_get_DBGCTRL(uint8_t mask)
{
    return AES->DBGCTRL.reg & mask;
}

/**
 * @brief aes write DBGCTRL register
 *
 * @param[in] data uint8_t 
 * - AES_DBGCTRL_DBGRUN Debug Run
 **/
static inline void aes_write_DBGCTRL(uint8_t data)
{
	AES->DBGCTRL.reg = data;
}

/**
 * @brief aes clear DBGCTRL register
 *
 * @param[in] mask uint8_t 
 * - AES_DBGCTRL_DBGRUN Debug Run
 **/
static inline void aes_clear_DBGCTRL(uint8_t mask)
{
	AES->DBGCTRL.reg &= ~mask;
}

/**
 * @brief aes read DBGCTRL register
 *
 * @return uint8_t
 * - AES_DBGCTRL_DBGRUN Debug Run
 **/
static inline uint8_t aes_read_DBGCTRL(void)
{
	return AES->DBGCTRL.reg;
}

/**
 * @brief aes write INDATA register
 *
 * @param[in] data uint32_t 
 **/
static inline void aes_write_INDATA(uint32_t data)
{
	AES->INDATA.reg = data;
}

/**
 * @brief aes read INDATA register
 *
 * @return uint32_t
 **/
static inline uint32_t aes_read_INDATA(void)
{
	return AES->INDATA.reg;
}

/**
 * @brief aes set HASHKEY register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 **/
static inline void aes_set_HASHKEY(uint8_t index, uint32_t mask)
{
	AES->HASHKEY[index].reg |= mask;
}

/**
 * @brief aes get HASHKEY register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t aes_get_HASHKEY(uint8_t index, uint32_t mask)
{
    return AES->HASHKEY[index].reg & mask;
}

/**
 * @brief aes write HASHKEY register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 **/
static inline void aes_write_HASHKEY(uint8_t index, uint32_t data)
{
	AES->HASHKEY[index].reg = data;
}

/**
 * @brief aes clear HASHKEY register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 **/
static inline void aes_clear_HASHKEY(uint8_t index, uint32_t mask)
{
	AES->HASHKEY[index].reg &= ~mask;
}

/**
 * @brief aes read HASHKEY register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 **/
static inline uint32_t aes_read_HASHKEY(uint8_t index)
{
	return AES->HASHKEY[index].reg;
}

/**
 * @brief aes set GHASH register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 **/
static inline void aes_set_GHASH(uint8_t index, uint32_t mask)
{
	AES->GHASH[index].reg |= mask;
}

/**
 * @brief aes get GHASH register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t aes_get_GHASH(uint8_t index, uint32_t mask)
{
    return AES->GHASH[index].reg & mask;
}

/**
 * @brief aes write GHASH register
 *
 * @param[in] index uint8_t 
 * @param[in] data uint32_t 
 **/
static inline void aes_write_GHASH(uint8_t index, uint32_t data)
{
	AES->GHASH[index].reg = data;
}

/**
 * @brief aes clear GHASH register
 *
 * @param[in] index uint8_t 
 * @param[in] mask uint32_t 
 **/
static inline void aes_clear_GHASH(uint8_t index, uint32_t mask)
{
	AES->GHASH[index].reg &= ~mask;
}

/**
 * @brief aes read GHASH register
 *
 * @param[in] index uint8_t 
 * @return uint32_t
 **/
static inline uint32_t aes_read_GHASH(uint8_t index)
{
	return AES->GHASH[index].reg;
}

/**
 * @brief aes set CIPLEN register
 *
 * @param[in] mask uint32_t 
 **/
static inline void aes_set_CIPLEN(uint32_t mask)
{
	AES->CIPLEN.reg |= mask;
}

/**
 * @brief aes get CIPLEN register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t aes_get_CIPLEN(uint32_t mask)
{
    return AES->CIPLEN.reg & mask;
}

/**
 * @brief aes write CIPLEN register
 *
 * @param[in] data uint32_t 
 **/
static inline void aes_write_CIPLEN(uint32_t data)
{
	AES->CIPLEN.reg = data;
}

/**
 * @brief aes clear CIPLEN register
 *
 * @param[in] mask uint32_t 
 **/
static inline void aes_clear_CIPLEN(uint32_t mask)
{
	AES->CIPLEN.reg &= ~mask;
}

/**
 * @brief aes read CIPLEN register
 *
 * @return uint32_t
 **/
static inline uint32_t aes_read_CIPLEN(void)
{
	return AES->CIPLEN.reg;
}

/**
 * @brief aes set RANDSEED register
 *
 * @param[in] mask uint32_t 
 **/
static inline void aes_set_RANDSEED(uint32_t mask)
{
	AES->RANDSEED.reg |= mask;
}

/**
 * @brief aes get RANDSEED register
 *
 * @param[in] mask uint32_t 
 * @return uint32_t
 **/
static inline uint32_t aes_get_RANDSEED(uint32_t mask)
{
    return AES->RANDSEED.reg & mask;
}

/**
 * @brief aes write RANDSEED register
 *
 * @param[in] data uint32_t 
 **/
static inline void aes_write_RANDSEED(uint32_t data)
{
	AES->RANDSEED.reg = data;
}

/**
 * @brief aes clear RANDSEED register
 *
 * @param[in] mask uint32_t 
 **/
static inline void aes_clear_RANDSEED(uint32_t mask)
{
	AES->RANDSEED.reg &= ~mask;
}

/**
 * @brief aes read RANDSEED register
 *
 * @return uint32_t
 **/
static inline uint32_t aes_read_RANDSEED(void)
{
	return AES->RANDSEED.reg;
}

#endif /* _AES_H */
