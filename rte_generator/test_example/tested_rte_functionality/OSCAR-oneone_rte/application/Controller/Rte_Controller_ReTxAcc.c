#define RTE_RUNNABLEAPI_ReTxAcc
#include "Rte_Controller.h" 
#include "../rte_data_management.h"
extern MyUint8OfVendorID R2_Acc;
Std_ReturnType Rte_Write_PpIfVehAcc_Acc(Impl_uint8 data, Std_TransformerForward forwardedStatus, Std_TransformerError transformerError){

     Std_ReturnType return_value0 = RTE_Update(&R2_Acc, &data, sizeof(MyUint8OfVendorID));
     return RTE_E_OK;
}
Std_ReturnType Rte_Invalidate_PpIfVehAcc_Acc(Std_TransformerError transformerError){

     // Write the invalid value that config in SwDataDefProps.InvalidValue
     Impl_uint8 data = 255;
     Std_ReturnType return_value0 = RTE_Update(&R2_Acc, &data, sizeof(MyUint8OfVendorID));
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxAcc(){
     /* The algorithm of ReTxAcc */
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;

     Std_TransformerForward myTransformerForward;
     myTransformerForward.errorCode = 0;
     myTransformerForward.transformerClass = STD_TRANSFORMER_SERIALIZER;

     //last is best
     Rte_Write_PpIfVehAcc_Acc(254,myTransformerForward , myTransformerError);
     return;
}
