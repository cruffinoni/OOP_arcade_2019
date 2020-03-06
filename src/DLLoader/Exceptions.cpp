/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Exceptions.hpp"

const char *
DLLoader::Exceptions::NotFound::what(const std::string &DLLPath) const noexcept {
    return (std::string("DLL Path named '" + DLLPath + "' not found").c_str());
}
