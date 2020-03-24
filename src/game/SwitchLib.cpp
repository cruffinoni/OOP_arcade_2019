/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Core.hpp"

bool Core::Core::handleInternalKey(const std::string &key) {
    std::array<std::pair<const char *, Core::libChanger>, 2> keys = {
        std::make_pair(IEventIterator::KEY_A, &Core::Core::previousLib),
        std::make_pair(IEventIterator::KEY_E, &Core::Core::nextLib),
    };
    for (auto &i : keys) {
        if (i.first == key) {
            try {
                (this->*i.second)(true);
                return (true);
            } catch (const SoLoader::Exceptions::InvalidSO &e) {
                throw e;
            } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
                throw e;
            }
        }
    }
    return (false);
}

void Core::Core::previousLib(bool graphical) {
    std::string categoryName;

    if (graphical)
        categoryName.append("bin");
    else
        categoryName.append("games");
    std::string libName = this->_lib[categoryName].back();
    this->_lib[categoryName].pop_back();
    this->_lib[categoryName].emplace_front(libName);
    std::cout << "Changing backward [\"" << categoryName << "\"] dll to: " << libName << std::endl;
    try {
        this->_graphic.changeDLL(libName);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::Core::nextLib(bool graphical) {
    std::string categoryName;

    if (graphical)
        categoryName.append("bin");
    else
        categoryName.append("games");
    this->_lib[categoryName].emplace_back(this->_lib[categoryName].front());
    this->_lib[categoryName].pop_front();

    std::string libName = this->_lib[categoryName].front();
    std::cout << "Changing forward [\"" << categoryName << "\"] dll to: " << libName << std::endl;
    try {
        this->_graphic.changeDLL(libName);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}
