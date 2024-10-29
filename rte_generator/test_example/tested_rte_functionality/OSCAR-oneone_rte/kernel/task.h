#ifndef TASK_H
#define TASK_H

#include "os.h"
#include "task_Cfg.h"

// #define GETTASKVAR()                                    \
//     do{                                                 \
//         TaskVarType *TaskVar;                           \
//         TaskConstType *TaskConst;                       \
//         CoreIdType CoreID;                              \
//         CoreID = (CoreIdType)(TaskID >> 16);            \
//         if(CoreID != GetCoreID())                       \
//         {                                               \
//             /* check access right */                    \
//             /* go to the core */                        \
//             /* wait the api completed */                \
//             return result;                              \
//         }                                               \
//         TaskVar = SystemObjects[CoreID]->TaskVar;       \
//         TaskConst = SystemObjects[CoreID]->TaskConst;   \
//         TaskID = TaskID & 0xffff;                  \
//     } while(0)

/* OSEK System Service */
StatusType ActivateTask(TaskType TaskID);
StatusType TerminateTask(void);
StatusType ChainTask(TaskType TaskID);
StatusType GetTaskID(TaskRefType TaskID);
StatusType GetTaskState(TaskType TaskID, TaskStateRefType state);
void ActivateTaskAsyn(TaskType TaskID);
StatusType ControlIdle(CoreIdType CoreID,IdleModeType IdleMode);


/* Task management internal function */
void InitContext(TaskType TaskID);
void InitTask(TaskType TaskID);
StatusType ActivateTaskInternal(TaskType TaskID);
void TerminateTaskInternal(void);
void AddReady(TaskType TaskID);
void TerminateSpecificTaskbyOS(TaskType TaskID);
void TerminateCurrentTaskbyOS();
void ReleaseAllSpinlock(TaskType TaskID);
void ReleaseAllResource(TaskType TaskID);
void ReleaseAllLockObject(TaskType TaskID);
void TerminateTaskObjByOS();

/*  */
StatusType SysActivateTask(TaskType TaskID);
StatusType SysTerminateTask(void);
StatusType SysChainTask(TaskType TaskID);
StatusType SysGetTaskID(TaskRefType TaskID);
StatusType SysGetTaskState(TaskType TaskID, TaskStateRefType state);
void SysActivateTaskAsyn(TaskType TaskID);
StatusType SysControlIdle(CoreIdType CoreID,IdleModeType IdleMode);
void SysTerminateTaskObjByOS();

TaskType GetIdleTaskID(void);
TaskType GetSysTaskID(void);
void DeSysTaskActionQueue(SysTaskInformationType *info);
void EnSysTaskActionQueue(SysTaskInformationType info);

/* IdleTask for kernel scheduling */
//void MILKSHOP_TASK_IdleTask(void);
TASK(IdleTask);
TASK(SysTask);
#endif /* #ifndef TASK_H */
