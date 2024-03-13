#define RTE_RUNNABLEAPI_ReRxTemp
#include "Rte_Observation.h" 
#include "../rte_data_management.h"
#include "../../kernel/alarm.h"
#include "../../kernel/event.h"
#include "../../Os_Configure/inc/event_Cfg.h"
extern RingBuffer RB_R3_Temp;
Std_ReturnType Rte_Receive_RpIfTemperature_Temp(Impl_uint8* data, Std_TransformerError transformerError){

     Std_ReturnType return_value0 = RTE_Dequeue(&RB_R3_Temp, data, sizeof(MyUint8OfVendorID));
     if(return_value0 == RTE_E_NO_DATA) {
          TickType max = 0;
          //GetAlarm(alarm3,&max);
          max = max + 100;
          TickType temp = 0;
          //WaitEvent(event1);
          //GetAlarm(alarm3,&temp);
          if(temp >= max) {
               return RTE_E_TIMEOUT;
          }
          RTE_Dequeue(&RB_R3_Temp, data, sizeof(MyUint8OfVendorID));
     }
     else if(return_value0 == RTE_E_NOK) {
          return RTE_E_NOK;
     }
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReRxTemp(){
/* The algorithm of ReRxTemp */
     uint16* data = 0;
     
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;
     
     for (int i = 0; i <4; i++){
     	Rte_Receive_RpIfTemperature_Temp(&data,myTransformerError);
     }
     return;
}