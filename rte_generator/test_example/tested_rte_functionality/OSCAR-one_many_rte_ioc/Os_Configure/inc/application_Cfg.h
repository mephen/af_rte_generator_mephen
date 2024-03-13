/* Copyright 2008, 2009 Mariano Cerdeiro
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

#ifndef APPLICATION_CFG_H
#define APPLICATION_CFG_H

/* This file content the generated configuration of task */

/*==================[inclusions]=============================================*/
#include "typedefine.h"

/*==================[macros]=================================================*/
#define APPLICATIONS_COUNT_CORE0 2
#define APPLICATIONS_COUNT_CORE1 2
#define APPLICATIONS_COUNT 4

#define TRUSTED_APPLICATIONS_COUNT 2

#define TRUSTED_FUNCTIONS_COUNT 0

/* 
the app-id should be pure nature number like 0,1,2,... ,
because we use app-id as a "bit" in ApplicationsMaskType.
Also, in autosar, the app-id should be exclusive number,
i.e., even in different core, the app-id is never the same.
*/

#define app_lion 0  //lion 
#define app2 1  //wolf
#define app3 2  //cat
#define app4 3  //dog
#define INVALID_OSAPPLICATION 4

/*==================[external data declaration]=========================*/
// extern ApplicationVarType ApplicationVar_core0[APPLICATIONS_COUNT_CORE0];
// extern ApplicationVarType ApplicationVar_core1[APPLICATIONS_COUNT_CORE1];
extern ApplicationVarType ApplicationVar[APPLICATIONS_COUNT];
/*the ApplicationObjectsType are currrently used only in application.c*/
extern ApplicationObjectsType ApplicationObjects_core0[APPLICATIONS_COUNT_CORE0];
extern ApplicationObjectsType ApplicationObjects_core1[APPLICATIONS_COUNT_CORE1];
extern LockType lockForApplicationState[APPLICATIONS_COUNT];

/*==================[end of file]============================================*/
#endif /* #ifndef APPLICATION_CFG_H */