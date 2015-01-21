#include "display.h"
#include "radar.h"

#include <Arduino.h>

#define OLED_RESET 4666456456

Display::Display(): screen(OLED_RESET)
{
    screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    screen.display();
    delay(1000);
    screen.clearDisplay();
}

void Display::print(const char * message)
{
    screen.clearDisplay();
    screen.setTextSize(2);
    screen.setTextColor(WHITE);
    screen.setCursor(0,0);
    screen.println(message);
    screen.display();
}

void Display::print(const Radar & radar)
{
    screen.clearDisplay();
    screen.setTextSize(2);
    screen.setTextColor(WHITE);
    screen.setCursor(0,0);
    screen.print("Front:");
    screen.println(radar.getFrontDistance());
    screen.print("Left:");
    screen.println(radar.getLeftDistance());
    screen.print("Right:");
    screen.println(radar.getRightDistance());
    screen.display();
}
