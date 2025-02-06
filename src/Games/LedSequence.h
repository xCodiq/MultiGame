//
// Created by: Elmar Blume - 06/02/2025
//

#ifndef LEDSEQUENCE_H
#define LEDSEQUENCE_H

#include <Game.h>

class LedSequence final : public Game {
public:
    void setup() override;

    bool finished() override;

    void loop() override;

    void end() override;
};



#endif //LEDSEQUENCE_H
