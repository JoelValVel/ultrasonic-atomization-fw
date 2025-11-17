#include "PCA9685.h"
#include "../mcc_generated_files/uart/uart1.h"

const PCA9685_interface_t PCA9685 = {
    .SetFrecuency = setPWMFreq,
    .SetDutyCycle = setPWM
};


void setPWMFreq(float freq){
    // Limitar la frecuencia a los valores permitidos por el PCA9685
    if (freq < 1){
        freq = 1;
    }
    if (freq > 1526){
        freq = 1526; // Límite máximo según datasheet
    }
    // Calcular el valor prescale para configurar el oscilador interno
    // Fórmula según datasheet: prescale = round(osc_clock / (freq * 4096)) - 1
    float prescaleval = ((FREQUENCY_OSCILLATOR / (freq * 4096.0))) - 1;

    // Limitar el valor prescale a su rango válido
    if (prescaleval < PCA9685_PRESCALE_MIN){
        prescaleval = PCA9685_PRESCALE_MIN;
    }
    if (prescaleval > PCA9685_PRESCALE_MAX){
        prescaleval = PCA9685_PRESCALE_MAX;
    }
    
    uint8_t prescale = (uint8_t)prescaleval;
    uint8_t oldmode;
    uint8_t reg=PCA9685_MODE1;
    
    // Leer el registro MODE1 para obtener la configuración actual
    I2C1_Host.WriteRead(PCA9685_ADDR, &reg, sizeof(reg), &oldmode, sizeof(oldmode));
    while(I2C1_Host.IsBusy()){}
    
    // Preparar un nuevo modo que pone el chip en modo SLEEP para cambiar el prescaler
    uint8_t newmode = (uint8_t)((oldmode & ~MODE1_RESTART) | MODE1_SLEEP); // sleep
    uint8_t data[2];
    data[0] = reg;
    data[1] = newmode;
    __delay_ms(5);
    
    // Escribir el nuevo modo con SLEEP activado para pausar el chip
    I2C1_Host.Write(PCA9685_ADDR, data,sizeof(data));// go to sleep
    while(I2C1_Host.IsBusy()){}
    __delay_ms(10);
    
    // Escribir el nuevo valor del prescaler para ajustar la frecuencia PWM
    reg = PCA9685_PRESCALE;
    data[0] = reg;
    data[1] = prescale;
    I2C1_Host.Write(PCA9685_ADDR, data,sizeof(data));
    while(I2C1_Host.IsBusy()){}
    __delay_ms(10);
    
    // Restaurar el modo MODE1 anterior para reactivar el chip sin reiniciar
    reg = PCA9685_MODE1;
    data[0] = reg;
    data[1] = oldmode & ~MODE1_SLEEP; // Quitar el bit sleep;
    I2C1_Host.Write(PCA9685_ADDR, data,sizeof(data));
    while(I2C1_Host.IsBusy()){}
    
    // Esperar 5 ms para que el oscilador se estabilice tras el cambio
    __delay_ms(10);

    // Activar los bits RESTART y AUTO INCREMENT en MODE1 para un funcionamiento óptimo
    data[0] = reg;
    data[1] = (oldmode & ~MODE1_SLEEP) | MODE1_RESTART | MODE1_AI;
    I2C1_Host.Write(PCA9685_ADDR, data,sizeof(data));
    while(I2C1_Host.IsBusy()){}
}

void setPWM(uint8_t num, uint16_t on, uint16_t off){
  uint8_t buffer[5];    // Buffer para enviar por I2C: 1 byte de registro + 4 bytes de datos
  uint8_t addres,rt;

  // Calcula la dirección base del registro del canal 'num'
  // Cada canal ocupa 4 registros consecutivos, empezando en LED0_ON_L (0x06)
  addres = PCA9685_LED0_ON_L + (4 * num);
  buffer[0] = addres;  // Primer byte: registro inicial donde escribir
  buffer[1] = on;       // Segundo byte: parte baja del valor 'on' (bit 0-7)
  buffer[2] = on >> 8;  // Tercer byte: parte alta del valor 'on' (bit 8-11, PCA9685 usa solo 12 bits)
  buffer[3] = off;      // Cuarto byte: parte baja del valor 'off' (bit 0-7)
  buffer[4] = off >> 8; // Quinto byte: parte alta del valor 'off' (bit 8-11)
  
  // Enviar los 5 bytes por I2C al dispositivo con dirección PCA9685_ADDR
  // Esto escribe los valores on/off en los registros correspondientes para el canal num
  rt = I2C1_Host.Write(PCA9685_ADDR,buffer,sizeof(buffer));
  //UART1_Write(rt+48);
  while(I2C1_Host.IsBusy()){}
  
}