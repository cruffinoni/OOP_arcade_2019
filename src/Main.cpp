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
        Arcade::IGraphic *graphic = graphicDll.getInstance();

        std::cout << std::string(av[1]) << std::endl;
        //auto a = graphicDll.getInstance()->createForm({145.f, 100.f}, {5421.f, 243.f});
        //printf("a: %u\n", a);
        //graphicDll.changeDLL(av[1]);
        //a = graphicDll.getInstance()->createForm({541.f, 100.f}, {5421.f, 243.f});
        //printf("a (1): %u\n", a);
        uint a = 0;
        while (graphic->windowIsOpen()) {
            if (a == 0)
                a = graphic->createForm({200.f, 200.f},
                                                 {150, 200});
            graphic->process();

        }
        return (0);
    } catch (const DLLoader::Exceptions::InvalidDLL &e) {
        std::cerr << e.what();
        return (84);
    } catch (const DLLoader::Exceptions::InvalidEntryPoint &e) {
        std::cerr << e.what();
        return (84);
    }
}
