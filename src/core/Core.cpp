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
#include <cstring>
#include "soLoader/SoLoader.hpp"
#include "Core.hpp"

using Clock = std::chrono::high_resolution_clock;

void Core::Core::readFolder(const std::string &folderName) {
    DIR *dir = opendir(folderName.c_str());
    struct dirent *dirent;

    if (dir == nullptr)
        throw Exceptions::MissingMandatoryFolder(folderName);
    dirent = readdir(dir);
    while (dirent != nullptr) {
        if (strstr(dirent->d_name, ".so") != nullptr && dirent->d_type == DT_REG)
            this->_lib[folderName].push_back(std::string("./" + folderName + "/" + dirent->d_name));
        dirent = readdir(dir);
    }
    closedir(dir);
}

Core::Core::Core() {
    try {
        Core::Core::createScoreFolder();

        for (auto &i: this->MANDATORY_FOLDERS) {
            this->readFolder(i);
            if (this->_lib[i].empty())
                throw Exceptions::EmptyMandatoryFolder(i);
            for (auto &k: this->_lib[i])
                std::cout << k << std::endl;
        }
        this->useGame(this->_lib["games"].front());
    } catch (const Exceptions::UnableCreateFolder &e) {
        throw e;
    } catch (const Exceptions::MissingMandatoryFolder &e) {
        throw e;
    } catch (const Exceptions::EmptyMandatoryFolder &e) {
        throw e;
    }
    this->_gameRunning = true;
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

//mettre les explications dans une sorte de help dans le menu
// draw rect ???????

void Core::Core::createStripGame() {
    this->_graphic->drawRect(Rect{
            {05.0f, 96.f},
            {30.f, 5.f},
            Color::Blue(),
    });

    this->_graphic->drawText(Text {
            std::string("Lib = Sfml Game = Nibble"),
            {05.f, 96.f},
            {10.f, 5.f},
            Color::Black(),
    });

    this->_graphic->drawRect(Rect{
            {50.0f, 96.f},
            {47.f, 5.f},
            Color::Blue(),
    });

    this->_graphic->drawText(Text {
            std::string("A: Next graphic lib  E: Previous graphic lib"),
            {50.f, 96.f},
            {10.f, 5.f},
            Color::Black(),
    });
}

void Core::Core::createStripMenu() {
    this->_graphic->drawRect(Rect{
            {05.0f, 96.f},
            {30.f, 5.f},
            Color::Blue(),
    });

    this->_graphic->drawText(Text {
            std::string("Lib = Sfml"),
            {05.f, 96.f},
            {10.f, 5.f},
            Color::White(),
    });

    this->_graphic->drawRect(Rect{
            {50.0f, 96.f},
            {47.f, 5.f},
            Color::Blue(),
    });

    this->_graphic->drawText(Text {
            std::string("A: Next graphic lib  E: Previous graphic lib"),
            {50.f, 96.f},
            {10.f, 5.f},
            Color::White(),
    });
}

void Core::Core::run() {
    auto t1 = Clock::now();
    //auto high_score = Core::Core::loadScore("nibbler");
    while (this->_graphic->isOperational()) {
        try {
            this->_graphic->clearScreen();
            auto event = this->_graphic->handleEvent();
            if (this->_gameRunning) {
                if (event != IEventIterator::KEY_UNKNOWN) {
                    printf("Event: '%s'\n", event.c_str());
                    if (!this->handleInternalKey(event))
                        this->_game->handleEvent(event);
                }
                this->_game->handleUpdate(
                    std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - t1).count());
                t1 = Clock::now();
                this->_game->handleRender(*this->_graphic.getInstance());
                createStripGame();
            } else {
                if (!this->handleInternalKey(event)) {
                    this->menuEvents(event);
                    this->renderMenu();
                    createStripMenu();
                }
            }
            this->_graphic->drawScreen();
        } catch (const std::bad_alloc &e) {
            std::cerr << e.what();
            return;
        } catch (const Graphic::Exceptions::LoadFontFailed &e) {
            std::cerr << e.what();
            return;
        } catch (const SoLoader::Exceptions::InvalidSO &e) {
            std::cerr << e.what();
            return;
        } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
            std::cerr << e.what();
            return;
        } catch (...) {
            std::cerr << "[!] An exception occurred that cannot be caught" << std::endl;
            return;
        }
    }
}

void Core::Core::createScoreFolder() {
    DIR *folder = opendir(Core::SCORE_PATH);

    if (folder == nullptr) {
        if (mkdir(Core::SCORE_PATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
            throw Exceptions::UnableCreateFolder();
        return (Core::Core::createScoreFolder());
    } else
        closedir(folder);
}

std::string Core::Core::loadScore(const std::string &gameName) {
    std::ifstream file(Core::SCORE_PATH + gameName + ".score");
    std::ostringstream oss;

    if (!file.is_open())
        return ("");
    oss << file.rdbuf();
    return (oss.str());
}


/*
 * handleEvent  ++      handleEvent         ++      handleEvent
 *   LEAVE      -->     KEY_PRESSED_Q       -->         ""
 *
 *
 *   User -> Input -> Graphical -> Core | -> Game -> Core
 *                                      | -> Changement -> Game
 */
