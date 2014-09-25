#include <Arduino.h>
#include "engine.h"

Engine::Engine(int left1, int left2, int right1, int right2)
    : left1(left1), left2(left2), right1(right1), right2(right2)
{}

void Engine::leftForward(int speed)
{
    analogWrite(left1, speed);
    analogWrite(left2, speed);
}

void Engine::leftRightForward(int speed)
{
    leftForward(speed);
    rightForward(speed);
}

void Engine::rightForward(int speed)
{
    analogWrite(right1, speed);
    analogWrite(right2, speed);
}
