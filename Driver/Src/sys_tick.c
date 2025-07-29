/*
 * sys_tick.c
 *
 *  Created on: Jul 28, 2025
 *      Author: Sujith S Babu
 */
#include <stdint.h>
#include <stdio.h>
#include "sys_tick.h"
#include "stm32f407_xx_MemMap.h"

__vo uint32_t systick_timer = 0;

/* Enabling systick counter functionlity */
void SysTick_Init(uint32_t ticks)
{
    SYST_RVR = ticks - 1;              // Set reload register
    SYST_CVR = 0;                      // Reset current value register
    SYST_CSR = 0x05;                   // Enable SysTick, use processor clock
}

/* API to produce 1 second delay,which will also increment systick_timer to 1 second-
 *  which is important for generating current time.
 */
void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        SysTick_Init(16000); // assuming 16 MHz clock -> 1ms
        while ((SYST_CSR & (1 << 16)) == 0); // Wait until COUNTFLAG is set
        systick_timer++;
    }
}

/* API for generating current time when it is called-for storing time stamped data */
void log_current_time(Current_time_Struct* cur_time_data,uint32_t systick_timer)
{
    uint32_t total_seconds = systick_timer/1000;

    cur_time_data->hour         = (total_seconds/3600)%24;
    cur_time_data->minute       = (total_seconds/60)%60;
    cur_time_data->second       =  total_seconds%60;

}
