#include "display.h"

#include <Arduino.h>

#define OLED_RESET 4666456456

Display::Display(): screen(OLED_RESET)
{
    screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    screen.display();
    delay(1000);
    screen.clearDisplay();
    //screen.println("testing message");
    //screen.display();
    //delay(1000);

}

void Display::print(const char * message)
{
    screen.setTextSize(2);
    screen.setTextColor(WHITE);
    screen.setCursor(0,0);
    screen.println(message);
    screen.display();
    screen.clearDisplay();
}
