#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
  public:
    Robot(const Engine & engine, const NewPing & forwardSonar);
    bool hasObsticle(int distance);
    void moveForward(int speed);
    void moveRight(int speed);
  private:
    Engine engine;
    NewPing forwardSonar;
};

#endif

