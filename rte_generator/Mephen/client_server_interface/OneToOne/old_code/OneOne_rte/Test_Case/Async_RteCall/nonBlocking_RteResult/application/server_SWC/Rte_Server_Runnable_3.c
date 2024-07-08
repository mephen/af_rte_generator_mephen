#define RTE_SERVER_RUNNABLE_3_C
#include "Rte_Server_Runnable.h"
#include "../ringbuffer.h"

uint16 request_buffer_SR3[20];
RingBuffer RB_request_SR3 = {
    request_buffer_SR3,
    0,
    0,
    20,
    0
};

Impl_uint16 Multiply_ImplUint16(){
    uint16 data_1, data_2;
    RTE_Dequeue(&RB_request_SR3, &data_1, sizeof(uint16));
    RTE_Dequeue(&RB_request_SR3, &data_2, sizeof(uint16));
    return data_1 * data_2;
}

Impl_uint16 RTE_RUNNABLE_Server3()
{
    //for developer to design the implementation
    Impl_uint16 server_response = Multiply_ImplUint16();
    return server_response;
}