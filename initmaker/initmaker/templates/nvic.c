#defmacro nvic
#ifdefined nvic
#var	const NVICList_t IRQLIST[] = {
#foreach nvic
#var		{.irq = %value%, .priority = %priority%},
#endfor
>>>};
#var	int i;
#fi
#ifdefined nvic
	 /** Enable NVIC Interrupts **/
	for(i = 0; i < sizeof(IRQLIST)/sizeof(NVICList_t); i++) {
		NVIC_DisableIRQ(IRQLIST[i].irq);
    	NVIC_ClearPendingIRQ(IRQLIST[i].irq);
    	if (IRQLIST[i].priority >= 0) NVIC_SetPriority(IRQLIST[i].irq, (uint32_t) IRQLIST[i].priority);
    	NVIC_EnableIRQ(IRQLIST[i].irq);
    }
#fi
#endmacro
