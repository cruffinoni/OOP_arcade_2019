/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Core.hpp"

bool Core::Core::handleInternalKey(const std::string &key) {
    std::array<std::pair<const char *, Core::libChanger>, 10> keys = {
        // Graphic lib
        std::make_pair(KeyboardEvent_s::NEXT_GRAPHIC, &Core::Core::nextLib),
        std::make_pair(KeyboardEvent_s::PREV_GRAPHIC, &Core::Core::previousLib),

        // Game lib
        std::make_pair(KeyboardEvent_s::NEXT_GAME, &Core::Core::nextLib),
        std::make_pair(KeyboardEvent_s::PREV_GAME, &Core::Core::previousLib),

        // Interactive key
        std::make_pair(KeyboardEvent_s::ESC, &Core::Core::exitKey),
        std::make_pair(KeyboardEvent_s::ENTER, &Core::Core::enterGame),

        //
        std::make_pair(KeyboardEvent_s::LEFT, &Core::Core::nameLeftAction),
        std::make_pair(KeyboardEvent_s::RIGHT, &Core::Core::nameRightAction),
        std::make_pair(KeyboardEvent_s::UP, &Core::Core::nameUpAction),
        std::make_pair(KeyboardEvent_s::DOWN, &Core::Core::nameDownAction),
    };

    if (IS_IN_GAME(this) && key != KeyboardEvent_s::ESC)
        return (false);
    for (std::size_t i = 0; i != keys.size(); i++) {
        if (keys[i].first == key) {
            (this->*keys[i].second)(i < 2);
            return (true);
        }
    }
    return (false);
}

void Core::Core::previousLib(bool graphical) {
    const std::string categoryName = this->MANDATORY_FOLDERS[graphical];
    auto iterator = this->_lib[categoryName].begin();

    if (this->_selection[categoryName] == 0)
        this->_selection[categoryName] = static_cast<short>(this->_lib[categoryName].size() - 1);
    else
        this->_selection[categoryName]--;
    std::advance(iterator, this->_selection[categoryName]);
    std::cout << "Changing backward [\"" << categoryName << "\"] dll to: " << *iterator << std::endl;
    try {
        if (graphical)
            this->useGraphic(*iterator);
        else
            this->useGame(*iterator);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::Core::nextLib(bool graphical) {
    std::string categoryName = this->MANDATORY_FOLDERS[graphical];
    auto iterator = this->_lib[categoryName].begin();

    if (this->_selection[categoryName] == static_cast<short>(this->_lib[categoryName].size() - 1))
        this->_selection[categoryName] = 0;
    else
        this->_selection[categoryName]++;
    std::advance(iterator, this->_selection[categoryName]);
    std::cout << "Changing forward [\"" << categoryName << "\"] dll to: " << *iterator << std::endl;
    try {
        if (graphical)
            this->useGraphic(*iterator);
        else
            this->useGame(*iterator);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::Core::exitKey(bool) {
    if (IS_IN_GAME(this)) {
        std::string gameName = this->_game.getLibPath();
        long score = std::atol(this->_game->getGameData()["score"].c_str());

        this->_score.setScore(score);
        this->_score.setGame(Core::Core::getLibName(gameName, false));
        try {
            this->_score.save();
        } catch (const Score::Exceptions::InvalidFile &e) {
            std::cerr << e.what() << std::endl;
        }
        this->_scores[gameName].addEntry({
            this->_score.getAuthor(),
            score
        });
        this->_score.reset();
        for (auto &i : this->MANDATORY_FOLDERS)
            this->_selection[i] = 0;
    }
    else
        throw Exceptions::ExitGame();
}

void Core::Core::enterGame(bool) {
    for (auto &i : this->MANDATORY_FOLDERS)
        this->_selection[i] = -1;
}

void Core::Core::updateCurrentLetter() {
    try {
        this->_playerName.currentLetter = this->_score.getLetter(this->_playerName.currentIndex);
    } catch (const std::out_of_range &e) {
        this->_playerName.currentLetter = 'a';
        this->_score.addLetter(this->_playerName.currentLetter);
    }
}

void Core::Core::nameLeftAction(bool) {
    if (static_cast<uint>(this->_playerName.currentIndex - 1) >= Score::Game::MAX_AUTHOR_NAME)
        return;
    try {
        if (this->_playerName.currentLetter == '_' && this->_playerName.currentIndex == (this->_score.getAuthor().length() - 1))
            this->_score.removeLastLetter();
    } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
    this->_playerName.currentIndex--;
    this->updateCurrentLetter();
}

void Core::Core::nameRightAction(bool) {
    if (static_cast<uint>(this->_playerName.currentIndex + 1) >= Score::Game::MAX_AUTHOR_NAME)
        return;
    this->_playerName.currentIndex++;
    this->updateCurrentLetter();
}

void Core::Core::nameUpAction(bool) {
    if (this->_playerName.currentLetter == '_')
        this->_playerName.currentLetter = 'a';
    else if (this->_playerName.currentLetter >= 'a' && this->_playerName.currentLetter <= 'z') {
        if (this->_playerName.currentLetter + 1 > 'z')
            this->_playerName.currentLetter = 'A';
        else
            this->_playerName.currentLetter++;
    } else if (this->_playerName.currentLetter >= 'A' && this->_playerName.currentLetter <= 'Z') {
        if (this->_playerName.currentLetter + 1 > 'Z')
            this->_playerName.currentLetter = '0';
        else
            this->_playerName.currentLetter++;
    } else {
        if (this->_playerName.currentLetter + 1 > '9')
            this->_playerName.currentLetter = '_';
        else
            this->_playerName.currentLetter++;
    }
    try {
        this->_score.setLetter(this->_playerName.currentIndex, this->_playerName.currentLetter);
    } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Core::Core::nameDownAction(bool) {
    if (this->_playerName.currentLetter == '_')
        this->_playerName.currentLetter = '9';
    else if (this->_playerName.currentLetter >= 'a' && this->_playerName.currentLetter <= 'z') {
        if (this->_playerName.currentLetter - 1 < 'a')
            this->_playerName.currentLetter = '_';
        else
            this->_playerName.currentLetter--;
    } else if (this->_playerName.currentLetter >= 'A' && this->_playerName.currentLetter <= 'Z') {
        if (this->_playerName.currentLetter - 1 < 'A')
            this->_playerName.currentLetter = 'z';
        else
            this->_playerName.currentLetter--;
    } else {
        if (this->_playerName.currentLetter - 1 < '0')
            this->_playerName.currentLetter = 'Z';
        else
            this->_playerName.currentLetter--;
    }
    try {
        this->_score.setLetter(this->_playerName.currentIndex, this->_playerName.currentLetter);
    } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
}
