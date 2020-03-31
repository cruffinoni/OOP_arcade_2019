/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Map.cpp - File used to generate pacman map
*/

#include "Pacman.hpp"

void Game::Pacman::generateMap() {
    for (ushort x = 0; x < this->MAX_MAP_SIZE; ++x) {
        for (ushort y = 0; y < this->MAX_MAP_SIZE; ++y) {
            if (y == 0 || y == this->MAX_MAP_SIZE - 2 || x == 0 || x == this->MAX_MAP_SIZE - 1)
                this->_map.emplace_back(
                    (static_cast<float>(x) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                    (static_cast<float>(y) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
        }
    }
    this->drawSquare(this->MAX_MAP_SIZE / 2 - 1, 1, 2, 3);
    this->drawSquare(2, 2, this->MAX_MAP_SIZE / 3, 2);
    this->drawSquare(this->MAX_MAP_SIZE / 2 + 2, 2, this->MAX_MAP_SIZE / 3, 2);
    this->drawSquare(2, 5, 2, 7);
    this->drawSquare(2, 13, 2, 4);
    this->drawSquare(5, 5, this->MAX_MAP_SIZE / 4, 2);
    this->drawSquare(11, 5, this->MAX_MAP_SIZE / 4, 2);
    this->drawSquare(17, 5, 2, 2);
    this->drawSquare(4, 8, 4, 2);
    this->drawSquare(9, 8, 2, 4);
    this->drawSquare(9, 13, 2,1);
    this->drawSquare(5, 11, 3, 2);
    this->drawSquare(5, 14, 6, 2);
    this->drawSquare(5, 17, 14, 1);
    this->drawSquare(12, 8, 2, 5);
    this->drawSquare(15, 8, 3, 2);
    this->drawSquare(15, 11, 4, 2);
    this->drawSquare(15, 14, 3, 2);
    this->drawSquare(12, 14, 2, 2);
}

void Game::Pacman::drawSquare(int x, int y, int sizeX, int sizeY) {
    for (int i = 0; i < sizeY; ++i) {
        for (int z = 0; z < sizeX; ++z) {
            this->_map.emplace_back(
                (static_cast<float>(x + z) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                (static_cast<float>(y + i) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
        }
    }
}
