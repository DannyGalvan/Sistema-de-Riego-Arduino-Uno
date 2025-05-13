/**
 * @file lcd_definitions.cpp
 * @brief Definición y control de la pantalla LCD para el sistema.
 *
 * Este módulo se encarga de configurar y mostrar información en una pantalla LCD
 * utilizando el protocolo I2C. Permite visualizar datos de temperatura y humedad
 * en tiempo real.
 *
 * La pantalla se inicializa con retroiluminación y se actualiza en cada ciclo
 * de lectura de sensores.
 *
 * @author Grupo 1
 * @date 2025-05-12
 * @version 1.0
 */

#include "lcd_definitions.h"

/// Instancia del objeto LCD utilizando I2C.
LiquidCrystal_I2C lcd(DIRECCION_LCD, COLUMNAS_LCD, FILAS_LCD);

/**
 * @brief Configura la pantalla LCD e inicia la retroiluminación.
 *
 * Esta función inicializa el display y activa la retroiluminación para
 * permitir la visualización de datos.
 *
 * @return void
 */
void configurarLCD()
{
    lcd.init();      ///< Inicialización del display LCD
    lcd.backlight(); ///< Activación de la retroiluminación
}

/**
 * @brief Muestra el valor de la temperatura en la pantalla LCD.
 *
 * La función coloca el cursor en la segunda línea (fila 1, columna 0) de la pantalla
 * y despliega el valor de la temperatura en grados Celsius.
 *
 * @param temperatura Valor flotante de la temperatura actual.
 * @return void
 */
void mostrarTemperatura(float temperatura)
{
    lcd.setCursor(0, 1);    ///< Posiciona el cursor en la segunda línea
    lcd.print(F("Temp: ")); ///< Etiqueta para temperatura
    lcd.print(temperatura); ///< Valor de la temperatura
    lcd.print(F(" C "));    ///< Unidad de medida
}

/**
 * @brief Muestra el valor de la humedad en la pantalla LCD.
 *
 * La función coloca el cursor en la primera línea (fila 0, columna 0) de la pantalla
 * y despliega el valor de la humedad en porcentaje.
 *
 * @param humedad Valor flotante de la humedad actual.
 * @return void
 */
void mostrarHumedad(float humedad)
{
    lcd.setCursor(0, 0);       ///< Posiciona el cursor en la primera línea
    lcd.print(F("Humedad: ")); ///< Etiqueta para humedad
    lcd.print(humedad);        ///< Valor de la humedad
    lcd.print(F("% "));        ///< Símbolo de porcentaje
}
