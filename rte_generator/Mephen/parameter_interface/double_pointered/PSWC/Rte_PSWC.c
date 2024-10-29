#define RTE_PSWC_C
#include "Rte_PSWC.h"

//index of the para
#define speed 0
#define height 1
//ParaEleGroup (ROM)
Parameter const ParaEleGroup[2] = {
    {.para_uint8 = 0},
    {.para_uint16 = 10}
};

//index of the ParaEleGroup
#define Group1 0
//calibration ref table (ROM)
void* const RteParameterRefTab[1] = {
    ParaEleGroup
};

//base ref (RAM)
void** RteParameterBase = RteParameterRefTab;

Impl_uint8 get_speed(){
    Parameter* paraGroup = (Parameter*)(RteParameterBase[Group1]);
    return paraGroup[speed].para_uint8;
}
Impl_uint16 get_height(){
    Parameter* paraGroup = (Parameter*)(RteParameterBase[Group1]);
    return paraGroup[height].para_uint16;
}

