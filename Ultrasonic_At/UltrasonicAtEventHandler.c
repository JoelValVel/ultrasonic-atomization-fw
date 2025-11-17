#include "UltrasonicAtEventHandler.h"
#include "UltrasonicAtHAL.h"
#include<stdbool.h>
#include<string.h>
#include<stdio.h>
#include"../mcc_generated_files/uart/uart1.h"
typedef enum{
    Init,
    Finish,
    Error,
}ua_FSM_t;

ua_FSM_t uaEvent = Init;

void(*UltrasonicAtomization_InterruptHandler)(ua_event_t evnt, void *pEvent);


void UltrasonicAtomization_EventHandlerInitialize(void){
    UltrasonicAtomizationHAL_Initialize();
    UltrasonicAtomization_HALCallbackRegister(UltrasonicAtomization_DecodeRxFrame);
}

void UltrasonicAtomization_DecodeRxFrame(uint8_t *pQueueHead){
    
    uint8_t str[20];
    uint16_t millares, centenas, decenas, unidades;
    switch(uaEvent){
        case Init:
            if(*pQueueHead == Flowmeter_Head_Event){
                flowmeterEven.u8component   = *pQueueHead++;
                flowmeterEven.u8componentID = *pQueueHead++;
                millares = ((*pQueueHead++) * 1000);
                centenas = ((*pQueueHead++) * 100 );
                decenas = ((*pQueueHead++)* 10 );
                unidades = ((*pQueueHead++) * 1);
                flowmeterEven.u32value      = millares + centenas + decenas + 
                                                unidades;
                //UltrasonicAtomization_InterruptHandler(Flowmeter_Head_Event,&flowmeterEven);
                event_UA = Flowmeter_Head_Event;
            }
            if(*pQueueHead == Servomotor_Head_Event){

                
                ServomotorEven.u8component   = *pQueueHead++;
                ServomotorEven.u8componentID = *pQueueHead++;
                centenas = ((*pQueueHead++) * 100 );
                decenas = ((*pQueueHead++)* 10 );
                unidades = ((*pQueueHead++) * 1);
                ServomotorEven.u32value      = centenas + decenas + unidades;
                //UltrasonicAtomization_InterruptHandler(Servomotor_Head_Event,&ServomotorEven);
                event_UA = Servomotor_Head_Event;
            }
            
            if(*pQueueHead == Switch_Head_Event){
                
                
                switchEven.u8component   = (*pQueueHead++);
                switchEven.u8componentID = (*pQueueHead++);
                switchEven.bevent      = (*pQueueHead++);
                //UltrasonicAtomization_InterruptHandler(Switch_Head_Event,&switchEven);
                event_UA = Switch_Head_Event;
            }
            if(*pQueueHead == Temperature_Head_Event){
                
                
                temperatureEven.u8component   = (*pQueueHead++);
                temperatureEven.bevent      = (*pQueueHead++);
                //UltrasonicAtomization_InterruptHandler(Switch_Head_Event,&switchEven);
                event_UA = Temperature_Head_Event;
            }
            break;
            
            
        case Finish:
            break;
        case Error:
            break;
    }
}

void UltrasonicAtomization_InterruptHandlerRegister(void(*InterruptHandler)(ua_event_t evnt, void *pEvent)){
    if(NULL!=InterruptHandler){
        UltrasonicAtomization_InterruptHandler = InterruptHandler;
    }
}