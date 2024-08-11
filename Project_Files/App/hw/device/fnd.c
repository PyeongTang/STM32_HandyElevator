/*
 * fnd.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Lee JaePyeong
 */

#include "fnd.h"

FND fnd[8] = {0,};
uint8_t fndDigitValue = 0;

void FND_init (){
	fndDigitValue 		=0;
	fnd[0].gpioPort		=GPIOA;
	fnd[0].pinNumber	=GPIO_PIN_5;
	fnd[0].fndState		=false;
	fnd[0].onState		=GPIO_PIN_SET;
	fnd[0].offState		=GPIO_PIN_RESET;


	fnd[1].gpioPort		=GPIOA;
	fnd[1].pinNumber	=GPIO_PIN_6;
	fnd[1].fndState		=false;
	fnd[1].onState		=GPIO_PIN_SET;
	fnd[1].offState		=GPIO_PIN_RESET;


	fnd[2].gpioPort		=GPIOA;
	fnd[2].pinNumber	=GPIO_PIN_7;
	fnd[2].fndState		=false;
	fnd[2].onState		=GPIO_PIN_SET;
	fnd[2].offState		=GPIO_PIN_RESET;


	fnd[3].gpioPort		=GPIOB;
	fnd[3].pinNumber	=GPIO_PIN_6;
	fnd[3].fndState		=false;
	fnd[3].onState		=GPIO_PIN_SET;
	fnd[3].offState		=GPIO_PIN_RESET;


	fnd[4].gpioPort		=GPIOC;
	fnd[4].pinNumber	=GPIO_PIN_7;
	fnd[4].fndState		=false;
	fnd[4].onState		=GPIO_PIN_SET;
	fnd[4].offState		=GPIO_PIN_RESET;


	fnd[5].gpioPort		=GPIOA;
	fnd[5].pinNumber	=GPIO_PIN_9;
	fnd[5].fndState		=false;
	fnd[5].onState		=GPIO_PIN_SET;
	fnd[5].offState		=GPIO_PIN_RESET;


	fnd[6].gpioPort		=GPIOA;
	fnd[6].pinNumber	=GPIO_PIN_8;
	fnd[6].fndState		=false;
	fnd[6].onState		=GPIO_PIN_SET;
	fnd[6].offState		=GPIO_PIN_RESET;


	fnd[7].gpioPort		=GPIOB;
	fnd[7].pinNumber	=GPIO_PIN_10;
	fnd[7].fndState		=false;
	fnd[7].onState		=GPIO_PIN_SET;
	fnd[7].offState		=GPIO_PIN_RESET;
};

void FND_setMiddleBar(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].offState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].offState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].offState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].offState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].offState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].onState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
}

void FND_setUnderBar(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].offState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].offState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].offState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].onState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].offState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].offState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
}

void FND_setDecimal(uint8_t bcdValue){
	if (bcdValue > 9) return;

	fndDigitValue = bcdValue;
	switch (bcdValue){
		case 0 : FND_setFND_0(); break;
		case 1 : FND_setFND_1(); break;
		case 2 : FND_setFND_2(); break;
		case 3 : FND_setFND_3(); break;
		case 4 : FND_setFND_4(); break;
		case 5 : FND_setFND_5(); break;
		case 6 : FND_setFND_6(); break;
		case 7 : FND_setFND_7(); break;
		case 8 : FND_setFND_8(); break;
		case 9 : FND_setFND_9(); break;
	}
};

void FND_incDigit(){
	if (fndDigitValue >= 9)	{fndDigitValue = 0;}
	else					{fndDigitValue++;}
	FND_setDecimal(fndDigitValue);
}

void FND_decDigit(){
	if (fndDigitValue <= 0)	{fndDigitValue = 9;}
	else					{fndDigitValue--;}
	FND_setDecimal(fndDigitValue);
}

void FND_off(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].offState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].offState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].offState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].offState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].offState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].offState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_0(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].onState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].onState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].onState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].onState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].onState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].offState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_1(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].offState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].onState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].offState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].offState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].offState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_2(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].onState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].onState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].offState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].onState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].onState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].offState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].onState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_3(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].onState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].onState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].onState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].offState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].onState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_4(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].offState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].onState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].offState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].onState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].onState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_5(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].onState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].offState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].onState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].onState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].onState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_6(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].onState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].offState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].onState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].onState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].onState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].onState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_7(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].onState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].onState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].offState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].offState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].offState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_8(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].onState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].onState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].onState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].onState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].onState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].onState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};

void FND_setFND_9(){
	HAL_GPIO_WritePin(fnd[0].gpioPort, fnd[0].pinNumber, fnd[0].onState);
	HAL_GPIO_WritePin(fnd[1].gpioPort, fnd[1].pinNumber, fnd[1].onState);
	HAL_GPIO_WritePin(fnd[2].gpioPort, fnd[2].pinNumber, fnd[2].onState);
	HAL_GPIO_WritePin(fnd[3].gpioPort, fnd[3].pinNumber, fnd[3].onState);
	HAL_GPIO_WritePin(fnd[4].gpioPort, fnd[4].pinNumber, fnd[4].offState);
	HAL_GPIO_WritePin(fnd[5].gpioPort, fnd[5].pinNumber, fnd[5].onState);
	HAL_GPIO_WritePin(fnd[6].gpioPort, fnd[6].pinNumber, fnd[6].onState);
	HAL_GPIO_WritePin(fnd[7].gpioPort, fnd[7].pinNumber, fnd[7].offState);
};
