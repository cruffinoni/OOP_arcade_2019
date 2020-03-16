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

Graphic::SFML::SFML() {
    this->_window = new sf::RenderWindow({800, 600}, "Arcade");
}

Graphic::SFML::~SFML() {
    printf("delete constructor\n");
    //delete this->_window;
}

//void Graphic::SFML::process() {
//    this->_window->clear();
//    for (auto &i: this->_forms)
//        this->_window->draw(*i);
//    this->_window->display();
//}
