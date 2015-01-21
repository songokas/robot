#ifndef DISPLAY_H
#define DISPLAY_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Radar;

class Display
{
public:
    Display();
    void print(const char * message);
    void print(const Radar & radar);
private:
    Adafruit_SSD1306 screen;
};

#endif /* DISPLAY_H */
