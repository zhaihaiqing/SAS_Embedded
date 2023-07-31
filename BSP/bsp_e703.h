
#ifndef __BSP_E703_H
#define __BSP_E703_H


/******************************* Configuration Registers********************************/
//Operation Mode
#define CFG_EN	0x04
//Interfaces
#define CFG_SPI_I2C					0x06
#define CFG_PADS0					0x08
#define CFG_PADS1					0x0a
#define CFG_PADS2					0x0c
#define CFG_PERIOD					0x0e
#define CFG_AODO					0x10
//Sensor Analog Front End and ADC Filters
#define CFG_SBC_INTF				0x12
#define CFG_ADC						0x14
#define CFG_LP0						0x16
#define CFG_LP1						0x18
#define CFG_AFE0					0x1a
#define CFG_AFE1					0x1c
#define CFG_AFE2					0x1e
// Chip Calibration
#define CFG_CAL0					0x00
#define CFG_CAL1					0x02	

/******************************* Command Registers********************************/
//Command
#define CMD							0x22

/******************************* Results Registers********************************/
//Results
#define ADC_TC						0x26
#define ADC_T						0x28
#define ADC_S						0x2a
#define DSP_AODO					0x2c
#define DSP_T						0x2e
#define DSP_S						0x30


/******************************* Status Registers********************************/
#define STATUS_SYNC					0x32
#define HW_DIAG						0x34
#define STATUS						0x36

/******************************* Identification Code (ID) Registers********************************/
//Unique Serial Number
#define VERSION						0x38
#define SER0						0x50
#define SER1						0x52
//User Data
#define USER						0x6a

/******************************* Configuration Memory (CM) Access Registers********************************/
#define CM_STATUS					0x46
#define CM_RDATA					0x48
#define CM_WDATA					0x4a
#define CM_CMD						0x4e

/******************************* Static Registers and DSP Parameters Registers********************************/
//Static Registers
#define RATIO_DAC01					0x54
#define RATIO_DAC23					0x56
#define RATIO_DAC45					0x58
#define ABS_V_DAC01					0x5a
#define ABS_V_DAC23					0x5c
#define ABS_V_DAC45					0x5e
#define ABS_I_DAC01					0x60
#define ABS_I_DAC23					0x62
#define ABS_I_DAC45					0x64
#define G01							0x66
#define G2OFF						0x68
//DSP Parameters
#define REG_DSP_T_O					0x6c
#define REG_DSP_T_F					0x6e
#define REG_DSP_S_O					0x70
#define REG_DSP_S_F					0x72
#define REG_DSP_S0					0x74
#define REG_DSP_S1					0x76
#define REG_DSP_S2					0x78
#define REG_DSP_S3					0x7a
#define REG_DSP_S4					0x7c
#define REG_DSP_S5					0x7e
#define REG_DSP_S6					0x80
#define REG_DSP_S7					0x82
#define REG_DSP_S8					0x84
#define REG_DSP_S9					0x86
#define REG_DSP_S10					0x88
#define REG_DSP_S11					0x8a
#define REG_DSP_S12					0x8c
#define REG_DSP_S13					0x8e
#define REG_DSP_S14					0x90
#define REG_DSP_S15					0x92
#define REG_DSP_T0					0x94
#define REG_DSP_T1					0x96
#define REG_DSP_T2					0x98
#define REG_DSP_T3					0x9a
#define REG_DSP_ALARM_LO			0x9c
#define REG_DSP_ALARM_HI			0x9e
#define REG_DSP_AODO_O				0xa0
#define REG_DSP_AODO_F				0xa2
#define REG_DSP_LIMIT_LO			0xa4
#define REG_DSP_LIMIT_HI			0xa6
#define REG_DSP_ERR_MASK			0xa8
#define REG_DSP_ERR_VAL_HI_LO		0xaa
//General Parameters
#define PARA0						0xe4

























void Read_sendat(void);
uint16_t Read_OneRegdat(uint8_t reg_addr,uint8_t is_log);




void Read_e703_CFG(void);
void Read_e703_Results(void);
void Read_e703_Status(void);
void Read_e703_ID(void);
void Read_e703_CM(void);
void Read_e703_SR(void);






#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
