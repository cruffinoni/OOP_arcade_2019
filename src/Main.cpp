/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Main file for the project.
*/

#include <iostream>
#include <game/Core.hpp>
#include "soLoader/SoLoader.hpp"

int main(const int ac, const char **av)
{
    if (ac == 1) {
        std::cerr << "Enter a dll name" << std::endl;
        return (84);
    }
    try {
        Core core;
        core.useGraphic(av[1]);
        core.useGame("./bin/lib_arcade_nibbler.so");
        core.run();
        return (0);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        std::cerr << e.what();
        return (84);
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        std::cerr << e.what();
        return (84);
    }
}
