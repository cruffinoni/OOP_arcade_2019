/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include "Core.hpp"

void Core::useGraphic(const std::string &filename) {
    try {
        _graphic.changeDLL(filename);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::useGame(const std::string &filename) {
    try {
        _game.changeDLL(filename);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::run() {
    while (this->_graphic->isOperational()) {
        //this->_graphic->clearScreen();
        //this->_graphic->drawCircle(Circle({20, 20}, {20, 20},
        //                                  Color::White()));
        //this->_graphic->drawScreen();
        auto a = this->_graphic->handleEvent();
        if (a == "CHANGE_GRAPHIC_LIB")
            this->_graphic.changeDLL("PAS SFML");
        else
            this->_game->handleEvent(a);
    }
}


/*
 * handleEvent  ++      handleEvent         ++      handleEvent
 *   LEAVE      -->     KEY_PRESSED_Q       -->         ""
 *
 *
 *   User -> Input -> Graphical -> Core | -> Game -> Core
 *                                      | -> Changement -> Game
 */
