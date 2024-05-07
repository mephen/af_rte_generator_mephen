//App1.c
//-------------------------------------
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
#include "Rte_Event_Cfg.h"
#include "Transformer_stub.h"
#include "Rte_Cs_Data_Management.h"
#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

uint8 lock = 0;
uint8 lock_bit = 1;

uint16 rte_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;

    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core0, &len_args, sizeof(uint16));
    uint16 para_arr[len_args];
    uint16 transformed_para_arr[len_args];
    for(int i = 0; i < len_args; i++){
        RTE_Dequeue(&RB_requestInfo_core0, &para_arr[i], sizeof(Impl_uint16));
    }
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.sequence_counter, sizeof(uint16));

//App2.c
//-------------------------------------
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
#include "Rte_Event_Cfg.h"
#include "Transformer_stub.h"
#include "Rte_Cs_Data_Management.h"
#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

uint8 lock = 0;
uint8 lock_bit = 1;

uint16 rte_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;

    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core1, &len_args, sizeof(uint16));
    uint16 para_arr[len_args];
    uint16 transformed_para_arr[len_args];
    for(int i = 0; i < len_args; i++){
        RTE_Dequeue(&RB_requestInfo_core1, &para_arr[i], sizeof(Impl_uint16));
    }
    RTE_Dequeue(&RB_requestInfo_core1, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core1, &transaction_handle.sequence_counter, sizeof(uint16));
