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

    this->drawPacGom(1, 1, 1, 17);
    this->drawPacGom(2, 1, 7, 1);
    this->drawPacGom(2, 4, 17, 1);
    this->drawPacGom(8, 2, 1, 2);
    this->drawPacGom(11, 1, 8, 1);
    this->drawPacGom(11, 2, 1, 2);
    this->drawPacGom(18, 2, 1, 2);
    this->drawPacGom(4, 5, 1, 2);
    this->drawPacGom(10, 5, 1, 2);
    this->drawPacGom(16, 5, 1, 2);
    this->drawPacGom(4, 7, 15, 1);
    this->drawPacGom(2, 12, 2, 1);
    this->drawPacGom(2, 17, 2, 1);
    this->drawPacGom(4, 10, 1, 8);
    this->drawPacGom(5, 10, 3, 1);
    this->drawPacGom(5, 13, 3, 1);
    this->drawPacGom(8, 8, 1, 6);
    this->drawPacGom(9, 12, 2, 1);
    this->drawPacGom(4, 16, 15, 1);
    this->drawPacGom(11, 8, 1, 8);
    this->drawPacGom(14, 8, 1, 8);
    this->drawPacGom(12, 13, 2, 1);
    this->drawPacGom(15, 13, 3, 1);
    this->drawPacGom(18, 13, 1, 3);
    this->drawPacGom(18, 8, 1, 3);
    this->drawPacGom(15, 10, 3, 1);

    this->drawSuperGom(2, 17,1,1);
}

void Game::Pacman::drawPacGom(int x, int y, int sizeX, int sizeY) {
    for (int i = 0; i < sizeY; ++i) {
        for (int z = 0; z < sizeX; ++z) {
            this->_pacGoms.emplace_back(
                (static_cast<float>(x + z) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                (static_cast<float>(y + i) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
        }
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

void Game::Pacman::drawSuperGom(int x, int y, int sizeX, int sizeY) {
    for (int i = 0; i < sizeY; ++i) {
        for (int z = 0; z < sizeX; ++z) {
            this->_superGoms.emplace_back(
                    (static_cast<float>(x + z) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                    (static_cast<float>(y + i) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
        }
    }
}
