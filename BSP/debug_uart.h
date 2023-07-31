
#ifndef __DEBUG_UART_H
#define __DEBUG_UART_H
#include  "main.h"

//����log_info

#define EN_LOG_UART_RX


#define debug
#ifdef debug
		 #define log_info(...)     printf(__VA_ARGS__)
#else
		#define log_info(...)
#endif


#define LOG_USART			USART1
#define LOG_USART_BPS   	115200


#define LOG_USART_RBUF_SIZE   256		//Ҫ��2 ��������
#if LOG_USART_RBUF_SIZE < 2
#error LOG_USART_RBUF_SIZE is too small.  It must be larger than 1.
#elif ((LOG_USART_RBUF_SIZE & (LOG_USART_RBUF_SIZE-1)) != 0)
#error LOG_USART_RBUF_SIZE must be a power of 2.
#endif

#define LOG_USART_TBUF_SIZE   256		//

typedef struct log_usart_rbuf_st
{
	unsigned int 	in;								//����
	unsigned int 	out;							//���
	unsigned char	rx_flag;						//����һ֡��־
	unsigned int	rx_len;							//֡����
	unsigned char  	rx_buf [LOG_USART_RBUF_SIZE];		//���ջ������ռ�
	unsigned char  	tx_buf [LOG_USART_TBUF_SIZE];		//���ͻ������ռ�	
}LOG_USART_RBUF_ST;



void debug_usart_Init(void);
void debug_usart_Tx(unsigned char *buf,unsigned char len);



#endif

