#defmacro defines

/* Miscellaneous Defines */
#foreach defines
#define %key% %value%
#endfor
#endmacro

#defmacro sdo

/* SDO */
#define SWO_PRINT_PORT %print_port%
#define SWO_FREQUENCY %frequency%UL
#define SWOPRESCALE (((CPU_FREQUENCY)/(SWO_FREQUENCY)) - 1)
#define ITM_ID ((1UL << ITM_TCR_TraceBusID_Pos) & ITM_TCR_TraceBusID_Msk)
#endmacro

