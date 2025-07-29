/*
 * plant_profile.c
 *
 *  Created on: Jul 27, 2025
 *      Author: Sujith S Babu
 */
#include <stdint.h>
#include "plant_profile.h"

/* array to structure for storing the plant profile thresholds */
Plant_profile_Struct plant_profile_db[] =
{
		{"Indoor_Plant_1",{20,45,55,70,79},{15,20,30,37,44},{100,500,750,850,999}},
		{"Indoor_plant_2",{20,45,55,70,79},{15,20,30,37,44},{100,500,750,850,999}}
};

/*Calculating the element array size inside the array of structure */
volatile uint8_t max_size = sizeof(plant_profile_db[0].moisture_thresholds)/sizeof(plant_profile_db[0].moisture_thresholds[0]);
