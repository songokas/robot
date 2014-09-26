#ifndef ENGINE_H
#define ENGINE_H

class DualEngine 
{
  public:
    DualEngine(int left1, int left2, int right1, int right2);
    void leftRightForward(int speed);
    void leftForward(int speed);
    void rightForward(int speed);
  private:
    void move(int l1, int l2, int r1, int r2);

    const int left1;
    const int left2;
    const int right1;
    const int right2;
};

#endif
