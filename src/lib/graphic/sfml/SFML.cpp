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
        printf("constructor called\n");
        instance = new Graphic::SFML();
    }

    __attribute__((destructor)) void unload() {
        printf("destructor called\n");
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
uint Graphic::SFML::createForm(Arcade::Vector position, Arcade::Vector size) {
    printf("Create square called\n");
    return (position.x);
}
