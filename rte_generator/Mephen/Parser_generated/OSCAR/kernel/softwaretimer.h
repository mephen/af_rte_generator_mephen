#ifndef SOFTWARETIMER_H
#define SOFTWARETIMER_H

#include "os.h"
#include "typedefine.h"
#include "os_Cfg.h"


/* System service */
StatusType GetSoftwareTimerValue (SoftwareTimerType, TickRefType);
StatusType TickToMs(SoftwareTimerType,SoftwareTimerTickType,uint32*);

StatusType SysGetSoftwareTimerValue (SoftwareTimerType, TickRefType);
StatusType SysTickToMs(SoftwareTimerType,SoftwareTimerTickType,uint32*);


/* Internal function */
void TimerTick(void);

#endif /* #ifndef SOFTWARETIMER_H */