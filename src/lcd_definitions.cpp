#include "lcd_definitions.h"

LiquidCrystal_I2C lcd(DIRECCION_LCD, COLUMNAS_LCD, FILAS_LCD);

void configurarLCD()
{
    lcd.init();
    lcd.backlight();
}

void mostrarTemperatura(float temperatura)
{
    lcd.setCursor(0, 1);
    lcd.print(F("Temp: "));
    lcd.print(temperatura);
    lcd.print(F(" C "));
}

void mostrarHumedad(float humedad)
{
    lcd.setCursor(0, 0);
    lcd.print(F("Humedad: "));
    lcd.print(humedad);
    lcd.print(F("% "));
}
