#!/bin/bash

# genvar.sh <target>.c {-v}
# adds variables from generated file
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

scriptpath="${INITMAKER}/scripts"
export AWKPATH="${scriptpath}"

if [[ $# -le 1 ]]; then
	echo "Usage: genvar.sh <target>.c {-v}"
	exit 1
fi

if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi

boardsrc="$1"
verbose="$2"
errfile="02.000"
tmpsrc="${boardsrc%.c}.000"
vartmp="${boardsrc%.c}_var.tmp"
isrtmp="${boardsrc%.c}_isr.tmp"
if [[ ! -f $vartmp ]]; then
touch $vartmp
fi
if [[ ! -f $isrtmp ]]; then
touch $isrtmp
fi
today=`date +%D`

awk -v vars="$(<$vartmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/void\s+SystemInit\(void\)/ {
	   print "void SystemInit(void)";
	   print "{";
       print vars; 
	   skip = 1;
	}
	/\/\*+\s+@addtogroup\s+/ {
	   skip = 0
	}
	skip == 0 {
	   print $0
	}
	END {
	   if (skip == 1) {
		print "" > errfile;
           }
	}' ${boardsrc} > ${tmpsrc}

rm -f $vartmp
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${boardsrc} vars failed"
   fi
else
   mv -f $tmpsrc $boardsrc
	if [[ ${verbose} == 1 ]]; then
   		echo "${boardsrc} vars done"
	fi
fi

awk -v isrtmp="$(<$isrtmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\*+\s+@addtogroup\s+ISR/ {
           print "/** @addtogroup ISR";
           print " *  @ingroup SystemInit";
           print " *  Updated: " date;
           print " *  @{ **/";
           print isrtmp; 
	       skip = 1;
	}
	/\/\**\s*@}\s*\**\// {
	   skip = 0
	}
	skip == 0 {
	   print $0
	}
	END {
	   if (skip == 1) {
		print "" > errfile;
           }
	}' ${boardsrc} > ${tmpsrc}

rm -f $isrtmp
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${boardsrc} ISR failed"
   fi
else
   mv -f ${tmpsrc} ${boardsrc}
	if [[ ${verbose} == 1 ]]; then
   		echo "${boardsrc} ISR done"
	fi
fi

