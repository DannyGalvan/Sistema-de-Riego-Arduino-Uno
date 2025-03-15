#ifndef LCD_DEFINITIONS_H
#define LCD_DEFINITIONS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define DIRECCION_LCD 0x27
#define COLUMNAS_LCD 16
#define FILAS_LCD 2

extern LiquidCrystal_I2C lcd;

void configurarLCD();
void mostrarTemperatura(float temperatura);
void mostrarHumedad(float humedad);

#endif
