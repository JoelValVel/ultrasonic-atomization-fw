/* 
 * File:   UltrasonicAtTypes.h
 * Author: erjo_
 *
 * Created on 1 de septiembre de 2025, 02:22 PM
 */

#ifndef ULTRASONICATTYPES_H
#define	ULTRASONICATTYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>  

typedef enum{
    Home_Head_Event         = 0,
    Flowmeter_Head_Event    = 1,
    Servomotor_Head_Event   = 2,
    Switch_Head_Event       = 3,
    Temperature_Head_Event  = 4
}ua_event_t;
    
typedef struct{
    uint8_t     u8component;
    uint8_t     u8componentID;
    uint16_t    u32value;
}FlowmeterEvent_t;

typedef struct{
    uint8_t     u8component;
    uint8_t     u8componentID;
    bool        bevent;
}SwitchEvent_t;

typedef struct{
    uint8_t     u8component;
    uint8_t     u8componentID;
    uint8_t    u32value;
}ServomotorEvent_t;

typedef struct{
    uint8_t     u8component;
    bool        bevent;
}TemperatureEvent_t;
#ifdef	__cplusplus
}
#endif

#endif	/* ULTRASONICATTYPES_H */

