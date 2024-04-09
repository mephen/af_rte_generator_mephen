#include "Transformer_stub.h"

/*[SWS_Xfrm_00038]*/
//transforme data into DataType for Rte_Enqueue the rte_internal_buffer
uint8 Xfrm_transformer(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint16 data_1){
    uint16 rte_data_1 = (uint16)data_1;
    RTE_Enqueue(buffer, (void*)&rte_data_1, sizeof(uint16));
    return E_OK;
}
//transforme data into DataType for server_operation
uint8 Xfrm_Inv_transformer(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint16 rte_data){
    uint16 data = (uint16)rte_data;
    RTE_Enqueue(buffer, (void*)&data, sizeof(uint16));
    return E_OK;
}
//transforme data into DataType for Rte_Enqueue the rte_internal_buffer
uint8 Xfrm_transformer_2(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint16 data_1){
    uint16 rte_data_1 = (uint16)data_1;
    RTE_Enqueue(buffer, (void*)&rte_data_1, sizeof(uint16));
    return E_OK;
}
//transforme data into DataType for Rte_result
uint8 Xfrm_Inv_transformer_2(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, uint16 rte_data){
    uint16 data = (uint16)rte_data;
    RTE_Enqueue(buffer, (void*)&data, sizeof(uint16));
    return E_OK;
}

/*self-defined*/
Std_ReturnType Check_Transformer_Buffer(RingBuffer* rb){
    if(IsFull(rb)){
        return RTE_E_TRANSFORMER_LIMIT;
    }
    return RTE_E_OK;
}

Std_ReturnType Check_Transformer_Error(uint8 transformer_error, Std_ReturnType bsw_error){
    //in the priority rule of Rte_result: RTE_E_TRANSFORMER_LIMIT > RTE_E_HARD_TRANSFORMER_ERROR > RTE_E_SOFT_TRANSFORMER_ERROR
    if(bsw_error == RTE_E_TRANSFORMER_LIMIT){
        return RTE_E_TRANSFORMER_LIMIT;
    }else{
        if(transformer_error >= 0x01 && transformer_error <= 0x7F){
            return RTE_E_SOFT_TRANSFORMER_ERROR;
        }else if(transformer_error >= 0x80 && transformer_error <= 0xFF){
            return RTE_E_HARD_TRANSFORMER_ERROR;
        }
    }
    return RTE_E_OK;
}
