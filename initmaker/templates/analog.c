#defmacro adc
    mclk_set_%apbmask%(%apb%);
    /* Clock ADC%unit% with %toupper(ref_source)% (%frequency(ref_source)%) */
    gclk_write_PCHCTRL(ADC%unit%_GCLK_ID, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);

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
#iftrue refsel == "intref"
			| ADC_REFCTRL_REFSEL_INTREF
#fi
#iftrue refsel == "intvcc0"
			| ADC_REFCTRL_REFSEL_INTVCC0
#fi
#iftrue refsel == "intvcc1"
			| ADC_REFCTRL_REFSEL_INTVCC1
#fi
#iftrue refsel == "arefa"
			| ADC_REFCTRL_REFSEL_AREFA
#fi
#iftrue refsel == "arefb"
			| ADC_REFCTRL_REFSEL_AREFB
#fi
#iftrue refsel == "arefc"
			| ADC_REFCTRL_REFSEL_AREFC
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
#isr ADC%unit%_OVERRUN ADC%unit%_0_IRQn ADC%unit%_0_Handler
#fi
#ifdefined winmon_irq
#isr ADC%unit%_WINMON ADC%unit%_0_IRQn ADC%unit%_0_Handler
#fi
#ifdefined resrdy_irq
#isr ADC%unit%_RESRDY ADC%unit%_1_IRQn ADC%unit%_1_Handler
#fi

#endmacro