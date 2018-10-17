#defmacro tc

#iftrue (mode == 0)
#mod TC%unit% 16Bit Counter (%toupper(ref_source)% %frequency(ref_source)%/%prescaler%)
#otherwise
#iftrue (mode == 1)
#mod TC%unit% 8Bit Counter (%toupper(ref_source)% %frequency(ref_source)%/%prescaler%)
#otherwise
#mod TC%unit% 32Bit Counter (TC%unit%:TC%slaveunit%) (%toupper(ref_source)% %frequency(ref_source)%/%prescaler%)
#fi
#fi
	mclk_set_%apbmask%(%apb%);
#ifdefined apbslave
	mclk_set_%apbslavemask%(%apbslave%);
#fi
	/* Clock TC%unit% with %toupper(ref_source)% (%frequency(ref_source)%) */
	gclk_write_PCHCTRL(TC%unit%_GCLK_ID, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
#ifdefined slaveunit
	/** TC%unit% + TC%slaveunit% - 32 bit counter */
	tc_set_SWRST(TC%slaveunit%);
	tc_wait_for_sync(TC%slaveunit%, TC_SYNCBUSY_SWRST);
#fi
	tc_set_SWRST(TC%unit%);
	tc_wait_for_sync(TC%unit%, TC_SYNCBUSY_SWRST);
	
	tc_write_CTRLA(TC%unit%, TC_CTRLA_MODE_COUNT%mode%);
	tc_write_WAVE(TC%unit%, TC_WAVE_WAVEGEN_%wavegen%);

	tc_set_CTRLA(TC%unit%, <<<
	                  | TC_CTRLA_PRESCSYNC_%toupper(prescsync)%
					  | TC_CTRLA_PRESCALER_DIV%prescaler%
#ifdefined captmode0
	                  | TC_CTRLA_CAPTMODE0_%toupper(captmode0)%
#fi
#ifdefined captmode1
	                  | TC_CTRLA_CAPTMODE1_%toupper(captmode1)%
#fi
#ifdefined capten0
	                  | TC_CTRLA_CAPTEN0
#fi
#ifdefined capten1
	                  | TC_CTRLA_CAPTEN1
#fi
#ifdefined copen0
	                  | TC_CTRLA_COPEN0
#fi
#ifdefined copen1
	                  | TC_CTRLA_COPEN1
#fi
#ifdefined dmaos
	                  | TC_CTRLA_DMAOS
#fi
#ifdefined alock
	                  | TC_CTRLA_ALOCK
#fi
>>>);
	tc_write_CTRLB(TC%unit%, <<<
	                  | TC_CTRLBSET_CMD_NONE
#ifdefined oneshot
	                  | TC_CTRLBSET_ONESHOT
#fi
#ifdefined dir
					  | TC_CTRLBSET_DIR
#fi
#ifdefined lupd
                      | TC_CTRLBSET_LUPD
#fi
>>>);

	tc_write_DRVCTRL(TC%unit%, 0);
	tc_clear_CTRLB(TC%unit%, TC_CTRLBCLR_CMD_Msk);
#ifdefined cc0
	tccount%mode%_write_CC(TC%unit%, 0, %cc0%);
#fi
#ifdefined cc1
	tccount%mode%_write_CC(TC%unit%, 1, %cc1%);
#fi
#ifdefined count
	tccount%mode%_write_COUNT(TC%unit%, %count%);
#fi
	tc_write_EVCTRL(TC%unit%,<<<
#ifdefined event
	                  | TC_EVCTRL_TCEI
#ifdefined evact
	                  | TC_EVCTRL_EVACT_%toupper(evact)%
#fi
#ifdefined tcinv
	                  | TC_EVCTRL_TCINV
#fi
#fi
#ifdefined gen_ovf
	                  | TC_EVCTRL_OVFEO
#fi
#ifdefined gen_mc0
	                  | TC_EVCTRL_MCEO0
#fi	
#ifdefined gen_mc1
	                  | TC_EVCTRL_MCEO1
#fi	
>>>);
#ifdefined use_inten
	tc_write_INTEN(TC%unit%, <<<
#ifdefined int_ovf
                      | TC_INTENSET_OVF
#fi
#ifdefined int_err
                      | TC_INTENSET_ERR
#fi
#ifdefined int_mc0
                      | TC_INTENSET_MC0
#fi
#ifdefined int_mc1
                      | TC_INTENSET_MC1
#fi
>>>;
#fi
#ifdefined int_ovf
#nvic TC%unit%_OVF TC%unit%_IRQn TC%unit%_Handler
#fi
#ifdefined int_err
#nvic TC%unit%_ERR TC%unit%_IRQn TC%unit%_Handler
#fi
#ifdefined int_mc0
#nvic TC%unit%_MC0 TC%unit%_IRQn TC%unit%_Handler
#fi
#ifdefined int_mc1
#nvic TC%unit%_MC1 TC%unit%_IRQn TC%unit%_Handler
#fi
#ifdefined gen_ovf
#evt gen %gen_ovf% TC%unit%_OVF %toupper(path_ovf)% %edge_ovf% %touppper(sync_source_ovf)% %evint_ovf%
#fi
#ifdefined gen_mc0
#evt gen %gen_mc0% TC%unit%_MCX_0 %toupper(path_mc0)% %edge_mc0% %touppper(sync_source_mc0)% %evint_mc0%
#fi
#ifdefined gen_mc1
#evt gen %gen_mc1% TC%unit%_MCX_1 %toupper(path_mc1)% %edge_mc1% %touppper(sync_source_mc1)% %evint_mc1%
#fi
#ifdefined event
#evt event %event% TC%unit%_EVU
#fi
#ifdefined swgen
#evt swgen %swgen%
#fi
	tc_set_ENABLE(TC%unit%);
	tc_wait_for_sync(TC%unit%, TC_SYNCBUSY_ENABLE);
#endmacro

#defmacro tcc

	mclk_set_%apbmask%(%apb%);
	/* Clock TCC%unit% with %toupper(ref_source)% (%frequency(ref_source)%) */
	gclk_write_PCHCTRL(TCC%unit%_GCLK_ID, GCLK_PCHCTRL_GEN_%toupper(ref_source)% | GCLK_PCHCTRL_CHEN);
#mod TCC%unit% (%toupper(ref_source)% %frequency(ref_source)%/%prescaler%)
	/* Reset TCC%unit% */
	tcc_wait_for_sync(TCC%unit%, TCC_SYNCBUSY_SWRST);
	tcc_set_SWRST(TCC%unit%);
	tcc_wait_for_sync(TCC%unit%, TCC_SYNCBUSY_SWRST);
	/* Set Enable Protected Registers */
	tcc_write_CTRLA(TCC%unit%, <<<
#ifdefined cpten5
	                  | TCC_CTRLA_%toupper(cpten5)%
#fi
#ifdefined cpten4
	                  | TCC_CTRLA_%toupper(cpten4)%
#fi
#ifdefined cpten3
	                  | TCC_CTRLA_%toupper(cpten3)%
#fi
#ifdefined cpten2
	                  | TCC_CTRLA_%toupper(cpten2)%
#fi
#ifdefined cpten1
	                  | TCC_CTRLA_%toupper(cpten1)%
#fi
#ifdefined cpten0
	                  | TCC_CTRLA_%toupper(cpten0)%
#fi
#ifdefined dmaos
	                  | TCC_CTRLA_DMAOS
#fi
#ifdefined runstdby
	                  | TCC_CTRLA_RUNSTDBY
#fi
#ifdefined alock
	                  | TCC_CTRLA_ALOCK
#fi
                      | TCC_CTRLA_PRESCSYNC_%toupper(prescsync)%
					  | TCC_CTRLA_PRESCALER_DIV%prescaler%
					  | TCC_CTRLA_RESOLUTION_%toupper(resolution)%
>>>);
	tcc_write_FCTRLA(TCC%unit%, <<<
	                  | TCC_FCTRLA_SRC_%toupper(faulta_src)%
#ifdefined faulta_keep
				      | TCC_FCTRLA_KEEP
#fi
#ifdefined faulta_qual
				      | TCC_FCTRLA_QUAL
#fi
#ifdefined faulta_blank
	                  | TCC_FCTRLA_BLANK_%toupper(faulta_blank)%
#fi
#ifdefined faulta_restart
				      | TCC_FCTRLA_RESTART
#fi
#ifdefined faulta_halt
	                  | TCC_FCTRLA_HALT_%faulta_halt%
#fi
#ifdefined faulta_chsel
	                  | TCC_FCTRLA_CHSEL_CC%faulta_chsel%
#fi
#ifdefined faulta_capture
	                  | TCC_FCTRLA_CAPTURE_%toupper(faulta_capture)%
#otherwise
	                  | TCC_FCTRLA_CAPTURE_DISABLE
#fi
#ifdefined faulta_blankpresc
				      | TCC_FCTRLA_BLANKPRESC
#fi
#ifdefined faulta_blankval
                      | TCC_FCTRLA_BLANKVAL(%faulta_blankval%)
#fi
#ifdefined faulta_filterval
                      | TCC_FCTRLA_FILTERVAL(%faulta_filterval%)
#fi
>>>);
	tcc_write_FCTRLB(TCC%unit%, <<<
	                  | TCC_FCTRLB_SRC_%toupper(faultb_src)%
#ifdefined faultb_keep
				      | TCC_FCTRLB_KEEP
#fi
#ifdefined faultb_qual
				      | TCC_FCTRLB_QUAL
#fi
#ifdefined faultb_blank
	                  | TCC_FCTRLB_BLANK_%toupper(faultb_blank)%
#fi
#ifdefined faultb_restart
				      | TCC_FCTRLB_RESTART
#fi
#ifdefined faultb_halt
	                  | TCC_FCTRLB_HALT_%faultb_halt%
#fi
#ifdefined faultb_chsel
	                  | TCC_FCTRLB_CHSEL_CC%faultb_chsel%
#fi
#ifdefined faultb_capture
	                  | TCC_FCTRLB_CAPTURE_%toupper(faultb_capture)%
#otherwise
	                  | TCC_FCTRLA_CAPTURE_DISABLE
#fi
#ifdefined faultb_blankpresc
				      | TCC_FCTRLB_BLANKPRESC
#fi
#ifdefined faultb_blankval
                      | TCC_FCTRLB_BLANKVAL(%faultb_blankval%)
#fi
#ifdefined faultb_filterval
                      | TCC_FCTRLB_FILTERVAL(%faultb_filterval%)
#fi
>>>);
	tcc_write_DRVCTRL(TCC%unit%, <<<
#ifdefined nre0
                      | TCC_DRVCTRL_NRE0
#fi
#ifdefined nre1
                      | TCC_DRVCTRL_NRE1
#fi
#ifdefined nre2
                      | TCC_DRVCTRL_NRE2
#fi
#ifdefined nre3
                      | TCC_DRVCTRL_NRE3
#fi
#ifdefined nre4
                      | TCC_DRVCTRL_NRE4
#fi
#ifdefined nre5
                      | TCC_DRVCTRL_NRE5
#fi
#ifdefined nre6
                      | TCC_DRVCTRL_NRE6
#fi
#ifdefined nre7
                      | TCC_DRVCTRL_NRE7
#fi
#ifdefined nrv0
                      | TCC_DRVCTRL_NRV0
#fi
#ifdefined nrv1
                      | TCC_DRVCTRL_NRV1
#fi
#ifdefined nrv2
                      | TCC_DRVCTRL_NRV2
#fi
#ifdefined nrv3
                      | TCC_DRVCTRL_NRV3
#fi
#ifdefined nrv4
                      | TCC_DRVCTRL_NRV4
#fi
#ifdefined nrv5
                      | TCC_DRVCTRL_NRV5
#fi
#ifdefined nrv6
                      | TCC_DRVCTRL_NRV6
#fi
#ifdefined nrv7
                      | TCC_DRVCTRL_NRV7
#fi
#ifdefined inven0
                      | TCC_DRVCTRL_INVEN0
#fi
#ifdefined inven1
                      | TCC_DRVCTRL_INVEN1
#fi
#ifdefined inven2
                      | TCC_DRVCTRL_INVEN2
#fi
#ifdefined inven3
                      | TCC_DRVCTRL_INVEN3
#fi
#ifdefined inven4
                      | TCC_DRVCTRL_INVEN4
#fi
#ifdefined inven5
                      | TCC_DRVCTRL_INVEN5
#fi
#ifdefined inven6
                      | TCC_DRVCTRL_INVEN6
#fi
#ifdefined inven7
                      | TCC_DRVCTRL_INVEN7
#fi
#ifdefined filterval0
                      | TCC_DRVCTRL_FILTERVAL0(%filterval0%)
#fi
#ifdefined filterval1
                      | TCC_DRVCTRL_FILTERVAL1(%filterval1%)
#fi
>>>);
	tcc_write_DBGCTRL(TCC%unit%, <<<
#ifdefined fddbd
                      | TCC_DBGCTRL_FDDBD
#fi
#ifdefined dbgrun
                      | TCC_DBGCTRL_DBGRUN
#fi
>>>);
#ifdefined per
	tcc_write_PER(TCC%unit%, %per%);
#fi
#ifdefined cc0
	tcc_write_CC(TCC%unit%, 0, %cc0%);
#fi
#ifdefined cc1
	tcc_write_CC(TCC%unit%, 1, %cc1%);
#fi
#ifdefined cc2
	tcc_write_CC(TCC%unit%, 2, %cc2%);
#fi
#ifdefined cc3
	tcc_write_CC(TCC%unit%, 3, %cc3%);
#fi
#ifdefined cc4
	tcc_write_CC(TCC%unit%, 4, %cc4%);
#fi
#ifdefined cc5
	tcc_write_CC(TCC%unit%, 5, %cc5%);
#fi
#ifdefined count
	tcc_write_COUNT(TCC%unit%, %count%);
#fi
	tcc_write_WEXCTRL(TCC%unit%, <<<
#ifdefined otmx
                      | TCC_WEXCTRL_OTMX(%otmx%)
#fi
#ifdefined dtien0
                      | TCC_WEXCTRL_DTIEN0
#fi
#ifdefined dtien1
                      | TCC_WEXCTRL_DTIEN1
#fi
#ifdefined dtien2
                      | TCC_WEXCTRL_DTIEN2
#fi
#ifdefined dtien3
                      | TCC_WEXCTRL_DTIEN3
#fi
#ifdefined dtls
                      | TCC_WEXCTRL_DTLS(%dtls%)
#fi
#ifdefined dths
                      | TCC_WEXCTRL_DTHS(%dths%)
#fi
>>>);
	tcc_write_CTRLB(TCC%unit%, <<<
	                  | TCC_CTRLBSET_CMD_NONE
	                  | TCC_CTRLBSET_IDXCMD_DISABLE
#ifdefined oneshot
	                  | TCC_CTRLBSET_ONESHOT
#fi
#ifdefined dir
					  | TCC_CTRLBSET_DIR
#fi
#ifdefined lupd
                      | TCC_CTRLBSET_LUPD
#fi
>>>);
	tcc_write_WAVE(TCC%unit%, <<<
#ifdefined wavegen
                      | TCC_WAVE_WAVEGEN_%toupper(wavegen)%
#fi
#ifdefined ramp
                      | TCC_WAVE_RAMP_%toupper(ramp)%
#fi
#ifdefined ciperen
                      | TCC_WAVE_CIPEREN
#fi
#ifdefined ciccen0
                      | TCC_WAVE_CICCEN0
#fi
#ifdefined ciccen1
                      | TCC_WAVE_CICCEN1
#fi
#ifdefined ciccen2
                      | TCC_WAVE_CICCEN2
#fi
#ifdefined ciccen3
                      | TCC_WAVE_CICCEN3
#fi
#ifdefined pol0
                      | TCC_WAVE_POL0
#fi
#ifdefined pol0
                      | TCC_WAVE_POL0
#fi
#ifdefined pol1
                      | TCC_WAVE_POL1
#fi
#ifdefined pol2
                      | TCC_WAVE_POL2
#fi
#ifdefined pol3
                      | TCC_WAVE_POL3
#fi
#ifdefined pol4
                      | TCC_WAVE_POL4
#fi
#ifdefined pol5
                      | TCC_WAVE_POL5
#fi
#ifdefined swap0
                      | TCC_WAVE_SWAP0
#fi
#ifdefined swap1
                      | TCC_WAVE_SWAP1
#fi
#ifdefined swap2
                      | TCC_WAVE_SWAP2
#fi
#ifdefined swap3
                      | TCC_WAVE_SWAP3
#fi
>>>);
	tcc_write_PATT(TCC%unit%, <<<
#ifdefined pgv0
                      | TCC_PATT_PGV0
#fi
#ifdefined pgv1
                      | TCC_PATT_PGV1
#fi
#ifdefined pgv2
                      | TCC_PATT_PGV2
#fi
#ifdefined pgv3
                      | TCC_PATT_PGV3
#fi
#ifdefined pgv4
                      | TCC_PATT_PGV4
#fi
#ifdefined pgv5
                      | TCC_PATT_PGV5
#fi
#ifdefined pgv6
                      | TCC_PATT_PGV6
#fi
#ifdefined pgv7
                      | TCC_PATT_PGV7
#fi
#ifdefined pge0
                      | TCC_PATT_PGE0
#fi
#ifdefined pge1
                      | TCC_PATT_PGE1
#fi
#ifdefined pge2
                      | TCC_PATT_PGE2
#fi
#ifdefined pge3
                      | TCC_PATT_PGE3
#fi
#ifdefined pge4
                      | TCC_PATT_PGE4
#fi
#ifdefined pge5
                      | TCC_PATT_PGE5
#fi
#ifdefined pge6
                      | TCC_PATT_PGE6
#fi
#ifdefined pge7
                      | TCC_PATT_PGE7
#fi
>>>);
	tcc_write_EVCTRL(TCC%unit%, <<<
#ifdefined evact0
                      | TCC_EVCTRL_EVACT0_%toupper(evact0)%
#fi
#ifdefined evact1
                      | TCC_EVCTRL_EVACT1_%toupper(evact1)%
#fi
#ifdefined cntsel
                      | TCC_EVCTRL_CNTSEL_%toupper(cntsel)%
#fi
#ifdefined gen_ovf
                      | TCC_EVCTRL_OVFEO
#fi
#ifdefined gen_trg
                      | TCC_EVCTRL_TRGEO
#fi
#ifdefined gen_cnt
                      | TCC_EVCTRL_CNTEO
#fi
#ifdefined tcinv0
                      | TCC_EVCTRL_TCINV0
#fi
#ifdefined tcinv1
                      | TCC_EVCTRL_TCINV1
#fi
#ifdefined event0
                      | TCC_EVCTRL_TCEI0
#fi
#ifdefined event1
                      | TCC_EVCTRL_TCEI1
#fi
#ifdefined event_mc0
                      | TCC_EVCTRL_MCEI0
#fi
#ifdefined event_mc1
                      | TCC_EVCTRL_MCEI1
#fi
#ifdefined event_mc2
                      | TCC_EVCTRL_MCEI2
#fi
#ifdefined event_mc3
                      | TCC_EVCTRL_MCEI3
#fi
#ifdefined event_mc4
                      | TCC_EVCTRL_MCEI4
#fi
#ifdefined event_mc5
                      | TCC_EVCTRL_MCEI5
#fi
#ifdefined gen_mc0
                      | TCC_EVCTRL_MCEO0
#fi
#ifdefined gen_mc1
                      | TCC_EVCTRL_MCEO1
#fi
#ifdefined gen_mc2
                      | TCC_EVCTRL_MCEO2
#fi
#ifdefined gen_mc3
                      | TCC_EVCTRL_MCEO3
#fi
#ifdefined gen_mc4
                      | TCC_EVCTRL_MCEO4
#fi
#ifdefined gen_mc5
                      | TCC_EVCTRL_MCEO5
#fi
>>>);
#ifdefined use_inten
	tcc_write_INTEN(TCC%unit%, <<<
#ifdefined int_ovf
                      | TCC_INTENSET_OVF
#fi
#ifdefined int_trg
                      | TCC_INTENSET_TRG
#fi
#ifdefined int_cnt
                      | TCC_INTENSET_CNT
#fi
#ifdefined int_err
                      | TCC_INTENSET_ERR
#fi
#ifdefined int_ufs
                      | TCC_INTENSET_UFS
#fi
#ifdefined int_dfs
                      | TCC_INTENSET_DFS
#fi
#ifdefined int_faulta
                      | TCC_INTENSET_FAULTA
#fi
#ifdefined int_faultb
                      | TCC_INTENSET_FAULTB
#fi
#ifdefined int_fault0
                      | TCC_INTENSET_FAULT0
#fi
#ifdefined int_fault1
                      | TCC_INTENSET_FAULT1
#fi
#ifdefined int_mc0
                      | TCC_INTENSET_MC0
#fi
#ifdefined int_mc1
                      | TCC_INTENSET_MC1
#fi
#ifdefined int_mc2
                      | TCC_INTENSET_MC2
#fi
#ifdefined int_mc3
                      | TCC_INTENSET_MC3
#fi
#ifdefined int_mc4
                      | TCC_INTENSET_MC4
#fi
#ifdefined int_mc5
                      | TCC_INTENSET_MC5
#fi
>>>);
#fi
#ifdefined event0
#evt event %event0% TCC%unit%_EV_0
#fi
#ifdefined event1
#evt event %event1% TCC%unit%_EV_1
#fi
#ifdefined event_mc0
#evt event %event_mc0% TCC%unit%_MC_0
#fi
#ifdefined event_mc1
#evt event %event_mc1% TCC%unit%_MC_1
#fi
#ifdefined event_mc2
#evt event %event_mc2% TCC%unit%_MC_2
#fi
#ifdefined event_mc3
#evt event %event_mc3% TCC%unit%_MC_3
#fi
#ifdefined event_mc4
#evt event %event_mc4% TCC%unit%_MC_4
#fi
#ifdefined event_mc5
#evt event %event_mc5% TCC%unit%_MC_5
#fi
#ifdefined gen_ovf
#evt gen %gen_ovf% TCC%unit%_OVF %toupper(path_ovf)% %toupper(edge_ovf)% %touppper(sync_source_ovf)% %evint_ovf%
#fi
#ifdefined gen_trg
#evt gen %gen_trg% TCC%unit%_TRG %toupper(path_trg)% %toupper(edge_trg)% %touppper(sync_source_trg)% %evint_trg%
#fi
#ifdefined gen_cnt
#evt gen %gen_cnt% TCC%unit%_CNT %toupper(path_cnt)% %toupper(edge_cnt)% %touppper(sync_source_cnt)% %evint_cnt%
#fi
#ifdefined gen_mc0
#evt gen %gen_mc0% TCC%unit%_MCX_0 %toupper(path_mc0)% %toupper(edge_mc0)% %touppper(sync_source_mc0)% %evint_mc0%
#fi
#ifdefined gen_mc1
#evt gen %gen_mc1% TCC%unit%_MCX_1 %toupper(path_mc1)% %toupper(edge_mc1)% %touppper(sync_source_mc1)% %evint_mc1%
#fi
#ifdefined gen_mc2
#evt gen %gen_mc2% TCC%unit%_MCX_2 %toupper(path_mc2)% %toupper(edge_mc2)% %touppper(sync_source_mc2)% %evint_mc2%
#fi
#ifdefined gen_mc3
#evt gen %gen_mc3% TCC%unit%_MCX_3 %toupper(path_mc3)% %toupper(edge_mc3)% %touppper(sync_source_mc3)% %evint_mc3%
#fi
#ifdefined gen_mc4
#evt gen %gen_mc4% TCC%unit%_MCX_4 %toupper(path_mc4)% %toupper(edge_mc4)% %touppper(sync_source_mc4)% %evint_mc4%
#fi
#ifdefined gen_mc5
#evt gen %gen_mc5% TCC%unit%_MCX_5 %toupper(path_mc5)% %toupper(edge_mc5)% %touppper(sync_source_mc5)% %evint_mc5%
#fi
#ifdefined swgen
#evt swgen %swgen%
#fi
#ifdefined int_ovf
#nvic TCC%unit%_OVF TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_trg
#nvic TCC%unit%_TRG TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_cnt
#nvic TCC%unit%_CNT TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_err
#nvic TCC%unit%_ERR TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_ufs
#nvic TCC%unit%_UFS TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_dfs
#nvic TCC%unit%_DFS TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_faulta
#nvic TCC%unit%_FAULTA TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_faultb
#nvic TCC%unit%_FAULTB TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_fault0
#nvic TCC%unit%_FAULT0 TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_fault1
#nvic TCC%unit%_FAULT1 TCC%unit%_0_IRQn TCC%unit%_0_Handler
#fi
#ifdefined int_mc0
#nvic TCC%unit%_MC0 TCC%unit%_1_IRQn TCC%unit%_1_Handler
#fi
#ifdefined int_mc1
#nvic TCC%unit%_MC1 TCC%unit%_2_IRQn TCC%unit%_2_Handler
#fi
#ifdefined int_mc2
#nvic TCC%unit%_MC2 TCC%unit%_3_IRQn TCC%unit%_3_Handler
#fi
#ifdefined int_mc3
#nvic TCC%unit%_MC3 TCC%unit%_4_IRQn TCC%unit%_4_Handler
#fi
#ifdefined int_mc4
#nvic TCC%unit%_MC4 TCC%unit%_5_IRQn TCC%unit%_5_Handler
#fi
#ifdefined int_mc5
#nvic TCC%unit%_MC5 TCC%unit%_6_IRQn TCC%unit%_6_Handler
#fi
	tcc_set_ENABLE(TCC%unit%);
	tcc_wait_for_sync(TCC%unit%, TCC_SYNCBUSY_ENABLE);
#endmacro

#defmacro systick
	/** System Tick (defined in CMSIS) */
	SysTick_Config((CPU_FREQUENCY/1000)*SYSTICK_PERIOD);
#nvic systick NA SysTick_Handler
#ifdefined isr
#isr volatile uint32_t tick = 0;
#isr void SysTick_Handler(void)
#isr {
#isr     tick++;
#isr }
#fi
#endmacro

