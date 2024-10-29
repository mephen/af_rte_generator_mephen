#define RTE_RUNNABLEAPI_RE_3
#include "App2Swc_ModeUser_Mode.h"
#include "../../Os_Configure/inc/event_Cfg.h"
#include "../../Os_Configure/inc/task_Cfg.h"

// Signature: [SWS_Rte_02628]
RteModeType Rte_Mode_ModeSwitchInterface_RPort_AC_Manager_MDGroup() {
    if (mode_manager_status[AC_MDGROUP_STATUS]->switch_status == notSwitch) {
        return mode_manager_status[AC_MDGROUP_STATUS]->currentmode;
    } else {
        return RTE_TRANSITION_AC_MDGroup;
    }
}

void RTE_RUNNABLE_RE_3(){
/* The algorithm of RE_3 */
    PrintText("RE_3\r\n\0");
    RteModeType result = Rte_Mode_ModeSwitchInterface_RPort_AC_Manager_MDGroup();
    if (result == RTE_TRANSITION_AC_MDGroup) {
        PrintText("RTE_TRANSITION_Engine_MDGroup\r\n\0");
    } else {
        switch(result) {
            case RTE_MODE_AC_MDGroup_CODE:
                PrintText("RTE_MODE_AC_MDGroup_CODE\r\n\0");
                break;
            case RTE_MODE_AC_MDGroup_HEAT:
                PrintText("RTE_MODE_AC_MDGroup_HEAT\r\n\0");
                break;
            case RTE_MODE_AC_MDGroup_INITMODE:
                PrintText("RTE_MODE_AC_MDGroup_INITMODE\r\n\0");
                break;
        }
    }
    return;
}
