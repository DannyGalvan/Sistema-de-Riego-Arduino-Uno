/**
 * @file system_manager.cpp
 * @brief Punto de entrada del sistema de gestión del invernadero.
 *
 * Este módulo contiene las funciones principales del programa:
 * `setup()` y `loop()`. Es el punto de entrada del sistema,
 * donde se configura el hardware y se inicia el ciclo principal
 * de control de sensores y actuadores.
 *
 * El sistema se encarga de:
 * - Configuración de sensores y actuadores.
 * - Monitoreo y actualización de la pantalla LCD.
 * - Control de la bomba de agua y servomotores.
 *
 * @note La configuración de cada módulo se realiza en `configurarSistema()`.
 *       El ciclo de control se ejecuta en `correrSistema()`.
 *
 * @see configurarSistema()
 * @see correrSistema()
 *
 * @author Grupo 1
 * @date 2025-05-12
 * @version 1.0
 */

#include <Arduino.h>
#include "system_manager.h"

/**
 * @brief Configura el sistema al iniciar el programa.
 *
 * Esta función es llamada una sola vez al iniciar el Arduino. Se encarga
 * de ejecutar la configuración de los dispositivos necesarios para el
 * funcionamiento del sistema.
 *
 * @return void
 */
void setup()
{
  configurarSistema(); ///< Llama a la función que configura todos los dispositivos
}

/**
 * @brief Ciclo principal del sistema.
 *
 * Esta función se ejecuta en bucle indefinidamente. En cada iteración,
 * realiza la lectura de sensores, actualiza la pantalla LCD y controla
 * los actuadores (bomba de agua y servomotores) según los valores leídos.
 *
 * @return void
 */
void loop()
{
  correrSistema(); ///< Ejecuta el ciclo de lectura y control de actuadores
}
