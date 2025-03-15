#ifndef PUMP_DEFINITIONS_H
#define PUMP_DEFINITIONS_H

#include <Arduino.h>

#define PIN_BOMBA 8

void configurarBomba();
void encenderBomba();
void apagarBomba();
bool esBombaNecesaria(float humedad);

#endif
