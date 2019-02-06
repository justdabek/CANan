/*
 *	Author: Paweł Pudo
 *	e-mail:	ppudo@outlook.com
 *	
 *	Date: 	01.10.2018
 *
 *	Description:
 *	Biblioteka do obsługi UARTa - tutaj jest bluetooth - BT-HC05/06
 *
 */
 
#include "stm32f4xx_hal.h"
#include "ring_buffer.h"
#include "bt_uart.h"

//extern UART_HandleTypeDef huart5;
//extern USART_HandleTypeDef husart1;


uint8_t uartBTrxTab[ BT_RX_BUFFER_SIZE ];
uint8_t uartBTtxTab[ BT_TX_BUFFER_SIZE ];
uint32_t uartBTtxTab32[ BT_TX_BUFFER_SIZE ];

RingBuffer_struct uartBTrxBuf;
RingBuffer_struct uartBTtxBuf;

RingBuffer_struct32 uartBTtxBuf32;

UART_HandleTypeDef uartBThandle;

//***************************************************************************************************************************************************
//***** FUNKJCE *****

//Funkjca inicjująca działanie całego modułu uart oraz buforów
void BTuartInit( void )
{
	GPIO_InitTypeDef GPIO_Init ;
	
	//Konfiguracja pinow od transmisji
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	GPIO_Init.Mode		= GPIO_MODE_AF_PP;
	GPIO_Init.Pull 		= GPIO_NOPULL;
	GPIO_Init.Speed		= GPIO_SPEED_FAST;
	
		//RX
	GPIO_Init.Pin		= GPIO_PIN_2;			//PD2
	GPIO_Init.Alternate = GPIO_AF8_UART5;
	HAL_GPIO_Init( GPIOD, &GPIO_Init );
	
		//TX
	GPIO_Init.Pin		= GPIO_PIN_12;			//PC12
	GPIO_Init.Alternate	= GPIO_AF8_UART5;
	HAL_GPIO_Init( GPIOC, &GPIO_Init );
	
	
	//Konfiguracja modulu UART
	__HAL_RCC_UART5_CLK_ENABLE();
	
	uartBThandle.Instance 			= UART5;
	uartBThandle.Init.BaudRate 		= 115200;
	uartBThandle.Init.HwFlowCtl 	= UART_HWCONTROL_NONE;
	uartBThandle.Init.Mode 			= UART_MODE_TX_RX;
	uartBThandle.Init.OverSampling 	= UART_OVERSAMPLING_16;
	uartBThandle.Init.Parity 		= UART_PARITY_NONE;
	uartBThandle.Init.StopBits 		= UART_STOPBITS_1;
	uartBThandle.Init.WordLength	= UART_WORDLENGTH_8B;
	
	HAL_UART_Init( &uartBThandle );
	
	//Konfiguracja przerwan od UARTA
	HAL_NVIC_SetPriority( UART5_IRQn, 0, 1 );
	HAL_NVIC_EnableIRQ( UART5_IRQn );
	
	__USART_ENABLE_IT( &uartBThandle, UART_IT_RXNE );
	
	//Inicjalizacja buforów
	RingBufferInit( &uartBTrxBuf, uartBTrxTab, BT_RX_BUFFER_SIZE );
	RingBufferInit( &uartBTtxBuf, uartBTtxTab, BT_TX_BUFFER_SIZE );
	//RingBufferInit32( &uartBTtxBuf32, uartBTtxTab32, BT_TX_BUFFER_SIZE );
}

//*************************************************************************************************
//Funkjca pobierająca bajt danych z bufroa UARTa
// @param Miejsce gdzie ma zostać zapisana dana
bool BTuartReadByte( uint8_t* byte )
{
	return RingBufferRead( &uartBTrxBuf, byte );
}

//*************************************************************************************************
//Funkjca pobierająca tablicę danych z bufora UARTa
// @param Wskaźnik na tablicę gdzie ma zostać zwrócona
// @param Ilość elementów, które chcemy pobrać
uint32_t BTuartReadArray( uint8_t* array, uint32_t arrayLen )
{
	return RingBufferReadArray( &uartBTrxBuf, array, arrayLen );
}

//*************************************************************************************************
//Funkjca pobierająca string z bufora UARTa
// @param Miejsce gdzie string ma zostać zapisany
// @param Maksymalna długość stringu jaką chcemy odczytać
// @return Długość stringa jakiego udało się odczytać
uint32_t BTuartReadString( char* string, uint32_t maxLen )
{
	return RingBufferReadString( &uartBTrxBuf, string, maxLen );
}

//*************************************************************************************************
//Funkjca dodająca bajt do wysłania przez UARTA
// @param Bajt, który chcemy wysłać
bool BTuartWriteByte( uint8_t byte )
{
	bool result = RingBufferWrite( &uartBTtxBuf, byte );
	__USART_ENABLE_IT( &uartBThandle, UART_IT_TXE );
	
	return result;
}

bool BTuartWriteByte32( uint32_t lbyte )
{
	bool result = RingBufferWrite32( &uartBTtxBuf32, lbyte );
	__USART_ENABLE_IT( &uartBThandle, UART_IT_TXE );
	
	return result;
}
//*************************************************************************************************
//Funkjca wysyłająca tablicę danych
// @param Wskaźnik na tablicę, którą chcemy wysłać
// @param Długość tablicy, którą chcemy wysłać
// @return Ile danych udało się wysłać
uint32_t BTuartWriteArray( uint8_t* array, uint32_t arrayLen )
{
	uint32_t result = RingBufferWriteArray( &uartBTtxBuf, array, arrayLen );
	__USART_ENABLE_IT( &uartBThandle, UART_IT_TXE );
	
	return result;
}

//*************************************************************************************************
//Funkjca wysyłająca tablicę danych
// @param String, który chcemy wysłać
// @retunr Jak długi string udało się wysłać
uint32_t BTuartWriteString( char* string )
{
	uint32_t result = RingBufferWriteString( &uartBTtxBuf, string );
	__USART_ENABLE_IT( &uartBThandle, UART_IT_TXE );
	
	return result;
}

//***************************************************************************************************************************************************
////Obsługa przerwania od danych wychodzących i przychodzących
//void UART5_IRQHandler( void )
//{
//	//Przerwanie od odbioru danych		- RX
//	if( __HAL_UART_GET_FLAG( &uartBThandle, UART_FLAG_RXNE ) )
//	{
//		if( __HAL_UART_GET_IT_SOURCE( &uartBThandle, UART_IT_RXNE ) )
//		{
//			uint8_t znak = UART5->DR;
//			RingBufferWrite( &uartBTrxBuf, znak );
//		}
//	}
//	
//	//Przerwanie od nadawania danych	- TX
//	if( __HAL_UART_GET_FLAG( &uartBThandle, UART_FLAG_TXE ) )
//	{
//		if( __HAL_UART_GET_IT_SOURCE( &uartBThandle, UART_IT_TXE ) )
//		{
//			uint8_t znak;
//			if( RingBufferRead( &uartBTtxBuf, &znak ) )
//			{
//				UART5->DR = znak;
//			}
//			else
//			{
//				__USART_DISABLE_IT( &uartBThandle, UART_IT_TXE );
//			}
//		}
//	}
//}
