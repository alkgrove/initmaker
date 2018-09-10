# stdio on samd51

There are a lot of ways of communicating over serial on a small microcontroller. Newlib and Nano are viable options but they use quite a bit memory. Printf in stdio is popular and there are reasoable size versions such as printf-stdarg.c. This file can be found in the [FreeRTOS](http://www.freertos.org) Labs download. It uses the stdio.h include from gcc with the only dependency is the call to print a character. 

This works well but sometimes gcc helps out by turning a argumentless printf into a puts. You end up with a lot of unresolved references. I solved this by 

1. Add a macro define of __CUSTOM_FILE_IO__ to gcc compile options. (`-D__CUSTOM_FILE_IO__`) 

This will cause gcc to pull in `<sys/custom_file.h>` rather than it's usual FILE descriptor. I've added a simple sys/custom_file.h in the gcc folder for this. It will require the compile option -isystem ${INITMAKER}/gcc in order to for stdio.h to find the file. 

2. Use the link wrap command to substitute code for putc, getc, fgets, fputs, and putchar for linking. The makefile link options should add:

`-Wl,-wrap=puts -Wl,-wrap=putc -Wl,-wrap=getc -Wl,-wrap=fgets -Wl,-wrap=fputs -Wl,-wrap=putchar`

Add printf-stdarg.c and usart.c to files to compile. The link wrap functions are found in the usart.c in samd5x directory. The usart.c file adds the wrapper functions and simple blocking functions for UART and for SWO. 

The source that use puts, putc, getc, fgets, fputs, putchar and printf must `#include <stdio.h>` and `#include "usart.h"`. Also it is recommended to assign the variables stdin, stdout, and stderr to the FILE pointers: COM0-COM5 or SWO0-SWO7 before they are used. There are 6 predefined FILE descriptors for SERCOM0 to SERCOM5 defined as COM0 through COM5. There is also 8 predefined FILE descriptors for single wire output channels 0 through 7 defined as SWO0 to SWO7.

This is mostly for simple single threaded non rentrant routines used primarily for debugging. It does not support file IO and many of the serial functions. 
