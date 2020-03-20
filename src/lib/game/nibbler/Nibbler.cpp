/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <algorithm>
#include <iostream>
#include <random>
#include <array>
#include "Nibbler.hpp"

static Game::Nibbler *instance;

extern "C" {
    IGame *loadLibrary() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        printf("[game] constructor Nibbler called\n");
        instance = new Game::Nibbler();
    }

    __attribute__((destructor)) void unload() {
        printf("[game] destructor Nibbler called\n");
        delete instance;
    }
}

Game::Nibbler::Nibbler() : _reward(50.f, 50.f) {
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
    std::array<std::string, 7> keys = {
        // Default keys
        IEventIterator::KEY_UP,
        IEventIterator::KEY_DOWN,
        IEventIterator::KEY_RIGHT,
        IEventIterator::KEY_LEFT,
        // Cheats
        IEventIterator::KEY_A,
        IEventIterator::KEY_B,
        IEventIterator::KEY_R,
    };
    void (Game::Nibbler::*cheatsFunc[])() = {
        &Game::Nibbler::addNode,
        &Game::Nibbler::spawnReward,
        &Game::Nibbler::resetPlayer,
    };

    for (std::size_t i = 0, j = keys.size(), middle = (keys.size() + 1) / 2; i < j; i++) {
        if (keys[i] != name)
            continue;
        if (i < middle) {
            this->_player.direction = static_cast<Nibbler::PLAYER_DIRECTION>(i);
            return;
        } else {
            printf("[nibbler] Cheat with the key %s activated\n", keys[i].c_str());
            (this->*cheatsFunc[i - middle])();
            return;
        }
    }
}

void Game::Nibbler::handleRender(IGraphicRenderer &renderer) {
    Game::Nibbler::drawBackground(renderer);
    std::size_t count = 0;

    for (auto &node : this->_player.position) {
        if (count++ % 2 == 0) {
            renderer.drawRect(Rect {
                node,
                this->DEFAULT_SQUARE_SIZE,
                Game::Nibbler::SNAKE_COLOR_1,
            });
        } else {
            renderer.drawRect(Rect {
                node,
                this->DEFAULT_SQUARE_SIZE,
                Game::Nibbler::SNAKE_COLOR_2,
            });
        }
    }
    for (auto &mapNode : this->_map) {
        renderer.drawRect(Rect {
            mapNode,
            this->DEFAULT_SQUARE_SIZE,
            Game::Nibbler::WALL_COLOR,
        });
    }
    renderer.drawRect(Rect {
        this->_reward,
        this->DEFAULT_SQUARE_SIZE,
        Game::Nibbler::REWARD_COLOR,
    });
    renderer.drawText(Text {
        std::string("Score: " + std::to_string(this->_player.score)),
        {45.f, 0.f},
        {10.f, 5.f},
        Color::Black(),
    });
}

void Game::Nibbler::handleUpdate(int elapsedTime) {
    this->_player.elapsedTime += elapsedTime;
    if (this->_player.elapsedTime > 1e+6) {
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
        if (this->_player.position.front().x >= (100.f - DEFAULT_SQUARE_SIZE.x) ||
            this->_player.position.front().y >= (100.f - DEFAULT_SQUARE_SIZE.y) ||
            this->_player.position.front().x < DEFAULT_SQUARE_SIZE.x ||
            this->_player.position.front().y < DEFAULT_SQUARE_SIZE.y ||
            std::count(this->_player.position.begin(), this->_player.position.end(), this->_player.position.front()) > 1) {
            this->resetPlayer();
            this->_player.death++;
        }
        if (this->_player.position.front() == this->_reward) {
            this->addNode();
            this->spawnReward();
        }
    }
}

void Game::Nibbler::setGameData(IGame::GameDataType &data) {
    // TODO: Score, XP, Death, lives, game state, etc.
    //  What's for?
    this->_data = data;
}

IGame::GameDataType Game::Nibbler::getGameData() {
    this->_data["score"] = std::to_string(this->_player.score);
    this->_data["death"] = std::to_string(this->_player.death);
    return (this->_data);
}

void Game::Nibbler::drawBackground(IGraphicRenderer &renderer) {
    renderer.drawRect(Rect({
       {0.f, 0.f},
       {100.f, 100.f},
       Color::White()
    }));
}

void Game::Nibbler::addNode() {
    this->_player.score++;
    this->_player.position.emplace_back(this->_player.position.back());
}

void Game::Nibbler::resetPlayer() {
    this->_player.position.clear();
    this->_player.position.emplace_back(50.f, 50.f);
    this->_player.direction = SOUTH;
    this->_player.score = 0;
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
