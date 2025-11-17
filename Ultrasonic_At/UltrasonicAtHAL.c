#include "UltrasonicAtHAL.h"
#include "../mcc_generated_files/uart/uart1.h"
#include<stdio.h>
#include<string.h>
#include<stdint.h>

#define UA_FRAME_BUFFER_SIZE 16U
uint8_t uaRxBuffer[UA_FRAME_BUFFER_SIZE];
uint8_t Counter=0;

void (*pfDecodeUAFrameSerial)(uint8_t *pQueue);

ua_drv_interface_t ultraAtom={
    .Init                      = UltrasonicAtomizationHAL_Initialize,
    .uaByteWrite               = UART1_Write,
    .uaByteRead                = UART1_Read,
    .IsRxDone                  = UART1_IsRxReady,
    .IsTxDone                  = UART1_IsTxReady,
    .appUAUserCallbackRegister = UART1_RxCompleteCallbackRegister
};

void UltrasonicAtomizationHAL_Initialize(void){
    ultraAtom.appUAUserCallbackRegister(UltrasonicAtomization_RxDecodeSerialFrame); 
}

void UltrasonicAtomization_RxDecodeSerialFrame(void){

        uaRxBuffer[Counter] = ultraAtom.uaByteRead();
        if(Counter > 3){
            if(uaRxBuffer[Counter] == 0xFF && uaRxBuffer[Counter-1] == 0xFF && uaRxBuffer[Counter-2] == 0xFF){
                // ejecutar component event
                pfDecodeUAFrameSerial(uaRxBuffer);
                memset(uaRxBuffer,0,sizeof(uaRxBuffer));
                Counter = 0;
            }
            else{
                Counter++;
            }
        }
        else{
            Counter++;
        }
        
}

void UltrasonicAtomization_HALCallbackRegister(void (*Callback)(uint8_t *pQueue)){
    if(NULL != Callback){
        pfDecodeUAFrameSerial = Callback;
    }
}
