#defmacro nvic
#foreach nvic

/** @fn NVIC_ENABLE_%name% 
 *  @brief Enables the NVIC Interrupt for %name%
 * This is called during initialzation after system_init
 * This should only be called if the interrupt handler 
 * void %handler%(void) or void %name%_Handler(void) exists. 
 **/
#define %name%_Handler %handler%
#define NVIC_ENABLE_%value% NVIC_ENABLE_%name%
static inline void NVIC_ENABLE_%name%(void)
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
