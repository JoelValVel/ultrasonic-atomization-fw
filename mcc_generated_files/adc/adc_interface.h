/* 
 * File:   adc_interface.h
 * Author: Lenovo
 *
 * Created on July 20, 2025, 9:11 PM
 */

#ifndef ADC_INTERFACE_H
#define	ADC_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "adc_types.h"
    
typedef struct{
    void            (*Initialize)(void);
    void            (*Desinitialize)(void);
    void            (*Enable)(void);
    void            (*Disable)(void);
    void            (*ChannelSelect)(adc_channel_t channel);
    void            (*ConversionStart)(void);
    void            (*ConversionStop)(void);
    bool            (*IsConversion)(void);
    adc_result_t    (*Get)(void);
    adc_result_t    (*ChannelSelectAndConvert)(adc_channel_t channel);
    void            (*SetInterrupt)(void (*InterruptHandler)(void));
}adc_interface_t;

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_INTERFACE_H */

