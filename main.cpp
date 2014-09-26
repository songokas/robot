#include <Arduino.h>
#include <NewPing.h>
#include "engine.h"
#include "robot.h"

// distance specified in cm
const unsigned int SENSOR_MAX_RANGE = 200;

const unsigned int SPEED_SLOW = 50;
const unsigned int SPEED_FAST = 250;

const unsigned int DISTANCE_TO_OBSTICLE = 20;

int main()
{
    NewPing forwardSonar(10, 11, SENSOR_MAX_RANGE);
    DualEngine engine(6, 7, 8, 9);
    Robot robot(engine, forwardSonar);
    while (true) {
        if (robot.hasObsticle(DISTANCE_TO_OBSTICLE)) {
            robot.moveRight(SPEED_SLOW);
        } else {
            robot.moveForward(SPEED_FAST);
        }
        delay(100);
    }
}
