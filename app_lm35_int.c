#include "app_lm35_int.h"
#include "mcc_generated_files/system/system.h"
#include "gpio_interface.h"
#include "TEMP_SENSOR/TempSensor.h"
#include <string.h>

/* Codigo para POO de lm35 
 * Prototype Functions  */

/* Variables Globales */
tempSensor_t TempSensorLM35_0;
tempSensor_t *pTempSensorLM35_0;
tempSensor_t TempSensorLM35_1;
tempSensor_t *pTempSensorLM35_1;
tempSensor_t TempSensorLM35_2;
tempSensor_t *pTempSensorLM35_2;
tempSensor_t TempSensorLM35_3;
tempSensor_t *pTempSensorLM35_3;

uint16_t TIMER_100MS;

void temperatureSensor_Initialize(void){    
    pTempSensorLM35_0 = newTempSensor(&TempSensorLM35_0);
    pTempSensorLM35_1 = newTempSensor(&TempSensorLM35_1);
    pTempSensorLM35_2 = newTempSensor(&TempSensorLM35_2);
    pTempSensorLM35_3 = newTempSensor(&TempSensorLM35_3);
    pTempSensorLM35_0->sensor.Init(pTempSensorLM35_0, TEMPSENSOR_ID_LM35_0, "SenLM35_0");
//    pTempSensorLM35_1->sensor.Init(pTempSensorLM35_1, TEMPSENSOR_ID_LM35_1, "SenLM35_1");
//    pTempSensorLM35_2->sensor.Init(pTempSensorLM35_2, TEMPSENSOR_ID_LM35_2, "SenLM35_2");
//    pTempSensorLM35_2->sensor.Init(pTempSensorLM35_3, TEMPSENSOR_ID_LM35_3, "SenLM35_3");
    pTempSensorLM35_0->SetanalogPin( pTempSensorLM35_0, &AN0);
//    pTempSensorLM35_1->SetanalogPin( pTempSensorLM35_1, &AN1);
//    pTempSensorLM35_2->SetanalogPin( pTempSensorLM35_2, &AN2);
//    pTempSensorLM35_3->SetanalogPin( pTempSensorLM35_3, &AN3);    
//    pTempSensorLM35_0->sensor.DisplayRegister(pTempSensorLM35_0);
//    pTempSensorLM35_1->sensor.DisplayRegister(pTempSensorLM35_1);
//    pTempSensorLM35_2->sensor.DisplayRegister(pTempSensorLM35_2);
//    pTempSensorLM35_3->sensor.DisplayRegister(pTempSensorLM35_3);
    TIMER_100MS = TMR0_PeriodGet();
    
}

void temperatureSensor_Acquire(void){
//    uint16_t timererror = 0;
//    uint16_t reloadTimer = 0;
    LATCbits.LATC6 = !LATCbits.LATC6;
    TMR0_TMRInterruptDisable();
//    pTempSensorLM35_0->sensor.Read(pTempSensorLM35_0);
    pTempSensorLM35_0->sensor.DisplayValue(pTempSensorLM35_0);
//    pTempSensorLM35_1->sensor.DisplayValue(pTempSensorLM35_1);
//    pTempSensorLM35_2->sensor.DisplayValue(pTempSensorLM35_2);
//    pTempSensorLM35_3->sensor.DisplayValue(pTempSensorLM35_3);
//    timererror = tmr0.CounterGet();
//    reloadTimer = ( timererror  -  TIMER_100MS) + TIMER_100MS;
//    tmr0.PeriodSet( reloadTimer );
//    tmr0.Reload();
    TMR0_TMRInterruptEnable();
}

