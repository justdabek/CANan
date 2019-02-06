#include "CAN.h"
//#include "bt_uart.h"

extern uint8_t *arrayID;

void printTXMsg(CAN_TxHeaderTypeDef *TxHd, uint8_t *data);
void u32ToArr(uint32_t data, uint8_t *array);
void printRXMsg(CAN_RxHeaderTypeDef *RxHd, uint8_t *data);
void uart_read_line(UART_HandleTypeDef * handler, char * buffer, uint16_t buffer_size);