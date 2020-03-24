/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Core.hpp"

const char *Core::Exceptions::ScoreFolder::what() const noexcept {
    return ("Unable to create score folder for the games.\n");
}

Core::Exceptions::MissingFolder::MissingFolder(
    const std::string &name) noexcept {
    this->_name = name;
}

const char *Core::Exceptions::MissingFolder::what() const noexcept {
    const static std::string msg = "Folder " + this->_name +
        " doesn't exists and it's required.\n";

    return (msg.c_str());
}

Core::Exceptions::MissingFolder::MissingFolder(
    const Exceptions::MissingFolder &a) noexcept {
    this->_name = a._name;
}
