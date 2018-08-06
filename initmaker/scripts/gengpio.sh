#!/bin/bash

# gengpio.sh <config file>.cfg <target>.c <target>.h {-v}
# modifies sercom section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text


scriptpath="${INITMAKER}/scripts"
export AWKPATH="${scriptpath}"

if [[ $# -le 3 ]]; then
	echo "Usage: gengpio.sh <config file>.cfg <target>.c <target>.h {-v}"
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
isrtmp="${boardtmp}_isr.tmp"
vartmp="${boardtmp}_var.tmp"
evttmp="${boardtmp}_evt.tmp"
templatearr=("${INITMAKER}/templates/gpio.c" "${INITMAKER}/templates/gpio.h")
today=`date +%D`

for i in 0 1
do
dst="${dstarr[i]}"
tmp="${tmparr[i]}"
newdst="${newdstarr[i]}"
template="${templatearr[i]}"

awk -i "${processor}" -v script="${script}" -v isrtmp="${isrtmp}" -v evttmp="${evttmp}" -v vartmp="${vartmp}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
    	gpio_count=3;
     	initpins();
	}
	(NR == FNR) && /^[#;]/ {
		next;
	}
	(NR == FNR) && /\[[^\]]+\]/ {
		gsub(/[\[\]\r\n\ \t]/,"");
		key = tolower($0);
		in_section = 0;
		if (key ~ /gpio/) {
  			in_section = 1;
  			section = key gpio_count;
  			devices[gpio_count++] = section;
  			prop[section ":macroname"] = key;
  		} else if (key ~ /eic/) {
  			in_section = 1;
  			section = key;
  			devices[2] = key;
  			prop[section ":macroname"] = key;
  		} else if (key ~ /pins/) {
  			in_section = 1;
  			section = key;
  			devices[1] = key;
  			prop[section ":macroname"] = key;
  		} else if (key ~ /freq/) {
  			in_section = 1;
  			section = key;
  		}
       	next;
	}
	(NR == FNR) && (in_section) && (section ~ /pins/) {
		if (match($0, /([a-zA-Z][a-zA-Z0-9_]*)\s*=\s*(P[AB][0-9]{2})/, arr)) {
			if (arr[1] in pinport) {
				errprint("Duplicate Pin Name " arr[1] " for port " arr[2] " Line: " FNR);
			}
 			pinport[arr[1]]=arr[2];
			delete arr;
		}
		next;
	}
	(NR == FNR) && (in_section) {
		if (match($0, /([a-zA-Z][a-zA-Z0-9_]*)\s*=\s*(.*)[\r\n]+$/, arr)) {
			key = section ":" tolower(arr[1]);
			value = arr[2];
			prop[key] =  value;
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
			errprint("endmacro without a defmacro Line : " FNR);
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
		for (widx in devices) {
			instance = devices[widx];
			key = instance ":in";
			if (key in prop) {
				prop[instance ":port"] = pinport[prop[key]];
			}
			key = instance ":out";
			if (key in prop) {
				prop[instance ":port"] = pinport[prop[key]];
			}
			actkey = instance ":action";
			if (actkey in prop) {
				prop[actkey] = wordtranslate("out set clear toggle", "OUT SET CLR TGL", prop[actkey], toupper(prop[actkey]));
			}
			key = instance ":pin";
			if (key in prop) {
				altkey = instance ":function";
				if (altkey in prop) {
					fun = toupper(prop[altkey]);
					port = pinport[prop[key]];
					prop[instance ":port"] = port;
					pin = port ":" fun;
					if (pin in pins) {
     					split(pins[pin], a, " ");
    					prop[instance ":mux"] = muxcnv(a[1]);
    					prop[instance ":muxpin"] = a[2];
    					delete a;
    				} else {
    					errprint("Alternate function for " instance " is invalid");
    				}
    			} else {
    				errprint("Pin defined but alternate function missing");
    			}
			}
			key = instance ":eic";
			if (key in prop) {
				sig = prop[key];
				port = pinport[prop[key]];
				prop[instance ":port"] = port;
				pinkey = port ":EIC";
				if (pinkey in pins) {
					sensekey = instance ":sense";
					split(pins[pinkey], a, " ");
					prop[instance ":eic_mux"] = muxcnv(a[1]);
					if ((a[2] ~ /NMI/) && (sensekey in prop)) {					
						prop[instance ":nmi"] = wordtranslate("high low rising falling both", "HIGH LOW RISE FALL BOTH", prop[sensekey], "NONE");
					} else {
						prop[instance ":eic_pin"] = a[2];
						match(a[2], /([0-9]+)$/, arr);
						num = arr[1];
						delete arr;
						if ((num in eicinterrupt) ||(num in genevent)) {
							errprint("EIC" num " is assigned more than once");
						} else {
							intkey = instance ":interrupt";
							if (intkey in prop) {
								eicinterrupt[num] = sig;
								eicpin[num] = sig;
								prop["eic:eic_interrupt"] = 1;
								prop["eic:eic_pin"] = 1;
							}
							dkey = instance ":debounce";
							if (dkey in prop) {
								eicdebounce[num] = sig;
								prop["eic:eic_debounce"] = 1;
								key = instance ":prescaler0";
								if (!(key in prop)) {
									prop[key] = 5;
								}
								key = instance ":prescaler1";
								if (!(key in prop)) {
									prop[key] = 5;
								}
							}
							evtkey = instance ":generator";
							if (evtkey in prop) {
								genevent[num] = sig;
								prop["eic:gen_event"] = 1;
								eicpin[num] = sig;
								prop["eic:eic_pin"] = 1;
							}
  							edgekey = instance ":edge";
  							if (!(edgekey in prop)) {
  								prop[edgekey] = "NONE";
  							}
  							pathkey = instance ":path";
  							if (!(pathkey in prop)) {
  								prop[pathkey] = "ASYNCHRONOUS";
  							}
  							synckey = instance ":sync_source";
  							if (!(synckey in prop)) {
  								prop[synckey] = "NONE";
  							}
  							asynckey = instance ":async";
  							if (asynckey in prop) {
  								eicasync[num] = sig;
  								prop["eic:eic_async"] = 1;
  							}
							eicsense[sig] = wordtranslate("high low rising falling both", "HIGH LOW RISE FALL BOTH", prop[sensekey], "NONE");
						}
					}
					delete a;
				} else {
					errprint("Signal " sig " (" port ") not valid for EIC");
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
   				if (line ~ /#foreach/) {
  					i++;
 					idx = 1;  								
  					if (match(line, /^#foreach\s+([a-zA-Z0-9_]+)/, a)) {
    					switch (a[1]) {
    						case /pins/:
     							for (j in pinport) { keys[idx] = j; values[idx++] = pinport[j]; } 
     							keyname = "pinname"; valuename = "portname";
    						break;
   							case /eic_interrupt/:
    							for (j in eicinterrupt) { keys[idx] = j; values[idx++] = eicinterrupt[j]; }
    							keyname = "eicnumber"; valuename = "pinname";    							
 							break;
   							case /gen_event/:
        						for (j in genevent) { keys[idx] = j; values[idx++] = genevent[j]; }
    							keyname = "eicnumber"; valuename = "pinname";    							
      						break;
    						case /eic_debounce/:
   								for (j in eicdebounce) { keys[idx] = j; values[idx++] = eicdebounce[j]; }
    							keyname = "eicnumber"; valuename = "pinname";    							
    						break;
    						case /eic_sense/:
    							for (j in eicsense) { keys[idx] = j; values[idx++] = eicsense[j]; }
    							keyname = "pinname"; valuename = "eicsense";    							
    						break;
    						case /eic_async/:
    							for (j in eicasync) { keys[idx] = j; values[idx++] = eicasync[j]; }
    							keyname = "eicnumber"; valuename = "eicasync";    							
    						break;
    						case /eic_pin/:
    							for (j in eicpin) { keys[idx] = j; values[idx++] = eicpin[j]; }
    							keyname = "eicnumber"; valuename = "pinname";    							
    						break;
  							default: errprint("Bad argument " a[1] " for foreach statement"); break;
  						}
   						delete a;
  					} else {
   						errprint("Missing argument for foreach");
   						break;
   					}
   					stack[++sp] = (idx > 1);
					idx = 1;  								
  					prop[name ":" keyname] = keys[idx];
  					prop[name ":" valuename] = values[idx];
  					line = macro[i];
  					loopstart = i;
   				} else if (line ~ /#endfor/) {
  					if (++idx <= length(keys)) {
  						i = loopstart;
 						prop[name ":" keyname] = keys[idx];
  						prop[name ":" valuename] = values[idx];
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
  							errprint("Unknown property " txtsub " in macro " name "+" i);
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
			    if(outline[i] ~ /^#isr/) {
					print gensub(/^#isr\s+/,"",1,outline[i]) >> isrtmp;
			    } else if (outline[i] ~ /^#var/) {
					print gensub(/^#var/,"",1,outline[i]) >> vartmp;
			    } else if (outline[i] ~ /^#evt/) {
					print gensub(/^#evt/,"",1,outline[i]) >> evttmp;
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

awk -v map="$(<$tmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\**\s*@addtogroup GPIO/ {
           print "/** @addtogroup GPIO";
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
	}' $dst > $newdst

rm -f $tmp
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${dst} gpio failed"
   fi
else
   mv -f $newdst $dst
	if [[ ${verbose} == 1 ]]; then
   		echo "${dst} gpio done"
	fi
fi
done
