/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include "soLoader/SoLoader.hpp"
#include "lib/graphic/Exceptions.hpp"
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
        this->_graphic->clearScreen();
        try {
            //this->_graphic->drawRect(Rect({20, 20}, {20, 20},
            //                              Color::White()));
            this->_graphic->drawText(Text("hello world!",
                                          {50, 50}, {20, 20}, Color::White()));
            //this->_graphic->drawRect(Rect({60, 60}, {20, 20},
            //                              Color::Red()));
        } catch (const std::bad_alloc &e) {
            std::cerr << e.what();
            return;
        } catch (...) {
            std::cerr << "exception occurred ?";
            return;
        }
        //} catch (const Graphic::Exceptions::LoadFontFailed &e) {
        //    std::cerr << e.what();
        //    return;
        //}
        this->_graphic->drawScreen();
        auto event = this->_graphic->handleEvent();
        if (event != IEventIterator::KEY_UNKNOWN)
            printf("Event: '%s'\n", event.c_str());
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
