/*
 * uart.h
 *
 *  Created on: Jul 23, 2025
 *      Author: Sujith S Babu
 */

#ifndef DRIVER_INC_UART_H_
#define DRIVER_INC_UART_H_

#include "stm32f407_xx_MemMap.h"

/* GPIO configuration -user input */
typedef struct
{
  uint8_t gpio_port;
  uint8_t pin_number;
  uint8_t pin_mode;
  uint8_t pin_otype;
  uint8_t pin_ospeed;
  uint8_t pin_pupd;

}GPIO_User_Cfg_Struct;

/* GPIO Handle structure */
typedef struct
{
	GPIO_RegDef_Struct* pGpio;
	GPIO_User_Cfg_Struct gpio_user_cfg;

}GPIO_Handle_Struct;

/*Function prototypes */
void gpio_init(GPIO_Handle_Struct* pGpiox);
void usart_init(USART_RegDef_Struct*);
void usart_transmit(USART_RegDef_Struct* pUSART,uint8_t ch);
#endif /* DRIVER_INC_UART_H_ */
