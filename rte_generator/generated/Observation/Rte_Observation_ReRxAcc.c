#define RTE_RUNNABLEAPI_ReRxAcc
#include "Rte_Observation.h" 
#include "../com_data_management.h"
extern MyUint16OfVendorID ComSignal2_2_Acc;
extern uint32 ComSignal2_2_Acc_first_reception_flag;
void Rte_Read_RpIfVehAcc_Acc(Impl_uint16* data, Std_TransformerError transformerError){

     return_value0 = RTE_Fetch(data, &ComSignal2_2_Acc, sizeof(MyUint16OfVendorID));
     //clear first_reception_flag check
     if (*data != 777 & ComSignal2_2_Acc_first_reception_flag){
          CLEAR_BIT0(&ComSignal2_2_Acc_first_reception_flag);
     }
     return;
}
void RTE_RUNNABLE_ReRxAcc(){
/* The algorithm of ReRxAcc */
return;
}
