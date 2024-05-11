#ifndef __GPIO_H__
#define __GPIO_H__

typedef struct {
    unsigned char bit00:1;
    unsigned char bit01:1;
    unsigned char bit02:1;
    unsigned char bit03:1;
    unsigned char bit04:1;
    unsigned char bit05:1;
    unsigned char bit06:1;
    unsigned char bit07:1;
    unsigned char bit08:1;
    unsigned char bit09:1;
    unsigned char bit10:1;
    unsigned char bit11:1;
    unsigned char bit12:1;
    unsigned char bit13:1;
    unsigned char bit14:1;
    unsigned char bit15:1;
} __bit_T;

typedef enum {
    PORT0 = 0x00,
    PORT1,
    PORT2,
    PORT8 = 0x08,
    PORT9,
    PORT10,
    PORT11,
    PORT12,
    PORT18 = 0x12,
    PORT20 = 0x14,
    PORT_AP0 = 0x32,
    PORT_AP1
} t_Port;

typedef enum {
    PIN0 = 0x0001,
    PIN1 = 0x0002,
    PIN2 = 0x0004,
    PIN3 = 0x0008,
    PIN4 = 0x0010,
    PIN5 = 0x0020,
    PIN6 = 0x0040,
    PIN7 = 0x0080,
    PIN8 = 0x0100,
    PIN9 = 0x0200,
    PIN10 = 0x0400,
    PIN11 = 0x0800,
    PIN12 = 0x1000,
    PIN13 = 0x2000,
    PIN14 = 0x4000,
    PIN15 = 0x8000,
} t_Pin;

typedef enum {
    INPUT_PIN,
    OUTPUT_PIN
} t_Pin_Dir;

#define P10_3	(((volatile __bit_T *)0xFFC10028)->bit03)
#define LED1	P10_3
#define P8_5	(((volatile __bit_T *)0xFFC10020)->bit05)
#define LED2	P8_5

void GPIO_init(void);

#endif  //__GPIO_H__