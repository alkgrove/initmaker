#defmacro nvic
#foreach nvic

/** @fn NVIC_ENABLE_%name% 
 *  @brief Enables the NVIC Interrupt for %name%
 * This is called during initialzation after system_init
 * This should only be called if the interrupt handler 
 * void %handler%(void) or void %name%_Handler(void) exists. 
#ifdefined shared
 * DMA4 - DMA127 is shared with one NVIC interrupt vector
 #fi
 */
#define NVIC_ENABLE_%name% NVIC_ENABLE_%value%
#define %name%_IRQn %value%
#define %name%_Handler %handler%
static inline void NVIC_ENABLE_%value%(void)
{
	NVIC_DisableIRQ(%value%);
	NVIC_ClearPendingIRQ(%value%);
#ifdefined priority
	NVIC_SetPriority(%value%, %priority%);
#fi
	NVIC_EnableIRQ(%value%);
}
#endfor
#endmacro
