#ifndef ALARM_H
#define ALARM_H

#include "os.h"
#include "typedefine.h"
#include "../Os_Configure/inc/alarm_Cfg.h"


/* OSEK System Service */
StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);
StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick);
StatusType SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);
StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);
StatusType CancelAlarm(AlarmType AlarmID);

/* Alarm management internal function */
void InsertAlarm(AlarmType AlarmID);
void RemoveAlarm(AlarmType AlarmID);

StatusType SysGetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);
StatusType SysGetAlarm(AlarmType AlarmID, TickRefType Tick);
StatusType SysSetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);
StatusType SysSetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);
StatusType SysCancelAlarm(AlarmType AlarmID);



#endif /* #ifndef ALARM_H */