//
// Created by: Elmar Blume - 05/02/2025
//

#ifndef MORSECODETRANSLATOR_H
#define MORSECODETRANSLATOR_H

#include <Game.h>

class MorseCodeTranslator final : public Game {
public:
    void setup() override;

    bool finished() override;

    void loop() override;

    void end() override;
};



#endif //MORSECODETRANSLATOR_H
