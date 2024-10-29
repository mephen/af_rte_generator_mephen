#include "iodefine.h"
#include "board.h"
#include "os.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "event.h"
#include "task.h"
#include "memsection.h"
#include "memprot_Cfg.h"

#include "string_format_test.h"
#include "ISRInit.h"
#include "systemcall.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* OSAPP_A04 *****************/
#pragma section OSAPP_A04_SEC

int app4_test_data = 0x44;

/* Brief StartupHook */
void StartupHook_OSAPP_A04(void)
{
    // PrintText("APP A04: \r\n");
    PrintText("    I'm in App A04 StartupHook\r\n");
    // PrintText("    Start up success!\r\n");
}

/* Brief ShutdownHook */
void ShutdownHook_OSAPP_A04(StatusType Error)
{
    // PrintText("APP A04: \r\n");
    PrintText("    I'm in APP A04 ShutdownHook\r\n");
    // PrintText("    Bye!\r\n");
}

/* Brief ErrorHook */
void ErrorHook_OSAPP_A04(StatusType Error)
{   
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
        //PrintText("[ErrorHook]: \r\n");
        break;
    }
}

#pragma section ISR_I105_SEC
ISR(I105)
{
    PrintText("isr 105 in osapp 04\r\n\0");
}

#pragma section ISR_I106_SEC
ISR(I106)
{
    PrintText("isr 106 in osapp 04\r\n\0");
}

#pragma section TASK_T104_SEC
TASK(T14)
{
    //PrintText("hello t14\r\n\0");
    TerminateTask();
}

#pragma section TASK_T105_SEC
TASK(T15)
{
    //PrintText("hello t15\r\n\0");
    TerminateTask();
}

#pragma section TASK_T106_SEC
TASK(T16)
{
    //PrintText("hello t16\r\n\0");
    TerminateTask();
}
