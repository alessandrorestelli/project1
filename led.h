/** ****************************************************************************************
* @file led.h
* @brief Dichiarazione delle librerie utilizzate per i led
* 
* @author Alessandro Restelli 5L
* @date 28/9/2021 
* @version 1.0 28/9/2021 Prima versione del file led.h
*/

/** ****************************************************************************************
* @brief Configurazione pin PB2 e PE8
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedInit(void); 

/** ****************************************************************************************
* @brief Accensione led rosso e led verde
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedOn(void);	

/** ****************************************************************************************
* @brief Lampeggio di un led
* @param  Per funzionare come parametri passo alla funzione:
*         -  1 o 2, ovvero led rosso(1) o verde (2);
*					-  il numero di lampeggi da eseguire;
*         -  l'intervallo di tempo con cui deve eseguire il lampeggio.
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedBlink(int led, int nLamp, int ms);	


/*------------------
Funzioni led Rosso*/

/** ****************************************************************************************
* @brief Configurazione pin PB2 su cui è collegato il led rosso
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedRedInit(void);						

/** ****************************************************************************************
* @brief Accensione led rosso
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedRedOn(void);						

/** ****************************************************************************************
* @brief Spegnimento led rosso
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedRedOff(void);						 

/** ****************************************************************************************
* @brief Inversione stato del led rosso: da spento il led verrà acceso e viceversa
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedRedToggle(void);					

/** ****************************************************************************************
* @brief Lampeggio del led rosso
* @param  Come parametri passo alla funzione il numero di lampeggi 
*         e il tempo i cui deve avvenire
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedRedBlink(int nLamp, int ms);				

/** ****************************************************************************************
* @brief Controllo stato del led rosso: verifico se è acceso o spento
* @retval La funzione ritorna il valore 1 se il registro è a 0. Se no ritornerà 1
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int LedRedCheck(void);

/** ****************************************************************************************
* @brief Lampeggio del led rosso utilizzando funzioni di calcolo del tempo (micros)
* @param  Come parametri passo il tempo di accensione e il tempo totale della durata del task	 
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void LedRedTask(int Ton, int t);


//Funzioni led Verde
void LedGreenInit(void);											//Inizializzazione
void LedGreenOn(void);												//Accensione
void LedGreenOff(void);												//Spegnimento 
void LedGreenToggle(void);										//Inversione stato
void LedGreenBlink(int nLamp, int ms);				//Lampeggio
void LedGreenTask (int Ton, int t);
int LedGreenCheck(void);
void LedRedTask(int Ton, int t);
