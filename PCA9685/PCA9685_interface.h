/* 
 * File:   PCA9685_interface.h
 * Author: erjo_
 *
 * Created on 21 de agosto de 2025, 11:22 AM
 */

#ifndef PCA9685_INTERFACE_H
#define	PCA9685_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    
typedef struct{
    void (*SetFrecuency)(float freq);
    void (*SetDutyCycle)(uint8_t num, uint16_t on, uint16_t off);
}PCA9685_interface_t;


#ifdef	__cplusplus
}
#endif

#endif	/* PCA9685_INTERFACE_H */

