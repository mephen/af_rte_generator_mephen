#include "Rte_Cs_Data_Management.h"
/*****************************************************************************/
/*for:
1. server_side_fn.
2. initEv & async_return_Ev case of for-loop event_check_fn. in os-task-body
*/
#include "client_SWC/Rte_Client_Runnable.h"
#include "server_SWC/Rte_Server_Runnable.h"
#include "client_SWC/Rte_Client_Response_Runnable.h"
#include "Rte_Event_Cfg.h"
Rte_Cs_metaData rte_cs_metaData_arr[2] = {
    //async + non_blocking
    {.CR_RVuint16 = RTE_RUNNABLE_Client1, .CRR_RVuint16 = RTE_RUNNABLE_ClientResponse1, .SR_RVuint16 = RTE_RUNNABLE_Server1, .client_id = 1, .RB_request_ptr = &RB_request_SR1, .RB_response_ptr = &RB_response_CRR1, .async_return_ev = &AsynchronousServerCallReturnsEvent_1, .rte_call_property = async, .rte_result_property = non_blocking},
    {.CR_RVuint16 = RTE_RUNNABLE_Client2, .CRR_RVuint16 = RTE_RUNNABLE_ClientResponse2, .SR_RVuint16 = RTE_RUNNABLE_Server1, .client_id = 2, .RB_request_ptr = &RB_request_SR1, .RB_response_ptr = &RB_response_CRR2, .async_return_ev = &AsynchronousServerCallReturnsEvent_2, .rte_call_property = async, .rte_result_property = non_blocking},
    //async + blocking
    // {.CR_RVuint16 = RTE_RUNNABLE_Client1, .CRR_RVuint16 = RTE_RUNNABLE_ClientResponse1, .SR_RVuint16 = RTE_RUNNABLE_Server1, .client_id = 1, .RB_request_ptr = &RB_request_SR1, .RB_response_ptr = &RB_response_CRR1, .async_return_ev = &AsynchronousServerCallReturnsEvent_1, .rte_call_property = async, .rte_result_property = blocking},
    // {.CR_RVuint16 = RTE_RUNNABLE_Client2, .CRR_RVuint16 = RTE_RUNNABLE_ClientResponse2, .SR_RVuint16 = RTE_RUNNABLE_Server1, .client_id = 2, .RB_request_ptr = &RB_request_SR1, .RB_response_ptr = &RB_response_CRR2, .async_return_ev = &AsynchronousServerCallReturnsEvent_2, .rte_call_property = async, .rte_result_property = blocking},
    //sync + not_used
    // {.CR_RVuint16 = RTE_RUNNABLE_Client1, .SR_RVuint16 = RTE_RUNNABLE_Server1, .client_id = 1, .RB_request_ptr = &RB_request_SR1, .RB_response_ptr = &RB_response_CR1, .rte_call_property = sync, .rte_result_property = not_used},
    // {.CR_RVuint16 = RTE_RUNNABLE_Client2, .SR_RVuint16 = RTE_RUNNABLE_Server1, .client_id = 2, .RB_request_ptr = &RB_request_SR1, .RB_response_ptr = &RB_response_CR2, .rte_call_property = sync, .rte_result_property = not_used},
};

/*****************************************************************************/
/*per pair of a client_runnable and a client_response_runnable*/
Std_ReturnType rteCall_returnValue_buffer_CR1[10];
RingBuffer RB_returnValue_CR1 = {
    rteCall_returnValue_buffer_CR1,
    0,
    0,
    10,
    0
};

Std_ReturnType rteCall_returnValue_buffer_CR2[10];
RingBuffer RB_returnValue_CR2 = {
    rteCall_returnValue_buffer_CR2,
    0,
    0,
    10,
    0
};

Std_ReturnType rteCall_returnValue_buffer_CR3[10];
RingBuffer RB_returnValue_CR3 = {
    rteCall_returnValue_buffer_CR3,
    0,
    0,
    10,
    0
};


/*****************************************************************************/
/*core0 c/s data structure*/
uint16 transformer_buffer_core0[20];
RingBuffer RB_transformer_core0 = { //for each core, there is a transformer buffer
    transformer_buffer_core0,
    0,
    0,
    20,
    0
};

//request_buffer & response buffer are internal buffers for intra-partition comm. on a core (core0)
uint16 requestInfo_buffer_core0[50];
RingBuffer RB_requestInfo_core0 = {
    requestInfo_buffer_core0,
    0,
    0,
    50,
    0
};

ResponseInfoType responseInfo_buffer_core0[50];
RingBuffer RB_responseInfo_core0 = {
    responseInfo_buffer_core0,
    0,
    0,
    50,
    0
};

/*****************************************************************************/
/*core1 c/s data structure*/
uint16 transformer_buffer_core1[20];
RingBuffer RB_transformer_core1 = {
    transformer_buffer_core1,
    0,
    0,
    20,
    0
};

//request_buffer & response buffer are internal buffers for intra-partition comm. on a core (core1)
uint16 requestInfo_buffer_core1[50];
RingBuffer RB_requestInfo_core1 = {
    requestInfo_buffer_core1,
    0,
    0,
    50,
    0
};

ResponseInfoType responseInfo_buffer_core1[50];
RingBuffer RB_responseInfo_core1 = {
    responseInfo_buffer_core1,
    0,
    0,
    50,
    0
};

