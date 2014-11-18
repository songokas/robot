#ifndef DIRECTION_CONTROL_H
#define DIRECTION_CONTROL_H

#include "radar.h"

class DirectionControl
{
    public:
        DirectionControl(const Radar & radar);
        int getFrontDistance();
        int getRightDistance();
        int getLeftDistance();
        void setInterval(int interval);
        void run();
    private:
        Radar radar;
};

#endif
