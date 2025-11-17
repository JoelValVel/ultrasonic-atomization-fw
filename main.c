#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "mcc_generated_files/system/interrupt.h"
#include "mcc_generated_files/system/system.h"
#include "Ultrasonic_At/UltrasonicAtEventHandler.h"
#include "Ultrasonic_At/UltrasonicAtHAL.h"
#include "Ultrasonic_At/UltrasonicAt_App.h"
#include "mcc_generated_files/uart/uart1.h"
#include "app_driverFlujometro.h"
#include "app_driverServomotor.h"
#include "app_lm35_int.h"

#define _XTAL_FREQ 64000000UL
uint8_t ok_msg = 49;
void pumpExecute(ua_event_t event, void *pEvent);

int main(){
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    //UART1_GeneralInterruptEnable;
    UART1_TransmitEnable();
    //UART1_TransmitInterruptEnable;
    //UART1_ReceiveInterruptEnable;
    UART1_ReceiveEnable();
    UART1_Enable();
    UltrasonicAtomization_EventHandlerInitialize();
    UltrasonicAtomization_InterruptHandlerRegister(pumpExecute);
    PCA9685.SetFrecuency(41);
    Flujometro_Initialize();
    Servomotor_Initialize();
    temperatureSensor_Initialize();
    TMR0_OverflowCallbackRegister(temperatureSensor_Acquire);
    TMR0_TMRInterruptDisable();
    TMR0_Start();
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC5 = 0;
    LATCbits.LATC4 = 1;
    LATCbits.LATC5 = 1;
    while(true){ 
        switch(event_UA){
            case Home_Head_Event:
                break;
            case Flowmeter_Head_Event:
                switch(flowmeterEven.u8componentID){
                    case 3:
                        pFlujom_3->SetFlujo(pFlujom_3,flowmeterEven.u32value);
                        event_UA = Home_Head_Event;
                        UART1.Write(ok_msg);
                        break;
                    case 4:
                        pFlujom_4->SetFlujo(pFlujom_4,flowmeterEven.u32value);
                        event_UA = Home_Head_Event;
                        UART1.Write(ok_msg);
                        break;
                    case 2:
                        pFlujom_2->SetFlujo(pFlujom_2,flowmeterEven.u32value);
                        event_UA = Home_Head_Event;
                        UART1.Write(ok_msg);
                        break;
                }
                break;

            case Servomotor_Head_Event:
                switch(ServomotorEven.u8componentID){
                    case 0:
                        pServo_0->SetAngle(pServo_0,ServomotorEven.u32value);
                        event_UA = Home_Head_Event;
                        UART1.Write(ok_msg);
                        break;
                    case 1:
                        pServo_1->SetAngle(pServo_1,ServomotorEven.u32value);
                        event_UA = Home_Head_Event;
                        UART1.Write(ok_msg);
                        break;
                    case 2:
                        pServo_2->SetAngle(pServo_2,ServomotorEven.u32value);
                        event_UA = Home_Head_Event;
                        UART1.Write(ok_msg);
                        break;
                }
                break;

            case Switch_Head_Event:
                switch(switchEven.u8componentID){
                    case 0:
                        LATCbits.LATC4 = ~switchEven.bevent;
                        event_UA = Home_Head_Event;
                        UART1.Write(ok_msg);
                        break;
                    case 1:
                        LATCbits.LATC5 = ~switchEven.bevent;
                        event_UA = Home_Head_Event;
                        UART1.Write(ok_msg);
                        break;      
                        
                }
                break;
            case Temperature_Head_Event:
                if(temperatureEven.bevent){
                    TMR0_TMRInterruptEnable();
                    event_UA = Home_Head_Event;
                    UART1.Write(50);
                }
                else{
                    tmr0.InterruptDisable();
                    event_UA = Home_Head_Event;
                    UART1.Write(49);
                }
                break;

        }    
    }
    return 1;
}

