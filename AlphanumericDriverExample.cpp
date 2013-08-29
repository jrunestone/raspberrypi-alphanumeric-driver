/**
 * AlphanumericDriverExample.cpp
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

#include <wiringPi.h>
#include "AlphanumericDriver.h"

#define DATA_PIN 3 // SDI
#define CLOCK_PIN 2 // CLK
#define LATCH_PIN 1 // LE
#define OUTPUT_PIN 0 // OE
#define NUM_DISPLAYS 1

int main()
{
	wiringPiSetup();

	AlphanumericDriver *display = new AlphanumericDriver(DATA_PIN, CLOCK_PIN, LATCH_PIN, OUTPUT_PIN, NUM_DISPLAYS);

	display->setup();
	display->clear();

	// loop through 0-9 and A-Z
	for (int i = 48; i <= 90; i++)
	{
		// skip some special characters
		if (i > 57 && i < 65)
			continue;

		display->print((char)i);
		delayMicroseconds(500000);
	}

	// could do this too
	// display->scroll("HELLO!", 500000)

	delayMicroseconds(500000);
	display->clear();

	delete display;

	return 0;
}