/*
 * ds18b20.c
 *
 *  Created on: Oct 21, 2024
 *      Author: MaJinhang
 */

#include "main.h"


uint8_t DS18B20_Init(void)
{
  DS18B20_Mode_Out_PP();           

  DS18B20_Dout_HIGH();  						

  DS18B20_Rst();        					

  return DS18B20_Presence ();  			
}



void DS18B20_Mode_IPU(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin   = DS18b20_GPIO_Pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  HAL_GPIO_Init(DS18b20_GPIO_Port, &GPIO_InitStruct);

}


void DS18B20_Mode_Out_PP(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;


  GPIO_InitStruct.Pin = DS18b20_GPIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(DS18b20_GPIO_Port, &GPIO_InitStruct);
}

void DS18B20_Rst(void)
{
   DS18B20_Mode_Out_PP(); 
   DS18B20_Dout_LOW();    
   DS18B20_Delay(750);    
   DS18B20_Dout_HIGH();   
   DS18B20_Delay(15);     
}



uint8_t DS18B20_Presence(void)
{
   uint8_t pulse_time = 0;
   DS18B20_Mode_IPU();


   while( DS18B20_Data_IN() && pulse_time<100 )
   {
      pulse_time++;
      DS18B20_Delay(1);
   }
   if( pulse_time >=100 )
      return 1;
   else
      pulse_time = 0;

   while( !DS18B20_Data_IN() && pulse_time<240 )
   {
       pulse_time++;
       DS18B20_Delay(1);
   }
   if( pulse_time >=240 ){
//	   printf("DS18B20_Presence 1\n");
       return 1;
   }
   else{
//       printf("DS18B20_Presence 0\n");
       return 0;
   }
}


uint8_t DS18B20_ReadBit(void)
{
   uint8_t dat;

   DS18B20_Mode_Out_PP();
   DS18B20_Dout_LOW();
   DS18B20_Delay(10);

   DS18B20_Mode_IPU();
   Delay_us(2);

   if( DS18B20_Data_IN() == GPIO_PIN_SET ){
           dat = 1;
//   printf("DS18B20_ReadBit dat = %d\n",dat);
           }

   else{
           dat = 0;
//   printf("DS18B20_ReadBit dat = %d\n",dat);
           }

   DS18B20_Delay(45);

   return dat;
}


uint8_t DS18B20_ReadByte(void)
{
   uint8_t i, j, dat = 0;
   for(i=0; i<8; i++)
   {
      j = DS18B20_ReadBit();
      dat = (dat) | (j<<i);
   }
//   printf("DS18B20_ReadByte dat = %d\n",dat);

   return dat;
}


void DS18B20_WriteByte(uint8_t dat)
{
   uint8_t i, testb;
   DS18B20_Mode_Out_PP();
   for( i=0; i<8; i++ )
   {
      testb = dat&0x01;
      dat = dat>>1;
      if (testb)
      {
         DS18B20_Dout_LOW();
         DS18B20_Delay(8);

         DS18B20_Dout_HIGH();
         DS18B20_Delay(58);
      }
      else
      {
         DS18B20_Dout_LOW();
         DS18B20_Delay(70);

         DS18B20_Dout_HIGH();
         DS18B20_Delay(5);
      }
//      printf("DS18B20_WriteByte dat[%d] = %d\n",i, testb);
   }
}


void DS18B20_SkipRom ( void )
{
   DS18B20_Rst();
   DS18B20_Presence();
   DS18B20_WriteByte(0XCC);               
//   printf("DS18B20_SkipRom\n");
}


float DS18B20_GetTemp_SkipRom ( void )
{
   uint8_t tpmsb, tplsb;
   short s_tem;
   float f_tem;

   DS18B20_SkipRom ();
   DS18B20_WriteByte(0X44);                              

   DS18B20_SkipRom ();
	 DS18B20_WriteByte(0XBE);                              

   tplsb = DS18B20_ReadByte();
//   printf("DS18B20_GetTemp_SkipRom tplsb = %d\n",tplsb);

   tpmsb = DS18B20_ReadByte();
//   printf("DS18B20_GetTemp_SkipRom tpmsb = %d\n",tpmsb);

   s_tem = tpmsb<<8;
   s_tem = s_tem | tplsb;

   if( s_tem < 0 )              
     f_tem = (~s_tem+1) * 0.0625;
   else
     f_tem = s_tem * 0.0625;

   return f_tem;
}


#define CPU_FREQUENCY_MHZ   (int)(HAL_RCC_GetHCLKFreq()/1000000)		
{
   int last, curr, val;
   int temp;

   while (delay != 0)
   {
      temp = delay > 900 ? 900 : delay;
      last = SysTick->VAL;
      curr = last - CPU_FREQUENCY_MHZ * temp;
      if (curr >= 0)
      {
         do
         {
             val = SysTick->VAL;
         }
         while ((val < last) && (val >= curr));
      }
      else
      {
         curr += CPU_FREQUENCY_MHZ * 1000;
         do
         {
             val = SysTick->VAL;
         }
         while ((val <= last) || (val > curr));
      }
      delay -= temp;
    }
}

