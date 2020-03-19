/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "SoLoader.hpp"
#include "Exceptions.hpp"


SoLoader::Exceptions::InvalidSO::InvalidSO(const std::string &DLLPath) noexcept {
    this->_dllName = DLLPath;
}

const char *SoLoader::Exceptions::InvalidSO::what() const noexcept {
    static const std::string message =
        "SO file \"" + this->_dllName + "\" is invalid. Either it doesn't exists, "
        "either it's not a shared library.\n"
        "Error: " + dlerror() + "\n";
    return (message.c_str());
}

SoLoader::Exceptions::InvalidSO::InvalidSO(const Exceptions::InvalidSO &a) noexcept {
    this->_dllName = a._dllName;
}

SoLoader::Exceptions::InvalidEntryPoint::InvalidEntryPoint(const std::string &DLLPath) noexcept {
    this->_dllName = DLLPath;
}

const char *SoLoader::Exceptions::InvalidEntryPoint::what() const noexcept {

    static const std::string message =
        "SO file '" + this->_dllName + "' doesn't have the entry point named: "
        + std::string(SoLoader<void>::entryPointName) + "\n"
        "Error: " + dlerror() + "\n";
    return (message.c_str());
}

SoLoader::Exceptions::InvalidEntryPoint::InvalidEntryPoint(const Exceptions::InvalidEntryPoint &a) noexcept {
    this->_dllName = a._dllName;
}