#ifndef RADAR_H
#define RADAR_H 

#include <Servo.h>
#include <NewPing.h>
#include <Thread.h>

class Radar: public Thread
{
    public:
        Radar(const NewPing & sonar, const Servo & engine);
        int getFrontDistance();
        int getRightDistance();
        int getLeftDistance();
        int getIrDistance(int pin);
        void run();

    private:
        //bool hasObsticle();
        int getDistance();
        NewPing sonar;
        Servo engine;

        int leftDistance;
        int frontDistance;
        int rightDistance;

};

#endif /* RADAR_H */
