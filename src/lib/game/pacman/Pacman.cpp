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

}

void Game::Pacman::handleEvent(std::string &name) {

}

void Game::Pacman::handleUpdate(int elapsedTime) {

}

void Game::Pacman::setGameData(IGame::GameDataType &data) {

}

IGame::GameDataType Game::Pacman::getGameData() {
}
