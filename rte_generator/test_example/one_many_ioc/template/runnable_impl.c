void RTE_RUNNABLE_ReTxAcc(){
     /* The algorithm of ReTxAcc */
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;

     Std_TransformerForward myTransformerForward;
     myTransformerForward.errorCode = 0;
     myTransformerForward.transformerClass = STD_TRANSFORMER_SERIALIZER;

	Rte_Write_PpIfVehAcc_Acc(254,myTransformerForward , myTransformerError);
     return;
}

void RTE_RUNNABLE_ReTxTemp(){
     /* The algorithm of ReTxTemp */
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;

     for(Impl_uint16 i = 123 ; i <132 ; i++){
          Std_ReturnType returnx = Rte_Send_PpIfTemperature_Temp(i,myTransformerError);
     }
     return;
}

void RTE_RUNNABLE_ReRxAcc(){
/* The algorithm of ReRxAcc */
     Impl_uint16* data = 0;
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;
     Rte_Read_RpIfVehAcc_Acc(&data, myTransformerError);
     return;
}

void RTE_RUNNABLE_ReRxTemp(){
/* The algorithm of ReRxTemp */
     Impl_uint16* data = 0;
     
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;
     
     for (int i = 0; i <4; i++){
     	Rte_Receive_RpIfTemperature_Temp(&data,myTransformerError);
     }
     return;
}

void RTE_RUNNABLE_ReRxAcc2(){
/* The algorithm of ReRxAcc */
     Impl_uint16* data = 0;
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;
     Rte_Read_RpIfVehAcc2_Acc(&data, myTransformerError);
     return;
}

void RTE_RUNNABLE_ReRxTemp2(){
/* The algorithm of ReRxTemp */
     Impl_uint16* data = 0;
     
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;
     
     for (int i = 0; i <4; i++){
     	Rte_Receive_RpIfTemperature2_Temp(&data,myTransformerError);
     }
     return;
}






