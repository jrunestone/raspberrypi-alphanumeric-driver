/**
 * AlphanumericSegments.h
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

#ifndef ALPHANUMERIC_SEGMENTS_H
#define ALPHANUMERIC_SEGMENTS_H

// THE FOLLOWING DEFINES ARE SHAMELESSLY STOLEN FROM THE ORIGINAL SPARKFUN DRIVER

#define D2_SEG	7	//	2		5
#define D1_SEG	10 	//	22		18
#define E_SEG	11	//	21		17
#define F_SEG	13	//	16		15
#define A2_SEG	2	//	10		10
#define A1_SEG	15	//	14		13
#define B_SEG	3	//	9		9
#define C_SEG	5	//	4		7
#define G2_SEG	4	//	7		8
#define G1_SEG	12	//	19		16
#define L_SEG	6	//	3		6
#define M_SEG	8	//	24		20
#define N_SEG	9	//	23		19
#define H_SEG	14	//	15		14
#define J_SEG	0	//	12		12
#define K_SEG	1	//	11		11

#define A_CHAR (1<<G1_SEG)+(1<<G2_SEG)+(1<<E_SEG)+(1<<F_SEG)+(1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<C_SEG)
#define B_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<C_SEG)+(1<<D2_SEG)+(1<<D1_SEG)+(1<<M_SEG)+(1<<J_SEG)+(1<<G1_SEG)+(1<<G2_SEG)
#define C_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<D2_SEG)+(1<<D1_SEG)+(1<<E_SEG)+(1<<F_SEG)
#define D_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<C_SEG)+(1<<D2_SEG)+(1<<D1_SEG)+(1<<M_SEG)+(1<<J_SEG)
#define E_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<D2_SEG)+(1<<D1_SEG)+(1<<E_SEG)+(1<<F_SEG)+(1<<G1_SEG)+(1<<G2_SEG)
#define F_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<F_SEG)+(1<<G1_SEG)+(1<<E_SEG)
#define G_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<F_SEG)+(1<<E_SEG)+(1<<D1_SEG)+(1<<D2_SEG)+(1<<C_SEG)+(1<<G2_SEG)
#define H_CHAR (1<<F_SEG)+(1<<E_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<B_SEG)+(1<<C_SEG)
#define I_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<J_SEG)+(1<<M_SEG)+(1<<D1_SEG)+(1<<D2_SEG)
#define J_CHAR (1<<B_SEG)+(1<<C_SEG)+(1<<D1_SEG)+(1<<D2_SEG)
#define K_CHAR (1<<F_SEG)+(1<<E_SEG)+(1<<G1_SEG)+(1<<K_SEG)+(1<<L_SEG)
#define L_CHAR (1<<F_SEG)+(1<<E_SEG)+(1<<D1_SEG)+(1<<D2_SEG)
#define M_CHAR (1<<E_SEG)+(1<<F_SEG)+(1<<H_SEG)+(1<<K_SEG)+(1<<B_SEG)+(1<<C_SEG)
#define N_CHAR (1<<E_SEG)+(1<<F_SEG)+(1<<H_SEG)+(1<<L_SEG)+(1<<C_SEG)+(1<<B_SEG)
#define O_CHAR (1<<F_SEG)+(1<<E_SEG)+(1<<D1_SEG)+(1<<D2_SEG)+(1<<C_SEG)+(1<<B_SEG)+(1<<A2_SEG)+(1<<A1_SEG)
#define P_CHAR (1<<E_SEG)+(1<<F_SEG)+(1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<G2_SEG)+(1<<G1_SEG)
#define Q_CHAR (1<<F_SEG)+(1<<E_SEG)+(1<<D1_SEG)+(1<<D2_SEG)+(1<<C_SEG)+(1<<B_SEG)+(1<<A2_SEG)+(1<<A1_SEG)+(1<<L_SEG)
#define R_CHAR (1<<E_SEG)+(1<<F_SEG)+(1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<L_SEG)
#define S_CHAR (1<<A2_SEG)+(1<<A1_SEG)+(1<<F_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<C_SEG)+(1<<D2_SEG)+(1<<D1_SEG)
#define T_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<J_SEG)+(1<<M_SEG)
#define U_CHAR (1<<F_SEG)+(1<<E_SEG)+(1<<D1_SEG)+(1<<D2_SEG)+(1<<C_SEG)+(1<<B_SEG)
#define V_CHAR (1<<F_SEG)+(1<<E_SEG)+(1<<N_SEG)+(1<<K_SEG)
#define W_CHAR (1<<F_SEG)+(1<<E_SEG)+(1<<N_SEG)+(1<<L_SEG)+(1<<C_SEG)+(1<<B_SEG)
#define X_CHAR (1<<H_SEG)+(1<<N_SEG)+(1<<L_SEG)+(1<<K_SEG)
#define Y_CHAR (1<<H_SEG)+(1<<K_SEG)+(1<<M_SEG)
#define Z_CHAR (1<<A1_SEG)+(1<<A2_SEG)+(1<<K_SEG)+(1<<N_SEG)+(1<<D1_SEG)+(1<<D2_SEG)

#define ONE (1<<B_SEG)+(1<<C_SEG)
#define TWO (1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<E_SEG)+(1<<D1_SEG)+(1<<D2_SEG)
#define THREE (1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<G2_SEG)+(1<<C_SEG)+(1<<D2_SEG)+(1<<D1_SEG)
#define FOUR (1<<F_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<B_SEG)+(1<<C_SEG)
#define FIVE (1<<A1_SEG)+(1<<A2_SEG)+(1<<F_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<C_SEG)+(1<<D2_SEG)+(1<<D1_SEG)
#define SIX (1<<A2_SEG)+(1<<A1_SEG)+(1<<F_SEG)+(1<<G2_SEG)+(1<<G1_SEG)+(1<<C_SEG)+(1<<D2_SEG)+(1<<D1_SEG)+(1<<E_SEG)
#define SEVEN (1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<C_SEG)
#define EIGHT (1<<A1_SEG)+(1<<A2_SEG)+(1<<F_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<B_SEG)+(1<<C_SEG)+(1<<D2_SEG)+(1<<D1_SEG)+(1<<E_SEG)
#define NINE (1<<A1_SEG)+(1<<A2_SEG)+(1<<F_SEG)+(1<<B_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<C_SEG)
#define ZERO (1<<F_SEG)+(1<<E_SEG)+(1<<D1_SEG)+(1<<D2_SEG)+(1<<C_SEG)+(1<<B_SEG)+(1<<A2_SEG)+(1<<A1_SEG)

#define EXCLAMATION (1<<B_SEG)+(1<<C_SEG)
#define ATSIGN (1<<D2_SEG)+(1<<D1_SEG)+(1<<E_SEG)+(1<<F_SEG)+(1<<A1_SEG)+(1<<A2_SEG)+(1<<B_SEG)+(1<<G2_SEG)+(1<<J_SEG)
#define DOLLAR (1<<A2_SEG)+(1<<A1_SEG)+(1<<F_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<C_SEG)+(1<<D2_SEG)+(1<<D1_SEG)+(1<<J_SEG)+(1<<M_SEG)
#define PERCENT (1<<A1_SEG)+(1<<F_SEG)+(1<<G1_SEG)+(1<<J_SEG)+(1<<G2_SEG)+(1<<M_SEG)+(1<<D2_SEG)+(1<<C_SEG)+(1<<N_SEG)+(1<<K_SEG)
#define CARROT (1<<K_SEG)+(1<<N_SEG)+(1<<A2_SEG)+(1<<B_SEG)
#define AMPERSAND (1<<A2_SEG)+(1<<J_SEG)+(1<<K_SEG)+(1<<N_SEG)+(1<<D1_SEG)+(1<<M_SEG)+(1<<D2_SEG)+(1<<C_SEG)
#define ASTERISK (1<<J_SEG)+(1<<H_SEG)+(1<<G1_SEG)+(1<<N_SEG)+(1<<M_SEG)+(1<<L_SEG)+(1<<G2_SEG)+(1<<K_SEG)
#define LPAREN (1<<K_SEG)+(1<<L_SEG)
#define RPAREN (1<<H_SEG)+(1<<N_SEG)
#define MINUS (1<<G1_SEG)+(1<<G2_SEG)
#define UNDERSCORE (1<<D1_SEG)+(1<<D2_SEG)
#define PLUSYSIGN (1<<J_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<M_SEG)
#define EQUALS (1<<G1_SEG)+(1<<G2_SEG)+(1<<D1_SEG)+(1<<D2_SEG)

#define PERIOD (1<<G1_SEG)+(1<<M_SEG)+(1<<D1_SEG)+(1<<E_SEG)
#define COLON (1<<J_SEG)+(1<<M_SEG)
#define SEMICOLON (1<<J_SEG)+(1<<N_SEG)
#define LARROW (1<<K_SEG)+(1<<L_SEG)
#define RARROW (1<<H_SEG)+(1<<N_SEG)
#define COMMA (1<<N_SEG)
#define FSLASH (1<<N_SEG)+(1<<K_SEG)
#define BSLASH (1<<H_SEG)+(1<<L_SEG)
#define SINGLEQUOTE (1<<K_SEG)
#define DOUBLEQUOTE (1<<J_SEG)+(1<<F_SEG)
#define LBRACKET (1<<A2_SEG)+(1<<J_SEG)+(1<<M_SEG)+(1<<D2_SEG)
#define RIBRACKET (1<<A1_SEG)+(1<<J_SEG)+(1<<M_SEG)+(1<<D1_SEG)
#define LECURLY (1<<A1_SEG)+(1<<J_SEG)+(1<<M_SEG)+(1<<D1_SEG)+(1<<G2_SEG)
#define RICURLY (1<<G1_SEG)+(1<<A2_SEG)+(1<<J_SEG)+(1<<M_SEG)+(1<<D2_SEG)
#define PIPE (1<<J_SEG)+(1<<M_SEG)
#define TILDE (1<<E_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<B_SEG)
#define APOSTROPHE (1<<H_SEG)
#define QUESTIONMARK (1<<M_SEG)+(1<<G2_SEG)+(1<<B_SEG)+(1<<A2_SEG)
#define POUNDSIGN 0xFFFF

#endif