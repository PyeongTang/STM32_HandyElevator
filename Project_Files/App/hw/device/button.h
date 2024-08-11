/*
 * button.h
 *
 *  Created on: Jul 22, 2024
 *      Author: Lee JaePyeong
 */

#ifndef HW_DEVICE_BUTTON_H_
#define HW_DEVICE_BUTTON_H_

//Upper Layer
#include "hw.h"

typedef struct{
	GPIO_TypeDef* 	gpioPort;
	uint16_t 		pinNumber;
	GPIO_PinState	pushedState;
	GPIO_PinState	releasedState;
}BUTTON;

void BUTTON_init();
bool BUTTON_getState(uint8_t ch);

#endif /* HW_DEVICE_BUTTON_H_ */
