
#include "main.h"
#include "bsp_timer.h"




/*******************************************************************************
* Function Name  : Delay_us_Timer_Init
* Description    : 亚毫秒定时功能初始化，采样timer7(基本定时器)
* Input          : PCLK2频率（MHz）
* Output         : None
* Return         : None
*******************************************************************************/
//void Delay_us_Timer_Init(unsigned char PCLK2_CLK)	
//{
//    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
//	//timer时钟来源，默认预分频系数，分频后的计数频率为Timer_CLK为PCLK1/PCLK2时钟频率的2倍
//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
//      
//    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);
//    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;		//时钟分频因子，输入捕获时会用到
//    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式，向下计数
//    TIM_TimeBaseInitStruct.TIM_Period = 1000-1;			//自动装载值
//    TIM_TimeBaseInitStruct.TIM_Prescaler = PCLK2_CLK; //预分频系数，分频后的计数频率CNT_CLK为Timer_CLK/TIM_Prescaler
//    TIM_TimeBaseInit(TIM7, &TIM_TimeBaseInitStruct);
//     
//    while((TIM7->SR & TIM_FLAG_Update)!=SET);
//	TIM7->SR = (uint16_t)~TIM_FLAG_Update;
//}

/*******************************************************************************
* Function Name  : Delay_us
* Description    : 亚毫秒延时函数，延时范围（1-65536us）
* Input          : 延时时间
* Output         : None
* Return         : None
*******************************************************************************/
//void Delay_us(unsigned short us_cnt)
//{
//	TIM7->ARR = us_cnt;
//    TIM7->CNT = 0;						//装载值
//    TIM7->CR1 |= TIM_CR1_CEN;    				//使能定时器
//    while((TIM7->SR & TIM_FLAG_Update)!=SET);	//等待更新事件的发生
//    TIM7->SR = (uint16_t)~TIM_FLAG_Update;		//清除事件标志
//    TIM7->CR1 &= ~TIM_CR1_CEN;					//关闭定时器
//}


//void rt_hw_us_delay(uint32_t us)
//{
//    uint32_t delta;
//    /* 获得延时经过的 tick 数 */
//    //us = us * (SysTick->LOAD/(1000000/RT_TICK_PER_SECOND));
//    /* 获得当前时间 */
//    delta = SysTick->VAL;
//    /* 循环获得当前时间，直到达到指定的时间后退出循环 */
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




