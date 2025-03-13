#include "pump_definitions.h"

void setupPump()
{
    pinMode(PUMP_PIN, OUTPUT);
}

void turnPumpOn()
{
    digitalWrite(PUMP_PIN, HIGH);
    Serial.println(F("Bomba Encendida"));
}

void turnPumpOff()
{
    digitalWrite(PUMP_PIN, LOW);
    Serial.println(F("Bomba Apagada"));
}

bool isPumpNeeded(float humidity)
{
    return (humidity >= 0 && humidity <= 30);
}
