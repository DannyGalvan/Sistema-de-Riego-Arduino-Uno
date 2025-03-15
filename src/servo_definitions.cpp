#include "servo_definitions.h"

Servo servo_mecanico;
Servo servo_automatico;

void configurarServo()
{
    servo_automatico.attach(PIN_SERVO_AUTOMATICO, MIN, MAX);
    servo_mecanico.attach(PIN_SERVO_MECANICO, MIN, MAX);
}

void moverServoMecanico(int angulo)
{
    servo_mecanico.write(angulo);
}

void moverServoAutomatico()
{
    // Define los ángulos en orden
    int angulos[] = {0, 90, 180, 90};
    static int indice = 0; // Mantiene el índice de la secuencia

    servo_automatico.write(angulos[indice]); // Mueve el servo al siguiente ángulo
    indice = (indice + 1) % 4;               // Avanza en la secuencia, volviendo a 0 cuando llegue al final
}
