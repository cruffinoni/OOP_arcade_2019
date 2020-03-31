/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Core.hpp"

bool Core::Core::handleInternalKey(const std::string &key) {
    std::array<std::pair<const char *, Core::libChanger>, 5> keys = {
        // Graphic lib
        std::make_pair(KeyboardEvent_s::KEY_A, &Core::Core::nextLib),
        std::make_pair(KeyboardEvent_s::KEY_W, &Core::Core::previousLib),

        // Game lib
        std::make_pair(KeyboardEvent_s::KEY_E, &Core::Core::nextLib),
        std::make_pair(KeyboardEvent_s::KEY_C, &Core::Core::previousLib),

        std::make_pair(KeyboardEvent_s::KEY_ESCAPE, &Core::Core::exitKey),
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
    std::string categoryName = this->MANDATORY_FOLDERS[graphical];
    std::string libName = this->_lib[categoryName].back();

    this->_lib[categoryName].pop_back();
    this->_lib[categoryName].emplace_front(libName);
    std::cout << "Changing backward [\"" << categoryName << "\"] dll to: " << libName << std::endl;
    try {
        if (graphical)
            this->_graphic.changeDLL(libName);
        else
            this->_game.changeDLL(libName);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::Core::nextLib(bool graphical) {
    std::string categoryName = this->MANDATORY_FOLDERS[graphical];
    this->_lib[categoryName].emplace_back(this->_lib[categoryName].front());
    this->_lib[categoryName].pop_front();

    std::string libName = this->_lib[categoryName].front();
    std::cout << "Changing forward [\"" << categoryName << "\"] dll to: " << libName << std::endl;
    try {
        if (graphical)
            this->_graphic.changeDLL(libName);
        else
            this->_game.changeDLL(libName);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::Core::exitKey(bool) {
    if (this->_gameSelected == -1)
        this->_gameSelected = 0;
    else
        throw Exceptions::ExitGame();
}
