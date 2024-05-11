#include "iodefine.h"
#include "timer.h"
#include "counter.h"
#include "memprot.h"
#include "scheduler.h"
#include "system.h"
#include "softwaretimer.h"
#include "os_Cfg.h"
#include "timingprot.h"
#include "context.h"
#include "ISRInit.h"

/******************************************************************************
** Function:    OSTM_init
** Description: This function set OSTM trigger interrupt per millisecond.
**              Use table reference method for interrupt vector.
** Parameter:   None
** Return:      None
******************************************************************************/
#define TIMER_CHANNEL_CORE0 84
#define TIMER_CHANNEL_CORE1 314

void OSTM0_init_pe1(void)
{
    // Set interrupt flags
    MKOSTM0 = 1U;    // Disables interrupt processing
    RFOSTM0 = 0U;    // Clear interrupt request flag
    TBOSTM0 = 1U;    // Table reference for interrupt vector
    ICOSTM0 &= 0xf0; // Set interrupt priority(the highest)
    MKOSTM0 = 0U;    // Enables interrupt processing

    OSTM0.CMP = 0xea60; // 60000 / 60MHz = 1ms
    OSTM0.CTL = 0x01;   //interval timer mode, interrupt when counting start
    OSTM0.TS = 0x01;    //start
}

#pragma section USER_SHARED_SEC

char kernel_str_arr1[32];
char kernel_str_arr2[32];
#pragma section

#pragma interrupt OSTM0_interrupt(enable = manual, channel = 84, callt = false, fpu = false)
void OSTM0_interrupt(void)
{
    DisableMPU();
    // if( systemFlag & AFTER_STARTOS )
    //     SwitchStackFromUtoK();
    systemFlag |= (IN_TIMER_INTERRUPT) ;
    
    // CounterTick();
    TimerTick();
    TimingProtection();
    
    systemFlag &= ~(IN_TIMER_INTERRUPT) ;

    // if( systemFlag & AFTER_STARTOS )
    //     SwitchStackFromKtoU();
    EnableMPU();
}



/******************************************************************************
** Function:    OSTM_init
** Description: This function set OSTM trigger interrupt per millisecond.
**              Use table reference method for interrupt vector.
** Parameter:   None
** Return:      None
******************************************************************************/

void OSTM5_init_pe2(void)
{
    // Set interrupt flags
    MKOSTM5 = 1U;    // Disables interrupt processing
    RFOSTM5 = 0U;    // Clear interrupt request flag
    TBOSTM5 = 1U;    // Table reference for interrupt vector
    ICOSTM5 &= 0xf0; // Set interrupt priority(the highest)
    MKOSTM5 = 0U;    // Enables interrupt processing

    OSTM5.CMP = 0xea60; // 60000 / 60MHz = 1ms
    OSTM5.CTL = 0x01;   //interval timer mode, interrupt when counting start
    OSTM5.TS = 0x01;    //start
}

#pragma interrupt OSTM5_interrupt(enable = manual, channel = 314, callt = false, fpu = false)
void OSTM5_interrupt(void)
{
    DisableMPU();
    systemFlag |= (IN_TIMER_INTERRUPT) ;

    // CounterTick();
    TimerTick();
    TimingProtection();

    systemFlag &= ~(IN_TIMER_INTERRUPT) ;
    EnableMPU();
}


void disableTimer(void)
{
    uint16 channel;
    kernelDisableTimerCounter++;
    if(_CoreID == OS_CORE_ID_0)
    {
        channel = TIMER_CHANNEL_CORE0;
    }
    else if(_CoreID == OS_CORE_ID_1)
    {
        channel = TIMER_CHANNEL_CORE1;
    }
    disableISR(channel);
}

void enableTimer(void)
{
    uint16 channel;
    if(_CoreID == OS_CORE_ID_0)
    {
        channel = TIMER_CHANNEL_CORE0;
    }
    else if(_CoreID == OS_CORE_ID_1)
    {
        channel = TIMER_CHANNEL_CORE1;
    }
    kernelDisableTimerCounter--;
    if(kernelDisableTimerCounter==0)
    {
        enableISR(channel);
    }
}