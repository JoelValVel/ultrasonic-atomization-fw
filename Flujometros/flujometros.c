#include "flujometros.h"
flujometro_t *newFlujometro(flujometro_t* pFlujometro){
    pFlujometro->Init                    = &FlujometroInit;
    pFlujometro->SetFlujo                = &SetFlujoFlujometro;
    pFlujometro->GetFlujo                = &GetFlujoFlujometro;
    pFlujometro->SetFlujoMax             = &SetFlujoMaxFlujometro;
    pFlujometro->GetFlujoMax             = &GetFlujoMaxFlujometro;
    return pFlujometro;
}

void FlujometroInit(void *pFlujom,  uint8_t Pin, uint16_t FlujoMax){
    flujometro_t *pFlujometro = (flujometro_t*) pFlujom;
    pFlujometro->FlujoMax = FlujoMax;
    pFlujometro->Pin      = Pin;
}

void SetFlujoMaxFlujometro(void *pFlujom, uint16_t flujomax){
    flujometro_t *pFlujometro = (flujometro_t*) pFlujom;
    pFlujometro->FlujoMax = flujomax;
}
uint16_t GetFlujoMaxFlujometro(void *pFlujom){
    flujometro_t *pFlujometro = (flujometro_t*) pFlujom;
    return pFlujometro->FlujoMax;
}

void SetFlujoFlujometro(void *pFlujom, uint16_t Flujo){
    uint16_t low_time;
    float flujoMax;
    flujometro_t *pFlujometro = (flujometro_t*) pFlujom;
    pFlujometro->Flujo = Flujo;
    //flujoMax = (float) pFlujometro->GetFlujoMax(pFlujometro);
    flujoMax = (float) (pFlujometro->FlujoMax);
    low_time = (uint16_t)(((Flujo/flujoMax)*PCA9685_RESOLUTION)-1);
    PCA9685.SetDutyCycle(pFlujometro->Pin,0,low_time);
//    SetDutyCyleFlujometro(pFlujom,dutycycle);
}

uint16_t GetFlujoFlujometro(void *pFlujom){
     flujometro_t *pFlujometro = (flujometro_t*) pFlujom;
     return pFlujometro->Flujo;
 }