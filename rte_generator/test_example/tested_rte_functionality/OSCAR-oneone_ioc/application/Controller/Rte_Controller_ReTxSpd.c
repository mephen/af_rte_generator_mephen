#define RTE_RUNNABLEAPI_ReTxSpd
#include "Rte_Controller.h" 
#include "../ioc_data_management.h"
Std_ReturnType Rte_Write_PpIfVehSpd_Spd(Impl_uint16 data){

     Std_ReturnType return_value0 = IocWrite_Q1_SND1(data);
     if(return_value0 == IOC_E_NOK) {
          return RTE_E_NOK;
     }
     return RTE_E_OK;
}
Std_ReturnType Rte_Invalidate_PpIfVehSpd_Spd(){

     // Write the invalid value that config in SwDataDefProps.InvalidValue
     Impl_uint16 data = 255;
     Std_ReturnType return_value0 = IocWrite_Q1_SND1(data);
     if(return_value0 == IOC_E_NOK) {
          return RTE_E_NOK;
     }
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxSpd(){
/* The algorithm of ReTxSpd */
return;
}
