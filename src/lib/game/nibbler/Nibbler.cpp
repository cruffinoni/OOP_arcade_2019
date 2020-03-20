/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <algorithm>
#include <iostream>
#include <random>
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
    this->_data["score"] = "0";
    this->_data["time"] = "0";
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
    std::string keys[] = {
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
    for (std::size_t i = 0, j = keys->size(); i < j; i++) {
        if (keys[i] != name)
            continue;
        if (i < 4) {
            this->_player.direction = static_cast<Nibbler::PLAYER_DIRECTION>(i);
            return;
        } else {
            printf("[cheat] Key: %s w/ %lu\n", keys[i].c_str(), i);
            (this->*cheatsFunc[i - 4])();
            return;
        }
    }
}

void Game::Nibbler::handleRender(IGraphicRenderer &renderer) {
    Game::Nibbler::drawBackground(renderer);
    for (auto &node : this->_player.position) {
        renderer.drawRect(Rect{node, this->DEFAULT_SQUARE_SIZE, Color::Green()});
    }
    for (auto &mapNode : this->_map) {
        renderer.drawRect(Rect{mapNode, this->DEFAULT_SQUARE_SIZE, Color::Red()});
    }
    renderer.drawRect(Rect{
        this->_reward, this->DEFAULT_SQUARE_SIZE,
        Color::Blue()
    });
}

void Game::Nibbler::handleUpdate(int elapsedTime) {
    this->_player.elapsedTime += elapsedTime;
    if (this->_player.elapsedTime > 5e+6) {
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
        }
        if (this->_player.position.front() == this->_reward) {
            this->addNode();
            this->spawnReward();
        }
    }
}

void Game::Nibbler::setGameData(IGame::GameDataType &data) {
    // TODO: Score, XP, Death, lives, game state, etc.
}

IGame::GameDataType Game::Nibbler::getGameData() {
    return (this->_data);
}

void Game::Nibbler::drawBackground(IGraphicRenderer &renderer) {
    renderer.drawRect(Rect({
       {0.f, 0.f},
       {100.f, 100.f},
       Color::White()}));
}

void Game::Nibbler::addNode() {
    this->_score++;
    this->_player.position.emplace_back(this->_player.position.back());
}

void Game::Nibbler::resetPlayer() {
    this->_player.position.clear();
    this->_player.position.emplace_back(50.f, 50.f);
    this->_player.direction = SOUTH;
}

void Game::Nibbler::spawnReward() {
    std::uniform_real_distribution<float> distribution(DEFAULT_SQUARE_SIZE.x,
        100.f - DEFAULT_SQUARE_SIZE.y);
    std::random_device rd;
    std::default_random_engine generator(rd());
    double x = round(distribution(generator));
    double y = round(distribution(generator));
    this->_reward.x = static_cast<float>(round(x / 10.f) * 10.f);
    this->_reward.y = static_cast<float>(round(y / 10.f) * 10.f);
}
