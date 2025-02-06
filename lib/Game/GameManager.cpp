//
// Created by: Elmar Blume - 06/02/2025
//

#include "GameManager.h"

Game *GameManager::getCurrentGame() const {
    return this->m_current_game;
}

void GameManager::loop() const {
    // Check if there is a current game
    if (!this->m_current_game) return;

    // Loop the current game
    this->m_current_game->loop();
}

void GameManager::transition() {
    // Check if there is a current game to transition from
    if (!this->m_current_game) return;

    // Check if the current game is finished
    if (!this->m_current_game->finished()) return;

    // Check if there is a transition for the current game
    const auto transition = this->m_transitions.find(typeid(*this->m_current_game));
    if (transition == this->m_transitions.end()) return;

    // Get the next game, and check if it is available
    const auto nextGame = this->m_games.find(transition->second);
    if (nextGame == this->m_games.end()) return;

    // Switch games
    this->m_current_game->end();
    this->m_current_game = nextGame->second.get();
}
