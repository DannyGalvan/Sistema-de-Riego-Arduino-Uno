#include "lcd_definitions.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setupLCD()
{
    lcd.init();
    lcd.backlight();
}

void displayTemperature(float temperature)
{
    lcd.setCursor(0, 1);
    lcd.print(F("Temp: "));
    lcd.print(temperature);
    lcd.print(F(" C "));
}

void displayHumidity(float humidity)
{
    lcd.setCursor(0, 0);
    lcd.print(F("Humidity: "));
    lcd.print(humidity);
    lcd.print(F("% "));
}
