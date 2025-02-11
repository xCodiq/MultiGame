//
// Created by: Elmar Blume - 05/02/2025
//

#include "MorseCodeTranslator.h"

#include <TM1638plus.h>

#define  STROBE_TM 4 // strobe = GPIO connected to strobe line of module
#define  CLOCK_TM 6  // clock = GPIO connected to clock line of module
#define  DIO_TM 7 // data = GPIO connected to data line of module

bool high_freq = false; //default false, If using a high freq CPU > ~100 MHZ set to true.

// Constructor object (GPIO STB , GPIO CLOCK , GPIO DIO, use high freq MCU)
TM1638plus tm(STROBE_TM, CLOCK_TM, DIO_TM, high_freq);

void MorseCodeTranslator::setup() {
    tm.displayBegin(); // Initialise display module
    tm.reset(); // Clear the display
}

bool MorseCodeTranslator::finished() {
    return false;
    // return Game::count == 10;
}

void MorseCodeTranslator::loop() {
    tm.displayText("hllo.wrld");
}

void MorseCodeTranslator::end() {
    Serial.println("MorseCodeTranslator ended");
}

/*
static unsigned long lastTime = 0;
static int state = 0;
static int i = 0;

unsigned long currentTime = millis();

switch (state) {
    case 0:
        if (i < 8) {
            tm.setLED(i, 1);
            tm.displayASCII(i, '-');
            lastTime = currentTime;
            state = 1;
        } else {
            i = 6;
            state = 2;
        }
        break;
    case 1:
        if (currentTime - lastTime >= 100) {
            tm.displayASCII(i, ' ');
            tm.setLED(i, 0);
            i++;
            state = 0;
        }
        break;
    case 2:
        if (i > 0) {
            tm.setLED(i, 1);
            tm.displayASCII(i, '-');
            lastTime = currentTime;
            state = 3;
        } else {
            i = 0;
            state = 4;
        }
        break;
    case 3:
        if (currentTime - lastTime >= 100) {
            tm.displayASCII(i, ' ');
            tm.setLED(i, 0);
            i--;
            state = 2;
        }
        break;
    case 4:
        if (i < 8) {
            tm.setLED(i, 1);
            tm.displayASCIIwDot(i, '0' + i);
            lastTime = currentTime;
            state = 5;
        } else {
            tm.reset();
            i = 0;
            state = 6;
        }
        break;
    case 5:
        if (currentTime - lastTime >= 500) {
            i++;
            state = 4;
        }
        break;
    case 6:
        if (i < 10000000) {
            tm.displayIntNum(millis(), true);
            i++;
        } else {
            tm.displayText("Velleman");
            lastTime = currentTime;
            state = 7;
        }
        break;
    case 7:
        if (currentTime - lastTime >= 2000) {
            tm.reset();
            tm.displayText("Whadda");
            lastTime = currentTime;
            state = 8;
        }
        break;
    case 8:
        if (currentTime - lastTime >= 2000) {
            tm.reset();
            state = 0;
            i = 0;
        }
        break;
}
*/
