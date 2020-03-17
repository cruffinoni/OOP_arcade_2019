/*
** EPITECH PROJECT, 2018
** include/IGraphic
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include "Drawables.hpp"

class IEventIterator {
    public:
        virtual bool hasNext() = 0;

        virtual std::string &getNext() = 0;
};

class IGraphicRenderer {
    public:
        IGraphicRenderer() = default;
        virtual ~IGraphicRenderer() = default;
        IGraphicRenderer(const IGraphicRenderer &) = delete;
        IGraphicRenderer &operator=(const IGraphicRenderer &) = delete;

        virtual void drawScreen() = 0;
        virtual void clearScreen() = 0;
        virtual void drawRect(Rect rect) = 0;
        virtual void drawCircle(Circle circle) = 0;
        virtual void drawSprite(Sprite sprite) = 0;
        virtual void drawText(Text text) = 0;
};

class IGraphic : public IGraphicRenderer {
    public:
        virtual bool isOperational() = 0;

        virtual IEventIterator &handleEvents() = 0;
};

#endif
