#include "Rte_Type.h"

/********************************************/
/*stub*/
//transformer stub: store the transformed data into the buffer
//Xfrm_transformer for sending side, Xfrm_Inv_transformer for receiving side
uint8 Xfrm_transformer(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint8 data_1);
uint8 Xfrm_Inv_transformer(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint8 data);
uint8 Xfrm_transformer_2(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint8 data_1);
uint8 Xfrm_Inv_transformer_2(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint8 data_1);

/*self-defined*/
Std_ReturnType Check_Transformer_Buffer(RingBuffer* rb);
Std_ReturnType Check_Transformer_Error(uint8 transformer_error, Std_ReturnType bsw_error);