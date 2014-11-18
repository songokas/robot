#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include "sound.h"
#include "radar.h"
#include <Thread.h>

class SoundPlayer: public Thread
{
    public:
        SoundPlayer(const Sound & sound, Radar & radar);
        void run();
    private:
        Sound sound;
        Radar & radar;
};

#endif /* SOUND_PLAYER_H */
