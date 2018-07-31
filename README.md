# initmaker
This is a simplified driver set for the ATSAMD5x processor and SystemInit creator scripts
for the Microchip (Atmel) ATSAMD5x chips. This is for those developing for the ATSAMD5x processor in C using arm-none-eabi-gcc. 

For ATSAMD5x and ATSAME5x processor families, Microchip  provided ASF4 for high and low level drivers, register description includes, initialization code, startup code and high level example code. The initialization was customized through the start.atmel.com website.
These processors have sophisticated clocking scheme, multiuse serial ports, event system, configurable logic blocks and more. Initialization of the MCU was significantly more complex than it has been in the past and start.atmel.com was Microchips answer. 

start.atmel.com uses graphical interface and menu selections to customize the initialization code. This lacked the flexibility and accessibility that we needed for development. So I came up with initmaker. 

initmaker, through a series of bash/awk scripts takes a terse configuration file and converts it into a rather large SystemInit procedure. It uses a basic macro expansion parser that takes the configuration properties with code template files to create chunks of code that make up the SystemInit. 

So this requires bash/awk. I use this often with Msys or Cygwin, it also works on Linux. I have used it on a Pi Zero but you have to apt-get a full version of Gnu awk for it to work. 

I've pulled over the ASF4 register description includes and cleaned them up a bit. This could have been done pure pointer arithmetic but I feel the use of static inline functions to describe this is easier to read. The ASF4 hri includes after some severe bash/awk translation does provide this and are included. The ones marked beta are tested in practice, the ones marked alpha compile but haven't been tested. 

I have included some higher level routines for a few of the peripherals. 
The directory structure is:
+ chip -> inc  ; static inline functions severely modified from ASF4 hri includes
+ chip -> inc -> component ; from ASF4
+ chip -> inc -> instance ; from ASF4
+ chip -> inc -> pio ; from ASF4
+ chip -> src ; specific higher level drivers
+ initmaker -> documentation -> ATSAMD5XE5X pins.xlsx ; excel spreadsheet of devices pins and functions
+ initmaker -> documentation -> Initmaker.pdf ; pdf file documentation for initmaker
+ initmaker -> scripts -> initmaker.sh ; this runs SystemInit creator - see documention
+ initmaker -> templates ; source code with markup language for initmaker
+ CMSIS -> download from https://developer.arm.com/embedded/cmsis
+ FatFS -> download from http://www.elm-chan.org/fsw/ff/00index_e.html

