#include "motor.h"
#include "speed.h"
#include <Arduino.h>

//@TODO use ena enb for speed control
Motor::Motor(int directionPin1, int directionPin2, int speedPin)
    : directionPin1(directionPin1), directionPin2(directionPin2), speedPin(speedPin)
{
    pinMode(directionPin1, OUTPUT);
    pinMode(directionPin2, OUTPUT);
    pinMode(speedPin, OUTPUT);
}

void Motor::backward(const Speed & speed)
{
    digitalWrite(directionPin1, HIGH);
    digitalWrite(directionPin2, LOW);
    //digitalWrite(speedPin, HIGH);
    analogWrite(speedPin, speed.getEngineSpeed());
}

void Motor::forward(const Speed & speed)
{
    digitalWrite(directionPin1, LOW);
    digitalWrite(directionPin2, HIGH);
    //digitalWrite(speedPin, HIGH);
    analogWrite(speedPin, speed.getEngineSpeed());
}


