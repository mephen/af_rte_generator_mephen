#ifndef COUNTER_H
#define COUNTER_H

#include "os.h"
#include "typedefine.h"
#include "system.h"
#include "alarm_Cfg.h"
#include "counter_Cfg.h"
#include "ScheduleTable.h"

StatusType IncrementCounter(CounterType);
StatusType GetCounterValue (CounterType, TickRefType);
StatusType GetElapsedValue (CounterType, TickRefType, TickRefType);

StatusType  SysIncrementCounter(CounterType CounterID);
StatusType  SysGetCounterValue (CounterType, TickRefType);
StatusType  SysGetElapsedValue (CounterType, TickRefType, TickRefType);


/* Internal function */
// void CounterTick(void);
void CounterTick(CounterType*, uint32);
#endif /* #ifndef COUNTER_H */