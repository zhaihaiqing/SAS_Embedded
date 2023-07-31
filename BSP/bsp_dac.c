
/*
	DAC1输出
	2020-12-29
	1：DAC1输出固定电压值
	2：DAC1输出可调参正弦波、三角波、锯齿波、方波、噪声信号等
*/

#include "main.h"


uint16_t aSine12bit[32] = {
                      2047, 2447, 2831, 3185, 3498, 3750, 3939, 4056, 4095, 4056,
                      3939, 3750, 3495, 3185, 2831, 2447, 2047, 1647, 1263, 909, 
                      599, 344, 155, 38, 0, 38, 155, 344, 599, 909, 1263, 1647};

unsigned short sinwave_128_U16[128] = {
									   2048, 2148, 2248, 2348, 2447, 2545, 2642, 2737, 2831, 2923, 3013, 3100, 3185, 3267, 3346, 3423,
                                       3495, 3565, 3630, 3692, 3750, 3804, 3853, 3898, 3939, 3975, 4007, 4034, 4056, 4073, 4085, 4093,
                                       4095, 4093, 4085, 4073, 4056, 4034, 4007, 3975, 3939, 3898, 3853, 3804, 3750, 3692, 3630, 3565,
                                       3495, 3423, 3346, 3267, 3185, 3100, 3013, 2923, 2831, 2737, 2642, 2545, 2447, 2348, 2248, 2148,
                                       2048, 1947, 1847, 1747, 1648, 1550, 1453, 1358, 1264, 1172, 1082, 995, 910, 828, 749, 672,
                                       600, 530, 465, 403, 345, 291, 242, 197, 156, 120, 88, 61, 39, 22, 10, 2,
                                       0, 2, 10, 22, 39, 61, 88, 120, 156, 197, 242, 291, 345, 403, 465, 530,
                                       600, 672, 749, 828, 910, 995, 1082, 1172, 1264, 1358, 1453, 1550, 1648, 1747, 1847, 1947};

unsigned short sinwave_256_U16[256] = {
									   2048, 2098, 2148, 2198, 2248, 2298, 2348, 2398, 2447, 2496, 2545, 2594, 2642, 2690, 2737, 2784,
                                       2831, 2877, 2923, 2968, 3013, 3057, 3100, 3143, 3185, 3226, 3267, 3307, 3346, 3385, 3423, 3459,
                                       3495, 3530, 3565, 3598, 3630, 3662, 3692, 3722, 3750, 3777, 3804, 3829, 3853, 3876, 3898, 3919,
                                       3939, 3958, 3975, 3992, 4007, 4021, 4034, 4045, 4056, 4065, 4073, 4080, 4085, 4089, 4093, 4094,
                                       4095, 4094, 4093, 4089, 4085, 4080, 4073, 4065, 4056, 4045, 4034, 4021, 4007, 3992, 3975, 3958,
                                       3939, 3919, 3898, 3876, 3853, 3829, 3804, 3777, 3750, 3722, 3692, 3662, 3630, 3598, 3565, 3530,
                                       3495, 3459, 3423, 3385, 3346, 3307, 3267, 3226, 3185, 3143, 3100, 3057, 3013, 2968, 2923, 2877,
                                       2831, 2784, 2737, 2690, 2642, 2594, 2545, 2496, 2447, 2398, 2348, 2298, 2248, 2198, 2148, 2098,
                                       2048, 1997, 1947, 1897, 1847, 1797, 1747, 1697, 1648, 1599, 1550, 1501, 1453, 1405, 1358, 1311,
                                       1264, 1218, 1172, 1127, 1082, 1038, 995, 952, 910, 869, 828, 788, 749, 710, 672, 636, 600,
                                       565, 530, 497, 465, 433, 403, 373, 345, 318, 291, 266, 242, 219, 197, 176, 156, 137, 120,
                                       103, 88, 74, 61, 50, 39, 30, 22, 15, 10, 6, 2, 1, 0, 1, 2, 6, 10, 15, 22, 30, 39,
                                       50, 61, 74, 88, 103, 120, 137, 156, 176, 197, 219, 242, 266, 291, 318, 345, 373,
                                       403, 433, 465, 497, 530, 565, 600, 636, 672, 710, 749, 788, 828, 869, 910, 952, 995,
                                       1038, 1082, 1127, 1172, 1218, 1264, 1311, 1358, 1405, 1453, 1501, 1550, 1599, 1648, 1697,
                                       1747, 1797, 1847, 1897, 1947, 1997};

unsigned short sinwave_512_U16[512] = {2048, 2073, 2098, 2123, 2148, 2173, 2198, 2223, 2248, 2273, 2298, 2323, 2348, 2373, 2398, 2422, 
                                       2447, 2472, 2496, 2521, 2545, 2569, 2594, 2618, 2642, 2666, 2690, 2714, 2737, 2761, 2784, 2808, 
                                       2831, 2854, 2877, 2900, 2923, 2946, 2968, 2990, 3013, 3035, 3057, 3078, 3100, 3122, 3143, 3164, 
                                       3185, 3206, 3226, 3247, 3267, 3287, 3307, 3327, 3346, 3366, 3385, 3404, 3423, 3441, 3459, 3477, 
                                       3495, 3513, 3530, 3548, 3565, 3581, 3598, 3614, 3630, 3646, 3662, 3677, 3692, 3707, 3722, 3736, 
                                       3750, 3764, 3777, 3791, 3804, 3816, 3829, 3841, 3853, 3865, 3876, 3888, 3898, 3909, 3919, 3929, 
                                       3939, 3949, 3958, 3967, 3975, 3984, 3992, 3999, 4007, 4014, 4021, 4027, 4034, 4040, 4045, 4051, 
                                       4056, 4060, 4065, 4069, 4073, 4076, 4080, 4083, 4085, 4087, 4089, 4091, 4093, 4094, 4094, 4095, 
                                       4095, 4095, 4094, 4094, 4093, 4091, 4089, 4087, 4085, 4083, 4080, 4076, 4073, 4069, 4065, 4060, 
                                       4056, 4051, 4045, 4040, 4034, 4027, 4021, 4014, 4007, 3999, 3992, 3984, 3975, 3967, 3958, 3949, 
                                       3939, 3929, 3919, 3909, 3898, 3888, 3876, 3865, 3853, 3841, 3829, 3816, 3804, 3791, 3777, 3764, 
                                       3750, 3736, 3722, 3707, 3692, 3677, 3662, 3646, 3630, 3614, 3598, 3581, 3565, 3548, 3530, 3513, 
                                       3495, 3477, 3459, 3441, 3423, 3404, 3385, 3366, 3346, 3327, 3307, 3287, 3267, 3247, 3226, 3206, 
                                       3185, 3164, 3143, 3122, 3100, 3078, 3057, 3035, 3013, 2990, 2968, 2946, 2923, 2900, 2877, 2854, 
                                       2831, 2808, 2784, 2761, 2737, 2714, 2690, 2666, 2642, 2618, 2594, 2569, 2545, 2521, 2496, 2472, 
                                       2447, 2422, 2398, 2373, 2348, 2323, 2298, 2273, 2248, 2223, 2198, 2173, 2148, 2123, 2098, 2073, 
                                       2048, 2022, 1997, 1972, 1947, 1922, 1897, 1872, 1847, 1822, 1797, 1772, 1747, 1722, 1697, 1673, 
                                       1648, 1623, 1599, 1574, 1550, 1526, 1501, 1477, 1453, 1429, 1405, 1381, 1358, 1334, 1311, 1287, 
                                       1264, 1241, 1218, 1195, 1172, 1149, 1127, 1105, 1082, 1060, 1038, 1017, 995, 973, 952, 931, 
                                       910, 889, 869, 848, 828, 808, 788, 768, 749, 729, 710, 691, 672, 654, 636, 618, 600, 582, 
                                       565, 547, 530, 514, 497, 481, 465, 449, 433, 418, 403, 388, 373, 359, 345, 331, 318, 304, 
                                       291, 279, 266, 254, 242, 230, 219, 207, 197, 186, 176, 166, 156, 146, 137, 128, 120, 111, 
                                       103, 96, 88, 81, 74, 68, 61, 55, 50, 44, 39, 35, 30, 26, 22, 19, 15, 12, 10, 8, 6, 4, 2, 
                                       1, 1, 0, 0, 0, 1, 1, 2, 4, 6, 8, 10, 12, 15, 19, 22, 26, 30, 35, 39, 44, 50, 55, 61, 68, 74, 
                                       81, 88, 96, 103, 111, 120, 128, 137, 146, 156, 166, 176, 186, 197, 207, 219, 230, 242, 254, 
                                       266, 279, 291, 304, 318, 331, 345, 359, 373, 388, 403, 418, 433, 449, 465, 481, 497, 514, 530, 
                                       547, 565, 582, 600, 618, 636, 654, 672, 691, 710, 729, 749, 768, 788, 808, 828, 848, 869, 889, 
                                       910, 931, 952, 973, 995, 1017, 1038, 1060, 1082, 1105, 1127, 1149, 1172, 1195, 1218, 1241, 1264, 
                                       1287, 1311, 1334, 1358, 1381, 1405, 1429, 1453, 1477, 1501, 1526, 1550, 1574, 1599, 1623, 1648, 
                                       1673, 1697, 1722, 1747, 1772, 1797, 1822, 1847, 1872, 1897, 1922, 1947, 1972, 1997, 2022};

unsigned short aEscalator12bit[32] = {0};

DAC_InitTypeDef  DAC_InitStructure;


//DAC通道1输出固定电压值
void Dac1_fixed_Init(void)
{  
	GPIO_InitTypeDef  GPIO_InitStructure;
	//DAC_InitTypeDef DAC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);//使能DAC时钟
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化

	DAC_InitStructure.DAC_Trigger=DAC_Trigger_None;	//不使用触发功能 TEN1=0
	DAC_InitStructure.DAC_WaveGeneration=DAC_WaveGeneration_None;//不使用波形发生
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;//屏蔽、幅值设置
	DAC_InitStructure.DAC_OutputBuffer=DAC_OutputBuffer_Enable ;	//DAC1输出缓存关闭 BOFF1=1
	DAC_Init(DAC_Channel_1,&DAC_InitStructure);	 //初始化DAC通道1

	DAC_Cmd(DAC_Channel_1, ENABLE);  //使能DAC通道1
  
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);  //12位右对齐数据格式设置DAC值
}
//设置通道1输出电压
//vol:0~3300,代表0~3.3V
void Dac1_Set_fixed_Vol(float vol)
{
	double temp=vol;
	//temp/=1000;
	temp=temp*4096/3.3;
	DAC_SetChannel1Data(DAC_Align_12b_R,temp);//12位右对齐数据格式设置DAC值
}



/*波形发生器：支持正弦波、三角波、锯齿波、方波、噪声信号等
	CPU：STM32F427VIT6
	时钟源：外部10MHz有源晶振，频率稳定度±1.5ppm
	CPU主频：168MHz
	HCLK/AHB：168MHz
	APB1外设：42MHz
	APB1定时器：84MHz
	APB1外设：84MHz
	APB1定时器：168MHz
	默认每个周期采用256个数据点，可选用其他点数
	DAC模式：12位右对齐

	采用定时器6作为DAC的触发源，每次触发时，DMA从内存表中搬运码字至DAC
*/
/*参数：
	波形:1-5对应正弦波、三角波、锯齿波、方波、噪声
	频率:不能太高
	幅度:0-3.3
	相位:0-360度
	占空比：方波特有,0-100
	时钟极性：方波、锯齿波特有，0、1）
*/

#define WAVE_DOT_NUM	256				//每个周期波形的点数
#define PI_14 3.14159265358979

unsigned short Wave_Xnum_U16[WAVE_DOT_NUM+1]={0};


unsigned short sinwave_512_U16_X[WAVE_DOT_NUM]={0};
void sin_dot(void)
{
    unsigned int i=0;
    double y=0;

    for(i=0;i<WAVE_DOT_NUM;i++)
    {
        y=2047.5*sin(((double)(i*360)/WAVE_DOT_NUM)*PI_14/180)+2047.5;
        if(y>-0.5)
        {
            sinwave_512_U16_X[i]=(unsigned short)(y+0.5);
        }
        else
        {
            sinwave_512_U16_X[i]=(unsigned short)(y-0.5);
        }
    }
}



//void WaveGeneration(unsigned char Wave_type,float f,float am,float ph,float duty,unsigned char direction)
void WaveGeneration(WAVE_InitTypeDef* WAVE_Init)
{
	RCC_ClocksTypeDef  RCC_Clocks;
	unsigned int arr=1;
	unsigned int i=0;
	unsigned short Wave_Xnum_U16_temp[WAVE_DOT_NUM+1]={0};
	
	RCC_GetClocksFreq(&RCC_Clocks);//获取系统时钟
	
	arr=RCC_Clocks.PCLK2_Frequency/(WAVE_Init->freq*WAVE_DOT_NUM);//计算频率对应的定时器装填数
	
	switch(WAVE_Init->wave_type)//根据波形加载或计算不同的表
	{
		case SINWAVE:	//正弦波通过查表法
			if(WAVE_DOT_NUM==128)
				memcpy(&Wave_Xnum_U16_temp[0],&sinwave_128_U16[0],WAVE_DOT_NUM*sizeof(unsigned short) );
			else if(WAVE_DOT_NUM==256)
				memcpy(&Wave_Xnum_U16_temp[0],&sinwave_256_U16[0],WAVE_DOT_NUM*sizeof(unsigned short) );
			else if(WAVE_DOT_NUM==512)
				memcpy(&Wave_Xnum_U16_temp[0],&sinwave_512_U16[0],WAVE_DOT_NUM*sizeof(unsigned short) );
			break;
		case TRIANGLEWAVE:	//三角波，计算三角波的数据表
			for(i=0;i<=WAVE_DOT_NUM/2;i++)
				Wave_Xnum_U16_temp[i]=i*4095/(WAVE_DOT_NUM/2);
			for(i=WAVE_DOT_NUM/2+1;i<WAVE_DOT_NUM;i++)
				Wave_Xnum_U16_temp[i]=Wave_Xnum_U16_temp[WAVE_DOT_NUM-i];
			break;
		case SAWTOOTHWAVE:	//计算锯齿波的数据表
			if(WAVE_Init->polarity==0)	//增加
			{
				for(i=0;i<WAVE_DOT_NUM;i++)
					Wave_Xnum_U16_temp[i]=i*4095/WAVE_DOT_NUM;
			}
			else				//减小
			{
				for(i=0;i<WAVE_DOT_NUM;i++)
					Wave_Xnum_U16_temp[i]=4095-i*4095/WAVE_DOT_NUM;
			}
			
			break;
		case SQUAREWAVE:	//计算方波的数据表
			if(WAVE_Init->polarity==0)//先输出低电平
			{
				for(i=0;i<WAVE_DOT_NUM-WAVE_DOT_NUM*WAVE_Init->duty_cycle/100;i++)
					Wave_Xnum_U16_temp[i]=0;
				
				for(i=WAVE_DOT_NUM-WAVE_DOT_NUM*WAVE_Init->duty_cycle/100;i<WAVE_DOT_NUM;i++)
					Wave_Xnum_U16_temp[i]=4095;
			}
			else			//先输出高电平
			{
				for(i=0;i<WAVE_DOT_NUM*WAVE_Init->duty_cycle/100;i++)
					Wave_Xnum_U16_temp[i]=4095;
				
				for(i=WAVE_DOT_NUM*WAVE_Init->duty_cycle/100;i<WAVE_DOT_NUM;i++)
					Wave_Xnum_U16_temp[i]=0;
			}
			break;
		default:
			break;
	}
	
	//计算相位
	{
		unsigned int ph0=0;
		ph0=WAVE_Init->phase*WAVE_DOT_NUM/360;	//计算相位起始位置
		
		//LOG_D("ph0=%d",ph0);
		
		memcpy(&Wave_Xnum_U16[0],&Wave_Xnum_U16_temp[ph0],(WAVE_DOT_NUM-ph0)*sizeof(unsigned short) );
		
		if(ph0!=0)
		{
			memcpy(&Wave_Xnum_U16[WAVE_DOT_NUM-ph0],&Wave_Xnum_U16_temp[0],ph0*sizeof(unsigned short) );
		}
	}
	
	
	//计算幅值
	for(i=0;i<WAVE_DOT_NUM;i++)
	{
		Wave_Xnum_U16[i]=WAVE_Init->am*Wave_Xnum_U16[i]/3.3;
	}
	
	
	if(WAVE_Init->wave_type==NOISEWAVE)
	{
		TIM6_Config(arr);	//配置定时器
		DAC_Ch1_NoiseConfig();
	}
		
	else
	{
		TIM6_Config(arr);	//配置定时器
		DAC_Ch1_EscalatorConfig();
	}
}


void TIM6_Config(unsigned int arr)
{
  TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
  /* TIM6 Periph clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
  
  /* --------------------------------------------------------
  TIM3 input clock (TIM6CLK) is set to 2 * APB1 clock (PCLK1), 
  since APB1 prescaler is different from 1.   
    TIM6CLK = 2 * PCLK1  
    TIM6CLK = HCLK / 2 = SystemCoreClock /2 
          
  TIM6 Update event occurs each TIM6CLK/256 

  Note: 
   SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
   Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
   function to update SystemCoreClock variable value. Otherwise, any configuration
   based on this variable will be incorrect.    
  ----------------------------------------------------------- */
  /* Time base configuration */
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
  TIM_TimeBaseStructure.TIM_Period = arr; 				//自动重装载值         
  TIM_TimeBaseStructure.TIM_Prescaler = TIM_CKD_DIV1;   //定时器分频值
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;    
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式
  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

  /* TIM6 TRGO selection */
  TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);//输出触发信号
  
  /* TIM6 enable counter */
  TIM_Cmd(TIM6, ENABLE);
}



//DAC通道1输出动态波形
void DAC_Ch1_EscalatorConfig(void)
{  
	int i=0;
	GPIO_InitTypeDef  GPIO_InitStructure;
	//DAC_InitTypeDef DAC_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
	//NVIC_InitTypeDef NVIC_Initstructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);//开启DMA1时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);//使能DAC时钟
	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//下拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化

	DAC_InitStructure.DAC_Trigger = DAC_Trigger_T6_TRGO;	//选择触发功能，触发源为T6 TEN1=0
	DAC_InitStructure.DAC_WaveGeneration=DAC_WaveGeneration_None;//不使用波形发生
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;//屏蔽、幅值设置
	DAC_InitStructure.DAC_OutputBuffer=DAC_OutputBuffer_Disable ;	//DAC1输出缓存关闭 BOFF1=1
	DAC_Init(DAC_Channel_1,&DAC_InitStructure);	 //初始化DAC通道1

	/* DMA1_Stream5 channel7 configuration **************************************/ 
	//DMA数据5的第7通道，DAC1
	DMA_DeInit(DMA1_Stream5);
	DMA_InitStructure.DMA_Channel = DMA_Channel_7; 
	DMA_InitStructure.DMA_PeripheralBaseAddr = DAC_DHR12R1_ADDRESS;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&Wave_Xnum_U16;
	DMA_InitStructure.DMA_BufferSize = WAVE_DOT_NUM;											//一个周期内的点数
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;		//传输宽度
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;				//内存地址宽度
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;							//传输方向
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_Init(DMA1_Stream5, &DMA_InitStructure);    
	
	/* Enable DMA1_Stream5 */
	DMA_Cmd(DMA1_Stream5, ENABLE);
  
	/* Enable DAC Channel1 */
	DAC_Cmd(DAC_Channel_1, ENABLE);  //使能DAC通道1
	/* Enable DMA for DAC Channel1 */
	DAC_DMACmd(DAC_Channel_1, ENABLE);
}


void DAC_Ch1_NoiseConfig(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);//开启DMA1时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);//使能DAC时钟
	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//下拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化

	DAC_InitStructure.DAC_Trigger = DAC_Trigger_T6_TRGO;	//选择触发功能，触发源为T6 TEN1=0
	DAC_InitStructure.DAC_WaveGeneration=DAC_WaveGeneration_Noise;//不使用波形发生
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bits10_0;//屏蔽、幅值设置
	DAC_InitStructure.DAC_OutputBuffer=DAC_OutputBuffer_Disable ;	//DAC1输出缓存关闭 BOFF1=1
	DAC_Init(DAC_Channel_1,&DAC_InitStructure);	 //初始化DAC通道1

	/* DMA1_Stream5 channel7 configuration **************************************/ 
	//DMA数据5的第7通道，DAC1
	DMA_DeInit(DMA1_Stream5);
	DMA_InitStructure.DMA_Channel = DMA_Channel_7; 
	DMA_InitStructure.DMA_PeripheralBaseAddr = DAC_DHR12R1_ADDRESS;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&Wave_Xnum_U16;
	DMA_InitStructure.DMA_BufferSize = WAVE_DOT_NUM;											//一个周期内的点数
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;		//传输宽度
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;				//内存地址宽度
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;							//传输方向
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_Init(DMA1_Stream5, &DMA_InitStructure);    
	
	/* Enable DMA1_Stream5 */
	DMA_Cmd(DMA1_Stream5, ENABLE);
  
	/* Enable DAC Channel1 */
	DAC_Cmd(DAC_Channel_1, ENABLE);  //使能DAC通道1
	/* Enable DMA for DAC Channel1 */
	//DAC_DMACmd(DAC_Channel_1, ENABLE);
	DAC_SetChannel1Data(DAC_Align_12b_L, 0x7FF0);
}








