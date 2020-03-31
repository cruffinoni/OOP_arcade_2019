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
    this->drawSquare(2, 5, 2, this->MAX_MAP_SIZE / 2 + 2);
    this->drawSquare(5, 5, this->MAX_MAP_SIZE / 4, 2);
    this->drawSquare(11, 5, this->MAX_MAP_SIZE / 4, 2);
    this->drawSquare(17, 5, 2, 2);
}

void Game::Pacman::drawLine(int x, int y, int size) {
    size = size + x;
    for (; x < size; ++x) {
        this->_map.emplace_back(
                (static_cast<float>(x) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                (static_cast<float>(y) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
    }
}

void Game::Pacman::drawColumn(int x, int y, int size) {
    size = size + y;
    for (; y < size; ++y) {
        this->_map.emplace_back(
                (static_cast<float>(x) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                (static_cast<float>(y) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
    }
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
