#include "Rte_Mode_Data_Management_Cfg.h"
#pragma section USER_SHARED_SEC

#define AC_MDGroup_MAX_SIZE 10

RteModeType AC_MDGroup[AC_MDGroup_MAX_SIZE];

RingBuffer RE_AC_ModeSwitch_queue = {
    AC_MDGroup,
    0,
    0,
    AC_MDGroup_MAX_SIZE,
    0
};

ModeStatusType AC_MDGroup_status;

RingBuffer *mode_manager_queue[1] = {&RE_AC_ModeSwitch_queue};
ModeStatusType *mode_manager_status[1] = {&AC_MDGroup_status};

