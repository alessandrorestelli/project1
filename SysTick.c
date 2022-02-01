#include "stm32l4xx.h"                  // Device header
#include "led.h"

/*------------------
Funzioni SysTick*/

void SystickInit(void){
  SysTick -> CTRL = 0;
	SysTick -> LOAD = 3999;
	SysTick -> VAL = 0;
	SysTick -> CTRL |= 1<<0;
	SysTick -> CTRL |= 1<<2;
}

void DelaySystick1Ms(int ms){
	int i;
  for (i=0; i<ms; i++){
	  while((SysTick -> CTRL & SysTick_CTRL_COUNTFLAG_Msk)==0){
		}
	}
}