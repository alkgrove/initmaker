#defmacro nvic
#ifdefined nvic
#var	const IRQn_Type IRQLIST[] = {
#foreach nvic
#var			%value%,
#endfor
>>>};
#var	int i;
#fi
#ifdefined nvic
	 /** Enable NVIC Interrupts **/
	for(i = 0; i < sizeof(IRQLIST)/sizeof(IRQn_Type); i++) {
		NVIC_DisableIRQ(IRQLIST[i]);
    	NVIC_ClearPendingIRQ(IRQLIST[i]);
    	NVIC_EnableIRQ(IRQLIST[i]);
    }
#fi
#endmacro
