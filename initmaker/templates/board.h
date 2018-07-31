#defmacro board
/**
 * @defgroup %project%
 * @file %filename%
 * %processor%
 * @brief %description%
 * 
 * @copyright %copyright%
 * All Rights Reserved
 * @author %author%
 * @date %date%
 *
%legal%
 **/
#ifndef __%tag%__
#define __%tag%__

#include "sam.h"

/** SystemInit is called from startup_samd51.c just prior to calling main.
  * it is by default a weak alias to Dummy_Init
  */
void SystemInit(void);
 
/** @addtogroup GPIO
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup clocking
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup SERCOM
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup DMA
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup TC
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup EVSYS
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup ExtendedInit
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/

#endif /* __%tag%__ */
#endmacro