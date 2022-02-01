/** ****************************************************************************************
* @file interrupt.h
* @brief Dichiarazione delle librerie utilizzate per abilitazione interrupt
*
* @author Alessandro Restelli 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file interrupt.h
* @version 1.1
*/

#include <stdint.h>

/** ****************************************************************************************
* @brief Per leggere correttamente i dati dalla memoria FLASH, il numero di stati di attesa
* deve essere correttamente programmato in base alla frequenza del clock della CPU
* e la tensione di alimentazione del dispositivo.
* CMSIS Function per l'aggiornamento della variabile SystemCoreClock
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void MSIInit(uint8_t range);

/** ****************************************************************************************
* @brief Abilita l'oscillatore interno ad alta velocità
* Regola il valore di calibrazione dell'oscillatore ad alta velocità
* Seleziona la sorgente di clock su PLL
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void pllInit(uint8_t M, uint8_t N, uint8_t R);

/** ****************************************************************************************
* @brief  Clock a 80Mhz
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void SysClockInit(void);

/** ****************************************************************************************
* @brief  Funzione di attesa per un valore passato come parametro avente come unità di misura
* i microsecondi
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void delayMicroseconds(uint64_t us);

/** ****************************************************************************************
* @brief  Funzione di attesa per un valore passato come parametro avente come unità di misura
* i millisecondi
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void delay(uint64_t ms);

/** ****************************************************************************************
* @brief  Incremento Ticks
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void SysTick_Handler (void);

/** ****************************************************************************************
* @brief  Funzione di calcolo microsecondi
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
uint64_t micros(void);

/** ****************************************************************************************
* @brief  Funzione di calcolo millisecondi
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
uint64_t millis(void);


//Funzioni SysTick
void SystickInit(void);
void DelaySystick1Ms(int ms);