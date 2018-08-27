/* SDO */
#define SWO_PRINT_PORT 0
#define SWO_FREQUENCY 6000000UL
#define SWOPRESCALE (((CPU_FREQUENCY)/(SWO_FREQUENCY)) - 1)
#define ITM_ID ((1UL << ITM_TCR_TraceBusID_Pos) & ITM_TCR_TraceBusID_Msk)
