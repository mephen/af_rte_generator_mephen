#ifndef __BOARD_H__
#define __BOARD_H__

void WDTAInit_pe1(void);
void INTWDTA0(void);
void _BoardInit_pe1(void);
void preBoardInit_pe2(void);
void WDTAInit_pe2(void);
void INTWDTA1(void);
void _BoardInit_pe2(void);
void SWReset(void);
void FEInterrupt(void);

#endif // __BOARD_H__
