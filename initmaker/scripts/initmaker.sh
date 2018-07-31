#!/bin/bash

# initmaker main script 
# this script references all other scripts in initmaker and should be the only one
# executed. 
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

export INITMAKER=$(dirname $(dirname $0))
scriptpath="${INITMAKER}/scripts"
templatepath="${INITMAKER}/templates"
export AWKPATH="${scriptpath}"

declare -a filelist

if [[ $# -lt 3 ]]; then
	echo "Usage: initmaker.sh <config file>.cfg <target>.c <target>.h <options>"
	echo "       options -v|--verbose"
	echo "       options -x|--extended <filename>"
	exit 1
fi
if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi
cfg=$1
shift;
boardsrc=$1
shift;
boardinc=$1
shift;
verbose=0
debug=0
idx=0

while [[ "$#" > 0 ]]; do case $1 in
  -v|--verbose) verbose=1;;
  --debug) debug=1;;
  -x|--extended) shift; filelist[$idx]=$1; ((idx++));;
  *) echo "Unknown parameter passed: $1"; exit 1;;
esac; shift; done

errfile="02.000"
boardtmp="${boardsrc%.c}"
extctmp="ext_tmp.c"
exthtmp="ext_tmp.h"
isrtmp="${boardtmp}_isr.tmp"
evttmp="${boardtmp}_evt.tmp"
cfgtmp="${boardtmp}_cfg.tmp"
rm -f ${isrtmp}
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
fi
processor="${scriptpath}/`${scriptpath}/getprocessor.sh ${cfg} -n`.awk"
if [ "${processor}" == "unknown.awk" ]; then
	echo "processor is not defined or correct in ${cfg}"
	exit
fi
if [[ ! -f ${processor} ]]; then
	echo "Script ${processor} does not exist"
	exit
fi

if [[ ! -f "${boardsrc}" ]]; then
	${scriptpath}/genboard.sh "${cfg}" "${boardsrc}" "${boardinc}" "${verbose}" 
fi
if [[ ! -f "${boardsrc}" ]]; then
	echo "Failed to create ${boardsrc}"
	exit 1
fi
if [[ ! -f "${boardinc}" ]]; then
	echo "Failed to create ${boardinc}"
	exit 1
fi

rm -f ${isrtmp}
rm -f ${vartmp}
rm -f ${evttmp}
rm -f ${cfgtmp}

${scriptpath}/genosc.sh "${cfg}" "${boardsrc}" "${boardinc}" "${processor}" "${verbose}"
cat < ${cfg} >> ${cfgtmp}
${scriptpath}/gengpio.sh "${cfgtmp}" "${boardsrc}" "${boardinc}" "${processor}" "${verbose}"
${scriptpath}/gensercom.sh "${cfgtmp}" "${boardsrc}" "${boardinc}" "${processor}" "${verbose}"
${scriptpath}/gentc.sh "${cfgtmp}" "${boardsrc}" "${boardinc}" "${processor}" "${verbose}"
${scriptpath}/gendma.sh "${cfgtmp}" "${boardsrc}" "${boardinc}" "${processor}" "${verbose}"
${scriptpath}/gennvic.sh "${boardsrc}" "${processor}" "${verbose}"
${scriptpath}/genevent.sh "${boardsrc}" "${boardinc}" "${processor}" "${verbose}"
${scriptpath}/genvar.sh "${boardsrc}" "${verbose}"

rm -f ${extctmp} ${exthtmp}
for extfile in "${filelist[@]}"
do
if [[ -f "${extfile}" ]]; then
extbasename=$(basename "${extfile}")
exttype=${extbasename##*.}
if [ "$exttype" == "c" ]; then
	cat ${extfile} >> ${extctmp}
fi
if [ "$exttype" == "h" ]; then
	cat ${extfile} >> ${exthtmp}
fi
else
	echo "File ${extfile} not found, skipping"
fi
done
if [[ -f "${extctmp}" ]]; then
${scriptpath}/genextended.sh "${extctmp}" "${boardsrc}" "${verbose}"
rm -f "${extctmp}"
fi

if [[ -f "${exthtmp}" ]]; then
${scriptpath}/genextended.sh "${exthtmp}" "${boardinc}" "${verbose}"
rm -f "${exthtmp}"
fi

if [ "${debug}" == 0 ]; then
rm -f ${isrtmp} ${vartmp} ${evttmp} ${cfgtmp}
fi
unset INITMAKER

