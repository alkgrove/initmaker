/**
 * @file feature.h 
 * @brief enables or disables features
 * @details template file to be copied to local directory and modified
 * @copyright Copyright © Alkgrove Electronics 2018 Company Confidential
 * @author Robert Alkire 
 * @date 3/22/2020
 *
 **/
#ifndef __FEATURE_H__
#define __FEATURE_H__



/* uart overrides */
#define CONSOLE_PORT SERCOM4 // debug port
// output Carriage Return Linefeed (Microsoft) for end of line otherwise output Linefeed (Linux)
//#define FEATURE_UART_CRLF
// echo each character that is read from console
#define FEATURE_UART_ECHO

/* console overrides */
// This uses CONSOLE_PORT defined in uart
// FreeRTOS event notification bits
//#define CONSOLE_ABORT_EVENT 	(1UL << 29)
//#define CONSOLE_OVERFLOW_EVENT 	(1UL << 30)
//#define CONSOLE_RX_EVENT 		(1UL << 31)

//#define NVIC_ENABLE_CONSOLE_PORT_RXC NVIC_ENABLE_SERCOM1_2_IRQn
//#define CONSOLE_PORT_RXC_Handler SERCOM1_2_Handler


#endif /* __FEATURE_H__ */