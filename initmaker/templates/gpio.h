#defmacro pins
/* Pin Definitions */
#foreach pins
#define %pinname%	    GPIO(PORT%groupof(portname)%, %unitof(portname)%)		/** %portname% */
#endfor
#endmacro

#defmacro eic
#ifdefined eic_interrupt
/* External Interrupt Definitions */
#foreach eic_interrupt
#define	EIC_%pinname%_IRQ    EIC%eicnumber%
#endfor
#fi
#ifdefined gen_event
/* External Event Definitions */
#foreach gen_event
#define	EIC_%pinname%_EVT    EIC%eicnumber%
#endfor
#fi
#endmacro