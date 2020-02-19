#!/bin/bash

# genevent.sh <target>.c {-v}
# modifies EVSYS section
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

#scriptpath="${INITMAKER}/scripts"
#export AWKPATH="${scriptpath}"

if [[ $# -le 2 ]]; then
	echo "Usage: genevent.sh <target>.c <target>.h <processor>.awk <verbose>"
	exit 1
fi
if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi
script="$0"
boardsrc="$1"
boardinc="$2"
processor="$3"
verbose="$4"

errfile="02.000"
boardtmp="${boardsrc%.c}"
evttmp="${boardtmp}_evt.tmp"
rsrctmp="${boardtmp}_rsrc.tmp"
dstarr=("${boardsrc}" "${boardinc}")
tmparr=("${boardtmp}.002" "${boardtmp}.003")
newdstarr=("${boardtmp}.000" "${boardtmp}.001")
templatearr=("${INITMAKER}/templates/event.c" "${INITMAKER}/templates/event.h")

today=`date +%D`

for i in 0 1
do
dst="${dstarr[i]}"
tmp="${tmparr[i]}"
newdst="${newdstarr[i]}"
template="${templatearr[i]}"
 
if [[ -f ${evttmp} ]]; then
${AWK} -v script="${script}" -v evttmp="${evttmp}" -v rsrctmp="${rsrctmp}" -i "${processor}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
        prop["evsys:macroname"] = "evsys";
     	initpins();
        sync_start = 0;
        async_start = 12;
        out_start = 0;
        sync_count = sync_start;
        async_count = async_start;
        out_count = out_start;
        devices[evt_count] = "evsys";
	}
	(NR == FNR) && /^#evt/ {
		gsub(/[\r\n]/, "");
		if ($2 ~ /swgen/) {
			eventlist[$3] = 0;
			swgenlist[async_count++] = $3;
			prop["evsys:swgenerators"] = 1;
		} else if ($2 ~ /gen/) {
			if (tolower($5) ~ /asynchronous/) {
				eventlist[$3] = 0;
				genidlist[async_count] = $4;
				pathlist[async_count] = $5;
				edgelist[async_count] = $6;
				eventname[async_count++] = $3;
			} else {
				eventlist[$3] = 0;
				genidlist[sync_count] = $4;
				pathlist[sync_count] = $5;
				edgelist[sync_count] = $6;
				clocklist[sync_count] = $7;
				evintlist[sync_count] = $8;
				prop["evsys:clocks"] = 1;
				eventname[sync_count++] = $3;
				if (sync_count >= async_start) {
					errprint("Too many synchronous event channels");
				}
			}
			prop["evsys:generators"] = 1;
		} else if ($2 ~ /event/) {
			username[out_count] = $3;
			userid[out_count++] = $4;
		}
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
		for (i in username) {
			name = username[i];
			if (name in eventlist) {
				eventlist[name] = 1;
			} else {
				warnprint("Event driver " name " without generator");
			}
		}
		for (name in eventlist) {
			if (eventlist[name] == 0) {
				warnprint("Event generator " name " without driver");
			}
		}
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
    					case /clocks/:
    						for (j in clocklist) { keys[idx] = j; values[idx++] = toupper(clocklist[j]); } 
    						keyname = "channel"; valuename = "clock";
    					break;
          				case /users/:
    						for (j in username) { keys[idx] = username[j]; values[idx++] = userid[j]; }
    						keyname = "username"; valuename = "userid";
        				break;
        				case /swgenerators/:
        					for (j in swgenlist) {
        						keys[idx] = j;
        						evtname[idx++] = swgenlist[j];
        					}
     						keyname = "channel"; valuename = "notused";
       					break;
          				case /generators/:
    						for (j in genidlist) { 
    							keys[idx] = j; 
    							values[idx] = genidlist[j]; 
    							path[idx] = pathlist[j];
    							edge[idx] = wordtranslate("rising falling both", "RISING_EDGE FALLING_EDGE BOTH_EDGES", edgelist[j], "NO_EVT_OUTPUT");
								evint[idx] = evintlist[j];
    							evtname[idx++] = eventname[j];
    						}
    						keyname = "channel"; valuename = "genid";
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
          			prop[name ":" keyname] = keys[idx];
          			prop[name ":" valuename] = values[idx];
          			prop[name ":path"] = path[idx];
          			prop[name ":edge"] = edge[idx];
          			prop[name ":eventname"] = evtname[idx];
           			prop[name ":evint"] = evint[idx];
          			line = macro[i];
          			loopstart = i;
          		} else if (line ~ /#endfor/) {
          			if (++idx <= length(keys)) {
          				i = loopstart;
          				prop[name ":" keyname] = keys[idx];
          				prop[name ":" valuename] = values[idx];
          				prop[name ":path"] = path[idx];
          				prop[name ":edge"] = edge[idx];
          				prop[name ":eventname"] = evtname[idx];
           				prop[name ":evint"] = evint[idx];
          			} else {
   						--sp;
        				delete keys;
          				delete values;
          				delete path;
          				delete edge;
          				delete evtname;
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
          		 	outline[j] = gensub(/,}/, "}", "g", outline[j]);
          		 	delete outline[i];
          		}
          	}
          	for (i in outline) {
			    if(outline[i] ~ /^#nvic/) {
					print outline[i] >> rsrctmp;
			    } else if (outline[i] ~ /^#var/) {
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
   }' ${evttmp} ${template} > ${tmp}
else
touch $tmp
fi
${AWK} -v map="$(<$tmp)" -v date="$today" 'BEGIN {
	   skip=0
	}
	/\/\*+\s+@addtogroup\s+EVSYS/ {
           print "/** @addtogroup EVSYS";
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
	}' ${dst} > ${newdst}

rm -f ${tmp}
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${dst} event failed"
   fi
else
   	mv -f ${newdst} ${dst}
	if [[ ${verbose} == 1 ]]; then
   		echo "${dst} event done"
	fi
fi
done

