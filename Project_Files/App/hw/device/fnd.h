/*
 * fnd.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Lee JaePyeong
 */

#ifndef HW_DEVICE_FND_H_
#define HW_DEVICE_FND_H_

#include "hw.h"
//Ahv Caroline
//글렌체크 Dive baby dive
//	DIGIT	SEGPIN		INPUT_PIN		COLOR
//	E		1			PC7				PURPLE
//	D		2			PB6				BLUE
//	220Ohm	3			-				-
//	C		4			PA7				GREEN
//	DP		5			PB10			YELLOW
//	B		6			PA6				BROWN
//	A		7			PA5				BLACK	`
//	NC		8			-				-
//	F		9			PA9				WHITE
//	G		10			PA8				GRAY

							//     .GFE_DCBA
							// 	   7654_3210
#define FND_0		0x3F	// 0 : 0011_1111
#define FND_1		0x06	// 1 : 0000_0110
#define FND_2		0x5B	// 2 : 0101_1011
#define FND_3		0x4F	// 3 : 0100_1111
#define FND_4		0x66	// 4 : 0110_0110
#define FND_5		0x6D	// 5 : 0110_1101
#define FND_6		0x7D	// 6 : 0111_1101
#define FND_7		0x07	// 7 : 0000_0111
#define FND_8		0x7F	// 8 : 0111_1111
#define FND_9		0x67	// 9 : 0110_1111

typedef struct{
	GPIO_TypeDef* 	gpioPort;
	uint16_t 		pinNumber;
	bool			fndState;
	GPIO_PinState	onState;
	GPIO_PinState	offState;
} FND;

void FND_init();
void FND_setMiddleBar();
void FND_setUnderBar();
void FND_setDecimal(uint8_t bcdValue);
void FND_incDigit();
void FND_decDigit();
void FND_off();
void FND_setFND_0();
void FND_setFND_1();
void FND_setFND_2();
void FND_setFND_3();
void FND_setFND_4();
void FND_setFND_5();
void FND_setFND_6();
void FND_setFND_7();
void FND_setFND_8();
void FND_setFND_9();

#endif /* HW_DEVICE_FND_H_ */
