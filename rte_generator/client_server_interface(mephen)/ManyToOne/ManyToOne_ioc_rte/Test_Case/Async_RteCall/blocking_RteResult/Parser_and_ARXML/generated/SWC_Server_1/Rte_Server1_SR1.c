//VFB interface(api) & Runnable Implementation
//----------------------------------------------------------------
#define RTE_Server1_SR1_C
#include "Rte_SWC_Server_1.h"
#include "../ringbuffer.h"
#include "../Transformer_stub.h"
#include "../Rte_Cs_Data_Management.h"
#include "../Rte_Event_Cfg.h"
#include "../../kernel/alarm.h"
#include "../../kernel/event.h"
#include "../../device/lock.h"
#include "../../OS_Configure/inc/event_Cfg.h"
#include "../../kernel/task.h"

Impl_uint16 request_buffer_Server1_SR1[20];
RingBuffer RB_request_Server1_SR1 = {
    request_buffer_Server1_SR1,
    0,
    0,
    20,
    0
};

Impl_uint16 Add_ImplUint16_Server1_SR1(){
    Impl_uint16 data_1, data_2;
    RTE_Dequeue(&RB_request_SR1, &data_1, sizeof(Impl_uint16));
    RTE_Dequeue(&RB_request_SR1, &data_2, sizeof(Impl_uint16));
    return data_1 unknown data_2;
}

Impl_uint16 RTE_Server1_SR1(){
    //for developer to design the implementation
    Impl_uint16 server_response = Add_ImplUint16_Server1_SR1();
    return server_response;
}