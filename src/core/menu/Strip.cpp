/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <cstring>
#include "core/Core.hpp"

//mettre les explications dans une sorte de help dans le menu
// draw rect ???????

void Core::Core::createStripGame() {
    this->_graphic->drawRect(Rect{
        {0.0f, 95.f},
        {49.f, 5.f},
        Color::Blue(),
    });
    this->_graphic->drawRect(Rect{
        {49.f, 95.f},
        {100.f, 5.f},
        Color::Green(),
    });
    this->_graphic->drawText(Text {
        std::string("Game: " + Core::Core::getLibName(this->_game.getLibPath())),
        {0.f, 95.f},
        {5.f, 5.f},
        Color::White(),
    });

    this->_graphic->drawText(Text {
        "E: Next game  C: Previous game",
        {50.f, 95.f},
        {5.f, 5.f},
        Color::White(),
    });
}

void Core::Core::createStripMenu() {
    this->_graphic->drawRect(Rect{
        {0.0f, 95.f},
        {49.f, 5.f},
        Color::Blue(),
    });
    this->_graphic->drawRect(Rect{
        {49.f, 95.f},
        {100.f, 5.f},
        Color::Green(),
    });

    this->_graphic->drawText(Text {
        std::string("Current graphical lib: " +
                        Core::Core::getLibName(this->_graphic.getLibPath())),
        {0.f, 95.f},
        {5.f, 5.f},
        Color::White(),
    });

    this->_graphic->drawText(Text {
        "A: Next graphic lib  W: Previous graphic lib",
        {50.f, 95.f},
        {5.f, 5.f},
        Color::White(),
    });
}
