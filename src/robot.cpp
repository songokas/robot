#include "robot.h"
#include "speed.h"
#include "display.h"

#include <MemoryFree.h>
#include <Arduino.h>


Robot::Robot(const Motor & motorA, const Motor & motorB, Radar & radar, SoundPlayer & soundPlayer, Display & display)
:motorA(motorA), motorB(motorB), radar(radar), soundPlayer(soundPlayer), display(display), distances {0}, index(0), moveUntil(1)
{
}

void Robot::run(const Speed & speed)
{
    soundPlayer.setInterval(100);
    radar.setInterval(100);
    while (true) {
        if (soundPlayer.shouldRun()) soundPlayer.run();
        if (radar.shouldRun()) radar.run();
        move(speed);
    }
}

void Robot::move(const Speed & speed)
{
    int distance = radar.getFrontDistance();
    int rightDistance = radar.getRightDistance();
    int leftDistance = radar.getLeftDistance();
    char test [40] = {0};
    sprintf(test, "front:%d\nleft:%d\nright:%d", distance, leftDistance, rightDistance);
    display.print(test);
    Serial.println(test);

    measurePath(distance);
    if (isMovingForRequiredTime()) {
        return;
    }
    if (distance > 0 && distance < 25) {
        moveLeftBack(speed, 2000);
    }
    else if (distance >= 25 && distance < 45) {
        if (rightDistance > leftDistance) {
            moveRightBack(speed, 2000);
        } else {
            moveLeftBack(speed, 2000);
        }
    }
    else if (leftDistance > 0 && leftDistance < 20) {
        moveRight(speed, 500);
    }
    else if (rightDistance > 0 && rightDistance < 20) {
        moveLeft(speed, 500);
    }
    else if (isStuck()) {
        if (rightDistance > leftDistance) {
            moveRightBack(speed, 2000);
        } else {
            moveLeftBack(speed, 2000);
        }
    } else {
        moveForward(speed, 500);
    }
}

void Robot::moveForward(const Speed & speed, int time)
{
    state = MovingFront;
    //Serial.println("Going forward");
    motorA.forward(speed);
    motorB.forward(speed);
    recordTime(time);
    //display.print("Moving front");
}

void Robot::moveBackward(const Speed & speed, int time)
{
    state = MovingBack;
    //Serial.println("Going backward");
    motorA.backward(speed);
    motorB.backward(speed);
    recordTime(time);
    //display.print("Moving back");
}

void Robot::moveRight(const Speed & speed, int time)
{
    state = MovingFront;
    motorA.off();
    motorB.forward(speed);
    recordTime(time);
    //display.print("Moving right");
}

void Robot::moveLeft(const Speed & speed, int time)
{
    motorA.forward(speed);
    motorB.off();
    recordTime(time);
    //display.print("Moving left");
}

void Robot::moveLeftBack(const Speed & speed, int time)
{
    state = MovingBack;
    motorA.backward(speed);
    motorB.off();
    recordTime(time);
    //display.print("Moving left back");
}

void Robot::moveRightBack(const Speed & speed, int time)
{
    state = MovingBack;
    motorA.off();
    motorB.backward(speed);
    recordTime(time);
    //display.print("Moving right back");
}

void Robot::off()
{
    state = Off;
    //Serial.println("Engine off");
    motorA.off();
    motorB.off();
}

//@TODO degrees
void Robot::turnAround(int degrees, const Speed & speed)
{
    motorA.backward(speed);
    motorB.forward(speed);
}

void Robot::measurePath(int distance)
{
    distances[index] = distance;
    index++;
    if (index >= DISTANCE_ARRAY) {
        index = 0;
    }
}

bool Robot::isStuck() const
{
    byte variance = 0, minn = 200, maxn = 0;
    for (byte i = 0; i < DISTANCE_ARRAY; i++) {
        minn = distances[i] < minn ? distances[i] : minn;
        maxn = distances[i] > maxn ? distances[i] : maxn;
    }
    variance = maxn - minn;
    if (variance > 0 && variance < 4) {
        return true;
    }

    return false;
}

void Robot::recordTime(int time)
{
    moveUntil = millis() + time;
}

bool Robot::isMovingForRequiredTime()
{
    return millis() < moveUntil;
}
