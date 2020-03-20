/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_SDL2_HPP
#define OOP_ARCADE_2019_SDL2_HPP

#include <SDL2/SDL.h>
#include <vector>
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
            static const uint WINDOW_HEIGHT = 600;
        private:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            SDL_Event _event;
            bool _running;
            std::vector<SDL_Texture *> _entities;
    };
}

#endif //OOP_ARCADE_2019_SDL2_HPP
