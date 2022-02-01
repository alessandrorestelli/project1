/** ****************************************************************************************
* @file pulsanti.h
* @brief Dichiarazione delle librerie utilizzate per i pulsanti
* @author Alessandro Restelli 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
*/

/** ****************************************************************************************
* @brief Configurazione dei pulsanti
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
void PulsInit(void);	

/** ****************************************************************************************
* @brief Verifica dello stato del pulsante centrale. Controllo se viene premuto
* @retval La funzione ritorna il valore del registro assegnato al pulsante così da capire se
* viene premuto
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int PulsCxPress(void);	

/** ****************************************************************************************
* @brief Verifica dello stato del pulsante sinistro. Controllo se viene premuto
* @retval La funzione ritorna il valore del registro assegnato al pulsante così da capire se
* viene premuto
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int PulsSxPress(void);	

/** ****************************************************************************************
* @brief Verifica dello stato del pulsante destro. Controllo se viene premuto
* @retval La funzione ritorna il valore del registro assegnato al pulsante così da capire se
* viene premuto
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int PulsDxPress(void);	

/** ****************************************************************************************
* @brief Verifica dello stato del pulsante in alto. Controllo se viene premuto
* @retval La funzione ritorna il valore del registro assegnato al pulsante così da capire se
* viene premuto
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int PulsUpPress(void);	

/** ****************************************************************************************
* @brief Verifica dello stato del pulsante in basso. Controllo se viene premuto
* @retval La funzione ritorna il valore del registro assegnato al pulsante così da capire se
* viene premuto
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int PulsDwPress(void);						

/** ****************************************************************************************
* @brief Calcolo per quanto tempo il pulsante centrale viene premuto. 
* @retval La funzione ritorna il tempo calcolato
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int pulseInPA0 (void);

/** ****************************************************************************************
* @brief Calcolo per quanto tempo il pulsante sinistro viene premuto. 
* @retval La funzione ritorna il tempo calcolato
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int pulseInPA1 (void);

/** ****************************************************************************************
* @brief Calcolo per quanto tempo il pulsante destro viene premuto. 
* @retval La funzione ritorna il tempo calcolato
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int pulseInPA2 (void);

/** ****************************************************************************************
* @brief Calcolo per quanto tempo il pulsante in alto viene premuto. 
* @retval La funzione ritorna il tempo calcolato
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int pulseInPA3 (void);

/** ****************************************************************************************
* @brief Calcolo per quanto tempo il pulsante in basso viene premuto. 
* @retval La funzione ritorna il tempo calcolato
* @author Alessandro Restelli 5L
* @date   28/9/2021
* @version 1.0 28/9/2021
*/
int pulseInPA5 (void);
