#
# Makefile for ATSAMD51 processors
# Alkgrove Electronics
# Copyright 2015 - 2018
#

TARGET = uart
#USE_METRO=1
DEBUG_ON=1
REV="1.00"
APP="Main"
STACK_SIZE=8192
ifeq ($(USE_METRO),1)
CFG=metro_uart
CPU=samd51j19a
else
CFG=fp_uart
CPU=samd51j20a
endif
INIT=${CFG}_init

CSRC = startup_samd51.c
CSRC += ${INIT}.c
CSRC += uart.c
CSRC += printf-stdarg.c
CSRC += main.c
CSRC += cli.c

os := $(shell uname -o)
hascygpath = 0
ifeq ($(os), Cygwin)
hascygpath = 1
endif
ifeq ($(os), Msys)
hascygpath = 1
endif

ifndef SAMD51_LIB
$(error SAMD51_LIB is not defined)
exit
endif
ifeq ($(hascygpath), 1)
IMPATH:=$(shell cygpath "${SAMD51_LIB}\initmaker")
SAMD51:=$(shell cygpath -m "${SAMD51_LIB}")
else
IMPATH:=${SAMD51_LIB}/initmaker
SAMD51:=${SAMD51_LIB}
endif

INC = ./inc
INC += ${SAMD51}/bsp/inc
INC += ${SAMD51}/samd5x/inc
INC += ${SAMD51}/CMSIS/Core/Include

VPATH = ./src
VPATH += ${SAMD51}/bsp/src
VPATH += ${SAMD51}/samd5x/src

LDSCRIPT=./${CPU}.ld

DEFS = -D__$(shell echo ${CPU} | tr '[:lower:]' '[:upper:]')__ -DARM_MATH_CM4
DEFS += -D'REV=${REV}' -D'APP=${APP}'
DEFS += -include feature.h
DEFS += -include ${INIT}.h

OBJ = $(notdir $(CSRC:.c=.o)) $(notdir $(ASRC:.s=.o))

INCLUDES=${patsubst %,-I%,${INC}}

CFLAGS = -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb
# optimization
#CFLAGS += -O0 -g3 
CFLAGS +=  -Os -g3
CFLAGS += -Wall -c -std=gnu99 
CFLAGS += -ffunction-sections -mlong-calls  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" 
LDFLAGS = -Wl,--start-group -lm -Wl,--end-group -mthumb -Wl,--defsym=__stack_size__=${STACK_SIZE} 
LDFLAGS += -Wl,-wrap=puts -Wl,-wrap=putc -Wl,-wrap=getc -Wl,-wrap=putchar
LDFLAGS += -Wl,-Map=$(addprefix ${OBJDIR},$(TARGET).map) --specs=nano.specs -Wl,--gc-sections -mcpu=cortex-m4  
LDFLAGS += -T$(LDSCRIPT)

ARFLAGS = rcs
# executables
CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
AR=arm-none-eabi-ar
LD=arm-none-eabi-ld
NM=arm-none-eabi-nm
OBJDUMP=arm-none-eabi-objdump
OBJCOPY=arm-none-eabi-objcopy
SIZE=arm-none-eabi-size
RM=rm -rf
IM:=${IMPATH}/scripts/initmaker.sh
UF2=../../scripts/uf2conv.py

#LIB+=${CMSIS}/Lib/GCC/libarm_cortexM4l_math.a
LIB+=${shell ${CC} ${CFLAGS} -print-file-name=libc.a}
LIB+=${shell ${CC} ${CFLAGS} -print-file-name=libgcc.a}

OBJDIR=bin/
SRCDIR=src/
INCDIR=inc/
EXTDIR=${IMPATH}/extended

# dependency rules
all: ${OBJDIR} ${OBJDIR}${TARGET}.uf2 ${OBJDIR}${TARGET}.bin ${OBJDIR}${TARGET}.lss ${OBJDIR}${TARGET}.sym

${OBJDIR}:
	@test -d ${OBJDIR} || mkdir ${OBJDIR}

config: 
	${IM} ${CFG}.cfg ${SRCDIR}${INIT}.c ${INCDIR}${INIT}.h -v -s
#-x ${EXTDIR}/src/sdo_init.c -x ${EXTDIR}/inc/sdo_init.h 

distclean: 
	${RM} ${OBJDIR} ${wildcard *~} ${SRCDIR}${INIT}.c ${INCDIR}${INIT}.h

${OBJDIR}%.o : %.c
	${CC} ${CFLAGS} ${DEFS} ${INCLUDES} $< -o ${@}

${OBJDIR}%.o: %.s
	${AS} ${AFLAGS} ${DEFS} ${INCLUDES} $< -o $@ 

${OBJDIR}${TARGET}.elf: $(addprefix ${OBJDIR},${OBJ})
	${CC} ${LDFLAGS}  $(filter %.o %.a, ${^}) ${LIB} -o ${@}

${OBJDIR}%.bin: ${OBJDIR}%.elf
	${OBJCOPY} -O binary ${<} ${@}
	${SIZE} $<

${OBJDIR}%.lss: ${OBJDIR}%.elf
	${OBJDUMP} -h -S ${^} > ${@}

${OBJDIR}%.sym: ${OBJDIR}%.elf
	${NM} -n ${^} > ${@}

${OBJDIR}%.uf2: ${OBJDIR}%.bin
	${UF2} -b 0x4000 -c -o ${OBJDIR}${TARGET}.UF2 ${OBJDIR}${TARGET}.bin 

clean:
	${RM} ${OBJDIR} ${wildcard *~}

print-%:
	@echo $* = $($*)

help:
	${CC} --version
	@make --version
	@make --print-data-base --question | awk '/^[^.%][-A-Za-z0-9_]*:/ { print substr($$1,1,length($$1)-1) }' 

# include dependencies
ifneq "${MAKECMDGOALS}" "clean"
-include ${wildcard ${OBJDIR}*.d}
endif
