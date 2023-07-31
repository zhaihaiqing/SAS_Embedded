/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"


CAN_HandleTypeDef hcan1;

CAN_TxHeaderTypeDef	TxHeader;	//������Ϣ
CAN_RxHeaderTypeDef RxHeader;	//������Ϣ

extern CAN_HandleTypeDef hcan1;



/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 9;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_7TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */

  /* USER CODE END CAN1_Init 2 */

}


/*
0Ϊ���Ե�ƽ��1λ���Ե�ƽ������ʵ�֣�ID�͵ı��ģ��������������ȷ���Ȩ�����ȼ��ߣ�ID�ߵ��ٲ�ʧ���������������ģʽ

CAN��5��֡���ͣ�
	����֡�����ڷ��͵�Ԫ����յ�Ԫ�������ݵ�֡������֡��ʼ���ٲöΡ����ƶΡ����ݶΣ�0-8���ֽڣ���CRC�Ρ�ACK�Ρ�֡������
	Զ��֡�����ڽ��յ�Ԫ�������ͬID�ķ��͵�Ԫ�������ݵ�֡
	����֡�����ڵ���������ʱ��������Ԫ֪ͨ�����֡
	����֡�����ڽ��յ�Ԫ֪ͨ����δ���ý���׼����֡
	���֡�����ڽ�����֡��ң��֡��ǰ���֡���뿪��֡
	
	
	����֡�ṹ��֡��ʼ+�ٲö�+���ƶ�+���ݶ�+CRC��+ACK��+֡����
	
	֡��ʼ����������λ���
	�ٲöΣ����˲���ID��ͬʱҲ��ʾ���ȼ���CANû�нڵ���ID��ָ����ID���б�׼��ʽ��11λ������չ��ʽ��29λ�����֣�RTR���ڱ���Ƿ�ΪԶ��֡
	���ƶΣ�6λ����׼��ʽ��IDE+R0+DLC��IDEΪʶ�����չλ����׼֡��λ�ڿ��ƶΣ����ԣ�����չ֡��λ���ٲöΣ����ԣ���R0Ϊ����λ��DLC�������ݳ���Ϊ��ռ4λ������ʾ��Χ0-8
	���ݶΣ�����0-8���ֽڣ�
	CRC�Σ�CRCУ����
	ACK�Σ�ACKӦ��
	֡������7������������λ���
	
	
	Զ��֡�ṹ��֡��ʼ+�ٲö�+���ƶ�+CRC��+ACK��+֡����
	
	������֡��ȣ�Զ��֡�����ݶΣ���RTRλΪ1�����Ե�ƽ��
	
	
	�����������ֹ���ģʽ���б�ģʽ��������ģʽ��
		�б�ģʽ������32λ�Ĵ�����Ϊ��ʶ���������ʹ�ã�CAN���յ��ı��ı�ʶ������ͱ�ʶ�롢�������е�һ����ͬʱ�Ż�ͨ����������14���˲����������ܹ����Թ���28�ֱ�ʶ����
		������ģʽ����ʶ�����������Ҫһ��ʹ�ã���ʶ���32λ���������32Ϊһһ��Ӧ��������ĳһλ����Ϊ1������Ҫ����λ�ı�ʶ�룬�����ͬ����ͨ������
		
		���ú��Ӳ����ֻ���˳���Ҫ���ĵı��ģ�Ҳ���Բ����ã�����ȫ������
*/




//CAN���������ã�Ӳ������
HAL_StatusTypeDef CAN_Filter_Config(CAN_HandleTypeDef *h_can)
{
	CAN_FilterTypeDef  sFilterConfig;
	
	sFilterConfig.FilterBank	=	0;																				//���ù�����������can����0-13��14����������0�Ź�������ÿ���˲���������32bit�ļĴ����������ù��˹���
	sFilterConfig.FilterMode	=	CAN_FILTERMODE_IDMASK;										//ѡ�����������ģʽ��IDMASK����������������ģʽ���б�ģʽ���������ܲ�����������ģʽ�����˲���ȷ��
	sFilterConfig.FilterScale	=	CAN_FILTERSCALE_32BIT;										//32bitģʽ
	
	sFilterConfig.FilterMaskIdHigh	=	0x0000;																//32λID MASK�����ü�����λ��飬0������顢1������
	sFilterConfig.FilterMaskIdLow		=	0x0000;																//
	
	sFilterConfig.FilterIdHigh	=	0x0000;			//32λID
	sFilterConfig.FilterIdLow		=	0x0000;			//32λID
	
//	sFilterConfig.FilterIdHigh	=	((((uint32_t)0x205<<3)|CAN_ID_EXT|CAN_RTR_DATA)&0xffff0000)>>16;			//32λID
//	sFilterConfig.FilterIdLow		=	(((uint32_t)0x205<<3)|CAN_ID_EXT|CAN_RTR_DATA)&0xffff;								//32λID
	
	
	
	sFilterConfig.FilterFIFOAssignment	=	CAN_FilterFIFO0;									//������0������FIFO0��ѡ��ʹ���ĸ�FIFO
	sFilterConfig.FilterActivation	=	CAN_FILTER_ENABLE;										//Can������ʹ��
	sFilterConfig.SlaveStartFilterBank	= 0;
	
	if(HAL_CAN_ConfigFilter(h_can,&sFilterConfig)	!= HAL_OK)								//��ʼ��������
	{
		log_info("can filter error!\r\n");
		return HAL_ERROR;
	}
	
	if(HAL_CAN_ActivateNotification(h_can,CAN_IT_RX_FIFO0_MSG_PENDING)	!=	HAL_OK)
	{
		log_info("can an error\r\n");
		return HAL_ERROR;
	}
	 
	return HAL_OK;
}





/*
//����Can��Ϣ

TxHeader:���͵�����֡��֡ͷ����
std_id��֡ID����׼֡
aData������֡��������
len�����͵����ݳ���

*/
uint8_t HAL_CAN_SendTxMessage(CAN_TxHeaderTypeDef *TxHeader,uint32_t std_id,uint8_t aData[],uint16_t len)
{
	uint32_t TxMailBox;
	uint8_t FreeTxMailBoxNum;
	
	
	if(len>8)
	{
		log_info("CAN Tx Data len ERROR!,len=%d,len limit is 8\r\n",len);
		len=8;
	}
	
	TxHeader->StdId	=	std_id;				//֡ID
	TxHeader->DLC	= len;						//�����򳤶�
	TxHeader->IDE	=	CAN_ID_STD;			//֡����
	TxHeader->RTR	=	CAN_RTR_DATA;		//����֡��Զ��֡
	TxHeader->TransmitGlobalTime	= DISABLE;
	
	while(0	==	FreeTxMailBoxNum)//�ȴ��������䲻Ϊ��
	{
		FreeTxMailBoxNum	=	HAL_CAN_GetTxMailboxesFreeLevel(&hcan1);
	}
	
	if(HAL_CAN_AddTxMessage(&hcan1,TxHeader,aData,&TxMailBox)	!= HAL_OK)
	{
		log_info("HAL_CAN_AddTxMessage error\r\n");
		return 0;
	}
	
	return 1;
}


uint8_t CAN_txdata[9]={0};
uint8_t CAN_rxdata[9]={0};
uint8_t CAN_rxflag=0;

//CAN���ã����ù�����������CAN
void F4_Can_Init(void)
{
	MX_CAN1_Init();
	
	CAN_txdata[0]=5000>>8;
	CAN_txdata[1]=5000&0x00ff;
	
	CAN_Filter_Config(&hcan1);
	HAL_CAN_Start(&hcan1);
	HAL_CAN_ActivateNotification(&hcan1,CAN_IT_RX_FIFO0_MSG_PENDING);
	
}

//CAN�������ݻص�����
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	if(hcan->Instance == CAN1)
	{
		HAL_CAN_GetRxMessage(&hcan1,CAN_FilterFIFO0,&RxHeader,CAN_rxdata);
		CAN_rxflag=1;
	}	
}




void F4_CAN_Test(void)
{
	
		HAL_CAN_SendTxMessage(&TxHeader,0x1ff,CAN_txdata,8);
		HAL_Delay(100);
		HAL_CAN_SendTxMessage(&TxHeader,0x10,CAN_txdata,8);
		
		if(CAN_rxflag)
		{
			CAN_rxflag=0;
			log_info("CAN1 Rx Data,StdId=0x%x,ExtId=0x%x,IDE=0x%x,RTR=0x%x,DLC=%d,d0=0x%x,d1=0x%x\r\n",RxHeader.StdId,RxHeader.ExtId,RxHeader.IDE,RxHeader.RTR,RxHeader.DLC,CAN_rxdata[0],CAN_rxdata[1]);
		}
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
