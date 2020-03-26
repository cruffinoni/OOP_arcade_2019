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
//    auto high_score = Core::Core::loadScore("nibbler");
    while (this->_graphic->isOperational()) {
        try {
            this->_graphic->clearScreen();
            auto event = this->_graphic->handleEvent();
            if (event != IEventIterator::KEY_UNKNOWN) {
                printf("Event: '%s'\n", event.c_str());
                if (!this->handleInternalKey(event))
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
//    createStrip();
}

void Core::Core::createScoreFolder() {
    DIR *folder = opendir(SCORE_PATH);

    if (folder == nullptr) {
        int rtn = mkdir(SCORE_PATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if (rtn == -1)
            throw Exceptions::UnableCreateFolder();
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

//mettre les explications dans une sorte de help dans le menu
// draw rect ???????

//void Core::Core::createStrip() {
//
//}
//    this->_graphic->drawText(Text {
//            std::string("PUTAIN DE TEST DE MORT FILS DE PUTE"),
//            {40.f, 40.f},
//            {10.f, 5.f},
//            Color::Black(),
//    });
//
//    auto node;
//    this->_graphic->drawRect(Rect {
//            node,
//            {5.f, 5.f},
//            {0x00, 0x66, 0x00, 0xFF},
//    });

//    this->_graphic->drawRect();
//    auto t1 = Clock::now();
//    auto high_score = Core::Core::loadScore("nibbler");
//    while (this->_graphic->isOperational()) {
//        try {
//            this->_graphic->clearScreen();
//            auto event = this->_graphic->handleEvent();
//            this->_game->handleUpdate(std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t1).count());
//            this->_game->handleRender(*this->_graphic.getInstance());
//            this->_graphic->drawScreen();
//            t1 = Clock::now();
//        } catch (const std::bad_alloc &e) {
//            std::cerr << e.what();
//            return;
//        } catch (const Graphic::Exceptions::LoadFontFailed &e) {
//            std::cerr << e.what();
//            return;
//        } catch (const SoLoader::Exceptions::InvalidSO &e) {
//            std::cerr << e.what();
//            return;
//        } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
//            std::cerr << e.what();
//            return;
//        } catch (...) {
//            std::cerr << "[!] An exception occurred that cannot be caught" << std::endl;
//            return;
//        }
//    }
//}

/*
 * handleEvent  ++      handleEvent         ++      handleEvent
 *   LEAVE      -->     KEY_PRESSED_Q       -->         ""
 *
 *
 *   User -> Input -> Graphical -> Core | -> Game -> Core
 *                                      | -> Changement -> Game
 */
