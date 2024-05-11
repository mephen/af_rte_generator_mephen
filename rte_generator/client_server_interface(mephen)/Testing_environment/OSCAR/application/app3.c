#include "iodefine.h"
#include "board.h"
#include "os.h"
#include "timer.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "counter.h"
#include "alarm.h"
#include "task.h"
#include "isr2.h"
#include "event.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "string_format_test.h"
#include "systemcall.h"
#include "application.h"
#include "ISRInit.h"
#include "isr_Cfg.h"
#include "spinlock.h"
#include "resource.h"
#include "memsection.h"
#include "trustedFunc_Cfg.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC


/************* OSAPP_A03 *****************/
#pragma section OSAPP_A03_SEC

int app3_test_data = 0x33;

/* Brief StartupHook */
void StartupHook_OSAPP_A03(void)
{
    // PrintText("APP A03: \r\n");
    PrintText("    I'm in App A03 StartupHook\r\n");
    // PrintText("    Start up success!\r\n");
}

/* Brief ShutdownHook */
void ShutdownHook_OSAPP_A03(StatusType Error)
{
    // PrintText("APP A03: \r\n");
    PrintText("I'm in App A03 ShutdownHook\r\n");
    // PrintText("    Bye!\r\n");
}

/* Brief ErrorHook */
void ErrorHook_OSAPP_A03(StatusType Error)
{   
    PrintText("App A03 Error Hook:\r\n");
    switch (Error)
    {
    case E_OS_ACCESS:
        PrintText("[ErrorHook]: E_OS_ACCESS\r\n");
        break;
    case E_OS_CALLEVEL:
        PrintText("[ErrorHook]: E_OS_CALLEVEL\r\n");
        break;
    case E_OS_ID:
        PrintText("[ErrorHook]: E_OS_ID\r\n");
        break;
    case E_OS_LIMIT:
        PrintText("[ErrorHook]: E_OS_LIMIT\r\n");
        break;
    case E_OS_NOFUNC:
        PrintText("[ErrorHook]: E_OS_NOFUNC\r\n");
        break;
    case E_OS_RESOURCE:
        PrintText("[ErrorHook]: E_OS_RESOURCE\r\n");
        break;
    case E_OS_STATE:
        PrintText("[ErrorHook]: E_OS_STATE\r\n");
        break;
    case E_OS_VALUE:
        PrintText("[ErrorHook]: E_OS_VALUE\r\n");
        break;
    case E_OS_SYS_NOFUNC:
        PrintText("[ErrorHook]: E_OS_SYS_NOFUNC\r\n");
        break;
    case E_OS_SERVICEID:
        PrintText("[ErrorHook]: E_OS_SERVICEID\r\n");
        break;
    case E_OS_INTERFERENCE_DEADLOCK:
        PrintText("[ErrorHook]: E_OS_INTERFERENCE_DEADLOCK\r\n");
        break;
    case E_OS_SYS_OK_CROSSCORE:
        PrintText("[ErrorHook]: E_OS_SYS_OK_CROSSCORE\r\n");
        break;
    case E_OS_SPINLOCK:
        PrintText("[ErrorHook]: E_OS_SPINLOCK\r\n");
        break;
    case E_OS_DISABLEDINT:
        PrintText("[ErrorHook]: E_OS_DISABLEDINT\r\n");
        break;
    default:
        PrintText("[ErrorHook]: \r\n");
        break;
    }
}

#pragma section ISR_I005_SEC
ISR(I005)
{
    PrintText("isr2 005 in osapp 03\r\n\0");
}

#pragma section ISR_I006_SEC
ISR(I006)
{
    PrintText("isr2 006 in osapp 03\r\n\0");
}

#pragma section TASK_T004_SEC
TASK(T04)
{   
    PrintText("hello t4\r\n\0");
    uint32 temp= 0 ;
    // for(uint32 i=0; i<40000;i++){
    //     temp = temp + 1;
    // }

    CallTrustedFunction(TF_AIMER, &temp);
    // ActivateTask(T05);
    TerminateTask();
}

#pragma section TASK_T005_SEC
TASK(T05)
{   
    PrintText("hello t5\r\n\0");
    TerminateTask();
}

#pragma section TASK_T006_SEC
TASK(T06)
{   
    PrintText("hello t6\r\n\0");
    TerminateTask();
}
