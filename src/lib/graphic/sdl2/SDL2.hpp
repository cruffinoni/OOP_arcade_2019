/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Header class file for SDL2
*/

#ifndef OOP_ARCADE_2019_SDL2_HPP
#define OOP_ARCADE_2019_SDL2_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <iostream>
#include "graphic/IGraphic.hpp"

namespace Graphic {
    class SDL2 : public IGraphic {
        public:
            SDL2();
            ~SDL2();

            void clearScreen() override;

            void drawCircle(Circle circle) override;
            void drawRect(Rect rect) override;
            void drawScreen() override;
            void drawSprite(Sprite sprite) override;
            void drawText(Text text) override;

            std::string handleEvent() override;
            bool isOperational() override;

            static const uint WINDOW_WIDTH = 800;
            static const uint WINDOW_HEIGHT = 800;

        private:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            bool _running;
            TTF_Font *_font;
            uint32_t _ticks;
    };
}

#endif //OOP_ARCADE_2019_SDL2_HPP
