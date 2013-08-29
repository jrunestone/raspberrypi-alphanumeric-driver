/**
 * AlphanumericDriver.h
 *
 * A Raspberry Pi version of SparkFun's original alphanumeric display driver for the Arduino, using WiringPi.
 *
 * By Johan Johansson
 * https://github.com/swemaniac/raspberrypi-alphanumeric-driver
 *
 * https://github.com/dubhunter/AlphaNumeric_Driver
 * http://wiringpi.com/
 * https://www.sparkfun.com/products/10103
 *
 * License: Do whatever you want with it, link to my github repo if you feel like it :)
 */

#ifndef ALPHANUMERIC_DRIVER_H
#define ALPHANUMERIC_DRIVER_H

#include <stdint.h>

class AlphanumericDriver
{
private:
	int dataPin;
	int clockPin;
	int latchPin;
	int outputPin;
	int numDisplays;

	void shift16(uint16_t data);
	void shiftPart16(uint16_t data);
	uint16_t getShiftData(char c);

public:
	AlphanumericDriver(int dataPin, int clockPin, int latchPin, int outputPin, int numDisplays);

	void setup();
	void clear();
	void print(char c);
	void scroll(const char *string, int microSeconds);
};

#endif