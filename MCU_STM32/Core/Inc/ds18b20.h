/*
 * ds18b20.h
 *
 *  Created on: Oct 21, 2024
 *      Author: Majinhang
 */

#ifndef INC_DS18B20_H_
#define INC_DS18B20_H_

#ifndef __DS18B20_H
#define __DS18B20_H

#include "main.h"

#define DS18b20_GPIO_Port			GPIOA
#define DS18b20_GPIO_Pin			GPIO_PIN_2


#define DS18B20_Dout_LOW()               HAL_GPIO_WritePin(DS18b20_GPIO_Port,DS18b20_GPIO_Pin,GPIO_PIN_RESET)
#define DS18B20_Dout_HIGH()              HAL_GPIO_WritePin(DS18b20_GPIO_Port,DS18b20_GPIO_Pin,GPIO_PIN_SET)
#define DS18B20_Data_IN()                HAL_GPIO_ReadPin(DS18b20_GPIO_Port,DS18b20_GPIO_Pin)

void DS18B20_Rst(void);
void DS18B20_SkipRom(void);
void DS18B20_Mode_IPU(void);
void DS18B20_Mode_Out_PP(void);
void DS18B20_WriteByte(uint8_t dat);
void DS18B20_Delay(__IO uint32_t delay);
float DS18B20_GetTemp_SkipRom(void);
uint8_t DS18B20_Init(void);
uint8_t DS18B20_ReadBit(void);
uint8_t DS18B20_Presence(void);
uint8_t DS18B20_ReadByte(void);

#endif

#endif /* INC_DS18B20_H_ */
