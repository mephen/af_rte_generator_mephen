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
#include "client_SWC/Rte_Client_Response_Runnable.h"
#include "server_SWC/Rte_Server_Runnable.h"
#include "Rte_Event_Cfg.h"
#include "Transformer_stub.h"
#include "Rte_Cs_Data_Management.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

uint8 lock = 0;
uint8 lock_bit = 1;

void rte_callback(){
    signal AsynchronousServerCallReturnsEvent_id = -1;
    com_receiveSignal(signal_2, &AsynchronousServerCallReturnsEvent_id);
    switch(AsynchronousServerCallReturnsEvent_id){
        case 4:
            GetLock(lock, lock_bit);
            rte_event_t03[AsynchronousServerCallReturnsEvent_4_t03]->rteevent++; 
            ReleaseLock(lock, lock_bit);
            break;
        default:
            PrintText("this event doesn't exist\r\n");
            break;
    }
    ActivateTask(T02);
    return;
}

uint16 rte_server_side_add(){
    uint16 para1, para2, transformed_para_1, transformed_para_2, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;

    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core0, &para1, sizeof(Impl_uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &para2, sizeof(Impl_uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.sequence_counter, sizeof(uint16));

    //transforme data into DataType for server_operation
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para1);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_1, sizeof(uint16));

    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para2);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_2, sizeof(uint16));
    
    //在 server side enqueue request queue
    RTE_Enqueue(&RB_request_SR1, &transformed_para_1, sizeof(uint16));
    RTE_Enqueue(&RB_request_SR1, &transformed_para_2, sizeof(uint16));
    Impl_uint16 response = RTE_RUNNABLE_Server1();//do "add" operation, add operation 會自己去 request_queue 裡面拿參數。
    
    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType response_info = {
        RTE_E_OK,
        transaction_handle,
        transformed_response
    };
    RTE_Enqueue(&RB_responseInfo_core0, &response_info, sizeof(ResponseInfoType));//via rte_internal_buffer, store response information (response & sequence_counter)
    return transaction_handle.client_id;
}

uint16 rte_server_side_sub(){
    uint16 para1, para2, transformed_para_1, transformed_para_2, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;
    Std_ReturnType bsw_error = RTE_E_OK;
    
    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core0, &para1, sizeof(Impl_uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &para2, sizeof(Impl_uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.sequence_counter, sizeof(uint16));

    //transforme data into DataType for server_operation
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para1);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_1, sizeof(uint16));

    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para2);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_2, sizeof(uint16));
    
    RTE_Enqueue(&RB_request_SR2, &transformed_para_1, sizeof(uint16));//在 server side enqueue request queue
    RTE_Enqueue(&RB_request_SR2, &transformed_para_2, sizeof(uint16));
    Impl_uint16 response = RTE_RUNNABLE_Server2();//do "sub" operation, sub operation 會自己去 request_queue 裡面拿參數。
    
    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType response_info = {
        RTE_E_OK,
        transaction_handle,
        transformed_response
    };

    RTE_Enqueue(&RB_responseInfo_core0, &response_info, sizeof(ResponseInfoType));//store response information (response & sequence_counter)
    return transaction_handle.client_id;
}

ResponseInfoType rte_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    RTE_Dequeue(&RB_responseInfo_core0, &response_info, sizeof(ResponseInfoType));
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

ResponseInfoType ioc_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    IocReceive_Q1(&response_info.transaction_handle.client_id);
    IocReceive_Q1(&response_info.transaction_handle.sequence_counter);
    IocReceive_Q1(&response_info.response);
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

ResponseInfoType com_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    com_receiveSignal(signal_7, &response_info);
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
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
    uint32* tt = &temp;
    ActivateTask(T03);
    CallTrustedFunction(TF_YORUSHIKA, &temp);
}
void TRUSTED_TF_YORUSHIKA( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF YORUSHIKA\r\n\0");
}

#pragma section ISR_I001_SEC

ISR(I001)//com 收到資料後，觸發 isr
{
    PrintText("isr1 001 in osapp 01\r\n\0");
    rte_callback();
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
uint32 temp1 = 10;
TASK(T01)//client side: 發送request。(發起 request 的 runnable 應該放在同一個 task，不然不知道該在哪裡 activate 這些含有發起 requests 的 runnables 的 task)
{
    PrintText("T01 initiate a C/S op\r\n\0");

    //inter-ECU
    //不可能在雙核上調用相同的 runnaable，因為一個 SWC 的 runnables 只能 map to "同一個core的同一個 os app (LSA spec.)"
    if(rte_event_t01[InitEvent_4_t01]->rteevent){
        GetLock(&lock, lock_bit);
        rte_event_t01[InitEvent_4_t01]->rteevent--;
        ReleaseLock(&lock, lock_bit);

        RTE_RUNNABLE_Client4();
    }

    TerminateTask();
}

#pragma section TASK_T002_SEC
int T02_Global = 0;
TASK(T02)
{
    for(int i = 0; i <10000; i++){//inter-arival protection
        ;
    }
    /*client side: 接收和處理 response_info*/
    //inter-partition
    if(rte_event_t03[AsynchronousServerCallReturnsEvent_4_t03]->rteevent){
        GetLock(&lock, lock_bit);
        rte_event_t03[AsynchronousServerCallReturnsEvent_4_t03]->rteevent--;
        ReleaseLock(&lock, lock_bit);

        ResponseInfoType server_response = com_client_side();
        RTE_Enqueue(&RB_response_CRR4, &server_response, sizeof(ResponseInfoType));
        uint16 result = RTE_RUNNABLE_ClientResponse4();

        /*test*/
        if(result == 1U){
            PrintText("success\r\n\0");
        }
    }

    TerminateTask();
}

#pragma section TASK_T003_SEC
TASK(T03)//
{
    for(int i = 0; i <10000; i++){//inter-arival protection
        ;
    }
    TerminateTask();
}
