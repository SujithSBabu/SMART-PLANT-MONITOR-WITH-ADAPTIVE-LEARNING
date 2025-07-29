/*
 * Plant_Sensor_Data_Simulate.c
 *
 *  Created on: Jul 23, 2025
 *      Author: Sujith S Babu
 */
#include <stdint.h>
#include <stdlib.h>
#include "Sensor_Data_Classifier.h"

/*API for fetching the simulated sensor data */
void sensor_data_plant(uint8_t plant_id, Sensor_data_Struct* sensor_data)
{

	sensor_data->moisture_data = simulated_moisture_data(plant_id);
	sensor_data->temp_data = simulated_temperature_data(plant_id);
	sensor_data->light_data = simulated_light_data(plant_id);


}

/*APIs for generating simulated sensor data */
uint8_t simulated_moisture_data(uint8_t pin)
{
	switch(pin)
	{
		case (0):return rand() % 60 + 20; // from 20 to 79
		case (1):return rand() % 60 + 20;
		default: return 0;
	}

}

uint8_t simulated_temperature_data(uint8_t pin)
{
	switch(pin)
		{
			case (0):return rand() % 30 + 15; // from 15 to 44
			case (1):return rand() % 30 + 15;
			default: return 0;
		}

}

uint16_t simulated_light_data(uint8_t pin)
{
	switch(pin)
	{
		case (0):return rand() % 900 + 100; // from 100 to 999
		case (1):return rand() % 900 + 100;
		default: return 0;
	}

}
