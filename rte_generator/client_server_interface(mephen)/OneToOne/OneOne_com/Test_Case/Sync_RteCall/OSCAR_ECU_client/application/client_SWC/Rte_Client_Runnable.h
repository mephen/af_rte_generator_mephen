//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_CLIENT_RUNNABLE_h
#define RTE_CLIENT_RUNNABLE_h

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Client_Runnable_Type.h"
#include "../ringbuffer.h"
FUNC(Impl_uint16, AUTOMATIC) Rte_Client_Runnable_1();

/********************************************/
/*stub*/
//transformer stub: store the transformed data into the buffer
//Xfrm_transformer_com for sending side, Xfrm_Inv_transformer_com for receiving side
//assum the underlying data structure of signal is uint8 in this situation
typedef uint8 signal;
uint8 Xfrm_transformer_com(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, Impl_uint16 data_1, Impl_uint16 data_2);
uint8 Xfrm_Inv_transformer_com(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, signal signal_1);
uint8 Xfrm_transformer_2_com(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, Impl_uint16 data_1);
uint8 Xfrm_Inv_transformer_2_com(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, signal signal_1);

//Com_sendSignal stub, Com_ReceiveSignal stub
typedef uint16 Com_SignalIdType;
#define E_NOT_OK 0x01
#define COM_SERVICE_NOT_AVAILABLE 0x80
#define COM_BUSY 0x81
uint8 Com_SendSignal(Com_SignalIdType signalId, const void* signalDataPtr);
uint8 Com_ReceiveSignal(Com_SignalIdType signalId,void* signalDataPtr);
/********************************************/
/*helpful functions*/
int Search_RteCallMetadata_RingBuffer(RingBuffer* rb, Rte_call_metaData* target);

/********************************************/
//make sure only Rte_Client_Runnable_1.c can invoke these functions.
#ifdef RTE_CLIENT_RUNNABLE_1_C
Std_ReturnType Rte_Call_Port1_InterEcuAsynchronousAdd(Impl_uint16, Impl_uint16); //Rte_call: initiate a C/S communication
Std_ReturnType Rte_Call_Port1_InterEcuSynchronousAdd(Impl_uint16, Impl_uint16, Impl_uint16*);
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif/* RTE_CLIENT_RUNNABLE_h */