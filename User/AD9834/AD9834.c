/* Includes ------------------------------------------------------------------*/
#include "main.h"

//void DDS_GPIO_Configuration(void)
//{
//	GPIO_InitTypeDef        GPIO_InitStructure;
//	
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;							//DDS_PS
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化该端口
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;							//DDS_POWERCTRL
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化该端口
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_7 | GPIO_Pin_12;		//PD4->DDS_FS,PD7->DDS_CS,PD12->DDS_LED
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
//	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化该端口
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;					//PE2->DDS_SLEEP,PD3->DDS_RESET
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
//	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化该端口	
//}

//void DDS_SPI4_Init(void)
//{
//	SPI_InitTypeDef  SPI_InitStructure;
//	GPIO_InitTypeDef GPIO_InitStructure;
//  
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI4,ENABLE);													//打开外设时钟
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE  , ENABLE);
//	
//	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_SPI4);                     						//设置为外设功能，此处不能合并
//	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_SPI4);
//	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_SPI4);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;															//设置端口模式，
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                						//外设复用模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;														//推挽模式
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;														//默认下拉
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;													//GPIO翻转速度为25MHz
//	GPIO_Init(GPIOE, &GPIO_InitStructure);																//将配置写入对应的GPIO寄存器中
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_14;												//设置端口模式，
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                						//外设复用模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;														//推挽模式
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;														//默认下拉
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;													//GPIO翻转速度为25MHz
//	GPIO_Init(GPIOE, &GPIO_InitStructure);																//将配置写入对应的GPIO寄存器中
//	
//	
//	
//	/* SPI2 configuration */
//	SPI_Cmd(SPI4, DISABLE); 
//	SPI_I2S_DeInit(SPI4);
//	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//设置SPI单向或者双向的数据模式:SPI设置为双线双向全双工
//	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;							//设置SPI工作模式:设置为主SPI
//	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;//设置SPI的数据大小:SPI发送接收8位帧结构
//	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;//串行同步时钟的空闲状态为高电平
//	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;//串行同步时钟的第1个跳变沿（上升或下降）数据被采样
//	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;//NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
//	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;//定义波特率预分频的值:波特率预分频值为2
//	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;//指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
//	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRC值计算的多项式
//	SPI_Init(SPI4, &SPI_InitStructure);  //根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器
//	
//	SPI_Cmd(SPI4, ENABLE); 
//}

///*******************************************************************************
//* Function Name  : SPI1_ReadWriteByte
//* Description    : 从SPI总线上读取或写一个字节数据
//* Input          : 写字节
//* Output         : None
//* Return         : None
//*******************************************************************************/
//unsigned int SPI4_Wait_TimeOut=1000;

//unsigned char SPI4_ReadWriteByte(unsigned char byte)
//{
//  unsigned int timeout = SPI4_Wait_TimeOut;
// 
//  while ((SPI_I2S_GetFlagStatus(SPI4, SPI_I2S_FLAG_TXE) == RESET) && (timeout--)); 	/*!< Loop while DR register in not emplty */
//  SPI_I2S_SendData(SPI4, byte);/*!< Send byte through the SPI2 peripheral */
//	
//  timeout = SPI4_Wait_TimeOut;
//  while ((SPI_I2S_GetFlagStatus(SPI4, SPI_I2S_FLAG_RXNE) == RESET) && (timeout--));/*!< Wait to receive a byte */
// 
//  return SPI_I2S_ReceiveData(SPI4); /*!< Return the byte read from the SPI bus */
//}


//void DDS_test(void)
//{
//	Dac1_fixed_Init();
//	Dac1_Set_fixed_Vol(0.1);
//	Delay_ms(50);
//	
//	DDS_GPIO_Configuration();
//	
//	DDS_POW_ON();
//	Delay_ms(50);
//	
//	DDS_SPI4_Init();
//	
//	DDS_RESET_H();	 //复位引脚。高电平复位
//	DDS_SLEEP_L();	 //休眠引脚。高电平休眠
//	DDS_PS_L(); 	//PS 相位选择 =0，选择p0寄存器，=1，选择p1寄存器
//	DDS_FS_L();		//FS 频率选择 =0，选择f0寄存器，=1，选择f1寄存器
//	
//	DDS_CS_L();
//	{
//		unsigned int fre=1000/20000*pow(2,28)-1;
//		
//		unsigned short frq_high=fre/0x4000+0x4000;
//		unsigned short frq_low=fre%0x4000+0x4000;
//		
//		SPI4_ReadWriteByte(0x20);
//		SPI4_ReadWriteByte(0x38);
//		
//		SPI4_ReadWriteByte(frq_low%256);
//		SPI4_ReadWriteByte(frq_low/256);
//		
//		SPI4_ReadWriteByte(frq_high%256);
//		SPI4_ReadWriteByte(frq_high/256);
//		
//	}
//	
//	LOG_D("%x %x",SPI4_ReadWriteByte(0x00),SPI4_ReadWriteByte(0x00));
//	
//	
//	
//}


/****************************************************************
函数名称: AD9834_Write_16Bits
功    能: 向AD9834写入16为数据
参    数: data --  要写入的16位数据
返回值  : 无
*****************************************************************/
void AD9834_Write_16Bits(unsigned int data)
{
    unsigned char i = 0 ;
   
    AD9834_SCLK_SET ;
    AD9834_FSYNC_CLR ;
    for(i=0 ;i<16 ;i++)
    {
        if(data & 0x8000)
          AD9834_SDATA_SET ;
        else
          AD9834_SDATA_CLR ;
        
        AD9834_SCLK_CLR ;
        data <<= 1 ;
        AD9834_SCLK_SET ;
    }
   
    AD9834_FSYNC_SET ;
}
///***********************************************************************************
//函数名称：AD9834_Select_Wave
//功    能：软件为控制，
//    --------------------------------------------------
//    IOUT正弦波 ，SIGNBITOUT方波 ，写FREQREG0 ，写PHASE0
//    ad9834_write_16bit(0x2028)   一次性写FREQREG0
//    ad9834_write_16bit(0x0038)   单独改写FREQREG0的LSB
//    ad9834_write_16bit(0x1038)   单独改写FREQREG0的MSB
//    --------------------------------------------------
//    IOUT三角波 ，写PHASE0
//    ad9834_write_16bit(0x2002)   一次性写FREQREG0
//    ad9834_write_16bit(0x0002)   单独改写FREQREG0的LSB
//    ad9834_write_16bit(0x1008)   单独改写FREQREG0的MSB
//参    数：initdata -- 要输入的命令
//返回值  ：无
//************************************************************************************/
void AD9834_Select_Wave(unsigned int initdata)
{
    AD9834_FSYNC_SET;
    AD9834_SCLK_SET;
   
    AD9834_RESET_SET;
    AD9834_RESET_SET;
    AD9834_RESET_CLR;
     
    AD9834_Write_16Bits(initdata);
}
///****************************************************************
//函数名称: Init_AD9834
//功    能: 初始化AD9834控制引脚
//参    数: 无
//返回值  : 无
//*****************************************************************/
void Init_AD9834()
{
    GPIO_InitTypeDef GPIO_InitStructure ;
    GPIO_InitStructure.GPIO_Pin = AD9834_FSYNC | AD9834_SCLK | AD9834_SDATA | AD9834_RESET ;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(AD9834_Control_Port ,&GPIO_InitStructure) ;
}
///****************************************************************
//函数名称: AD9834_Set_Freq
//功    能: 设置频率值
//参    数: freq_number -- 要写入的平率寄存器(FREQ_0或FREQ_1)
//          freq -- 频率值 (Freq_value(value)=Freq_data(data)*FCLK/2^28)
//返回值  : 无
//*****************************************************************/
void AD9834_Set_Freq(unsigned char freq_number, unsigned long freq)
{
    unsigned long FREQREG = (unsigned long)(268435456.0/AD9834_TCXO_COLCK*freq);
   
    unsigned int FREQREG_LSB_14BIT = (unsigned int)FREQREG;
    unsigned int FREQREG_MSB_14BIT = (unsigned int)(FREQREG>>14);
   
    if(freq_number == FREQ_0)
    {
        FREQREG_LSB_14BIT &= ~(1U<<15);
        FREQREG_LSB_14BIT |= 1<<14;
        FREQREG_MSB_14BIT &= ~(1U<<15);
        FREQREG_MSB_14BIT |= 1<<14;
    }
    else
    {
        FREQREG_LSB_14BIT &= ~(1<<14);
        FREQREG_LSB_14BIT |= 1U<<15;
        FREQREG_MSB_14BIT &= ~(1<<14);
        FREQREG_MSB_14BIT |= 1U<<15;
    }
   
    AD9834_Write_16Bits(FREQREG_LSB_14BIT);
    AD9834_Write_16Bits(FREQREG_MSB_14BIT);
   
}
////============================================================//















