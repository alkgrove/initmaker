#!/bin/bash

os=`uname -o`
if [ "`uname -o`" == "Cygwin" ]; then
export INITMAKER=`cygpath C:/SDK/Atmel/Master/initmaker`
else 
export INITMAKER="home/pi/initmaker"
fi
scriptpath="${INITMAKER}/scripts"
templatepath="${INITMAKER}/templates"
export AWKPATH="${scriptpath}"

if [[ $# -lt 3 ]]; then
	echo "Usage: debug.sh <script>.s <config file>.cfg <target>.c <target>.h <options>"
	echo "       options -v|--verbose, -n|--noisr"
	exit 1
fi
script=$1
shift
cfg=$1
shift
if [[ ! -f ${cfg} ]]; then
	echo "${cfg} file not found"
	exit 1
fi

boardsrc=$1
shift
boardinc=$1
shift
verbose=0
noisr=0
while [[ "$#" > 0 ]]; do case $1 in
  -v|--verbose) verbose=1;;
  *) echo "Unknown parameter passed: $1"; exit 1;;
esac; shift; done
processor="${scriptpath}/`${scriptpath}/getprocessor.sh ${cfg} -n`.awk"
if [ "${processor}" == "unknown.awk" ]; then
	echo "processor is not defined or correct in ${cfg}"
	exit
fi
if [[ ! -f ${processor} ]]; then
	echo "Script ${processor} does not exist"
	exit
fi

errfile="02.000"
${scriptpath}/${script} "${cfg}" "${boardsrc}" "${boardinc}" "${processor}" "${verbose}"
unset INITMAKER

