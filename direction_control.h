#ifndef DIRECTION_CONTROL_H
#define DIRECTION_CONTROL_H

#include "radar.h"

class Speed;

class DirectionControl
{
    public:
        DirectionControl(const Radar & radar);
        const Speed getLeftSpeed(const Speed & speed);
        const Speed getRightSpeed(const Speed & speed);
    private:
        Radar radar;
};

#endif
