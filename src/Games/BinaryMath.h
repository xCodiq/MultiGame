//
// Created by: Elmar Blume - 06/02/2025
//

#ifndef BINARYMATH_H
#define BINARYMATH_H

#include <Game.h>

class BinaryMath final : public Game {
public:
    void setup() override;

    bool finished() override;

    void loop() override;

    void end() override;
};


#endif //BINARYMATH_H
