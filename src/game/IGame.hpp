/*
** EPITECH PROJECT, 2018
** include/IGame
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <map>
#include <string>
#include "graphic/IGraphic.hpp"

class IGame {
     public:
        typedef std::map<std::string, std::string> GameDataType;

        virtual ~IGame() = default;
        virtual void handleEvent(std::string &name) = 0;
        virtual void handleUpdate(int elapsedTime) = 0;
        virtual void handleRender(IGraphicRenderer &renderer) = 0;
        virtual GameDataType getGameData() = 0;
        virtual void setGameData(GameDataType &data) = 0;
};

#endif
