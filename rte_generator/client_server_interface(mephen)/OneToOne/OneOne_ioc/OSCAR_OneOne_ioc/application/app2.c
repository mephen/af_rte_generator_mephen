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
#include "ioc.h"
#include "lock.h"
#include "client_SWC/Rte_Client_Runnable.h"
#include "client_SWC/Rte_Client_ResponseRunnable.h"
#include "server_SWC/Rte_Server_Runnable.h"


extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

extern Std_ReturnType errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_Blocking;

/*buffer*/
extern RingBuffer Rte_request_RB;
Impl_uint16 transformer_buffer_ioc_2[20];
RingBuffer transformer_RB_ioc_2 = {
    transformer_buffer_ioc_2,
    0,//point to oldest data
    0,
    20,
    0
};

extern int check_RTE_E_TRANSFORMER_LIMIT(RingBuffer* rb, Std_ReturnType* errorFlag);
extern int check_RTE_TRANSFORMER_ERROR(RingBuffer* rb, uint8 transformer_error_code, Std_ReturnType* errorFlag);

void iocCase_server_side(){
    uint8 data_1;
    uint8 data_2;
    StatusType ioc_error_code = IocReceive_aa(&data_1);
    ioc_error_code = IocReceive_aa(&data_2);
    
    Rte_Cs_TransactionHandleType transaction_handle; //for transformer stub.
    /*transform received data, and fetch parameters form RTE buffer*/
    check_RTE_E_TRANSFORMER_LIMIT(&transformer_RB_ioc_2, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_Blocking);
    uint8 transformer_error_code = Xfrm_Inv_transformer_ioc(&transaction_handle, &transformer_RB_ioc_2, &transformer_RB_ioc_2.currentSize, data_1);
    check_RTE_TRANSFORMER_ERROR(&transformer_RB_ioc_2, transformer_error_code, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_Blocking);
    Impl_uint16 data_1_transformed;
    RTE_Dequeue(&transformer_RB_ioc_2, (void*)&data_1_transformed, sizeof(Impl_uint16));

    check_RTE_E_TRANSFORMER_LIMIT(&transformer_RB_ioc_2, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_Blocking);
    transformer_error_code = Xfrm_Inv_transformer_ioc(&transaction_handle, &transformer_RB_ioc_2, &transformer_RB_ioc_2.currentSize, data_2);
    check_RTE_TRANSFORMER_ERROR(&transformer_RB_ioc_2, transformer_error_code, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_Blocking);
    Impl_uint16 data_2_transformed;
    RTE_Dequeue(&transformer_RB_ioc_2, (void*)&data_2_transformed, sizeof(Impl_uint16));

    /*call server runnable*/
    Impl_uint16 server_response = Rte_Server_Runnable(data_1_transformed, data_2_transformed);

    /*transform server response*/
    check_RTE_E_TRANSFORMER_LIMIT(&transformer_RB_ioc_2, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_Blocking);
    transformer_error_code = Xfrm_transformer_2_ioc(&transaction_handle, &transformer_RB_ioc_2, &transformer_RB_ioc_2.currentSize, server_response);
    check_RTE_TRANSFORMER_ERROR(&transformer_RB_ioc_2, transformer_error_code, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_Blocking);
    uint8 server_response_transformed;
    RTE_Dequeue(&transformer_RB_ioc_2, (void*)&server_response_transformed, sizeof(uint8));

    ioc_error_code = IocSend_aa((int)server_response_transformed);
    return;
}
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
    for(int i = 0; i <10000; i++){
        ;
    }
    
    PrintText("T11 do things after T01 initiate a C/S op\r\n\0");
    Rte_Cs_TransactionHandleType transaction_handle;
    RTE_Dequeue(&Rte_request_RB, &transaction_handle, sizeof(Rte_Cs_TransactionHandleType));
    switch(transaction_handle.communication_type){
        case 1: //com
            break;
        case 2: //ioc
            iocCase_server_side();
            break;
        case 3: //rte
            break;
        default:
            PrintText("undefined communication type\r\n\0");
            break;
    }

    ActivateTask(T02);//activate client side task
    TerminateTask();
}

#pragma section TASK_T102_SEC
TASK(T12)
{
}

#pragma section TASK_T103_SEC
TASK(T13)
{
}