/*
 * CanBus.cpp
 *
 *  Created on: Jul 27, 2024
 *      Author: umutsar
 */

#include "RingBuffer.h"

RingBuffer::RingBuffer(uint16_t _bufferSize) {
	bufferSize = _bufferSize;
	writeIndex = 0;
	readIndex = 0;
    buffer = new uint8_t[bufferSize];
}


bool RingBuffer::write(uint8_t value) {
    if ((writeIndex + 1) % bufferSize != readIndex) {
        buffer[writeIndex] = value;
        writeIndex = (writeIndex + 1) % bufferSize;
        return true;
    } else {
        return false;
    }
}

int RingBuffer::read() {
    if (readIndex != writeIndex) {
        uint8_t readValue = buffer[readIndex];
        readIndex = (readIndex + 1) % bufferSize;
        return readValue;
    } else {
        return -1;
    }
}

RingBuffer::~RingBuffer() {
    delete[] buffer;
}
