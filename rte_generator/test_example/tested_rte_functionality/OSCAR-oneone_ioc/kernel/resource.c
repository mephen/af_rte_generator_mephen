#include "os.h"
#include "resource.h"
#include "timingprot.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "scheduler.h"
#include "system.h"
#include "systemcall.h"
#include "timingprot_Cfg.h"
#include "application.h"

StatusType GetResource(ResourceType ResID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETRESOURCE;
    para.para1    = ResID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType ReleaseResource(ResourceType ResID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_RELEASERESOURCE;
    para.para1    = ResID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType GetInternalResource(void)
{
#if (INTERNAL_RESOURCES_COUNT > 0)
    InternalResourceVarType *Resource = CURRENTTASK.CurrentVar->InternalResource;
    /* TODO: implement error checking mechanism */
    if (Resource != NULL && Resource->owner == 0)
    {
        Resource->owner = CURRENTTASK.currentID;
        Resource->previousPriority = CURRENTTASK.CurrentVar->priority;
        CURRENTTASK.CurrentVar->priority = *(Resource->ceilingPriority);
    }
#endif /* (INTERNAL_RESOURCES_COUNT > 0) */
    return E_OK;
}

StatusType ReleaseInternalResource(void)
{
#if (INTERNAL_RESOURCES_COUNT > 0)
    InternalResourceVarType *Resource = CURRENTTASK.CurrentVar->InternalResource;
    /* TODO: implement error checking mechanism */
    if (Resource != NULL && Resource->owner == CURRENTTASK.currentID)
    {
        Resource->owner = 0;
        CURRENTTASK.CurrentVar->priority = Resource->previousPriority;
    }
#endif /* (INTERNAL_RESOURCES_COUNT > 0) */
    return E_OK;
}

StatusType SysGetResource(ResourceType ResID){
#if RESOURCES_COUNT > 0
    StatusType result = E_OK;
    CoreIdType CoreID = ResID >> 16;
    uint16 ResIndex = ResID & 0xffff;
    ResourceVarType *Resource = NULL;
    ResourceVarType *ResourceVar = SystemObjects[_CoreID]->ResourceVar;
    HardwareTickType Budget;

    TaskType TaskID = (CURRENTTASK.currentID);
    uint16 TaskIndex = TaskID & 0xffff;
    TaskAutosarType *TaskAutosar = &(SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex]);



    if(USE_RES_SCHEDULER == ENABLE && ResID == RES_SCHEDULER){
        ResID = (_CoreID << 4);
        CoreID = ResID & 0xffff;
    }

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }
    if (result == E_OK && ResIndex >= SystemObjects[_CoreID]->resourcesCount)
    {
        result = E_OS_ID;
    }
    if (CoreID != _CoreID)
    {
        result = E_OS_SYS_COREID;
    }
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ResourceAutosar[ResIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    if(result ==E_OK)
    {
        Resource = &ResourceVar[ResIndex];
        if ((result == E_OK) &&
            ((Resource->owner != 0) || (CURRENTTASK.CurrentConst->staticPriority > *(Resource->ceilingPriority)) ||
             ((CURRENTTASK.CurrentConst->resourcesMask & (1 << ResIndex)) == 0)))
        {
            result = E_OS_ACCESS;
        }
    }


    if (result == E_OK)
    {
        ResourceVar[ResIndex].owner = CURRENTTASK.currentID;
        ResourceVar[ResIndex].prelock.objectId = TaskAutosar->lastLock.objectId;
        ResourceVar[ResIndex].prelock.objectType = TaskAutosar->lastLock.objectType;
        Resource->previousPriority = CURRENTTASK.CurrentVar->priority;
        if (CURRENTTASK.CurrentVar->priority < *(Resource->ceilingPriority))
        {
            CURRENTTASK.CurrentVar->priority = *(Resource->ceilingPriority);
        }

        TaskAutosar->lastLock.objectType = OBJECT_RESOURCE;
        TaskAutosar->lastLock.objectId = ResID;

        Budget = getBound(CURRENTTASK.currentID, RESLOCKBUDGET, ResID);
        addTimingCounter(&SystemTimingCounter[_CoreID].ResourceTimingCounter[ResIndex], RESLOCKBUDGET, Budget);

        // Resource = &ResourceVar[ResIndex];
        // Resource->owner = CURRENTTASK.currentID;
        // Resource->NextResource = CURRENTTASK.CurrentVar->Resources;
        // CURRENTTASK.CurrentVar->Resources = (void *)Resource;
        // Resource->previousPriority = CURRENTTASK.CurrentVar->priority;
        // if (CURRENTTASK.CurrentVar->priority < *(Resource->ceilingPriority))
        // {
        //     CURRENTTASK.CurrentVar->priority = *(Resource->ceilingPriority);
        // }
        // Budget = getBound(CURRENTTASK.currentID, RESLOCKBUDGET, ResID);
        // addTimingCounter(&SystemTimingCounter[_CoreID].ResourceTimingCounter[ResIndex], RESLOCKBUDGET, Budget);
    }
#endif /* RESOURCES_COUNT > 0 */

#if RESOURCES_COUNT == 0
    StatusType result = E_OS_ID;
#endif

#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (result != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(result);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(result);
        }
#endif
    }
#endif

    return result;
}

StatusType SysReleaseResource(ResourceType ResID){
    #if (RESOURCES_COUNT > 0)
    StatusType result = E_OK;
    ResourceVarType *TargetResource = NULL;
    ResourceVarType *ResourcesHead = NULL;
    ResourceVarType *ResourceVar;
    CoreIdType CoreID = ResID >> 16;
    uint16 ResIndex = ResID & 0xffff;

    TaskType TaskID = (CURRENTTASK.currentID);
    uint16 TaskIndex = TaskID & 0xffff;
    TaskAutosarType *TaskAutosar = &(SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex]);

    ResourceVar = SystemObjects[_CoreID]->ResourceVar;
    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }
    if (result == E_OK && ResIndex >= SystemObjects[_CoreID]->resourcesCount)
    {
        result = E_OS_ID;
    }
    if (CoreID != _CoreID)
    {
        result = E_OS_SYS_COREID;
    }
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ResourceAutosar[ResIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    if((result == E_OK) && (CURRENTTASK.CurrentConst->resourcesMask & (1 << ResIndex)) == 0)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK && (TaskAutosar->lastLock.objectType != OBJECT_RESOURCE || TaskAutosar->lastLock.objectId != ResID))
    {
        result = E_OS_NOFUNC;
    }

    if (result == E_OK)
    {
        TaskAutosar->lastLock.objectId = ResourceVar[ResIndex].prelock.objectId;
        TaskAutosar->lastLock.objectType = ResourceVar[ResIndex].prelock.objectType;
        
        CURRENTTASK.CurrentVar->priority = ResourceVar[ResIndex].previousPriority;
        ResourceVar[ResIndex].prelock.objectType = OBJECT_INVALID;
        ResourceVar[ResIndex].owner = 0;

        resetTimingCounter(&SystemTimingCounter[_CoreID].ResourceTimingCounter[ResIndex]);

        if (CURRENTTASK.CurrentConst->Flags.preemptive == 1)
        {
            ScheduleKernel();
        }
    }
#endif /* (RESOURCES_COUNT > 0) */

#if (RESOURCES_COUNT == 0)
    StatusType result = E_OS_ID;
#endif /* (RESOURCES_COUNT == 0) */

#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (result != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(result);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(result);
        }
#endif
    }
#endif
    
    return result;
}

