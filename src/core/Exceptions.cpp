/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core file Exceptions.
*/

#include "Core.hpp"

const char *Core::Exceptions::UnableCreateFolder::what() const noexcept {
    return ("Unable to create score folder for the games.");
}

Core::Exceptions::MissingMandatoryFolder::MissingMandatoryFolder(
    const std::string &name) noexcept {
    this->_name = name;
}

const char *Core::Exceptions::MissingMandatoryFolder::what() const noexcept {
    const static std::string msg = "Folder " + this->_name +
        " doesn't exists and it's required.";

    return (msg.c_str());
}

Core::Exceptions::EmptyMandatoryFolder::EmptyMandatoryFolder(
    const std::string &name) noexcept {
    this->_name = name;
}

const char *Core::Exceptions::EmptyMandatoryFolder::what() const noexcept {
    const static std::string msg = "Folder " + this->_name +
        " is marked as mandatory but is empty. At least one element is required";

    return (msg.c_str());
}

Core::Exceptions::InvalidScorePath::InvalidScorePath(
    const std::string &name) noexcept {
    this->_name = name;
}

const char *Core::Exceptions::InvalidScorePath::what() const noexcept {
    const static std::string msg = "The path below is invalid: '" + this->_name + "'";

    return (msg.c_str());
}


const char *Core::Exceptions::ExitGame::what() const noexcept {
    return ("Exit game gracefully");
}


Core::Exceptions::UnknownGraphicalLib::UnknownGraphicalLib(
    const std::string &name) noexcept {
    this->_name = name;
}

const char *Core::Exceptions::UnknownGraphicalLib::what() const noexcept {
    const static std::string msg = "The graphical library below '" + this->_name + "'"
           " has been loaded but the file is not available anymore. It can be an internal error. "
           "Make sure the loaded library still in one of the mandatory folder.";

    return (msg.c_str());
}
