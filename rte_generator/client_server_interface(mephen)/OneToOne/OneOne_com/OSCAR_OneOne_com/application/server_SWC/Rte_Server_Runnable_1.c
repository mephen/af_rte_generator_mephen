#define RTE_SERVER_RUNNABLE_1_C
#include "Rte_Server_Runnable.h"
#include "../ringbuffer.h"

Impl_uint8 add_ImplUint8(Impl_uint8 data_1, Impl_uint8 data_2){
    return data_1 + data_2;
}

Impl_uint16 add_ImplUint16(Impl_uint16 data_1, Impl_uint16 data_2){
    return data_1 + data_2;
}

Impl_uint16 Rte_Server_Runnable(Impl_uint16 data_1, Impl_uint16 data_2)
{
    //for developer to design the implementation
    Impl_uint16 server_response = add_ImplUint16((Impl_uint16)data_1, (Impl_uint16)data_2);
    return server_response;
}