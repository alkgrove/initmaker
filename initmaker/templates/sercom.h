#defmacro sercom
#define SERCOM%unit%_CORE_FREQ %toupper(ref_source)%_FREQUENCY
#define SERCOM%unit%_BAUD %baudrate%
#iftrue type == "i2cm"
#define SERCOM%unit%_TRISE 215
#define SERCOM%unit%_BAUDLOW I2CM_BAUDLOW(SERCOM%unit%_TRISE, SERCOM%unit%_BAUD, SERCOM%unit%_CORE_FREQ)
#if (SERCOM%unit%_BAUDLOW > 510)
#warning SERCOM%unit% I2C Baudrate is too low - math error
#elif (SERCOM%unit%_BAUDLOW <= 1)
#warning SERCOM%unit% I2C Baudrate is too high - math error
#endif
#define SERCOM%unit%_BAUDRATE I2CM_BAUD(SERCOM%unit%_BAUDLOW)
#fi
#endmacro