#!/bin/bash
export AWK="gawk"
if [[ $# -lt 1 ]]; then
	echo "Usage: checkimpure.sh <filename>"
	exit 1
fi
symfile=$1
${AWK} 'BEGIN {flag=0} /_impure_ptr/ { flag = 1; } END {if (flag) print "Reent Bloat Detected" | "cat 1>&2";}' ${symfile}
