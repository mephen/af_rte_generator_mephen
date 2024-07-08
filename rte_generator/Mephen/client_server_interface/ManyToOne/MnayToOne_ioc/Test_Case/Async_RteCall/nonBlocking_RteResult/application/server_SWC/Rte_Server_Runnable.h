//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_SERVER_RUNNABLE_h
#define RTE_SERVER_RUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Server_Runnable_Type.h"
#include "../ringbuffer.h"

extern RingBuffer RB_request_SR1; //each server runnable has its own request buffer
FUNC(Impl_uint16, AUTOMATIC) Server_1();
#define RTE_RUNNABLE_Server1 Server_1

extern RingBuffer RB_request_SR2;
FUNC(Impl_uint16, AUTOMATIC) Server_2();
#define RTE_RUNNABLE_Server2 Server_2

extern RingBuffer RB_request_SR3;
FUNC(Impl_uint16, AUTOMATIC) Server_3();
#define RTE_RUNNABLE_Server3 Server_3

//make sure only Rte_Server_Runnable_1.c can invoke Add_ImplUint8.
#ifdef RTE_SERVER_RUNNABLE_1_C
Impl_uint16 Multiply_ImplUint16_SR1();
Impl_uint16 Add_ImplUint16_SR1();
#endif

#ifdef RTE_SERVER_RUNNABLE_2_C
Impl_uint16 Sub_ImplUint16_SR2();
#endif

#ifdef RTE_SERVER_RUNNABLE_3_C
Impl_uint16 Multiply_ImplUint16_SR3();
#endif

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_SERVER_RUNNABLE_h */