/** ****************************************************************************************
* \mainpage Es-04 Sensore a ultrasuoni
*
* @brief Scrittura del codice in linguaggio C per il calcolo della distanza da un oggetto
* 			 Questa distanza sarà visibuile sul display LCD presente sulla scheda. Più piccola 
*        sarà distanza rilevata dal sensore più veloce lampeggierà il led. Se la distanza è 
*        <1 metro il led non lampeggierà, ma rimarrà spento.
*
* @author Alessandro Restelli 5L
* @date 28/9/2021
* @version 1.0 28/9/2021
* @version 1.1 Nessuna modifica apportata fino ad ora
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include "stm32l4xx.h"                  	// Device header
#include <stdio.h>
#include "led.h"
#include "puls.h"
#include "interrupt.h"
#include "SysClock.h"
#include "LCD.h"
#include "Us.h"

//=== MAIN PROGRAM =========================================================================
int main(){
	
	//Inizializzazioni
	LedInit();													//Led
	PulsInit();											//Pulsanti
	InterruptInit();										//Interrupt
	SysClockInit();											//Clock
	LCDInit();													//LCD
	UsInit();										//Sensore a ultrasuoni

	LCDDisplayString((uint8_t *)"0");	
	
	//Main loop
	while(1){														
		Sensore_lampeggio();
	}
}
