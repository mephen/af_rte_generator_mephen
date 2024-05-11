/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_ostm.c                                                        */
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
/* Source code for the OperatingSystemTimer Functions                        */
/* The OSTM0 counts with CPU Clock / 2                                       */
/*                                                                           */
/*===========================================================================*/

/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include "r_device.h"
#include "r_ostm.h"

/*===========================================================================*/
/* Functions */
/*===========================================================================*/

/*****************************************************************************
** Function:    R_OSTM0_Init
** Description: Initializes the OSTM0.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_OSTM0_Init(void)
{
  OSTM0EMU = 0x00u;   /* Counter is stopped when Debugger takes control */
  OSTM0CTL = 0x00u;   /* IntervalTimer Mode / Interrupt on CounterStart disabled */
}

/*****************************************************************************
** Function:    R_OSTM0_Start
** Description: Starts the OSTM0 counter.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_OSTM0_Start(void)
{
 /* StartTrigger */
  OSTM0TS = 0x01u;    
}

/*****************************************************************************
** Function:    R_OSTM0_Stop
** Description: Stops the OSTM0 counter.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_OSTM0_Stop(void)
{
  /* StopTrigger */
  OSTM0TT = 0x01u;    
}

/*****************************************************************************
** Function:    R_OSTM0_SetCompareValue
** Description: Updates the OSTM0 compare register.
** Parameter:   cmp_value - Compare value
** Return:      None
******************************************************************************/
void R_OSTM0_SetCompareValue(uint32_t cmp_value)
{
  OSTM0CMP = cmp_value;
}

/*****************************************************************************
** Function:    R_OSTM0_GetCnt
** Description: Returns current down count value.
** Parameter:   None
** Return:      OSTM0CNT - OSTM0 Count Register
******************************************************************************/
uint32_t R_OSTM0_GetCnt(void)
{   
  return OSTM0CNT;
}

/*****************************************************************************
** Function:    R_OSTM1_Init
** Description: Initializes the OSTM1.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_OSTM1_Init(void)
{
  OSTM1EMU = 0x00u;   /* Counter is stopped when Debugger takes control */
  OSTM1CTL = 0x02u;   /* Free-run Compare Mode / Interrupt on CounterStart disabled */
}

/*****************************************************************************
** Function:    R_OSTM1_Start
** Description: Starts the OSTM1 counter.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_OSTM1_Start(void)
{
 /* StartTrigger */
  OSTM1TS = 0x01u;    
}

/*****************************************************************************
** Function:    R_OSTM1_Stop
** Description: Stops the OSTM1 counter.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_OSTM1_Stop(void)
{
  /* StopTrigger */
  OSTM1TT = 0x01u;    
}

/*****************************************************************************
** Function:    R_OSTM1_SetCompareValue
** Description: Updates the OSTM1 compare register.
** Parameter:   cmp_value - Compare value
** Return:      None
******************************************************************************/
void R_OSTM1_SetCompareValue(uint32_t cmp_value)
{
  OSTM1CMP = cmp_value;
}

/*****************************************************************************
** Function:    R_OSTM1_GetCnt
** Description: Returns current down count value.
** Parameter:   None
** Return:      OSTM1CNT - OSTM1 Count Register
******************************************************************************/
uint32_t R_OSTM1_GetCnt()
{
  return OSTM1CNT;
}
