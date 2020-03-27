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
#include <cstring>
#include <dirent.h>
#include "soLoader/SoLoader.hpp"
#include "Core.hpp"

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

Core::Core::Core() : _gameSelected(0) {
    Core::Core::createScoreFolder();

    for (auto &i: this->MANDATORY_FOLDERS) {
        this->readFolder(i);
        if (this->_lib[i].empty())
            throw Exceptions::EmptyMandatoryFolder(i);
        for (auto &k: this->_lib[i])
            std::cout << k << std::endl;
    }
    this->useGame(this->_lib["games"].front());
}

void Core::Core::useGraphic(const std::string &filename) {
    _graphic.changeDLL(filename);
    std::cout << "[debug] library \"" << filename << "\" loaded" << std::endl;
}

void Core::Core::useGame(const std::string &filename) {
    _game.changeDLL(filename);
    std::cout << "[debug] library \"" << filename << "\" loaded" << std::endl;
}

void Core::Core::run() {
    auto t1 = std::chrono::high_resolution_clock::now();
    for (auto &libName : this->_lib["games"]) {
        try {
            this->_scores[libName] = Core::Core::loadScore(
                Core::Core::getLibName(libName, false));
        } catch (const Exceptions::InvalidScorePath &) {
            // This is a minor error, we don't need to do anything with it
        }
    }
    while (this->_graphic->isOperational()) {
        try {
            this->_graphic->clearScreen();
            auto event = this->_graphic->handleEvent();
            if (this->_gameSelected == -1) {
                if (event != IEventIterator::KEY_UNKNOWN) {
                    printf("Event: '%s'\n", event.c_str());
                    if (!this->handleInternalKey(event))
                        this->_game->handleEvent(event);
                }
                auto now = std::chrono::high_resolution_clock::now();
                this->_game->handleUpdate(
                    std::chrono::duration_cast<std::chrono::milliseconds>(now - t1).count());
                t1 = now;
                this->_game->handleRender(*this->_graphic.getInstance());
                createStripGame();
            } else {
                if (!this->handleInternalKey(event)) {
                    this->menuEvents(event);
                    this->renderMenu();
                    createStripMenu();
                }
                this->renderMenu();
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
        } catch (const Exceptions::ExitGame &) {
            std::cout << "Exit arcade project gracefully" << std::endl;
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
