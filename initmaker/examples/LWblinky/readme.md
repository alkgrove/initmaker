### Blinky example for Adafruit SAMD51 boards

Prerequisites:
arm-none-eabi-gcc tool chain
make utility
gnu awk
initmaker
samd51 drivers provided with initmaker
cmsis -> from https://github.com/ARM-software/CMSIS_5

Edit makefile - uncomment the line CFG=featherm4, CFG=metrom4 or CFG=itsym4 to customize to your board.
Then do:

`make config`

This generates the src/blinky_init.c and inc/blinky_init.h initialization files. Then make the project:

`make`

This generates the bin/blinky.uf2. The file can be dragged to the metrom4boot drive that the UF2 bootloader makes. Double tap reset to get into the UF2 bootloader. 

Should see a red flashing LED once a second. 

The flashing is done with counter and event system. There is no further action after SystemInit()
needed to flash the LED. 
