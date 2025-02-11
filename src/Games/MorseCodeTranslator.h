//
// Created by: Elmar Blume - 05/02/2025
//

#ifndef MORSECODETRANSLATOR_H
#define MORSECODETRANSLATOR_H

#include <Game.h>

class MorseCodeTranslator final : public Game {
public:
    /**
     * Creates a new {@link MorseCodeTranslator} instance
     *
     * @param scheduler the {@link Scheduler} instance
     * @param lcd the {@link LCD} instance
     */
    explicit MorseCodeTranslator(Scheduler &scheduler, LCD &lcd);

    // Overridden from Game
    void setup() override;

    // Overridden from Game
    bool finished() override;

    // Overridden from Game
    void loop() override;

    // Overridden from Game
    void end() override;

private:
    // char -> morse code string
    std::map<char, std::string> m_morse_code_map{};

    // Reference instances
    Scheduler &m_scheduler;
    LCD &m_lcd;
};



#endif //MORSECODETRANSLATOR_H
