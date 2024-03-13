/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_clkc.c                                                        */
/* Version:  V1.00                                                           */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2016 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* In case of any question please do not hesitate to contact:                */
/*                                                                           */
/*        ABG Software Tool Support                                          */
/*                                                                           */
/*        Renesas Electronics Europe GmbH                                    */
/*        Arcadiastrasse 10                                                  */
/*        D-40472 Duesseldorf, Germany                                       */
/*                                                                           */
/*        e-mail: software_support-eu@lm.renesas.com                         */
/*        FAX:   +49 - (0)211 / 65 03 - 11 31                                */
/*                                                                           */
/*===========================================================================*/
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/
/* History:                                                                  */
/*              V1.00: Initial version                                       */
/*                                                                           */
/*===========================================================================*/
/*                                                                           */
/* Source code for the clock controller configurations.                      */
/*                                                                           */
/*===========================================================================*/


/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include "r_device.h"
#include "r_clkc.h"                 
#include "dr7f701527.dvf.h"

/*===========================================================================*/
/* Functions */
/*===========================================================================*/
/*****************************************************************************
** Function:    R_CLKC_PllInit
** Description: This function generates 120MHz CPU CLK and 80MHz PeripheralPLL CLK.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_PllInit(void)
{ 
  /* Prepare 16MHz MainOsc */
  MOSCC=0x05;                                     /* Set MainOSC gain (8MHz < MOSC frequency =< 16MHz) */
  MOSCST=0xFFFF;                                  /* Set MainOSC stabilization time to max (8,19 ms) */
  protected_write(PROTCMD0,PROTS0,MOSCE,0x01u);   /* Trigger Enable (protected write) */
  while ((MOSCS&0x04u) != 0x04u);                 /* Wait for active MainOSC */

  /* Prepare PLL0*/
  if((PLL0S&0x04u) != 0x04u)
  {
   PLL0C=0x0000021D;                              /* 16 MHz MainOSC -> 120MHz PLL0 */
   protected_write(PROTCMD1,PROTS1,PLL0E,0x01u);  /* Enable PLL */
   while((PLL0S&0x04u) != 0x04u);                 /* Wait for active PLL */
  }
  /* Prepare PLL1*/
  if((PLL1S&0x04u) != 0x04u)
  {
   PLL1C=0x00000a27;                              /* 16 MHz MainOSC -> 80MHz PLL1 */
   protected_write(PROTCMD1,PROTS1,PLL1E,0x01u);  /* Enable PLL */
   while((PLL1S&0x04u) != 0x04u);                 /* Wait for active PLL */
  }
  
  /* CPU Clock divider = PLL0/1 */
  protected_write(PROTCMD1,PROTS1,CKSC_CPUCLKD_CTL,0x01u);
  while(CKSC_CPUCLKD_ACT!=0x01u);

  /* PLL0 -> CPU Clock */ 
  protected_write(PROTCMD1,PROTS1,CKSC_CPUCLKS_CTL,0x03u);
  while(CKSC_CPUCLKS_ACT!=0x03u);
  
  /* Set Peripheral CLK2 to 40 MHZ (PPLL2) */
  protected_write(PROTCMD1,PROTS1,CKSC_IPERI2S_CTL,0x02u);
  while(CKSC_IPERI2S_ACT!=0x02u);
}

/*****************************************************************************
** Function:    R_CLKC_SetRscanClockDomain
** Description: Select the RS-CAN Module Clock and the Communication Clock.
** Parameter:   RscanModuleClockDomain - Clock for operation of the CAN module itself.
**              RscanComClockDomain - Clock used for the communication speed setting.
** Return:      None
******************************************************************************/
void R_CLKC_SetRscanClockDomain(uint32_t RscanModuleClockDomain, uint32_t RscanComClockDomain)
{
  /* Select RS-CAN Module Clock */
  protected_write(PROTCMD1, PROTS1, CKSC_ICANS_CTL, RscanModuleClockDomain);
  while (CKSC_ICANS_ACT !=RscanModuleClockDomain);

  /* Select RS-CAN Communication Clock */
  protected_write(PROTCMD1, PROTS1, CKSC_ICANOSCD_CTL, RscanComClockDomain);
  while (CKSC_ICANOSCD_CTL != RscanComClockDomain);
}

/*****************************************************************************
** Function:    R_CLKC_SetRlinClockDomain
** Description: Select the RLIN Clock domain.
** Parameter:   RlinClockDomain - Supply Clock of RLIN.
** Return:      None
******************************************************************************/
void R_CLKC_SetRlinClockDomain(uint32_t RlinClockDomain)
{
  protected_write(PROTCMD1, PROTS1, CKSC_ILINS_CTL, RlinClockDomain);
  while(CKSC_ILINS_ACT != RlinClockDomain);
}

/*****************************************************************************
** Function:    R_CLKC_SetAdca0ClockDomain
** Description: Select the ADCA0 Clock domain.
** Parameter:   Adca0ClockDomain - Supply Clock of ADCA0.
** Return:      None
******************************************************************************/
void R_CLKC_SetAdca0ClockDomain(uint32_t Adca0ClockDomain)
{
  protected_write(PROTCMD0, PROTS0, CKSC_AADCAS_CTL, Adca0ClockDomain);
  while(CKSC_AADCAS_ACT != Adca0ClockDomain);
}

/*****************************************************************************
** Function:    R_CLKC_SetTaujClockDomain
** Description: Select the TAUJ Clock domain.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_SetTaujClockDomain(uint32_t TaujClockDomain)
{
  protected_write(PROTCMD0, PROTS0, CKSC_ATAUJS_CTL, TaujClockDomain);
  while(CKSC_ATAUJS_CTL != TaujClockDomain);
}  

/*****************************************************************************
** Function:    R_CLKC_SetAdca0StopMask
** Description: Sets the stop-mask bit for the ADCA0 clock supply so it is not  
**              stopped in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_SetAdca0StopMask(void)
{
    CKSC_AADCAD_STPM = R_CLKC_STOPMASK_SET;
}

/*****************************************************************************
** Function:    R_CLKC_ResetAdca0StopMask
** Description: Resets the stop-mask bit for the ADCA0 clock supply so it is  
**              stopped in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_ResetAdca0StopMask(void)
{
    CKSC_AADCAD_STPM = R_CLKC_STOPMASK_RESET;
}

/*****************************************************************************
** Function:    R_CLKC_SetTaujStopMask
** Description: Sets the stop-mask bit for the TAUJ clock supply so it is not  
**              stopped in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_SetTaujStopMask(void)
{
    CKSC_ATAUJD_STPM = R_CLKC_STOPMASK_SET;
}

/*****************************************************************************
** Function:    R_CLKC_ResetTaujStopMask
** Description: Resets the stop-mask bit for the TAUJ clock supply so it is  
**              stopped in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_ResetTaujStopMask(void)
{
    CKSC_ATAUJD_STPM = R_CLKC_STOPMASK_RESET;
}
