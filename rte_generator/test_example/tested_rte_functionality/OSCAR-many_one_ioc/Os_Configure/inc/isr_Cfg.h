/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009, 2015 Mariano Cerdeiro
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef ISR_CFG_H
#define ISR_CFG_H

/* This file content the generated configuration of isr */
#include "typedefine.h"
#include "os_Cfg.h"
#include "iodefine.h"
/*==================[macros]=================================================*/

/* Brief Count of ISR2 task */
#define ISR1_COUNT_CORE0 2U
#define ISR2_COUNT_CORE0 4U
#define ISR_ALL_COUNT_CORE0 6U

#define ISR1_COUNT_CORE1 2U
#define ISR2_COUNT_CORE1 4U
#define ISR_ALL_COUNT_CORE1 6U

#define ISR_ALL_COUNT_ALL_CORE 12U

/* Brief ISR Definition */ /*isr2 is arranged before isr1*/
/* core0 */
#define I002             0x00000000
#define I003             0x00000001
#define I005             0x00000002
#define I006             0x00000003
#define I001             0x00000004  //isr1
#define I004             0x00000005  //isr1

/* core1 */
#define I102             0x00010000
#define I103             0x00010001
#define I105             0x00010002  
#define I106             0x00010003
#define I101             0x00010004  //isr1
#define I104             0x00010005  //isr1

#define INVALID_ISR_ID   0X00020000  

extern IsrConstType Isr_const_core0[ISR_ALL_COUNT_CORE0];
extern IsrConstType Isr_const_core1[ISR_ALL_COUNT_CORE1];
extern IsrConstRefType Isr_const[OsNumberOfCores];

extern IsrAutosarType IsrAutosar_core0[ISR_ALL_COUNT_CORE0];
extern IsrAutosarType IsrAutosar_core1[ISR_ALL_COUNT_CORE1];

/*==================[external functions declaration]=========================*/


/*==================[end of file]============================================*/
#endif /* #ifndef ISR_CFG_H */
