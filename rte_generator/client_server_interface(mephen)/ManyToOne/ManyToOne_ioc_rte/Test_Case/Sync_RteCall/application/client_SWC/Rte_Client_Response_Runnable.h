//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_CLIENT_RESPONSERUNNABLE_h
#define RTE_CLIENT_RESPONSERUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Client_Response_Runnable_Type.h"
#include "../Rte_Cs_Data_Management.h"
#include "Rte_Client_Runnable.h"

extern RingBuffer RB_response_CRR1;//if client use Rte_result to get the response, each client response runnable has its own response ringbuffer.
//Runnable declaration shouldn't be put btw #ifdef~#endif, otherise, os application can't access it.
FUNC(Impl_uint16, AUTOMATIC) ClientResponse_1(); //Impl_uint16 of return value is for testing
#define RTE_RUNNABLE_ClientResponse1 ClientResponse_1

extern RingBuffer RB_response_CRR2;
FUNC(Impl_uint16, AUTOMATIC) ClientResponse_2();
#define RTE_RUNNABLE_ClientResponse2 ClientResponse_2

extern RingBuffer RB_response_CRR3;
FUNC(Impl_uint16, AUTOMATIC) ClientResponse_3();
#define RTE_RUNNABLE_ClientResponse3 ClientResponse_3


/********************************************/
//make sure only Rte_Client_Runnable_1.c can invoke these functions.
#ifdef RTE_CLIENT_RESPONSERUNNABLE_1_C
/*intra-partition*/
Std_ReturnType Rte_Result_Port1_NonBlocking_CRR1(Impl_uint16* response);
Std_ReturnType Rte_Result_Port1_Blocking_CRR1(Impl_uint16* response);
#endif

#ifdef RTE_CLIENT_RESPONSERUNNABLE_2_C
/*intra-partition*/
Std_ReturnType Rte_Result_Port1_NonBlocking_CRR2(Impl_uint16* response);
Std_ReturnType Rte_Result_Port1_Blocking_CRR2(Impl_uint16* response);
#endif

#ifdef RTE_CLIENT_RESPONSERUNNABLE_3_C
/*inter-partition*/
Std_ReturnType Rte_Result_Port1_NonBlocking_CRR3(Impl_uint16* response);
Std_ReturnType Rte_Result_Port1_Blocking_CRR3(Impl_uint16* response);
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_CLIENT_RESPONSERUNNABLE_h */