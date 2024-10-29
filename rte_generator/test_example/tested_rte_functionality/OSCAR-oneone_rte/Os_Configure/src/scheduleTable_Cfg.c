/*==================[inclusions]=============================================*/
#include "alarm.h"
#include "counter.h"
#include "os_Cfg.h"
#include "counter_Cfg.h"
#include "scheduleTable_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "application_Cfg.h"
#include "alarm_Cfg.h"

/*==================[declarations]=============================================*/
#pragma section
/* ScheduleTables */
ScheduleTableType ScheduleTableA = scheduletable1;
ScheduleTableType ScheduleTableB = scheduletable2;

/* ExpiryPoint structure */
/* for ScheduleTableA */
ExpiryPointType expiryPoints_0[EXPIRYPOINT_COUNT_0] = {
    {
        2, /*offset*/
        0, /*task start*/
        1, /*task end*/
        0, /*event start*/
        0, /*event end*/
        0, /*maxShorten*/
        0, /*maxLengthen*/
        NULL /*next*/
    },
    {
        4, /*offset*/
        1, /*task start*/
        2, /*task end*/
        0, /*event start*/
        0, /*event end*/
        0, /*maxShorten*/
        0, /*maxLengthen*/
        NULL /*next*/
    },
};

/* Task and Event Array for expiryPoints_0 */
TaskType taskArray_0[2] = {
    T02,
    T04
};

EventSetting eventArray_0[1] = {
    {
        T03, 
        event1
    }
};

/* for ScheduleTableB */
ExpiryPointType expiryPoints_1[EXPIRYPOINT_COUNT_1] = {
    {
        5, /*offset*/
        0, /*task start*/
        1, /*task end*/
        0, /*event start*/
        0, /*event end*/
        0, /*maxShorten*/
        0, /*maxLengthen*/
        NULL /*next*/
    },
};

/* Task and Event Array */
TaskType taskArray_1[1] = {
    T04
};

EventSetting *eventArray_1;


const ScheduleTableConstType ScheduleTableConst_core0[SCHEDULETABLE_COUNT_CORE0] = {
    {
        NONE, /*syncStrategy*/
        FALSE, /*repeating*/
        counter3, /*counter*/
        DriveCounter, /*syncCounter*/
        0, /*ExplicitPrecision*/
        2, /*EPAmount*/
        6, /*duration*/
        2, /*initOffset*/
        2, /*finalDelay*/        
        SCalarm1, /*callbackAlarm*/
        expiryPoints_0, /*expiryPoints*/
        taskArray_0, /*taskArray*/
        eventArray_0 /*eventArray*/
    },
    {
        NONE, /*syncStrategy*/
        FALSE, /*repeating*/
        counter3, /*counter*/
        DriveCounter, /*syncCounter*/
        0, /*ExplicitPrecision*/
        1, /*EPAmount*/
        7, /*duration*/
        5, /*initOffset*/
        2, /*finalDelay*/
        SCalarm2, /*callbackAlarm*/
        expiryPoints_1, /*expiryPoints*/
        taskArray_1, /*taskArray*/
        NULL, /*eventArray*/
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


/* Expirypoint Callbackfunctions */
/* Todo: Modify it to a private function */
// DeclareCallback(ExpiryPointCallbackFuncA)
// {
    
//     ScheduleTableType ScheduleTableID = ScheduleTableA;
//     uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
//     CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

//     CounterConstType *CounterConst = SystemObjects[CoreID]->CounterConst;
//     ScheduleTableVarType *ScheduleTableVar = SystemObjects[CoreID]->ScheduleTableVar; 
//     ScheduleTableConstType *ScheduleTableConst = SystemObjects[CoreID]->ScheduleTableConst;
//     CounterVarType *CounterVar = SystemObjects[CoreID]->CounterVar; 
//     uint32 epIndex = ScheduleTableVar[ScheduleTableIndex].currentEPIndex;
//     uint32 i = 0; // temp variable
//     TickType delay = 0; // next expiry time - current time 
//     TickType Value = CounterVar[ScheduleTableConst[ScheduleTableID].syncCounter].currentCounts;
//     // If the current expiry point is the dummy expiry point 
//     // Dummy expiry point is to stop the schedule table and start the next schedule table
//     if(epIndex == ScheduleTableConst[ScheduleTableID].EPAmount)
//     {
        
//         ScheduleTableType nextScheduleTable = ScheduleTableVar[ScheduleTableID].next;
//         uint16 ScheduleTableIndexnext = nextScheduleTable & 0xffff;
//         // If next == SCHEDULETABLE_COUNT, this mean that don't have next schedule table.
//         if(ScheduleTableIndexnext >= SystemObjects[_CoreID]->scheduletableCount)
//         {
//             ScheduleTableVar[ScheduleTableID].status = SCHEDULETABLE_STOPPED;
//             return;
//         }
//         else
//         {
//             // set nxet schedule table

//             if(ScheduleTableConst[ScheduleTableID].syncStrategy == EXPLICIT && ScheduleTableVar[ScheduleTableID].status != SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
//             {
//                 delay = CounterConst[ScheduleTableConst[ScheduleTableID].syncCounter].maxAllowedValue + 1 - Value + ScheduleTableVar[nextScheduleTable].initOffset;
//             }
//             else
//             {
//                 ScheduleTableVar[ScheduleTableID].status = SCHEDULETABLE_STOPPED;
//                 if(ScheduleTableConst[ScheduleTableID].syncStrategy == NONE)
//                 {
//                     ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING;
//                 }
//                 else
//                 {
//                     ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
//                 }
//                 delay = ScheduleTableVar[ScheduleTableIndexnext].initOffset;
//             }
//             ScheduleTableVar[ScheduleTableID].currentEPIndex = 0;
//             ScheduleTableVar[ScheduleTableID].deviation = 0;
//             SetRelAlarm(ScheduleTableConst[ScheduleTableIndexnext].callbackAlarm, delay, 0);
//             return;
//         }
//     }

//     // Expiry point do something
//     // activate task and set event
//     for(i=expiryPoints_0[epIndex].taskStart; i<expiryPoints_0[epIndex].taskEnd; ++i)
//     {
//         ActivateTask(taskArray_0[i]);
//     }
//     for(i=expiryPoints_0[epIndex].eventStart; i<expiryPoints_0[epIndex].eventEnd; ++i)
//     {
//         EventSetting event = eventArray_0[i];
//         SetEvent(event.TaskID, event.Mask);
//     }
//     // if current expiry point is last point, we add a dummy expiry point to stop schedule table
//     if(epIndex == ScheduleTableConst[ScheduleTableIndex].EPAmount-1)
//     {
//         delay = ScheduleTableVar[ScheduleTableIndex].finalDelay;
//     }
//     else
//     {
//         delay = expiryPoints_0[epIndex+1].offset - expiryPoints_0[epIndex].offset;
//     }
//     // why need adjust ?
//     if(ScheduleTableVar[ScheduleTableIndex].deviation != 0)
//     {
//         delay = AdjustExpiryPoint(ScheduleTableID);
//     }
//     // After adjusting, the Schedule tabel that is EXPLICIT will change the status to SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS 
//     else if(ScheduleTableConst[ScheduleTableIndex].syncStrategy == EXPLICIT)
//     {
//         ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
//     }
//     ScheduleTableVar[ScheduleTableIndex].currentEPIndex++;

//     SetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, delay, 0);
// }

// DeclareCallback(ExpiryPointCallbackFuncB)
// {
    
//     ScheduleTableType ScheduleTableID = ScheduleTableB;
//     uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
//     CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

//     CounterConstType *CounterConst = SystemObjects[CoreID]->CounterConst;
//     ScheduleTableVarType *ScheduleTableVar = SystemObjects[CoreID]->ScheduleTableVar; 
//     ScheduleTableConstType *ScheduleTableConst = SystemObjects[CoreID]->ScheduleTableConst;
//     CounterVarType *CounterVar = SystemObjects[CoreID]->CounterVar; 
//     uint32 epIndex = ScheduleTableVar[ScheduleTableIndex].currentEPIndex;
//     uint32 i = 0; // temp variable
//     TickType delay = 0; // next expiry time - current time 
//     TickType Value = CounterVar[ScheduleTableConst[ScheduleTableID].syncCounter].currentCounts;
//     // If the current expiry point is the dummy expiry point 
//     // Dummy expiry point is to stop the schedule table and start the next schedule table
//     if(epIndex == ScheduleTableConst[ScheduleTableID].EPAmount)
//     {
//         ScheduleTableType nextScheduleTable = ScheduleTableVar[ScheduleTableID].next;
//         uint16 ScheduleTableIndexnext = nextScheduleTable & 0xffff;       
//         // If next == SCHEDULETABLE_COUNT, this mean that don't have next schedule table.
//         if(ScheduleTableIndexnext >= SystemObjects[_CoreID]->scheduletableCount)
//         {
//             ScheduleTableVar[ScheduleTableID].status = SCHEDULETABLE_STOPPED;
//             return;
//         }
//         else
//         {
//             // set nxet schedule table

//             if(ScheduleTableConst[ScheduleTableID].syncStrategy == EXPLICIT && ScheduleTableVar[ScheduleTableID].status != SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
//             {
//                 delay = CounterConst[ScheduleTableConst[ScheduleTableID].syncCounter].maxAllowedValue + 1 - Value + ScheduleTableVar[nextScheduleTable].initOffset;
//             }
//             else
//             {
//                 ScheduleTableVar[ScheduleTableID].status = SCHEDULETABLE_STOPPED;
//                 if(ScheduleTableConst[ScheduleTableID].syncStrategy == NONE)
//                 {
//                     ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING;
//                 }
//                 else
//                 {
//                     ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
//                 }
//                 delay = ScheduleTableVar[ScheduleTableIndexnext].initOffset;
//             }
//             ScheduleTableVar[ScheduleTableID].currentEPIndex = 0;
//             ScheduleTableVar[ScheduleTableID].deviation = 0;
//             SetRelAlarm(ScheduleTableConst[ScheduleTableIndexnext].callbackAlarm, delay, 0);
//             return;
//         }
//     }

//     // Expiry point do something
//     // activate task and set event
//     for(i=expiryPoints_1[epIndex].taskStart; i<expiryPoints_1[epIndex].taskEnd; ++i)
//     {
//         ActivateTask(taskArray_1[i]);
//     }
//     for(i=expiryPoints_1[epIndex].eventStart; i<expiryPoints_1[epIndex].eventEnd; ++i)
//     {
//         EventSetting event = eventArray_1[i];
//         SetEvent(event.TaskID, event.Mask);
//     }
//     // if current expiry point is last point, we add a dummy expiry point to stop schedule table
//     if(epIndex == ScheduleTableConst[ScheduleTableIndex].EPAmount-1)
//     {
//         delay = ScheduleTableVar[ScheduleTableIndex].finalDelay;
//     }
//     else
//     {
//         delay = expiryPoints_1[epIndex+1].offset - expiryPoints_1[epIndex].offset;
//     }
//     // why need adjust ?
//     if(ScheduleTableVar[ScheduleTableIndex].deviation != 0)
//     {
//         delay = AdjustExpiryPoint(ScheduleTableID);
//     }
//     // After adjusting, the Schedule tabel that is EXPLICIT will change the status to SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS 
//     else if(ScheduleTableConst[ScheduleTableIndex].syncStrategy == EXPLICIT)
//     {
//         ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
//     }
//     ScheduleTableVar[ScheduleTableIndex].currentEPIndex++;

//     SetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, delay, 0);
// }

/* ExpiryPoint structure */
/* for ScheduleTable3 */
ExpiryPointType expiryPoints_3[EXPIRYPOINT_COUNT_3] = {
    {
        5, /*offset*/
        0, /*task start*/
        1, /*task end*/
        0, /*event start*/
        0, /*event end*/
        0, /*maxShorten*/
        0, /*maxLengthen*/
        NULL /*next*/
    }
};

/* Task and Event Array for expiryPoints_0 */
TaskType taskArray_3[2] = {
    T12
};
EventSetting eventArray_3[1] = {
    {
        T03, 
        event1
    }
};



const ScheduleTableConstType ScheduleTableConst_core1[SCHEDULETABLE_COUNT_CORE1] = {
    {
        NONE, /*syncStrategy*/
        FALSE, /*repeating*/
        counter1, /*counter*/
        DriveCounter, /*syncCounter*/
        0, /*ExplicitPrecision*/
        1, /*EPAmount*/
        7, /*duration*/
        5, /*initOffset*/
        2, /*finalDelay*/
        SCalarm3, /*callbackAlarm*/
        expiryPoints_3, /*expiryPoints*/
        taskArray_3, /*taskArray*/
        eventArray_3 /*eventArray*/
    }
};

ScheduleTableVarType ScheduleTableVar_core1[SCHEDULETABLE_COUNT_CORE1] = {
    {
        SCHEDULETABLE_STOPPED, /*status*/
        0, /*deviation*/
        0, /*currentEPIndex*/
        SCHEDULETABLE_COUNT_CORE1 /*next*/
    }
};
// DeclareCallback(ExpiryPointCallbackFuncC){
//     return;
// }

// DeclareCallback(ExpiryPointCallbackFuncC)
// {
    
//     ScheduleTableType ScheduleTableID = scheduletable3;
//     uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
//     CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

//     CounterConstType *CounterConst = SystemObjects[CoreID]->CounterConst;
//     ScheduleTableVarType *ScheduleTableVar = SystemObjects[CoreID]->ScheduleTableVar; 
//     ScheduleTableConstType *ScheduleTableConst = SystemObjects[CoreID]->ScheduleTableConst;
//     CounterVarType *CounterVar = SystemObjects[CoreID]->CounterVar; 
//     uint32 epIndex = ScheduleTableVar[ScheduleTableIndex].currentEPIndex;
//     uint32 i = 0; // temp variable
//     TickType delay = 0; // next expiry time - current time 
//     TickType Value = CounterVar[ScheduleTableConst[ScheduleTableID].syncCounter].currentCounts;
//     // If the current expiry point is the dummy expiry point 
//     // Dummy expiry point is to stop the schedule table and start the next schedule table
//     if(epIndex == ScheduleTableConst[ScheduleTableID].EPAmount)
//     {
//         ScheduleTableType nextScheduleTable = ScheduleTableVar[ScheduleTableID].next;
//         uint16 ScheduleTableIndexnext = nextScheduleTable & 0xffff;       
//         // If next == SCHEDULETABLE_COUNT, this mean that don't have next schedule table.
//         if(ScheduleTableIndexnext >= SystemObjects[_CoreID]->scheduletableCount)
//         {
//             ScheduleTableVar[ScheduleTableID].status = SCHEDULETABLE_STOPPED;
//             return;
//         }
//         else
//         {
//             // set nxet schedule table

//             if(ScheduleTableConst[ScheduleTableID].syncStrategy == EXPLICIT && ScheduleTableVar[ScheduleTableID].status != SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
//             {
//                 delay = CounterConst[ScheduleTableConst[ScheduleTableID].syncCounter].maxAllowedValue + 1 - Value + ScheduleTableVar[nextScheduleTable].initOffset;
//             }
//             else
//             {
//                 ScheduleTableVar[ScheduleTableID].status = SCHEDULETABLE_STOPPED;
//                 if(ScheduleTableConst[ScheduleTableID].syncStrategy == NONE)
//                 {
//                     ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING;
//                 }
//                 else
//                 {
//                     ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
//                 }
//                 delay = ScheduleTableVar[ScheduleTableIndexnext].initOffset;
//             }
//             ScheduleTableVar[ScheduleTableID].currentEPIndex = 0;
//             ScheduleTableVar[ScheduleTableID].deviation = 0;
//             SetRelAlarm(ScheduleTableConst[ScheduleTableIndexnext].callbackAlarm, delay, 0);
//             return;
//         }
//     }

//     // Expiry point do something
//     // activate task and set event
//     for(i=expiryPoints_3[epIndex].taskStart; i<expiryPoints_3[epIndex].taskEnd; ++i)
//     {
//         ActivateTask(taskArray_1[i]);
//     }
//     for(i=expiryPoints_3[epIndex].eventStart; i<expiryPoints_3[epIndex].eventEnd; ++i)
//     {
//         EventSetting event = eventArray_3[i];
//         SetEvent(event.TaskID, event.Mask);
//     }
//     // if current expiry point is last point, we add a dummy expiry point to stop schedule table
//     if(epIndex == ScheduleTableConst[ScheduleTableIndex].EPAmount-1)
//     {
//         delay = ScheduleTableVar[ScheduleTableIndex].finalDelay;
//     }
//     else
//     {
//         delay = expiryPoints_1[epIndex+1].offset - expiryPoints_1[epIndex].offset;
//     }
//     // why need adjust ?
//     if(ScheduleTableVar[ScheduleTableIndex].deviation != 0)
//     {
//         delay = AdjustExpiryPoint(ScheduleTableID);
//     }
//     // After adjusting, the Schedule tabel that is EXPLICIT will change the status to SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS 
//     else if(ScheduleTableConst[ScheduleTableIndex].syncStrategy == EXPLICIT)
//     {
//         ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
//     }
//     ScheduleTableVar[ScheduleTableIndex].currentEPIndex++;

//     SetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, delay, 0);
// }

ScheduleTableAutosarType ScheduleTableAutosar_core0[SCHEDULETABLE_COUNT_CORE0] = {
    /* ScheduleTable scheduletable1 */
    {
        app_lion,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) |  (1 << app4) 
    },
    /* ScheduleTable scheduletable2 */
    {
        app_lion,
        0 | (1 << app_lion) 
    }   
};

ScheduleTableAutosarType ScheduleTableAutosar_core1[SCHEDULETABLE_COUNT_CORE1] = {
    /* ScheduleTable scheduletable1 */
    {
        app2,
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) |  (1 << app4)  
    }  
};

// DeclareCallback(ExpiryPointCallbackFuncC)
// {
    
//     ScheduleTableType ScheduleTableID = scheduletable3;
//     uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
//     CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

//     CounterConstType *CounterConst = SystemObjects[CoreID]->CounterConst;
//     ScheduleTableVarType *ScheduleTableVar = SystemObjects[CoreID]->ScheduleTableVar; 
//     ScheduleTableConstType *ScheduleTableConst = SystemObjects[CoreID]->ScheduleTableConst;
//     CounterVarType *CounterVar = SystemObjects[CoreID]->CounterVar; 
//     uint32 epIndex = ScheduleTableVar[ScheduleTableIndex].currentEPIndex;
//     uint32 i = 0; // temp variable
//     TickType delay = 0; // next expiry time - current time 
//     TickType Value = CounterVar[ScheduleTableConst[ScheduleTableID].syncCounter].currentCounts;
//     // If the current expiry point is the dummy expiry point 
//     // Dummy expiry point is to stop the schedule table and start the next schedule table
//     if(epIndex == ScheduleTableConst[ScheduleTableID].EPAmount)
//     {
//         ScheduleTableType nextScheduleTable = ScheduleTableVar[ScheduleTableID].next;
//         uint16 ScheduleTableIndexnext = nextScheduleTable & 0xffff;       
//         // If next == SCHEDULETABLE_COUNT, this mean that don't have next schedule table.
//         if(ScheduleTableIndexnext >= SystemObjects[_CoreID]->scheduletableCount)
//         {
//             ScheduleTableVar[ScheduleTableID].status = SCHEDULETABLE_STOPPED;
//             return;
//         }
//         else
//         {
//             // set nxet schedule table

//             if(ScheduleTableConst[ScheduleTableID].syncStrategy == EXPLICIT && ScheduleTableVar[ScheduleTableID].status != SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
//             {
//                 delay = CounterConst[ScheduleTableConst[ScheduleTableID].syncCounter].maxAllowedValue + 1 - Value + ScheduleTableVar[nextScheduleTable].initOffset;
//             }
//             else
//             {
//                 ScheduleTableVar[ScheduleTableID].status = SCHEDULETABLE_STOPPED;
//                 if(ScheduleTableConst[ScheduleTableID].syncStrategy == NONE)
//                 {
//                     ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING;
//                 }
//                 else
//                 {
//                     ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
//                 }
//                 delay = ScheduleTableVar[ScheduleTableIndexnext].initOffset;
//             }
//             ScheduleTableVar[ScheduleTableID].currentEPIndex = 0;
//             ScheduleTableVar[ScheduleTableID].deviation = 0;
//             SetRelAlarm(ScheduleTableConst[ScheduleTableIndexnext].callbackAlarm, delay, 0);
//             return;
//         }
//     }

//     // Expiry point do something
//     // activate task and set event
//     for(i=expiryPoints_3[epIndex].taskStart; i<expiryPoints_3[epIndex].taskEnd; ++i)
//     {
//         ActivateTask(taskArray_1[i]);
//     }
//     for(i=expiryPoints_3[epIndex].eventStart; i<expiryPoints_3[epIndex].eventEnd; ++i)
//     {
//         EventSetting event = eventArray_3[i];
//         SetEvent(event.TaskID, event.Mask);
//     }
//     // if current expiry point is last point, we add a dummy expiry point to stop schedule table
//     if(epIndex == ScheduleTableConst[ScheduleTableIndex].EPAmount-1)
//     {
//         delay = ScheduleTableVar[ScheduleTableIndex].finalDelay;
//     }
//     else
//     {
//         delay = expiryPoints_1[epIndex+1].offset - expiryPoints_1[epIndex].offset;
//     }
//     // why need adjust ?
//     if(ScheduleTableVar[ScheduleTableIndex].deviation != 0)
//     {
//         delay = AdjustExpiryPoint(ScheduleTableID);
//     }
//     // After adjusting, the Schedule tabel that is EXPLICIT will change the status to SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS 
//     else if(ScheduleTableConst[ScheduleTableIndex].syncStrategy == EXPLICIT)
//     {
//         ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
//     }
//     ScheduleTableVar[ScheduleTableIndex].currentEPIndex++;

//     SetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, delay, 0);
// }



// const AutoStartScheduleTableType AutoStartScheduleTabl_core0[SCHEDULETABLE_AUTOSTART_COUNT_CORE0] = {
//     // {
//     //     AppMode1, /* application mode */
//     //     ABSOLUTE,   /* autoStartType */
//     //     0,     /* startValue */   
//     //     scheduletable1  /* id */
//     // }
// };

#pragma section