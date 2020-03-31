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
    readMap();
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

void Game::Pacman::drawSquare(int x, int y, int size, int size2) {
    for (; x < 10; ++x) {
        for (; y < 10; ++y) {
                this->_map.emplace_back(
                        (static_cast<float>(x) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
                        (static_cast<float>(y) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
        }
    }
}

//void Game::Pacman::drawDiag(int size, int start) {
//    size = size + start;
//    for (; start < size; ++start) {
//        this->_map.emplace_back(
//                (static_cast<float>(size - start) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f,
//                (static_cast<float>(start) / static_cast<float>(this->MAX_MAP_SIZE)) * 100.f);
//    }
//}

//void Game::Pacman::pacGomeTEST() {
//
//}

void Game::Pacman::readMap() {
//    drawDiag(1, 5);
    drawSquare(5, 5, 10, 10);
//    drawLine(5, 5, 10);
//    drawColumn(5, 5, 10);
}