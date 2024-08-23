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


void Nextion::NextionSendString(const char *Id, const char *String) // char changed to const char
{
    char buf[70];
    int len = sprintf(buf, "%s.txt=\"%s\"", Id, String);
    HAL_UART_Transmit(huartNumber, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(huartNumber, Cmd_End, 3, 1000);
}


void Nextion::NextionSendNumber(const char *Id, int number) // char changed to const char
{
    char buf[50];
    int len = sprintf(buf, "%s.val=%d", Id, number);
    HAL_UART_Transmit(huartNumber, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(huartNumber, Cmd_End, 3, 1000);
}


void Nextion::NextionSetVisibility(const char *Id, int visibility) // char changed to const char
{
    char buf[50];
    int len = sprintf(buf, "vis %s,%d", Id, visibility);
    HAL_UART_Transmit(huartNumber, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(huartNumber, Cmd_End, 3, 1000);
}
Nextion::~Nextion() {

}

