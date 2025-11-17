/* 
 * File:   Servomotor.h
 * Author: Lenovo
 *
 * Created on March 14, 2025, 10:05 PM
 */

#ifndef SERVOMOTOR_H
#define	SERVOMOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "../PCA9685/PCA9685.h"
    
#define RESOLUTION_FREQ_US_RATIO 0.20580823 //4095(12 bits)/20000us (50 hz))
#
typedef struct servomotor servomotor_t;

struct servomotor{
    void        (*Init)(void *pServo,  uint8_t Pin, uint16_t Min_Count, uint16_t Max_Count);
    uint8_t     Pin;
    uint16_t     Max_Count;
    uint16_t     Min_Count;
    void        (*SetAngle)(void *pServo, uint8_t Angle);
    uint8_t    (*GetAngle)(void *pServo);
};

servomotor_t *newServomotor(servomotor_t* pServo);
void ServomotorInit(void *pServo,  uint8_t Pin, uint16_t Min_Count, uint16_t Max_Count);
void        SetAngleServomotor(void *pServo, uint8_t Angle);
uint8_t    GetAngleServomotor(void *pServo);




#ifdef	__cplusplus
}
#endif

#endif	/* SERVOMOTOR_H */

