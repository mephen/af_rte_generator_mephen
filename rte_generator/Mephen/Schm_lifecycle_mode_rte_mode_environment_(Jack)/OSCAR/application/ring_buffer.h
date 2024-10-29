#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "Rte_Type.h"
// Function declarations
int IsFull(RingBuffer* rb);
int IsEmpty(RingBuffer* rb);
void* memcpy_t(void* dest, const void* src, size_t n);
Std_ReturnType RTE_Enqueue(RingBuffer* rb, void* data, size_t dataSize);
Std_ReturnType RTE_Dequeue(RingBuffer* rb, void* data, size_t dataSize);
Std_ReturnType RTE_Update(void* target, void* data, size_t dataSize);
Std_ReturnType RTE_Fetch(void* target, const void* source, size_t dataSize);
#endif // RING_BUFFER_H