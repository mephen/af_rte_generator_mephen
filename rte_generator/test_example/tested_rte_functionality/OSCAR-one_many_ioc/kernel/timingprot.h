#ifndef TIMINGPROT_H
#define TIMINGPROT_H

extern ProtectionReturnType ProtectionHook(StatusType Error);

void ProtectionHandle(StatusType Error);
void TimingProtection();
HardwareTickType getBound(TaskType TaskID, TimingProtTypeType Type, uint32 key);
void addTimingCounter(TimingProtCounterType *Counter, TimingProtTypeType Type, HardwareTickType Bound);
void removeTimingCounter(TimingProtCounterType *Counter);
void resetTimingCounter(TimingProtCounterType *Counter);

#endif