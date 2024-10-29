#include "peripheral.h"
#include "typedefine.h"
#include "system.h"
#include "os_Cfg.h"
#include "application_Cfg.h"
#include "os.h"

extern CoreIdType _CoreID;
//area count
//applicationmask
peri_info peri_info_array[AREA_COUNT] ={
    {
        1000,
        1200,
    },
    {
        2000,
        2200,
    }
};
PeripheralAutosarType PeripherilAutosar_core0[AREA_COUNT] = {
    {
        0,
    },
    {
        0,
    },
};

StatusType ReadPeripheral8(AreaIdType Area,const uint8* Address,uint8* ReadValue){
    SysServiceParaType para;
    para.serviceID = READPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    para.para3 = ReadValue;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
StatusType SysReadPeripheral8(AreaIdType Area,const uint8* Address,uint8* ReadValue){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 8) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    //application mask
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }

    if(ret == E_OK){
        *ReadValue = *Address;
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
        //這個會幹麻
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

StatusType ReadPeripheral16(AreaIdType Area,const uint16* Address,uint16* ReadValue){
    SysServiceParaType para;
    para.serviceID = READPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    para.para3 = ReadValue;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
StatusType SysReadPeripheral16(AreaIdType Area,const uint16* Address,uint16* ReadValue){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 16) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }
    if(ret == E_OK){
        *ReadValue = *Address;
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
        //這個會幹麻
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
StatusType ReadPeripheral32(AreaIdType Area,const uint32* Address,uint32* ReadValue){
    SysServiceParaType para;
    para.serviceID = READPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    para.para3 = ReadValue;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
StatusType SysReadPeripheral32(AreaIdType Area,const uint32* Address,uint32* ReadValue){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 32) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }

    if(ret == E_OK){
        *ReadValue = *Address;
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
        //這個會幹麻
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
StatusType WritePeripheral8(AreaIdType Area,uint8* Address,uint8 WriteValue){
    SysServiceParaType para;
    para.serviceID = WRITEPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    para.para3 = WriteValue;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
StatusType SysWritePeripheral8(AreaIdType Area,uint8* Address,uint8 WriteValue){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 8) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }

    if(ret == E_OK){
        *Address = WriteValue;
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
        //這個會幹麻
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
StatusType WritePeripheral16(AreaIdType Area,uint16* Address,uint16 WriteValue){
    SysServiceParaType para;
    para.serviceID = WRITEPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    para.para3 = WriteValue;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
StatusType SysWritePeripheral16(AreaIdType Area,uint16* Address,uint16 WriteValue){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 16) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }

    if(ret == E_OK){
        *Address = WriteValue;
    }
}
StatusType WritePeripheral32(AreaIdType Area,uint32* Address,uint32 WriteValue){
    SysServiceParaType para;
    para.serviceID = WRITEPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    para.para3 = WriteValue;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
StatusType SysWritePeripheral32(AreaIdType Area,uint32* Address,uint32 WriteValue){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 32) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }

    if(ret == E_OK){
        *Address = WriteValue;
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
        //這個會幹麻
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
StatusType ModifyPeripheral8(AreaIdType Area,uint8* Address,uint8 ClearMask,uint8 SetMask){
    SysServiceParaType para;
    para.serviceID = MODIFYPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    uint8 mask_arr[2] = {ClearMask,SetMask};
    para.para3 = mask_arr;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}   
StatusType SysModifyPeripheral8(AreaIdType Area,uint8* Address,uint8 ClearMask,uint8 SetMask){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 8) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }

    if(ret == E_OK){
        *Address = (*Address & ClearMask) | SetMask;
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
        //這個會幹麻
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
StatusType ModifyPeripheral16(AreaIdType Area,uint16* Address,uint16 ClearMask,uint16 SetMask){
    SysServiceParaType para;
    para.serviceID = MODIFYPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    uint16 mask_arr[2] = {ClearMask,SetMask};
    para.para3 = mask_arr;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}   
StatusType SysModifyPeripheral16(AreaIdType Area,uint16* Address,uint16 ClearMask,uint16 SetMask){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 16) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }

    if(ret == E_OK){
        *Address = (*Address & ClearMask) | SetMask;
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
        //這個會幹麻
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
StatusType ModifyPeripheral32(AreaIdType Area,uint32* Address,uint32 ClearMask,uint32 SetMask){
    SysServiceParaType para;
    para.serviceID = MODIFYPERIPGERAL8;
    para.para1 = Area;
    para.para2 = Address;
    uint32 mask_arr[2] = {ClearMask,SetMask};
    para.para3 = mask_arr;
    para.result = E_OK;
    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
StatusType SysModifyPeripheral32(AreaIdType Area,uint32* Address,uint32 ClearMask,uint32 SetMask){
    StatusType ret = E_OK;
    // E_OS_ID Area id is out of range (EXTENDED status)
    if(Area >= AREA_COUNT){
        ret = E_OS_ID;
    }
    // E_OS_VALUE Address does not belong to given Area
    peri_info *peri = &peri_info_array[Area];
    if(ret == E_OK){
        if(Address < peri->OsperipheralAreaStartAddress || ((Address + 32) > peri->OsperipheralAreaEndAddress)){
            ret = E_OS_VALUE;
        }
    }
    // E_OS_CALLEVEL Wrong call context of the API function
    if (ret == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        ret = E_OS_CALLEVEL;
    }
    
    // E_OS_ACCESS The calling task or ISR is not allowed to access the given
    if(ret == E_OK){
        if(~(SystemObjectAutosar[_CoreID]->PeripheralAutosar[Area].applicationsMask) & (1 << ExecutingApp[_CoreID])){
            ret = E_OS_ACCESS;
        }
    }

    if(ret == E_OK){
        *Address = (*Address & ClearMask) | SetMask;
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
        //這個會幹麻
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
