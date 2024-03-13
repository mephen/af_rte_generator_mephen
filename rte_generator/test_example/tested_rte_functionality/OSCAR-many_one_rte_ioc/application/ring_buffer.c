#include "ring_buffer.h"// Function to check if the buffer is full
int IsFull(RingBuffer* rb) {
    return rb->currentSize == rb->maxSize;
}

// Function to check if the buffer is empty
int IsEmpty(RingBuffer* rb) {
    return rb->currentSize == 0;
}

void* memcpy_t(void* dest, const void* src, size_t n) {
    char* d = (char*) dest;
    const char* s = (const char*) src;
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}
// Function to add an element to the buffer
Std_ReturnType RTE_Enqueue(RingBuffer* rb, void* data, size_t dataSize) {
    char* byte_buffer = (char*)rb->buffer;
    if (IsFull(rb) || dataSize > sizeof(byte_buffer)) {
        return RTE_E_LIMIT;
    }
size_t offset = rb->tail * dataSize;
    memcpy_t(byte_buffer+offset, data, dataSize);  // Convert to int* then assign
    rb->tail = (rb->tail + 1) % rb->maxSize;
    rb->currentSize++;
    return RTE_E_OK;
}

// Function to remove an element from the buffer
Std_ReturnType RTE_Dequeue(RingBuffer* rb, void* data, size_t dataSize) {
    if (IsEmpty(rb)) {
        return RTE_E_NO_DATA;
    }
    char* byte_buffer = (char*)rb->buffer;
    size_t offset = rb->head * dataSize;
    memcpy_t(data, byte_buffer+offset, dataSize);
    rb->head = (rb->head + 1) % rb->maxSize;
    rb->currentSize--;
    return RTE_E_OK;
}

Std_ReturnType RTE_Update(void* target, void* data, size_t dataSize) {
    memcpy_t(target, data, dataSize);
    return RTE_E_OK;
}

Std_ReturnType RTE_Fetch(void* target, const void* source, size_t dataSize) {
    memcpy_t(target, source, dataSize);
    return RTE_E_OK;
}