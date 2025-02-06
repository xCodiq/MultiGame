//
// Created by: Elmar Blume - 06/02/2025
//

#include "VoltMatcher.h"

void VoltMatcher::setup() {
}

bool VoltMatcher::finished() {
    return Game::count == 20;
}

void VoltMatcher::loop() {
}

void VoltMatcher::end() {
    Serial.println("VoltMatcher ended");
}