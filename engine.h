#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
  public:
    Engine(int left1, int left2, int right1, int right2);
    void leftRightForward(int speed);
    void leftForward(int speed);
    void rightForward(int speed);
  private:
    const int left1;
    const int left2;
    const int right1;
    const int right2;
};

#endif
