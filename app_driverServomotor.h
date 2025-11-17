/* 
 * File:   app_driverServomotor.h
 * Author: Lenovo
 *
 * Created on March 14, 2025, 10:52 PM
 */

#ifndef APP_DRIVERSERVOMOTOR_H
#define	APP_DRIVERSERVOMOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Servo/Servomotor.h"

extern servomotor_t Servomotor_0;
extern servomotor_t *pServo_0;
extern servomotor_t Servomotor_1;
extern servomotor_t *pServo_1;
extern servomotor_t Servomotor_2;
extern servomotor_t *pServo_2;
    
void Servomotor_Initialize(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APP_DRIVERSERVOMOTOR_H */

