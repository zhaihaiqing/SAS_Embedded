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
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ���ö˿�
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;							//DDS_POWERCTRL
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ���ö˿�
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_7 | GPIO_Pin_12;		//PD4->DDS_FS,PD7->DDS_CS,PD12->DDS_LED
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//	GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ���ö˿�
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;					//PE2->DDS_SLEEP,PD3->DDS_RESET
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ���ö˿�	
//}

//void DDS_SPI4_Init(void)
//{
//	SPI_InitTypeDef  SPI_InitStructure;
//	GPIO_InitTypeDef GPIO_InitStructure;
//  
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI4,ENABLE);													//������ʱ��
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE  , ENABLE);
//	
//	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_SPI4);                     						//����Ϊ���蹦�ܣ��˴����ܺϲ�
//	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_SPI4);
//	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_SPI4);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;															//���ö˿�ģʽ��
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                						//���踴��ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;														//����ģʽ
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;														//Ĭ������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;													//GPIO��ת�ٶ�Ϊ25MHz
//	GPIO_Init(GPIOE, &GPIO_InitStructure);																//������д���Ӧ��GPIO�Ĵ�����
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_14;												//���ö˿�ģʽ��
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                						//���踴��ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;														//����ģʽ
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;														//Ĭ������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;													//GPIO��ת�ٶ�Ϊ25MHz
//	GPIO_Init(GPIOE, &GPIO_InitStructure);																//������д���Ӧ��GPIO�Ĵ�����
//	
//	
//	
//	/* SPI2 configuration */
//	SPI_Cmd(SPI4, DISABLE); 
//	SPI_I2S_DeInit(SPI4);
//	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
//	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;							//����SPI����ģʽ:����Ϊ��SPI
//	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
//	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;//����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
//	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;//����ͬ��ʱ�ӵĵ�1�������أ��������½������ݱ�����
//	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
//	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ2
//	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
//	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
//	SPI_Init(SPI4, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
//	
//	SPI_Cmd(SPI4, ENABLE); 
//}

///*******************************************************************************
//* Function Name  : SPI1_ReadWriteByte
//* Description    : ��SPI�����϶�ȡ��дһ���ֽ�����
//* Input          : д�ֽ�
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
//	DDS_RESET_H();	 //��λ���š��ߵ�ƽ��λ
//	DDS_SLEEP_L();	 //�������š��ߵ�ƽ����
//	DDS_PS_L(); 	//PS ��λѡ�� =0��ѡ��p0�Ĵ�����=1��ѡ��p1�Ĵ���
//	DDS_FS_L();		//FS Ƶ��ѡ�� =0��ѡ��f0�Ĵ�����=1��ѡ��f1�Ĵ���
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
��������: AD9834_Write_16Bits
��    ��: ��AD9834д��16Ϊ����
��    ��: data --  Ҫд���16λ����
����ֵ  : ��
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
//�������ƣ�AD9834_Select_Wave
//��    �ܣ����Ϊ���ƣ�
//    --------------------------------------------------
//    IOUT���Ҳ� ��SIGNBITOUT���� ��дFREQREG0 ��дPHASE0
//    ad9834_write_16bit(0x2028)   һ����дFREQREG0
//    ad9834_write_16bit(0x0038)   ������дFREQREG0��LSB
//    ad9834_write_16bit(0x1038)   ������дFREQREG0��MSB
//    --------------------------------------------------
//    IOUT���ǲ� ��дPHASE0
//    ad9834_write_16bit(0x2002)   һ����дFREQREG0
//    ad9834_write_16bit(0x0002)   ������дFREQREG0��LSB
//    ad9834_write_16bit(0x1008)   ������дFREQREG0��MSB
//��    ����initdata -- Ҫ���������
//����ֵ  ����
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
//��������: Init_AD9834
//��    ��: ��ʼ��AD9834��������
//��    ��: ��
//����ֵ  : ��
//*****************************************************************/
void Init_AD9834()
{
    GPIO_InitTypeDef GPIO_InitStructure ;
    GPIO_InitStructure.GPIO_Pin = AD9834_FSYNC | AD9834_SCLK | AD9834_SDATA | AD9834_RESET ;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
    GPIO_Init(AD9834_Control_Port ,&GPIO_InitStructure) ;
}
///****************************************************************
//��������: AD9834_Set_Freq
//��    ��: ����Ƶ��ֵ
//��    ��: freq_number -- Ҫд���ƽ�ʼĴ���(FREQ_0��FREQ_1)
//          freq -- Ƶ��ֵ (Freq_value(value)=Freq_data(data)*FCLK/2^28)
//����ֵ  : ��
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















