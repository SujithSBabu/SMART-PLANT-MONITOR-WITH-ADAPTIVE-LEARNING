/*
 * Sensor_Data_Classifier.h
 *
 *  Created on: Jul 23, 2025
 *      Author: Sujith S Babu
 */

#ifndef APPLICATION_INC_SENSOR_DATA_CLASSIFIER_H_
#define APPLICATION_INC_SENSOR_DATA_CLASSIFIER_H_

/* Structure definition for storing simulated sensor data based on plant id */
typedef struct
{
	char plant_name[20];
	uint8_t moisture_data;
	uint8_t temp_data;
	uint16_t light_data;

}Sensor_data_Struct;


/* Function prototypes */
uint8_t simulated_moisture_data(uint8_t pin);
uint8_t simulated_temperature_data(uint8_t pin);
uint16_t simulated_light_data(uint8_t pin);

void sensor_data_plant(uint8_t plant_id,Sensor_data_Struct* sensor_data);
int8_t state_classifier_8_bit(const uint8_t* ,uint8_t);
int8_t state_classifier_16_bit(const uint16_t* ,uint16_t);

#endif /* APPLICATION_INC_SENSOR_DATA_CLASSIFIER_H_ */
