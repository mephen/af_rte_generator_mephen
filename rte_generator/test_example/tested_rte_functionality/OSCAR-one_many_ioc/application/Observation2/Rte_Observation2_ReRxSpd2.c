#define RTE_RUNNABLEAPI_ReRxSpd2
#include "Rte_Observation2.h" 
#include "../ioc_data_management.h"
extern uint32 Q1_Spd_first_reception_flag;
Impl_uint16 Rte_DRead_RpIfVehSpd2_Spd(){

     Impl_uint16 dataValue = 0;
     Impl_uint16* data = &dataValue;
     Std_ReturnType return_value0 = IocRead_Q1_RCV2(data);
     return *data;
}
void RTE_RUNNABLE_ReRxSpd2(){
/* The algorithm of ReRxSpd2 */
return;
}
