### Blinky example for Adafruit SAMD51 boards

Prerequisites:  
initmaker with samd5x   
adafruit itsybitsym4, featherm4 or metrom4 dev board  
arm-none-eabi-gcc tool chain -> from https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads  
make utility  
gawk - Gnu AWK to run initmaker scripts.   
python3 - you need python3 to run the uf2conv.py script.  

cmsis -> from https://developer.arm.com/embedded/cmsis and follow the github link.   
You can make a simple build environment with:   
```
sudo apt-get install gcc-arm-none-eabi
sudo apt-get install python3
git clone https://github.com/alkgrove/initmaker.git
git clone https://github.com/ARM-software/CMSIS_5.git
mv initmaker build
mv CMSIS_5/CMSIS build/
mv CMSIS_5/LICENSE.txt build/CMSIS/
rm -r CMSIS_5
```
This has been tested to work under Msys, cygwin and Linux Mint Sonya. ARM doesn't seem to have a release of Linux 32 bit and the version that can be apt-get on raspbian is an old one (5.4.1) and didn't work for us.  

Edit makefile - uncomment/comment the line CFG=featherm4, CFG=metrom4 or CFG=itsym4 to customize to your board.
Then do:  
`make config`  
This generates the src/blinky_init.c and inc/blinky_init.h initialization files.  

`make`  
This generates the bin/blinky.uf2, this file can be dragged to the <board>m4boot drive that the UF2 bootloader makes. Double tap reset to get into the UF2 bootloader, then drag the blinky.UF2 into the drive folder. Once it downloads, push the reset button once to run the program. 

Should see a red flashing LED. 

You can change the speed of flashing by going into the blinky.cfg file and change  
```
[SYSTICK]
period=340
```
To 
```
[SYSTICK]
period=50
```
Since the period is a change to Systick Configuration and is called inside SystemInit(),
you will need to `make config; make`.

Note that even though the itsy uses a ATSAMD51G19A, the link scrhipt for the ATSAMD51J19A will work. They both have the same memory allocation just different package. 

