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
#include "ioc.h"
#include "lock.h"
#include "client_SWC/Rte_Client_Runnable.h"
#include "client_SWC/Rte_Client_ResponseRunnable.h"
#include "server_SWC/Rte_Server_Runnable.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

uint8 lock_buffer_x;
uint8 lock_bit_x;
extern Std_ReturnType errorFlag_Rte_Call_Port1_InterPartitionSynchronousAdd;
extern Rte_call_metaData Rte_Call_Port1_InterPartitionSynchronousAdd_metaData;

/*buffer*/
//shared by all the client response runnables(Asyn case), client runnables(Sync case).
extern RingBuffer Rte_response_RB_ioc;
//in Async case, this can be used to help client response runnable
Std_ReturnType previous_RteCall_returnValue_buffer[10];
RingBuffer previous_RteCall_returnValue_RB = {
    previous_RteCall_returnValue_buffer,
    0,
    0,
    10,
    0
};
//for RTE to ensure the order of client requests on the server side
Rte_Cs_TransactionHandleType Rte_request_buffer[10];
RingBuffer Rte_request_RB = {
    Rte_request_buffer,
    0,
    0,
    10,
    0
};

Impl_uint16 transformer_buffer_ioc[20];
RingBuffer transformer_RB_ioc = {
    transformer_buffer_ioc,
    0,//point to oldest data
    0,
    20,
    0
};

int check_RTE_E_TRANSFORMER_LIMIT(RingBuffer* rb, Std_ReturnType* errorFlag){
    if(IsFull(rb)){
        *errorFlag = RTE_E_TRANSFORMER_LIMIT;
        return 1;
    }
    return 0;
}

int check_RTE_TRANSFORMER_ERROR(RingBuffer* rb, uint8 transformer_error_code, Std_ReturnType* errorFlag){
    int true_false = 0;
    //in the priority rule of Rte_call: RTE_E_TRANSFORMER_LIMIT > RTE_E_HARD_TRANSFORMER_ERROR > RTE_E_SOFT_TRANSFORMER_ERROR
    if(*errorFlag != RTE_E_TRANSFORMER_LIMIT){
        if(transformer_error_code >= 0x01 && transformer_error_code <= 0x7F){
            //soft transformer error won't cause immediate return
            *errorFlag = RTE_E_SOFT_TRANSFORMER_ERROR;
            true_false = 1;
        }else if(transformer_error_code >= 0x80 && transformer_error_code <= 0xFF){
            *errorFlag = RTE_E_HARD_TRANSFORMER_ERROR;
            true_false = 1;
        }
    }
    return true_false;
}

void iocCase_client_side(){
    uint8 server_response;
    StatusType ioc_error_code = IocReceive_aa(&server_response);
    Rte_Cs_TransactionHandleType transaction_handle; //for transformer stub.

    /*transform received data, and fetch parameters form RTE transformer buffer*/
    check_RTE_E_TRANSFORMER_LIMIT(&transformer_RB_ioc, &errorFlag_Rte_Call_Port1_InterPartitionSynchronousAdd);
    uint8 transformer_error_code = Xfrm_Inv_transformer_2_ioc(&transaction_handle, &transformer_RB_ioc, &transformer_RB_ioc.currentSize, server_response);
    check_RTE_TRANSFORMER_ERROR(&transformer_RB_ioc, transformer_error_code, &errorFlag_Rte_Call_Port1_InterPartitionSynchronousAdd);
    Impl_uint16 server_response_transformed;
    RTE_Dequeue(&transformer_RB_ioc, (void*)&server_response_transformed, sizeof(Impl_uint16));

    //put server response in RTE internal buffer, and Rte_result will fetch the server response from the buffer.
    RTE_Enqueue(&Rte_response_RB_ioc, (void*)&server_response_transformed, sizeof(Impl_uint16));
    
    return;
}
/************* OSAPP_A01 *****************/
#pragma section OSAPP_A03_SEC
uint16 App_A03_test_data_1 = 1;
#pragma section OSAPP_A01_SEC

int app1_test_data = 2;
uint16 App_test_data_2 = 2;

/* Brief StartupHook */
void StartupHook_OSAPP_app_lion(void)
{
    // Memory fault test
    // App_A03_test_data_1 = 0x1234;

    // PrintText("APP lion: \r\n");
    PrintText("    I'm in app lion StartupHook\r\n");
    // PrintText("    Start up success!\r\n");
}

/* Brief ShutdownHook */
void ShutdownHook_OSAPP_app_lion(StatusType Error)
{
    // Memory fault test
    // App_A03_test_data_1 = 0x1234;
    
    // PrintText("APP lion: \r\n");
    PrintText("    I'm in app lion ShutdownHook\r\n");
    // PrintText("    Bye!\r\n");
}

/* Brief ErrorHook */
void ErrorHook_OSAPP_app_lion(StatusType Error)
{   
    
    PrintText("App lion Error Hook:\r\n");
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
        PrintText("[App lion ErrorHook]: \r\n");
        break;
    }
}

void TRUSTED_TF_AIMER( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF AIMER\r\n\0");
    uint32 temp = 0;
    uint32* tt = &temp;
    for(uint32 i=0; i<40000;i++){
        temp = temp + 1;
    }
    // CallTrustedFunction(TF_IKURA, &temp);
}
void TRUSTED_TF_IKURA( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF IKURA\r\n\0");
    uint32 temp = 0;
    // uint32* tt = &temp;
    ActivateTask(T03);
    CallTrustedFunction(TF_YORUSHIKA, &temp);
}
void TRUSTED_TF_YORUSHIKA( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF YORUSHIKA\r\n\0");
}

#pragma section ISR_I001_SEC

ISR(I001)
{
    PrintText("isr1 001 in osapp 01\r\n\0");
}

#pragma section ISR_I002_SEC 
uint32 temp_I002 = 10;
ISR(I002)
{
    PrintText("isr2 002 in osapp 01\r\n\0");
}

#pragma section ISR_I003_SEC
ISR(I003)
{
    PrintText("isr2 003 in osapp 01\r\n\0");
}

#pragma section ISR_I004_SEC
ISR(I004)
{
    PrintText("isr1 004 in osapp 01\r\n\0");
}
#pragma section OSAPP_A03_SEC
uint16 testforvil = 5;


#pragma section TASK_T001_SEC
TASK(T01)
{
    // GetLock(lock_buffer_x, lock_bit_x);
    // uint16 data = 6;
    // StatusType error = IocSend_aa(data);
    // uint16 data2 = 3;
    // error = IocSend_aa(data2);
    // ReleaseLock(lock_buffer_x, lock_bit_x);
    // ActivateTask(T11);

    PrintText("T01 initiate a C/S op\r\n\0");
    RTE_Enqueue(&Rte_request_RB, (void*)&Rte_Call_Port1_InterPartitionSynchronousAdd_metaData.transaction_handle, sizeof(Rte_Cs_TransactionHandleType));
    Impl_uint16 response = Rte_Client_Runnable_1();
    if(response == 10U){
        PrintText("success\r\n\0");
    }
    TerminateTask();
}

#pragma section TASK_T002_SEC
TASK(T02)
{
    for(int i = 0; i <10000; i++){
        ;
    }
    iocCase_client_side();
    PrintText("T02 set event to wake up T01\r\n\0");
    SetEvent(T01, event1);
    TerminateTask();
}

#pragma section TASK_T003_SEC
TASK(T03)
{
    //for timeout mechanism
    //in the priority rule of rte_call, the priority of RTE_E_TIMEOUT is lower than the hard transformer error.
    if(errorFlag_Rte_Call_Port1_InterPartitionSynchronousAdd != RTE_E_HARD_TRANSFORMER_ERROR){
        errorFlag_Rte_Call_Port1_InterPartitionSynchronousAdd = RTE_E_TIMEOUT;
    }
    TerminateTask();
}
