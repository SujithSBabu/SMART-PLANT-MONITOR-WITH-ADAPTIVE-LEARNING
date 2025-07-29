/*
 * time_stamped_state_data.h
 *
 *  Created on: Jul 28, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_TIME_STAMPED_STATE_DATA_H_
#define INC_TIME_STAMPED_STATE_DATA_H_
#include <stdint.h>
#include "notification.h"

/* MACROS - for defining the time window as of now time window is 240.ie,4 minutes.
 * so pattern matching will be done on last 4 minutes of the 600 seconds,ie,10 minutes.
 */

#define MAX_RECORDS  600 //max number of record stored-also equal to 660 sec,which is 10 mins.
#define TIME_WINDOW  240 //for identifying the pattern from the last 4 minutes of the total 10 minutes.
#define PLANTS 2

/* Structure definition for storing time stamped data */
typedef struct
{
	uint8_t time_stamped_plant_id;
	uint8_t time_stamped_hour;
	uint8_t time_stamped_min;
	uint8_t time_stamped_sec;
	uint32_t total_time_in_sec;

	char time_stamped_moist_state[25];
	char time_stamped_temp_state[25];
	char time_stamped_light_state[25];

}Time_stamped_data_Struct;

extern Time_stamped_data_Struct time_stamped_db[];

/* Function prototype */
void print_time_stamped_data(Time_stamped_data_Struct* time_stamped_db,volatile Occurence_count_Struct* plant_state_pattern_count);

#endif /* INC_TIME_STAMPED_STATE_DATA_H_ */


