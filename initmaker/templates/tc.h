#defmacro systick
#ifdefined period
/** @brief Systic Period %period%ms */
#define SYSTICK_PERIOD %period%
#fi
#endmacro