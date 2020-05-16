#defmacro xosc
/* XOSC%unit% %frequency(ext_frequency)% External Oscillator */
#define XOSC%unit%_FREQUENCY %ext_frequency%
#endmacro
#defmacro xosc32k
/* XOSC32K %frequency(ext_frequency)% External Oscillator */
#define XOSC32K_FREQUENCY %ext_frequency%
#endmacro
#defmacro dpll
/* DPLL%unit% Frequency %frequency(out_frequency)% */
#define DPLL%unit%_FREQUENCY %out_frequency%
/* DPLL%unit% Reference %frequency(src_frequency)% */
#define DPLL%unit%_REFERENCE %src_frequency%
#endmacro
#defmacro gclk
#iftrue (unit == 0)
/* CPU Frequency %frequency(out_frequency)% */
#define CPU_FREQUENCY %out_frequency%
#otherwise
/* GCLK%unit% %frequency(out_frequency)% */
#define GCLK%unit%_FREQUENCY %out_frequency%
#fi
#endmacro
#defmacro nvmctrl
#define NVM_WAIT_STATES %wait_states%
#endmacro