/* 
 * File:   app_driverFlujometro.h
 * Author: erjo_
 *
 * Created on 24 de marzo de 2025, 07:27 PM
 */

#ifndef APP_DRIVERFLUJOMETRO_H
#define	APP_DRIVERFLUJOMETRO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Flujometros/flujometros.h"
    
extern flujometro_t Flujometro_3;
extern flujometro_t *pFlujom_3;
extern flujometro_t Flujometro_4;
extern flujometro_t *pFlujom_4;
extern flujometro_t Flujometro_2;
extern flujometro_t *pFlujom_2;

    
void Flujometro_Initialize(void);


#ifdef	__cplusplus
}
#endif

#endif	/* APP_DRIVERFLUJOMETRO_H */

