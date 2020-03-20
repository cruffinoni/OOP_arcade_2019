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
    float circleX = PERCENTAGE(circle.getSizeX() * Graphic::SDL2::WINDOW_WIDTH);
    float circleY = PERCENTAGE(circle.getSizeY() * Graphic::SDL2::WINDOW_HEIGHT);
    float circleRadius = PERCENTAGE(circle.getSizeY());
    int pointX = 0;
    int pointY = 0;

    SDL_SetRenderDrawColor(_renderer, circle.getColor().red,
        circle.getColor().green, circle.getColor().blue, circle.getColor().alpha);
    while (circleRadius > 0) {
        for (int i = 0; i < 360; ++i) {
            pointX = circleX + circleRadius * cos(i);
            pointY = circleY + circleRadius * cos(i);
            SDL_RenderDrawPoint(_renderer, pointX, pointY);
        }
        --circleRadius;
    }
}

void Graphic::SDL2::drawRect(Rect rect) {
    SDL_Rect sdlRect = {(int) PERCENTAGE(rect.getPositionX() * Graphic::SDL2::WINDOW_WIDTH),
                        (int) PERCENTAGE(rect.getPositionY() * Graphic::SDL2::WINDOW_HEIGHT),
                        (int) PERCENTAGE(rect.getSizeX() * Graphic::SDL2::WINDOW_WIDTH),
                        (int) PERCENTAGE(rect.getSizeY() * Graphic::SDL2::WINDOW_HEIGHT)};

    SDL_SetRenderDrawColor(_renderer, rect.getColor().red, rect.getColor().green, rect.getColor().blue, rect.getColor().alpha);
    SDL_RenderFillRect(_renderer, &sdlRect);
}

void Graphic::SDL2::drawScreen() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
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
            return (IEventIterator::KEY_UNKNOWN);
    }
    return "undefined";
}

bool Graphic::SDL2::isOperational() { return _running; }
