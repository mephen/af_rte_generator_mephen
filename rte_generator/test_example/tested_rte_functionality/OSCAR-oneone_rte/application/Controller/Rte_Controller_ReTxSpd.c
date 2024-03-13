#define RTE_RUNNABLEAPI_ReTxSpd
#include "Rte_Controller.h" 
#include "../rte_data_management.h"
extern MyUint8OfVendorID R1_Spd;
Std_ReturnType Rte_Write_PpIfVehSpd_Spd(Impl_uint8 data){

     Std_ReturnType return_value0 = RTE_Update(&R1_Spd, &data, sizeof(MyUint8OfVendorID));
     return RTE_E_OK;
}
Std_ReturnType Rte_Invalidate_PpIfVehSpd_Spd(){

     // Write the invalid value that config in SwDataDefProps.InvalidValue
     Impl_uint8 data = 255;
     Std_ReturnType return_value0 = RTE_Update(&R1_Spd, &data, sizeof(MyUint8OfVendorID));
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxSpd(){
/* The algorithm of ReTxSpd */
return;
}
