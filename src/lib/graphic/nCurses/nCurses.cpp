/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "nCurses.hpp"

static Graphic::nCurses *instance;

extern "C" {
IGraphicRenderer *loadLibrary() {
//    return (instance);
}

__attribute__((constructor)) void load() {
    printf("constructor nCurses called\n");
    instance = new Graphic::nCurses();
}

__attribute__((destructor)) void unload() {
    printf("destructor nCurses called\n");
    delete instance;
}
}

Graphic::nCurses::nCurses() {
//    this->_window = new sf::RenderWindow({800, 600}, "Arcade");
}

Graphic::nCurses::~nCurses() {
    printf("delete constructor\n");
    //delete this->_window;
}

void Graphic::nCurses::clearScreen() {
//    this->_window->clear();
}

void Graphic::nCurses::drawCircle(Circle circle) {
    Vector2f a(4.5, 63.1);
    // TODO: ...
}

void Graphic::nCurses::drawRect(Rect rect) {
    // TODO: ...
}

void Graphic::nCurses::drawScreen() {
    // TODO: ...
}

void Graphic::nCurses::drawSprite(Sprite sprite) {
    // TODO: ...
}

void Graphic::nCurses::drawText(Text text) {
    // TODO: ...
}

std::string Graphic::nCurses::handleEvent() {
    return ("unknown");
}

bool Graphic::nCurses::isOperational() {
    return false;
}
