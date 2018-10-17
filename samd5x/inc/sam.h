/**
 * @mainpage SAMD51 Low Level Drivers
 * 
 * This is a derivation of the hri includes from Microchip ASF4 library. 
 * These files have been heavily altered by a series of bash/awk scripts, some 
 * have been completely rewritten.
 * 	1. Removed the const void const * to peripheral struct space. void pointers
 * should be used sparingly and this wasn't the case here. Where there were single 
 * components, the pointer is unnecessary to pass. 
 * 	2. Some of the functions were not useful and removed. For example, there were
 * functions which could toggle bitfields but they were applied to non-bitfield
 * registers.
 * 	3. Removed hri_ and _bit, _bf from the function names. This identified the
 * layer, processor and so on. This no longer is a HAL layer.
 * 	4. Removed  critical code. An RTOS provides critical code calls and usually used 
 * sparingly. 
 * 	5. Assign typedefs to return values is reverted back to basic types. This was
 * redundant and it would be better to know the actual size of the return value. 
 * 	6. Added doxygen comments with included bit patterns from the component and  *
 * instance files for the functions referencing those. 
 * 	7. Optimized the code removing unnecessary variables and lines of code.
 * 	8. They had a convention of naming times with _t or _Type but they 
 * weren't consitant. 
 * 	9. Many bugfixes. 
 * 
 * @note This file is modified from Start.Atmel.com
 * by Alkgrove 2018
 * @version beta
 **/

/**
 * \file
 *
 * \brief Top header file for SAMD51
 *
 * Copyright (c) 2017 Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAM_
#define _SAM_

/**
 * \defgroup SAMD51_definitions SAMD51 Device Definitions
 * \brief SAMD51 CMSIS Definitions.
 */

#if   defined(__SAMD51G18A__) || defined(__ATSAMD51G18A__)
  #include "samd51g18a.h"
#elif defined(__SAMD51G19A__) || defined(__ATSAMD51G19A__)
  #include "samd51g19a.h"
#elif defined(__SAMD51J18A__) || defined(__ATSAMD51J18A__)
  #include "samd51j18a.h"
#elif defined(__SAMD51J19A__) || defined(__ATSAMD51J19A__)
  #include "samd51j19a.h"
#elif defined(__SAMD51J20A__) || defined(__ATSAMD51J20A__)
  #include "samd51j20a.h"
#elif defined(__SAMD51N19A__) || defined(__ATSAMD51N19A__)
  #include "samd51n19a.h"
#elif defined(__SAMD51N20A__) || defined(__ATSAMD51N20A__)
  #include "samd51n20a.h"
#elif defined(__SAMD51P19A__) || defined(__ATSAMD51P19A__)
  #include "samd51p19a.h"
#elif defined(__SAMD51P20A__) || defined(__ATSAMD51P20A__)
  #include "samd51p20a.h"
#else
  #error Library does not support the specified device.
#endif

#include "ac.h"
#include "adc.h"
#include "aes.h"
#include "ccl.h"
#include "cmcc.h"
#include "dac.h"
#include "dmac.h"
#include "dsu.h"
#include "eic.h"
#include "evsys.h"
#include "freqm.h"
#include "gclk.h"
#include "hmatrixb.h"
#include "i2s.h"
#include "i2cm.h"
#include "icm.h"
#include "mclk.h"
#include "nvmctrl.h"
#include "osc32kctrl.h"
#include "oscctrl.h" 
#include "pac.h"
#include "pcc.h"
#include "pdec.h"
#include "pm.h"
#include "qspi.h"
#include "ramecc.h"
#include "rstc.h"
#include "rtc.h"
#include "sdhc.h"
#include "sercom.h"
#include "supc.h"
#include "tc.h"
#include "tcc.h"
#include "trng.h"
#include "usb.h"
#include "wdt.h"
#include "gpio.h" /* renamed from port */

#endif /* _SAM_ */
