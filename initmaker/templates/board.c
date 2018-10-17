#defmacro board
/* 
#ifdefined project
 * Project %project%
#fi
 * Filename %filename%
 * Processor %processor%
#ifdefined description
 * Description %description%
#fi
 * 
#ifdefined copyright
 * %copyright%
 * All Rights Reserved
#fi
#ifdefined comment
 * %comment%
#fi
#ifdefined company
 * %company%
#fi
#ifdefined author
 * %author%
#fi
 * %date%
 *
%legal%
 */

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include "sam.h"
#include "%includefile%"

/** @defgroup SystemInit System Init
 * Called prior to main() by startup
 */
void SystemInit(void)
{
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
/** @addtogroup Analog
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup GPIO
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup ExtendedInit
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup NVIC
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
/** @addtogroup EVSYS
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/
} /* SystemInit */

/** @addtogroup ISR
 *  @ingroup SystemInit
 *  @{ **/
/** @} **/

#endmacro
