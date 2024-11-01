#define RTE_SERVER_RUNNABLE_1_C
#include "Rte_Server_Runnable.h"
#include "../ringbuffer.h"

Impl_uint16 request_buffer_SR1[20];
RingBuffer RB_request_SR1 = {
    request_buffer_SR1,
    0,
    0,
    20,
    0
};

Impl_uint16 Multiply_ImplUint16_SR1(){
    uint16 data_1, data_2;
    RTE_Dequeue(&RB_request_SR1, &data_1, sizeof(uint16));
    RTE_Dequeue(&RB_request_SR1, &data_2, sizeof(uint16));
    return data_1 * data_2;
}

// Impl_uint16 Add_ImplUint16_SR1(){
//     Impl_uint16 data_1, data_2;
//     RTE_Dequeue(&RB_request_SR1, &data_1, sizeof(Impl_uint16));
//     RTE_Dequeue(&RB_request_SR1, &data_2, sizeof(Impl_uint16));
//     return data_1 + data_2;
// }

Impl_uint16 RTE_RUNNABLE_Server1()
{
    //for developer to design the implementation
    Impl_uint16 server_response = Multiply_ImplUint16_SR1();
    return server_response;
}