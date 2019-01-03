#defmacro sercom

	/* Clock SERCOM%unit% core with %toupper(ref_source)% (%frequency(ref_source)%) */
	gclk_write_PCHCTRL(SERCOM%unit%_GCLK_ID_CORE, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
	/* Clock SERCOM%unit% slow with %toupper(slow_source)% (%frequency(slow_source)%) */
	gclk_write_PCHCTRL(SERCOM%unit%_GCLK_ID_SLOW, GCLK_PCHCTRL_GEN_%toupper(slow_source)% | GCLK_PCHCTRL_CHEN);
	// enable APB Clock SERCOM%unit%
	mclk_set_%apbmask%(%apb%);
#iftrue type == "uart"

#mod SERCOM%unit% UART (%toupper(ref_source)% %frequency(ref_source)%) %baudrate% baud
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
#port %txd_port% UART TXD (SERCOM%unit%/PAD%unitof(txd_pad)%) 
#fi
#ifdefined rxd
	port_set_pin_function(%rxd%, MUX_%rxd_port%%rxd_mux%_%rxd_pad%);
#port %rxd_port% UART RXD (SERCOM%unit%/PAD%unitof(rxd_pad)%)
#fi
#ifdefined rts
	port_set_pin_function(%rts%, MUX_%rts_port%%rts_mux%_%rts_pad%);
#port %rts_port% UART RTS (SERCOM%unit%/PAD%unitof(rts_pad)%)
#fi
#ifdefined cts
	port_set_pin_function(%cts%, MUX_%cts_port%%cts_mux%_%cts_pad%);
#port %cts_port% UART CTS (SERCOM%unit%/PAD%unitof(cts_pad)%)
#fi
#ifdefined dre_interrupt
#nvic SERCOM%unit%_UART_DRE SERCOM%unit%_0_IRQn SERCOM%unit%_0_Handler %dre_priority%
#fi
#ifdefined txc_interrupt
#nvic SERCOM%unit%_UART_TXC SERCOM%unit%_1_IRQn SERCOM%unit%_1_Handler %txc_priority%
#fi
#ifdefined rxc_interrupt
#nvic SERCOM%unit%_UART_RXC SERCOM%unit%_2_IRQn SERCOM%unit%_2_Handler %rxc_priority%
#fi
#ifdefined err_interrupt
#nvic SERCOM%unit%_UART_ERR SERCOM%unit%_3_IRQn SERCOM%unit%_3_Handler %err_priority%
#fi
#fi
#iftrue type == "spim"

#mod SERCOM%unit% SPI Master (%toupper(ref_source)% %frequency(ref_source)%) %baudrate% baud
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
#port %mosi_port% SPI Master MOSI (SERCOM%unit%/PAD%unitof(mosi_pad)%)
#ifdefined miso
	port_set_pin_function(%miso%, MUX_%miso_port%%miso_mux%_%miso_pad%);
#port %miso_port% SPI Master MISO (SERCOM%unit%/PAD%unitof(miso_pad)%) 
#fi
	port_set_pin_function(%sck%, MUX_%sck_port%%sck_mux%_%sck_pad%);
#port %sck_port% SPI Master SCLK (SERCOM%unit%/PAD%unitof(sck_pad)%) 
#ifdefined ss
	port_set_pin_function(%ss%, MUX_%ss_port%%ss_mux%_%ss_pad%);
#port %ss_port% SPI Master CSn (SERCOM%unit%/PAD%unitof(ss_pad)%)
#fi
#ifdefined dre_interrupt
#nvic SERCOM%unit%_SPIM_DRE SERCOM%unit%_0_IRQn SERCOM%unit%_0_Handler %dre_priority%
#fi
#ifdefined txc_interrupt
#nvic SERCOM%unit%_SPIM_TXC SERCOM%unit%_1_IRQn SERCOM%unit%_1_Handler %txc_priority%
#fi
#ifdefined rxc_interrupt
#nvic SERCOM%unit%_SPIM_RXC SERCOM%unit%_2_IRQn SERCOM%unit%_2_Handler %rxc_priority%
#fi
#ifdefined err_interrupt
#nvic SERCOM%unit%_SPIM_ERR SERCOM%unit%_3_IRQn SERCOM%unit%_3_Handler %err_priority%
#fi
#fi
#iftrue type == "i2cm"

#mod SERCOM%unit% I2C Master (%toupper(ref_source)% %frequency(ref_source)%) %baudrate% baud
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
#port %sda_port% I2C Master SDA (SERCOM%unit%/PAD%unitof(sda_pad)%)
#port %scl_port% I2C Master SCL (SERCOM%unit%/PAD%unitof(scl_pad)%)

#ifdefined isr
#isr volatile i2cm_msg_t %messagename% = {
#isr 	.dev = SERCOM%unit%,
#isr 	.sda = %sda%,
#isr 	.scl = %scl%,
#isr 	.txbuf = NULL,
#isr 	.rxbuf = NULL,
#isr 	.txlen = 0,
#isr 	.rxlen = 0,
#isr 	.address = 0,
#isr 	.status = 0 };
#isr /* Interrupt Service Routine for SERCOM%unit% master on bus */
#isr void SERCOM%unit%_0_Handler(void)
#isr {
#isr 	uint16_t status;
#isr 	status = i2cm_read_STATUS(SERCOM%unit%);
#isr 	// bus error check
#isr 	if (status & (SERCOM_I2CM_STATUS_ARBLOST | SERCOM_I2CM_STATUS_BUSERR)) {
#isr 		%messagename%.status |= I2CM_FAIL;
#isr 		%messagename%.status &= ~I2CM_BUSY;
#isr 		i2cm_clear_INTFLAG(SERCOM%unit%, SERCOM_I2CM_INTFLAG_MB);
#isr 	// check for NACK from slave
#isr 	} else if (status & SERCOM_I2CM_STATUS_RXNACK) {
#isr 			%messagename%.status |= I2CM_NACK;
#isr 			%messagename%.status &= ~I2CM_BUSY;
#isr  			i2cm_wait_for_sync(SERCOM%unit%, SERCOM_I2CM_SYNCBUSY_SYSOP);
#isr 			i2cm_set_CMD(SERCOM%unit%, I2CM_CMD_STOP); // clears MB and issues stop
#isr 	// data write check
#isr 	} else if (%messagename%.txlen > 0) {
#isr  		i2cm_wait_for_sync(SERCOM%unit%, SERCOM_I2CM_SYNCBUSY_SYSOP);
#isr 		i2cm_write_DATA(SERCOM%unit%,*%messagename%.txbuf++);
#isr 		%messagename%.txlen--;
#isr 	// data read check
#isr 	} else {
#isr 		// data read check
#isr  		if (%messagename%.rxlen > 0) {
#isr  			// send ACK to slave while rxlen > 0
#isr  			i2cm_set_ACK(SERCOM%unit%);
#isr 			// force repeated start by sending address, clears MB int flag
#isr  			i2cm_wait_for_sync(SERCOM%unit%, SERCOM_I2CM_SYNCBUSY_SYSOP);
#isr 			i2cm_write_ADDR(SERCOM%unit%, SERCOM_I2CM_ADDR_ADDR((%messagename%.address << 1) | I2CM_RD));
#isr 		// data read complete, issue stop
#isr 		} else { 
#isr  			i2cm_wait_for_sync(SERCOM%unit%, SERCOM_I2CM_SYNCBUSY_SYSOP);
#isr  			i2cm_set_CMD(SERCOM%unit%, I2CM_CMD_STOP);
#isr 			%messagename%.status &= ~I2CM_BUSY;
#isr 		}
#isr 	}
#isr }
#isr /* Interrupt Service Routine for SERCOM%unit% slave on bus */
#isr void SERCOM%unit%_1_Handler(void)
#isr {
#isr    if (%messagename%.rxlen > 0) {
#isr 		%messagename%.rxlen--;
#isr        if (%messagename%.rxlen == 0) {
#isr 			// send NACK and STOP for final byte
#isr  			i2cm_wait_for_sync(SERCOM%unit%, SERCOM_I2CM_SYNCBUSY_SYSOP);
#isr  			i2cm_set_NACK(SERCOM%unit%);
#isr  			i2cm_set_CMD(SERCOM%unit%, I2CM_CMD_STOP);
#isr 			%messagename%.status &= ~I2CM_BUSY;
#isr 		}
#isr 		// read data
#isr 		*%messagename%.rxbuf++ = i2cm_read_DATA(SERCOM%unit%); // clears SB
#isr 	} 
#isr 	i2cm_clear_INTFLAG(SERCOM%unit%, SERCOM_I2CM_INTFLAG_SB);
#isr }
#isr /* Interrupt Service Routine for SERCOM%unit% error */
#isr void SERCOM%unit%_3_Handler(void)
#isr {
#isr 	%messagename%.status |=  I2CM_FAIL;
#isr 	%messagename%.status &= ~I2CM_BUSY;
#isr 	i2cm_clear_INTFLAG(SERCOM%unit%, SERCOM_I2CM_INTFLAG_ERROR);
#isr }
#fi
#ifdefined interrupt
#nvic SERCOM%unit%_I2CM_MB SERCOM%unit%_0_IRQn SERCOM%unit%_0_Handler %priority%
#nvic SERCOM%unit%_I2CM_SB SERCOM%unit%_1_IRQn SERCOM%unit%_1_Handler %priority%
#nvic SERCOM%unit%_I2CM_ERR SERCOM%unit%_3_IRQn SERCOM%unit%_3_Handler %priority%
#fi
#fi
#endmacro

#defmacro qspi

	/** QSPI Initialization **/
	mclk_set_AHBMASK(MCLK_AHBMASK_QSPI);
	mclk_set_AHBMASK(MCLK_AHBMASK_QSPI_2X);
	mclk_set_%apbmask%(%apb%);
	qspi_set_CTRLA(QSPI_CTRLA_SWRST); // Reset QSPI module
	qspi_write_CTRLB(<<<
#ifdefined mode
                 | QSPI_CTRLB_MODE_%toupper(mode)%
#fi
#ifdefined loopen
	             | QSPI_CTRLB_LOOPEN
#fi
#ifdefined wdrbt
	             | QSPI_CTRLB_WDRBT
#fi
#ifdefined smemreg
	             | QSPI_CTRLB_SMEMREG
#fi
#ifdefined csmode
				 | QSPI_CTRLB_CSMODE_%toupper(csmode)%
#fi
#ifdefined datalen
	             | QSPI_CTRLB_DATALEN_%datalen%BITS
#fi
#ifdefined dlybct
	             | QSPI_CTRLB_DLYBCT(%dlybct%)
#fi
#ifdefined dlycs
				 | QSPI_CTRLB_DLYCS(%dlycs%)
#fi
>>>);
	qspi_write_BAUD(<<<
#ifdefined cpol
				 | QSPI_BAUD_CPOL
#fi
#ifdefined cpha
				 | QSPI_BAUD_CPHA
#fi
				 | QSPI_BAUD_BAUD(QSPI_BAUD(QSPI_BAUDRATE, CPU_FREQUENCY))
#ifdefined dlybs
				 | QSPI_BAUD_DLYBS(%dlybs%)
#fi
>>>);
	qspi_set_CTRLA(QSPI_CTRLA_ENABLE);
	port_set_pin_function(%data0%, MUX_%data0_port%%data0_mux%_%data0_pad%);
#port %data0_port% QSPI Data 0 (MOSI)
	port_set_pin_function(%data1%, MUX_%data1_port%%data1_mux%_%data1_pad%);
#port %data1_port% QSPI Data 1 (MISO)
#ifdefined data2
	port_set_pin_function(%data2%, MUX_%data2_port%%data2_mux%_%data2_pad%);
#port %data2_port% QSPI Data 2
#fi
#ifdefined data3
	port_set_pin_function(%data3%, MUX_%data3_port%%data3_mux%_%data3_pad%);
#port %data3_port% QSPI Data 3
#fi
	port_set_pin_function(%sck%, MUX_%sck_port%%sck_mux%_%sck_pad%);
#port %sck_port% QSPI Clock
	port_set_pin_function(%cs%, MUX_%cs_port%%cs_mux%_%cs_pad%);
#port %sck_port% QSPI Chip Select
#mod QSPI QSPI %frequency(baudrate)% baud (%baud%)
#ifdefined interrupt
#nvic QSPI QSPI_IRQn QSPI_Handler %priority%
#fi	             
#endmacro