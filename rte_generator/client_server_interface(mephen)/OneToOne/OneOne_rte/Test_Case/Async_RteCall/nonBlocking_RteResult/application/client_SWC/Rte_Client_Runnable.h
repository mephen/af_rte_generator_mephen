//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_CLIENT_RUNNABLE_h
#define RTE_CLIENT_RUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Client_Runnable_Type.h"
#include "../ringbuffer.h"
FUNC(Std_ReturnType, AUTOMATIC) Rte_Client_Runnable_1();

/********************************************/
/*stub*/
//transformer stub: store the transformed data into the buffer
//Xfrm_transformer_com for sending side, Xfrm_Inv_transformer_com for receiving side

uint8 Xfrm_transformer_ioc(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, Impl_uint16 data_1, Impl_uint16 data_2);
uint8 Xfrm_Inv_transformer_ioc(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint16 data);
uint8 Xfrm_transformer_2_ioc(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, Impl_uint16 data_1);
uint8 Xfrm_Inv_transformer_2_ioc(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint16 data_1);

/********************************************/
/*helpful functions*/
int Search_RteCallMetadata_RingBuffer(RingBuffer* rb, Rte_call_metaData* target);

/********************************************/
//make sure only Rte_Client_Runnable_1.c can invoke these functions.
#ifdef RTE_CLIENT_RUNNABLE_1_C
Std_ReturnType Rte_Call_Port1_InterPartitionAsynchronousAdd(Impl_uint16, Impl_uint16);
Std_ReturnType Rte_Call_Port1_InterPartitionSynchronousAdd(Impl_uint16, Impl_uint16, Impl_uint16*);
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_CLIENT_RUNNABLE_h */