/**
 * @file potentiometer_definitions.cpp
 * @brief Definición y control del potenciómetro para el sistema.
 *
 * Este módulo se encarga de configurar y leer el valor de un potenciómetro,
 * permitiendo mapear su valor analógico a un ángulo para el control de un servomotor.
 *
 * La lectura del potenciómetro se realiza mediante un puerto analógico, y el valor
 * obtenido se convierte a un rango de 0° a 180°, correspondiente al ángulo del servomotor.
 *
 * @author Grupo 1
 * @date 2025-05-12
 * @version 1.0
 */

#include "potentiometer_definitions.h"

/**
 * @brief Configura el pin del potenciómetro como entrada analógica.
 *
 * Esta función define el pin asociado al potenciómetro como un pin
 * de entrada (`INPUT`). Esto permite capturar el valor analógico
 * que representa la posición del potenciómetro.
 *
 * @return void
 */
void configurarPotenciometro()
{
    pinMode(POT_PIN, INPUT); ///< Define el pin del potenciómetro como entrada
}

/**
 * @brief Lee el valor analógico del potenciómetro.
 *
 * La función obtiene el valor en un rango de 0 a 1023 (10 bits) desde el pin
 * analógico configurado. Este valor representa la posición actual del potenciómetro.
 *
 * @return int Valor analógico leído del potenciómetro (0 - 1023).
 */
int leerPotenciometro()
{
    return analogRead(POT_PIN); ///< Lee el valor analógico del potenciómetro
}

/**
 * @brief Convierte el valor del potenciómetro en un ángulo para el servomotor.
 *
 * El valor analógico del potenciómetro (0 - 1023) se mapea a un rango de
 * 0° a 180°, el cual corresponde al ángulo de movimiento del servomotor.
 *
 * @return int Ángulo calculado para el servomotor (0 - 180).
 */
int obtenerAnguloServo()
{
    int value = leerPotenciometro();    ///< Obtiene el valor analógico del potenciómetro
    return map(value, 0, 1023, 0, 180); ///< Mapea el valor al rango de 0° a 180°
}
