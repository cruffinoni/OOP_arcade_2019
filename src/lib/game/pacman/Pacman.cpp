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
        instance = new Game::Pacman();
    }
    
    __attribute__((destructor)) void unload() {
        delete instance;
    }
}

Game::Pacman::Pacman() {
    this->resetGame();
    this->_player.death = 0;
    this->_state = GAME_STATE::GAME;
}

void Game::Pacman::handleEvent(std::string &name) {
    std::array<std::string, 8> keys = {
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
        } else if (keys[i] == KeyboardEvent_s::RESTART) {
            this->_state = GAME_STATE::GAME;
            this->resetGame();
            return;
        }
    }
}

void Game::Pacman::resetGame() {
    srand(time(nullptr));
    this->_enemies.clear();
    this->_map.clear();
    this->_pacGoms.clear();
    this->_superGoms.clear();
    this->_player.score = 0;
    this->_player.death++;
    this->_player.position.x = 5;
    this->_player.position.y = 5;
    this->generateMap();
    this->_enemies.emplace_back(enemy_s(Vector2i(90, 5)));
    this->_enemies.emplace_back(enemy_s(Vector2i(5, 80)));
    this->_enemies.emplace_back(enemy_s(Vector2i(80, 80)));
    this->_enemies.emplace_back(enemy_s(Vector2i(75, 80)));
}

void Game::Pacman::handleUpdate(int elapsedTime) {
    if (!IS_GAME_IN_PROGRESS(this))
        return;
    this->_player.elapsedTime += elapsedTime;
    if (this->_player.elapsedTime > 250) {
        this->movePlayer();
    }
    if (this->_player.super) {
        if (this->_player.superTime >= 10000) {
            this->_player.superTime = 0;
            this->_player.super = false;
        } else {
            this->_player.superTime += elapsedTime;
        }
    }
    for (enemy_s &enemy : this->_enemies) {
        enemy.elapsedTime += elapsedTime;
        enemy.isEatable = this->_player.super;
        if (enemy.elapsedTime > 200)
            this->moveEnemy(enemy);
    }
}

void Game::Pacman::setGameData(IGame::GameDataType &data) {
    this->_data = data;
}

IGame::GameDataType Game::Pacman::getGameData() {
    this->_data["score"] = std::to_string(this->_player.score);
    this->_data["death"] = std::to_string(this->_player.death);
    return (this->_data);
}
