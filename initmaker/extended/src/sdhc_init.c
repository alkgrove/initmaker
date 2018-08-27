
	/* SDHC Initialization */
    mclk_set_AHBMASK(MCLK_AHBMASK_SDHC0);
 	gclk_write_PCHCTRL(SDHC0_GCLK_ID, GCLK_PCHCTRL_GEN_GCLK4 | GCLK_PCHCTRL_CHEN);
 	gclk_write_PCHCTRL(SDHC0_GCLK_ID_SLOW, GCLK_PCHCTRL_GEN_GCLK5 | GCLK_PCHCTRL_CHEN);
	sdhc_set_SRR(SDHC0, SDHC_SRR_SWRSTALL); // reset all
	while(sdhc_get_SRR(SDHC0, SDHC_SRR_SWRSTALL)) {};
	sdhc_write_TCR(SDHC0, 14); // max timeout is 14 or about 1sec
	sdhc_write_PCR(SDHC0, SDHC_PCR_SDBPWR | SDHC_PCR_SDBVSEL_3V3);
	sdhc_set_NISTER(SDHC0, SDHC_NISTER_MASK); // clear all normal interrupt bits
	sdhc_set_EISTER(SDHC0, SDHC_EISTER_MASK); // clear all error interrupt bits
