#include "iodefine.h"
#include "ISRInit.h"
#include "core.h"
#include "os_Cfg.h"
#include "isr_Cfg.h"
#include "system.h"


/* the base address is for channel id from 31 to 255 */
#define ISR_CONTROL_BASEADDRESS 0xFFFFB040
#define ISR_BINDING_BASEADDRESS 0xFFFFB880

/* scheduler channel and cross core interrupt channel */
#define SCHEDULER_CHANNEL_CORE0 37
#define SCHEDULER_CHANNEL_CORE1 38
/******************************************************************************
** Function:    ISRInit
** Description: This function is used to initialize the interrupt flags
**              of the user defined interrupts.
**              User should write the initial code of his interrupt
**              in this function.
**              The step of configuring a interrupt is:
**                  1. Disables interrupt processing
**                  2. Clear interrupt request flag
**                  3. Table reference for interrupt vector
**                  4. Set interrupt priority(0 as the highest and 15 as the lowest)
**                     Only timer use priority 0 (highest)
**                     Category1 ISR should use 1 ~ 3
**                     Category2 ISR should use priority 4 ~ 15
**                  5. Enables interrupt processing
** Parameter:   None
** Return:      None
** - - - - - - - - - - 
** Channels that is already in-use list below
**  (OS) Channel      0~3: reserve for Internal processor interrupt, ISR(1)
**       Channel      5~7: Reserved by hardware(f1h)
**  (OS) Channel    33~36: reserve for RLIN30(uart), ISR(1)
**  (OS) Channel    37~38: reserve for Scheduler, ISR(1)
**  (OS) Channel    40~42: reserve for WDTA 75% interrupt (WDTA0/WDTA1/WDTA2), ISR(0)
**  (OS) Channel       84: reserve for OSTM0 interrupt, ISR(0)
**       Channel  104~109: Reserved by hardware(f1h)
**       Channel  136~141: Reserved by hardware(f1h)
**       Channel      172: Reserved by hardware(f1h)
**       Channel      216: Reserved by hardware(f1h)
**  (OS) Channel  236~239: reserve for RLIN35(uart), ISR(1)
**       Channel  290~297: Reserved by hardware(f1h)
**  (OS) Channel      314: reserve for OSTM5 interrupt, ISR(0)
**       Channel  324~325: Reserved by hardware(f1h)
**       Channel  335~350: Reserved by hardware(f1h)
** other channel (ranging from 0~334 except listed above), is available
** - - - - - - - - - -
** Channel that is registered for test
**(TEST) channel    43~45,93: test for app_lion
**(TEST) channel 128~130,186: test for app2
**(TEST) channel       94,95: test for app3
**(TEST) channel     187,188: test for app4
******************************************************************************/
void ISRInit(void)
{   
    uint32 i, channel, priority, core;
    if(GetPhyCoreID()==OS_CORE_ID_0)
    {
        /* Init core 0 user ISR */
        for(i=0, core = OS_CORE_ID_0 ; i<SystemObjects[core]->isrAllCount;i++)
        {
            channel = SystemObjects[core]->IsrConst[i].ISRchannel;
            priority = SystemObjects[core]->IsrConst[i].ISRprio;
            disableISR(channel);
            clearpendingISR(channel);
            setTableReference(channel);
            setInterruptPriority(channel,priority);
            setInterruptCore(channel,core);
            enableISR(channel);
        }

        /* Init core 1 user ISR */
        for(i=0, core = OS_CORE_ID_1; i<SystemObjects[core]->isrAllCount;i++)
        {
            channel = SystemObjects[core]->IsrConst[i].ISRchannel;
            priority = SystemObjects[core]->IsrConst[i].ISRprio;
            disableISR(channel);
            clearpendingISR(channel);
            setTableReference(channel);
            setInterruptPriority(channel,priority);
            setInterruptCore(channel,core);
            enableISR(channel);
        }
    }

    // /***** test for app_lion *****/
    // /* INTP3 */     //ICP3, INT43 in boot.asm, test for app_lion
    // MKP3 = 1U;    // Disables interrupt processing
    // RFP3 = 0U;    // No interrupt request is made
    // TBP3 = 1U;    // Table reference
    // ICP3 &= 0xf3;   /* Set interrupt priority 3 */
    // //IBDP3 &= ~0x2; // Bind to pe1
    // //IBDP3 |= ~0x1; // Bind to pe1
    // MKP3 = 0U;      //Enables interrupt processing

    // i = (*(volatile unsigned int *)IBDP3);

    // /* INTP4 */     //ICP4, INT44 in boot.asm, test for app_lion
    // MKP4 = 1U;
    // RFP4 = 0U;
    // TBP4 = 1U;
    // ICP4 &= 0xff;   /* Set interrupt priority 15 */
    // // IBDP4 &= ~0x2; // Bind to pe1
    // // IBDP4 |= ~0x1; // Bind to pe1
    // MKP4 = 0U;      //Enables interrupt processing

    // /* INTP5 */     //ICP5, INT45 in boot.asm, test for app_lion
    // MKP5 = 1U;
    // RFP5 = 0U;
    // TBP5 = 1U;
    // ICP5 &= 0xff;   /* Set interrupt priority 15 */
    // //IBDP5 &= ~0x2; // Bind to pe1
    // //IBDP5 |= ~0x1; // Bind to pe1
    // MKP5 = 0U;      //Enables interrupt processing

    // /* INTPWGA1 */     //ICPWGA1, INT93 in boot.asm, test for app_lion
    // MKPWGA1 = 1U;
    // RFPWGA1 = 0U;
    // TBPWGA1 = 1U;
    // ICPWGA1 &= 0xf3;   /* Set interrupt priority 3 */
    // //IBDPWGA1 &= ~0x2; // Bind to pe1
    // //IBDPWGA1 |= ~0x1; // Bind to pe1
    // MKPWGA1 = 0U;      //Enables interrupt processing

    // /***** test for app2 *****/
    // /* INTP6 */     //ICP6, IN128 in boot.asm, test for app2
    // MKP6 = 1U;
    // RFP6 = 0U;
    // TBP6 = 1U;
    // ICP6 &= 0xf3;   /* Set interrupt priority 3 */
    // //IBDP6 &= ~0x1; // Bind to pe2
    // //IBDP6 |= ~0x2; // Bind to pe2
    // MKP6 = 0U;      //Enables interrupt processing



    // /* INTP7 */     //ICP7, INT129 in boot.asm, test for app2
    // MKP7 = 1U;
    // RFP7 = 0U;
    // TBP7 = 1U;
    // ICP7 &= 0xff;   /* Set interrupt priority 15 */
    // // IBDP7 ^= 0x10003; // Bind to pe2


    // // IBDP7 &= ~0x1;
    // //IBDP7 |= ~0x2; // Bind to pe2
    // MKP7 = 0U;      //Enables interrupt processing

    // /* INTP8 */     //ICP8, INT130 in boot.asm, test for app2
    // MKP8 = 1U;
    // RFP8 = 0U;
    // TBP8 = 1U;
    // ICP8 &= 0xff;   /* Set interrupt priority 15 */
    // // IBDP8 ^= 0x10003;
    

    // // (((volatile __bitf_T *)IBDP8)->bit00) = 0U;
    // // (((volatile __bitf_T *)IBDP8)->bit01) = 1U;
    // // (((volatile __bitf_T *)IBDP8)->bit02) = 0U;
    
    // //((((volatile __bitf_T *)IBDP8)+2)->bit00) = 1U;
    // //((((volatile __bitf_T *)IBDP8)+2)->bit01) = 0U;
    
    // // i = (*(volatile unsigned int *)IBDP8);

    // // IBDP8 &= ~0x1; // Bind to pe2
    // // IBDP8 |= ~0x2; // Bind to pe2
    // MKP8 = 0U;      //Enables interrupt processing

    // /* ICPWGA27 */     //INTPWGA27, INT186 in boot.asm, test for app2
    // MKPWGA27 = 1U;
    // RFPWGA27 = 0U;
    // TBPWGA27 = 1U;
    // ICPWGA27 &= 0xf3;   /* Set interrupt priority 3 */
    // //IBDPWGA27 &= ~0x1; // Bind to pe2
    // //IBDWGA27 |= ~0x2; // Bind to pe2
    // MKPWGA27 = 0U;      //Enables interrupt processing

    // /***** test for app3 *****/


    // /* INTPWGA2 */     //ICPWGA2, INT94 in boot.asm, test for app3
    // MKPWGA2 = 1U;
    // RFPWGA2 = 0U;
    // TBPWGA2 = 1U;
    // ICPWGA2 &= 0xff;   /* Set interrupt priority 15 */
    // //IBDPWGA2 &= ~0x2; // Bind to pe1
    // //IBDPWGA2 |= ~0x1; // Bind to pe1
    // MKPWGA2 = 0U;      //Enables interrupt processing

    // /* INTPWGA3 */     //ICPWGA3, INT95 in boot.asm, test for app3
    // MKPWGA3 = 1U;
    // RFPWGA3 = 0U;
    // TBPWGA3 = 1U;
    // ICPWGA3 &= 0xff;   /* Set interrupt priority 15 */
    // //IBDPWGA3 &= ~0x2; // Bind to pe1
    // //IBDPWGA3 |= ~0x1; // Bind to pe1
    // MKPWGA3 = 0U;      //Enables interrupt processing

    // /***** test for app4 *****/

    // /* ICPWGA28 */     //INTPWGA28, INT187 in boot.asm, test for app4
    // MKPWGA28 = 1U;
    // RFPWGA28 = 0U;
    // TBPWGA28 = 1U;
    // ICPWGA28 &= 0xff;   /* Set interrupt priority 15 */
    // //IBDPWGA28 &= ~0x1; // Bind to pe2 ^= 0x10003
    // //IBDPWGA28 |= ~0x2; // Bind to pe2
    // MKPWGA28 = 0U;      //Enables interrupt processing

    // /* ICPWGA29 */     //INTPWGA29, INT188 in boot.asm, test for app4
    // MKPWGA29 = 1U;
    // RFPWGA29 = 0U;
    // TBPWGA29 = 1U;
    // ICPWGA29 &= 0xff;   /* Set interrupt priority 15 */
    // //IBDPWGA29 &= ~0x1; // Bind to pe2
    // //IBDPWGA29 |= ~0x2; // Bind to pe2
    // MKPWGA29 = 0U;      //Enables interrupt processing

    /***** legact code below *****/

    /* INTP10 */    //INT46 in boot.asm
    // MKP10 = 1U;
    // RFP10 = 0U;
    // TBP10 = 1U;
    // ICP10 &= 0xff;  /* Set interrupt priority 15 */
    // MKP10 = 0U;     //Enables interrupt processing

    // /* INTP11 */    //INT47 in boot.asm
    // MKP11 = 1U;
    // RFP11 = 0U;
    // TBP11 = 1U;
    // ICP11 &= 0xff;
    // MKP11 = 0U;     //Enables interrupt processing
}

/******************************************************************************
** Function:    CrossCoreISRInit
** Description: This function is called before ISRInit
**              This function is used to initialize the interrupt flags
**              of the user defined interrupts.
**              User should write the initial code of his interrupt
**              in this function.
**              The step of configuring a interrupt is:
**                  1. Disables interrupt processing
**                  2. Clear interrupt request flag
**                  3. Table reference for interrupt vector
**                  4. Set interrupt priority 1
**                  5. Enables interrupt processing
** Parameter:   None
** Return:      None
******************************************************************************/
void CrossCoreISRInit(void){

    /* INTIPIR0 */   //ICIPIR0 in boot.asm for _ServiceCrossCore
    MKIPIR0 = 1U;
    RFIPIR0 = 0U;    //Setting the RFxxx bit to 1 generates an EI level maskable interrupt
    TBIPIR0 = 1U;    //select the way to determine the interrupt vector. 1: Table reference
    ICIPIR0 &= 0xf4; /* Set interrupt priority(4) */ 
    // MKIPIR0 = 0U;    //Enables interrupt processing

    // legact code below

    /* INTIPIR1 */  //ICIPIR1 (Internal processor interrupt 1) in boot.asm (but not in use now)
    // MKIPIR1 = 1U;
    // RFIPIR1 = 0U;
    // TBIPIR1 = 1U;
    // ICIPIR1 &= 0xf0; /* Set interrupt priority(0) */ 
    // MKIPIR1 = 0U;    //Enables interrupt processing
}


#define InitSchedulerIRQ_pe(name)                                           \
    do {                                                                    \
        ICP ## name |= 0x80;    /* Disables interrupt processing */         \
        ICP ## name &= ~0x1000; /* Clear interrupt request flag */          \
        ICP ## name |= 0x40;    /* Table reference for interrupt vector */  \
        ICP ## name &= 0xf4;    /* Set interrupt priority(4) */             \
        \
    } while (0)

/******************************************************************************
** Function:    InitSchedulerIRQ
** Description: This function is used to initialize the interrupt flags
**              of the scheduler interrupt.
**              Users should not modify this function unless you know what you
**              are doing.
** Parameter:   None
** Return:      None
******************************************************************************/
void InitSchedulerIRQ(void)
{
    CoreIdType CoreID = CoreIdPhyToLogArray[GetPhyCoreID()];
    if (CoreID == OS_CORE_ID_0)
    {
        InitSchedulerIRQ_pe(0);
    }
    else if (CoreID == OS_CORE_ID_1)
    {
        InitSchedulerIRQ_pe(1);
    }
}


/******************************************************************************
** Function:    diableISR
** Description: This function is used to disable the interrupt <channel> 
**              
** Parameter:   channel
** Return:      None
******************************************************************************/
void disableISR(uint32 channel)
{
    uint32 address = ISR_CONTROL_BASEADDRESS + ((channel-32)*2);
    (((volatile __bitf_T *)address)->bit07) = 1U;
}

/******************************************************************************
** Function:    enableISR
** Description: This function is used to enable the interrupt <channel> 
**              
** Parameter:   channel
** Return:      None
******************************************************************************/
void enableISR(uint32 channel)
{
    uint32 address = ISR_CONTROL_BASEADDRESS + ((channel-32)*2);
    (((volatile __bitf_T *)address)->bit07) = 0U;
}


/******************************************************************************
** Function:    clearpendingISR
** Description: This function is used to clear the pending interrupt <channel> 
**              
** Parameter:   channel
** Return:      None
******************************************************************************/
void clearpendingISR(uint32 channel)
{
    uint32 address = ISR_CONTROL_BASEADDRESS + ((channel-32)*2) + 1;
    (((volatile __bitf_T *)address)->bit04) = 0U;
}

/******************************************************************************
** Function:    triggerISR
** Description: This function is used to trigger the interrupt <channel> 
**              
** Parameter:   channel
** Return:      None
******************************************************************************/
void triggerISR(uint32 channel)
{
    uint32 address = ISR_CONTROL_BASEADDRESS + ((channel-32)*2) + 1;
    (((volatile __bitf_T *)address)->bit04) = 1U;

}

/******************************************************************************
** Function:    setInterruptPriority
** Description: This function is used to set the interrupt <channel>'s priority
**              to <priority>
** Parameter:   channel , priority
** Return:      None
******************************************************************************/
void setInterruptPriority(uint32 channel,uint32 priority)
{
    uint32 address = ISR_CONTROL_BASEADDRESS + ((channel-32)*2);
    (*(volatile unsigned short *)address) &= (0xf0 + priority);
}

/******************************************************************************
** Function:    setInterruptCore
** Description: This function is used to bind the interrupt <channel>
**              to core
** Parameter:   channel , core
** Return:      None
******************************************************************************/
void setInterruptCore(uint32 channel, uint32 core)
{
    uint32 address = ISR_BINDING_BASEADDRESS + ((channel-32)*4);
    if(core == 0)
    {
        /* default core is core 0 */
    }
    else if(core == 1)
    {
        (*(volatile unsigned int *)address) ^= 0x10003; // Bind to pe2
    }
}

/******************************************************************************
** Function:    setTableReference
** Description: This function is used to set the interrupt <channel> to
**              table reference
** Parameter:   channel 
** Return:      None
******************************************************************************/
void setTableReference(uint32 channel)
{
    uint32 address = ISR_CONTROL_BASEADDRESS + ((channel-32)*2);
    (((volatile __bitf_T *)address)->bit06) = 1U;
}


/******************************************************************************
** Function:    checkISRdisabled
** Description: This function is used to cheack that the ISR is disabled
**              
** Parameter:   channel
** Return:      True: ISR is disabled
                False: ISR is enabled
******************************************************************************/
boolean checkISRdisabled(uint32 channel)
{
    uint32 address = ISR_CONTROL_BASEADDRESS + ((channel-32)*2);
    uint32 MKvalue = (uint32)(((volatile __bitf_T *)address)->bit07);
    boolean returnValue = FALSE;
    if(MKvalue==1)
    {
        returnValue = TRUE;
    }
    return returnValue;
}

/******************************************************************************
** Function:    checkISRenabled
** Description: This function is used to cheack that the ISR is enabled
**              
** Parameter:   channel
** Return:      True: ISR is enabled
                False: ISR is disabled
******************************************************************************/
boolean checkISRenabled(uint32 channel)
{
    uint32 address = ISR_CONTROL_BASEADDRESS + ((channel-32)*2);
    uint32 MKvalue = (uint32)(((volatile __bitf_T *)address)->bit07);
    boolean returnValue = FALSE;
    if(MKvalue==0)
    {
        returnValue = TRUE;
    }
    return returnValue;
}


#pragma section 
void disableSchedulerIRQ(void)
{
    kernelDisableSchedulerCounter ++;
    if(_CoreID == OS_CORE_ID_0)
    {
        disableISR(SCHEDULER_CHANNEL_CORE0);
    }
    else if(_CoreID == OS_CORE_ID_1)
    {
        disableISR(SCHEDULER_CHANNEL_CORE1);    
    }
}

void enableSchedulerIRQ(void)
{
    kernelDisableSchedulerCounter--;
    if(kernelDisableSchedulerCounter==0)
    {
        if(_CoreID == OS_CORE_ID_0)
        {
            enableISR(SCHEDULER_CHANNEL_CORE0);
        }
        else if(_CoreID == OS_CORE_ID_1)
        {
            enableISR(SCHEDULER_CHANNEL_CORE1);    
        }
    }

}

void disableCrossCoreISR(void)
{
    MKIPIR0 = 1U; 
    kernelDisableCrossCoreCounter++;
}
void enableCrossCoreISR(void)
{
    kernelDisableCrossCoreCounter--;
    if(kernelDisableCrossCoreCounter==0)
    {
        MKIPIR0 = 0U; 
    }
}
