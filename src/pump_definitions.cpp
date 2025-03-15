#include "pump_definitions.h"

void configurarBomba()
{
    pinMode(PIN_BOMBA, OUTPUT);
}

void encenderBomba()
{
    digitalWrite(PIN_BOMBA, HIGH);
    Serial.println(F("Bomba Encendida"));
}

void apagarBomba()
{
    digitalWrite(PIN_BOMBA, LOW);
    Serial.println(F("Bomba Apagada"));
}

bool esBombaNecesaria(float humedad)
{
    return (humedad >= 0 && humedad <= 30);
}
