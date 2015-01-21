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
    servo.attach(9);
    servo.write(90);
    NewPing leftSonar(9, 10, SENSOR_MAX_RANGE);
    NewPing middleSonar(11, 12, SENSOR_MAX_RANGE);
    NewPing rightSonar(1, 2, SENSOR_MAX_RANGE);
    Radar radar(leftSonar, middleSonar, rightSonar);
    Sound sound(13);
    SoundPlayer soundPlayer(sound, radar);
    Motor motorA(4, 5, 3);
    Motor motorB(7, 8, 6);
    Display display;
    Robot robot(motorA, motorB, radar, soundPlayer, display);
    robot.run(Speed(95));
}

void loop()
{
    //Serial.print("left: ");
    //Serial.print(analogRead(A1));
    //Serial.print(" right: ");
    //Serial.println(analogRead(A0));
    //delay(1000);
}

//unable to overide this using setup as main
//int main(void)
//{

//} 
