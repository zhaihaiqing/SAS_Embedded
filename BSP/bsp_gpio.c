
#include "main.h"


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef        GPIO_InitStructure;
	//enable port clock
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化该端口
	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化该端口
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
//	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化该端口
	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
//	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化该端口
	
	LED_OFF(LED1|LED2|LED3|LED4);
}


void LED_ON(unsigned char bits)
{
//	if(bits&LED1)   GPIO_ResetBits(GPIOE,GPIO_Pin_9);
//	if(bits&LED2)   GPIO_ResetBits(GPIOB,GPIO_Pin_2);
//	if(bits&LED3)   GPIO_ResetBits(GPIOB,GPIO_Pin_1);
//	if(bits&LED4)   GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	
	if(bits&LED1)   GPIOB->BSRRH = GPIO_Pin_7;
	if(bits&LED2)   GPIOB->BSRRH = GPIO_Pin_6;
	if(bits&LED3)   GPIOB->BSRRH = GPIO_Pin_5;
	if(bits&LED4)   GPIOB->BSRRH = GPIO_Pin_4;
}

void LED_OFF(unsigned char bits)
{
//	if(bits&LED1)   GPIO_SetBits(GPIOE,GPIO_Pin_9);
//	if(bits&LED2)   GPIO_SetBits(GPIOB,GPIO_Pin_2);
//	if(bits&LED3)   GPIO_SetBits(GPIOB,GPIO_Pin_1);
//	if(bits&LED4)   GPIO_SetBits(GPIOB,GPIO_Pin_0);
	
	if(bits&LED1)   GPIOB->BSRRL = GPIO_Pin_7;
	if(bits&LED2)   GPIOB->BSRRL = GPIO_Pin_6;
	if(bits&LED3)   GPIOB->BSRRL = GPIO_Pin_5;
	if(bits&LED4)   GPIOB->BSRRL = GPIO_Pin_4;
}








