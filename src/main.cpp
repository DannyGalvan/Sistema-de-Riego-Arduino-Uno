#include <Arduino.h>
#include "DHT.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define BOMB 8
#define DHTPIN 2
#define DHTTYPE DHT22 // DHT 22  (AM2302), AM2321

#define POT_PIN A0
#define Min 500
#define Max 2400

#define SERVO_PIN 9 // Controla el servo
Servo servo;

LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  pinMode(BOMB, OUTPUT);
  servo.attach(SERVO_PIN, Min, Max);
  lcd.init();
  dht.begin();
}

void loop()
{
  int valorPot = analogRead(POT_PIN);          // Lee el valor del potenciómetro
  int angulo = map(valorPot, 0, 1023, 0, 180); // Convertir a PWM (0-180)
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    delay(2000);
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print(F("Humidity: "));
  lcd.print(humidity);
  lcd.print(F("% "));
  lcd.setCursor(0, 1);
  lcd.print(F("Temp: "));
  lcd.print(temperature);
  lcd.print(F(" g C "));

  if (humidity >= 0 && humidity <= 30)
  {
    digitalWrite(BOMB, HIGH); // Enciende relay
    Serial.println(F("Bomba Encendida"));
  }
  else
  {
    digitalWrite(BOMB, LOW);
    Serial.println(F("Bomba Apagada"));
  }

  servo.write(angulo);

  delay(2000);
}
