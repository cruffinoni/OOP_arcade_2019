/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <fstream>
#include "core/Core.hpp"
#include "Score.hpp"

Score::Game::Game(const int amount, const std::string &gameName) {
    // Load scores like core does it
    this->_amount = amount;
    this->_game = gameName;
}

void Score::Game::addLetter(std::string &letter) {
    std::size_t idx = letter.find("EVENT_KEY_");
    const std::size_t len = std::string("EVENT_KEY_").size();

    if (idx == std::string::npos) {
        this->_author.append(letter);
        return;
    }
    letter.erase(0, len);
    this->_author.append(letter);
}

void Score::Game::saveScore() const {
    std::ofstream file;

    file.open(Core::Core::SCORE_PATH + this->_game + ".score", std::fstream::app);
    if (!file.is_open())
        throw Score::Exceptions::InvalidFile();
    if (this->_author.empty())
        file << std::string("Unknown=" + std::to_string(this->_amount)) << std::endl;
    else
        file << std::string(this->_author + "=" + std::to_string(this->_amount)) << std::endl;
}

Score::Game Score::Game::operator++(const int) {
    this->_amount++;
    return (*this);
}

Score::Game &Score::Game::operator=(const int amount) {
    this->_amount = amount;
    return (*this);
}

int Score::Game::operator*() {
    return (this->_amount);
}

void Score::Game::handleEvent(std::string &letter) {
    if (letter == IEventIterator::KEY_ENTER) {
        try {
            this->saveScore();
        } catch (const Score::Exceptions::InvalidFile &e) {
            throw e;
        }
        throw Score::Exceptions::FileSaved();
    }
    else {
        const std::size_t maxAuthorName = 6;
        if (this->_author.size() > maxAuthorName)
            std::cerr << "Your name cannot exceed " + std::to_string(maxAuthorName) + " characters" << std::endl;
        else
            this->addLetter(letter);
    }
}

std::string Score::Game::getAuthor() const {
    return (this->_author);
}

void Score::Game::reset() {
    this->_author.clear();
    this->_amount = 0;
}
