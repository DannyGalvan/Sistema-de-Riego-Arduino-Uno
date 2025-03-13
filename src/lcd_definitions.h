#ifndef LCD_DEFINITIONS_H
#define LCD_DEFINITIONS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

extern LiquidCrystal_I2C lcd;

void setupLCD();
void displayTemperature(float temperature);
void displayHumidity(float humidity);

#endif // LCD_DEFINITIONS_H
