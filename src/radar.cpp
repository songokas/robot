#include "radar.h"

Radar::Radar(const NewPing & sonar, const Servo & engine): sonar(sonar), engine(engine)
{}

int Radar::getDistance()
{
    return sonar.ping() / US_ROUNDTRIP_CM;
}

bool Radar::hasFrontObsticle()
{
    engine.write(90);
    return hasObsticle();
}

bool Radar::hasLeftObsticle()
{
    engine.write(30);
    return hasObsticle();
}

bool Radar::hasRighObsticle()
{
    engine.write(150);
    return hasObsticle();
}

bool Radar::hasObsticle()
{
    delay(200);
    int distance = getDistance();
    Serial.print("Distance to target: ");
    Serial.print(distance);
    Serial.print("Angle: ");
    Serial.println(engine.read());

    //distance 0 means unable to get distance
    if (distance == 0) {
        return false;
    }
    if (distance < 50) {
        return true;
    }
    return false;
}
