#include "typedefine.h"
#include "core.h"
#include "systemcall.h"
#include "memprot.h"
#include "scheduler.h"
#include "os_Cfg.h"
#include "trustedFunc_Cfg.h"
#include "timer.h"
#include "ISRInit.h"
#include "alarm.h"
#include "event.h"
#include "task.h"
#include "counter.h"
#include "application.h"
#include "isr2.h"
#include "resource.h"
#include "spinlock.h"
#include "scheduletable.h"
#include "scheduler.h"
#include "softwaretimer.h"
#include "system.h"
#include "Ioc.h"


#define PSWUM 0x40000000

#pragma section SELF_AREA

SysCallEIRegType syscall_EI_Reg;

#pragma section

#pragma inline_asm SetSupervisor
void SetSupervisor(void)
{
    //EIPSW -> kernelSystemCallEIPSW
    stsr    1, r20
    mov     #_syscall_EI_Reg, r21    ; load kernelSystemCallEIPSW
    st.w    r20, 0[r21]
    mov     PSWUM, r21                      ;**reset PSW.UM bit**
    not     r21, r21                        ;**reset PSW.UM bit**
	and     r21, r20			            ;**reset PSW.UM bit**
	ldsr	r20, 1
}

#pragma inline_asm ResetSupervisor
void ResetSupervisor(void)
{
    //kernelSystemCallEIPSW -> EIPSW
    // stsr    1, r20ll
    // mov     PSWUM, r21       ;**set PSW.UM bit**
	// or      r21, r20			;**set PSW.UM bit**
    mov     #_syscall_EI_Reg, r21    ; load kernelSystemCallEIPSW
    ld.w    0[r21], r20
	ldsr	r20, 1
}

// #pragma inline_asm syscallSaveEIPC
// void syscallSaveEIPC(void)
// {
//     //EIPSW -> kernelSystemCallEIPC
//     stsr    0, r20                          ; load eipc
//     mov     #_kernelSystemCallEIPC, r21     ; load kernelSystemCallEIPC
//     st.w    r20, 0[r21]                     ; save to kernelSystemCallEIPC
// }

// #pragma inline_asm syscallLoadEIPC
// void syscallLoadEIPC(void)
// {
//     //kernelSystemCallEIPC -> EIPSW
//     // stsr    1, r20
//     // mov     PSWUM, r21       ;**set PSW.UM bit**
// 	// or      r21, r20			;**set PSW.UM bit**
//     mov     #_kernelSystemCallEIPC, r21    ; load kernelSystemCallEIPC
//     ld.w    0[r21], r20                    ; load from kernelSystemCallEIPC
// 	ldsr	r20, 0                         ; save to eipc
// }

//***************** vvv future work vvv ******************//

// #pragma inline_asm syscall_save_EIPC_PSW
// void syscall_save_EIPC_PSW (void) {
//     //add           -0x1C, sp
//     // st.w           r6, 12[sp]
//     // st.w           r7, 8[sp]
//     // stsr            0, r6
//     // stsr            1, r7
//     // st.w           r6, 0[sp]
//     // st.w           r6, 4[sp]
//     // ld.w           12[sp], r6
//     // ld.w           8[sp], r7 
// }

// #pragma inline_asm syscall_load_EIPC_PSW
// void syscall_load_EIPC_PSW (void) {
//     // st.w           r6, 12[sp]
//     // st.w           r7, 8[sp]
//     // ldsr            r6, 0
//     // ldsr            r7, 1
//     // ld.w           8[sp], r6
//     // ld.w           12[sp], r7 
//     //add           0x1C, sp
// }

//***************** ^^^ future work ^^^ ******************//

/* syscall interrupt handler below */

#pragma interrupt sysEnterSystemCall(enable = false, callt = false, fpu = false)
void sysEnterSystemCall(void)
{
    DisableMPU();
    EnterCritical();
    if (kernelSystemCallCounter < 0){
            /* this case should NOT happen */
            //kernelSystemCallCounter == 0;
            //innerEnterSystemCall();
    }  
    else if (kernelSystemCallCounter == 0){  
            SetSupervisor();             
    }                                   
    kernelSystemCallCounter++;    
    //syscallSaveEIPC();
    //syscall_save_EIPC_PSW();
}

#pragma interrupt sysExitSystemCall(enable = false, callt = false, fpu = false)
void sysExitSystemCall(void)
{
    //syscall_load_EIPC_PSW();
    //syscallLoadEIPC();
    ResetSupervisor();
    ExitCritical();
    EnableMPU();
}



#pragma inline_asm sysCallSystemService
void sysCallSystemService(void)
{
    syscall 3
}


#pragma interrupt sysCallSystemServiceHandler(enable = manual, callt = false, fpu = false)
void sysCallSystemServiceHandler(void)
{
    SysServiceParaType *para;
    getPara(&para);
    DisableMPU();
    if(CheckAddressinStack(para))
    {
        
        // disable ISR2 ,scheduler, timer
        kernelDisableISR2();
        disableCrossCoreISR();
        disableSchedulerIRQ();
        disableTimer();
        __EI();

        callService(para);

        // enable ISR2 ,scheduler, timer
        __DI();
        enableTimer();
        enableSchedulerIRQ();
        enableCrossCoreISR();
        kernelEnableISR2();
        
        
    }
    EnableMPU(); 
    
}

#pragma inline_asm pushStack
void pushStack(SysServiceParaType *para)
{
	add		-0x04, sp
	st.w    r6, 0[sp]
}

#pragma inline_asm getPara
void getPara(SysServiceParaType *para)
{
    add     -0x04, sp
    st.w    r7,0[sp] ; push r7
    ld.w    88[sp],r7 ; 88 will depend on the function sysCallSystemServiceHandler  
    st.w    r7,0[r6] 
    ld.w    0[sp],r7
    add		0x04, sp
}

#pragma inline_asm popStack
void popStack()
{
    add		0x04, sp
}

StatusType ActivateTaskUser(TaskType TaskID){

    SysServiceParaType para;
    para.serviceID  = SERVICE_ACTIVATETASK;
    para.para1    = TaskID;
    para.result = E_OK;
    
    pushStack(&para);
    
    sysCallSystemService();
    popStack();
    return para.result;
}

void callService(SysServiceParaType *para){
    switch (para->serviceID)
    {
    case SERVICE_IOC:
        // para->result = (*(Std_ReturnType(*)(int))(para->para1))(para->para2);
        para->result = IOC_API(para->para1,para->para2,para->para3);//channel, data, flag
        break;
    case READPERIPGERAL8:
        para->result = SysReadPeripheral8(para->para1, para->para2, para->para3);
        break;
    case READPERIPGERAL16:
        para->result = SysReadPeripheral16(para->para1, para->para2, para->para3);
        break;
    case READPERIPGERAL32:
        para->result = SysReadPeripheral32(para->para1, para->para2, para->para3);
        break;
    case WRITEPERIPGERAL8:
        para->result = SysWritePeripheral8(para->para1, para->para2, para->para3);
        break;
    case WRITEPERIPGERAL16:
        para->result = SysWritePeripheral16(para->para1, para->para2, para->para3);
        break;
    case WRITEPERIPGERAL32:
        para->result = SysWritePeripheral32(para->para1, para->para2, para->para3);
        break;
    case MODIFYPERIPGERAL8:
        para->result = SysModifyPeripheral8(para->para1, para->para2, ((uint8*)(para->para3))[0], ((uint8*)(para->para3))[1]);
        break;
    case MODIFYPERIPGERAL16:
        para->result = SysModifyPeripheral16(para->para1, para->para2, ((uint16*)(para->para3))[0], ((uint16*)(para->para3))[1]);
        break;
    case MODIFYPERIPGERAL32:
        para->result = SysModifyPeripheral32(para->para1, para->para2, ((uint32*)(para->para3))[0], ((uint32*)(para->para3))[1]);
        break;
    case SERVICE_ACTIVATETASK:
        para->result = SysActivateTask((TaskType)para->para1);
        break;
    case SERVICE_ALLOWACCESS:
        para->result = SysAllowAccess();
        break;
    case SERVICE_CALLTRUSTEDFUNCTION:
        // para->result = SysCallTrustedFunction(para->para1, para->para2);
        break;
    case SERVICE_CANCELALARM:
        para->result = SysCancelAlarm((AlarmType)para->para1);
        break;
    case SERVICE_CHAINTASK:
        para->result = SysChainTask((TaskType)para->para1);
        break;
    case SERVICE_CHECKISRMEMORYACCESS:
        para->result = SysCheckISRMemoryAccess((ISRType)para->para1,(MemoryStartAddressType)para->para2, (MemorySizeType)para->para3);
        break; 
    case SERVICE_CHECKOBJECTACCESS:
        para->result = SysCheckObjectAccess((ApplicationType)para->para1, (ObjectTypeType)para->para2, (uint32)para->para3);
        break;
    case SERVICE_CHECKOBJECTOWNERSHIP:
        para->result = SysCheckObjectOwnership((ObjectTypeType )para->para1, (uint32)para->para2);
        break;
    case SERVICE_CHECKTASKMEMORYACCESS:
        para->result = SysCheckTaskMemoryAccess((TaskType)para->para1, (MemoryStartAddressType)para->para2, (MemorySizeType)para->para3);
        break;
    case SERVICE_CLEAREVENT:
        para->result = SysClearEvent((EventMaskType)para->para1);
        break;
    case SERVICE_CONTROLIDLE:
        para->result = SysControlIdle((CoreIdType)para->para1,(IdleModeType)para->para2);
        break;
    case SERVICE_DISABLEALLINTERRUPTS:
        SysDisableAllInterrupts();
        break;
    case SERVICE_ENABLEALLINTERRUPTS:
        SysEnableAllInterrupts();
        break;
    case SERVICE_GETACTIVEAPPLICATIONMODE:
        para->result = SysGetActiveApplicationMode();
        break;
    case SERVICE_GETALARM:
        para->result = SysGetAlarm((AlarmType)para->para1, (TickRefType)para->para2);
        break;
    case SERVICE_GETALARMBASE:
        para->result = SysGetAlarmBase((AlarmType)para->para1, (AlarmBaseRefType)para->para2);
        break;
    case SERVICE_GETAPPLICATIONID:
        para->result = SysGetApplicationID();
        break;
    case SERVICE_GETAPPLICATIONSTATE:
        para->result = SysGetApplicationState((ApplicationType)para->para1, (ApplicationStateRefType)para->para2);
        break;
    case SERVICE_GETCOREID:
        para->result = SysGetCoreID();
        break;
    case SERVICE_GETCOUNTERVALUE:
        para->result = SysGetCounterValue((CounterType)para->para1, (TickRefType)para->para2);
        break;
    case SERVICE_GETELAPSEDVALUE:
        para->result = SysGetElapsedValue((CounterType)para->para1, (TickRefType)para->para2, (TickRefType)para->para3);
        break;
    case SERVICE_GETEVENT:
        para->result = SysGetEvent((TaskType )para->para1, (EventMaskRefType )para->para2);
        break;
    case SERVICE_GETISRID: 
        para->result = SysGetISRID();
        break;
    case SERVICE_GETNUMBEROFACTIVATEDCORES:
        para->result = SysGetNumberOfActivatedCores();
        break;
    case SERVICE_GETRESOURCE:
        para->result = SysGetResource((ResourceType)para->para1);
        break;
    case SERVICE_GETSCHEDULETABLESTATUS:
        para->result = SysGetScheduleTableStatus(para->para1, (ScheduleTableStatusRefType)para->para2);
        break;
    case SERVICE_GETSPINLOCK:   
        para->result = SysGetSpinlock((SpinlockIdType )para->para1);
        break;
    case SERVICE_GETTASKID:
        para->result = SysGetTaskID((TaskRefType)para->para1);
        break;
    case SERVICE_GETTASKSTATE:
        para->result = SysGetTaskState((TaskType )para->para1, (TaskStateRefType)para->para2);
        break;
    case SERVICE_INCREMENTCOUNTER:
        para->result = SysIncrementCounter((CounterType )para->para1);
        break;
    case SERVICE_NEXTSCHEDULETABLE:
        para->result = SysNextScheduleTable((ScheduleTableType)para->para1, (ScheduleTableType)para->para2);
        break;
    case SERVICE_RELEASERESOURCE:
        para->result = SysReleaseResource((ResourceType)para->para1);
        break;  
    case SERVICE_RELEASESPINLOCK:
        para->result = SysReleaseSpinlock((ResourceType )para->para1);
        break;
    case SERVICE_RESUMEALLINTERRUPTS:
        SysResumeAllInterrupts();
        break;
    case SERVICE_RESUMEOSINTERRUPTS:
        SysResumeOSInterrupts();
        break;
    case SERVICE_SCHEDULE:
        para->result = SysSchedule();
        break;
    case SERVICE_SETABSALARM:
        para->result = SysSetAbsAlarm((AlarmType )para->para1,(TickType)para->para2, (TickType)para->para3);
        break;
    case SERVICE_SETEVENT:
        para->result = SysSetEvent(para->para1, (EventMaskType)para->para2);
        break;
    case SERVICE_SETRELALARM:
        para->result = SysSetRelAlarm(para->para1, (TickType)para->para2, (TickType)para->para3);
        break;    
    case SERVICE_SETSCHEDULETABLEASYNC:
        para->result = SysSetScheduleTableAsync(para->para1);
        break;
    case SERVICE_SHUTDOWNALLCORES:
        SysShutdownAllCores((StatusType)para->para1);
        break;
    case SERVICE_SHUTDOWNOS:
        SysShutdownOS((StatusType)para->para1);
        break;
    case SERVICE_STARTCORE:
        SysStartCore((CoreIdType)para->para1, (StatusType *)para->para2);
        break;
    case SERVICE_STARTOS:
        SysStartOS((AppModeType)para->para1);
        break;
    case SERVICE_STARTNONAUTOSARCORE:
        SysStartNonAutosarCore(para->para1, (StatusType *)para->para2);
        break;
    case SERVICE_STARTSCHEDULETABLEABS:
        para->result = SysStartScheduleTableAbs(para->para1, (TickType)para->para2);
        break;
    case SERVICE_STARTSCHEDULETABLEREL:
        para->result = SysStartScheduleTableRel(para->para1, (TickType)para->para2);
        break;  
    case SERVICE_STARTSCHEDULETABLESYNCHRON:
        para->result = SysStartScheduleTableSynchron(para->para1);
        break;
    case SERVICE_STOPSCHEDULETABLE:
        para->result = SysStopScheduleTable(para->para1);
        break;   
    case SERVICE_SUSPENDALLINTERRUPTS:
        SysSuspendAllInterrupts();
        break;
    case SERVICE_SUSPENDOSINTERRUPTS:
        SysSuspendOSInterrupts();
        break;
    case SERVICE_SYNCSCHEDULETABLE:
        para->result = SysSyncScheduleTable(para->para1, para->para2);
        break;
    case SERVICE_TERMINATEAPPLICATION:
        para->result = SysTerminateApplication((ApplicationType )para->para1,(RestartType )para->para2);
        break;            
    case SERVICE_TERMINATETASK:
        para->result = SysTerminateTask();
        break;
    case SERVICE_TRYTOGETSPINLOCK:
        para->result = SysTryToGetSpinlock(para->para1, (TryToGetSpinlockType *)para->para2);
        break;
    case SERVICE_WAITEVENT:
        para->result = SysWaitEvent(para->para1);
        break;    
    case SERVICE_ACTIVATETASKASYN:
        SysActivateTaskAsyn(para->para1);
        break;
    case SERVICE_SETEVENTASYN:
        SysSetEventAsyn(para->para1, para->para2);
        break;
    case SERVICE_CLEARPENDINGINTERRUPT:
        para->result = SysClearPendingInterrupt(para->para1);
        break;
    case SERVICE_ENABLEINTERRUPTSOURCE:
        para->result = SysEnableInterruptSource(para->para1, (boolean)para->para2);
        break;
    case SERVICE_DISABLEINTERRUPTSOURCE:
        para->result = SysDisableInterruptSource(para->para1);
        break;
    case SERVICE_GETSOFTWARETIMERVALUE:
        para->result = SysGetSoftwareTimerValue(para->para1, (TickRefType)para->para2);
        break;
    case SERVICE_TICKTOMS:
        para->result = SysTickToMs((SoftwareTimerType)para->para1, (SoftwareTimerTickType)para->para2, (uint32 *)para->para3);
        break;
    case SERVICE_GETCURRENTAPPLICATIONID:
        para->result = SysGetCurrentApplicationID();
        break;
    case SERVICE_TERMINATETASKOBJBYOS:
        SysTerminateTaskObjByOS((TaskType)para->para1);
        break;
    default:
        break;
    }
}




/* syscall helper functon below */

#pragma inline_asm innerEnterSystemCall
void innerEnterSystemCall(void)
{
    syscall 1 
}

#pragma inline_asm innerExitSystemCall
void innerExitSystemCall(void)
{
    syscall 2
}

void EnterSystemCall(){                   
    do{                                     
        innerEnterSystemCall();        
    } while(0);
}

void ExitSystemCall(){                            
    do{                                             
        kernelSystemCallCounter--;
        if (kernelSystemCallCounter < 0){  
            /* this case should NOT happen if EnterSystemCall and ExitSystemCall are used in pair*/
            kernelSystemCallCounter = 0;            
        }                                           
        else if (kernelSystemCallCounter == 0){     
            innerExitSystemCall();                      
        }                                           
        else { /* (kernelSystemCallCounter > 0) */  
            /* still in inner region of nested-call */
            ; /* do noth, keep in syscall-privilege */        
        }                                           
    } while(0); 
}

#pragma inline_asm innerEnterCallTrustedFunc
void innerEnterCallTrustedFunc(void)
{
    syscall 3
}

void syscall_CallTrustedFunc(void){
    innerEnterCallTrustedFunc();
}

#pragma inline_asm sysCallPrintText
void sysCallPrintText(void)
{
    syscall 4
}

#pragma inline_asm sysCallPrintText_R35
void sysCallPrintText_R35(void)
{
    syscall 5
}

#pragma inline_asm sysCallTrustFunc
void sysCallTrustFunc(void)
{
    syscall 6
}

#pragma inline_asm getParaTrustFunc
void getParaTrustFunc(SysServiceParaType *para)
{
    add     -0x04, sp
    st.w    r7,0[sp] ; push r7
    ld.w    120[sp],r7 ; will depend on the function sysCallTrustFuncHandler  
    st.w    r7,0[r6] 
    ld.w    0[sp],r7
    add		0x04, sp
}


#pragma interrupt sysCallTrustFuncHandler(enable = manual, callt = false, fpu = false)
void sysCallTrustFuncHandler(void)
{
    SysServiceParaType *para;
    getParaTrustFunc(&para);
    DisableMPU();
    if(CheckAddressinStack(para))
    {
        TaskType TaskIndex  = CurrentTask[_CoreID]->currentID & 0x0000FFFF;
        ApplicationType originalApp  =  SystemObjects[_CoreID]->TaskVar[TaskIndex].executingApp;
        StatusType result = E_OK;
        TrustedFunctionIndexType index = para->para1 & 0x0000FFFF;
        
        CurrentTask[_CoreID]->CurrentVar->nestedTrustFuncCounter++;

        result = TrustfunctionChecking(para->para1,para->para2);
        if(result == E_OK)
        {
            ResourceType resourceId = ApplicationVar[SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex].owner].Resource;
            TrustedFuncPtrType function = TF_array[_CoreID][index];
            ApplicationType functionOwner = SystemObjectAutosar[_CoreID]->trustedFunctionAutosar[index].owner;
            ExecutingApp[_CoreID] = functionOwner;
            SetAppMemProtWithMPM(functionOwner);
            
            /* Disable ISR2 to avoid interferenced by ISR2 */
            /* get a resource to promote priority to avoid prempted by the task in the same app */
            if(CurrentTask[_CoreID]->CurrentVar->nestedTrustFuncCounter == 1)
            {
                DisableAppISR(SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex].owner);
                SysGetResource(resourceId);
            }
            /* Enable MPu to run trusted function on the corresponding access right */
            EnableMPU();
            __EI();
            function(para->para1,para->para2);
            __DI();
            DisableMPU();
            if(CurrentTask[_CoreID]->CurrentVar->nestedTrustFuncCounter == 1)
            {
                SysReleaseResource(resourceId);
                EnableAppISR(SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex].owner);
            }
            
            ExecutingApp[_CoreID] = originalApp;
            if( (CurrentTask[_CoreID]->CurrentVar->nestedTrustFuncCounter==1 ||
                ApplicationVar[ExecutingApp[_CoreID]].OsTrustedApplicationDelayTimingViolationCall == FALSE)
                && SystemObjects[_CoreID]->TaskVar[TaskIndex].isDelay == TRUE
            )
            {
                ProtectionHandle(E_OS_PROTECTION_TIME);
            }
            SetAppMemProtWithMPM(originalApp);
        }
        CurrentTask[_CoreID]->CurrentVar->nestedTrustFuncCounter--;
        if(result != E_OK)
        {
            /* Do error hook */
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
        }
    }
    EnableMPU(); 
    
}