/*
 * delay.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Lee JaePyeong
 */

#include "delay.h"

void delay_us (uint16_t us){
	__HAL_TIM_SET_COUNTER(&htim10, 0);			// Reset Timer/Counter10
	HAL_TIM_Base_Start(&htim10);				// Start Timer/Counter10
	while(__HAL_TIM_GET_COUNTER(&htim10) < us){	// Compare Timer/Counter10 Value
		;
	}
	HAL_TIM_Base_Stop(&htim10);					// Stop Timer/Counter10
};
