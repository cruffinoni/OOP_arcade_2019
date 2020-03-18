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

        static constexpr const char *CLOSE = "EVENT_CLOSE";
        static constexpr const char *KEY_A = "EVENT_KEY_A";
        static constexpr const char *KEY_B = "EVENT_KEY_B";
        static constexpr const char *KEY_C = "EVENT_KEY_C";
        static constexpr const char *KEY_D = "EVENT_KEY_D";
        static constexpr const char *KEY_UNKNOWN = "EVENT_KEY_UNKNWON";
        static const std::string key;
};

class IGraphicRenderer {
    public:
        virtual void drawScreen() = 0;
        virtual void clearScreen() = 0;
        virtual void drawRect(Rect rect) = 0;
        virtual void drawCircle(Circle circle) = 0;
        virtual void drawSprite(Sprite sprite) = 0;
        virtual void drawText(Text text) = 0;
};

class IGraphic : public IGraphicRenderer {
    public:
         virtual ~IGraphic() = default;

         virtual bool isOperational() = 0;
         virtual std::string handleEvent() = 0;
};

#endif
