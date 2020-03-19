/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include <chrono>
#include "soLoader/SoLoader.hpp"
#include "lib/graphic/Exceptions.hpp"
#include "Core.hpp"

using Clock = std::chrono::high_resolution_clock;

void Core::useGraphic(const std::string &filename) {
    try {
        _graphic.changeDLL(filename);
        std::cout << "[debug] library \"" << filename << "\" loaded" << std::endl;
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::useGame(const std::string &filename) {
    try {
        _game.changeDLL(filename);
        std::cout << "[debug] library \"" << filename << "\" loaded" << std::endl;
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::run() {
    auto t1 = Clock::now();

    while (this->_graphic->isOperational()) {
        try {
            this->_graphic->clearScreen();
            auto event = this->_graphic->handleEvent();
            if (event != IEventIterator::KEY_UNKNOWN) {
                printf("Event: '%s'\n", event.c_str());
                this->_game->handleEvent(event);
            }
            this->_game->handleUpdate(std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t1).count());
            this->_game->handleRender(*this->_graphic.getInstance());
            this->_graphic->drawScreen();
            t1 = Clock::now();
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
