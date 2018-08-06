#defmacro pins
/* Pin Definitions */
#foreach pins
#define %pinname%			GPIO(PORT%groupof(portname)%, %unitof(portname)%)		/** %portname% */
#endfor
#endmacro

#defmacro eic
#ifdefined eic_pin
/* External Interrupt Definitions */
#foreach eic_pin
#define EIC_%pinname%_Pos	EIC%eicnumber%_Pos
#define	EIC_%pinname%		(1UL << EIC_%pinname%_Pos)
#endfor
#fi
#endmacro