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
uint32 temp1 = 10;
TASK(T01)//rte client side: 發送request。(發起 request 的 runnable 應該放在同一個 task，不然不知道該在哪裡 activate 這些含有發起 requests 的 runnables 的 task)
{
    PrintText("T01 initiate a C/S op\r\n\0");

    //intra-partition
    //單核，不會有同時存取同一個 global variable 的問題
    if(rte_event_t01[InitEvent_1_t01]->rteevent){
        GetLock(&lock, lock_bit);
        rte_event_t01[InitEvent_1_t01]->rteevent--;
        ReleaseLock(&lock, lock_bit);

        Impl_uint16 result = RTE_RUNNABLE_Client1();//send request info (parameters & transaction handle).
        //在 async rte_call + non-blocking rte_result case：如果 "發出 request 的 client-side-task" 和 "處理 response info. 的 client-side-task" 是同一個 task
        //client runnable 的判斷句，下面應該要接 client response runnable 的判斷句，才符合 intra-partition 完成一個 c/s 溝通為優先。

        /*test*/
        if(result == 10U){
            PrintText("success\r\n\0");
        }
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
    /*rte server side: 接收 request_info，處理 request，發送 response_info*/
    //server side task 用 while 檢查 rte event：因為可能同時有多個不同 runnable 調用相同的 server-side runnable。
    while(rte_event_t02[OperationInvokedEvent_1_t02]->rteevent){
        GetLock(&lock, lock_bit);
        rte_event_t02[OperationInvokedEvent_1_t02]->rteevent--;
        ReleaseLock(&lock, lock_bit);
        
        uint16 client_id = rte_server_side_add();//check error, call transformer, enqueue request queue, do operation, send response
        
        switch (client_id){
            case 1: //client runnable 1 發起的 request
                //因為執行 server runnable 後還需要進行資料處理(調用 transformer、傳輸資料)，所以無法把 server-side 的 Rte event 存取包到 server runnable 內部調用的 api 裡面。
                GetLock(&lock, lock_bit);
                rte_event_t03[AsynchronousServerCallReturnsEvent_1_t03]->rteevent++;
                ReleaseLock(&lock, lock_bit);
                // ActivateTask(T02); //client runnable 1 處理 response info 的 task
                break;
            default:
                break;//parser error: doesn't know where is the client.
        }
    }
    while(rte_event_t02[OperationInvokedEvent_2_t02]->rteevent){
        GetLock(&lock, lock_bit);
        rte_event_t02[OperationInvokedEvent_2_t02]->rteevent--;
        ReleaseLock(&lock, lock_bit);

        uint16 client_id = rte_server_side_sub();
        
        // ResponseInfoType server_response = rte_client_side();//check error, call transformer, dequeue response queue
        // RTE_Enqueue(&RB_response_CR1, &server_response, sizeof(ResponseInfoType)); //RB_response_CR1: response Q of client_runnable_1 (Sync server call point configuration)
        // SetEvent(T01, event1);//unblock the corresponding client runnable

        switch (client_id){
            case 2: //client runnable 2 發起的 request
                GetLock(&lock, lock_bit);
                rte_event_t03[AsynchronousServerCallReturnsEvent_2_t03]->rteevent++;
                ReleaseLock(&lock, lock_bit);
                // ActivateTask(T02); //client runnable 2 處理 response info 的 task
                break;
            default:
                break;//parser error: doesn't know where is the client.
        }
    }
    
    /*client side: 接收和處理 response_info*/
    //intra-partition
    //不用 while 檢查 rte event：因為 AsynchronousServerCallReturnsEvent 是告訴"某一個" client 它的 response 好了。
    if(rte_event_t03[AsynchronousServerCallReturnsEvent_1_t03]->rteevent){
        GetLock(&lock, lock_bit);
        rte_event_t03[AsynchronousServerCallReturnsEvent_1_t03]->rteevent--;
        ReleaseLock(&lock, lock_bit);

        // ResponseInfoType server_response = rte_client_side();//check error, call transformer, dequeue response queue
        // RTE_Enqueue(&RB_response_CR1, &server_response, sizeof(ResponseInfoType)); //RB_response_CR1: response Q of client_runnable_1 (Sync server call point configuration)
        
        // SetEvent(T01, event1);//unblock the corresponding client runnable
    }

    TerminateTask();
}

#pragma section TASK_T003_SEC
TASK(T03)
{
    for(int i = 0; i <10000; i++){//inter-arival protection
        ;
    }
    TerminateTask();
}
