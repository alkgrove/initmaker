Blinky example for Adafruit SAMD51 boards

Prerequisites:
arm-none-eabi-gcc tool chain
make utility
gnu awk
initmaker
samd51 drivers provided with initmaker
cmsis -> from https://github.com/ARM-software/CMSIS_5

Edit makefile - uncomment board you want to build for
Then do:
make config
This generates the src/blinky_init.c and inc/blinky_init.h initialization files. 

make
This generates the bin/blinky.uf2, this file can be dragged to the metrom4boot drive that the UF2 bootloader makes. Double tap reset to get into the UF2 bootloader. 

Should see a red flashing LED. 

You can change the speed of flashing by going into the blinky.cfg file and change
[SYSTICK]
period=500
To 
[SYSTICK]
period=100

run make config; make and reload the uf2 file into the metrom4

You can make other LEDs blink too by adding
[GPIO]
out=TXLED
drvstr=TXLED
initial=1
to blinky.cfg and 
	gpio_toggle_out(TXLED);
to the systick routine in main.c


