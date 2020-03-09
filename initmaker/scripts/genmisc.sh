#!/bin/bash

# genmisc.sh <config file>.cfg <target>.c <target>.h {-v}
# modifies miscellaneous section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

#scriptpath="${INITMAKER}/scripts"
#export AWKPATH="${scriptpath}"

if [[ $# -le 3 ]]; then
	echo "Usage: genmisc.sh <config file>.cfg <target>.c <target>.h {-v}"
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
processor="$4"
verbose="$5"

errfile="02.000"
boardtmp="${boardsrc%.c}"
dstarr=("${boardsrc}" "${boardinc}")
tmparr=("${boardtmp}.002" "${boardtmp}.003")
newdstarr=("${boardtmp}.000" "${boardtmp}.001")
rsrctmp="${boardtmp}_rsrc.tmp"
vartmp="${boardtmp}_var.tmp"
evttmp="${boardtmp}_evt.tmp"
templatearr=("${INITMAKER}/templates/misc.c" "${INITMAKER}/templates/misc.h")
today=`date +%D`

for i in 0 1
do
dst="${dstarr[i]}"
tmp="${tmparr[i]}"
newdst="${newdstarr[i]}"
template="${templatearr[i]}"

${AWK} -v script="${script}" -v rsrctmp="${rsrctmp}" -v vartmp="${vartmp}" -v evttmp="${evttmp}" -i "${processor}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
		count = 1;
		prop["icm:macroname"] = "icm";
		prop["sdo:macroname"] = "sdo";
		prop["sdhc:macroname"] = "sdhc";
		prop["defines:macroname"] = "defines";
		prop["sdo:frequency"] = "60000000";
		prop["sdo:print_port"] = 1;
    	initpins();
     	initmclk();
	}
	(NR == FNR) && /^[#;]/ {
		next;
	}
	(NR == FNR) && /\[[^\]]+\]/ {
		gsub(/[\[\]\r\n \t]/,"");
		key = tolower($0);
		in_section = 0;
		macrokey = key ":macroname";
		if (macrokey in prop) {
  			in_section = 1;
  			section = key;
 			devices[count++] = section;
  		}  else if (key ~ /freq/) {
  			in_section = 1;
  			section = key;
  		}
       	next;
	}
	(NR == FNR) && (in_section) {
		if (match($0, /([a-zA-Z][a-zA-Z0-9_]*)\s*=\s*(.*)$/, arr)) {
			key = section ":" tolower(arr[1]);
			value = gensub(/[\r\n]+/,"", "g", arr[2]);
			prop[key] = value;
			if (section ~ /defines/) {
				defines[toupper(arr[1])] = value;
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
	}		
	END {
		sp = 0;
		stack[++sp] = 1; 
		for (widx in devices) {
			instance = devices[widx];
			if (instance in mclk) {
				prop[instance ":apb"] = mclk[instance];
				match(mclk[instance], /^MCLK_([^_]+)/, arr);
				prop[instance ":apbmask"] = arr[1];
				delete arr;
			}
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
						case /defines/:
    						for (j in defines) { keys[idx] = j; values[idx++] = defines[j]; } 
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
   					line = macro[i];
  					loopstart = i;
   				} else if (line ~ /#endfor/) {
  					if (++idx <= length(keys)) {
  						i = loopstart;
  						prop[name ":key"] = keys[idx];
  						prop[name ":value"] = values[idx];
   					} else {
   						--sp;
 						delete keys;
  						delete values;
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
  						errprint("endif without matching if Line: " i);
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
  				 	outline[i] = gensub(/[\r\n]/,"","g",outline[i]) gensub(/\s*[\|&]?\s*/,"",1, outline[i+1]);
  					delete outline[i+1];
					outline[i] = gensub(/<<<\s*>>>/,"0",1,outline[i]);
					outline[i] = gensub(/<<</,"",1,outline[i]);
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
			    if(outline[i] ~ /^#(nvic|port|mod)/) {
					print outline[i] >> rsrctmp;
			    } else if (outline[i] ~ /^#var/) {
					print gensub(/^#var/,"",1,outline[i]) >> vartmp;
			    } else if (outline[i] ~ /^#evt/) {
					print outline[i] >> evttmp;
			    } else {
  					print outline[i];
			    }
  			}
  			delete outline;
    	}
    	if (sp != 1) {
    		errprint("iftrue/fi unbalanced at end of file");
		}
   }' $cfg $template > $tmp

${AWK} -v map="$(<$tmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\**\s*@addtogroup MISC/ {
           print "/** @addtogroup MISC";
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
	}' $dst > $newdst

rm -f $tmp
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${dst} misc failed"
   fi
else
   mv -f $newdst $dst
	if [[ ${verbose} == 1 ]]; then
   		echo "${dst} misc done"
	fi
fi
done

#    	for(i in prop) {
#    		print i ": " prop[i];
#    	}
