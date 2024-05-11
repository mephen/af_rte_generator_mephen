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
#include "client_SWC/Rte_Client_Response_Runnable.h"
#include "server_SWC/Rte_Server_Runnable.h"
#include "Rte_Event_Cfg.h"
#include "Transformer_stub.h"
#include "Rte_Cs_Data_Management.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

static uint8 lock = 0;
static uint8 lock_bit = 1;

static uint16 rte_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Impl_uint16 response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    
    uint16 para_arr[10];
    uint16 transformed_para_arr[10];
    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core1, &len_args, sizeof(uint16));
    for(int i = 0; i < len_args; i++){
        RTE_Dequeue(&RB_requestInfo_core1, &para_arr[i], sizeof(Impl_uint16));
    }
    RTE_Dequeue(&RB_requestInfo_core1, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core1, &transaction_handle.sequence_counter, sizeof(uint16));
    
    //transforme data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core1, (void*)&transformed_para_arr[i], sizeof(uint16));
    }
    //在 server side enqueue request queue
    for(int i = 0; i < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); i++){
        if(Server_Runnable == rte_cs_metaData_arr[i].SR_RVuint16){
            for(int j = 0; j < len_args; j++){
                RTE_Enqueue(rte_cs_metaData_arr[i].RB_request_ptr, &transformed_para_arr[j], sizeof(uint16));
            }
            response = rte_cs_metaData_arr[i].SR_RVuint16();//do server operation, server runnable 會自己去 request_queue 裡面拿參數。
            break;
        }
    }

    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType response_info = {
        RTE_E_OK,
        transaction_handle,
        transformed_response
    };
    RTE_Enqueue(&RB_responseInfo_core1, &response_info, sizeof(ResponseInfoType));//via rte_internal_buffer, store response information (response & sequence_counter)
    return transaction_handle.client_id;
}

static ResponseInfoType rte_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    RTE_Dequeue(&RB_responseInfo_core1, &response_info, sizeof(ResponseInfoType));
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

static uint16 ioc_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Impl_uint16 response;
    Rte_Cs_TransactionHandleType transaction_handle;
    Std_ReturnType bsw_error = RTE_E_OK;
    
    uint16 para_arr[10];
    uint16 transformed_para_arr[10];
    //get request information (parameters & sequence_counter).
    IocReceive_Q1(&len_args);
    for(int i = 0; i < len_args; i++){
        IocReceive_Q1(&para_arr[i]);
    }
    IocReceive_Q1(&transaction_handle.client_id);
    IocReceive_Q1(&transaction_handle.sequence_counter);
    
    //transforme data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core1, (void*)&transformed_para_arr[i], sizeof(uint16));
    }
    //在 server side enqueue request queue
    for(int i = 0; i < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); i++){
        if(Server_Runnable == rte_cs_metaData_arr[i].SR_RVuint16){
            for(int j = 0; j < len_args; j++){
                RTE_Enqueue(rte_cs_metaData_arr[i].RB_request_ptr, &transformed_para_arr[j], sizeof(uint16));
            }
            response = rte_cs_metaData_arr[i].SR_RVuint16();//do server operation, server runnable 會自己去 request_queue 裡面拿參數。
            break;
        }
    }

    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    //send response information (response & sequence_counter).
    IocSend_Q1_SND1(transaction_handle.client_id);//for server_response.transaction_handle.client_id
    IocSend_Q1_SND1(transaction_handle.sequence_counter);//for server_response.transaction_handle.sequence_counter
    IocSend_Q1_SND1(transformed_response);//for server_response.response
    return transaction_handle.client_id;
}

static ResponseInfoType ioc_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    IocReceive_Q1(&response_info.transaction_handle.client_id);
    IocReceive_Q1(&response_info.transaction_handle.sequence_counter);
    IocReceive_Q1(&response_info.response);
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
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
TASK(T11)//ioc server side: 接收request，處理request，發送response
{
    for(int i = 0; i <10000; i++){//inter-arival protection
        ;
    }

  

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