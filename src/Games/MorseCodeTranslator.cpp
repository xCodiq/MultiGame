//
// Created by: Elmar Blume - 05/02/2025
//

#include "MorseCodeTranslator.h"

#include <TM1638plus.h>

#define  STROBE_TM 4
#define  CLOCK_TM 6
#define  DIO_TM 7
TM1638plus tm(STROBE_TM, CLOCK_TM, DIO_TM, false);

MorseCodeTranslator::MorseCodeTranslator(Scheduler &scheduler, LCD &lcd) : m_scheduler(scheduler), m_lcd(lcd) {
    // Fill the morse code map
    this->m_morse_code_map['A'] = ".-";
    this->m_morse_code_map['B'] = "-...";
    this->m_morse_code_map['C'] = "-.-.";
    this->m_morse_code_map['D'] = "-..";
    this->m_morse_code_map['E'] = ".";
    this->m_morse_code_map['F'] = "..-.";
    this->m_morse_code_map['G'] = "--.";
    this->m_morse_code_map['H'] = "....";
    this->m_morse_code_map['I'] = "..";
    this->m_morse_code_map['J'] = ".---";
    this->m_morse_code_map['K'] = "-.-";
    this->m_morse_code_map['L'] = ".-..";
    this->m_morse_code_map['M'] = "--";
    this->m_morse_code_map['N'] = "-.";
    this->m_morse_code_map['O'] = "---";
    this->m_morse_code_map['P'] = ".--.";
    this->m_morse_code_map['Q'] = "--.-";
    this->m_morse_code_map['R'] = ".-.";
    this->m_morse_code_map['S'] = "...";
    this->m_morse_code_map['T'] = "-";
    this->m_morse_code_map['U'] = "..-";
    this->m_morse_code_map['V'] = "...-";
    this->m_morse_code_map['W'] = ".--";
    this->m_morse_code_map['X'] = "-..-";
    this->m_morse_code_map['Y'] = "-.--";
    this->m_morse_code_map['Z'] = "--..";
}

void MorseCodeTranslator::setup() {
    // tm.displayBegin(); tm.reset();
}

bool MorseCodeTranslator::finished() {
    return false;
}

void MorseCodeTranslator::loop() {
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
