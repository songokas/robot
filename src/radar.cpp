#include "radar.h"

Radar::Radar(const NewPing & leftSonar, const NewPing & middleSonar, const NewPing & rightSonar): 
    leftSonar(leftSonar), middleSonar(middleSonar), rightSonar(rightSonar)
{
    frontDistance = 0;
    leftDistance = 0;
    rightDistance = 0;
}

int Radar::getFrontDistance() const
{
    return frontDistance;
}

int Radar::getLeftDistance() const
{
    return leftDistance;
}

int Radar::getRightDistance() const
{
    return rightDistance;
}

void Radar::run()
{
    frontDistance = middleSonar.ping() / US_ROUNDTRIP_CM; 
    leftDistance = leftSonar.ping() / US_ROUNDTRIP_CM; 
    rightDistance = rightSonar.ping() / US_ROUNDTRIP_CM; 
    runned();
}

//bool Radar::getIrDistance(int pin)
//{
    //return analogRead(pin) > 500 ? true: false;
//}
