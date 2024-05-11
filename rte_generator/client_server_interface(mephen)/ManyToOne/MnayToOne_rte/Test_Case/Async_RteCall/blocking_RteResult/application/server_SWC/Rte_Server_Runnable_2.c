#define RTE_SERVER_RUNNABLE_2_C
#include "Rte_Server_Runnable.h"
#include "../ringbuffer.h"

uint16 request_buffer_SR2[20];
RingBuffer RB_request_SR2 = {
    request_buffer_SR2,
    0,
    0,
    20,
    0
};

Impl_uint16 Sub_ImplUint16_SR2(){
    uint16 data_1, data_2;
    RTE_Dequeue(&RB_request_SR2, &data_1, sizeof(uint16));
    RTE_Dequeue(&RB_request_SR2, &data_2, sizeof(uint16));
    return data_1 - data_2;
}

Impl_uint16 RTE_RUNNABLE_Server2()
{
    //for developer to design the implementation
    Impl_uint16 server_response = Sub_ImplUint16_SR2();
    return server_response;
}