#include "sound_player.h"

SoundPlayer::SoundPlayer(const Sound & sound, Radar & radar): sound(sound), radar(radar)
{}

void SoundPlayer::run()
{
    int distance = radar.getFrontDistance();
    int pitch = NOTE_A4;
    if (distance > 0) {
        if (distance < 10) {
            sound.playInterval(pitch, NOTE_G3, 100);
        } else if (distance < 20) {
            sound.playInterval(pitch, NOTE_G3, 200);
        } else if (distance < 30) {
            sound.playInterval(pitch, NOTE_G3, 300);
        } else if (distance < 50) {
            sound.playInterval(NOTE_G3, 400, 400);
        }    
    }
    //Serial.print("Distance: ");
    //Serial.println(distance);
    runned();
}
