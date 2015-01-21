#include "sound.h"

#include <Arduino.h>

Sound::Sound(int pin): pin(pin), songDuration(0)
{
}

void Sound::play(unsigned int frequency, unsigned long duration)
{
    //tone(pin, frequency, duration);
    songDuration = millis() + duration;
}

bool Sound::isPlaying() const
{
    if (millis() < songDuration) {
        return true;
    }
    return false;
}

void Sound::playInterval(unsigned int frequency, unsigned long duration, unsigned long interval)
{
    if (songDuration + interval < millis() && songDuration + (2 * interval) > millis()) {
        //noTone(pin);
    } else {
        if (!isPlaying()) {
            //play(frequency, duration);
        }
    }
}


