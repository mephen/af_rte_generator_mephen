#define RTE_RUNNABLEAPI_ReTxTemp
#include "Rte_Controller.h" 
#include "../rte_data_management.h"
#include "../../kernel/event.h"
#include "../../Os_Configure/inc/task_Cfg.h"
#include "../../Os_Configure/inc/event_Cfg.h"
extern RingBuffer RB_R3_Temp;
Std_ReturnType Rte_Send_PpIfTemperature_Temp(Impl_uint8 data, Std_TransformerError transformerError){

     Std_ReturnType return_value0 = RTE_Enqueue(&RB_R3_Temp, &data, sizeof(MyUint8OfVendorID));
     //SetEvent(T02,event1);
     if(return_value0 == RTE_E_LIMIT) {
          return RTE_E_LIMIT;
     }
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxTemp(){
     /* The algorithm of ReTxTemp */
     uint16 i = 0;
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;

     for(i = 123 ; i <125 ; i++){
          Std_ReturnType returnx = Rte_Send_PpIfTemperature_Temp(i,myTransformerError);
     }
     return;
}