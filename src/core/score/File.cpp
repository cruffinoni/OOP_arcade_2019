/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Opens file score and get information from it
*/

#include <algorithm>
#include "core/score/Score.hpp"

Score::File::File(const std::string &content) noexcept {
    std::size_t idx;
    std::size_t sec_idx;
    std::size_t currIdx = 0;
    std::string line;

    while ((idx = content.find('\n', currIdx)) != std::string::npos) {
        line = content.substr(currIdx, idx - currIdx);
        sec_idx = line.find('=');
        if (sec_idx != std::string::npos) {
            this->_userList.emplace_back(
                line.substr(0, sec_idx),
                std::atol(line.substr(sec_idx + 1).c_str())
            );
        }
        currIdx = idx + 1;
    }
    this->sort();
}

std::list<Score::File::PlayerData> Score::File::getListUser() {
    return (this->_userList);
}

void Score::File::addEntry(const Score::File::PlayerData &user) {
    this->_userList.push_back(user);
    this->sort();
}

void Score::File::sort() {
    this->_userList.sort([](const PlayerData &a, const PlayerData &b) {
        return (a.score > b.score);
    });
    auto iterator = this->_userList.begin();
    std::advance(iterator, 3);
    this->_userList.erase(iterator, this->_userList.end());
}

Score::File::PlayerData::PlayerData(const std::string &name, const long score) {
    this->name = name;
    this->score = score;
}

std::string Score::File::PlayerData::toStr() const {
    return (std::string(this->name + " = " + std::to_string(this->score)));
}
