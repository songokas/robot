#include "robot.h"

#include <Arduino.h>

Robot::Robot(const Motor & motorA, const Motor & motorB, const DirectionControl & directionControl)
  :motorA(motorA), motorB(motorB), directionControl(directionControl) 
{}

void Robot::run(const Speed & speed)
{
    motorA.forward(directionControl.getLeftSpeed(speed));
    motorB.forward(directionControl.getRightSpeed(speed));
}

//@TODO degrees
void Robot::turnAround(int degrees, const Speed & speed)
{
    motorA.backward(speed);
    motorB.forward(speed);
    delay(200);
}

