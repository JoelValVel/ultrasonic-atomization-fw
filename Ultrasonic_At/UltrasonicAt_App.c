#include "UltrasonicAt_App.h" 
#include "../app_driverFlujometro.h"
#include "../app_driverServomotor.h"
void pumpExecute(ua_event_t event, void (*pEvent)){
    switch(event){
        case Flowmeter_Head_Event:
            
            FlowmeterEvent_t *pflowmeterEvent = (FlowmeterEvent_t*)pEvent;
            switch(pflowmeterEvent->u8componentID){
                case 3:
                    pFlujom_3->SetFlujo(pFlujom_3,pflowmeterEvent->u32value);
                    break;
                case 4:
                    UART1_Write(41);
                    pFlujom_4->SetFlujo(pFlujom_4,pflowmeterEvent->u32value);
                    break;
                case 2:
                    pFlujom_2->SetFlujo(pFlujom_2,pflowmeterEvent->u32value);
                    break;
            }
            break;
            
        case Servomotor_Head_Event:
            
            ServomotorEvent_t *pservomotorEvent = (ServomotorEvent_t*)pEvent;
            
            switch(pservomotorEvent->u8componentID){
                case 0:
                    pServo_0->SetAngle(pServo_0,pservomotorEvent->u32value);
                    break;
                case 1:
                    pServo_1->SetAngle(pServo_1,pservomotorEvent->u32value);
                    break;
                case 2:
                    pServo_2->SetAngle(pServo_2,pservomotorEvent->u32value);
                    break;
            }
            break;
            
        case Switch_Head_Event:
            
            SwitchEvent_t *pswitchEvent = (SwitchEvent_t*)pEvent;
            
            switch(pswitchEvent->u8componentID){
                case 0:
                    LATCbits.LATC4 = pswitchEvent->bevent;
                    break;
                case 1:
                    LATCbits.LATC5 = pswitchEvent->bevent;
                    break;      
            }
            break;
    
    }
}
