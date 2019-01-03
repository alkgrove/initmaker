#!/bin/bash

# gennvic.sh <target>.c {-v}
# modifies NVIC section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

scriptpath="${INITMAKER}/scripts"
export AWKPATH="${scriptpath}"

if [[ $# -le 2 ]]; then
	echo "Usage: gennvic.sh <target>.c <processor> {-v}"
	exit 1
fi
if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi
script="$0"
boardsrc="$1"
processor="$2"
verbose="$3"

errfile="02.000"
boardtmp="${boardsrc%.c}"
tmp="${boardtmp}.002"
srctmp="${boardtmp}.004"
rsrctmp="${boardtmp}_rsrc.tmp"
isrtmp="${boardtmp}_isr.tmp"
vartmp="${boardtmp}_var.tmp"
template="${INITMAKER}/templates/nvic.c"
today=`date +%D`

if [[ -f ${rsrctmp} ]]; then
awk -v script="${script}" -v vartmp="${vartmp}" -i "${processor}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
        prop["nvic:macroname"] = "nvic";
     	initpins();
        isr_start = 1;
        isr_count = isr_start;
        devices[isr_count] = "nvic";
	}
	(NR == FNR) && /^#nvic/ {
		if (($3 !~ "NA") && !($3 in nviclist)) {
			nvicpriolist[isr_count] = gensub(/\s+/,"","g",$5);
			nviclist[isr_count++] = $3;
			prop["nvic:nvic"] = 1;
		}
		isrlist[$2] = gensub(/\s+/,"","g",$4);
		prop["nvic:isr"] = 1;
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
          		if (line ~ /#foreach/) {
          			i++;
    				idx=1; 
          			if (match(line, /^#foreach\s+([a-zA-Z0-9_]+)/, a)) {
    				switch (a[1]) {
    					case /nvic/:
    						for (j in nviclist) { keys[idx] = j; values[idx] = nviclist[j]; value2[idx++] = nvicpriolist[j]} 
    					break;
          				case /isr/:
    						for (j in isrlist) { keys[idx] = j; values[idx++] = isrlist[j]; }
        					break;
        				default: errprint("Bad argument " a[1] " for foreach"); 
        				break;
          				}
          				delete a;
          			} else {
          				errprint("Missing argument for foreach");
          				break;
          			}
   					stack[++sp] = (idx > 1);
        			idx = 1;  								
          			prop[name ":key"] = keys[idx];
          			prop[name ":value"] = values[idx];
          			prop[name ":priority"] = value2[idx];
          			line = macro[i];
          			loopstart = i;
          		} else if (line ~ /#endfor/) {
          			if (++idx <= length(keys)) {
          				i = loopstart;
          				prop[name ":key"] = keys[idx];
          				prop[name ":value"] = values[idx];
          				prop[name ":priority"] = value2[idx];
          			} else {
   						--sp;
        				delete keys;
          				delete values;
          				delete value2;
          				continue;
          			}
          			line = macro[i];
          		}
          		if (line ~ /#iftrue/) {
          			value = and(evalexp(instance, gensub(/#iftrue\s+/,"",1,line)), stack[sp]);
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
          				errprint("endif without matching if Line: "h i);
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
          		 	outline[i] = gensub(/[\r\n]/,"","g",outline[i]) gensub(/\s*[\|\&]?\s*/,"",1, outline[i+1]);
          			delete outline[i+1];
        			outline[i] = gensub(/<<<\s*>>>/,"0",1,outline[i]);
        			outline[i] = gensub(/<<</,"",1,outline[i]);
          			i++;
        		} else if (outline[i] ~ />>>/) {
          			outline[i] = gensub(/>>>/, "", "g", outline[i]);
          			j = i-1;
          			if (!(j in outline)) j--;
          		 	outline[j] = gensub(/[\r\n]/,"","g", outline[j]) outline[i];
          		 	outline[j] = gensub(/,}/, "}", "g", outline[j]);
          		 	delete outline[i];
          		}
          	}
          	for (i in outline) {
        	    if (outline[i] ~ /^#var/) {
        			print gensub(/^#var/,"",1,outline[i]) >> vartmp;
        	    } else {
          			print outline[i];
        	    }
          	}
          	delete outline;
    	}
    	if (sp != 1) {
    		errprint("iftrue/fi unbalanced at end of file");
		}
   }' ${rsrctmp} ${template} > ${tmp}
else
touch $tmp
fi
awk -v map="$(<$tmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\*+\s+@addtogroup\s+NVIC/ {
           print "/** @addtogroup NVIC";
           print " *  @ingroup SystemInit";
           print " *  Updated: " date;
           print " *  @{ **/";
           print map; 
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
		print "Malformed doxygen tags" | "cat 1>&2";
	}
	}' ${boardsrc} > ${srctmp}

rm -f $tmp
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${boardsrc} NVIC failed"
   fi
else
   mv -f ${srctmp} ${boardsrc}
	if [[ ${verbose} == 1 ]]; then
   		echo "${boardsrc} NVIC done"
	fi
fi

