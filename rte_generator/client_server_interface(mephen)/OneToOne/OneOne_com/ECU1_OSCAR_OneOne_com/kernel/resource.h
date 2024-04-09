#ifndef RESOURCE_H
#define RESOURCE_H

#include "typedefine.h"
#include "os.h"
#include "resource_Cfg.h"

StatusType GetResource(ResourceType ResID);
StatusType ReleaseResource(ResourceType ResID);
StatusType GetInternalResource(void);
StatusType ReleaseInternalResource(void);

StatusType SysGetResource(ResourceType ResID);
StatusType SysReleaseResource(ResourceType ResID);




#endif /* #ifndef RESOURCE_H */