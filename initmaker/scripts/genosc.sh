#!/bin/bash

# genoscsrc.sh <pinmap file>.ini
# modifies oscillator section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

scriptpath="${INITMAKER}/scripts"
export AWKPATH="${scriptpath}"

if [[ $# -lt 2 ]]; then
	echo "Usage: genosc.sh <config file>.ini <board src>.c <board inc>.h processor 1|0"
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
templatearr=("${INITMAKER}/templates/osc.c" "${INITMAKER}/templates/osc.h")
nvictmp="${boardtmp}_nvic.tmp"
vartmp="${boardtmp}_var.tmp"
evttmp="${boardtmp}_evt.tmp"
cfgtmp="${boardtmp}_cfg.tmp"

today=`date +%D`

for i in 0 1
do
dst="${dstarr[i]}"
tmp="${tmparr[i]}"
newdst="${newdstarr[i]}"
template="${templatearr[i]}"

awk -i "${processor}" -v script="${script}" -v nvictmp="${nvictmp}" -v evttmp="${evttmp}" -v vartmp="${vartmp}" -v cfgtmp="${cfgtmp}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
     	nvmctrl_count = 1;
    	osculp32k_count = 2;
    	xosc32k_count = 3;
    	mclk_count = 4;
    	xosc_count = 10;
    	dpll_gclk_start = 20;
    	dpll_gclk_count = dpll_gclk_start;
    	dpll_gclk_sync_count = 30;
    	dfll_count = 40;
    	dpll_count = 42;
    	gclk_start = 50;
    	gclk_count = gclk_start;
    	gclk_sync_count = 80;
    	
    	devices[nvmctrl_count] = "nvmctrl";
    	prop["nvmctrl:macroname"] = "nvmctrl";
    	prop["nvmctrl:wait_states"] = 0;
    	prop["dpll_gclk_sync:macroname"] = "dpll_gclk_sync";
    	prop["gclk_sync:macroname"] = "gclk_sync";
     	prop["mclk:div"] = 1;
      	prop["dpll0:div"] = 1;
      	prop["dpll1:div"] = 1;
    	prop["xosc32k:startup"] = 3;
    	prop["dfll:fstep"] = 1;
    	prop["dfll:cstep"] = 1;
    	prop["dfll:mode"] = 1;
		prop["osculp32k:ext_frequency"]=32768
		prop["xosc32k:ext_frequency"]=32768
    	initpins();
	}
	(NR == FNR) && /^[#;]/ {
		next;
	}
	(NR == FNR) && /\[[^\]]+\]/ {
		gsub(/[\[\]\r\n\ \t]/,"");
		key = tolower($0);
		in_section = 1;
		section = key;
		setunit = 0;
		in_pins = 0;
		switch (section) {
			case /pins/: 
				in_pins = 1;
			break;
			case /nvmctrl/:
				prop["nvmctrl:macroname"] = "nvmctrl";
			break;
			case /dfll/: 
				devices[dfll_count] = section; 
				prop["dfll:macroname"] = "dfll";
			break;
			case /osculp32k/: 
				devices[osculp32k_count] = section; 
				prop["osculp32k:macroname"] = "osculp32k";
			break;
			case /xosc32k/: 
				devices[xosc32k_count] = section; 
				prop["xosc32k:macroname"] = "xosc32k";
			break;
			case /mclk/: 
				devices[mclk_count] = section;
				prop["mclk:macroname"] = "mclk";
			break;
			case /xosc[0-9]+/: 
				devices[xosc_count++] = section; 
				prop[section ":macroname"] = "xosc";
				setunit = 1;
			break;
			case /gclk[0-9]+/: 
				devices[gclk_count++] = section; 
				prop[section ":macroname"] = "gclk";				
				setunit = 1;
			break;
			case /dpll[0-9]+/: 
				devices[dpll_count++] = section; 
				prop[key ":macroname"] = "dpll";								
				setunit = 1;
			break;
			default: in_section = 0; section = ""; break;
		}
		if (setunit) {
			if(match(section, /([0-9]{1,2}$)/, a)) {
 				key = section ":unit";
 				if (key in prop) {
 					errprint(toupper(section) " defined more than once");
 				} else {
					prop[key] = a[1];
				}
			}
			delete a;
		}
       	next;
	}
	(NR == FNR) && (in_pins) {
		if (match($0, /([a-zA-Z][a-zA-Z0-9_]*)\s*=\s*(P[AB][0-9]{2})/, arr)) {
 			pinport[arr[1]]=arr[2];
			delete arr;
		}
		next;
	}
	(NR == FNR) && (in_section == 1) {
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
		key = "mclk:div";
		if (key in prop) {
			div = prop[key];
			if ((bitcount(div) != 1) || (div > 128)) {
				errprint("Invalid divisor value in mclk" j);
			}
		}
		firstgclk = 1;
		for (j = 0; j < unitmax["gclk"]; j++) {
			key = "gclk" j ":ref_source";
			if (key in prop) {
				refsrc = prop[key];
				indkey = refsrc ((refsrc ~ /^(dpll[01])|(dfll)$/) ?  ":out_frequency" :  ":ext_frequency");
				if (indkey in prop) {
					fout = prop[indkey];
					prop["gclk" j ":ref_frequency"] = fout;
					key = "gclk" j ":div";
					if (!(key in prop)) prop[key] = 1;
					prop["gclk" j ":out_frequency"] = fout/prop[key];
					if (firstgclk) {
						print "[FREQ]\r" > cfgtmp;
						firstgclk = 0;
					}
					print "gclk" j "=" prop["gclk" j ":out_frequency"] "\r" >> cfgtmp;
				}
			}
			key = "gclk" j ":out";
			if (key in prop) {
				outpin = prop[key];
				if (outpin in pinport) {
					port = pinport[outpin];
					prop["gclk" j ":port"] = port;
					muxkey = port ":GCLK";
					if (muxkey in pins) {
						split(pins[muxkey], a, " ");
    					prop["gclk" j ":mux"] = muxcnv(a[1]);
    					prop["gclk" j ":io"] = a[2];
    					delete a;
					} else {
						errprint(port " is not valid GCLK output");
					}
				} else {
					errprint("GCLK" j " has output " outpin " which is not assigned a port");
				}
			}
			key = "gclk" j ":in";
			if (key in prop) {
				inpin = prop[key];
				if (inpin in pinport) {
					port = pinport[inpin];
					prop["gclk" j ":port"] = port;
					muxkey = port ":GCLK";
					if (muxkey in pins) {
						split(pins[muxkey], a, " ");
    					prop["gclk" j ":mux"] = muxcnv(a[1]);
    					prop["gclk" j ":io"] = a[2];
    					delete a;
					} else {
						errprint(port " is not valid GCLK input");
					}
					freqkey = "gclk" j ":ext_frequency";
					if (freqkey in prop) {
						fout = prop[freqkey];
						prop["gclk" j ":ref_frequency"] = fout;
						key = "gclk" j ":div";
						if (!(key in prop)) prop[key] = 1;
						prop["gclk" j ":out_frequency"] = fout/prop[key];
					}
				} else {
					errprint("GCLK" j " has input " inpin " which is not assigned a port");
				}
			}
		}
		lastsrc = "";
		key = "dfll:macroname";
		if (key in prop) {
			key = "dfll:ref_source";
			if (key in prop) {
				src = prop[key];
				outkey = src ":out_frequency";
     			if (!(outkey in prop)) {
    				errprint("out_frequency not defined for " src);
    			} else {
    				ref = prop[outkey];
    				prop["dfll:mul"] = int((prop["dfll:out_frequency"]/ref) + 0.5);
 					if (src ~ /gclk[0-9]+/) {
    					for (k = gclk_start; k < gclk_count; k++) {
        					if ((k in devices) && (devices[k] ~ src)) {
        						delete devices[k];
        						devices[dpll_gclk_count++] = src;
        						devices[dpll_gclk_sync_count] = "dpll_gclk_sync";
        						break;
        					}
        				} 
        			}
        		}
			}
		}

		for (j = 0; j < unitmax["dpll"]; j++) {
			key = "dpll" j ":macroname";
			if (key in prop) {
    			key = "dpll" j ":ref_source";
    			if (key in prop) {
    				src = prop[key];
    				prop["dpll" j ":divisor"] = 0;
    				if (src ~ /xosc32k/) {
        				extkey = src ":ext_frequency";
         				if (!(extkey in prop)) {
        					errprint("ext_frequency not defined for " src);
        					break;
        				}
        				ref = prop[extkey];
   						prop["dpll" j ":ref_name"] = "xosc32";
    					prop["dpll" j ":ref_frequency"] = ref;
   					} else if (src ~ /gclk[0-9]+/) {
    					outkey = src ":out_frequency";
     					if (!(outkey in prop)) {
    						errprint("out_frequency not defined for " src);
    						break;
    					}
    					ref = prop[outkey];
    					prop["dpll" j ":ref_name"] = "gclk";
    					prop["dpll" j ":ref_frequency"] = ref;
    					for (k = gclk_start; k < gclk_count; k++) {
    						if ((k in devices) && (devices[k] ~ src)) {
    							delete devices[k];
    							devices[dpll_gclk_count++] = src;
    							devices[dpll_gclk_sync_count] = "dpll_gclk_sync";
    							break;
    						}
    					} 
    				} else if (src ~ /xosc[01]/) {
        				extkey = src ":ext_frequency";
         				if (!(extkey in prop)) {
        					errprint("ext_frequency not defined for " src);
        					break;
        				}
        				ref = prop[extkey];
    					prop["dpll" j ":ref_name"] = src;
    					divkey = "dpll" j ":div";
  						div = (prop[divkey] / 2) - 1;
  						prop["dpll" j ":divisor"] = div;
  						ref = (ref / ((div + 1) * 2));
   						prop["dpll" j ":ref_frequency"] = ref;
					}
    			} else {
    				errprint("no ref_source for dpll" j);
    			}
    			key = "dpll" j ":out_frequency";
    			if (key in prop) {
    				fout = prop[key];
    				intref = "dpll" j ":integeronly";
    				if (ref > 0) {		
    					prop["dpll" j ":ldr"] = int(fout/ref) - 1;
    					prop["dpll" j ":ldrfrac"] = ((intref in prop) ? 0 : (int(((fout/ref) - int(fout/ref)) * 32)));
    				}
    			}
    		}
    	}
  		if (((gclk_count - gclk_start) - (dpll_gclk_count - dpll_gclk_start)) > 0) {
  			devices[gclk_sync_count] = "gclk_sync";
  			prop["gclk_sync:macroname"] = "gclk_sync";
  		}
    	
		sp = 0;
		stack[sp] = 1; 
		for (widx in devices) {
			instance = devices[widx];
			key = instance ":macroname";
			name = prop[instance ":macroname"];
    		if (name ~ "^dpll$") {
     			key = instance ":ref_frequency";
    			if (key in prop) {
    				ref = prop[key] + 0.0;
    				if ((ref > 3200000.0) || (ref < 32000.0)) {
        				errprint("Reference Clock must be between 32KHz and 3.2MHz is " ref);
        			}
   				}
   				key = instance ":out_frequency";
   				if (key in prop) {
    				freq = prop[key] + 0.0;
     				if ((freq > 200000000.0) || (freq < 96000000.0)) {
        				errprint("DPLL output must be between 96MHz and 200MHz is " freq);
        			}
        		}
    		}
  			olp = 1;
  			for (i = beginmacro[name]; i < endmacro[name]; i++) {
  				line = macro[i];
  				if (line ~ /#foreach/) {
  					i++;
    				idx=1; 
  					if (match(line, /^#foreach\s+([a-zA-Z0-9_]+)/, a)) {
    					switch (a[1]) {
    						case /pins/:
    							for (j in pinport) { keys[idx] = j; values[idx++] = pinport[j]; } 
    						break;
    						case /^dpll_gclk/:
    							for (j = dpll_gclk_start; j < dpll_gclk_count; j++) {
     									keys[idx] = j; values[idx++] = prop[devices[j] ":unit"]; 
    							}
    						break;
    						case /^gclk/:
       							for (j = gclk_start; j < gclk_count; j++) {
									if (j in devices) {
     									keys[idx] = j; values[idx++] = prop[devices[j] ":unit"]; 
     								}
    							} 
   							break;
   							case /osc_event/:
        						for (j in oscevent) { keys[idx] = j; values[idx++] = oscevent[j]; }
      						break;
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
  				 	delete outline[i];
  				}
  			}
  			for (i in outline) {
			    if(outline[i] ~ /^#nvic/) {
					print gensub(/^#nvic\s+/,"",1,outline[i]) >> nvictmp;
			    } else if (outline[i] ~/^#var/) {
					print gensub(/^#var/,"",1,outline[i]) >> vartmp;
			    } else if (outline[i] ~ /^#evt/) {
					print gensub(/^#evt/,"",1,outline[i]) >> evttmp;
			    } else {
  					print outline[i];
			    }
  			}
  			delete outline;
    	}
       	if (sp != 0) {
    		errprint("iftrue/fi unbalanced at end of file");
		}
   }' ${cfg} ${template} > ${tmp}

awk -v map="$(<$tmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\**\s*@addtogroup clocking/ {
           print "/** @addtogroup clocking";
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
           }
	}' ${dst} > ${newdst}

rm -f $tmp
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${dst} clocks failed"
   fi
else
   mv -f $newdst $dst
   if [[ ${verbose} == 1 ]]; then
   	   echo "${dst} clocks done"
   fi
fi
done
