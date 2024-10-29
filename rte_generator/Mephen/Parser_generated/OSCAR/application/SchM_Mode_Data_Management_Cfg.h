#ifndef SCHM_MODE_DATA_MANAGEMENT_CFG_H
#define SCHM_MODE_DATA_MANAGEMENT_CFG_H

#include "ringbuffer.h"
#include "Rte_Type.h"

#define notSwitch 0
#define onSwitch 1

// [SWS_Rte_07293] ALPHABETIC_ORDER 
#ifndef RTE_TRANSITION_Engine_MDGroup
#define RTE_TRANSITION_Engine_MDGroup 14U
#endif
// [SWS_Rte_07294]
#ifndef RTE_MODE_Engine_MDGroup_D
#define RTE_MODE_Engine_MDGroup_D 0U
#endif
#ifndef RTE_MODE_Engine_MDGroup_INITMODE
#define RTE_MODE_Engine_MDGroup_INITMODE 1U
#endif
#ifndef RTE_MODE_Engine_MDGroup_N
#define RTE_MODE_Engine_MDGroup_N 2U
#endif
#ifndef RTE_MODE_Engine_MDGroup_P
#define RTE_MODE_Engine_MDGroup_P 3U
#endif
#ifndef RTE_MODE_Engine_MDGroup_R
#define RTE_MODE_Engine_MDGroup_R 4U
#endif

#define BE_ENGINE_MODESWITCH_QUEUE 0
#define ENGINE_MDGROUP_STATUS 0

extern RingBuffer *schm_mode_group_set_queue[1];
extern ModeStatusType *schm_mode_group_set_status[1];

#endif
