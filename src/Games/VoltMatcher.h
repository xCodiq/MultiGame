//
// Created by: Elmar Blume - 06/02/2025
//

#ifndef VOLTMATCHER_H
#define VOLTMATCHER_H

#include <Game.h>

class VoltMatcher final : public Game {
public:
    void setup() override;

    bool finished() override;

    void loop() override;

    void end() override;
};



#endif //VOLTMATCHER_H
