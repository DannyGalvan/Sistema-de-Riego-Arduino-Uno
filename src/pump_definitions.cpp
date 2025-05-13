/**
 * @file pump_definitions.cpp
 * @brief Definición y control de la bomba de riego para el sistema.
 *
 * Este módulo permite configurar, activar y desactivar la bomba de riego
 * según las condiciones de humedad del entorno.
 *
 * La bomba se enciende automáticamente cuando la humedad está por debajo
 * del umbral definido (30%). Además, permite el control manual a través
 * de funciones dedicadas.
 *
 * @author Grupo 1
 * @date 2025-05-12
 * @version 1.0
 */

#include "pump_definitions.h"

/**
 * @brief Configura el pin de la bomba de agua para salida digital.
 *
 * Esta función establece el pin asignado a la bomba como un pin
 * de salida (`OUTPUT`). Esto permite controlar el encendido y apagado
 * de la bomba mediante señales digitales.
 *
 * @return void
 */
void configurarBomba()
{
    pinMode(PIN_BOMBA, OUTPUT); ///< Define el pin de la bomba como salida
}

/**
 * @brief Activa la bomba de agua.
 *
 * Enciende la bomba al enviar una señal HIGH al pin correspondiente.
 * Además, imprime un mensaje en el monitor serial indicando el estado.
 *
 * @return void
 */
void encenderBomba()
{
    digitalWrite(PIN_BOMBA, HIGH);        ///< Envía una señal HIGH al pin de la bomba
    Serial.println(F("Bomba Encendida")); ///< Muestra un mensaje en el monitor serial
}

/**
 * @brief Apaga la bomba de agua.
 *
 * Desactiva la bomba al enviar una señal LOW al pin correspondiente.
 * Además, imprime un mensaje en el monitor serial indicando el estado.
 *
 * @return void
 */
void apagarBomba()
{
    digitalWrite(PIN_BOMBA, LOW);       ///< Envía una señal LOW al pin de la bomba
    Serial.println(F("Bomba Apagada")); ///< Muestra un mensaje en el monitor serial
}

/**
 * @brief Verifica si es necesario activar la bomba de agua.
 *
 * La función determina si la bomba debe encenderse en función del
 * nivel de humedad actual. Si la humedad está entre 0% y 30%, se
 * considera necesario activar el riego.
 *
 * @param humedad Nivel de humedad del entorno (0 - 100%).
 * @return `true` si la bomba es necesaria, `false` en caso contrario.
 */
bool esBombaNecesaria(float humedad)
{
    return (humedad >= 0 && humedad <= 30); ///< Evalúa si la humedad está en el rango crítico
}
