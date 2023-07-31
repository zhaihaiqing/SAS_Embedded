/* Includes ------------------------------------------------------------------*/
#include "main.h"

//TMP102采用默认设置
//Read a tmp102 sensor on a given temp_number or channel
uint32_t TimeDelay=0xfffff;
void TMP102_Init(void)
{
	i2c_port_init();
}
unsigned char Tmp102Read_Data(uint8_t * pBuffer1,uint8_t Device_addr,uint8_t Reg_addr, uint16_t NumByteToRead1)
{
	uint32_t Timeout=TimeDelay;
	 
	i2c_port_start();//I2C_GenerateSTART(I2C2, ENABLE);	/* Send START condition */
	/* Test on EV5 and clear it */
	//while((!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))&&(Timeout--));
	/* Send sensor address */
	//I2C_Send7bitAddress(I2C2, Device_addr, I2C_Direction_Transmitter);
	i2c_port_send_byte(Device_addr|0x00);
	/* Test on EV6 and clear it */
	//Timeout=TimeDelay;
	//while((!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))&&(Timeout--));
	/* Make sure pointer register is set to read from temp register */
	if(i2c_port_wait_ack())	//等待应答
	{
		i2c_port_stop();		 
		return 1;		
	}
	
	//I2C_SendData(I2C2, Reg_addr);
	i2c_port_send_byte(Reg_addr);
	if(i2c_port_wait_ack())	//等待应答
	{
		i2c_port_stop();		 
		return 1;		
	}
	/* Test on EV8 and clear it */
	//Timeout=TimeDelay;
	//while((!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))&&(Timeout--));
	/* Send START condition a second time */
	//I2C_GenerateSTART(I2C2, ENABLE);
	i2c_port_start();
	/* Test on EV5 and clear it */
	//Timeout=TimeDelay;
	//while((!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))&&(Timeout--));
	/* Send Sensor address for read */
	//I2C_Send7bitAddress(I2C2, Device_addr, I2C_Direction_Receiver);
	i2c_port_send_byte(Device_addr|0x01);
	if(i2c_port_wait_ack())	//等待应答
	{
		i2c_port_stop();		 
		return 1;		
	}
	/* Test on EV6 and clear it */
	//Timeout=TimeDelay;
	//while((!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))&&(Timeout--));
	// Now read the 2 bytes in
	/* While there is data to be read */
	while(NumByteToRead1)
	{
//		if(NumByteToRead1 == 1)
//		{
//			/* Disable Acknowledgement */
//			//I2C_AcknowledgeConfig(I2C2, DISABLE);
//			/* Send STOP Condition */
//			//I2C_GenerateSTOP(I2C2, ENABLE);
//			i2c_port_stop();
//		}
		/* Test on EV7 and clear it */
//		if(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED))
//		{
//			/* Read a byte */
//			*pBuffer1 = i2c_port_read_byte(0);
//			/* Point to the next location where the byte read will be saved */
//			pBuffer1++;
//			/* Decrement the read bytes counter */
//			NumByteToRead1--;
//		}
		if(NumByteToRead1 == 1)*pBuffer1 = i2c_port_read_byte(0);
		else	
		{
			*pBuffer1 = i2c_port_read_byte(1);
			i2c_port_wait_ack();
		}
		
		pBuffer1++;
		NumByteToRead1--;
	}
	i2c_port_stop();
	/* Enable Acknowledgement to be ready for another reception */
	//I2C_AcknowledgeConfig(I2C2, ENABLE);
}


void TMP102_ReadTemp(void)
{
	uint8_t	tmp[2]={0};
	float temp=0;
	
	Tmp102Read_Data(tmp,Temp102_addr,TMP102_TEMP_REG,2);
	
	temp = ( ( (int16_t)(tmp[0]<<8 | tmp[1]) )>>4 )*0.0625;
	
	log_info("tmp[0]:0x%x,tmp[1]:0x%x,tmp:%.2f\r\n",tmp[0],tmp[1],temp);
}














