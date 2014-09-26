#include <Arduino.h>
#include "engine.h"

//@TODO apply speed

DualEngine::DualEngine(int left1, int left2, int right1, int right2)
    : left1(left1), left2(left2), right1(right1), right2(right2)
{
    pinMode(left1, OUTPUT);
    pinMode(left2, OUTPUT);
    pinMode(right1, OUTPUT);
    pinMode(right2, OUTPUT);
}

void DualEngine::leftForward(int speed)
{
    move(HIGH, LOW, HIGH, LOW);
    //analogWrite(left1, speed);
    //analogWrite(left2, speed);
}

void DualEngine::leftRightForward(int speed)
{
    //leftForward(speed);
    //rightForward(speed);
    move(LOW, HIGH, HIGH, LOW);
}

void DualEngine::rightForward(int speed)
{
    move(LOW, HIGH, LOW, HIGH);
    //analogWrite(right1, speed);
    //analogWrite(right2, speed);
}

// robMove routine switches the correct inputs to the L298N for the direction selected.
void DualEngine::move(int l1, int l2, int r1, int r2)
{
    digitalWrite(left1, l1);
    digitalWrite(left2, l2);
    digitalWrite(right1, r1);
    digitalWrite(right2, r2);  
}
