#include "task_Cfg.h"
#include "iodefine.h"
#include "typedefine.h"
#include "os.h"

StatusType SetEvent(TaskType TaskID, EventMaskType Mask);
StatusType ClearEvent(EventMaskType Mask);
StatusType GetEvent(TaskType TaskID, EventMaskRefType Event);
StatusType WaitEvent(EventMaskType Mask);
void SetEventAsyn(TaskType TaskID, EventMaskType Mask); 


StatusType SysSetEvent(TaskType TaskID, EventMaskType Mask);
StatusType SysClearEvent(EventMaskType Mask);
StatusType SysGetEvent(TaskType TaskID, EventMaskRefType Event);
StatusType SysWaitEvent(EventMaskType Mask);
void SysSetEventAsyn(TaskType TaskID, EventMaskType Mask); 