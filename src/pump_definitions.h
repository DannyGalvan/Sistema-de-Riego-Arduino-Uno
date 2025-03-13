#ifndef PUMP_DEFINITIONS_H
#define PUMP_DEFINITIONS_H

#include <Arduino.h>

#define PUMP_PIN 8

void setupPump();
void turnPumpOn();
void turnPumpOff();
bool isPumpNeeded(float humidity);

#endif // PUMP_DEFINITIONS_H
