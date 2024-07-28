/*
 * Nextion.h
 *
 *  Created on: Jul 27, 2024
 *      Author: umutsar
 */

#ifndef SRC_EXTERNAL_NEXTION_H_
#define SRC_EXTERNAL_NEXTION_H_

#include "usart.h"
#include <cstdio>
#include <cstdint>

class Nextion {
private:
	UART_HandleTypeDef *huartNumber = &huart1;
	uint8_t Cmd_End[3] = {0xFF, 0xFF, 0xFF};
public:
	Nextion(UART_HandleTypeDef *huart);

	void NextionSendString(char *Id, char *String);
	void NextionSendNumber(char *Id, int number);
	void NextionSetVisibility(char *Id, int visibility);

	virtual ~Nextion();
};

#endif /* SRC_EXTERNAL_NEXTION_H_ */
  
