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
 
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "ring_buffer.h"
#include "bt_uart.h"

//***** FUNKCJE *****
 
//***************************************************************************************************************************************************
//Funkcja inicjalizująca bufor kołowy
// @param Wskaźnik na struktuę bufora
// @param Wskaźnik na miejscie gdzie bufor ma przechowywać dane
// @param Rozmiar bufora
void RingBufferInit( RingBuffer_struct* ringBuffer, uint8_t* bufferTable, uint32_t bufferSize )
{
	ringBuffer->buffer = bufferTable;
	ringBuffer->size = bufferSize;
	ringBuffer->usage = 0;
	ringBuffer->headPos = 0;
	ringBuffer->tailPos = 0;
}

void RingBufferInit32( RingBuffer_struct32* ringBuffer, uint32_t* bufferTable, uint32_t bufferSize )
{
	ringBuffer->buffer = bufferTable;
	ringBuffer->size = bufferSize;
	ringBuffer->usage = 0;
	ringBuffer->headPos = 0;
	ringBuffer->tailPos = 0;
}

//*************************************************************************************************
//Funkcja dodająca bajt do bufroa
// @param Wskaźnik na bufor, do którgo mamy wstawić dane
// @param Dana do wstawienia
// @return '1' jeżeli się udało, '0' jeżeli się nie udało dodać
bool RingBufferWrite( RingBuffer_struct* ringBuffer, uint8_t byte )
{
	bool result;
	__disable_irq();
	
	if( ringBuffer->usage < ringBuffer->size )
	{
		ringBuffer->buffer[ ringBuffer->headPos ] = byte;
		ringBuffer->usage++;
		ringBuffer->headPos++;
		if( ringBuffer->headPos >= ringBuffer->size )
		{
			ringBuffer->headPos = 0;
		}
		result = 1;
	}
	else
	{
		result = 0;
	}
	
	__enable_irq();	
	return result;
}


bool RingBufferWrite32( RingBuffer_struct32* ringBuffer, uint32_t lbyte )
{
	bool result;
	__disable_irq();
	
	if( ringBuffer->usage < ringBuffer->size )
	{
		ringBuffer->buffer[ ringBuffer->headPos ] = lbyte;
		ringBuffer->usage++;
		ringBuffer->headPos++;
		if( ringBuffer->headPos >= ringBuffer->size )
		{
			ringBuffer->headPos = 0;
		}
		result = 1;
	}
	else
	{
		result = 0;
	}
	
	__enable_irq();	
	return result;
}
//*************************************************************************************************
//Funkcja dodająca tablicę danych do bufora
// @param Wskaźnik na bufor, do którgo mamy wstawić dane
// @param Wskaźnik na tablicę danych
// @param Ilość danych do wysłania
// @return Ile danych udało się dodać do bufora
uint32_t RingBufferWriteArray( RingBuffer_struct* ringBuffer, uint8_t* array, uint32_t arraySize )
{
	uint32_t i = 0;
	for( i=0; i<arraySize; i++ )
	{
		if( !RingBufferWrite( ringBuffer, array[i] ) )
		{
			break;
		}
	}
	
	return i;
}

//*************************************************************************************************
//Funkcja dodająca do bufora stringa
// @param Wskaźnik na bufor, do którgo mamy wstawić dane
// @param String do wstawienia
// @return '1' jeżeli opercja się udała, '0' jeżeli wystąpił jakiś błąd
bool RingBufferWriteString( RingBuffer_struct* ringBuffer, char* string )
{
	uint32_t size = strlen( string );
	
	if( size != RingBufferWriteArray( ringBuffer, (uint8_t*)string, size ) )
	{
		return 0;
	}
	
	return 1;
}

//*************************************************************************************************
//Funkjca pobierjąca dane z bufora
// @param Wskaźnik na bufor, z którego pobieramy dane
// @param Miejscie gdzie mamy zapisać dane
bool RingBufferRead( RingBuffer_struct* ringBuffer, uint8_t* byte )
{
	bool result;
	__disable_irq();
	
	if( ringBuffer->usage > 0 )
	{
		*byte = ringBuffer->buffer[ ringBuffer->tailPos ];
		ringBuffer->usage--;
		ringBuffer->tailPos++;
		if( ringBuffer->tailPos >= ringBuffer->size )
		{
			ringBuffer->tailPos = 0;
		}
		result = 1;
	}
	else
	{
		*byte = 0x00;
		result = 0;
	}
	
	__enable_irq();
	return result;
}

//*************************************************************************************************
//Funkjca pobierająca tablicę z bufora
// @param Wskaźnik na bufor, z którgo pobiermy tablicę
// @param Miejsce gdzie mamy zapisać dane 
// @param Ile danych chcemy odczytać
// @return Ile danych idało się odczytać
uint32_t RingBufferReadArray( RingBuffer_struct* ringBuffer, uint8_t* array, uint32_t arraySize )
{
	uint32_t i = 0;
	for( i=0; i<arraySize; i++ )
	{
		if( !RingBufferRead( ringBuffer, &array[i] ) )
		{
			break;
		}
	}
	
	return i;
}

//*************************************************************************************************
//Funkjca pobierająca stringa z bufora
// @param Wskaźnik na bufor, z którgo pobiermy stringa
// @param Miejsce gdzie mamy zapisać stringa
// @param Maksymalna długość stringa (razem z NULL na końcu)
// @return Długość stringa jakiego udało się pobrać
uint32_t RingBufferReadString( RingBuffer_struct* ringBuffer, char* string, uint32_t maxLen )
{
	uint32_t i = 0;
	for( i=0; i<maxLen; i++ )
	{
		if( RingBufferRead( ringBuffer, (uint8_t*)&string[i] ) )
		{
			if( string[i] == 0x00 )
			{
				return i;
			}				
		}
		else
		{
			return 0;
		}
	}
	
	return 0;
}

//*************************************************************************************************
//Funkcja zerująca bufor, dodatkow wypełnia go zerami
// @param Wskaźnik na bufor, który chcemy wyczyścić
void RingBufferClean( RingBuffer_struct* ringBuffer )
{
	uint32_t i = 0;
	
	ringBuffer->headPos = 0;
	ringBuffer->tailPos = 0;
	ringBuffer->usage = 0;
	
	for( i=0; i<ringBuffer->size; i++ )
	{
		RingBufferWrite( ringBuffer, 0x00 );
	}
	
	ringBuffer->headPos = 0;
	ringBuffer->tailPos = 0;
	ringBuffer->usage = 0;
}
