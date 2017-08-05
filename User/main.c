/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/

#include <stdio.h>
#include "stddef.h"
#include "key.h"
#include "motor.h"
#include "spi.h"
#include "stm32f10x_spi.h"
#include "lis3dh_driver.h"

int main()
{
	u8 LcdState=0;
	u8 KeyValue=0;

	KEY_Init();
	MotorInit();
	SPI2_Init();
	SPI2_SetSpeed(SPI_BaudRatePrescaler_256);
	LIS3DH_Init();

	KeyValue=KEY_Scan(LcdState);
	MotorFWD(1);/*正转一步*/
	MotorREV(1);/*反转一步*/
	LIS3DH_Check();
}



/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
