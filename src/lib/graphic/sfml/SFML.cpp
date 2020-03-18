/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "SFML.hpp"

static Graphic::SFML *instance;

extern "C" {
    IGraphicRenderer *loadLibrary() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        printf("constructor SFML called\n");
        instance = new Graphic::SFML();
    }

    __attribute__((destructor)) void unload() {
        printf("destructor SFML called\n");
        delete instance;
    }
}

Graphic::SFML::SFML() : _events(nullptr) {
    this->_window = new sf::RenderWindow({800, 600}, "Arcade");
}

Graphic::SFML::~SFML() {
    printf("delete constructor\n");
    delete this->_window;
}

void Graphic::SFML::clearScreen() {
    this->_window->clear();
}

void Graphic::SFML::drawCircle(Circle circle) {
    // TODO: ...
}

void Graphic::SFML::drawRect(Rect rect) {
    // TODO: ...
}

void Graphic::SFML::drawScreen() {
    // TODO: ...
}

void Graphic::SFML::drawSprite(Sprite sprite) {
    // TODO: ...
}

void Graphic::SFML::drawText(Text text) {
    // TODO: ...
}

std::string Graphic::SFML::handleEvent() {
    return ("unknown");
}

bool Graphic::SFML::isOperational() {
    return false;
}
