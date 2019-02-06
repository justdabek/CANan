#include "Notifications.h"

//extern UART_HandleTypeDef huart1;

void u32ToArr(uint32_t data, uint8_t *array){
	array[0] = (data >> 0)  & 0xFF;
	array[1] = (data >> 8)  & 0xFF;
	array[2] = (data >> 16) & 0xFF;
}

void printTXMsg(CAN_TxHeaderTypeDef *TxHd, uint8_t *data){
	char str;
	char *pStr=&str;
	printf("TX\tID: 0x%.2X\tDLC: %i\tData: ",TxHd->StdId,TxHd->DLC);
	//printf("TX%.2X%i\n",TxHd->StdId,TxHd->DLC);
	for(int i=0;i<TxHd->DLC;i++){
		printf(" %.2X",data[i]);
	}
	printf("\n");
	//snprintf(pStr,27,"TX%.4X%.4X%.2X%.2X%.2X%.2X%.2X%.2X%.2X%.2X",TxHd->StdId,TxHd->DLC,*data,*(data+1),*(data+2),*(data+3),*(data+4),*(data+5),*(data+6),*(data+7));
	//printf("%s",pStr);
}

void printRXMsg(CAN_RxHeaderTypeDef *RxHd, uint8_t *data){
	printf("RX\tID: 0x%.2X\tDLC: %i\tData: ",RxHd->StdId,RxHd->DLC);
	
	for(int i=0;i<RxHd->DLC;i++){
		printf(" %.2X",data[i]);
	}
	printf("\r\n");
	
}

void uart_read_line(UART_HandleTypeDef * handler, char * buffer, uint16_t buffer_size) {
       HAL_StatusTypeDef status;
       char current_char;
       uint16_t char_counter = 0;
 
       while (char_counter < buffer_size - 1) {
             status = HAL_UART_Receive(handler, &current_char, 1, 1);
             if (status == HAL_OK) {
                    if (current_char == '\r' || current_char == '\n')
                           if (char_counter == 0) 
														 continue; 
													 else 
														 break;
                    *(buffer + char_counter++) = current_char;
             }
       }
 
       *(buffer + char_counter) = '\0';
			 printf("%s - b", buffer);
}
