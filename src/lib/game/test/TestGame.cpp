/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <iostream>
#include "TestGame.hpp"

static Game::TestGame *instance;

extern "C" {
    IGame *entry() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        printf("[game] constructor TestGame called\n");
        instance = new Game::TestGame();
    }

    __attribute__((destructor)) void unload() {
        printf("[game] destructor TestGame called\n");
        delete instance;
    }
}

void Game::TestGame::handleEvent(std::string &name) {
    //std::cout << "Function handleEvent called" << std::endl;
    std::cerr << "Event named \"" << name << "\" called" << std::endl;
}

void Game::TestGame::handleRender(IGraphicRenderer &renderer) {
    //std::cout << "Function handleRender called" << std::endl;
    renderer.drawRect(Rect {
        {50.f, 50.f},
        {10.f, 10.f},
        Color::Green(),
    });
    renderer.drawCircle(Circle {
        {25.f, 25.f},
        {5.f, 5.f},
        Color::Red(),
    });
    renderer.drawText(Text {
        "hello world",
        {75.f, 75.f},
        {10.f, 10.f},
        Color::Blue(),
    });
}

void Game::TestGame::handleUpdate(int elapsedTime) {
    this->_tick += elapsedTime;
    if (this->_tick > 250) {
        //std::cerr << "1 sec elapsed" << std::endl;
        this->_tick = 0;
    }
}

IGame::GameDataType Game::TestGame::getGameData() {
    return (this->_event);
}

void Game::TestGame::setGameData(IGame::GameDataType &data) {
    (void) data;
}
