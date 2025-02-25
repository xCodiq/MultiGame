//
// Created by: Elmar Blume - 06/02/2025
//

#ifndef BINARYMATH_H
#define BINARYMATH_H

#include <Game.h>

/**
 * BinaryMath
 *
 * A game where the player has to solve simple binary math problems, on a timer.
 * The game will display 2 binary numbers that the player has to add together.
 *
 * The player has to put in the answer on the TM1638 keypad, which displays it on the whadda segments.
 */
class BinaryMath final : public Game {
public:
    /**
    * Creates a new {@link BinaryMath} instance
    *
    * @param wpm the {@link WPM} instance
    */
    explicit BinaryMath(WPM &wpm);

    // Overridden from Game
    void setup() override;

    // Overridden from Game
    bool finished() override;

    // Overridden from Game
    void loop() override;

    // Overridden from Game
    void end() override;

private:
    WPM &m_wpm;
};


#endif //BINARYMATH_H
