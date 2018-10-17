
# initmaker
This is a simplified driver set for the ATSAMD5x processor and SystemInit creator scripts for the Microchip (Atmel) ATSAMD5x chips. 
This is intended for developers of the Microchip ATSAMD5x processor programming in C using arm-none-eabi-gcc. For more information, see www.alkgrove.com. It needs a bash shell environment and Gnu awk. 
## Updates
Added an option (-s) to build a summary file of the system init. This generates <cfg>.txt.  
Fixed the I2CM recovery of bad bus faults. 
Various bug fixes. 
## Description
For ATSAMD5x and ATSAME5x processor families, Microchip  provided ASF4 for high and low level drivers, register description includes, initialization code, startup code and high level example code. The initialization was customized through the start.atmel.com website.
These processors have sophisticated clocking scheme, multiuse serial ports, event system, configurable logic blocks and more. Initialization of the MCU was significantly more complex than it has been in the past and start.atmel.com was Microchips answer. 

start.atmel.com uses graphical interface and menu selections to customize the initialization code. This lacked the flexibility and accessibility that we needed for development, so I came up with initmaker. 

initmaker, through a series of bash/awk scripts, takes a terse configuration file and converts it into a rather large SystemInit procedure. It uses a basic macro expansion parser that takes the configuration properties with code template files to create chunks of code that make up the SystemInit().

I've pulled over the ASF4 register description includes and cleaned them up a bit. This could have been done pure pointer arithmetic but I feel the use of static inline functions to describe this is easier to read. The ASF4 hri includes after some severe bash/awk translation does provide this and are included. The files marked as beta are tested in practice, the ones marked as alpha compile without error but haven't been tested. 

I have included some higher level routines for a few of the peripherals.  
The directory structure is:  
chip -> inc  ; static inline functions severely modified from ASF4 hri includes  
chip -> inc -> component ; from ASF4  
chip -> inc -> instance ; from ASF4  
chip -> inc -> pio ; from ASF4  
chip -> src ; specific higher level drivers and startup_samd51.c
initmaker -> documentation -> ATSAMD5XE5X pins.xlsx ; excel spreadsheet of devices pins and functions  
initmaker -> documentation -> Initmaker.pdf ; pdf file documentation for initmaker  
initmaker -> scripts -> initmaker.sh ; this runs SystemInit creator - see documention  
initmaker -> templates ; source code with markup language for initmaker  

For development, you will also need [CMSIS](https://developer.arm.com/embedded/cmsis)




