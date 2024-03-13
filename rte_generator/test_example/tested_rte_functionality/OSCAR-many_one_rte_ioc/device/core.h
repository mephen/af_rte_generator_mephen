#ifndef __CORE_H__
#define __CORE_H__

#include "typedefine.h"

void _StartCore(CoreIdType CoreID);
CoreIdType GetPhyCoreID(void);
void InterruptToCore(CoreIdType CoreID);
//TaskType GetIdleID(void); /* not in use*/

#endif // __CORE_H__
