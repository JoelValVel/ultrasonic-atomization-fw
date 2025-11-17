#include "app_driverFlujometro.h"
#include "Flujometros/flujometros.h"

 /* 
  * Construimos el objetos Flujometro_1 
  * su espacio de memoria con pFlujom_1 
 */
flujometro_t Flujometro_3;
flujometro_t *pFlujom_3;
flujometro_t Flujometro_4;
flujometro_t *pFlujom_4;
flujometro_t Flujometro_2;
flujometro_t *pFlujom_2;


void Flujometro_Initialize(void){
    pFlujom_3 = newFlujometro(&Flujometro_3);
    pFlujom_3->Init(pFlujom_3,4,500);
    pFlujom_3->SetFlujo(pFlujom_3,120);
    pFlujom_4 = newFlujometro(&Flujometro_4);
    pFlujom_4->Init(pFlujom_4,8,500);
    pFlujom_4->SetFlujo(pFlujom_4,100);
    pFlujom_2 = newFlujometro(&Flujometro_2);
    pFlujom_2->Init(pFlujom_2,1,1000);
    pFlujom_2->SetFlujo(pFlujom_2,750);
}


