/*
 * CAN.c
 *
 *  Created on: 12.01.2019
 *      Author: Justyna
 */
#include "stm32f4xx_hal_can.h"
#include "CAN.h"


void CanMessageDefinitionSTD(CAN_TxHeaderTypeDef *TxHd,uint32_t DLC, uint32_t STDid){
	  TxHd->DLC = DLC;
	  TxHd->ExtId = 0;
	  TxHd->IDE = CAN_ID_STD;
	  TxHd->RTR = CAN_RTR_DATA;
	  TxHd->StdId = STDid;
}

void CanMessageDefinitionEXT(CAN_TxHeaderTypeDef *TxHd,uint32_t DLC, uint32_t EXTid){
	  TxHd->DLC = DLC;
	  TxHd->ExtId = EXTid;
	  TxHd->IDE = CAN_ID_EXT;
	  TxHd->RTR = CAN_RTR_DATA;
	  TxHd->StdId = 0;
}

void CanFilterConfigALL(CAN_FilterTypeDef *sFilterConfig){
	  sFilterConfig->FilterMode = CAN_FILTERMODE_IDMASK;
	  sFilterConfig->FilterScale = CAN_FILTERSCALE_32BIT;
	  sFilterConfig->FilterIdHigh = 0x0000;
	  sFilterConfig->FilterIdLow = 0x0000;
	  sFilterConfig->FilterMaskIdHigh = 0x0000;
	  sFilterConfig->FilterMaskIdLow = 0x0000;
	  sFilterConfig->FilterFIFOAssignment = 0;
	  sFilterConfig->FilterActivation = ENABLE;
	  sFilterConfig->FilterBank = 14;
}

HAL_StatusTypeDef CanSendMsg(CAN_TxHeaderTypeDef *TxHd, uint8_t *TxData){
		return HAL_CAN_AddTxMessage(&hcan1, TxHd, TxData, &TxMailBox);  
}

