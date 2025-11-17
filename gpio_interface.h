/* 
 * File:   gpio_interface.h
 * Author: Lenovo
 *
 * Created on 15 de julio de 2025, 05:21 PM
 */

#ifndef GPIO_INTERFACE_H
#define	GPIO_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif


#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/adc/adc.h"
   
adc_channel_t AN0 = ADC_CHANNEL_ANA0;
//adc_channel_t AN1 = ADC_CHANNEL_ANA1;
//adc_channel_t AN2 = ADC_CHANNEL_ANA2;
//adc_channel_t AN3 = ADC_CHANNEL_ANA3;

#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_INTERFACE_H */

