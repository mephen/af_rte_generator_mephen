#define RTE_RUNNABLEAPI_ReRxAcc
#include "Rte_Observation.h" 
#include "../rte_data_management.h"
#include "../ioc_data_management.h"
extern MyUint16OfVendorID R2_Acc;
extern uint32 R2_Acc_first_reception_flag;
extern uint32 Q2_Acc_first_reception_flag;
Std_ReturnType Rte_Read_RpIfVehAcc_Acc(Impl_uint16* data, Std_TransformerError transformerError){

     Std_ReturnType      return_value0 = RTE_Fetch(data, &R2_Acc, sizeof(MyUint16OfVendorID));
     //clear first_reception_flag check
     if (*data != 111 & R2_Acc_first_reception_flag){
          CLEAR_BIT0(&R2_Acc_first_reception_flag);
     }
          //invalid check
     if ( *data == 255) {
          *data = 111;
     }
     Std_ReturnType return_value1 = IocRead_Q2_RCV1(data);
     //clear first_reception_flag check
     if (*data != 111 & Q2_Acc_first_reception_flag){
          CLEAR_BIT0(&Q2_Acc_first_reception_flag);
     }
          //invalid check
     if ( *data == 255) {
          *data = 111;
     }
     return RTE_E_OK;
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