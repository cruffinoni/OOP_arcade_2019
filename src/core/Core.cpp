/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <sys/stat.h>
#include <fcntl.h>
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
        std::experimental::filesystem::path file("./" + folderName + "/" + dirent->d_name);
        if (file.extension() == ".so" && dirent->d_type == DT_REG)
            this->_lib[folderName].push_back(std::experimental::filesystem::canonical(file));
        dirent = readdir(dir);
    }
    closedir(dir);
}

Core::Core::Core(const std::string &graphicalLib) : _playerName(), _score() {
    Core::Core::createScoreFolder();
    this->useGraphic(graphicalLib);
    for (auto &i: this->MANDATORY_FOLDERS) {
        this->_selection[i] = 0;
        this->readFolder(i);
        if (this->_lib[i].empty())
            throw Exceptions::EmptyMandatoryFolder(i);
        for (auto &k: this->_lib[i])
            std::cout << k << std::endl;
    }
    this->useGame( this->_lib["games"].front());
    auto iterator = std::find(this->_lib["lib"].begin(),
                              this->_lib["lib"].end(),
                              std::experimental::filesystem::canonical(this->_graphic.getLibPath()));
    if (iterator == this->_lib["lib"].end())
        throw Exceptions::UnknownGraphicalLib(this->_graphic.getLibPath());
    else
        this->_selection["lib"] = std::distance(this->_lib["lib"].begin(), iterator);
    this->updateCurrentLetter();
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
            if (IS_IN_GAME(this)) {
                if (event != KeyboardEvent_s::UNKNOWN) {
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
                this->handleInternalKey(event);
                createStripMenu();
                this->renderMenu();
            }
            this->_graphic->drawScreen();
        } catch (const std::bad_alloc &e) {
            std::cerr << e.what() << std::endl;
            return;
        } catch (const Graphic::Exceptions::LoadFontFailed &e) {
            std::cerr << e.what() << std::endl;
            return;
        } catch (const SoLoader::Exceptions::InvalidSO &e) {
            std::cerr << e.what() << std::endl;
            return;
        } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
            std::cerr << e.what() << std::endl;
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
