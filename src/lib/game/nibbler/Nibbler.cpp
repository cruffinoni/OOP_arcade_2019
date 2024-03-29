/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Mainfile for Nibbler game
*/

#include <algorithm>
#include <iostream>
#include <random>
#include <array>
#include "Nibbler.hpp"

static Game::Nibbler *instance;

extern "C" {
    IGame *entry() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        instance = new Game::Nibbler();
    }

    __attribute__((destructor)) void unload() {
        delete instance;
    }
}

Game::Nibbler::Nibbler() : _reward(50.f, 50.f), _state(Nibbler::GAME_STATE::GAME) {
    this->resetPlayer();

    for (ushort x = 0; x < this->MAX_MAP_SIZE; ++x) {
        for (ushort y = 0; y < this->MAX_MAP_SIZE; ++y) {
            if (y == 0 || y == this->MAX_MAP_SIZE - 1 ||
                x == 0 || x == this->MAX_MAP_SIZE - 1)
                this->_map.emplace_back(
                    (static_cast<float>(x) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                    (static_cast<float>(y) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
        }
    }
    this->spawnReward();
}

void Game::Nibbler::handleEvent(std::string &name) {
    std::array<std::string, 6> keys = {
        KeyboardEvent_s::UP,
        KeyboardEvent_s::DOWN,
        KeyboardEvent_s::RIGHT,
        KeyboardEvent_s::LEFT,

        KeyboardEvent_s::RESTART,
        KeyboardEvent_s::ESC,
    };

    for (std::size_t i = 0, j = keys.size(); i < j; i++) {
        if (keys[i] != name)
            continue;
        if (i < 4 && IS_GAME_IN_PROGRESS(this)) {
            uint mask = (1u << i) | (1u << this->_player.direction);
            if ((mask == 0b1100u || mask == 0b11u) && this->_player.position.size() > 1)
                return;
            this->_player.direction = static_cast<Nibbler::PLAYER_DIRECTION>(i);
            return;
        } else if (keys[i] == KeyboardEvent_s::RESTART || keys[i] == KeyboardEvent_s::ESC) {
            this->_state = GAME_STATE::GAME;
            this->resetPlayer();
            return;
        }
    }
}

void Game::Nibbler::handleUpdate(int elapsedTime) {
    //printf("Elapsed time: %i / %i = %li\n", elapsedTime, IS_GAME_IN_PROGRESS(this), this->_player.elapsedTime);
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
        }
        this->_player.elapsedTime = 0;
        Vector2f head = this->_player.position.front();
        if (head.x >= (100.f - DEFAULT_SQUARE_SIZE.x) ||
            head.y >= (100.f - DEFAULT_SQUARE_SIZE.y) ||
            head.x < DEFAULT_SQUARE_SIZE.x ||
            head.y < DEFAULT_SQUARE_SIZE.y ||
            std::count(this->_player.position.begin(), this->_player.position.end(), head) > 1) {
            this->_player.death++;
            this->_state = Nibbler::GAME_STATE::SCORE;
        }
        if (this->_player.position.front() == this->_reward) {
            this->addNode();
            this->spawnReward();
        }
    }
}

void Game::Nibbler::setGameData(IGame::GameDataType &data) {
    this->_data = data;
}

IGame::GameDataType Game::Nibbler::getGameData() {
    this->_data["score"] = std::to_string(this->_player.score);
    this->_data["death"] = std::to_string(this->_player.death);
    return (this->_data);
}

void Game::Nibbler::addNode() {
    this->_player.score++;
    this->_player.position.emplace_back(this->_player.position.back());
}

void Game::Nibbler::resetPlayer() {
    this->_player.position.clear();
    this->_player.score = 0;
    this->_player.position.emplace_back(50.f, 50.f);
    this->_player.direction = SOUTH;
}

void Game::Nibbler::spawnReward() {
    std::uniform_real_distribution<float> distribution(DEFAULT_SQUARE_SIZE.x * 2,
        100.f - DEFAULT_SQUARE_SIZE.y);
    std::random_device rd;
    std::default_random_engine generator(rd());
    double x = floor(distribution(generator));
    double y = floor(distribution(generator));
    this->_reward.x = static_cast<float>(floor(x / 10.f) * 10.f);
    this->_reward.y = static_cast<float>(floor(y / 10.f) * 10.f);
    if (std::count(this->_player.position.begin(), this->_player.position.end(), this->_reward) > 0)
        this->spawnReward();
}
