/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    22-April-2016
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
//void HardFault_Handler(void)
//{
//  /* Go to infinite loop when Hard Fault exception occurs */
//  while (1)
//  {
//  }
//}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
//void PendSV_Handler(void)
//{
//}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
//void SysTick_Handler(void)
//{
//	if (TimingDelay != 0x00)
//	{ 
//		TimingDelay--;
//	}
//	
//	SysTick_Count++;
//	if(SysTick_Count==200)		LED_ON(LED1);
//	else if(SysTick_Count==400)	LED_ON(LED2);
//	else if(SysTick_Count==600)	LED_ON(LED3);
//	else if(SysTick_Count==800)	LED_ON(LED4);
//	else if(SysTick_Count==1300)
//	{
//		SysTick_Count=0;
//		LED_OFF(LED1|LED2|LED3|LED4);
//	}
//	
////	else if(SysTick_Count==2000)
////	{
////		SysTick_Count=0;
////		LED_OFF(LED4);
////	}
//}



//void USART1_Handler(void)
//{
//	unsigned char 	Uart_Get_Data;	//串口接收的数据
//	UART1_RBUF_ST *p = &uart1_rbuf;
//	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
//	{
//		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
//		Uart_Get_Data = USART_ReceiveData(USART1);
//		if((p->in - p->out)<UART1_RBUF_SIZE)
//		{
//			p->buf [p->in & (UART1_RBUF_SIZE-1)] = Uart_Get_Data;	
//			p->in++;
//			Uart1Flag = 1;
//		}
//	}
//}



//void UART7_IRQHandler(void)
//{
//	unsigned char 	Uart_Get_Data,tmp;	//串口7接收的数据
//	UART7_RBUF_ST *p = &uart7_rbuf;
//	if(USART_GetITStatus(UART7, USART_IT_RXNE) != RESET)
//	{
//		USART_ClearITPendingBit(UART7,USART_IT_RXNE);
//		Uart_Get_Data = USART_ReceiveData(UART7);
//		//if(!Uart7Flag)		
//		//{
//			if((p->in - p->out)<UART7_RBUF_SIZE)
//			{
//				p->buf [p->in & (UART7_RBUF_SIZE-1)] = Uart_Get_Data;	
//				p->in++;
//			}
//			uart7_rx_len  = (p->in - p->out) & (UART7_RBUF_SIZE - 1);//获取数据长度
//		//}
//		
//	}
//	else if(USART_GetITStatus(UART7, USART_IT_IDLE) != RESET)
//	{
//		tmp=UART7->SR;
//		tmp=UART7->DR;		
//		Uart7Flag = 1;
//	}
//}

//void TIM7_IRQHandler(void)
//{
//	
//}


//extern  __IO uint8_t aRxBuffer[];
//extern __IO uint8_t ubRxIndex;
//extern __IO uint8_t ubTxIndex;
//extern uint8_t aTxBuffer[];
//extern __IO uint32_t TimeOut;

//extern __IO uint8_t spi4_rx_flag;

//__IO uint8_t ubCounter = 0;

//__IO uint8_t rxdata=0;

//void SPI4_IRQHandler(void)
//{
//  /* SPI in Receiver mode */
//  if (SPI_I2S_GetITStatus(SPI4, SPI_I2S_IT_RXNE) == RESET)
//  {
//    if (ubRxIndex < BUFFERSIZE)
//    {
//      /* Receive Transaction data */
//			rxdata=SPI_I2S_ReceiveData(SPI4);
//      aRxBuffer[ubRxIndex++] = rxdata;
//			
//			spi4_rx_flag=1;
//			//log_info("rxdata:%d\r\n",rxdata);
//    }
//    else
//    {
//      /* Disable the Rx buffer not empty interrupt */
//      SPI_I2S_ITConfig(SPI4, SPI_I2S_IT_RXNE, DISABLE);
//    }
//  }
//  /* SPI in Transmitter mode */
//  if (SPI_I2S_GetITStatus(SPI4, SPI_I2S_IT_TXE) == SET)
//  {
//    if (ubTxIndex < BUFFERSIZE)
//    {
//      /* Send Transaction data */
//      //SPI_I2S_SendData(SPI4, aTxBuffer[ubTxIndex++]);
//			SPI_I2S_SendData(SPI4, rxdata);
//    }
//    else
//    {
//      /* Disable the Tx buffer empty interrupt */
//      //SPI_I2S_ITConfig(SPI4, SPI_I2S_IT_TXE, DISABLE);
//    }
//  }
//}



/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
