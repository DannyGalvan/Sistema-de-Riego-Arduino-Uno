#ifndef SERVO_DEFINITIONS_H
#define SERVO_DEFINITIONS_H

#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 9
#define Min 500
#define Max 2400

extern Servo servo;

void setupServo();
void moveServo(int angle);

#endif
