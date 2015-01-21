#ifndef ROBOT_H
#define ROBOT_H

#include "motor.h"
#include "radar.h"
#include "sound_player.h"
#include "display.h"

#define DISTANCE_ARRAY 20

class Speed;

class Robot
{
  public:
    Robot(const Motor & motorA, const Motor & motorB, Radar & radar, SoundPlayer & soundPlayer, Display & display);
    void run(const Speed & speed);
    void turnAround(int degrees, const Speed & speed);
    void moveForward(const Speed & speed, int time);
    void moveBackward(const Speed & speed, int time);
    void moveLeft(const Speed & speed, int time);
    void moveRight(const Speed & speed, int time);
    void moveLeftBack(const Speed & speed, int time);
    void moveRightBack(const Speed & speed, int time);
    void off();
    enum State {
        MovingBack, MovingFront, Off, Stuck
    };

    bool isStuck() const;
  private:
    void move(const Speed & speed);
    void measurePath(int distance);
    void recordTime(int time);
    bool isMovingForRequiredTime();

    Motor motorA;
    Motor motorB;
    Radar & radar;
    SoundPlayer & soundPlayer;
    Display & display;
    State state;
    int distances[DISTANCE_ARRAY];
    byte index;
    unsigned long moveUntil;
};

#endif

