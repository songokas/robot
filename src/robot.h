#ifndef ROBOT_H
#define ROBOT_H

#include "motor.h"
#include "radar.h"
#include "sound_player.h"
#include "display.h"

#define DISTANCE_ARRAY 10

class Speed;

class Robot
{
  public:
    Robot(const Motor & motorA, const Motor & motorB, Radar & radar, SoundPlayer & soundPlayer, Display & display);
    void run(const Speed & speed);
    void turnAround(int degrees, const Speed & speed);
    void moveForward(const Speed & speed);
    void moveBackward(const Speed & speed);
    void moveLeft(const Speed & speed);
    void moveRight(const Speed & speed);
    void moveLeftBack(const Speed & speed);
    void moveRightBack(const Speed & speed);
    void off();
    enum State {
        MovingBack, MovingFront, Off, Stuck
    };

    void measurePath(int distance);
    bool isStuck() const;
  private:
    void move(const Speed & speed);
    Motor motorA;
    Motor motorB;
    Radar & radar;
    SoundPlayer & soundPlayer;
    Display & display;
    State state;
    int distances[DISTANCE_ARRAY];
    byte index;
};

#endif

