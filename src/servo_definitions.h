#ifndef SERVO_DEFINITIONS_H
#define SERVO_DEFINITIONS_H

#include <Arduino.h>
#include <Servo.h>

#define PIN_SERVO_MECANICO 9
#define PIN_SERVO_AUTOMATICO 10
#define MIN 500
#define MAX 2400

extern Servo servo_mecanico;
extern Servo servo_automatico;

void configurarServo();
void moverServoMecanico(int angulo);
void moverServoAutomatico();

#endif
