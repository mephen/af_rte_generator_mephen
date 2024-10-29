/*==================[inclusions]=============================================*/
#include "alarm_Cfg.h"
#include "alarm.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "counter.h"
#include "counter_Cfg.h"
#include "scheduleTable_Cfg.h"
#include "application_Cfg.h"
/*==================[declarations]=============================================*/
#pragma section

/* ScheduleTables */
ScheduleTableType ST1;
ScheduleTableType ST2;
ScheduleTableType ST3;
const ScheduleTableConstType ScheduleTableConst_core0[SCHEDULETABLE_COUNT_CORE0] = {
    {
        EXPLICIT, /*syncStrategy*/
        TRUE, /*repeating*/
        counter1, /*counter*/
        counter_ST2, /*syncCounter*/
        2, /*ExplicitPrecision*/
        2, /*EPAmount*/
        100, /*duration*/
        20, /*initOffset*/
        80, /*finalDelay*/
        alarm_ST2, /*callbackAlarm*/
        expirypoints_ST2, /*expiryPoints*/
        ST2_taskArray, /*taskArray*/
        ST2_eventArray /*eventArray*/
    },
    {
        EXPLICIT, /*syncStrategy*/
        TRUE, /*repeating*/
        counter1, /*counter*/
        counter_ST3, /*syncCounter*/
        2, /*ExplicitPrecision*/
        2, /*EPAmount*/
        50, /*duration*/
        30, /*initOffset*/
        20, /*finalDelay*/
        alarm_ST3, /*callbackAlarm*/
        expirypoints_ST3, /*expiryPoints*/
        ST3_taskArray, /*taskArray*/
        NULL,
    },
};
ScheduleTableVarType ScheduleTableVar_core0[SCHEDULETABLE_COUNT_CORE0] = {
    {
        SCHEDULETABLE_STOPPED, /*status*/
        0, /*deviation*/
        0, /*currentEPIndex*/
        SCHEDULETABLE_COUNT_CORE0 /*next*/
    },
    {
        SCHEDULETABLE_STOPPED, /*status*/
        0, /*deviation*/
        0, /*currentEPIndex*/
        SCHEDULETABLE_COUNT_CORE0 /*next*/
    },
};
ScheduleTableAutosarType ScheduleTableAutosar_core0[SCHEDULETABLE_COUNT_CORE0] = {
    /* ScheduleTable ST2 */
    {
        App3,
        0 | (1 << App2) | (1 << App4) ,
    },
    /* ScheduleTable ST3 */
    {
        App3,
        0 | (1 << App2) | (1 << App4) ,
    },
};
/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncST2 */
DeclareCallback(ExpiryPointCallbackFuncST2);
/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncST3 */
DeclareCallback(ExpiryPointCallbackFuncST3);
const ScheduleTableConstType ScheduleTableConst_core0[SCHEDULETABLE_COUNT_CORE0] = {
    {
        EXPLICIT, /*syncStrategy*/
        TRUE, /*repeating*/
        counter1, /*counter*/
        counter_ST2, /*syncCounter*/
        2, /*ExplicitPrecision*/
        2, /*EPAmount*/
        100, /*duration*/
        20, /*initOffset*/
        80, /*finalDelay*/
        alarm_ST2, /*callbackAlarm*/
        expirypoints_ST2, /*expiryPoints*/
        ST2_taskArray, /*taskArray*/
        ST2_eventArray /*eventArray*/
    },
    {
        EXPLICIT, /*syncStrategy*/
        TRUE, /*repeating*/
        counter1, /*counter*/
        counter_ST3, /*syncCounter*/
        2, /*ExplicitPrecision*/
        2, /*EPAmount*/
        50, /*duration*/
        30, /*initOffset*/
        20, /*finalDelay*/
        alarm_ST3, /*callbackAlarm*/
        expirypoints_ST3, /*expiryPoints*/
        ST3_taskArray, /*taskArray*/
        NULL,
    },
};
ScheduleTableVarType ScheduleTableVar_core0[SCHEDULETABLE_COUNT_CORE0] = {
    {
        SCHEDULETABLE_STOPPED, /*status*/
        0, /*deviation*/
        0, /*currentEPIndex*/
        SCHEDULETABLE_COUNT_CORE0 /*next*/
    },
};
ScheduleTableAutosarType ScheduleTableAutosar_core0[SCHEDULETABLE_COUNT_CORE0] = {
    /* ScheduleTable ST1 */
    {
        0 | (1 << App2) | (1 << App4) ,
    },
};
/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncST1 */
DeclareCallback(ExpiryPointCallbackFuncST1);
