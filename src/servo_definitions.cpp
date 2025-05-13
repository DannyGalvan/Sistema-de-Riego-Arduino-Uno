/**
 * @file servo_definitions.cpp
 * @brief Definición y control de servomotores para el sistema.
 *
 * Este módulo se encarga de configurar y controlar dos servomotores:
 * - Un servomotor automático que realiza un ciclo de movimientos predeterminados.
 * - Un servomotor manual que se ajusta según el valor leído de un potenciómetro.
 *
 * @author Grupo 1
 * @date 2025-05-12
 * @version 1.0
 */

#include "servo_definitions.h"

/// Instancia del servomotor para control manual.
Servo servo_mecanico;

/// Instancia del servomotor para control automático.
Servo servo_automatico;

/**
 * @brief Configura los servomotores con sus respectivos pines y rangos.
 *
 * Esta función asocia los servomotores a los pines definidos:
 * - `PIN_SERVO_AUTOMATICO`: Controla el servomotor automático.
 * - `PIN_SERVO_MECANICO`: Controla el servomotor manual.
 *
 * Los valores de movimiento están limitados por `MIN` y `MAX`.
 *
 * @return void
 */
void configurarServo()
{
    servo_automatico.attach(PIN_SERVO_AUTOMATICO, MIN, MAX); ///< Configura el servomotor automático
    servo_mecanico.attach(PIN_SERVO_MECANICO, MIN, MAX);     ///< Configura el servomotor mecánico
}

/**
 * @brief Mueve el servomotor manual a un ángulo especificado.
 *
 * Esta función recibe un valor de ángulo en grados y ajusta
 * el servomotor manual a esa posición.
 *
 * @param angulo Valor en grados al que se moverá el servomotor (0 a 180).
 *
 * @return void
 */
void moverServoMecanico(int angulo)
{
    servo_mecanico.write(angulo); ///< Ajusta el servomotor al ángulo indicado
}

/**
 * @brief Realiza un ciclo automático de movimientos en el servomotor.
 *
 * El servomotor se mueve en una secuencia predefinida:
 * - 0°, 90°, 180° y regresa a 90°.
 *
 * La secuencia se ejecuta de manera cíclica en cada llamada a esta función.
 *
 * @return void
 */
void moverServoAutomatico()
{
    int angulos[] = {0, 90, 180, 90}; ///< Secuencia de ángulos de movimiento
    static int indice = 0;            ///< Índice para llevar el seguimiento del ángulo actual

    servo_automatico.write(angulos[indice]); ///< Mueve el servo al ángulo correspondiente
    indice = (indice + 1) % 4;               ///< Avanza al siguiente ángulo en el ciclo
}
