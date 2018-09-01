function initpins()
{
   unitmax["adc1"] = 12;
   unitmax["sercom"] = 8;
   unitmax["gclk"] = 12;
   unitmax["ccl"] = 4;
   unitmax["gpio"] = 81;
   unitmax["ac"] = 4;
   unitmax["sdhc"] = 1;
   unitmax["pcc"] = 14;
   unitmax["dma"] = 32;
   unitmax["tc"] = 8;
   unitmax["dac"] = 2;
   unitmax["eic"] = 16;
   unitmax["dpll"] = 2;
   unitmax["tcc"] = 2;
   unitmax["adc0"] = 16;
   unitmax["adc"] = 2;

   pins["PA02:EIC"] = "0 EIC_EXTINT2";
   pins["PA03:EIC"] = "0 EIC_EXTINT3";
   pins["PB04:EIC"] = "0 EIC_EXTINT4";
   pins["PB05:EIC"] = "0 EIC_EXTINT5";
   pins["PB06:EIC"] = "0 EIC_EXTINT6";
   pins["PB07:EIC"] = "0 EIC_EXTINT7";
   pins["PB08:EIC"] = "0 EIC_EXTINT8";
   pins["PB09:EIC"] = "0 EIC_EXTINT9";
   pins["PA04:EIC"] = "0 EIC_EXTINT4";
   pins["PA05:EIC"] = "0 EIC_EXTINT5";
   pins["PA06:EIC"] = "0 EIC_EXTINT6";
   pins["PA07:EIC"] = "0 EIC_EXTINT7";
   pins["PA08:EIC"] = "0 EIC_NMI";
   pins["PA09:EIC"] = "0 EIC_EXTINT9";
   pins["PA10:EIC"] = "0 EIC_EXTINT10";
   pins["PA11:EIC"] = "0 EIC_EXTINT11";
   pins["PB10:EIC"] = "0 EIC_EXTINT10";
   pins["PB11:EIC"] = "0 EIC_EXTINT11";
   pins["PB12:EIC"] = "0 EIC_EXTINT12";
   pins["PB13:EIC"] = "0 EIC_EXTINT13";
   pins["PB14:EIC"] = "0 EIC_EXTINT14";
   pins["PB15:EIC"] = "0 EIC_EXTINT15";
   pins["PA12:EIC"] = "0 EIC_EXTINT12";
   pins["PA13:EIC"] = "0 EIC_EXTINT13";
   pins["PA14:EIC"] = "0 EIC_EXTINT14";
   pins["PA15:EIC"] = "0 EIC_EXTINT15";
   pins["PA16:EIC"] = "0 EIC_EXTINT0";
   pins["PA17:EIC"] = "0 EIC_EXTINT1";
   pins["PA18:EIC"] = "0 EIC_EXTINT2";
   pins["PA19:EIC"] = "0 EIC_EXTINT3";
   pins["PB16:EIC"] = "0 EIC_EXTINT0";
   pins["PB17:EIC"] = "0 EIC_EXTINT1";
   pins["PA20:EIC"] = "0 EIC_EXTINT4";
   pins["PA21:EIC"] = "0 EIC_EXTINT5";
   pins["PA22:EIC"] = "0 EIC_EXTINT6";
   pins["PA23:EIC"] = "0 EIC_EXTINT7";
   pins["PA24:EIC"] = "0 EIC_EXTINT8";
   pins["PA25:EIC"] = "0 EIC_EXTINT9";
   pins["PB22:EIC"] = "0 EIC_EXTINT6";
   pins["PB23:EIC"] = "0 EIC_EXTINT7";
   pins["PA27:EIC"] = "0 EIC_EXTINT11";
   pins["PA30:EIC"] = "0 EIC_EXTINT14";
   pins["PA31:EIC"] = "0 EIC_EXTINT15";
   pins["PB30:EIC"] = "0 EIC_EXTINT14";
   pins["PB31:EIC"] = "0 EIC_EXTINT15";
   pins["PB00:EIC"] = "0 EIC_EXTINT0";
   pins["PB01:EIC"] = "0 EIC_EXTINT1";
   pins["PB02:EIC"] = "0 EIC_EXTINT2";
   pins["PB03:EIC"] = "0 EIC_EXTINT3";
   pins["PA03:VREF"] = "1 ANAREF_VREF2";
   pins["PA04:VREF"] = "1 ANAREF_VREF2";
   pins["PA06:VREF"] = "1 ANAREF_VREF2";
   pins["PA02:ADC0"] = "1 ADC0_AIN0";
   pins["PA03:ADC0"] = "1 ADC0_AIN1";
   pins["PB08:ADC0"] = "1 ADC0_AIN2";
   pins["PB09:ADC0"] = "1 ADC0_AIN3";
   pins["PA04:ADC0"] = "1 ADC0_AIN4";
   pins["PA05:ADC0"] = "1 ADC0_AIN5";
   pins["PA06:ADC0"] = "1 ADC0_AIN6";
   pins["PA07:ADC0"] = "1 ADC0_AIN7";
   pins["PA08:ADC0"] = "1 ADC0_AIN8";
   pins["PA09:ADC0"] = "1 ADC0_AIN9";
   pins["PA10:ADC0"] = "1 ADC0_AIN10";
   pins["PA11:ADC0"] = "1 ADC0_AIN11";
   pins["PB00:ADC0"] = "1 ADC0_AIN12";
   pins["PB01:ADC0"] = "1 ADC0_AIN13";
   pins["PB02:ADC0"] = "1 ADC0_AIN14";
   pins["PB03:ADC0"] = "1 ADC0_AIN15";
   pins["PB04:ADC1"] = "1 ADC1_AIN6";
   pins["PB05:ADC1"] = "1 ADC1_AIN7";
   pins["PB06:ADC1"] = "1 ADC1_AIN8";
   pins["PB07:ADC1"] = "1 ADC1_AIN9";
   pins["PB08:ADC1"] = "1 ADC1_AIN0";
   pins["PB09:ADC1"] = "1 ADC1_AIN1";
   pins["PA08:ADC1"] = "1 ADC1_AIN2";
   pins["PA09:ADC1"] = "1 ADC1_AIN3";
   pins["PA04:AC"] = "1 AC_AIN0";
   pins["PA05:AC"] = "1 AC_AIN1";
   pins["PA06:AC"] = "1 AC_AIN2";
   pins["PA07:AC"] = "1 AC_AIN3";
   pins["PA02:DAC"] = "1 DAC_VOUT0";
   pins["PA05:DAC"] = "1 DAC_VOUT1";
   pins["PA03:PTC"] = "1 ADC0_PTCX0Y0";
   pins["PB04:PTC"] = "1 ADC0_PTCX22Y22";
   pins["PB05:PTC"] = "1 ADC0_PTCX23Y23";
   pins["PB06:PTC"] = "1 ADC0_PTCX24Y24";
   pins["PB07:PTC"] = "1 ADC0_PTCX25Y25";
   pins["PB08:PTC"] = "1 ADC0_PTCX1Y1";
   pins["PB09:PTC"] = "1 ADC0_PTCX2Y2";
   pins["PA04:PTC"] = "1 ADC0_PTCX3Y3";
   pins["PA06:PTC"] = "1 ADC0_PTCX4Y4";
   pins["PA07:PTC"] = "1 ADC0_PTCX5Y5";
   pins["PA08:PTC"] = "1 ADC0_PTCX6Y6";
   pins["PA09:PTC"] = "1 ADC0_PTCX7Y7";
   pins["PA10:PTC"] = "1 ADC0_PTCX8Y8";
   pins["PA11:PTC"] = "1 ADC0_PTCX9Y9";
   pins["PB12:PTC"] = "1 ADC0_PTCX26Y26";
   pins["PB13:PTC"] = "1 ADC0_PTCX27Y27";
   pins["PB14:PTC"] = "1 ADC0_PTCX28Y28";
   pins["PB15:PTC"] = "1 ADC0_PTCX29Y29";
   pins["PA16:PTC"] = "1 ADC0_PTCX10Y10";
   pins["PA17:PTC"] = "1 ADC0_PTCX11Y11";
   pins["PA18:PTC"] = "1 ADC0_PTCX12Y12";
   pins["PA19:PTC"] = "1 ADC0_PTCX13Y13";
   pins["PA20:PTC"] = "1 ADC0_PTCX14Y14";
   pins["PA21:PTC"] = "1 ADC0_PTCX15Y15";
   pins["PA22:PTC"] = "1 ADC0_PTCX16Y16";
   pins["PA23:PTC"] = "1 ADC0_PTCX17Y17";
   pins["PA27:PTC"] = "1 ADC0_PTCX18Y18";
   pins["PA30:PTC"] = "1 ADC0_PTCX19Y19";
   pins["PB00:PTC"] = "1 ADC0_PTCX30Y30";
   pins["PB01:PTC"] = "1 ADC0_PTCX31Y31";
   pins["PB02:PTC"] = "1 ADC0_PTCX20Y20";
   pins["PB03:PTC"] = "1 ADC0_PTCX21Y21";
   pins["PA08:SERCOM0"] = "2 SERCOM0_PAD0";
   pins["PA09:SERCOM0"] = "2 SERCOM0_PAD1";
   pins["PA10:SERCOM0"] = "2 SERCOM0_PAD2";
   pins["PA11:SERCOM0"] = "2 SERCOM0_PAD3";
   pins["PB12:SERCOM4"] = "2 SERCOM4_PAD0";
   pins["PB13:SERCOM4"] = "2 SERCOM4_PAD1";
   pins["PB14:SERCOM4"] = "2 SERCOM4_PAD2";
   pins["PB15:SERCOM4"] = "2 SERCOM4_PAD3";
   pins["PA12:SERCOM2"] = "2 SERCOM2_PAD0";
   pins["PA13:SERCOM2"] = "2 SERCOM2_PAD1";
   pins["PA14:SERCOM2"] = "2 SERCOM2_PAD2";
   pins["PA15:SERCOM2"] = "2 SERCOM2_PAD3";
   pins["PA16:SERCOM1"] = "2 SERCOM1_PAD0";
   pins["PA17:SERCOM1"] = "2 SERCOM1_PAD1";
   pins["PA18:SERCOM1"] = "2 SERCOM1_PAD2";
   pins["PA19:SERCOM1"] = "2 SERCOM1_PAD3";
   pins["PB16:SERCOM5"] = "2 SERCOM5_PAD0";
   pins["PB17:SERCOM5"] = "2 SERCOM5_PAD1";
   pins["PA20:SERCOM5"] = "2 SERCOM5_PAD2";
   pins["PA21:SERCOM5"] = "2 SERCOM5_PAD3";
   pins["PA22:SERCOM3"] = "2 SERCOM3_PAD0";
   pins["PA23:SERCOM3"] = "2 SERCOM3_PAD1";
   pins["PA24:SERCOM3"] = "2 SERCOM3_PAD2";
   pins["PA25:SERCOM3"] = "2 SERCOM3_PAD3";
   pins["PB22:SERCOM1"] = "2 SERCOM1_PAD2";
   pins["PB23:SERCOM1"] = "2 SERCOM1_PAD3";
   pins["PA30:SERCOM7"] = "2 SERCOM7_PAD2";
   pins["PA31:SERCOM7"] = "2 SERCOM7_PAD3";
   pins["PB30:SERCOM7"] = "2 SERCOM7_PAD0";
   pins["PB31:SERCOM7"] = "2 SERCOM7_PAD1";
   pins["PB08:SERCOM4"] = "3 SERCOM4_PAD0";
   pins["PB09:SERCOM4"] = "3 SERCOM4_PAD1";
   pins["PA04:SERCOM0"] = "3 SERCOM0_PAD0";
   pins["PA05:SERCOM0"] = "3 SERCOM0_PAD1";
   pins["PA06:SERCOM0"] = "3 SERCOM0_PAD2";
   pins["PA07:SERCOM0"] = "3 SERCOM0_PAD3";
   pins["PA08:SERCOM2"] = "3 SERCOM2_PAD1";
   pins["PA09:SERCOM2"] = "3 SERCOM2_PAD0";
   pins["PA10:SERCOM2"] = "3 SERCOM2_PAD2";
   pins["PA11:SERCOM2"] = "3 SERCOM2_PAD3";
   pins["PB10:SERCOM4"] = "3 SERCOM4_PAD2";
   pins["PB11:SERCOM4"] = "3 SERCOM4_PAD3";
   pins["PA12:SERCOM4"] = "3 SERCOM4_PAD1";
   pins["PA13:SERCOM4"] = "3 SERCOM4_PAD0";
   pins["PA14:SERCOM4"] = "3 SERCOM4_PAD2";
   pins["PA15:SERCOM4"] = "3 SERCOM4_PAD3";
   pins["PA16:SERCOM3"] = "3 SERCOM3_PAD1";
   pins["PA17:SERCOM3"] = "3 SERCOM3_PAD0";
   pins["PA18:SERCOM3"] = "3 SERCOM3_PAD2";
   pins["PA19:SERCOM3"] = "3 SERCOM3_PAD3";
   pins["PA20:SERCOM3"] = "3 SERCOM3_PAD2";
   pins["PA21:SERCOM3"] = "3 SERCOM3_PAD3";
   pins["PA22:SERCOM5"] = "3 SERCOM5_PAD1";
   pins["PA23:SERCOM5"] = "3 SERCOM5_PAD0";
   pins["PA24:SERCOM5"] = "3 SERCOM5_PAD2";
   pins["PA25:SERCOM5"] = "3 SERCOM5_PAD3";
   pins["PB22:SERCOM5"] = "3 SERCOM5_PAD2";
   pins["PB23:SERCOM5"] = "3 SERCOM5_PAD3";
   pins["PA30:SERCOM1"] = "3 SERCOM1_PAD2";
   pins["PA31:SERCOM1"] = "3 SERCOM1_PAD3";
   pins["PB30:SERCOM5"] = "3 SERCOM5_PAD1";
   pins["PB31:SERCOM5"] = "3 SERCOM5_PAD0";
   pins["PB00:SERCOM5"] = "3 SERCOM5_PAD2";
   pins["PB01:SERCOM5"] = "3 SERCOM5_PAD3";
   pins["PB02:SERCOM5"] = "3 SERCOM5_PAD0";
   pins["PB03:SERCOM5"] = "3 SERCOM5_PAD1";
   pins["PB08:TC4"] = "4 TC4_WO0";
   pins["PB09:TC4"] = "4 TC4_WO1";
   pins["PA04:TC0"] = "4 TC0_WO0";
   pins["PA05:TC0"] = "4 TC0_WO1";
   pins["PA06:TC1"] = "4 TC1_WO0";
   pins["PA07:TC1"] = "4 TC1_WO1";
   pins["PA08:TC0"] = "4 TC0_WO0";
   pins["PA09:TC0"] = "4 TC0_WO1";
   pins["PA10:TC1"] = "4 TC1_WO0";
   pins["PA11:TC1"] = "4 TC1_WO1";
   pins["PB10:TC5"] = "4 TC5_WO0";
   pins["PB11:TC5"] = "4 TC5_WO1";
   pins["PB12:TC4"] = "4 TC4_WO0";
   pins["PB13:TC4"] = "4 TC4_WO1";
   pins["PB14:TC5"] = "4 TC5_WO0";
   pins["PB15:TC5"] = "4 TC5_WO1";
   pins["PA12:TC2"] = "4 TC2_WO0";
   pins["PA13:TC2"] = "4 TC2_WO1";
   pins["PA14:TC3"] = "4 TC3_WO0";
   pins["PA15:TC3"] = "4 TC3_WO1";
   pins["PA16:TC2"] = "4 TC2_WO0";
   pins["PA17:TC2"] = "4 TC2_WO1";
   pins["PA18:TC3"] = "4 TC3_WO0";
   pins["PA19:TC3"] = "4 TC3_WO1";
   pins["PB16:TC6"] = "4 TC6_WO0";
   pins["PB17:TC6"] = "4 TC6_WO1";
   pins["PA20:TC7"] = "4 TC7_WO0";
   pins["PA21:TC7"] = "4 TC7_WO1";
   pins["PA22:TC4"] = "4 TC4_WO0";
   pins["PA23:TC4"] = "4 TC4_WO1";
   pins["PA24:TC5"] = "4 TC5_WO0";
   pins["PA25:TC5"] = "4 TC5_WO1";
   pins["PB22:TC7"] = "4 TC7_WO0";
   pins["PB23:TC7"] = "4 TC7_WO1";
   pins["PA30:TC6"] = "4 TC6_WO0";
   pins["PA31:TC6"] = "4 TC6_WO1";
   pins["PB30:TC0"] = "4 TC0_WO0";
   pins["PB31:TC0"] = "4 TC0_WO1";
   pins["PB00:TC7"] = "4 TC7_WO0";
   pins["PB01:TC7"] = "4 TC7_WO1";
   pins["PB02:TC6"] = "4 TC6_WO0";
   pins["PB03:TC6"] = "4 TC6_WO0";
   pins["PA08:TCC0"] = "5 TCC0_WO0";
   pins["PA09:TCC0"] = "5 TCC0_WO1";
   pins["PA10:TCC0"] = "5 TCC0_WO2";
   pins["PA11:TCC0"] = "5 TCC0_WO3";
   pins["PB10:TCC0"] = "5 TCC0_WO4";
   pins["PB11:TCC0"] = "5 TCC0_WO5";
   pins["PB12:TCC3"] = "5 TCC3_WO0";
   pins["PB13:TCC3"] = "5 TCC3_WO1";
   pins["PB14:TCC4"] = "5 TCC4_WO0";
   pins["PB15:TCC4"] = "5 TCC4_WO1";
   pins["PA12:TCC0"] = "5 TCC0_WO6";
   pins["PA13:TCC0"] = "5 TCC0_WO7";
   pins["PA14:TCC2"] = "5 TCC2_WO0";
   pins["PA15:TCC2"] = "5 TCC2_WO1";
   pins["PA16:TCC1"] = "5 TCC1_WO0";
   pins["PA17:TCC1"] = "5 TCC1_WO1";
   pins["PA18:TCC1"] = "5 TCC1_WO2";
   pins["PA19:TCC1"] = "5 TCC1_WO3";
   pins["PB16:TCC3"] = "5 TCC3_WO0";
   pins["PB17:TCC3"] = "5 TCC3_WO1";
   pins["PA20:TCC1"] = "5 TCC1_WO4";
   pins["PA21:TCC1"] = "5 TCC1_WO5";
   pins["PA22:TCC1"] = "5 TCC1_WO6";
   pins["PA23:TCC1"] = "5 TCC1_WO7";
   pins["PA24:TCC2"] = "5 TCC2_WO2";
   pins["PA30:TCC2"] = "5 TCC2_WO0";
   pins["PA31:TCC2"] = "5 TCC2_WO1";
   pins["PB30:TCC4"] = "5 TCC4_WO0";
   pins["PB31:TCC4"] = "5 TCC4_WO1";
   pins["PB02:TCC2"] = "5 TCC2_WO2";
   pins["PA08:TCC1"] = "6 TCC1_WO4";
   pins["PA09:TCC1"] = "6 TCC1_WO5";
   pins["PA10:TCC1"] = "6 TCC1_WO6";
   pins["PA11:TCC1"] = "6 TCC1_WO7";
   pins["PB10:TCC1"] = "6 TCC1_WO0";
   pins["PB11:TCC1"] = "6 TCC1_WO1";
   pins["PB12:TCC0"] = "6 TCC0_WO0";
   pins["PB13:TCC0"] = "6 TCC0_WO1";
   pins["PB14:TCC0"] = "6 TCC0_WO2";
   pins["PB15:TCC0"] = "6 TCC0_WO3";
   pins["PA12:TCC1"] = "6 TCC1_WO2";
   pins["PA13:TCC1"] = "6 TCC1_WO3";
   pins["PA14:TCC1"] = "6 TCC1_WO2";
   pins["PA15:TCC1"] = "6 TCC1_WO3";
   pins["PA16:TCC0"] = "6 TCC0_WO4";
   pins["PA17:TCC0"] = "6 TCC0_WO5";
   pins["PA18:TCC0"] = "6 TCC0_WO6";
   pins["PA19:TCC0"] = "6 TCC0_WO7";
   pins["PB16:TCC0"] = "6 TCC0_WO4";
   pins["PB17:TCC0"] = "6 TCC0_WO5";
   pins["PA20:TCC0"] = "6 TCC0_WO0";
   pins["PA21:TCC0"] = "6 TCC0_WO1";
   pins["PA22:TCC0"] = "6 TCC0_WO2";
   pins["PA23:TCC0"] = "6 TCC0_WO3";
   pins["PB30:TCC0"] = "6 TCC0_WO6";
   pins["PB31:TCC0"] = "6 TCC0_WO7";
   pins["PA24:PDEC"] = "6 PDEC_QDI0";
   pins["PA25:PDEC"] = "6 PDEC_QDI1";
   pins["PB22:PDEC"] = "6 PDEC_QDI2";
   pins["PB23:PDEC"] = "6 PDEC_QDI0";
   pins["PA08:QSPI"] = "7 QSPI_DATA0";
   pins["PA09:QSPI"] = "7 QSPI_DATA1";
   pins["PA10:QSPI"] = "7 QSPI_DATA2";
   pins["PA11:QSPI"] = "7 QSPI_DATA3";
   pins["PB10:QSPI"] = "7 QSPI_SCK";
   pins["PB11:QSPI"] = "7 QSPI_CS";
   pins["PB12:CAN1"] = "7 CAN1_TX";
   pins["PB13:CAN1"] = "7 CAN1_RX";
   pins["PB14:CAN1"] = "7 CAN1_TX";
   pins["PB15:CAN1"] = "7 CAN1_RX";
   pins["PA23:USB"] = "7 USB_SOF_1KHZ";
   pins["PA24:USB"] = "7 USB_DM";
   pins["PA25:USB"] = "7 USB_DP";
   pins["PB22:USB"] = "7 USB_SOF_1KHZ";
   pins["PA30:CM4"] = "7 CM4_SWCLK";
   pins["PA31:CM4"] = "7 CM4_SWDIO";
   pins["PB30:CM4"] = "7 CM4_SWO";
   pins["PA06:SDHC0"] = "8 SDHC0_SDCD";
   pins["PA07:SDHC0"] = "8 SDHC0_SDWP";
   pins["PA08:SDHC0"] = "8 SDHC0_SDCMD";
   pins["PA09:SDHC0"] = "8 SDHC0_SDDAT0";
   pins["PA10:SDHC0"] = "8 SDHC0_SDDAT1";
   pins["PA11:SDHC0"] = "8 SDHC0_SDDAT2";
   pins["PB10:SDHC0"] = "8 SDHC0_SDDAT3";
   pins["PB11:SDHC0"] = "8 SDHC0_SDCK";
   pins["PB12:SDHC0"] = "8 SDHC0_SDCD";
   pins["PB13:SDHC0"] = "8 SDHC0_SDWP";
   pins["PA12:SDHC0"] = "8 SDHC0_SDCD";
   pins["PA13:SDHC0"] = "8 SDHC0_SDWP";
   pins["PB16:SDHC1"] = "8 SDHC1_SDCD";
   pins["PB17:SDHC1"] = "8 SDHC1_SDWP";
   pins["PA20:SDHC1"] = "8 SDHC1_SDCMD";
   pins["PA21:SDHC1"] = "8 SDHC1_SDCK";
   pins["PA22:CAN0"] = "8 CAN0_TX";
   pins["PA23:CAN0"] = "8 CAN0_RX";
   pins["PA24:CAN0"] = "8 CAN0_TX";
   pins["PA25:CAN0"] = "8 CAN0_RX";
   pins["PA08:I2S"] = "9 I2S_MCK0";
   pins["PA09:I2S"] = "9 I2S_FS0";
   pins["PA10:I2S"] = "9 I2S_SCK0";
   pins["PA11:I2S"] = "9 I2S_SDO";
   pins["PB10:I2S"] = "9 I2S_SDI";
   pins["PB11:I2S"] = "9 I2S_FS1";
   pins["PB12:I2S"] = "9 I2S_SCK1";
   pins["PB13:I2S"] = "9 I2S_MCK1";
   pins["PB16:I2S"] = "9 I2S_SCK0";
   pins["PB17:I2S"] = "9 I2S_MCK0";
   pins["PA20:I2S"] = "9 I2S_FS0";
   pins["PA21:I2S"] = "9 I2S_SDO";
   pins["PA22:I2S"] = "9 I2S_SDI";
   pins["PA23:I2S"] = "9 I2S_FS1";
   pins["PB14:PCC"] = "10 PCC_DATA8";
   pins["PB15:PCC"] = "10 PCC_DATA9";
   pins["PA12:PCC"] = "10 PCC_DEN1";
   pins["PA13:PCC"] = "10 PCC_DEN2";
   pins["PA14:PCC"] = "10 PCC_CLK";
   pins["PA16:PCC"] = "10 PCC_DATA0";
   pins["PA17:PCC"] = "10 PCC_DATA1";
   pins["PA18:PCC"] = "10 PCC_DATA2";
   pins["PA19:PCC"] = "10 PCC_DATA3";
   pins["PA20:PCC"] = "10 PCC_DATA4";
   pins["PA21:PCC"] = "10 PCC_DATA5";
   pins["PA22:PCC"] = "10 PCC_DATA6";
   pins["PA23:PCC"] = "10 PCC_DATA7";
   pins["PB14:GMAC"] = "11 GMAC_GMDC";
   pins["PB15:GMAC"] = "11 GMAC_GMDIO";
   pins["PA12:GMAC"] = "11 GMAC_GRX1";
   pins["PA13:GMAC"] = "11 GMAC_GRX0";
   pins["PA14:GMAC"] = "11 GMAC_GTXCK";
   pins["PA15:GMAC"] = "11 GMAC_GRXER";
   pins["PA16:GMAC"] = "11 GMAC_GCRS";
   pins["PA17:GMAC"] = "11 GMAC_GTXEN";
   pins["PA18:GMAC"] = "11 GMAC_GTX0";
   pins["PA19:GMAC"] = "11 GMAC_GTX1";
   pins["PA20:GMAC"] = "11 GMAC_GMDC";
   pins["PA21:GMAC"] = "11 GMAC_GMDIO";
   pins["PA10:GCLK"] = "12 GCLK_IO4";
   pins["PA11:GCLK"] = "12 GCLK_IO5";
   pins["PB10:GCLK"] = "12 GCLK_IO4";
   pins["PB11:GCLK"] = "12 GCLK_IO5";
   pins["PB12:GCLK"] = "12 GCLK_IO6";
   pins["PB13:GCLK"] = "12 GCLK_IO7";
   pins["PB14:GCLK"] = "12 GCLK_IO0";
   pins["PB15:GCLK"] = "12 GCLK_IO1";
   pins["PA12:AC"] = "12 AC_CMP0";
   pins["PA13:AC"] = "12 AC_CMP1";
   pins["PA14:GCLK"] = "12 GCLK_IO0";
   pins["PA15:GCLK"] = "12 GCLK_IO1";
   pins["PA16:GCLK"] = "12 GCLK_IO2";
   pins["PA17:GCLK"] = "12 GCLK_IO3";
   pins["PA18:AC"] = "12 AC_CMP0";
   pins["PA19:AC"] = "12 AC_CMP1";
   pins["PB16:GCLK"] = "12 GCLK_IO2";
   pins["PB17:GCLK"] = "12 GCLK_IO3";
   pins["PB22:GCLK"] = "12 GCLK_IO0";
   pins["PB23:GCLK"] = "12 GCLK_IO1";
   pins["PA30:GCLK"] = "12 GCLK_IO0";
   pins["PB06:CCL"] = "13 CCL_IN6";
   pins["PB07:CCL"] = "13 CCL_IN7";
   pins["PB08:CCL"] = "13 CCL_IN8";
   pins["PB09:CCL"] = "13 CCL_OUT2";
   pins["PA04:CCL"] = "13 CCL_IN0";
   pins["PA05:CCL"] = "13 CCL_IN1";
   pins["PA06:CCL"] = "13 CCL_IN2";
   pins["PA07:CCL"] = "13 CCL_OUT0";
   pins["PA08:CCL"] = "13 CCL_IN3";
   pins["PA09:CCL"] = "13 CCL_IN4";
   pins["PA10:CCL"] = "13 CCL_IN5";
   pins["PA11:CCL"] = "13 CCL_OUT1";
   pins["PB10:CCL"] = "13 CCL_IN11";
   pins["PB11:CCL"] = "13 CCL_OUT1";
   pins["PB14:CCL"] = "13 CCL_IN9";
   pins["PB15:CCL"] = "13 CCL_IN10";
   pins["PA16:CCL"] = "13 CCL_IN0";
   pins["PA17:CCL"] = "13 CCL_IN1";
   pins["PA18:CCL"] = "13 CCL_IN2";
   pins["PA19:CCL"] = "13 CCL_OUT0";
   pins["PB16:CCL"] = "13 CCL_IN11";
   pins["PB17:CCL"] = "13 CCL_OUT3";
   pins["PA22:CCL"] = "13 CCL_IN6";
   pins["PA23:CCL"] = "13 CCL_IN7";
   pins["PA24:CCL"] = "13 CCL_IN8";
   pins["PA25:CCL"] = "13 CCL_OUT2";
   pins["PB22:CCL"] = "13 CCL_IN0";
   pins["PB23:CCL"] = "13 CCL_OUT0";
   pins["PA30:CCL"] = "13 CCL_IN3";
   pins["PA31:CCL"] = "13 CCL_OUT1";
   pins["PB00:CCL"] = "13 CCL_IN1";
   pins["PB01:CCL"] = "13 CCL_IN2";
   pins["PB02:CCL"] = "13 CCL_OUT0";
}
