#define RTE_SERVER_RUNNABLE_2_C
#include "Rte_SWC_Server2.h"
#include "../ringbuffer.h"

uint16 request_buffer_SWC_Server2_SR1[20];
RingBuffer RB_request_SWC_Server2_SR1 = {
    request_buffer_SWC_Server2_SR1,
    0,
    0,
    20,
    0
};

Impl_uint16 Sub_ImplUint16_SR2(){
    uint16 data_1, data_2;
    RTE_Dequeue(&RB_request_SWC_Server2_SR1, &data_1, sizeof(uint16));
    RTE_Dequeue(&RB_request_SWC_Server2_SR1, &data_2, sizeof(uint16));
    return data_1 - data_2;
}

Impl_uint16 RTE_RUNNABLE_SWC_Server1_Runnable_1()
{
    //for developer to design the implementation
    Impl_uint16 server_response = Sub_ImplUint16_SR2();
    return server_response;
}