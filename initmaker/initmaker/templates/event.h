#defmacro evsys
#ifdefined generators
#foreach generators
#define %eventname% EVSYS_CHANNEL%channel%
#endfor
#fi
#ifdefined swgenerators
#foreach swgenerators
#define %eventname% EVSYS_CHANNEL%channel%
#endfor
#fi
#endmacro