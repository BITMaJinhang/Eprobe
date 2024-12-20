
/*
 * ads125x.h
 *
 *  Created on: Sep 26, 2024
 *      Author: MaJinhang
 */

#ifndef ADS1255_H
#define	ADS1255_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"


// reference voltage
#define ADS125X_VREF 2.5f
#define ADS125X_OSC_FREQ (7680000)
#define ADS125X1_CS_GPIO_Port	GPIOB
#define ADS125X1_CS_Pin			GPIO_PIN_0
#define ADS125X1_DRDY_GPIO_Port	GPIOB
#define ADS125X1_DRDY_Pin		GPIO_PIN_1
#define ADS125X2_CS_GPIO_Port	GPIOA
#define ADS125X2_CS_Pin			GPIO_PIN_9
#define ADS125X2_DRDY_GPIO_Port	GPIOA
#define ADS125X2_DRDY_Pin		GPIO_PIN_8


//#define DEBUG_ADS1255
/*
const defaults = {
      clkinFrequency: 7680000,
      spiFrequency: 976563,
      spiMode: 1,
      vRef: 2.5,
    };
*/

//ADS1256 range
#define ADS125X_RANGE1		0x01
#define ADS125X_RANGE2		0x02
#define ADS125X_RANGE3		0x03
#define ADS125X_RANGE4		0x04

// ADS1256 Register
#define ADS125X_REG_STATUS 0x00
#define ADS125X_REG_MUX    0x01
#define ADS125X_REG_ADCON  0x02
#define ADS125X_REG_DRATE  0x03
#define ADS125X_REG_IO     0x04
#define ADS125X_REG_OFC0   0x05
#define ADS125X_REG_OFC1   0x06
#define ADS125X_REG_OFC2   0x07
#define ADS125X_REG_FSC0   0x08
#define ADS125X_REG_FSC1   0x09
#define ADS125X_REG_FSC2   0x0A

// ADS1256 Command
// Datasheet p. 34 / Table 24
// All of the commands are stand-alone
// except for the register reads and writes (RREG, WREG)
// which require a second command byte plus data

#define ADS125X_CMD_WAKEUP   0x00
#define ADS125X_CMD_RDATA    0x01
#define ADS125X_CMD_RDATAC   0x03
#define ADS125X_CMD_SDATAC   0x0f
#define ADS125X_CMD_RREG     0x10
#define ADS125X_CMD_WREG     0x50
#define ADS125X_CMD_SELFCAL  0xF0
#define ADS125X_CMD_SELFOCAL 0xF1
#define ADS125X_CMD_SELFGCAL 0xF2
#define ADS125X_CMD_SYSOCAL  0xF3
#define ADS125X_CMD_SYSGCAL  0xF4
#define ADS125X_CMD_SYNC     0xFC
#define ADS125X_CMD_STANDBY  0xFD
#define ADS125X_CMD_RESET    0xFE

#define ADS125X_BUFON   0x02
#define ADS125X_BUFOFF  0x00

#define ADS125X_CLKOUT_OFF     0x00
#define ADS125X_CLKOUT_1       0x20
#define ADS125X_CLKOUT_HALF    0x40
#define ADS125X_CLKOUT_QUARTER 0x60

#define ADS125X_RDATA     0x01    /* Read Data */
#define ADS125X_RDATAC    0x03    /* Read Data Continuously */
#define ADS125X_SDATAC    0x0F    /* Stop Read Data Continuously */
#define ADS125X_RREG      0x10    /* Read from REG */
#define ADS125X_WREG      0x50    /* Write to REG */
#define ADS125X_SELFCAL   0xF0    /* Offset and Gain Self-Calibration */
#define ADS125X_SELFOCAL  0xF1    /* Offset Self-Calibration */
#define ADS125X_SELFGCAL  0xF2    /* Gain Self-Calibration */
#define ADS125X_SYSOCAL   0xF3    /* System Offset Calibration */
#define ADS125X_SYSGCAL   0xF4    /* System Gain Calibration */
#define ADS125X_SYNC      0xFC    /* Synchronize the A/D Conversion */
#define ADS125X_STANDBY   0xFD    /* Begin Standby Mode */
#define ADS125X_RESET     0xFE    /* Reset to Power-Up Values */
#define ADS125X_WAKEUP    0xFF    /* Completes SYNC and Exits Standby Mode */

// multiplexer codes
#define ADS125X_MUXP_AIN0 0x00
#define ADS125X_MUXP_AIN1 0x10
#define ADS125X_MUXP_AIN2 0x20
#define ADS125X_MUXP_AIN3 0x30
#define ADS125X_MUXP_AIN4 0x40
#define ADS125X_MUXP_AIN5 0x50
#define ADS125X_MUXP_AIN6 0x60
#define ADS125X_MUXP_AIN7 0x70
#define ADS125X_MUXP_AINCOM 0x80

#define ADS125X_MUXN_AIN0 0x00
#define ADS125X_MUXN_AIN1 0x01
#define ADS125X_MUXN_AIN2 0x02
#define ADS125X_MUXN_AIN3 0x03
#define ADS125X_MUXN_AIN4 0x04
#define ADS125X_MUXN_AIN5 0x05
#define ADS125X_MUXN_AIN6 0x06
#define ADS125X_MUXN_AIN7 0x07
#define ADS125X_MUXN_AINCOM 0x08

#define ADS125X_CHANNEL_01	0x01
#define ADS125X_CHANNEL_23	0x23
#define ADS125X_CHANNEL_45	0x45
#define ADS125X_CHANNEL_67	0x67
#define ADS125X_CHANNEL_08	0x08
#define ADS125X_CHANNEL_18	0x18
#define ADS125X_CHANNEL_28	0x28
#define ADS125X_CHANNEL_38	0x38
#define ADS125X_CHANNEL_48	0x48
#define ADS125X_CHANNEL_58	0x58
#define ADS125X_CHANNEL_68	0x68
#define ADS125X_CHANNEL_78	0x78
#define ADS125X_CHANNEL_88	0x78



// gain codes
#define ADS125X_PGA1    0x00
#define ADS125X_PGA2    0x01
#define ADS125X_PGA4    0x02
#define ADS125X_PGA8    0x03
#define ADS125X_PGA16   0x04
#define ADS125X_PGA32   0x05
#define ADS125X_PGA64   0x06

// data rate codes
/** @note: Data Rate vary depending on crystal frequency.
  * Data rates listed below assumes the crystal frequency is 7.68Mhz
  * for other frequency consult the datasheet.
  */
#define ADS125X_DRATE_30000SPS 0xF0
#define ADS125X_DRATE_15000SPS 0xE0
#define ADS125X_DRATE_7500SPS 0xD0
#define ADS125X_DRATE_3750SPS 0xC0
#define ADS125X_DRATE_2000SPS 0xB0
#define ADS125X_DRATE_1000SPS 0xA1
#define ADS125X_DRATE_500SPS 0x92
#define ADS125X_DRATE_100SPS 0x82
#define ADS125X_DRATE_60SPS 0x72
#define ADS125X_DRATE_50SPS 0x63
#define ADS125X_DRATE_30SPS 0x53
#define ADS125X_DRATE_25SPS 0x43
#define ADS125X_DRATE_15SPS 0x33
#define ADS125X_DRATE_10SPS 0x23
#define ADS125X_DRATE_5SPS 0x13
#define ADS125X_DRATE_2_5SPS 0x03

// Struct "Object"
typedef struct {
	SPI_HandleTypeDef 	*hspix;
    float 				vref;
    uint8_t 			pga;
    float 				convFactor;
    uint32_t 			oscFreq;
    GPIO_TypeDef 		*csPort;
    uint16_t     		csPin;
    GPIO_TypeDef 		*drdyPort;
    uint16_t    		drdyPin;
    uint8_t				range[8];
} ADS125X_t;

void Delay_us(uint32_t Delay);
uint8_t  ADS125X_CS              (ADS125X_t *ads, uint8_t on);
uint8_t  ADS125X_DRDY_Wait       (ADS125X_t *ads );
uint8_t  ADS125X_Init            (ADS125X_t *ads, SPI_HandleTypeDef *hspi, uint8_t drate, uint8_t gain, uint8_t buffer_en);
uint8_t  ADS125X_Register_Read   (ADS125X_t *ads, uint8_t reg, uint8_t* pData, uint8_t n);
uint8_t  ADS125X_Register_Write  (ADS125X_t *ads, uint8_t reg, uint8_t data);
uint8_t  ADS125X_CMD_Send        (ADS125X_t *ads, uint8_t cmd);
void     ADS125X_ADC_Code2Volt   (ADS125X_t *ads, int32_t *pCode, float *pVolt, uint16_t size);
float    ADS125X_ADC_ReadVolt    (ADS125X_t *ads);

void     ADS125X_Channel_Set     (ADS125X_t *ads, int8_t chan);
uint8_t  ADS125X_ChannelDiff_Set (ADS125X_t *ads, int8_t p_chan, int8_t n_chan);
// float    ADS125X_Read_Channel    (ADS125X_t *ads );

uint8_t  ADS125X_Delay_Cycles    (ADS125X_t *ads, uint32_t cycles);
uint32_t ADS125X_read_uint24     (ADS125X_t *ads );
uint32_t ADS125X_read_uint32     (ADS125X_t *ads );
float    ADS125X_read_float32    (ADS125X_t *ads );

void ADS125X_Range_Set(ADS125X_t *ads, int8_t channel, int8_t range);
float ADS125X_ReadChannelVolt(ADS125X_t *ads, int8_t channel);
uint8_t ADS125X_Register_Read(ADS125X_t *ads, uint8_t reg, uint8_t* pData, uint8_t n);

#endif	/* ADS1255_H */

