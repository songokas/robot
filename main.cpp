#include "robot.h"

#include <Arduino.h>

// distance specified in cm
const unsigned int SENSOR_MAX_RANGE = 200;

const unsigned int SPEED_SLOW = 50;
const unsigned int SPEED_FAST = 250;

const unsigned int DISTANCE_TO_OBSTICLE = 20;

int main()
{
    NewPing sonar(10, 11, SENSOR_MAX_RANGE);
    Servo servo();
    servo.attach(12)
    Radar radar(sonar, servo);
    DirectionControl directionControl(radar, 20);
    Motor motorA(6, 7);
    Motor motorB(8, 9);
    Robot robot(motorA, motorB, directionControl);
    while (true) {
        if (!directionControl.canMoveForward()) {
            robot.turn(Speed(20));
        }
        else {
            robot.run(Speed(40));
        }
        delay(100);
    }
}
