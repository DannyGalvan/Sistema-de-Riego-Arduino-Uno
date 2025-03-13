#include "system_manager.h"
#include "dht_definitions.h"
#include "lcd_definitions.h"
#include "servo_definitions.h"
#include "potentiometer_definitions.h"
#include "pump_definitions.h"

void setupSystem()
{
    Serial.begin(9600);
    setupPump();
    setupPotentiometer();
    setupServo();
    setupLCD();
    setupDHT();
}

void runSystem()
{
    int valorPot = readPotentiometer(); // Lee el valor del potenciómetro
    int angulo = getServoAngle();       // Convertir a PWM (0-180)
    float temperature = getTemperature();
    float humidity = getHumidity();

    // Check if any reads failed and exit early (to try again).
    if (isDHTReadFailed(temperature, humidity))
    {
        Serial.println(F("Failed to read from DHT sensor!"));
        delay(2000);
        return;
    }

    displayHumidity(humidity);
    displayTemperature(temperature);

    if (isPumpNeeded(humidity))
    {
        turnPumpOn();
    }
    else
    {
        turnPumpOff();
    }

    moveServo(angulo);

    delay(2000);
}
