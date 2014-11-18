#include "radar.h"

Radar::Radar(const NewPing & sonar, const Servo & engine): sonar(sonar), engine(engine)
{
    leftDistance = 0;
    frontDistance = 0;
    rightDistance = 0;
    //engine.write(90);
}

int Radar::getDistance()
{
    return sonar.ping() / US_ROUNDTRIP_CM;
}

int Radar::getFrontDistance()
{
    return frontDistance;
    //engine.write(90);
    //return getDistance();
}

int Radar::getLeftDistance()
{
    return leftDistance;
    //engine.write(30);
    //return getDistance();
}

int Radar::getRightDistance()
{
    return rightDistance;
    //engine.write(150);
    //return getDistance();
}

void Radar::run()
{
    int distance = getDistance();
    frontDistance = distance;
    leftDistance = getIrDistance(A1);
    rightDistance = getIrDistance(A0);
    //int angle = engine.read();
    //if (angle > 0 && angle <= 60) {
        //rightDistance = distance;
    //} else if (angle > 60 && angle <= 120) {
        //frontDistance = distance;
    //} else {
        //leftDistance = distance;
    //}
    //int newAngle = angle;// + 60;
    //if (newAngle > 150) {
        //newAngle = 30;
    //}
    //engine.write(newAngle);
    runned();
}

int Radar::getIrDistance(int pin)
{
    return analogRead(pin) > 500 ? 50 : 10;
}
