#define RTE_RUNNABLEAPI_ReTxTemp
#include "Rte_Controller.h" 
#include "../ioc_data_management.h"
#include "../../kernel/event.h"
#include "../../Os_Configure/inc/task_Cfg.h"
#include "../../Os_Configure/inc/event_Cfg.h"
Std_ReturnType Rte_Send_PpIfTemperature_Temp(Impl_uint16 data, Std_TransformerError transformerError){

     Std_ReturnType return_value0 = IocSend_Q3_1_SND1(data);
     //SetEvent(T11,event1);
    //SetEvent(T11,event1);
     if(return_value0 == IOC_E_LIMIT) {
          return RTE_E_LIMIT;
     }
     else if(return_value0 == IOC_E_NOK) {
          return RTE_E_NOK;
     }
     Std_ReturnType return_value1 = IocSend_Q3_2_SND1(data);
     //SetEvent(T11,event1);
     //SetEvent(T11,event1);
     if(return_value1 == IOC_E_LIMIT) {
          return RTE_E_LIMIT;
     }
     else if(return_value1 == IOC_E_NOK) {
          return RTE_E_NOK;
     }
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxTemp(){
     /* The algorithm of ReTxTemp */
     Std_TransformerError myTransformerError;
     myTransformerError.errorCode = 0;
     myTransformerError.transformerClass = STD_TRANSFORMER_SERIALIZER;

     for(Impl_uint16 i = 123 ; i <132 ; i++){
          Std_ReturnType returnx = Rte_Send_PpIfTemperature_Temp(i,myTransformerError);
     }
     return;
}
