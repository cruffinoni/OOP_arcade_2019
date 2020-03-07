/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "DLLoader.hpp"
#include "Exceptions.hpp"


DLLoader::Exceptions::InvalidDLL::InvalidDLL(const std::string &DLLPath) noexcept {
    this->_dllName = DLLPath;
}

const char *DLLoader::Exceptions::InvalidDLL::what() const noexcept {
    static const std::string message =
        "DLL \"" + this->_dllName + "\" is invalid. Either it doesn't exists, "
        "either it's not a shared library.\n"
        "Error: " + dlerror() + "\n";
    return (message.c_str());
}

DLLoader::Exceptions::InvalidDLL::InvalidDLL(const Exceptions::InvalidDLL &a) noexcept {
    this->_dllName = a._dllName;
}

DLLoader::Exceptions::InvalidEntryPoint::InvalidEntryPoint(const std::string &DLLPath) noexcept {
    this->_dllName = DLLPath;
}

const char *DLLoader::Exceptions::InvalidEntryPoint::what() const noexcept {

    static const std::string message =
        "DLL '" + this->_dllName + "' doesn't have the entry point named: "
        + std::string(DLLoader<void>::entryPointName) + "\n"
        "Error: " + dlerror() + "\n";
    return (message.c_str());
}

DLLoader::Exceptions::InvalidEntryPoint::InvalidEntryPoint(const Exceptions::InvalidEntryPoint &a) noexcept {
    this->_dllName = a._dllName;
}
