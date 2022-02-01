//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include "stm32l4xx.h"
#include "SysClock.h"

void MSIInit(uint8_t range) {
	
	FLASH->ACR &= ~FLASH_ACR_LATENCY;
	FLASH->ACR |=  FLASH_ACR_LATENCY_2WS;

	RCC->CR |=  RCC_CR_MSION_Msk;
	while((RCC->CR & RCC_CR_MSION_Msk)==0);
	RCC->CFGR &= ~RCC_CFGR_SW_Msk;
	RCC->CFGR |= RCC_CFGR_SW_MSI;
	RCC->CR &= ~ RCC_CR_MSIRANGE_Msk;
	RCC->CR |=range<<RCC_CR_MSIRANGE_Pos;	
	RCC->CR |=RCC_CR_MSIRGSEL;
	
	SystemCoreClockUpdate();
}

void pllInit(uint8_t M, uint8_t N, uint8_t R) {
	
	uint32_t HSITrim;	
	FLASH->ACR &= ~FLASH_ACR_LATENCY;
	FLASH->ACR |=  FLASH_ACR_LATENCY_2WS;


	RCC->CR |= RCC_CR_HSION;
	RCC->CR |=  RCC_CR_HSION_Msk;
	while((RCC->CR & RCC_CR_HSION_Msk)==0);
	
	RCC->ICSCR &= ~RCC_ICSCR_HSITRIM;
	RCC->ICSCR |= HSITrim << RCC_ICSCR_HSITRIM_Pos;

	RCC->CR &= ~ RCC_CR_PLLON; 
	while((RCC->CR & RCC_CR_PLLRDY_Msk)==RCC_CR_PLLRDY_Msk) {;} //attendo

  RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLSRC_Msk; 
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSI; 
	RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLM_Msk;
	RCC->PLLCFGR |= M<<RCC_PLLCFGR_PLLM_Pos;
	RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLN_Msk;
	RCC->PLLCFGR |= N<<RCC_PLLCFGR_PLLN_Pos;
	RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLR_Msk;
	RCC->PLLCFGR |= R<<RCC_PLLCFGR_PLLR_Pos;
  
	RCC->CR |= RCC_CR_PLLON;
	while((RCC->CR & RCC_CR_PLLRDY_Msk)==0) {;}

  RCC->PLLCFGR |= 1<<RCC_PLLCFGR_PLLREN_Pos;
	RCC->CFGR &= ~ RCC_CFGR_SW;	
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	
	SystemCoreClockUpdate();
}

void SysClockInit(void){
	pllInit(0, 10, 0);		
	SysTick_Config(80);
}

volatile uint64_t ticks;

void SysTick_Handler (void){
	ticks++;
}

uint64_t micros(void){
	return ticks;
}

void delayMicroseconds(uint64_t us){
	uint64_t startTime=micros();
	while((micros()-startTime)<=us){}
}

uint64_t millis(void){
	return ticks/1000;
}

void delay(uint64_t ms){
	uint64_t startTime=millis();
	while ((millis()-startTime)<=ms){}
}
