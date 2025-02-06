//
// Created by: Elmar Blume - 06/02/2025
//

#include "BinaryMath.h"

void BinaryMath::setup() {
}

bool BinaryMath::finished() {
    return Game::count == 40;
}

void BinaryMath::loop() {
}

void BinaryMath::end() {
    Serial.println("BinaryMath ended");
}
