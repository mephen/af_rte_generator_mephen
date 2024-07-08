#ifndef MEMPROT_H
#define MEMPROT_H

#include "application_Cfg.h"
#include "os_Cfg.h"

#define MPM_DX 0x400    //this bit should be zero
#define MPM_DW 0x200    //this bit should be zero
#define MPM_DR 0x100    //this bit should be zero
#define MPM_SVP 0x2     //enable mpu In SV mode and ref SX, SW, SR
#define MPM_MPE 0x1     //enable mpu

#define MPAT_E 0x80     // this area enable mpu
#define MPAT_G 0x40     // 0 means not using ASID
#define MPAT_SX 0x20
#define MPAT_SW 0x10
#define MPAT_SR 0x8
#define MPAT_UX 0x4
#define MPAT_UW 0x2
#define MPAT_UR 0x1

#define MPM_regID 0
#define MPM_selID 5

#define DisableMPU()                                \
    do {                                            \
        __ldsr_rh(MPM_regID, MPM_selID, 0);         \
        kernelDisableMPUCounter++;                  \
    } while(0)

#define EnableMPU()                                             \
    do {                                                        \
        kernelDisableMPUCounter--;                              \
        if (kernelDisableMPUCounter < 0){                       \
            /* this case should NOT happen, */                  \
            /* if EnableMPU and DisableMPU are used in pair */  \
            kernelDisableMPUCounter = 0;                        \
        }                                                       \
        else if (kernelDisableMPUCounter == 0){                 \
            __ldsr_rh(MPM_regID, MPM_selID, CURRENTTASK.MPM);   \
        }                                                       \
        else { /* (kernelDisableMPUCounter > 0) */              \
            ; /* do noth, keep disable */                       \
        }                                                       \
    } while(0)


#if (ENABLE_SOFTWARE_STACK_MONITOR == ENABLE)
    #define STACK_MONITOR_APPEND_SIZE 4
    #define STACK_MONITOR_PATTERN 0x01234567
#else
    #define STACK_MONITOR_APPEND_SIZE 0
    #define STACK_MONITOR_PATTERN 0x00000000
#endif

extern ProtectionReturnType ProtectionHook(StatusType Error);

inline void my_mem_data_copy( uint32 my_rom_s, uint32 my_rom_e, uint32 my_ram_s){
    uint32 ii,jj;
    for(ii = my_rom_s, jj = my_ram_s; ii < my_rom_e; ++ii, ++jj ){
        *((uint8*)(jj)) = *((uint8*)(ii));  //copy byte
    }
}

inline void my_mem_bss_clean( uint32 my_bss_s, uint32 my_bss_e){
    uint32 ii;
    for(ii = my_bss_s; ii < my_bss_e; ++ii){
        *((uint8*)(ii)) = 0;    //reset byte
    }
}

void SetOSMemProt(void);
void SetMemProt(void);
void SetSystaskMemProt(void);
void SetAppMemProtWithMPM( ApplicationType app_id );
void InitRomToRamMemArea(CoreIdType coreID);
void ReInitTaskRomToRamMemArea( uint32 RunnableID );
void ReInitOSAppRomToRamMemArea( uint32 appID );
boolean CheckWritingAccess(uint32 *address);

boolean CheckAddressinStack(uint32 *address);


#if (ENABLE_SOFTWARE_STACK_MONITOR == ENABLE)
void ReInitStackMonitorPattern( uint32 objectID );
void checkStackMonitorPattern();
#else
    #define ReInitStackMonitorPattern(objectID)     \
        do{                                         \
            ; /*do nth*/                            \
        }while (0)

    #define checkStackMonitorPattern()     \
        do{                                \
            ; /*do nth*/                   \
        }while (0)
#endif  /* ENABLE_SOFTWARE_STACK_MONITOR */

#endif  /* MEMPROT_H */