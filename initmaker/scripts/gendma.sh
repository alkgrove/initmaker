#!/bin/bash

# gendma.sh <config file>.cfg <target>.c <target>.h {-v} {-s}
# modifies sercom section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text


#scriptpath="${INITMAKER}/scripts"
#export AWKPATH="${scriptpath}"

if [[ $# -le 3 ]]; then
	echo "Usage: gendma.sh <config file>.cfg <target>.c <target>.h {-v}"
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
templatearr=("${INITMAKER}/templates/dma.c" "${INITMAKER}/templates/dma.h")
today=`date +%D`

for i in 0 1
do
dst="${dstarr[i]}"
tmp="${tmparr[i]}"
newdst="${newdstarr[i]}"
template="${templatearr[i]}"

${AWK} -v script="${script}" -i "${processor}" -v rsrctmp="${rsrctmp}" -v evttmp="${evttmp}" -v vartmp="${vartmp}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
    	dma_start=10;
    	dma_count=dma_start;
	for (i = 0; i < 31; i++) {
		prop["dma" i ":priority"] = -1;
	}
     	initpins();
	}
	(NR == FNR) && /^[#;]/ {
		next;
	}
	(NR == FNR) && /\[[^\]]+\]/ {
		gsub(/[\[\]\r\n \t]/,"");
		key = tolower($0);
		in_section = 0;
		if (key ~ /dma[0-9]+/) {
  			in_section = 1;
  			section = key;
  			devices[dma_count++] = section;
  			prop[section ":macroname"] = "dma";
  			if(match(section, /([0-9]{1,2}$)/, a)) {
  				key = section ":unit";
 				if (key in prop) {
 					errprint(toupper(section) " defined more than once");
 				} else {
					prop[key] = a[1];
				}
			}
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
		if (dma_count > dma_start) {
			devices[1] = "dma_init";
			prop["dma_init:macroname"] = "dma_init";
			devices[100] = "dma_end";
			prop["dma_end:macroname"] = "dma_end";
		}
		for (i = dma_start; i < dma_count; i++) {
			instance = devices[i];
			key = instance ":source";
			trigsrc = "SOFTWARE";
			if (key in prop) {
				trigsrc = toupper(prop[key]);
				if ((trigsrc ~ /SOFTWARE/) || (trigsrc ~ /EVENT/)) {
					trigsrc = "SOFTWARE";
				}
			}
			key = instance ":channel";
			if (key in prop) {
				trigsrc = trigsrc "_" toupper(prop[key]);
			} else if (trigsrc !~ /SOFTWARE/) {
				errprint("Unknown Trigger Source for DMA" prop[instance ": b"]);
				break;
			}
			prop[instance ":trigsrc"] = trigsrc;
			key = instance ":burstlen";
			bl = (key in prop) ? prop[key] : 1;
			if (bl ~ /^[0-9]+$/) {
				if (int(bl) > 16) {
					errprint("Invalid Burst Length for DMA " prop[instance ":unit"]);
				}
				prop[key] = ((bl == 1) ? "SINGLE" : bl "BEAT");
			}
			key = instance ":threshold";
			bl = (key in prop) ? prop[key] : 1;
			if (bl ~ /^[0-9]+$/) {
				if ((bitcount(bl) != 1) && (bl > 8)){
					errprint("Invalid Threshold for DMA " prop[instance ":unit"]);
				}
				prop[key] = ((bl == 1) ? "1BEAT" : bl "BEATS");
			}
			key = instance ":event";
			if (key in prop) {
				actkey = instance ":evact";
				if (!(actkey in prop)) {
					prop[actkey] = "NOACT";
				}
				if (prop[instance ":unit"] > 7) {
					errprint("DMA Events must be on channels 0 through 7 only");
				}
			}
			key = instance ":generator";
			if (key in prop) {
				if (prop[instance ":unit"] > 3) {
					errprint("DMA Event Generators must bon on channels 0 throgh 3 only");
				}
				evintkey = instance ":evint";
  				if (!(evintkey in prop)) {
  					prop[evintkey] = "0";
  				}
			}
		}
		sp = 0;
		stack[++sp] = 1;
		for (widx in devices) {
			instance = devices[widx];
			name = prop[instance ":macroname"];
  			olp = 1;
  			for (i = beginmacro[name]; i < endmacro[name]; i++) {
  				line = macro[i];
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
			    if(outline[i] ~ /^#(nvic|mod)/) {
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
    		errprint(" At end of file and iftrue/fi unbalanced");
		}
   }' $cfg $template > $tmp

${AWK} -v map="$(<$tmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\**\s*@addtogroup DMA/ {
           print "/** @addtogroup DMA";
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
   	   echo "${dst} dma failed"
   fi
else
   mv -f $newdst $dst
	if [[ ${verbose} == 1 ]]; then
   		echo "${dst} dma done"
	fi
fi
done
