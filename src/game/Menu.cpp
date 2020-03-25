/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Menu.c - File used to handle menu
*/

#include "Core.hpp"

void Core::Core::menuEvents(std::string &event) {
    if (event == IEventIterator::KEY_UP) {
        this->_selectedGame = NIBBLER;
    }
    if (event == IEventIterator::KEY_DOWN) {
        this->_selectedGame = PACMAN;
    }
    if (event == IEventIterator::KEY_ENTER) {
        if (this->_selectedGame == NIBBLER) {
            this->_gameRunning = true;
        } else {
            std::cout << "Change game pacman" << std::endl;
            //this->useGame("");
        }
    }
}

void Core::Core::renderMenu() {
    this->_graphic->drawText(Text(std::string("Arcade"),
        {25.f, 3.f}, {50.f, 20.f}, Color::Green()));
    this->_graphic->drawRect(Rect({48.f, 25.f},
        {2.f, 70.f}, Color::Red()));
    this->_graphic->drawText(Text(std::string("Selection de jeu"),
        {7.f, 25.f}, {35.f, 15.f}, Color::White()));
    if (_selectedGame == NIBBLER) {
        this->_graphic->drawRect(Rect({10.f, 48.f},
            {25.f, 15.f}, Color::Red()));
    } else {
        this->_graphic->drawRect(Rect({10.f, 68.f},
            {25.f, 15.f}, Color::Red()));
    }
    this->_graphic->drawText(Text(std::string("Nibbler"),
        {12.f, 50.f}, {20.f, 10.f}, Color::White()));
    this->_graphic->drawText(Text(std::string("Pacman"),
        {12.f, 70.f}, {20.f, 10.f}, Color::White()));
}
