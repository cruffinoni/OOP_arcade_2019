/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "core/Core.hpp"

static const Vector2f DEFAULT_STRIP_TEXT_SIZE = {30.f, 5.f};

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
        DEFAULT_STRIP_TEXT_SIZE,
        Color::White(),
    });

    this->_graphic->drawText(Text {
        std::string("Player: '" + this->_score.getAuthor() + "'"),
        {50.f, 95.f},
        DEFAULT_STRIP_TEXT_SIZE,
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
        DEFAULT_STRIP_TEXT_SIZE,
        Color::White(),
    });

    this->_graphic->drawText(Text {
        "A: Next graphic lib  W: Previous graphic lib",
        {50.f, 95.f},
        DEFAULT_STRIP_TEXT_SIZE,
        Color::White(),
    });
}
