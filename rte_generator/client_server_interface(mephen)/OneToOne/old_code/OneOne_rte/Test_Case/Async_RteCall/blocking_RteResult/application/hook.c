#include "typedefine.h"
#include "scheduler.h"
#include "memprot.h"
#include "os.h"
#include "task.h"
#include "string_format_test.h" 
extern CoreIdType _CoreID;
extern int kernelDisableMPUCounter;

#pragma section GLOBAL_RAM_A

char my_prot_err_str_arr[32];

#pragma section default



extern int PrintText(char *TextArray);

/* Brief PreTaskHook */
void PreTaskHook(void)
{
    PrintText("I'm in PreTaskHook\r\n");
}

/* Brief PostTaskHook */
void PostTaskHook(void)
{
    PrintText("I'm in PostTaskHook\r\n");
}

/* Brief ErrorHook */
void ErrorHook(StatusType Error)
{   
    //DisableMPU();
    TaskType taskID;
    GetTaskID(&taskID);
    PrintText("System Error Hook:\r\n");
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
    //EnableMPU();
}

/* Brief StartupHook */
void StartupHook(void)
{
    PrintText("I'm in StartupHook\r\n");
}

/* Brief ShutdownHook */
void ShutdownHook(StatusType Error)
{
    PrintText("I'm in ShutdownHook\r\n");
}

/* SWS_Os_00542 */
int flagforPROTECTION_LOCKED=0;     //test code
ProtectionReturnType ProtectionHook(StatusType Error)
{   
    ProtectionReturnType retMsg = PRO_IGNORE;
      
    itoa_16_show_id(my_prot_err_str_arr, CURRENTTASK.currentID);
    switch (Error)
    {
    case E_OS_PROTECTION_ARRIVAL:
        PrintText(my_prot_err_str_arr);
        PrintText("I'm in inter-arrival error :((((\r\n\0");
        retMsg = PRO_IGNORE;
        break;
    case E_OS_PROTECTION_LOCKED:
        if(flagforPROTECTION_LOCKED==0){                    //test code
            PrintText("I'm in locking error :((((\r\n\0");  //test code
            flagforPROTECTION_LOCKED =1;                    //test code
        }
        retMsg = PRO_IGNORE;
        break;
    case E_OS_PROTECTION_TIME:
        PrintText(my_prot_err_str_arr);
        PrintText("I'm in Executing error :((((\r\n\0");
        retMsg = PRO_TERMINATETASKISR;
        break;
    case E_OS_PROTECTION_MEMORY:
        PrintText(my_prot_err_str_arr);
        PrintText("Memory fault!! \r\n\0");
        retMsg = PRO_TERMINATEAPPL; 
        break;
    case E_OS_STACKFAULT:
        PrintText(my_prot_err_str_arr);
        retMsg = PRO_TERMINATETASKISR;
        break;
    default:
        break;
    }

    return retMsg;
}
