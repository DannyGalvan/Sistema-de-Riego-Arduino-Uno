#ifndef POTENTIOMETER_DEFINITIONS_H
#define POTENTIOMETER_DEFINITIONS_H

#include <Arduino.h>

#define POT_PIN A0

void configurarPotenciometro();
int leerPotenciometro();
int obtenerAnguloServo();

#endif
