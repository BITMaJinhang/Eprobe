/*
 * dac856x.h
 *
 *  Created on: Sep 26, 2024
 *      Author: MaJinhang
 */

#ifndef INCLUDE_DAC856X_H_
#define INCLUDE_DAC856X_H_

//#define DEBUG_DAC856X	1

#define STM32L4

#if defined(STM32F1)
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_spi.h"
#elif defined(STM32F4)
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"
#elif defined(STM32L4)
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_spi.h"
#elif defined(STM32F3)
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_spi.h"
#endif

// ref: https://github.com/imcort-nrf-drivers/dac8568

#define DAC856X_DEFAULT 0x0
#define DAC856X_SYNC_Port GPIOA
#define DAC856X_SYNC_Pin GPIO_PIN_4
#define DAC856X_VREF 2.5
#define DAC856X_GAIN_1 1
#define DAC856X_GAIN_2 2	//Gain = 1 for A/B grades or 2 for C/D grades

typedef union {
  uint32_t raw;
  uint8_t byte[4];
  struct {
    // LSB
    unsigned int feature : 4;
    unsigned int data : 16;
    unsigned int address : 4;
    unsigned int control : 4;
    unsigned int prefix : 4;
    // MSB
  } field;
} dac856x_reg_t;


typedef enum CHANNEL_SELECT {
  DAC_CH_A,
  DAC_CH_B,
  DAC_CH_C,
  DAC_CH_D,
  DAC_CH_E,
  DAC_CH_F,
  DAC_CH_G,
  DAC_CH_H,
  DAC_NO_MSG,
  DAC_BROADCAST
} CHANNEL_SELECT;

typedef enum {
  CONTROL_WRITE_TO_INPUT_REGISTER,
  CONTROL_UPDATE_DAC_REGISTER,
  CONTROL_WRITE_TO_DAC_CH_AND_UPDATE_ALL_REG,
  CONTROL_WRITE_TO_DAC_CH_AND_UPDATE_SINGLE_REG,
  CONTROL_POWER_DOWN_COMM,
  CONTROL_WRITE_TO_CLEAR_CODE_REG,
  CONTROL_WRITE_TO_LDAC_REG,
  CONTROL_SOFTWARE_RESET,
} CONTROL_TYPE;

typedef enum {
  CONTROL_SETUP_STATIC_MODE = 8,
  CONTROL_SETUP_FLEX_MODE = 9
} CONTROL_SETUP_MODE;

typedef enum {
  FEATURE_CLEAR_TO_ZERO_SCALE,
  FEATURE_CLEAR_TO_MID_SCALE,
  FEATURE_CLEAR_TO_FULL_SCALE,
  FEATURE_IGNORE_CLR_PIN
} CLEAR_CODE_FEATURE;

typedef enum {
  FEATURE_POWER_DOWN_INT_REF_STATIC,
  FEATURE_POWER_UP_INT_REF_STATIC,
  FEATURE_POWER_UP_INT_REF_FLEX = 0,
  FEATURE_POWER_UP_INT_REF_ALWAYS_FLEX = 0,
  FEATURE_POWER_DOWN_INT_REF_FLEX = 0,
  FEATURE_SWITCH_FROM_FLEX_TO_STATIC = 0
} INTERNAL_REF_COMM_FEATURE;

typedef enum {
  LDAC_REG_A = 1,
  LDAC_REG_B = 2,
  LDAC_REG_C = 4,
  LDAC_REG_D = 8,
  LDAC_REG_E = 16,
  LDAC_REG_F = 32,
  LDAC_REG_G = 64,
  LDAC_REG_H = 128
} WRITE_TO_LDAC_CH;

typedef enum {
  POWER_DAC_A = 1,
  POWER_DAC_B = 2,
  POWER_DAC_C = 4,
  POWER_DAC_D = 8,
  POWER_DAC_E = 16,
  POWER_DAC_F = 32,
  POWER_DAC_G = 64,
  POWER_DAC_H = 128
} POWER_UP_DOWN_CH;

typedef enum {
  POWER_UP_DAC = 0,
  POWER_DOWN_DAC_1KO_TO_GND = 16,
  POWER_DOWN_DAC_100KO_TO_GND = 32,
  POWER_DOWN_DAC_HIZ_TO_GND = 48
} POWER_UP_DOWN_DAC;

typedef enum {
  DATA_POWER_DOWN_INT_REF_STATIC = 0,
  DATA_POWER_UP_INT_REF_STATIC = 0,
  DATA_POWER_UP_INT_REF_FLEX = 32768,
  DATA_POWER_UP_INT_REF_ALWAYS_FLEX = 40960,
  DATA_POWER_DOWN_INT_REF_FLEX = 49152,
  DATA_SWITCH_FROM_FLEX_TO_STATIC = 0
} INTERNAL_REF_COMM_DATA;


// Struct "Object"
typedef struct {
	SPI_HandleTypeDef *hspix;
    GPIO_TypeDef *csPort;
    uint16_t     csPin;
    dac856x_reg_t	reg;
    uint8_t		gain;
} DAC856X_t;


uint8_t DAC856X_init(DAC856X_t *dac ,SPI_HandleTypeDef *hspi, uint8_t gain);
uint8_t DAC856X_CS(DAC856X_t *dac, uint8_t on);
uint8_t DAC856X_Write_Dac(DAC856X_t *dac, CHANNEL_SELECT chn, uint16_t val);
uint8_t DAC856X_Write_Dac_Voltage(DAC856X_t *dac, CHANNEL_SELECT chn, float val);
uint8_t DAC856X_Register_Write(DAC856X_t *dac);
#endif /* INCLUDE_DAC8568_H_ */
