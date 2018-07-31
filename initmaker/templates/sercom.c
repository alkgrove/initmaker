#defmacro sercom

	/* Clock SERCOM%unit% core with %toupper(ref_source)% (%frequency(ref_source)%) */
	gclk_write_PCHCTRL(SERCOM%unit%_GCLK_ID_CORE, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
	/* Clock SERCOM%unit% slow with %toupper(slow_source)% (%frequency(slow_source)%) */
	gclk_write_PCHCTRL(SERCOM%unit%_GCLK_ID_SLOW, GCLK_PCHCTRL_GEN_%toupper(slow_source)% | GCLK_PCHCTRL_CHEN);
	// enable APB Clock SERCOM%unit%
	mclk_set_%apb%MASK(MCLK_%apb%MASK_SERCOM%unit%);
#iftrue type == "uart"

	// Initialize SERCOM%unit% as UART
	usart_clear_ENABLE(SERCOM%unit%);
	usart_wait_for_sync(SERCOM%unit%, SERCOM_USART_SYNCBUSY_ENABLE);
	/* UART with internal clock 
     <<<
#ifdefined rxinv
     * Receive is inverted
#fi
#ifdefined txinv
     * Transmit is inverted
#fi
#ifdefined ibon
	 * BUFOVF is set immediately on overflow
#fi
#iftrue dord
	 * LSB clocked out first
#otherwise
	 * MSB clocked out first
#fi
>>>
     */
	usart_write_CTRLA(SERCOM%unit%, <<<
							 | SERCOM_USART_CTRLA_MODE(SERCOM_MODE_USART_INTCLK)
							 | SERCOM_USART_CTRLA_SAMPR(%sampr%)
							 | SERCOM_USART_CTRLA_SAMPA(%sampa%)
							 | SERCOM_USART_CTRLA_TXPO(%txpo%)
							 | SERCOM_USART_CTRLA_RXPO(%rxpo%)
							 | SERCOM_USART_CTRLA_FORM(%form%)
#ifdefined rxinv
							 | SERCOM_USART_CTRLA_RXINV
#fi
#ifdefined txinv
							 | SERCOM_USART_CTRLA_TXINV
#fi
#ifdefined ibon
							 | SERCOM_USART_CTRLA_IBON
#fi
#ifdefined runstdby
							 | SERCOM_USART_CTRLA_RUNSTDBY
#fi
#ifdefined dord
							 | SERCOM_USART_CTRLA_DORD
#fi
>>>); 
	usart_write_CTRLB(SERCOM%unit%, <<<
						     | SERCOM_USART_CTRLB_CHSIZE(%charsize%) /* %chsize% bit character */
#ifdefined txd
							 | SERCOM_USART_CTRLB_TXEN
#fi
#ifdefined rxd
							 | SERCOM_USART_CTRLB_RXEN
#fi
							 | SERCOM_USART_CTRLB_LINCMD(0)
>>>);
	usart_wait_for_sync(SERCOM%unit%, SERCOM_USART_SYNCBUSY_CTRLB);
	
	usart_write_CTRLC(SERCOM%unit%, 0);
	usart_write_BAUD(SERCOM%unit%, USART_BAUDRATE(SERCOM%unit%_BAUD, SERCOM%unit%_CORE_FREQ));
	usart_set_ENABLE(SERCOM%unit%);
	usart_wait_for_sync(SERCOM%unit%, SERCOM_USART_SYNCBUSY_ENABLE);
	
#ifdefined txd
	port_set_pin_function(%txd%, MUX_%txd_port%%txd_mux%_%txd_pad%);
#fi
#ifdefined rxd
	port_set_pin_function(%rxd%, MUX_%rxd_port%%rxd_mux%_%rxd_pad%);
#fi
#ifdefined rts
	port_set_pin_function(%rts%, MUX_%rts_port%%rts_mux%_%rts_pad%);
#fi
#ifdefined cts
	port_set_pin_function(%cts%, MUX_%cts_port%%cts_mux%_%cts_pad%);
#fi
#ifdefined dre_irq
#isr SERCOM%unit%_UART_DRE SERCOM%unit%_0_IRQn SERCOM%unit%_0_Handler
#fi
#ifdefined txc_irq
#isr SERCOM%unit%_UART_TXC SERCOM%unit%_1_IRQn SERCOM%unit%_1_Handler
#fi
#ifdefined rxc_irq
#isr SERCOM%unit%_UART_RXC SERCOM%unit%_2_IRQn SERCOM%unit%_2_Handler
#fi
#ifdefined err_irq
#isr SERCOM%unit%_UART_ERR SERCOM%unit%_3_IRQn SERCOM%unit%_3_Handler
#fi
#fi
#iftrue type == "spim"

	// Initialize SERCOM%unit% as SPI Master
	spi_wait_for_sync(SERCOM%unit%, SERCOM_SPI_SYNCBUSY_SWRST | SERCOM_SPI_SYNCBUSY_ENABLE);
	spi_set_SWRST(SERCOM%unit%);
	spi_wait_for_sync(SERCOM%unit%, SERCOM_SPI_SYNCBUSY_SWRST);
	/* <<<
#iftrue cpol
 	 clock is high when idle
#otherwise
     clock is low when idle
#fi
#iftrue cpha
	 * sample rising edge, change falling edge
#otherwise
	 * sample falling edge, change rising edge
#fi
#iftrue dord
	 * LSB clocked out first
#otherwise
	 * MSB clocked out first
#fi
>>>
     */
	spi_write_CTRLA(SERCOM%unit%, SERCOM_SPI_CTRLA_MODE(SERCOM_MODE_SPI_MASTER)
#iftrue cpol
						   | SERCOM_SPI_CTRLA_CPOL
#fi
#iftrue cpha
						   | SERCOM_SPI_CTRLA_CPHA
#fi
#ifdefined ibon
						   | SERCOM_SPI_CTRLA_IBON
#fi
#iftrue dord
						   | SERCOM_SPI_CTRLA_DORD 
#fi
#iftrue runstdby
						   | SERCOM_SPI_CTRLA_RUNSTDBY
#fi
						   | SERCOM_SPI_CTRLA_DOPO(%dopo%)
						   | SERCOM_SPI_CTRLA_DIPO(%dipo%)
						   | SERCOM_SPI_CTRLA_FORM(%form%));
	spi_write_CTRLB(SERCOM%unit%,<<<
#ifdefined miso
					       | SERCOM_SPI_CTRLB_RXEN
#fi
	                       | SERCOM_SPI_CTRLB_CHSIZE(%charsize%)
#ifdefined ss
                           | SERCOM_SPI_CTRLB_MSSEN
#fi
>>>);
#ifdefined len
	// 32 bit mode
	spi_write_CTRLC(SERCOM%unit%, SERCOM_SPI_CTRLC_DATA32B
				           | SERCOM_SPI_CTRLC_ICSPACE(%icspace%));
	// Set initial length to %len% bytes
	spi_write_LENGTH(SERCOM%unit%, SERCOM_SPI_LENGTH_LEN(%len%)
	                        | SERCOM_SPI_LENGTH_LENEN);

	spi_wait_for_sync(SERCOM%unit%, SERCOM_SPI_SYNCBUSY_LENGTH);
#fi
	// Write baudrate
	spi_write_BAUD(SERCOM%unit%, SPI_BAUD(SERCOM%unit%_BAUD, SERCOM%unit%_CORE_FREQ));
	spi_wait_for_sync(SERCOM%unit%, SERCOM_SPI_SYNCBUSY_ENABLE);
	spi_set_ENABLE(SERCOM%unit%);

	port_set_pin_function(%mosi%, MUX_%mosi_port%%mosi_mux%_%mosi_pad%);
#ifdefined miso
	port_set_pin_function(%miso%, MUX_%miso_port%%miso_mux%_%miso_pad%);
#fi
	port_set_pin_function(%sck%, MUX_%sck_port%%sck_mux%_%sck_pad%);
#ifdefined ss
	port_set_pin_function(%ss%, MUX_%ss_port%%ss_mux%_%ss_pad%);
#fi
#ifdefined dre_irq
#isr SERCOM%unit%_SPIM_DRE SERCOM%unit%_0_IRQn SERCOM%unit%_0_Handler
#fi
#ifdefined txc_irq
#isr SERCOM%unit%_SPIM_TXC SERCOM%unit%_1_IRQn SERCOM%unit%_1_Handler
#fi
#ifdefined rxc_irq
#isr SERCOM%unit%_SPIM_RXC SERCOM%unit%_2_IRQn SERCOM%unit%_2_Handler
#fi
#ifdefined err_irq
#isr SERCOM%unit%_SPIM_ERR SERCOM%unit%_3_IRQn SERCOM%unit%_3_Handler
#fi
#fi
#iftrue type == "i2cm"

	// initialize SERCOM2 as I2C
	i2cm_wait_for_sync(SERCOM%unit%, SERCOM_I2CM_SYNCBUSY_SWRST);
	i2cm_set_SWRST(SERCOM%unit%);
	i2cm_wait_for_sync(SERCOM%unit%, SERCOM_I2CM_SYNCBUSY_SWRST);
	i2cm_write_CTRLA(SERCOM%unit%, SERCOM_I2CM_CTRLA_SDAHOLD(2)
							| SERCOM_I2CM_CTRLA_SPEED(0)
							| SERCOM_I2CM_CTRLA_MODE(SERCOM_MODE_I2C_MASTER));
	i2cm_write_CTRLB(SERCOM%unit%, SERCOM_I2CM_CTRLB_SMEN); 
	i2cm_write_BAUD(SERCOM%unit%, SERCOM%unit%_BAUD);

	port_set_pin_function(%sda%, MUX_%sda_port%%sda_mux%_%sda_pad%);
	port_set_pin_function(%scl%, MUX_%scl_port%%scl_mux%_%scl_pad%);
#ifdefined mb_irq
#isr SERCOM%unit%_I2CM_MB SERCOM%unit%_0_IRQn SERCOM%unit%_0_Handler
#fi
#ifdefined sb_irq
#isr SERCOM%unit%_I2CM_SB SERCOM%unit%_1_IRQn SERCOM%unit%_1_Handler
#fi
#ifdefined err_irq
#isr SERCOM%unit%_I2CM_ERR SERCOM%unit%_3_IRQn SERCOM%unit%_3_Handler
#fi
#fi
#endmacro