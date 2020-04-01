/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Main file for the project.
*/

/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */

#include <iostream>
#include "core/Core.hpp"
#include "soLoader/SoLoader.hpp"

int main(const int ac, const char **av)
{
    if (ac < 2) {
        std::cerr << "Enter a so file which is a compatible graphical library" << std::endl;
        return (84);
    }
    if (ac > 2) {
        std::cerr << "Too much argument" << std::endl;
        return (84);
    }
    try {
        Core::Core core(av[1]);
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
    } catch (const Core::Exceptions::UnknownGraphicalLib &e) {
        std::cerr << e.what();
        return (84);
    }
}
