#ifndef RADAR_H
#define RADAR_H 

#include <NewPing.h>
#include <Thread.h>

class Radar: public Thread
{
    public:
        Radar(const NewPing & leftSonar, const NewPing & middleSonar, const NewPing & rightSonar);
        int getFrontDistance() const;
        int getRightDistance() const;
        int getLeftDistance() const;
        void run();

    private:
        NewPing leftSonar;
        NewPing middleSonar;
        NewPing rightSonar;
        int frontDistance;
        int leftDistance;
        int rightDistance;
};

#endif /* RADAR_H */
