/* 
 * File:   app_lm35_int.h
 * Author: Lenovo
 *
 * Created on 18 de julio de 2025, 01:22 AM
 */

#ifndef APP_LM35_INT_H
#define	APP_LM35_INT_H

#ifdef	__cplusplus
extern "C" {
#endif

void temperatureSensor_Initialize(void);
void temperatureSensor_Acquire(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APP_LM35_INT_H */

