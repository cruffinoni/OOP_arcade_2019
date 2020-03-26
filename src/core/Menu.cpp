/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Menu.c - File used to handle menu
*/

#include "Core.hpp"

std::string getGameName(std::string &libName) {
    int start = 0;
    int len = 0;
    int i = 0;
    std::string gameName;

    for (start = libName.length(); start > -1 && libName[start] != '_'; --start);
    if (start <= 0) {
        //TODO: throw here out of bounds
    }
    for (i = start; libName[i] != '.' && libName[i]; ++i, ++len);
    if (libName[i] == '\0') {
        //TODO: throw here out of bounds
    }
    gameName.append(libName, start + 1, len - 1);
    if (gameName[0] >= 'a' && gameName[0] <= 'z')
        gameName[0] -= 32;
    return (gameName);
}

void Core::Core::menuEvents(std::string &event) {
    unsigned short i = 0;

    if (event == IEventIterator::KEY_UP) {
        if (this->_gameSelected == 0)
            this->_gameSelected = this->_lib["games"].size() - 1;
        else
            this->_gameSelected--;
    }
    if (event == IEventIterator::KEY_DOWN) {
        if (this->_gameSelected == this->_lib["games"].size() - 1)
            this->_gameSelected = 0;
        else
            this->_gameSelected++;
    }
    if (event == IEventIterator::KEY_ENTER) {
        for (std::string &libName : this->_lib["games"]) {
            if (i == _gameSelected) {
                this->useGame(libName);
                this->_gameRunning = true;
                return;
            }
            ++i;
        }
    }
}

void Core::Core::renderMenu() {
    Vector2f textPos(12.f, 50.f);
    Vector2f selectPos(8.f,47.f + static_cast<float>(20 * _gameSelected));

    this->_graphic->drawText(Text(std::string("Arcade"),
        {25.f, 3.f}, {50.f, 20.f}, Color::Green()));
    this->_graphic->drawRect(Rect({48.f, 25.f},
        {2.f, 70.f}, Color::Red()));
    this->_graphic->drawText(Text(std::string("Selection de jeu"),
        {7.f, 25.f}, {35.f, 15.f}, Color::White()));
    this->_graphic->drawRect(Rect(selectPos,
        {26, 16}, Color::Red()));
    for (auto &libName : this->_lib["games"]) {
        std::string gameName = getGameName(libName);
        this->_graphic->drawText(Text(std::string(gameName),
            textPos, {20.f, 10.f}, Color::White()));
        textPos.y += 20;
    }
}
