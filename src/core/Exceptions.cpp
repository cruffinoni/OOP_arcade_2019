/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Core.hpp"

const char *Core::Exceptions::UnableCreateFolder::what() const noexcept {
    return ("Unable to create score folder for the games.\n");
}

Core::Exceptions::MissingMandatoryFolder::MissingMandatoryFolder(
    const std::string &name) noexcept {
    this->_name = name;
}

const char *Core::Exceptions::MissingMandatoryFolder::what() const noexcept {
    const static std::string msg = "Folder " + this->_name +
        " doesn't exists and it's required.\n";

    return (msg.c_str());
}

Core::Exceptions::MissingMandatoryFolder::MissingMandatoryFolder(
    const Exceptions::MissingMandatoryFolder &a) noexcept {
    this->_name = a._name;
}

Core::Exceptions::EmptyMandatoryFolder::EmptyMandatoryFolder(
    const std::string &name) noexcept {
    this->_name = name;
}

Core::Exceptions::EmptyMandatoryFolder::EmptyMandatoryFolder(
    const Exceptions::EmptyMandatoryFolder &a) noexcept {
    this->_name = a._name;
}

const char *Core::Exceptions::EmptyMandatoryFolder::what() const noexcept {
    const static std::string msg = "Folder " + this->_name +
        " is marked as mandatory but is empty. At least one element is required\n";

    return (msg.c_str());
}