/*
 * LoRa.cpp
 *
 *  Created on: Jul 28, 2024
 *      Author: umutsar
 */

#include "LoRa.h"

LoRa::LoRa(UART_HandleTypeDef *huart, uint8_t _addr, uint8_t _channel) {
	huartNumber = huart;
	addr = _addr;
	channel = _channel;
}

void LoRa::Transmit(uint8_t* arr, uint16_t size) {
    uint8_t header[3] = {0, addr, channel }; // Range 0-255.

    HAL_UART_Transmit(huartNumber, header, sizeof(header), 1000);
    HAL_UART_Transmit(huartNumber, arr, size, 1000);
}

bool LoRa::Receive(uint8_t* buffer, uint16_t size) {
    HAL_StatusTypeDef status = HAL_UART_Receive(huartNumber, buffer, size, 2000);
    return (status == HAL_OK);
}

LoRa::~LoRa() {

}
