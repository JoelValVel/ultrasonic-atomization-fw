#include <builtins.h>
#include "LM35_TI.h"

#define SCALE_FACTOR_LM35   100U        //LM35-->1°C/0.01V = 100 °C/V
#define ADC_RES10bits       1024.0f
#define V_REF               5
#define SCALE_CEL_2_KEL     273.15f
#define SCALE_CEL_2_FAR     9/5.0f
#define FACTOR_CORR_FAR     32

/* Variables*/
adc_channel_t *analogPinLM35;

void LM35_Initialize(adc_channel_t *analogPin){
    LM35_SetAnalogPin(analogPin);    
}

void LM35_SetAnalogPin(adc_channel_t *analogPin ){
    analogPinLM35 = analogPin;
}

adc_channel_t* LM35_GetAnalogPin(void){
    return analogPinLM35;
}

float LM35_ReadTemperature(void){
    uint16_t readADC = (uint16_t)ADC_ChannelSelectAndConvert(*analogPinLM35);
    float temperature = readADC * (V_REF/ADC_RES10bits) * SCALE_FACTOR_LM35;
    return temperature;
}

float LM35_ScaleTemperature(unit_temp_t scale){
    float temperatureVal = LM35_ReadTemperature();
    float tempConv;
    switch(scale){
        case Celsius:
            tempConv = temperatureVal;
            break;
        case Kelvin:
            tempConv = SCALE_CEL_2_KEL + temperatureVal;
            break;
        case Farenheit:
            tempConv = (SCALE_CEL_2_FAR * temperatureVal ) + FACTOR_CORR_FAR;
            break;
    }
    return tempConv;
}
