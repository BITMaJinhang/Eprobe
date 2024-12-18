/*
 * ble.c
 *
 *  Created on: Sep 26, 2024
 *      Author: MaJinhang
 */


// ble.c

#include "main.h"

 uint8_t rxBuffer[BLE_PARAM_BUFFER_SIZE]; // receive buffer
 volatile uint32_t lastReceiveTime = 0; // last receive time
 volatile uint8_t dataReady = 0; // data ready flag
 volatile uint8_t paramReady = 0; // paramaters ready flag
 UART_HandleTypeDef *huartGlobal; // global UART handle
 extern uint32_t TimeTable;
 extern uint8_t Loop_stop;
 Eprobe_param_t BLE_RX_BUFFER;
 extern UART_HandleTypeDef huart1;
 extern UART_HandleTypeDef huart2;
 extern StateMachine Machine[TOTAL_CHANNELS];

void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart) {
    // 
//	printf("YEAH!!\n");
}

bool BLE_Pram_Set(void){
	switch(BLE_RX_BUFFER.BLE.Channel){
		case CHANNEL_1:
			memcpy(&Machine[CHANNEL_1].param, &BLE_RX_BUFFER, sizeof(Eprobe_param_t));
#if UART_DEBUG
			printf("CHN:%ld\n",Machine[CHANNEL_1].param.BLE.Channel);
			printf("MODE:%ld\n",Machine[CHANNEL_1].param.BLE.Mode);
			printf("SENS:%ld\n",Machine[CHANNEL_1].param.BLE.Sensitivity);
			printf("CMD:%ld\n",Machine[CHANNEL_1].param.BLE.Command);
			for(int i = 0;i<28;i++){
			printf("param[%d]:%f\n",i,Machine[CHANNEL_1].param.BLE.BLE_params[i]);
			}
#endif
			break;
		case CHANNEL_2:
			memcpy(&Machine[CHANNEL_2].param, &BLE_RX_BUFFER, sizeof(Eprobe_param_t));
#if UART_DEBUG
			printf("CHN:%ld\n",Machine[CHANNEL_2].param.BLE.Channel);
			printf("MODE:%ld\n",Machine[CHANNEL_2].param.BLE.Mode);
			printf("SENS:%ld\n",Machine[CHANNEL_2].param.BLE.Sensitivity);
			printf("CMD:%ld\n",Machine[CHANNEL_2].param.BLE.Command);
			for(int i = 0;i<28;i++){
			printf("param[%d]:%f\n",i,Machine[CHANNEL_2].param.BLE.BLE_params[i]);
			}
#endif
			break;
		case CHANNEL_3:
			memcpy(&Machine[CHANNEL_3].param, &BLE_RX_BUFFER, sizeof(Eprobe_param_t));
#if UART_DEBUG
			printf("CHN:%ld\n",Machine[CHANNEL_3].param.BLE.Channel);
			printf("MODE:%ld\n",Machine[CHANNEL_3].param.BLE.Mode);
			printf("SENS:%ld\n",Machine[CHANNEL_3].param.BLE.Sensitivity);
			printf("CMD:%ld\n",Machine[CHANNEL_3].param.BLE.Command);
			for(int i = 0;i<28;i++){
			printf("param[%d]:%f\n",i,Machine[CHANNEL_3].param.BLE.BLE_params[i]);
			}
#endif
			break;
		case CHANNEL_4:
			memcpy(&Machine[CHANNEL_4].param, &BLE_RX_BUFFER, sizeof(Eprobe_param_t));
#if UART_DEBUG
			printf("CHN:%ld\n",Machine[CHANNEL_4].param.BLE.Channel);
			printf("MODE:%ld\n",Machine[CHANNEL_4].param.BLE.Mode);
			printf("SENS:%ld\n",Machine[CHANNEL_4].param.BLE.Sensitivity);
			printf("CMD:%ld\n",Machine[CHANNEL_4].param.BLE.Command);
			for(int i = 0;i<28;i++){
			printf("param[%d]:%f\n",i,Machine[CHANNEL_4].param.BLE.BLE_params[i]);
			}
#endif
			break;
		case CHANNEL_5:
			memcpy(&Machine[CHANNEL_5].param, &BLE_RX_BUFFER, sizeof(Eprobe_param_t));
#if UART_DEBUG
			printf("CHN:%ld\n",Machine[CHANNEL_5].param.BLE.Channel);
			printf("MODE:%ld\n",Machine[CHANNEL_5].param.BLE.Mode);
			printf("SENS:%ld\n",Machine[CHANNEL_5].param.BLE.Sensitivity);
			printf("CMD:%ld\n",Machine[CHANNEL_5].param.BLE.Command);
			for(int i = 0;i<28;i++){
			printf("param[%d]:%f\n",i,Machine[CHANNEL_5].param.BLE.BLE_params[i]);
			}
#endif
			break;
		case CHANNEL_6:
			memcpy(&Machine[CHANNEL_6].param, &BLE_RX_BUFFER, sizeof(Eprobe_param_t));
#if UART_DEBUG
			printf("CHN:%ld\n",Machine[CHANNEL_6].param.BLE.Channel);
			printf("MODE:%ld\n",Machine[CHANNEL_6].param.BLE.Mode);
			printf("SENS:%ld\n",Machine[CHANNEL_6].param.BLE.Sensitivity);
			printf("CMD:%ld\n",Machine[CHANNEL_6].param.BLE.Command);
			for(int i = 0;i<28;i++){
			printf("param[%d]:%f\n",i,Machine[CHANNEL_6].param.BLE.BLE_params[i]);
			}
#endif
			paramReady = 1;
#if UART_DEBUG
			printf("Paramaters are ready.paramReady =%d\n",paramReady);
#endif
			break;
		default:
			break;
		}


	return 0;
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    
    dataReady = 1;  
    BLE_Data_Receive();		
    if(BLE_RX_BUFFER.BLE.Channel > CHANNEL_6){//Only 6 channels, channels greater than six indicate that it is not parameter data, but configuration commands
    	BLE_Cmd(BLE_RX_BUFFER.BLE.Command);//
    }
    else if (BLE_RX_BUFFER.BLE.Channel <= CHANNEL_6)
    {
    	BLE_Pram_Set();		
    }
    else{
#if UART_DEBUG
printf("Unknown Parameters or Command.\n");
#endif
    }
    
	HAL_UART_Receive_DMA(huartGlobal, rxBuffer, BLE_PARAM_BUFFER_SIZE);
}

void BLE_Cmd(uint32_t cmd){
	switch(cmd){
	case BLE_CMD_START:
		  Loop_stop = 0;
		  TimeTable = 0;
			Machine[CHANNEL_1].StopFlag = 1;		Machine[CHANNEL_1].Current_State = STATE_INIT;			Machine[CHANNEL_1].timetable = 1;
			Machine[CHANNEL_2].StopFlag = 1;		Machine[CHANNEL_2].Current_State = STATE_INIT;			Machine[CHANNEL_2].timetable = 2;
			Machine[CHANNEL_3].StopFlag = 1;		Machine[CHANNEL_3].Current_State = STATE_INIT;			Machine[CHANNEL_3].timetable = 3;
			Machine[CHANNEL_4].StopFlag = 1;		Machine[CHANNEL_4].Current_State = STATE_INIT;			Machine[CHANNEL_4].timetable = 4;
			Machine[CHANNEL_5].StopFlag = 1;		Machine[CHANNEL_5].Current_State = STATE_INIT;			Machine[CHANNEL_5].timetable = 5;
			Machine[CHANNEL_6].StopFlag = 1;		Machine[CHANNEL_6].Current_State = STATE_INIT;			Machine[CHANNEL_6].timetable = 6;

			#if UART_DEBUG
			printf("BLE_CMD_START.\n");
			#endif
		break;

	case BLE_CMD_STOP:
		Machine[CHANNEL_1].StopFlag = 0;		Machine[CHANNEL_1].Current_State = STATE_DONE;
		Machine[CHANNEL_2].StopFlag = 0;		Machine[CHANNEL_2].Current_State = STATE_DONE;
		Machine[CHANNEL_3].StopFlag = 0;		Machine[CHANNEL_3].Current_State = STATE_DONE;
		Machine[CHANNEL_4].StopFlag = 0;		Machine[CHANNEL_4].Current_State = STATE_DONE;
		Machine[CHANNEL_5].StopFlag = 0;		Machine[CHANNEL_5].Current_State = STATE_DONE;
		Machine[CHANNEL_6].StopFlag = 0;		Machine[CHANNEL_6].Current_State = STATE_DONE;
			#if UART_DEBUG
			printf("BLE_CMD_STOP.\n");
			#endif
		break;
	case BLE_CMD_STOPCHN:
		switch (BLE_RX_BUFFER.BLE.Channel){
		case BLE_CMD_CHANNEL1:
			Machine[CHANNEL_1].StopFlag = 0;		Machine[CHANNEL_1].Current_State = STATE_DONE;
			break;
		case BLE_CMD_CHANNEL2:
			Machine[CHANNEL_2].StopFlag = 0;		Machine[CHANNEL_2].Current_State = STATE_DONE;
			break;
		case BLE_CMD_CHANNEL3:
			Machine[CHANNEL_3].StopFlag = 0;		Machine[CHANNEL_3].Current_State = STATE_DONE;
			break;
		case BLE_CMD_CHANNEL4:
			Machine[CHANNEL_4].StopFlag = 0;		Machine[CHANNEL_4].Current_State = STATE_DONE;
			break;
		case BLE_CMD_CHANNEL5:
			Machine[CHANNEL_5].StopFlag = 0;		Machine[CHANNEL_5].Current_State = STATE_DONE;
			break;
		case BLE_CMD_CHANNEL6:
			Machine[CHANNEL_6].StopFlag = 0;		Machine[CHANNEL_6].Current_State = STATE_DONE;
			break;
		default:
			#if UART_DEBUG
			printf("Unknown stop channel.\n");
			#endif
			break;
	}
		#if UART_DEBUG
		printf("BLE_CMD_STOPCHN[%ld].\n",(BLE_RX_BUFFER.BLE.Channel>>4));
		#endif
		break;

	case BLE_CMD_RESTARTCHN:
		  Loop_stop = 0;
		switch (BLE_RX_BUFFER.BLE.Channel){
		case BLE_CMD_CHANNEL1:
			Machine[CHANNEL_1].StopFlag = 1;		Machine[CHANNEL_1].Current_State = STATE_INIT;
			Machine[CHANNEL_1].timetable = TimeTable;
			break;
		case BLE_CMD_CHANNEL2:
			Machine[CHANNEL_2].StopFlag = 1;		Machine[CHANNEL_2].Current_State = STATE_INIT;
			Machine[CHANNEL_2].timetable = TimeTable+1;
			break;
		case BLE_CMD_CHANNEL3:
			Machine[CHANNEL_3].StopFlag = 1;		Machine[CHANNEL_3].Current_State = STATE_INIT;
			Machine[CHANNEL_3].timetable = TimeTable+2;
			break;
		case BLE_CMD_CHANNEL4:
			Machine[CHANNEL_4].StopFlag = 1;		Machine[CHANNEL_4].Current_State = STATE_INIT;
			Machine[CHANNEL_4].timetable = TimeTable+3;
			break;
		case BLE_CMD_CHANNEL5:
			Machine[CHANNEL_5].StopFlag = 1;		Machine[CHANNEL_5].Current_State = STATE_INIT;
			Machine[CHANNEL_5].timetable = TimeTable+4;
			break;
		case BLE_CMD_CHANNEL6:
			Machine[CHANNEL_6].StopFlag = 1;		Machine[CHANNEL_6].Current_State = STATE_INIT;
			Machine[CHANNEL_6].timetable = TimeTable+5;
			break;
		default:
			#if UART_DEBUG
			printf("Unknown restart channel.\n");
			#endif
			break;
	}
		#if UART_DEBUG
				printf("BLE_CMD_RESTARTCHN[%ld].\n",(BLE_RX_BUFFER.BLE.Channel>>4));
		#endif
		break;

	case BLE_CMD_PAUSECHN:
		switch (BLE_RX_BUFFER.BLE.Channel){
			case BLE_CMD_CHANNEL1:
				Machine[CHANNEL_1].pause_delta_time = Machine[CHANNEL_1].timetable - TimeTable;
				Machine[CHANNEL_1].PauseFlag = 0;
				Set_VBias(&Machine[CHANNEL_1], 0);
				break;
			case BLE_CMD_CHANNEL2:
				Machine[CHANNEL_2].pause_delta_time = Machine[CHANNEL_2].timetable - TimeTable;
				Machine[CHANNEL_2].PauseFlag = 0;
				Set_VBias(&Machine[CHANNEL_2], 0);
				break;
			case BLE_CMD_CHANNEL3:
				Machine[CHANNEL_3].pause_delta_time = Machine[CHANNEL_3].timetable - TimeTable;
				Machine[CHANNEL_3].PauseFlag = 0;
				Set_VBias(&Machine[CHANNEL_3], 0);
				break;
			case BLE_CMD_CHANNEL4:
				Machine[CHANNEL_4].pause_delta_time = Machine[CHANNEL_4].timetable - TimeTable;
				Machine[CHANNEL_4].PauseFlag = 0;
				Set_VBias(&Machine[CHANNEL_4], 0);
				break;
			case BLE_CMD_CHANNEL5:
				Machine[CHANNEL_5].pause_delta_time = Machine[CHANNEL_5].timetable - TimeTable;
				Machine[CHANNEL_5].PauseFlag = 0;
				Set_VBias(&Machine[CHANNEL_5], 0);
				break;
			case BLE_CMD_CHANNEL6:
				Machine[CHANNEL_6].pause_delta_time = Machine[CHANNEL_6].timetable - TimeTable;
				Machine[CHANNEL_6].PauseFlag = 0;
				Set_VBias(&Machine[CHANNEL_6], 0);
				break;
			default:
				#if UART_DEBUG
				printf("Unknown pause channel.\n");
				#endif
				break;
			}
		#if UART_DEBUG
				printf("BLE_CMD_PAUSECHN[%ld].\n",(BLE_RX_BUFFER.BLE.Channel>>4));
		#endif
		break;

	case BLE_CMD_CONTINUECHN:
		switch (BLE_RX_BUFFER.BLE.Channel){
			case BLE_CMD_CHANNEL1:
				Machine[CHANNEL_1].timetable = Machine[CHANNEL_1].pause_delta_time + TimeTable;
				Machine[CHANNEL_1].PauseFlag = 1;
				Set_VBias(&Machine[CHANNEL_1], Machine[CHANNEL_1].VBias);
				break;
			case BLE_CMD_CHANNEL2:
				Machine[CHANNEL_2].timetable = Machine[CHANNEL_2].pause_delta_time + TimeTable;
				Machine[CHANNEL_2].PauseFlag = 1;
				Set_VBias(&Machine[CHANNEL_2], Machine[CHANNEL_2].VBias);
				break;
			case BLE_CMD_CHANNEL3:
				Machine[CHANNEL_3].timetable = Machine[CHANNEL_3].pause_delta_time + TimeTable;
				Machine[CHANNEL_3].PauseFlag = 1;
				Set_VBias(&Machine[CHANNEL_3], Machine[CHANNEL_3].VBias);
				break;
			case BLE_CMD_CHANNEL4:
				Machine[CHANNEL_4].timetable = Machine[CHANNEL_4].pause_delta_time + TimeTable;
				Machine[CHANNEL_4].PauseFlag = 1;
				Set_VBias(&Machine[CHANNEL_4], Machine[CHANNEL_4].VBias);
				break;
			case BLE_CMD_CHANNEL5:
				Machine[CHANNEL_5].timetable = Machine[CHANNEL_5].pause_delta_time + TimeTable;
				Machine[CHANNEL_5].PauseFlag = 1;
				Set_VBias(&Machine[CHANNEL_5], Machine[CHANNEL_5].VBias);
				break;
			case BLE_CMD_CHANNEL6:
				Machine[CHANNEL_6].timetable = Machine[CHANNEL_6].pause_delta_time + TimeTable;
				Machine[CHANNEL_6].PauseFlag = 1;
				Set_VBias(&Machine[CHANNEL_6], Machine[CHANNEL_6].VBias);
				break;
			default:
				#if UART_DEBUG
				printf("Unknown continue channel.\n");
				#endif
				break;
		}
		#if UART_DEBUG
				printf("BLE_CMD_CONTINUE[%ld].\n",(BLE_RX_BUFFER.BLE.Channel>>4));
		#endif
		break;
	default:
#if UART_DEBUG
printf("BLE_CMD_UNKNOWN.\n");
#endif
		break;
	}
}

bool BLE_Data_Receive(void){
	if(dataReady) {
    	parseBLEData(rxBuffer,&BLE_RX_BUFFER);
		dataReady = 0;
	}
		return true;
}



void BLE_Init(UART_HandleTypeDef *huart) {
	Loop_stop = 1;
    huartGlobal = huart; 
	HAL_UART_Receive_DMA(huartGlobal, rxBuffer, BLE_PARAM_BUFFER_SIZE);
}

bool CheckBLETimeout(void) {
    if (TimeTable - lastReceiveTime > TIMEOUT_MS) {
#if UART_DEBUG
  printf("BLE_Receive timeout.\n");
#endif
  return 1;
    }else{
    return 0;
    }
}

void Buffer_clear(bool if_timeout){
	if(if_timeout){
//		        memset(rxBuffer, 0, BLE_PARAM_BUFFER_SIZE); 
//		        HAL_DMA_Abort(huartGlobal->hdmarx);
		        HAL_UART_Receive_DMA(huartGlobal, rxBuffer, BLE_PARAM_BUFFER_SIZE); 
	}
}





void parseBLEData(const uint8_t* data, Eprobe_param_t* ble) {
    if (data == NULL || ble == NULL) {
        fprintf(stderr, "Error: Null pointer passed to parseBLEData.\n");
        return;
    }

    memcpy(&ble->BLE.Channel, data, sizeof(uint32_t));              
    memcpy(&ble->BLE.Mode, data + 4, sizeof(uint32_t));      
    memcpy(&ble->BLE.Sensitivity, data + 8, sizeof(uint32_t)); 
    memcpy(&ble->BLE.Command, data + 12, sizeof(uint32_t));  
    memcpy(ble->BLE.BLE_params, data + 16, sizeof(float) * 28); 

}

