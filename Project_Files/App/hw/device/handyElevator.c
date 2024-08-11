/*
 * handyElevator.c
 *
 *  Created on: Jul 25, 2024
 *      Author: Lee JaePyeong
 */


#include "handyElevator.h"

extern STEP step;

uint8_t currentFloor;
uint8_t nextFloor;
bool floorQueue[4];

void HE_init(){
	currentFloor = FLOOR_1;
	nextFloor = FLOOR_1;
	floorQueue[0] = false;
	floorQueue[1] = false;
	floorQueue[2] = false;
	floorQueue[3] = false;
	STEP_init();
	HE_ledControl();
};

void HE_ledControl(){
	HAL_GPIO_WritePin(LED_1_GPIO_CH, LED_1_Pin, floorQueue[0]);
	HAL_GPIO_WritePin(LED_2_GPIO_CH, LED_2_Pin, floorQueue[1]);
	HAL_GPIO_WritePin(LED_3_GPIO_CH, LED_3_Pin, floorQueue[2]);
	HAL_GPIO_WritePin(LED_4_GPIO_CH, LED_4_Pin, floorQueue[3]);
}

void HE_enqueue(uint8_t floorNumber){
	floorQueue[floorNumber - 1] = true;
}

void HE_dequeue(uint8_t floorNumber){
	floorQueue[floorNumber - 1] = false;
}

void HE_searchNearestFloor(){
	uint8_t minDistance = 4; // Start as maximum value + 1. if 3, 1 -> 4 ignored
	uint8_t queuedFloor = 0;
	uint8_t difference = 0;
	for (int var = 0; var < 4; ++var) {
//
		if (floorQueue[var]){
			queuedFloor = var + 1;
			difference = HW_abs(currentFloor, queuedFloor);
			if 		(difference == minDistance || difference == 0){
//					Minimum Distance in floorQueue already exists
//					Updating and determining of nextFloor should be ignored
//					Just after arriving to desired nextFloor, search NN again
			}
			else if (difference < minDistance){
				minDistance = difference;
				nextFloor = queuedFloor;
			}
		}
	}
}

void HE_run(){
	if 		(currentFloor > nextFloor){
		STEP_unitStepCCW();
	}
	else if (currentFloor < nextFloor){
		STEP_unitStepCW();
	}
	FND_setDecimal(currentFloor);
}
