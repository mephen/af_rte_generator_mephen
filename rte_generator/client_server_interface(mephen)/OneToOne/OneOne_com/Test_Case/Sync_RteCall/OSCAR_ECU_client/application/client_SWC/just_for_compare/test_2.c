Std_ReturnType Rte_Call_Port1_InterEcuAsynchronousAdd(Impl_uint16 data_1, Impl_uint16 data_2){
    Std_ReturnType rte_error_code = RTE_E_OK;
    Impl_uint16 Enqueue_rte_call_RB = 0;//to check if the rte_call is enqueued
    if(Rte_Call_Port1_InterEcuAsynchronousAdd_metaData.connected_unconnected == "unconnected"){
        rte_error_code = RTE_E_UNCONNECTED;
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_InterEcuAsynchronousAdd_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error_code = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Search_RteCallMetadata_RingBuffer(&rte_call_record_RB, &Rte_Call_Port1_InterEcuAsynchronousAdd_metaData)){
            rte_error_code = RTE_E_LIMIT;
        }else{
            RTE_Enqueue(&rte_call_record_RB, &Rte_Call_Port1_InterEcuAsynchronousAdd_metaData, sizeof(Rte_call_metaData));
            Enqueue_rte_call_RB = 1;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_InterEcuAsynchronousAdd_metaData.CanAccess == "CanNot"){
            rte_error_code = RTE_E_SEG_FAULT;
        }
    }
    if(rte_error_code == RTE_E_OK){
        //The RTE is not able to allocate the buffer needed to transform the data
        if(IsFull(&transformer_RB_com)){
            rte_error_code = RTE_E_TRANSFORMER_LIMIT;
        }
    }
    if(rte_error_code == RTE_E_OK){
        uint8 transformer_error_code = Xfrm_transformer_com(&Rte_Call_Port1_InterEcuAsynchronousAdd_metaData.transaction_handle, &transformer_RB_com, &transformer_RB_com.currentSize, data_1, data_2);
        if(transformer_error_code >= 0x01 && transformer_error_code <= 0x7F){
            //soft transformer error won't cause immediate return
            rte_error_code = RTE_E_SOFT_TRANSFORMER_ERROR;
        }else if(transformer_error_code >= 0x80 && transformer_error_code <= 0xFF){
            rte_error_code = RTE_E_HARD_TRANSFORMER_ERROR;
        }
    }
    if(rte_error_code == RTE_E_OK || rte_error_code == RTE_E_SOFT_TRANSFORMER_ERROR){
        signal signal_1;
        RTE_Dequeue(&transformer_RB_com, (void*)&signal_1, sizeof(signal));
        uint8 com_error_code = Com_SendSignal(1U, &signal_1);
        if(com_error_code == COM_SERVICE_NOT_AVAILABLE){
            rte_error_code = RTE_E_COM_STOPPED;
        }else if(com_error_code == COM_BUSY){
            rte_error_code = RTE_E_COM_BUSY;
        }
    }
    if(rte_error_code == RTE_E_OK || rte_error_code == RTE_E_SOFT_TRANSFORMER_ERROR){
        signal signal_2;
        RTE_Dequeue(&transformer_RB_com, (void*)&signal_2, sizeof(signal));
        uint8 com_error_code = Com_SendSignal(2U, &signal_2);
        if(com_error_code == COM_SERVICE_NOT_AVAILABLE){
            rte_error_code = RTE_E_COM_STOPPED;
        }else if(com_error_code == COM_BUSY){
            rte_error_code = RTE_E_COM_BUSY;
        }
    }
    if(Enqueue_rte_call_RB == 1){
        RTE_Dequeue(&rte_call_record_RB, &Rte_Call_Port1_InterEcuAsynchronousAdd_metaData, sizeof(Rte_call_metaData));
    }
    //return value shall follow the priority rules
    return rte_error_code;
}