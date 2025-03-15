#ifndef DHT_DEFINITIONS_H
#define DHT_DEFINITIONS_H

#include <Arduino.h>
#include "DHT.h"

#define PIN_DHT 2
#define TIPO_DHT DHT22

extern DHT dht;

void configurarDHT();
float obtenerTemperatura();
float obtenerHumedad();
bool estaFallandoLecturaDHT(float temperatura, float humedad);

#endif
