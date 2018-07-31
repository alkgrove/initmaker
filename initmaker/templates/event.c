#defmacro evsys

#ifdefined clocks
#foreach clocks
	/* Map %clock% to Event System CH%channel% */
	gclk_write_PCHCTRL(EVSYS_GCLK_ID_%channel%, GCLK_PCHCTRL_GEN_%clock% | GCLK_PCHCTRL_CHEN);
#endfor
#fi
	/* Enable Event System APB Clock */
	mclk_set_APBBMASK(MCLK_APBBMASK_EVSYS);
#ifdefined users
#foreach users
	/* Event Channel %username% to user ID %userid% */
	evsys_set_USER(EVSYS_ID_USER_%userid%, %username%);
#endfor
#fi
#foreach generators
	/* Event %eventname% (CH%channel%) for generator %genid% */
	evsys_write_CHANNEL(%eventname%, EVSYS_ID_GEN_%genid% 
						| EVSYS_CHANNEL_PATH_%path%
						| EVSYS_CHANNEL_EDGSEL_%edge%);
#endfor
#endmacro
