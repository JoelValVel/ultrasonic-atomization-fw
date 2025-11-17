/* 
 * File:   LM35_TI.h
 * Author: Lenovo
 *
 * Created on 10 de julio de 2025, 12:02 AM
 */

#ifndef LM35_TI_H
#define	LM35_TI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "lm35_interface.h"
    
void            LM35_Initialize(adc_channel_t *analogPin);
void            LM35_SetAnalogPin(adc_channel_t *analogPin );
adc_channel_t*  LM35_GetAnalogPin(void);
float           LM35_ReadTemperature(void);
float           LM35_ScaleTemperature(unit_temp_t scale);


#ifdef	__cplusplus
}
#endif

#endif	/* LM35_TI_H */

