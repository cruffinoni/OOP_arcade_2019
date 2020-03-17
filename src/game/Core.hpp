/*
** EPITECH PROJECT, 2018
** include/Core
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include "game/IGame.hpp"
#include "graphic/IGraphic.hpp"
#include "DLLoader/SoLoader.hpp"

class Core {
    public:
        explicit Core();
        ~Core();

        void useGraphic(const std::string &filename);
        void useGame(const std::string &filename);
        void run();

    private:
        SoLoader::SoLoader<IGame> _game;
        SoLoader::SoLoader<IGraphic> _graphic;
};

#endif
