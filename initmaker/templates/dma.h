#defmacro dma
#iftrue (gen_source == "beat") || (gen_source == "block")
#define DMA_CH%unit%_EVOSEL DMAC_BTCTRL_EVOSEL_%toupper(gen_source)%
#otherwise
#define DMA_CH%unit%_EVOSEL DMAC_BTCTRL_EVOSEL_DISABLE
#fi
#ifdefined name
#define %toupper(name)% CHANNEL%unit%
#fi
#ifdefined handler
#iftrue (unit == 0) || (unit == 1) || (unit == 2) || (unit == 3)
#define %toupper(handler)% DMAC_%unit%_Handler
#otherwise
/** @Note: DMA Channels >= 4 share the same handler. If it is aliased, make sure the handler is defined once **/
#define %toupper(handler)% DMAC_4_Handler
#fi
#fi
#endmacro