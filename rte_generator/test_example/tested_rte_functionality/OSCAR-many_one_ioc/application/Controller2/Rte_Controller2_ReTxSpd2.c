#define RTE_RUNNABLEAPI_ReTxSpd2
#include "Rte_Controller2.h" 
#include "../ioc_data_management.h"
Std_ReturnType Rte_Write_PpIfVehSpd2_Spd(Impl_uint16 data){

     Std_ReturnType return_value0 = IocWrite_Q1_SND2(data);
     if(return_value0 == IOC_E_NOK) {
          return RTE_E_NOK;
     }
     return RTE_E_OK;
}
Std_ReturnType Rte_Invalidate_PpIfVehSpd2_Spd(){

     // Write the invalid value that config in SwDataDefProps.InvalidValue
     Impl_uint16 data = 255;
     Std_ReturnType return_value0 = IocWrite_Q1_SND2(data);
     if(return_value0 == IOC_E_NOK) {
          return RTE_E_NOK;
     }
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxSpd2(){
/* The algorithm of ReTxSpd2 */
return;
}
