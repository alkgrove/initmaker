#defmacro nvmctrl

	nvmctrl_write_CTRLA((nvmctrl_read_CTRLA() & ~NVMCTRL_CTRLA_RWS_Msk) 
						| NVMCTRL_CTRLA_RWS(NVM_WAIT_STATES));
#endmacro
#defmacro mclk

	/* Master Clock */
  	mclk_write_CPUDIV(MCLK_CPUDIV_DIV_DIV%div%);
#endmacro

#defmacro osculp32k

#var    uint16_t cal = 0;
	cal = (osc32kctrl_read_OSCULP32K() & OSC32KCTRL_OSCULP32K_CALIB_Msk) >> OSC32KCTRL_OSCULP32K_CALIB_Pos; // get calibration value
	osc32kctrl_write_OSCULP32K(OSC32KCTRL_OSCULP32K_CALIB(cal));
#endmacro

#defmacro xosc

	/** XOSC%unit% External Oscillator %frequency(out_frequency)% **/
	oscctrl_write_XOSCCTRL(%unit%, OSCCTRL_XOSCCTRL_ENABLE
 		| OSCCTRL_XOSCCTRL_XTALEN
#iftrue runstdby
	    | OSCCTRL_XOSCCTRL_RUNSTDBY
#fi
#iftrue ondemand
	    | OSCCTRL_XOSCCTRL_ONDEMAND
#fi
 		| OSCCTRL_XOSCCTRL_IPTAT(XOSC_IPTAT(XOSC%unit%_FREQUENCY))
		| OSCCTRL_XOSCCTRL_IMULT(XOSC_IMULT(XOSC%unit%_FREQUENCY))
 		| OSCCTRL_XOSCCTRL_CFDPRESC(XOSC_CFDPRESC(XOSC%unit%_FREQUENCY)));
 	/* wait for oscillator to come online */
 	while ((oscctrl_read_STATUS() & OSCCTRL_STATUS_XOSCRDY%unit%) == 0){};
#endmacro
#defmacro xosc32k

	/** XOSC32K External 32KHz Oscillator **/
	osc32kctrl_write_XOSC32K(OSC32KCTRL_XOSC32K_ENABLE
	     | OSC32KCTRL_XOSC32K_XTALEN
#iftrue runstdby
	     | OSCCTRL_XOSCCTRL_RUNSTDBY
#fi // osc32k
#iftrue ondemand
	     | OSCCTRL_XOSCCTRL_ONDEMAND
#fi // osc32K_on_demand
#ifdefined en32k
         | OSC32KCTRL_XOSC32K_EN32K
#fi
#ifdefined en1k
         | OSC32KCTRL_XOSC32K_EN1K
#fi
         | OSC32KCTRL_XOSC32K_STARTUP(%startup%)
#iftrue hs
         | OSC32KCTRL_XOSC32K_CGM_HS);
#otherwise
	     | OSC32KCTRL_XOSC32K_CGM_XT);
#fi
 	/* wait for oscillator to come online */
 	while ((osc32kctrl_read_STATUS() & OSC32KCTRL_STATUS_XOSC32KRDY) == 0){};
#endmacro

#defmacro dpll

#iftrue ref_name == "gclk"
	/* %frequency(ref_frequency)% clock from %toupper(ref_source)% to DPLL%unit%  */
	gclk_write_PCHCTRL(OSCCTRL_GCLK_ID_FDPLL%unit%, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
#fi
	/** Digital Phase Lock Loop DPLL%unit% **/
	dpll_wait_for_sync(DPLL%unit%, OSCCTRL_DPLLSYNCBUSY_ENABLE);
    dpll_clear_ENABLE(DPLL%unit%);
	/* set DPLL%unit% ratio to %ldr% so that %frequency(ref_frequency)% * (%ldr%+1) = %frequency(out_frequency)% */
#iftrue !(ldrfrac == 0)
	/* DPLL will jitter more with non-zero fraction */
#fi
	dpll_wait_for_sync(DPLL%unit%,OSCCTRL_DPLLSYNCBUSY_DPLLRATIO);
	oscctrl_write_DPLLRATIO(DPLL%unit%, OSCCTRL_DPLLRATIO_LDR(%ldr%)
								 | OSCCTRL_DPLLRATIO_LDRFRAC(%ldrfrac%));
	
	oscctrl_write_DPLLCTRLB(DPLL%unit%, OSCCTRL_DPLLCTRLB_LTIME_DEFAULT
								 | OSCCTRL_DPLLCTRLB_DIV(%divisor%)
#ifdefined lbypass
							     | OSCCTRL_DPLLCTRLB_LBYPASS
#fi
								 | OSCCTRL_DPLLCTRLB_DCOFILTER(0)
						  //	 | OSCCTRL_DPLLCTRLB_DCOEN 
						         | OSCCTRL_DPLLCTRLB_FILTER(0)
								 | OSCCTRL_DPLLCTRLB_REFCLK_%toupper(ref_name)%);

  	 // the oscctrl_write_DPLLCTRLA function clears on demand
  	 // on demand should only be set after wait for lock
    oscctrl_write_DPLLCTRLA(DPLL%unit%, OSCCTRL_DPLLCTRLA_ENABLE);
	while(!oscctrl_get_DPLLSTATUS(DPLL%unit%, OSCCTRL_DPLLSTATUS_LOCK | OSCCTRL_DPLLSTATUS_CLKRDY)) {};
#iftrue ondemand | runstdby
   oscctrl_write_DPLLCTRLA(DPLL%unit%, <<<
#iftrue ondemand
                               | OSCCTRL_DPLLCTRLA_ONDEMAND
#fi
#iftrue runstdby
	                           | OSCCTRL_DPLLCTRLA_RUNSTDBY
#fi
                               | OSCCTRL_DPLLCTRLA_ENABLE
>>>);
#fi
#endmacro

#defmacro gclk

	/** GCLK%unit% %frequency(ref_frequency)%/%div% -> %frequency(out_frequency)% **/
 	gclk_write_GENCTRL(GCLK%unit%, GCLK_GENCTRL_GENEN
#ifdefined in
 						| GCLK_GENCTRL_SRC_GCLKIN
#otherwise
 						| GCLK_GENCTRL_SRC_%toupper(ref_source)%
#fi
#ifdefined out
 						| GCLK_GENCTRL_OE
#fi
#iftrue idc
 						| GCLK_GENCTRL_IDC
#fi
#iftrue oov
 						| GCLK_GENCTRL_OOV
#fi
#iftrue runstdby
					    | GCLK_GENCTRL_RUNSTDBY
#fi
 						| GCLK_GENCTRL_DIV(%div%));
#ifdefined out
	/** Set pin %out% as clock output (%frequency(out_frequency)%) */
	port_set_pin_function(%out%, MUX_%port%%mux%_%io%);
#fi
#ifdefined in
	/** Set pin %in% as clock input (%frequency(out_frequency)%) */
	port_set_pin_function(%in%, MUX_%port%%mux%_%io%);
#fi
#endmacro
#defmacro gclk_sync

	/* wait for GCLK to synchronize */
 	gclk_wait_for_sync(<<<
#foreach gclk
 						| GCLK_SYNCBUSY_GENCTRL%value%
#endfor
>>>);
#endmacro


#defmacro dpll_gclk_sync

	/* wait for GCLK to synchronize */
 	gclk_wait_for_sync(<<<
#foreach dpll_gclk
 						| GCLK_SYNCBUSY_GENCTRL%value%
#endfor
>>>);
#endmacro


#defmacro dfll

	/* DFLL */
	/* DFLL is used on reset as default source, make the source 32K temporarily */
	gclk_set_GENCTRL_SRC(GCLK0, GCLK_GENCTRL_GENEN
 						| GCLK_GENCTRL_SRC_OSCULP32K
 						| GCLK_GENCTRL_DIV(1));
 						
 	gclk_wait_for_sync(GCLK_SYNCBUSY_GENCTRL0);
 	/* Disable DFLL */
	oscctrl_write_DFLLCTRLA(0);
#ifdefined mode
#ifundefined usbcrm
	gclk_write_PCHCTRL(OSCCTRL_GCLK_ID_DFLL48, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
#fi
#fi
	oscctrl_write_DFLLMUL(OSCCTRL_DFLLMUL_CSTEP(%cstep%)
						| OSCCTRL_DFLLMUL_FSTEP(%fstep%)
						| OSCCTRL_DFLLMUL_MUL(%mul%));
	dfll_wait_for_sync(OSCCTRL_DFLLSYNC_DFLLMUL);
	/* put it into open loop mode first to update VAL register */
	oscctrl_write_DFLLCTRLB(0);
	dfll_wait_for_sync(OSCCTRL_DFLLSYNC_DFLLCTRLB);

	oscctrl_write_DFLLCTRLA(<<<
                | OSCCTRL_DFLLCTRLA_ENABLE
#ifdefined runstdby
				| OSCCTRL_DFLLCTRLA_RUNSTDBY
#fi
>>>);
	dfll_wait_for_sync(OSCCTRL_DFLLSYNC_ENABLE);
#ifdefined course
#ifdefined fine
	oscctrl_write_DFLLVAL(OSCCTRL_DFLLVAL_COARSE(%course%) 
				| OSCCTRL_DFLLVAL_FINE(%fine%));
#fi
#fi
	oscctrl_write_DFLLVAL(oscctrl_read_DFLLVAL());
	dfll_wait_for_sync(OSCCTRL_DFLLSYNC_DFLLVAL);
	
	oscctrl_write_DFLLCTRLB(<<<
#ifdefined waitlock
				| OSCCTRL_DFLLCTRLB_WAITLOCK
#fi
#ifdefined mode
				| OSCCTRL_DFLLCTRLB_MODE
#fi
#ifdefined stable
				| OSCCTRL_DFLLCTRLB_STABLE
#fi
#ifdefined llaw
				| OSCCTRL_DFLLCTRLB_LLAW
#fi
#ifdefined usbcrm
				| OSCCTRL_DFLLCTRLB_USBCRM
#fi
#ifdefined ccdis
			    | OSCCTRL_DFLLCTRLB_CCDIS
#fi
#ifdefined qldis
				| OSCCTRL_DFLLCTRLB_QLDIS
#fi
#ifdefined bplckc
			    | OSCCTRL_DFLLCTRLB_BPLCKC
#fi
>>>);
	dfll_wait_for_sync(OSCCTRL_DFLLSYNC_DFLLCTRLB);
    /* See Errata on DFLLRDY */
#ifdefined mode
	while(oscctrl_get_STATUS(OSCCTRL_STATUS_DFLLLCKC) == OSCCTRL_STATUS_DFLLLCKC) {};
#fi
#ifdefined ondemand	
	oscctrl_write_DFLLCTRLA(<<<
					| OSCCTRL_DFLLCTRLA_ENABLE
					| OSCCTRL_DFLLCTRLA_ONDEMAND
#ifdefined runstdby
					| OSCCTRL_DFLLCTRLA_RUNSTDBY
#fi
>>>);
#fi
#endmacro
	