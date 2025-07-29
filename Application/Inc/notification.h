/*
 * notification.h
 *
 *  Created on: Jul 29, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_NOTIFICATION_H_
#define INC_NOTIFICATION_H_
#include <stdint.h>

/* Macros*/
#define NOTIFY_THRESHOLD 20

/* Structure definition to store number of occurences of the plant profile data in a specific time window */
typedef struct
{
	uint8_t plnat_id;
	uint8_t plant_moist_range_count;
	uint8_t plant_temp_range_count;
	uint8_t plant_light_range_count;


}Occurence_count_Struct;

/* Function prototype */
void trigger_notification(volatile Occurence_count_Struct*);

#endif /* INC_NOTIFICATION_H_ */
