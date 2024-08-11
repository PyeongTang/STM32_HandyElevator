/*
 * delay.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Lee JaePyeong
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include "stm32f4xx_hal.h"
#include "tim.h"

// Using Timer 10 (16-bit)
void delay_us (uint16_t us);

#endif /* INC_DELAY_H_ */
