function wordtranslate(fromlist, tolist, x, def)
{
	split(fromlist, a, " ");
	split(tolist, b, " ");
	xl = tolower(x);
	for(wordindex in a) {
		if (xl ~ a[wordindex]) return b[wordindex];
	}
	return def;
}

function unitof(refdes) 
{
	match(refdes, /([0-9]+)$/, az);
	azv = int(az[1]);
	delete az;
	return azv;
}

function designatorof(refdes)
{
	match(refdes, /([a-zA-Z0-9_]*[a-zA-Z])([0-9]+)$/, az);
	azv = toupper(az[1]);
	delete az;
	return azv;
}

function dofunction(text)
{
      fun = "nf";
      if (match(text,/([a-z0-9_]+)\(([a-z0-9_]+)\)/, f)) {
      	fun = f[1];
      	txtsub = f[2];
      } 
      delete f;
      key = instance ":" txtsub;
      value = "Unknown";
      if (key in prop) {
      	value = prop[key];
      	if (fun !~ /nf/) {
      		switch (fun) {
      			case /frequency/: 
      				if (value ~ /gclk[0-9]{1,2}/) {
      					key = "freq:" value;
      					if (key in prop) {
      						value = prop[key];
      					} else {
      						errprint(value " not defined but used" );
      						break;
      					}
      				}
      				if (value >= 1000000) {
      					value = (value/1000000.0) "MHz"; 
      				} else if (value >= 1000) {
      					value = (value/1000.0) "KHz";
      				} else {
      					value = value "Hz";
      				}
      			break;
      			case /groupof/: value = match(value, /P([a-eA-E])([0-9]+)/, az); value = az[1]; delete az; ; break;
      			case /unitof/: value = unitof(value); break;
      			case /designatorof/:  value = designatorof(value); break;
      			case /toupper/: value = toupper(value); break;
      			case /toodd/: value = or(value,1); break;
      			case /toeven/: value = and(value, compl(1)); break;
				default: break;
			}
		}
	}
    return value;
}

 function muxcnv(x) 
{
     return substr("ABCDEFGHIJKLMN", x+1, 1);
}
function bitcount(x)
{				
    bit_count=0;
	for (bitcount_index = 0; bitcount_index < 32; bitcount_index++) {
		if (and(x, lshift(1,bitcount_index))) bit_count++;
	}
	return bit_count;
}

function findDeviceIndex(dev)
{
	for (i in working_devices) {
		if (working_devices[i] ~ dev) return i;
	}
	return -1;
}

function evaldefined(inst, expression) {
  	params = gensub(/[\r\n]/, "", "g", expression);
  	key = inst ":" params;
  	return (key in prop);
}

function evalexp(inst, expression)
{
  	params = gensub(/\&/, " \\& ", "g", expression);
    params = gensub(/\|/, " | ", "g", params);
    params = gensub(/\=\=/, " = ", "g", params);
    params = gensub(/\!/, " ! ", "g", params);
    params = gensub(/\(/, " ( ", "g", params);
    params = gensub(/\)/, " ) ", "g", params);
  	params = gensub(/\s+/, " ", "g", params);
  	params = tolower(params);
  	split(params, args, " ");
  	for (k in args) {
  		if (args[k] ~ /\"[^\"]*\"/) {
  			args[k] = gensub(/\"/, "", "g", args[k]);
  		} else if (args[k] ~ /[a-z][a-z0-9_]*/) {
  			key = inst ":" args[k];
  			if (key in prop) {
  				args[k] = prop[key];
  			} else {
  				args[k] = 0;
  			}
		} 
  	}
    esp = 0;
    qp = 0;
    idx = 1;
    while(idx <= length(args)) {
        if (args[idx] ~ /[\!\(]/) {
            estack[esp++] = args[idx++];
    	} else if (args[idx] ~ /[\&\|\=]/) {
    		while((esp > 0) && (estack[esp-1] ~ /\!/)) {
        		queue[qp++] = estack[--esp];
    	}
    	estack[esp++] = args[idx++];
    	} else if (args[idx] ~ /\)/) {
        	while((esp > 0) && (estack[esp-1] !~ /\(/)) {
            	queue[qp++] = estack[--esp];
            }
      		if ((esp == 0) && (estack[esp-1] !~ /\(/)) {
      	   		print "Expression error on line " FNF | "cat 1>&2";
      	  		 break;
      		}
      		esp--;
            idx++;
    	} else {
    		queue[qp++] = args[idx++];
  		}
    }
    while (esp > 0) {
    	queue[qp++] = estack[--esp];
    }
    for (idx = 0; idx < length(queue); idx++) {
	switch (queue[idx]) {
		case /\&/: estack[esp-2] = and(estack[esp-1], estack[esp-2]); esp--; break;
		case /\|/: estack[esp-2] = or(estack[esp-1], estack[esp-2]); esp--; break;
		case /\=/: estack[esp-2] = (tolower(estack[esp-1]) == tolower(estack[esp-2])); esp--; break;
		case /\!/: estack[esp-1] = !estack[esp-1]; break;
		default: estack[esp++] = queue[idx]; break;
	}
    }
    rv = estack[--esp];
    delete estack;
    delete queue;
    if (rv !~ /^[0-9+\-\+]+$/) {
    	rv = ((rv == "") ? 0 : 1);
    }
    return rv;
}

function findproperties(search, prop) 
{
	str = "";
	for (key in prop) {
		if (key ~ search) {
			str = ((length(str) == 0) ? key : (str " " key));
		}
	}
	return str;
}

function errprint(string)
{	
	print "ERROR: " string " File: " gensub(/.*\//,"", 1, script) | "cat 1>&2";
}