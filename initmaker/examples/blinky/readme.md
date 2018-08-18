### Blinky example for Adafruit SAMD51 boards

Prerequisites:  
adafruit itsybitsym4, featherm4 or metrom4 dev board  
arm-none-eabi-gcc tool chain -> from https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads
make utility  
Gnu awk  
initmaker with samd5x   
cmsis -> from https://developer.arm.com/embedded/cmsis and follow the github link.
cmsis is very large and you only need one folder. Make a directory CMSIS at the same level as initmaker and samd5x, unzip the CMSIS-5.x.x and copy the folder CMSIS-5.x.x/CMSIS-5.x.x/CMSIS/Core/Include into the CMSIS folder you just created. You should have CMSIS/Include/core_cm4.h now. 


Edit makefile - uncomment/comment the line CFG=featherm4, CFG=metrom4 or CFG=itsym4 to customize to your board.
Then do:  
`make config`  
This generates the src/blinky_init.c and inc/blinky_init.h initialization files.  

`make`  
This generates the bin/blinky.uf2, this file can be dragged to the <board>m4boot drive that the UF2 bootloader makes. Double tap reset to get into the UF2 bootloader. 

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


