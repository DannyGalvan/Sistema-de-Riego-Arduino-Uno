#include "system_manager.h"
#include "dht_definitions.h"
#include "lcd_definitions.h"
#include "servo_definitions.h"
#include "potentiometer_definitions.h"
#include "pump_definitions.h"

void configurarSistema()
{
    Serial.begin(9600);
    configurarBomba();
    configurarPotenciometro();
    configurarServo();
    configurarLCD();
    configurarDHT();
}

void correrSistema()
{
    int angulo = obtenerAnguloServo(); // Convertir a GRADOS (0-180)
    float temperatura = obtenerTemperatura();
    float humedad = obtenerHumedad();

    if (estaFallandoLecturaDHT(temperatura, humedad))
    {
        Serial.println(F("Falla al leer Sensor DHT"));
        delay(2000);
        return;
    }

    mostrarHumedad(humedad);
    mostrarTemperatura(temperatura);

    if (esBombaNecesaria(humedad))
    {
        encenderBomba();
        moverServoAutomatico();
    }
    else
    {
        apagarBomba();
    }

    moverServoMecanico(angulo);

    delay(2000);
}
