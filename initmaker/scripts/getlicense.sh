#!/bin/bash

# getlicense.sh <config file>.ini
# returns name of license file found in config file
# otherwise defaults to no license
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text


if [[ $# -lt 1 ]]; then
	echo "Usage: getlicense.sh <config file>.ini"
	exit 1
fi
if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi

src="$1"
dir=$(dirname $0)
dir=$(dirname $dir)
awk -v dir="$dir" 'BEGIN {
	license="";
	boardsection=0;
	}
	/\[[^\]]+\]/ {
	   boardsection = (tolower($0) ~ /\[board\]/);
           next;
	}
	boardsection == 1 {
	   $0 = gensub("=", " ", 1, $0);
	   key = tolower($1);
	   $1 = "";
	   value = gensub(/\s+/,"", 1, $0);
	   value = gensub(/[\r\n]/,"","g", value);
	   if (key ~ "license") {
	      license = value;
	   }
	}
	END {
	print ((license == "") ? "" : (dir "/templates/" license));
   }' $src


