#defmacro sercom
#ifdefined name
#define %toupper(name)% SERCOM%unit%
#fi
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
#ifdefined isr
/**
 * %messagename% is global access to the I2C Master ISR message structure
 * it must only be used with the i2cm.c library routines. 
 * This is the only message structure for SERCOM%unit%
 **/
extern volatile i2cm_msg_t %messagename%;
#fi
#fi
#endmacro
#defmacro qspi
#define QSPI_BAUDRATE %baudrate%
#if (QSPI_BAUDRATE <= 50000000)
#define READ_PARAM_DUMMY_CLOCKS READ_PARAM_CLK2
#define QPI_DUMMY_CLOCK_LEN 2
#elif (QSPI_BAUDRATE <= 80000000)
#define READ_PARAM_DUMMY_CLOCKS READ_PARAM_CLK4
#define QPI_DUMMY_CLOCK_LEN 4
#elif (QSPI_BAUDRATE <= 104000000)
#define READ_PARAM_DUMMY_CLOCKS READ_PARAM_CLK6
#define QPI_DUMMY_CLOCK_LEN 6
#else
#define READ_PARAM_DUMMY_CLOCKS READ_PARAM_CLK8
#define QPI_DUMMY_CLOCK_LEN 8
#endif

#endmacro
#defmacro i2c_slave
// I2C Device %name% slave address
#define %toupper(name)%_ADDRESS %address%
#mod I2C External I2C Slave Device %name% (%address%)
#endmacro