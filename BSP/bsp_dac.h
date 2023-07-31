
#ifndef __BSP_DAC_H
#define __BSP_DAC_H


#define DAC_DHR8R1_ADDRESS     0x40007410	//DAC1ͨ�� 8λ�Ҷ���
#define DAC_DHR12R1_ADDRESS    0x40007408	//DAC1ͨ�� 12λ�Ҷ���
#define DAC_DHR12L1_ADDRESS    0x4000740C	//DAC1ͨ�� 12λ�����

#define DAC_DHR12R2_ADDRESS    0x40007414	//DAC2ͨ�� 12λ�Ҷ���
#define DAC_DHR12L2_ADDRESS    0x40007418	//DAC2ͨ�� 12λ�����
#define DAC_DHR8R2_ADDRESS     0x4000741C	//DAC2ͨ�� 8λ�Ҷ���


#define SINWAVE			0x01
#define TRIANGLEWAVE	0x02
#define SAWTOOTHWAVE	0x03
#define SQUAREWAVE		0x04
#define NOISEWAVE		0x05


typedef struct
{
  unsigned char wave_type; 	//����:1-5��Ӧ���Ҳ������ǲ�����ݲ�������������
  float freq;     			//Ƶ��:����̫��
  float am;   				//����:0-3.3
  float phase;   			//��λ:0-360��
  float duty_cycle; 		//ռ�ձȣ���������,0-100
  unsigned char polarity;	//ʱ�Ӽ��ԣ���������ݲ����У�0��1��
}WAVE_InitTypeDef;




void Dac1_fixed_Init(void);
void Dac1_Set_fixed_Vol(float vol);



void TIM6_Config(unsigned int arr);
void DAC_Ch1_EscalatorConfig(void);
void DAC_Ch1_NoiseConfig(void);

//void WaveGeneration(unsigned char Wave_type,float f,float am,float ph,float duty,unsigned char direction);
void WaveGeneration(WAVE_InitTypeDef* WAVE_Init);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
