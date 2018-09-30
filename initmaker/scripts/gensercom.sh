#!/bin/bash

# gensercom.sh <pinmap file>.ini
# modifies sercom section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

scriptpath="${INITMAKER}/scripts"
export AWKPATH="${scriptpath}"

if [[ $# -lt 3 ]]; then
	echo "Usage: gensercom.sh <config file>.ini <target>.c <target>.h {-v}"
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
#"APBA APBA APBB APBB APBD APBD APBD APBD";

errfile="02.000"
boardtmp="${boardsrc%.c}"
dstarr=("${boardsrc}" "${boardinc}")
tmparr=("${boardtmp}.002" "${boardtmp}.003")
newdstarr=("${boardtmp}.000" "${boardtmp}.001")
templatearr=("${INITMAKER}/templates/sercom.c" "${INITMAKER}/templates/sercom.h")
nvictmp="${boardtmp}_nvic.tmp"
isrtmp="${boardtmp}_isr.tmp"
vartmp="${boardtmp}_var.tmp"
today=`date +%D`

for i in 0 1
do
dst="${dstarr[i]}"
tmp="${tmparr[i]}"
newdst="${newdstarr[i]}"
template="${templatearr[i]}"

awk -i "${processor}" -v script="${script}" -v nvictmp="${nvictmp}"  -v isrtmp="${isrtmp}" -v vartmp="${vartmp}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
    	sercom_start = 1;
    	sercom_count = sercom_start;
    	for (i = 0; i < 8; i++) {
    		prop["sercom" i ":interrupt"] = 0;
    	}
    	initpins();
    	initmclk();
	}
	(NR == FNR) && /^[#;]/ {
		next;
	}
	(NR == FNR) && /\[[^\]]+\]/ {
		gsub(/[\[\]\r\n\ \t]/,"");
		key = tolower($0);
		section = key;
		in_section = 0;
		in_pins = 0;
		if (section ~ /pins/) {
			in_pins = 1;
		} else if (section ~ /sercom[0-9]+/) {
			in_section = 1;
			if (match(section, /([0-9]{1,2}$)/, a)) {
				key = section ":unit";
 				if (key in prop) {
 					errprint(toupper(section) " defined more than once");
 				} else {
					prop[key] = a[1];
				}
			}
			delete a;
			devices[sercom_count++] = section;
			prop[section ":macroname"] = "sercom";
		}  else if (key ~ /freq/) {
  			in_section = 1;
  			section = key;
  		}
       	next;
	}
	(NR == FNR) && (in_pins) {
		if (match($0, /([a-zA-Z][a-zA-Z0-9_]*)\s*=\s*(P[AB][0-9]{2})/, arr)) {
			pinport[arr[1]]=arr[2];
			delete arr;
		}
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
    	for (j = sercom_start; j < sercom_count; j++) {
    		instance = devices[j];
    		if (instance ~ /sercom[0-9]+/) {
    			checkfreq(instance, 100000000);
    		}
    		key = instance ":type";
    		if (key in prop) {
				type = prop[instance ":type"];
			} else {
				errprint("Expected property \"type\" in " toupper(instance));
				break;
			}
			switch (type) {
		 		case /i2cm/: 
		 			split("sda scl", arr, " ");
		 			split("0 0", opt, " ");

		 		break;
		 		case /uart/: 
		 			split("txd rxd cts rts", arr, " "); 
		 			split("0 1 1 1", opt, " ");
		 			prop[instance ":txpo"] = 0;
		 			prop[instance ":rxpo"] = 1;
		 		break;
		 		case /spim/: 
		 			split("mosi miso sck ss", arr, " ");
		 			split("0 1 0 1", opt, " ");
		 			prop[instance ":dipo"] = 3;
					prop[instance ":dopo"] = 0;

		 		break;
				default: break;
			}
			for (k in arr) {
    			key = instance ":" arr[k];   				
    			if (key in prop) {
	   				name = prop[key];
    				if (!(name in pinport)) {
    					errprint(name " name for " toupper(instance)  " not found in [pins] section");
    					break;
    				}
    				port = pinport[name];
    				prop[instance ":" arr[k] "_port"] = port;
    				muxkey = port ":" toupper(instance);
    				if (muxkey in pins) {
    					split(pins[muxkey], a, " ");
    					prop[instance  ":" arr[k] "_mux"] = muxcnv(a[1]);
    					prop[instance ":" arr[k] "_pad"] = a[2];
    					prop[instance ":" arr[k] "_padnum"] = unitof(a[2]);
    					delete a;
    				}
    			} else {
    				if (!opt[k]) {
    				 	errprint("Missing property " arr[k] " in " toupper(instance)); 
    				 	break;
    				}
    			}
    		} 
			delete valid;
    		delete arr;
    		delete opt;
    		switch (type) {
    			case /uart/:
        			key = instance ":txd";
        			if (key in prop) {
        				pad = prop[instance ":txd_padnum"];
          				if (pad != 0) {
        					errprint("TXD is on pad " pad " must be on pad 0 of " toupper(instance));
        					break;
        				}
        			} else {
        				key = instance ":rts";
        				if (key in prop) prop[instance ":txpo"] = 2;
    				}
    				key = instance ":rxd";
    				if (key in prop) {
    					prop[instance ":rxpo"] = prop[instance ":rxd_padnum"];
    				}
    				key = instance ":sampr";
    				if (!(key in prop)) {
    					prop[key] = 0;
    				}
   					key = instance ":sampa";
    				if (!(key in prop)) {
    					prop[key] = 0;
    				}
   					key = instance ":form";
    				if (!(key in prop)) {
    					prop[key] = 0;
    				}
   					key = instance ":dord";
    				if (!(key in prop)) {
    					prop[key] = 1;
    				}
    				key = instance ":chsize";
    				if (!(key in prop)) {
    					prop[key] = 8;
    				}
    				chsize = int(prop[key]);
    				if ((chsize < 5) || (chsize > 9)) {
    					errprint("property chsize needs to be between 5 and 9");
    					break;
    				}  
    				prop[instance ":charsize"] = ((chsize < 8) ? chsize : (chsize - 8));
    				
				break;
				case /spim/:
					misokey = instance ":miso";
        			if ((prop[instance ":mosi_padnum"] == 0) && (!(misokey in prop) || (prop[instance ":miso_padnum"] == 3))) {
        				prop[instance ":dipo"] = 3;
        				prop[instance ":dopo"] = 0;
        			} else if ((prop[instance ":mosi_padnum"] == 3) && (!(misokey in prop) || (prop[instance ":miso_padnum"] == 0))) {
        				prop[instance ":dipo"] = 0;
        				prop[instance ":dopo"] = 2;
        			} else {
        				errprint("Invalid pad configuration for SPI master on " toupper(instance));
        			}
   					key = instance ":form";
    				if (!(key in prop)) {
    					prop[key] = 0;
    				}
    				key = instance ":icspace";
    				if (!(key in prop)) {
    					prop[key] = 1;
    				}
   					key = instance ":dord";
    				if (!(key in prop)) {
    					prop[key] = 0;
    				}
    				key = instance ":chsize";
    				if (!(key in prop)) {
    					prop[key] = 8;
    				}
     				chsize = int(prop[key]);
    				if ((chsize < 8) || (chsize > 9)) {
    					errprint("property charsize needs to be 8 or 9");
    					break;
    				}  
    				prop[instance ":charsize"] = chsize - 8;
				break;
				default: 
				break;
			}
 		}
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
    						case /pins/:
    							for (j in pinport) { keys[idx] = j; values[idx++] = pinport[j]; } 
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
  						errprint("fi without matching if in macro " name);
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
			    if(outline[i] ~ /^#nvic/) {
					print gensub(/^#nvic\s+/,"",1,outline[i]) >> nvictmp;
			    } else if(outline[i] ~ /^#isr/) {
					print gensub(/^#isr[ \t]/,"",1,outline[i]) >> isrtmp;
			    } else if (outline[i] ~ /^var/) {
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
   }' $cfg $template > $tmp

awk -v map="$(<$tmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\**\s*@addtogroup SERCOM/ {
           print "/** @addtogroup SERCOM";
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
   	   echo "${dst} sercom failed"
   fi

else
   mv -f $newdst $dst
   if [[ ${verbose} == 1 ]]; then
   	   echo "${dst} sercom done"
   fi
fi
done
