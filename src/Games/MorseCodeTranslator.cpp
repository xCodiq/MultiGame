//
// Created by: Elmar Blume - 05/02/2025
//

#include "MorseCodeTranslator.h"

void MorseCodeTranslator::setup() {

}

bool MorseCodeTranslator::finished() {
    return Game::count == 10;
}

void MorseCodeTranslator::loop() {
}

void MorseCodeTranslator::end() {
    Serial.println("MorseCodeTranslator ended");
}
