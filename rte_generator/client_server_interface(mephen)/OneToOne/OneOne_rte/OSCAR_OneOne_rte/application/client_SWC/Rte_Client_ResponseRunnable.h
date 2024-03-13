//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_CLIENT_RESPONSERUNNABLE_h
#define RTE_CLIENT_RESPONSERUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Client_ResponseRunnable_Type.h"
FUNC(Impl_uint16, AUTOMATIC) Rte_Client_ResponseRunnable_1(Std_ReturnType Previous_RteCall_returnValue);


/********************************************/
//make sure only Rte_Client_Runnable_1.c can invoke these functions.
#ifdef RTE_CLIENT_RESPONSERUNNABLE_1_C
Std_ReturnType Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking(Std_ReturnType Previous_RteCall_returnValue, Impl_uint16* response);
Std_ReturnType Rte_Result_Port1_InterPartitionAsynchronousAdd_Blocking(Std_ReturnType Previous_RteCall_returnValue, Impl_uint16* response);
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_CLIENT_RESPONSERUNNABLE_h */