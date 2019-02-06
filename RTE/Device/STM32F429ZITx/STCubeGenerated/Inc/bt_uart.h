#ifndef _BT_UART_H
#define _BT_UART_H
/*
 *	Author: Paweł Pudo
 *	e-mail:	ppudo@outlook.com
 *	
 *	Date: 	01.10.2018
 *
 *	Description:
 *	Biblioteka do obsługi UARTa - w tym projekcie jest tu podłączony moduł bluetooth
 *
 */
 
#include <stdint.h>																					//uintxx_t
#include <stdbool.h>																				//bool
 

//***************************************************************************************************************************************************
//***** DEFINICJE *****
#define BT_RX_BUFFER_SIZE	256
#define BT_TX_BUFFER_SIZE	256


//***************************************************************************************************************************************************
//***** FUNKCJE *****

//***************************************************************************************************************************************************
//Funkjca inicjująca działanie całego modułu uart oraz buforów
void BTuartInit( void );

//*************************************************************************************************
//Funkjca pobierająca bajt danych z bufroa UARTA
// @param Miejsce gdzie ma zostać zapisana dana
bool BTuartReadByte( uint8_t* byte );

//*************************************************************************************************
//Funkjca pobierająca tablicę danych z bufora UARTA
// @param Wskaźnik na tablicę gdzie ma zostać zwrócona
// @param Ilość elementów, które chcemy pobrać
uint32_t BTuartReadArray( uint8_t* array, uint32_t arrayLen );

//*************************************************************************************************
//Funkjca pobierająca string z bufora UARTa
// @param Miejsce gdzie string ma zostać zapisany
// @param Maksymalna długość stringu jaką chcemy odczytać
// @return Długość stringa jakiego udało się odczytać
uint32_t BTuartReadString( char* string, uint32_t maxLen );

//*************************************************************************************************
//Funkjca dodająca bajt do wysłania przez UARTA
// @param Bajt, który chcemy wysłać
bool BTuartWriteByte( uint8_t byte );

//*************************************************************************************************
//Funkjca wysyłająca tablicę danych
// @param Wskaźnik na tablicę, którą chcemy wysłać
// @param Długość tablicy, którą chcemy wysłać
// @return Ile danych udało się wysłać
uint32_t BTuartWriteArray( uint8_t* array, uint32_t arrayLen );

//*************************************************************************************************
//Funkjca wysyłająca tablicę danych
// @param String, który chcemy wysłać
// @retunr Jak długi string udało się wysłać
uint32_t BTuartWriteString( char* string );

#endif
