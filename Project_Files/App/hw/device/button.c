/*
 * button.c
 *
 *  Created on: Jul 22, 2024
 *      Author: Lee JaePyeong
 */


#include "button.h"

BUTTON btn[3] = {0,};

void BUTTON_init(){
	btn[0].gpioPort			=GPIOB;
	btn[0].pinNumber		=GPIO_PIN_5;
	btn[0].pushedState		=GPIO_PIN_RESET;
	btn[0].releasedState	=GPIO_PIN_SET;


	btn[1].gpioPort			=GPIOB;
	btn[1].pinNumber		=GPIO_PIN_3;
	btn[1].pushedState		=GPIO_PIN_RESET;
	btn[1].releasedState	=GPIO_PIN_SET;


	btn[2].gpioPort			=GPIOA;
	btn[2].pinNumber		=GPIO_PIN_10;
	btn[2].pushedState		=GPIO_PIN_RESET;
	btn[2].releasedState	=GPIO_PIN_SET;
};

bool BUTTON_getState(uint8_t ch){
	if (ch > BTN_MAX_CH) return false;
	return !(HAL_GPIO_ReadPin(btn[ch].gpioPort, btn[ch].pinNumber));
}
