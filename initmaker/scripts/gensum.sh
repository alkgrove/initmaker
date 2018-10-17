#!/bin/bash

# gensum.sh <pinmap file>.cfg
# generates summary
# Copyright © 2018, Alkgrove
# BSD 3-clause license - see initmaker/LICENSE.txt for license text

scriptpath="${INITMAKER}/scripts"
export AWKPATH="${scriptpath}"

if [[ $# -lt 2 ]]; then
	echo "Usage: gensum.sh <config file>.cfg <processor> <srcfile> {-v}"
	exit 1
fi
if [[ ! -f $1 ]]; then
	echo "$1 file not found"
	exit 1
fi
script="$0"
cfg="$1"
boardsrc="$2"
processor="$3"
verbose="$4"
sum="$5"
errfile="02.000"
summary="${cfg%.*}.txt"
rsrctmp="${boardsrc%.c}_rsrc.tmp"
evttmp="${boardsrc%.c}_evt.tmp"

tmp="002.000"
if [[ -f ${evttmp} ]]; then
cat ${rsrctmp} ${evttmp} >> ${tmp}
else
cp ${rsrctmp} ${tmp}
fi

awk -i "${processor}" -v script="${script}" '@include "functions.awk"
	BEGIN {
    	section="";
    	linecount=1;
    	in_macro=0;
    	in_section=0;
    	nvic_count=1;
    	gen_count=1;
    	event_count=1
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
		} else if (section ~ /board/) {
			in_section = 1;
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
	(NR != FNR) && /^#port/ {
		port[$2] = gensub(/^#port\s+P[A-Z][0-9][0-9]\s+/,"",1,$0);
		next;
	}
	(NR != FNR) && /^#mod/ {
		mod[$2] = gensub(/^#mod\s+[^ \t]+\s+/,"",1,$0);
		next;
	}
	(NR != FNR) && /^#nvic/ {
		nvic[nvic_count++] = "void " gensub(/\s+$/,"",1,$4) "(void) /* ISR for " $2 " */"
		next;
	}
	(NR != FNR) && /^#clk/ {
		key = tolower($2);
		freq[key] = $3;
		clocks[key] = gensub(/^#clk\s+[a-zA-Z0-9]+\s+/,"",1,$0);
		unitkey = unitof(key);
		switch (key) {
			case /xosc32k/:  clock_ol[1] = key; break;
			case /osculp32k/: clock_ol[2] = key; break;
			case /xosc(0|1)/: clock_ol[unitkey+3] = key; break;
			case /dfll/: clock_ol[5] = key; break;
			case /dpll(0|1)/: clock_ol[unitkey+6] = key; break;
			case /gclk[0-9]+/: clock_ol[unitkey+8] = key; break;
			default: errprint("Clock key " key " is unknown"); break;
		}	
		next;
	}
	(NR != FNR) && /^#evt/ {
		if ($2 ~ /swgen/) {
			gen[gen_count++] = gensub(/^#evt\s+/,"",1,$0);
		} else if ($2 ~ /gen/) {
			gen[gen_count++] = gensub(/^#evt\s+gen\s+/,"",1,$0);
		} else if ($2 ~ /event/) {
			if ($4 ~ /^PORT_EV_/) {
				portevt[$5] = ($5 in portevt) ? (portevt[$5] ", EVENT " $3 " " gensub(/\s+$/,"", 1,$6) " (" $4 ")") : (" EVENT " $3 " "  gensub(/\s+$/,"", 1,$6) " (" $4 ")");
			}
			evt[event_count++] = gensub(/^#evt\s+event\s+/,"",1,$0);
		}
		next;
	}
	(NR != FNR) {
		next;	
	}
	END {
	str = "Initmaker Summary ";
	key = "board:project";
	if (key in prop) {
		print "Initmaker Summary for " prop[key];
	} else {
		print "Initmaker Summary";
	}
	key = "board:description";
	if (key in prop) {
		print prop[key];
	}
	print "Processor " prop["board:processor"];
	key = "board:author";
	str = "";
	if (key in prop) {
		str = "by " prop[key];
	}
	key = "board:company";
	if (key in prop) {
		str = str ", " prop[key];
	}
	if (length(str) > 0) {
		print str;
	}
	print "\nPin Alias List";
	for (i in pinport) {
		key = pinport[i];
		portpin[key] = (key in portpin) ? (portpin[key] ", " i) : i;
	}			
	n=asort(pinport, sorted);
	for(i=1; i <= n; i++) {
		if ((i == n) || (sorted[i] != sorted[i+1])) {
			portitem = sorted[i];
			str=portitem " (" portpin[portitem] ") ";
			desc=gensub("_", " ", "g", gensub(/\s+$/, "", 1, port[portitem]));			
			if (portitem in port) {
				str = str desc;
			}
			if (portitem in portevt) {
				str = str portevt[portitem];
			}
			print str;
		}
	}
	delete sorted;
	print "\nPort List";
	n=asorti(pinport, sorted)
	for (i=1; i<=n; i++) {
		portitem = pinport[sorted[i]];
		str = sorted[i] " (" portitem ") ";
		desc=gensub("_", " ", "g", gensub(/\s+$/, "", 1, port[portitem]));			
		if (portitem in port) {
			str = str desc;
		}
		if (portitem in portevt) {
			str = str portevt[portitem];
		}
		print str;
	}
	delete sorted;
	print "\nClocks";
	for (i in clock_ol) {
		key = clock_ol[i];
		print toupper(key) " " clocks[key];
	}
	n = asorti(mod, sorted);
	if (n > 0) {
		print "\nPeripherals";
		for (i=1; i <= n; i++) {
			periph = sorted[i];
			print periph ": " mod[periph];
		}
	}
	delete sorted;
	if (nvic_count > 1) {
		print "\nInterrupt Service Routines";
		for (i in nvic) {
			print nvic[i];
		}
	}
	if (length(gen) > 0) {
        print "\nEvent Generators";
        for (i in gen) {
        	$0 = gensub(/\s+$/, "", "g", gen[i]);
        	eicport = ($2 ~ /^EIC_EXTINT_/) ? ("(" $7 ")") : "";
        	switch ($4) {
      			case /both/: edge = "Both Edges"; break;
       			case /falling/: edge = "Falling Edge"; break;
       			case /rising/: edge = "Rising Edge"; break;
       			default: edge = ""; break;
        	}
        	if ($1 ~ /swgen/) {
        		print $2 ": Software Event"
        	} else {
        		print $1 ": " $2 eicport " " edge (($3 ~ /ASYNCHRONOUS/) ? (" Asynchronous") : (" Synchronous(" toupper($5) " " freq[tolower($5)] ")"));
        	}
        }
        print "\nEvent Users";
        for (i in evt) {
        	$0 = gensub(/\s+$/, "", "g", evt[i]);
        	print $1 ": " $2 (($2 ~ /^PORT_EV/) ? ("(" $3 " " $4 ")") : "");
        }
	  }
   }' ${cfg} ${tmp} > ${summary}

rm -f ${tmp}
if [[ -f "${errfile}" ]]; then
   rm -f "${errfile}"
   if [[ ${verbose} == 1 ]]; then
   	   echo "${summary} Summary Failed"
   fi
else
	if [[ ${verbose} == 1 ]]; then
   		echo "${summary} Generate Summary"
	fi
fi
