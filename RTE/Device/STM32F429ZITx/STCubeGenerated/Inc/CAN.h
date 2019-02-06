/*
 * CAN.h
 *
 *  Created on: 12.01.2019
 *      Author: Justyna
 */

#ifndef CAN_H_
#define CAN_H_
#include "stm32f4xx_hal.h"

extern CAN_HandleTypeDef hcan1;

extern CAN_TxHeaderTypeDef TxHd;
extern CAN_RxHeaderTypeDef RxHd;
extern uint32_t TxMailBox;
extern CAN_FilterTypeDef sFilterConfig;
extern uint8_t TxData;
extern uint8_t RxData[8];


void CanMessageDefinitionSTD(CAN_TxHeaderTypeDef *TxHd,uint32_t DLC, uint32_t STDid);
void CanMessageDefinitionEXT(CAN_TxHeaderTypeDef *TxHd,uint32_t DLC, uint32_t EXTid);
void CanFilterConfigALL(CAN_FilterTypeDef *sFilterConfig);
HAL_StatusTypeDef CanSendMsg(CAN_TxHeaderTypeDef *TxHd, uint8_t *TxData);
#endif /* CAN_H_ */
