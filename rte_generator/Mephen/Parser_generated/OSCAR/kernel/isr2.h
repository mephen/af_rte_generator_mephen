#ifndef ISR2_H
#define ISR2_H

#include "typedefine.h"


/* System service */
ISRType GetISRID( void );
StatusType ClearPendingInterrupt(ISRType ISRID);
StatusType EnableInterruptSource(ISRType ISRID, boolean ClearPending);
StatusType DisableInterruptSource(ISRType ISRID);

void ActivateISR2(TaskType TaskID);
StatusType TerminateISR2(void);

ISRType SysGetISRID( void );
StatusType SysClearPendingInterrupt(ISRType ISRID);
StatusType SysEnableInterruptSource(ISRType ISRID, boolean ClearPending);
StatusType SysDisableInterruptSource(ISRType ISRID);


#endif /* #ifndef ISR2_H */