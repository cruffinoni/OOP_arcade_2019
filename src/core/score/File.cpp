/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

//#include <iostream>
#include "core/score/Score.hpp"

Score::File::File(const std::string &content) noexcept {
    std::size_t idx;
    std::size_t currIdx = 0;

    while ((idx = content.find('\n', currIdx)) != std::string::npos) {
        this->_formatted.push_back(content.substr(currIdx, idx - currIdx));
        currIdx = idx + 1;
    }
    for (auto &i : this->_formatted) {
        idx = i.find('=');
        if (idx != std::string::npos)
            i.replace(idx, 1, " -> ");
    }
}

std::list<std::string> Score::File::getFormattedBuffer() {
    return (this->_formatted);
}
