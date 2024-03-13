#include "Rte_Cbk.h"

void Rte_COMCbk (CbkHandleIdType ComUserCbkHandleId){
    MyUint16OfVendorID temp = 0;
    Std_ReturnType return_value = Com_ReceiveSignal(ComUserCbkHandleId, &temp);
    if(return_value == E_OK){
        switch(ComUserCbkHandleId){
            case 1:
                return_value = RTE_Update(temp, &ComSignal1_1_Spd, sizeof(MyUint16OfVendorID));
                break;
            case 2:
                return_value = RTE_Update(temp, &ComSignal2_2_Acc, sizeof(MyUint16OfVendorID));
                break;
            case 3:
                return_value = RTE_Enqueue(&RB_ComSignal3_3_Temp, &temp, sizeof(MyUint16OfVendorID));
                break;
            default:
                break;
        }
    }
}