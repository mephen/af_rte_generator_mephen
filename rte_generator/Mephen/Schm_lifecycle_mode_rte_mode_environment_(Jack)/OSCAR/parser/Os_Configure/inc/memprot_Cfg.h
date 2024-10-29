#ifndef MEMPROT_CFG_H
#define MEMPROT_CFG_H
#include "task_Cfg.h"

/* OS Protection Area */
extern MemProtAreaType MemProtArea_OS[3];

extern MemProtAreaType MemStackArea[2];

extern MemProtAreaType MemProtArea_SysTask_core0[2];
extern MemProtAreaType MemProtArea_SysTask_core1[2];

extern MemProtAreaType MemProtArea_T01[2];
extern MemProtAreaType MemProtArea_T02[2];
extern MemProtAreaType MemProtArea_T03[2];
extern MemProtAreaType MemProtArea_T04[2];
extern MemProtAreaType MemProtArea_T05[2];
extern MemProtAreaType MemProtArea_T06[2];
extern MemProtAreaType MemProtArea_I005[2];
extern MemProtAreaType MemProtArea_I006[2];

extern MemProtAreaType MemProtArea_T11[2];
extern MemProtAreaType MemProtArea_T12[2];
extern MemProtAreaType MemProtArea_T13[2];
extern MemProtAreaType MemProtArea_T14[2];
extern MemProtAreaType MemProtArea_T15[2];
extern MemProtAreaType MemProtArea_T16[2];
extern MemProtAreaType MemProtArea_I105[2];
extern MemProtAreaType MemProtArea_I106[2];

extern MemProtAreaType MemProtArea_App1[2];
extern MemProtAreaType MemProtArea_App2[2];
extern MemProtAreaType MemProtArea_App3[2];
extern MemProtAreaType MemProtArea_App4[2];

#define PERI_COOL_ID 0
#define PERI_WOW_ID 1
#define PERI_HAHA_ID 2
#define PERI_FUN_ID 3
#define PERI_TRY_ID 4
#define OsPeriAreaID_INVALID 5
#define OsPeriAreaID_COUNT 5

extern OsPeriAreaInfoType OsPeriAreaInfoArr[OsPeriAreaID_COUNT];

#pragma section

#endif

