/*
 * CanBus.h
 *
 *  Created on: Jul 27, 2024
 *      Author: superuser
 */

#ifndef SRC_EXTERNAL_CANBUS_H_
#define SRC_EXTERNAL_CANBUS_H_

#include "can.h"
#include <cstdint>

class CanBus {
private:
	uint32_t TxMailbox;
	uint8_t RxData[8];
public:
	CanBus();
	uint32_t getStdId();
	uint32_t getExtId();
	uint32_t getIDE();
	uint32_t getRTR();
	uint32_t getDLC();

	void Transmit(uint8_t* _TransmittedData, uint32_t size);
	uint8_t* Receive();

	virtual ~CanBus();
};

#endif /* SRC_EXTERNAL_CANBUS_H_ */
