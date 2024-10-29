/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009, 2014, 2015 Mariano Cerdeiro
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

/* This file content the generated implementation of resource */

/*==================[inclusions]=============================================*/
#include "alarm_Cfg.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "application_Cfg.h"
#include "counter_Cfg.h"
#include "scheduleTable_Cfg.h"

/*==================[external data declaration]==============================*/

#pragma section

/* Brief AlarmVar Array */
AlarmVarType AlarmVar_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm3 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm3, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm4 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm4, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm SCalarm1 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        SCalarm1, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm SCalarm2 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        SCalarm2, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm Countalarm1 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        Countalarm1, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm Countalarm2 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        Countalarm2, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
};

/* Brief AlarmVar Array */
AlarmVarType AlarmVar_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm1 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm1, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm SCalarm3 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        SCalarm3, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm Countalarm3 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        Countalarm3, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm backgroundalarm */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        backgroundalarm, /* alarm ID */
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
};

/* Brief AlarmConst Array */
const AlarmConstType AlarmConst_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm3 */
    {
        counter3, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T02, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0, /* no schduletableID */
        }
    },
    /* Alarm alarm4 */
    {
        counter4, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T02, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0, /* no schduletableID */
        }
    },
        /* Alarm SCalarm1 */
    {
        counter3, /*counter ID */
        EPCALLBACK, /* alarm action */
        {
            0, /* Callback */
            0, /* TaskID */
            0, /* no event */
            0, /* no counter */
            scheduletable1, /* no schduletableID */
        }
    },
        /* Alarm SCalarm2 */
    {
        counter3, /*counter ID */
        EPCALLBACK, /* alarm action */
        {
            0, /* Callback */
            0, /* TaskID */
            0, /* no event */
            0, /* no counter */
            scheduletable2, /* no schduletableID */
        }
    },
    /* Alarm Countalarm1 */
    {
        counter3, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T01, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0, /* no schduletableID */
        }
    },
    /* Alarm Countalarm2 */
    {
        counter3, /*counter ID */
        SETEVENT, /* alarm action */
        {
            NULL, /* no callback */
            T01, /* TaskID */
            event2, /* no event */
            0, /* no counter */
            0, /* no schduletableID */
        }
    },
};

/* Brief AlarmConst Array */
const AlarmConstType AlarmConst_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm1 */
    {
        counter1, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T14, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0, /* no schduletableID */
        }
    },
    /* Alarm SCalarm3 */
    {
        counter1, /*counter ID */
        EPCALLBACK, /* alarm action */
        {
            0, /* callback */
            0, /* TaskID */
            0, /* no event */
            0, /* no counter */
            scheduletable3, /* no schduletableID */
        }
    },
    /* Alarm Countalarm3 */
    {
        counter1, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T11, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0, /* no schduletableID */
        }
    },
    /* Alarm backgroundalarm */
    {
        counter1, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T16, /* TaskID */
            event2, /* no event */
            0, /* no counter */
            0, /* no schduletableID */
        }
    },
};

AlarmAutosarType AlarmAutosar_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm3 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2)
    },
    /* Alarm alarm4 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2)
    },
    /* Alarm alarm5 */
    {
        app_lion,
        0 | (1 << app_lion)
    },
    /* Alarm alarm6 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2)
    },
    /* Alarm Countalarm1 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2)
    },
    /* Alarm Countalarm2 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2)
    },
};

AlarmAutosarType AlarmAutosar_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm1 */
    {
        app2,
        0 | (1 << app_lion) | (1 << app2)
    },
    /* Alarm SCalarm3 */
    {
        app2,
        0 | (1 << app_lion) | (1 << app2)
    },
    /* Alarm Countalarm3 */
    {
        app2,
        0 | (1 << app_lion) | (1 << app2)
    },
    /* Alarm backgroundalarm */
    {
        app2,
        0 | (1 << app_lion) | (1 << app2)
    },
};

/* Brief AutoStartAlarm Array */
// const AutoStartAlarmType AutoStartAlarm_core0[ALARMS_AUTOSTART_COUNT_CORE0] = {
//     {
//         AppMode1, /* application mode */
//         alarm1, /* Alarm */
//         100, /* alarm time */
//         100 /* cycle time */
//     }
// };

// const AutoStartAlarmType AutoStartAlarm_core1[ALARMS_AUTOSTART_COUNT_CORE1] = {
//     {
//         AppMode1, /* application mode */
//         alarm1, /* Alarm */
//         100, /* alarm time */
//         0 /* cycle time */
//     }
// };

#pragma section
