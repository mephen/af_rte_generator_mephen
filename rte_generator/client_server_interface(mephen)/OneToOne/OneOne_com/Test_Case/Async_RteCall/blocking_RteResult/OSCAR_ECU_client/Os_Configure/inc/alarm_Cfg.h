/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

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

#ifndef ALARM_CFG_H
#define ALARM_CFG_H

/* This file content the generated configuration of alarm */

/*==================[inclusions]=============================================*/
#include "typedefine.h"
/*==================[macros]=================================================*/
/* Brief Definition of the DeclareAlarmCallback Macro */
#define DeclareCallback(name) void MILKSHOP_CALLBACK_ ## name (void)

/* brief ALARMS_COUNT define */
#define ALARMS_COUNT_CORE0 4
#define ALARMS_COUNT_CORE1 2
#define ALARMS_COUNT 6
/* brief ALARMS_AUTOSTART_COUNT define */
#define ALARMS_AUTOSTART_COUNT_CORE0 0
#define ALARMS_AUTOSTART_COUNT_CORE1 0
#define ALARMS_AUTOSTART_COUNT 0

/* brief Definition of the Alarm alarm3 */
#define alarm3 0x00000000
/* brief Definition of the Alarm alarm4 */
#define alarm4 0x00000001
/* brief Definition of the Alarm alarm3 */
#define SCalarm1 0x00000002
/* brief Definition of the Alarm alarm4 */
#define SCalarm2 0x00000003

/* brief Definition of the Alarm alarm1 */
#define alarm1 0x00010000
/* brief Definition of the Alarm alarm2 */
#define SCalarm3 0x00010001

#define INVALID_ALARM_ID 0x00020000

/*==================[external data declaration]=========================*/
/* brief Alarm Variable Structure */
extern AlarmVarType AlarmVar_core0[ALARMS_COUNT_CORE0];
extern AlarmVarType AlarmVar_core1[ALARMS_COUNT_CORE1];

/* brief Alarm Constant Structure */
extern const AlarmConstType AlarmConst_core0[ALARMS_COUNT_CORE0];
extern const AlarmConstType AlarmConst_core1[ALARMS_COUNT_CORE1];

/* brief Accessible App of Alarm */
extern AlarmAutosarType AlarmAutosar_core0[ALARMS_COUNT_CORE0];
extern AlarmAutosarType AlarmAutosar_core1[ALARMS_COUNT_CORE1];

/* brief AutoStartAlarm Structure */
// extern const AutoStartAlarmType AutoStartAlarm_core0[ALARMS_AUTOSTART_COUNT_CORE0];
// extern const AutoStartAlarmType AutoStartAlarm_core1[ALARMS_AUTOSTART_COUNT_CORE1];

/*==================[external functions declaration]=========================*/
/* Brief Callback Declaration of Callback CallbackFunc */
DeclareCallback(CallbackFunc0);
DeclareCallback(CallbackFunc);

/*==================[end of file]============================================*/
#endif /* #ifndef ALARM_CFG_H */
