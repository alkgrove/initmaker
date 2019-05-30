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
#define %toupper(handler)% DMA%unit%_Handler
#fi
#endmacro