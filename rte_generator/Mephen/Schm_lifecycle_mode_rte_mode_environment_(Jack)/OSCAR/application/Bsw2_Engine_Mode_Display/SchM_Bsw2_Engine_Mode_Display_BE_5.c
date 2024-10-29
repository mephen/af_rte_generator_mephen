#define SCHM_API_BE_5
#include "Bsw2_Engine_Mode_Display.h"
#include "../../Os_Configure/inc/event_Cfg.h"
#include "../../Os_Configure/inc/task_Cfg.h"

// [SWS_Rte_07260]
SchMModeType SchM_Mode_Bsw2_Engine_Mode_Display_Engine_MDGroup() {
    if (schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->switch_status == notSwitch) {
        return schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->currentmode;
    } else {
        return RTE_TRANSITION_Engine_MDGroup;
    }
}

void SCHM_BE_5(){
/* The algorithm of BE_5 */
    PrintText("BE_5\r\n\0");
    SchMModeType result = SchM_Mode_Bsw2_Engine_Mode_Display_Engine_MDGroup();
    if (result == RTE_TRANSITION_Engine_MDGroup) {
        PrintText("RTE_TRANSITION_Engine_MDGroup\r\n\0");
    } else {
        switch(result) {
            case RTE_MODE_Engine_MDGroup_D:
                PrintText("RTE_MODE_Engine_MDGroup_D\r\n\0");
                break;
            case RTE_MODE_Engine_MDGroup_INITMODE:
                PrintText("RTE_MODE_Engine_MDGroup_INITMODE\r\n\0");
                break;
            case RTE_MODE_Engine_MDGroup_N:
                PrintText("RTE_MODE_Engine_MDGroup_N\r\n\0");
                break;
            case RTE_MODE_Engine_MDGroup_P:
                PrintText("RTE_MODE_Engine_MDGroup_P\r\n\0");
                break;
            case RTE_MODE_Engine_MDGroup_R:
                PrintText("RTE_MODE_Engine_MDGroup_R\r\n\0");
                break;
        }
    }
    return;
}
