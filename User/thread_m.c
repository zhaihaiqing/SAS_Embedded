#include "main.h"

//ALIGN(RT_ALIGN_SIZE)



//ָʾ���߳�
static struct rt_thread led_thread;				//����ɨ���߳̿��ƿ�
static char led_thread_stack[512];				//�̶߳�ջ
#define LED_THREAD_PRIORITY         16			//�߳����ȼ�������ɨ��Ϊ������ȼ�
#define LED_THREAD_TIMESLICE        100			//�̵߳�ʱ��Ƭ��С
void led_thread_entry(void *par);



//static struct rt_thread log_info_thread;	//�߳̿��ƿ�
//static char log_info_thread_stack[512];		//�̶߳�ջ
//#define LOG_THREAD_PRIORITY         30		//�߳����ȼ�
//#define LOG_THREAD_TIMESLICE        5		//�̵߳�ʱ��Ƭ��С


//static struct rt_thread led_thread;	//�߳̿��ƿ�
//static char led_thread_stack[256];	//�̶߳�ջ
//#define LED_THREAD_PRIORITY         31	//�߳����ȼ�
//#define LED_THREAD_TIMESLICE        5	//�̵߳�ʱ��Ƭ��С


//struct rt_messagequeue mq_log_info;
//rt_uint8_t mq_log_info_pool[2048];				//��Ϣ�����ڴ��


//void log_info_thread_entry(void *par)
//{
//	char log_buf[32]={0};
//	uint8_t i=0;
//	int a=3;
//	float b=3.1415926;
//	rt_mq_init(&mq_log_info,					//��ʼ�����ڴ�ӡ��Ϣ���У�������Ϣ�32�ֽڣ��ɻ���32����Ϣ
//               "mq_log_info",
//               &mq_log_info_pool[0],            /* �ڴ��ָ�� msg_pool */
//               sizeof(log_buf),                /* ÿ����Ϣ�Ĵ�С�� 64 �ֽ� */
//               sizeof(mq_log_info_pool),        /* �ڴ�صĴ�С�� msg_pool �Ĵ�С */
//               RT_IPC_FLAG_FIFO);       		/* ����ж���̵߳ȴ������������ȵõ��ķ���������Ϣ */
//			   
//	a=b*1000;   
//	while(1)
//	{
//		if(rt_mq_recv(&mq_log_info, &log_buf, sizeof(log_buf), RT_WAITING_FOREVER) == RT_EOK)
//		{
//			for(i=0;i<8;i++)rt_kprintf("0x%x ",log_buf[i]);
//			
//			rt_kprintf("a=%d\r\n",a);
//		}
//	}
//}

//void led_thread_entry(void *par)
//{
//	uint8_t buf[2]={0};
//	uint8_t i=0;
//	while(1)
//	{
//		rt_thread_mdelay(200);LED_ON(LED1);
//		rt_thread_mdelay(200);LED_ON(LED2);
//		rt_thread_mdelay(200);LED_ON(LED3);
//		rt_thread_mdelay(200);LED_ON(LED4);
//		rt_thread_mdelay(500);LED_OFF(LED1|LED2|LED3|LED4);
//		
////		rt_mq_send(&mq_log_info, &buf, 2);
////		buf[0]=i++;
////		buf[1]=i++;
//	}
//}

//void tmp_thread_entry(void *par)
//{
//	uint8_t buf[2]={0};
//	uint8_t i=0;
//	
//	SPI2_Configuration();
//	rt_thread_mdelay(300);
//	while(1)
//	{
//		//(void)Temp_Read();
//		rt_thread_mdelay(2000);
//	}
//}

int thread_init(void)
{
//	rt_thread_init(&tmp_thread,					//�߳̿��ƿ�
//                   "tmp_thread",				//�߳̿��ƿ�����
//                   tmp_thread_entry,			//�߳���ں���
//                   RT_NULL,						//�߳���ں����Ĳ���
//                   &tmp_thread_stack[0],		//�߳�ջ��ʼ��ַ
//                   sizeof(tmp_thread_stack),	//�߳�ջ��С
//                   TMP_THREAD_PRIORITY, 		//�߳����ȼ�
//				   TMP_THREAD_TIMESLICE);		//�߳�ʱ��Ƭ��С
//    rt_thread_startup(&tmp_thread); 
//				   
//	rt_thread_init(&log_info_thread,				//�߳̿��ƿ�
//                   "log_info_thread",				//�߳̿��ƿ�����
//                   log_info_thread_entry,			//�߳���ں���
//                   RT_NULL,							//�߳���ں����Ĳ���
//                   &log_info_thread_stack[0],		//�߳�ջ��ʼ��ַ
//                   sizeof(log_info_thread_stack),	//�߳�ջ��С
//                   LOG_THREAD_PRIORITY, 			//�߳����ȼ�
//				   LOG_THREAD_TIMESLICE);			//�߳�ʱ��Ƭ��С
//    rt_thread_startup(&log_info_thread);
//				   
	rt_thread_init(&led_thread,					//�߳̿��ƿ�
                   "led_thread",				//�߳̿��ƿ�����
                   led_thread_entry,			//�߳���ں���
                   RT_NULL,						//�߳���ں����Ĳ���
                   &led_thread_stack[0],		//�߳�ջ��ʼ��ַ
                   sizeof(led_thread_stack),	//�߳�ջ��С
                   LED_THREAD_PRIORITY, 		//�߳����ȼ�
				   LED_THREAD_TIMESLICE);		//�߳�ʱ��Ƭ��С
									 
	rt_thread_startup(&led_thread); 
	
	return 0;
}

void led_thread_entry(void *par)
{
	uint16_t count = 0;
	
	while(1)
	{
		rt_thread_mdelay(100);
		count++;
		if(count==2)		LED_ON(LED1);
		else if(count==4)	LED_ON(LED2);
		else if(count==6)	LED_ON(LED3);
		else if(count==8)	LED_ON(LED4);
		else if(count==13)
		{
			count=0;
			LED_OFF(LED1|LED2|LED3|LED4);
		}
	}
	
}


