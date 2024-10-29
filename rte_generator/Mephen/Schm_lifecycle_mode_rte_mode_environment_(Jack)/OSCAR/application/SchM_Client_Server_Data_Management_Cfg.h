#ifndef SCHM_CLIENT_SERVER_DATA_MANAGEMENT_CFG_H
#define SCHM_CLIENT_SERVER_DATA_MANAGEMENT_CFG_H

#include "ring_buffer.h"
#include "Rte_Type.h"

//per core: Rte internal buffer of intra-parition communication
//for application and client_runnable
extern RingBuffer RB_requestInfo_core0; //client -> server intra-partition communication (store Request information: parameters & sequence_counter)
extern RingBuffer RB_responseInfo_core0; //server -> client intra-partition communication (store response information: ResponseInfoType)
extern RingBuffer RB_requestInfo_core1;
extern RingBuffer RB_responseInfo_core1;

//per core: transformer buffer for transformer use
//for application and client_runnable
//RTE should provide transformer buffer
extern RingBuffer RB_transformer_core0;
extern RingBuffer RB_transformer_core1;

//per pair of a client_runnable and a client_response_runnable

#endif
