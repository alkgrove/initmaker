#!/bin/bash

# genboard.sh <pinmap file>.ini
# creates board section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text
export INITMAKER=$(dirname $(dirname $0))
scriptpath="${INITMAKER}/scripts"
initmaker_revision="2.0"
if [[ $# -le 3 ]]; then
	echo "Usage: genboard.sh <config file>.cfg <target>.c <target.h> verboseflag"
	exit 1
fi
if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi
script="$0"
cfg="$1"
boardsrc="$2"
boardinc="$3"
verbose="$4"
errfile="02.000"
boardtmp="${boardsrc%.c}"
echo " *" > license.tmp
dstarr=("${boardsrc}" "${boardinc}")
templatearr=("${INITMAKER}/templates/board.c" "${INITMAKER}/templates/board.h")
today=`date +%D`

license=`${scriptpath}/getlicense.sh ${cfg}`

if [[ $license == "" ]]; then 
	license="license.tmp"
elif [[ ! -f $license ]]; then
	echo $license file not found
	exit 1
fi

for i in 0 1
do
dst="${dstarr[i]}"
fname=$(basename "${dst}")
incfile=$(basename "${boardinc}")
template="${templatearr[i]}"
${AWK} -v script="${script}" -v date="$today" -v license="$(<$license)" -v rev=${initmaker_revision} -v file="${fname}" -v includefile="${incfile}" '
	@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
    	board_count = 1;
  		prop["board:filename"] = file;
		prop["board:date"] = date;
		prop["board:initmaker_revision"] = rev;
		prop["board:legal"] = license;
		prop["board:macroname"] = "board";
		prop["board:includefile"] = includefile;
		includetag = gensub(/\./, "_", 1, toupper(includefile));
		prop["board:tag"] = includetag;
	}
	(NR == FNR) && /^[;#]/ {
		next;
	}
	(NR == FNR) && /\[[^\]]+\]/ {
		gsub(/[\[\]\r\n]/,"");
		key = tolower($0);
		in_section = 0;
		if (key ~ /board/) {
			in_section = 1;
			section = key;
			devices[board_count++] = section;
		}
       	next;
	}
	(NR == FNR) && (in_section == 1) {
		if ($0 ~ /[a-zA-Z0-9_]+=/) {
	   		$0 = gensub("=", " ", 1, $0);
	   		key = section ":" tolower($1);
	   		$1 = "";
	   		value = gensub(/\s+/,"", 1, $0);
	   		value = gensub(/[\r\n]/,"","g", value);
			if (key ~ /board:include_h/) {
				prop[key include_h_count++] = value;
			} else if (key ~ /board:include_c/) {
				prop[key include_c_count++] = value;
			} else {
 	   			prop[key] = value;		
			}
 	   	}
 	   	next;
	}
	(NR == FNR) && (in_section == 0) {
		next;
	}	
	(NR != FNR) && /^#defmacro/ {
		key = gensub(/[\r\n]/,"","g", tolower($2));
		if (!key) {
			errprint("defmacro incorrect Line: " FNR);
		} else {
			beginmacro[key] = linecount;
			in_macro = 1;
		}
		next;
	}
	(NR != FNR) && /^#endmacro/ {
		if (in_macro == 0) {
			errprint("endmacro without a defmacro Line: " FNR);
		} else {
			endmacro[key] = linecount;
			in_macro = 0;
		}
		next;
	}
	(NR != FNR) && (in_macro) {
		macro[linecount] = $0;
		linecount++;
		next;
	}		
	END {
		sp = 0;
		stack[++sp] = 1; 
		for (widx in devices) {
			instance = devices[widx];
			key = instance ":macroname";
			name = prop[instance ":macroname"];
   			olp = 1;
  			for (i = beginmacro[name]; i < endmacro[name]; i++) {
  				line = macro[i];
   				if (line ~ /#iftrue/) {
  					value = and(evalexp(instance, gensub(/#iftrue\s+/,"",1,line)), stack[sp]);
  					stack[++sp] = value;
  				} else if (line  ~ /#iffalse/) {
  					value = and(!evalexp(instance, gensub(/#iffalse\s+/,"",1,line)), stack[sp]);
    				stack[++sp] = value;
  				} else if (line ~ /#ifdefined/) {
    				value = and(evaldefined(instance, gensub(/#ifdefined\s+/,"",1,line)), stack[sp]);
  					stack[++sp] = value;
  				} else if (line ~ /#ifundefined/) {
					value = and(!evaldefined(instance, gensub(/#ifundefined\s+/,"",1,line)), stack[sp]);
  					stack[++sp] = value;
  				} else if (line ~ /#otherwise/) {
  					stack[sp] = and(!stack[sp], stack[sp-1]);
  				} else if (line ~ /#fi/) {
  					sp--; 
  					if (sp < 0) {
  						sp = 0;
  						errprint("endif without matching ifdef Line: " i);
  					}
  				} else if (stack[sp]) {
    				while (match(line,/%([A-Za-z0-9_\(\)]+)%/, a)) {
    					repl = gensub(/[\(\)]/,".","g", a[0]);
    					txtsub = tolower(a[1]);
    					delete a;
    					value = dofunction(txtsub);
    					if (value ~ "Unknown") {
    						errprint("Unknown property " txtsub " in macro " instance "+" i);
    						break;
    					} else {
  						line = gensub(repl, value, "g", line);
  						}
  					}
  					outline[olp++] = line;
  				}
 			}   				
  			for (i = 1; i < olp; i++) {
  				if (outline[i] ~ /<<</) {
  					outline[i] = gensub(/<<</, "", "g", outline[i]);
  				 	outline[i] = gensub(/[\r\n]/,"","g",outline[i]) gensub(/\s*[\|&]\s*/,"",1, outline[i+1]);
  					delete outline[i+1];
  					i++;
 				} else if (outline[i] ~ />>>/) {
  					outline[i] = gensub(/>>>/, "", "g", outline[i]);
  					j = i-1;
  					if (!(j in outline)) j--;
   				 	outline[j] = gensub(/[\r\n]/,"","g", outline[j]) outline[i];
  				 	delete outline[i];
  				}
  			}
  			for (i in outline) {
  				print outline[i];
  			}
  			delete outline;
    	}
    	if (sp != 1) {
    		errprint("iftrue/fi unbalanced at end of file");
		}
   }' $cfg $template > $dst
if [[ $verbose ]]; then
echo "${dst} created"
fi
done
rm -f "license.tmp"