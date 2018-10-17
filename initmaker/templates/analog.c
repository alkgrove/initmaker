#defmacro adc
    mclk_set_%apbmask%(%apb%);
    /* Clock ADC%unit% with %toupper(ref_source)% (%frequency(ref_source)%) */
    gclk_write_PCHCTRL(ADC%unit%_GCLK_ID, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);

#mod ADC%unit% (%toupper(ref_source)% %frequency(ref_source)%) Reference %toupper(refsel)%
    adc_wait_for_sync(ADC%unit%, ADC_SYNCBUSY_SWRST | ADC_SYNCBUSY_ENABLE);
    adc_set_CTRLA(ADC%unit%, ADC_CTRLA_SWRST);
    adc_wait_for_sync(ADC%unit%, ADC_SYNCBUSY_SWRST);

    adc_write_CTRLB(ADC0, <<<
#ifdefined leftadj
			| ADC_CTRLB_LEFTADJ
#fi
#ifdefined freerun
			| ADC_CTRLB_FREERUN
#fi
#ifdefined corren
			| ADC_CTRLB_CORREN
#fi
#ifdefined ressel
			| ADC_CTRLB_RESSEL_%ressel%BIT
#fi
#ifdefined winmode
#iftrue (winmode == 0)
			| ADC_CTRLB_WINMODE_DISABLE
#otherwise
			| ADC_CTRLB_WINMODE_MODE%winmode%
#fi
#fi
#ifdefined winss
			| ADC_CTRLB_WINSS
#fi
>>>);
    adc_write_REFCTRL(ADC%unit%, <<<
#ifdefined refcomp
			| ADC_REFCTRL_REFCOMP
#fi
#ifdefined refsel
			| ADC_REFCTRL_REFSEL_%toupper(refsel)%
#fi
>>>);
    adc_write_EVCTRL(ADC%unit%, <<<
#ifdefined flushei
                              | ADC_EVCTRL_FLUSHEI
#fi
#ifdefined startei
                              | ADC_EVCTRL_STARTEI
#fi
#ifdefined flushinv
                              | ADC_EVCTRL_FLUSHINV
#fi
#ifdefined startinv
                              | ADC_EVCTRL_STARTINV
#fi
#ifdefined resrdyeo
                              | ADC_EVCTRL_RESRDYEO
#fi
#ifdefined winmoneo
                              | ADC_EVCTRL_WINMONEO
#fi
>>>);
    adc_write_INPUTCTRL(ADC%unit%, <<<
#ifdefined muxpos
                              | ADC_INPUTCTRL_MUXPOS_%toupper(muxpos)%
#fi
#ifdefined diffmode
				              | ADC_INPUTCTRL_DIFFMODE
#fi
#ifdefined muxneg
                              | ADC_INPUTCTRL_MUXNEG_%toupper(muxneg)%
#fi
#ifdefined dseqstop
			                  | ADC_INPUTCTRL_DSEQSTOP
#fi
>>>);
    adc_write_AVGCTRL(ADC%unit%, <<<
#ifdefined samplenum
			                  | ADC_AVGCTRL_SAMPLENUM_%samplenum%
#fi
#ifdefined adjres
			                  | ADC_AVGCTRL_ADJRES(%adjres%)
#fi
>>>);
    adc_write_SAMPCTRL(ADC%unit%, <<<
#ifdefined samplen
                              | ADC_SAMPCTRL_SAMPLEN(%samplen%)
#fi
#ifdefined offcomp
                              | ADC_SAMPCTRL_OFFCOMP
#fi
>>>);
#ifdefined winut
    adc_write_WINUT(ADC%unit%, %winut%);
#fi
#ifdefined winlt
    adc_write_WINLT(ADC%unit%, %winlt%);
#fi
#ifdefined gaincorr
    adc_write_GAINCORR(ADC%unit%, %gaincorr%);
#fi
#ifdefined offsetcorr
    adc_write_OFFSETCORR(ADC%unit%, %offsetcorr%);
#fi
#ifdefined dbgrun
    adc_set_DBGCTRL(ADC%unit%, ADC_DBGCTRL_DBGRUN);
#otherwise
    adc_clear_DBGCTRL(ADC%unit%, ADC_DBGCTRL_DBGRUN);
#fi
    adc_write_CTRLA(ADC%unit%, <<<
                              | ADC_CTRLA_ENABLE
#ifdefined dualsel
                              | ADC_CTRLA_DUALSEL_%toupper(dualsel)%
#fi
#ifdefined slaveen
                              | ADC_CTRLA_SLAVEEN
#fi
#ifdefined runstdby
                              | ADC_CTRLA_RUNSTDBY
#fi
#ifdefined ondemand
                              | ADC_CTRLA_ONDEMAND
#fi
#ifdefined prescaler
                              | ADC_CTRLA_PRESCALER_%toupper(prescaler)%
#fi
#ifdefined r2r
                              | ADC_CTRLA_R2R
#fi
>>>);
#ifdefined overrun_irq
#nvic ADC%unit%_OVERRUN ADC%unit%_0_IRQn ADC%unit%_0_Handler
#fi
#ifdefined winmon_irq
#nvic ADC%unit%_WINMON ADC%unit%_0_IRQn ADC%unit%_0_Handler
#fi
#ifdefined resrdy_irq
#nvic ADC%unit%_RESRDY ADC%unit%_1_IRQn ADC%unit%_1_Handler
#fi

#endmacro

#defmacro dac
    mclk_set_%apbmask%(%apb%);
    /* Clock DAC with %toupper(ref_source)% (%frequency(ref_source)%) */
    gclk_write_PCHCTRL(DAC_GCLK_ID, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
#mod DAC (%toupper(ref_source)% %frequency(ref_source)%) Reference %toupper(refsel)%

	dac_write_CTRLA(DAC_CTRLA_SWRST);
	dac_wait_for_sync(DAC_SYNCBUSY_SWRST);
#iftrue (refsel == "vddana") || (refsel == "VDDANA")
#warning ERRATA NOTICE: DAC does not work with VDDANA
#fi
	dac_write_CTRLB(<<<
				    | DAC_CTRLB_REFSEL_%toupper(refsel)%
#ifdefined diff
				    | DAC_CTRLB_DIFF
#fi
>>>);
	dac_write_EVCTRL(<<<
#ifdefined startei0
				    | DAC_EVCTRL_STARTEI0
#fi
#ifdefined startei1
				    | DAC_EVCTRL_STARTEI1
#fi
#ifdefined emptyeo0
				    | DAC_EVCTRL_EMPTYEO0
#fi
#ifdefined emptyeo1
				    | DAC_EVCTRL_EMPTYEO1
#fi
#ifdefined invei0
				    | DAC_EVCTRL_INVEI0
#fi
#ifdefined invei1
				    | DAC_EVCTRL_INVEI1
#fi
#ifdefined resrdyeo0
				    | DAC_EVCTRL_RESRDYEO0
#fi
#ifdefined resrdyeo1
				    | DAC_EVCTRL_RESRDYEO1
#fi
>>>);
	dac_write_DACCTRL(0, <<<
#ifdefined dacctrl0_enable
	                   | DAC_DACCTRL_ENABLE
#fi
#ifdefined dacctrl0_osr
				       | DAC_DACCTRL_OSR_%dacctrl0_osr%
#fi
#iftrue dacctrl0_osr == 1
#ifdefined dacctrl0_refresh
			           | DAC_DACCTRL_REFRESH(%dacctrl0_refresh%)
#fi
#fi
#ifdefined dacctrl0_dither
                       | DAC_DACCTRL_DITHER
#fi
#ifdefined dacctrl0_runstdby
                       | DAC_DACCTRL_RUNSTDBY
#fi
#ifdefined dacctrl0_fext
                       | DAC_DACCTRL_FEXT
#fi
#ifdefined cctrl
			           | DAC_DACCTRL_CCTRL_%toupper(cctrl)%
#fi
#ifdefined dacctrl0_leftadj
					   | DAC_DACCTRL_LEFTADJ
#fi
>>>);
	dac_write_DACCTRL(1, <<<
#ifdefined dacctrl1_enable
	                   | DAC_DACCTRL_ENABLE
#fi
#ifdefined dacctrl1_osr
				       | DAC_DACCTRL_OSR_%dacctrl1_osr%
#fi
#iftrue dacctrl1_osr == 1
#ifdefined dacctrl1_refresh
			           | DAC_DACCTRL_REFRESH(%dacctrl1_refresh%)
#fi
#fi
#ifdefined dacctrl1_dither
                       | DAC_DACCTRL_DITHER
#fi
#ifdefined dacctrl1_runstdby
                       | DAC_DACCTRL_RUNSTDBY
#fi
#ifdefined dacctrl1_fext
                       | DAC_DACCTRL_FEXT
#fi
#ifdefined cctrl
			           | DAC_DACCTRL_CCTRL_%toupper(cctrl)%
#fi
#ifdefined dacctrl1_leftadj
					   | DAC_DACCTRL_LEFTADJ
#fi
>>>);
#ifdefined dbgrun
	dac_set_DBGRUN();
#otherwise
	dac_clear_DBGRUN();
#fi
	dac_write_CTRLA(DAC_CTRLA_ENABLE);
	dac_wait_for_sync(DAC_SYNCBUSY_ENABLE);

#endmacro

#defmacro supc
	supc_write_VREF(<<<
#ifdefined sel
                   | SUPC_VREF_SEL_%toupper(sel)%
#fi
#ifdefined ondemand
                   | SUPC_VREF_ONDEMAND
#fi
#ifdefined runstdby
                   | SUPC_VREF_RUNSTDBY
#fi
#ifdefined tssel
                   | SUPC_VREF_TSSEL
#fi
#ifdefined vrefoe
                   | SUPC_VREF_VREFOE
#fi
#ifdefined tsen
                   | SUPC_VREF_TSEN
#fi
>>>);
#endmacro