#include "os.h"
#include "system.h"
#include "scheduler.h"
#include "spinlock.h"
#include "lock.h"
#include "systemcall.h"
#include "os_Cfg.h"
#include "spinlock_Cfg.h"
#include "resource.h"
#include "resource_Cfg.h"
#include "application.h"
#include "memprot.h"

/* SWS_Os_00648 */

/* SWS_Os_00686 */
StatusType GetSpinlock(SpinlockIdType SpinlockId)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETSPINLOCK;
    para.para1    = (uint32)SpinlockId;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00695 */
StatusType ReleaseSpinlock(SpinlockIdType SpinlockId)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_RELEASESPINLOCK;
    para.para1    = (uint32)SpinlockId;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00703 */
StatusType TryToGetSpinlock(SpinlockIdType SpinlockId, TryToGetSpinlockType* Success)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_TRYTOGETSPINLOCK;
    para.para1    = SpinlockId;
    para.para2    = (uint32)Success;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}



StatusType SysGetSpinlock(SpinlockIdType SpinlockId)
{

    StatusType result = E_OK;
    uint8 *byte = &SpinLockList[SpinlockId];
    uint8 bit = 0;
    TaskType TaskID = (CURRENTTASK.currentID);
    uint16 TaskIndex = TaskID & 0xffff;
    TaskAutosarType *TaskAutosar = &(SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex]);

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }
    if (result == E_OK && SpinlockId >= SPINLOCKS_COUNT)
    {
        result = E_OS_ID; /* SWS_Os_00689 */
    }
    else if (result == E_OK && !(SpinlockConst[SpinlockId].applicationsMask & (1 << TaskAutosar->owner)))
    {
        result = E_OS_ACCESS; /* SWS_Os_00692 */
    }
    else if (result == E_OK && SpinlockVar[SpinlockId].ownerCoreID == _CoreID)
    {
        result = E_OS_INTERFERENCE_DEADLOCK; /* SWS_Os_00658, SWS_Os_00659, SWS_Os_00690 */
    }
    else if (result == E_OK && TaskAutosar->lastSpinlock < SpinlockId)
    {
        result = E_OS_NESTING_DEADLOCK; /* SWS_Os_00661, SWS_Os_00691 */
    }

    if (result == E_OK) /* SWS_Os_00688 */
    {
        switch (SpinlockConst[SpinlockId].lockMethod)
        {
        case LOCK_ALL_INTERRUPTS:
            kernelDisableAllISR();
            break;
        case LOCK_CAT2_INTERRUPTS:
            kernelDisableISR2();
            break;
        case LOCK_WITH_RES_SCHEDULER:
            SysGetResource(RES_SCHEDULER);
            break;
        case LOCK_NOTHING:
        default:
            break;
        }
        
        GetLock(byte, bit); /* SWS_Os_00687 */
        SpinlockVar[SpinlockId].ownerCoreID = _CoreID;
        SpinlockVar[SpinlockId].ownerTaskID = TaskID;
        // SpinlockVar[SpinlockId].preSpinlock = TaskAutosar->lastSpinlock;
        SpinlockVar[SpinlockId].preLock.objectId = TaskAutosar->lastLock.objectId;
        SpinlockVar[SpinlockId].preLock.objectType = TaskAutosar->lastLock.objectType;

        TaskAutosar->lastSpinlock = SpinlockId;
        TaskAutosar->lastLock.objectType = OBJECT_SPINLOCK;
        TaskAutosar->lastLock.objectId = SpinlockId;
    }



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
StatusType SysReleaseSpinlock(SpinlockIdType SpinlockId)
{
    StatusType result = E_OK;
    uint8 *byte = &SpinLockList[SpinlockId];
    uint8 bit = 0;
    TaskType TaskID = (CURRENTTASK.currentID);
    uint16 TaskIndex = TaskID & 0xffff;
    TaskAutosarType *TaskAutosar = &(SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex]);



    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    } 
    if (result == E_OK && SpinlockId >= SPINLOCKS_COUNT)
    {
        result = E_OS_ID; /* SWS_Os_00698 */
    }
    else if (result == E_OK && TaskID != SpinlockVar[SpinlockId].ownerTaskID)
    {
        result = E_OS_STATE; /* SWS_Os_00699 */
    }
    else if (result == E_OK && !(SpinlockConst[SpinlockId].applicationsMask & (1 << TaskAutosar->owner)))
    {
        result = E_OS_ACCESS; /* SWS_Os_00700 */
    }
    else if (result == E_OK && TaskAutosar->lastLock.objectType != OBJECT_SPINLOCK || TaskAutosar->lastLock.objectId != SpinlockId)
    {
        result = E_OS_NOFUNC; /* SWS_Os_00701 */
    }
    if (result == E_OK) /* SWS_Os_00697 */
    {
        switch (SpinlockConst[SpinlockId].lockMethod)
        {
        case LOCK_ALL_INTERRUPTS:
            kernelEnableAllISR();
            break;
        case LOCK_CAT2_INTERRUPTS:
            kernelEnableISR2();
            break;
        case LOCK_WITH_RES_SCHEDULER:
            SysReleaseResource(RES_SCHEDULER);
            break;
        default:
            break;
        }
        ReleaseLock(byte, bit); /* SWS_Os_00696 */
        TaskAutosar->lastSpinlock = SpinlockVar[SpinlockId].preLock.objectId;
        TaskAutosar->lastLock.objectId = SpinlockVar[SpinlockId].preLock.objectId;
        TaskAutosar->lastLock.objectType = SpinlockVar[SpinlockId].preLock.objectType;

        SpinlockVar[SpinlockId].ownerCoreID = OS_CORE_ID_INVALID;
        SpinlockVar[SpinlockId].ownerTaskID = INVALID_TASK_ID;
        SpinlockVar[SpinlockId].preLock.objectType = OBJECT_INVALID;
    }
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

StatusType SysTryToGetSpinlock(SpinlockIdType SpinlockId, TryToGetSpinlockType* Success)
{
    StatusType result = E_OK;
    uint8 *byte = &SpinLockList[SpinlockId];
    uint8 bit = 0;
    TaskType TaskID = (CURRENTTASK.currentID);
    uint16 TaskIndex = TaskID & 0xffff;
    TaskAutosarType *TaskAutosar = &(SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex]);



    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }
    if (SpinlockId >= SPINLOCKS_COUNT)
    {
        result = E_OS_ID; /* SWS_Os_00707 */
    }
    else if (!(SpinlockConst[SpinlockId].applicationsMask & (1 << TaskAutosar->owner)))
    {
        result = E_OS_ACCESS; /* SWS_Os_00710 */
    }
    else if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(Success))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    else if (SpinlockVar[SpinlockId].ownerCoreID == _CoreID)
    {
        result = E_OS_INTERFERENCE_DEADLOCK; /* SWS_Os_00658, SWS_Os_00659, SWS_Os_00708 */
    }
    else if (TaskAutosar->lastSpinlock < SpinlockId)
    {
        result = E_OS_NESTING_DEADLOCK; /* SWS_Os_00661, SWS_Os_00709 */
    }

    if (result == E_OK)/* SWS_Os_00706 */
    {
        TryLock(byte, bit, (uint32 *)Success); /* SWS_Os_00704, SWS_Os_00705 */
        if (*Success == TRYTOGETSPINLOCK_SUCCESS)
        {
            switch (SpinlockConst[SpinlockId].lockMethod)
            {
            case LOCK_ALL_INTERRUPTS:
                kernelEnableAllISR();
                break;
            case LOCK_CAT2_INTERRUPTS:
                kernelEnableISR2();
                break;
            case LOCK_WITH_RES_SCHEDULER:
                SysGetResource(RES_SCHEDULER);
                break;
            default:
                break;
            }
            SpinlockVar[SpinlockId].ownerCoreID = _CoreID;
            SpinlockVar[SpinlockId].ownerTaskID = TaskID;
            // SpinlockVar[SpinlockId].preSpinlock = TaskAutosar->lastSpinlock;
            SpinlockVar[SpinlockId].preLock.objectId = TaskAutosar->lastLock.objectId;
            SpinlockVar[SpinlockId].preLock.objectType = TaskAutosar->lastLock.objectType;

            TaskAutosar->lastSpinlock = SpinlockId;
            TaskAutosar->lastLock.objectType = OBJECT_SPINLOCK;
            TaskAutosar->lastLock.objectId = SpinlockId;
        }
    }



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