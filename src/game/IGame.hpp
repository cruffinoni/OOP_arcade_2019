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

class IGame
{
     public:
         virtual void handleEvent(std::string &name) = 0;
         virtual void handleUpdate(int elepsedTime) = 0;
         virtual void handleRender(IGraphicRenderer &renderer) = 0;
         virtual std::map<std::string, std::string> getGameData() = 0;
         virtual void setGameData(std::map<std::string, std::string> &data) = 0;
};

#endif
