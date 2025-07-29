/*
 * notification.c
 *
 *  Created on: Jul 29, 2025
 *      Author: Sujith S Babu
 */
#include <stdio.h>
#include "notification.h"
#include "time_stamped_state_data.h"

/*API for triggering notification based on the occurrence threshold of the plant profile*/
void trigger_notification(volatile Occurence_count_Struct* state_occurence_count)
{
   /* Looping over the number of total indoor plants available */
   for(uint8_t plant_idd = 0; plant_idd < PLANTS ; plant_idd++)
   {
	   if(state_occurence_count[plant_idd].plant_moist_range_count >= NOTIFY_THRESHOLD)
	   {
		   printf(">>ALERT: Moisture is LOW : Plant%d needs attention!\n",plant_idd);
	   }
	   if(state_occurence_count[plant_idd].plant_temp_range_count >= NOTIFY_THRESHOLD)
	   {
	   		printf(">>ALERT: Temperature is HIGH : Plant%d needs attention!\n",plant_idd);
	   }
	   if(state_occurence_count[plant_idd].plant_light_range_count >= NOTIFY_THRESHOLD)
	   {
	   		printf(">>ALERT: Light Intensity is LOW : Plant%d needs attention!\n",plant_idd);
	   }
   }

}
