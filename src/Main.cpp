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
    DLLoader::DLLoader<Arcade::IGraphic> graphicDll("./a.out");

    std::cout << std::string(av[0]) << std::endl;
    return (0);
}
