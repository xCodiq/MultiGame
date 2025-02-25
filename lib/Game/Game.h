//
// Created by: Elmar Blume - 05/02/2025
//

#ifndef GAME_H
#define GAME_H

// unused #include directives are not removed, as they are needed for Game implementations
#include <Arduino.h>
#include <Scheduler.h>
#include <Button.h>
#include <LCD.h>
#include <WPM.h>
#include <map>
#include <string>
#include <utility>

/**
 * Abstract class for a game
 */
class Game {
public:
    /**
     * Destructor of Game
     */
    virtual ~Game() = default;

    /**
     * Set up the game, called within the setup() function of the Arduino
     */
    virtual void setup() = 0;

    /**
     * @return true if the game is finished, false otherwise
     */
    virtual bool finished() = 0;

    /**
     * Loop the game, called within the loop() function of the Arduino
     */
    virtual void loop() = 0;

    /**
     * End the game, called when game is switched/finished
     */
    virtual void end() = 0;

    static unsigned int count;
};



#endif //GAME_H
