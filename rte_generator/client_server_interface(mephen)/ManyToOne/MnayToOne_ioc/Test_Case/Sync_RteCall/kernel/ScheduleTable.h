#ifndef SCHEDULETABLE_H
#define SCHEDULETABLE_H

#include "typedefine.h"

/* System service */
StatusType StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
StatusType StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
StatusType StopScheduleTable(ScheduleTableType ScheduleTableID);
StatusType NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
StatusType StartScheduleTableSynchron(ScheduleTableType ScheduleTableID);
StatusType SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value);
StatusType SetScheduleTableAsync(ScheduleTableType ScheduleTableID);
StatusType GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);

StatusType SysStartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
StatusType SysStartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
StatusType SysStopScheduleTable(ScheduleTableType ScheduleTableID);
StatusType SysNextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
StatusType SysStartScheduleTableSynchron(ScheduleTableType ScheduleTableID);
StatusType SysSyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value);
StatusType SysSetScheduleTableAsync(ScheduleTableType ScheduleTableID);
StatusType SysGetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);



void SchedulTableCallbackFunction(ScheduleTableType ScheduleTableID);

#endif /* #ifndef SCHEDULETABLE_H */
