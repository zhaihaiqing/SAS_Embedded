/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    22-April-2016
  * @brief   Main program body
  ******************************************************************************
  */

#include "main.h"

//#include "ecg_data_normal.h"
//#include "ecg_data_arrhythmia.h"

//volatile unsigned int SysTick_Count = 0;
//volatile unsigned int TimingDelay = 0;


//uint8_t aTxBuffer[BUFFERSIZE] = "SPI Master/Slave : Communication between two SPI using Interrupts";

//__IO uint8_t aRxBuffer [BUFFERSIZE];
//__IO uint8_t ubRxIndex = 0;
//__IO uint8_t ubTxIndex = 0;
//__IO uint32_t TimeOut = 0;

//__IO uint8_t spi4_rx_flag = 0;


int main(void)
{	
	//int vol=0; 	
	
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//Init_SysTick();
//	debug_usart_Init();
	GPIO_Configuration();
//	SPI2_Configuration();
//	get_rccclock_info();

	
	//i2cb_port_init();
	
//	Delay_ms(200);
//	
//	i2cb_CheckDevice(0xd8);
//	Delay_ms(200);
//	
//	Read_e703_CFG();
//	//Read_e703_Results();
//	Read_e703_Status();
//	Read_e703_ID();
//	Read_e703_CM();
//	Read_e703_SR();
	
	rt_thread_mdelay(50);
	log_info("sys init ok!\r\n");
	
	thread_init();
	
	rt_thread_mdelay(200);
	
	while(1)
	{

		
		//LED_ON(LED1|LED2|LED3|LED4);
		rt_thread_mdelay(500);
		
		//LED_OFF(LED1|LED2|LED3|LED4);
		//rt_thread_mdelay(500);
	}
	
	
//	/*******************	1：DAC波形发生器 *******************/
//	{
//		
//		WAVE_InitTypeDef WAVE_Init;
//		
//		DAC_DeInit(); 			//初始化DAC
//		
//		//设置波形参数
//		WAVE_Init.wave_type=SINWAVE;
//		WAVE_Init.freq = 1;
//		WAVE_Init.am = 1;
//		WAVE_Init.phase =0;
//		WAVE_Init.duty_cycle =50;
//		WAVE_Init.polarity=0;
//		
//		//WaveGeneration(&WAVE_Init);	//输出波形
//		//Dac1_Set_fixed_Vol(vol);		//设置恒定电平
//	}
//	
//	
//	
//	/******************* 2：DDS测试 *******************/
//	{
//			//DDS_test();
//	}
//	
	
//	/*******************	3：TEMP测试 *******************/
//	{
//		while (0)
//		{	
//			get_temp();
//			Delay_ms(100);
//		}
//	}
//	
	
	
//	/******************* 4：SPI4 Slave测试 *******************/
//	{
//		uint16_t ix=0;
//		
//		SPI4_Configuration();
//		SPI_I2S_ReceiveData(SPI4);
//		
//		while (1)
//		{				
//			Delay_ms(5);
//			if(spi4_rx_flag)
//			{
//				spi4_rx_flag=0;
//				ubRxIndex=0;
//				
//				log_info("aRxBuffer=");
//				for(ix=1;ix<BUFFERSIZE-1;ix++)
//				{
//					log_info("%d ",aRxBuffer[ix]);
//				}
//				log_info("\r\n");
//				
//				memset((void *)aRxBuffer,0,BUFFERSIZE);
//			}
//		}
//	}
	
	
	
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
