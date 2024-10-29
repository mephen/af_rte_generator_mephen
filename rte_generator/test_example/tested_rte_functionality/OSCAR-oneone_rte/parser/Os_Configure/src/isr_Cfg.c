/*==================[inclusions]=============================================*/
#include "isr_Cfg.h"
#include "task_Cfg.h"
#include "isr2.h"
#include "system.h"
#include "os.h"
#include "task.h"
#include "dr7f701527.dvf.h"
#include "scheduler.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

IsrConstType Isr_const_core0[ISR_ALL_COUNT_CORE0] = {
    {
        I005,
        ISR_CAT_2,
        10,//uint8 ISRprio;
        60,//uint16 ISRchannel;
        (I005 + TASKS_COUNT_CORE0 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I006,
        ISR_CAT_2,
        7,//uint8 ISRprio;
        61,//uint16 ISRchannel;
        (I006 + TASKS_COUNT_CORE0 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I001,
        ISR_CAT_1,
        1,//uint8 ISRprio;
        26,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
    {
        I002,
        ISR_CAT_1,
        2,//uint8 ISRprio;
        217,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
    {
        I003,
        ISR_CAT_1,
        3,//uint8 ISRprio;
        68,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
    {
        I004,
        ISR_CAT_1,
        4,//uint8 ISRprio;
        69,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
},
IsrConstType Isr_const_core1[ISR_ALL_COUNT_CORE1] = {
    {
        I105,
        ISR_CAT_2,
        11,//uint8 ISRprio;
        206,//uint16 ISRchannel;
        (I105 + TASKS_COUNT_CORE1 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I106,
        ISR_CAT_2,
        12,//uint8 ISRprio;
        86,//uint16 ISRchannel;
        (I106 + TASKS_COUNT_CORE1 - 1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I101,
        ISR_CAT_1,
        7,//uint8 ISRprio;
        96,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
    {
        I102,
        ISR_CAT_1,
        8,//uint8 ISRprio;
        76,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
    {
        I103,
        ISR_CAT_1,
        9,//uint8 ISRprio;
        96,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
    {
        I104,
        ISR_CAT_1,
        10,//uint8 ISRprio;
        206,//uint16 ISRchannel;
        0,       //TaskType ISR2TaskRefIndex;
    },
},
IsrConstRefType Isr_const[OsNumberOfCores] = {
    Isr_const_core0,
    Isr_const_core1,
};
IsrAutosarType IsrAutosar_core0[ISR_ALL_COUNT_CORE0] = {
    //I005
    {
        App1,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I006
    {
        App1,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I001
    {
        App1,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I002
    {
        App1,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I003
    {
        App1,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I004
    {
        App1,
        0 | (1 << App3) | (1 << App4) ,
    },
};

IsrAutosarType IsrAutosar_core1[ISR_ALL_COUNT_CORE1] = {
    //I105
    {
        App2,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I106
    {
        App2,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I101
    {
        App2,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I102
    {
        App2,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I103
    {
        App2,
        0 | (1 << App3) | (1 << App4) ,
    },
    //I104
    {
        App2,
        0 | (1 << App3) | (1 << App4) ,
    },
};

/*==================[ISR launhcer]========================================*/
/* I005 launhcer*/
#pragma interrupt ISR_I005_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I005_Launcher(void)
{
    DisableMPU();
    ActivateISR2(I005);
    EnableMPU();
}

/* I006 launhcer*/
#pragma interrupt ISR_I006_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I006_Launcher(void)
{
    DisableMPU();
    ActivateISR2(I006);
    EnableMPU();
}

/* I001 launhcer*/
#pragma interrupt ISR_I001_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I001_Launcher(void)
{
    systemFlag |= IN_ISR1_HANDLER;
    DisableMPU();
    MILKSHOP_ISR_I001();
    EnableMPU();
    systemFlag &= ~IN_ISR1_HANDLER;
}

/* I002 launhcer*/
#pragma interrupt ISR_I002_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I002_Launcher(void)
{
    systemFlag |= IN_ISR1_HANDLER;
    DisableMPU();
    MILKSHOP_ISR_I002();
    EnableMPU();
    systemFlag &= ~IN_ISR1_HANDLER;
}

/* I003 launhcer*/
#pragma interrupt ISR_I003_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I003_Launcher(void)
{
    systemFlag |= IN_ISR1_HANDLER;
    DisableMPU();
    MILKSHOP_ISR_I003();
    EnableMPU();
    systemFlag &= ~IN_ISR1_HANDLER;
}

/* I004 launhcer*/
#pragma interrupt ISR_I004_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I004_Launcher(void)
{
    systemFlag |= IN_ISR1_HANDLER;
    DisableMPU();
    MILKSHOP_ISR_I004();
    EnableMPU();
    systemFlag &= ~IN_ISR1_HANDLER;
}

/* I105 launhcer*/
#pragma interrupt ISR_I105_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I105_Launcher(void)
{
    DisableMPU();
    ActivateISR2(I105);
    EnableMPU();
}

/* I106 launhcer*/
#pragma interrupt ISR_I106_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I106_Launcher(void)
{
    DisableMPU();
    ActivateISR2(I106);
    EnableMPU();
}

/* I101 launhcer*/
#pragma interrupt ISR_I101_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I101_Launcher(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I101();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}

/* I102 launhcer*/
#pragma interrupt ISR_I102_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I102_Launcher(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I102();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}

/* I103 launhcer*/
#pragma interrupt ISR_I103_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I103_Launcher(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I103();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}

/* I104 launhcer*/
#pragma interrupt ISR_I104_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I104_Launcher(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I104();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}

