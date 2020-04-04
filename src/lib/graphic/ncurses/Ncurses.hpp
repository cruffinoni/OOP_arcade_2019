/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Header class file for Ncurses lib
*/

#ifndef OOP_ARCADE_2019_NCURSES_HPP
#define OOP_ARCADE_2019_NCURSES_HPP

#include <curses.h>
#include "graphic/IGraphic.hpp"

namespace Graphic {
    class Ncurses : public IGraphic {
        public:
            /**
             * Basic constructor for SFML. It creates the window with some
             * specific parameters (framerate, window's name, ...).
             */
            Ncurses();
            ~Ncurses() override;

            /**
             * The KEY_ESCAPE macro doesn't exists in NCurses, we add it.
             */
            #define KEY_ESCAPE  27
            /**
             * Since the KEY_ENTER NCurses macro doesn't correspond to the actual
             * ENTER key, we define a custom one.
             */
            #define CUSTOM_KEY_ENTER  10

            void clearScreen() override;
            void drawCircle(Circle circle) override;
            void drawRect(Rect rect) override;
            void drawScreen() override;
            void drawSprite(Sprite sprite) override;
            void drawText(Text text) override;

            std::string handleEvent() override;
            bool isOperational() override;

            /**
             * This array correspond to the liaison between NCurses' colors and
             * the color's value within the Color class.
             */
            std::array<Color, 8> TRANSLATE_COLORS = {
                Color {Color::Black().red, Color::Black().blue, Color::Black().green, Color::Black().alpha},
                Color {Color::Red().red, Color::Red().blue, Color::Red().green, Color::Red().alpha},
                Color {Color::Green().red, Color::Green().blue, Color::Green().green, Color::Green().alpha},
                Color {230, 0, 230, 255},
                Color {Color::Blue().red, Color::Blue().blue, Color::Blue().green, Color::Blue().alpha},
                Color {255, 255, 0, Color::Blue().alpha},
                Color {0, 255, 255, Color::Blue().alpha},
                Color {Color::White().red, Color::White().blue, Color::White().green, Color::White().alpha},
            };

            static const int WINDOW_WIDTH = 100;
            static const int WINDOW_HEIGHT = 50;

        private:
            int getNcursesColor(Color color);
            std::chrono::time_point<std::chrono::high_resolution_clock> _tick;
            bool _alive;
            bool _block;
    };
}

#endif //OOP_ARCADE_2019_NCURSES_HPP
