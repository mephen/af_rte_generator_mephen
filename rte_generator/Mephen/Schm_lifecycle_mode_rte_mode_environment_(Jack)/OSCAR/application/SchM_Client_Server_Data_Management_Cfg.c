#include "SchM_Client_Server_Data_Management_Cfg.h"

/*****************************************************************************/
/*for:
1. server_side_fn.
2. initEv & async_return_Ev case of for-loop event_check_fn. in os-task-body
*/

#include "SchM.h"
#include "Bsw_Event_Cfg.h"



/*****************************************************************************/
/*per pair of a client_runnable and a client_response_runnable*/

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

