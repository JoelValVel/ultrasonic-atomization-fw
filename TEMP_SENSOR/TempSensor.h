/* 
 * File:   Temp_Sensor.h
 * Author: Lenovo
 *
 * Created on 20 de julio de 2025, 02:25 PM
 */

#ifndef TEMP_SENSOR_H
#define	TEMP_SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Sensor.h"
#include "../LM35_TI/LM35_TI.h"
#include "../mcc_generated_files/uart/uart1.h"

#define TEMPSENSOR_ID_LM35_0  0U
#define TEMPSENSOR_ID_LM35_1  1U
#define TEMPSENSOR_ID_LM35_2  2U
#define TEMPSENSOR_ID_LM35_3  3U
    
typedef struct{
    adc_channel_t           analogPin;
    sensor_t                sensor;
    lm35_drv_interface_t    lm35;
    void                    (*SetanalogPin)(void *pSensor, adc_channel_t *analogPin);
    adc_channel_t*          (*GetanalogPin)(void *pSensor);
}tempSensor_t;

tempSensor_t* newTempSensor(tempSensor_t *pSensor);

#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_SENSOR_H */

