/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <iostream>
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

Game::Nibbler::Nibbler() : _elapsedTime(0) {
    this->_player.emplace_back(50.f, 50.f);
    this->_direction = SOUTH;
    this->_data["xp"] = "0";
    this->_data["time"] = "0"; // (?)

    /*
     * TODO:
     * - Spawn les "rewards" pour faire grandir le snake
     * - Function pour ajouter une node au snake
     * - Hitbox
     * - Loose/Win conditions
     */

    for (ushort x = 0; x < this->MAX_MAP_SIZE; ++x) {
        for (ushort y = 0; y < this->MAX_MAP_SIZE; ++y) {
            if (y == 0 || y == this->MAX_MAP_SIZE - 1 ||
                x == 0 || x == this->MAX_MAP_SIZE - 1)
                this->_map.emplace_back(
                    (static_cast<float>(x) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                    (static_cast<float>(y) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
        }
    }
}

void Game::Nibbler::handleEvent(std::string &name) {
    std::string keys[] = {
        IEventIterator::KEY_UP,
        IEventIterator::KEY_DOWN,
        IEventIterator::KEY_RIGHT,
        IEventIterator::KEY_LEFT,
    };
    if (name == IEventIterator::KEY_A) {
        printf("[debug] add node to the snake\n");
        this->addNode();
        return;
    }
    for (std::size_t i = 0, j = keys->size(); i < j; i++) {
        if (keys[i] == name) {
            this->_direction = static_cast<Nibbler::PLAYER_DIRECTION>(i);
            return;
        }
    }
}

void Game::Nibbler::handleRender(IGraphicRenderer &renderer) {
    // TODO: Display the game thanks to the renderer

    Game::Nibbler::drawBackground(renderer);
    for (auto &node : this->_player) {
        renderer.drawRect(Rect{node, this->DEFAULT_SQUARE_SIZE, Color::Black()});
    }
    for (auto &mapNode : this->_map) {
        renderer.drawRect(Rect{mapNode, this->DEFAULT_SQUARE_SIZE, Color::Red()});
    }
}

void Game::Nibbler::handleUpdate(int elapsedTime) {
    this->_elapsedTime += elapsedTime;
    if (this->_elapsedTime > 1e+7) {
        //printf("1 sec elapsed\n");
        Vector2f prev = this->_player.front();
        Vector2f next(0.f, 0.f);
        for (auto &iter : this->_player) {
            next = iter;
            iter.x = prev.x;
            iter.y = prev.y;
            prev = next;
        }

        // TODO: Gérer le cas où le snake sort de la map
        switch (this->_direction) {
            case NORTH:
                this->_player.front().y -= DEFAULT_SQUARE_SIZE.y;
                break;
            case SOUTH:
                this->_player.front().y += DEFAULT_SQUARE_SIZE.y;
                break;
            case EAST:
                this->_player.front().x += DEFAULT_SQUARE_SIZE.x;
                break;
            case WEST:
                this->_player.front().x -= DEFAULT_SQUARE_SIZE.x;
                break;
        }
        //for (auto &node : this->_player) {
        //    printf("[%p] New pos: %f & %f\n", &node, node.x, node.y);
        //}
        this->_elapsedTime = 0;
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
    this->_player.emplace_back(this->_player.back());
}
