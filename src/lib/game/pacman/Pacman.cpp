/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Pacman.cpp
*/

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
    for (ushort x = 0; x < this->MAX_MAP_SIZE; ++x) {
        for (ushort y = 0; y < this->MAX_MAP_SIZE; ++y) {
            if (y == 0 || y == this->MAX_MAP_SIZE - 1 ||
                x == 0 || x == this->MAX_MAP_SIZE - 1)
                this->_map.emplace_back(
                    (static_cast<float>(x) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                    (static_cast<float>(y) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
        }
    }
    this->_state = GAME;
}

void Game::Pacman::handleEvent(std::string &name) {

}

void Game::Pacman::handleUpdate(int elapsedTime) {
    if (!IS_GAME_IN_PROGRESS(this))
        return;
    this->_player.elapsedTime += elapsedTime;
    if (this->_player.elapsedTime > 250) {
        Vector2f prev = this->_player.position.front();
        Vector2f next(0.f, 0.f);
        for (auto &iter: this->_player.position) {
            next = iter;
            iter.x = prev.x;
            iter.y = prev.y;
            prev = next;
        }
        switch (this->_player.direction) {
            case NORTH:
                this->_player.position.front().y -= DEFAULT_SQUARE_SIZE.y;
                break;
            case SOUTH:
                this->_player.position.front().y += DEFAULT_SQUARE_SIZE.y;
                break;
            case EAST:
                this->_player.position.front().x += DEFAULT_SQUARE_SIZE.x;
                break;
            case WEST:
                this->_player.position.front().x -= DEFAULT_SQUARE_SIZE.x;
                break;
            case IDLE:
                break;
        }
        this->_player.elapsedTime = 0;
    }
}

void Game::Pacman::setGameData(IGame::GameDataType &data) {
    // TODO: Score, XP, Death, lives, game state, etc.
    //  What's for?
    this->_data = data;
    this->_player.score = 54;
}

IGame::GameDataType Game::Pacman::getGameData() {
    this->_data["score"] = std::to_string(*this->_player.score);
    this->_data["death"] = std::to_string(this->_player.death);
    return (this->_data);
}
