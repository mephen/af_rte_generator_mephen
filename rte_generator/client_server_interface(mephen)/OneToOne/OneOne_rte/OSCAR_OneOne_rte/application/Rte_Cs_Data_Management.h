#ifndef RTE_DATA_MANAGEMENT_H
#define RTE_DATA_MANAGEMENT_H

#include "ringbuffer.h"
#include "Rte_Type.h"

//per core: Rte internal buffer of intra-parition communication
//for application and client_runnable
extern RingBuffer RB_requestInfo_core0; //client -> server intra-partition communication (store Request information: parameters & sequence_counter)
extern RingBuffer RB_responseInfo_core0; //server -> client intra-partition communication (store response information: ResponseInfoType)

//per core: transformer buffer for transformer use
//for application and client_runnable
//RTE should provide transformer buffer
extern RingBuffer RB_transformer_core0;
extern RingBuffer RB_transformer_core1;

//per pair of a client_runnable and a client_response_runnable
extern RingBuffer RB_returnValue_CR1; //for RTE_RUNNABLE_ClientResponse1 to get the return_value of RTE_RUNNABLE_Client1
extern RingBuffer RB_returnValue_CR2; //for RTE_RUNNABLE_ClientResponse2 to get the return_value of RTE_RUNNABLE_Client2
extern RingBuffer RB_returnValue_CR3; //for RTE_RUNNABLE_ClientResponse3 to get the return_value of RTE_RUNNABLE_Client3
#endif // RTE_DATA_MANAGEMENT_H