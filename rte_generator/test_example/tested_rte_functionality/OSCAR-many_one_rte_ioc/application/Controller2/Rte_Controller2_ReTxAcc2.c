#define RTE_RUNNABLEAPI_ReTxAcc2
#include "Rte_Controller2.h" 
#include "../rte_data_management.h"
#include "../ioc_data_management.h"
extern MyUint16OfVendorID R2_Acc;
Std_ReturnType Rte_Write_PpIfVehAcc2_Acc(Impl_uint16 data, Std_TransformerForward forwardedStatus, Std_TransformerError transformerError){

     Std_ReturnType return_value0 = RTE_Update(&R2_Acc, &data, sizeof(MyUint16OfVendorID));
     return RTE_E_OK;
}
Std_ReturnType Rte_Invalidate_PpIfVehAcc2_Acc(Std_TransformerError transformerError){

     // Write the invalid value that config in SwDataDefProps.InvalidValue
     Impl_uint16 data = 255;
     Std_ReturnType return_value0 = RTE_Update(&R2_Acc, &data, sizeof(MyUint16OfVendorID));
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxAcc2(){
    /* The algorithm of ReTxAcc2 */
    Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;

     Std_TransformerForward myTransformerForward;
     myTransformerForward.errorCode = 0;
     myTransformerForward.transformerClass = STD_TRANSFORMER_SERIALIZER;
     Rte_Write_PpIfVehAcc2_Acc(541,myTransformerForward , myTransformerError);
     return;
}
