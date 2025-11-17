#include "TempSensor.h"
#include <stdio.h>

/* Constantes Literales */
//#define BUFFER_SIZE_FILTER  16U
//
///* Estructuras y varaibles de estructura */
//typedef struct{
//    float   Buffer[BUFFER_SIZE_FILTER];
//    uint8_t index;
//    float   sum;
//    uint8_t countSum;            
//}tempFilter_t;
//
//tempFilter_t SensorLM35_0;
//tempFilter_t SensorLM35_1;
//tempFilter_t SensorLM35_2;
//tempFilter_t SensorLM35_3;

/* Prototype Function */
static void             tempSensor_Initialize(void *pSensor, uint8_t *ID, uint8_t *Name);
static void             tempSensor_setID(void *pSensor, uint8_t *ID);
static uint8_t*         tempSensor_getID(void *pSensor);
static void             tempSensor_setName(void *pSensor, uint8_t *Name);
static uint8_t*         tempSensor_getName(void *pSensor);
static void             tempSensor_SetanalogPin(void *pSensor, adc_channel_t *analogPin);
static adc_channel_t*   tempSensor_GetanalogPin(void *pSensor);
//static float*           tempSensor_ReadFilter(void *pSensor);
static float*           tempSensor_Read(void *pSensor);
static void             tempSensor_DisplayRegister(void *pSensor);
static void             tempSensor_DisplayValue(void *pSensor);


//static float    (*pfMoveAverageTemperature)(float temperatureVal, tempFilter_t *ptempFilter);
//static float    (*pfFilterTemperature)(void *pSensor, tempFilter_t *pTempFilter);
//static float    MoveAverageTemperature(float temperatureVal, tempFilter_t *ptempFilter);
//static float    FilterTemperature(void *pSensor, tempFilter_t *pTempFilter);
//static void     tempSensor_AveMovTempCallBackHandlerRegister(float (*AveMovTempCallbackhander)(float temperatureVal, tempFilter_t *ptempFilter));
//static void     tempSensor_FilTempCallBackHandlerRegister(float (*FilTempCallbackHandler)(void *pSensor, tempFilter_t *pTempFilter));

tempSensor_t* newTempSensor(tempSensor_t *pSensor){
    /* Method Mapping */
    pSensor->sensor.Init            = tempSensor_Initialize;
    pSensor->sensor.setID           = tempSensor_setID;
    pSensor->sensor.getID           = tempSensor_getID;
    pSensor->sensor.setName         = tempSensor_setName;
    pSensor->sensor.getName         = tempSensor_getName;
    pSensor->SetanalogPin           = tempSensor_SetanalogPin;
    pSensor->GetanalogPin           = tempSensor_GetanalogPin;
//    pSensor->sensor.ReadFilter      = tempSensor_ReadFilter;
    pSensor->sensor.Read            = tempSensor_Read;    
    pSensor->sensor.DisplayRegister = tempSensor_DisplayRegister;
    pSensor->sensor.DisplayValue    = tempSensor_DisplayValue;

    
    /* Method Mapping Sensor LM35 */
    pSensor->lm35.SetAnalogPin      = LM35_SetAnalogPin;
//    pSensor->lm35.GetAnalogPin      = LM35_GetAnalogPin;
    pSensor->lm35.ReadTemp          = LM35_ReadTemperature;
    
    /* Method Mapping Comunication */
    pSensor->sensor.COM.UART1.Write = UART1_Write;
    
//    tempSensor_AveMovTempCallBackHandlerRegister(MoveAverageTemperature);
//    tempSensor_FilTempCallBackHandlerRegister(FilterTemperature);
   
    return pSensor;
}

static void tempSensor_Initialize(void *pSensor, uint8_t *ID, uint8_t *Name){
    tempSensor_setID(pSensor, ID);
    tempSensor_setName(pSensor, Name);
}

static void tempSensor_setID(void *pSensor, uint8_t *ID){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    ptempSensor->sensor.ID = ID;
}

static uint8_t* tempSensor_getID(void *pSensor){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    return ptempSensor->sensor.ID;
}

static void tempSensor_setName(void *pSensor, uint8_t *Name){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    ptempSensor->sensor.Name = Name;
}

static uint8_t* tempSensor_getName(void *pSensor){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    return ptempSensor->sensor.Name;
}

static void tempSensor_SetanalogPin(void *pSensor, adc_channel_t *analogPin){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    ptempSensor->analogPin = *analogPin;    
}

static adc_channel_t* tempSensor_GetanalogPin(void *pSensor){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    return &ptempSensor->analogPin;
}

//static float* tempSensor_ReadFilter(void *pSensor){
//    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
//    ptempSensor->lm35.SetAnalogPin(ptempSensor->GetanalogPin(ptempSensor));
//    switch(*ptempSensor->sensor.ID){
//        case TEMPSENSOR_ID_LM35_0:            
//            ptempSensor->sensor.readVal = pfFilterTemperature(ptempSensor, &SensorLM35_0);
//            break;
//        case TEMPSENSOR_ID_LM35_1:
////            ptempSensor->lm35.SetAnalogPin(ptempSensor->GetanalogPin(ptempSensor));
//            ptempSensor->sensor.readVal = pfFilterTemperature(ptempSensor, &SensorLM35_1);
//            break;
//        case TEMPSENSOR_ID_LM35_2:
////            ptempSensor->lm35.SetAnalogPin(ptempSensor->GetanalogPin(ptempSensor));
//            ptempSensor->sensor.readVal = pfFilterTemperature(ptempSensor, &SensorLM35_2);
//            break;
//        case TEMPSENSOR_ID_LM35_3:
////            ptempSensor->lm35.SetAnalogPin(ptempSensor->GetanalogPin(ptempSensor));
//            ptempSensor->sensor.readVal = pfFilterTemperature(ptempSensor, &SensorLM35_3);
//            break;
//        default:
//            break;
//    }
//    return &ptempSensor->sensor.readVal;
//}

static float* tempSensor_Read(void *pSensor){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    ptempSensor->lm35.SetAnalogPin(ptempSensor->GetanalogPin(ptempSensor));
    ptempSensor->sensor.readVal = ptempSensor->lm35.ReadTemp();
    return &ptempSensor->sensor.readVal;;
}

//static float MoveAverageTemperature(float temperatureVal, tempFilter_t *ptempFilter){
//    float avgTemp = 0;
//    ptempFilter->sum -= ptempFilter->Buffer[ptempFilter->index];
//    ptempFilter->Buffer[ptempFilter->index] = temperatureVal;
//    ptempFilter->sum += ptempFilter->Buffer[ptempFilter->index];
//    ptempFilter->index++;
//    ptempFilter->index %= BUFFER_SIZE_FILTER;
//    if(ptempFilter->countSum < BUFFER_SIZE_FILTER){
//        ptempFilter->countSum++;
//    }
//    avgTemp = ptempFilter->sum / ptempFilter->countSum;
//    return avgTemp;
//}
//
//static float FilterTemperature(void *pSensor, tempFilter_t *pTempFilter){
//    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
//    float readTemp = pfMoveAverageTemperature(ptempSensor->lm35.ReadTemp(), pTempFilter);
//    return readTemp;
//}

//static void tempSensor_AveMovTempCallBackHandlerRegister(float (*AveMovTempCallbackHandler)(float temperatureVal, tempFilter_t *ptempFilter)){
//    pfMoveAverageTemperature = AveMovTempCallbackHandler;
//}
//
//static void tempSensor_FilTempCallBackHandlerRegister(float (*FilTempCallbackHandler)(void *pSensor, tempFilter_t *pTempFilter)){
//    pfFilterTemperature = FilTempCallbackHandler;
//}

static void tempSensor_DisplayRegister(void *pSensor){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    printf("Register Sensor......\n Name: %s| ID: %d| Pin: AN%d\n",
            ptempSensor->sensor.getName(ptempSensor),
            ptempSensor->sensor.getID(ptempSensor),
            (uint8_t)*ptempSensor->GetanalogPin(ptempSensor));
}

static void tempSensor_DisplayValue(void *pSensor){
    tempSensor_t *ptempSensor = (tempSensor_t*)pSensor;
    float temporalval = *ptempSensor->sensor.Read(ptempSensor);
    uint16_t tempInt = (uint16_t)temporalval;
    uint8_t tempDec = (uint8_t)(temporalval * 10) % 10;
    //printf("%s: %d.%d C\r\n", 
    //        ptempSensor->sensor.getName(ptempSensor),
    //        tempInt, tempDec);
    printf("%2d.%d\n",tempInt-100,tempDec);
}