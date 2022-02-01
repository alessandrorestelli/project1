//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include "stm32l4xx.h"          // Device header
#include "puls.h"
#include "SysClock.h"


void PulsInit(void){
	//Pulsante centrale
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE0_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE0_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE0_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE0_1;
	
	//Pulsante Sinistro
	GPIOA->MODER &= ~GPIO_MODER_MODE1_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE1_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE1_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE1_1;
	
	//Pulsante Destro
	GPIOA->MODER &= ~GPIO_MODER_MODE2_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE2_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE2_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE2_1;
	
	//Pulsante Up
	GPIOA->MODER &= ~GPIO_MODER_MODE3_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE3_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE3_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE3_1;
	
	//Pulsante Down
	GPIOA->MODER &= ~GPIO_MODER_MODE5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE5_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE5_1;
}

int PulsCxPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID0_Msk);
}

int PulsSxPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID1_Msk);
}

int PulsDxPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID2_Msk);
}

int PulsUpPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID3_Msk);
}

int PulsDwPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID5_Msk);
}

int pulseInPA0(void){
	while(PulsCxPress()==0){};
	int inizio=micros();
	while(PulsCxPress()!=0){};
	int t=micros()-inizio;
	return t;
}

int pulseInPA1(void){
	while(PulsSxPress()==0){};
	int inizio=millis();
	while(PulsSxPress()!=0){};
	int t=millis()-inizio;
	return t;
}

int pulseInPA2(void){
	while(PulsDxPress()==0){};
	int inizio=micros();
	while(PulsDxPress()!=0){};
	int t=micros()-inizio;
	return t;
}

int pulseInPA3(void){
	while(PulsUpPress()==0){};
	int inizio=micros();
	while(PulsUpPress()!=0){};
	int t=micros()-inizio;
	return t;
}

int pulseInPA5(void){
	while(PulsDwPress()==0){};
	int inizio=micros();
	while(PulsDwPress()!=0){};
	int t=micros()-inizio;
	return t;
}
