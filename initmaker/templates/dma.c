#defmacro dma_init
	mclk_set_AHBMASK(MCLK_AHBMASK_DMAC);
	dmac_clear_DMAENABLE();
	dmac_clear_CRCCTRL(DMAC_CRCCTRL_CRCSRC_Msk);
	// reset the DMAC after stopping the CRC and DMA
	dmac_set_SWRST();
	while(dmac_get_SWRST()) {};
	// we keep DMA enable off and set Leval Enables
	dmac_write_CTRL(DMAC_CTRL_LVLEN0
				  | DMAC_CTRL_LVLEN1
				  | DMAC_CTRL_LVLEN2
				  | DMAC_CTRL_LVLEN3);

	dmac_clear_DBGRUN();
	// we aren't scheduling anything yet, so Priority Control is zero
	dmac_write_PRICTRL0(0);
	// set up our DMA descriptor base storage
	dmac_write_BASEADDR((uint32_t) get_base_DMA_descriptor(CHANNEL0));
	dmac_write_WRBADDR((uint32_t) get_base_DMA_writeback_descriptor(CHANNEL0));
#endmacro

#defmacro dma_end
	dmac_set_DMAENABLE();	
#endmacro

#defmacro dma
	// reset DMA channel %unit%
    dmac_clear_CHCTRLA(CHANNEL%unit%, DMAC_CHCTRLA_ENABLE);
    dmac_set_CHCTRLA(CHANNEL%unit%, DMAC_CHCTRLA_SWRST);
    while(dmac_get_CHCTRLA(CHANNEL%unit%, DMAC_CHCTRLA_SWRST)) {};

    dmac_write_CHCTRLA(CHANNEL%unit%, DMAC_CHCTRLA_TRIGACT_%toupper(trigact)%
                    | DMAC_CHCTRLA_BURSTLEN_%burstlen%
                    | DMAC_CHCTRLA_THRESHOLD_%threshold%
					| DMAC_CHCTRLA_TRIGSRC(DMAC_%trigsrc%_TRIGGER));    
	dmac_write_CHPRILVL(CHANNEL%unit%, DMAC_CHPRILVL_PRILVL_LVL0);
	dmac_write_CHEVCTRL(CHANNEL%unit%,<<<
#ifdefined event
				    | DMAC_CHEVCTRL_EVACT_%toupper(evact)%
				    | DMAC_CHEVCTRL_EVIE
#otherwise
			        | DMAC_CHEVCTRL_EVACT_NOACT
#fi
#ifdefined generator
				    | DMAC_CHEVCTRL_EVOE
#fi
#iftrue gen_source == "trigact"
					| DMAC_CHEVCTRL_EVOMODE_TRIGACT
#otherwise
				    | DMAC_CHEVCTRL_EVOMODE_DEFAULT
#fi			    
>>>);
#ifdefined interrupt
#iftrue (unit == 0) | (unit == 1) | (unit == 2) | (unit == 3)
#isr DMAC_CHANNEL%unit% DMAC_%unit%_IRQn DMAC_%unit%_Handler
#otherwise
#isr DMAC_CHANNEL4 DMAC_4_IRQn DMAC_4_Handler
#fi
#fi
#ifdefined generator
#evt gen %generator% DMAC_CH_%unit% %toupper(path)% %edge% %touppper(sync_source)%
#fi
#ifdefined event
#evt event %event% DMAC_CH_%unit%
#fi	
#ifdefined swgen
#evt swgen %swgen%
#fi

#endmacro
