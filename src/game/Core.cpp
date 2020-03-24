/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include <iostream>
#include <chrono>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>
#include "soLoader/SoLoader.hpp"
#include "Core.hpp"

using Clock = std::chrono::high_resolution_clock;

Core::Core::Core() {
    try {
        Core::Core::createScoreFolder();
    } catch (const Exceptions::ScoreFolder &e) {
        throw e;
    }
}

void Core::Core::useGraphic(const std::string &filename) {
    try {
        _graphic.changeDLL(filename);
        std::cout << "[debug] library \"" << filename << "\" loaded" << std::endl;
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::Core::useGame(const std::string &filename) {
    try {
        _game.changeDLL(filename);
        std::cout << "[debug] library \"" << filename << "\" loaded" << std::endl;
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::Core::run() {
    auto t1 = Clock::now();

    //auto high_score = Core::Core::loadScore("nibbler");
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
        } catch (const Graphic::Exceptions::LoadFontFailed &e) {
            std::cerr << e.what();
            return;
        } catch (...) {
            std::cerr << "exception occurred ?" << std::endl;
            return;
        }
    }
}

void Core::Core::createScoreFolder() {
    DIR *folder = opendir(SCORE_PATH);

    if (folder == nullptr) {
        int rtn = mkdir(SCORE_PATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if (rtn == -1)
            throw Exceptions::ScoreFolder();
        return (Core::Core::createScoreFolder());
    } else
        closedir(folder);
}

std::string Core::Core::loadScore(const std::string &gameName) {
    std::ifstream file(SCORE_PATH + gameName + ".score");
    std::ostringstream oss;

    if (!file.is_open())
        return ("");
    oss << file.rdbuf();
    return (oss.str());
}

const char *Core::Exceptions::ScoreFolder::what() const noexcept {
    return ("Unable to create score folder for the games.\n");
}

/*
 * handleEvent  ++      handleEvent         ++      handleEvent
 *   LEAVE      -->     KEY_PRESSED_Q       -->         ""
 *
 *
 *   User -> Input -> Graphical -> Core | -> Game -> Core
 *                                      | -> Changement -> Game
 */
