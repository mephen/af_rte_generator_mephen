#include "Rte_Cs_Data_Management.h"
/*****************************************************************************/
/*for:
1. server_side_fn.
2. initEv & async_return_Ev case of for-loop event_check_fn. in os-task-body
*/
#include "Rte_Event_Cfg.h"
#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"

Rte_Cs_metaData rte_cs_metaData_arr[3] = {
//async+non_blocking
    {.CR_RVuint16 = Client_1, .CRR_RVuint16 = Client_Response_1, .SR_RVuint16 = Server1_SR1, .client_id = 1, .RB_request_ptr = &RB_request_Server1_SR1, .RB_response_ptr = &RB_response_Client_Response_1, .async_return_ev = &AsynchronousServerCallReturnsEvent_1, .SR_task = 0x00000002, .CRR_task = 0x00000002, .rte_call_property = async, .rte_result_property = non_blocking},
    {.CR_RVuint16 = Client_2, .CRR_RVuint16 = Client_Response_2, .SR_RVuint16 = Server1_SR1, .client_id = 2, .RB_request_ptr = &RB_request_Server1_SR1, .RB_response_ptr = &RB_response_Client_Response_2, .async_return_ev = &AsynchronousServerCallReturnsEvent_2, .SR_task = 0x00000002, .CRR_task = 0x00000002, .rte_call_property = async, .rte_result_property = non_blocking},
    {.CR_RVuint16 = Client_3, .CRR_RVuint16 = Client_Response_3, .SR_RVuint16 = Server2_SR1, .client_id = 3, .RB_request_ptr = &RB_request_Server2_SR1, .RB_response_ptr = &RB_response_Client_Response_3, .async_return_ev = &AsynchronousServerCallReturnsEvent_3, .SR_task = 0x00010001, .CRR_task = 0x00000002, .rte_call_property = async, .rte_result_property = non_blocking},
};

/*****************************************************************************/
/*per pair of a client_runnable and a client_response_runnable*/
Std_ReturnType rteCall_returnValue_buffer_Client_1[10];
RingBuffer RB_returnValue_Client_1 = {
    rteCall_returnValue_buffer_Client_1,
    0,
    0,
    10,
    0
};

Std_ReturnType rteCall_returnValue_buffer_Client_2[10];
RingBuffer RB_returnValue_Client_2 = {
    rteCall_returnValue_buffer_Client_2,
    0,
    0,
    10,
    0
};

Std_ReturnType rteCall_returnValue_buffer_Client_3[10];
RingBuffer RB_returnValue_Client_3 = {
    rteCall_returnValue_buffer_Client_3,
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
RingBuffer RB_transformer_core1 = { //for each core, there is a transformer buffer
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