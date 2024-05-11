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

extern RingBuffer RB_response_CRR3;//if client use Rte_result to get the response, each client response runnable has its own response ringbuffer.
//Runnable declaration shouldn't be put btw #ifdef~#endif, otherise, os application can't access it.
FUNC(Impl_uint16, AUTOMATIC) RTE_RUNNABLE_ClientResponse3();

extern RingBuffer RB_response_CRR4;
FUNC(Impl_uint16, AUTOMATIC) RTE_RUNNABLE_ClientResponse4();


/********************************************/
//make sure only Rte_Client_Runnable_3.c can invoke these functions.
#ifdef RTE_CLIENT_RESPONSERUNNABLE_3_C
/*inter-partition*/
Std_ReturnType Rte_Result_Port1_NonBlocking_CRR3(Impl_uint16* response);
Std_ReturnType Rte_Result_Port1_Blocking_CRR3(Impl_uint16* response);
#endif

#ifdef RTE_CLIENT_RESPONSERUNNABLE_4_C
/*inter-partition*/
Std_ReturnType Rte_Result_Port1_NonBlocking_CRR4(Impl_uint16* response);
Std_ReturnType Rte_Result_Port1_Blocking_CRR4(Impl_uint16* response);
#endif

/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_CLIENT_RESPONSERUNNABLE_h */