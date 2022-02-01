#ifndef __STM32L476G_DISCOVERY_LCD_H
#define __STM32L476G_DISCOVERY_LCD_H

#include <stdint.h>

#define bool _Bool
typedef enum{BAR0,BAR1,BAR2,BAR3} bar;
void LCDInit(void);
void LCDbar(void);
void LCDClockInit(void);
void LCDPINInit(void);
void LCDConfigure(void);
void LCDClear(void);
void LCDDisplayString(uint8_t* ptr);
void LCDDisplayStringEx(uint8_t* ptr);
void LCDWriteChar(uint8_t* ch, bool point, bool colon, uint8_t position);
static void LCDConvCharSeg(uint8_t* c,bool point,bool colon, uint8_t* digit);
void LCDDisplayName(void);
void LCDcontrastoUp(void);
void LCDcontrastoDown(void);
uint8_t LCDcontrastovalue(void);
void LCDcontrastoset(uint8_t c);
void LCDbarOn(bar b);
void LCDbarOff(bar b);
void Printtime (void);

#endif /* __STM32L476G_DISCOVERY_LCD_H */
