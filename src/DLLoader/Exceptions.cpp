/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "DLLoader.hpp"

DLLoader::Exceptions::InvalidDLL::InvalidDLL(const std::string &DLLPath) noexcept {
    this->_dllPath = DLLPath;
}

const char *DLLoader::Exceptions::InvalidDLL::what() const noexcept {

    std::string message = "DLL \"%s\" is invalid. Either it doesn't exists, "
                          "either it's not a shared library.\n";
    char *str = static_cast<char *>(malloc(message.length() + this->_dllPath.length()));

    if (str == nullptr)
        return ("dll not found\n");
    sprintf(str, message.c_str(), this->_dllPath.c_str());
    return (str);
}

const char *DLLoader::Exceptions::InvalidEntryPoint::what() const noexcept {
    return (std::string("DLL '" + this->_dllName + "' doesn't have the entry point named: "
    + std::string(DLLoader<int>::entryPointName) + "\n").c_str());
}

DLLoader::Exceptions::InvalidEntryPoint::InvalidEntryPoint(const std::string &DLLPath) noexcept {
    this->_dllName = DLLPath;
}
