/** ****************************************************************************************
* @file Ultrasuoni.h
* @brief Dichiarazione delle librerie utilizzate per la configurazione e l'utilizzo del sensore a ultrasuoni
*
* @author Alessandro Restelli 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file Ultrasuoni.h
* @version 1.1
*/

/** ****************************************************************************************
* @brief Configurazione del segnale di Trigger
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void TrigConfig(void);

/** ****************************************************************************************
* @brief Accensione segnale di trigger
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void TrigOn(void);

/** ****************************************************************************************
* @brief Spegnimento segnale di trigger
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void TrigOff(void);

/** ****************************************************************************************
* @brief Controllo stato del segnale di trigger: verifico se è acceso o spento
* @retval Ritorna il valore 1 se il registro è a 0. Se no ritornerà 1
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int TrigCheck(void);

/** ****************************************************************************************
* @brief Task per far funzione il sensore a ultrasuoni in modo che mandi un impulso costante
* @param  Come parametri passo il tempo di accensione e il tempo totale della durata del task	 
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void TrigTask (int Ton, int T);

/** ****************************************************************************************
* @brief Configurazione Echo del sensore a ultrasuoni
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void EchoConfig (void);

/** ****************************************************************************************
* @brief Configurazione interrupt sull'Echo del sensore a ultrasuoni
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void EchoInterrupt(void);

/** ****************************************************************************************
* @brief Funzione che manda in esecuzione il task del segnale di Trigger. Una volta ricevuta 
* l amisura controlla che sia minore di un metro; in questo caso farà lampeggiare il led. 
* Se la misura è maggiore o uguale a un metro il led rimarrà spento
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void Sensore_lampeggio (void);

/** ****************************************************************************************
* @brief Configurazione dei pin della scheda a cui sono collegati Trigger  e Echo
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void UsInit (void);

/** ****************************************************************************************
* @brief Funzione che riceve la misura calcolata e stampa il valore sul display LCD
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void StampoValore(void);

/** ****************************************************************************************
* @brief Funzione che mette il valore della variabile "flag_misura" a 1 se la misura è minore di 0.
*        Altrimenti sarà messo a 0 e il led non lampeggierà. 
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void ControlloMisura (void);

/** ****************************************************************************************
* @brief Questa funzione calcola per quanto tempo il led deve rimanere acceso e per quanto spento.
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void CalcoloTempiLampeggio(void);
