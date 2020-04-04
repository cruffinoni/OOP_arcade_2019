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

/**
 * The structure KeyboardEvent_s define generic values for the different action that
 * can occurs in the program. The associated key for each key is defined inside the private function: Core::Core::handleInternalKey
 * and is displayed during runtime.
 */
struct KeyboardEvent_s {
    static constexpr const char *NEXT_GAME = "next_game";
    static constexpr const char *PREV_GAME = "prev_game";
    static constexpr const char *RESTART = "restart";
    static constexpr const char *NEXT_GRAPHIC = "next_graphic";
    static constexpr const char *PREV_GRAPHIC = "prev_graphic";

    static constexpr const char *RIGHT = "right";
    static constexpr const char *UP = "up";
    static constexpr const char *DOWN = "down";
    static constexpr const char *LEFT = "left";

    static constexpr const char *ENTER = "enter";
    static constexpr const char *ESC = "menu";
    static constexpr const char *SPACE = "space";

    static constexpr const char *UNKNOWN = "unknown";
};

/**
 * Common macro defined between groups.
 */
#define FONT_FILENAME "/usr/share/fonts/liberation/LiberationMono-Regular.ttf"
#ifndef PERCENTAGE
    #define PERCENTAGE(a) (a / 100.f)
#endif

/**
 * The IGraphicRenderer class render the graphical aspect of a game.
 */
class IGraphicRenderer {
    public:
        virtual ~IGraphicRenderer() = default;
        /**
         * Draw all visual elements on the screen. Up to each library graphical library to handle the
         * way they manages their graphical entities.
         */
        virtual void drawScreen() = 0;
        virtual void clearScreen() = 0;
        virtual void drawRect(Rect rect) = 0;
        virtual void drawCircle(Circle circle) = 0;
        virtual void drawSprite(Sprite sprite) = 0;
        virtual void drawText(Text text) = 0;

        IGraphicRenderer &operator =(const IGraphicRenderer &) = delete;
};

class IGraphic : public IGraphicRenderer {
    public:
        IGraphic() = default;
        IGraphic(const IGraphic &) = delete;
        virtual ~IGraphic() = default;

        virtual bool isOperational() = 0;
        /**
         * The function handle keyboard events
         * @return A string with the latest event. The string must be one element of the structure KeyboardEvent_s.
         */
        virtual std::string handleEvent() = 0;
};

#endif
