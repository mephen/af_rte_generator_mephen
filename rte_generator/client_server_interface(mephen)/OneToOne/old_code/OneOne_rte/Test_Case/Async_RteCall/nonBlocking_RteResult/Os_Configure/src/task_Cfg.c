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

/* This file content the generated implementation of task */

/*==================[inclusions]=============================================*/
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "application_Cfg.h"
#include "spinlock_Cfg.h"
#include "memsection.h"
#include "memprot_Cfg.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/* core 0 */
#pragma section ALL_TASK_ISR_STACK_PE1
/* Brief idle task stack */
uint8 StackTaskIdleTask_core0[StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief sys task stack */
uint8 StackTaskSysTask_core0[StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T01 stack */
uint8 StackTaskT01[StackTaskT01_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T02 stack */
uint8 StackTaskT02[StackTaskT02_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T03 stack */
uint8 StackTaskT03[StackTaskT03_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T04 stack */
uint8 StackTaskT04[StackTaskT04_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T05 stack */
uint8 StackTaskT05[StackTaskT05_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T06 stack */
uint8 StackTaskT06[StackTaskT06_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I002 stack */
uint8 StackIsr2TaskI002[StackIsr2TaskI002_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I003 stack */
uint8 StackIsr2TaskI003[StackIsr2TaskI003_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I005 stack */
uint8 StackIsr2TaskI005[StackIsr2TaskI005_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I006 stack */
uint8 StackIsr2TaskI006[StackIsr2TaskI006_SIZE + STACK_MONITOR_APPEND_SIZE];

/* core 1 */
#pragma section ALL_TASK_ISR_STACK_PE2
/* Brief idle task stack */
uint8 StackTaskIdleTask_core1[StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief sys task stack */
uint8 StackTaskSysTask_core1[StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T11 stack */
uint8 StackTaskT11[StackTaskT11_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T12 stack */
uint8 StackTaskT12[StackTaskT12_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T13 stack */
uint8 StackTaskT13[StackTaskT13_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T14 stack */
uint8 StackTaskT14[StackTaskT14_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T15 stack */
uint8 StackTaskT15[StackTaskT15_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief T16 stack */
uint8 StackTaskT16[StackTaskT16_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I102 stack */
uint8 StackIsr2TaskI102[StackIsr2TaskI102_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I103 stack */
uint8 StackIsr2TaskI103[StackIsr2TaskI103_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I105 stack */
uint8 StackIsr2TaskI105[StackIsr2TaskI105_SIZE + STACK_MONITOR_APPEND_SIZE];
/* Brief I106 stack */
uint8 StackIsr2TaskI106[StackIsr2TaskI106_SIZE + STACK_MONITOR_APPEND_SIZE];

#pragma section 
/* Brief idle task context */
TaskContextType ContextIdleTask_core0;
/* Brief sys task context */
TaskContextType ContextSysTask_core0;
/* Brief T01 context */
TaskContextType ContextT01;
/* Brief T02 context */
TaskContextType ContextT02;
/* Brief T03 context */
TaskContextType ContextT03;
/* Brief T04 context */
TaskContextType ContextT04;
/* Brief T05 context */
TaskContextType ContextT05;
/* Brief T06 context */
TaskContextType ContextT06;
/* Brief I002 context */
TaskContextType ContextI002;
/* Brief I003 context */
TaskContextType ContextI003;
/* Brief I005 context */
TaskContextType ContextI005;
/* Brief I006 context */
TaskContextType ContextI006;

TaskVarType *ReadyList_core0[READYLISTS_COUNT_CORE0];

TaskVarType *ReadyListTail_core0[READYLISTS_COUNT_CORE0];

/* Brief idle task context */
TaskContextType ContextIdleTask_core1;
/* Brief sys task context */
TaskContextType ContextSysTask_core1;
/* Brief T11 context */
TaskContextType ContextT11;
/* Brief T12 context */
TaskContextType ContextT12;
/* Brief T13 context */
TaskContextType ContextT13;
/* Brief T14 context */
TaskContextType ContextT14;
/* Brief T15 context */
TaskContextType ContextT15;
/* Brief T16 context */
TaskContextType ContextT16;
/* Brief I102 context */
TaskContextType ContextI102;
/* Brief I103 context */
TaskContextType ContextI103;
/* Brief I105 context */
TaskContextType ContextI105;
/* Brief I106 context */
TaskContextType ContextI106;

TaskVarType *ReadyList_core1[READYLISTS_COUNT_CORE1];

TaskVarType *ReadyListTail_core1[READYLISTS_COUNT_CORE1];

const TaskConstType TaskConst_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* Task IdleTask */
    {            
        TASK_ENTRY(IdleTask),            /* task entry point */
        &ContextIdleTask_core0,          /* pointer to task context */
        StackTaskIdleTask_core0,         /* pointer to stack memory */
        StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE,    /* stack size */
        IdleTask_core0,                  /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_idle_core0, /* task priority */
        1, /* task max activations */
        0, /* events mask */
        0,  /* resources mask */
        
        //RomToRamInitTableType RomToRamInitTable
        {
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0   /* IdleTask special case */
        }
    },
    /* Task T01 */
    {
        TASK_ENTRY(T01),            /* task entry point */
        &ContextT01, /* pointer to task context */
        StackTaskT01,    /* pointer to stack memory */
        StackTaskT01_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T01,     /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0 , /* not isr2 task */
        },
        task_static_prio_T01, /* task priority */
        55, /* task max activations */
        0 | event1, /* events mask */
        0 | (1 << (resourceApp1 & 0xffff)), /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T001_SEC_data),
            (uint32*)(_ETASK_T001_SEC_data),
            (uint32*)(_STASK_T001_SEC_data_R),
            (uint32*)(_STASK_T001_SEC_bss),
            (uint32*)(_ETASK_T001_SEC_bss)
        }
    },
    /* Task T02 */
    {
        TASK_ENTRY(T02),            /* task entry point */
        &ContextT02, /* pointer to task context */
        StackTaskT02,    /* pointer to stack memory */
        StackTaskT02_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T02,     /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T02, /* task priority */
        10, /* task max activations */
        0 | event1 , /* events mask */
        0 | (1 << (resource1 & 0xffff))  | (1 << (resource2 & 0xffff)) | (1 << (resource3 & 0xffff)) | (1 << (resourceApp1 & 0xffff)),   /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T002_SEC_data),
            (uint32*)(_ETASK_T002_SEC_data),
            (uint32*)(_STASK_T002_SEC_data_R),
            (uint32*)(_STASK_T002_SEC_bss),
            (uint32*)(_ETASK_T002_SEC_bss)
        }
    },
    /* Task T04 */
    {
        TASK_ENTRY(T04),            /* task entry point */
        &ContextT04, /* pointer to task context */
        StackTaskT04,    /* pointer to stack memory */
        StackTaskT04_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T04,     /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T04, /* task priority */
        1, /* task max activations */
        0, /* events mask */
        0 | (1 << (resourceApp3 & 0xffff)), /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T004_SEC_data),
            (uint32*)(_ETASK_T004_SEC_data),
            (uint32*)(_STASK_T004_SEC_data_R),
            (uint32*)(_STASK_T004_SEC_bss),
            (uint32*)(_ETASK_T004_SEC_bss)
        }
    },
    /* Task T05 */
    {
        TASK_ENTRY(T05),            /* task entry point */
        &ContextT05, /* pointer to task context */
        StackTaskT05,    /* pointer to stack memory */
        StackTaskT05_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T05,     /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T05, /* task priority */
        1, /* task max activations */
        0 | event3 , /* events mask */
        0 | (1 << (resource1 & 0xffff))  | (1 << (resource2 & 0xffff)) | (1 << (resource3 & 0xffff)) | (1 << (resourceApp3 & 0xffff)),   /* resources mask */
    
        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T005_SEC_data),
            (uint32*)(_ETASK_T005_SEC_data),
            (uint32*)(_STASK_T005_SEC_data_R),
            (uint32*)(_STASK_T005_SEC_bss),
            (uint32*)(_ETASK_T005_SEC_bss)
        }
    },
    /* Task T03 */
    {
        TASK_ENTRY(T03),            /* task entry point */
        &ContextT03, /* pointer to task context */
        StackTaskT03,    /* pointer to stack memory */
        StackTaskT03_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T03,     /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T03, /* task priority */
        10, /* task max activations */
        0 | event1, /* events mask */
        0 | (1 << (resourceApp1 & 0xffff)),  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T003_SEC_data),
            (uint32*)(_ETASK_T003_SEC_data),
            (uint32*)(_STASK_T003_SEC_data_R),
            (uint32*)(_STASK_T003_SEC_bss),
            (uint32*)(_ETASK_T003_SEC_bss)
        }
    },
    /* Task T06 */
    {
        TASK_ENTRY(T06),            /* task entry point */
        &ContextT06, /* pointer to task context */
        StackTaskT06,    /* pointer to stack memory */
        StackTaskT06_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T06,     /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T06, /* task priority */
        10, /* task max activations */
        0, /* events mask */
        0 | (1 << (resourceApp3 & 0xffff)),  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T006_SEC_data),
            (uint32*)(_ETASK_T006_SEC_data),
            (uint32*)(_STASK_T006_SEC_data_R),
            (uint32*)(_STASK_T006_SEC_bss),
            (uint32*)(_ETASK_T006_SEC_bss)
        }
    },
    /* isr I002 Task  */
    {
        ISR_ENTRY(I002),            /* task entry point */
        &ContextI002, /* pointer to task context */
        StackIsr2TaskI002,    /* pointer to stack memory */
        StackIsr2TaskI002_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I002 + TASKS_COUNT_CORE0 - 1,     /* isr2 task id */
        {      /* task const flags */
            0, /* extended task */      //isr2-task is always a basic task
            1, /* preemptive task */    //isr2-task is always a preemptive task
            1  /* not isr2 task */
        },
        task_static_prio_I002, /* task priority */
        255, /* task max activations */ //isr2-task default value is max value
        0, /* events mask */            //isr2-task is always a basic task
        0 | (1 << (resourceApp1 & 0xffff)), /* resources mask */         //checked in OIL

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I002_SEC_data),
            (uint32*)(_EISR_I002_SEC_data),
            (uint32*)(_SISR_I002_SEC_data_R),
            (uint32*)(_SISR_I002_SEC_bss),
            (uint32*)(_EISR_I002_SEC_bss)
        }
    },
    /* isr I003 Task  */
    {
        ISR_ENTRY(I003),            /* task entry point */
        &ContextI003, /* pointer to task context */
        StackIsr2TaskI003,    /* pointer to stack memory */
        StackIsr2TaskI003_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I003 + TASKS_COUNT_CORE0 - 1,     /* isr2 task id */
        {      /* task const flags */
            0, /* extended task */      //isr2-task is always a basic task
            1, /* preemptive task */    //isr2-task is always a preemptive task
            1  /* not isr2 task */
        },
        task_static_prio_I003, /* task priority */
        255, /* task max activations */ //isr2-task default value is max value
        0, /* events mask */            //isr2-task is always a basic task
        0 | (1 << (resourceApp1 & 0xffff)), /* resources mask */         //checked in OIL

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I003_SEC_data),
            (uint32*)(_EISR_I003_SEC_data),
            (uint32*)(_SISR_I003_SEC_data_R),
            (uint32*)(_SISR_I003_SEC_bss),
            (uint32*)(_EISR_I003_SEC_bss)
        }
    },
    /* isr I005 Task  */
    {
        ISR_ENTRY(I005),            /* task entry point */
        &ContextI005, /* pointer to task context */
        StackIsr2TaskI005,    /* pointer to stack memory */
        StackIsr2TaskI005_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I005 + TASKS_COUNT_CORE0 - 1,     /* isr2 task id */
        {      /* task const flags */
            0, /* extended task */      //isr2-task is always a basic task
            1, /* preemptive task */    //isr2-task is always a preemptive task
            1  /* not isr2 task */
        },
        task_static_prio_I005, /* task priority */
        255, /* task max activations */ //isr2-task default value is max value
        0, /* events mask */            //isr2-task is always a basic task
        0 | (1 << (resourceApp3 & 0xffff)), /* resources mask */         //checked in OIL

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I005_SEC_data),
            (uint32*)(_EISR_I005_SEC_data),
            (uint32*)(_SISR_I005_SEC_data_R),
            (uint32*)(_SISR_I005_SEC_bss),
            (uint32*)(_EISR_I005_SEC_bss)
        }
    },
    /* isr I006 Task  */
    {
        ISR_ENTRY(I006),            /* task entry point */
        &ContextI006, /* pointer to task context */
        StackIsr2TaskI006,    /* pointer to stack memory */
        StackIsr2TaskI006_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I006 + TASKS_COUNT_CORE0 - 1,     /* isr2 task id */
        {      /* task const flags */
            0, /* extended task */      //isr2-task is always a basic task
            1, /* preemptive task */    //isr2-task is always a preemptive task
            1  /* not isr2 task */
        },
        task_static_prio_I006, /* task priority */
        255, /* task max activations */ //isr2-task default value is max value
        0, /* events mask */            //isr2-task is always a basic task
        0 | (1 << (resourceApp3 & 0xffff)), /* resources mask */         //checked in OIL

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I006_SEC_data),
            (uint32*)(_EISR_I006_SEC_data),
            (uint32*)(_SISR_I006_SEC_data_R),
            (uint32*)(_SISR_I006_SEC_bss),
            (uint32*)(_EISR_I006_SEC_bss)
        }
    },
    /* Task SysTask */
    {            
        TASK_ENTRY(SysTask),            /* task entry point */
        &ContextSysTask_core0,          /* pointer to task context */
        StackTaskSysTask_core0,         /* pointer to stack memory */
        StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE,    /* stack size */
        SysTask_core0,                  /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_sys_core0, /* task priority */
        255, /* task max activations */
        0, /* events mask */
        0 | (1 << (resourceApp1 & 0xffff)) | (1 << (resourceApp3 & 0xffff)),  /* resources mask */
        
        //RomToRamInitTableType RomToRamInitTable
        {
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0   /* SysTask special case */
        }
    },
};

const TaskConstType TaskConst_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* Task IdleTask */
    {
        MILKSHOP_TASK_IdleTask,         /* task entry point */
        &ContextIdleTask_core1,             /* pointer to task context */
        StackTaskIdleTask_core1,            /* pointer to stack memory */
        StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE,    /* stack size */
        IdleTask_core1,                     /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_idle_core1, /* task priority */
        1, /* task max activations */
        0, /* events mask */
        0,  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0,  /* IdleTask special case */
            0  /* IdleTask special case */
        }
    },
    /* Task T11 */
    {
        MILKSHOP_TASK_T11,   /* task entry point */
        &ContextT11, /* pointer to task context */
        StackTaskT11,    /* pointer to stack memory */
        StackTaskT11_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T11,     /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T11, /* task priority */
        1, /* task max activations */
        0 | event1 , /* events mask */
        0 | (1 << (resourceApp2 & 0xffff)),  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T101_SEC_data),
            (uint32*)(_ETASK_T101_SEC_data),
            (uint32*)(_STASK_T101_SEC_data_R),
            (uint32*)(_STASK_T101_SEC_bss),
            (uint32*)(_ETASK_T101_SEC_bss)
        }
    },
    /* Task T14 */
    {
        MILKSHOP_TASK_T14,   /* task entry point */
        &ContextT14, /* pointer to task context */
        StackTaskT14,    /* pointer to stack memory */
        StackTaskT14_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T14,     /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T14, /* task priority */
        1, /* task max activations */
        0 | event1 | event2, /* events mask */
        0 | (1 << (resourceApp4 & 0xffff)),  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T104_SEC_data),
            (uint32*)(_ETASK_T104_SEC_data),
            (uint32*)(_STASK_T104_SEC_data_R),
            (uint32*)(_STASK_T104_SEC_bss),
            (uint32*)(_ETASK_T104_SEC_bss)
        }
    },
    /* Task T12 */
    {
        MILKSHOP_TASK_T12,   /* task entry point */
        &ContextT12, /* pointer to task context */
        StackTaskT12,    /* pointer to stack memory */
        StackTaskT12_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T12,     /* task id */
        {      /* task const flags */
            1, /* extended task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T12, /* task priority */
        10, /* task max activations */
        0, /* events mask */
        0 | (1 << (resourceApp2 & 0xffff)),  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T102_SEC_data),
            (uint32*)(_ETASK_T102_SEC_data),
            (uint32*)(_STASK_T102_SEC_data_R),
            (uint32*)(_STASK_T102_SEC_bss),
            (uint32*)(_ETASK_T102_SEC_bss)
        }
    },
    /* Task T13 */
    {
        MILKSHOP_TASK_T13,   /* task entry point */
        &ContextT13, /* pointer to task context */
        StackTaskT13,    /* pointer to stack memory */
        StackTaskT13_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T13,     /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T13, /* task priority */
        1, /* task max activations */
        0, /* events mask */
        0 | ( 1 << (resource4 & 0xffff)) | ( 1 << (resource5 & 0xffff)) | ( 1 << (resource6 & 0xffff)) | (1 << (resourceApp2 & 0xffff)), /* resources mask */
        
        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T103_SEC_data),
            (uint32*)(_ETASK_T103_SEC_data),
            (uint32*)(_STASK_T103_SEC_data_R),
            (uint32*)(_STASK_T103_SEC_bss),
            (uint32*)(_ETASK_T103_SEC_bss)
        }
    },
    /* Task T15 */
    {
        MILKSHOP_TASK_T15,   /* task entry point */
        &ContextT15, /* pointer to task context */
        StackTaskT15,    /* pointer to stack memory */
        StackTaskT15_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T15,     /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T15, /* task priority */
        10, /* task max activations */
        0, /* events mask */
        0 | (1 << (resourceApp4 & 0xffff)),  /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T105_SEC_data),
            (uint32*)(_ETASK_T105_SEC_data),
            (uint32*)(_STASK_T105_SEC_data_R),
            (uint32*)(_STASK_T105_SEC_bss),
            (uint32*)(_ETASK_T105_SEC_bss)
        }
    },
    /* Task T16 */
    {
        MILKSHOP_TASK_T16,   /* task entry point */
        &ContextT16, /* pointer to task context */
        StackTaskT16,    /* pointer to stack memory */
        StackTaskT16_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        T16,     /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_T16, /* task priority */
        1, /* task max activations */
        0, /* events mask */
        0 | ( 1 << (resource4 & 0xffff)) | ( 1 << (resource5 & 0xffff)) | ( 1 << (resource6 & 0xffff)) | (1 << (resourceApp4 & 0xffff)), /* resources mask */

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_STASK_T106_SEC_data),
            (uint32*)(_ETASK_T106_SEC_data),
            (uint32*)(_STASK_T106_SEC_data_R),
            (uint32*)(_STASK_T106_SEC_bss),
            (uint32*)(_ETASK_T106_SEC_bss)
        }
    },
    /* isr I102 Task  */
    {
        ISR_ENTRY(I102),            /* task entry point */
        &ContextI102, /* pointer to task context */
        StackIsr2TaskI102,    /* pointer to stack memory */
        StackIsr2TaskI102_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I102 + TASKS_COUNT_CORE1 - 1,     /* isr2 task id */
        {      /* task const flags */
            0, /* extended task */      //isr2-task is always a basic task
            1, /* preemptive task */    //isr2-task is always a preemptive task
            1  /* not isr2 task */
        },
        task_static_prio_I102, /* task priority */
        255, /* task max activations */ //isr2-task default value is max value
        0, /* events mask */            //isr2-task is always a basic task
        0 | (1 << (resourceApp2 & 0xffff)), /* resources mask */         //checked in OIL

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I102_SEC_data),
            (uint32*)(_EISR_I102_SEC_data),
            (uint32*)(_SISR_I102_SEC_data_R),
            (uint32*)(_SISR_I102_SEC_bss),
            (uint32*)(_EISR_I102_SEC_bss)
        }
    },
    /* isr I103 Task  */
    {
        ISR_ENTRY(I103),            /* task entry point */
        &ContextI103, /* pointer to task context */
        StackIsr2TaskI103,    /* pointer to stack memory */
        StackIsr2TaskI103_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I103 + TASKS_COUNT_CORE1 - 1,     /* isr2 task id */
        {      /* task const flags */
            0, /* extended task */      //isr2-task is always a basic task
            1, /* preemptive task */    //isr2-task is always a preemptive task
            1  /* not isr2 task */
        },
        task_static_prio_I103, /* task priority */
        255, /* task max activations */ //isr2-task default value is max value
        0, /* events mask */            //isr2-task is always a basic task
        0 | (1 << (resourceApp2 & 0xffff)), /* resources mask */         //checked in OIL

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I103_SEC_data),
            (uint32*)(_EISR_I103_SEC_data),
            (uint32*)(_SISR_I103_SEC_data_R),
            (uint32*)(_SISR_I103_SEC_bss),
            (uint32*)(_EISR_I103_SEC_bss)
        }
    },
    /* isr I105 Task  */
    {
        ISR_ENTRY(I105),            /* task entry point */
        &ContextI105, /* pointer to task context */
        StackIsr2TaskI105,    /* pointer to stack memory */
        StackIsr2TaskI105_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I105 + TASKS_COUNT_CORE1 - 1,     /* isr2 task id */
        {      /* task const flags */
            0, /* extended task */      //isr2-task is always a basic task
            1, /* preemptive task */    //isr2-task is always a preemptive task
            1  /* not isr2 task */
        },
        task_static_prio_I105, /* task priority */
        255, /* task max activations */ //isr2-task default value is max value
        0, /* events mask */            //isr2-task is always a basic task
        0 | (1 << (resourceApp4 & 0xffff)), /* resources mask */         //checked in OIL

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I105_SEC_data),
            (uint32*)(_EISR_I105_SEC_data),
            (uint32*)(_SISR_I105_SEC_data_R),
            (uint32*)(_SISR_I105_SEC_bss),
            (uint32*)(_EISR_I105_SEC_bss)
        }
    },
    /* isr I106 Task  */
    {
        ISR_ENTRY(I106),            /* task entry point */
        &ContextI106, /* pointer to task context */
        StackIsr2TaskI106,    /* pointer to stack memory */
        StackIsr2TaskI106_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */
        I106 + TASKS_COUNT_CORE1 - 1,     /* isr2 task id */
        {      /* task const flags */
            0, /* extended task */      //isr2-task is always a basic task
            1, /* preemptive task */    //isr2-task is always a preemptive task
            1  /* not isr2 task */
        },
        task_static_prio_I106, /* task priority */
        255, /* task max activations */ //isr2-task default value is max value
        0, /* events mask */            //isr2-task is always a basic task
        0 | (1 << (resourceApp4 & 0xffff)), /* resources mask */         //checked in OIL

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SISR_I106_SEC_data),
            (uint32*)(_EISR_I106_SEC_data),
            (uint32*)(_SISR_I106_SEC_data_R),
            (uint32*)(_SISR_I106_SEC_bss),
            (uint32*)(_EISR_I106_SEC_bss)
        }
    },
    /* Task SysTask */
    {            
        TASK_ENTRY(SysTask),            /* task entry point */
        &ContextSysTask_core1,          /* pointer to task context */
        StackTaskSysTask_core1,         /* pointer to stack memory */
        StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE,    /* stack size */
        SysTask_core1,                  /* task id */
        {      /* task const flags */
            0, /* basic task */
            1, /* preemptive task */
            0  /* not isr2 task */
        },
        task_static_prio_sys_core1, /* task priority */
        255, /* task max activations */
        0, /* events mask */
        0 | (1 << (resourceApp2 & 0xffff)) | (1 << (resourceApp4 & 0xffff)),  /* resources mask */
        
        //RomToRamInitTableType RomToRamInitTable
        {
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0,  /* SysTask special case */
            0   /* SysTask special case */
        }
    },
};


TaskAutosarType TaskAutosar_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* Task IdleTask */
    {
        INVALID_OSAPPLICATION,
        0,
        INVALID_SPINLOCK,
        NULL
    },
    /* Task T01 */
    {
        app_lion,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T01 /* MemArea */
    },
    /* Task T02 */
    {
        app_lion,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T02 /* MemArea */
    },
    /* Task T04 */
    {
        app3,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T04 /* MemArea */
    },
    /* Task T05 */
    {
        app3,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T05 /* MemArea */

    },
    /* Task T03 */
    {
        app_lion,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T03 /* MemArea */
    },
    /* Task T06 */
    {
        app3,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T06 /* MemArea */
    },
    /* isrTask I002 */
    {
        app_lion,
        0 | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_I002 /* MemArea */
    },
    /* isrTask I003 */
    {
        app_lion,
        0 | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_I003 /* MemArea */

    },
    /* isrTask I005 */
    {
        app3,
        0 | (1 << app3),
        INVALID_SPINLOCK,
        MemProtArea_I005 /* MemArea */
    },
    /* isrTask I006 */
    {
        app3,
        0 | (1 << app3),
        INVALID_SPINLOCK,
        MemProtArea_I006 /* MemArea */
    },
    /* Task SysTask */
    {
        INVALID_OSAPPLICATION,
        0,
        INVALID_SPINLOCK,
        MemProtArea_SysTask_core0 /* MemArea */
    },
};

TaskAutosarType TaskAutosar_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* Task IdleTask */
    {
        INVALID_OSAPPLICATION,
        0,
        INVALID_SPINLOCK,
        NULL /* MemArea */
    },
    /* Task T11 */
    {
        app2,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T11 /* MemArea */
    },
    /* Task T14 */
    {
        app4,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T14 /* MemArea */
    },
    /* Task T12 */
    {
        app2,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T12 /* MemArea */
    },
    /* Task T13 */
    {
        app2,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T13 /* MemArea */
    },
    /* Task T15 */
    {
        app4,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T15 /* MemArea */
    },
    /* Task T16 */
    {
        app4,
        0 | (1 << app2) | (1 << app4) | (1 << app3) | (1 << app_lion),
        INVALID_SPINLOCK,
        MemProtArea_T16 /* MemArea */
    },
    /* isrTask I102 */
    {
        app2,
        0 | (1 << app2),
        INVALID_SPINLOCK,
        MemProtArea_I102 /* MemArea */
    },
    /* isrTask I103 */
    {
        app2,
        0 | (1 << app2),
        INVALID_SPINLOCK,
        MemProtArea_I103 /* MemArea */
    },
    /* isrTask I105 */
    {
        app4,
        0 | (1 << app4),
        INVALID_SPINLOCK,
        MemProtArea_I105 /* MemArea */
    },
    /* isrTask I106 */
    {
        app4,
        0 | (1 << app4),
        INVALID_SPINLOCK,
        MemProtArea_I106 /* MemArea */
    },
    /* Task SysTask */
    {
        INVALID_OSAPPLICATION,
        0,
        INVALID_SPINLOCK,
        MemProtArea_SysTask_core1 /* MemArea */
    },
};


TaskVarType TaskVar_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* Task IdleTask */
    {
        &TaskConst_core0[0], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_idle_core0,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
    },
    /* Task T01 */
    {
        &TaskConst_core0[1], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T01,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T02 */
    {
        &TaskConst_core0[2], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T02,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T04 */
    {
        &TaskConst_core0[3], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T04,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T05 */
    {
        &TaskConst_core0[4], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T05,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T03 */
    {
        &TaskConst_core0[5], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T03,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T06 */
    {
        &TaskConst_core0[6], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_T06,    /* task priority */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* isrTask I001 */
    {
        &TaskConst_core0[7], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I002,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* isrTask I002 */
    {
        &TaskConst_core0[8], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I003,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app_lion, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* isrTask I005 */
    {
        &TaskConst_core0[9], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I005,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* isrTask I006 */
    {
        &TaskConst_core0[10], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I006,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app3, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task sysTask */
    {
        &TaskConst_core0[11], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_sys_core0,    /* task priority */
        0,    /* task state */
        NULL  /* point to the internal resource */
    },
};

TaskVarType TaskVar_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* Task IdleTask */
    {
        &TaskConst_core1[0], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_idle_core1,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
    },
    /* Task T11 */
    {
        &TaskConst_core1[1], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        2,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T14 */
    {
        &TaskConst_core1[2], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        2,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T12 */
    {
        &TaskConst_core1[3], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        1,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T13 */
    {
        &TaskConst_core1[4], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        3,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T15 */
    {
        &TaskConst_core1[5], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        1,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task T16 */
    {
        &TaskConst_core1[6], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        3,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
        /* isrTask I102 */
    {
        &TaskConst_core1[7], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I102,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* isrTask I103 */
    {
        &TaskConst_core1[8], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I103,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app2, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* isrTask I105 */
    {
        &TaskConst_core1[9], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I105,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* isrTask I106 */
    {
        &TaskConst_core1[10], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_I106,    /* task priority */
        0,    /* task state */
        NULL,  /* point to the internal resource */
        app4, /* the executing application id */
        0, /* nesting trust function count */
    },
    /* Task sysTask */
    {
        &TaskConst_core1[11], /* TaskConst pointer */
        NULL, /* pointer to resources */
        NULL, /* pointer to next task */
        0,    /* the number of activations */
        task_static_prio_sys_core0,    /* task priority */
        0,    /* task state */
        NULL  /* point to the internal resource */
    },
};


/** brief List of Auto Start Tasks in Application Mode AppMode1 */
/** isr2-task cannot Auto Start **/
const TaskType TasksAutoStartAppMode1[TASK_AUTOSTART_APPMODE1_COUNT]  = {
    T01,
    T12,
};

// const TaskType TasksAppModeAppMode2[4]  = {
//    T01,
//    T02,
//    T11,
//    T12,
// };

/** brief AutoStart Array */
const AutoStartType AutoStart[1]  = {
   /* Application Mode AppMode1 */
   {
      TASK_AUTOSTART_APPMODE1_COUNT, /* Total Auto Start Tasks in this Application Mode */
      (TaskRefType)TasksAutoStartAppMode1 /* Pointer to the list of Auto Start Stacks on this Application Mode */
   }

//    /* Application Mode AppMode2 */
//    {
//       4, /* Total Auto Start Tasks in this Application Mode */
//       (TaskRefType)TasksAppModeAppMode2 /* Pointer to the list of Auto Start Stacks on this Application Mode */
//    },
};

TaskType SysTaskID[OsNumberOfCores] = {
    SysTask_core0,
    SysTask_core1,
};



#pragma section
/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*==================[end of file]============================================*/