/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <cstring>
#include <fstream>
#include "core/Core.hpp"

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

void Core::Core::useGraphic(const std::string &filename) {
    this->_graphic.changeSo(filename);
}

void Core::Core::useGame(const std::string &filename) {
    this->_game.changeSo(filename);
}

Score::File Core::Core::loadScore(const std::string &gameName) {
    std::string path = Core::SCORE_PATH + gameName + ".score";
    std::ifstream file(path);
    std::ostringstream oss;

    if (!file.is_open())
        throw Exceptions::InvalidScorePath(path);
    oss << file.rdbuf();
    return (Score::File(oss.str()));
}
