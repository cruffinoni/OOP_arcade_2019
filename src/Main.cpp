/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Main file for the project.
*/

#include <iostream>
#include <core/Core.hpp>
#include "soLoader/SoLoader.hpp"

int main(const int ac, const char **av)
{
    if (ac == 1) {
        std::cerr << "Enter a so file which is a compatible graphical library" << std::endl;
        return (84);
    }
    try {
        Core::Core core;
        core.useGraphic(av[1]);
        core.run();
        return (0);
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        std::cerr << e.what();
        return (84);
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        std::cerr << e.what();
        return (84);
    } catch (const Core::Exceptions::UnableCreateFolder &e) {
        std::cerr << e.what();
        return (84);
    } catch (const Core::Exceptions::MissingMandatoryFolder &e) {
        std::cerr << e.what();
        return (84);
    } catch (const Core::Exceptions::EmptyMandatoryFolder &e) {
        std::cerr << e.what();
        return (84);
    }
}
