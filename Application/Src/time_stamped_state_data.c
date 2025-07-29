/*
 * time_stamped_state_data.c
 *
 *  Created on: Jul 28, 2025
 *      Author: Sujith S Babu
 */

#include <stdio.h>
#include <string.h>
#include "time_stamped_state_data.h"


Time_stamped_data_Struct time_stamped_db[MAX_RECORDS];

/* API for adaptive pattern matching or to find the current plant profile based on the history of records */
void print_time_stamped_data(Time_stamped_data_Struct* pointerdb,volatile Occurence_count_Struct* pPlant_state_pattern_count)
{

	uint8_t moist_occurence_counter0 = 0;
	uint8_t temp_occurence_counter0 = 0;
	uint8_t light_occurence_counter0 = 0;

	uint8_t moist_occurence_counter1 = 0;
	uint8_t temp_occurence_counter1 = 0;
	uint8_t light_occurence_counter1 = 0;

	uint16_t current_time           = pointerdb[MAX_RECORDS-1].total_time_in_sec;

	for(uint16_t i= 0; i < MAX_RECORDS; i++)
   {
//	   printf("Currenent_data:%02ld:%d:%02d:%02d:%02d:%s:%s:%s\n",time_stamped_db[i].total_time_in_sec,time_stamped_db[i].time_stamped_plant_id,time_stamped_db[i].time_stamped_hour,time_stamped_db[i].time_stamped_min,
//			   time_stamped_db[i].time_stamped_sec,time_stamped_db[i].time_stamped_moist_state,time_stamped_db[i].time_stamped_temp_state,
//			   time_stamped_db[i].time_stamped_light_state);

	   /* Condition to check the latest records in the specified time window and it will ignore the older records
	    * which will enable adaptive pattern recognition based on the latest records.
	    */
	   if((current_time - time_stamped_db[i].total_time_in_sec) <= TIME_WINDOW)
       {
          if(time_stamped_db[i].time_stamped_plant_id == 0)
          {
        	  if((strcmp(time_stamped_db[i].time_stamped_moist_state, "LOW")==0))
        	  {
        		  moist_occurence_counter0++;
        	  }
        	  if((strcmp(time_stamped_db[i].time_stamped_temp_state, "HIGH")== 0) ||
        	    (strcmp(time_stamped_db[i].time_stamped_temp_state, "VERY HIGH")==0))
        	  {
        		  temp_occurence_counter0++;
        	  }
        	  if((strcmp(time_stamped_db[i].time_stamped_light_state,"LOW")==0))
        	  {
        		  light_occurence_counter0++;
        	  }
          }

          else if(time_stamped_db[i].time_stamped_plant_id == 1)
          {
        	 if((strcmp(time_stamped_db[i].time_stamped_moist_state, "LOW")==0))
			  {
				  moist_occurence_counter1++;
			  }
			  if((strcmp(time_stamped_db[i].time_stamped_temp_state, "HIGH")== 0) ||
				(strcmp(time_stamped_db[i].time_stamped_temp_state, "VERY_HIGH")==0))
			  {
				  temp_occurence_counter1++;
			  }
			  if((strcmp(time_stamped_db[i].time_stamped_light_state,"LOW")==0))
			  {
				  light_occurence_counter1++;
			  }
    	  }
       }

   }

	/* storing the data to a array of structure */
	pPlant_state_pattern_count[0].plant_moist_range_count = moist_occurence_counter0;
	pPlant_state_pattern_count[0].plant_temp_range_count  = temp_occurence_counter0;
	pPlant_state_pattern_count[0].plant_light_range_count = light_occurence_counter0;

	pPlant_state_pattern_count[1].plant_moist_range_count = moist_occurence_counter1;
	pPlant_state_pattern_count[1].plant_temp_range_count  = temp_occurence_counter1;
	pPlant_state_pattern_count[1].plant_light_range_count = light_occurence_counter1;

}
