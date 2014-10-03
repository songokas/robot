#ifndef ROBOT_H
#define ROBOT_H

#include "motor.h"
#include "direction_control.h"

class Speed;

class Robot
{
  public:
    Robot(const Motor & motorA, const Motor & motorB, const DirectionControl & directionControl);
    void run(const Speed & speed);
    void turnAround(int degrees, const Speed & speed);
  private:
    Motor motorA;
    Motor motorB;
    DirectionControl directionControl;
};

#endif

