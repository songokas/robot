#include "direction_control.h"

DirectionControl::DirectionControl(const Radar & radar): radar(radar)
{}

int DirectionControl::getFrontDistance()
{
    return radar.getFrontDistance();
}

int DirectionControl::getRightDistance()
{
    return radar.getRightDistance();
}

int DirectionControl::getLeftDistance()
{
    return radar.getLeftDistance();
}

void DirectionControl::setInterval(int interval)
{
    radar.setInterval(interval);
}
 
void DirectionControl::run()
{
    if (radar.shouldRun()) radar.run();
}
