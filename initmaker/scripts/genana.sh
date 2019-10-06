#!/bin/bash

# genana.sh <config file>.cfg <target>.c <target>.h {-v}
# modifies analog section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

#scriptpath="${INITMAKER}/scripts"
#export AWKPATH="${scriptpath}"

if [[ $# -le 3 ]]; then
	echo "Usage: genana.sh <config file>.cfg <target>.c <target>.h {-v}"
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
templatearr=("${INITMAKER}/templates/analog.c" "${INITMAKER}/templates/analog.h")
today=`date +%D`

for i in 0
do
dst="${dstarr[i]}"
tmp="${tmparr[i]}"
newdst="${newdstarr[i]}"
template="${templatearr[i]}"

awk -v script="${script}" -v rsrctmp="${rsrctmp}" -v vartmp="${vartmp}" -v evttmp="${evttmp}" -i "${processor}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
    	supc_count = 10;
		adc_count = 20;
		dac_count = 100;
     	initpins();
     	initmclk();
     	for (i = 0; i < unitmax["adc"]; i++) {
			prop["adc" i ":samplenum"] = 1;
			prop["adc" i ":adjres"] = 0;
			prop["adc" i ":samplen"] = 0;			
			prop["adc" i ":prescaler"] = "div2";
			prop["adc" i ":overrun_priority"] = -1;
			prop["adc" i ":winmon_priority"] = -1;
			prop["adc" i ":resrdy_priority"] = -1;
		}
		prop["dac:dacctrl0_osr"] = 1;
		prop["dacctrl0_refresh"] = 0;
	}
	(NR == FNR) && /^[#;]/ {
		next;
	}
	(NR == FNR) && /\[[^\]]+\]/ {
		gsub(/[\[\]\r\n \t]/,"");
		key = tolower($0);
		in_section = 0;
		if (key ~ /adc[0-9]+/) {
  			in_section = 1;
  			section = key;
 			if (match(section, /([0-9]{1,2}$)/, a)) {
 				key = section ":unit";
 				if (key in prop) {
 					errprint(toupper(section) " defined more than once");
 				} else {
					prop[key] = a[1];
				}
			}
			delete a;
 			devices[adc_count++] = section;
  			prop[section ":macroname"] = "adc";
  		} else if (key ~ /dac/) {
  			in_section = 1;
  			section = key;
  			devices[dac_count] = section;
  			prop[section ":macroname"] = "dac";
  		} else if (key ~ /supc/) {
  			in_section = 1;
  			section = key;
  			devices[supc_count] = section;
  			prop[section ":macroname"] = "supc";
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
			checkfreq(instance, 100000000);
			if (!("dac:cctrl" in prop)) {
				keyclk = "dac:ref_source";
				if (keyclk in prop) {
					keyfreq = "freq:" prop[keyclk];
					if (keyfreq in prop) {
						value = int(prop[keyfreq]);
						if (value <= 1200000) {
							prop["dac:cctrl"] = "CC100K";
						} else if (value <= 6000000) {
							prop["dac:cctrl"] = "CC1M";
						} else {
							prop["dac:cctrl"] = "CC12M";
						} 						
					}
				}
			}
			refselkey = instance ":refsel";
			if (refselkey in prop) {
				prop[refselkey] = wordtranslate("vrefau vddana vrefab intref", "VREFPU VDDANA VREFPB INTREF", prop[refselkey], toupper(prop[refselkey]));
			}
			prop[instance ":vref"] = (("supc:sel" in prop) ? gensub(/V/, ".", 1, prop["supc:sel"]) "V" : "");
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
  							default: errprint("Bad argument " a[1] " for foreach"); break;
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

awk -v map="$(<$tmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\**\s*@addtogroup Analog/ {
           print "/** @addtogroup Analog";
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
   	   echo "${dst} analog failed"
   fi
else
   mv -f $newdst $dst
	if [[ ${verbose} == 1 ]]; then
   		echo "${dst} analog done"
	fi
fi
done

#    	for(i in prop) {
#    		print i ": " prop[i];
#    	}
