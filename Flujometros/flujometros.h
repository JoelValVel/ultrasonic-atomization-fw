/* 
 * File:   flujometros.h
 * Author: erjo_
 *
 * Created on 24 de marzo de 2025, 01:18 PM
 */

#ifndef FLUJOMETROS_H
#define	FLUJOMETROS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
#include "../PCA9685/PCA9685.h"
    
typedef struct flujometro flujometro_t;

struct flujometro{
    void        (*Init)(void *pFlujom, uint8_t Pin, uint16_t FlujoMax);
    uint8_t      Pin;
    uint16_t     Flujo;
    uint16_t     FlujoMax;
    void        (*SetFlujo)(void *pFlujom, uint16_t Flujo);
    uint16_t    (*GetFlujo)(void *pFlujom);
    void        (*SetFlujoMax)(void *pFlujom, uint16_t flujomax);
    uint16_t    (*GetFlujoMax)(void *pFlujometro);
};

flujometro_t *newFlujometro(flujometro_t* pFlujometro);

void SetFlujoMaxFlujometro(void *pFlujom, uint16_t flujomax);
uint16_t GetFlujoMaxFlujometro(void *pFlujom);
void FlujometroInit(void *pFlujom,  uint8_t Pin, uint16_t FlujoMax);
void        SetFlujoFlujometro(void *pFlujom, uint16_t Flujo);
uint16_t    GetFlujoFlujometro(void *pFlujom);





#ifdef	__cplusplus
}
#endif

#endif	/* FLUJOMETROS_H */

