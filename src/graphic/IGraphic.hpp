/*
** EPITECH PROJECT, 2018
** include/IGraphic
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include "lib/graphic/Exceptions.hpp"
#include "Drawables.hpp"

class IEventIterator {
    public:
        virtual bool hasNext() = 0;
        virtual std::string &getNext() = 0;

        static constexpr const char *KEY_A = "EVENT_KEY_A";
        static constexpr const char *KEY_B = "EVENT_KEY_B";
        static constexpr const char *KEY_C = "EVENT_KEY_C";
        static constexpr const char *KEY_D = "EVENT_KEY_D";
        static constexpr const char *KEY_E = "EVENT_KEY_E";
        static constexpr const char *KEY_R = "EVENT_KEY_R";
        static constexpr const char *KEY_W = "EVENT_KEY_W";
        static constexpr const char *KEY_UP = "EVENT_KEY_UP";
        static constexpr const char *KEY_DOWN = "EVENT_KEY_DOWN";
        static constexpr const char *KEY_LEFT = "EVENT_KEY_LEFT";
        static constexpr const char *KEY_RIGHT = "EVENT_KEY_RIGHT";
        static constexpr const char *KEY_ENTER = "EVENT_KEY_ENTER";
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
