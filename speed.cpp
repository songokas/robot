#include "speed.h"   

#include <Arduino.h>

Speed::Speed(int speed): speedPersent(speed)
{}

int Speed::getEngineSpeed() const
{
    return map(speedPersent, 0, 100, 0, 255);
}
