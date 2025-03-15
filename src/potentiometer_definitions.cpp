#include "potentiometer_definitions.h"

void configurarPotenciometro()
{
    pinMode(POT_PIN, INPUT);
}

int leerPotenciometro()
{
    return analogRead(POT_PIN);
}

int obtenerAnguloServo()
{
    int value = leerPotenciometro();
    return map(value, 0, 1023, 0, 180); // Convertir a rango de ángulo del servo
}
