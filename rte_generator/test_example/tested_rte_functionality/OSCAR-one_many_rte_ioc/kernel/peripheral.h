#ifndef PERIPHERAL_H
#define PERIPHERAL_H
#include "typedefine.h"

//area count
#define AREA_COUNT 2
extern peri_info peri_info_array[AREA_COUNT];
extern PeripheralAutosarType PeripherilAutosar_core0[AREA_COUNT];
extern PeripheralAutosarType PeripherilAutosar_core1[AREA_COUNT];

//right of osappication
StatusType ReadPeripheral8(AreaIdType Area,const uint8* Address,uint8* ReadValue);
StatusType ReadPeripheral16(AreaIdType Area,const uint16* Address,uint16* ReadValue);
StatusType ReadPeripheral32(AreaIdType Area,const uint32* Address,uint32* ReadValue);

StatusType WritePeripheral8(AreaIdType Area,uint8* Address,uint8 WriteValue);
StatusType WritePeripheral16(AreaIdType Area,uint16* Address,uint16 WriteValue);
StatusType WritePeripheral32(AreaIdType Area,uint32* Address,uint32 WriteValue);

StatusType ModifyPeripheral8(AreaIdType Area,uint8* Address,uint8 ClearMask,uint8 SetMask);
StatusType ModifyPeripheral16(AreaIdType Area,uint16* Address,uint16 ClearMask,uint16 SetMask);
StatusType ModifyPeripheral32(AreaIdType Area,uint32* Address,uint32 ClearMask,uint32 SetMask);


StatusType SysReadPeripheral8(AreaIdType Area,const uint8* Address,uint8* ReadValue);
StatusType SysReadPeripheral16(AreaIdType Area,const uint16* Address,uint16* ReadValue);
StatusType SysReadPeripheral32(AreaIdType Area,const uint32* Address,uint32* ReadValue);

StatusType SysWritePeripheral8(AreaIdType Area,uint8* Address,uint8 WriteValue);
StatusType SysWritePeripheral16(AreaIdType Area,uint16* Address,uint16 WriteValue);
StatusType SysWritePeripheral32(AreaIdType Area,uint32* Address,uint32 WriteValue);

StatusType SysModifyPeripheral8(AreaIdType Area,uint8* Address,uint8 ClearMask,uint8 SetMask);
StatusType SysModifyPeripheral16(AreaIdType Area,uint16* Address,uint16 ClearMask,uint16 SetMask);
StatusType SysModifyPeripheral32(AreaIdType Area,uint32* Address,uint32 ClearMask,uint32 SetMask); 

#endif