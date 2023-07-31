
#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

#define LED1   0x01
#define LED2   0x02
#define LED3   0x04
#define LED4   0x08

#define POWER_OUT_ON()		GPIO_SetBits(GPIOE,GPIO_Pin_0)
#define POWER_OUT_OFF()		GPIO_ResetBits(GPIOE,GPIO_Pin_0)

void GPIO_Configuration(void);
void LED_ON(unsigned char bits);
void LED_OFF(unsigned char bits);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
