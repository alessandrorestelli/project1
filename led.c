//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include "stm32l4xx.h"                  // Device header
#include "led.h"
#include "SysClock.h"

void LedInit(void){
	LedRedInit();					//Inizializzazione led rosso
	LedGreenInit();				//Inizializzazione led verde
}

void LedOn(void){
	LedRedOn();
	LedGreenOn();
}

void LedBlink (int led, int nLamp, int ms){
	if (led==1 && nLamp!=0)
		LedRedBlink(nLamp,ms);
	else
		LedGreenBlink(nLamp,ms);
}

void LedRedInit(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;		//Abilitazione clock sul GPIOB
	GPIOB->MODER |= GPIO_MODER_MODER2_0;		//Configurazione output: bit 5 a 0
	GPIOB->MODER &= ~GPIO_MODER_MODER2_1;		//Configurazione output: bit 4 a 1
}

void LedRedOn(void){
	GPIOB->ODR |= GPIO_ODR_OD2;							//Accensione Led Rosso
}

void LedRedOff(void){
	GPIOB->ODR &= ~ GPIO_ODR_OD2;						//Spegnimento Led Rosso
}

void LedRedToggle(void){
	GPIOB->ODR ^= GPIO_ODR_OD2;							//Inversione dello stato tramite exor
}

void LedRedBlink(int nLamp, int ms){
	int a=0;										
	while(a<nLamp){								//Ciclo ripeturo nLamp volte per lampeggio
		LedRedToggle();								//Inversione dello stato
		DelaySystick1Ms(ms);
		a++;
	}
}

int LedRedCheck(void){
	if((GPIOB->ODR & GPIO_ODR_OD2)==0)
		return 0;
	else
		return 1;
}	

void LedRedTask(int Ton, int T){
	static int tiniziale;
	static char inizio=1;
	int tempo;
	if(inizio){
		LedRedOn();
		inizio=0;
		tiniziale= micros();
	}
	else
		tempo= micros()-tiniziale;
	if(LedRedCheck() && (tempo>=Ton)){
		LedRedOff();
	}
	else if (tempo>=T){
		LedRedOn();
		tiniziale=micros();
	}
}

/*------------------
Funzioni led Verde*/

void LedGreenInit(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;		//Abilitazione clock sul GPIOE
	GPIOE->MODER |= GPIO_MODER_MODER8_0;		//Configurazione come output: bit 17 a 0
	GPIOE->MODER &= ~GPIO_MODER_MODER8_1;		//Configurazione come output: bit 16 a 1
}

void LedGreenOn(void){
	GPIOE->ODR |= GPIO_ODR_OD8;							//Accensione Led Verde
}

void LedGreenOff(void){
  GPIOE->ODR &= ~ GPIO_ODR_OD8;							//Spegnimento Led Verde
}

void LedGreenToggle(void){
	GPIOE->ODR ^= GPIO_ODR_OD8;							//Inversione dello stato tramite exor
}

void LedGreenBlink(int nLamp, int ms){
	int a=0;
	while(a<nLamp){									//Ciclo ripeturo nLamp volte per lampeggio
		LedGreenToggle();							//Inversione dello stato
		DelaySystick1Ms(ms);
		a++;
	}
}

int LedGreenCheck(void){
	if((GPIOE->ODR & GPIO_ODR_OD8)==0)
		return 0;
	else
		return 1;
}

void LedGreenTask(int Ton, int T){
	static int tiniziale;
	static char inizio=1;
	int tempo;
	if (inizio){
		LedGreenOn();
		inizio=0;
		tiniziale= millis();
	}
	else 
		tempo= millis()-tiniziale;
	if(LedGreenCheck() && (tempo>=Ton)){
		LedGreenOff();
	}
	else if (tempo>=T){
		LedGreenOn();
		tiniziale=millis();
	}
}
