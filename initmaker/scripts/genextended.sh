#!/bin/bash

# genextended.sh <extended>.c <target>.c {-v}
# adds variables from generated file
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

scriptpath="${INITMAKER}/scripts"
export AWKPATH="${scriptpath}"

if [[ $# -le 2 ]]; then
	echo "Usage: genextended.sh <extended>.c <target>.c {1|0}"
	exit 1
fi

if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi

extendedsrc="$1"
boardsrc="$2"
verbose="$3"
errfile="02.000"
tmpsrc="${boardsrc%.c}.000"
today=`date +%D`

awk -v extended="$(<$extendedsrc)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\*+\s+@addtogroup\s+ExtendedInit/ {
    	print "/** @addtogroup ExtendedInit";
    	print " *  @ingroup SystemInit";
        print " *  Updated: " date;
    	print " *  @{ **/";
    	print extended;
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

if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${boardsrc} extended init failed"
   fi
else
   mv -f $tmpsrc $boardsrc
	if [[ ${verbose} == 1 ]]; then
   		echo "${boardsrc} extended init done"
	fi
fi

