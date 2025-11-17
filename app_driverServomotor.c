#include "app_driverServomotor.h"

 /* 
  * Construimos el objetos Servo_1 
  * su espacio de memoria con pServo_1 
 */
servomotor_t Servomotor_0;
servomotor_t *pServo_0;
servomotor_t Servomotor_1;
servomotor_t *pServo_1;
servomotor_t Servomotor_2;
servomotor_t *pServo_2;

void Servomotor_Initialize(void){
    pServo_0 = newServomotor(&Servomotor_0);
    pServo_0->Init(pServo_0,3,544,2400);
    pServo_0->SetAngle(pServo_0,(uint8_t)180);
    pServo_1 = newServomotor(&Servomotor_1);
    pServo_1->Init(pServo_1,6,544,2500);
    pServo_1->SetAngle(pServo_1,0);
    pServo_2 = newServomotor(&Servomotor_2);
    pServo_2->Init(pServo_2,10,544,2500);
    pServo_2->SetAngle(pServo_2,(uint8_t)0);
}
