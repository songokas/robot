#include "robot.h"
#include "speed.h"
#include "display.h"

#include <MemoryFree.h>
#include <Arduino.h>


Robot::Robot(const Motor & motorA, const Motor & motorB, Radar & radar, SoundPlayer & soundPlayer, Display & display)
:motorA(motorA), motorB(motorB), radar(radar), soundPlayer(soundPlayer), display(display), distances {0}, index(0)
{
}

void Robot::run(const Speed & speed)
{
    soundPlayer.setInterval(100);
    radar.setInterval(200);
    while (true) {
        if (radar.shouldRun()) radar.run();
        if (soundPlayer.shouldRun()) soundPlayer.run();
        move(speed);
    }
}

void Robot::move(const Speed & speed)
{
    int distance = radar.getFrontDistance();
    char message[40];
    sprintf(message, "Front: %i\nLeft: %i\nRight: %i\nRam: %i", radar.getFrontDistance(), radar.getLeftDistance(), radar.getRightDistance(), freeMemory());
    display.print(message);
    if (distance > 0 && distance < 20) {
        moveLeftBack(speed);
        delay(2000);
    } else if (distance >= 20 && distance < 40 && state == MovingBack) {
        moveLeftBack(speed);
    } else if (distance > 0) {
        if (isStuck()) {
            display.print("Is stuck");
            int rightDistance = radar.getRightDistance();
            int leftDistance = radar.getLeftDistance();
            if (rightDistance < 20 && leftDistance > 20) {
                moveRightBack(speed);
                delay(1000);
            } else if (rightDistance > 20 && leftDistance < 20) {
                moveLeftBack(speed);
                delay(1000);
            } else {
                moveLeftBack(speed);
                delay(1000);
            }
        } else if (distance < 60) {
            moveLeft(speed);
        } else {
            moveForward(speed);
        }
    } else {
        off();
    }
    measurePath(distance);
    delay(50);
}

void Robot::moveForward(const Speed & speed)
{
    state = MovingFront;
    //Serial.println("Going forward");
    motorA.forward(speed);
    motorB.forward(speed);
}

void Robot::moveBackward(const Speed & speed)
{
    state = MovingBack;
    //Serial.println("Going backward");
    motorA.backward(speed);
    motorB.backward(speed);
}

void Robot::moveRight(const Speed & speed)
{
   state = MovingFront;

    //Serial.println("Moving left");
    motorA.forward(speed);
    motorB.off();
}

void Robot::moveLeft(const Speed & speed)
{
    //Serial.println("Moving right");
    motorA.off();
    motorB.forward(speed);
}

void Robot::moveLeftBack(const Speed & speed)
{
    state = MovingBack;
    //Serial.println("Moving back left");
    motorB.backward(speed);
    motorA.off();
}

void Robot::moveRightBack(const Speed & speed)
{
    state = MovingBack;
    //Serial.println("Moving back left");
    motorB.off();
    motorA.backward(speed);
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
    delay(200);
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
    //for (DistanceList::const_iterator it = distances.begin(); it != distances.end(); ++it) {
        Serial.print("Variance ");
        Serial.println(variance);
        //Serial.print(" ");
        //Serial.println(*it);
        //variance = abs((long)(*it - variance)); 
    //}
        //Serial.println("Finished");
    if (variance > 0 && variance < 4) {
        return true;
    }

    return false;
}
