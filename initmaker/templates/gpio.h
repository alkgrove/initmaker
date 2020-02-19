#defmacro pins
/* Pin Definitions */
#foreach pins
#define %pinname%			GPIO(PORT%groupof(portname)%, %unitof(portname)%)		/** %portname% */
#endfor
#ifdefined adc

/* ADC Channels */
#foreach adc_pin
#define %toupper(pinname)%_CHANNEL	ADC_INPUTCTRL_MUXPOS_%channel%
#endfor

#fi
#endmacro

#defmacro eic
#ifdefined eic_pin
/* EIC Definitions */
#foreach eic_pin
#define EIC_%pinname%_Pos	EIC%eicnumber%_Pos
#define	EIC_%pinname%		(1UL << EIC_%pinname%_Pos)
#endfor
#fi
#endmacro

