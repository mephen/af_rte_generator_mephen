/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009, 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* This file content the generated implementation of isr */

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
        I002,       //ISRType isrID;
        ISR_CAT_2,  //uint8 ISRcategory;
        10,         //uint8 ISRprio;
        44,         //uint16 ISRchannel;
        (I002+TASKS_COUNT_CORE0-1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I003,       //ISRType isrID;
        ISR_CAT_2,  //uint8 ISRcategory;
        11,         //uint8 ISRprio;
        45,         //uint16 ISRchannel;
        (I003+TASKS_COUNT_CORE0-1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I005,       //ISRType isrID;
        ISR_CAT_2,  //uint8 ISRcategory;
        12,         //uint8 ISRprio;
        94,         //uint16 ISRchannel;
        (I005+TASKS_COUNT_CORE0-1),   //TaskType ISR2TaskRefIndex;
    },
    {
        I006,       //ISRType isrID;
        ISR_CAT_2,  //uint8 ISRcategory;
        13,         //uint8 ISRprio;
        95,         //uint16 ISRchannel;
        (I006+TASKS_COUNT_CORE0-1),   //TaskType ISR2TaskRefIndex;
    },
    {
        I001,       //ISRType isrID;
        ISR_CAT_1,  //uint8 ISRcategory;
        2,          //uint8 ISRprio;
        43,         //uint16 ISRchannel;
        0,          //isr1 special case //TaskType ISR2TaskRefIndex;
    },
    {
        I004,       //ISRType isrID;
        ISR_CAT_1,  //uint8 ISRcategory;
        3,          //uint8 ISRprio;
        93,         //uint16 ISRchannel;
        0,          //isr1 special case //TaskType ISR2TaskRefIndex;
    },
};

IsrConstType Isr_const_core1[ISR_ALL_COUNT_CORE1] = {
    {
        I102,       //ISRType isrID;
        ISR_CAT_2,  //uint8 ISRcategory;
        10,         //uint8 ISRprio;
        129,        //uint16 ISRchannel;
        (I102+TASKS_COUNT_CORE1-1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I103,       //ISRType isrID;
        ISR_CAT_2,  //uint8 ISRcategory;
        11,         //uint8 ISRprio;
        130,        //uint16 ISRchannel;
        (I103+TASKS_COUNT_CORE1-1),       //TaskType ISR2TaskRefIndex;
    },
    {
        I105,       //ISRType isrID;
        ISR_CAT_2,  //uint8 ISRcategory;
        12,         //uint8 ISRprio;
        187,        //uint16 ISRchannel;
        (I105+TASKS_COUNT_CORE1-1),   //TaskType ISR2TaskRefIndex;
    },
    {
        I106,       //ISRType isrID;
        ISR_CAT_2,  //uint8 ISRcategory;
        13,         //uint8 ISRprio;
        188,        //uint16 ISRchannel;
        (I106+TASKS_COUNT_CORE1-1),   //TaskType ISR2TaskRefIndex;
    },
    {
        I101,       //ISRType isrID;
        ISR_CAT_1,  //uint8 ISRcategory;
        2,          //uint8 ISRprio;
        128,        //uint16 ISRchannel;
        0,          //isr1 special case //TaskType ISR2TaskRefIndex;
    },
    {
        I104,       //ISRType isrID;
        ISR_CAT_1,  //uint8 ISRcategory;
        3,          //uint8 ISRprio;
        186,        //uint16 ISRchannel;
        0,          //isr1 special case //TaskType ISR2TaskRefIndex;
    },
};   

IsrConstRefType Isr_const[OsNumberOfCores] = {
    Isr_const_core0,
    Isr_const_core1,
};

IsrAutosarType IsrAutosar_core0[ISR_ALL_COUNT_CORE0] = {
    //I002
    {
        app_lion,                           //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2),  //ApplicationsMaskType applicationsMask; 
    },
    //I003
    {
        app_lion,                           //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2),  //ApplicationsMaskType applicationsMask; 
    },
    //I005
    {
        app3,                       //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4),  
    },
    //I006
    {
        app3,                       //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), 
    },
    //I001
    {
        app_lion,                           //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2),  //ApplicationsMaskType applicationsMask;
    },
    //I004
    {
        app_lion,                           //ApplicationType owner;
        0 | (1 << app_lion)| (1 << app2),   //ApplicationsMaskType applicationsMask;
    },
};

IsrAutosarType IsrAutosar_core1[ISR_ALL_COUNT_CORE1] = {
    //I102
    {
        app2,                           //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2),  //ApplicationsMaskType applicationsMask;
    },
    //I103
    {
        app2,                           //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2),  //ApplicationsMaskType applicationsMask;
    },
    //I105
    {
        app4,                       //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4),            
    },
    //I106
    {
        app4,                       //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4),   
    },
    //I101
    {
        app2,                           //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2),  //ApplicationsMaskType applicationsMask;
    },
    //I104
    {
        app2,                           //ApplicationType owner;
        0 | (1 << app_lion) | (1 << app2),  //ApplicationsMaskType applicationsMask;
    },
};

/*==================[ISR launhcer]========================================*/



/* I002 launhcer */
#pragma interrupt ISR_I002_Launcher(enable = manual, channel = 44, callt = false, fpu = false)
void ISR_I002_Launcher(void)
{
    DisableMPU();
    ActivateISR2(I002);
    EnableMPU();
}

/* I101 launhcer */
#pragma interrupt ISR_I001_Launcher(enable = manual, channel = 43, callt = false, fpu = false)
void ISR_I001_Launcher(void)
{
    DisableMPU();
    systemFlag |= IN_ISR1_HANDLER;
    MILKSHOP_ISR_I001();
    systemFlag &= ~IN_ISR1_HANDLER;
    EnableMPU();
}

/* I102 launhcer */
#pragma interrupt ISR_I102_Launcher(enable = manual, channel = 129, callt = false, fpu = false)
void ISR_I102_Launcher(void)
{
    DisableMPU();
    ActivateISR2(I102);
    EnableMPU();
}
/* I103 launhcer */
#pragma interrupt ISR_I103_Launcher(enable = manual, channel = 130, callt = false, fpu = false)
void ISR_I103_Launcher(void)
{
    DisableMPU();
    ActivateISR2(I103);
    EnableMPU();
}
