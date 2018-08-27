/*******************************************************************************
 * 
 * custom_file.h
 * @brief This replaces the existing type FILE for small footprint processors
 * nano and newlib libraries and the rentrant code is too large for many 
 * small memory footprint microprocessors, yet we still want to use GCC.
 * if we use the CHaN FatFS, it has it's own file descriptor and doesn't use
 * the stdio FILE. 
 * The recent gcc has a sys/custom_file.h to override the definition of 
 * FILE. 
 * It requires __CUSTOM_FILE_IO__ to be defined prefereably in the makefile
 * It also requires wrappers to be defined for the stream IO functions: 
 * putc, puts, getc and gets
 * @par Author: Bob Alkire
 *  Copyright © Bob Alkire 08/25/2018
 * 
 *****************************************************************************/

#ifndef __CUSTOM_FILE_H__
#define __CUSTOM_FILE_H__

typedef struct sFILE {
	enum {NO_COM = 0, SERIAL_COM, SWO_COM} type;
	union {
		void *dev;
		unsigned long io;
	};
} __FILE;

#endif // __CUSTOM_FILE_H__