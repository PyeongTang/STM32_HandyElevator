/*
 * step.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Lee JaePyeong
 */


#include "stepMotor.h"

STEP step;
uint8_t nextStep;

void STEP_init(){
	step.gpioPort 		= GPIOC;
	step.pinIN1 		= GPIO_PIN_9;
	step.pinIN2 		= GPIO_PIN_8;
	step.pinIN3 		= GPIO_PIN_6;
	step.pinIN4 		= GPIO_PIN_5;
	step.direction		= STEP_DIR_CW;
	step.currentStep	= 0;
	nextStep 			= 0;
};

void STEP_setStep(uint8_t steps){
	HAL_GPIO_WritePin(step.gpioPort, step.pinIN1, HALF_STEP_SEQ[steps][0]);
	HAL_GPIO_WritePin(step.gpioPort, step.pinIN2, HALF_STEP_SEQ[steps][1]);
	HAL_GPIO_WritePin(step.gpioPort, step.pinIN3, HALF_STEP_SEQ[steps][2]);
	HAL_GPIO_WritePin(step.gpioPort, step.pinIN4, HALF_STEP_SEQ[steps][3]);
	step.currentStep = steps;
};

void STEP_unitStepCW(){
	if (nextStep == MAX_STEP_NUM){
		nextStep = 0;
	}
	else {
		nextStep++;
	}
	STEP_setStep(nextStep);
	delay_us(900);
};

void STEP_unitStepCCW(){
	if (nextStep == 0){
		nextStep = MAX_STEP_NUM;
	}
	else {
		nextStep--;
	}
	STEP_setStep(nextStep);
	delay_us(900);
};

void STEP_rotateStep(uint16_t steps){
	uint8_t temp_step = 0;
	for (int var = 0; var < steps; ++var) {
		if (step.direction == STEP_DIR_CW){
			temp_step = var % (MAX_STEP_NUM + 1);
		}
		else if (step.direction == STEP_DIR_CCW){
			temp_step = MAX_STEP_NUM - (var % (MAX_STEP_NUM + 1));
		}
		STEP_setStep(temp_step);
		delay_us(1000);								// Delay Between Each Steps
	}
}

void STEP_setAngle(uint16_t angle){
	uint16_t angle2Step = (uint16_t)(((uint32_t)angle * STEPS_PER_REVOLUTION) / 360);
	STEP_rotateStep(angle2Step);
};
