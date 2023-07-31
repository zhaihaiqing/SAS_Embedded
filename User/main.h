/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.h 
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    22-April-2016
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
//#include "rtthread.h"	//包含RTT所需的资源


#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "rtthread.h"
#include "thread_m.h"

#include "sys.h"
#include "debug_uart.h"

#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_timer.h"
#include "bsp_i2c_port.h"
#include "bsp_spi.h"
#include "bsp_dac.h"
//#include "app_can.h"
//#include "tmp102.h"
#include "ADT7301.h"
#include "AD9834.h"
#include "bsp_e703.h"



//#include "thread_m.h"

////#define debugnt

//#ifdef debugnt
//		 #define log_info(...)    	 printf(__VA_ARGS__)
//#else
//		#define log_info(...)
//#endif

#define BUFFERSIZE 256

#define WDI_H     GPIO_SetBits(GPIOA,GPIO_Pin_15)
#define WDI_L	  GPIO_ResetBits(GPIOA,GPIO_Pin_15)

//#define Sen_SCL_H     GPIOE->BSRRL = GPIO_Pin_11
//#define Sen_SCL_L	  GPIOE->BSRRH = GPIO_Pin_11

extern volatile unsigned int SysTick_Count;
extern volatile unsigned int TimingDelay;


#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
