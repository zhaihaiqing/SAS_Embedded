/**
  ******************************************************************************
  * @file    Project/BSP/bsp_i2c_port.c 
  * @author  zhaihaiqing
  * @version V1.0.0
  * @date    5-April-2020
  * @brief   ʹ��IOģ��I2C
  ******************************************************************************
  */
#include "main.h"

void oled_i2c_port_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(I2CA_SCL_RCC_PORT, ENABLE);//ʹ��GPIOʱ��
	RCC_AHB1PeriphClockCmd(I2CA_SDA_RCC_PORT, ENABLE);//ʹ��GPIOʱ��

	//GPIO��ʼ������
	GPIO_InitStructure.GPIO_Pin = I2CA_SCL_GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(I2CA_SCL_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	
	//GPIO��ʼ������
	GPIO_InitStructure.GPIO_Pin = I2CA_SDA_GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(I2CA_SDA_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	
	oled_i2c_port_stop();
}

/*
*********************************************************************************************************
*	�� �� ��: i2c_Delay
*	����˵��: I2C����λ�ӳ٣����400KHz
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void i2ca_port_delay(void)
{
	uint16_t i;
	/*��
		CPU��Ƶ168MHzʱ�����ڲ�Flash����, MDK���̲��Ż�����̨ʽʾ�����۲Ⲩ�Ρ�
		ѭ������Ϊ5ʱ��SCLƵ�� = 1.78MHz (����ʱ: 92ms, ��д������������ʾ����̽ͷ���ϾͶ�дʧ�ܡ�ʱ��ӽ��ٽ�)
		ѭ������Ϊ10ʱ��SCLƵ�� = 1.1MHz (����ʱ: 138ms, ���ٶ�: 118724B/s)
		ѭ������Ϊ30ʱ��SCLƵ�� = 440KHz�� SCL�ߵ�ƽʱ��1.0us��SCL�͵�ƽʱ��1.2us

		��������ѡ��2.2Kŷʱ��SCL������ʱ��Լ0.5us�����ѡ4.7Kŷ����������Լ1us

		ʵ��Ӧ��ѡ��400KHz���ҵ����ʼ���
	*/
	for (i = 0; i < 28; i++);
}

//����IIC��ʼ�ź�
void oled_i2c_port_start(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C���������ź� */
	I2CA_SDA_1();
	I2CA_SCL_1();
	i2ca_port_delay();
	I2CA_SDA_0();
	i2ca_port_delay();
	I2CA_SCL_0();
	i2ca_port_delay();
}
//����IICֹͣ�ź�
void oled_i2c_port_stop(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C����ֹͣ�ź� */
	I2CA_SDA_0();
	I2CA_SCL_1();
	i2ca_port_delay();
	I2CA_SDA_1();					   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
unsigned char oled_i2c_port_wait_ack(void)
{
	uint8_t re;
	
	I2CA_SDA_1();
	i2ca_port_delay();
	I2CA_SCL_1();
	i2ca_port_delay();
	if( I2CA_SDA_READ() )
	{
		re=1;
	}
	else
	{
		re=0;
	}
	I2CA_SCL_0();
	return re; 
} 
//����ACKӦ��
void oled_i2c_port_ack(void)
{
	I2CA_SDA_0();
	i2ca_port_delay();
	I2CA_SCL_1();
	i2ca_port_delay();
	I2CA_SCL_0();
	i2ca_port_delay();
	I2CA_SDA_1();
}
//������ACKӦ��		    
void oled_i2c_port_nack(void)
{
	I2CA_SDA_1();
	i2ca_port_delay();
	I2CA_SCL_1();
	i2ca_port_delay();
	I2CA_SCL_0();
	i2ca_port_delay();		
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void oled_i2c_port_send_byte(unsigned char txd)
{                        
    unsigned char t;
	
	for(t=0;t<8;t++)
	{
		if(txd & 0x80)
		{
			I2CA_SDA_1();
		}
		else
		{
			I2CA_SDA_0();
		}
		i2ca_port_delay();
		I2CA_SCL_1();
		i2ca_port_delay();
		I2CA_SCL_0();
		if(t == 7)
		{
			I2CB_SDA_1();
		}
		txd <<= 1;
		i2ca_port_delay();
	}
	
	I2CA_SDA_1();	//�ͷ����� 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
unsigned char oled_i2c_port_read_byte(void)
{
	unsigned char i=0,receive=0;
	
	for(i=0;i<8;i++)
	{
		receive <<= 1;
		I2CA_SCL_1();
		i2ca_port_delay();
		if( I2CA_SDA_READ() ) receive++;
		I2CA_SCL_0();
		i2ca_port_delay();
	}
	return receive;
}

/*
*********************************************************************************************************
*	�� �� ��: i2c_CheckDevice
*	����˵��: ���I2C�����豸��CPU�����豸��ַ��Ȼ���ȡ�豸Ӧ�����жϸ��豸�Ƿ����
*	��    ��:  _Address���豸��I2C���ߵ�ַ
*	�� �� ֵ: ����ֵ 0 ��ʾ��ȷ�� ����1��ʾδ̽�⵽
*********************************************************************************************************
*/
unsigned char i2cA_CheckDevice(unsigned char Device_addr)
{
	uint8_t ucAck=0;
	
	if( I2CA_SDA_READ() && I2CA_SCL_READ() )
	{
		oled_i2c_port_start();						/* ���������ź� */
		oled_i2c_port_send_byte(Device_addr | 0);	/* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
		ucAck = oled_i2c_port_wait_ack();			/* ����豸��ACKӦ�� */
		
		oled_i2c_port_stop();						/* ����ֹͣ�ź� */
		return ucAck;
	}
	return 1;		//�����쳣
}























/*
****************************************************************************************
****************************************************************************************
****************************************************************************************
****************************************************************************************
****************************************************************************************
*/


void i2cb_port_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(I2CB_SCL_RCC_PORT, ENABLE);//ʹ��GPIOʱ��
	RCC_AHB1PeriphClockCmd(I2CB_SDA_RCC_PORT, ENABLE);//ʹ��GPIOʱ��

	//GPIOE11,E10��ʼ������
	GPIO_InitStructure.GPIO_Pin = I2CB_SCL_GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//��©���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(I2CB_SCL_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	
	//GPIOE11,E10��ʼ������
	GPIO_InitStructure.GPIO_Pin = I2CB_SDA_GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//��©���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(I2CB_SDA_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	
	i2cb_port_stop();
}



/*
*********************************************************************************************************
*	�� �� ��: i2c_Delay
*	����˵��: I2C����λ�ӳ٣����400KHz
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void i2cb_port_delay(void)
{
	uint16_t i;
	/*��
		CPU��Ƶ168MHzʱ�����ڲ�Flash����, MDK���̲��Ż�����̨ʽʾ�����۲Ⲩ�Ρ�
		ѭ������Ϊ5ʱ��SCLƵ�� = 1.78MHz (����ʱ: 92ms, ��д������������ʾ����̽ͷ���ϾͶ�дʧ�ܡ�ʱ��ӽ��ٽ�)
		ѭ������Ϊ10ʱ��SCLƵ�� = 1.1MHz (����ʱ: 138ms, ���ٶ�: 118724B/s)
		ѭ������Ϊ30ʱ��SCLƵ�� = 440KHz�� SCL�ߵ�ƽʱ��1.0us��SCL�͵�ƽʱ��1.2us

		��������ѡ��2.2Kŷʱ��SCL������ʱ��Լ0.5us�����ѡ4.7Kŷ����������Լ1us

		ʵ��Ӧ��ѡ��400KHz���ҵ����ʼ���
	*/
	for (i = 0; i < 100; i++);
}

//����IIC��ʼ�ź�
void i2cb_port_start(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C���������ź� */
	I2CB_SDA_1();
	I2CB_SCL_1();
	i2cb_port_delay();
	I2CB_SDA_0();
	i2cb_port_delay();
	I2CB_SCL_0();
	i2cb_port_delay();
}
//����IICֹͣ�ź�
void i2cb_port_stop(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C����ֹͣ�ź� */
	I2CB_SDA_0();
	I2CB_SCL_1();
	i2cb_port_delay();
	I2CB_SDA_1();					   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
unsigned char i2cb_port_wait_ack(void)
{
	uint8_t re=0;
	uint16_t times=0;
	I2CB_SDA_1();
	i2cb_port_delay();
	I2CB_SCL_1();
	i2cb_port_delay();
	
//	while( I2CB_SDA_READ() )
//	{
//		times++;
//		if(times>100)
//		{
//			i2cb_port_stop();
//			return 1;
//		}
//	}
	
	if( I2CB_SDA_READ() )
	{
		re=1;
	}
	else
	{
		re=0;
	}
	
	I2CB_SCL_0();
	i2cb_port_delay();
	return re; 
} 
//����ACKӦ��
void i2cb_port_ack(void)
{
	I2CB_SDA_0();
	i2cb_port_delay();
	I2CB_SCL_1();
	i2cb_port_delay();
	I2CB_SCL_0();
	i2cb_port_delay();
	I2CB_SDA_1();
}
//������ACKӦ��		    
void i2cb_port_nack(void)
{
	I2CB_SDA_1();
	i2cb_port_delay();
	I2CB_SCL_1();
	i2cb_port_delay();
	I2CB_SCL_0();
	i2cb_port_delay();	
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void i2cb_port_send_byte(unsigned char txd)
{                        
    unsigned char t;
	
	I2CB_SCL_0();
	
	for(t=0;t<8;t++)
	{
		if(txd & 0x80)
		{
			I2CB_SDA_1();
		}
		else
		{
			I2CB_SDA_0();
		}
		txd <<= 1;
		i2cb_port_delay();
		I2CB_SCL_1();
		i2cb_port_delay();
		I2CB_SCL_0();			
		i2cb_port_delay();
	}
	
	I2CB_SDA_1();	//�ͷ����� 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
unsigned char i2cb_port_read_byte(void)
{
	unsigned char i=0,receive=0;
	
	for(i=0;i<8;i++)
	{
		I2CB_SCL_1();
		i2cb_port_delay();
		receive <<= 1;
		if( I2CB_SDA_READ() ) receive++;
		I2CB_SCL_0();
		i2cb_port_delay();
	}
//	if(!ack)
//	{
//		i2cb_port_nack();
//	}
//	else
//	{
//		i2cb_port_ack();
//	}
			
	return receive;
}









/*
*********************************************************************************************************
*	�� �� ��: i2c_CheckDevice
*	����˵��: ���I2C�����豸��CPU�����豸��ַ��Ȼ���ȡ�豸Ӧ�����жϸ��豸�Ƿ����
*	��    ��:  _Address���豸��I2C���ߵ�ַ
*	�� �� ֵ: ����ֵ 0 ��ʾ��ȷ�� ����1��ʾδ̽�⵽
*********************************************************************************************************
*/
unsigned char i2cb_CheckDevice(unsigned char Device_addr)
{
	uint8_t ucAck=0;
	
	if( I2CB_SDA_READ() && I2CB_SCL_READ() )
	{
		i2cb_port_start();						/* ���������ź� */
		i2cb_port_send_byte(Device_addr | 0);	/* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
		ucAck = i2cb_port_wait_ack();			/* ����豸��ACKӦ�� */
		
		i2cb_port_stop();						/* ����ֹͣ�ź� */
		log_info("CheckDevice OK\r\n");
		return ucAck;
	}
	log_info("CheckDevice Failed\r\n");
	return 1;		//�����쳣
}











