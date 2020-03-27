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
    class Ncurses : public IGraphic {
        public:
            Ncurses();
            ~Ncurses() override;

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

            std::array<Color, 8> TRANSLATE_COLORS = {
                Color {Color::Black().red, Color::Black().green, Color::Black().blue, Color::Black().alpha},
                Color {Color::Red().red, Color::Red().green, Color::Red().blue, Color::Red().alpha},
                Color {Color::Green().red, Color::Green().green, Color::Green().blue, Color::Green().alpha},
                Color {230, 230, 0, 255},
                Color {Color::Blue().red, Color::Blue().green, Color::Blue().blue, Color::Blue().alpha},
                Color {255, 0, 255, Color::Blue().alpha},
                Color {0, 255, 255, Color::Blue().alpha},
                Color {Color::White().red, Color::White().green, Color::White().blue, Color::White().alpha},
            };

        private:
            int getNcursesColor(Color color);
            std::chrono::time_point<std::chrono::high_resolution_clock> _tick;
            bool _alive;
    };
}

#endif //OOP_ARCADE_2019_NCURSES_HPP
