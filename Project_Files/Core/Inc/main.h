/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PHOTO_INT_2_Pin GPIO_PIN_2
#define PHOTO_INT_2_GPIO_Port GPIOC
#define PHOTO_INT_2_EXTI_IRQn EXTI2_IRQn
#define PHOTO_INT_3_Pin GPIO_PIN_3
#define PHOTO_INT_3_GPIO_Port GPIOC
#define PHOTO_INT_3_EXTI_IRQn EXTI3_IRQn
#define BUTTON_INT_1_Pin GPIO_PIN_1
#define BUTTON_INT_1_GPIO_Port GPIOA
#define BUTTON_INT_1_EXTI_IRQn EXTI1_IRQn
#define BUTTON_INT_2_Pin GPIO_PIN_4
#define BUTTON_INT_2_GPIO_Port GPIOA
#define BUTTON_INT_2_EXTI_IRQn EXTI4_IRQn
#define FND_0_Pin GPIO_PIN_5
#define FND_0_GPIO_Port GPIOA
#define FND_1_Pin GPIO_PIN_6
#define FND_1_GPIO_Port GPIOA
#define FND_2_Pin GPIO_PIN_7
#define FND_2_GPIO_Port GPIOA
#define LED_4_Pin GPIO_PIN_4
#define LED_4_GPIO_Port GPIOC
#define STEP_4_Pin GPIO_PIN_5
#define STEP_4_GPIO_Port GPIOC
#define BUTTON_INT_3_Pin GPIO_PIN_0
#define BUTTON_INT_3_GPIO_Port GPIOB
#define BUTTON_INT_3_EXTI_IRQn EXTI0_IRQn
#define FND_7_Pin GPIO_PIN_10
#define FND_7_GPIO_Port GPIOB
#define STEP_3_Pin GPIO_PIN_6
#define STEP_3_GPIO_Port GPIOC
#define FND_4_Pin GPIO_PIN_7
#define FND_4_GPIO_Port GPIOC
#define STEP_2_Pin GPIO_PIN_8
#define STEP_2_GPIO_Port GPIOC
#define STEP_1_Pin GPIO_PIN_9
#define STEP_1_GPIO_Port GPIOC
#define FND_6_Pin GPIO_PIN_8
#define FND_6_GPIO_Port GPIOA
#define FND_5_Pin GPIO_PIN_9
#define FND_5_GPIO_Port GPIOA
#define BUTTON_INT_4_Pin GPIO_PIN_10
#define BUTTON_INT_4_GPIO_Port GPIOA
#define BUTTON_INT_4_EXTI_IRQn EXTI15_10_IRQn
#define LED_3_Pin GPIO_PIN_3
#define LED_3_GPIO_Port GPIOB
#define LED_1_Pin GPIO_PIN_4
#define LED_1_GPIO_Port GPIOB
#define LED_2_Pin GPIO_PIN_5
#define LED_2_GPIO_Port GPIOB
#define FND_3_Pin GPIO_PIN_6
#define FND_3_GPIO_Port GPIOB
#define PHOTO_INT_1_Pin GPIO_PIN_7
#define PHOTO_INT_1_GPIO_Port GPIOB
#define PHOTO_INT_1_EXTI_IRQn EXTI9_5_IRQn
#define PHOTO_INT_4_Pin GPIO_PIN_8
#define PHOTO_INT_4_GPIO_Port GPIOB
#define PHOTO_INT_4_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
