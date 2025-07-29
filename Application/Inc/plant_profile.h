/*
 * plant_profile.h
 *
 *  Created on: Jul 26, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_PLANT_PROFILE_H_
#define INC_PLANT_PROFILE_H_
#include <stdint.h>

/* Structure for storing the plant name and its threshold values */
typedef struct
{
	char plant_name[20];
	uint8_t moisture_thresholds[5];
	uint8_t temp_thresholds[5];
	uint16_t light_intensity_thresholds[5];
}Plant_profile_Struct;

extern Plant_profile_Struct plant_profile_db[];
extern volatile uint8_t max_size;

#endif /* INC_PLANT_PROFILE_H_ */
