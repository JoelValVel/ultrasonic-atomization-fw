/* 
 * File:   tmr0_interface.h
 * Author: Lenovo
 *
 * Created on 24 de julio de 2025, 11:35 AM
 */

#ifndef TMR0_INTERFACE_H
#define	TMR0_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    
typedef struct{
    void        (*Initialze)(void);
    void        (*Deinitilize)(void);
    void        (*Start)(void);
    void        (*Stop)(void);
    uint16_t    (*CounterGet)(void);
    void        (*CounterSet)(uint16_t counterValue);
    void        (*Reload)(void);
    void        (*PeriodSet)(uint16_t periodCount);
    uint16_t    (*PeriodGet)(void);
    uint16_t    (*MaxCountGet)(void);
    void        (*InterruptEnable)(void);
    void        (*InterruptDisable)(void);
    void        (*ISR)(void);
    void        (*OverflowCallBackRegister)(void (* CallbackHandler)(void));
}tmr0_drv_interface_t;


#ifdef	__cplusplus
}
#endif

#endif	/* TMR0_INTERFACE_H */

