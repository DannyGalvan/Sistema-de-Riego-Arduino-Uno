#include <Arduino.h>
#include "DHT.h"
#include "dht_definitions.h"

DHT dht(DHTPIN, DHTTYPE);

void setupDHT()
{
    dht.begin();
}

float getTemperature()
{
    return dht.readTemperature();
}

float getHumidity()
{
    return dht.readHumidity();
}

bool isDHTReadFailed(float temperature, float humidity)
{
    return isnan(temperature) || isnan(humidity);
}
