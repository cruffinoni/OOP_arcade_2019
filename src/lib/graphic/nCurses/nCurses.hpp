/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_NCURSES_HPP
#define OOP_ARCADE_2019_NCURSES_HPP

#include "graphic/IGraphic.hpp"
#include <curses.h>

namespace Graphic {
    class nCurses : public IGraphic {
        public:
            nCurses();
            ~nCurses() override;

            #define KEY_ESCAPE  27

            #ifndef PERCENTAGE
                #define PERCENTAGE(a) (a / 100.f)
            #endif

            void clearScreen() override;
            void drawCircle(Circle circle) override;
            void drawRect(Rect rect) override;
            void drawScreen() override;
            void drawSprite(Sprite sprite) override;
            void drawText(Text text) override;

            std::string handleEvent() override;
            bool isOperational() override;

        private:
            //WINDOW *_window;
            std::chrono::time_point<std::chrono::high_resolution_clock> _tick;
            bool _alive;
    };
}

#endif //OOP_ARCADE_2019_NCURSES_HPP
