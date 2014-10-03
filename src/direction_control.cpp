#include "direction_control.h"
#include "speed.h"

DirectionControl::DirectionControl(const Radar & radar): radar(radar)
{}

const Speed DirectionControl::getLeftSpeed(const Speed & speed)
{
    if (radar.hasFrontObsticle()) {
        if (!radar.hasRighObsticle() && radar.hasLeftObsticle()) {
            return speed + Speed(15);
        }
    }
    return speed;
}

const Speed DirectionControl::getRightSpeed(const Speed & speed)
{
    if (radar.hasFrontObsticle()) {
        if (!radar.hasLeftObsticle() && radar.hasRighObsticle()) {
            return speed + Speed(15);
        }
    }
    return speed;
}
