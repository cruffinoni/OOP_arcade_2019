/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Menu.c - File used to handle menu
*/

#include <fstream>
#include <sstream>
#include <cstring>
#include "Core.hpp"

std::string Core::Core::getGameName(std::string libName, bool uppercase) {
    const std::size_t prefixLen = std::strlen("lib_arcade_");
    const char *rtn = std::strstr(libName.c_str(), "lib_arcade_");

    if (rtn == nullptr || libName.size() < prefixLen) {
        std::cerr << "The lib name " << libName << " might be invalid" << std::endl;
        return "";
    }
    libName = rtn;
    libName.erase(0, prefixLen);
    libName.erase(libName.size() - 3);
    if (uppercase)
        libName[0] = std::toupper(libName[0]);
    return (libName);
}

void Core::Core::menuEvents(std::string &event) {
    if (event == IEventIterator::KEY_UP) {
        if (this->_gameSelected == 0)
            this->_gameSelected = static_cast<short>(this->_lib["games"].size() - 1);
        else
            this->_gameSelected--;
    }
    if (event == IEventIterator::KEY_DOWN) {
        if (this->_gameSelected == static_cast<short>(this->_lib["games"].size() - 1))
            this->_gameSelected = 0;
        else
            this->_gameSelected++;
    }
    if (event == IEventIterator::KEY_ENTER) {
        unsigned short i = 0;

        for (std::string &libName : this->_lib["games"]) {
            if (i++ == _gameSelected) {
                this->_gameSelected = -1;
                this->useGame(libName);
                return;
            }
        }
    }
    // TODO: Echap to exit the arcade
}

void Core::Core::renderMenu() {
    std::string gameName;
    std::string scoreBuff;
    Vector2f textPos(12.f, 50.f);
    Vector2f scorePos(57.f, 25.f);
    Vector2f selectPos(8.f,47.f + static_cast<float>(20 * _gameSelected));

    this->_graphic->drawText(Text {
        std::string("Arcade"),
        {25.f, 3.f},
        {50.f, 20.f},
        Color::Green()
    });
    this->_graphic->drawRect(Rect({48.f, 25.f},
        {2.f, 70.f}, Color::Red()));
    this->_graphic->drawText(Text(std::string("Selection de jeu"),
        {7.f, 25.f}, {35.f, 15.f}, Color::White()));
    this->_graphic->drawRect(Rect(selectPos,
        {26, 16}, Color::Red()));

    this->_graphic->drawText(Text {
        "Scores du jeu",
        scorePos,
        {35.f, 15.f},
        Color::White()
    });
    for (auto &libName : this->_lib["games"]) {
        this->_graphic->drawText(Text {
            this->getGameName(libName),
            textPos,
            {20.f, 10.f},
            Color::Black()
        });
        textPos.y += 20;
        if (this->_scores.find(libName) != this->_scores.end()) {
            // TODO: Display score for the current lib!
        }
    }
}

std::string Core::Core::loadScore(const std::string &gameName) {
    std::string path = Core::SCORE_PATH + gameName + ".score";
    std::ifstream file(path);
    std::ostringstream oss;

    printf("Game: '%s / Path: '%s'\n", gameName.c_str(), path.c_str());
    if (!file.is_open())
        throw Exceptions::InvalidScorePath(path);
    oss << file.rdbuf();
    return (oss.str());
}
