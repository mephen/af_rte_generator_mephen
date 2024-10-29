#ifndef __INTERRUPT_CTL_H__
#define __INTERRUPT_CTL_H__

#define PMRregID 11
#define PMRselID 2

/* 
    note that, when we say disable_all_ISR, 
    we include all channel-IE-level interrupts except for timer,
    so os-related interrupt like schedule or crosscore will also be disabled

    MaskEIPriority(1): only zero is allowed which is timer(0)
    MaskEIPriority(4): only 0-3  is allowed which are timer(0) and ISR1(1-3)
    MaskEIPriority(16): equal MaskEIPriority(0), 0-15 all allowed, 
                                                 ISR2 is therefore good to go
    
    also note that syscall is IE-level, but not channel-IE-level,
    so will not be disabled even in disable_all_ISR 
*/

/*
    OSTM0/OSTM5 is priority 0
    INTWDTA0/INTWDTA1 is priority 0
    ISR1 is priority 1-3
    INTRLIN30UR0 is is priority 1
    INTRLIN35UR0 is is priority 1
    ServiceCrossCore is priority 4
    SchedulerIRQ is is priority 4
    ISR2 is priority 5-15
    syscall is not ISR and it's prio is lower than ISR
    MPU_FAULT_HANDLER is not ISR and it's prio is higher than ISR (FE-level fault)
*/

#define arch_disable_all_interrupts()               MaskEIPriority(0)
#define arch_disable_all_ISR_interrupts()           MaskEIPriority(1)
#define arch_disable_only_ISR2_interrupts()         MaskEIPriority(5)
#define arch_enable_all_interrupts()                MaskEIPriority(16)

/* current version not using these two */
#define arch_disable_clock()                        DisableClockPriority()
#define arch_enable_clock()                         EnableClockPriority()

/* legacy code*/
#define arch_disable_low_priority_interrupts()      MaskEIPriority(4)
#define arch_irq_ack()								__EI()

/******************************************************************************
** Function:    MaskEIPriority
** Description: This function is used to mask the specified interrupt priorities.
**              These bits in the PMR register mask an interrupt request with a
**              priority level that corresponds to the relevant bit position.
**              Specify the masks by setting the bits to 1 in order from the
**              lowest-priority bit.
**              For example, F0H can be set, but 10H or 0FH cannot.
** Parameter:   priority: The same or lower priority interrupts are masked.
**                        Can use 16 to unmask all interrupts.
** Return:      None
******************************************************************************/
static inline void MaskEIPriority(unsigned char priority)
{
    unsigned long value = 0xffff;

    value = value << priority;
    value &= 0xffff;
    __ldsr_rh(PMRregID, PMRselID, value);
}

static inline void DisableClockPriority(void)
{
    unsigned long value = 0xffff;

    __ldsr_rh(PMRregID, PMRselID, value);
}

static inline void EnableClockPriority(void)
{
    unsigned long value = 0;

    value = __stsr_rh(PMRregID, PMRselID);
    __ldsr_rh(PMRregID, PMRselID, value & 0xfffe);
}

#endif //__INTERRUPT_CTL_H__