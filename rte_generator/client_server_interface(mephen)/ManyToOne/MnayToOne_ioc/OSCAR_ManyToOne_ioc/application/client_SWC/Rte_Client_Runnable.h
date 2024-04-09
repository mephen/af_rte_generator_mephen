//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_CLIENT_RUNNABLE_h
#define RTE_CLIENT_RUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Client_Runnable_Type.h"
#include "../ringbuffer.h"
#include "../Rte_Cs_Data_Management.h"

extern RingBuffer RB_response_CR3; //if client use sync_rte_call to get the response, each client runnable has its own response ringbuffer.
extern int request_number_CR3;//shared by CRR3.
FUNC(Impl_uint16, AUTOMATIC) RTE_RUNNABLE_Client3();

extern RingBuffer RB_response_CR4; //if client use sync_rte_call to get the response, each client runnable has its own response ringbuffer.
extern int request_number_CR4;//shared by CRR4.
FUNC(Impl_uint16, AUTOMATIC) RTE_RUNNABLE_Client4();

/********************************************/
//make sure only Rte_Client_Runnable_1.c can invoke these functions.
#ifdef RTE_CLIENT_RUNNABLE_3_C
/*inter-partition*/
Std_ReturnType Rte_Call_Port1_AsyncIocMultiply_CR3(Impl_uint16, Impl_uint16);
Std_ReturnType Rte_Call_Port1_SyncIocMultiply_CR3(Impl_uint16, Impl_uint16, Impl_uint16*);
#endif

#ifdef RTE_CLIENT_RUNNABLE_4_C
/*inter-partition*/
Std_ReturnType Rte_Call_Port1_AsyncIocMultiply_CR4(Impl_uint16, Impl_uint16);
Std_ReturnType Rte_Call_Port1_SyncIocMultiply_CR4(Impl_uint16, Impl_uint16, Impl_uint16*);
#endif

/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_CLIENT_RUNNABLE_h */