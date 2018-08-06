#
# Makefile for ATSAMD51 processors
# Copyright 2015 - 2018 Alkgrove
# Licensed under BSD 3 clause License (see initmaker/LICENSE.txt)

TARGET = blinky
STACK_SIZE=8192
# Selecting the board uncomment one of these to select board
#CFG=featherm4
CFG=metrom4
#CFG=itsym4
INIT=${CFG}_init

CSRC = startup_samd51.c
CSRC += ${INIT}.c
CSRC += main.c

os := $(shell uname -o)

INC = ./inc
INC += ../../../samd5x/inc
INC += ../../../CMSIS/Include

ASRC =

VPATH = ./src
VPATH += ../../../samd5x/src

LDSCRIPT=./samd51j19a.ld

DEFS = -DDEBUG -D__SAMD51J19A__ -DARM_MATH_CM4 -D${CFG}

OBJ = $(notdir $(CSRC:.c=.o)) $(notdir $(ASRC:.s=.o))

INCLUDES=${patsubst %,-I%,${INC}}

AFLAGS = -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99
AFLAGS += -D__SAMD51J19A__ -mcpu=cortex-m4 -mfloat-abi=softfp -mfpu=fpv4-sp-d16
AFLAGS += -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" 

CFLAGS = -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb
# optimization
#CFLAGS += -O0 -g3 
CFLAGS +=  -Os -g3

CFLAGS += -Wall -c -std=gnu99 
CFLAGS += -ffunction-sections -mlong-calls  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" 
LDFLAGS = -Wl,--start-group -lm -Wl,--end-group -mthumb -Wl,--defsym=__stack_size__=${STACK_SIZE} -nostdlib
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
IM=../../scripts/initmaker.sh
UF2=./uf2conv.py

LIB+=${shell ${CC} ${CFLAGS} -print-file-name=libc.a}
LIB+=${shell ${CC} ${CFLAGS} -print-file-name=libgcc.a}

OBJDIR=bin/
SRCDIR=src/
INCDIR=inc/
# dependency rules
all: ${OBJDIR} ${OBJDIR}${TARGET}.uf2 ${OBJDIR}${TARGET}.lss ${OBJDIR}${TARGET}.sym

config: 
	${IM} ${CFG}.cfg ${SRCDIR}${INIT}.c ${INCDIR}${INIT}.h -v 
# -x ../../extsource/sdo.c -x ../../extsource/sdo.h

distclean: 
	${RM} ${OBJDIR} ${wildcard *~} ${SRCDIR}${INIT}.c ${INCDIR}${INIT}.h

${OBJDIR}:
	@test -d ${OBJDIR} || mkdir ${OBJDIR}

${OBJDIR}%.o : %.c
	${CC} ${CFLAGS} ${DEFS} ${INCLUDES} $< -o ${@}

${OBJDIR}%.o: %.s
	${AS} ${AFLAGS} ${DEFS} ${INCLUDES} $< -o $@ 

${OBJDIR}${TARGET}.elf: $(addprefix ${OBJDIR},${OBJ})
	${CC} ${LDFLAGS}  $(filter %.o %.a, ${^}) ${LIB} -o ${@}

${OBJDIR}%.bin: ${OBJDIR}%.elf
	${OBJCOPY} -O binary ${<} ${@}
	${SIZE} $<

${OBJDIR}%.uf2: ${OBJDIR}%.bin
	${UF2} -b 0x4000 -c -o ${OBJDIR}${TARGET}.UF2 ${OBJDIR}${TARGET}.bin 

${OBJDIR}%.lss: ${OBJDIR}%.elf
	${OBJDUMP} -h -S ${^} > ${@}

${OBJDIR}%.sym: ${OBJDIR}%.elf
	${NM} -n ${^} > ${@}

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
