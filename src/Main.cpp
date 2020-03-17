/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Main file for the project.
*/

#include <iostream>
#include "SoLoader/SoLoader.hpp"
#include "graphic/IGraphic.hpp"

int main(const int ac, const char **av)
{
    //Arcade::Color a = Arcade::BLACK;
    if (ac == 1) {
        printf("Enter a dll name\n");
        return (84);
    }
    try {
        SoLoader::SoLoader<IGraphic> graphicDll(av[1]);

        std::cout << std::string(av[1]) << std::endl;
        return (0);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        std::cerr << e.what();
        return (84);
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        std::cerr << e.what();
        return (84);
    }
}
