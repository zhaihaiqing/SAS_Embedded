/* Includes ------------------------------------------------------------------*/
#include "main.h"


/*******************************************************************************
* Function Name  : Temp_Read
* Description    : ADT7301»ñÈ¡ÎÂ¶È
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
float Temp_Read(void)
{
	unsigned int TempVal_temp;
	unsigned char MSByte,LSByte;
	float TempVal,tt;
	
	SPI2_CS_Select(ADT_CS);
	//rt_thread_mdelay(10);
	
	MSByte=SPI2_ReadWriteByte(0x00);//
	LSByte=SPI2_ReadWriteByte(0x00);//
	
	//rt_thread_mdelay(5);
	SPI2_CS_Select(SPI2_CS_ALL_H);
	
	TempVal_temp = (MSByte<<8) | LSByte;
	TempVal      = 1.0*TempVal_temp;
	if((TempVal_temp & 0x2000) == 0x2000) tt = (TempVal-16384)/32;
	else 
		tt = (TempVal/32);
	
	log_info("ADT_temp=%.2f\r\n",tt);
	return tt;
}

void get_temp(void)
{
    (void)Temp_Read();
}
//MSH_CMD_EXPORT(get_temp , get temp from ADT7301);













