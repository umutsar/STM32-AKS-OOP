/*
 * Nextion.cpp
 *
 *  Created on: Jul 27, 2024
 *      Author: umutsar
 */

#include "Nextion.h"
Nextion::Nextion(UART_HandleTypeDef *huart) {
	huartNumber = huart;
}


void Nextion::NextionSendString(char *Id, char *String)
{
    char buf[70];
    int len = sprintf(buf, "%s.txt=\"%s\"", Id, String);
    HAL_UART_Transmit(huartNumber, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(huartNumber, Cmd_End, 3, 1000);
}


void Nextion::NextionSendNumber(char *Id, int number)
{
    char buf[50];
    int len = sprintf(buf, "%s.val=%d", Id, number);
    HAL_UART_Transmit(huartNumber, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(huartNumber, Cmd_End, 3, 1000);
}


void Nextion::NextionSetVisibility(char *Id, int visibility)
{
    char buf[50];
    int len = sprintf(buf, "vis %s,%d", Id, visibility);
    HAL_UART_Transmit(huartNumber, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(huartNumber, Cmd_End, 3, 1000);
}
Nextion::~Nextion() {

}

