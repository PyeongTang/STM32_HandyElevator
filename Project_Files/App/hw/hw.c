/*
 * hw.c
 *
 *  Created on: Jul 22, 2024
 *      Author: Lee JaePyeong
 */

#include "hw.h"

//Declared at uart.c
//Declared Externally for initialize
extern uint8_t rxData;

void HW_init(){
	FND_init();
//	BUTTON_init();
	HE_init();
}

void delay(uint32_t time_ms){
	HAL_Delay(time_ms);
};

uint32_t millis(void){
	return HAL_GetTick();
};

uint8_t HW_abs(uint8_t x, uint8_t y){
	if (x >= y) return x - y;
	else 		return y - x;
}
