
#include "main.h"
#include "bsp_timer.h"




/*******************************************************************************
* Function Name  : Delay_us_Timer_Init
* Description    : �Ǻ��붨ʱ���ܳ�ʼ��������timer7(������ʱ��)
* Input          : PCLK2Ƶ�ʣ�MHz��
* Output         : None
* Return         : None
*******************************************************************************/
//void Delay_us_Timer_Init(unsigned char PCLK2_CLK)	
//{
//    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
//	//timerʱ����Դ��Ĭ��Ԥ��Ƶϵ������Ƶ��ļ���Ƶ��ΪTimer_CLKΪPCLK1/PCLK2ʱ��Ƶ�ʵ�2��
//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
//      
//    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);
//    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;		//ʱ�ӷ�Ƶ���ӣ����벶��ʱ���õ�
//    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;	//����ģʽ�����¼���
//    TIM_TimeBaseInitStruct.TIM_Period = 1000-1;			//�Զ�װ��ֵ
//    TIM_TimeBaseInitStruct.TIM_Prescaler = PCLK2_CLK; //Ԥ��Ƶϵ������Ƶ��ļ���Ƶ��CNT_CLKΪTimer_CLK/TIM_Prescaler
//    TIM_TimeBaseInit(TIM7, &TIM_TimeBaseInitStruct);
//     
//    while((TIM7->SR & TIM_FLAG_Update)!=SET);
//	TIM7->SR = (uint16_t)~TIM_FLAG_Update;
//}

/*******************************************************************************
* Function Name  : Delay_us
* Description    : �Ǻ�����ʱ��������ʱ��Χ��1-65536us��
* Input          : ��ʱʱ��
* Output         : None
* Return         : None
*******************************************************************************/
//void Delay_us(unsigned short us_cnt)
//{
//	TIM7->ARR = us_cnt;
//    TIM7->CNT = 0;						//װ��ֵ
//    TIM7->CR1 |= TIM_CR1_CEN;    				//ʹ�ܶ�ʱ��
//    while((TIM7->SR & TIM_FLAG_Update)!=SET);	//�ȴ������¼��ķ���
//    TIM7->SR = (uint16_t)~TIM_FLAG_Update;		//����¼���־
//    TIM7->CR1 &= ~TIM_CR1_CEN;					//�رն�ʱ��
//}


//void rt_hw_us_delay(uint32_t us)
//{
//    uint32_t delta;
//    /* �����ʱ������ tick �� */
//    //us = us * (SysTick->LOAD/(1000000/RT_TICK_PER_SECOND));
//    /* ��õ�ǰʱ�� */
//    delta = SysTick->VAL;
//    /* ѭ����õ�ǰʱ�䣬ֱ���ﵽָ����ʱ����˳�ѭ�� */
//    while (delta - SysTick->VAL< us);
//}


//void Delay_ms(volatile unsigned int nTime)
//{ 
//	TimingDelay = nTime;
//	while(TimingDelay != 0);
//}


//void get_RCCCLOCK(void)
//{
//	//char str[32]={0};
//	RCC_ClocksTypeDef  RCC_Clocks;
//	RCC_GetClocksFreq(&RCC_Clocks);
//	//sprintf(str," HCLK:%.3fMHz\n",1.0*RCC_Clocks.HCLK_Frequency/1000000);
//	//rt_kprintf(str);
//	LOG_D("HCLK_Frequency:%.3fMHz",RCC_Clocks.HCLK_Frequency/1000000.0);
//	LOG_D("PCLK1_Frequency:%.3fMHz",RCC_Clocks.PCLK1_Frequency/1000000.0);
//	LOG_D("PCLK2_Frequency:%.3fMHz",RCC_Clocks.PCLK2_Frequency/1000000.0);
//	LOG_D("SYSCLK_Frequency:%.3fMHz",RCC_Clocks.SYSCLK_Frequency/1000000.0);
//}




