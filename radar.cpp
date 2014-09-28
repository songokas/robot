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
    int distance = getDistance();
    if (distance > 50) {
        return true;
    }
    return false;
}
