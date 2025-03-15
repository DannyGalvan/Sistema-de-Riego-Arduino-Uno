#include <Arduino.h>
#include "DHT.h"
#include "dht_definitions.h"

DHT dht(PIN_DHT, TIPO_DHT);

void configurarDHT()
{
    dht.begin();
}

float obtenerTemperatura()
{
    return dht.readTemperature();
}

float obtenerHumedad()
{
    return dht.readHumidity();
}

bool estaFallandoLecturaDHT(float temperatura, float humedad)
{
    return isnan(temperatura) || isnan(humedad);
}
