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

function tofreq(frequency)
{
	frq = int(frequency) + 0.0;
      	if (frq >= 1000000) {
      		return (frq/1000000.0) "MHz"; 
      	} else if (frq >= 1000) {
      		return (frq/1000.0) "KHz";
      	}
      	return frequency "Hz";
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
				value = tofreq(value);
      			break;
      			case /groupof/: value = match(value, /P([a-eA-E])([0-9]+)/, az); value = az[1]; delete az; ; break;
      			case /unitof/: value = unitof(value); break;
      			case /designatorof/:  value = designatorof(value); break;
      			case /toupper/: value = toupper(value); break;
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
  	params = gensub(/&/, " \\& ", "g", expression);
    params = gensub(/\|/, " | ", "g", params);
    params = gensub(/==/, " = ", "g", params);
    params = gensub(/!/, " ! ", "g", params);
    params = gensub(/\(/, " ( ", "g", params);
    params = gensub(/\)/, " ) ", "g", params);
  	params = gensub(/\s+/, " ", "g", params);
  	params = tolower(params);
  	split(params, args, " ");
  	for (k in args) {
  		if (args[k] ~ /"[^"]*"/) {
  			args[k] = gensub(/"/, "", "g", args[k]);
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
        if (args[idx] ~ /[!\(]/) {
            estack[esp++] = args[idx++];
    	} else if (args[idx] ~ /[&\|=]/) {
    		while((esp > 0) && (estack[esp-1] ~ /!/)) {
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
		case /&/: estack[esp-2] = and(estack[esp-1], estack[esp-2]); esp--; break;
		case /\|/: estack[esp-2] = or(estack[esp-1], estack[esp-2]); esp--; break;
		case /=/: estack[esp-2] = (tolower(estack[esp-1]) == tolower(estack[esp-2])); esp--; break;
		case /!/: estack[esp-1] = !estack[esp-1]; break;
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

function initmclk()
{
   mclk["hpb0"]="MCLK_AHBMASK_HPB0";
   mclk["hpb1"]="MCLK_AHBMASK_HPB1";
   mclk["hpb2"]="MCLK_AHBMASK_HPB2";
   mclk["hpb3"]="MCLK_AHBMASK_HPB3";
   mclk["dsu"]="MCLK_AHBMASK_DSU";
   mclk["hmatrix"]="MCLK_AHBMASK_HMATRIX";
   mclk["nvmctrl"]="MCLK_AHBMASK_NVMCTRL";
   mclk["hsram"]="MCLK_AHBMASK_HSRAM";
   mclk["cmcc"]="MCLK_AHBMASK_CMCC";
   mclk["dmac"]="MCLK_AHBMASK_DMAC";
   mclk["usb"]="MCLK_AHBMASK_USB";
   mclk["bkupram"]="MCLK_AHBMASK_BKUPRAM";
   mclk["pac"]="MCLK_AHBMASK_PAC";
   mclk["qspi"]="MCLK_AHBMASK_QSPI";
   mclk["sdhc0"]="MCLK_AHBMASK_SDHC0";
   mclk["sdhc1"]="MCLK_AHBMASK_SDHC1";
   mclk["icm"]="MCLK_AHBMASK_ICM";
   mclk["pukcc"]="MCLK_AHBMASK_PUKCC";
   mclk["qspi_2x"]="MCLK_AHBMASK_QSPI_2X";
   mclk["nvmctrl_smeeprom"]="MCLK_AHBMASK_NVMCTRL_SMEEPROM";
   mclk["nvmctrl_cache"]="MCLK_AHBMASK_NVMCTRL_CACHE";
   mclk["pac"]="MCLK_APBAMASK_PAC";
   mclk["pm"]="MCLK_APBAMASK_PM";
   mclk["mclk"]="MCLK_APBAMASK_MCLK";
   mclk["rstc"]="MCLK_APBAMASK_RSTC";
   mclk["oscctrl"]="MCLK_APBAMASK_OSCCTRL";
   mclk["osc32kctrl"]="MCLK_APBAMASK_OSC32KCTRL";
   mclk["supc"]="MCLK_APBAMASK_SUPC";
   mclk["gclk"]="MCLK_APBAMASK_GCLK";
   mclk["wdt"]="MCLK_APBAMASK_WDT";
   mclk["rtc"]="MCLK_APBAMASK_RTC";
   mclk["eic"]="MCLK_APBAMASK_EIC";
   mclk["freqm"]="MCLK_APBAMASK_FREQM";
   mclk["sercom0"]="MCLK_APBAMASK_SERCOM0";
   mclk["sercom1"]="MCLK_APBAMASK_SERCOM1";
   mclk["tc0"]="MCLK_APBAMASK_TC0";
   mclk["tc1"]="MCLK_APBAMASK_TC1";
   mclk["usb"]="MCLK_APBBMASK_USB";
   mclk["dsu"]="MCLK_APBBMASK_DSU";
   mclk["nvmctrl"]="MCLK_APBBMASK_NVMCTRL";
   mclk["port"]="MCLK_APBBMASK_PORT";
   mclk["hmatrix"]="MCLK_APBBMASK_HMATRIX";
   mclk["evsys"]="MCLK_APBBMASK_EVSYS";
   mclk["sercom2"]="MCLK_APBBMASK_SERCOM2";
   mclk["sercom3"]="MCLK_APBBMASK_SERCOM3";
   mclk["tcc0"]="MCLK_APBBMASK_TCC0";
   mclk["tcc1"]="MCLK_APBBMASK_TCC1";
   mclk["tc2"]="MCLK_APBBMASK_TC2";
   mclk["tc3"]="MCLK_APBBMASK_TC3";
   mclk["tal"]="MCLK_APBBMASK_TAL";
   mclk["ramecc"]="MCLK_APBBMASK_RAMECC";
   mclk["tcc2"]="MCLK_APBCMASK_TCC2";
   mclk["tcc3"]="MCLK_APBCMASK_TCC3";
   mclk["tc4"]="MCLK_APBCMASK_TC4";
   mclk["tc5"]="MCLK_APBCMASK_TC5";
   mclk["pdec"]="MCLK_APBCMASK_PDEC";
   mclk["ac"]="MCLK_APBCMASK_AC";
   mclk["aes"]="MCLK_APBCMASK_AES";
   mclk["trng"]="MCLK_APBCMASK_TRNG";
   mclk["icm"]="MCLK_APBCMASK_ICM";
   mclk["qspi"]="MCLK_APBCMASK_QSPI";
   mclk["ccl"]="MCLK_APBCMASK_CCL";
   mclk["sercom4"]="MCLK_APBDMASK_SERCOM4";
   mclk["sercom5"]="MCLK_APBDMASK_SERCOM5";
   mclk["sercom6"]="MCLK_APBDMASK_SERCOM6";
   mclk["sercom7"]="MCLK_APBDMASK_SERCOM7";
   mclk["tcc4"]="MCLK_APBDMASK_TCC4";
   mclk["tc6"]="MCLK_APBDMASK_TC6";
   mclk["tc7"]="MCLK_APBDMASK_TC7";
   mclk["adc0"]="MCLK_APBDMASK_ADC0";
   mclk["adc1"]="MCLK_APBDMASK_ADC1";
   mclk["dac"]="MCLK_APBDMASK_DAC";
   mclk["i2s"]="MCLK_APBDMASK_I2S";
   mclk["pcc"]="MCLK_APBDMASK_PCC";
}

function warnprint(string)
{	
	print "Warning: " string " File: " gensub(/.*\//,"", 1, script) | "cat 1>&2";
}
function errprint(string)
{	
	print "ERROR: " string " File: " gensub(/.*\//,"", 1, script) | "cat 1>&2";
}

function checkfreq(instance, max_freq)
{
	keyclk = instance ":ref_source";
	if (keyclk in prop) {
		keyfreq = "freq:" prop[keyclk];
		if (keyfreq in prop) {
			value = int(prop[keyfreq]);
			if (value > int(max_freq)) {
				errprint(prop[keyclk] " (" tofreq(value) ") exceeds maximum " tofreq(max_freq));
			}
		}
	}
}
