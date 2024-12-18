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
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#if defined(STM32F1)
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_spi.h"
#elif defined(STM32F4)
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"
#elif defined(STM32L4)
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_spi.h"
#include "stm32l4xx_hal_dma.h"
#elif defined(STM32F3)
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_spi.h"
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "ads125x.h"
#include "dac856x.h"
#include "eprobe.h"
#include "ble.h"
#include "ds18b20.h"

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
#define LED_Pin GPIO_PIN_1
#define LED_GPIO_Port GPIOA
#define TEMP_Pin GPIO_PIN_2
#define TEMP_GPIO_Port GPIOA
#define DAC_SYNC__Pin GPIO_PIN_4
#define DAC_SYNC__GPIO_Port GPIOA
#define ADC1_CS_Pin GPIO_PIN_0
#define ADC1_CS_GPIO_Port GPIOB
#define ADC1_DRDY_Pin GPIO_PIN_1
#define ADC1_DRDY_GPIO_Port GPIOB
#define ADC2_DRDY_Pin GPIO_PIN_8
#define ADC2_DRDY_GPIO_Port GPIOA
#define ADC2_CS_Pin GPIO_PIN_9
#define ADC2_CS_GPIO_Port GPIOA
#define POWEN_Pin GPIO_PIN_15
#define POWEN_GPIO_Port GPIOA
#define SELECT_A0_Pin GPIO_PIN_4
#define SELECT_A0_GPIO_Port GPIOB
#define SELECT_A1_Pin GPIO_PIN_5
#define SELECT_A1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
