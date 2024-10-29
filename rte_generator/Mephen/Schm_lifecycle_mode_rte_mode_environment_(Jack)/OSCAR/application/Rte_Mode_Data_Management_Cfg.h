#ifndef RTE_MODE_DATA_MANAGEMENT_CFG_H
#define RTE_MODE_DATA_MANAGEMENT_CFG_H

#include "ring_buffer.h"
#include "Rte_Type.h"

#define notSwitch 0
#define onSwitch 1

// [SWS_Rte_02659] ALPHABETIC_ORDER 
#ifndef RTE_TRANSITION_AC_MDGroup
#define RTE_TRANSITION_AC_MDGroup 3U
#endif
// [SWS_Rte_02568]
#ifndef RTE_MODE_AC_MDGroup_CODE
#define RTE_MODE_AC_MDGroup_CODE 0U
#endif
#ifndef RTE_MODE_AC_MDGroup_HEAT
#define RTE_MODE_AC_MDGroup_HEAT 1U
#endif
#ifndef RTE_MODE_AC_MDGroup_INITMODE
#define RTE_MODE_AC_MDGroup_INITMODE 2U
#endif

#define RE_AC_MODESWITCH_QUEUE 0
#define AC_MDGROUP_STATUS 0

extern RingBuffer *mode_manager_queue[1];
extern ModeStatusType *mode_manager_status[1];

#endif
