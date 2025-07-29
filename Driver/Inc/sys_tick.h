/*
 * sys_tick.h
 *
 *  Created on: Jul 28, 2025
 *      Author: Sujit S Babu
 */

#ifndef INC_SYS_TICK_H_
#define INC_SYS_TICK_H_
#include <stdint.h>
#include "stm32f407_xx_MemMap.h"

extern __vo uint32_t systick_timer;

/*Structure definition for storing the time generated based on the systick counter */
typedef struct
{
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
}Current_time_Struct;

/*Function prototypes */
void SysTick_Init(uint32_t ticks);
void delay_ms(uint32_t ms);
void log_current_time(Current_time_Struct*,uint32_t);

#endif /* INC_SYS_TICK_H_ */
