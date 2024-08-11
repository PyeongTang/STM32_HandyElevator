/*
 * stepMotor.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Lee JaePyeong
 */

#ifndef HW_DEVICE_STEPMOTOR_H_
#define HW_DEVICE_STEPMOTOR_H_

#include "hw.h"
#include "delay.h"

#define STEPS_PER_REVOLUTION		4096
#define MAX_STEP_NUM				7

typedef enum{
	STEP_DIR_CW = 0,
	STEP_DIR_CCW
} STEP_DIRECTION;

typedef struct{
	GPIO_TypeDef* 	gpioPort;
	uint16_t		pinIN1;
	uint16_t		pinIN2;
	uint16_t		pinIN3;
	uint16_t		pinIN4;
	uint8_t			currentStep;
	STEP_DIRECTION	direction;
} STEP;

static const uint8_t HALF_STEP_SEQ[8][4] = {
//		IN1  IN2 IN3 IN4
		{1,  0,  0,  0},	// SEQ 1
		{1,  1,  0,  0},	// SEQ 2
		{0,  1,  0,  0},	// SEQ 3
		{0,  1,  1,  0},	// SEQ 4
		{0,  0,  1,  0},	// SEQ 5
		{0,  0,  1,  1},	// SEQ 6
		{0,  0,  0,  1},	// SEQ 7
		{1,  0,  0,  1}	    // SEQ 8
};

void STEP_init();
void STEP_setStep(uint8_t step);
void STEP_unitStepCW();
void STEP_unitStepCCW();
void STEP_rotateStep(uint16_t steps);
void STEP_setAngle(uint16_t angle);

#endif /* HW_DEVICE_STEPMOTOR_H_ */
