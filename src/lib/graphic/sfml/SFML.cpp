/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "SFML.hpp"

static Graphic::SFML *instance;

extern "C" {
    Arcade::IGraphic *loadLibrary() {
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

Graphic::SFML::SFML() {
    this->_window = new sf::RenderWindow({800, 600}, "Arcade");
}

Graphic::SFML::~SFML() {
    printf("delete constructor\n");
    //delete this->_window;
}

// uint for an UID ?
uint Graphic::SFML::createForm(const Arcade::fVector position, const Arcade::fVector size) {
    printf("Create square called\n");
    auto a = new sf::RectangleShape({size.x, size.y});
    a->setPosition({position.x, position.y});
    this->_forms.push_back(a);
    return (position.x);
}

bool Graphic::SFML::windowIsOpen() {
    return (this->_window->isOpen());
}

void Graphic::SFML::process() {
    this->_window->clear();
    for (auto &i: this->_forms)
        this->_window->draw(*i);
    this->_window->display();
}
