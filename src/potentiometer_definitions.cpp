#include "potentiometer_definitions.h"

void setupPotentiometer()
{
    pinMode(POT_PIN, INPUT);
}

int readPotentiometer()
{
    return analogRead(POT_PIN);
}

int getServoAngle()
{
    int value = readPotentiometer();
    return map(value, 0, 1023, 0, 180); // Convertir a rango de ángulo del servo
}
