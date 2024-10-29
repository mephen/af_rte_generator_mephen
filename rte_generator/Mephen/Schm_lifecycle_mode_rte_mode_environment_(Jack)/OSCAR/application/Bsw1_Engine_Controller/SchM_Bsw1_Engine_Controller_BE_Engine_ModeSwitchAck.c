#define SCHM_API_BE_Engine_ModeSwitchAck
#include "Bsw1_Engine_Controller.h"
#include "../../Os_Configure/inc/event_Cfg.h"
#include "../../Os_Configure/inc/task_Cfg.h"
#include "../Share_Function.h"

// [SWS_Rte_07556]
Std_ReturnType SchM_SwitchAck_Bsw1_Engine_Controller_Engine_MDGroup() {
    Std_ReturnType result = SCHM_E_OK;
    if (schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->switch_status == onSwitch) {
        if (count_0 - IB_Engine_Controller_timeout_count > 1) {
            // [SWS_Rte_07055]
            result = SCHM_E_TIMEOUT;
        } else {
            // [SWS_Rte_07561]
            result = SCHM_E_TRANSMIT_ACK;
        }
    } else {
        // [SWS_Rte_07560]
        result = SCHM_E_NO_DATA;
    }
    return result;
}

void SCHM_BE_Engine_ModeSwitchAck(){
/* The algorithm of BE_Engine_ModeSwitchAck */
    PrintText("BE_Engine_ModeSwitchAck\r\n\0");
    SchMModeType result = SchM_SwitchAck_Bsw1_Engine_Controller_Engine_MDGroup();
    if (result == SCHM_E_TIMEOUT) {
        PrintText("SCHM_E_TIMEOUT\r\n\0");
    } else {
        switch(result) {
            case RTE_MODE_Engine_MDGroup_D:
                PrintText("RTE_MODE_Engine_MDGroup_D\r\n\0");
                break;
            case SCHM_E_TRANSMIT_ACK:
                PrintText("SCHM_E_TRANSMIT_ACK\r\n\0");
                break;
            case SCHM_E_NO_DATA:
                PrintText("SCHM_E_NO_DATA\r\n\0");
                break;
        }
    }
    return;
}
