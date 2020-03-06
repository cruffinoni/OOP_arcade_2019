/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Main file for the project.
*/

#include <iostream>
#include "DLLoader/DLLoader.hpp"
#include "game/IGame.hpp"
#include "graphic/IGraphic.hpp"

int main(const int ac, const char **av)
{
    //Arcade::Color a = Arcade::BLACK;
    if (ac == 1) {
        printf("Enter a dll name\n");
        return (84);
    }
    try {
        DLLoader::DLLoader<Arcade::IGraphic> graphicDll(av[1]);

        std::cout << std::string(av[1]) << std::endl;
        return (0);
    } catch (const DLLoader::Exceptions::InvalidDLL &e) {
        std::cerr << e.what();
        return (84);
    } catch (const DLLoader::Exceptions::InvalidEntryPoint &e) {
        std::cerr << e.what();
        return (84);
    }
}
