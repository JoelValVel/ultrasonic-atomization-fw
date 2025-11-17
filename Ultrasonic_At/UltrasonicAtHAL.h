/* 
 * File:   UltrasonicAtHAL.h
 * Author: erjo_
 *
 * Created on 1 de septiembre de 2025, 02:17 PM
 */

#ifndef ULTRASONICATHAL_H
#define	ULTRASONICATHAL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include"UltrasonicAtTypes.h"
typedef struct{
    void    (*Init)(void);
    void    (*uaByteWrite)(uint8_t TxData);
    uint8_t (*uaByteRead)(void);
    bool    (*IsTxDone)(void);
    bool    (*IsRxDone)(void);
    void    (*appUAUserCallbackRegister)(void (*Callback)(void));
}ua_drv_interface_t;
    
void UltrasonicAtomizationHAL_Initialize(void);
void UltrasonicAtomization_RxDecodeSerialFrame(void);
void UltrasonicAtomization_HALCallbackRegister(void (*Callback)(uint8_t *pQueue));
void UltrasonicAtomization_InterruptHandlerRegister(void(*InterruptHandler)(ua_event_t evnt, void *pEvent));

#ifdef	__cplusplus
}
#endif

#endif	/* ULTRASONICATHAL_H */

