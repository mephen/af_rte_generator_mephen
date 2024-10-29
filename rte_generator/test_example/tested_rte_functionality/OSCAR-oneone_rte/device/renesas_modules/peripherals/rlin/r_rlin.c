/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_rlin.c                                                        */
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
/* Source code for the RLIN2 and RLIN3 functions. RLIN24 is used as LIN      */
/* interface, RLIN30 is used as UART interface.                              */
/*                                                                           */
/*===========================================================================*/

/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include "r_device.h"
#include "r_rlin.h"
//#include "r_uart.h"
#include "dr7f701527.dvf.h"
#include "system.h"
#include "memprot.h"
#include "scheduler.h"
#include "os_Cfg.h"
#include "lock.h"

/*===========================================================================*/
/* Variables */
/*===========================================================================*/

#pragma section 

char_t *g_pNextData;	/* Pointer to next data to be transmitted */
char_t *g_pNextData_r35;	/* Pointer to next data to be transmitted */

/* add on 20220515 to print str to console */
#define RING_BUF_SIZE 128
char* str_ring_buf[RING_BUF_SIZE];
unsigned int buf_idx_add_head;
unsigned int buf_idx_cur_tail;

#define RING_BUF_SIZE_R35 128
char* str_ring_buf_r35[RING_BUF_SIZE_R35];
unsigned int buf_idx_add_head_r35;
unsigned int buf_idx_cur_tail_r35;

#define MULTICORE_TO_SAME_PRINT 1
#ifdef MULTICORE_TO_SAME_PRINT
  uint8 lock_var;
  uint8 lock_var_r35;
  #define lock_bit 0x07     /*the 0x07 do not has special meaning, just a pattern*/
#endif

#pragma section 

/*===========================================================================*/
/* Interrupts */
/*===========================================================================*/
/*****************************************************************************
** Function:    INTRLIN30UR0
** Description: RLIN30 UART Tx Completion interrupt.
** Parameter:   None
** Return:      None
******************************************************************************/

// /*commemt on 20220515 */
// #ifdef __IAR__
//     #pragma vector = NUMINTRLIN30UR0
//       __interrupt void INTRLIN30UR0(void){
//       ++g_pNextData;
//       if(*g_pNextData != '\0'){
//           RLN30LUTDR = *g_pNextData;
//       }
//     }
// #endif
// #ifdef __GHS__
//     #pragma ghs interrupt
//     void INTRLIN30UR0(void){
//       ++g_pNextData;
//       if(*g_pNextData != '\0'){
//           RLN30LUTDR = *g_pNextData;
//       }
//     }
// #endif
// #ifdef __CSP__
// #endif /* __CSP__*/

#pragma interrupt INTRLIN30UR0(enable=manual, priority=EIINT_PRIORITY1, fpu=false, callt=false )
void INTRLIN30UR0(void){
    DisableMPU();
    if(*g_pNextData != '\0'){
        RLN30LUTDR = *g_pNextData++;
    }
    else if( buf_idx_add_head != buf_idx_cur_tail ){
        buf_idx_cur_tail = (buf_idx_cur_tail+1)%RING_BUF_SIZE;
        g_pNextData = str_ring_buf[buf_idx_cur_tail];
        if( *g_pNextData != '\0' ){
            RLN30LUTDR = *g_pNextData++;
        }
    }
    else{
        ;//do nth
    }
    EnableMPU();
}

/* add on 20220515 */
#pragma interrupt INTRLIN35UR0(enable=manual, priority=EIINT_PRIORITY1, fpu=false, callt=false )
void INTRLIN35UR0(void){
    DisableMPU();
    if(*g_pNextData_r35 != '\0'){
        RLN35LUTDR = *g_pNextData_r35++;
    }
    else if( buf_idx_add_head_r35 != buf_idx_cur_tail_r35 ){
        buf_idx_cur_tail_r35 = (buf_idx_cur_tail_r35 + 1)%RING_BUF_SIZE_R35;
        g_pNextData_r35 = str_ring_buf_r35[buf_idx_cur_tail_r35];
        if( *g_pNextData_r35 != '\0' ){
            RLN35LUTDR = *g_pNextData_r35++;
        }
    }
    else{
        ;//do nth
    }
    EnableMPU();
}

/*===========================================================================*/
/* Functions */
/*===========================================================================*/


/*****************************************************************************
** Function:    R_RLIN30_UartInit
** Description: Initialize the RLIN30 for UART usage.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_RLIN30_UartInit(void)
{
    /* @2022/02/20 LIN */  
    
    /* UART_RLIN30 Operation Enable Register */
	/* UROE 0 and UTOE 0: Disables reception and transmission. */
	RLN30LUOER = 0x00u;

	/* LIN / UART_RLIN30 Control Register */
	RLN30LCUC = 0x00u;  /* LIN reset mode is set */
	/* for error-detect, you can check RLN30LMST after set the RLN30LCUC */

	/* LIN Wake-up Baud Rate Selector register  */
    RLN30LWBR = 0x50u; /* 6 samples per bit */

	/* LIN Baud Rate Prescaler1/UART_RLIN30 Baud Rate Prescaler */
	/* Baudrate = PCLK / ( ((BRP value) + 1)*(number of samples per bit) ) */
    /* if use 0x02b5, 40MHZ/((0x2b5+1)*6)= 9600 baud */
	/* 40MHZ/((0x38+1)*6)= 115200 baud */
    RLN30LBRP01=0x0038;

	/* LIN Mode Register/UART_RLIN30 Mode Register (LMD) */
	/* LRDNFS is 0, so noise filter enabled */
	/* LMD is set b01 To use the LIN/UART */
	RLN30LMD = 0x01u; 

    /* LIN Break Field Configuration Register/UART_RLIN30 Configuration Register1 */
	/* UTPS 0: Without TX inversion */
	/* URPS 0: Without RX inversion */
	/* UPS 01: Even Parity is adapted */
	/* USBLS 0: Stop Bit 1 bit */
	/* UBOS 0: LSB first */
	/* UBLS 0: UART_RLIN30 8-bit communication */
	RLN30LBFC = 0x08u; 


    /* LIN / UART_RLIN30 Error Detection Enable Register */
	/* FERE 1: Framing Error Detection Enable */
	/* OERE 1: Overrun Error Detection Enable */
	/* BERE 0: Only Bit Error Detection Enable is disabled now */
	RLN30LEDE = 0x0cu;  /*b'00001100*/

    /* LIN / UART_RLIN30 Control Register */
    RLN30LCUC = 0x01u; /* LIN reset mode is cancelled */
	/* for error-detect, you can check RLN30LMST after set the RLN30LCUC */

    /* UART_RLIN30 Operation Enable Register */
	/* UROE 1 and UTOE 1: Enables reception and transmission. */
	RLN30LUOER = 0x03u;
}

void R_RLIN35_UartInit(void)
{
    /* @2022/02/20 LIN */  
    
    /* UART_RLIN35 Operation Enable Register */
	/* UROE 0 and UTOE 0: Disables reception and transmission. */
	RLN35LUOER = 0x00u;

	/* LIN / UART_RLIN35 Control Register */
	RLN35LCUC = 0x00u;  /* LIN reset mode is set */
	/* for error-detect, you can check RLN30LMST after set the RLN30LCUC */

	/* LIN Wake-up Baud Rate Selector register  */
    RLN35LWBR = 0x50u; /* 6 samples per bit */

	/* LIN Baud Rate Prescaler1/UART_RLIN35 Baud Rate Prescaler */
	/* Baudrate = PCLK / ( ((BRP value) + 1)*(number of samples per bit) ) */
    /* if use 0x02b5, 40MHZ/((0x2b5+1)*6)= 9600 baud */
	/* 40MHZ/((0x38+1)*6)= 115200 baud */
    RLN35LBRP01=0x0038;

	/* LIN Mode Register/UART_RLIN35 Mode Register (LMD) */
	/* LRDNFS is 0, so noise filter enabled */
	/* LMD is set b01 To use the LIN/UART */
	RLN35LMD = 0x01u; 

    /* LIN Break Field Configuration Register/UART_RLIN30 Configuration Register1 */
	/* UTPS 0: Without TX inversion */
	/* URPS 0: Without RX inversion */
	/* UPS 01: Even Parity is adapted */
	/* USBLS 0: Stop Bit 1 bit */
	/* UBOS 0: LSB first */
	/* UBLS 0: UART_RLIN30 8-bit communication */
	RLN35LBFC = 0x08u; 


    /* LIN / UART_RLIN30 Error Detection Enable Register */
	/* FERE 1: Framing Error Detection Enable */
	/* OERE 1: Overrun Error Detection Enable */
	/* BERE 0: Only Bit Error Detection Enable is disabled now */
	RLN35LEDE = 0x0cu;  /*b'00001100*/

    /* LIN / UART_RLIN35 Control Register */
    RLN35LCUC = 0x01u; /* LIN reset mode is cancelled */
	/* for error-detect, you can check RLN30LMST after set the RLN30LCUC */

    /* UART_RLIN35 Operation Enable Register */
	/* UROE 1 and UTOE 1: Enables reception and transmission. */
	RLN35LUOER = 0x03u;
}

/*****************************************************************************
** Function:    init_str_ring_buf
** Description: initialize str_ring_buf and str_ring_buf_r35 and lock_var, lock_var_r35
** Parameter:   None
** Return:      None
** will be called by device\renesas_modules\modules\uart\r_uart.c: R_UART_Init()
******************************************************************************/
void init_str_ring_buf(){
    buf_idx_add_head = buf_idx_cur_tail = 0;
	buf_idx_add_head_r35 = buf_idx_cur_tail_r35 = 0;
    g_pNextData = g_pNextData_r35 = 0;

  #ifdef MULTICORE_TO_SAME_PRINT
    lock_var = 0x0;
	lock_var_r35 = 0x0;
  #endif
}

/*****************************************************************************
** Function:    str_add_head
** Parameter:   string to be send
** Return:      -1 if buffer is full
** will be called by device\renesas_modules\modules\uart\r_uart.c: R_UART_SendString()
******************************************************************************/
int str_add_head(char* str_to_p){
	//Full-Ascending

    #ifdef MULTICORE_TO_SAME_PRINT
    	GetLock(&lock_var, lock_bit);
    #endif
    
    if( (buf_idx_add_head+1)%RING_BUF_SIZE == buf_idx_cur_tail ){
        
		#ifdef MULTICORE_TO_SAME_PRINT
	    	ReleaseLock(&lock_var, lock_bit);
        #endif
		
		;//do nth, buf is full
		return -1;
    }
    else{
        buf_idx_add_head = (buf_idx_add_head+1)%RING_BUF_SIZE;
        str_ring_buf[buf_idx_add_head] = str_to_p;
	
		#ifdef MULTICORE_TO_SAME_PRINT
	    	ReleaseLock(&lock_var, lock_bit);
        #endif

        return 0;
    }
}

int str_add_head_r35(char* str_to_p){

    #ifdef MULTICORE_TO_SAME_PRINT
    	GetLock(&lock_var_r35, lock_bit);
    #endif
    
    if( (buf_idx_add_head_r35+1)%RING_BUF_SIZE_R35 == buf_idx_cur_tail_r35 ){
        
		#ifdef MULTICORE_TO_SAME_PRINT
	    	ReleaseLock(&lock_var_r35, lock_bit);
        #endif
		
		;//do nth, buf is full
		return -1;
    }
    else{
        buf_idx_add_head_r35 = (buf_idx_add_head_r35 + 1)%RING_BUF_SIZE_R35;
        str_ring_buf_r35[buf_idx_add_head_r35] = str_to_p;
	
		#ifdef MULTICORE_TO_SAME_PRINT
	    	ReleaseLock(&lock_var_r35, lock_bit);
        #endif

        return 0;
    }
}

/*****************************************************************************
** Function:    R_RLIN30_UartSendString
** Description: Sends out a string via UART.
** Parameter:   string to be send
** Return:      None
******************************************************************************/
void R_RLIN30_UartSendString(char_t send_string[])
{
	while((RLN30LST&16u)==16u){
		/* Wait until RLIN transmission is finished */
	}

	if( buf_idx_add_head != buf_idx_cur_tail ){		// "maybe" sth in buffer not print yet
		if( g_pNextData == 0 || *g_pNextData == '\0' ){				//make sure actually nothing left before, 
			buf_idx_cur_tail = (buf_idx_cur_tail+1)%RING_BUF_SIZE;	//so we need to prepare a new print action.
			g_pNextData = str_ring_buf[buf_idx_cur_tail];
			if( *g_pNextData != '\0' ){
				RLN30LUTDR = *g_pNextData++;						//when you modify the reg, you start the print
			}
		}
		else{
			return;    // there are other strings not print complete yet
		} 
	}

	//legacy code:
	//g_pNextData = send_string;
	//RLN30LUTDR = *g_pNextData++;
}

void R_RLIN35_UartSendString(char_t send_string[])
{
	
	while((RLN35LST&16u)==16u){
		/* Wait until RLIN transmission is finished */
	}

	if( buf_idx_add_head_r35 != buf_idx_cur_tail_r35 ){
		if( g_pNextData_r35 == 0 || *g_pNextData_r35 == '\0' ){
			buf_idx_cur_tail_r35 = (buf_idx_cur_tail_r35 + 1)%RING_BUF_SIZE_R35;
			g_pNextData_r35 = str_ring_buf_r35[buf_idx_cur_tail_r35];
			if( *g_pNextData_r35 != '\0' ){
				RLN35LUTDR = *g_pNextData_r35++;
			}
		}
		else{
			return;    // there are other strings not print complete yet
		} 
	}
}

/*****************************************************************************
** Function:    R_RLIN30_GetStatus
** Description: Returns if RLIN30 is busy or ready.
** Parameter:   None
** Return:      RLIN30_busy
**              RLIN30_ready
******************************************************************************/
uint8_t R_RLIN30_GetStatus(void)
{
  if((RLN30LST&16u)==16u)
  {
    return RLIN_BUSY;
  }
  else                             /* If transmission bit is 0 (transmission ready) */
  {
    return RLIN_READY;
  }
}

uint8_t R_RLIN35_GetStatus(void)
{
  if((RLN35LST&16u)==16u)
  {
    return RLIN_BUSY;
  }
  else                             /* If transmission bit is 0 (transmission ready) */
  {
    return RLIN_READY;
  }
}


/*****************************************************************************/
/* BELOW are R_RLIN24 relative function*/
/*****************************************************************************/

/*****************************************************************************
** Function:    R_RLIN24_BaudrateInit
** Description: Configures the RLIN24 Baudrate.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_RLIN24_BaudrateInit(void)
{
  /* LIN Wake-up Baud Rate Selector register  */
  RLN240GLWBR = 0X01u;
  
  /* LIN Baud Rate Prescaler1 */
  RLN240GLBRP1 = 0x02;     /* Baudrate = PCLK / (((BRP value) + 1)*(number of samples per bit)) */
  RLN240GLBRP0 = 0x81;     /* 40MHZ/((129+1)*16)=19200 */
}

/*****************************************************************************
** Function:    R_RLIN24_Channel1Init
** Description: Initialize Channel1 of RLIN24.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_RLIN24_Channel1Init(void)
{
  do{
      RLN2401L1CUC = 0x00u;
  }while(RLN2401L1MST !=0u );
  
    /* LIN Mode Register */
  RLN2401L1MD = 0x00u;      /* LIN System Clock: fa */
  
  /* LIN Break Field Configuration Register */
  RLN2401L1BFC = 0x15u;     /* b3-b0=0101: break width 18Tbits; b5b4=01: break delimiter 2Tbit */
  

  
  RLN2401L1SC = 0x17u;     /* Inter-byte(header/response) 7Tbits and interbyte 1Tbit */

  RLN2401L1WUP=0x30u;      /* b7-b4=0100: Wake-up Transmission low width 4 bits */

  RLN2401L1IE = 0x03u;       /* Tx/Rx interrupt enabled */
  

  
  /* LIN Error Detection Enable Register */
  RLN2401L1EDE = 0x0fu;      /* Enable error detection */
  
  RLN2401L1DFC = 0x28u;     /* Enhanced checksum, response field length 8byte + checksum */
  
  /* Reset is cancelled / operating mode is caused */ 
  do
  {
    RLN2401L1CUC = 0x03u;
  }while(RLN2401L1MST != 0x03u);
}

/*****************************************************************************
** Function:    R_RLIN24_Channel1TxFrame
** Description: Transmits Data on Channel 1 of RLIN24.
** Parameter:   TxFrame - Frame to be transmitted
**                  ID - Frame ID
**                  DB - Data Buffer
** Return:      LIN_OK - No error occurred
**              LIN_ERROR - Error occurred
******************************************************************************/
uint8_t R_RLIN24_Channel1TxFrame(uint8_t ID, uint8_t TxDB[])
{
  uint8_t PB = 0;
  
  /* Only 6 Bits are valid for ID */
  ID &= 0x3Fu;
  
  /* Parity Bit Calculation */
  if(ID&&0x17u)
    {
        PB |= 0x40;
    }
  if(!(ID&&0x3Au))
    {
        PB |= 0x80;
    }
  ID |= PB;
  
  while(RLN2401L1TRC&&0x03); /* Wait until an ongoing transmission is stopped */
  
  /* Set ID and Parity */
  RLN2401L1IDB = ID;

  /* Fill LIN data buffer registers */
  RLN2401L1DBR1 = TxDB[0];    
  RLN2401L1DBR2 = TxDB[1];    
  RLN2401L1DBR3 = TxDB[2];
  RLN2401L1DBR4 = TxDB[3];
  RLN2401L1DBR5 = TxDB[4];
  RLN2401L1DBR6 = TxDB[5];
  RLN2401L1DBR7 = TxDB[6];
  RLN2401L1DBR8 = TxDB[7];  
  
  RLN2401L1DFC |= 1u<<4;    /* Set mode to transmission */
  RLN2401L1TRC |= 0x01u;    /* Set start bit */
  
  while(RLN2401L1ST!=0x81u)  /* Wait while frame transmission not completed */
  {    
    if((RLN2401L1ST&8)==8u)     /* If error occurred */
    {        
      return RLIN_ERROR;   /* Return error */
    }    
  }
  return RLIN_OK;
}

/*****************************************************************************
** Function:    R_RLIN24_Channel1RxFrame
** Description: Stores Data received on Channel 1 of RLIN24.
** Parameter:   RxDB - Receive Data Buffer
** Return:      LIN_OK - No error occurred
**              LIN_ERROR - Error occurred
**              LIN_NO_MSG - No message received
******************************************************************************/
uint8_t R_RLIN24_Channel1RxFrame(uint8_t RxDB[])
{
   
    while(RLN2401L1TRC&&0x03u); /* Wait until an ongoing transmission is stopped */
    
    if(RLN2401L1ST==0x02u) /* Successful Frame Reception */
        { 
            RxDB[0] = RLN2401L1DBR1;
            RxDB[1] = RLN2401L1DBR2;
            RxDB[2] = RLN2401L1DBR3;
            RxDB[3] = RLN2401L1DBR4;
            RxDB[4] = RLN2401L1DBR5;
            RxDB[5] = RLN2401L1DBR6;
            RxDB[6] = RLN2401L1DBR7;
            RxDB[7] = RLN2401L1DBR8;
            
            return RLIN_OK;
        }
    else
        {
            if(RLN2401L1ST==0x08u) /* An error occured */
                {
                    return RLIN_ERROR;
                }
            else
                {
                    return RLIN_NO_MSG;
                }
        }
}