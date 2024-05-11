#ifndef PLATFORM_TYPES_H_INCLUDED
#define PLATFORM_TYPES_H_INCLUDED

#define CPU_TYPE_8  8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

#define CPU_TYPE  (CPU_TYPE_32)

#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;

typedef signed char        sint8;
typedef signed short       sint16;
typedef signed int         sint32;
typedef signed long long   sint64;

typedef float            float32;
typedef double           float64;
typedef uint64           size_t;

#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned long      uint32;
typedef unsigned long long uint64;

typedef signed char        sint8;
typedef signed short       sint16;
typedef signed long        sint32;
typedef signed long long   sint64;

typedef float              float32;
typedef double             float64;
typedef uint32             size_t;

#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned long      uint32;
typedef unsigned long long uint64;

typedef signed char        sint8;
typedef signed short       sint16;
typedef signed long        sint32;
typedef signed long long   sint64;

typedef float              float32;
typedef double             float64;
typedef uint16             size_t;

#elif (CPU_TYPE == CPU_TYPE_8)
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;

typedef signed char   sint8;
typedef signed short  sint16;
typedef signed long   sint32;

typedef float float32;
typedef uint8 size_t;

#endif
#endif // PLATFORM_TYPES_H_INCLUDED