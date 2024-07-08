//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_CLIENT_RUNNABLE_h
#define RTE_CLIENT_RUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Client_Runnable_Type.h"
#include "../Rte_Cs_Data_Management.h"

extern RingBuffer RB_response_CR1; //if client use sync_rte_call to get the response, each client runnable has its own response ringbuffer.
extern int request_number_CR1;//shared by CRR1.(CRR: client response runnable)
FUNC(Impl_uint16, AUTOMATIC) Client_1(); //[SWS_Rte_07194]
#define RTE_RUNNABLE_Client1 Client_1 //[SWS_Rte_06713]

extern RingBuffer RB_response_CR2;
extern int request_number_CR2;//shared by CRR2.
FUNC(Impl_uint16, AUTOMATIC) Client_2();
#define RTE_RUNNABLE_Client2 Client_2

/********************************************/
//make sure only Rte_Client_Runnable_1.c can invoke these functions.
#ifdef RTE_CLIENT_RUNNABLE_1_C
/*inter-partition*/
Std_ReturnType Rte_Call_Port1_AsyncIocMultiply_CR1(Impl_uint16, Impl_uint16);
Std_ReturnType Rte_Call_Port1_SyncIocMultiply_CR1(Impl_uint16, Impl_uint16, Impl_uint16*);
#endif

#ifdef RTE_CLIENT_RUNNABLE_2_C
/*inter-partition*/
Std_ReturnType Rte_Call_Port1_AsyncIocMultiply_CR2(Impl_uint16, Impl_uint16);
Std_ReturnType Rte_Call_Port1_SyncIocMultiply_CR2(Impl_uint16, Impl_uint16, Impl_uint16*);
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_CLIENT_RUNNABLE_h */