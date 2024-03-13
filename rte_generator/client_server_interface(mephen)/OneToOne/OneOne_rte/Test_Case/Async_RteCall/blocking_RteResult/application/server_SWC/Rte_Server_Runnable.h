//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_SERVER_RUNNABLE_h
#define RTE_SERVER_RUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Server_Runnable_Type.h"
#include "../ringbuffer.h"
FUNC(Impl_uint16, AUTOMATIC) Rte_Server_Runnable(Impl_uint16, Impl_uint16);

//make sure only Rte_Server_Runnable_1.c can invoke these functions.
#ifdef RTE_SERVER_RUNNABLE_1_C
Impl_uint8 add_ImplUint8(Impl_uint8, Impl_uint8);
Impl_uint16 add_ImplUint16(Impl_uint16, Impl_uint16);
#endif

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_SERVER_RUNNABLE_h */