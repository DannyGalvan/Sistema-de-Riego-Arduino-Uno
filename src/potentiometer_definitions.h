#ifndef POTENTIOMETER_DEFINITIONS_H
#define POTENTIOMETER_DEFINITIONS_H

#include <Arduino.h>

#define POT_PIN A0

void setupPotentiometer();
int readPotentiometer();
int getServoAngle();

#endif // POTENTIOMETER_DEFINITIONS_H
