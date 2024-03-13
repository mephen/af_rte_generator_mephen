#define RTE_RUNNABLEAPI_ReTxTemp
#include "Rte_Controller.h" 
#include "../com_data_management.h"
#include "../../kernel/event.h"
#include "../../Os_Configure/inc/task_Cfg.h"
#include "../../Os_Configure/inc/event_Cfg.h"
Std_ReturnType Rte_Send_PpIfTemperature_Temp(Impl_uint16 data, Std_TransformerError transformerError){

     Com_SignalIdType com_handle_id = 3;
     Std_ReturnType return_value0 = Com_SendSignal(com_handle_id, &data);
     SetEvent(T11,event1);
     if(return_value0 == COM_SERVICE_NOT_AVAILABLE) {
          return RTE_E_COM_STOPPED;
     }
     else if(return_value0 == COM_BUSY) {
          return RTE_E_COM_BUSY;
     }
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxTemp(){
/* The algorithm of ReTxTemp */
return;
}
