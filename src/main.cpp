#include "robot.h"
#include "speed.h"

#include <Servo.h>
#include <NewPing.h>
#include <Arduino.h>

// distance specified in cm
const unsigned int SENSOR_MAX_RANGE = 200;
const unsigned int BAUD_RATE = 9600;

void setup()
{
    Serial.begin(BAUD_RATE);
    Servo servo;
    servo.attach(12);
    NewPing sonar(11, 10, SENSOR_MAX_RANGE);
    Radar radar(sonar, servo);
    DirectionControl directionControl(radar);
    Motor motorA(6, 7, 3);
    Motor motorB(8, 9, 5);
    Robot robot(motorA, motorB, directionControl);
    while (true) {
        //if (!directionControl.canMoveForward()) {
            //robot.turn(Speed(20));
        //}
        //else {
            robot.run(Speed(70));
        //}
        delay(100);
    }
}

void loop()
{
}

//unable to overide this using setup as main
//int main(void)
//{

//} 
