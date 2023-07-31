#include "main.h"  


//THUMBָ�֧�ֻ������
//�������·���ʵ��ִ�л��ָ��WFI  
__asm void WFI_SET(void)
{
	WFI;		  
}

//�ر������ж�(���ǲ�����fault��NMI�ж�)
__asm void INTX_DISABLE(void)
{
	CPSID   I
	BX      LR	  
}

//���������ж�
__asm void INTX_ENABLE(void)
{
	CPSIE   I
	BX      LR  
}

//����ջ����ַ
//addr:ջ����ַ
__asm void MSR_MSP(unsigned int addr) 
{
	MSR MSP, r0 			//set Main Stack value
	BX r14
}



volatile unsigned int SysTick_Count = 0;   //Systick����
volatile unsigned int TimingDelay = 0;     //��ʱ��������

/*******************************************************************************
* Function Name  : Delay_us
* Description    : ��ʱ����������ʱ����sleepģʽ
* Input          : ��ʱʱ����us��
* Output         : None
* Return         : None
*******************************************************************************/
void Delay_us(volatile unsigned int us)
{
    unsigned int delta;
    /* �����ʱ������ tick �� */
    us = us * (SysTick->LOAD/(1000000/1000));
    /* ��õ�ǰʱ�� */
    delta = SysTick->VAL;
    /* ѭ����õ�ǰʱ�䣬ֱ���ﵽָ����ʱ����˳�ѭ�� */
    while (delta - SysTick->VAL< us);
}

/*******************************************************************************
* Function Name  : Delay function
* Description    : ��ʱ����������ʱ����sleepģʽ
* Input          : ��ʱʱ����ms��
* Output         : None
* Return         : None
*******************************************************************************/
void Delay_ms(volatile unsigned int nTime)
{ 
	TimingDelay = nTime;
	while(TimingDelay != 0);//__WFI;//�ȴ������н���sleepģʽ
}

/*******************************************************************************
* Function Name  : SysTick init function
* Description    : ���ö�ʱ���ȼ�SysTick���ȼ�
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Init_SysTick(void)
{
	SysTick_Config(SystemCoreClock / 1000); //���ö�ʱ���ȣ�1ms
	NVIC_SetPriority(SysTick_IRQn, 0x0);    //SysTick�ж����ȼ�����
}

/*******************************************************************************
* Function Name  : get_rccclock_info
* Description    : ��ȡRCCʱ����Ϣ
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void get_rccclock_info(void)
{
	//char str[32]={0};
	RCC_ClocksTypeDef  RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	
	log_info("SYSCLK_Frequency:%.3fMHz\r\n",RCC_Clocks.SYSCLK_Frequency/1000000.0);
	log_info("HCLK_Frequency:%.3fMHz\r\n",RCC_Clocks.HCLK_Frequency/1000000.0);
	log_info("PCLK1_Frequency:%.3fMHz\r\n",RCC_Clocks.PCLK1_Frequency/1000000.0);
	log_info("PCLK2_Frequency:%.3fMHz\r\n",RCC_Clocks.PCLK2_Frequency/1000000.0);
	
}

void MCU_RESET_Log(void)
{
	if(RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
	{
		log_info("RCC_FLAG_PORRST\r\n");
	}
	if(RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET)
	{
		log_info("RCC_FLAG_PINRST\r\n");
	}
	if(RCC_GetFlagStatus(RCC_FLAG_SFTRST) != RESET)
	{
		log_info("RCC_FLAG_SFTRST\r\n");
	}
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST) != RESET)
	{
		log_info("RCC_FLAG_IWDGRST\r\n");
	}
	if(RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET)
	{
		log_info("RCC_FLAG_WWDGRST\r\n");
	}
	if(RCC_GetFlagStatus(RCC_FLAG_LPWRRST) != RESET)
	{
		log_info("RCC_FLAG_LPWRRST\r\n");
	}
	if(RCC_GetFlagStatus(RCC_FLAG_BORRST) != RESET)
	{
		log_info("RCC_FLAG_BORRST\r\n");
	}
	RCC_ClearFlag();	//����жϸ�λ��־
}

uint32_t MCU_idAddr[]=
{
	0x1FFFF7AC,		/*STM32F0ΨһID��ʼ��ַ*/
	0x1FFFF7E8,		/*STM32F1ΨһID��ʼ��ַ*/
	0x1FFF7A10,		/*STM32F2ΨһID��ʼ��ַ*/
	0x1FFFF7AC,		/*STM32F3ΨһID��ʼ��ַ*/
	0x1FFF7A10,		/*STM32F4ΨһID��ʼ��ַ*/
	0x1FF0F420,		/*STM32F7ΨһID��ʼ��ַ*/
	0x1FF80050,		/*STM32L0ΨһID��ʼ��ַ*/
	0x1FF80050,		/*STM32L1ΨһID��ʼ��ַ*/
	0x1FFF7590,		/*STM32L4ΨһID��ʼ��ַ*/
	0x1FF0F420		/*STM32H7ΨһID��ʼ��ַ*/
};

//void get_MCU_Type(MCUTypedef type)
//{
//	uint32_t id[3]={0};
//	uint32_t id1[3]={0};
//	id[0] = (uint32_t)DBGMCU->IDCODE & DBGMCU_IDCODE_DEV_ID;
//	
//	log_info("MCU id[0]:0x%x\r\n",id[0]);
//	
//	id[0]=*(uint32_t*)(MCU_idAddr[type]);
//	id[1]=*(uint32_t*)(MCU_idAddr[type]+4);
//	id[2]=*(uint32_t*)(MCU_idAddr[type]+8);
//	
//	log_info("MCU id1[0]:0x%x\r\n",id1[0]);
//	log_info("MCU id1[1]:0x%x\r\n",id1[1]);
//	log_info("MCU id1[2]:0x%x\r\n",id1[2]);
//	
//}

/*******************************************************************************

* Author:�Ժ���
* Function Name  : Bubble_Sort ð������

* ���룺
* *pa:����ָ�룬��Ҫ�����������ͽ����ض���

* len:��������ݳ���
* f:������0����С��������1���Ӵ�С����
* return��None

*******************************************************************************/
void Bubble_Sort(float *pa,unsigned int len, unsigned char f)
{
	unsigned int i=0,j=0;
	float buf=0;

	for(i=0;i<len;i++)
		for(j=i+1;j<len;j++)
			if(f==0)
			{
				if(*(pa+i)>*(pa+j))
				{
					buf=*(pa+i);
					*(pa+i)=*(pa+j);
					*(pa+j)=buf;
				}
			}
			else if(f==1)
			{
				if(*(pa+i)<*(pa+j))
				{
					buf=*(pa+i);
					*(pa+i)=*(pa+j);
					*(pa+j)=buf;
				}
			}
}


void f_max_min(float *pa,uint32_t len,float *p_max,float *p_min)
{
	uint32_t ix=0;
	
	*p_max = *pa;
	*p_min = *pa;
	for(ix=1;ix<len;ix++)
	{
		pa++;
		if(*p_max < *pa)
			*p_max = *pa;
		if(*p_min > *pa)
			*p_min = *pa;
	}
}


/*******************************************************************************
* Function Name  : CRC16_Check
* Description    : CRCУ��
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint16_t CRC16_Check(uint8_t *Pushdata,uint8_t length)
{
	uint16_t Reg_CRC=0xffff;
	uint8_t i,j;
	for( i = 0; i<length; i ++)
	{
		Reg_CRC^= *Pushdata++;
		for (j = 0; j<8; j++)
		{
			if (Reg_CRC & 0x0001)

			Reg_CRC=Reg_CRC>>1^0xA001;
			else
			Reg_CRC >>=1;
		}
	}
	return   Reg_CRC;
}








