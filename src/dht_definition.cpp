/**
 * @file dht_definitions.cpp
 * @brief Definición y control del sensor DHT para la lectura de temperatura y humedad.
 *
 * Este módulo permite la configuración y lectura de datos del sensor DHT.
 * Se obtienen valores de temperatura (°C) y humedad (%), y se valida si
 * las lecturas son correctas o fallan por algún motivo.
 *
 * @note El tipo de sensor y el pin están definidos en "dht_definitions.h".
 *
 * @author Grupo 1
 * @date 2025-05-12
 * @version 1.0
 */

#include <Arduino.h>
#include "DHT.h"
#include "dht_definitions.h"

/// Instancia del sensor DHT especificando el pin y el tipo de sensor.
DHT dht(PIN_DHT, TIPO_DHT);

/**
 * @brief Configura e inicia el sensor DHT.
 *
 * Esta función inicializa el sensor para que pueda comenzar a realizar
 * lecturas de temperatura y humedad.
 *
 * @return void
 */
void configurarDHT()
{
    dht.begin(); ///< Inicia el sensor DHT
}

/**
 * @brief Obtiene el valor de la temperatura desde el sensor DHT.
 *
 * La función lee el valor de temperatura en grados Celsius directamente
 * desde el sensor y lo retorna como un valor flotante.
 *
 * @return float Valor de la temperatura en grados Celsius (°C).
 */
float obtenerTemperatura()
{
    return dht.readTemperature(); ///< Lee el valor de temperatura del sensor
}

/**
 * @brief Obtiene el valor de la humedad desde el sensor DHT.
 *
 * La función lee el valor de humedad en porcentaje directamente desde el
 * sensor y lo retorna como un valor flotante.
 *
 * @return float Valor de la humedad en porcentaje (%).
 */
float obtenerHumedad()
{
    return dht.readHumidity(); ///< Lee el valor de humedad del sensor
}

/**
 * @brief Verifica si las lecturas del sensor DHT son válidas.
 *
 * Esta función evalúa si los valores obtenidos para temperatura y humedad
 * son correctos. Si alguno de ellos es `NaN` (Not a Number), indica que
 * hubo un fallo en la lectura.
 *
 * @param temperatura Valor leído de temperatura.
 * @param humedad Valor leído de humedad.
 * @return `true` si hay un fallo en la lectura, `false` en caso contrario.
 */
bool estaFallandoLecturaDHT(float temperatura, float humedad)
{
    return isnan(temperatura) || isnan(humedad); ///< Verifica si alguna lectura es NaN
}
