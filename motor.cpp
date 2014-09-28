#include "motor.h"
#include "speed.h"
#include <Arduino.h>

Motor::Motor(int directionPin, int speedPin)
    : directionPin(directionPin), speedPin(speedPin)
{
    pinMode(directionPin, OUTPUT);
    pinMode(speedPin, OUTPUT);
}

void Motor::forward(const Speed & speed)
{
    digitalWrite(directionPin, HIGH);
    analogWrite(speedPin, speed.getEngineSpeed());
}

void Motor::backward(const Speed & speed)
{
    digitalWrite(directionPin, LOW);
    analogWrite(speedPin, speed.getEngineSpeed());
}


