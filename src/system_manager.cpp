/**
 * @file system_manager.cpp
 * @brief Control del sistema de gestión para un invernadero.
 *
 * Este módulo se encarga de gestionar los sensores, actuadores y
 * dispositivos necesarios para el control de un invernadero.
 * Incluye funciones para leer temperatura y humedad, manejar un
 * servomotor para ventilación, una bomba de agua y un potenciómetro
 * para ajuste manual.
 *
 * @author Grupo 1
 * @date 2025-05-12
 * @version 1.0
 */

#include "system_manager.h"
#include "dht_definitions.h"
#include "lcd_definitions.h"
#include "servo_definitions.h"
#include "potentiometer_definitions.h"
#include "pump_definitions.h"

/**
 * @brief Configura el sistema y todos los dispositivos conectados.
 *
 * Esta función inicializa la comunicación serial y configura:
 * - Bomba de agua
 * - Potenciómetro
 * - Servomotor
 * - Pantalla LCD
 * - Sensor DHT
 *
 * @return void
 */
void configurarSistema()
{
    Serial.begin(9600);        ///< Inicialización de comunicación serial a 9600 bps
    configurarBomba();         ///< Configuración de la bomba de agua
    configurarPotenciometro(); ///< Configuración del potenciómetro
    configurarServo();         ///< Configuración del servomotor
    configurarLCD();           ///< Configuración de la pantalla LCD
    configurarDHT();           ///< Configuración del sensor DHT
}

/**
 * @brief Ejecuta el ciclo principal de lectura y control del sistema.
 *
 * Esta función realiza las siguientes tareas en cada ciclo:
 * - Lee el ángulo del servomotor
 * - Lee temperatura y humedad del sensor DHT
 * - Muestra los valores en la pantalla LCD
 * - Activa o desactiva la bomba de agua según la humedad
 * - Mueve el servomotor de manera automática o manual
 *
 * @return void
 */
void correrSistema()
{
    int angulo = obtenerAnguloServo();        ///< Obtención del ángulo del servomotor (0-180)
    float temperatura = obtenerTemperatura(); ///< Obtención de la temperatura (°C)
    float humedad = obtenerHumedad();         ///< Obtención de la humedad (%)

    // Verificación de fallo en la lectura del sensor DHT
    if (estaFallandoLecturaDHT(temperatura, humedad))
    {
        Serial.println(F("Falla al leer Sensor DHT"));
        delay(2000); ///< Espera de 2 segundos antes de reintentar
        return;
    }

    // Mostrar los valores en pantalla LCD
    mostrarHumedad(humedad);
    mostrarTemperatura(temperatura);

    // Control de la bomba según el nivel de humedad
    if (esBombaNecesaria(humedad))
    {
        encenderBomba();
        moverServoAutomatico();
    }
    else
    {
        apagarBomba();
    }

    // Control manual del servomotor
    moverServoMecanico(angulo);

    delay(2000); ///< Espera de 2 segundos antes de la próxima lectura
}
