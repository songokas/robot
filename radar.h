#ifndef RADAR_H
#define RADAR_H 

//@TODO makefile should load it without paths
#include "libs/Servo.h"
#include "libs/NewPing.h"

class Radar
{
    public:
        Radar(const NewPing & sonar, const Servo & engine);
        bool hasFrontObsticle();
        bool hasRighObsticle();
        bool hasLeftObsticle();
        int getDistance();
    private:
        bool hasObsticle();
        NewPing sonar;
        Servo engine;
};

#endif /* RADAR_H */
