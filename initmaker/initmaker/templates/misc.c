#defmacro icm

	/* Integrity Check Module */
	mclk_set_AHBMASK(MCLK_AHBMASK_ICM);
	mclk_set_APBCMASK(MCLK_APBCMASK_ICM);
	icm_write_CTRL(ICM_CTRL_SWRST);
#mod ICM Integrity Check Module
#endmacro

#defmacro sdo
#mod SDO Software Debug Channel %print_port% (%frequency(frequency)%)
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
#endmacro

#defmacro sdhc

#mod SDHC SD Card Host Controller
	/* SDHC Initialization */
    mclk_set_AHBMASK(MCLK_AHBMASK_SDHC0);
	/* Clock SDHC core with %toupper(ref_source)% (%frequency(ref_source)%) */
 	gclk_write_PCHCTRL(SDHC0_GCLK_ID, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
	/* Clock SDHC slow clock with %toupper(slow_source)% (%frequency(slow_source)%) */
 	gclk_write_PCHCTRL(SDHC0_GCLK_ID_SLOW, GCLK_PCHCTRL_GEN_%toupper(slow_source)% | GCLK_PCHCTRL_CHEN);
	sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset all
	while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
	sdhc_write_TCR(SDHC0, 14); // max timeout is 14 or about 1sec
	sdhc_write_PCR(SDHC0, SDHC_PCR_SDBPWR | SDHC_PCR_SDBVSEL_3V3);
	sdhc_set_NISTER(SDHC0, SDHC_NISTER_MASK); // clear all normal interrupt bits
	sdhc_set_EISTER(SDHC0, SDHC_EISTER_MASK); // clear all error interrupt bits
#endmacro