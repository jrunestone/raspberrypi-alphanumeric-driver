raspberrypi-alphanumeric-driver
===============================
A Raspberry Pi version of SparkFun's original alphanumeric display driver for the Arduino, using WiringPi.

**Version 1.0**

By Johan Johansson (https://github.com/swemaniac/raspberrypi-alphanumeric-driver)

Resources:

* https://github.com/dubhunter/AlphaNumeric_Driver
* http://wiringpi.com/
* https://www.sparkfun.com/products/10103

Usage
-----
You will need:

* Raspberry Pi rev2
* Serial Alphanumeric Display Driver card (https://www.sparkfun.com/products/10103)
* Sparkfun 1.0" Single Digit Alphanumeric Display (https://www.sparkfun.com/products/9932)

First thing is to install the Wiring Pi library on your Raspberry. See http://wiringpi.com/download-and-install/ for instructions.

Solder your display onto the driver card and then wire it up to your Raspberry (5v, GND) on GPIO ports of your choice (headers 11, 12, 13, 15 for example).
Take note of the WiringPi numbering of the GPIO ports (0-based) because that's what's used to configure the driver (not the original GPIO numberings).
So for headers 11, 12, 13, 15 the WiringPi numbers are 0, 1, 2, 3.

Here's a pinout with all the numberings: http://wiringpi.com/pins/.

Then for the code, see AlphanumericDriverExample.cpp. It's really very simple :)
You can also daisy chain multiple driver cards, just make sure to set the NUM_DISPLAYS constant accordingly.

Build
-----
Compile with `g++ -Wall -o example AlphanumericDriverExample.cpp AlphanumericDriver.cpp -lwiringPi`.

License
-------
Do whatever you want with it, link to my github repo if you feel like it :)