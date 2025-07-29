/*
 * sensor_data_classifier.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Sujith S Babu
 */
#include <stdint.h>
#include "general_macros.h"
#include "plant_profile.h"

extern volatile uint8_t max_size;

/* API for classifying the state of the 8-bit sensor data using binary search algorithm  */
int8_t state_classifier_8_bit(const uint8_t* thresholds,uint8_t sensor_data)
{

	int8_t low  = 0;
    int8_t high = max_size - 2;


    while(low <= high)
    {
    	uint8_t mid  = (low + high)/2;
    	if(sensor_data >= thresholds[mid] && sensor_data<= (thresholds[mid+1]-1))
    	{
    		return mid;
    	}
    	else if(sensor_data <= thresholds[mid])
    	{
    		high = mid - 1;
    	}
    	else
    	{
    		low  = mid + 1;
    	}

    }
    if(sensor_data >= thresholds[max_size-2] && sensor_data <= thresholds[max_size-1])
    {
    	return max_size-2;
    }
    return -1;
}

/* API for classifying the state of the 16-bit sensor data using binary search algorithm  */
int8_t state_classifier_16_bit(const uint16_t* thresholds,uint16_t sensor_data)
{

	int8_t low  = 0;
    int8_t high = max_size - 2;


    while(low <= high)
    {
    	uint8_t mid  = (low + high)/2;
    	if(sensor_data >= thresholds[mid] && sensor_data<= (thresholds[mid+1]-1))
    	{
    		return mid;
    	}
    	else if(sensor_data <= thresholds[mid])
    	{
    		high = mid - 1;
    	}
    	else
    	{
    		low  = mid + 1;
    	}

    }
    if(sensor_data >= thresholds[max_size-2] && sensor_data <= thresholds[max_size-1])
    {
        return max_size-2;
    }
    return -1;
}
