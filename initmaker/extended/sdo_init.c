	/* SDO can be used for printf messages without the expense of a UART */
	/* This file is included as an extended file to initialize ITM */
	/* CM4_TRACE_GCLK_ID is not defined in ASF4 and undocumented */
	gclk_write_PCHCTRL(CM4_TRACE_GCLK_ID, GCLK_PCHCTRL_GEN_GCLK0 | GCLK_PCHCTRL_CHEN);
	while(gclk_get_PCHCTRL(CM4_TRACE_GCLK_ID, GCLK_PCHCTRL_CHEN) == 0) {};
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; // enable access to the trace component registers.

	TPI->SPPR = 0x2UL; // Selected Pin Protocol Register -> Serial Wire Viewer, UART Non-Return to Zero encoding
	TPI->ACPR = SWOPRESCALE;
	ITM->LAR = 0xC5ACCE55UL; // unlock the ITM
	ITM->TCR = ITM_TCR_ITMENA_Msk 
				| ITM_TCR_TSENA_Msk 
				| (1UL << ITM_TCR_TraceBusID_Pos) 
				| ITM_TCR_DWTENA_Msk 
				| ITM_TCR_SYNCENA_Msk 
				| ITM_TCR_SWOENA_Msk; // Enable ITM. This must be before ITM Stimulus and Trace Enable registers are written.
	ITM->TER = 0xFFFFFFFF; // ITM Trace Enable Register - enable port
	ITM->TPR = 0;
