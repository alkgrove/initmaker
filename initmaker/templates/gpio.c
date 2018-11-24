#defmacro gpio
#ifdefined eic
	/** GPIO Input Interrupt %eic% (%port%) */
	port_set_pin_function(%eic%, MUX_%port%%eic_mux%_%eic_pin%);
#port %port% External Interrupt %unitof(eic_pin)% (EIC%unitof(eic_pin)%)
#ifdefined generator
#evt gen %generator% EIC_EXTINT_%unitof(eic_pin)% %toupper(path)% %edge% %sync_source% %evint% %port%
#fi
#fi
#ifdefined pullup
	gpio_set_pull(%pullup%, GPIO_PULL_UP);
#fi
#ifdefined pulldown
	gpio_set_pull(%pulldown%, GPIO_PULL_DOWN);
#fi
#ifdefined drvstr
	gpio_set_high_drive(%drvstr%);
#fi
#ifdefined in
	/** GPIO Input %in% (%port%) */
	gpio_set_dir_in(%in%);
#port %port% GPIO IN
#fi
#ifdefined out
	/** GPIO Output %out% (%port%) */
	gpio_set_dir_out(%out%);
#port %port% GPIO OUT
#ifdefined initial
#iftrue initial
 	gpio_set_out_high(%out%);
#otherwise
 	gpio_set_out_low(%out%);
#fi
#fi
#ifdefined event0
	gpio_set_EVCTRL0(%out%, PORT_EVCTRL_EVACT_%toupper(evact0)% | PORT_EVCTRL_PORTEI);
#evt event %event0% PORT_EV_0 %port% %toupper(evact0)%
#fi
#ifdefined event1
	gpio_set_EVCTRL1(%out%, PORT_EVCTRL_EVACT_%toupper(evact1)% | PORT_EVCTRL_PORTEI);
#evt event %event1% PORT_EV_1 %port% %toupper(evact1)%
#fi
#ifdefined event2
	gpio_set_EVCTRL2(%out%, PORT_EVCTRL_EVACT_%toupper(evact2)% | PORT_EVCTRL_PORTEI);
#evt event %event2% PORT_EV_2 %port% %toupper(evact2)%
#fi
#ifdefined event3
	gpio_set_EVCTRL3(%out%, PORT_EVCTRL_EVACT_%toupper(evact3)% | PORT_EVCTRL_PORTEI);
#evt event %event3% PORT_EV_3 %port% %toupper(evact3)%
#fi
#fi
#ifdefined swgen
#evt swgen %swgen%
#fi
#ifdefined pin
	/* %pin% alternate function %toupper(function)% */
	port_set_pin_function(%pin%, MUX_%port%%mux%_%muxpin%);
#port %port% %muxpin%
#fi
#endmacro

#defmacro eic
#iftrue !(ref_source == "osculp32k")
	/* Clock EIC with %toupper(ref_source)% (%frequency(ref_frequency)%) */
	gclk_write_PCHCTRL(EIC_GCLK_ID, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
#fi
#ifdefined list
#mod EIC External Interrupt Control (%toupper(ref_source)% %frequency(ref_frequency)%) EIC Channels: %list%
#fi
	// enable APB Clock EIC
	mclk_set_APBAMASK(MCLK_APBAMASK_EIC);

	eic_clear_ENABLE();
	eic_wait_for_sync(EIC_SYNCBUSY_ENABLE);
#iftrue ref_source == "osculp32k"
	eic_set_CTRLA(EIC_CTRLA_CKSEL); // EIC clocked from OSCULP32K (32.768KHz)
#otherwise
	eic_clear_CTRLA(EIC_CTRLA_CKSEL); // EIC clocked from %toupper(ref_source)% (%frequency(ref_frequency)%)
#fi
#ifdefined nmi
	eic_write_NMICTRL(EIC_NMICTRL_NMISENSE_%nmi%);
#otherwise
	eic_write_NMICTRL(EIC_NMICTRL_NMISENSE_NONE);
#fi
	eic_write_EVCTRL(<<<
#foreach gen_event
                   | EIC_%pinname%
#endfor
>>>); 
	eic_write_ASYNCH(<<<
#foreach eic_async
                    | EIC_%eicasync%
#endfor
>>>); 
#ifdefined eic_debounce
	eic_write_DEBOUNCEN(<<<
#foreach eic_debounce
					| EIC_%pinname%
#endfor
>>>);
	eic_write_DPRESCALER(<<<
#ifdefined tickon
                       | EIC_DPRESCALER_TICKON
#fi
#ifdefined prescaler0
                       | EIC_DPRESCALER_PRESCALER0(%prescaler0%)
#fi
#ifdefined state0
                       | EIC_DPRESCALER_STATES0
#fi
#ifdefined prescaler1
                       | EIC_DPRESCALER_PRESCALER0(%prescaler1%)
#fi
#ifdefined state1
                       | EIC_DPRESCALER_STATES1
#fi
>>>);
#fi
#foreach eic_sense
	eic_set_CONFIG(EIC_%pinname%_Pos, EIC_CONFIG_SENSE_%eicsense%);
#endfor
	eic_set_ENABLE();
	eic_wait_for_sync(EIC_SYNCBUSY_ENABLE);
#foreach eic_interrupt
#nvic %pinname% EIC_%eicnumber%_IRQn EIC_%eicnumber%_Handler
#endfor
#endmacro
