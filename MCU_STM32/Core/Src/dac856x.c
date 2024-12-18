/*
 * dac856x.c
 *
 *  Created on: 2024年5月6日
 *      Author: MaJinhang
 */


#include "main.h"



/*static dac8568_reg_t dac8568_reg;
 */


uint8_t DAC856X_init(DAC856X_t *dac ,SPI_HandleTypeDef *hspi, uint8_t gain){

	dac->hspix = hspi;
	dac->gain = gain;
	DAC856X_CS(dac, 0);
#ifdef DEBUG_DAC856X
	printf("DAC856X_CS/n");
#endif

	dac->reg.raw = DAC856X_DEFAULT;
	DAC856X_Register_Write(dac);
#ifdef DEBUG_DAC856X
	printf("DAC856X_Register_Write");
#endif
	dac->reg.raw = DAC856X_DEFAULT;
	dac->reg.field.data = DATA_POWER_UP_INT_REF_STATIC;
	dac->reg.field.feature = FEATURE_POWER_UP_INT_REF_STATIC;
	dac->reg.field.control = CONTROL_SETUP_STATIC_MODE;
	DAC856X_Register_Write(dac);

	dac->reg.raw = DAC856X_DEFAULT;
	dac->reg.field.control = CONTROL_POWER_DOWN_COMM;
	dac->reg.byte[0] = 0xFF;
	DAC856X_Register_Write(dac);

	  DAC856X_Write_Dac_Voltage(dac, DAC_CH_A, 1.5);
	  DAC856X_Write_Dac_Voltage(dac, DAC_CH_B, 1.5);
	  DAC856X_Write_Dac_Voltage(dac, DAC_CH_C, 0.5);
	  DAC856X_Write_Dac_Voltage(dac, DAC_CH_D, 0.5);
	  DAC856X_Write_Dac_Voltage(dac, DAC_CH_E, 0.5);
	  DAC856X_Write_Dac_Voltage(dac, DAC_CH_F, 0.5);
	  DAC856X_Write_Dac_Voltage(dac, DAC_CH_G, 0.5);
	  DAC856X_Write_Dac_Voltage(dac, DAC_CH_H, 0.5);


	return 0;
}

/**
  * @brief  toggles chip select pin of DAC
  * @param  *dac pointer to ads handle
  * @param  on [0 = unselect, 1 = select]
  */
uint8_t DAC856X_CS(DAC856X_t *dac, uint8_t on)
{
  if(on)
	  HAL_GPIO_WritePin( dac->csPort, dac->csPin, GPIO_PIN_RESET);
  else
	  HAL_GPIO_WritePin( dac->csPort, dac->csPin, GPIO_PIN_SET);
	return 0;
}

/**
  * @brief  writes to internal registers
  * @param  *ads pointer to ads handle
  * @param  reg  first register to write to
  * @param  payload to write to register
  * @return
  * @see    Datasheet Fig. 35 WREG Command Example
  */
uint8_t DAC856X_Register_Write(DAC856X_t *dac)
{


	DAC856X_CS(dac, 1);
	HAL_SPI_Transmit(dac->hspix, dac->reg.byte+3, 1, 10);
	HAL_SPI_Transmit(dac->hspix, dac->reg.byte+2, 1, 10);
	HAL_SPI_Transmit(dac->hspix, dac->reg.byte+1, 1, 10);
	HAL_SPI_Transmit(dac->hspix, dac->reg.byte, 1, 10);
	DAC856X_CS(dac, 0);
	return 0;
}


uint8_t DAC856X_Write_Dac(DAC856X_t *dac, CHANNEL_SELECT chn, uint16_t val){
	dac->reg.raw = DAC856X_DEFAULT;
	dac->reg.field.data = val;
	dac->reg.field.address = chn;
	dac->reg.field.control = CONTROL_WRITE_TO_DAC_CH_AND_UPDATE_SINGLE_REG;
	DAC856X_Register_Write(dac);
	return 0;
}

uint8_t DAC856X_Write_Dac_Voltage(DAC856X_t *dac, CHANNEL_SELECT chn, float val){
	dac->reg.raw = DAC856X_DEFAULT;
	dac->reg.field.control = CONTROL_WRITE_TO_DAC_CH_AND_UPDATE_SINGLE_REG;
	dac->reg.field.address = chn;
	dac->reg.field.data = (uint16_t)(val/DAC856X_VREF/dac->gain*(1<<15));
	DAC856X_Register_Write(dac);
    return 0;
}
