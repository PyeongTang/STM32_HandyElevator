/*
 * led.c
 *
 *  Created on: Jul 22, 2024
 *      Author: Lee JaePyeong
 */


#include "led.h"

LED led[8] = {0,};

void LED_init(){

	led[0].gpioPort		=GPIOA;
	led[0].pinNumber	=GPIO_PIN_5;
	led[0].ledState		=false;
	led[0].onState		=GPIO_PIN_SET;
	led[0].offState		=GPIO_PIN_RESET;


	led[1].gpioPort		=GPIOA;
	led[1].pinNumber	=GPIO_PIN_6;
	led[1].ledState		=false;
	led[1].onState		=GPIO_PIN_SET;
	led[1].offState		=GPIO_PIN_RESET;


	led[2].gpioPort		=GPIOA;
	led[2].pinNumber	=GPIO_PIN_7;
	led[2].ledState		=false;
	led[2].onState		=GPIO_PIN_SET;
	led[2].offState		=GPIO_PIN_RESET;


	led[3].gpioPort		=GPIOB;
	led[3].pinNumber	=GPIO_PIN_6;
	led[3].ledState		=false;
	led[3].onState		=GPIO_PIN_SET;
	led[3].offState		=GPIO_PIN_RESET;


	led[4].gpioPort		=GPIOC;
	led[4].pinNumber	=GPIO_PIN_7;
	led[4].ledState		=false;
	led[4].onState		=GPIO_PIN_SET;
	led[4].offState		=GPIO_PIN_RESET;


	led[5].gpioPort		=GPIOA;
	led[5].pinNumber	=GPIO_PIN_9;
	led[5].ledState		=false;
	led[5].onState		=GPIO_PIN_SET;
	led[5].offState		=GPIO_PIN_RESET;


	led[6].gpioPort		=GPIOA;
	led[6].pinNumber	=GPIO_PIN_8;
	led[6].ledState		=false;
	led[6].onState		=GPIO_PIN_SET;
	led[6].offState		=GPIO_PIN_RESET;


	led[7].gpioPort		=GPIOB;
	led[7].pinNumber	=GPIO_PIN_10;
	led[7].ledState		=false;
	led[7].onState		=GPIO_PIN_SET;
	led[7].offState		=GPIO_PIN_RESET;
};

void LED_on(uint8_t ch){
	if (ch > LED_MAX_CH) return;
	HAL_GPIO_WritePin(led[ch].gpioPort, led[ch].pinNumber, led[ch].onState);
	led[ch].ledState = true;
};


void LED_off(uint8_t ch){
	if (ch > LED_MAX_CH) return;
	HAL_GPIO_WritePin(led[ch].gpioPort, led[ch].pinNumber, led[ch].offState);
	led[ch].ledState = false;
};

void LED_rightShift(){
	for (int var = LED_MAX_CH - 1; var >= 0; --var) {
		if (led[var].ledState){
			if (var == 0){
				LED_on(7);
			}
			else{
				LED_on(var - 1);
			}
			LED_off(var);
			var--;
		}
	}
};

void LED_leftShift(){
	for (int var = 0; var < LED_MAX_CH; ++var) {
		if (led[var].ledState){
			LED_on((var + 1) % 8);
			LED_off(var);
			var++;
		}
	}
};

void LED_allOn(){
	for (int var = 0; var < LED_MAX_CH; ++var) {
		LED_on(var);
	}
};

void LED_allOff(){
	for (int var = 0; var < LED_MAX_CH; ++var) {
		LED_off(var);
	}
};

void LED_toggle(uint8_t ch){
	if (ch > LED_MAX_CH) return;
	HAL_GPIO_TogglePin(led[ch].gpioPort, led[ch].pinNumber);
};

void LED_leftSlideOn(uint8_t blinkDelay){
	for (int var = 0; var < LED_MAX_CH; ++var) {
		LED_on(var);
		delay(blinkDelay);
	}
};


void LED_rightSlideOn(uint8_t blinkDelay){
	for (int var = 7; var > 0; --var) {
		LED_on(var);
		delay(blinkDelay);
	}
};

void LED_leftSlideOff(uint8_t blinkDelay){
	for (int var = 0; var < LED_MAX_CH; ++var) {
		LED_off(var);
		delay(blinkDelay);
	}
};


void LED_leftShiftOn(uint8_t startPoint, uint8_t endPoint, uint8_t blinkDelay){
	if (endPoint > LED_MAX_CH) return;
	int var = 0;
	for (var = startPoint; var <= endPoint; ++var){
		if (var == startPoint){
			LED_on(var);
		}
		else{
			LED_off(var - 1);
			LED_on(var);
		}
		delay(blinkDelay);
	}
	LED_off(endPoint);
};

void LED_rightShiftOn(uint8_t startPoint, uint8_t endPoint, uint8_t blinkDelay){
	if (startPoint > LED_MAX_CH) return;
	int var = 0;
	for (var = startPoint; var >= endPoint; --var){
		if (var == startPoint){
			LED_on(var);
		}
		else{
			LED_off(var + 1);
			LED_on(var);
		}
		delay(blinkDelay);
	}
	LED_off(endPoint);
};

void LED_flower(){
	LED_leftShiftOn (4, 5, 10); LED_rightShiftOn(3, 2, 10);
	LED_leftShiftOn (5, 6, 10); LED_rightShiftOn(2, 1, 10);
	LED_leftShiftOn (6, 7, 10); LED_rightShiftOn(1, 0, 10);
}
