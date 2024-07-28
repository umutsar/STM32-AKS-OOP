/*
 * CanBus.cpp
 *
 *  Created on: Jul 27, 2024
 *      Author: umutsar
 */

#include "CanBus.h"

CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef receiver_structure;


CanBus::CanBus() {
	HAL_CAN_Start(&hcan);
	HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}


uint32_t getStdId() {
	return receiver_structure.StdId;
}

uint32_t getExtId() {
	return receiver_structure.ExtId;
}

uint32_t getIDE() {
	return receiver_structure.IDE;
}

uint32_t getRTR() {
	return receiver_structure.RTR;
}

uint32_t getDLC() {
	return receiver_structure.DLC;
}


void CanBus::Transmit(uint8_t* _TransmittedData, uint32_t size) {
    if (size > 8) size = 8;
    TxHeader.DLC = size;
    HAL_CAN_AddTxMessage(&hcan, &TxHeader, _TransmittedData, &TxMailbox);
}

uint8_t* CanBus::Receive() {
    static uint8_t RxData[8];

    if (HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &receiver_structure, RxData) == HAL_OK) {
        return RxData;
    } else {
    	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
        return nullptr;
    }
}

CanBus::~CanBus() {
}










