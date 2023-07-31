
/*
	
*/

#include "main.h"



void Read_sendat(void)
{
	uint8_t reg[10]={0};
	
	i2cb_port_start();
	
	i2cb_port_send_byte( 0xd8);		//发送器件地址,写数据 	 
	i2cb_port_wait_ack(); 
	
    i2cb_port_send_byte(0x2e);		//发送低地址
	i2cb_port_wait_ack();
	
//	i2cb_port_send_byte(0x5b);		//发送低地址
//	i2cb_port_wait_ack();
	
	
	i2cb_port_start();
	i2cb_port_send_byte(0xd9);		//进入接收模式
	i2cb_port_wait_ack();
	
    reg[0]=i2cb_port_read_byte();
    i2cb_port_ack();
	
	reg[1]=i2cb_port_read_byte();
    i2cb_port_ack();
	
	reg[2]=i2cb_port_read_byte();
    i2cb_port_ack();
	
	reg[3]=i2cb_port_read_byte();
    i2cb_port_ack();
	
	reg[4]=i2cb_port_read_byte();
    i2cb_port_ack();
	
	reg[5]=i2cb_port_read_byte();
	i2cb_port_nack();

	i2cb_port_stop();
	
	{
		uint8_t i=0;
		for(i=0;i<6;i++)
			log_info("0x%x ",reg[i]);
		log_info("\r\n");
	}
}


uint16_t Read_OneRegdat(uint8_t reg_addr,uint8_t is_log)
{
	uint8_t reg[2]={0};
	uint16_t reg_val=0;
	
	i2cb_port_start();
	
	i2cb_port_send_byte( 0xd8);		//发送器件地址,写数据 	 
	i2cb_port_wait_ack(); 
	
    i2cb_port_send_byte(reg_addr);		//发送低地址
	i2cb_port_wait_ack();
	
//	i2cb_port_send_byte(0x5b);		//发送低地址
//	i2cb_port_wait_ack();
	
	
	i2cb_port_start();
	i2cb_port_send_byte(0xd9);		//进入接收模式
	i2cb_port_wait_ack();
	
    reg[0]=i2cb_port_read_byte();
    i2cb_port_ack();
	
	reg[1]=i2cb_port_read_byte();	
	i2cb_port_nack();

	i2cb_port_stop();
	
	
	reg_val = (reg[1]<<8) | reg[0] ;
	
	if(is_log == 1)
	{
		log_info("reg_addr[0x%x]:0x%x \r\n",reg_addr,reg_val);
	}
	
		
	return reg_val;
}

//读取e703配置寄存器
void Read_e703_CFG(void)
{
	log_info("\r\nRead_e703_CFG:\r\n");
	Read_OneRegdat(CFG_EN,1);
	Read_OneRegdat(CFG_SPI_I2C,1);
	Read_OneRegdat(CFG_PADS0,1);
	Read_OneRegdat(CFG_PADS1,1);
	Read_OneRegdat(CFG_PADS2,1);
	Read_OneRegdat(CFG_PERIOD,1);
	Read_OneRegdat(CFG_AODO,1);
	Read_OneRegdat(CFG_SBC_INTF,1);
	Read_OneRegdat(CFG_ADC,1);
	Read_OneRegdat(CFG_LP0,1);
	Read_OneRegdat(CFG_LP1,1);
	Read_OneRegdat(CFG_AFE0,1);
	Read_OneRegdat(CFG_AFE1,1);
	Read_OneRegdat(CFG_AFE2,1);
	Read_OneRegdat(CFG_CAL0,1);
	Read_OneRegdat(CFG_CAL1,1);
}

//读取e703结果寄存器
uint32_t countx=0;
void Read_e703_Results(void)
{
	uint16_t reg_val[7]={0};
	
	//log_info("\r\nRead_e703_Results:\r\n");
	reg_val[0] = Read_OneRegdat(ADC_TC,0);
	reg_val[1] = Read_OneRegdat(ADC_T,0);
	reg_val[2] = Read_OneRegdat(ADC_S,0);
	reg_val[3] = Read_OneRegdat(DSP_AODO,0);
	reg_val[4] = Read_OneRegdat(DSP_T,0);
	reg_val[5] = Read_OneRegdat(DSP_S,0);
	
	countx++;
	
	log_info("[%d] ADC_TC:0x%x ",countx,reg_val[0]);
	log_info("ADC_T:0x%x ",reg_val[0]);
	log_info("ADC_S:0x%x ",reg_val[0]);
	log_info("DSP_AODO:0x%x ",reg_val[0]);
	log_info("DSP_T:0x%x ",reg_val[0]);
	log_info("DSP_S:0x%x\r\n",reg_val[0]);
}

//读取e703状态寄存器
void Read_e703_Status(void)
{
	log_info("\r\nRead_e703_Status:\r\n");
	Read_OneRegdat(STATUS_SYNC,1);
	Read_OneRegdat(HW_DIAG,1);
	Read_OneRegdat(STATUS,1);
}

//读取e703 ID寄存器
void Read_e703_ID(void)
{
	log_info("\r\nRead_e703_ID:\r\n");
	Read_OneRegdat(VERSION,1);
	Read_OneRegdat(SER0,1);
	Read_OneRegdat(SER1,1);
	Read_OneRegdat(USER,1);
}

//读取e703 Configuration Memory寄存器
void Read_e703_CM(void)
{
	log_info("\r\nRead_e703_CM:\r\n");
	Read_OneRegdat(CM_STATUS,1);
	Read_OneRegdat(CM_RDATA,1);
	Read_OneRegdat(CM_WDATA,1);
	Read_OneRegdat(CM_CMD,1);
}

//读取e703 Static Registers寄存器
void Read_e703_SR(void)
{
	log_info("\r\nRead_e703_SR:\r\n");
	Read_OneRegdat(RATIO_DAC01,1);
	Read_OneRegdat(RATIO_DAC23,1);
	Read_OneRegdat(RATIO_DAC45,1);
	Read_OneRegdat(ABS_V_DAC01,1);
	Read_OneRegdat(ABS_V_DAC23,1);
	Read_OneRegdat(ABS_V_DAC45,1);
	Read_OneRegdat(ABS_I_DAC01,1);
	Read_OneRegdat(ABS_I_DAC23,1);
	Read_OneRegdat(ABS_I_DAC45,1);
	Read_OneRegdat(G01,1);
	Read_OneRegdat(G2OFF,1);
	Read_OneRegdat(REG_DSP_T_O,1);
	Read_OneRegdat(REG_DSP_T_F,1);
	Read_OneRegdat(REG_DSP_S_O,1);
	Read_OneRegdat(REG_DSP_S_F,1);
	Read_OneRegdat(REG_DSP_S0,1);
	Read_OneRegdat(REG_DSP_S1,1);
	Read_OneRegdat(REG_DSP_S2,1);
	Read_OneRegdat(REG_DSP_S3,1);
	Read_OneRegdat(REG_DSP_S4,1);
	Read_OneRegdat(REG_DSP_S5,1);
	Read_OneRegdat(REG_DSP_S6,1);
	Read_OneRegdat(REG_DSP_S7,1);
	Read_OneRegdat(REG_DSP_S8,1);
	Read_OneRegdat(REG_DSP_S9,1);
	Read_OneRegdat(REG_DSP_S10,1);
	Read_OneRegdat(REG_DSP_S11,1);
	Read_OneRegdat(REG_DSP_S12,1);
	Read_OneRegdat(REG_DSP_S13,1);
	Read_OneRegdat(REG_DSP_S14,1);
	Read_OneRegdat(REG_DSP_S15,1);
	Read_OneRegdat(REG_DSP_T0,1);
	Read_OneRegdat(REG_DSP_T1,1);
	Read_OneRegdat(REG_DSP_T2,1);
	Read_OneRegdat(REG_DSP_T3,1);
	Read_OneRegdat(REG_DSP_ALARM_LO,1);
	Read_OneRegdat(REG_DSP_ALARM_HI,1);
	Read_OneRegdat(REG_DSP_AODO_O,1);
	Read_OneRegdat(REG_DSP_AODO_F,1);
	Read_OneRegdat(REG_DSP_LIMIT_LO,1);
	Read_OneRegdat(REG_DSP_LIMIT_HI,1);
	Read_OneRegdat(REG_DSP_ERR_MASK,1);
	Read_OneRegdat(REG_DSP_ERR_VAL_HI_LO,1);	
}





