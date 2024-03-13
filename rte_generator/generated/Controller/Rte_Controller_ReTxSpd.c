#define RTE_RUNNABLEAPI_ReTxSpd
#include "Rte_Controller.h" 
#include "../com_data_management.h"
Std_ReturnType Rte_Write_PpIfVehSpd_Spd(Impl_uint16 data){

     Com_SignalIdType com_handle_id = 1;
     Std_ReturnType return_value0 = Com_SendSignal(com_handle_id, &data);
     if(return_value0 == COM_SERVICE_NOT_AVAILABLE) {
          return RTE_E_COM_STOPPED;
     }
     else if(return_value0 == COM_BUSY) {
          return RTE_E_COM_BUSY;
     }
     return RTE_E_OK;
}
Std_ReturnType Rte_Invalidate_PpIfVehSpd_Spd(){

     // Write the invalid value that config in SwDataDefProps.InvalidValue
     Impl_uint16 data = 255;
     Com_SignalIdType com_handle_id = 1;
     Std_ReturnType return_value0 = Com_SendSignal(com_handle_id, &data);
     if(return_value0 == COM_SERVICE_NOT_AVAILABLE) {
          return RTE_E_COM_STOPPED;
     }
     else if(return_value0 == COM_BUSY) {
          return RTE_E_COM_BUSY;
     }
     return RTE_E_OK;
}
void RTE_RUNNABLE_ReTxSpd(){
/* The algorithm of ReTxSpd */
return;
}
