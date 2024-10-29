#define RTE_RUNNABLEAPI_RE_AC_ModeSwitchAck
#include "App1Swc_ModeManager_Mode.h"
#include "../../Os_Configure/inc/event_Cfg.h"
#include "../../Os_Configure/inc/task_Cfg.h"

// Signature: [SWS_Rte_02725]
Std_ReturnType Rte_SwitchAck_ModeSwitchInterface_PPort_AC_Manager_MDGroup() {
    Std_ReturnType result = RTE_E_OK;
    if (mode_manager_status[AC_MDGROUP_STATUS]->switch_status == notSwitch) {
        // [SWS_Rte_02729]
        result = RTE_E_TRANSMIT_ACK;
    } else {
        // [SWS_Rte_02727]
        result = RTE_E_NO_DATA;
    }
    return result;
}

void RTE_RUNNABLE_RE_AC_ModeSwitchAck(){
/* The algorithm of RE_AC_ModeSwitchAck */
    PrintText("RE_AC_ModeSwitchAck\r\n\0");
    return;
}
