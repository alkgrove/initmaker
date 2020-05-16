/**
 * @file RTOSconfig.h
 * @brief Custom file for configuring FreeRTOS to a specific application
 * @details Modify this file specific to the application
 * @copyright Copyright © Alkgrove 2020
 * @author Robert Alkire 
 * @date 2/13/2020
 *
 *  ATSAMD51
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
 **/
 
#ifndef __RTOSCONFIG_H__
#define __RTOSCONFIG_H__
#include "sam.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stream_buffer.h"
#include "semphr.h"

#define MS_TO_COUNT(ms) ((TIMER_PORT_FREQUENCY/1000) * (ms))

/* hooks definitions */
#if ( configSUPPORT_STATIC_ALLOCATION == 1 )
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize );
#if ( configUSE_TIMERS == 1 )
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer,
                                     StackType_t **ppxTimerTaskStackBuffer,
                                     uint32_t *pulTimerTaskStackSize );
#endif
#endif
void vAssertCalled( unsigned long ulLine, const char * const pcFileName );
#ifdef configASSERT
#undef configASSERT
#endif
#define configASSERT( x ) if( ( x ) == 0 ) vAssertCalled( __LINE__, __FILE__)

void *_sbrk(int32_t inc); 

/* SAMD51 customization */

/* For I2C Master RTOS customization
 * i2cm.c has placeholder for RTOS functions
 * I2CM_RTOS_VARIABLES - static variable for semaphore storage and handles
 * I2CM_RTOS_INIT - initialization code for semaphore or mutex
 * I2CM_RTOS_TAKE - called when i2c variables are being accessed (for semaphore or mutex)
 * I2CM_RTOS_GIVE - called when i2c variables are released
 * since the take time depends on actually sending i2c data, a timeout is imposed
 * I2CM_TIMEOUT it has a default of 500ms but can be redefined
 */
#ifdef I2CM_PORT
/* for I2C customization */
#define I2CM_RTOS_VARIABLES SemaphoreHandle_t i2cSemaphore = NULL; \
    StaticSemaphore_t i2cSemaphoreBuffer
#define I2CM_RTOS_INIT i2cSemaphore = xSemaphoreCreateBinaryStatic( &i2cSemaphoreBuffer ); \
	xSemaphoreGive( i2cSemaphore )

#define I2CM_RTOS_TAKE if (xSemaphoreTake( i2cSemaphore, pdMS_TO_TICKS(I2CMTO))) { 
#define I2CM_RTOS_GIVE xSemaphoreGive( i2cSemaphore ); \
	                    } else { \
		                    err = I2CM_TIMEOUT; \
	                    }
extern SemaphoreHandle_t i2cSemaphore;
#endif


/* For Timer/Counter Time Scheduler Customization */
/* tc.c has placeholders for RTOS functions
 * TC_RTOS_VARIABLES - static variables for semaphore storage and handles
 * TC_RTOS_IRQ_INIT - called at beginning of tc scheduler interrupt
 * TC_RTOS_IRQ_UPDATE - called when timeout encountered
 * TC_RTOS_IRQ_FINAL - called at end of tc scheduler interrupt
 * TC_RTOS_TAKE - called at when timer list is being accessed (for semaphores or mutex)
 * TC_RTOS_GIVE - called when timer list is no longer accessed
 */
#ifdef TIMER_PORT
#define TC_RTOS_VARIABLES SemaphoreHandle_t TCsemaphore = NULL; \
    StaticSemaphore_t TCsemaphoreBuffer; \
    volatile uint32_t timeSchedulerEvent = 0
#define TC_RTOS_INIT TCsemaphore = xSemaphoreCreateBinaryStatic( &TCsemaphoreBuffer ); \
	xSemaphoreGive( TCsemaphore )

#define TC_RTOS_IRQ_INIT    uint32_t taskWoken = 0
#define TC_RTOS_IRQ_UPDATE  taskWoken |= (*root->callback)(root->mask)
#define TC_RTOS_IRQ_FINAL   portYIELD_FROM_ISR((taskWoken != 0) ? pdTRUE : pdFALSE)

#define TC_RTOS_TAKE xSemaphoreTake( TCsemaphore, portMAX_DELAY )
#define TC_RTOS_GIVE xSemaphoreGive( TCsemaphore )
extern SemaphoreHandle_t TCsemaphore;
#endif

#endif /* __RTOSCONFIG_H__ */