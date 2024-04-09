//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_SERVER_RUNNABLE_h
#define RTE_SERVER_RUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Server_Runnable_Type.h"
#include "../ringbuffer.h"

extern RingBuffer RB_request_SR4; //each server runnable has its own request buffer
FUNC(Impl_uint16, AUTOMATIC) RTE_RUNNABLE_Server4();

//make sure only Rte_Server_Runnable_1.c can invoke Add_ImplUint8.
#ifdef RTE_SERVER_RUNNABLE_4_C
Impl_uint16 Divide_ImplUint16();
#endif

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_SERVER_RUNNABLE_h */