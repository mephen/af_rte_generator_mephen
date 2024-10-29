#define RTE_PSWC_C
#include "Rte_PSWC.h"

Impl_uint8 const speed_Init = 0;
Impl_uint8 speed = speed_Init;

Impl_uint16 const height_Init = 10;
Impl_uint16 height = height_Init;

Impl_uint8 get_speed(){
    return speed;
}
Impl_uint16 get_height(){
    return height;
}

