#define RTE_RUNNABLEAPI_ReTxTemp2
#include "Rte_Controller2.h" 
#include "../rte_data_management.h"
#include "../ioc_data_management.h"
#include "../../kernel/event.h"
#include "../../Os_Configure/inc/task_Cfg.h"
#include "../../Os_Configure/inc/event_Cfg.h"
extern RingBuffer RB_R3_Temp;
Std_ReturnType Rte_Send_PpIfTemperature2_Temp(Impl_uint16 data, Std_TransformerError transformerError){

     Std_ReturnType return_value0 = RTE_Enqueue(&RB_R3_Temp, &data, sizeof(MyUint16OfVendorID));
     //SetEvent(T02,event1);
     if(return_value0 == RTE_E_LIMIT) {
          return RTE_E_LIMIT;
     }
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxTemp2(){
     /* The algorithm of ReTxTemp2 */
     Impl_uint16 i = 0;
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;

     for(i = 234 ; i <237 ; i++){
          Std_ReturnType returnx = Rte_Send_PpIfTemperature2_Temp(i,myTransformerError);
     }
     return;
}
