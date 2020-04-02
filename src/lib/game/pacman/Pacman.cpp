/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Pacman.cpp
*/

#include <algorithm>
#include "Pacman.hpp"

static Game::Pacman *instance;

extern "C" {
    IGame *loadLibrary() {
        return (instance);
    }
    
    __attribute__((constructor)) void load() {
        printf("[game] constructor Pacman called\n");
        instance = new Game::Pacman();
    }
    
    __attribute__((destructor)) void unload() {
        printf("[game] destructor Pacman called\n");
        delete instance;
    }
}

Game::Pacman::Pacman() {
    this->generateMap();
    this->_state = GAME;
    this->_enemies.emplace_back(enemy_s(Vector2i(90, 80)));
    this->_enemies.emplace_back(enemy_s(Vector2i(85, 80)));
    this->_enemies.emplace_back(enemy_s(Vector2i(80, 80)));
    this->_enemies.emplace_back(enemy_s(Vector2i(75, 80)));
}

void Game::Pacman::handleEvent(std::string &name) {
    std::array<std::string, 8> keys = {
        // Default keys
        KeyboardEvent_s::UP,
        KeyboardEvent_s::DOWN,
        KeyboardEvent_s::RIGHT,
        KeyboardEvent_s::LEFT,

        KeyboardEvent_s::RESTART,
    };

    for (std::size_t i = 0, j = keys.size(); i < j; i++) {
        if (keys[i] != name)
            continue;
        if (i + 1 != j && IS_GAME_IN_PROGRESS(this)) {
            this->_player.direction = static_cast<Pacman::ENTITY_DIRECTION>(i);
            return;
        } else if (keys[i] == KeyboardEvent_s::RESTART){
            this->_state = GAME_STATE::GAME;
            //this->resetPlayer();
            return;
        }
    }
}

void Game::Pacman::handleUpdate(int elapsedTime) {
    if (!IS_GAME_IN_PROGRESS(this))
        return;
    this->_player.elapsedTime += elapsedTime;
    if (this->_player.elapsedTime > 250) {
        this->moveEntity(this->_player.position, this->_player.direction);
    }
    for (enemy_s &enemy : this->_enemies) {
        enemy.elapsedTime += elapsedTime;
        if (enemy.elapsedTime > 230)
            this->moveEnemy(enemy);
    }
}

void Game::Pacman::setGameData(IGame::GameDataType &data) {
    // TODO: Score, XP, Death, lives, game state, etc.
    //  What's for?
    this->_data = data;
}

IGame::GameDataType Game::Pacman::getGameData() {
    this->_data["score"] = std::to_string(this->_player.score);
    this->_data["death"] = std::to_string(this->_player.death);
    return (this->_data);
}
