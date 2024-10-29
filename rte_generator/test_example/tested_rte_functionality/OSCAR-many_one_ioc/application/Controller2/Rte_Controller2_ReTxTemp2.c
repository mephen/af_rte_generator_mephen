#define RTE_RUNNABLEAPI_ReTxTemp2
#include "Rte_Controller2.h" 
#include "../ioc_data_management.h"
#include "../../kernel/event.h"
#include "../../Os_Configure/inc/task_Cfg.h"
#include "../../Os_Configure/inc/event_Cfg.h"
Std_ReturnType Rte_Send_PpIfTemperature2_Temp(Impl_uint16 data, Std_TransformerError transformerError){

     Std_ReturnType return_value0 = IocSend_Q3_SND2(data);
     //SetEvent(T11,event1);
     if(return_value0 == IOC_E_LIMIT) {
          return RTE_E_LIMIT;
     }
     else if(return_value0 == IOC_E_NOK) {
          return RTE_E_NOK;
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