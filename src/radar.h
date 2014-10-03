#ifndef RADAR_H
#define RADAR_H 

#include <Servo.h>
#include <NewPing.h>

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
