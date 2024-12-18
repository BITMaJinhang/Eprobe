/*
 * eprobe.c
 *
 *  Created on: Jun 12, 2024
 *      Author: MaJinhang
 */

#include "main.h"

extern DAC856X_t dac1;
extern ADS125X_t adc1;
extern ADS125X_t adc2;
extern Eprobe_param_t RX_BUFFER;
extern uint32_t TimeTable;
extern SPI_HandleTypeDef hspi1;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef *huartGlobal; 


volatile uint8_t buffer_channel = Buffer_Channel_A;
volatile uint8_t buffer_index_a = 0;
volatile uint8_t buffer_index_b = 0;
float data_buffer_a[BUFFER_SIZE][3];
float data_buffer_b[BUFFER_SIZE][3];
extern StateMachine Machine[TOTAL_CHANNELS];

volatile uint8_t Loop_stop;

void State_Machine_Init(void){
  Machine[CHANNEL_1] = (StateMachine){.param.BLE.Channel = (float)CHANNEL_1,
	  	  	  	  	  	  	  	  	  .param.BLE.Mode = MODE_NONE,
                                      .timetable = 0,
                                      .DAC_CH = DAC_CH_D,
                                      .ADC_CH = ADS125X_CHANNEL_01,
									  .OCP_CH = ADS125X_CHANNEL_28,
                                      .adc = adc2,
                                      .Current_State = STATE_INIT,
									  .PauseFlag = 1,
  	  	  	  	  	  	  	  	  	  .StopFlag = 1};

  Machine[CHANNEL_2] = (StateMachine){.param.BLE.Channel = (float)CHANNEL_2,
	  	  	  	  	  	  	  	  	  .param.BLE.Mode = MODE_NONE,
                                      .timetable = 1,
                                      .DAC_CH = DAC_CH_F,
                                      .ADC_CH = ADS125X_CHANNEL_45,
									  .OCP_CH = ADS125X_CHANNEL_38,
                                      .adc = adc2,
                                      .Current_State = STATE_INIT,
									  .PauseFlag = 1,
  	  	  	  	  	  	  	  	  	  .StopFlag = 1};

  Machine[CHANNEL_3] = (StateMachine){.param.BLE.Channel = (float)CHANNEL_3,
	  	  	  	  	  	  	  	  	  .param.BLE.Mode = MODE_NONE,
                                      .timetable = 2,
                                      .DAC_CH = DAC_CH_H,
                                      .ADC_CH = ADS125X_CHANNEL_67,
                                      .adc = adc2,
                                      .Current_State = STATE_INIT,
									  .PauseFlag = 1,
  	  	  	  	  	  	  	  	  	  .StopFlag = 1};

  Machine[CHANNEL_4] = (StateMachine){.param.BLE.Channel = (float)CHANNEL_4,
	  	  	  	  	  	  	  	  	  .param.BLE.Mode = MODE_NONE,
                                      .timetable = 3,
                                      .DAC_CH = DAC_CH_G,
                                      .ADC_CH = ADS125X_CHANNEL_01,
									  .OCP_CH = ADS125X_CHANNEL_28,
                                      .adc = adc1,
                                      .Current_State = STATE_INIT,
									  .PauseFlag = 1,
  	  	  	  	  	  	  	  	  	  .StopFlag = 1};

  Machine[CHANNEL_5] = (StateMachine){.param.BLE.Channel = (float)CHANNEL_5,
	  	  	  	  	  	  	  	  	  .param.BLE.Mode = MODE_NONE,
                                      .timetable = 4,
                                      .DAC_CH = DAC_CH_E,
                                      .ADC_CH = ADS125X_CHANNEL_45,
									  .OCP_CH = ADS125X_CHANNEL_38,
                                      .adc = adc1,
                                      .Current_State = STATE_INIT,
									  .PauseFlag = 1,
  	  	  	  	  	  	  	  	  	  .StopFlag = 1};

  Machine[CHANNEL_6] = (StateMachine){.param.BLE.Channel = (float)CHANNEL_6,
	  	  	  	  	  	  	  	  	  .param.BLE.Mode = MODE_NONE,
                                      .timetable = 5,
                                      .DAC_CH = DAC_CH_C,
                                      .ADC_CH = ADS125X_CHANNEL_67,
                                      .adc = adc1,
                                      .Current_State = STATE_INIT,
									  .PauseFlag = 1,
  	  	  	  	  	  	  	  	  	  .StopFlag = 1};

}


float my_log(float datain) { return datain > 0 ? log10(datain) : log10(-datain); }

uint8_t LED_ON(void) {
  HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
  return 0;
}
uint8_t LED_OFF(void) {
  HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
  return 0;
}
uint8_t LED_TOGGLE(void) {
  HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
  return 0;
}
uint8_t Sensitivity_set(StateMachine *machine) {

  HAL_GPIO_WritePin(SENS_SELECTA0_Port, SENS_SELECTA0_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(SENS_SELECTA1_Port, SENS_SELECTA1_Pin, GPIO_PIN_RESET);
  machine->R_SENS = 750.0;

  if(machine->param.BLE.Channel ==0 && machine->param.BLE.Mode!= MODE_OCPT)
  {
#if UART_DEBUG
//  printf("Sensitivity setting:\n");
#endif
  switch (machine->param.BLE.Sensitivity) {
  case SENSITIVITY_1: // 00
#if UART_DEBUG
//    printf("SENSITIVITY_1\n");
#endif
    HAL_GPIO_WritePin(SENS_SELECTA0_Port, SENS_SELECTA0_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SENS_SELECTA1_Port, SENS_SELECTA1_Pin, GPIO_PIN_RESET);
    machine->R_SENS = 750.0;
    break;
  case SENSITIVITY_2: // 10
#if UART_DEBUG
    printf("SENSITIVITY_2\n");
#endif
    HAL_GPIO_WritePin(SENS_SELECTA0_Port, SENS_SELECTA0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SENS_SELECTA1_Port, SENS_SELECTA1_Pin, GPIO_PIN_RESET);
    machine->R_SENS = 3100.0;
    break;
  case SENSITIVITY_3: // 01
#if UART_DEBUG
    printf("SENSITIVITY_3\n");
#endif
    HAL_GPIO_WritePin(SENS_SELECTA0_Port, SENS_SELECTA0_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SENS_SELECTA1_Port, SENS_SELECTA1_Pin, GPIO_PIN_SET);
    machine->R_SENS = 10000.0;
    break;
  case SENSITIVITY_4: //11
#if UART_DEBUG
    printf("SENSITIVITY_4\n");
#endif
    HAL_GPIO_WritePin(SENS_SELECTA0_Port, SENS_SELECTA0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SENS_SELECTA1_Port, SENS_SELECTA1_Pin, GPIO_PIN_SET);
    machine->R_SENS = 100.0;
    break;
  default:
#if UART_DEBUG
    printf("error:wrong in Sensitivity_set.\n");
#endif
    break;
  }
  }
  return 0;
}
uint8_t Set_VBias(StateMachine *machine, float vbias) {
	float Calibrated_Vbias = vbias;
//	Calibrated_Vbias = machine->Cali_Vbias;
	switch (machine->param.BLE.Channel){
	case CHANNEL_1:
		Calibrated_Vbias = (vbias - 0.0241)/0.9968;
		break;
	case CHANNEL_2:
		Calibrated_Vbias = (vbias - 0.0148)/1.0011;
		break;
	case CHANNEL_3:
		Calibrated_Vbias = (vbias - 0.018)/1.0034;
		break;
	case CHANNEL_4:
		Calibrated_Vbias = (vbias - 0.0065)/1.0075;
		break;
	case CHANNEL_5:
		Calibrated_Vbias = (vbias - 0.0186)/1.0044;
		break;
	case CHANNEL_6:
		Calibrated_Vbias = (vbias - 0.0142)/0.9975;
		break;
	default:
		break;
	}
#if PROBE_EDITION
  DAC856X_Write_Dac_Voltage(&dac1, machine->DAC_CH,
                             (Calibrated_Vbias - 1.5 + 12.5) /334*39);
#else
	switch (machine->param.BLE.Channel){
	case CHANNEL_1:
		Calibrated_Vbias = (vbias - 0.0193)/0.9967;
		break;
	case CHANNEL_2:
		Calibrated_Vbias = (vbias - 0.0146)/0.9965;
		break;
	case CHANNEL_3:
		Calibrated_Vbias = (vbias - 0.031)/0.9904;
		break;
	case CHANNEL_4:
		Calibrated_Vbias = (vbias - 0.0198)/0.9918;
		break;
	case CHANNEL_5:
		Calibrated_Vbias = (vbias - 0.0284)/0.9923;
		break;
	case CHANNEL_6:
		Calibrated_Vbias = (vbias - 0.0136)/0.9949;
		break;
	default:
		break;
	}
  DAC856X_Write_Dac_Voltage(&dac1, machine->DAC_CH,
                            (Calibrated_Vbias - 1.5 + 10) /8);
#endif
//	HAL_Delay(1);
  return 0;
}
float Get_Current(StateMachine *machine) {
	ADS125X_ReadChannelVolt(&machine->adc, machine->ADC_CH);
//	HAL_Delay(2);
  return ADS125X_ReadChannelVolt(&machine->adc, machine->ADC_CH) /
         machine->R_SENS;
}

uint8_t Ttans_Data_To_Buffer(uint8_t channel,float data_x, float data_y,uint8_t buffer_channel){
#if UART_DEBUG
    printf("%d,%.3f,%.8f\n", channel, data_x,
    		data_y);
#else
	if (buffer_channel == Buffer_Channel_A){
		data_buffer_a[buffer_index_a][0] = (float)channel; // channel
		data_buffer_a[buffer_index_a][1] = data_x; // VBias
		data_buffer_a[buffer_index_a][2] = data_y*1000; // Current
//		if(buffer_index_a ==0){
//		data_buffer_a[buffer_index_a][2] = data_y; // Current
//		}
//		else data_buffer_a[buffer_index_a-1][2] = data_y; // Current
		buffer_index_a++;
		}
	else if(buffer_channel == Buffer_Channel_B){
		data_buffer_b[buffer_index_b][0] = (float)channel; // channel
		data_buffer_b[buffer_index_b][1] = data_x; // VBias
		data_buffer_b[buffer_index_b][2] = data_y*1000; // Current
//		if(buffer_index_b ==0){
//		data_buffer_b[buffer_index_b][2] = data_y; // Current
//		}
//		else data_buffer_b[buffer_index_b-1][2] = data_y; // Current
		buffer_index_b++;
		buffer_channel = Buffer_Channel_A;
		}
#endif
	return 0;
}
uint8_t DMA_Buffer_Update(){
//	if (buffer_index_a >= BUFFER_SIZE || Loop_stop == 1) {
	if (buffer_index_a >= BUFFER_SIZE) {
        buffer_index_a = 0; 
        HAL_UART_Transmit_DMA(huartGlobal, (uint8_t*)&data_buffer_a, 4*BUFFER_SIZE*3);  
		buffer_channel = Buffer_Channel_B;
    }
//	if (buffer_index_b >= BUFFER_SIZE || Loop_stop == 1) {
	if (buffer_index_b >= BUFFER_SIZE) {
        buffer_index_b = 0; 
        HAL_UART_Transmit_DMA(huartGlobal, (uint8_t*)&data_buffer_b, 4*BUFFER_SIZE*3);  
		buffer_channel = Buffer_Channel_A;
    }
	return 0;
}



float CV_update(StateMachine *machine) {

  switch (machine->Current_State) {
  case CV_STATE_INIT:
#if UART_DEBUG
//    printf("Channel[%ld] Start CV mode:\n",machine->param.BLE.Channel+1);
#endif


    machine->sample_rate =
        machine->param.CV.ScanRate / machine->param.CV.SampleInt;
    machine->interval_time = 1 / machine->sample_rate;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->VBias = machine->param.CV.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = CV_STATE_UP;
    return 1000 * machine->param.CV.QuietTime;
    break;
  case CV_STATE_UP:
    Set_VBias(machine, machine->VBias);
	  Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,Get_Current(machine),buffer_channel);
    machine->VBias += machine->param.CV.SampleInt;
    if (machine->VBias > machine->param.CV.HighE) {
      machine->segment_count += 1;
      if (machine->segment_count > machine->param.CV.Segments) {
        machine->Current_State = CV_STATE_DONE;
#if UART_DEBUG
//        printf("CV_STATE_DONE!\n");
#endif
      } else {
        machine->Current_State = CV_STATE_DOWN;
        machine->VBias = machine->param.CV.HighE;
      }
    }
    return 1000 * machine->interval_time;
    break;
  case CV_STATE_DOWN:
    Set_VBias(machine, machine->VBias);
	  Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,Get_Current(machine),buffer_channel);
    machine->VBias -= machine->param.CV.SampleInt;
    if (machine->VBias < machine->param.CV.LowE) {
      machine->segment_count += 1;
      if (machine->segment_count > machine->param.CV.Segments) {
        machine->Current_State = CV_STATE_DONE;
#if UART_DEBUG
//        printf("CV_STATE_DONE!\n");
#endif
      } else {
        machine->Current_State = CV_STATE_UP;
        machine->VBias = machine->param.CV.LowE;
      }
    }
    return 1000 * machine->interval_time;
    break;
  case CV_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
#if UART_DEBUG
#endif
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("CV_STATE_ERROR!\n");
#endif
    return 0;
    break;
  }
}

float LSV_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case LSV_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start LSV mode:\n",machine->param.BLE.Channel+1);
#endif
	machine->StopFlag = 1;
    machine->sample_rate =
        machine->param.LSV.ScanRate / machine->param.LSV.SampleInt;
    machine->interval_time = 1 / machine->sample_rate;
    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->VBias = machine->param.LSV.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = LSV_STATE_UP;
    return 1000 * machine->param.LSV.QuietTime;
    break;
  case LSV_STATE_UP:
#if BLE_DEBUG
    ble_data_tx.channal = machine->param.BLE.Channel;
    ble_data_tx.data_x = machine->VBias;
    ble_data_tx.data_y = Get_Current(machine);
    DMA_Send_Data(&huart1,&ble_data_tx);
#endif
    Set_VBias(machine, machine->VBias);
	  Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,Get_Current(machine),buffer_channel);
    machine->VBias += machine->param.LSV.SampleInt;
    if (machine->VBias > machine->param.LSV.FinalE) {
      machine->Current_State = LSV_STATE_DONE;
#if UART_DEBUG
//      printf("LSV_STATE_DONE.\n");
#endif
    }
    return 1000 * machine->interval_time;
    break;
  case LSV_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("LSV_STATE_ERROR!\n");
#endif
    return 0;
    break;
  }
}

float SCV_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case SCV_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start SCV mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->VBias = machine->param.SCV.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = SCV_STATE_SAMPLE;
    return 1000 * machine->param.SCV.QuietTime;
    break;
  case SCV_STATE_UP:
    machine->VBias += machine->param.SCV.IncrE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = SCV_STATE_SAMPLE;
    return (1000 *
            (machine->param.SCV.StepPeriod - machine->param.SCV.SampleWidth));
    break;
  case SCV_STATE_SAMPLE:
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,Get_Current(machine),buffer_channel);
    if ((machine->VBias > machine->param.SCV.FinalE) ||
        (machine->VBias < machine->param.SCV.InitE)) {
      machine->segment_count += 1;
      if (machine->segment_count > machine->param.SCV.Segments) {
        machine->Current_State = SCV_STATE_DONE;
#if UART_DEBUG
        printf("SCV_STATE_DONE.\n");
#endif
      } else
        machine->Current_State =
            machine->segment_count % 2 != 0 ? SCV_STATE_UP : SCV_STATE_DOWN;
    } else
      machine->Current_State =
          machine->segment_count % 2 != 0 ? SCV_STATE_UP : SCV_STATE_DOWN;
    return (1000 * machine->param.SCV.SampleWidth);
    break;
  case SCV_STATE_DOWN:
    machine->VBias -= machine->param.SCV.IncrE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = SCV_STATE_SAMPLE;
    return (1000 *
            (machine->param.SCV.StepPeriod - machine->param.SCV.SampleWidth));
    break;
  case SCV_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;

    return 0;
    break;
  default:
    return 0;
    break;
  }
}

float TAFEL_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case TAFEL_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start TAFEL mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;

    machine->sample_rate =
        machine->param.TAFEL.ScanRate / machine->param.TAFEL.IncrE;
    machine->interval_time = 1 / machine->sample_rate;
    machine->segment_count = 1;
    Sensitivity_set(machine);
    machine->VBias = machine->param.TAFEL.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = TAFEL_STATE_UP;
    return 1000 * machine->param.TAFEL.QuietTime;
    break;
  case TAFEL_STATE_UP:
    machine->VBias += machine->param.TAFEL.IncrE;
    Set_VBias(machine, machine->VBias);
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,my_log(Get_Current(machine)),buffer_channel);
    if (machine->VBias > machine->param.TAFEL.FinalE) {
      machine->segment_count += 1;
      if (machine->segment_count > machine->param.TAFEL.Segments) {
        machine->Current_State = TAFEL_STATE_DONE;
        printf("TAFEL_STATE_DONE.\n");
      } else {
        machine->Current_State = TAFEL_STATE_HOLD;
        machine->VBias = machine->param.TAFEL.FinalE;
      }
    }
    return (1000 * (machine->interval_time));
    break;
  case TAFEL_STATE_HOLD:
    machine->Current_State = TAFEL_STATE_DOWN;
    return (1000 * machine->param.TAFEL.HoldTime);
    break;
  case TAFEL_STATE_DOWN:
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,my_log(Get_Current(machine)),buffer_channel);
    machine->VBias -= machine->param.TAFEL.IncrE;
    Set_VBias(machine, machine->VBias);
    if (machine->VBias < machine->param.TAFEL.InitE) {
      machine->Current_State = TAFEL_STATE_DONE;
      printf("TAFEL_STATE_DONE.\n");
    }
    return (1000 * (machine->interval_time));
    break;
  case TAFEL_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("TAFEL_STATE_ERROR.\n");
#endif
    return 0;
    break;
  }
}

float CA_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case CA_STATE_INIT:
// Start CA mode
#if UART_DEBUG
	    printf("Channel[%ld] Start CA mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;


    machine->interval_time = machine->param.CA.SampleIntrval;
    machine->sample_rate = 1 / machine->interval_time;

    // Initialize TIA
    Sensitivity_set(machine);

    machine->segment_count = 1;
    machine->time_count = 0.0;
    machine->time_count2 = 0.0;

    machine->VBias = machine->param.CA.InitE;
    Set_VBias(machine, machine->VBias);
    if ((uint32_t)machine->param.CA.direct == DIRECTION_POS){
    	machine->Current_State = CA_STATE_HIGH;
    }
    else {
    	machine->Current_State = CA_STATE_LOW;
    }
    // Quiet time before starting
    return (1000 * machine->param.CA.QuietTime);
    break;
  case CA_STATE_HIGH:
    // Set VBias to HighE
    machine->VBias = machine->param.CA.HighE;
    Set_VBias(machine, machine->VBias);

    // Store data in buffers
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,Get_Current(machine),buffer_channel);
    machine->time_count += machine->interval_time;
    machine->time_count2 += machine->interval_time;

    if (machine->time_count2 >= machine->param.CA.PulseWidth) {
      machine->segment_count += 1;
      machine->time_count2 = 0.0;
      if (machine->segment_count > machine->param.CA.NumberOfSteps){
    	  machine->Current_State = CA_STATE_DONE;
      }
      else{
    	  machine->Current_State = CA_STATE_LOW;
    	    machine->VBias = machine->param.CA.LowE;
    	    Set_VBias(machine, machine->VBias);
      }
    }
    return (1000 * machine->interval_time);
    break;
  case CA_STATE_LOW:
    // Set VBias to LowE
    machine->VBias = machine->param.CA.LowE;
    Set_VBias(machine, machine->VBias);
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,Get_Current(machine),buffer_channel);
    machine->time_count += machine->interval_time;
    machine->time_count2 += machine->interval_time;
    if (machine->time_count2 >= machine->param.CA.PulseWidth) {
      machine->segment_count += 1;
      machine->time_count2 = 0.0;
      if (machine->segment_count > machine->param.CA.NumberOfSteps){
    	  machine->Current_State = CA_STATE_DONE;
#if UART_DEBUG
    printf("CA done!\n");
#endif
      }
      else {
    	machine->Current_State = CA_STATE_HIGH;
	    machine->VBias = machine->param.CA.HighE;
	    Set_VBias(machine, machine->VBias);
      }
    }
    return (1000 * machine->interval_time);
    break;
  case CA_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in CA STATE!\n");
#endif
    return 0;
    break;
  }
}

float CC_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case CC_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start CC mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;

    machine->interval_time = machine->param.CC.SampleIntrval;
    machine->sample_rate = 1 / machine->interval_time;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->time_count = 0.0;
    machine->time_count2 = 0.0;
    machine->CC_charge = 0.0;
    machine->VBias = machine->param.CC.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = CC_STATE_HIGH;
    return (1000 * machine->param.CC.QuietTime);
    break;
  case CC_STATE_HIGH:
    machine->VBias = machine->param.CC.FinalE;
    Set_VBias(machine, machine->VBias);
    machine->time_count += machine->interval_time;
    machine->time_count2 += machine->interval_time;
    machine->CC_charge += Get_Current(machine) * machine->interval_time * 1000;
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,machine->CC_charge,buffer_channel);
    if (machine->time_count2 >= machine->param.CC.PulseWidth) {
      machine->segment_count += 1;
      machine->time_count2 = 0.0;
      if (machine->segment_count > machine->param.CC.NumberOfSteps){
        machine->Current_State = CC_STATE_DONE;
#if UART_DEBUG
    printf("CC done!\n");
#endif
      }
      else{
  	    machine->VBias = machine->param.CA.LowE;
  	    Set_VBias(machine, machine->VBias);
        machine->Current_State = CC_STATE_LOW;
      }
    }
    return (1000 * machine->interval_time);
    break;
  case CC_STATE_LOW:
    machine->VBias = machine->param.CC.InitE;
    Set_VBias(machine, machine->VBias);
    machine->time_count += machine->interval_time;
    machine->time_count2 += machine->interval_time;
    machine->CC_charge += Get_Current(machine) * machine->interval_time * 1000;
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,machine->CC_charge,buffer_channel);
    if (machine->time_count2 >= machine->param.CC.PulseWidth) {
      machine->segment_count += 1;
      machine->time_count2 = 0.0;
      if (machine->segment_count > machine->param.CC.NumberOfSteps){
        machine->Current_State = CC_STATE_DONE;
#if UART_DEBUG
    printf("CC done!\n");
#endif
      }
      else{
  	    machine->VBias = machine->param.CA.HighE;
  	    Set_VBias(machine, machine->VBias);
        machine->Current_State = CC_STATE_HIGH;
      }
    }
    return (1000 * machine->interval_time);
    break;
  case CC_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in CC STATE!\n");
#endif
    return 0;
    break;
  };
}

float DPV_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case DPV_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start DPV mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->VBias = machine->param.DPV.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = DPV_STATE_SAMPLE1;
    return (1000 * machine->param.DPV.QuietTime);
    break;
  case DPV_STATE_SAMPLE1:
    machine->current = Get_Current(machine);
    machine->Current_State = DPV_STATE_UP;
    return (1000 * machine->param.DPV.SampleWidth);
    break;
  case DPV_STATE_UP:
    Set_VBias(machine, machine->VBias + machine->param.DPV.Amplitude);
    machine->Current_State = DPV_STATE_SAMPLE2;
    return (1000 *
            (machine->param.DPV.PulseWidth - machine->param.DPV.SampleWidth));
    break;
  case DPV_STATE_SAMPLE2:
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,
				Get_Current(machine) - machine->current, buffer_channel);
    machine->Current_State = DPV_STATE_DOWN;
    return (1000 * machine->param.DPV.SampleWidth);
    break;
  case DPV_STATE_DOWN:
    machine->VBias += machine->param.DPV.IncrE;
    Set_VBias(machine, machine->VBias);
    if (machine->VBias > machine->param.DPV.FinalE) {
      machine->segment_count += 1;
      machine->Current_State = DPV_STATE_DONE;
#if UART_DEBUG
//    printf("DPV done!\n");
#endif
    } else
      machine->Current_State = DPV_STATE_SAMPLE1;
    return (1000 *
            (machine->param.DPV.PulsePeriod - machine->param.DPV.PulseWidth -
             machine->param.DPV.SampleWidth));
    break;
  case DPV_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;

    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in DPV STATE!\n");
#endif
    return 0;
    break;
  };
}

float NPV_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case NPV_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start NPV mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;


    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->VBias = machine->param.NPV.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = NPV_STATE_HIGH;
    return (1000 * machine->param.NPV.QuietTime);
    break;
  case NPV_STATE_HIGH:
    machine->VBias += machine->param.NPV.IncrE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = NPV_STATE_SAMPLE;
    return (1000 *
            (machine->param.NPV.PulseWidth - machine->param.NPV.SampleWidth));
    break;
  case NPV_STATE_SAMPLE:
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias, Get_Current(machine), buffer_channel);
    machine->Current_State = NPV_STATE_LOW;
    return (1000 * machine->param.NPV.SampleWidth);
    break;
  case NPV_STATE_LOW:
    Set_VBias(machine, machine->param.NPV.InitE);
    if (machine->VBias >= machine->param.NPV.FinalE) {
        machine->Current_State = NPV_STATE_DONE;
#if UART_DEBUG
    printf("NPV done!\n");
#endif
    } else {
        machine->Current_State = NPV_STATE_HIGH;
    }
    return (1000 *
            (machine->param.NPV.PulsePeriod - machine->param.NPV.PulseWidth));
    break;
  case NPV_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in NPV STATE!\n");
#endif
    return 0;
    break;
  }
}

float DNPV_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case DNPV_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start DNPV mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;
    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->VBias = machine->param.DNPV.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = DNPV_STATE_UP;
    return (1000 * machine->param.DNPV.QuietTime);
    break;
  case DNPV_STATE_UP:
    machine->VBias += machine->param.DNPV.IncrE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = DNPV_STATE_SAMPLE1;
    return (1000 * (machine->param.DNPV.PulseWidth1 -
                    machine->param.DNPV.SampleWidth));
    break;
  case DNPV_STATE_SAMPLE1:
    machine->current = Get_Current(machine);
    machine->Current_State = DNPV_STATE_AMPLITUDE;
    return (1000 * machine->param.DNPV.SampleWidth);
    break;
  case DNPV_STATE_AMPLITUDE:
    Set_VBias(machine, machine->VBias + machine->param.DNPV.Amplitude);
    machine->Current_State = DNPV_STATE_SAMPLE2;
    return (1000 * (machine->param.DNPV.PulseWidth2 -
                    machine->param.DNPV.SampleWidth));
    break;
  case DNPV_STATE_SAMPLE2:
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias - machine->param.DNPV.Amplitude,
			Get_Current(machine) - machine->current, buffer_channel);
    machine->Current_State = DNPV_STATE_LOW;
    return (1000 * machine->param.DNPV.SampleWidth);
    break;
  case DNPV_STATE_LOW:
    Set_VBias(machine, machine->param.DNPV.InitE);
    if (machine->VBias >= machine->param.DNPV.FinalE) {
        machine->Current_State = DNPV_STATE_DONE;
#if UART_DEBUG
    printf("DNPV done!\n");
#endif
    } else {
        machine->Current_State = DNPV_STATE_UP;
    }

    return (1000 *
            (machine->param.DNPV.PulsePeriod - machine->param.DNPV.PulseWidth1 -
             machine->param.DNPV.PulseWidth2));
    break;
  case DNPV_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in DNPV STATE!\n");
#endif
    return 0;
    break;
  };
}

float SWV_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case SWV_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start SWV mode:\n",machine->param.BLE.Channel+1);
#endif

  machine->sample_rate = machine->param.SWV.Frequency;
  machine->interval_time = 1 / machine->sample_rate;
	machine->StopFlag = 1;


    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->VBias = machine->param.SWV.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = SWV_STATE_DOWN;
    return (1000 * machine->param.SWV.QuietTime);
    break;
  case SWV_STATE_DOWN:
//#if UART_DEBUG
//  printf("Start SWV DOWN\n");
//#endif
    Set_VBias(machine, machine->VBias - machine->param.SWV.Amplitude);
    machine->Current_State = SWV_STATE_SAMPLE1;
    return (1000 * machine->interval_time / 2);
    break;
  case SWV_STATE_SAMPLE1:
    machine->current = Get_Current(machine);
    machine->Current_State = SWV_STATE_UP;
    return (1000 * machine->interval_time / 2);
    break;
  case SWV_STATE_UP:
    Set_VBias(machine, machine->VBias + machine->param.SWV.Amplitude);
    machine->Current_State = SWV_STATE_SAMPLE2;
    return (1000 * machine->interval_time / 2);
    break;
  case SWV_STATE_SAMPLE2:
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,
			Get_Current(machine) - machine->current, buffer_channel);
    machine->VBias += machine->param.SWV.IncrE;
    if (machine->VBias > machine->param.SWV.FinalE) {
        machine->Current_State = SWV_STATE_DONE;
#if UART_DEBUG
    printf("SWV done!\n");
#endif
    } else {
        machine->Current_State = SWV_STATE_DOWN;
    }
    return (1000 * machine->interval_time / 2);
    break;
  case SWV_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in SWV STATE!\n");
#endif
    return 1;
    break;
  };
}

float IT_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case IT_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start i-t mode:\n",machine->param.BLE.Channel+1);
#endif


  machine->StopFlag = 1;

    machine->interval_time = machine->param.IT.SampleIntrval;

    Sensitivity_set(machine);
    machine->VBias = machine->param.IT.InitE;
    machine->time_count = 0.000001;
    Set_VBias(machine,machine->VBias);
    machine->Current_State = IT_STATE_SAMPLE;
    return (1000 * machine->param.IT.QuietTime);
    break;
  case IT_STATE_SAMPLE:
//	    Set_VBias(machine,machine->VBias);

    if (machine->time_count >= machine->param.IT.RunTime) {
      machine->Current_State = IT_STATE_DONE;
    }
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,
			Get_Current(machine), buffer_channel);
    machine->time_count += machine->interval_time;
    return (1000 * machine->interval_time);
    break;
  case IT_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error:unknown state in i-t.\n");
#endif
    return 0;
    break;
  }
}

float DPA_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case DPA_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start DPA mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->time_count = 0.0;
    machine->VBias = machine->param.DPA.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = DPA_STATE_CLEAN;
    return (1000 * machine->param.DPA.QuietTime);
    break;
  case DPA_STATE_CLEAN:
//#if UART_DEBUG
//    printf("DPA_STATE_CLEAN:\n");
//#endif
    Set_VBias(machine, machine->param.DPA.CleaningE);
    machine->time_count += machine->param.DPA.CleaningT;
    machine->Current_State = DPA_STATE_E1;
    return (1000 * machine->param.DPA.CleaningT);
    break;
  case DPA_STATE_E1:
    Set_VBias(machine, machine->param.DPA.PulseE1);
    machine->time_count += machine->param.DPA.PulseT1/2;
    machine->Current_State = DPA_STATE_SAMPLE1;
    return (1000 * (machine->param.DPA.PulseT1/2));
    break;
  case DPA_STATE_SAMPLE1:
	    machine->time_count += machine->param.DPA.PulseT1/2;
    machine->current = Get_Current(machine);
    machine->Current_State = DPA_STATE_E2;
    return (1000 * (machine->param.DPA.PulseT1/2));
    break;
  case DPA_STATE_E2:
//#if UART_DEBUG
//    printf("DPA_STATE_E2:\n");
//#endif
    Set_VBias(machine, machine->param.DPA.PulseE2);
    machine->time_count += machine->param.DPA.PulseT2/2;
    machine->Current_State = DPA_STATE_SAMPLE2;
    return (1000 * machine->param.DPA.PulseT2/2);
    break;
  case DPA_STATE_SAMPLE2:
	    machine->time_count += machine->param.DPA.PulseT2/2;
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,
			machine->current - Get_Current(machine), buffer_channel);
    machine->segment_count++;
    machine->Current_State = machine->segment_count > machine->param.DPA.Cycles
                                 ? DPA_STATE_DONE
                                 : DPA_STATE_CLEAN;
    return (1000 * machine->param.DPA.PulseT2/2);
    break;
  case DPA_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in DPA STATE!\n");
#endif
    return 0;
    break;
  };
}

float DDPA_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case DDPA_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start DDPA mode:\n",machine->param.BLE.Channel+1);
#endif


	machine->StopFlag = 1;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->time_count = 0.0;
    machine->VBias = machine->param.DDPA.InitE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = DDPA_STATE_CLEAN1;
    return (1000 * machine->param.DDPA.QuietTime);
    break;
  case DDPA_STATE_CLEAN1:
    Set_VBias(machine, machine->param.DDPA.CleaningE);
    machine->time_count += machine->param.DDPA.CleaningT;
    machine->Current_State = DDPA_STATE_E1;
    return (1000 * machine->param.DDPA.CleaningT);
    break;
  case DDPA_STATE_E1:
    Set_VBias(machine, machine->param.DDPA.PulseE1);
    machine->time_count += machine->param.DDPA.PulseT1/2;
    machine->Current_State = DDPA_STATE_SAMPLE1;
    return (1000 * machine->param.DDPA.PulseT1/2);
    break;
  case DDPA_STATE_SAMPLE1:
	    machine->time_count += machine->param.DDPA.PulseT1/2;
    machine->current = Get_Current(machine);
    machine->Current_State = DDPA_STATE_E2;
    return (1000 * (machine->param.DDPA.PulseT1/2));
  case DDPA_STATE_E2:
    Set_VBias(machine, machine->param.DDPA.PulseE2);
    machine->time_count += machine->param.DDPA.PulseT2/2;
    machine->Current_State = DDPA_STATE_SAMPLE2;
    return (1000 * machine->param.DDPA.PulseT2/2);
    break;
  case DDPA_STATE_SAMPLE2:
	    machine->time_count += machine->param.DDPA.PulseT2/2;
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,
			machine->current - Get_Current(machine), buffer_channel);
    machine->Current_State = DDPA_STATE_CLEAN2;
    return (1000 * (machine->param.DDPA.PulseT2/2));
  case DDPA_STATE_CLEAN2:
    Set_VBias(machine, machine->param.DDPA.CleaningE2);
    machine->time_count += machine->param.DDPA.CleaningT2;
    machine->Current_State = DDPA_STATE_E3;
    return (1000 * machine->param.DDPA.CleaningT2);
    break;
  case DDPA_STATE_E3:
    Set_VBias(machine, machine->param.DDPA.PulseE3);
    machine->time_count += machine->param.DDPA.PulseT3/2;
    machine->Current_State = DDPA_STATE_E4;
    return (1000 * machine->param.DDPA.PulseT3/2);
    break;
  case DDPA_STATE_SAMPLE3:
	    machine->time_count += machine->param.DDPA.PulseT3/2;
    machine->current = Get_Current(machine);
    machine->Current_State = DDPA_STATE_E4;
    return (1000 * (machine->param.DDPA.PulseT3/2));
  case DDPA_STATE_E4:
    Set_VBias(machine, machine->param.DDPA.PulseE4);
    machine->time_count += machine->param.DDPA.PulseT4/2;
    machine->Current_State = DDPA_STATE_SAMPLE4;
    return (1000 * machine->param.DDPA.PulseT4/2);
    break;
  case DDPA_STATE_SAMPLE4:
	    machine->time_count += machine->param.DDPA.PulseT4/2;
	    machine->segment_count++;
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,
			machine->current - Get_Current(machine), buffer_channel);
    machine->Current_State =  machine->segment_count > machine->param.DDPA.Cycles
            ? DDPA_STATE_DONE
            : DDPA_STATE_CLEAN1;
#if UART_DEBUG
    if(machine->Current_State == DDPA_STATE_DONE){
    printf("DDPA done!\n");
    }
#endif
    return (1000 * (machine->param.DDPA.PulseT4/2));
    break;
  case DDPA_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in DDPA STATE!\n");
#endif
    return 0;
    break;
  };
}

float TPA_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case TPA_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start TPA mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->time_count = 0.0;
    Set_VBias(machine, machine->param.TPA.InitE);
    machine->VBias = machine->param.TPA.E3;
    machine->Current_State = TPA_STATE_E1;
    return (1000 * machine->param.TPA.QuietTime);
    break;
  case TPA_STATE_E1:
    Set_VBias(machine, machine->param.TPA.E1);
    machine->time_count += machine->param.TPA.D1;
    machine->Current_State = TPA_STATE_E2;
    return (1000 * machine->param.TPA.D1);
    break;
  case TPA_STATE_E2:
    Set_VBias(machine, machine->param.TPA.E2);
    machine->time_count += machine->param.TPA.D2;
    machine->Current_State = TPA_STATE_E3;
    return (1000 * machine->param.TPA.D2);
    break;
  case TPA_STATE_E3:
    machine->time_count += machine->param.TPA.D3/2;
    if (machine->param.TPA.IncrE != 0) {
    machine->VBias += machine->param.TPA.IncrE;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = TPA_STATE_SAMPLE;
    }
    else {
        machine->VBias = machine->param.TPA.E3;
        Set_VBias(machine, machine->VBias);
      machine->Current_State = TPA_STATE_SAMPLE;
    }
    return (1000 * machine->param.TPA.D3/2);
    break;
  case TPA_STATE_SAMPLE:
	    machine->time_count += machine->param.TPA.D3/2;
	    if (machine->param.TPA.IncrE != 0) {
	  	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->VBias,Get_Current(machine), buffer_channel);
	    }
	    else {
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,Get_Current(machine), buffer_channel);
	    }
	    machine->segment_count++;
	    if (machine->param.TPA.IncrE != 0) {
	      machine->Current_State = machine->VBias >= machine->param.TPA.FinalE
	                                   ? TPA_STATE_DONE
	                                   : TPA_STATE_E1;
	    }
	    else
	      machine->Current_State =
	          machine->segment_count > machine->param.TPA.Cycles ? TPA_STATE_DONE
	                                                             : TPA_STATE_E1;
	#if UART_DEBUG
	    if(machine->Current_State == TPA_STATE_DONE){
	    printf("TPA done!\n");
	    }
	#endif
	    return (1000 * machine->param.TPA.D3/2);
	    break;
  case TPA_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in TPA STATE!\n");
#endif
    return 0;
    break;
  };
}

float IPAD_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case IPAD_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start IPAD mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->time_count = 0.0;
    machine->time_count2 = 0.0;
    Set_VBias(machine, machine->param.IPAD.E1);
    machine->VBias = machine->param.IPAD.E3;
    machine->Current_State = IPAD_STATE_START;
    return (1000 * machine->param.IPAD.QuietTime);
    break;
  case IPAD_STATE_START:
//#if UART_DEBUG
//    printf("IPAD_STATE_START\n");
//#endif
    Set_VBias(machine, machine->param.IPAD.E1);
    machine->current = 0;
    machine->time_count += (machine->param.IPAD.T1-0.01);
    machine->Current_State = IPAD_STATE_SAMPLE;
    machine->Next_State = IPAD_STATE_UP;
    return (1000 * machine->param.IPAD.T1 - 10);
    break;
  case IPAD_STATE_UP:
//#if UART_DEBUG
//    printf("IPAD_STATE_UP\n");
//#endif
    machine->VBias += (machine->param.IPAD.E2 - machine->param.IPAD.E1) /
                      machine->param.IPAD.T2 * 0.01; // VBais up per 10msec;
    Set_VBias(machine, machine->VBias);
    machine->time_count += 0.01;
    machine->time_count2 += 0.01;
    if (machine->time_count2 >= machine->param.IPAD.T2 - 0.01) {
      machine->time_count2 = 0.0;
      machine->time_count += 0.01;
      machine->VBias = machine->param.IPAD.E2;
      machine->Current_State = IPAD_STATE_SAMPLE;
      machine->Next_State = IPAD_STATE_DOWN;
    }
    return (10);
    break;
  case IPAD_STATE_DOWN:
//#if UART_DEBUG
//    printf("IPAD_STATE_DOWN\n");
//#endif
    machine->VBias -= (machine->param.IPAD.E2 - machine->param.IPAD.E3) /
                      machine->param.IPAD.T3 * 0.01; // VBais up per 10msec;
    Set_VBias(machine, machine->VBias);
    machine->time_count += 0.01;
    machine->time_count2 += 0.01;
    if (machine->time_count2 >= machine->param.IPAD.T3 - 0.01) {
      machine->time_count2 = 0.0;
      machine->time_count += 0.01;
      machine->Current_State = IPAD_STATE_SAMPLE;
      machine->Next_State = IPAD_STATE_HOLD;
    }
    return (10);
    break;
  case IPAD_STATE_HOLD:
//#if UART_DEBUG
//    printf("IPAD_STATE_HOLD\n");
//#endif
    Set_VBias(machine, machine->param.IPAD.E4);
    machine->time_count += 0.01;
    machine->Current_State = IPAD_STATE_SAMPLE;
    machine->Next_State = IPAD_STATE_OXD;
    return (10);
    break;
  case IPAD_STATE_OXD:
//#if UART_DEBUG
//    printf("IPAD_STATE_OXD\n");
//#endif
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,machine->current / 4, buffer_channel);
    Set_VBias(machine, machine->param.IPAD.E5);
    machine->time_count += machine->param.IPAD.T5;
    machine->Current_State = IPAD_STATE_RED;
    return (1000 * machine->param.IPAD.T5);
    break;
  case IPAD_STATE_RED:
//#if UART_DEBUG
//    printf("IPAD_STATE_RED\n");
//#endif
    Set_VBias(machine, machine->param.IPAD.E6);
    machine->time_count += machine->param.IPAD.T6;
    machine->segment_count++;
    if (machine->segment_count > machine->param.IPAD.Cycles) {
      machine->Current_State = IPAD_STATE_DONE;
#if UART_DEBUG
    printf("IPAD done!\n");
#endif
    } else
      machine->Current_State = IPAD_STATE_START;
    return (1000 * machine->param.IPAD.T6);
    break;
  case IPAD_STATE_SAMPLE:
//#if UART_DEBUG
//    printf("IPAD_STATE_SAMPLE\n");
//#endif
    machine->current += Get_Current(machine);
    machine->Current_State = machine->Next_State;
    if (machine->Next_State == IPAD_STATE_OXD){
    	machine->time_count += (machine->param.IPAD.T4-0.01);
      return (1000 * machine->param.IPAD.T4 - 10);
    }
    else{
    	machine->time_count += 0.01;
      return (10);
    }
    break;
  case IPAD_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in IPAD STATE!\n");
#endif
    return 0;
    break;
  };
}

float SSF_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case SSF_STATE_INIT:

#if UART_DEBUG
	    printf("Channel[%ld] Start SSF mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;


    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->time_count = 0.0;
    machine->time_count2 = 0.0;
    machine->VBias = machine->param.SSF.InitE0;
    Set_VBias(machine, machine->VBias);
    machine->VBias = machine->param.SSF.InitE1;
    machine->Current_State = SSF_STATE_SWEEP1;
    return (1000 * machine->param.SSF.QuietTime);
    break;
  case SSF_STATE_SWEEP1:
    Set_VBias(machine, machine->VBias);
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 +=
        machine->param.SSF.SweepInt/ machine->param.SSF.ScanRate1 ;
    if (machine->param.SSF.InitE1 < machine->param.SSF.FinalE1){
    machine->VBias += machine->param.SSF.SweepInt;
    	if(machine->VBias > machine->param.SSF.FinalE1){
    		machine->Current_State = SSF_STATE_STEP1;
    		Set_VBias(machine, machine->param.SSF.E1);
    	}
    }
    else if(machine->param.SSF.InitE1 > machine->param.SSF.FinalE1){
        machine->VBias -= machine->param.SSF.SweepInt;
        if(machine->VBias < machine->param.SSF.FinalE1){
        	machine->Current_State = SSF_STATE_STEP1;
        	Set_VBias(machine, machine->param.SSF.E1);
        }
	}
    return (1000 * machine->param.SSF.SweepInt/machine->param.SSF.ScanRate1 );
    break;
  case SSF_STATE_STEP1:
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.SSF.StepInt;
    machine->time_count += machine->param.SSF.StepInt;
    if (machine->time_count >= machine->param.SSF.T1) {
      machine->time_count = 0.0;
      machine->Current_State = SSF_STATE_SWEEP2;
      Set_VBias(machine, machine->param.SSF.InitE2);
    }
    return (1000 * machine->param.SSF.StepInt);
    break;
  case SSF_STATE_SWEEP2:
    Set_VBias(machine, machine->VBias);
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 +=
        machine-> param.SSF.SweepInt/ machine->param.SSF.ScanRate2 ;
    if (machine->param.SSF.InitE2 < machine->param.SSF.FinalE2){
    machine->VBias += machine->param.SSF.SweepInt;
    	if(machine->VBias > machine->param.SSF.FinalE2){
    		machine->Current_State = SSF_STATE_STEP2;
        Set_VBias(machine, machine->param.SSF.E2);
    	}
    }
    else if(machine->param.SSF.InitE2 > machine->param.SSF.FinalE2){
        machine->VBias -= machine->param.SSF.SweepInt;
        if(machine->VBias < machine->param.SSF.FinalE2){
        	machine->Current_State = SSF_STATE_STEP2;
        Set_VBias(machine, machine->param.SSF.E2);
        }
	}
    return (1000 * machine->param.SSF.SweepInt/machine->param.SSF.ScanRate2 );
    break;
  case SSF_STATE_STEP2:
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.SSF.StepInt;
    machine->time_count += machine->param.SSF.StepInt;
    if (machine->time_count >= machine->param.SSF.T2) {
      machine->time_count = 0.0;
      machine->Current_State = SSF_STATE_SWEEP3;
      Set_VBias(machine, machine->param.SSF.InitE3);
    }
    return (1000 * machine->param.SSF.StepInt);
    break;
  case SSF_STATE_SWEEP3:
    Set_VBias(machine, machine->VBias);
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 +=
        machine-> param.SSF.SweepInt/ machine->param.SSF.ScanRate3 ;
    if (machine->param.SSF.InitE3 < machine->param.SSF.FinalE3){
    machine->VBias += machine->param.SSF.SweepInt;
    	if(machine->VBias > machine->param.SSF.FinalE3){
    		machine->Current_State = SSF_STATE_STEP3;
        Set_VBias(machine, machine->param.SSF.E3);
    	}
    }
    else if(machine->param.SSF.InitE3 > machine->param.SSF.FinalE3){
        machine->VBias -= machine->param.SSF.SweepInt;
        if(machine->VBias < machine->param.SSF.FinalE3){
        	machine->Current_State = SSF_STATE_STEP3;
        Set_VBias(machine, machine->param.SSF.E3);
        }
	}
    return (1000 * machine->param.SSF.SweepInt/machine->param.SSF.ScanRate3 );
    break;
  case SSF_STATE_STEP3:
	Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.SSF.StepInt;
    machine->time_count += machine->param.SSF.StepInt;
    if (machine->time_count >= machine->param.SSF.T3) {
      machine->time_count = 0.0;
      machine->Current_State = SSF_STATE_SWEEP4;
      Set_VBias(machine, machine->param.SSF.InitE4);
    }
    return (1000 * machine->param.SSF.StepInt);
    break;
  case SSF_STATE_SWEEP4:
    Set_VBias(machine, machine->VBias);
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 +=
        machine->param.SSF.SweepInt/ machine->param.SSF.ScanRate4 ;
    if (machine->param.SSF.InitE4 < machine->param.SSF.FinalE4){
    machine->VBias += machine->param.SSF.SweepInt;
    	if(machine->VBias > machine->param.SSF.FinalE4){
    		machine->Current_State = SSF_STATE_STEP4;
        Set_VBias(machine, machine->param.SSF.E4);
    	}
    }
    else if(machine->param.SSF.InitE4 > machine->param.SSF.FinalE4){
        machine->VBias -= machine->param.SSF.SweepInt;
        if(machine->VBias < machine->param.SSF.FinalE4){
        	machine->Current_State = SSF_STATE_STEP4;
        Set_VBias(machine, machine->param.SSF.E4);
        }
	}
    return (1000 * machine->param.SSF.SweepInt/machine->param.SSF.ScanRate4);
    break;
  case SSF_STATE_STEP4:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.SSF.StepInt;
    machine->time_count += machine->param.SSF.StepInt;
    if (machine->time_count >= machine->param.SSF.T4) {
      machine->time_count = 0.0;
      machine->Current_State = SSF_STATE_SWEEP5;
      Set_VBias(machine, machine->param.SSF.InitE5);
    }
    return (1000 * machine->param.SSF.StepInt);
    break;
  case SSF_STATE_SWEEP5:
    Set_VBias(machine, machine->VBias);
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 +=
        machine-> param.SSF.SweepInt/ machine->param.SSF.ScanRate5;
    if (machine->param.SSF.InitE5 < machine->param.SSF.FinalE5){
    machine->VBias += machine->param.SSF.SweepInt;
    	if(machine->VBias > machine->param.SSF.FinalE5){
    		machine->Current_State = SSF_STATE_STEP5;
        Set_VBias(machine, machine->param.SSF.E5);
    	}
    }
    else if(machine->param.SSF.InitE5 > machine->param.SSF.FinalE5){
        machine->VBias -= machine->param.SSF.SweepInt;
        if(machine->VBias < machine->param.SSF.FinalE5){
        	machine->Current_State = SSF_STATE_STEP5;
        Set_VBias(machine, machine->param.SSF.E5);
        }
	}
    return (1000 * machine-> param.SSF.SweepInt/ machine->param.SSF.ScanRate5);
    break;
  case SSF_STATE_STEP5:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.SSF.StepInt;
    machine->time_count += machine->param.SSF.StepInt;
    if (machine->time_count >= machine->param.SSF.T5) {
      machine->time_count = 0.0;
      machine->Current_State = SSF_STATE_SWEEP6;
      Set_VBias(machine, machine->param.SSF.InitE6);
    }
    return (1000 * machine->param.SSF.StepInt);
    break;
  case SSF_STATE_SWEEP6:
    Set_VBias(machine, machine->VBias);
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 +=
        machine-> param.SSF.SweepInt/ machine->param.SSF.ScanRate6;
    if (machine->param.SSF.InitE6 < machine->param.SSF.FinalE6){
    machine->VBias += machine->param.SSF.SweepInt;
    	if(machine->VBias > machine->param.SSF.FinalE6){
    		machine->Current_State = SSF_STATE_STEP6;
        Set_VBias(machine, machine->param.SSF.E6);
    	}
    }
    else if(machine->param.SSF.InitE6 > machine->param.SSF.FinalE6){
        machine->VBias -= machine->param.SSF.SweepInt;
        if(machine->VBias < machine->param.SSF.FinalE6){
        	machine->Current_State = SSF_STATE_STEP6;
        Set_VBias(machine, machine->param.SSF.E6);
        }
	}
    return (1000 * machine-> param.SSF.SweepInt/ machine->param.SSF.ScanRate6);
    break;
  case SSF_STATE_STEP6:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.SSF.StepInt;
    machine->time_count += machine->param.SSF.StepInt;
    if (machine->time_count >= machine->param.SSF.T6) {
      machine->time_count = 0.0;
      machine->Current_State = SSF_STATE_DONE;
#if UART_DEBUG
    printf("SSF done!\n");
#endif
      Set_VBias(machine, machine->param.SSF.InitE0);
    }
    return (1000 * machine->param.SSF.StepInt);
    break;
  case SSF_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in SSF STATE!%d\n",machine->Current_State);
#endif
    return 200;
    break;
  };
}

float STEP_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case STEP_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start STEP mode:\n",machine->param.BLE.Channel+1);
#endif

	machine->StopFlag = 1;

    Sensitivity_set(machine);
    machine->segment_count = 1;
    machine->time_count = 0.0;
    machine->time_count2 = 0.0;
    machine->VBias = 0.0;
    Set_VBias(machine, machine->VBias);
    machine->Current_State = STEP_STATE_STEP1;
    machine->VBias = machine->param.STEP.E1;
    return (1000 * machine->param.STEP.QuietTime);
    break;
  case STEP_STATE_STEP1:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T1) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP2;
      Set_VBias(machine, machine->param.STEP.E2);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP2:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T2) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP3;
      Set_VBias(machine, machine->param.STEP.E3);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP3:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T3) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP4;
      Set_VBias(machine, machine->param.STEP.E4);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP4:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T4) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP5;
      Set_VBias(machine, machine->param.STEP.E5);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP5:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T5) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP6;
      Set_VBias(machine, machine->param.STEP.E6);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP6:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T6) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP7;
      Set_VBias(machine, machine->param.STEP.E7);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP7:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T7) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP8;
      Set_VBias(machine, machine->param.STEP.E8);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP8:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T8) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP9;
      Set_VBias(machine, machine->param.STEP.E9);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP9:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T9) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP10;
      Set_VBias(machine, machine->param.STEP.E10);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP10:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T10) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP11;
      Set_VBias(machine, machine->param.STEP.E11);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP11:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T11) {
      machine->time_count = 0.0;
      machine->Current_State = STEP_STATE_STEP12;
      Set_VBias(machine, machine->param.STEP.E12);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_STEP12:
	    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count2,Get_Current(machine), buffer_channel);
    machine->time_count2 += machine->param.STEP.SampleIntrval;
    machine->time_count += machine->param.STEP.SampleIntrval;
    if (machine->time_count >= machine->param.STEP.T12) {
      machine->time_count = 0.0;
      machine->segment_count++;
      machine->Current_State =
          machine->segment_count >= machine->param.STEP.Cycles
              ? STEP_STATE_DONE
              : STEP_STATE_STEP1;
#if UART_DEBUG
    if(machine->Current_State == STEP_STATE_DONE){
    printf("STEP done!\n");
    }
#endif
      Set_VBias(machine, machine->param.STEP.E1);
    }
    return (1000 * machine->param.STEP.SampleIntrval);
    break;
  case STEP_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error in STEP STATE!\n");
#endif
    return 0;
    break;
  };
}

float OCPT_update(StateMachine *machine) {
  switch (machine->Current_State) {
  case OCPT_STATE_INIT:
#if UART_DEBUG
	    printf("Channel[%ld] Start OCPT mode:\n",machine->param.BLE.Channel+1);
#endif

  machine->StopFlag = 1;

    machine->interval_time = machine->param.OCPT.SampleIntrval;
    Sensitivity_set(machine);
    machine->VBias = 1.5;
    machine->time_count = 0.0;
    Set_VBias(machine,machine->VBias);
    machine->Current_State = OCPT_STATE_SAMPLE;
    return (100);
    break;
  case OCPT_STATE_SAMPLE:
#if UART_DEBUG
    printf("%d,%.8f,%.8f\n", (uint8_t)machine->param.BLE.Channel, machine->time_count,
    		(-ADS125X_ReadChannelVolt(&machine->adc, machine->OCP_CH)*73-75)/3);

#endif
    Ttans_Data_To_Buffer(machine->param.BLE.Channel,machine->time_count,
    		(-ADS125X_ReadChannelVolt(&machine->adc, machine->OCP_CH)*3/73+75/73), buffer_channel);
    machine->time_count += machine->interval_time;

    if (machine->time_count >= machine->param.OCPT.RunTime) {
      machine->Current_State = OCPT_STATE_DONE;
    }
    return (1000 * machine->interval_time);
    break;
  case OCPT_STATE_DONE:
	  machine->param.BLE.Mode = MODE_NONE;
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
#if UART_DEBUG
    printf("error:unknown state in OCPT.\n");
#endif
    return 0;
    break;
  }
}

float stateMachineUpdate(StateMachine *machine) {
	if(machine->StopFlag == 0){
		return 0;
	}
	if(machine->PauseFlag == 0){
		return 0;
	}
  switch (machine->param.BLE.Mode) {
  case MODE_CV:
    return (CV_update(machine));
    break;
  case MODE_LSV:
    return (LSV_update(machine));
    break;
  case MODE_SCV:
    return (SCV_update(machine));
    break;
  case MODE_TAFEL:
    return (TAFEL_update(machine));
    break;
  case MODE_CA:
    return (CA_update(machine));
    break;
  case MODE_CC:
    return (CC_update(machine));
    break;
  case MODE_DPV:
    return (DPV_update(machine));
    break;
  case MODE_NPV:
    return (NPV_update(machine));
    break;
  case MODE_DNPV:
    return (DNPV_update(machine));
    break;
  case MODE_SWV:
    return (SWV_update(machine));
    break;
  case MODE_IT:
    return (IT_update(machine));
    break;
  case MODE_DPA:
    return (DPA_update(machine));
    break;
  case MODE_DDPA:
    return (DDPA_update(machine));
    break;
  case MODE_TPA:
    return (TPA_update(machine));
    break;
  case MODE_IPAD:
    return (IPAD_update(machine));
    break;
  case MODE_SSF:
    return (SSF_update(machine));
    break;
  case MODE_STEP:
    return (STEP_update(machine));
    break;
  case MODE_OCPT:
    return (OCPT_update(machine));
    break;
  case MODE_NONE:
	  machine->StopFlag = 0;
    return 0;
    break;
  default:
    return 0;
    break;
  }
}

void Eprobe_loop(void) {
  uint8_t Stop_flag = 0;

  DAC856X_Write_Dac_Voltage(&dac1, DAC_CH_A, 1.5);
  DAC856X_Write_Dac_Voltage(&dac1, DAC_CH_B, 1.5);


  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
  HAL_Delay(1000);
  DAC856X_init(&dac1, &hspi1, DAC856X_GAIN_1);
  Set_VBias(&Machine[CHANNEL_1],0);
  Set_VBias(&Machine[CHANNEL_2],0);
  Set_VBias(&Machine[CHANNEL_3],0);
  Set_VBias(&Machine[CHANNEL_4],0);
  Set_VBias(&Machine[CHANNEL_5],0);
  Set_VBias(&Machine[CHANNEL_6],0);

  HAL_Delay(5);

  while (Loop_stop == 0) {
//#if UART_DEBUG
//    printf("%lu,\n",TimeTable);
//#endif
    if (TimeTable % 1000 == 0) {
      LED_TOGGLE();
    }
    	Stop_flag = 0;
    for (int i = 0; i < TOTAL_CHANNELS; ++i) {
      if (TimeTable >= Machine[i].timetable) {
        Machine[i].timetable += stateMachineUpdate(&Machine[i]);
        DMA_Buffer_Update();
      }
      Stop_flag += Machine[i].StopFlag;
    }
//    printf("%d\n",Stop_flag);
    if (!Stop_flag){
    	Loop_stop = 1;
    	TimeTable = 0;
    	DMA_Buffer_Update();
        for (int i = 0; i < TOTAL_CHANNELS; ++i) {
    	Set_VBias(&Machine[i],0);
        }
    	LED_OFF();
    	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
//    	printf("All Finished!\n");
    }
  }
}
