//============================================================================
// PROJECT  :  Example project
//============================================================================
//                           C O P Y R I G H T
//============================================================================
// Copyright (c) 2013 by Renesas Electronics Europe GmbH. All rights reserved.
// Arcadiastr.10
// D-40472 Duesseldorf
// Germany
//============================================================================
//
// Warranty Disclaimer :
// Because the Product(s) is licensed free of charge, there is no warranty of
// any kind whatsoever and expressly disclaimed and excluded by Renesas, either
// expressed or implied, including but not limited to those for non-
// infringement of intellectual property, merchantability and/or fitness for
// the particular purpose. Renesas shall not have any obligation to maintain,
// service or provide bug fixes for the supplied Product(s) and/or the
// Application.
//
// Each User is solely responsible for determining the appropriateness of
// using the Product(s) and assumes all risks associated with its exercise
// of rights under this Agreement, including, but not limited to the risks
// and costs of program errors, compliance with applicable laws, damage to
// or loss of data, programs or equipment, and unavailability or
// interruption of operations.
//
// Limitation of Liability :
// In no event shall Renesas be liable to the User for any incidental,
// consequential, indirect, or punitive damage (including but not limited to
// lost profits) regardless of whether such liability is based on breach of
// contract, tort, strict liability, breach of warranties, failure of
// essential purpose or otherwise and even if advised of the possibility of
// such damages. Renesas shall not be liable for any services or products provided
// by third party vendors, developers or consultants identified or referred
// to the User by Renesas in connection with the Product(s) and/or the
// Application.
//
//============================================================================
//
// Device specific main header file to be included in all source files.
//
//============================================================================

#ifndef   R_DEVICE_H
#define   R_DEVICE_H

//============================================================================
// Includes
//============================================================================
#ifdef __GHS__
    #include "dr7f701527.dvf.h"
    #include "icu_feret.h"
    #include "cpu.h"
    
    /* Suppress warning that main function shall return integer. */
    #pragma ghs nowarning 951

    #define main_pe1 main
    #define main_pe2 main
    
    #define __nop() __asm("nop")
#endif

#ifdef __IAR__
    #include <intrinsics.h>
    #include <ior7f701527.h>
    #include <intVecNumF1H.h>
    
    #define __nop() __asm("nop")
    
    #define __SYNCP() __asm("syncp")
#endif 

#ifdef __CSP__
    #include "dr7f701527.dvf.h"
    #include "intVecNumF1H.h"
    
    #pragma inline_asm __SYNCP
    static void __SYNCP(void)
    {
	    syncp;
    }
    
    #define RET_RAM_BEG   0xFEF00000
    #define RET_RAM_END   0xFEF0FFFF 
    #define __SNOOZE __nop
#endif 

#include "r_typedefs.h"

//============================================================================
// Defines
//============================================================================
#define protected_write(preg,pstatus,reg,value)   do{\
                                                  (preg)=0xa5u;\
                                                  (reg)=(value);\
                                                  (reg)=~(value);\
                                                  (reg)=(value);\
                                                  }while((pstatus)==1u)
                                                    
                                                    
#define PE1 1
#define PE2 2
                                                  
#endif  /* R_DEVICE_H */
