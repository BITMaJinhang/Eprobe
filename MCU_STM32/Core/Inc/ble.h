/*
 * ble.h
 *
 *  Created on: Sep 26, 2024
 *      Author: MaJinhang
 */

#ifndef INC_BLE_H_
#define INC_BLE_H_

#include "main.h"

#define BLE_PARAM_BUFFER_SIZE 4*32*1
#define TIMEOUT_MS 5000 
#define BLE_CMD_START 			0x00
#define BLE_CMD_STOP 			0x01

#define BLE_CMD_STOPCHN 		0x02
#define BLE_CMD_RESTARTCHN 		0x03
#define BLE_CMD_PAUSECHN 		0x04
#define BLE_CMD_CONTINUECHN 	0x05

#define BLE_CMD_CHANNEL1 	0x10
#define BLE_CMD_CHANNEL2 	0x20
#define BLE_CMD_CHANNEL3 	0x30
#define BLE_CMD_CHANNEL4 	0x40
#define BLE_CMD_CHANNEL5 	0x50
#define BLE_CMD_CHANNEL6 	0x60

// 函数原型声明
void BLE_Init(UART_HandleTypeDef *huart);
bool CheckBLETimeout(void);
void Buffer_clear(bool if_timeout);
bool DecodeBLEData(Eprobe_param_t* data);
bool BLE_Data_Receive(void);
void BLE_Cmd(uint32_t cmd);
void parseBLEData(const uint8_t* data, Eprobe_param_t* ble);
bool BLE_Pram_Set(void);
#endif /* INC_BLE_H_ */
