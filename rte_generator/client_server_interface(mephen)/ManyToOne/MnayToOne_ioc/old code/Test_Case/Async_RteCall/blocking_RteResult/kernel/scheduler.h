#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task_Cfg.h"
#include "iodefine.h"
#include "typedefine.h"
#include "os.h"
#include "core.h"

/* software interrupt for scheduler context switch */
#define ScheduleKernel()                        \
    do {                                        \
        checkStackMonitorPattern();             \
        if (_CoreID == OS_CORE_ID_0)            \
            ICP0 |= 0x1000;                     \
        else if(_CoreID == OS_CORE_ID_1)        \
            ICP1 |= 0x1000;                     \
    } while (0)


#define DisableScheduler()                  \
    do {                                    \
        if (_CoreID == OS_CORE_ID_0)        \
        {                                   \
            ICP0 |= 0x80;                   \
        }                                   \
        else if (_CoreID == OS_CORE_ID_1)   \
        {                                   \
            ICP1 |= 0x80;                   \
        }                                   \
    } while (0)

#define EnableScheduler()                   \
    do {                                    \
        if (_CoreID == OS_CORE_ID_0)        \
        {                                   \
            ICP0 &= ~0x80;                  \
        }                                   \
        else if (_CoreID == OS_CORE_ID_1)   \
        {                                   \
            ICP1 &= ~0x80;                  \
        }                                   \
    } while (0)




/* System service */
StatusType Schedule(void);
StatusType SysSchedule(void);


/* Task management internal function */
TaskType GetNextTask(void);
void RemoveTask(TaskType TaskID);
void AddReadyHead(TaskType TaskID);
void Scheduler(void);
void RemoveSpecificTask(TaskType TaskID);

void InitReadyList(void);

void SetPSW(ApplicationType ApplID);

// extern CurrentTaskType CurrentTask;
// extern uint32 readyListFlag;

#define CURRENTTASK (*(CurrentTask[_CoreID]))
#define READYLISTFLAG (SystemReadyList[_CoreID]->readyListFlag)
#define READYLIST (SystemReadyList[_CoreID]->ReadyList)
#define READYLISTTAIL (SystemReadyList[_CoreID]->ReadyListTail)

#endif /* SCHEDULER_H */