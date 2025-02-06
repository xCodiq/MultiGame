//
// Created by: Elmar Blume - 05/02/2025
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <Game.h>
#include <map>
#include <unordered_map>
#include <memory>
#include <typeindex>

/**
 * Class to manage multiple m_games
 *
 * The following functions have inline definitions because they are template functions:
 * - GameManager::registerGame
 * - GameManager::getGame
 * - GameManager::switchGame
 *
 */
class GameManager {
public:
    explicit GameManager() = default;

    /**
     * Add a game to the manager
     * @param game_instance a pointer to the instance of the game
     */
    template<typename T>
    void registerGame(std::unique_ptr<T> game_instance) {
        static_assert(std::is_base_of_v<Game, T>, "T must be a subclass of Game");

        // Add the game to the map
        m_games[typeid(T)] = std::move(game_instance);

        // Call setup method
        m_games[typeid(T)]->setup();
    }

    /**
     * Get a game by type
     *
     * @return a pointer to the game instance if found, nullptr otherwise
     */
    template<typename T>
    [[nodiscard]] T *getGame() const {
        // Check if the game exists
        const auto it = m_games.find(typeid(T));
        if (it == m_games.end())
            return nullptr;

        // Cast the game to the correct type
        return dynamic_cast<T *>(it->second.get());
    }

    /**
     * Manually switch to a different game
     * @return true if the game was switched successfully, false otherwise
     */
    template<typename T>
    bool switchGame() {
        // Check if the game exists
        const auto &it = this->getGame<T>();
        if (it == nullptr)
            return false;

        // Teardown the current game if it exists
        if (this->m_current_game != nullptr)
            this->m_current_game->end();

        // Se the new game as the new current game
        this->m_current_game = it;

        return true;
    }

    /**
     * Register a transition between two games
     *
     * @tparam From the game to transition from
     * @tparam To  the game to transition to
     */
    template<typename From, typename To>
    void registerTransition() {
        this->m_transitions.insert_or_assign(
            std::type_index(typeid(From)),
            std::type_index(typeid(To))
        );
    }

    /**
     * Loops the current game if it exists
     */
    void loop() const;

    /**
     * Attempt to transition to the next game
     */
    void transition();

    /**
     * Get the current game
     *
     * @return a pointer to the current game
     */
    [[nodiscard]] Game *getCurrentGame() const;

private:
    std::unordered_map<std::type_index, std::unique_ptr<Game> > m_games;
    std::map<std::type_index, std::type_index> m_transitions;

    Game *m_current_game = nullptr;
};


#endif //GAMEMANAGER_H
