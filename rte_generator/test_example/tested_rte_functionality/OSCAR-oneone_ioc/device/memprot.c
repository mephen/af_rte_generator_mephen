#include "typedefine.h"
#include "memprot.h"
#include "memsection.h"
#include "system.h"
#include "scheduler.h"
#include "timer.h"
#include "os.h"
#include "os_Cfg.h"
#include "application_Cfg.h"
#include "task_Cfg.h"
#include <_h_c_lib.h>   //for using _INITSCT_RH()
#include "application.h"
#include "task.h"
#include "memprot_Cfg.h"

#define MPRC_regID 1
#define MPRC_selID 5

#define IN_START_UP_CASE 0
#define IN_SHUT_DOWN_CASE 1
#define WITHOUTPROTECTION 0x00
#define PROTECTIONINKERNELMODE 0x03
#define PROTECTIONINUSERMODE 0x01

void memProtectionHandle(StatusType Error)
{
    ProtectionReturnType result;
    result = PRO_TERMINATETASKISR;
    systemFlag |= IN_PROTECTION_HANDLER;

#if (HOOK_ENABLE_PROTECTIONHOOK == ENABLE)
    systemFlag |= IN_PROTECTION_HOOK;
    result = ProtectionHook(Error);
    systemFlag &= ~IN_PROTECTION_HOOK;
#else
    result = PRO_SHUTDOWN;  /* SWS_Os_00107 */
#endif  /* HOOK_ENABLE_PROTECTIONHOOK == ENABLE */

    /* Memory protection must terminate task at least */
    if(result == PRO_IGNORE){
        result = PRO_TERMINATETASKISR;
    }

    /* OS will terminate app if memory fault happen in app hook */
    if(systemFlag & (IN_OSAPP_STARTUP_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_ERROR_HOOK)){
        /* Terminate systask */
        TerminateSpecificTaskbyOS(CURRENTTASK.currentID);
        if(result == PRO_IGNORE || result == PRO_TERMINATETASKISR)
        result = PRO_TERMINATEAPPL;
    }

    /* Execute according to result */
    switch (result)
    {
    case PRO_IGNORE:
        /* do nth */
        break;
    case PRO_TERMINATETASKISR:
        TerminateSpecificTaskbyOS(CURRENTTASK.currentID);
        ScheduleKernel();
        break;
    case PRO_TERMINATEAPPL:
        // TerminateAppInternal(ExecutingApp[_CoreID]);
        SysTerminateApplication(ExecutingApp[_CoreID], NO_RESTART);
        ScheduleKernel();
        break;
    case PRO_TERMINATEAPPL_RESTART:
        if (ApplicationVar[ ExecutingApp[_CoreID] ].RestartTaskID == 0)
        {
            ShutdownOS(Error);
        }
        else
        {
            SysTerminateApplication(ExecutingApp[_CoreID], RESTART);
        }
        break;
    case PRO_SHUTDOWN:
        ShutdownOS(Error);
        break;
    default:
        break;  /* SWS_Os_00308 */
    }
    
    systemFlag &= ~IN_PROTECTION_HANDLER;
}

#pragma interrupt AHA_MPU_hander(enable=false, priority=feint, fpu=false, callt=false)
void AHA_MPU_hander(void){
    while(1)
        ;
}

#pragma interrupt MPU_FAULT_HANDLER(enable=false, priority=feint, fpu=false, callt=false)
void MPU_FAULT_HANDLER(void)
{   
    DisableMPU();
    
    memProtectionHandle( E_OS_PROTECTION_MEMORY );    /* SWS_Os_00044 */
    
    // if( systemFlag & (IN_OSAPP_STARTUP_HOOK|IN_OSAPP_SHUTDOWN_HOOK) ){
    //     app_shut_down_hook_err_flag[_CoreID] = 1;
    //     LoadOSContextInMemHandler();
    // }

    EnableMPU();
}


/* you can find the register number info at 
  RH850G3M User’s Manual: Software page.87 
  <<2 is "times 4", which will just match the needed Register selID*/
#define SETMP_1(i)                             \
    do {                                       \
        __ldsr_rh(( ## i<<2)   , 6, MPLA);     \
        __ldsr_rh(( ## i<<2) +1, 6, MPUA);     \
        __ldsr_rh(( ## i<<2) +2, 6, MPAT);     \
    } while(0)

/* the SETMP_2 is not used currenctly because we only use 7 registers */
#define SETMP_2(i)                              \
    do {                                        \
        __ldsr_rh(( ## i<<2)   , 7, MPLA);     \
        __ldsr_rh(( ## i<<2) +1, 7, MPUA);     \
        __ldsr_rh(( ## i<<2) +2, 7, MPAT);     \
    } while(0)

void setMPRegister(uint16 n, uint32 MPLA, uint32 MPUA, uint32 MPAT)
{
    switch (n)
    {
    case 0:
        SETMP_1(0);
        break;
    case 1:
        SETMP_1(1);
        break;
    case 2:
        SETMP_1(2);
        break;
    case 3:
        SETMP_1(3);
        break;
    case 4:
        SETMP_1(4);
        break;
    case 5:
        SETMP_1(5);
        break;
    case 6:
        SETMP_1(6);
        break;
    case 7:
        SETMP_1(7);
        break;
    case 8:
        SETMP_2(0);
        break;
    case 9:
        SETMP_2(1);
        break;
    case 10:
        SETMP_2(2);
        break;
    case 11:
        SETMP_2(3);
        break;
    case 12:
        SETMP_2(4);
        break;
    case 13:
        SETMP_2(5);
        break;
    case 14:
        SETMP_2(6);
        break;
    case 15:
        SETMP_2(7);
        break;
    }
}

/* Set the first 3 area(0~2)'s MPLAn MPUAn MPATn at boot time */
void SetOSMemProt(void)
{
    MemProtAreaType *MemProtArea = MemProtArea_OS;
    for(uint16 i=0 ; i<3 ; i++)
    {
        setMPRegister(i, MemProtArea[i].MPLAn, MemProtArea[i].MPUAn, MemProtArea[i].MPATn);
    }
    __ldsr_rh(MPRC_regID, MPRC_selID, 0x7); 
}

/* Set normal task/ISR2 memory protection configuration */
void SetMemProt(void)
{
    TaskType task_ID = CURRENTTASK.currentID & 0xffff;
    TaskType IdleTask = 0; 
    MemProtAreaType *TaskMemProtArea = SystemObjectAutosar[_CoreID]->TaskAutosar[task_ID].MemArea;
    MemProtAreaType *AppMemProtArea = ApplicationVar[SystemObjectAutosar[_CoreID]->TaskAutosar[task_ID].owner].MemArea;

    if (task_ID == IdleTask) /* idle-task */
    {
        CURRENTTASK.MPM = WITHOUTPROTECTION;     /* run in Os-level */
    }
    else if (ApplicationVar[ ExecutingApp[_CoreID] ].OsTrusted  == TRUE ) /* trusted */
    {
        if( ApplicationVar[ ExecutingApp[_CoreID] ].OsTrustedApplicationWithProtection == WithMemProt)
        {
            CURRENTTASK.MPM = PROTECTIONINKERNELMODE;     /* SWS_Os_00795 */
        }
        else
        {   /* i.e., trustWithProt == WithoutProt, allow all access, this is default */
            CURRENTTASK.MPM = WITHOUTPROTECTION;     
        }
    }
    else if( ApplicationVar[ ExecutingApp[_CoreID] ].OsTrusted  == FALSE) /* non-trusted */
    {    
        CURRENTTASK.MPM = PROTECTIONINUSERMODE;
    }


    if (task_ID != IdleTask){
        /* Set OS-App memory protection area*/
        setMPRegister(3, AppMemProtArea[0].MPLAn, AppMemProtArea[0].MPUAn, AppMemProtArea[0].MPATn);
        setMPRegister(4, AppMemProtArea[1].MPLAn, AppMemProtArea[1].MPUAn, AppMemProtArea[1].MPATn);

        /* Set task memory protection area */
        setMPRegister(5, TaskMemProtArea[0].MPLAn, TaskMemProtArea[0].MPUAn, TaskMemProtArea[0].MPATn);
        setMPRegister(6, TaskMemProtArea[1].MPLAn, TaskMemProtArea[1].MPUAn, TaskMemProtArea[1].MPATn);
    
        // set the MPRC register to enable the MPU region 0~6  
        __ldsr_rh(MPRC_regID, MPRC_selID, 0x7f);
    }

}

/* Set system task memory protection */
void SetSystaskMemProt()
{
    uint32 task_ID = CURRENTTASK.currentID & 0xffff; //system task ID
    MemProtAreaType *TaskMemProtArea = SystemObjectAutosar[_CoreID]->TaskAutosar[task_ID].MemArea;
    
    /* Set task memory protection area */
    setMPRegister(5, TaskMemProtArea[0].MPLAn, TaskMemProtArea[0].MPUAn, TaskMemProtArea[0].MPATn);
    setMPRegister(6, TaskMemProtArea[1].MPLAn, TaskMemProtArea[1].MPUAn, TaskMemProtArea[1].MPATn);
    
    // set the MPRC register to enable the MPU region 0~3, 6  
    // no data amd bss region
    __ldsr_rh(MPRC_regID, MPRC_selID, 0x7f);
}

/* Set system task with app memory protection configuration */
void SetAppMemProtWithMPM(ApplicationType app_id)
{
    uint32 AppMPM;

    /* Use INVALID_OSAPPLICATION to indicate run in kernel mode and with out memory proteciton */
    if(app_id == INVALID_OSAPPLICATION) 
    {
        AppMPM = WITHOUTPROTECTION;     /* run in Os-level */
    }
    else
    {
        MemProtAreaType *AppMemProtArea = ApplicationVar[app_id].MemArea;
        setMPRegister(3, AppMemProtArea[0].MPLAn, AppMemProtArea[0].MPUAn, AppMemProtArea[0].MPATn);
        setMPRegister(4, AppMemProtArea[1].MPLAn, AppMemProtArea[1].MPUAn, AppMemProtArea[1].MPATn);
        // set the MPRC register to enable the MPU region 0~4, 6
        __ldsr_rh(MPRC_regID, MPRC_selID, 0x7f); 
        
        if (ApplicationVar[ app_id ].OsTrusted  == TRUE ) /* trusted */
        {
            if( ApplicationVar[ app_id ].OsTrustedApplicationWithProtection == TRUE)
            {
                AppMPM = PROTECTIONINKERNELMODE;     /* SWS_Os_00795 */
            }
            else
            {   /* TrustWithProt == WithoutProt, allow all access, this is default */
                AppMPM = WITHOUTPROTECTION;     
            }
        }
        else if( ApplicationVar[ app_id ].OsTrusted  == FALSE) /* non-trusted */
        {    
            AppMPM = PROTECTIONINUSERMODE;
        }
    }
    CURRENTTASK.MPM = AppMPM; 
}

void InitOSCoreRomToRamMemArea( uint32 coreID ){
    struct _C_DSEC{
        uint32 rom_s; 
        uint32 rom_e; 
        uint32 ram_s; 
    } c_data_sec[1];

    struct _C_BSEC{
        uint32 bss_s; 
        uint32 bss_e; 
    } c_bss_sec[1];

    if( coreID == OS_CORE_ID_MASTER ){
        // .data, .bss
        c_data_sec->rom_s = (uint32)(_S_data);
        c_data_sec->rom_e = (uint32)(_E_data);
        c_data_sec->ram_s = (uint32)(_S_data_R);
        c_bss_sec->bss_s = (uint32)(_S_bss);
        c_bss_sec->bss_e = (uint32)(_E_bss);
        _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );

        // IOC_RESERVED_SEC.data, IOC_RESERVED_SEC.bss
        c_data_sec->rom_s = (uint32)(_SIOC_RESERVED_SEC_data);
        c_data_sec->rom_e = (uint32)(_EIOC_RESERVED_SEC_data);
        c_data_sec->ram_s = (uint32)(_SIOC_RESERVED_SEC_data_R);
        c_bss_sec->bss_s = (uint32)(_SIOC_RESERVED_SEC_bss);
        c_bss_sec->bss_e = (uint32)(_EIOC_RESERVED_SEC_bss);
        _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );

        // USER_SHARED_SEC.data, USER_SHARED_SEC.bss
        c_data_sec->rom_s = (uint32)(_SUSER_SHARED_SEC_data);
        c_data_sec->rom_e = (uint32)(_EUSER_SHARED_SEC_data);
        c_data_sec->ram_s = (uint32)(_SUSER_SHARED_SEC_data_R);
        c_bss_sec->bss_s = (uint32)(_SUSER_SHARED_SEC_bss);
        c_bss_sec->bss_e = (uint32)(_EUSER_SHARED_SEC_bss);
        _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );

        // GLOBAL_RAM_A.data, GLOBAL_RAM_A.bss
        c_data_sec->rom_s = (uint32)(_SGLOBAL_RAM_A_data);
        c_data_sec->rom_e = (uint32)(_EGLOBAL_RAM_A_data);
        c_data_sec->ram_s = (uint32)(_SGLOBAL_RAM_A_data_R);
        c_bss_sec->bss_s = (uint32)(_SGLOBAL_RAM_A_bss);
        c_bss_sec->bss_e = (uint32)(_EGLOBAL_RAM_A_bss);
        _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );

        // RETENTION_RAM.data, RETENTION_RAM_A.bss
        c_data_sec->rom_s = (uint32)(_SRETENTION_RAM_data);
        c_data_sec->rom_e = (uint32)(_ERETENTION_RAM_data);
        c_data_sec->ram_s = (uint32)(_SRETENTION_RAM_data_R);
        c_bss_sec->bss_s = (uint32)(_SRETENTION_RAM_bss);
        c_bss_sec->bss_e = (uint32)(_ERETENTION_RAM_bss);
        _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );

        // GLOBAL_RAM_B.data, GLOBAL_RAM_B.bss
        c_data_sec->rom_s = (uint32)(_SGLOBAL_RAM_B_data);
        c_data_sec->rom_e = (uint32)(_EGLOBAL_RAM_B_data);
        c_data_sec->ram_s = (uint32)(_SGLOBAL_RAM_B_data_R);
        c_bss_sec->bss_s = (uint32)(_SGLOBAL_RAM_B_bss);
        c_bss_sec->bss_e = (uint32)(_EGLOBAL_RAM_B_bss);
        _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );

        // LOCAL_RAM_PE1.data, LOCAL_RAM_PE1.bss
        c_data_sec->rom_s = (uint32)(_SLOCAL_RAM_PE1_data);
        c_data_sec->rom_e = (uint32)(_ELOCAL_RAM_PE1_data);
        c_data_sec->ram_s = (uint32)(_SLOCAL_RAM_PE1_data_R);
        c_bss_sec->bss_s = (uint32)(_SLOCAL_RAM_PE1_bss);
        c_bss_sec->bss_e = (uint32)(_ELOCAL_RAM_PE1_bss);
        _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );
    }
    else if( coreID == OS_CORE_ID_1 ){

        // LOCAL_RAM_PE2.data, LOCAL_RAM_PE2.bss
        c_data_sec->rom_s = (uint32)(_SLOCAL_RAM_PE2_data);
        c_data_sec->rom_e = (uint32)(_ELOCAL_RAM_PE2_data);
        c_data_sec->ram_s = (uint32)(_SLOCAL_RAM_PE2_data_R);
        c_bss_sec->bss_s = (uint32)(_SLOCAL_RAM_PE2_bss);
        c_bss_sec->bss_e = (uint32)(_ELOCAL_RAM_PE2_bss);
        _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );
    }

    // SELF_AREA.data, SELF_AREA.bss, actually, this action do not take effect
    c_data_sec->rom_s = (uint32)(_SSELF_AREA_data);
    c_data_sec->rom_e = (uint32)(_ESELF_AREA_data);
    c_data_sec->ram_s = (uint32)(_SSELF_AREA_data_R);
    c_bss_sec->bss_s = (uint32)(_SSELF_AREA_bss);
    c_bss_sec->bss_e = (uint32)(_ESELF_AREA_bss);
    _INITSCT_RH(c_data_sec, c_data_sec +1, c_bss_sec, c_bss_sec +1 );

    //the compiler SPEC says that the bss-region need to be align-4 
    //otherwise, _INITSCT_RH() will not reset all bss-region
    //but since function InitOSCoreRomToRamMemArea() is called at boot-time
    //and we have reset all the memorry area in boot.asm,
    //we still use _INITSCT_RH() here for speed up

    //my_mem_data_copy(c_data_sec->rom_s, c_data_sec->rom_e, c_data_sec->ram_s);
    //my_mem_bss_clean(c_data_sec->bss_s, c_data_sec->bss_e);
}

//run only once at boot time, afterward, all the re-init is done by ReInitRomToRamMemArea()
void InitRomToRamMemArea(CoreIdType coreID){

    uint32 index;
    ApplicationType cur_app;

    // per core self-data, core0 also help move kernel-data
    InitOSCoreRomToRamMemArea(coreID);
    
    // initialize mySysStackPtr to pointing to per-core sys stack
    // switch (coreID)
	// {
	// case 0: /* PE1 */
	// 	mySysStackPtr[0] = ( *(uint32*)(system_pe1_stack_BSS_S) + 0x400 );
	// 	break;
	// case 1: /* PE2 */
	// 	mySysStackPtr[0] = ( *(uint32*)(system_pe2_stack_BSS_S) + 0x400 );
	// 	break;
	// }

    // since all the OS-app should be turn-on at boot time, we initialize it
    for(index=0 ; index < SystemAppsInCore[coreID].AppsCount; ++index){
        cur_app = SystemAppsInCore->AppsRef[index];
        ReInitOSAppRomToRamMemArea(cur_app);
    }
}

void ReInitOSAppRomToRamMemArea( uint32 appID ){
    
    uint32 rom_s; 
    uint32 rom_e; 
    uint32 ram_s; 
    uint32 bss_s; 
    uint32 bss_e;
    
    rom_s = (uint32)(ApplicationVar[appID].RomToRamInitTable.rom_s);
    rom_e = (uint32)(ApplicationVar[appID].RomToRamInitTable.rom_e);
    ram_s = (uint32)(ApplicationVar[appID].RomToRamInitTable.ram_s);
    bss_s = (uint32)(ApplicationVar[appID].RomToRamInitTable.bss_s);
    bss_e = (uint32)(ApplicationVar[appID].RomToRamInitTable.bss_e);

    //the compiler SPEC says that the bss-region need to be align-4 
    //otherwise, _INITSCT_RH() will not reset all bss-region
    //so we use our own implementation here
    my_mem_data_copy(rom_s, rom_e, ram_s);
    my_mem_bss_clean(bss_s, bss_e);
}

//objectID means task or isr2-task 
void ReInitTaskRomToRamMemArea( uint32 objectID ){
    
    uint32 rom_s; 
    uint32 rom_e; 
    uint32 ram_s; 
    uint32 bss_s; 
    uint32 bss_e; 
    
    CoreIdType coreID = GetPhyCoreID();
    objectID = objectID & 0xffff;

     //idle task, do nth. 
    if( objectID == 0 ){
        return;    
    }
    
    rom_s = (uint32)(SystemObjects[coreID]->TaskConst[objectID].RomToRamInitTable.rom_s);
    rom_e = (uint32)(SystemObjects[coreID]->TaskConst[objectID].RomToRamInitTable.rom_e);
    ram_s = (uint32)(SystemObjects[coreID]->TaskConst[objectID].RomToRamInitTable.ram_s);
    bss_s = (uint32)(SystemObjects[coreID]->TaskConst[objectID].RomToRamInitTable.bss_s);
    bss_e = (uint32)(SystemObjects[coreID]->TaskConst[objectID].RomToRamInitTable.bss_e);

    //the compiler SPEC says that the bss-region need to be align-4 
    //otherwise, _INITSCT_RH() will not reset all bss-region
    //so we use our own implementation here
    my_mem_data_copy(rom_s, rom_e, ram_s);
    my_mem_bss_clean(bss_s, bss_e);
}

boolean CheckAddressinStack(uint32 *address)
{
    TaskType task_ID = CURRENTTASK.currentID & 0xffff;
    MemProtAreaType *TaskMemProtArea = SystemObjectAutosar[_CoreID]->TaskAutosar[task_ID].MemArea;
    uint32 MPUStatus;
    MPUStatus = __stsr_rh(0,5);
    // If address is in stack area or MPU is disable return TRUE
    if( ((uint32)address >= TaskMemProtArea[1].MPLAn) && ((uint32)address <= TaskMemProtArea[1].MPUAn) || MPUStatus == 0){
        return TRUE;
    }else {
        return FALSE;
    }
}

boolean CheckWritingAccess(uint32 *address)
{
    TaskType task_ID = CURRENTTASK.currentID & 0xffff;
    ApplicationType app_ID = ExecutingApp[_CoreID];
    MemProtAreaType *OSMemProtArea = MemProtArea_OS;
    MemProtAreaType *AppMemProtArea = ApplicationVar[app_ID].MemArea;
    MemProtAreaType *TaskMemProtArea = SystemObjectAutosar[_CoreID]->TaskAutosar[task_ID].MemArea;

    /* Check shared library */
    if( ((uint32)address >= OSMemProtArea[2].MPLAn) && ((uint32)address <= OSMemProtArea[2].MPUAn) ){
        return TRUE;
    }
    /*Check app data */
    if ( ((uint32)address >= AppMemProtArea[1].MPLAn) && ((uint32)address <= AppMemProtArea[1].MPUAn) ){
        return TRUE;
    }
    /* Check task data */
    if( ((uint32)address >= TaskMemProtArea[1].MPLAn) && ((uint32)address <= TaskMemProtArea[1].MPUAn) ){
        return TRUE;
    }
    /* Check task stack */
    if( ((uint32)address >= TaskMemProtArea[0].MPLAn) && ((uint32)address <= TaskMemProtArea[0].MPUAn) ){
        return TRUE;
    }
    return FALSE;
}

#if (ENABLE_SOFTWARE_STACK_MONITOR == ENABLE)
//objectID means task or isr2-task 
void ReInitStackMonitorPattern( uint32 objectID ){
    
    CoreIdType coreID;
    StackPtrType stack_top_ptr;
    StackSizeType user_stack_size;
    uint32* stack_full_pos;     //this pointer type really depend on STACK_MONITOR_APPEND_SIZE

    objectID = objectID & 0xffff;
    coreID = GetPhyCoreID();
    stack_top_ptr   = (SystemObjects[coreID]->TaskConst[objectID].stackZone);
    user_stack_size = (SystemObjects[coreID]->TaskConst[objectID].stackSize);

    stack_full_pos = (uint32*)(stack_top_ptr + user_stack_size);
    *stack_full_pos = STACK_MONITOR_PATTERN;
    coreID = 0;
}

void checkStackMonitorPattern(){
   
    StackPtrType stack_top_ptr;
    StackSizeType user_stack_size;
    uint32* stack_full_pos;     //this pointer type really depend on STACK_MONITOR_APPEND_SIZE


    
    //only check when task is in running state
    if (CURRENTTASK.CurrentVar->state == RUNNING)
    {
        stack_top_ptr   = (CURRENTTASK.CurrentConst->stackZone);
        user_stack_size = (CURRENTTASK.CurrentConst->stackSize);

        stack_full_pos = (uint32*)(stack_top_ptr + user_stack_size);
        if( stack_full_pos[0] != STACK_MONITOR_PATTERN){
            memProtectionHandle( E_OS_STACKFAULT );     /* SWS_Os_00068 SWS_Os_00396 */ 
        }
    }


}


#endif