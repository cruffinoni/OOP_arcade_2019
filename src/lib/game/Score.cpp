/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <fstream>
#include "game/Core.hpp"
#include "Score.hpp"

Game::Score::Score::Score(const int amount, const std::string &gameName) {
    // Load scores like core does it
    this->_amount = amount;
    this->_game = gameName;
}

void Game::Score::Score::addLetter(std::string &letter) {
    std::size_t idx = letter.find("EVENT_KEY_");
    const std::size_t len = std::string("EVENT_KEY_").size();

    if (idx == std::string::npos) {
        this->_author.append(letter);
        return;
    }
    letter.erase(0, len);
    this->_author.append(letter);
}

void Game::Score::Score::saveScore() const {
    std::ofstream file;

    file.open(Core::Core::SCORE_PATH + this->_game + ".score", std::fstream::app);
    if (!file.is_open())
        throw Game::Score::Exceptions::InvalidFile();
    if (this->_author.empty())
        file << std::string("Unknown=" + std::to_string(this->_amount)) << std::endl;
    else
        file << std::string(this->_author + "=" + std::to_string(this->_amount)) << std::endl;
}

Game::Score::Score Game::Score::Score::operator++(const int) {
    this->_amount++;
    return (*this);
}

Game::Score::Score &Game::Score::Score::operator=(const int amount) {
    this->_amount = amount;
    return (*this);
}

int Game::Score::Score::operator*() {
    return (this->_amount);
}

void Game::Score::Score::handleEvent(std::string &letter) {
    if (letter == IEventIterator::KEY_ENTER) {
        try {
            this->saveScore();
        } catch (const Game::Score::Exceptions::InvalidFile &e) {
            throw e;
        }
        throw Game::Score::Exceptions::FileSaved();
    }
    else {
        const std::size_t maxAuthorName = 6;
        if (this->_author.size() > maxAuthorName)
            std::cerr << "Your name cannot exceed " + std::to_string(maxAuthorName) + " characters" << std::endl;
        else
            this->addLetter(letter);
    }
}

std::string Game::Score::Score::getAuthor() const {
    return (this->_author);
}

void Game::Score::Score::reset() {
    this->_author.clear();
    this->_amount = 0;
}

const char *Game::Score::Exceptions::InvalidFile::what() const noexcept {
    return ("Unable to create or write inside the score file.\n");
}

const char *Game::Score::Exceptions::FileSaved::what() const noexcept {
    return ("No error so far, you may not display that\n");
}
