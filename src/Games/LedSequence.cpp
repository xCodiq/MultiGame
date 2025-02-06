//
// Created by: Elmar Blume - 06/02/2025
//

#include "LedSequence.h"

void LedSequence::setup() {
}

bool LedSequence::finished() {
    return Game::count == 30;
}

void LedSequence::loop() {
}

void LedSequence::end() {
    Serial.println("LedSequence ended");
}