#include "SchM_Mode_Data_Management_Cfg.h"
#pragma section USER_SHARED_SEC

#define Engine_MDGroup_MAX_SIZE 10

SchMModeType Engine_MDGroup[Engine_MDGroup_MAX_SIZE];

RingBuffer BE_Engine_ModeSwitch_queue = {
    Engine_MDGroup,
    0,
    0,
    Engine_MDGroup_MAX_SIZE,
    0
};

ModeStatusType Engine_MDGroup_status;

RingBuffer *schm_mode_group_set_queue[1] = {&BE_Engine_ModeSwitch_queue};
ModeStatusType *schm_mode_group_set_status[1] = {&Engine_MDGroup_status};

