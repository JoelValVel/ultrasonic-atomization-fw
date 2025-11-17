/* 
 * File:   Sensor.h
 * Author: Lenovo
 *
 * Created on 20 de julio de 2025, 02:25 PM
 */

#ifndef SENSOR_H
#define	SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stddef.h>
#include <stdint.h>
#include "../mcc_generated_files/uart/uart1.h"
#include "../mcc_generated_files/uart/uart_drv_interface.h"

typedef union{
    uart_drv_interface_t UART1;
}comInterface_t;
    
typedef struct{
    /* Attributes */
    uint8_t *ID;
    uint8_t *Name;    
//    float   *readVal;
    float   readVal;
    uint8_t *writeVal;
    
    /* Comunication */
    comInterface_t COM;
    
    /* Methods */
    void        (*Init)(void *pvSensor, uint8_t *ID, uint8_t *Name);
    void        (*Write)(void *pvSensor, uint8_t *ID);
    float*      (*ReadFilter)(void *pvSensor);
    float*      (*Read)(void *pvSensor);
    void        (*DisplayRegister)(void *pvSensor);
    void        (*DisplayValue)(void *pvSensor);
    void        (*Calibrate)(void *pvSensor, uint8_t *ID, uint8_t *Name);
    void        (*setID)(void *pvSensor, uint8_t *ID);
    uint8_t*    (*getID)(void *pvSensor);
    void        (*setName)(void *pvSensor, uint8_t *Name);
    uint8_t*    (*getName)(void *pvSensor);
}sensor_t;


#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

