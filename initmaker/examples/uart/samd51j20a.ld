/**
 * \file
 *
 * \brief Linker script for running in internal FLASH on the SAMD51J20A
 *
 * Copyright (c) 2017 Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */


OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
SEARCH_DIR(.)

/* Memory Spaces Definitions */
/* Flash 1MByte SRAM 256KByte Auxiliary RAM 8K */
MEMORY
{
  rom      (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00100000
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00040000
  bkupram  (rwx) : ORIGIN = 0x47000000, LENGTH = 0x00002000
}

/* The stack size used by the application. NOTE: you need to adjust according to your application. */
STACK_SIZE = DEFINED(__stack_size__) ? __stack_size__ : 0x10000;
SECTOR_SIZE = 512;
PANIC_STACK_SIZE = 512;
PLUGIN_SIZE = 16384;
STAGING_SIZE = 16384;

/* Section Definitions */
SECTIONS
{
    /* panic stack is set on emergency exits and is located at top of memory */
    _panic_stack = ORIGIN(ram) + LENGTH(ram);
    /* staging and plugin address are unused sections of RAM for writing the bootloader. */
    _staging_address = _panic_stack - (PANIC_STACK_SIZE + STAGING_SIZE);
    _plugin_address = _staging_address - PLUGIN_SIZE;
    PROVIDE(_staging_size = STAGING_SIZE);
    PROVIDE(_plugin_size = PLUGIN_SIZE);

    .text :
    {
        . = ALIGN(4);
        _sfixed = .;
        KEEP(*(.vectors .vectors.*))
        *(.text .text.* .gnu.linkonce.t.*)
        *(.glue_7t) *(.glue_7)
        *(.rodata .rodata* .gnu.linkonce.r.*)
        *(.ARM.extab* .gnu.linkonce.armextab.*)

        /* Support C constructors, and C destructors in both user code
           and the C library. This also provides support for C++ code. */
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(.preinit_array))
        __preinit_array_end = .;

        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        __init_array_end = .;

        . = ALIGN(4);
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*crtend.o(.ctors))

        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
        KEEP (*(SORT(.fini_array.*)))
        __fini_array_end = .;

        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*crtend.o(.dtors))

        . = ALIGN(4);
        _efixed = .;            /* End of text section */
	_flash_origin = ORIGIN(rom);
	_flash_length = LENGTH(rom);
    } > rom

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    PROVIDE_HIDDEN (__exidx_start = .);
    .ARM.exidx :
    {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > rom
    PROVIDE_HIDDEN (__exidx_end = .);
    _etext = .;

    /* stack section */
    .stack (NOLOAD):
    {
        . = ALIGN(8);
        _sstack = .;
        . = . + STACK_SIZE;
        . = ALIGN(8);
        _estack = .;
    } > ram

    /* rtos task stack section */
    ._staskstack (NOLOAD):
    {
        . = ALIGN(4);
        _staskstack = .;
	*(.taskstack .taskstack.*)
        . = ALIGN(4);
        _etaskstack = .;
    } > ram

    .relocate : AT (_etext)
    {
        . = ALIGN(4);
        _srelocate = .;
        *(.ramfunc .ramfunc.*);
        *(.data .data.*);
        . = ALIGN(4);
        _erelocate = .;
    } > ram
   /* we need binaries to align to a 512 byte boundary */
    _bin_size = (SIZEOF(.relocate) + SIZEOF(.text) + SIZEOF(.ARM.exidx) + (SECTOR_SIZE - 1)) & -(SECTOR_SIZE);
    PROVIDE(_datasize = SIZEOF(.relocate));

    .bkupram (NOLOAD):
    {
        . = ALIGN(8);
        _sbkupram = .;
        *(.bkupram .bkupram.*);
        . = ALIGN(8);
        _ebkupram = .;
    } > bkupram

    /* .bss section which is used for uninitialized data */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = . ;
        _szero = .;
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = . ;
        _ezero = .;
    } > ram

    _end = . ;
}
