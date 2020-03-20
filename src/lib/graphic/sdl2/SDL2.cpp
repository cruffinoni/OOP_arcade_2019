/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "SDL2.hpp"

static Graphic::SDL2 *instance;

extern "C" {
    IGraphicRenderer *loadLibrary() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        printf("constructor SDL2 called\n");
        instance = new Graphic::SDL2();
    }

    __attribute__((destructor)) void unload() {
        printf("destructor SDL2 called\n");
        delete instance;
    }
}

Graphic::SDL2::SDL2() {
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    _running = true;
}

Graphic::SDL2::~SDL2() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

void Graphic::SDL2::clearScreen() {
    SDL_RenderClear(_renderer);
}

void Graphic::SDL2::drawCircle(Circle circle) {
    float circleX = circle.getSizeX() * Graphic::SDL2::WINDOW_WIDTH;
    float circleY = circle.getSizeY() * Graphic::SDL2::WINDOW_HEIGHT;

    
}

void Graphic::SDL2::drawRect(Rect rect) {

}

void Graphic::SDL2::drawScreen() {
    SDL_RenderPresent(_renderer);
}

void Graphic::SDL2::drawSprite(Sprite sprite) {

}

void Graphic::SDL2::drawText(Text text) {

}

std::string Graphic::SDL2::handleEvent() {
    SDL_PollEvent(&_event);
    switch (_event.type) {
        case SDL_QUIT:
            _running = false;
            return "gameClosed";
    }
    return "undefined";
}

bool Graphic::SDL2::isOperational() { return _running; }
