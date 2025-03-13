#include "servo_definitions.h"

Servo servo;

void setupServo()
{
    servo.attach(SERVO_PIN, Min, Max);
}

void moveServo(int angle)
{
    servo.write(angle);
}
