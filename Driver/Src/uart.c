/*
 * uart.c
 *
 *  Created on: Jul 23, 2025
 *      Author: Sujith S Babu
 */

#include "stm32f407_xx_MemMap.h"

/* ToDo: Can be utilized if need to use printf using UART protocol */
void gpio_init(GPIO_Handle_Struct* pGpiox)
{
    /* Enabling GPIOA peripheral */
	GPIOA_CLK_EN();

	/* MODER configuration */
	pGpiox->pGpio->MODER &= ~(3 << ((pGpiox->gpio_user_cfg.pin_number)*2));
	pGpiox->pGpio->MODER |= (GPIO_ALT_FUNC_MODE << ((pGpiox->gpio_user_cfg.pin_number)*2));

	/* OTYPE Configuration */
	pGpiox->pGpio->OTYPER &= ~(1 << (pGpiox->gpio_user_cfg.pin_number));
	pGpiox->pGpio->OTYPER |=  (0 << (pGpiox->gpio_user_cfg.pin_number));

	/* OSPEED COnfiguration */
	pGpiox->pGpio->OSPEEDR &= ~(3 << ((pGpiox->gpio_user_cfg.pin_number)*2));
	pGpiox->pGpio->OSPEEDR |= (GPIO_HIGH_SPEED << ((pGpiox->gpio_user_cfg.pin_number)*2));

	pGpiox->pGpio->PUPDR   &= ~(3 << ((pGpiox->gpio_user_cfg.pin_number)*2));
	pGpiox->pGpio->PUPDR   |=  (GPIO_PIN_PU << ((pGpiox->gpio_user_cfg.pin_number)*2));

	/* AFR configuration */
	pGpiox->pGpio->AFR[0]  &= ~(15 << ((pGpiox->gpio_user_cfg.pin_number)*4));
	pGpiox->pGpio->AFR[0]  |= (7 << ((pGpiox->gpio_user_cfg.pin_number)*4));
}

void usart_init(USART_RegDef_Struct* usart2)
{
	USART2_CLK_EN();

	usart2->USART_BRR = ((0x0111 << 4) | 0x7); //BRR is not modified ,its written clearly and precisely.
	usart2->USART_BRR = 0x23;
	usart2->USART_CR1 = 0;
    usart2->USART_CR2 = 0;
    usart2->USART_CR3 = 0;
    usart2->USART_CR1 |= (1 << 3);
    usart2->USART_CR1 |= (1 << 2);
    usart2->USART_CR1 |= (1 << 13);

}

void usart_transmit(USART_RegDef_Struct* pUsart, uint8_t ch)
{
    while(!((pUsart->USART_SR >> 7) & 1)){} // if TXE is 1 then !1=0 then exit the while loop,if TXE is 0,!0=1 ,condition satisfies and it stays in the loop.
    pUsart->USART_DR = ch;
}
