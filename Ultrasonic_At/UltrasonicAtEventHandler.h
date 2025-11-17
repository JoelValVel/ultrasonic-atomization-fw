/* 
 * File:   UltrasonicAtEventHandler.h
 * Author: erjo_
 *
 * Created on 1 de septiembre de 2025, 02:16 PM
 */

#ifndef ULTRASONICATEVENTHANDLER_H
#define	ULTRASONICATEVENTHANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "UltrasonicAtTypes.h"
    
void UltrasonicAtomization_EventHandlerInitialize(void);
void UltrasonicAtomization_DecodeRxFrame(uint8_t *pQueue);
SwitchEvent_t switchEven;
ServomotorEvent_t ServomotorEven;
FlowmeterEvent_t flowmeterEven;
TemperatureEvent_t temperatureEven;

uint8_t event_UA = Home_Head_Event;

#ifdef	__cplusplus
}
#endif

#endif	/* ULTRASONICATEVENTHANDLER_H */

