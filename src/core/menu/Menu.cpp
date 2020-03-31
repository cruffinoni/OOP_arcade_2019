/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Menu.c - File used to handle menu
*/

#include <fstream>
#include <sstream>
#include <cstring>
#include "core/Core.hpp"
#include "core/score/Score.hpp"

std::string Core::Core::getLibName(std::string libName, bool uppercase) {
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
    if (event == KeyboardEvent_s::KEY_UP) {
        if (this->_gameSelected == 0)
            this->_gameSelected = static_cast<short>(this->_lib["games"].size() - 1);
        else
            this->_gameSelected--;
    }
    if (event == KeyboardEvent_s::KEY_DOWN) {
        if (this->_gameSelected == static_cast<short>(this->_lib["games"].size() - 1))
            this->_gameSelected = 0;
        else
            this->_gameSelected++;
    }
    if (event == KeyboardEvent_s::KEY_ENTER) {
        unsigned short i = 0;

        for (std::string &libName : this->_lib["games"]) {
            if (i++ == _gameSelected) {
                this->_gameSelected = -1;
                this->useGame(libName);
                return;
            }
        }
    }
}

std::string Core::Core::drawGames(Vector2f &final_pos) {
    Vector2f pos(5.f, 45.f);
    std::string selectedGameName;

    short i = 0;
    this->_graphic->drawText(Text {
        "Available games",
        {pos.x + 3.5f, pos.y - 18.f},
        this->DEFAULT_MEDIUM_TEXT_SIZE,
        Color::Blue()
    });
    for (auto &libName : this->_lib["games"]) {
        if (i++ == this->_gameSelected) {
            this->_graphic->drawRect(Rect {
                pos,
                this->DEFAULT_SMALL_TEXT_SIZE,
                Color::Red()
            });
            selectedGameName = libName;
        }
        this->_graphic->drawText(Text {
            this->getLibName(libName),
            pos,
            this->DEFAULT_SMALL_TEXT_SIZE,
            Color::Black()
        });
        pos.x += 15.f;
    }
    this->_graphic->drawRect(Rect{
        {0.f, (pos.y += 10.f)},
        {100.f, 2.5f},
        Color::Black(),
    });
    pos.x = 5.f;
    pos.y += 25.f;
    final_pos = pos;
    return (selectedGameName);
}

void Core::Core::drawGraphicalLib(Vector2f &position) {
    short i = 0;

    this->_graphic->drawText(Text {
        "Available graphic",
        {position.x, position.y - 18.f},
        this->DEFAULT_MEDIUM_TEXT_SIZE,
        Color::Blue()
    });
    for (auto &libName : this->_lib["lib"]) {
        if (i++ == this->_gameSelected) {
            this->_graphic->drawRect(Rect {
                position,
                this->DEFAULT_SMALL_TEXT_SIZE,
                Color::Red()
            });
        }
        this->_graphic->drawText(Text {
            this->getLibName(libName),
            position,
            this->DEFAULT_SMALL_TEXT_SIZE,
            Color::Black()
        });
        position.x += 15.f;
    }
}

void Core::Core::drawScore(const std::string &game, Vector2f &pos) {
    Vector2f scorePos(57.f, 27.f);

    this->_graphic->drawText(Text {
        "Scores du jeu",
        scorePos,
        this->DEFAULT_TEXT_SIZE,
        Color::Black()
    });
    if (this->_scores.find(game) != this->_scores.end()) {
        // TODO: Changer la position des scores I guess
        Score::File scoreBuffer(this->_scores[game]);
        scorePos.y += 10.f;
        for (auto &i : scoreBuffer.getFormattedBuffer()) {
            this->_graphic->drawText(Text {
                i.toStr(),
                scorePos,
                this->DEFAULT_SMALL_TEXT_SIZE,
                Color::Green()
            });
            scorePos.y += 5.f;
        }
    }
    else {
        this->_graphic->drawText(Text {
            "No score",
            {scorePos.x, scorePos.y + 15.f},
            this->DEFAULT_TEXT_SIZE,
            Color::Blue()
        });
    }
    pos = scorePos;
}

void Core::Core::drawPlayerName(Vector2f &position) {
    position.y += 10.f;
    this->_graphic->drawText(Text {
        "Enter your name",
        position,
        this->DEFAULT_MEDIUM_TEXT_SIZE,
        Color::Blue()
    });
    position.y += 5.f;
    this->_graphic->drawText(Text {
        this->_score.getAuthor(),
        position,
        this->DEFAULT_MEDIUM_TEXT_SIZE,
        Color::Red()
    });
}

void Core::Core::renderMenu() {
    Vector2f selectPos(8.f,47.f + static_cast<float>(20 * _gameSelected));
    Vector2f graphicalLibPos(0.0, 0.0);
    Vector2f playerNamePos(0.0, 0.0);
    std::string selectedGameName = this->drawGames(graphicalLibPos);

    this->drawGraphicalLib(graphicalLibPos);
    this->_graphic->drawText(Text {
        "Arcade",
        {30.f, 2.f},
        this->DEFAULT_TITLE_SIZE,
        Color::Green()
    });
    this->drawScore(selectedGameName, playerNamePos);
    this->_graphic->drawRect(Rect({48.f, 25.f},
        {2.f, 70.f}, Color::Black()));
    this->drawPlayerName(playerNamePos);
}

std::string Core::Core::loadScore(const std::string &gameName) {
    std::string path = Core::SCORE_PATH + gameName + ".score";
    std::ifstream file(path);
    std::ostringstream oss;

    if (!file.is_open())
        throw Exceptions::InvalidScorePath(path);
    oss << file.rdbuf();
    return (oss.str());
}
