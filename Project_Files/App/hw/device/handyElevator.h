/*
 * handyElevator.h
 *
 *  Created on: Jul 25, 2024
 *      Author: Lee JaePyeong
 */

#ifndef HW_DEVICE_HANDYELEVATOR_H_
#define HW_DEVICE_HANDYELEVATOR_H_

#include "hw.h"

typedef enum{
	FLOOR_NOT_DETERMINED = 0,
	FLOOR_1,
	FLOOR_2,
	FLOOR_3,
	FLOOR_4
} FLOORS;

typedef enum{
	DEV_MODE = 0,
	OP_MODE = 1
} MODES;

void HE_init();
void HE_ledControl();
void HE_enqueue(uint8_t floorNumber);
void HE_dequeue(uint8_t floorNumber);
void HE_searchNearestFloor();
void HE_run();

#endif /* HW_DEVICE_HANDYELEVATOR_H_ */
