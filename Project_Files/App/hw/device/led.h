/*
 * led.h
 *
 *  Created on: Jul 22, 2024
 *      Author: Lee JaePyeong
 */

#ifndef HW_DEVICE_LED_H_
#define HW_DEVICE_LED_H_

//Upper Layer
#include "hw.h"

//	PA5
//	PA6
//	PA7
//	PB6
//	PC7
//	PA9
//	PA8
//	PB10


typedef struct{
	GPIO_TypeDef* 	gpioPort;
	uint16_t 		pinNumber;
	bool			ledState;
	GPIO_PinState	onState;
	GPIO_PinState	offState;
} LED;

void LED_init();

void LED_on(uint8_t ch);
void LED_off(uint8_t ch);
void LED_allOn();
void LED_allOff();
void LED_rightShift();
void LED_leftShift();
void LED_toggle(uint8_t ch);
void LED_leftSlideOn(uint8_t blinkDelay);
void LED_rightSlideOn(uint8_t blinkDelay);
void LED_leftSlideOff(uint8_t blinkDelay);
void LED_leftShiftOn(uint8_t startPoint, uint8_t endPoint, uint8_t blinkDelay);
void LED_rightShiftOn(uint8_t startPoint, uint8_t endPoint, uint8_t blinkDelay);
void LED_flower();
#endif /* HW_DEVICE_LED_H_ */
