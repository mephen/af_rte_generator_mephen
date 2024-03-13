#ifndef TIMINGPROT_CFG_H
#define TIMINGPROT_CFG_H

#include "typedefine.h"
#include "task_Cfg.h"
#include "resource_Cfg.h"
#include "os_Cfg.h"

extern TimingProtCounterType TaskExecutingCounter_core0[TASK_OBJECTS_COUNT_CORE0];
extern TimingProtCounterType TaskArrivalCounter_core0[TASK_OBJECTS_COUNT_CORE0];
extern TimingProtCounterType ResourceTimingCounter_core0[RESOURCES_COUNT_CORE0];
extern TimingProtCounterType InterruptTimingCounter_core0[3];

extern TimingProtCounterType TaskExecutingCounter_core1[TASK_OBJECTS_COUNT_CORE1];
extern TimingProtCounterType TaskArrivalCounter_core1[TASK_OBJECTS_COUNT_CORE1];
extern TimingProtCounterType ResourceTimingCounter_core1[RESOURCES_COUNT_CORE1];
extern TimingProtCounterType InterruptTimingCounter_core1[3];

extern TimingProtCounterType *TimingCounterList[OsNumberOfCores];
extern SystemTimingCounterType SystemTimingCounter[OsNumberOfCores];
#endif
