#include "main.h"

//ALIGN(RT_ALIGN_SIZE)



//指示灯线程
static struct rt_thread led_thread;				//按键扫描线程控制块
static char led_thread_stack[512];				//线程堆栈
#define LED_THREAD_PRIORITY         16			//线程优先级，按键扫描为最高优先级
#define LED_THREAD_TIMESLICE        100			//线程的时间片大小
void led_thread_entry(void *par);



//static struct rt_thread log_info_thread;	//线程控制块
//static char log_info_thread_stack[512];		//线程堆栈
//#define LOG_THREAD_PRIORITY         30		//线程优先级
//#define LOG_THREAD_TIMESLICE        5		//线程的时间片大小


//static struct rt_thread led_thread;	//线程控制块
//static char led_thread_stack[256];	//线程堆栈
//#define LED_THREAD_PRIORITY         31	//线程优先级
//#define LED_THREAD_TIMESLICE        5	//线程的时间片大小


//struct rt_messagequeue mq_log_info;
//rt_uint8_t mq_log_info_pool[2048];				//消息队列内存池


//void log_info_thread_entry(void *par)
//{
//	char log_buf[32]={0};
//	uint8_t i=0;
//	int a=3;
//	float b=3.1415926;
//	rt_mq_init(&mq_log_info,					//初始化串口打印消息队列，单个消息最长32字节，可缓冲32条消息
//               "mq_log_info",
//               &mq_log_info_pool[0],            /* 内存池指向 msg_pool */
//               sizeof(log_buf),                /* 每个消息的大小是 64 字节 */
//               sizeof(mq_log_info_pool),        /* 内存池的大小是 msg_pool 的大小 */
//               RT_IPC_FLAG_FIFO);       		/* 如果有多个线程等待，按照先来先得到的方法分配消息 */
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
//	rt_thread_init(&tmp_thread,					//线程控制块
//                   "tmp_thread",				//线程控制块名字
//                   tmp_thread_entry,			//线程入口函数
//                   RT_NULL,						//线程入口函数的参数
//                   &tmp_thread_stack[0],		//线程栈起始地址
//                   sizeof(tmp_thread_stack),	//线程栈大小
//                   TMP_THREAD_PRIORITY, 		//线程优先级
//				   TMP_THREAD_TIMESLICE);		//线程时间片大小
//    rt_thread_startup(&tmp_thread); 
//				   
//	rt_thread_init(&log_info_thread,				//线程控制块
//                   "log_info_thread",				//线程控制块名字
//                   log_info_thread_entry,			//线程入口函数
//                   RT_NULL,							//线程入口函数的参数
//                   &log_info_thread_stack[0],		//线程栈起始地址
//                   sizeof(log_info_thread_stack),	//线程栈大小
//                   LOG_THREAD_PRIORITY, 			//线程优先级
//				   LOG_THREAD_TIMESLICE);			//线程时间片大小
//    rt_thread_startup(&log_info_thread);
//				   
	rt_thread_init(&led_thread,					//线程控制块
                   "led_thread",				//线程控制块名字
                   led_thread_entry,			//线程入口函数
                   RT_NULL,						//线程入口函数的参数
                   &led_thread_stack[0],		//线程栈起始地址
                   sizeof(led_thread_stack),	//线程栈大小
                   LED_THREAD_PRIORITY, 		//线程优先级
				   LED_THREAD_TIMESLICE);		//线程时间片大小
									 
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


