#ifndef __ISRINIT_H__
#define __ISRINIT_H__


#include "typedefine.h"



void CrossCoreISRInit(void);
void InitSchedulerIRQ(void);
void ISRInit(void);
void disableISR(uint32 channel);
void enableISR(uint32 channel);
void clearpendingISR(uint32 channel);

void setInterruptPriority(uint32 channel,uint32 priority);
void setInterruptCore(uint32 channel, uint32 core);
void setTableReference(uint32 channel);

boolean checkISRdisabled(uint32 channel);
boolean checkISRenabled(uint32 channel);

// for testing
void triggerISR(uint32 channel);

void disableSchedulerIRQ(void);
void enableSchedulerIRQ(void);

void disableCrossCoreISR(void);
void enableCrossCoreISR(void);

#endif // __ISRINIT_H__