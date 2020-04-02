/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** File who handle score gestion from games
*/

#include <fstream>
#include "core/Core.hpp"
#include "Score.hpp"

void Score::Game::addLetter(const char &letter) {
    this->_author += letter;
}

void Score::Game::save() const {
    std::ofstream file;

    file.open(Core::Core::SCORE_PATH + this->_game + ".score", std::fstream::app);
    if (!file.is_open())
        throw Score::Exceptions::InvalidFile();
    if (this->_author.empty())
        file << std::string("Unknown=" + std::to_string(this->_amount)) << std::endl;
    else
        file << std::string(this->_author + "=" + std::to_string(this->_amount)) << std::endl;
}

std::string Score::Game::getAuthor() const {
    return (this->_author);
}

void Score::Game::reset() {
    this->_amount = 0;
}

const char &Score::Game::getLetter(const std::size_t idx) const {
    return (this->_author.at(idx));
}

void Score::Game::setLetter(const std::size_t idx, const char c) {
    try {
        this->_author.at(idx);
        this->_author[idx] = c;
    } catch (const std::out_of_range &e) {
        throw e;
    }
}

void Score::Game::removeLastLetter() {
    if (this->_author.empty())
        throw std::out_of_range("size is 0, unable to remove the last letter");
    this->_author.erase(this->_author.end() - 1, this->_author.end());
}

void Score::Game::setScore(const std::size_t score) {
    this->_amount = score;
}

void Score::Game::setGame(const std::string &game) {
    this->_game = game;
}
