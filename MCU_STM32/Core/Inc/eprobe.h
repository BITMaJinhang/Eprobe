/*
 * eprobe.h
 *
 *  Created on: Jun 12, 2024
 *      Author: MaJinhang
 */

#ifndef USER_EPROBE_H_
#define USER_EPROBE_H_


#include "main.h"



#define UART_DEBUG	0
#define BLE_DEBUG	0
#define PROBE_EDITION 0

#define SENS_SELECTA0_Port GPIOB
#define SENS_SELECTA0_Pin GPIO_PIN_5
#define SENS_SELECTA1_Port GPIOB
#define SENS_SELECTA1_Pin GPIO_PIN_4

#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_1

#define Ref_Volt_Set1	DAC856X_Write_Dac_Voltage(&dac1, DAC_CH_A, 1.5)
#define Ref_Volt_Set2	DAC856X_Write_Dac_Voltage(&dac1, DAC_CH_B, 1.5)

#define BUFFER_SIZE 1

#define Buffer_Channel_A 0
#define Buffer_Channel_B 1

typedef enum {
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	TOTAL_CHANNELS,
	CHANNEL_CMD = 255
} CHANNEL_TYPE;

typedef enum {
	MODE_CV,
	MODE_LSV,
	MODE_SCV,
	MODE_TAFEL,
	MODE_CA,
	MODE_CC,
	MODE_DPV,
	MODE_NPV,
	MODE_DNPV,
	MODE_SWV,
	MODE_IT,
	MODE_DPA,
	MODE_DDPA,
	MODE_TPA,
	MODE_IPAD,
	MODE_SSF,
	MODE_STEP,
	MODE_OCPT,
	MODE_NONE,
	TOTAL_MODES
} MODE_TYPE;

typedef enum {
    DIRECTION_NEG,
    DIRECTION_POS
} POT_DIRECTION_TYPE;

typedef enum {
  SENSITIVITY_1, //MIN
  SENSITIVITY_2,
  SENSITIVITY_3,
  SENSITIVITY_4//MAX(lowest FSR)
} POT_SENSITIVITY_TYPE;

#define STATE_INIT 0
#define STATE_DONE 255

typedef enum {
    CV_STATE_INIT = STATE_INIT,
    CV_STATE_UP,
    CV_STATE_DOWN,
    CV_STATE_DONE = STATE_DONE
} CV_STATE_TYPE;

typedef enum {
	LSV_STATE_INIT = STATE_INIT,
	LSV_STATE_UP,
	LSV_STATE_DONE = STATE_DONE
} LSV_STATE_TYPE;

typedef enum {
	SCV_STATE_INIT = STATE_INIT,
	SCV_STATE_UP,
	SCV_STATE_SAMPLE,
	SCV_STATE_DOWN,
	SCV_STATE_DONE = STATE_DONE
} SCV_STATE_TYPE;

typedef enum {
	TAFEL_STATE_INIT = STATE_INIT,
	TAFEL_STATE_UP,
	TAFEL_STATE_HOLD,
	TAFEL_STATE_DOWN,
	TAFEL_STATE_DONE = STATE_DONE
} TAFEL_STATE_TYPE;

typedef enum {
	CA_STATE_INIT = STATE_INIT,
	CA_STATE_HIGH,
	CA_STATE_LOW,
	CA_STATE_DONE = STATE_DONE
} CA_STATE_TYPE;

typedef enum {
	CC_STATE_INIT = STATE_INIT,
	CC_STATE_HIGH,
	CC_STATE_LOW,
	CC_STATE_DONE =STATE_DONE
} CC_STATE_TYPE;

typedef enum {
	DPV_STATE_INIT = STATE_INIT,
	DPV_STATE_UP,
	DPV_STATE_SAMPLE1,
	DPV_STATE_DOWN,
	DPV_STATE_SAMPLE2,
	DPV_STATE_DONE = STATE_DONE
} DPV_STATE_TYPE;

typedef enum {
	NPV_STATE_INIT = STATE_INIT,
	NPV_STATE_LOW,
	NPV_STATE_HIGH,
	NPV_STATE_SAMPLE,
	NPV_STATE_DONE = STATE_DONE
} NPV_STATE_TYPE;

typedef enum {
	DNPV_STATE_INIT = STATE_INIT,
	DNPV_STATE_LOW,
	DNPV_STATE_UP,
	DNPV_STATE_SAMPLE1,
	DNPV_STATE_AMPLITUDE,
	DNPV_STATE_SAMPLE2,
	DNPV_STATE_DONE = STATE_DONE
} DNPV_STATE_TYPE;

typedef enum {
SWV_STATE_INIT = STATE_INIT,
SWV_STATE_UP,
SWV_STATE_SAMPLE1,
SWV_STATE_DOWN,
SWV_STATE_SAMPLE2,
SWV_STATE_DONE = STATE_DONE
} SWV_STATE_TYPE;

typedef enum {
IT_STATE_INIT = STATE_INIT,
IT_STATE_SAMPLE,
IT_STATE_DONE = STATE_DONE
} IT_STATE_TYPE;

typedef enum {
DPA_STATE_INIT = STATE_INIT,
DPA_STATE_CLEAN,
DPA_STATE_E1,
DPA_STATE_SAMPLE1,
DPA_STATE_E2,
DPA_STATE_SAMPLE2,
DPA_STATE_DONE = STATE_DONE
} DPA_STATE_TYPE;

typedef enum {
DDPA_STATE_INIT = STATE_INIT,
DDPA_STATE_CLEAN1,
DDPA_STATE_E1,
DDPA_STATE_SAMPLE1,
DDPA_STATE_E2,
DDPA_STATE_SAMPLE2,
DDPA_STATE_CLEAN2,
DDPA_STATE_E3,
DDPA_STATE_SAMPLE3,
DDPA_STATE_E4,
DDPA_STATE_SAMPLE4,
DDPA_STATE_DONE = STATE_DONE
} DDPA_STATE_TYPE;

typedef enum {
TPA_STATE_INIT = STATE_INIT,
TPA_STATE_E1,
TPA_STATE_E2,
TPA_STATE_E3,
TPA_STATE_SAMPLE,
TPA_STATE_DONE = STATE_DONE
} TPA_STATE_TYPE;

typedef enum {
IPAD_STATE_INIT = STATE_INIT,
IPAD_STATE_START,
IPAD_STATE_UP,
IPAD_STATE_DOWN,
IPAD_STATE_HOLD,
IPAD_STATE_OXD,
IPAD_STATE_RED,
IPAD_STATE_SAMPLE,
IPAD_STATE_DONE = STATE_DONE
} IPAD_STATE_TYPE;

typedef enum {
SSF_STATE_INIT = STATE_INIT,
SSF_STATE_SWEEP1,
SSF_STATE_SWEEP2,
SSF_STATE_SWEEP3,
SSF_STATE_SWEEP4,
SSF_STATE_SWEEP5,
SSF_STATE_SWEEP6,
SSF_STATE_STEP1,
SSF_STATE_STEP2,
SSF_STATE_STEP3,
SSF_STATE_STEP4,
SSF_STATE_STEP5,
SSF_STATE_STEP6,
SSF_STATE_DONE = STATE_DONE
} SSF_STATE_TYPE;

typedef enum {
STEP_STATE_INIT = STATE_INIT,
STEP_STATE_STEP1,
STEP_STATE_STEP2,
STEP_STATE_STEP3,
STEP_STATE_STEP4,
STEP_STATE_STEP5,
STEP_STATE_STEP6,
STEP_STATE_STEP7,
STEP_STATE_STEP8,
STEP_STATE_STEP9,
STEP_STATE_STEP10,
STEP_STATE_STEP11,
STEP_STATE_STEP12,
STEP_STATE_DONE = STATE_DONE
} STEP_STATE_TYPE;

typedef enum {
OCPT_STATE_INIT = STATE_INIT,
OCPT_STATE_SAMPLE,
OCPT_STATE_DONE = STATE_DONE
} OCPT_STATE_TYPE;

typedef union{
	struct {
	    uint32_t Channel;
	    uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float BLE_params[28];
	} BLE;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float HighE;
		float LowE;
		float FinalE;
	    float direct;
		float ScanRate;
		float Segments;
		float SampleInt;
		float QuietTime;
	} CV;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float FinalE;
		float ScanRate;
		float SampleInt;
		float QuietTime;
	} LSV;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float FinalE;
		float Segments;
		float QuietTime;
		float IncrE;
		float SampleWidth;
		float StepPeriod;
	} SCV;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float FinalE;
		float ScanRate;
		float Segments;
		float QuietTime;
		float IncrE;
		float HoldTime;
	} TAFEL;
	struct{
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float HighE;
		float LowE;
	    float direct;
		float QuietTime;
		float NumberOfSteps;
		float PulseWidth;
		float SampleIntrval;
	}CA;
	struct{
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float FinalE;
		float QuietTime;
		float NumberOfSteps;
		float PulseWidth;
		float SampleIntrval;
	}CC;
	struct{
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float FinalE;
		float QuietTime;
		float IncrE;
		float SampleWidth;
		float PulseWidth;
		float Amplitude;
		float PulsePeriod;
	}DPV;
	struct{
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float FinalE;
		float QuietTime;
		float IncrE;
		float SampleWidth;
		float PulseWidth;
		float PulsePeriod;
	}NPV;
	struct{
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float FinalE;
		float QuietTime;
		float IncrE;
		float SampleWidth;
		float Amplitude;
		float PulsePeriod;
		float PulseWidth1;
		float PulseWidth2;
	}DNPV;
	struct{
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float FinalE;
		float QuietTime;
		float IncrE;
		float Amplitude;
		float Frequency;
	}SWV;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float QuietTime;
		float SampleIntrval;
		float RunTime;
		float ScalesDuringRun;
	} IT;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float QuietTime;
		float ScalesDuringRun;
		float CleaningE;
		float CleaningT;
		float PulseE1;
		float PulseT1;
		float PulseE2;
		float PulseT2;
		float Cycles;
	} DPA;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float QuietTime;
		float ScalesDuringRun;
		float CleaningE;
		float CleaningT;
		float PulseE1;
		float PulseT1;
		float PulseE2;
		float PulseT2;
		float Cycles;
		float CleaningE2;
		float CleaningT2;
		float PulseE3;
		float PulseT3;
		float PulseE4;
		float PulseT4;
	} DDPA;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
	    float FinalE;
		float QuietTime;
	    float IncrE;
	    float ScalesDuringRun;
		float E1;
		float D1;
		float E2;
		float D2;
		float Cycles;
		float E3;
		float D3;
	} TPA;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
		float QuietTime;
		float E1;
		float T1;
		float E2;
		float T2;
		float E3;
		float T3;
		float E4;
		float T4;
		float E5;
		float T5;
		float E6;
		float T6;
		float Cycles;
	} IPAD;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
		float InitE0;
		float InitE1;
		float ScanRate1;
		float FinalE1;
		float InitE2;
		float ScanRate2;
		float FinalE2;
		float InitE3;
		float ScanRate3;
		float FinalE3;
		float InitE4;
		float ScanRate4;
		float FinalE4;
		float InitE5;
		float ScanRate5;
		float FinalE5;
		float InitE6;
		float ScanRate6;
		float FinalE6;
		float QuietTime;
		float E1;
		float T1;
		float E2;
		float T2;
		float E3;
		float T3;
		float E4;
		float T4;
		float E5;
		float T5;
		float E6;
		float T6;
		float SweepInt;
		float StepInt;
	} SSF;
	struct {
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
	    float InitE;
		float QuietTime;
		float SampleIntrval;
		float E1;
		float T1;
		float E2;
		float T2;
		float E3;
		float T3;
		float E4;
		float T4;
		float E5;
		float T5;
		float E6;
		float T6;
		float E7;
		float T7;
		float E8;
		float T8;
		float E9;
		float T9;
		float E10;
		float T10;
		float E11;
		float T11;
		float E12;
		float T12;
		float Cycles;
	} STEP;
	struct{
	    uint32_t Channel;
		uint32_t Mode;
	    uint32_t Sensitivity;
	    uint32_t Command;
		float HighE;
		float LowE;
		float SampleIntrval;
		float RunTime;
	}OCPT;
}Eprobe_param_t;

typedef struct {
	Eprobe_param_t param;
	uint8_t Current_State;
	uint8_t Next_State;
	uint32_t segment_count;
	float timetable;
	float time_count;
	float time_count2;
	float sample_rate;
	float interval_time;
	float VBias;
	float R_SENS;
	float CC_charge;
	float data_tx_x;
	float data_tx_y;
	float data_tx_z;
	float data_tx_m;
	float data_tx_n;
	float current;
	CHANNEL_SELECT DAC_CH;
	ADS125X_t adc;
	uint8_t ADC_CH;
	uint8_t OCP_CH;
	uint8_t StopFlag;	//StopFlag = 0, Channel stop
	uint8_t PauseFlag;	//PauseFlag = 0, Channel pause
	float pause_delta_time;		
} StateMachine;




void Eprobe_loop(void);
uint8_t Set_VBias(StateMachine *machine,float vbias);
float Get_Current(StateMachine *machine);
void State_Machine_Init(void);
uint8_t LED_TOGGLE(void);
uint8_t LED_OFF(void);
uint8_t LED_ON(void);


#endif /* USER_EPROBE_H_ */
