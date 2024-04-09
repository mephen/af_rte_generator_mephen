#include "board.h"
#include "dr7f701527.dvf.h"
#include "timer.h"
#include "GPIO.h"
#include "memprot.h"
#include "r_uart.h"
#include "r_clkc.h"
#include "write_protect.h"

#pragma interrupt INTWDTA0(enable = manual, channel = 40, callt = false, fpu = false)
void INTWDTA0(void)
{
    WDTA0WDTE = 0xAC; // Restart the WDTA counter
}

#pragma interrupt INTWDTA1(enable = manual, channel = 41, callt = false, fpu = false)
void INTWDTA1(void)
{
    WDTA1WDTE = 0xAC; // Restart the WDTA counter
}

void WDTAInit_pe1(void)
{
    // PE1 use WDTA0, Set interrupt flags
    MKWDTA0 = 1U;    // Disables interrupt processing
    RFWDTA0 = 0U;    // Clear interrupt request flag
    TBWDTA0 = 1U;    // Table reference for interrupt vector
    ICWDTA0 &= 0xf0; // Set interrupt priority(the highest)
    MKWDTA0 = 0U;    // Enables interrupt processing

    WDTA0MD = 0x0b; // NMI error mode, enable 75% EI. The overflow interval time is set by 6 to 4 bits, check hardware spec.
                    // 512 / 240kHz * 128 = 0.2731 sec
    WDTA0WDTE = 0xAC;
}

void WDTAInit_pe2(void)
{
    // PE2 use WDTA1, set interrupt flags
    MKWDTA1 = 1U;    // Disables interrupt processing
    RFWDTA1 = 0U;    // Clear interrupt request flag
    TBWDTA1 = 1U;    // Table reference for interrupt vector
    ICWDTA1 &= 0xf0; // Set interrupt priority(the highest)
    MKWDTA1 = 0U;    // Enables interrupt processing

    WDTA1MD = 0x0b; // NMI error mode, enable 75% EI. The overflow interval time is set by 6 to 4 bits, check hardware spec.
                    // 512 / 240kHz * 128 = 0.2731 sec
    WDTA1WDTE = 0xAC;
}

void _BoardInit_pe1(void)
{
    WDTAInit_pe1();
    OSTM0_init_pe1();
    R_CLKC_PllInit(); /* CPUCLK = 120MHz, PPLLCLK = 80MHz */
	R_CLKC_SetRlinClockDomain(R_CLKC_RLIN_PPLLCLK2); /* RLIN Clock = PPLLCLK/2 */
    R_UART_Init();
}

void preBoardInit_pe2(void)
{
    //the 17-to-16 bits are for GPID[1:0], 01:When CPU2 is selected for a binding destination by using PEID
    //the 2-to-0 bits are for PEID[2:0], 010: An interrupt is bound to CPU2 
    // ^3 -> change '01' to '10'
    IBDWDTA1 ^= 0x10003;    // Bind to pe2  // _INTWDTA0 watch dog timer
    IBDOSTM5 ^= 0x10003;    // Bind to pe2  //timer interrupt
    IBDP1    ^= 0x10003;    // Bind to pe2  //scheduler for core1(PE2)
}

void _BoardInit_pe2(void)
{
    WDTAInit_pe2();
    OSTM5_init_pe2();
    // R_CLKC_PllInit(); /* CPUCLK = 120MHz, PPLLCLK = 80MHz */
	// R_CLKC_SetRlinClockDomain(R_CLKC_RLIN_PPLLCLK2); /* RLIN Clock = PPLLCLK/2 */
    // R_UART_Init();
}

/******************************************************************************
** Function:    SWReset
** Description: This function is used to do the software reset.
** Parameter:   None
** Return:      None
******************************************************************************/
void SWReset(void)
{
    protected_write(PROTCMD0, PROTS0, SWRESA, 0x0001u);
}