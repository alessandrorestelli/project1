//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include "interrupt.h"
#include "led.h"
#include "stm32l4xx.h"                  // Device header

void InterruptInit(void){
	setIntPulsPA0();
	setIntPulsPA1();
	setIntPulsPA2();
	setIntPulsPA3();
	setIntPulsPA5();
}

void setIntPulsPA0(void){
	//Abilatazione interrupt sul pulsante centrale
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT0;
	EXTI->FTSR1 &= EXTI_FTSR1_FT0;
	EXTI->IMR1 |= EXTI_IMR1_IM0;
	NVIC_SetPriority(EXTI0_IRQn,3);
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler (void){
	//ISR del pulsante centrale
	LedGreenOff();
	EXTI->PR1 |= EXTI_PR1_PIF0;
}

void setIntPulsPA1(void){
	//Abilatazione interrupt sul pulsante sinistro
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI1_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI1_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT1;
	EXTI->FTSR1 &= EXTI_FTSR1_FT1;
	EXTI->IMR1 |= EXTI_IMR1_IM1;
	NVIC_SetPriority(EXTI1_IRQn,3);
	NVIC_EnableIRQ(EXTI1_IRQn);
}

void EXTI1_IRQHandler (void){
	//ISR del pulsante sinistro
	LedRedOn();
	EXTI->PR1 |= EXTI_PR1_PIF1;
}

void setIntPulsPA2(void){
	//Abilatazione interrupt sul pulsante destro
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI2_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT2;
	EXTI->FTSR1 &= EXTI_FTSR1_FT2;
	EXTI->IMR1 |= EXTI_IMR1_IM2;
	NVIC_SetPriority(EXTI2_IRQn,3);
	NVIC_EnableIRQ(EXTI2_IRQn);
}

void EXTI2_IRQHandler (void){
	//ISR del pulsante destro
	LedRedOff();
	EXTI->PR1 |= EXTI_PR1_PIF2;
}

void setIntPulsPA3(void){
	//Abilatazione interrupt sul pulsante UP
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI3_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI3_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT3;
	EXTI->FTSR1 &= EXTI_FTSR1_FT3;
	EXTI->IMR1 |= EXTI_IMR1_IM3;
	NVIC_SetPriority(EXTI3_IRQn,3);
	NVIC_EnableIRQ(EXTI3_IRQn);
}

void EXTI3_IRQHandler (void){
	//ISR del pulsante UP
	LedGreenOn();
	EXTI->PR1 |= EXTI_PR1_PIF3;
}

void setIntPulsPA5(void){
	//Abilatazione interrupt sul pulsante DOWN
	SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI5_Msk;
	SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI5_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT5;
	EXTI->FTSR1 &= EXTI_FTSR1_FT5;
	EXTI->IMR1 |= EXTI_IMR1_IM5;
	NVIC_SetPriority(EXTI9_5_IRQn,3);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void EXTI9_5_IRQHandler (void){
	//ISR del pulsante DOWN
	LedGreenToggle();
	LedRedToggle();
	EXTI->PR1 |= EXTI_PR1_PIF5;
}