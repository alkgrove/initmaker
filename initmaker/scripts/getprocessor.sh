#!/bin/bash

# getprocessor.sh <config file>.ini
# returns name of processor found in config file
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

if [[ $# -lt 1 ]]; then
	echo "Usage: getprocessor.sh <config file>.ini"
	exit 1
fi
if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi
removevariant=0;
src="$1"
shift
while [[ "$#" > 0 ]]; do case $1 in
  -n|--novariant) removevariant=1;;
  *) echo "Unknown parameter passed: $1"; exit 1;;
esac; shift; done

dir=$(dirname $0)
dir=$(dirname $dir)
awk -v dir="$dir" -v variant="${removevariant}" 'BEGIN {
	processor="unknown";
	in_section=0;
	}
	/\[[^\]]+\]/ {
	   in_section = (tolower($0) ~ /\[board\]/);
           next;
	}
	in_section {
		if (match($0, /([a-zA-Z][a-zA-Z0-9_]*)\s*=\s*(.*)$/, arr)) {
	   		if (tolower(arr[1]) ~ /processor/) {
	      		processor = gensub(/\s+$/,"", 1, arr[2]);
	      		in_section = 0;
	   		}
		}
 	   	next;
	}
	!insection {
	next;
	}
	END {
	if (variant) { 
		processor = gensub(/[A-Z]$/,"",1,processor);
	}
	print processor;
   }' $src


