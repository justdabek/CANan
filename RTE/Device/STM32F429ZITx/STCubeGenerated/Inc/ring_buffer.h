#ifndef _RING_BUFFER_H
#define _RING_BUFFER_H
/*
 *	Author: Paweł Pudo
 *	e-mail:	ppudo@outlook.com
 *	
 *	Date: 	30.09.2018
 *
 *	Description:
 *	Biblioteka do obsługi bufora kołowego
 *
 */
 
#include <stdint.h>																					//uintxx_t
#include <stdbool.h>																				//bool
 
//***************************************************************************************************************************************************
//Struktura opisująca budowę bufora
typedef struct 
{
	uint8_t* buffer;									//wskaźnik na miejsce w pamięci gdzie znaduje się dane
	uint32_t size;										//rozmiar bufora
	uint32_t usage;										//poziom użycia
	uint32_t headPos;									//początek, gdzie zapisywane są nowe dane
	uint32_t tailPos;									//koniec, skąd pobierane są dane
}RingBuffer_struct;

typedef struct 
{
	uint32_t* buffer;									//wskaźnik na miejsce w pamięci gdzie znaduje się dane
	uint32_t size;										//rozmiar bufora
	uint32_t usage;										//poziom użycia
	uint32_t headPos;									//początek, gdzie zapisywane są nowe dane
	uint32_t tailPos;									//koniec, skąd pobierane są dane
}RingBuffer_struct32;

//***************************************************************************************************************************************************
//***** FUNKCJE *****

//Funkcja inicjalizująca bufor kołowy
// @param Wskaźnik na struktuę bufora
// @param Wskaźnik na miejscie gdzie bufor ma przechowywać dane
// @param Rozmiar bufora
void RingBufferInit( RingBuffer_struct* ringBuffer, uint8_t* bufferTable, uint32_t bufferSize );
void RingBufferInit32( RingBuffer_struct32* ringBuffer, uint32_t* bufferTable, uint32_t bufferSize );
//*************************************************************************************************
//Funkcja dodająca bajt do bufroa
// @param Wskaźnik na bufor, do którgo mamy wstawić dane
// @param Dana do wstawienia
// @return '1' jeżeli się udało, '0' jeżeli się nie udało dodać
bool RingBufferWrite( RingBuffer_struct* ringBuffer, uint8_t byte );
bool RingBufferWrite32( RingBuffer_struct32* ringBuffer, uint32_t lbyte );
//*************************************************************************************************
//Funkcja dodająca tablicę danych do bufora
// @param Wskaźnik na bufor, do którgo mamy wstawić dane
// @param Wskaźnik na tablicę danych
// @param Ilość danych do wysłania
// @return Ile danych udało się dodać do bufora
uint32_t RingBufferWriteArray( RingBuffer_struct* ringBuffer, uint8_t* array, uint32_t arraySize );

//*************************************************************************************************
//Funkcja dodająca do bufora stringa
// @param Wskaźnik na bufor, do którgo mamy wstawić dane
// @param String do wstawienia
// @return '1' jeżeli opercja się udała, '0' jeżeli wystąpił jakiś błąd
bool RingBufferWriteString( RingBuffer_struct* ringBuffer, char* string );

//*************************************************************************************************
//Funkjca pobierjąca dane z bufora
// @param Wskaźnik na bufor, z którego pobieramy dane
// @param Miejscie gdzie mamy zapisać dane
bool RingBufferRead( RingBuffer_struct* ringBuffer, uint8_t* byte );

//*************************************************************************************************
//Funkjca pobierająca tablicę z bufora
// @param Wskaźnik na bufor, z którgo pobiermy tablicę
// @param Miejsce gdzie mamy zapisać dane 
// @param Ile danych chcemy odczytać
// @return Ile danych idało się odczytać
uint32_t RingBufferReadArray( RingBuffer_struct* ringBuffer, uint8_t* array, uint32_t arraySize );

//*************************************************************************************************
//Funkjca pobierająca stringa z bufora
// @param Wskaźnik na bufor, z którgo pobiermy stringa
// @param Miejsce gdzie mamy zapisać stringa
// @param Maksymalna długość stringa (razem z NULL na końcu)
// @return Długość stringa jakiego udało się pobrać
uint32_t RingBufferReadString( RingBuffer_struct* ringBuffer, char* string, uint32_t maxLen );

//*************************************************************************************************
//Funkcja zerująca bufor, dodatkow wypełnia go zerami
// @param Wskaźnik na bufor, który chcemy wyczyścić
void RingBufferClean( RingBuffer_struct* ringBuffer );

#endif
