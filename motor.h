#ifndef MOTOR_H
#define MOTOR_H 

class Speed;

class Motor 
{
  public:

    Motor(int directionPin, int speedPin);
    void forward(const Speed & speed);
    void backward(const Speed & speed);
  private:
    const int directionPin;
    const int speedPin;
};

#endif
