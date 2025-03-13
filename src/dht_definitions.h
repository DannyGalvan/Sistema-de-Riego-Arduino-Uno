#ifndef DHT_DEFINITIONS_H
#define DHT_DEFINITIONS_H

#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321

extern DHT dht;

void setupDHT();
float getTemperature();
float getHumidity();
bool isDHTReadFailed(float temperature, float humidity);

#endif // DHT_DEFINITIONS_H
