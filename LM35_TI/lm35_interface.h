/* 
 * File:   lm35_interface.h
 * Author: Lenovo
 *
 * Created on 10 de julio de 2025, 12:59 AM
 */

#ifndef LM35_INTERFACE_H
#define	LM35_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include "../mcc_generated_files/adc/adc.h"
#include "../mcc_generated_files/adc/adc_interface.h"

typedef union{
    adc_interface_t adc;
}drv_interface_t;
    
typedef enum{
    Celsius,
    Kelvin,
    Farenheit
}unit_temp_t;

typedef struct{
    void            (*Init)(adc_channel_t *analogPin);
    void            (*SetAnalogPin)(adc_channel_t *analogPin);
    adc_channel_t*  (*GetAnalogPin)(void);
    float           (*ReadTemp)(void);    
    float           (*ScaleTemp)(unit_temp_t scale);
}lm35_drv_interface_t;

#ifdef	__cplusplus
}
#endif

#endif	/* LM35_INTERFACE_H */

