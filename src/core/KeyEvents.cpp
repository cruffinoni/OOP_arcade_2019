/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Core.hpp"

bool Core::Core::handleInternalKey(const std::string &key) {
    std::array<std::pair<const char *, Core::libChanger>, 6> keys = {
        // Graphic lib
        std::make_pair(KeyboardEvent_s::NEXT_GRAPHIC, &Core::Core::nextLib),
        std::make_pair(KeyboardEvent_s::PREV_GRAPHIC, &Core::Core::previousLib),

        // Game lib
        std::make_pair(KeyboardEvent_s::NEXT_GAME, &Core::Core::nextLib),
        std::make_pair(KeyboardEvent_s::PREV_GAME, &Core::Core::previousLib),

        // Important key
        std::make_pair(KeyboardEvent_s::ESC, &Core::Core::exitKey),
        std::make_pair(KeyboardEvent_s::ENTER, &Core::Core::enterGame),
    };
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
