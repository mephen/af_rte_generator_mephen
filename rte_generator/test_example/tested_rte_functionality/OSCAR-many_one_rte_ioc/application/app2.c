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
#include "application.h"
#include "trustedFunc_Cfg.h"
#include "Controller2/Rte_Controller2.h"
#include "Observation/Rte_Observation.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

/************* OSAPP_A02 *****************/
#pragma section OSAPP_A02_SEC

int app2_test_data = 0x22;

/* Brief StartupHook */
void StartupHook_OSAPP_A02(void)
{
    // PrintText("APP A02: \r\n");
    PrintText("    I'm in App A02 StartupHook\r\n");
    // PrintText("    Start up success!\r\n");
}

/* Brief ShutdownHook */
void ShutdownHook_OSAPP_A02(StatusType Error)
{
    // PrintText("APP A02: \r\n");
    PrintText("    I'm in APP A02 ShutdownHook\r\n");
    // PrintText("    Bye!\r\n");
}

/* Brief ErrorHook */
void ErrorHook_OSAPP_A02(StatusType Error)
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
        PrintText("[ErrorHook]: \r\n");
        break;
    }
}

void TRUSTED_TF_YUURI( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF YUURI\r\n\0");
}
void TRUSTED_TF_HITORIE( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF HITORIE\r\n\0");
}

#pragma section ISR_I101_SEC
ISR(I101)
{
    PrintText("isr 101 in osapp 02\r\n\0");
}

#pragma section ISR_I102_SEC
ISR(I102)
{
    PrintText("isr 102 in osapp 02\r\n\0");
}

#pragma section ISR_I103_SEC
ISR(I103)
{
    PrintText("isr 103 in osapp 02\r\n\0");
}

#pragma section ISR_I104_SEC
ISR(I104)
{
    PrintText("isr 104 in osapp 02\r\n\0");
}

#pragma section LOCAL_RAM_PE1
uint16 local = 100;

#pragma section TASK_T101_SEC
TASK(T11)
{
    //PrintText("hello t11\r\n\0");
    for(int i = 0; i < 1000;i++){
    }
    RTE_RUNNABLE_ReTxAcc2();
    RTE_RUNNABLE_ReTxTemp2();
    RTE_RUNNABLE_ReRxAcc();
    RTE_RUNNABLE_ReRxTemp();
    TerminateTask();
}

#pragma section TASK_T102_SEC
TASK(T12)
{
    PrintText("hello t12\r\n\0");
    
    TerminateTask();
}

#pragma section TASK_T103_SEC
TASK(T13)
{
    PrintText("hello t13\r\n\0");
    TerminateTask();
}