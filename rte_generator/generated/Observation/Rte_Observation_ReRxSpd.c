#define RTE_RUNNABLEAPI_ReRxSpd
#include "Rte_Observation.h" 
#include "../com_data_management.h"
extern MyUint16OfVendorID ComSignal1_1_Spd;
extern uint32 ComSignal1_1_Spd_first_reception_flag;
Impl_uint16 Rte_DRead_RpIfVehSpd_Spd(){

     Impl_uint16 dataValue = 0;
     Impl_uint16* data = &dataValue;
     Std_ReturnType return_value0 = RTE_Fetch(data, &ComSignal1_1_Spd, sizeof(Impl_uint16));
     return *data;
}
void RTE_RUNNABLE_ReRxSpd(){
/* The algorithm of ReRxSpd */
return;
}
