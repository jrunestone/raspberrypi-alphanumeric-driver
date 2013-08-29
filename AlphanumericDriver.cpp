/**
 * AlphanumericDriver.cpp
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
#include <wiringShift.h>
#include <stdint.h>
#include <string.h>
#include <cstddef>

#include "AlphanumericDriver.h"
#include "AlphanumericSegments.h"

AlphanumericDriver::AlphanumericDriver(int dataPin, int clockPin, int latchPin, int outputPin, int numDisplays)
{
	this->dataPin = dataPin;
	this->clockPin = clockPin;
	this->latchPin = latchPin;
	this->outputPin = outputPin;
	this->numDisplays = numDisplays;
}

void AlphanumericDriver::setup()
{
	pinMode(dataPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(outputPin, OUTPUT);

	digitalWrite(dataPin, LOW);
	digitalWrite(clockPin, LOW);
	digitalWrite(latchPin, HIGH);
	digitalWrite(outputPin, LOW);
}

void AlphanumericDriver::clear()
{
	for (int i = 0; i < numDisplays; i++)
		shift16((uint16_t)0);
}

void AlphanumericDriver::print(char c)
{
	shift16(getShiftData(c));
}

void AlphanumericDriver::scroll(const char *string, int microSeconds)
{
	if (string != NULL)
	{
		int len = strlen(string);

		for (int i = 0; i < len; i++)
		{
			print(string[i]);
			delayMicroseconds(microSeconds);
		}
	}
}

void AlphanumericDriver::shift16(uint16_t data)
{
	shiftPart16(data >> 8);
	shiftPart16(data & 0x00FF);
}

void AlphanumericDriver::shiftPart16(uint16_t data)
{
	digitalWrite(latchPin, LOW);
	delayMicroseconds(1);

	shiftOut(dataPin, clockPin, MSBFIRST, data);

	digitalWrite(latchPin, HIGH);
	delayMicroseconds(1);
}

uint16_t AlphanumericDriver::getShiftData(char c)
{
	switch (c)
	{
		case '0':
		case 0:
			return ZERO;

		case '1':
		case 1:
			return ONE;

		case '2':
		case 2:
			return TWO;

		case '3':
		case 3:
			return THREE;

		case '4':
		case 4:
			return FOUR;

		case '5':
		case 5:
			return FIVE;

		case '6':
		case 6:
			return SIX;

		case '7':
		case 7:
			return SEVEN;

		case '8':
		case 8:
			return EIGHT;

		case '9':
		case 9:
			return NINE;

		case 'A':
		case 'a':
		case 10:
			return A_CHAR;

		case 'B':
		case 'b':
		case 11:
		  return B_CHAR;

		case 'C':
		case 'c':
		case 12:
			return C_CHAR;

		case 'D':
		case 'd':
		case 13:
			return D_CHAR;

		case 'E':
		case 'e':
		case 14:
			return E_CHAR;

		case 'F':
		case 'f':
		case 15:
			return F_CHAR;

		case 'G':
		case 'g':
			return G_CHAR;

		case 'H':
		case 'h':
			return H_CHAR;

		case 'I':
		case 'i':
			return I_CHAR;

		case 'J':
		case 'j':
			return J_CHAR;

		case 'K':
		case 'k':
			return K_CHAR;

		case 'L':
		case 'l':
			return L_CHAR;

		case 'M':
		case 'm':
			return M_CHAR;

		case 'N':
		case 'n':
			return N_CHAR;

		case 'O':
		case 'o':
			return O_CHAR;

		case 'P':
		case 'p':
			return P_CHAR;

		case 'Q':
		case 'q':
			return Q_CHAR;

		case 'R':
		case 'r':
			return R_CHAR;

		case 'S':
		case 's':
			return S_CHAR;

		case 'T':
		case 't':
			return T_CHAR;

		case 'U':
		case 'u':
			return U_CHAR;

		case 'V':
		case 'v':
			return V_CHAR;

		case 'W':
		case 'w':
			return W_CHAR;

		case 'X':
		case 'x':
			return X_CHAR;

		case 'Y':
		case 'y':
			return Y_CHAR;

		case 'Z':
		case 'z':
			return Z_CHAR;

		case ' ':
			return 0;

		case '!':
			return EXCLAMATION;

		case '#':
			return (uint16_t) 0xFFFF;

		case '$':
			return DOLLAR;

		case '%':
			return PERCENT;

		case '^':
			return CARROT;

		case '&':
			return AMPERSAND;

		case '*':
			return ASTERISK;

		case '(':
			return LPAREN;

		case ')':
			return RPAREN;

		case '-':
			return MINUS;

		case '_':
			return UNDERSCORE;

		case '+':
			return PLUSYSIGN;

		case '=':
			return EQUALS;

		case '>':
			return RARROW;

		case '<':
			return LARROW;

		case ',':
			return COMMA;

		case '/':
			return FSLASH;

		case '\\':
			return BSLASH;

		case '\'':
			return SINGLEQUOTE;

		case '"':
			return DOUBLEQUOTE;

		case 0X5B:
			return LBRACKET;

		case 0X5D:
			return RIBRACKET;

		case 0X7D:
			return LECURLY;

		case 0X7B:
			return RICURLY;

		case '|':
			return PIPE;

		case '~':
			return TILDE;

		case '`':
			return APOSTROPHE;

		case '@':
			return ATSIGN;

		case '?':
			return QUESTIONMARK;

		case ':':
			return COLON;

		case ';':
			return SEMICOLON;

		case '.':
			return PERIOD;

		default:
			break;
	}
}