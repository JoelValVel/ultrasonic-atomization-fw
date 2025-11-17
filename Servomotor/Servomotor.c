#include "Servomotor.h"
#include "../mcc_generated_files/uart/uart1.h"

servomotor_t *newServomotor(servomotor_t* pServo){
    pServo->Init                    = &ServomotorInit;
    pServo->SetAngle                = &SetAngleServomotor;
    return pServo;
}
    
void ServomotorInit(void *pServo,  uint8_t Pin, uint16_t Min_Count, uint16_t Max_Count){
    servomotor_t *pServomotor = (servomotor_t*) pServo;
    pServomotor->Pin      = Pin;
    pServomotor->Min_Count = Min_Count;
    pServomotor->Max_Count = Max_Count;
}

void SetAngleServomotor(void *pServo, uint8_t Angle){
    
    servomotor_t *pServomotor = (servomotor_t*) pServo;
    uint16_t Min_Count, Max_Count, low_time;
    float angle_float = (float)Angle;
    Max_Count = pServomotor->Max_Count;
    Min_Count = pServomotor->Min_Count;
    // se calcula el tiempo, en us, que tiene que mantener el alto la señal para 
    // mover el servomotor al angulo deseado, donde el angulo 0 corresponde a MinCount
    // y el angulo 180 a max_count
    low_time = (uint16_t)((((Max_Count-Min_Count)*angle_float)/180.0)+Min_Count);
    low_time=RESOLUTION_FREQ_US_RATIO*low_time;
    PCA9685.SetDutyCycle(pServomotor->Pin,0,low_time);
    
}

