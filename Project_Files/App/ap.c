/*
 * ap.c
 *
 *  Created on: Jul 22, 2024
 *      Author: Lee JaePyeong
 */

#include "ap.h"

void AP_setup(){
	HW_init();
};

void AP_loop(){
	while (1){
		HE_run();
	}
};
