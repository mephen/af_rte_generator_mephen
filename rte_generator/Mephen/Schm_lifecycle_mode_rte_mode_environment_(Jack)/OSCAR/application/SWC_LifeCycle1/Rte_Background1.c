//VFB interface(api) & Runnable Implementation
//----------------------------------------------------------------
#define RTE_BACKGROUND1_C
#include "Rte_LifeCycle1.h"
#include "../../Os_Configure/inc/event_Cfg.h"
#include "../../Os_Configure/inc/task_Cfg.h"

void RTE_RUNNABLE_RTE_background1(void)
{
    PrintText("RTE_background1\r\n\0");
    return;
}
