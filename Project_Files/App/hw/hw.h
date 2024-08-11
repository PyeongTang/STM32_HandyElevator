/*
 * hw.h
 *
 *  Created on: Jul 22, 2024
 *      Author: Lee JaePyeong
 */

#ifndef HW_HW_H_
#define HW_HW_H_

//Upper Layer
#include "hw_def.h"

//Include Hardware Headers Here
#include "led.h"
//#include "button.h"
#include "fnd.h"
#include "stepMotor.h"
#include "handyElevator.h"

void HW_init();
void delay(uint32_t time_ms);
uint32_t millis(void);
uint8_t HW_abs(uint8_t x, uint8_t y);

#endif /* HW_HW_H_ */
