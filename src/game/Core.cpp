/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include "Core.hpp"

Core::Core(const std::string &libGame, const std::string &libGraphic)
    try : _game(libGame), _graphic(libGraphic) {
} catch (const SoLoader::Exceptions::InvalidSO &e) {
    throw e;
} catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
    throw e;
}

void Core::useGraphic(const std::string &filename) {
    try {
        _graphic.changeDLL(filename);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::useGame(const std::string &filename) {
    try {
        _game.changeDLL(filename);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        throw e;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        throw e;
    }
}

void Core::run() {

}
