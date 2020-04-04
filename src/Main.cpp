/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Main file for the project.
*/

/*! \mainpage OOP_arcade_2019
 *
 * \section intro_sec Introduction
 *
 * Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of
 * player scores.
 *
 * To be able to deal with the elements of your gaming plateform at run-time,
 * your graphic libraries and your games must be implemented as dynamic libraries, loaded at runtime.
 *
 * Each GUI available for the program must be used as a shared
 * library that will be loaded and used dynamically by the main program.
 *
 * \section install_sec Add a dynamic library
 * \warning Your library must be have an entry point (a.k.a a function) named `entry`.
 *
 *  Place your library (only the `.so` extension is supported) in the `lib` or `games` folder depending if
 *  it's a graphical library or a game. Your file name must be respect the following pattern:
 *  `lib_arcade_$gamename.so` or `lib_arcade_$libraryname.so`
 *  \warning The graphical library's entry point must return a `IGraphic *` instance
 *  \warning The game library's entry point must return a `IGame *` instance
 *
 *
 *  \section colab Collaboration
 *
 *  The project has been made in collaboration with:
 *  - Louise KLEIVER - Leo KAIDER - Loic BRANSTETT
 *  - Victor LIMBACH - Leo SEICHEPINE - Maxime SCHAEFFER
 *  @authors Clément RUFFINONI - Quentin HALTER - Antoine PRONNIER
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
    } catch (const std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
    } catch (const SoLoader::Exceptions::InvalidSO &e) {
        std::cerr << e.what() << std::endl;
    } catch (const SoLoader::Exceptions::InvalidEntryPoint &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Core::Exceptions::UnableCreateFolder &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Core::Exceptions::MissingMandatoryFolder &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Core::Exceptions::EmptyMandatoryFolder &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Core::Exceptions::UnknownGraphicalLib &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Graphic::Exceptions::LoadFontFailed &e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "[!] An exception occurred that cannot be caught" << std::endl;
    }
    return (84);
}
