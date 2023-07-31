
#include "main.h"

#define SPI_Wait_TimeOut  		0xffff     //��ʱ���� 0x5000	

/*******************************************************************************
* Function Name  : SPI2_Configuration
* Description    : STM32 SPI1����
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI2_Configuration(void)
{
	SPI_InitTypeDef  SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);													//������ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOE  , ENABLE);
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_SPI2);                     						//����Ϊ���蹦�ܣ��˴����ܺϲ�
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource2, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource3, GPIO_AF_SPI2);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;															//���ö˿�ģʽ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                						//���踴��ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;														//����ģʽ
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;														//Ĭ������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;													//GPIO��ת�ٶ�Ϊ25MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);																//������д���Ӧ��GPIO�Ĵ�����
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;												//���ö˿�ģʽ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                						//���踴��ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;														//����ģʽ
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;														//Ĭ������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;													//GPIO��ת�ٶ�Ϊ25MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);																//������д���Ӧ��GPIO�Ĵ�����

	//PE6=ADT7301_CS��PE15=FLASH_CS��
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_15;													//����SPIƬѡ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;																//�˿����ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;																//����ģʽ
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;																//Ĭ����������ֹADƬѡ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;															//GPIO��ת�ٶ�Ϊ2MHz
	GPIO_Init(GPIOE, &GPIO_InitStructure);																		//������д���Ӧ��GPIO�Ĵ����� 
	
	//PC13=ADT7301_CS
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;																	//����SPIƬѡ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;																//�˿����ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;																//����ģʽ
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;																//Ĭ����������ֹADƬѡ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;															//GPIO��ת�ٶ�Ϊ2MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);																		//������д���Ӧ��GPIO�Ĵ����� 
	
	
	
	/* SPI2 configuration */
	SPI_Cmd(SPI2, DISABLE); 
	SPI_I2S_DeInit(SPI2);
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;							//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;//����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;//����ͬ��ʱ�ӵĵ�1�������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ2
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	SPI_Init(SPI2, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
	
	SPI_Cmd(SPI2, ENABLE); 
}

/*******************************************************************************
* Function Name  : SPI1_ReadWriteByte
* Description    : ��SPI�����϶�ȡ��дһ���ֽ�����
* Input          : д�ֽ�
* Output         : None
* Return         : None
*******************************************************************************/
unsigned char SPI2_ReadWriteByte(unsigned char byte)
{
  unsigned int timeout = SPI_Wait_TimeOut;
 
  while ((SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET) && (timeout--)); 	/*!< Loop while DR register in not emplty */
  SPI_I2S_SendData(SPI2, byte);/*!< Send byte through the SPI2 peripheral */
	
  timeout = SPI_Wait_TimeOut;
  while ((SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET) && (timeout--));/*!< Wait to receive a byte */
 
  return SPI_I2S_ReceiveData(SPI2); /*!< Return the byte read from the SPI bus */
}


unsigned char SPI2_CS_Select(unsigned char cs)
{
	if(cs==ADT_CS)
	{
		FLASH_CS_H;
		SRAM_CS_H;
		ADT_CS_L;
		return SUCCESS;
	}
	else if(cs==FLASH_CS)
	{
		SRAM_CS_H;
		ADT_CS_H;
		FLASH_CS_L;
		return SUCCESS;
	}
	else if(cs==SRAM_CS)
	{
		ADT_CS_H;
		FLASH_CS_H;
		SRAM_CS_L;
		return SUCCESS;
	}
	else if(cs==SPI2_CS_ALL_H)
	{
		ADT_CS_H;
		FLASH_CS_H;
		SRAM_CS_H;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}


void SPI4_Configuration(void)
{
	SPI_InitTypeDef  SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStruct;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI4,ENABLE);													//������ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE  , ENABLE);
	
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource4, GPIO_AF_SPI4);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_SPI4);                     						//����Ϊ���蹦�ܣ��˴����ܺϲ�
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_SPI4);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_SPI4);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;															//���ö˿�ģʽ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                						//���踴��ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;														//����ģʽ
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;														//Ĭ������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;													//GPIO��ת�ٶ�Ϊ25MHz
	GPIO_Init(GPIOE, &GPIO_InitStructure);																//������д���Ӧ��GPIO�Ĵ�����
	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;												//���ö˿�ģʽ��
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                						//���踴��ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;														//����ģʽ
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;														//Ĭ������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;													//GPIO��ת�ٶ�Ϊ25MHz
//	GPIO_Init(GPIOC, &GPIO_InitStructure);																//������д���Ӧ��GPIO�Ĵ�����

//	//PE6=ADT7301_CS��PE15=FLASH_CS��
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_15;													//����SPIƬѡ
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;																//�˿����ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;																//����ģʽ
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;																//Ĭ����������ֹADƬѡ
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;															//GPIO��ת�ٶ�Ϊ2MHz
//	GPIO_Init(GPIOE, &GPIO_InitStructure);																		//������д���Ӧ��GPIO�Ĵ����� 
//	
//	//PC13=ADT7301_CS
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;																	//����SPIƬѡ
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;																//�˿����ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;																//����ģʽ
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;																//Ĭ����������ֹADƬѡ
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;															//GPIO��ת�ٶ�Ϊ2MHz
//	GPIO_Init(GPIOC, &GPIO_InitStructure);																		//������д���Ӧ��GPIO�Ĵ����� 
//	
	
	
	/* SPI2 configuration */
	SPI_Cmd(SPI4, DISABLE); 
	SPI_I2S_DeInit(SPI4);
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;							//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;//����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;//����ͬ��ʱ�ӵĵ�1�������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Hard;//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ2
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	SPI_Init(SPI4, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
	
	/* NVIC Init */
	NVIC_InitStruct.NVIC_IRQChannel = SPI4_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	SPI_I2S_ITConfig(SPI4, SPI_I2S_IT_TXE | SPI_I2S_IT_RXNE | SPI_I2S_IT_ERR, ENABLE);
	SPI_Cmd(SPI4, ENABLE); 
}


/*******************************************************************************
* Function Name  : SPI1_ReadWriteByte
* Description    : ��SPI�����϶�ȡ��дһ���ֽ�����
* Input          : д�ֽ�
* Output         : None
* Return         : None
*******************************************************************************/
unsigned char SPI4_ReadWriteByte(unsigned char byte)
{
  unsigned int timeout = SPI_Wait_TimeOut;
 
  while ((SPI_I2S_GetFlagStatus(SPI4, SPI_I2S_FLAG_TXE) == RESET) && (timeout--)); 	/*!< Loop while DR register in not emplty */
  SPI_I2S_SendData(SPI4, byte);/*!< Send byte through the SPI2 peripheral */
	
  timeout = SPI_Wait_TimeOut;
  while ((SPI_I2S_GetFlagStatus(SPI4, SPI_I2S_FLAG_RXNE) == RESET) && (timeout--));/*!< Wait to receive a byte */
 
  return SPI_I2S_ReceiveData(SPI4); /*!< Return the byte read from the SPI bus */
}









