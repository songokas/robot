#ifndef MOTOR_H
#define MOTOR_H 

class Speed;

class Motor 
{
  public:

    Motor(int directionPin1, int directionPin2, int speedPin);
    void forward(const Speed & speed);
    void backward(const Speed & speed);
    void off();
  private:
    const int directionPin1;
    const int directionPin2;
    const int speedPin;
};

#endif
