#include <NewPing.h>
#include "engine.h"
#include "robot.h"

Robot::Robot(const Engine & engine, const NewPing & forwardSonar)
  :engine(engine), forwardSonar(forwardSonar) 
{}

void Robot::moveForward(int speed)
{
    engine.leftRightForward(speed);
}

void Robot::moveRight(int speed)
{
    engine.leftForward(speed);
}

bool Robot::hasObsticle(int distance)
{
    int toObsticle = forwardSonar.ping() / US_ROUNDTRIP_CM;
    return toObsticle < distance;
}
