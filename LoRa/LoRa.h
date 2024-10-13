/*
 * LoRa.h
 *
 *  Created on: Jul 28, 2024
 *      Author: umutsar
 */

#ifndef SRC_EXTERNAL_LORA_H_
#define SRC_EXTERNAL_LORA_H_

#include "usart.h"
#include <cstdio>
#include <cstdint>

class LoRa {
private:
	UART_HandleTypeDef *huartNumber = &huart3; // Default uart port, change it.
	uint8_t addr;
	uint8_t channel;
public:
	LoRa(UART_HandleTypeDef *huart, uint8_t _addr, uint8_t _channel);
	void Transmit(uint8_t* arr, uint16_t size);
	bool Receive(uint8_t* buffer, uint16_t size);
	virtual ~LoRa();
};

#endif /* SRC_EXTERNAL_LORA_H_ */
