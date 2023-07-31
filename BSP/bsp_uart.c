/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define UART_FLAG_TimeOut  0x50000   //��ʱ����

unsigned char Uart1Flag;
UART1_RBUF_ST	uart1_rbuf	=	{ 0, 0, };

unsigned char Uart2Flag;
UART2_RBUF_ST	uart2_rbuf	=	{ 0, 0, };

unsigned char Uart3Flag;
UART3_RBUF_ST	uart3_rbuf	=	{ 0, 0, };

#ifdef	USE_UART7
unsigned char Uart7Flag=0;
unsigned short uart7_rx_len=0;
UART7_RBUF_ST	uart7_rbuf	=	{ 0, 0, };
#endif


/**********************************************************************************
* Function Name  : UART7_Configuration
* ����7��ʼ��
* ��ڲ���
* baudrate:������
**********************************************************************************/
void UART7_Configuration(unsigned int baudrate)
{
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* Enable the USART1 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = UART7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	//��GPIO��USART2��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART7, ENABLE);
	
	//����7��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource7,GPIO_AF_UART7); //GPIOE7����ΪUART7
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource8,GPIO_AF_UART7); //GPIOE8����ΪUART7
	
	/* ��UART7_Tx��GPIO����Ϊ���츴��ģʽ */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;     
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;		
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = baudrate;//���ò�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//��������λΪ8
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//����ֹͣλΪ1
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������λ
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//���ͺͽ���
	USART_Init(UART7, &USART_InitStructure);
	
	USART_ClearFlag(UART7, USART_FLAG_TC);     /* �巢�ͱ�־��Transmission Complete flag */
	USART_ClearFlag(UART7, USART_FLAG_IDLE); //���������IDLE�жϣ������һֱ��IDLE�ж�
	
	USART_ITConfig(UART7, USART_IT_RXNE, ENABLE);
	USART_ITConfig(UART7, USART_IT_IDLE, ENABLE);  //���� UART7 ���߿����ж�
	
//	USART_ITConfig(UART7, USART_IT_ERR, ENABLE);
//	USART_ITConfig(UART7, USART_IT_ORE, ENABLE);
//	USART_ITConfig(UART7, USART_IT_PE, ENABLE);
//	USART_ITConfig(UART7, USART_IT_NE, ENABLE);
//	USART_ITConfig(UART7, USART_IT_FE, ENABLE);
	
	//ʹ��
	USART_Cmd(UART7, ENABLE);
	//�ж�ʹ��
	
	//return 0;
}

/**********************************************************************************
* Function Name  : USART_PutChar
* ���ڷ���һ���ַ�
* ��ڲ���
* USARTx:���ں�
* ch:����
**********************************************************************************/
void USART_PutChar(USART_TypeDef* USARTx,uint8_t  ch)
{
  unsigned int timeout = 0;
  USART_SendData(USARTx, (uint8_t)  ch);
  while((USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET) && (timeout++ < UART_FLAG_TimeOut));
}
/**********************************************************************************
* Function Name  : USART_PutData
* ���ڷ������ɸ��ַ�
* ��ڲ���
* USARTx:���ں�
* ch:����
* len:���ݳ���
**********************************************************************************/
void USART_PutData(USART_TypeDef* USARTx,unsigned char *dat,unsigned short int len)
{
	unsigned short int i;
	for(i = 0;i < len;i++)USART_PutChar(USARTx,(uint8_t)* (dat++));
}
/**********************************************************************************
* Function Name  : USART_PutS
* ���ڷ����ַ���
* ��ڲ���
* USARTx:���ں�
* *s:����ָ��
**********************************************************************************/
void USART_PutS(USART_TypeDef* USARTx,unsigned char *s)
{
	while(*s != '\0')USART_PutChar(USARTx,*(s++));
}


/**********************************************************************************
* ����1�����ַ�����������ģʽ�����ջ���������ȡ��
**********************************************************************************/
uint16_t USART1_GetCharBlock(uint16_t timeout)
{
	UART1_RBUF_ST *p = &uart1_rbuf;
	uint16_t to = timeout;	
	while(p->out == p->in)if(!(--to))return TIMEOUT;
	return (p->buf [(p->out++) & (UART1_RBUF_SIZE - 1)]);
}

/**********************************************************************************
* ����1�����ַ�������������ģʽ�����ջ���������ȡ��
**********************************************************************************/
uint16_t USART1_GetChar(void)
{
	UART1_RBUF_ST *p = &uart1_rbuf;			
	if(p->out == p->in) //������������
		return EMPTY;
	return USART1_GetCharBlock(1000);
}

/**********************************************************************************
* ����2�����ַ�����������ģʽ�����ջ���������ȡ��
**********************************************************************************/
uint16_t USART2_GetCharBlock(uint16_t timeout)
{
	UART2_RBUF_ST *p = &uart2_rbuf;
	uint16_t to = timeout;	
	while(p->out == p->in)if(!(--to))return TIMEOUT;
	return (p->buf [(p->out++) & (UART2_RBUF_SIZE - 1)]);
}

/**********************************************************************************
* ����2�����ַ�������������ģʽ�����ջ���������ȡ��
**********************************************************************************/
uint16_t USART2_GetChar(void)
{
	UART2_RBUF_ST *p = &uart2_rbuf;			
	if(p->out == p->in) //������������
		return EMPTY;
	return USART2_GetCharBlock(1000);
}

/**********************************************************************************
* ����3�����ַ�����������ģʽ�����ջ���������ȡ��
**********************************************************************************/
uint16_t USART3_GetCharBlock(uint16_t timeout)
{
	UART3_RBUF_ST *p = &uart3_rbuf;
	uint16_t to = timeout;
	while(((p->out - p->in)& (UART3_RBUF_SIZE - 1)) == 0)if(!(--to))return TIMEOUT;
	return (p->buf [(p->out++) & (UART3_RBUF_SIZE - 1)]);
}

/**********************************************************************************
* ����3�����ַ�������������ģʽ�����ջ���������ȡ��
**********************************************************************************/
uint16_t USART3_GetChar(void)
{
	UART3_RBUF_ST *p = &uart3_rbuf;		
	if(((p->out - p->in) & (UART3_RBUF_SIZE - 1)) == 0) //������������
		return EMPTY;
	return USART3_GetCharBlock(1000);
}





/**********************************************************************************
* ����7�����ַ�����������ģʽ�����ջ���������ȡ��
**********************************************************************************/
#ifdef	USE_UART7
uint16_t USART7_GetCharBlock(uint16_t timeout)
{
	UART7_RBUF_ST *p = &uart7_rbuf;
	uint16_t to = timeout;
	while(((p->out - p->in)& (UART7_RBUF_SIZE - 1)) == 0)if(!(--to))return TIMEOUT;
	return (p->buf [(p->out++) & (UART7_RBUF_SIZE - 1)]);
}
#endif

/**********************************************************************************
* ����3�����ַ�������������ģʽ�����ջ���������ȡ��
**********************************************************************************/
#ifdef	USE_UART7
uint16_t USART7_GetChar(void)
{
	UART7_RBUF_ST *p = &uart7_rbuf;		
	if(((p->out - p->in) & (UART7_RBUF_SIZE - 1)) == 0) //������������
		return EMPTY;
	return USART7_GetCharBlock(1000);
}
#endif


/**********************************************************************************
�������1���ձ�־λ����֡����
**********************************************************************************/
void USART1_ClearBuf_Flag(void)
{
	UART1_RBUF_ST *p = &uart1_rbuf;
	p->out = 0;
	p->in = 0;
	
	Uart1Flag = 0;
	//USART1_RX_Len = 0;
}

/**********************************************************************************
�������2���ձ�־λ����֡����
**********************************************************************************/
void USART2_ClearBuf_Flag(void)
{
	UART2_RBUF_ST *p = &uart2_rbuf;
	p->out = 0;
	p->in = 0;
	
	Uart2Flag = 0;
	//USART2_RX_Len = 0;
	//ModbusDataPackage.DataFlag=0;
	//ModbusDataPackage.DataLen=0;
}

/**********************************************************************************
�������3���ձ�־λ����֡����
**********************************************************************************/
void USART3_ClearBuf_Flag(void)
{
	UART3_RBUF_ST *p = &uart3_rbuf;
	p->out = 0;
	p->in = 0;
	
	Uart3Flag = 0;
	//USART3_RX_Len = 0;
}

/**********************************************************************************
�������7���ձ�־λ����֡����
**********************************************************************************/
#ifdef USE_UART7
void USART7_ClearBuf_Flag(void)
{
	UART7_RBUF_ST *p = &uart7_rbuf;
	p->out = 0;
	p->in = 0;
	
	Uart7Flag = 0;
	//USART3_RX_Len = 0;
}
#endif


/**********************************************************************************
printf���ܶ��壬(�����б�ʾ���ĸ�����������ݼ���������)
**********************************************************************************/
//PUTCHAR_PROTOTYPE
//{
//	USART_PutChar(UART7,(uint8_t) ch);
//	return ch;
//}






