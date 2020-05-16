#defmacro systick
#ifdefined period
/** @brief Systic Period %period%ms */
#define SYSTICK_PERIOD %period%
#fi
static inline SysTickInit(void)
{
	/** System Tick (defined in CMSIS) */
	SysTick_Config((CPU_FREQUENCY/1000)*SYSTICK_PERIOD);
}
#endmacro

#defmacro tc
#ifdefined name
#define %toupper(name)% TC%unit%
#define %toupper(name)%_FREQUENCY %toupper(ref_source)%_FREQUENCY
#fi
#endmacro

#defmacro tcc
#ifdefined name
#define %toupper(name)% TCC%unit%
#define %toupper(name)%_FREQUENCY %toupper(ref_source)%_FREQUENCY
#fi
#endmacro
