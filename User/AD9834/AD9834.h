
#ifndef __AD9834_H
#define __AD9834_H

#define DDS_POW_ON()      GPIO_SetBits(GPIOB,GPIO_Pin_8)
#define DDS_POW_OFF()	  GPIO_ResetBits(GPIOB,GPIO_Pin_8) 

#define DDS_LED_ON()      GPIO_ResetBits(GPIOD,GPIO_Pin_12)
#define DDS_LED_OFF()	  GPIO_SetBits(GPIOD,GPIO_Pin_12) 


#define DDS_RESET_H()     GPIO_SetBits(GPIOE,GPIO_Pin_3)
#define DDS_RESET_L()	  GPIO_ResetBits(GPIOE,GPIO_Pin_3) 

#define DDS_SLEEP_H()     GPIO_SetBits(GPIOE,GPIO_Pin_2)
#define DDS_SLEEP_L()	  GPIO_ResetBits(GPIOE,GPIO_Pin_2) 

#define DDS_PS_H()        GPIO_SetBits(GPIOA,GPIO_Pin_15)
#define DDS_PS_L()	  	  GPIO_ResetBits(GPIOA,GPIO_Pin_15) 

#define DDS_FS_H()        GPIO_SetBits(GPIOD,GPIO_Pin_4)
#define DDS_FS_L()	  	  GPIO_ResetBits(GPIOD,GPIO_Pin_4) 

#define DDS_CS_H()        GPIO_SetBits(GPIOD,GPIO_Pin_7)
#define DDS_CS_L()	  	  GPIO_ResetBits(GPIOD,GPIO_Pin_7) 

//ctrl寄存器

void DDS_GPIO_Configuration(void);
void DDS_test(void);





/* AD9834 晶振频率*/
#define AD9834_TCXO_COLCK     75000000UL
#define Triangle_Wave    0x2002
#define Sine_Wave  0x2028

/* AD9834 控制引脚*/
#define AD9834_Control_Port GPIOC
#define AD9834_FSYNC GPIO_Pin_6
#define AD9834_SCLK GPIO_Pin_7
#define AD9834_SDATA GPIO_Pin_8
#define AD9834_RESET GPIO_Pin_9

#define AD9834_FSYNC_SET GPIO_SetBits(AD9834_Control_Port ,AD9834_FSYNC)
#define AD9834_FSYNC_CLR GPIO_ResetBits(AD9834_Control_Port ,AD9834_FSYNC)

#define AD9834_SCLK_SET GPIO_SetBits(AD9834_Control_Port ,AD9834_SCLK)
#define AD9834_SCLK_CLR GPIO_ResetBits(AD9834_Control_Port ,AD9834_SCLK)

#define AD9834_SDATA_SET GPIO_SetBits(AD9834_Control_Port ,AD9834_SDATA)
#define AD9834_SDATA_CLR GPIO_ResetBits(AD9834_Control_Port ,AD9834_SDATA)

#define AD9834_RESET_SET GPIO_SetBits(GPIOE ,GPIO_Pin_3)
#define AD9834_RESET_CLR GPIO_ResetBits(GPIOE ,GPIO_Pin_3)

#define FREQ_0 0
#define FREQ_1 1

#define DB15 0
#define DB14 0
#define DB13 B28
#define DB12 HLB
#define DB11 FSEL
#define DB10 PSEL
#define DB9 PIN_SW
#define DB8 RESET
#define DB7 SLEEP1
#define DB6 SLEEP12
#define DB5 OPBITEN
#define DB4 SIGN_PIB
#define DB3 DIV2
#define DB2 0
#define DB1 MODE
#define DB0 0

#define CONTROL_REGISTER (DB15<<15)|(DB14<<14)|(DB13<<13)|(DB12<<12)|(DB11<<11)|(DB10<<10)\
						|(DB9<<9)|(DB8<<8)|(DB7<<7)|(DB6<<6)|(DB5<<5)|(DB4<<4)|(DB3<<3)|(DB2<<2)|(DB1<<1)|(DB0<<0)



/* AD9834 函数声明*/
extern void AD9834_Write_16Bits(unsigned int data) ; //写一个字到AD9834
extern void AD9834_Select_Wave(unsigned int initdata) ; // 选择输出波形
extern void Init_AD9834() ;// 初始化配置
extern void AD9834_Set_Freq(unsigned char freq_number, unsigned long freq) ;// 选择输出寄存器和输出频率值












#endif


